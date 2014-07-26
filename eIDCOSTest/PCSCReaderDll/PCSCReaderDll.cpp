// PCSCReaderDll.cpp : 定义 DLL 应用程序的入口点。
//

#include "stdafx.h"
#include "PCSCReaderDll.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

SCARD_IO_REQUEST	IO_Request;
SCARDCONTEXT		ContextHandle;
SCARDHANDLE			SCardHandle;

LONG				ret;
LONG				ReaderID;
unsigned char		ReaderName1[MAX_READER][MAX_READER_NAME];
unsigned long		ReaderStatus[10][2];

DWORD				ActiveProtocol;



/**********************************************************************************************
1.PCSC_GetReaderList
获取读卡器列表。枚举系统中存在的读卡器列表

PCSC_GetReaderList(int * ReaderCount, char ResponseBuffer[MAX_READER_NAME])

参数说明
ResponseBuffer 	返回值，读卡器名字。	
ReaderCount		返回值，设备数量。

返回值
函数返回0x9000表示正确;其余参考Smart Card Return Values
***********************************************************************************************/
//PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(HANDLE ContextNo, int * ReaderCount, char ResponseBuffer[MAX_READER_NAME])
PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(int * ReaderCount, char ResponseBuffer[MAX_READER_NAME])
{ 
	unsigned long ResponseLength;
	int j, StringLen;
	unsigned char ReaderNameTmp[MAX_READER_NAME];

	ret = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &ContextHandle);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}

	//The SCardListCards function searches the smart card database 
	//and provides a list of named cards previously introduced to the system by the user.
	//
	//The caller specifies an ATR string, a set of interface identifiers (GUIDs), or both. 
	//If both an ATR string and an identifier array are supplied, the cards returned 
	//will match the ATR string supplied and support the interfaces specified.
	ret = SCardListReaders(ContextHandle, NULL, NULL, &ResponseLength);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}

	ret = SCardListReaders(ContextHandle, NULL, (char *)ResponseBuffer, &ResponseLength);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}

	j=0;
//	ReaderID = 0;
	StringLen = 0;

	while ((unsigned long)StringLen < (ResponseLength - 1))
	{
		strcpy((char*)ReaderNameTmp, (char*)ResponseBuffer+StringLen);

		ret = SCardConnect(ContextHandle, (char *)ReaderNameTmp, SCARD_SHARE_DIRECT, 0, &SCardHandle, &ActiveProtocol);

		if ((ret == SCARD_S_SUCCESS)||(ret == SCARD_W_REMOVED_CARD))
		{
			j++;
			ReaderStatus[j-1][0]=0;
			ReaderStatus[j-1][1]=0;
			SCardDisconnect(SCardHandle, SCARD_EJECT_CARD);
			StringLen += (int)strlen((char*)ReaderNameTmp);
			StringLen += 1;
		}
		else{
			return ret;
		}
	}

	*ReaderCount = j;

	return EXCUTE_SUC ;	

}


/**********************************************************************************************
2.PCSC_OpenReader
打开指定读卡器

PCSC_OpenReader(HANDLE *hReader, const char *ReaderName)

参数说明
ReaderName		输入值,指定打开的读卡器名字
hReader			返回值,指定打开的读卡器句柄


返回值
函数返回0x9000表示正确;其余参考Smart Card Return Values
***********************************************************************************************/
PCSCREADERDLL_API LONG CCONV PCSC_OpenReader(HANDLE *hReader, const char *ReaderName)
{
	ret = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &ContextHandle);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}


	ret = SCardConnect(ContextHandle, (char *)ReaderName, SCARD_SHARE_SHARED, SCARD_PROTOCOL_T0, &SCardHandle, &ActiveProtocol);

	if ((ret != SCARD_S_SUCCESS)&&(ret != SCARD_W_REMOVED_CARD))
	{
		return ret;	
	}	
	
	*hReader = (HANDLE)SCardHandle;

	return EXCUTE_SUC ;	

}


/**********************************************************************************************
10  PCSC_ApduT0
卡命令处理函数,该命令接收APDU Case2 Case3格式的指令。

HD_ApduT0( HANDLE hReader,  unsigned char *apduData, short srAPDULen, unsigned char *respData, short *respDataLen)

参数说明
hReader				由PCSC_OpenReader返回的设备句柄
apduData			APDU命令(字节串)用CLA、INS、P1、P2以及一个可变长度的条件体来表示，条件体的定义为Lc、Data（Lc个字节）和Le。
					根据Lc和Le值的不同，共有四种命令情况，如下表所示：
					情况	结构
					1	CLA INS P1 P2
					2	CLA INS P1 P2 Le
					3	CLA INS P1 P2 Lc Data
					4	CLA INS P1 P2 Lc Data Le
srAPDULen			存放发送的APDU数据的长度
respData			卡响应数据
respDataLen			卡响应数据的长度


返回值

当操作Case1和 Case2时，respData无意义。当操作Case3和 Case4时，函数返回0x9000，respData有意义；其余响应，respData无意义。
***********************************************************************************************/
LONG isobase2(HANDLE hReader, unsigned char *apduData, int svAPDULen, unsigned char *srResp, int *srRespLen)
{
	BYTE  ResponseBuffer[MAX_RESPDATA_LENGTH];
	DWORD ResponseLength = 1024;

	WORD retval = 0;

	*srRespLen = 0 ;
	*srResp = '\0' ;

	IO_Request.dwProtocol = ActiveProtocol;
	IO_Request.cbPciLength = (DWORD) sizeof(SCARD_IO_REQUEST);


	ResponseLength=2000;

	ret = SCardTransmit((SCARDHANDLE)hReader, &IO_Request, apduData, svAPDULen, 0, (BYTE *)&ResponseBuffer, &ResponseLength);
	if (ret != SCARD_S_SUCCESS)
	{
		return ret;
	}

	if ( ResponseLength >= 2 )
	{

		retval = ((BYTE)ResponseBuffer[ResponseLength-2]) * 256 + (BYTE)ResponseBuffer[ResponseLength-1] ;

		*srRespLen = (short)ResponseLength - 2;
		memcpy(srResp,ResponseBuffer,ResponseLength-2);

	}else{
		return ret;
	}

	return EXCUTE_SUC ;
}

LONG isobase3(HANDLE hReader,unsigned char *apduData,int svAPDULen,unsigned char *srResp,int *srRespLen)
{
	BYTE  ResponseBuffer[MAX_RESPDATA_LENGTH] = {0};
	DWORD ResponseLength = 1024;

	WORD retval = 0;

	unsigned char responeCMD[5] = {0x00, 0xC0, 0x00, 0x00, 0x00};

	short respLen;

	IO_Request.dwProtocol = ActiveProtocol;
	IO_Request.cbPciLength = (DWORD) sizeof(SCARD_IO_REQUEST);


	ret = SCardTransmit((SCARDHANDLE)hReader, &IO_Request, apduData, svAPDULen, 0, (BYTE *)ResponseBuffer, &ResponseLength);
	if (ret != SCARD_S_SUCCESS)
	{
		return ret;
	}


	if ( ResponseLength >= 2 )
	{
		retval = ((BYTE)ResponseBuffer[ResponseLength-2]) * 256 + (BYTE)ResponseBuffer[ResponseLength-1] ;
		
		//if rf
		if(retval==0x9000)
		{
			*srRespLen = (short)ResponseLength - 2;
			memcpy(srResp,ResponseBuffer,*srRespLen);
		}else if((retval & 0xFF00) == 0x6100){
			respLen = (BYTE)ResponseBuffer[ResponseLength-1] ;
			
			responeCMD[4] = (unsigned char)respLen;

			ResponseLength = respLen + 2;

			ret = SCardTransmit((SCARDHANDLE)hReader, &IO_Request, responeCMD, RESPONECMD_LEN, 0, (BYTE *)&ResponseBuffer, &ResponseLength);
			if (ret != SCARD_S_SUCCESS)
			{
				return ret;
			}
			
			retval = ((BYTE)ResponseBuffer[ResponseLength-2]) * 256 + (BYTE)ResponseBuffer[ResponseLength-1] ;
			memcpy(srResp,ResponseBuffer,respLen);
		}else{
			return retval;
		}
	}
	else
	{
		return ILLEGAL_RESPONSE_LENGTH;
	}

	return EXCUTE_SUC ;

}

PCSCREADERDLL_API LONG CCONV PCSC_ApduT0( HANDLE hReader,  unsigned char *apduData, int srAPDULen, unsigned char *respData, int *respDataLen)
{

	LONG ret;
//	unsigned char getresp[12];
	unsigned char tmpTPDU[600];

	*respData = '\0';

	if( srAPDULen < 4 || srAPDULen > 261 )
		return ILLEGAL_APDU_LENGTH;			// 非法APDU字节数

	memcpy( tmpTPDU, apduData, srAPDULen);
	
    // begin transaction locking
    // check that handle to card is valid
//     ret = SCardBeginTransaction((SCARDHANDLE)devNo);
// 	if (ret != SCARD_S_SUCCESS)
// 	{
// //		GetErrorCode(ret);
// 		return CER_PCSC_SCardBeginTransaction;
// 	}

	if (srAPDULen == 4)
	{
		// isocase = 1
		tmpTPDU[4]=0x00;
		ret = isobase2(hReader,tmpTPDU,5, respData, respDataLen);
		if(ret != EXCUTE_SUC){
			return ret;
		}
/*
		if(  HIBYTE(retv) == 0x61)
		{
			memcpy(getresp, "\x00\xC0\x00\x00",4);
			getresp[4]= LOBYTE(retv);

			retv = isobase2(devNo,getresp,5, respData, respDataLen, ivCardSeat);
		}
		else if(  HIBYTE(retv) == 0x6C)
		{
			tmpTPDU[4]= LOBYTE(retv);	// 补上新的Le字节
			retv = isobase2(devNo,tmpTPDU,5, respData, respDataLen, ivCardSeat); 
		}*/
	}

	else if( srAPDULen == 5 )
	{
		// isocase = 2
		ret = isobase2(hReader,tmpTPDU, 5,respData, respDataLen); 
		if(ret != EXCUTE_SUC){
			return ret;
		}
		/*if(  HIBYTE(retv) == 0x61)
		{
			memcpy(getresp, "\x00\xC0\x00\x00",4);
			getresp[4]= LOBYTE(retv);

			retv = isobase2(devNo,getresp,5, respData, respDataLen, ivCardSeat);
		}
		else if(  HIBYTE(retv) == 0x6C)
		{
			tmpTPDU[4]= LOBYTE(retv);	// 补上新的Le字节
			retv = isobase2(devNo,tmpTPDU,5, respData, respDataLen, ivCardSeat); 
		}*/
	}

	else if( srAPDULen-5 == (unsigned char)apduData[4] )
	{
		// isocase = 3
		ret = isobase3(hReader,tmpTPDU,srAPDULen,respData, respDataLen);
		if(ret != EXCUTE_SUC){
			return ret;
		}

		/*if(  HIBYTE(retv) == 0x61)
		{
			memcpy(getresp, "\x00\xC0\x00\x00",4);
			getresp[4]= LOBYTE(retv);
			retv = isobase2(devNo,getresp,5, respData, respDataLen, ivCardSeat);
		}*/
		
	}
	else if( srAPDULen-6 == (unsigned char)apduData[4] )
	{
		// isocase = 4;
		ret = isobase3(hReader,tmpTPDU,srAPDULen-1,respData, respDataLen); // 去掉Le
		if(ret != EXCUTE_SUC){
			return ret;
		}
	/*	if(  HIBYTE(retv) == 0x61)
		{
			memcpy(getresp, "\x00\xC0\x00\x00",4);
			getresp[4]= LOBYTE(retv);
			retv = isobase2(devNo,getresp,5, respData, respDataLen, ivCardSeat);
		}*/
	}
	else
	{
		//SCardEndTransaction((SCARDHANDLE)devNo, SCARD_LEAVE_CARD);
		return ILLEGAL_APDU_CASE;			// 非法APDU Case结构
	}

    //end transaction locking
//     ret = SCardEndTransaction((SCARDHANDLE)devNo, SCARD_LEAVE_CARD);
// 	if (ret != SCARD_S_SUCCESS)
// 	{
// 		GetErrorCode(ret);
// 		return CER_PCSC_SCardEndTransaction;
// 	}

	return EXCUTE_SUC;
}
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


#define MAX_READER 16

#define MAX_RESPDATA_LENGTH 2048
#define RESPONECMD_LEN 5



typedef struct tagPCSCReader_STATE 
{
	int data;
}PCSCReader_STATE, *PPCSCReader_STATE;

SCARD_IO_REQUEST	IO_Request;
SCARDCONTEXT		ContextHandle;

LONG		ret;
LONG		ReaderID;
unsigned char		ReaderName1[MAX_READER][MAX_READER_NAME];
unsigned long		ReaderStatus[10][2];



DWORD ActiveProtocol;

PPCSCReader_STATE g_RefCount;


/**********************************************************************************************
1.PCSC_GetReaderList
获取读卡器列表。枚举系统中存在的读卡器列表

参数说明
ContextNo		句柄
ReaderNo 		返回值，设备标识列表。	
ReaderCount		返回值，设备数量。

返回值
函数返回0x9000表示正确，此时devNo有效；其它值表示出错，错误信息见附后的“错误信息表”。
***********************************************************************************************/

//PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(HANDLE ContextNo, int * ReaderNo, int * ReaderCount, char ResponseBuffer[MAX_READER_NAME])
PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(HANDLE ContextNo, int * ReaderCount, char ResponseBuffer[MAX_READER_NAME])
{
	SCARDHANDLE	CardHandle;
//	unsigned char ResponseBuffer[255];
	unsigned long ResponseLength;
	int j, StringLen;
	unsigned char ReaderNameTmp[MAX_READER_NAME];

	//
	//The SCardListCards function searches the smart card database 
	//and provides a list of named cards previously introduced to the system by the user.
	//
	//The caller specifies an ATR string, a set of interface identifiers (GUIDs), or both. 
	//If both an ATR string and an identifier array are supplied, the cards returned 
	//will match the ATR string supplied and support the interfaces specified.
	//

	ret = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &CardHandle);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}

	ContextNo = (HANDLE)CardHandle;

	ret = SCardListReaders((SCARDCONTEXT)ContextNo, NULL, NULL, &ResponseLength);
	if (ret != SCARD_S_SUCCESS) 
	{
		return ret;
	}

	ret = SCardListReaders((SCARDCONTEXT)ContextNo, NULL, (char *)ResponseBuffer, &ResponseLength);
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
		
		
		

		ret = SCardConnect((SCARDCONTEXT)ContextNo, (char *)ReaderNameTmp, SCARD_SHARE_DIRECT, 0, &CardHandle, &ActiveProtocol);

		if ((ret == SCARD_S_SUCCESS)||(ret == SCARD_W_REMOVED_CARD))
		{
			j++;
			ReaderStatus[j-1][0]=0;
			ReaderStatus[j-1][1]=0;
			SCardDisconnect(CardHandle, SCARD_EJECT_CARD);
		}
		StringLen += (int)strlen((char*)ReaderNameTmp);
		StringLen += 1;
	}

	*ReaderCount = j;
/*
	ReaderID = j;

	for (i=0;i<j;i++)
		 ReaderNo[i] = i+1;
*/	
	return EXCUTE_SUC ;	

}


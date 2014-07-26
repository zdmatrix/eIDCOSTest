
// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 PCSCREADERDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// PCSCREADERDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef PCSCREADERDLL_EXPORTS
#define PCSCREADERDLL_API __declspec(dllexport)
#else
#define PCSCREADERDLL_API __declspec(dllimport)
#endif

#define CCONV _stdcall//WINAPI

#define MAX_READER				16
#define EXCUTE_SUC				0x9000
#define MAX_READER_NAME			4096
#define MAX_RESPDATA_LENGTH		261
#define RESPONECMD_LEN			5
#define MAX_APDU_LENGTH			260

#define ILLEGAL_APDU_LENGTH		0x00010001		//非法APDU长度
#define ILLEGAL_APDU_CASE		0x00010002		//非法APDU结构
#define ILLEGAL_RESPONSE_LENGTH		0x00010010		//非法APDU长度

PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(int * ReaderCount, char ReaderName[MAX_READER_NAME]);
PCSCREADERDLL_API LONG CCONV PCSC_OpenReader(HANDLE *hReader, const char *ReaderName);
PCSCREADERDLL_API LONG CCONV PCSC_ApduT0( HANDLE hReader,  unsigned char *apduData, int srAPDULen, unsigned char *respData, int *respDataLen);

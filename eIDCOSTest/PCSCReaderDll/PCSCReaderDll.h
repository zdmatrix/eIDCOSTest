
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� PCSCREADERDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// PCSCREADERDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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

#define ILLEGAL_APDU_LENGTH		0x00010001		//�Ƿ�APDU����
#define ILLEGAL_APDU_CASE		0x00010002		//�Ƿ�APDU�ṹ
#define ILLEGAL_RESPONSE_LENGTH		0x00010010		//�Ƿ�APDU����

PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(int * ReaderCount, char ReaderName[MAX_READER_NAME]);
PCSCREADERDLL_API LONG CCONV PCSC_OpenReader(HANDLE *hReader, const char *ReaderName);
PCSCREADERDLL_API LONG CCONV PCSC_ApduT0( HANDLE hReader,  unsigned char *apduData, int srAPDULen, unsigned char *respData, int *respDataLen);

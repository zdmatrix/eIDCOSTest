
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

#define EXCUTE_SUC 0x9000
#define MAX_READER_NAME 4096

PCSCREADERDLL_API LONG CCONV PCSC_GetReaderList(HANDLE ContextNo, int * ReaderCount, char ReaderName[MAX_READER_NAME]);

#ifndef _WHEATYEXCEPTIONREPORT_
#define _WHEATYEXCEPTIONREPORT_

#include <dbghelp.h>

#if _MSC_VER < 1400
#   define countof(array)   (sizeof(array) / sizeof(array[0]))
#else
#   include <stdlib.h>
#   define countof  _countof
#endif                                                      // _MSC_VER < 1400

enum BasicType                                              // Stolen from CVCONST.H in the DIA 2.0 SDK
{
    btNoType = 0,
    btVoid = 1,
    btChar = 2,
    btWChar = 3,
    btInt = 6,
    btUInt = 7,
    btFloat = 8,
    btBCD = 9,
    btBool = 10,
    btLong = 13,
    btULong = 14,
    btCurrency = 25,
    btDate = 26,
    btVariant = 27,
    btComplex = 28,
    btBit = 29,
    btBSTR = 30,
    btHresult = 31
};

const char* const rgBaseType[] =
{
    " <user defined> ",                                     // btNoType = 0,
    " void ",                                               // btVoid = 1,
    " char* ",                                              // btChar = 2,
    " wchar_t* ",                                           // btWChar = 3,
    " signed char ",
    " unsigned char ",
    " int ",                                                // btInt = 6,
    " unsigned int ",                                       // btUInt = 7,
    " float ",                                              // btFloat = 8,
    " <BCD> ",                                              // btBCD = 9,
    " bool ",                                               // btBool = 10,
    " short ",
    " unsigned short ",
    " long ",                                               // btLong = 13,
    " unsigned long ",                                      // btULong = 14,
    " __int8 ",
    " __int16 ",
    " __int32 ",
    " __int64 ",
    " __int128 ",
    " unsigned __int8 ",
    " unsigned __int16 ",
    " unsigned __int32 ",
    " unsigned __int64 ",
    " unsigned __int128 ",
    " <currency> ",                                         // btCurrency = 25,
    " <date> ",                                             // btDate = 26,
    " VARIANT ",                                            // btVariant = 27,
    " <complex> ",                                          // btComplex = 28,
    " <bit> ",                                              // btBit = 29,
    " BSTR ",                                               // btBSTR = 30,
    " HRESULT "                                             // btHresult = 31
};

class WheatyExceptionReport
{
    public:

        WheatyExceptionReport();
        ~WheatyExceptionReport();

        // entry point where control comes on an unhandled exception
        static LONG WINAPI WheatyUnhandledExceptionFilter(
            PEXCEPTION_POINTERS pExceptionInfo);

        static void printTracesForAllThreads();
    private:
        // where report info is extracted and generated
        static void GenerateExceptionReport(PEXCEPTION_POINTERS pExceptionInfo);
        static void PrintSystemInfo();
        static BOOL _GetWindowsVersion(TCHAR* szVersion, DWORD cntMax);
        static BOOL _GetProcessorName(TCHAR* sProcessorName, DWORD maxcount);

        // Helper functions
        static LPTSTR GetExceptionString(DWORD dwCode);
        static BOOL GetLogicalAddress(PVOID addr, PTSTR szModule, DWORD len,
            DWORD& section, DWORD_PTR& offset);

        static void WriteStackDetails(PCONTEXT pContext, bool bWriteVariables, HANDLE pThreadHandle);

        static BOOL CALLBACK EnumerateSymbolsCallback(PSYMBOL_INFO,ULONG, PVOID);

        static bool FormatSymbolValue(PSYMBOL_INFO, STACKFRAME *, char * pszBuffer, unsigned cbBuffer);

        static char * DumpTypeIndex(char *, DWORD64, DWORD, unsigned, DWORD_PTR, bool & , char*);

        static char * FormatOutputValue(char * pszCurrBuffer, BasicType basicType, DWORD64 length, PVOID pAddress);

        static BasicType GetBasicType(DWORD typeIndex, DWORD64 modBase);

        static int __cdecl _tprintf(const TCHAR * format, ...);

        // Variables used by the class
        static TCHAR m_szLogFileName[MAX_PATH];
        static TCHAR m_szDumpFileName[MAX_PATH];
        static LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
        static HANDLE m_hReportFile;
        static HANDLE m_hDumpFile;
        static HANDLE m_hProcess;
};

extern WheatyExceptionReport g_WheatyExceptionReport;       //  global instance of class
#endif                                                      //WheatyExceptionReport


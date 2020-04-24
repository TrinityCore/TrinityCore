#ifndef _WHEATYEXCEPTIONREPORT_
#define _WHEATYEXCEPTIONREPORT_

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS && !defined(__MINGW32__)

#include <winnt.h>
#include <winternl.h>
#include <dbghelp.h>
#include <set>
#include <stdlib.h>
#include <stack>
#include <mutex>
#define countof  _countof

#define WER_MAX_ARRAY_ELEMENTS_COUNT 10
#define WER_MAX_NESTING_LEVEL 4
#define WER_SMALL_BUFFER_SIZE 1024
#define WER_LARGE_BUFFER_SIZE WER_SMALL_BUFFER_SIZE * 16

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
    btHresult = 31,

    // Custom types
    btStdString = 101
};

enum DataKind                                              // Stolen from CVCONST.H in the DIA 2.0 SDK
{
    DataIsUnknown,
    DataIsLocal,
    DataIsStaticLocal,
    DataIsParam,
    DataIsObjectPtr,
    DataIsFileStatic,
    DataIsGlobal,
    DataIsMember,
    DataIsStaticMember,
    DataIsConstant
};

const char* const rgBaseType[] =
{
    "<user defined>",                                     // btNoType = 0,
    "void",                                               // btVoid = 1,
    "char",//char*                                        // btChar = 2,
    "wchar_t*",                                           // btWChar = 3,
    "signed char",
    "unsigned char",
    "int",                                                // btInt = 6,
    "unsigned int",                                       // btUInt = 7,
    "float",                                              // btFloat = 8,
    "<BCD>",                                              // btBCD = 9,
    "bool",                                               // btBool = 10,
    "short",
    "unsigned short",
    "long",                                               // btLong = 13,
    "unsigned long",                                      // btULong = 14,
    "int8",
    "int16",
    "int32",
    "int64",
    "int128",
    "uint8",
    "uint16",
    "uint32",
    "uint64",
    "uint128",
    "<currency>",                                         // btCurrency = 25,
    "<date>",                                             // btDate = 26,
    "VARIANT",                                            // btVariant = 27,
    "<complex>",                                          // btComplex = 28,
    "<bit>",                                              // btBit = 29,
    "BSTR",                                               // btBSTR = 30,
    "HRESULT"                                             // btHresult = 31
};

struct SymbolPair
{
    SymbolPair(DWORD type, DWORD_PTR offset)
    {
        _type = type;
        _offset = offset;
    }

    bool operator<(const SymbolPair& other) const
    {
        return _offset < other._offset ||
              (_offset == other._offset && _type < other._type);
    }

    DWORD _type;
    DWORD_PTR _offset;
};
typedef std::set<SymbolPair> SymbolPairs;

struct SymbolDetail
{
    SymbolDetail() : Prefix(), Type(), Suffix(), Name(), Value(), Logged(false), HasChildren(false) {}

    std::string ToString()
    {
        Logged = true;
        std::string formatted = Prefix + Type + Suffix;
        if (!Name.empty())
        {
            if (!formatted.empty())
                formatted += " ";
            formatted += Name;
        }
        if (!Value.empty())
            formatted += " = " + Value;
        return formatted;
    }

    bool empty() const
    {
        return Value.empty() && !HasChildren;
    }

    std::string Prefix;
    std::string Type;
    std::string Suffix;
    std::string Name;
    std::string Value;
    bool Logged;
    bool HasChildren;
};

class WheatyExceptionReport
{
    public:

        WheatyExceptionReport();
        ~WheatyExceptionReport();

        // entry point where control comes on an unhandled exception
        static LONG WINAPI WheatyUnhandledExceptionFilter(
            PEXCEPTION_POINTERS pExceptionInfo);

        static void __cdecl WheatyCrtHandler(wchar_t const* expression, wchar_t const* function, wchar_t const* file, unsigned int line, uintptr_t pReserved);

        static void printTracesForAllThreads(bool);
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

        static BOOL CALLBACK EnumerateSymbolsCallback(PSYMBOL_INFO, ULONG, PVOID);

        static bool FormatSymbolValue(PSYMBOL_INFO, STACKFRAME64 *);

        static void DumpTypeIndex(DWORD64, DWORD, DWORD_PTR, bool &, const char*, char*, bool, bool);

        static void FormatOutputValue(char * pszCurrBuffer, BasicType basicType, DWORD64 length, PVOID pAddress, size_t bufferSize, size_t countOverride = 0);

        static BasicType GetBasicType(DWORD typeIndex, DWORD64 modBase);
        static DWORD_PTR DereferenceUnsafePointer(DWORD_PTR address);

        static int __cdecl Log(const TCHAR * format, ...);
        static int __cdecl StackLog(const TCHAR * format, va_list argptr);
        static int __cdecl HeapLog(const TCHAR * format, va_list argptr);

        static bool StoreSymbol(DWORD type , DWORD_PTR offset);
        static void ClearSymbols();

        // Variables used by the class
        static TCHAR m_szLogFileName[MAX_PATH];
        static TCHAR m_szDumpFileName[MAX_PATH];
        static LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
        static _invalid_parameter_handler m_previousCrtHandler;
        static HANDLE m_hReportFile;
        static HANDLE m_hDumpFile;
        static HANDLE m_hProcess;
        static SymbolPairs symbols;
        static std::stack<SymbolDetail> symbolDetails;
        static bool stackOverflowException;
        static bool alreadyCrashed;
        static std::mutex alreadyCrashedLock;
        typedef NTSTATUS(NTAPI* pRtlGetVersion)(PRTL_OSVERSIONINFOW lpVersionInformation);
        static pRtlGetVersion RtlGetVersion;

        static void PushSymbolDetail();
        static void PopSymbolDetail();
        static void PrintSymbolDetail();

};

extern WheatyExceptionReport g_WheatyExceptionReport;       //  global instance of class
#endif                                                      // _WIN32
#endif                                                      // _WHEATYEXCEPTIONREPORT_

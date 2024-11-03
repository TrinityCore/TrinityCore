#ifndef _WHEATYEXCEPTIONREPORT_
#define _WHEATYEXCEPTIONREPORT_

#define _NO_CVCONST_H

#include "Define.h"
#include "Optional.h"
#include <windows.h>
#include <winnt.h>
#include <winternl.h>
#include <dbghelp.h>
#include <compare>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <mutex>

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

enum CpuRegister                                           // Stolen from CVCONST.H in the DIA SDK
{
    CV_ALLREG_VFRAME=   30006,

    //
    //  Register set for the Intel 80x86 and ix86 processor series
    //
    CV_REG_NONE     =   0,
    CV_REG_AL       =   1,
    CV_REG_CL       =   2,
    CV_REG_DL       =   3,
    CV_REG_BL       =   4,
    CV_REG_AH       =   5,
    CV_REG_CH       =   6,
    CV_REG_DH       =   7,
    CV_REG_BH       =   8,
    CV_REG_AX       =   9,
    CV_REG_CX       =  10,
    CV_REG_DX       =  11,
    CV_REG_BX       =  12,
    CV_REG_SP       =  13,
    CV_REG_BP       =  14,
    CV_REG_SI       =  15,
    CV_REG_DI       =  16,
    CV_REG_EAX      =  17,
    CV_REG_ECX      =  18,
    CV_REG_EDX      =  19,
    CV_REG_EBX      =  20,
    CV_REG_ESP      =  21,
    CV_REG_EBP      =  22,
    CV_REG_ESI      =  23,
    CV_REG_EDI      =  24,
    CV_REG_EIP      =  33,

    //
    // AMD64 registers
    //
    CV_AMD64_AL       =   1,
    CV_AMD64_CL       =   2,
    CV_AMD64_DL       =   3,
    CV_AMD64_BL       =   4,
    CV_AMD64_AH       =   5,
    CV_AMD64_CH       =   6,
    CV_AMD64_DH       =   7,
    CV_AMD64_BH       =   8,
    CV_AMD64_AX       =   9,
    CV_AMD64_CX       =  10,
    CV_AMD64_DX       =  11,
    CV_AMD64_BX       =  12,
    CV_AMD64_SP       =  13,
    CV_AMD64_BP       =  14,
    CV_AMD64_SI       =  15,
    CV_AMD64_DI       =  16,
    CV_AMD64_EAX      =  17,
    CV_AMD64_ECX      =  18,
    CV_AMD64_EDX      =  19,
    CV_AMD64_EBX      =  20,
    CV_AMD64_ESP      =  21,
    CV_AMD64_EBP      =  22,
    CV_AMD64_ESI      =  23,
    CV_AMD64_EDI      =  24,
    CV_AMD64_RIP      =  33,

    // Low byte forms of some standard registers
    CV_AMD64_SIL      =  324,
    CV_AMD64_DIL      =  325,
    CV_AMD64_BPL      =  326,
    CV_AMD64_SPL      =  327,

    // 64-bit regular registers
    CV_AMD64_RAX      =  328,
    CV_AMD64_RBX      =  329,
    CV_AMD64_RCX      =  330,
    CV_AMD64_RDX      =  331,
    CV_AMD64_RSI      =  332,
    CV_AMD64_RDI      =  333,
    CV_AMD64_RBP      =  334,
    CV_AMD64_RSP      =  335,

    // 64-bit integer registers with 8-, 16-, and 32-bit forms (B, W, and D)
    CV_AMD64_R8       =  336,
    CV_AMD64_R9       =  337,
    CV_AMD64_R10      =  338,
    CV_AMD64_R11      =  339,
    CV_AMD64_R12      =  340,
    CV_AMD64_R13      =  341,
    CV_AMD64_R14      =  342,
    CV_AMD64_R15      =  343,

    CV_AMD64_R8B      =  344,
    CV_AMD64_R9B      =  345,
    CV_AMD64_R10B     =  346,
    CV_AMD64_R11B     =  347,
    CV_AMD64_R12B     =  348,
    CV_AMD64_R13B     =  349,
    CV_AMD64_R14B     =  350,
    CV_AMD64_R15B     =  351,

    CV_AMD64_R8W      =  352,
    CV_AMD64_R9W      =  353,
    CV_AMD64_R10W     =  354,
    CV_AMD64_R11W     =  355,
    CV_AMD64_R12W     =  356,
    CV_AMD64_R13W     =  357,
    CV_AMD64_R14W     =  358,
    CV_AMD64_R15W     =  359,

    CV_AMD64_R8D      =  360,
    CV_AMD64_R9D      =  361,
    CV_AMD64_R10D     =  362,
    CV_AMD64_R11D     =  363,
    CV_AMD64_R12D     =  364,
    CV_AMD64_R13D     =  365,
    CV_AMD64_R14D     =  366,
    CV_AMD64_R15D     =  367,

    //
    // Register set for ARM64
    //
    CV_ARM64_NOREG  =  CV_REG_NONE,

    // General purpose 32-bit integer registers
    CV_ARM64_W0     =  10,
    CV_ARM64_W1     =  11,
    CV_ARM64_W2     =  12,
    CV_ARM64_W3     =  13,
    CV_ARM64_W4     =  14,
    CV_ARM64_W5     =  15,
    CV_ARM64_W6     =  16,
    CV_ARM64_W7     =  17,
    CV_ARM64_W8     =  18,
    CV_ARM64_W9     =  19,
    CV_ARM64_W10    =  20,
    CV_ARM64_W11    =  21,
    CV_ARM64_W12    =  22,
    CV_ARM64_W13    =  23,
    CV_ARM64_W14    =  24,
    CV_ARM64_W15    =  25,
    CV_ARM64_W16    =  26,
    CV_ARM64_W17    =  27,
    CV_ARM64_W18    =  28,
    CV_ARM64_W19    =  29,
    CV_ARM64_W20    =  30,
    CV_ARM64_W21    =  31,
    CV_ARM64_W22    =  32,
    CV_ARM64_W23    =  33,
    CV_ARM64_W24    =  34,
    CV_ARM64_W25    =  35,
    CV_ARM64_W26    =  36,
    CV_ARM64_W27    =  37,
    CV_ARM64_W28    =  38,
    CV_ARM64_W29    =  39,
    CV_ARM64_W30    =  40,
    CV_ARM64_WZR    =  41,

    // General purpose 64-bit integer registers
    CV_ARM64_X0     =  50,
    CV_ARM64_X1     =  51,
    CV_ARM64_X2     =  52,
    CV_ARM64_X3     =  53,
    CV_ARM64_X4     =  54,
    CV_ARM64_X5     =  55,
    CV_ARM64_X6     =  56,
    CV_ARM64_X7     =  57,
    CV_ARM64_X8     =  58,
    CV_ARM64_X9     =  59,
    CV_ARM64_X10    =  60,
    CV_ARM64_X11    =  61,
    CV_ARM64_X12    =  62,
    CV_ARM64_X13    =  63,
    CV_ARM64_X14    =  64,
    CV_ARM64_X15    =  65,
    CV_ARM64_IP0    =  66,
    CV_ARM64_IP1    =  67,
    CV_ARM64_X18    =  68,
    CV_ARM64_X19    =  69,
    CV_ARM64_X20    =  70,
    CV_ARM64_X21    =  71,
    CV_ARM64_X22    =  72,
    CV_ARM64_X23    =  73,
    CV_ARM64_X24    =  74,
    CV_ARM64_X25    =  75,
    CV_ARM64_X26    =  76,
    CV_ARM64_X27    =  77,
    CV_ARM64_X28    =  78,
    CV_ARM64_FP     =  79,
    CV_ARM64_LR     =  80,
    CV_ARM64_SP     =  81,
    CV_ARM64_ZR     =  82,
};

char const* const rgBaseType[] =
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

    bool operator==(SymbolPair const& other) const = default;
    std::strong_ordering operator<=>(SymbolPair const& other) const = default;

    DWORD _type;
    DWORD_PTR _offset;
};
typedef std::set<SymbolPair> SymbolPairs;

struct SymbolDetail
{
    SymbolDetail() : Prefix(), Type(), Suffix(), Name(), Value(), Logged(false), HasChildren(false) {}

    std::string ToString();

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

class TC_COMMON_API WheatyExceptionReport
{
    public:

        WheatyExceptionReport();
        WheatyExceptionReport(WheatyExceptionReport const&) = delete;
        WheatyExceptionReport(WheatyExceptionReport&&) = delete;
        WheatyExceptionReport& operator=(WheatyExceptionReport const&) = delete;
        WheatyExceptionReport& operator=(WheatyExceptionReport&&) = delete;
        ~WheatyExceptionReport();

        // entry point where control comes on an unhandled exception
        static LONG WINAPI WheatyUnhandledExceptionFilter(
            PEXCEPTION_POINTERS pExceptionInfo);

        LONG UnhandledExceptionFilterImpl(PEXCEPTION_POINTERS pExceptionInfo);

        static void __cdecl WheatyCrtHandler(wchar_t const* expression, wchar_t const* function, wchar_t const* file, unsigned int line, uintptr_t pReserved);

        void printTracesForAllThreads(bool bWriteVariables);
    private:
        // where report info is extracted and generated
        void GenerateExceptionReport(PEXCEPTION_POINTERS pExceptionInfo);
        void PrintSystemInfo();
        BOOL _GetWindowsVersion(TCHAR* szVersion, DWORD cntMax);
        static BOOL _GetWindowsVersionFromWMI(TCHAR* szVersion, DWORD cntMax);
        static BOOL _GetProcessorName(TCHAR* sProcessorName, DWORD maxcount);

        // Helper functions
        static LPCTSTR GetExceptionString(DWORD dwCode);
        static BOOL GetLogicalAddress(PVOID addr, PTSTR szModule, DWORD len,
            DWORD& section, DWORD_PTR& offset);

        void WriteStackDetails(PCONTEXT pContext, bool bWriteVariables, HANDLE pThreadHandle);

        static BOOL GetSymbolFromAddress(HANDLE hProcess, DWORD64 Address, ULONG InlineContext, PDWORD64 Displacement, PSYMBOL_INFO Symbol);
        static BOOL GetSymbolLineFromAddress(HANDLE hProcess, DWORD64 qwAddr, ULONG InlineContext, PDWORD pdwDisplacement, PIMAGEHLP_LINE64 Line64);

        struct EnumerateSymbolsCallbackContext
        {
            LPSTACKFRAME_EX sf;
            PCONTEXT context;
            WheatyExceptionReport* report;
        };

        static BOOL CALLBACK EnumerateSymbolsCallback(PSYMBOL_INFO, ULONG, PVOID);

        bool FormatSymbolValue(PSYMBOL_INFO, EnumerateSymbolsCallbackContext*);

        void DumpTypeIndex(DWORD64, DWORD, DWORD_PTR, bool &, char const*, char const*, bool, bool);

        static void FormatOutputValue(char * pszCurrBuffer, BasicType basicType, DWORD64 length, PVOID pAddress, size_t bufferSize, size_t countOverride = 0);

        BasicType GetBasicType(DWORD typeIndex, DWORD64 modBase) const;
        static DWORD_PTR DereferenceUnsafePointer(DWORD_PTR address);

        int Log(const TCHAR * format, ...);

        bool StoreSymbol(DWORD type , DWORD_PTR offset);
        void ClearSymbols();

        static Optional<DWORD_PTR> GetIntegerRegisterValue(PCONTEXT context, ULONG registerId);

        // Variables used by the class
        TCHAR m_logFileName[MAX_PATH];
        TCHAR m_dumpFileName[MAX_PATH];
        LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
        _invalid_parameter_handler m_previousCrtHandler;
        FILE* m_reportFile;
        HANDLE m_dumpFile;
        HANDLE m_process;
        SymbolPairs m_symbols;
        std::stack<SymbolDetail> m_symbolDetails;
        bool m_alreadyCrashed;
        std::mutex m_alreadyCrashedLock;
        typedef NTSTATUS(NTAPI* pRtlGetVersion)(PRTL_OSVERSIONINFOW lpVersionInformation);
        pRtlGetVersion RtlGetVersion;

        void PushSymbolDetail();
        void PopSymbolDetail();
        void PrintSymbolDetail();
};

#define INIT_CRASH_HANDLER() \
    __pragma(warning(push)) \
    __pragma(warning(disable:4073))  /* C4073: initializers put in library initialization area */ \
    __pragma(init_seg(lib)) \
    WheatyExceptionReport g_WheatyExceptionReport; \
    __pragma(warning(pop))

#endif                                                      // _WHEATYEXCEPTIONREPORT_

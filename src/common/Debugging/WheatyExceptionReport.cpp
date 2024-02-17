//==========================================
// Matt Pietrek
// MSDN Magazine, 2002
// FILE: WheatyExceptionReport.CPP
//==========================================
#include "WheatyExceptionReport.h"
#include "Errors.h"
#include "GitRevision.h"
#include <algorithm>

#ifdef __clang__
// clang-cl doesn't have these hardcoded types available, correct ehdata_forceinclude.h that relies on it
#define _ThrowInfo ThrowInfo
#endif

#include <ehdata.h>
#include <rttidata.h>
#include <tlhelp32.h>
#include <tchar.h>

#include <comdef.h>
#include <WbemIdl.h>

#define CrashFolder _T("Crashes")
#pragma comment(linker, "/DEFAULTLIB:dbghelp.lib")
#pragma comment(linker, "/DEFAULTLIB:wbemuuid.lib")

inline LPTSTR ErrorMessage(DWORD dw)
{
    LPVOID lpMsgBuf;
    DWORD formatResult = FormatMessage(
                            FORMAT_MESSAGE_ALLOCATE_BUFFER |
                            FORMAT_MESSAGE_FROM_SYSTEM,
                            nullptr,
                            dw,
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                            (LPTSTR) &lpMsgBuf,
                            0, nullptr);
    if (formatResult != 0)
        return (LPTSTR)lpMsgBuf;
    else
    {
        LPTSTR msgBuf = (LPTSTR)LocalAlloc(LPTR, 30);
        sprintf(msgBuf, "Unknown error: %u", dw);
        return msgBuf;
    }

}

//============================== Global Variables =============================

//
// Declare the static variables of the WheatyExceptionReport class and force their initialization before any other static in the program
//
#pragma warning(push)
#pragma warning(disable: 4073) // C4073: initializers put in library initialization area
#pragma init_seg(lib)
TCHAR WheatyExceptionReport::m_szLogFileName[MAX_PATH];
TCHAR WheatyExceptionReport::m_szDumpFileName[MAX_PATH];
LPTOP_LEVEL_EXCEPTION_FILTER WheatyExceptionReport::m_previousFilter;
_invalid_parameter_handler WheatyExceptionReport::m_previousCrtHandler;
FILE* WheatyExceptionReport::m_hReportFile;
HANDLE WheatyExceptionReport::m_hDumpFile;
HANDLE WheatyExceptionReport::m_hProcess;
SymbolPairs WheatyExceptionReport::symbols;
std::stack<SymbolDetail> WheatyExceptionReport::symbolDetails;
bool WheatyExceptionReport::alreadyCrashed;
std::mutex WheatyExceptionReport::alreadyCrashedLock;
WheatyExceptionReport::pRtlGetVersion WheatyExceptionReport::RtlGetVersion;

// Declare global instance of class
WheatyExceptionReport g_WheatyExceptionReport;
#pragma warning(pop)

//============================== Class Methods =============================

WheatyExceptionReport::WheatyExceptionReport()             // Constructor
{
    // Install the unhandled exception filter function
    m_previousFilter = SetUnhandledExceptionFilter(WheatyUnhandledExceptionFilter);
    m_previousCrtHandler = _set_invalid_parameter_handler(WheatyCrtHandler);
    m_hProcess = GetCurrentProcess();
    alreadyCrashed = false;
    RtlGetVersion = (pRtlGetVersion)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "RtlGetVersion");
    if (!IsDebuggerPresent())
    {
        _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
        _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    }
}

//============
// Destructor
//============
WheatyExceptionReport::~WheatyExceptionReport()
{
    if (m_previousFilter)
        SetUnhandledExceptionFilter(m_previousFilter);
    if (m_previousCrtHandler)
        _set_invalid_parameter_handler(m_previousCrtHandler);
    ClearSymbols();
}

//===========================================================
// Entry point where control comes on an unhandled exception
//===========================================================
LONG WINAPI WheatyExceptionReport::WheatyUnhandledExceptionFilter(
PEXCEPTION_POINTERS pExceptionInfo)
{
    std::unique_lock<std::mutex> guard(alreadyCrashedLock);
    // Handle only 1 exception in the whole process lifetime
    if (alreadyCrashed)
        return EXCEPTION_EXECUTE_HANDLER;

    alreadyCrashed = true;

    TCHAR module_folder_name[MAX_PATH];
    GetModuleFileName(nullptr, module_folder_name, MAX_PATH);
    TCHAR* pos = _tcsrchr(module_folder_name, '\\');
    if (!pos)
        return 0;
    pos[0] = '\0';
    ++pos;

    TCHAR crash_folder_path[MAX_PATH];
    sprintf_s(crash_folder_path, "%s\\%s", module_folder_name, CrashFolder);
    if (!CreateDirectory(crash_folder_path, nullptr))
    {
        if (GetLastError() != ERROR_ALREADY_EXISTS)
            return 0;
    }

    SYSTEMTIME systime;
    GetLocalTime(&systime);
    sprintf(m_szDumpFileName, "%s\\%s_%s_[%u-%u_%u-%u-%u].dmp",
        crash_folder_path, GitRevision::GetHash(), pos, systime.wDay, systime.wMonth, systime.wHour, systime.wMinute, systime.wSecond);

    _stprintf(m_szLogFileName, _T("%s\\%s_%s_[%u-%u_%u-%u-%u].txt"),
        crash_folder_path, GitRevision::GetHash(), pos, systime.wDay, systime.wMonth, systime.wHour, systime.wMinute, systime.wSecond);

    m_hDumpFile = CreateFile(m_szDumpFileName,
        GENERIC_WRITE,
        0,
        nullptr,
        OPEN_ALWAYS,
        FILE_FLAG_WRITE_THROUGH,
        nullptr);

    if (m_hDumpFile)
    {
        MINIDUMP_EXCEPTION_INFORMATION info;
        info.ClientPointers = FALSE;
        info.ExceptionPointers = pExceptionInfo;
        info.ThreadId = GetCurrentThreadId();

        MINIDUMP_USER_STREAM additionalStream = {};
        MINIDUMP_USER_STREAM_INFORMATION additionalStreamInfo = {};

        if (pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ASSERTION_FAILURE && pExceptionInfo->ExceptionRecord->NumberParameters > 0)
        {
            additionalStream.Type = CommentStreamA;
            additionalStream.Buffer = reinterpret_cast<PVOID>(pExceptionInfo->ExceptionRecord->ExceptionInformation[0]);
            additionalStream.BufferSize = strlen(reinterpret_cast<char const*>(pExceptionInfo->ExceptionRecord->ExceptionInformation[0])) + 1;

            additionalStreamInfo.UserStreamArray = &additionalStream;
            additionalStreamInfo.UserStreamCount = 1;
        }

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
            m_hDumpFile, MiniDumpWithIndirectlyReferencedMemory, &info, &additionalStreamInfo, nullptr);

        CloseHandle(m_hDumpFile);
    }

    m_hReportFile = _tfopen(m_szLogFileName, _T("wb"));

    if (m_hReportFile)
    {
        GenerateExceptionReport(pExceptionInfo);

        fclose(m_hReportFile);
        m_hReportFile = nullptr;
    }

    if (m_previousFilter)
        return m_previousFilter(pExceptionInfo);
    else
        return EXCEPTION_EXECUTE_HANDLER/*EXCEPTION_CONTINUE_SEARCH*/;
}

void __cdecl WheatyExceptionReport::WheatyCrtHandler(wchar_t const* /*expression*/, wchar_t const* /*function*/, wchar_t const* /*file*/, unsigned int /*line*/, uintptr_t /*pReserved*/)
{
    RaiseException(EXCEPTION_ACCESS_VIOLATION, 0, 0, nullptr);
}

BOOL WheatyExceptionReport::_GetProcessorName(TCHAR* sProcessorName, DWORD maxcount)
{
    if (!sProcessorName)
        return FALSE;

    HKEY hKey;
    LONG lRet;
    lRet = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"),
        0, KEY_QUERY_VALUE, &hKey);
    if (lRet != ERROR_SUCCESS)
        return FALSE;
    TCHAR szTmp[2048];
    DWORD cntBytes = sizeof(szTmp);
    lRet = ::RegQueryValueEx(hKey, _T("ProcessorNameString"), nullptr, nullptr,
        (LPBYTE)szTmp, &cntBytes);
    if (lRet != ERROR_SUCCESS)
        return FALSE;
    ::RegCloseKey(hKey);
    sProcessorName[0] = '\0';
    // Skip spaces
    TCHAR* psz = szTmp;
    while (iswspace(*psz))
        ++psz;
    _tcsncpy(sProcessorName, psz, maxcount);
    return TRUE;
}

template<size_t size>
void ToTchar(wchar_t const* src, TCHAR (&dst)[size])
{
    if constexpr (std::is_same_v<TCHAR, char>)
        ::wcstombs_s(nullptr, dst, src, size);
    else
        ::wcscpy_s(dst, size, src);
}

BOOL WheatyExceptionReport::_GetWindowsVersion(TCHAR* szVersion, DWORD cntMax)
{
    *szVersion = _T('\0');

    if (_GetWindowsVersionFromWMI(szVersion, cntMax))
        return TRUE;

    // Try calling GetVersionEx using the OSVERSIONINFOEX structure.
    // If that fails, try using the OSVERSIONINFO structure.
    RTL_OSVERSIONINFOEXW osvi = { };
    osvi.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
    NTSTATUS bVersionEx = RtlGetVersion((PRTL_OSVERSIONINFOW)&osvi);
    if (FAILED(bVersionEx))
    {
        osvi.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);
        if (!RtlGetVersion((PRTL_OSVERSIONINFOW)&osvi))
            return FALSE;
    }

    TCHAR szCSDVersion[256];
    ToTchar(osvi.szCSDVersion, szCSDVersion);

    TCHAR wszTmp[128];
    switch (osvi.dwPlatformId)
    {
        // Windows NT product family.
        case VER_PLATFORM_WIN32_NT:
        {
        #if WINVER < 0x0500
            BYTE suiteMask = osvi.wReserved[0];
            BYTE productType = osvi.wReserved[1];
        #else
            WORD suiteMask = osvi.wSuiteMask;
            BYTE productType = osvi.wProductType;
        #endif                                          // WINVER < 0x0500

            // Test for the specific product family.
            if (osvi.dwMajorVersion == 10)
            {
                if (productType == VER_NT_WORKSTATION)
                    _tcsncat(szVersion, _T("Windows 10 "), cntMax);
                else
                    _tcsncat(szVersion, _T("Windows Server 2016 "), cntMax);
            }
            else if (osvi.dwMajorVersion == 6)
            {
                if (productType == VER_NT_WORKSTATION)
                {
                    if (osvi.dwMinorVersion == 3)
                        _tcsncat(szVersion, _T("Windows 8.1 "), cntMax);
                    else if (osvi.dwMinorVersion == 2)
                        _tcsncat(szVersion, _T("Windows 8 "), cntMax);
                    else if (osvi.dwMinorVersion == 1)
                        _tcsncat(szVersion, _T("Windows 7 "), cntMax);
                    else
                        _tcsncat(szVersion, _T("Windows Vista "), cntMax);
                }
                else if (osvi.dwMinorVersion == 3)
                    _tcsncat(szVersion, _T("Windows Server 2012 R2 "), cntMax);
                else if (osvi.dwMinorVersion == 2)
                    _tcsncat(szVersion, _T("Windows Server 2012 "), cntMax);
                else if (osvi.dwMinorVersion == 1)
                    _tcsncat(szVersion, _T("Windows Server 2008 R2 "), cntMax);
                else
                    _tcsncat(szVersion, _T("Windows Server 2008 "), cntMax);
            }
            else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
                _tcsncat(szVersion, _T("Microsoft Windows Server 2003 "), cntMax);
            else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
                _tcsncat(szVersion, _T("Microsoft Windows XP "), cntMax);
            else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
                _tcsncat(szVersion, _T("Microsoft Windows 2000 "), cntMax);
            else if (osvi.dwMajorVersion <= 4)
                _tcsncat(szVersion, _T("Microsoft Windows NT "), cntMax);

            // Test for specific product on Windows NT 4.0 SP6 and later.
            if (bVersionEx >= 0)
            {
                // Test for the workstation type.
                if (productType == VER_NT_WORKSTATION)
                {
                    if (osvi.dwMajorVersion == 4)
                        _tcsncat(szVersion, _T("Workstation 4.0 "), cntMax);
                    else if (suiteMask & VER_SUITE_PERSONAL)
                        _tcsncat(szVersion, _T("Home Edition "), cntMax);
                    else if (suiteMask & VER_SUITE_EMBEDDEDNT)
                        _tcsncat(szVersion, _T("Embedded "), cntMax);
                    else
                        _tcsncat(szVersion, _T("Professional "), cntMax);
                }
                // Test for the server type.
                else if (productType == VER_NT_SERVER)
                {
                    if (osvi.dwMajorVersion == 6 || osvi.dwMajorVersion == 10)
                    {
                        if (suiteMask & VER_SUITE_SMALLBUSINESS_RESTRICTED)
                            _tcsncat(szVersion, _T("Essentials "), cntMax);
                        else if (suiteMask & VER_SUITE_DATACENTER)
                            _tcsncat(szVersion, _T("Datacenter "), cntMax);
                        else if (suiteMask & VER_SUITE_ENTERPRISE)
                            _tcsncat(szVersion, _T("Enterprise "), cntMax);
                        else
                            _tcsncat(szVersion, _T("Standard "), cntMax);
                    }
                    else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
                    {
                        if (suiteMask & VER_SUITE_DATACENTER)
                            _tcsncat(szVersion, _T("Datacenter Edition "), cntMax);
                        else if (suiteMask & VER_SUITE_ENTERPRISE)
                            _tcsncat(szVersion, _T("Enterprise Edition "), cntMax);
                        else if (suiteMask == VER_SUITE_BLADE)
                            _tcsncat(szVersion, _T("Web Edition "), cntMax);
                        else
                            _tcsncat(szVersion, _T("Standard Edition "), cntMax);
                    }
                    else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
                    {
                        if (suiteMask & VER_SUITE_DATACENTER)
                            _tcsncat(szVersion, _T("Datacenter Server "), cntMax);
                        else if (suiteMask & VER_SUITE_ENTERPRISE)
                            _tcsncat(szVersion, _T("Advanced Server "), cntMax);
                        else
                            _tcsncat(szVersion, _T("Server "), cntMax);
                    }
                    else                                        // Windows NT 4.0
                    {
                        if (suiteMask & VER_SUITE_ENTERPRISE)
                            _tcsncat(szVersion, _T("Server 4.0, Enterprise Edition "), cntMax);
                        else
                            _tcsncat(szVersion, _T("Server 4.0 "), cntMax);
                    }
                }
            }

            // Display service pack (if any) and build number.
            if (osvi.dwMajorVersion == 4 && _tcsicmp(szCSDVersion, _T("Service Pack 6")) == 0)
            {
                HKEY hKey;
                LONG lRet;

                // Test for SP6 versus SP6a.
                lRet = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009"), 0, KEY_QUERY_VALUE, &hKey);
                if (lRet == ERROR_SUCCESS)
                {
                    _stprintf(wszTmp, _T("Service Pack 6a (Version %d.%d, Build %d)"),
                        osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                    _tcsncat(szVersion, wszTmp, cntMax);
                }
                else                                            // Windows NT 4.0 prior to SP6a
                {
                    _stprintf(wszTmp, _T("%s (Version %d.%d, Build %d)"),
                        szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                    _tcsncat(szVersion, wszTmp, cntMax);
                }
                ::RegCloseKey(hKey);
            }
            else                                                // Windows NT 3.51 and earlier or Windows 2000 and later
            {
                if (!_tcslen(szCSDVersion))
                    _stprintf(wszTmp, _T("(Version %d.%d, Build %d)"),
                        osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                else
                    _stprintf(wszTmp, _T("%s (Version %d.%d, Build %d)"),
                        szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                _tcsncat(szVersion, wszTmp, cntMax);
            }
            break;
        }
        default:
            _stprintf(wszTmp, _T("%s (Version %d.%d, Build %d)"),
                szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
            _tcsncat(szVersion, wszTmp, cntMax);
            break;
    }

    return TRUE;
}

BOOL WheatyExceptionReport::_GetWindowsVersionFromWMI(TCHAR* szVersion, DWORD cntMax)
{
    // Step 1: --------------------------------------------------
    // Initialize COM. ------------------------------------------
    HRESULT hres = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hres))
        return FALSE;

    std::shared_ptr<void> com(nullptr, [](void*)
    {
        CoUninitialize();
    });

    // Step 2: --------------------------------------------------
    // Set general COM security levels --------------------------
    hres = CoInitializeSecurity(
        nullptr,
        -1,                          // COM authentication
        nullptr,                     // Authentication services
        nullptr,                     // Reserved
        RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
        RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
        nullptr,                     // Authentication info
        EOAC_NONE,                   // Additional capabilities
        nullptr                      // Reserved
    );

    if (FAILED(hres))
        return FALSE;

    // Step 3: ---------------------------------------------------
    // Obtain the initial locator to WMI -------------------------
    std::shared_ptr<IWbemLocator> loc = []() -> std::shared_ptr<IWbemLocator>
    {
        IWbemLocator* tmp = nullptr;
        HRESULT hres = CoCreateInstance(
            CLSID_WbemLocator,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_IWbemLocator,
            reinterpret_cast<LPVOID*>(&tmp));

        if (FAILED(hres))
            return nullptr;

        return { tmp, [](IWbemLocator* ptr) { if (ptr) ptr->Release(); } };
    }();

    if (!loc)
        return FALSE;

    // Step 4: -----------------------------------------------------
    // Connect to the root\cimv2 namespace with
    // the current user and obtain pointer pSvc
    // to make IWbemServices calls.
    std::shared_ptr<IWbemServices> svc = [loc]() ->std::shared_ptr<IWbemServices>
    {
        IWbemServices* tmp = nullptr;
        HRESULT hres = loc->ConnectServer(
            bstr_t(L"ROOT\\CIMV2"),         // Object path of WMI namespace
            nullptr,                        // User name. NULL = current user
            nullptr,                        // User password. NULL = current
            nullptr,                        // Locale. NULL indicates current
            WBEM_FLAG_CONNECT_USE_MAX_WAIT, // Security flags.
            nullptr,                        // Authority (for example, Kerberos)
            nullptr,                        // Context object
            &tmp                            // pointer to IWbemServices proxy
        );

        if (FAILED(hres))
            return nullptr;

        return { tmp, [](IWbemServices* ptr) { if (ptr) ptr->Release(); } };
    }();

    if (!svc)
        return FALSE;

    // Step 5: --------------------------------------------------
    // Set security levels on the proxy -------------------------
    hres = CoSetProxyBlanket(
        svc.get(),                   // Indicates the proxy to set
        RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
        RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
        nullptr,                     // Server principal name
        RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx
        RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
        nullptr,                     // client identity
        EOAC_NONE                    // proxy capabilities
    );

    if (FAILED(hres))
        return FALSE;

    // Step 6: --------------------------------------------------
    // Use the IWbemServices pointer to make requests of WMI ----

    // For example, get the name of the operating system
    std::shared_ptr<IEnumWbemClassObject> queryResult = [svc]() -> std::shared_ptr<IEnumWbemClassObject>
    {
        IEnumWbemClassObject* tmp = nullptr;
        HRESULT hres = svc->ExecQuery(
            bstr_t("WQL"),
            bstr_t("SELECT Caption, CSDVersion FROM Win32_OperatingSystem"),
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &tmp);

        if (FAILED(hres))
            return nullptr;

        return { tmp, [](IEnumWbemClassObject* ptr) { if (ptr) ptr->Release(); } };
    }();

    BOOL result = FALSE;
    // Step 7: -------------------------------------------------
    // Get the data from the query in step 6 -------------------
    if (queryResult)
    {
        do
        {
            IWbemClassObject* fields = nullptr;

            ULONG rows = 0;
            queryResult->Next(WBEM_INFINITE, 1, &fields, &rows);
            if (!rows)
                break;

            VARIANT field;
            VariantInit(&field);
            fields->Get(L"Caption", 0, &field, nullptr, nullptr);
            TCHAR buf[256] = { };
            ToTchar(field.bstrVal, buf);
            _tcsncat(szVersion, buf, cntMax);
            VariantClear(&field);

            fields->Get(L"CSDVersion", 0, &field, nullptr, nullptr);
            if (field.vt == VT_BSTR)
            {
                _tcsncat(szVersion, _T(" "), cntMax);
                memset(buf, 0, sizeof(buf));
                ToTchar(field.bstrVal, buf);
                if (strlen(buf))
                    _tcsncat(szVersion, buf, cntMax);
            }
            VariantClear(&field);

            fields->Release();

            result = TRUE;
        } while (true);
    }

    return result;
}

void WheatyExceptionReport::PrintSystemInfo()
{
    SYSTEM_INFO SystemInfo;
    ::GetSystemInfo(&SystemInfo);

    MEMORYSTATUS MemoryStatus;
    MemoryStatus.dwLength = sizeof (MEMORYSTATUS);
    ::GlobalMemoryStatus(&MemoryStatus);
    TCHAR sString[1024];
    Log(_T("//=====================================================\r\n"));
    if (_GetProcessorName(sString, std::size(sString)))
        Log(_T("*** Hardware ***\r\nProcessor: %s\r\nNumber Of Processors: %d\r\nPhysical Memory: %d KB (Available: %d KB)\r\nCommit Charge Limit: %d KB\r\n"),
            sString, SystemInfo.dwNumberOfProcessors, MemoryStatus.dwTotalPhys/0x400, MemoryStatus.dwAvailPhys/0x400, MemoryStatus.dwTotalPageFile/0x400);
    else
        Log(_T("*** Hardware ***\r\nProcessor: <unknown>\r\nNumber Of Processors: %d\r\nPhysical Memory: %d KB (Available: %d KB)\r\nCommit Charge Limit: %d KB\r\n"),
            SystemInfo.dwNumberOfProcessors, MemoryStatus.dwTotalPhys/0x400, MemoryStatus.dwAvailPhys/0x400, MemoryStatus.dwTotalPageFile/0x400);

    if (_GetWindowsVersion(sString, std::size(sString)))
        Log(_T("\r\n*** Operation System ***\r\n%s\r\n"), sString);
    else
        Log(_T("\r\n*** Operation System:\r\n<unknown>\r\n"));
}

//===========================================================================
void WheatyExceptionReport::printTracesForAllThreads(bool bWriteVariables)
{
  THREADENTRY32 te32;

  DWORD dwOwnerPID = GetCurrentProcessId();
  DWORD dwCurrentTID = GetCurrentThreadId();
  m_hProcess = GetCurrentProcess();
  // Take a snapshot of all running threads
  HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  if (hThreadSnap == INVALID_HANDLE_VALUE)
    return;

  // Fill in the size of the structure before using it.
  te32.dwSize = sizeof(THREADENTRY32);

  // Retrieve information about the first thread,
  // and exit if unsuccessful
  if (!Thread32First(hThreadSnap, &te32))
  {
    CloseHandle(hThreadSnap);    // Must clean up the
                                   //   snapshot object!
    return;
  }

  // Now walk the thread list of the system,
  // and display information about each thread
  // associated with the specified process
  do
  {
    if (te32.th32OwnerProcessID == dwOwnerPID && te32.th32ThreadID != dwCurrentTID)
    {
        CONTEXT context;
        context.ContextFlags = 0xffffffff;
        HANDLE threadHandle = OpenThread(THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION, false, te32.th32ThreadID);
        if (threadHandle)
        {
            if (GetThreadContext(threadHandle, &context))
                WriteStackDetails(&context, bWriteVariables, threadHandle);
            CloseHandle(threadHandle);
        }
    }
  } while (Thread32Next(hThreadSnap, &te32));

//  Don't forget to clean up the snapshot object.
  CloseHandle(hThreadSnap);
}

//===========================================================================
// Open the report file, and write the desired information to it.  Called by
// WheatyUnhandledExceptionFilter
//===========================================================================
void WheatyExceptionReport::GenerateExceptionReport(
PEXCEPTION_POINTERS pExceptionInfo)
{
    __try
    {
        SYSTEMTIME systime;
        GetLocalTime(&systime);

        // Start out with a banner
        Log(_T("Revision: %s\r\n"), GitRevision::GetFullVersion());
        Log(_T("Date %u:%u:%u. Time %u:%u \r\n"), systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute);
        PEXCEPTION_RECORD pExceptionRecord = pExceptionInfo->ExceptionRecord;

        PrintSystemInfo();
        // First print information about the type of fault
        Log(_T("\r\n//=====================================================\r\n"));
        Log(_T("Exception code: %08X %s\r\n"),
            pExceptionRecord->ExceptionCode,
            GetExceptionString(pExceptionRecord->ExceptionCode));
        if (pExceptionRecord->ExceptionCode == EXCEPTION_ASSERTION_FAILURE && pExceptionRecord->NumberParameters >= 2)
        {
            pExceptionRecord->ExceptionAddress = reinterpret_cast<PVOID>(pExceptionRecord->ExceptionInformation[1]);
            Log(_T("Assertion message: %s\r\n"), pExceptionRecord->ExceptionInformation[0]);
        }

        // Now print information about where the fault occured
        TCHAR szFaultingModule[MAX_PATH];
        DWORD section;
        DWORD_PTR offset;
        GetLogicalAddress(pExceptionRecord->ExceptionAddress,
            szFaultingModule,
            sizeof(szFaultingModule),
            section, offset);

#if defined(_M_IX86) || defined(_M_ARM)
        Log(_T("Fault address:  %08X %02X:%08X %s\r\n"),
            pExceptionRecord->ExceptionAddress,
            section, offset, szFaultingModule);
#endif
#if defined(_M_X64) || defined(_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined (_M_ARM64EC)
        Log(_T("Fault address:  %016I64X %02X:%016I64X %s\r\n"),
            pExceptionRecord->ExceptionAddress,
            section, offset, szFaultingModule);
#endif

        PCONTEXT pCtx = pExceptionInfo->ContextRecord;

        // Show the registers
#ifdef _M_IX86                                          // X86 Only!
        Log(_T("\r\nRegisters:\r\n"));

        Log(_T("EAX:%08X\r\nEBX:%08X\r\nECX:%08X\r\nEDX:%08X\r\nESI:%08X\r\nEDI:%08X\r\n")
            , pCtx->Eax, pCtx->Ebx, pCtx->Ecx, pCtx->Edx,
            pCtx->Esi, pCtx->Edi);

        Log(_T("CS:EIP:%04X:%08X\r\n"), pCtx->SegCs, pCtx->Eip);
        Log(_T("SS:ESP:%04X:%08X  EBP:%08X\r\n"),
            pCtx->SegSs, pCtx->Esp, pCtx->Ebp);
        Log(_T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
            pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs);
        Log(_T("Flags:%08X\r\n"), pCtx->EFlags);
#endif

#ifdef _M_X64
        Log(_T("\r\nRegisters:\r\n"));
        Log(_T("RAX:%016I64X\r\nRBX:%016I64X\r\nRCX:%016I64X\r\nRDX:%016I64X\r\nRSI:%016I64X\r\nRDI:%016I64X\r\n")
            _T("R8: %016I64X\r\nR9: %016I64X\r\nR10:%016I64X\r\nR11:%016I64X\r\nR12:%016I64X\r\nR13:%016I64X\r\nR14:%016I64X\r\nR15:%016I64X\r\n")
            , pCtx->Rax, pCtx->Rbx, pCtx->Rcx, pCtx->Rdx,
            pCtx->Rsi, pCtx->Rdi, pCtx->R8, pCtx->R9, pCtx->R10, pCtx->R11, pCtx->R12, pCtx->R13, pCtx->R14, pCtx->R15);
        Log(_T("CS:RIP:%04X:%016I64X\r\n"), pCtx->SegCs, pCtx->Rip);
        Log(_T("SS:RSP:%04X:%016I64X  RBP:%08X\r\n"),
            pCtx->SegSs, pCtx->Rsp, pCtx->Rbp);
        Log(_T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
            pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs);
        Log(_T("Flags:%08X\r\n"), pCtx->EFlags);
#endif

#ifdef _M_ARM64
        Log(_T("\r\nRegisters:\r\n"));
        Log(_T("X0:%016I64X\r\nX1:%016I64X\r\nX2:%016I64X\r\nX3:%016I64X\r\nX4:%016I64X\r\nX5:%016I64X\r\n"),
            _T("X6:%016I64X\r\nX7:%016I64X\r\nX8:%016I64X\r\nX9:%016I64X\r\nX10:%016I64X\r\nX11:%016I64X\r\nX12:%016I64X\r\nX13:%016I64X\r\n"),
            _T("X14:%016I64X\r\nX15:%016I64X\r\nX16:%016I64X\r\nX17:%016I64X\r\nX18:%016I64X\r\nX19:%016I64X\r\nX20:%016I64X\r\nX21:%016I64X\r\n"),
            _T("X22:%016I64X\r\nX23:%016I64X\r\nX24:%016I64X\r\nX25:%016I64X\r\nX26:%016I64X\r\nX27:%016I64X\r\nX28:%016I64X\r\n"),
            pCtx->X0, pCtx->X1, pCtx->X2, pCtx->X3, pCtx->X4, pCtx->X5,
            pCtx->X6, pCtx->X7, pCtx->X8, pCtx->X9, pCtx->X10, pCtx->X11, pCtx->X12, pCtx->X13,
            pCtx->X14, pCtx->X15, pCtx->X16, pCtx->X17, pCtx->X18, pCtx->X19, pCtx->X20, pCtx->X21,
            pCtx->X22, pCtx->X23, pCtx->X24, pCtx->X25, pCtx->X26, pCtx->X27, pCtx->X28);
        Log(_T("LR:%016I64X\r\n"), pCtx->Lr);
        Log(_T("PC:%016I64X\r\n"), pCtx->Pc);
        Log(_T("SP:%016I64X FP:%016I64X\r\n"), pCtx->Sp, pCtx->Fp);
        Log(_T("Flags:%08X\r\n"), pCtx->Cpsr);
#endif

        SymSetOptions(SYMOPT_DEFERRED_LOADS);

        // Initialize DbgHelp
        if (!SymInitialize(GetCurrentProcess(), nullptr, TRUE))
        {
            Log(_T("\r\n"));
            Log(_T("----\r\n"));
            Log(_T("SYMBOL HANDLER ERROR (THIS IS NOT THE CRASH ERROR)\r\n\r\n"));
            Log(_T("Couldn't initialize symbol handler for process when generating crash report\r\n"));
            Log(_T("Error: %s\r\n"), ErrorMessage(GetLastError()));
            Log(_T("THE BELOW CALL STACKS MIGHT HAVE MISSING OR INACCURATE FILE/FUNCTION NAMES\r\n\r\n"));
            Log(_T("----\r\n"));
        }

        if (pExceptionRecord->ExceptionCode == 0xE06D7363 && pExceptionRecord->NumberParameters >= 2)
        {
            PVOID exceptionObject = reinterpret_cast<PVOID>(pExceptionRecord->ExceptionInformation[1]);
            ThrowInfo const* throwInfo = reinterpret_cast<ThrowInfo const*>(pExceptionRecord->ExceptionInformation[2]);
#if _EH_RELATIVE_TYPEINFO
            // When _EH_RELATIVE_TYPEINFO is defined, the pointers need to be retrieved with some pointer math
            auto resolveExceptionRVA = [pExceptionRecord](int32 rva) -> DWORD_PTR
            {
                return rva + (pExceptionRecord->NumberParameters >= 4 ? pExceptionRecord->ExceptionInformation[3] : 0);
            };
#else
            // Otherwise the pointers are already there in the API types
            auto resolveExceptionRVA = [](void const* input) -> void const* { return input; };
#endif

            CatchableTypeArray const* catchables = reinterpret_cast<CatchableTypeArray const*>(resolveExceptionRVA(throwInfo->pCatchableTypeArray));
            CatchableType const* catchable = catchables->nCatchableTypes ? reinterpret_cast<CatchableType const*>(resolveExceptionRVA(catchables->arrayOfCatchableTypes[0])) : nullptr;
            TypeDescriptor const* exceptionTypeinfo = catchable ? reinterpret_cast<TypeDescriptor const*>(resolveExceptionRVA(catchable->pType)) : nullptr;

            if (exceptionTypeinfo)
            {
                void* stdExceptionTypeInfo = []() -> void*
                {
                    try
                    {
                        std::exception fake;
                        return __RTtypeid(&fake);
                    }
                    catch (...)
                    {
                        return nullptr;
                    }
                }();
                std::exception const* exceptionPtr = [](void* object, TypeDescriptor const* typeInfo, void* stdExceptionTypeInfo) -> std::exception const*
                {
                    try
                    {
                        // real_type descriptor is obtained by parsing throwinfo
                        // equivalent to expression like this
                        // std::exception* e = object;
                        // real_type* r = dynamic_cast<real_type*>(e);
                        // return r;
                        return reinterpret_cast<std::exception const*>(__RTDynamicCast(object, 0, stdExceptionTypeInfo, (void*)typeInfo, false));
                    }
                    catch (...)
                    {
                        return nullptr;
                    }
                }(exceptionObject, exceptionTypeinfo, stdExceptionTypeInfo);

                // dynamic_cast<type>(variable_that_already_has_that_type) is optimized away by compiler and attempting to call __RTDynamicCast fails for it
                if (!exceptionPtr && exceptionTypeinfo == stdExceptionTypeInfo)
                    exceptionPtr = reinterpret_cast<std::exception*>(exceptionObject);

                Log(_T("\r\nUncaught C++ exception info:"));
                if (exceptionPtr)
                    Log(_T(" %s"), exceptionPtr->what());

                Log(_T("\r\n"));

                char undName[MAX_SYM_NAME] = { };
                if (UnDecorateSymbolName(&exceptionTypeinfo->name[1], &undName[0], MAX_SYM_NAME, UNDNAME_32_BIT_DECODE | UNDNAME_NAME_ONLY | UNDNAME_NO_ARGUMENTS))
                {
                    char buf[MAX_SYM_NAME + sizeof(SYMBOL_INFO)] = { };
                    PSYMBOL_INFO sym = (PSYMBOL_INFO)&buf[0];
                    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                    sym->MaxNameLen = MAX_SYM_NAME;
                    if (SymGetTypeFromName(m_hProcess, (ULONG64)GetModuleHandle(nullptr), undName, sym))
                    {
                        sym->Address = pExceptionRecord->ExceptionInformation[1];
                        sym->Flags = 0;
                        char const* variableName = "uncaught_exception";
                        memset(sym->Name, 0, MAX_SYM_NAME);
                        memcpy(sym->Name, variableName, strlen(variableName));
                        FormatSymbolValue(sym, nullptr);
                    }
                }
            }
        }

        CONTEXT trashableContext = *pCtx;

        WriteStackDetails(&trashableContext, false, nullptr);
        printTracesForAllThreads(false);

        //    #ifdef _M_IX86                                          // X86 Only!

        Log(_T("========================\r\n"));
        Log(_T("Local Variables And Parameters\r\n"));

        trashableContext = *pCtx;
        WriteStackDetails(&trashableContext, true, nullptr);
        printTracesForAllThreads(true);

        SymCleanup(GetCurrentProcess());

        Log(_T("\r\n"));
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        Log(_T("Error writing the crash log\r\n"));
    }
}

//======================================================================
// Given an exception code, returns a pointer to a static string with a
// description of the exception
//======================================================================
LPCTSTR WheatyExceptionReport::GetExceptionString(DWORD dwCode)
{
    #define EXCEPTION(x) case EXCEPTION_##x: return _T(#x);

    switch (dwCode)
    {
        EXCEPTION(ACCESS_VIOLATION)
        EXCEPTION(DATATYPE_MISALIGNMENT)
        EXCEPTION(BREAKPOINT)
        EXCEPTION(SINGLE_STEP)
        EXCEPTION(ARRAY_BOUNDS_EXCEEDED)
        EXCEPTION(FLT_DENORMAL_OPERAND)
        EXCEPTION(FLT_DIVIDE_BY_ZERO)
        EXCEPTION(FLT_INEXACT_RESULT)
        EXCEPTION(FLT_INVALID_OPERATION)
        EXCEPTION(FLT_OVERFLOW)
        EXCEPTION(FLT_STACK_CHECK)
        EXCEPTION(FLT_UNDERFLOW)
        EXCEPTION(INT_DIVIDE_BY_ZERO)
        EXCEPTION(INT_OVERFLOW)
        EXCEPTION(PRIV_INSTRUCTION)
        EXCEPTION(IN_PAGE_ERROR)
        EXCEPTION(ILLEGAL_INSTRUCTION)
        EXCEPTION(NONCONTINUABLE_EXCEPTION)
        EXCEPTION(STACK_OVERFLOW)
        EXCEPTION(INVALID_DISPOSITION)
        EXCEPTION(GUARD_PAGE)
        EXCEPTION(INVALID_HANDLE)
        case 0xE06D7363: return _T("Unhandled C++ exception");
    }

    // If not one of the "known" exceptions, try to get the string
    // from NTDLL.DLL's message table.

    static TCHAR szBuffer[512] = { 0 };

    FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE,
        GetModuleHandle(_T("NTDLL.DLL")),
        dwCode, 0, szBuffer, sizeof(szBuffer), nullptr);

    return szBuffer;
}

//=============================================================================
// Given a linear address, locates the module, section, and offset containing
// that address.
//
// Note: the szModule paramater buffer is an output buffer of length specified
// by the len parameter (in characters!)
//=============================================================================
BOOL WheatyExceptionReport::GetLogicalAddress(
PVOID addr, PTSTR szModule, DWORD len, DWORD& section, DWORD_PTR& offset)
{
    MEMORY_BASIC_INFORMATION mbi;

    if (!VirtualQuery(addr, &mbi, sizeof(mbi)))
        return FALSE;

    DWORD_PTR hMod = (DWORD_PTR)mbi.AllocationBase;

    if (!hMod)
        return FALSE;

    if (!GetModuleFileName((HMODULE)hMod, szModule, len))
        return FALSE;

    // Point to the DOS header in memory
    PIMAGE_DOS_HEADER pDosHdr = (PIMAGE_DOS_HEADER)hMod;

    // From the DOS header, find the NT (PE) header
    PIMAGE_NT_HEADERS pNtHdr = (PIMAGE_NT_HEADERS)(hMod + DWORD_PTR(pDosHdr->e_lfanew));

    PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION(pNtHdr);

    DWORD_PTR rva = (DWORD_PTR)addr - hMod;                         // RVA is offset from module load address

    // Iterate through the section table, looking for the one that encompasses
    // the linear address.
    for (unsigned i = 0;
        i < pNtHdr->FileHeader.NumberOfSections;
        i++, pSection++)
    {
        DWORD_PTR sectionStart = pSection->VirtualAddress;
        DWORD_PTR sectionEnd = sectionStart
            + DWORD_PTR(std::max(pSection->SizeOfRawData, pSection->Misc.VirtualSize));

        // Is the address in this section???
        if ((rva >= sectionStart) && (rva <= sectionEnd))
        {
            // Yes, address is in the section.  Calculate section and offset,
            // and store in the "section" & "offset" params, which were
            // passed by reference.
            section = i+1;
            offset = rva - sectionStart;
            return TRUE;
        }
    }

    return FALSE;                                           // Should never get here!
}

// It contains SYMBOL_INFO structure plus additional
// space for the name of the symbol
struct CSymbolInfoPackage : public SYMBOL_INFO_PACKAGE
{
    CSymbolInfoPackage()
    {
        si.SizeOfStruct = sizeof(SYMBOL_INFO);
        si.MaxNameLen   = sizeof(name);
    }
};

//============================================================
// Walks the stack, and writes the results to the report file
//============================================================
void WheatyExceptionReport::WriteStackDetails(
PCONTEXT pContext,
bool bWriteVariables, HANDLE pThreadHandle)                                      // true if local/params should be output
{
    Log(_T("\r\nCall stack:\r\n"));

    Log(_T("Address   Frame     Function      SourceFile\r\n"));

    DWORD dwMachineType = 0;
    // Could use SymSetOptions here to add the SYMOPT_DEFERRED_LOADS flag

    STACKFRAME64 sf;
    memset(&sf, 0, sizeof(sf));

    // Initialize the STACKFRAME structure for the first call.
    sf.AddrPC.Mode         = AddrModeFlat;
    sf.AddrStack.Mode      = AddrModeFlat;
    sf.AddrFrame.Mode      = AddrModeFlat;

#ifdef _M_IX86
    sf.AddrPC.Offset       = pContext->Eip;
    sf.AddrStack.Offset    = pContext->Esp;
    sf.AddrFrame.Offset    = pContext->Ebp;
    dwMachineType = IMAGE_FILE_MACHINE_I386;
#elif defined(_M_X64)
    sf.AddrPC.Offset       = pContext->Rip;
    sf.AddrStack.Offset    = pContext->Rsp;
    sf.AddrFrame.Offset    = pContext->Rbp;
    dwMachineType = IMAGE_FILE_MACHINE_AMD64;
#elif defined(_M_ARM64)
    sf.AddrPC.Offset       = pContext->Pc;
    sf.AddrStack.Offset    = pContext->Sp;
    sf.AddrFrame.Offset    = pContext->Fp;
    dwMachineType = IMAGE_FILE_MACHINE_ARM64;
#endif

    for (;;)
    {
        // Get the next stack frame
        if (! StackWalk64(dwMachineType,
            m_hProcess,
            pThreadHandle != nullptr ? pThreadHandle : GetCurrentThread(),
            &sf,
            pContext,
            nullptr,
            SymFunctionTableAccess64,
            SymGetModuleBase64,
            nullptr))
            break;
        if (0 == sf.AddrFrame.Offset)                     // Basic sanity check to make sure
            break;                                          // the frame is OK.  Bail if not.
#ifdef _M_IX86
        Log(_T("%08X  %08X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset);
#elif defined(_M_X64) || defined(_M_ARM64)
        Log(_T("%016I64X  %016I64X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset);
#endif

        DWORD64 symDisplacement = 0;                        // Displacement of the input address,
        // relative to the start of the symbol

        // Get the name of the function for this stack frame entry
        CSymbolInfoPackage sip;
        if (SymFromAddr(
            m_hProcess,                                     // Process handle of the current process
            sf.AddrPC.Offset,                               // Symbol address
            &symDisplacement,                               // Address of the variable that will receive the displacement
            &sip.si))                                       // Address of the SYMBOL_INFO structure (inside "sip" object)
        {
            Log(_T("%hs+%I64X"), sip.si.Name, symDisplacement);

        }
        else                                                // No symbol found.  Print out the logical address instead.
        {
            TCHAR szModule[MAX_PATH] = _T("");
            DWORD section = 0;
            DWORD_PTR offset = 0;

            GetLogicalAddress((PVOID)sf.AddrPC.Offset,
                szModule, sizeof(szModule), section, offset);
#ifdef _M_IX86
            Log(_T("%04X:%08X %s"), section, offset, szModule);
#elif defined(_M_X64) || defined(_M_ARM64)
            Log(_T("%04X:%016I64X %s"), section, offset, szModule);
#endif
        }

        // Get the source line for this stack frame entry
        IMAGEHLP_LINE64 lineInfo = { sizeof(IMAGEHLP_LINE64) };
        DWORD dwLineDisplacement;
        if (SymGetLineFromAddr64(m_hProcess, sf.AddrPC.Offset,
            &dwLineDisplacement, &lineInfo))
        {
            Log(_T("  %s line %u"), lineInfo.FileName, lineInfo.LineNumber);
        }

        Log(_T("\r\n"));

        // Write out the variables, if desired
        if (bWriteVariables)
        {
            // Use SymSetContext to get just the locals/params for this frame
            IMAGEHLP_STACK_FRAME imagehlpStackFrame;
            imagehlpStackFrame.InstructionOffset = sf.AddrPC.Offset;
            SymSetContext(m_hProcess, &imagehlpStackFrame, nullptr);

            // Enumerate the locals/parameters
            EnumerateSymbolsCallbackContext ctx;
            ctx.sf = &sf;
            ctx.context = pContext;
            SymEnumSymbols(m_hProcess, 0, nullptr, EnumerateSymbolsCallback, &ctx);

            Log(_T("\r\n"));
        }
    }

}

//////////////////////////////////////////////////////////////////////////////
// The function invoked by SymEnumSymbols
//////////////////////////////////////////////////////////////////////////////

BOOL CALLBACK
WheatyExceptionReport::EnumerateSymbolsCallback(
PSYMBOL_INFO  pSymInfo,
ULONG         /*SymbolSize*/,
PVOID         UserContext)
{
    __try
    {
        ClearSymbols();
        FormatSymbolValue(pSymInfo, (EnumerateSymbolsCallbackContext*)UserContext);

    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        Log(_T("punting on symbol %s, partial output:\r\n"), pSymInfo->Name);
    }

    return TRUE;
}

Optional<DWORD_PTR> WheatyExceptionReport::GetIntegerRegisterValue(PCONTEXT context, ULONG registerId)
{
#define REG_L(x) ((BYTE)(((DWORD_PTR)(x)) & 0xff))
#define REG_H(x) ((BYTE)((((DWORD_PTR)(x)) >> 8) & 0xff))
#define REG_X(x) ((WORD)(((DWORD_PTR)(x)) & 0xffff))
#define REG_E(x) ((DWORD)(((DWORD_PTR)(x)) & 0xffffffff))
#define REG_R(x) ((DWORD64)(((DWORD_PTR)(x)) & 0xffffffffffffffff))
#define CPU_REG(reg, field, part) case reg: return part(context->field);
    switch (registerId)
    {
#ifdef _M_IX86
        CPU_REG(CV_REG_AL, Eax, REG_L);
        CPU_REG(CV_REG_CL, Ecx, REG_L);
        CPU_REG(CV_REG_DL, Edx, REG_L);
        CPU_REG(CV_REG_BL, Ebx, REG_L);
        CPU_REG(CV_REG_AH, Eax, REG_H);
        CPU_REG(CV_REG_CH, Ecx, REG_H);
        CPU_REG(CV_REG_DH, Edx, REG_H);
        CPU_REG(CV_REG_BH, Ebx, REG_H);
        CPU_REG(CV_REG_AX, Eax, REG_X);
        CPU_REG(CV_REG_CX, Ecx, REG_X);
        CPU_REG(CV_REG_DX, Edx, REG_X);
        CPU_REG(CV_REG_BX, Ebx, REG_X);
        CPU_REG(CV_REG_SP, Esp, REG_X);
        CPU_REG(CV_REG_BP, Ebp, REG_X);
        CPU_REG(CV_REG_SI, Esi, REG_X);
        CPU_REG(CV_REG_DI, Edi, REG_X);
        CPU_REG(CV_REG_EAX, Eax, REG_E);
        CPU_REG(CV_REG_ECX, Ecx, REG_E);
        CPU_REG(CV_REG_EDX, Edx, REG_E);
        CPU_REG(CV_REG_EBX, Ebx, REG_E);
        CPU_REG(CV_REG_ESP, Esp, REG_E);
        CPU_REG(CV_REG_EBP, Ebp, REG_E);
        CPU_REG(CV_REG_ESI, Esi, REG_E);
        CPU_REG(CV_REG_EDI, Edi, REG_E);
        CPU_REG(CV_REG_EIP, Eip, REG_E);
#elif defined (_M_X64)
        CPU_REG(CV_AMD64_AL, Rax, REG_L);
        CPU_REG(CV_AMD64_CL, Rcx, REG_L);
        CPU_REG(CV_AMD64_DL, Rdx, REG_L);
        CPU_REG(CV_AMD64_BL, Rbx, REG_L);
        CPU_REG(CV_AMD64_SIL, Rsi, REG_L);
        CPU_REG(CV_AMD64_DIL, Rdi, REG_L);
        CPU_REG(CV_AMD64_BPL, Rbp, REG_L);
        CPU_REG(CV_AMD64_SPL, Rsp, REG_L);
        CPU_REG(CV_AMD64_R8B, R8, REG_L);
        CPU_REG(CV_AMD64_R9B, R9, REG_L);
        CPU_REG(CV_AMD64_R10B, R10, REG_L);
        CPU_REG(CV_AMD64_R11B, R11, REG_L);
        CPU_REG(CV_AMD64_R12B, R12, REG_L);
        CPU_REG(CV_AMD64_R13B, R13, REG_L);
        CPU_REG(CV_AMD64_R14B, R14, REG_L);
        CPU_REG(CV_AMD64_R15B, R15, REG_L);
        CPU_REG(CV_AMD64_AH, Rax, REG_H);
        CPU_REG(CV_AMD64_CH, Rcx, REG_H);
        CPU_REG(CV_AMD64_DH, Rdx, REG_H);
        CPU_REG(CV_AMD64_BH, Rbx, REG_H);
        CPU_REG(CV_AMD64_AX, Rax, REG_X);
        CPU_REG(CV_AMD64_CX, Rcx, REG_X);
        CPU_REG(CV_AMD64_DX, Rdx, REG_X);
        CPU_REG(CV_AMD64_BX, Rbx, REG_X);
        CPU_REG(CV_AMD64_SP, Rsp, REG_X);
        CPU_REG(CV_AMD64_BP, Rbp, REG_X);
        CPU_REG(CV_AMD64_SI, Rsi, REG_X);
        CPU_REG(CV_AMD64_DI, Rdi, REG_X);
        CPU_REG(CV_AMD64_R8W, R8, REG_X);
        CPU_REG(CV_AMD64_R9W, R9, REG_X);
        CPU_REG(CV_AMD64_R10W, R10, REG_X);
        CPU_REG(CV_AMD64_R11W, R11, REG_X);
        CPU_REG(CV_AMD64_R12W, R12, REG_X);
        CPU_REG(CV_AMD64_R13W, R13, REG_X);
        CPU_REG(CV_AMD64_R14W, R14, REG_X);
        CPU_REG(CV_AMD64_R15W, R15, REG_X);
        CPU_REG(CV_AMD64_EAX, Rax, REG_E);
        CPU_REG(CV_AMD64_ECX, Rcx, REG_E);
        CPU_REG(CV_AMD64_EDX, Rdx, REG_E);
        CPU_REG(CV_AMD64_EBX, Rbx, REG_E);
        CPU_REG(CV_AMD64_ESP, Rsp, REG_E);
        CPU_REG(CV_AMD64_EBP, Rbp, REG_E);
        CPU_REG(CV_AMD64_ESI, Rsi, REG_E);
        CPU_REG(CV_AMD64_EDI, Rdi, REG_E);
        CPU_REG(CV_AMD64_R8D, R8, REG_E);
        CPU_REG(CV_AMD64_R9D, R9, REG_E);
        CPU_REG(CV_AMD64_R10D, R10, REG_E);
        CPU_REG(CV_AMD64_R11D, R11, REG_E);
        CPU_REG(CV_AMD64_R12D, R12, REG_E);
        CPU_REG(CV_AMD64_R13D, R13, REG_E);
        CPU_REG(CV_AMD64_R14D, R14, REG_E);
        CPU_REG(CV_AMD64_R15D, R15, REG_E);
        CPU_REG(CV_AMD64_RIP, Rip, REG_R);
        CPU_REG(CV_AMD64_RAX, Rax, REG_R);
        CPU_REG(CV_AMD64_RBX, Rbx, REG_R);
        CPU_REG(CV_AMD64_RCX, Rcx, REG_R);
        CPU_REG(CV_AMD64_RDX, Rdx, REG_R);
        CPU_REG(CV_AMD64_RSI, Rsi, REG_R);
        CPU_REG(CV_AMD64_RDI, Rdi, REG_R);
        CPU_REG(CV_AMD64_RBP, Rbp, REG_R);
        CPU_REG(CV_AMD64_RSP, Rsp, REG_R);
        CPU_REG(CV_AMD64_R8, R8, REG_R);
        CPU_REG(CV_AMD64_R9, R9, REG_R);
        CPU_REG(CV_AMD64_R10, R10, REG_R);
        CPU_REG(CV_AMD64_R11, R11, REG_R);
        CPU_REG(CV_AMD64_R12, R12, REG_R);
        CPU_REG(CV_AMD64_R13, R13, REG_R);
        CPU_REG(CV_AMD64_R14, R14, REG_R);
        CPU_REG(CV_AMD64_R15, R15, REG_R);
#elif defined(_M_ARM64)
        CPU_REG(CV_ARM64_W0, X0, REG_E);
        CPU_REG(CV_ARM64_W1, X1, REG_E);
        CPU_REG(CV_ARM64_W2, X2, REG_E);
        CPU_REG(CV_ARM64_W3, X3, REG_E);
        CPU_REG(CV_ARM64_W4, X4, REG_E);
        CPU_REG(CV_ARM64_W5, X5, REG_E);
        CPU_REG(CV_ARM64_W6, X6, REG_E);
        CPU_REG(CV_ARM64_W7, X7, REG_E);
        CPU_REG(CV_ARM64_W8, X8, REG_E);
        CPU_REG(CV_ARM64_W9, X9, REG_E);
        CPU_REG(CV_ARM64_W10, X10, REG_E);
        CPU_REG(CV_ARM64_W11, X11, REG_E);
        CPU_REG(CV_ARM64_W12, X12, REG_E);
        CPU_REG(CV_ARM64_W13, X13, REG_E);
        CPU_REG(CV_ARM64_W14, X14, REG_E);
        CPU_REG(CV_ARM64_W15, X15, REG_E);
        CPU_REG(CV_ARM64_W16, X16, REG_E);
        CPU_REG(CV_ARM64_W17, X17, REG_E);
        CPU_REG(CV_ARM64_W18, X18, REG_E);
        CPU_REG(CV_ARM64_W19, X19, REG_E);
        CPU_REG(CV_ARM64_W20, X20, REG_E);
        CPU_REG(CV_ARM64_W21, X21, REG_E);
        CPU_REG(CV_ARM64_W22, X22, REG_E);
        CPU_REG(CV_ARM64_W23, X23, REG_E);
        CPU_REG(CV_ARM64_W24, X24, REG_E);
        CPU_REG(CV_ARM64_W25, X25, REG_E);
        CPU_REG(CV_ARM64_W26, X26, REG_E);
        CPU_REG(CV_ARM64_W27, X27, REG_E);
        CPU_REG(CV_ARM64_W28, X28, REG_E);
        CPU_REG(CV_ARM64_W29, Fp, REG_E);
        CPU_REG(CV_ARM64_W30, Lr, REG_E);
        case CV_ARM64_WZR: return 0;
        CPU_REG(CV_ARM64_X0, X0, REG_R);
        CPU_REG(CV_ARM64_X1, X1, REG_R);
        CPU_REG(CV_ARM64_X2, X2, REG_R);
        CPU_REG(CV_ARM64_X3, X3, REG_R);
        CPU_REG(CV_ARM64_X4, X4, REG_R);
        CPU_REG(CV_ARM64_X5, X5, REG_R);
        CPU_REG(CV_ARM64_X6, X6, REG_R);
        CPU_REG(CV_ARM64_X7, X7, REG_R);
        CPU_REG(CV_ARM64_X8, X8, REG_R);
        CPU_REG(CV_ARM64_X9, X9, REG_R);
        CPU_REG(CV_ARM64_X10, X10, REG_R);
        CPU_REG(CV_ARM64_X11, X11, REG_R);
        CPU_REG(CV_ARM64_X12, X12, REG_R);
        CPU_REG(CV_ARM64_X13, X13, REG_R);
        CPU_REG(CV_ARM64_X14, X14, REG_R);
        CPU_REG(CV_ARM64_X15, X15, REG_R);
        CPU_REG(CV_ARM64_IP0, X16, REG_R);
        CPU_REG(CV_ARM64_IP1, X17, REG_R);
        CPU_REG(CV_ARM64_X18, X18, REG_R);
        CPU_REG(CV_ARM64_X19, X19, REG_R);
        CPU_REG(CV_ARM64_X20, X20, REG_R);
        CPU_REG(CV_ARM64_X21, X21, REG_R);
        CPU_REG(CV_ARM64_X22, X22, REG_R);
        CPU_REG(CV_ARM64_X23, X23, REG_R);
        CPU_REG(CV_ARM64_X24, X24, REG_R);
        CPU_REG(CV_ARM64_X25, X25, REG_R);
        CPU_REG(CV_ARM64_X26, X26, REG_R);
        CPU_REG(CV_ARM64_X27, X27, REG_R);
        CPU_REG(CV_ARM64_X28, X28, REG_R);
        CPU_REG(CV_ARM64_FP, Fp, REG_R);
        CPU_REG(CV_ARM64_LR, Lr, REG_R);
        CPU_REG(CV_ARM64_SP, Sp, REG_R);
        case CV_ARM64_ZR: return 0;
#endif
        default:
            break;
    }
    return {};
#undef CPU_REG
#undef REG_R
#undef REG_E
#undef REG_X
#undef REG_H
#undef REG_L
}

//////////////////////////////////////////////////////////////////////////////
// Given a SYMBOL_INFO representing a particular variable, displays its
// contents.  If it's a user defined type, display the members and their
// values.
//////////////////////////////////////////////////////////////////////////////
bool WheatyExceptionReport::FormatSymbolValue(
PSYMBOL_INFO pSym,
EnumerateSymbolsCallbackContext* pCtx)
{
    // If it's a function, don't do anything.
    if (pSym->Tag == SymTagFunction)                      // SymTagFunction from CVCONST.H from the DIA SDK
        return false;

    DWORD_PTR pVariable = pSym->Address;                    // Will point to the variable's data in memory
    Optional<DWORD_PTR> registerVariableStorage;

    if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_FRAMERELATIVE
        || (pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGRELATIVE && pSym->Register == CV_ALLREG_VFRAME))
    {
        pVariable += pCtx->sf->AddrFrame.Offset;
    }
    else if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGRELATIVE)
    {
        Optional<DWORD_PTR> registerValue = GetIntegerRegisterValue(pCtx->context, pSym->Register);
        if (!registerValue)
            return false;

        pVariable += *registerValue;
    }
    else if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGISTER)
        return false;                                       // Don't try to report register variable
    else
    {
        // It must be a global variable
    }

    PushSymbolDetail();

    // Indicate if the variable is a local or parameter
    if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_PARAMETER)
        symbolDetails.top().Prefix = "Parameter ";
    else if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_LOCAL)
        symbolDetails.top().Prefix = "Local ";

    // Determine if the variable is a user defined type (UDT).  IF so, bHandled
    // will return true.
    bool bHandled;
    DumpTypeIndex(pSym->ModBase, pSym->TypeIndex, pVariable, bHandled, pSym->Name, "", false, true);

    if (!bHandled)
    {
        // The symbol wasn't a UDT, so do basic, stupid formatting of the
        // variable.  Based on the size, we're assuming it's a char, WORD, or
        // DWORD.
        BasicType basicType = GetBasicType(pSym->TypeIndex, pSym->ModBase);
        if (symbolDetails.top().Type.empty())
            symbolDetails.top().Type = rgBaseType[basicType];

        // Emit the variable name
        if (pSym->Name[0] != '\0')
            symbolDetails.top().Name = pSym->Name;

        char buffer[50];
        FormatOutputValue(buffer, basicType, pSym->Size, (PVOID)pVariable, sizeof(buffer));
        symbolDetails.top().Value = buffer;
    }

    PopSymbolDetail();
    return true;
}

//////////////////////////////////////////////////////////////////////////////
// If it's a user defined type (UDT), recurse through its members until we're
// at fundamental types.  When he hit fundamental types, return
// bHandled = false, so that FormatSymbolValue() will format them.
//////////////////////////////////////////////////////////////////////////////
void WheatyExceptionReport::DumpTypeIndex(
DWORD64 modBase,
DWORD dwTypeIndex,
DWORD_PTR offset,
bool & bHandled,
char const* Name,
char const* /*suffix*/,
bool newSymbol,
bool logChildren)
{
    bHandled = false;

    if (newSymbol)
        PushSymbolDetail();

    DWORD typeTag;
    if (!SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_SYMTAG, &typeTag))
        return;

    // Get the name of the symbol.  This will either be a Type name (if a UDT),
    // or the structure member name.
    WCHAR * pwszTypeName;
    if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_SYMNAME,
        &pwszTypeName))
    {
        // handle special cases
        if (wcscmp(pwszTypeName, L"std::basic_string<char,std::char_traits<char>,std::allocator<char> >") == 0)
        {
            LocalFree(pwszTypeName);
            symbolDetails.top().Type = "std::string";
            char buffer[50];
            FormatOutputValue(buffer, btStdString, 0, (PVOID)offset, sizeof(buffer));
            symbolDetails.top().Value = buffer;
            if (Name != nullptr && Name[0] != '\0')
                symbolDetails.top().Name = Name;
            bHandled = true;
            return;
        }

        char buffer[WER_SMALL_BUFFER_SIZE];
        wcstombs(buffer, pwszTypeName, sizeof(buffer));
        buffer[WER_SMALL_BUFFER_SIZE - 1] = '\0';
        if (Name != nullptr && Name[0] != '\0')
        {
            symbolDetails.top().Type = buffer;
            symbolDetails.top().Name = Name;
        }
        else if (buffer[0] != '\0')
            symbolDetails.top().Name = buffer;

        LocalFree(pwszTypeName);
    }
    else if (Name != nullptr && Name[0] != '\0')
        symbolDetails.top().Name = Name;

    if (!StoreSymbol(dwTypeIndex, offset))
    {
        // Skip printing address and base class if it has been printed already
        if (typeTag == SymTagBaseClass)
            bHandled = true;
        return;
    }

    DWORD innerTypeID;
    switch (typeTag)
    {
        case SymTagPointerType:
            if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_TYPEID, &innerTypeID))
            {
                if (Name != nullptr && Name[0] != '\0')
                    symbolDetails.top().Name = Name;

                BOOL isReference;
                SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_IS_REFERENCE, &isReference);

                char addressStr[40];
                memset(addressStr, 0, sizeof(addressStr));

                if (isReference)
                    symbolDetails.top().Suffix += "&";
                else
                    symbolDetails.top().Suffix += "*";

                // Try to dereference the pointer in a try/except block since it might be invalid
                DWORD_PTR address = DereferenceUnsafePointer(offset);

                char buffer[WER_SMALL_BUFFER_SIZE];
                FormatOutputValue(buffer, btVoid, sizeof(PVOID), (PVOID)offset, sizeof(buffer));
                symbolDetails.top().Value = buffer;

                if (symbolDetails.size() >= WER_MAX_NESTING_LEVEL)
                    logChildren = false;

                // no need to log any children since the address is invalid anyway
                if (address == 0 || address == DWORD_PTR(-1))
                    logChildren = false;

                DumpTypeIndex(modBase, innerTypeID, address, bHandled, Name, addressStr, false, logChildren);

                if (!bHandled)
                {
                    BasicType basicType = GetBasicType(dwTypeIndex, modBase);
                    if (symbolDetails.top().Type.empty())
                        symbolDetails.top().Type = rgBaseType[basicType];

                    if (address == 0)
                        symbolDetails.top().Value = "NULL";
                    else if (address == DWORD_PTR(-1))
                        symbolDetails.top().Value = "<Unable to read memory>";
                    else
                    {
                        // Get the size of the child member
                        ULONG64 length;
                        SymGetTypeInfo(m_hProcess, modBase, innerTypeID, TI_GET_LENGTH, &length);
                        char buffer2[50];
                        FormatOutputValue(buffer2, basicType, length, (PVOID)address, sizeof(buffer2));
                        symbolDetails.top().Value = buffer2;
                    }
                    bHandled = true;
                    return;
                }
                else if (address == 0)
                    symbolDetails.top().Value = "NULL";
                else if (address == DWORD_PTR(-1))
                {
                    symbolDetails.top().Value = "<Unable to read memory>";
                    bHandled = true;
                    return;
                }
            }
            break;
        case SymTagData:
            if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_TYPEID, &innerTypeID))
            {
                DWORD innerTypeTag;
                if (!SymGetTypeInfo(m_hProcess, modBase, innerTypeID, TI_GET_SYMTAG, &innerTypeTag))
                    break;

                switch (innerTypeTag)
                {
                    case SymTagUDT:
                        if (symbolDetails.size() >= WER_MAX_NESTING_LEVEL)
                            logChildren = false;
                        DumpTypeIndex(modBase, innerTypeID,
                            offset, bHandled, symbolDetails.top().Name.c_str(), "", false, logChildren);
                        break;
                    case SymTagPointerType:
                        if (Name != nullptr && Name[0] != '\0')
                            symbolDetails.top().Name = Name;
                        DumpTypeIndex(modBase, innerTypeID,
                            offset, bHandled, symbolDetails.top().Name.c_str(), "", false, logChildren);
                        break;
                    case SymTagArrayType:
                        DumpTypeIndex(modBase, innerTypeID,
                            offset, bHandled, symbolDetails.top().Name.c_str(), "", false, logChildren);
                        break;
                    default:
                        break;
                }
            }
            break;
        case SymTagArrayType:
            if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_TYPEID, &innerTypeID))
            {
                symbolDetails.top().HasChildren = true;

                BasicType basicType = btNoType;
                DumpTypeIndex(modBase, innerTypeID,
                    offset, bHandled, Name, "", false, false);

                // Set Value back to an empty string since the Array object itself has no value, only its elements have
                std::string firstElementValue = symbolDetails.top().Value;
                symbolDetails.top().Value.clear();

                DWORD elementsCount;
                if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_COUNT, &elementsCount))
                    symbolDetails.top().Suffix += "[" + std::to_string(elementsCount) + "]";
                else
                    symbolDetails.top().Suffix += "[<unknown count>]";

                if (!bHandled)
                {
                    basicType = GetBasicType(dwTypeIndex, modBase);
                    if (symbolDetails.top().Type.empty())
                        symbolDetails.top().Type = rgBaseType[basicType];
                    bHandled = true;
                }

                // Get the size of the child member
                ULONG64 length;
                SymGetTypeInfo(m_hProcess, modBase, innerTypeID, TI_GET_LENGTH, &length);

                char buffer[50];
                switch (basicType)
                {
                    case btChar:
                    case btStdString:
                        FormatOutputValue(buffer, basicType, length, (PVOID)offset, sizeof(buffer), elementsCount);
                        symbolDetails.top().Value = buffer;
                        break;
                    default:
                        for (DWORD index = 0; index < elementsCount && index < WER_MAX_ARRAY_ELEMENTS_COUNT; index++)
                        {
                            bool elementHandled = false;
                            PushSymbolDetail();
                            if (index == 0)
                            {
                                if (firstElementValue.empty())
                                {
                                    FormatOutputValue(buffer, basicType, length, (PVOID)(offset + length * index), sizeof(buffer));
                                    firstElementValue = buffer;
                                }
                                symbolDetails.top().Value = firstElementValue;
                            }
                            else
                            {
                                DumpTypeIndex(modBase, innerTypeID, offset + length * index, elementHandled, "", "", false, false);
                                if (!elementHandled)
                                {
                                    FormatOutputValue(buffer, basicType, length, (PVOID)(offset + length * index), sizeof(buffer));
                                    symbolDetails.top().Value = buffer;
                                }
                            }
                            symbolDetails.top().Prefix.clear();
                            symbolDetails.top().Type.clear();
                            symbolDetails.top().Suffix = "[" + std::to_string(index) + "]";
                            symbolDetails.top().Name.clear();
                            PopSymbolDetail();
                        }
                        break;
                }

                return;
            }
            break;
        case SymTagBaseType:
            break;
        case SymTagEnum:
            return;
        default:
            break;
    }

    // Determine how many children this type has.
    DWORD dwChildrenCount = 0;
    SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_CHILDRENCOUNT, &dwChildrenCount);

    if (!dwChildrenCount)                                 // If no children, we're done
        return;

    // Prepare to get an array of "TypeIds", representing each of the children.
    // SymGetTypeInfo(TI_FINDCHILDREN) expects more memory than just a
    // TI_FINDCHILDREN_PARAMS struct has.  Use derivation to accomplish this.
    struct FINDCHILDREN : TI_FINDCHILDREN_PARAMS
    {
        ULONG   MoreChildIds[1024*2];
        FINDCHILDREN(){Count = sizeof(MoreChildIds) / sizeof(MoreChildIds[0]);}
    } children;

    children.Count = dwChildrenCount;
    children.Start= 0;

    // Get the array of TypeIds, one for each child type
    if (!SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_FINDCHILDREN,
        &children))
    {
        return;
    }

    // Iterate through each of the children
    for (unsigned i = 0; i < dwChildrenCount; i++)
    {
        DWORD symTag;
        SymGetTypeInfo(m_hProcess, modBase, children.ChildId[i], TI_GET_SYMTAG, &symTag);

        if (symTag == SymTagFunction ||
            symTag == SymTagEnum ||
            symTag == SymTagTypedef ||
            symTag == SymTagVTable)
            continue;

        // Ignore static fields
        DWORD dataKind;
        SymGetTypeInfo(m_hProcess, modBase, children.ChildId[i], TI_GET_DATAKIND, &dataKind);
        if (dataKind == DataIsStaticLocal ||
            dataKind == DataIsGlobal ||
            dataKind == DataIsStaticMember)
            continue;

        symbolDetails.top().HasChildren = true;
        if (!logChildren)
        {
            bHandled = false;
            return;
        }

        // Recurse for each of the child types
        bool bHandled2;
        BasicType basicType = GetBasicType(children.ChildId[i], modBase);

        // Get the offset of the child member, relative to its parent
        DWORD dwMemberOffset;
        SymGetTypeInfo(m_hProcess, modBase, children.ChildId[i],
            TI_GET_OFFSET, &dwMemberOffset);

        // Calculate the address of the member
        DWORD_PTR dwFinalOffset = offset + dwMemberOffset;

        DumpTypeIndex(modBase,
            children.ChildId[i],
            dwFinalOffset, bHandled2, ""/*Name */, "", true, true);

        // If the child wasn't a UDT, format it appropriately
        if (!bHandled2)
        {
            if (symbolDetails.top().Type.empty())
                symbolDetails.top().Type = rgBaseType[basicType];

            // Get the real "TypeId" of the child.  We need this for the
            // SymGetTypeInfo(TI_GET_TYPEID) call below.
            DWORD typeId;
            SymGetTypeInfo(m_hProcess, modBase, children.ChildId[i],
                TI_GET_TYPEID, &typeId);

            // Get the size of the child member
            ULONG64 length;
            SymGetTypeInfo(m_hProcess, modBase, typeId, TI_GET_LENGTH, &length);

            char buffer[50];
            FormatOutputValue(buffer, basicType, length, (PVOID)dwFinalOffset, sizeof(buffer));
            symbolDetails.top().Value = buffer;
        }

        PopSymbolDetail();
    }

    bHandled = true;
}

void WheatyExceptionReport::FormatOutputValue(char * pszCurrBuffer,
BasicType basicType,
DWORD64 length,
PVOID pAddress,
size_t bufferSize,
size_t countOverride)
{
    __try
    {
        switch (basicType)
        {
            case btChar:
            {
                // Special case handling for char[] type
                if (countOverride != 0)
                    length = countOverride;
                else
                    length = strlen((char*)pAddress);
                if (length > bufferSize - 6)
                    pszCurrBuffer += sprintf(pszCurrBuffer, "\"%.*s...\"", (DWORD)(bufferSize - 6), (char*)pAddress);
                else
                    pszCurrBuffer += sprintf(pszCurrBuffer, "\"%.*s\"", (DWORD)length, (char*)pAddress);
                break;
            }
            case btStdString:
            {
                std::string* value = static_cast<std::string*>(pAddress);
                if (value->length() > bufferSize - 6)
                    pszCurrBuffer += sprintf(pszCurrBuffer, "\"%.*s...\"", (DWORD)(bufferSize - 6), value->c_str());
                else
                    pszCurrBuffer += sprintf(pszCurrBuffer, "\"%s\"", value->c_str());
                break;
            }
            default:
                // Format appropriately (assuming it's a 1, 2, or 4 bytes (!!!)
                if (length == 1)
                    pszCurrBuffer += sprintf(pszCurrBuffer, "0x%X", *(PBYTE)pAddress);
                else if (length == 2)
                    pszCurrBuffer += sprintf(pszCurrBuffer, "0x%X", *(PWORD)pAddress);
                else if (length == 4)
                {
                    if (basicType == btFloat)
                        pszCurrBuffer += sprintf(pszCurrBuffer, "%f", *(PFLOAT)pAddress);
                    else
                        pszCurrBuffer += sprintf(pszCurrBuffer, "0x%X", *(PDWORD)pAddress);
                }
                else if (length == 8)
                {
                    if (basicType == btFloat)
                    {
                        pszCurrBuffer += sprintf(pszCurrBuffer, "%f",
                            *(double *)pAddress);
                    }
                    else
                        pszCurrBuffer += sprintf(pszCurrBuffer, "0x%I64X",
                        *(DWORD64*)pAddress);
                }
                else
                {
    #if _WIN64
                    pszCurrBuffer += sprintf(pszCurrBuffer, "0x%I64X", (DWORD64)pAddress);
    #else
                    pszCurrBuffer += sprintf(pszCurrBuffer, "0x%X", (DWORD)pAddress);
    #endif
                }
                break;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
#if _WIN64
        pszCurrBuffer += sprintf(pszCurrBuffer, "0x%I64X <Unable to read memory>", (DWORD64)pAddress);
#else
        pszCurrBuffer += sprintf(pszCurrBuffer, "0x%X <Unable to read memory>", (DWORD)pAddress);
#endif
    }
}

BasicType
WheatyExceptionReport::GetBasicType(DWORD typeIndex, DWORD64 modBase)
{
    BasicType basicType;
    if (SymGetTypeInfo(m_hProcess, modBase, typeIndex,
        TI_GET_BASETYPE, &basicType))
    {
        return basicType;
    }

    // Get the real "TypeId" of the child.  We need this for the
    // SymGetTypeInfo(TI_GET_TYPEID) call below.
    DWORD typeId;
    if (SymGetTypeInfo(m_hProcess, modBase, typeIndex, TI_GET_TYPEID, &typeId))
    {
        if (SymGetTypeInfo(m_hProcess, modBase, typeId, TI_GET_BASETYPE,
            &basicType))
        {
            return basicType;
        }
    }

    return btNoType;
}

DWORD_PTR WheatyExceptionReport::DereferenceUnsafePointer(DWORD_PTR address)
{
    __try
    {
        return *(PDWORD_PTR)address;
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return DWORD_PTR(-1);
    }
}

//============================================================================
// Helper function that writes to the report file, and allows the user to use
// printf style formating
//============================================================================
int __cdecl WheatyExceptionReport::Log(const TCHAR * format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    int retValue = _vftprintf(m_hReportFile, format, argptr);
    va_end(argptr);
    return retValue;
}

bool WheatyExceptionReport::StoreSymbol(DWORD type, DWORD_PTR offset)
{
    return symbols.insert(SymbolPair(type, offset)).second;
}

void WheatyExceptionReport::ClearSymbols()
{
    symbols.clear();
    while (!symbolDetails.empty())
        symbolDetails.pop();
}

void WheatyExceptionReport::PushSymbolDetail()
{
    // Log current symbol and then add another to the stack to keep the hierarchy format
    PrintSymbolDetail();
    symbolDetails.emplace();
}

void WheatyExceptionReport::PopSymbolDetail()
{
    PrintSymbolDetail();
    symbolDetails.pop();
}

void WheatyExceptionReport::PrintSymbolDetail()
{
    if (symbolDetails.empty())
        return;

    // Don't log anything if has been logged already or if it's empty
    if (symbolDetails.top().Logged || symbolDetails.top().empty())
        return;

    // Add appropriate indentation level (since this routine is recursive)
    for (size_t i = 0; i < symbolDetails.size(); i++)
        Log(_T("\t"));

    Log(_T("%s\r\n"), symbolDetails.top().ToString().c_str());
}

std::string SymbolDetail::ToString()
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
    {
        if (Name == "passwd" || Name == "password")
            Value = "<sensitive data>";
        formatted += " = " + Value;
    }
    return formatted;
}

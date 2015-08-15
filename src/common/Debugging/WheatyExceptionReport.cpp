//==========================================
// Matt Pietrek
// MSDN Magazine, 2002
// FILE: WheatyExceptionReport.CPP
//==========================================
#include "CompilerDefs.h"

#if PLATFORM == PLATFORM_WINDOWS && !defined(__MINGW32__)
#define WIN32_LEAN_AND_MEAN
#pragma warning(disable:4996)
#pragma warning(disable:4312)
#pragma warning(disable:4311)
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <tchar.h>
#define _NO_CVCONST_H
#include <dbghelp.h>

#include "WheatyExceptionReport.h"

#include "Common.h"
#include "SystemConfig.h"
#include "revision.h"

#define CrashFolder _T("Crashes")
#pragma comment(linker, "/DEFAULTLIB:dbghelp.lib")

inline LPTSTR ErrorMessage(DWORD dw)
{
    LPVOID lpMsgBuf;
    DWORD formatResult = FormatMessage(
                            FORMAT_MESSAGE_ALLOCATE_BUFFER |
                            FORMAT_MESSAGE_FROM_SYSTEM,
                            NULL,
                            dw,
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                            (LPTSTR) &lpMsgBuf,
                            0, NULL);
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
// Declare the static variables of the WheatyExceptionReport class
//
TCHAR WheatyExceptionReport::m_szLogFileName[MAX_PATH];
TCHAR WheatyExceptionReport::m_szDumpFileName[MAX_PATH];
LPTOP_LEVEL_EXCEPTION_FILTER WheatyExceptionReport::m_previousFilter;
HANDLE WheatyExceptionReport::m_hReportFile;
HANDLE WheatyExceptionReport::m_hDumpFile;
HANDLE WheatyExceptionReport::m_hProcess;
SymbolPairs WheatyExceptionReport::symbols;
std::stack<SymbolDetail> WheatyExceptionReport::symbolDetails;
bool WheatyExceptionReport::stackOverflowException;
bool WheatyExceptionReport::alreadyCrashed;
std::mutex WheatyExceptionReport::alreadyCrashedLock;

// Declare global instance of class
WheatyExceptionReport g_WheatyExceptionReport;

//============================== Class Methods =============================

WheatyExceptionReport::WheatyExceptionReport()             // Constructor
{
    // Install the unhandled exception filter function
    m_previousFilter = SetUnhandledExceptionFilter(WheatyUnhandledExceptionFilter);
    m_hProcess = GetCurrentProcess();
    stackOverflowException = false;
    alreadyCrashed = false;
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

    if (pExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_STACK_OVERFLOW)
        stackOverflowException = true;

    TCHAR module_folder_name[MAX_PATH];
    GetModuleFileName(0, module_folder_name, MAX_PATH);
    TCHAR* pos = _tcsrchr(module_folder_name, '\\');
    if (!pos)
        return 0;
    pos[0] = '\0';
    ++pos;

    TCHAR crash_folder_path[MAX_PATH];
    sprintf(crash_folder_path, "%s\\%s", module_folder_name, CrashFolder);
    if (!CreateDirectory(crash_folder_path, NULL))
    {
        if (GetLastError() != ERROR_ALREADY_EXISTS)
            return 0;
    }

    SYSTEMTIME systime;
    GetLocalTime(&systime);
    sprintf(m_szDumpFileName, "%s\\%s_%s_[%u-%u_%u-%u-%u].dmp",
        crash_folder_path, _HASH, pos, systime.wDay, systime.wMonth, systime.wHour, systime.wMinute, systime.wSecond);

    sprintf(m_szLogFileName, "%s\\%s_%s_[%u-%u_%u-%u-%u].txt",
        crash_folder_path, _HASH, pos, systime.wDay, systime.wMonth, systime.wHour, systime.wMinute, systime.wSecond);

    m_hDumpFile = CreateFile(m_szDumpFileName,
        GENERIC_WRITE,
        0,
        0,
        OPEN_ALWAYS,
        FILE_FLAG_WRITE_THROUGH,
        0);

    m_hReportFile = CreateFile(m_szLogFileName,
        GENERIC_WRITE,
        0,
        0,
        OPEN_ALWAYS,
        FILE_FLAG_WRITE_THROUGH,
        0);

    if (m_hDumpFile)
    {
        MINIDUMP_EXCEPTION_INFORMATION info;
        info.ClientPointers = FALSE;
        info.ExceptionPointers = pExceptionInfo;
        info.ThreadId = GetCurrentThreadId();

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
            m_hDumpFile, MiniDumpWithIndirectlyReferencedMemory, &info, 0, 0);

        CloseHandle(m_hDumpFile);
    }

    if (m_hReportFile)
    {
        SetFilePointer(m_hReportFile, 0, 0, FILE_END);

        GenerateExceptionReport(pExceptionInfo);

        CloseHandle(m_hReportFile);
        m_hReportFile = 0;
    }

    if (m_previousFilter)
        return m_previousFilter(pExceptionInfo);
    else
        return EXCEPTION_EXECUTE_HANDLER/*EXCEPTION_CONTINUE_SEARCH*/;
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
    lRet = ::RegQueryValueEx(hKey, _T("ProcessorNameString"), NULL, NULL,
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

BOOL WheatyExceptionReport::_GetWindowsVersion(TCHAR* szVersion, DWORD cntMax)
{
    // Try calling GetVersionEx using the OSVERSIONINFOEX structure.
    // If that fails, try using the OSVERSIONINFO structure.
    OSVERSIONINFOEX osvi = { 0 };
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    BOOL bOsVersionInfoEx;
    bOsVersionInfoEx = ::GetVersionEx((LPOSVERSIONINFO)(&osvi));
    if (!bOsVersionInfoEx)
    {
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        if (!::GetVersionEx((OSVERSIONINFO*)&osvi))
            return FALSE;
    }
    *szVersion = _T('\0');
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
            if (osvi.dwMajorVersion == 6)
            {
                if (productType == VER_NT_WORKSTATION)
                {
                    if (osvi.dwMinorVersion == 2)
                        _tcsncat(szVersion, _T("Windows 8 "), cntMax);
                    else if (osvi.dwMinorVersion == 1)
                        _tcsncat(szVersion, _T("Windows 7 "), cntMax);
                    else
                        _tcsncat(szVersion, _T("Windows Vista "), cntMax);
                }
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
            if (bOsVersionInfoEx)
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
                    if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
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
            if (osvi.dwMajorVersion == 4 && _tcsicmp(osvi.szCSDVersion, _T("Service Pack 6")) == 0)
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
                        osvi.szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                    _tcsncat(szVersion, wszTmp, cntMax);
                }
                ::RegCloseKey(hKey);
            }
            else                                                // Windows NT 3.51 and earlier or Windows 2000 and later
            {
                if (!_tcslen(osvi.szCSDVersion))
                    _stprintf(wszTmp, _T("(Version %d.%d, Build %d)"),
                        osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                else
                    _stprintf(wszTmp, _T("%s (Version %d.%d, Build %d)"),
                        osvi.szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
                _tcsncat(szVersion, wszTmp, cntMax);
            }
            break;
        }
        default:
            _stprintf(wszTmp, _T("%s (Version %d.%d, Build %d)"),
                osvi.szCSDVersion, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber & 0xFFFF);
            _tcsncat(szVersion, wszTmp, cntMax);
            break;
    }

    return TRUE;
}

void WheatyExceptionReport::PrintSystemInfo()
{
    SYSTEM_INFO SystemInfo;
    ::GetSystemInfo(&SystemInfo);

    MEMORYSTATUS MemoryStatus;
    MemoryStatus.dwLength = sizeof (MEMORYSTATUS);
    ::GlobalMemoryStatus(&MemoryStatus);
    TCHAR sString[1024];
    _tprintf(_T("//=====================================================\r\n"));
    if (_GetProcessorName(sString, countof(sString)))
        _tprintf(_T("*** Hardware ***\r\nProcessor: %s\r\nNumber Of Processors: %d\r\nPhysical Memory: %d KB (Available: %d KB)\r\nCommit Charge Limit: %d KB\r\n"),
            sString, SystemInfo.dwNumberOfProcessors, MemoryStatus.dwTotalPhys/0x400, MemoryStatus.dwAvailPhys/0x400, MemoryStatus.dwTotalPageFile/0x400);
    else
        _tprintf(_T("*** Hardware ***\r\nProcessor: <unknown>\r\nNumber Of Processors: %d\r\nPhysical Memory: %d KB (Available: %d KB)\r\nCommit Charge Limit: %d KB\r\n"),
            SystemInfo.dwNumberOfProcessors, MemoryStatus.dwTotalPhys/0x400, MemoryStatus.dwAvailPhys/0x400, MemoryStatus.dwTotalPageFile/0x400);

    if (_GetWindowsVersion(sString, countof(sString)))
        _tprintf(_T("\r\n*** Operation System ***\r\n%s\r\n"), sString);
    else
        _tprintf(_T("\r\n*** Operation System:\r\n<unknown>\r\n"));
}

//===========================================================================
void WheatyExceptionReport::printTracesForAllThreads(bool bWriteVariables)
{
  THREADENTRY32 te32;

  DWORD dwOwnerPID = GetCurrentProcessId();
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
    if (te32.th32OwnerProcessID == dwOwnerPID)
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
        _tprintf(_T("Revision: %s\r\n"), _FULLVERSION);
        _tprintf(_T("Date %u:%u:%u. Time %u:%u \r\n"), systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute);
        PEXCEPTION_RECORD pExceptionRecord = pExceptionInfo->ExceptionRecord;

        PrintSystemInfo();
        // First print information about the type of fault
        _tprintf(_T("\r\n//=====================================================\r\n"));
        _tprintf(_T("Exception code: %08X %s\r\n"),
            pExceptionRecord->ExceptionCode,
            GetExceptionString(pExceptionRecord->ExceptionCode));

        // Now print information about where the fault occured
        TCHAR szFaultingModule[MAX_PATH];
        DWORD section;
        DWORD_PTR offset;
        GetLogicalAddress(pExceptionRecord->ExceptionAddress,
            szFaultingModule,
            sizeof(szFaultingModule),
            section, offset);

#ifdef _M_IX86
        _tprintf(_T("Fault address:  %08X %02X:%08X %s\r\n"),
            pExceptionRecord->ExceptionAddress,
            section, offset, szFaultingModule);
#endif
#ifdef _M_X64
        _tprintf(_T("Fault address:  %016I64X %02X:%016I64X %s\r\n"),
            pExceptionRecord->ExceptionAddress,
            section, offset, szFaultingModule);
#endif

        PCONTEXT pCtx = pExceptionInfo->ContextRecord;

        // Show the registers
#ifdef _M_IX86                                          // X86 Only!
        _tprintf(_T("\r\nRegisters:\r\n"));

        _tprintf(_T("EAX:%08X\r\nEBX:%08X\r\nECX:%08X\r\nEDX:%08X\r\nESI:%08X\r\nEDI:%08X\r\n")
            , pCtx->Eax, pCtx->Ebx, pCtx->Ecx, pCtx->Edx,
            pCtx->Esi, pCtx->Edi);

        _tprintf(_T("CS:EIP:%04X:%08X\r\n"), pCtx->SegCs, pCtx->Eip);
        _tprintf(_T("SS:ESP:%04X:%08X  EBP:%08X\r\n"),
            pCtx->SegSs, pCtx->Esp, pCtx->Ebp);
        _tprintf(_T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
            pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs);
        _tprintf(_T("Flags:%08X\r\n"), pCtx->EFlags);
#endif

#ifdef _M_X64
        _tprintf(_T("\r\nRegisters:\r\n"));
        _tprintf(_T("RAX:%016I64X\r\nRBX:%016I64X\r\nRCX:%016I64X\r\nRDX:%016I64X\r\nRSI:%016I64X\r\nRDI:%016I64X\r\n")
            _T("R8: %016I64X\r\nR9: %016I64X\r\nR10:%016I64X\r\nR11:%016I64X\r\nR12:%016I64X\r\nR13:%016I64X\r\nR14:%016I64X\r\nR15:%016I64X\r\n")
            , pCtx->Rax, pCtx->Rbx, pCtx->Rcx, pCtx->Rdx,
            pCtx->Rsi, pCtx->Rdi, pCtx->R9, pCtx->R10, pCtx->R11, pCtx->R12, pCtx->R13, pCtx->R14, pCtx->R15);
        _tprintf(_T("CS:RIP:%04X:%016I64X\r\n"), pCtx->SegCs, pCtx->Rip);
        _tprintf(_T("SS:RSP:%04X:%016X  RBP:%08X\r\n"),
            pCtx->SegSs, pCtx->Rsp, pCtx->Rbp);
        _tprintf(_T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
            pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs);
        _tprintf(_T("Flags:%08X\r\n"), pCtx->EFlags);
#endif

        SymSetOptions(SYMOPT_DEFERRED_LOADS);

        // Initialize DbgHelp
        if (!SymInitialize(GetCurrentProcess(), 0, TRUE))
        {
            _tprintf(_T("\n\rCRITICAL ERROR.\n\r Couldn't initialize the symbol handler for process.\n\rError [%s].\n\r\n\r"),
                ErrorMessage(GetLastError()));
        }

        CONTEXT trashableContext = *pCtx;

        WriteStackDetails(&trashableContext, false, NULL);
        printTracesForAllThreads(false);

        //    #ifdef _M_IX86                                          // X86 Only!

        _tprintf(_T("========================\r\n"));
        _tprintf(_T("Local Variables And Parameters\r\n"));

        trashableContext = *pCtx;
        WriteStackDetails(&trashableContext, true, NULL);
        printTracesForAllThreads(true);

        /*_tprintf(_T("========================\r\n"));
        _tprintf(_T("Global Variables\r\n"));

        SymEnumSymbols(GetCurrentProcess(),
        (UINT_PTR)GetModuleHandle(szFaultingModule),
        0, EnumerateSymbolsCallback, 0);*/
        //  #endif                                                  // X86 Only!

        SymCleanup(GetCurrentProcess());

        _tprintf(_T("\r\n"));
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        _tprintf(_T("Error writing the crash log\r\n"));
    }
}

//======================================================================
// Given an exception code, returns a pointer to a static string with a
// description of the exception
//======================================================================
LPTSTR WheatyExceptionReport::GetExceptionString(DWORD dwCode)
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
    }

    // If not one of the "known" exceptions, try to get the string
    // from NTDLL.DLL's message table.

    static TCHAR szBuffer[512] = { 0 };

    FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE,
        GetModuleHandle(_T("NTDLL.DLL")),
        dwCode, 0, szBuffer, sizeof(szBuffer), 0);

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
    _tprintf(_T("\r\nCall stack:\r\n"));

    _tprintf(_T("Address   Frame     Function      SourceFile\r\n"));

    DWORD dwMachineType = 0;
    // Could use SymSetOptions here to add the SYMOPT_DEFERRED_LOADS flag

    STACKFRAME64 sf;
    memset(&sf, 0, sizeof(sf));

    #ifdef _M_IX86
    // Initialize the STACKFRAME structure for the first call.  This is only
    // necessary for Intel CPUs, and isn't mentioned in the documentation.
    sf.AddrPC.Offset       = pContext->Eip;
    sf.AddrPC.Mode         = AddrModeFlat;
    sf.AddrStack.Offset    = pContext->Esp;
    sf.AddrStack.Mode      = AddrModeFlat;
    sf.AddrFrame.Offset    = pContext->Ebp;
    sf.AddrFrame.Mode      = AddrModeFlat;

    dwMachineType = IMAGE_FILE_MACHINE_I386;
    #endif

#ifdef _M_X64
    sf.AddrPC.Offset    = pContext->Rip;
    sf.AddrPC.Mode = AddrModeFlat;
    sf.AddrStack.Offset    = pContext->Rsp;
    sf.AddrStack.Mode      = AddrModeFlat;
    sf.AddrFrame.Offset    = pContext->Rbp;
    sf.AddrFrame.Mode      = AddrModeFlat;
    dwMachineType = IMAGE_FILE_MACHINE_AMD64;
#endif

    for (;;)
    {
        // Get the next stack frame
        if (! StackWalk64(dwMachineType,
            m_hProcess,
            pThreadHandle != NULL ? pThreadHandle : GetCurrentThread(),
            &sf,
            pContext,
            0,
            SymFunctionTableAccess64,
            SymGetModuleBase64,
            0))
            break;
        if (0 == sf.AddrFrame.Offset)                     // Basic sanity check to make sure
            break;                                          // the frame is OK.  Bail if not.
#ifdef _M_IX86
        _tprintf(_T("%08X  %08X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset);
#endif
#ifdef _M_X64
        _tprintf(_T("%016I64X  %016I64X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset);
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
            _tprintf(_T("%hs+%I64X"), sip.si.Name, symDisplacement);

        }
        else                                                // No symbol found.  Print out the logical address instead.
        {
            TCHAR szModule[MAX_PATH] = _T("");
            DWORD section = 0;
            DWORD_PTR offset = 0;

            GetLogicalAddress((PVOID)sf.AddrPC.Offset,
                szModule, sizeof(szModule), section, offset);
#ifdef _M_IX86
            _tprintf(_T("%04X:%08X %s"), section, offset, szModule);
#endif
#ifdef _M_X64
            _tprintf(_T("%04X:%016I64X %s"), section, offset, szModule);
#endif
        }

        // Get the source line for this stack frame entry
        IMAGEHLP_LINE64 lineInfo = { sizeof(IMAGEHLP_LINE64) };
        DWORD dwLineDisplacement;
        if (SymGetLineFromAddr64(m_hProcess, sf.AddrPC.Offset,
            &dwLineDisplacement, &lineInfo))
        {
            _tprintf(_T("  %s line %u"), lineInfo.FileName, lineInfo.LineNumber);
        }

        _tprintf(_T("\r\n"));

        // Write out the variables, if desired
        if (bWriteVariables)
        {
            // Use SymSetContext to get just the locals/params for this frame
            IMAGEHLP_STACK_FRAME imagehlpStackFrame;
            imagehlpStackFrame.InstructionOffset = sf.AddrPC.Offset;
            SymSetContext(m_hProcess, &imagehlpStackFrame, 0);

            // Enumerate the locals/parameters
            SymEnumSymbols(m_hProcess, 0, 0, EnumerateSymbolsCallback, &sf);

            _tprintf(_T("\r\n"));
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

    char szBuffer[WER_LARGE_BUFFER_SIZE];
    memset(szBuffer, 0, sizeof(szBuffer));

    __try
    {
        ClearSymbols();
        if (FormatSymbolValue(pSymInfo, (STACKFRAME64*)UserContext,
            szBuffer, sizeof(szBuffer)))
            _tprintf(_T("%s"), szBuffer);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        _tprintf(_T("punting on symbol %s, partial output:\r\n"), pSymInfo->Name);
        if (szBuffer[0] != '\0')
            _tprintf(_T("%s"), szBuffer);
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// Given a SYMBOL_INFO representing a particular variable, displays its
// contents.  If it's a user defined type, display the members and their
// values.
//////////////////////////////////////////////////////////////////////////////
bool WheatyExceptionReport::FormatSymbolValue(
PSYMBOL_INFO pSym,
STACKFRAME64 * sf,
char * pszBuffer,
unsigned /*cbBuffer*/)
{
    char * pszCurrBuffer = pszBuffer;

    // If it's a function, don't do anything.
    if (pSym->Tag == SymTagFunction)                      // SymTagFunction from CVCONST.H from the DIA SDK
        return false;

    DWORD_PTR pVariable = 0;                                // Will point to the variable's data in memory

    if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGRELATIVE)
    {
        // if (pSym->Register == 8)   // EBP is the value 8 (in DBGHELP 5.1)
        {                                                   //  This may change!!!
#ifdef _M_IX86
            pVariable = sf->AddrFrame.Offset;
#elif _M_X64
            pVariable = sf->AddrStack.Offset;
#endif
            pVariable += (DWORD_PTR)pSym->Address;
        }
        // else
        //  return false;
    }
    else if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGISTER)
        return false;                                       // Don't try to report register variable
    else
    {
        pVariable = (DWORD_PTR)pSym->Address;               // It must be a global variable
    }

    pszCurrBuffer = PushSymbolDetail(pszCurrBuffer);

    // Indicate if the variable is a local or parameter
    if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_PARAMETER)
        symbolDetails.top().Prefix = "Parameter ";
    else if (pSym->Flags & IMAGEHLP_SYMBOL_INFO_LOCAL)
        symbolDetails.top().Prefix = "Local ";

    // Determine if the variable is a user defined type (UDT).  IF so, bHandled
    // will return true.
    bool bHandled;
    pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, pSym->ModBase, pSym->TypeIndex,
        0, pVariable, bHandled, pSym->Name, "", false, true);

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

    pszCurrBuffer = PopSymbolDetail(pszCurrBuffer);
    return true;
}

//////////////////////////////////////////////////////////////////////////////
// If it's a user defined type (UDT), recurse through its members until we're
// at fundamental types.  When he hit fundamental types, return
// bHandled = false, so that FormatSymbolValue() will format them.
//////////////////////////////////////////////////////////////////////////////
char * WheatyExceptionReport::DumpTypeIndex(
char * pszCurrBuffer,
DWORD64 modBase,
DWORD dwTypeIndex,
unsigned nestingLevel,
DWORD_PTR offset,
bool & bHandled,
const char* Name,
char* /*suffix*/,
bool newSymbol,
bool logChildren)
{
    bHandled = false;

    if (newSymbol)
        pszCurrBuffer = PushSymbolDetail(pszCurrBuffer);

    DWORD typeTag;
    if (!SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_SYMTAG, &typeTag))
        return pszCurrBuffer;

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
            if (Name != NULL && Name[0] != '\0')
                symbolDetails.top().Name = Name;
            bHandled = true;
            return pszCurrBuffer;
        }

        char buffer[200];
        wcstombs(buffer, pwszTypeName, sizeof(buffer));
        buffer[199] = '\0';
        if (Name != NULL && Name[0] != '\0')
        {
            symbolDetails.top().Type = buffer;
            symbolDetails.top().Name = Name;
        }
        else if (buffer[0] != '\0')
            symbolDetails.top().Name = buffer;

        LocalFree(pwszTypeName);
    }
    else if (Name != NULL && Name[0] != '\0')
        symbolDetails.top().Name = Name;

    if (!StoreSymbol(dwTypeIndex, offset))
    {
        // Skip printing address and base class if it has been printed already
        if (typeTag == SymTagBaseClass)
            bHandled = true;
        return pszCurrBuffer;
    }

    DWORD innerTypeID;
    switch (typeTag)
    {
        case SymTagPointerType:
            if (SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_TYPEID, &innerTypeID))
            {
                if (Name != NULL && Name[0] != '\0')
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

                char buffer[50];
                FormatOutputValue(buffer, btVoid, sizeof(PVOID), (PVOID)offset, sizeof(buffer));
                symbolDetails.top().Value = buffer;

                if (nestingLevel >= WER_MAX_NESTING_LEVEL)
                    logChildren = false;

                // no need to log any children since the address is invalid anyway
                if (address == NULL || address == DWORD_PTR(-1))
                    logChildren = false;

                pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase, innerTypeID, nestingLevel + 1,
                    address, bHandled, Name, addressStr, false, logChildren);

                if (!bHandled)
                {
                    BasicType basicType = GetBasicType(dwTypeIndex, modBase);
                    if (symbolDetails.top().Type.empty())
                        symbolDetails.top().Type = rgBaseType[basicType];

                    if (address == NULL)
                        symbolDetails.top().Value = "NULL";
                    else if (address == DWORD_PTR(-1))
                        symbolDetails.top().Value = "<Unable to read memory>";
                    else
                    {
                        // Get the size of the child member
                        ULONG64 length;
                        SymGetTypeInfo(m_hProcess, modBase, innerTypeID, TI_GET_LENGTH, &length);
                        char buffer2[50];
                        FormatOutputValue(buffer2, basicType, length, (PVOID)address, sizeof(buffer));
                        symbolDetails.top().Value = buffer2;
                    }
                    bHandled = true;
                    return pszCurrBuffer;
                }
                else if (address == NULL)
                    symbolDetails.top().Value = "NULL";
                else if (address == DWORD_PTR(-1))
                {
                    symbolDetails.top().Value = "<Unable to read memory>";
                    bHandled = true;
                    return pszCurrBuffer;
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
                        if (nestingLevel >= WER_MAX_NESTING_LEVEL)
                            logChildren = false;
                        pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase, innerTypeID, nestingLevel + 1,
                            offset, bHandled, symbolDetails.top().Name.c_str(), "", false, logChildren);
                        break;
                    case SymTagPointerType:
                        if (Name != NULL && Name[0] != '\0')
                            symbolDetails.top().Name = Name;
                        pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase, innerTypeID, nestingLevel + 1,
                            offset, bHandled, symbolDetails.top().Name.c_str(), "", false, logChildren);
                        break;
                    case SymTagArrayType:
                        pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase, innerTypeID, nestingLevel + 1,
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
                pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase, innerTypeID, nestingLevel + 1,
                    offset, bHandled, Name, "", false, false);

                // Set Value back to an empty string since the Array object itself has no value, only its elements have
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
                            pszCurrBuffer = PushSymbolDetail(pszCurrBuffer);
                            symbolDetails.top().Suffix += "[" + std::to_string(index) + "]";
                            FormatOutputValue(buffer, basicType, length, (PVOID)(offset + length * index), sizeof(buffer));
                            symbolDetails.top().Value = buffer;
                            pszCurrBuffer = PopSymbolDetail(pszCurrBuffer);
                        }
                        break;
                }

                return pszCurrBuffer;
            }
            break;
        case SymTagBaseType:
            break;
        case SymTagEnum:
            return pszCurrBuffer;
        default:
            break;
    }

    // Determine how many children this type has.
    DWORD dwChildrenCount = 0;
    SymGetTypeInfo(m_hProcess, modBase, dwTypeIndex, TI_GET_CHILDRENCOUNT, &dwChildrenCount);

    if (!dwChildrenCount)                                 // If no children, we're done
        return pszCurrBuffer;

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
        return pszCurrBuffer;
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
            return pszCurrBuffer;
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

        pszCurrBuffer = DumpTypeIndex(pszCurrBuffer, modBase,
            children.ChildId[i], nestingLevel+1,
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

        pszCurrBuffer = PopSymbolDetail(pszCurrBuffer);
    }

    bHandled = true;
    return pszCurrBuffer;
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
int __cdecl WheatyExceptionReport::_tprintf(const TCHAR * format, ...)
{
    int retValue;
    va_list argptr;
    va_start(argptr, format);
    if (stackOverflowException)
    {
        retValue = heapprintf(format, argptr);
        va_end(argptr);
    }
    else
    {
        retValue = stackprintf(format, argptr);
        va_end(argptr);
    }

    return retValue;
}

int __cdecl WheatyExceptionReport::stackprintf(const TCHAR * format, va_list argptr)
{
    int retValue;
    DWORD cbWritten;

    TCHAR szBuff[WER_LARGE_BUFFER_SIZE];
    retValue = vsprintf(szBuff, format, argptr);
    WriteFile(m_hReportFile, szBuff, retValue * sizeof(TCHAR), &cbWritten, 0);

    return retValue;
}

int __cdecl WheatyExceptionReport::heapprintf(const TCHAR * format, va_list argptr)
{
    int retValue;
    DWORD cbWritten;
    TCHAR* szBuff = (TCHAR*)malloc(sizeof(TCHAR) * WER_LARGE_BUFFER_SIZE);
    retValue = vsprintf(szBuff, format, argptr);
    WriteFile(m_hReportFile, szBuff, retValue * sizeof(TCHAR), &cbWritten, 0);
    free(szBuff);

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

char* WheatyExceptionReport::PushSymbolDetail(char* pszCurrBuffer)
{
    // Log current symbol and then add another to the stack to keep the hierarchy format
    pszCurrBuffer = PrintSymbolDetail(pszCurrBuffer);
    symbolDetails.emplace();
    return pszCurrBuffer;
}

char* WheatyExceptionReport::PopSymbolDetail(char* pszCurrBuffer)
{
    pszCurrBuffer = PrintSymbolDetail(pszCurrBuffer);
    symbolDetails.pop();
    return pszCurrBuffer;
}

char* WheatyExceptionReport::PrintSymbolDetail(char* pszCurrBuffer)
{
    if (symbolDetails.empty())
        return pszCurrBuffer;

    // Don't log anything if has been logged already or if it's empty
    if (symbolDetails.top().Logged || symbolDetails.top().empty())
        return pszCurrBuffer;

    // Add appropriate indentation level (since this routine is recursive)
    for (size_t i = 0; i < symbolDetails.size(); i++)
        pszCurrBuffer += sprintf(pszCurrBuffer, "\t");

    pszCurrBuffer += sprintf(pszCurrBuffer, "%s\r\n", symbolDetails.top().ToString().c_str());

    return pszCurrBuffer;
}

#endif  // _WIN32

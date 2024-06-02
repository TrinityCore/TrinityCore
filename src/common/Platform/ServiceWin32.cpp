/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef _WIN32

#include "Log.h"
#include <cstring>
#include <tchar.h>
#include <windows.h>
#include <winsvc.h>

#if !defined(WINADVAPI)
#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif
#endif

extern int main(int argc, char ** argv);
extern TCHAR serviceLongName[];
extern TCHAR serviceName[];
extern TCHAR serviceDescription[];

extern int m_ServiceStatus;

SERVICE_STATUS serviceStatus;

SERVICE_STATUS_HANDLE serviceStatusHandle = nullptr;

typedef WINADVAPI BOOL (WINAPI *CSD_T)(SC_HANDLE, DWORD, LPCVOID);

bool WinServiceInstall()
{
    SC_HANDLE serviceControlManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);

    if (serviceControlManager)
    {
        TCHAR path[_MAX_PATH + 10];
        if (GetModuleFileName( nullptr, path, sizeof(path)/sizeof(path[0]) ) > 0)
        {
            SC_HANDLE service;
            _tcscat(path, _T(" --service run"));
            service = CreateService(serviceControlManager,
                serviceName,                                // name of service
                serviceLongName,                            // service name to display
                SERVICE_ALL_ACCESS,                         // desired access
                                                            // service type
                SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS,
                SERVICE_AUTO_START,                         // start type
                SERVICE_ERROR_IGNORE,                       // error control type
                path,                                       // service's binary
                nullptr,                                    // no load ordering group
                nullptr,                                    // no tag identifier
                nullptr,                                    // no dependencies
                nullptr,                                    // LocalSystem account
                nullptr);                                   // no password
            if (service)
            {
                HMODULE advapi32 = GetModuleHandle(_T("ADVAPI32.DLL"));
                if (!advapi32)
                {
                    CloseServiceHandle(service);
                    CloseServiceHandle(serviceControlManager);
                    return false;
                }

                CSD_T ChangeService_Config2 = (CSD_T) GetProcAddress(advapi32, "ChangeServiceConfig2A");
                if (!ChangeService_Config2)
                {
                    CloseServiceHandle(service);
                    CloseServiceHandle(serviceControlManager);
                    return false;
                }

                SERVICE_DESCRIPTION sdBuf;
                sdBuf.lpDescription = serviceDescription;
                ChangeService_Config2(
                    service,                                // handle to service
                    SERVICE_CONFIG_DESCRIPTION,             // change: description
                    &sdBuf);                                // new data

                SC_ACTION _action[1];
                _action[0].Type = SC_ACTION_RESTART;
                _action[0].Delay = 10000;
                SERVICE_FAILURE_ACTIONS sfa;
                ZeroMemory(&sfa, sizeof(SERVICE_FAILURE_ACTIONS));
                sfa.lpsaActions = _action;
                sfa.cActions = 1;
                sfa.dwResetPeriod =INFINITE;
                ChangeService_Config2(
                    service,                                // handle to service
                    SERVICE_CONFIG_FAILURE_ACTIONS,         // information level
                    &sfa);                                  // new data

                CloseServiceHandle(service);

            }
        }
        CloseServiceHandle(serviceControlManager);
    }

    printf("Service installed\n");
    return true;
}

bool WinServiceUninstall()
{
    SC_HANDLE serviceControlManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_CONNECT);

    if (serviceControlManager)
    {
        SC_HANDLE service = OpenService(serviceControlManager,
            serviceName, SERVICE_QUERY_STATUS | DELETE);
        if (service)
        {
            SERVICE_STATUS serviceStatus2;
            if (QueryServiceStatus(service, &serviceStatus2))
            {
                if (serviceStatus2.dwCurrentState == SERVICE_STOPPED)
                    DeleteService(service);
            }
            CloseServiceHandle(service);
        }

        CloseServiceHandle(serviceControlManager);
    }

    printf("Service uninstalled\n");
    return true;
}

void WINAPI ServiceControlHandler(DWORD controlCode)
{
    switch (controlCode)
    {
        case SERVICE_CONTROL_INTERROGATE:
            break;

        case SERVICE_CONTROL_SHUTDOWN:
        case SERVICE_CONTROL_STOP:
            serviceStatus.dwCurrentState = SERVICE_STOP_PENDING;
            SetServiceStatus(serviceStatusHandle, &serviceStatus);

            m_ServiceStatus = 0;
            return;

        case SERVICE_CONTROL_PAUSE:
            m_ServiceStatus = 2;
            serviceStatus.dwCurrentState = SERVICE_PAUSED;
            SetServiceStatus(serviceStatusHandle, &serviceStatus);
            break;

        case SERVICE_CONTROL_CONTINUE:
            serviceStatus.dwCurrentState = SERVICE_RUNNING;
            SetServiceStatus(serviceStatusHandle, &serviceStatus);
            m_ServiceStatus = 1;
            break;

        default:
            if ( controlCode >= 128 && controlCode <= 255 )
                // user defined control code
                break;
            else
                // unrecognized control code
                break;
    }

    SetServiceStatus(serviceStatusHandle, &serviceStatus);
}

template<size_t size>
void TCharToChar(TCHAR const* src, char(&dst)[size])
{
    if constexpr (std::is_same_v<TCHAR, char>)
        ::strcpy_s(dst, src, size);
    else
        ::wcstombs_s(nullptr, dst, src, _TRUNCATE);
}

void WINAPI ServiceMain(DWORD /*argc*/, TCHAR *argv[])
{
    // initialise service status
    serviceStatus.dwServiceType = SERVICE_WIN32;
    serviceStatus.dwCurrentState = SERVICE_START_PENDING;
    serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE;
    serviceStatus.dwWin32ExitCode = NO_ERROR;
    serviceStatus.dwServiceSpecificExitCode = NO_ERROR;
    serviceStatus.dwCheckPoint = 0;
    serviceStatus.dwWaitHint = 0;

    serviceStatusHandle = RegisterServiceCtrlHandler(serviceName, ServiceControlHandler);

    if ( serviceStatusHandle )
    {
        TCHAR path[_MAX_PATH + 1];
        unsigned int i, last_slash = 0;

        GetModuleFileName(nullptr, path, sizeof(path)/sizeof(path[0]));

        size_t pathLen = _tcslen(path);
        for (i = 0; i < pathLen; i++)
        {
            if (path[i] == '\\') last_slash = i;
        }

        path[last_slash] = 0;

        // service is starting
        serviceStatus.dwCurrentState = SERVICE_START_PENDING;
        SetServiceStatus(serviceStatusHandle, &serviceStatus);

        // do initialisation here
        SetCurrentDirectory(path);

        // running
        serviceStatus.dwControlsAccepted |= (SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN);
        serviceStatus.dwCurrentState = SERVICE_RUNNING;
        SetServiceStatus( serviceStatusHandle, &serviceStatus );

        ////////////////////////
        // service main cycle //
        ////////////////////////

        m_ServiceStatus = 1;

        char cArg[_MAX_PATH + 1];
        TCharToChar(argv[0], cArg);
        char* cArgv[] = { cArg };

        main(1, cArgv);

        // service was stopped
        serviceStatus.dwCurrentState = SERVICE_STOP_PENDING;
        SetServiceStatus(serviceStatusHandle, &serviceStatus);

        // do cleanup here

        // service is now stopped
        serviceStatus.dwControlsAccepted &= ~(SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN);
        serviceStatus.dwCurrentState = SERVICE_STOPPED;
        SetServiceStatus(serviceStatusHandle, &serviceStatus);
    }
}

bool WinServiceRun()
{
    SERVICE_TABLE_ENTRY serviceTable[] =
    {
        { serviceName, ServiceMain },
        { nullptr, nullptr }
    };

    if (!StartServiceCtrlDispatcher(serviceTable))
    {
        TC_LOG_ERROR("server.worldserver", "StartService Failed. Error [{}]", uint32(::GetLastError()));
        return false;
    }
    return true;
}
#endif

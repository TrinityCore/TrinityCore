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

#include "ServiceWin32.h"
#include <array> // for std::size
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <winsvc.h>

namespace
{
_TCHAR* ServiceLongName;
_TCHAR* ServiceName;
_TCHAR* ServiceDescription;
int(*ServiceEntryPoint)(int argc, char** argv);
int* ServiceStatusPtr;

SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE ServiceStatusHandle = nullptr;
}

typedef BOOL (WINAPI *CSD_T)(SC_HANDLE, DWORD, LPCVOID);

void Trinity::Service::Init(_TCHAR* serviceLongName, _TCHAR* serviceName, _TCHAR* serviceDescription, int(* entryPoint)(int argc, char** argv), int* status)
{
    ServiceLongName = serviceLongName;
    ServiceName = serviceName;
    ServiceDescription = serviceDescription;
    ServiceEntryPoint = entryPoint;
    ServiceStatusPtr = status;
}

int32 Trinity::Service::Install()
{
    SC_HANDLE serviceControlManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);

    if (serviceControlManager)
    {
        TCHAR path[_MAX_PATH + 10];
        if (GetModuleFileName(nullptr, path, std::size(path)) > 0)
        {
            _tcscat(path, _T(" --service run"));
            SC_HANDLE service = CreateService(serviceControlManager,
                ServiceName,                                // name of service
                ServiceLongName,                            // service name to display
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
                SERVICE_DESCRIPTION sdBuf;
                sdBuf.lpDescription = ServiceDescription;
                ChangeServiceConfig2(
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
                sfa.dwResetPeriod = INFINITE;
                ChangeServiceConfig2(
                    service,                                // handle to service
                    SERVICE_CONFIG_FAILURE_ACTIONS,         // information level
                    &sfa);                                  // new data

                CloseServiceHandle(service);

            }
        }
        CloseServiceHandle(serviceControlManager);
    }

    printf("Service installed\n");
    return 0;
}

int32 Trinity::Service::Uninstall()
{
    SC_HANDLE serviceControlManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_CONNECT);

    if (serviceControlManager)
    {
        SC_HANDLE service = OpenService(serviceControlManager,
            ServiceName, SERVICE_QUERY_STATUS | DELETE);
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
    return 0;
}

void WINAPI ServiceControlHandler(DWORD controlCode)
{
    switch (controlCode)
    {
        case SERVICE_CONTROL_INTERROGATE:
            break;

        case SERVICE_CONTROL_SHUTDOWN:
        case SERVICE_CONTROL_STOP:
            ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
            SetServiceStatus(ServiceStatusHandle, &ServiceStatus);

            *ServiceStatusPtr = 0;
            return;

        case SERVICE_CONTROL_PAUSE:
            *ServiceStatusPtr = 2;
            ServiceStatus.dwCurrentState = SERVICE_PAUSED;
            SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
            break;

        case SERVICE_CONTROL_CONTINUE:
            ServiceStatus.dwCurrentState = SERVICE_RUNNING;
            SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
            *ServiceStatusPtr = 1;
            break;

        default:
            if (controlCode >= 128 && controlCode <= 255)
                // user defined control code
                break;
            else
                // unrecognized control code
                break;
    }

    SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
}

template<size_t size>
void TCharToChar(TCHAR const* src, char(&dst)[size])
{
    if constexpr (std::is_same_v<TCHAR, char>)
        ::strcpy_s(dst, src);
    else
        ::wcstombs_s(nullptr, dst, src, _TRUNCATE);
}

void WINAPI ServiceMain(DWORD /*argc*/, TCHAR *argv[])
{
    // initialise service status
    ServiceStatus.dwServiceType = SERVICE_WIN32;
    ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE;
    ServiceStatus.dwWin32ExitCode = NO_ERROR;
    ServiceStatus.dwServiceSpecificExitCode = NO_ERROR;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 0;

    ServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceControlHandler);

    if (ServiceStatusHandle)
    {
        TCHAR path[_MAX_PATH + 1];
        size_t last_slash = 0;

        size_t pathLen = GetModuleFileName(nullptr, path, std::size(path));
        for (size_t i = 0; i < pathLen; i++)
            if (path[i] == '\\')
                last_slash = i;

        path[last_slash] = 0;

        // service is starting
        ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
        SetServiceStatus(ServiceStatusHandle, &ServiceStatus);

        // do initialisation here
        SetCurrentDirectory(path);

        // running
        ServiceStatus.dwControlsAccepted |= (SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN);
        ServiceStatus.dwCurrentState = SERVICE_RUNNING;
        SetServiceStatus(ServiceStatusHandle, &ServiceStatus);

        ////////////////////////
        // service main cycle //
        ////////////////////////

        *ServiceStatusPtr = 1;

        char cArg[_MAX_PATH + 1];
        TCharToChar(argv[0], cArg);
        char* cArgv[] = { cArg };

        ServiceEntryPoint(1, cArgv);

        // service was stopped
        ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
        SetServiceStatus(ServiceStatusHandle, &ServiceStatus);

        // do cleanup here

        // service is now stopped
        ServiceStatus.dwControlsAccepted &= ~(SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN);
        ServiceStatus.dwCurrentState = SERVICE_STOPPED;
        SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
    }
}

int32 Trinity::Service::Run()
{
    SERVICE_TABLE_ENTRY serviceTable[] =
    {
        { ServiceName, ServiceMain },
        { nullptr, nullptr }
    };

    if (!StartServiceCtrlDispatcher(serviceTable))
    {
        printf("StartService Failed. Error [%u]", uint32(::GetLastError()));
        return 1;
    }
    return 0;
}

/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "IPCData.h"

HANDLE ApcStartedEvent = nullptr;
HANDLE ApcFinishedEvent = nullptr;

extern "C" {

__declspec(dllexport) void CALLBACK SignalReady(ULONG_PTR /*param*/)
{
    // signal launcher that wow is ready
    SetEvent(ApcStartedEvent);

    // hold the main wow thread
    WaitForSingleObjectEx(ApcFinishedEvent, INFINITE, TRUE);
}

__declspec(dllexport) BOOL __stdcall DllMain(HINSTANCE dllInstance, DWORD reason, void* /*reserved*/)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
        {
            ApcStartedEvent = CreateEventA(nullptr, TRUE, FALSE, ApcStarted);
            ApcFinishedEvent = CreateEventA(nullptr, TRUE, FALSE, ApcFinished);
            HANDLE dllBaseMapping = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, SharedMemoryName);
            // will be null in launcher process
            if (dllBaseMapping)
            {
                IPCData* ipcData = reinterpret_cast<IPCData*>(MapViewOfFile(dllBaseMapping, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(IPCData)));
                if (ipcData)
                {
                    ipcData->SignalReadyAddress = &SignalReady;
                    ipcData->InitializerHandle = dllInstance;
                    FlushViewOfFile(ipcData, 0);
                    UnmapViewOfFile(ipcData);
                }
                CloseHandle(dllBaseMapping);
            }
            break;
        }
        case DLL_PROCESS_DETACH:
            CloseHandle(ApcStartedEvent);
            CloseHandle(ApcFinishedEvent);
            break;
    }
    return TRUE;
}
}

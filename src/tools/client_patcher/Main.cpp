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

#include <windows.h>
#include <string>
#include <atlstr.h>
#include "MinHook.h"
#include <iostream>
#include <Banner.h>

#include "Helper.hpp"
#include "Patcher.hpp"
#include "Patches/Common.hpp"
#include "Patches/Windows.hpp"
#include "Patterns/Common.hpp"
#include "Patterns/Windows.hpp"

HINSTANCE DllHandle;
bool DllPatched = false;
FILE* fp;

namespace ClientPatcher
{
    template<typename PATCH, typename PATTERN>
    void do_dll_patches(Patcher* patcher)
    {
        std::cout << "Patching battle.net binary...\n";

        std::cout << "patching Portal\n";
        patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

        std::cout << "patching Bnet\n";
        patcher->Patch(PATCH::BNet(), PATTERN::BNet());

        std::cout << "patching Signature\n";
        patcher->Patch(PATCH::Signature(), PATTERN::Signature());
    }

    typedef HMODULE(WINAPI* TYPE_LoadLibraryW)(LPCWSTR);
    TYPE_LoadLibraryW g_loadLibraryW_original = NULL;
    HMODULE WINAPI LoadLibraryW_replacement(LPCWSTR lpLibFileName)
    {
        HMODULE dllHandle = g_loadLibraryW_original(lpLibFileName);

        if (lstrcmpiW(lpLibFileName, L"Battle.net.dll") == 0 || lstrcmpiW(lpLibFileName, L"Battle.net-64.dll") == 0)
        {
            std::cout << "Detected Battle.net.dll\n";
            std::cout << "Start patching...\n";

            MEMORY_BASIC_INFORMATION mbi;
            std::vector<BYTE> binaryData;

            if (!VirtualQuery(dllHandle, &mbi, sizeof(mbi)))
                return dllHandle;

#ifdef _M_IX86
            uint32_t baseAddr = reinterpret_cast<uint32_t>(dllHandle);;
#else
            uint64_t baseAddr = reinterpret_cast<uint64_t>(dllHandle);
#endif

            while (true)
            {
                if (!VirtualQuery((void*)baseAddr, &mbi, sizeof(mbi)))
                    return dllHandle;

                if (mbi.AllocationBase == 0)
                    break;

                std::vector<BYTE> temp(mbi.RegionSize);
                if (!ReadProcessMemory(GetCurrentProcess(), mbi.BaseAddress, temp.data(), mbi.RegionSize, nullptr))
                    return dllHandle;

                binaryData.insert(binaryData.end(), temp.begin(), temp.end());
                baseAddr += mbi.RegionSize;
            }

            Patcher battleNetPatcher(binaryData, GetCurrentProcess(), dllHandle);

#ifdef _M_IX86
            do_dll_patches<Patches::Windows::x86, Patterns::Windows::x86>(&battleNetPatcher);
#else
            do_dll_patches<Patches::Windows::x64, Patterns::Windows::x64>(&battleNetPatcher);
#endif

            DllPatched = true;
        }

        return dllHandle;
    }

    DWORD __stdcall EjectThread(LPVOID /*lpParameter*/) {
        Sleep(100);
        FreeLibraryAndExitThread(DllHandle, 0);
        return 0;
    }

    void shutdown(std::string reason) {

        MH_Uninitialize();
        std::cout << reason << std::endl;
        Sleep(1000);
        if (fp != nullptr)
            fclose(fp);
        FreeConsole();
        CreateThread(0, 0, EjectThread, 0, 0, 0);
        return;
    }

    void HookThread(HINSTANCE /*hModule*/)
    {
        Trinity::Banner::Show("client_patcher", [](char const* text) { std::cout << text << std::endl; }, nullptr);

        std::cout << "Awaiting login to patch Battle.net...\n";

        MH_STATUS status = MH_Initialize();
        if (status != MH_OK)
        {
            std::string sStatus = MH_StatusToString(status);
            shutdown("Minhook init failed!");
            return;
        }
        if (MH_CreateHook(&LoadLibraryW, &LoadLibraryW_replacement, (LPVOID*)(&g_loadLibraryW_original)) != MH_OK)
        {
            shutdown("CreateHook failed!");
            return;
        }
        if (MH_EnableHook(&LoadLibraryW) != MH_OK)
        {
            shutdown("EnableHook failed!");
            return;
        }

        while (!DllPatched) {
            Sleep(50);
        }

        shutdown("Done!");
        return;
    }
}

__declspec(dllexport) BOOL __stdcall DllMain(HINSTANCE dllInstance, DWORD reason, void* /*reserved*/)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        wchar_t* threadDesc;
        HRESULT hr = GetThreadDescription(GetCurrentThread(), &threadDesc);

        if (FAILED(hr) || wcscmp(threadDesc, L"console") == 0)
        {
            LocalFree(threadDesc);
            AllocConsole();
            freopen_s(&fp, "CONOUT$", "w", stdout);

            if (FAILED(hr))
                std::cout << "GetThreadDescription failed!";
        }

        DllHandle = dllInstance;
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ClientPatcher::HookThread, NULL, 0, NULL);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

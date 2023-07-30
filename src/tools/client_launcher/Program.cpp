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

#include "Banner.h"
#include "Helper.hpp"
#include "Windows.h"
#include "Patcher.hpp"
#include "Patches/Common.hpp"
#include "Patches/Windows.hpp"
#include "Patterns/Common.hpp"
#include "Patterns/Windows.hpp"

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <Shlobj.h>

namespace po = boost::program_options;

namespace ClientLauncher
{
    template<typename PATCH, typename PATTERN>
    void do_module(const std::string& moduleName, const boost::filesystem::path& path)
    {
        namespace fs = boost::filesystem;

        fs::path const modulePath
        (path / std::string(&moduleName[0], 2) / std::string(&moduleName[2], 2));
        fs::path const module(modulePath / moduleName);

        std::cout << "Patching module...\n";

        FilePatcher patcher(module);

        std::cout << "patching Password\n";
        // if (Authentication::ServerSignature::ClientValidateProof(x)) to if (true)
        patcher.Patch(PATCH::Password(), PATTERN::Password());

        std::string const newModuleName(Helper::GetFileChecksum(patcher.GetBinary()) + ".auth");
        fs::path const newModulePath
        (path / std::string(&newModuleName[0], 2) / std::string(&newModuleName[2], 2));

        if (!fs::exists(newModulePath))
            fs::create_directories(newModulePath);

        if (fs::exists(newModulePath / newModuleName))
            fs::permissions(newModulePath / newModuleName, fs::add_perms | fs::others_write | fs::group_write | fs::owner_write);
        patcher.Finish(newModulePath / newModuleName);
        fs::permissions(newModulePath / newModuleName, fs::remove_perms | fs::others_write | fs::group_write | fs::owner_write);

        std::cout << "Patching module finished.\n";
    }

    template<typename PATCH, typename PATTERN>
    void do_client_patches(Patcher* patcher)
    {
        std::cout << "Patching client memory...\n";

        std::cout << "patching redirect RSA Modulus\n";
        patcher->Patch(Patches::Common::Modulus(), Patterns::Common::Modulus());

        std::cout << "Patching done.\n";
    }

    bool LaunchAndInject(boost::filesystem::path binaryDir, bool patcherConsole, std::vector<std::string> const& args)
    {
        HANDLE processHandle = INVALID_HANDLE_VALUE;
        try
        {
#ifdef _M_IX86
            char const* executable = "Wow.exe";
            char const* dllName = "client_patcher_32.dll";
#else
            char const* executable = "Wow-64.exe";
            char const* dllName = "client_patcher_64.dll";
#endif
            std::string gameInstallDir = binaryDir.string();

            std::cout << "Injecting " << dllName << " into " << executable << " process..\n";

            char commandLine[32768] = {};
            strcat(commandLine, gameInstallDir.c_str());
            strcat(commandLine, "\\");
            strcat(commandLine, executable);
            for (std::string const& arg : args)
            {
                strcat(commandLine, " ");
                strcat(commandLine, arg.c_str());
            }

            char selfName[MAX_PATH] = {};
            GetModuleFileNameA(nullptr, selfName, sizeof(selfName));

            std::string dllPath = (boost::filesystem::path(selfName).remove_filename() / dllName).string();

            if (!boost::filesystem::exists(dllPath))
                throw std::exception("Launcher::LaunchAndInject | ERROR: couldn't find client_patcher dll!");

            STARTUPINFOA startupInfo{ sizeof(STARTUPINFOA) };
            PROCESS_INFORMATION processInfo;
            if (!CreateProcessA(nullptr, commandLine, nullptr, nullptr, TRUE, CREATE_SUSPENDED, nullptr, gameInstallDir.c_str(), &startupInfo, &processInfo))
                return false;

            processHandle = processInfo.hProcess;

            MemoryPatcher patcher(processInfo.hProcess);

            if (!patcher.IsSupportedBuild())
                throw std::exception("Launcher::LaunchAndInject | ERROR: Client version different than 4.3.4.15595!");

#ifdef _M_IX86
            do_client_patches<Patches::Windows::x86, Patterns::Windows::x86>(&patcher);
#else
            do_client_patches<Patches::Windows::x64, Patterns::Windows::x64>(&patcher);
#endif

            ResumeThread(processInfo.hThread);

            HMODULE hModule = GetModuleHandle("kernel32.dll");
            if (!hModule)
                throw std::exception("Launcher::LaunchAndInject | ERROR: couldn't get kernel32.dll handle!");

            FARPROC loadLibA = GetProcAddress(hModule, "LoadLibraryA");
            if (!loadLibA)
                throw std::exception("Launcher::LaunchAndInject | ERROR: couldn't get LoadLibraryA ProcAddress");

            LPVOID allocatedMem = VirtualAllocEx(processInfo.hProcess, nullptr, dllPath.length() + 1, (MEM_RESERVE | MEM_COMMIT), PAGE_READWRITE);
            if (!allocatedMem)
            {
                CloseHandle(processInfo.hProcess);
                throw std::exception("Launcher::LaunchAndInject | ERROR: VirtualAllocEx failed. Errorcode " + GetLastError());
            }

            if (!WriteProcessMemory(processInfo.hProcess, allocatedMem, dllPath.c_str(), dllPath.length() + 1, nullptr))
            {
                VirtualFreeEx(processInfo.hProcess, allocatedMem, 0, MEM_RELEASE);
                CloseHandle(processInfo.hProcess);
                throw std::exception("Launcher::LaunchAndInject | ERROR: WriteProcessMemory failed. Errorcode " + GetLastError());
            }
            WaitForInputIdle(processInfo.hProcess, INFINITE);

            HANDLE hRemoteThread = CreateRemoteThread(processInfo.hProcess, nullptr, CREATE_SUSPENDED, (LPTHREAD_START_ROUTINE)loadLibA, allocatedMem, 0, nullptr);
            if (!hRemoteThread)
            {
                VirtualFreeEx(processInfo.hProcess, allocatedMem, 0, MEM_RELEASE);
                CloseHandle(processInfo.hProcess);
                throw std::exception("Launcher::LaunchAndInject | ERROR: CreateRemoteThread failed. Errorcode " + GetLastError());
            }

            if (patcherConsole)
            {
                HRESULT hr = SetThreadDescription(hRemoteThread, L"console");
                if (FAILED(hr))
                {
                    std::cout << "Launcher::LaunchAndInject | Warning: SetThreadDescription failed\n";
                }
            }
            WaitForSingleObject(hRemoteThread, INFINITE);

            VirtualFreeEx(processInfo.hProcess, allocatedMem, 0, MEM_RELEASE);
            CloseHandle(hRemoteThread);
            CloseHandle(processInfo.hProcess);
            CloseHandle(processHandle);
            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl;
            if (processHandle != INVALID_HANDLE_VALUE)
                TerminateProcess(processHandle, 1);
            return false;
        }
        return true;
    }

    std::pair<po::variables_map, std::vector<std::string>> GetConsoleArguments(int argc, char** argv)
    {
        po::options_description all("Allowed options");
        all.add_options()
            ("help,h", "print usage message")
            ("path", po::value<std::string>()->default_value(boost::filesystem::current_path().string()), "Path to the Wow.exe")
            ("console", "Open patcher console")
            ;

        po::positional_options_description pos;
        pos.add("path", 1);

        po::variables_map vm;
        std::vector<std::string> unrecognized;
        try
        {
            po::basic_parsed_options<char> parsed = po::command_line_parser(argc, argv).options(all).positional(pos).allow_unregistered().run();
            po::store(parsed, vm);
            unrecognized = po::collect_unrecognized(parsed.options, po::exclude_positional);
            po::notify(vm);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

        if (vm.count("help"))
            std::cout << all << "\n";

        return std::make_pair(std::move(vm), std::move(unrecognized));
    }
}

int main(int argc, char** argv)
{
    using namespace ClientLauncher;

    try
    {
        Trinity::Banner::Show("client_launcher", [](char const* text) { std::cout << text << std::endl; }, nullptr);

        auto vm = GetConsoleArguments(argc, argv);

        // exit if help is enabled
        if (vm.first.count("help"))
        {
            std::cin.get();
            return 0;
        }

        bool console = false;
        if (vm.first.count("console"))
            console = true;

        wchar_t* commonAppData(nullptr);
        SHGetKnownFolderPath(FOLDERID_ProgramData, 0, nullptr, &commonAppData);

        if (!Helper::VerifyRequirements(std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")))
            return 1;

#ifdef _M_IX86
        do_module<Patches::Windows::x86, Patterns::Windows::x86>("8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth", std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/"));
#else
        do_module<Patches::Windows::x64, Patterns::Windows::x64>("0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth", std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/"));
#endif

        boost::filesystem::path binary_path(vm.first["path"].as<std::string>());

        if (!LaunchAndInject(binary_path, console, vm.second))
            return 1;

        return 0;
    }
    catch (std::exception const& ex)
    {
        std::cerr << "EX: " << ex.what() << std::endl;
        std::cerr << "An error occurred. Press ENTER to continue...";
        std::cin.get();
        return 1;
    }
}

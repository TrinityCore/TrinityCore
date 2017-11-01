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

#include "Banner.h"
#include "Helper.hpp"
#include "NtSection.hpp"
#include "Patcher.hpp"
#include "Patches/Common.hpp"
#include "Patches/Windows.hpp"
#include "Patterns/Common.hpp"
#include "Patterns/Windows.hpp"
#include "../client_initializer/IPCData.h"
#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <Windows.h>

template<typename T, typename D>
struct winapi_lambda_deleter : D
{
    using pointer = T;
    winapi_lambda_deleter(D&& deleter) : D(std::forward<D>(deleter)) { }
};

template<typename T, typename D>
struct winapi_function_pointer_deleter
{
    using pointer = T;
    winapi_function_pointer_deleter(D deleter) : _deleter(deleter) { }

    void operator()(pointer ptr) { _deleter(ptr); }

private:
    D _deleter;
};

template<typename T, typename D>
auto make_winapi_ptr(T ptr, D&& deleter)
{
    using deleter_t = std::conditional_t<std::is_pointer_v<D> && std::is_function_v<std::remove_pointer_t<D>>,
        winapi_function_pointer_deleter<T, D>,
        winapi_lambda_deleter<T, D>>;

    return std::unique_ptr<T, deleter_t>(ptr, deleter_t(std::forward<D>(deleter)));
}

namespace po = boost::program_options;

namespace ClientLauncher
{
    auto apcStartedEvent = make_winapi_ptr(CreateEventA(nullptr, TRUE, FALSE, ApcStarted), &CloseHandle);
    auto apcFinishedEvent = make_winapi_ptr(CreateEventA(nullptr, TRUE, FALSE, ApcFinished), &CloseHandle);

    template<typename PATCH, typename PATTERN>
    void do_patches(Patcher* patcher, uint32 buildNumber)
    {
        std::cout << "patching Portal\n";
        // '.actual.battle.net' -> '' to allow for set portal 'host'
        patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

        std::cout << "patching redirect RSA Modulus\n";
        // public component of connection signing key to use known key pair
        patcher->Patch(Patches::Common::Modulus(), Patterns::Common::Modulus());

        std::cout << "patching BNet certificate file location\n";
        // replace name of the file with certificates
        patcher->Patch(Patches::Common::CertFileName(), Patterns::Common::CertFileName());

        std::cout << "patching BNet certificate file to load from local path instead of CASC\n";
        // force loading tc_bundle.txt from local directory instead of CASC
        patcher->Patch(PATCH::CertBundleCASCLocalFile(), PATTERN::CertBundleCASCLocalFile());

        std::cout << "patching BNet certificate file signature check\n";
        // remove signature check from certificate bundle
        patcher->Patch(PATCH::CertBundleSignatureCheck(), PATTERN::CertBundleSignatureCheck());

        std::cout << "patching Versions\n";
        // sever the connection to blizzard's versions file to stop it from updating and replace with custom version
        // this is good practice with or without the retail version, just to stop the exe from auto-patching randomly
        // hardcode %s.patch.battle.net:1119/%s/versions to trinity6.github.io/%s/%s/build/versi
        std::string verPatch(Patches::Common::VersionsFile());
        std::string buildPattern = "build";

        boost::algorithm::replace_all(verPatch, buildPattern, std::to_string(buildNumber));
        std::vector<uint8> verVec(verPatch.begin(), verPatch.end());
        patcher->Patch(verVec, Patterns::Common::VersionsFile());

        std::cout << "patching launcher login parameters location\n";
        // change registry/CFPreferences path
        patcher->Patch(PATCH::LauncherLoginParametersLocation(), PATTERN::LauncherLoginParametersLocation());

        std::cout << "Patching done.\n";
    }

    void WriteCertificateBundle(boost::filesystem::path const& dest)
    {
        std::ofstream ofs(dest.string(), std::ofstream::binary);
        if (!ofs)
            throw std::runtime_error("could not open " + dest.string());

        ofs << std::noskipws << Patches::Common::CertificateBundle();
    }

    bool WaitFor(HANDLE waitedObject)
    {
        switch (WaitForSingleObjectEx(waitedObject, INFINITE, TRUE))
        {
            case WAIT_FAILED:
                return false;
            case WAIT_OBJECT_0:
            case WAIT_TIMEOUT:
            case WAIT_ABANDONED:
                break;
        }
        return true;
    }

    bool LaunchGame(boost::filesystem::path binaryDir, std::vector<std::string> const& args)
    {
#ifdef _M_IX86
        char const* executable = "Wow.exe";
        char const* initializer = "client_initializer_32.dll";
#else
        char const* executable = "Wow-64.exe";
        char const* initializer = "client_initializer_64.dll";
#endif

        std::string gameInstallDir = binaryDir.string();

        std::cout << "Creating patched binary..." << std::endl;

        WriteCertificateBundle(binaryDir / "tc_bundle.txt");

        char commandLine[32768] = {};
        strcat(commandLine, gameInstallDir.c_str());
        strcat(commandLine, "\\");
        strcat(commandLine, executable);
        strcat(commandLine, " -noautolaunch64bit");
        for (std::string const& arg : args)
        {
            strcat(commandLine, " ");
            strcat(commandLine, arg.c_str());
        }

        STARTUPINFOA startupInfo{ sizeof(STARTUPINFOA) };
        PROCESS_INFORMATION processInfo;
        if (!CreateProcessA(nullptr, commandLine, nullptr, nullptr, TRUE, CREATE_SUSPENDED, nullptr, gameInstallDir.c_str(), &startupInfo, &processInfo))
            return false;

        auto processHandle = make_winapi_ptr(processInfo.hProcess, &CloseHandle);
        auto mainThreadHandle = make_winapi_ptr(processInfo.hThread, &CloseHandle);

        // kill child process on failure
        auto terminator = make_winapi_ptr(processInfo.hProcess, [](HANDLE handle) { TerminateProcess(handle, 1); });

        auto dllBaseMapping = make_winapi_ptr(CreateFileMappingA(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeof(IPCData), SharedMemoryName), &CloseHandle);

        auto ipcData = make_winapi_ptr(reinterpret_cast<IPCData*>(MapViewOfFile(dllBaseMapping.get(), FILE_MAP_ALL_ACCESS, 0, 0, sizeof(IPCData))), &UnmapViewOfFile);

        // load dll into wow and QueueUserAPC
        char selfName[MAX_PATH] = {};
        GetModuleFileNameA(nullptr, selfName, sizeof(selfName));

        std::string initializerPath = (boost::filesystem::path(selfName).remove_filename() / initializer).string();

        auto dllAddress = make_winapi_ptr(
            VirtualAllocEx(processInfo.hProcess, nullptr, initializerPath.length() + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE),
            [&processInfo](LPVOID ptr) { VirtualFreeEx(processInfo.hProcess, ptr, 0, MEM_RELEASE); });

        if (!dllAddress)
            return false;

        if (!WriteProcessMemory(processInfo.hProcess, dllAddress.get(), initializerPath.c_str(), initializerPath.length() + 1, nullptr))
            return false;

        LPTHREAD_START_ROUTINE loadLibrary = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandleA("kernel32"), "LoadLibraryA"));
        auto loadLibraryThread = make_winapi_ptr(CreateRemoteThread(processInfo.hProcess, nullptr, 0, loadLibrary, dllAddress.get(), 0, nullptr), &CloseHandle);
        if (!loadLibraryThread || !WaitFor(loadLibraryThread.get()))
            return false;

        if (!ipcData->SignalReadyAddress || !ipcData->InitializerHandle)
            return false;

        // doing this before main thread starts ensures it runs right before main and after tls callbacks
        QueueUserAPC(ipcData->SignalReadyAddress, processInfo.hThread, 0);

        ResumeThread(processInfo.hThread);

        if (!WaitFor(apcStartedEvent.get()))
            return false;

        std::unique_ptr<NtSection> section = NtSection::CopyCodeSection(processInfo.hProcess);
        if (!section)
            return false;

        Patcher patcher(section->GetData(), processInfo.hProcess);

        // always set wowBuild to current build of the .exe files
        uint32 wowBuild = Helper::GetBuildNumber(patcher.GetBinary());

        // define logical limits in case the exe was tinkered with and the build number was changed
        if (wowBuild == 0 || wowBuild < 10000 || wowBuild > 65535) // Build number has to be exactly 5 characters long
            throw std::runtime_error("Build number was out of range. Build: " + std::to_string(wowBuild));

        std::cout << "Determined build number: " << std::to_string(wowBuild) << std::endl;

#ifdef _M_IX86
        std::cout << "Win32 client...\n";
        do_patches<Patches::Windows::x86, Patterns::Windows::x86>(&patcher, wowBuild);
#else
        std::cout << "Win64 client...\n";
        do_patches<Patches::Windows::x64, Patterns::Windows::x64>(&patcher, wowBuild);
#endif

        auto writableView = make_winapi_ptr(section->CreateView(PAGE_READWRITE), [&section](PVOID view) { section->DestroyView(view); });
        if (!WriteProcessMemory(processInfo.hProcess, writableView.get(), patcher.GetBinary().data(), section->GetData().size(), nullptr))
            return false;

        std::cout << "Successfully patched.\n";

        // unload initializer
        LPTHREAD_START_ROUTINE freeLibrary = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandleA("kernel32"), "FreeLibrary"));
        auto freeLibraryThread = make_winapi_ptr(CreateRemoteThread(processInfo.hProcess, nullptr, 0, freeLibrary, ipcData->InitializerHandle, 0, nullptr), &CloseHandle);
        if (!freeLibraryThread || !WaitFor(freeLibraryThread.get()))
            return false;

        // unblock wow
        SetEvent(apcFinishedEvent.get());

        // all went well, we can skip killing process
        terminator.release();

        return true;
    }

    std::pair<po::variables_map, std::vector<std::string>> GetConsoleArguments(int argc, char** argv)
    {
        po::options_description all("Allowed options");
        all.add_options()
            ("help,h", "print usage message")
            ("path", po::value<std::string>()->required(), "Path to the Wow.exe")
            ;

        po::positional_options_description pos;
        pos.add("path", 1);

        po::variables_map vm;
        std::vector<std::string> unrecognized;
        try
        {
            po::basic_parsed_options<char> parsed = po::command_line_parser(argc, argv).options(all).positional(pos).allow_unregistered().run();
            po::store(parsed, vm);
            unrecognized = po::collect_unrecognized(parsed.options, po::include_positional);
            po::notify(vm);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

        if (vm.count("help"))
            std::cout << all << "\n";

        if (!vm.count("path"))
            throw std::invalid_argument("Wrong number of arguments: Missing client install directory.");

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

        boost::filesystem::path binary_path(vm.first["path"].as<std::string>());

        if (!LaunchGame(binary_path, vm.second))
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

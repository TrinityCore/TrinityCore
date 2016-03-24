/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Helper.hpp"
#include "Patcher.hpp"
#include "Patches/Common.hpp"
#include "Patches/Mac.hpp"
#include "Patches/Windows.hpp"
#include "Patterns/Common.hpp"
#include "Patterns/Mac.hpp"
#include "Patterns/Windows.hpp"

#include <CompilerDefs.h>

#include <boost/algorithm/string/replace.hpp>
#include <boost/program_options.hpp>

#if PLATFORM == PLATFORM_WINDOWS
#include <Shlobj.h>
#elif PLATFORM == PLATFORM_UNIX
#include <pwd.h>
#endif

namespace po = boost::program_options;

namespace Connection_Patcher
{
    po::variables_map GetConsoleArguments(int argc, char** argv);

    namespace
    {
        template<typename PATCH, typename PATTERN>
        void PatchModule(boost::filesystem::path file, boost::filesystem::path path)
        {
            namespace fs = boost::filesystem;

            std::cout << "Patching module...\n";

            Patcher patcher(file);

            std::cout << "patching Password\n";
            // if (Authentication::ServerSignature::ClientValidateProof(x)) to if (true)
            patcher.Patch(PATCH::Password(), PATTERN::Password());

            std::string const moduleName(Helper::GetFileChecksum(patcher.GetBinary()) + ".auth");
            fs::path const modulePath
                (path / std::string(&moduleName[0], 2) / std::string(&moduleName[2], 2));

            if (!fs::exists(modulePath))
                fs::create_directories(modulePath);

            if (fs::exists(modulePath / moduleName))
                fs::permissions(modulePath / moduleName, fs::add_perms | fs::others_write | fs::group_write | fs::owner_write);
            patcher.Finish(modulePath / moduleName);
            fs::permissions(modulePath / moduleName, fs::remove_perms | fs::others_write | fs::group_write | fs::owner_write);

            std::cout << "Patching module finished.\n";
        }

        template<typename PATCH, typename PATTERN>
        void do_module(const std::string& moduleName, const boost::filesystem::path& path)
        {
            boost::filesystem::path const modulePath
                (path / std::string(&moduleName[0], 2) / std::string(&moduleName[2], 2));
            boost::filesystem::path const module(modulePath / moduleName);

            if (!boost::filesystem::exists(module))
            {
                std::cout << "Base module doesn't exist, downloading it...\n";

                if (!boost::filesystem::exists(modulePath))
                    boost::filesystem::create_directories(modulePath);

                std::ofstream outFile(module.string(), std::ofstream::out | std::ofstream::binary);
                Helper::DownloadFile("xx.depot.battle.net", 1119, "/" + moduleName, outFile);
                outFile.close();
                std::cout << "Done.\n";
            }

            PatchModule<PATCH, PATTERN>(module, path);
        }

        template<typename PATCH, typename PATTERN>
        void do_patches(Patcher* patcher, boost::filesystem::path output, uint32_t buildNumber)
        {
            std::cout << "patching Portal\n";
            // '.logon.battle.net' -> '' to allow for set portal 'host'
            patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

            std::cout << "patching redirect RSA Modulus\n";
            // public component of connection signing key to use known key pair
            patcher->Patch(Patches::Common::Modulus(), Patterns::Common::Modulus());

            std::cout << "patching BNet\n";
            // hardcode 213.248.127.130 in IP6::Address::Address(IP4::Address::Address const&)
            // used in Creep::Layer::Authentication::Online(), which overwrites GameStream::Connection::GetAddressRemote()
            // to avoid CRYPT_SERVER_ADDRESS_IPV6 check in module
            patcher->Patch(PATCH::BNet(), PATTERN::BNet());

            std::cout << "patching Signature\n";
            // if (Authentication::ModuleSignature::Validator::IsValid(x)) to if (true) in
            // Creep::Instance::LoadModule() to allow for unsigned auth module
            patcher->Patch(PATCH::Signature(), PATTERN::Signature());

            std::cout << "patching Versions\n";
            // sever the connection to blizzard's versions file to stop it from updating and replace with custom version
            // this is good practice with or without the retail version, just to stop the exe from auto-patching randomly
            // hardcode %s.patch.battle.net:1119/%s/versions to trinity6.github.io/%s/%s/build/versi
            std::string verPatch(Patches::Common::VersionsFile());
            std::string buildPattern = "build";

            boost::algorithm::replace_all(verPatch, buildPattern, std::to_string(buildNumber));
            std::vector<unsigned char> verVec(verPatch.begin(), verPatch.end());
            patcher->Patch(verVec, Patterns::Common::VersionsFile());

            patcher->Finish(output);

            std::cout << "Patching done.\n";
        }
    }

    po::variables_map GetConsoleArguments(int argc, char** argv)
    {
        po::options_description all("Allowed options");
        all.add_options()
            ("help,h", "print usage message")
            ("path", po::value<std::string>()->required(), "Path to the Wow.exe")
            ("modulePath,m", po::value<std::string>(), "Path to the Battle.net module download destination.")
            ;

        po::positional_options_description pos;
        pos.add("path", 1);

        po::variables_map vm;
        try
        {
            po::store(po::command_line_parser(argc, argv).options(all).positional(pos).run(), vm);
            po::notify(vm);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

        if (vm.count("help"))
            std::cout << all << "\n";

        if (!vm.count("path"))
            throw std::invalid_argument("Wrong number of arguments: Missing client file.");

        return vm;
    }
}

int main(int argc, char** argv)
{
    using namespace Connection_Patcher;

    try
    {
        auto vm = GetConsoleArguments(argc, argv);

        // exit if help is enabled
        if (vm.count("help"))
        {
            std::cin.get();
            return 0;
        }

        std::string const binary_path(std::move(vm["path"].as<std::string>()));
        std::string renamed_binary_path(binary_path);
        std::wstring appDataPath;

#if PLATFORM == PLATFORM_WINDOWS
        wchar_t* tempPath(nullptr);
        SHGetKnownFolderPath(FOLDERID_ProgramData, 0, NULL, &tempPath);
        appDataPath = std::wstring(tempPath);
#elif PLATFORM == PLATFORM_UNIX
        char* tempPath(nullptr);
        if ((tempPath = getenv("HOME")) == nullptr)
            tempPath = getpwuid(getuid())->pw_dir;
        std::string tempPathStr(tempPath);
        appDataPath.assign(tempPathStr.begin(), tempPathStr.end());
        appDataPath += std::wstring(L"/.wine/drive_c/users/Public/Application Data");
#endif
        if (vm.count("modulePath"))
            appDataPath.assign(vm["modulePath"].as<std::string>().begin(), vm["modulePath"].as<std::string>().end());

        std::cout << "Creating patched binary..." << std::endl;

        Patcher patcher(binary_path);

        // always set wowBuild to current build of the .exe files
        int wowBuild = Helper::GetBuildNumber(patcher.GetBinary());

        // define logical limits in case the exe was tinkered with and the build number was changed
        if (wowBuild == 0 || wowBuild < 10000 || wowBuild > 65535) // Build number has to be exactly 5 characters long
            throw std::runtime_error("Build number was out of range. Build: " + std::to_string(wowBuild));

        std::cout << "Determined build number: " << std::to_string(wowBuild) << std::endl;

        switch (patcher.GetType())
        {
            case Constants::BinaryTypes::Pe32:
                std::cout << "Win32 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_patches<Patches::Windows::x86, Patterns::Windows::x86>
                    (&patcher, renamed_binary_path, wowBuild);

                do_module<Patches::Windows::x86, Patterns::Windows::x86>
                    ( "8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth"
                    , std::wstring(appDataPath) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                    );

                break;
            case Constants::BinaryTypes::Pe64:
                std::cout << "Win64 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_patches<Patches::Windows::x64, Patterns::Windows::x64>
                    (&patcher, renamed_binary_path, wowBuild);

                do_module<Patches::Windows::x64, Patterns::Windows::x64>
                    ( "0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth"
                    , std::wstring(appDataPath) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                    );

                break;
            case Constants::BinaryTypes::Mach64:
                std::cout << "Mac client...\n";

                boost::algorithm::replace_all (renamed_binary_path, ".app", " Patched.app");
                Helper::CopyDir(boost::filesystem::path(binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        , boost::filesystem::path(renamed_binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        );

                do_patches<Patches::Mac::x64, Patterns::Mac::x64>
                    (&patcher, renamed_binary_path, wowBuild);

                {
                    namespace fs = boost::filesystem;
                    fs::permissions(renamed_binary_path, fs::add_perms | fs::others_exe | fs::group_exe | fs::owner_exe);
                }

                do_module<Patches::Mac::x64, Patterns::Mac::x64>
                    ( "97eeb2e28e9e56ed6a22d09f44e2ff43c93315e006bbad43bafc0defaa6f50ae.auth"
                    , "/Users/Shared/Blizzard/Battle.net/Cache/"
                    );

                break;
            default:
                throw std::runtime_error("Type: " + std::to_string(static_cast<uint32_t>(patcher.GetType())) + " not supported!");
        }

        std::cout << "Successfully created your patched binaries.\n";

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

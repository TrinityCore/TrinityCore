/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Banner.h"
#include "BigNumber.h"
#include "RSA.h"
#include "SHA256.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/program_options.hpp>

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include <Shlobj.h>
#elif TRINITY_PLATFORM == TRINITY_PLATFORM_UNIX
#include <pwd.h>
#endif

namespace po = boost::program_options;

namespace Connection_Patcher
{
    po::variables_map GetConsoleArguments(int argc, char** argv);

    namespace
    {
        template<typename PATCH, typename PATTERN>
        void do_patches(Patcher* patcher, boost::filesystem::path output, uint32_t buildNumber)
        {
            std::cout << "patching Portal\n";
            // '.actual.battle.net' -> '' to allow for set portal 'host'
            patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

            std::cout << "patching redirect RSA Modulus\n";
            // public component of connection signing key to use known key pair
            patcher->Patch(Patches::Common::Modulus(), Patterns::Common::Modulus());

            std::cout << "patching BNet certificate file location\n";
            // replace certificate bundle url
            patcher->Patch(Patches::Common::CertBundleUrl(), Patterns::Common::CertBundleUrl());

            std::cout << "patching BNet certificate file signature\n";
            Trinity::Crypto::RSA rsa;
            rsa.LoadFromString(Patches::Common::CertificatePrivateKey(), Trinity::Crypto::RSA::PrivateKey{});
            std::unique_ptr<uint8[]> modulusArray = rsa.GetModulus().AsByteArray(256);
            patcher->Patch(std::vector<uint8>(modulusArray.get(), modulusArray.get() + 256), Patterns::Common::CertSignatureModulus());

            std::cout << "patching Versions\n";
            // sever the connection to blizzard's versions file to stop it from updating and replace with custom version
            // this is good practice with or without the retail version, just to stop the exe from auto-patching randomly
            // hardcode %s.patch.battle.net:1119/%s/versions to trinity6.github.io/%s/%s/build/versi
            std::string verPatch(Patches::Common::VersionsFile());
            std::string buildPattern = "build";

            boost::algorithm::replace_all(verPatch, buildPattern, std::to_string(buildNumber));
            std::vector<unsigned char> verVec(verPatch.begin(), verPatch.end());
            patcher->Patch(verVec, Patterns::Common::VersionsFile());

            std::cout << "patching launcher login parameters location\n";
            // change registry/CFPreferences path
            patcher->Patch(PATCH::LauncherLoginParametersLocation(), PATTERN::LauncherLoginParametersLocation());

            patcher->Finish(output);

            std::cout << "Patching done.\n";
        }

        void WriteCertificateBundle(boost::filesystem::path const& dest)
        {
            if (!boost::filesystem::exists(dest.parent_path()) &&
                !boost::filesystem::create_directories(dest.parent_path()))
                throw std::runtime_error("could not create " + dest.parent_path().string());

            std::ofstream ofs(dest.string(), std::ofstream::binary);
            if (!ofs)
                throw std::runtime_error("could not open " + dest.string());

            ofs << std::noskipws << Patches::Common::CertificateBundle() << "NGIS";

            SHA256Hash signatureHash;
            signatureHash.UpdateData(Patches::Common::CertificateBundle());
            signatureHash.UpdateData("Blizzard Certificate Bundle");
            signatureHash.Finalize();
            std::array<uint8, 256> signature;

            Trinity::Crypto::RSA rsa;
            rsa.LoadFromString(Patches::Common::CertificatePrivateKey(), Trinity::Crypto::RSA::PrivateKey{});
            rsa.Sign(signatureHash.GetDigest(), signatureHash.GetLength(), signature.data(), Trinity::Crypto::RSA::SHA256{});

            ofs.write(reinterpret_cast<char const*>(signature.data()), signature.size());
        }
    }

    po::variables_map GetConsoleArguments(int argc, char** argv)
    {
        po::options_description all("Allowed options");
        all.add_options()
            ("help,h", "print usage message")
            ("path", po::value<std::string>()->required(), "Path to the Wow.exe")
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
        Trinity::Banner::Show("connection_patcher", [](char const* text) { std::cout << text << std::endl; }, nullptr);

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

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
        wchar_t* tempPath(nullptr);
        SHGetKnownFolderPath(FOLDERID_ProgramData, 0, NULL, &tempPath);
        appDataPath = std::wstring(tempPath);
        CoTaskMemFree(tempPath);
#elif TRINITY_PLATFORM == TRINITY_PLATFORM_UNIX
        char* tempPath(nullptr);
        if ((tempPath = getenv("HOME")) == nullptr)
            tempPath = getpwuid(getuid())->pw_dir;
        std::string tempPathStr(tempPath);
        appDataPath.assign(tempPathStr.begin(), tempPathStr.end());
        appDataPath += std::wstring(L"/.wine/drive_c/users/Public/Application Data");
#elif TRINITY_PLATFORM == TRINITY_PLATFORM_APPLE
        appDataPath = L"/Users/Shared";
#endif
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
            case Constants::BinaryTypes::Pe64:
                std::cout << (patcher.GetType() == Constants::BinaryTypes::Pe64 ? "Win64" : "Win32") << " client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_patches<Patches::Windows, Patterns::Windows>
                    (&patcher, renamed_binary_path, wowBuild);
                WriteCertificateBundle(boost::filesystem::path(appDataPath) / L"Blizzard Entertainment/Battle.net/Cache/web_cert_bundle");
                break;
            case Constants::BinaryTypes::Mach64:
                std::cout << "Mac client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".app", " Patched.app");
                Helper::CopyDir(boost::filesystem::path(binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        , boost::filesystem::path(renamed_binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        );

                do_patches<Patches::Mac, Patterns::Mac>
                    (&patcher, renamed_binary_path, wowBuild);

                {
                    namespace fs = boost::filesystem;
                    fs::permissions(renamed_binary_path, fs::add_perms | fs::others_exe | fs::group_exe | fs::owner_exe);
                }
                WriteCertificateBundle(boost::filesystem::path(appDataPath) / "Blizzard/Battle.net/Cache/web_cert_bundle");
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

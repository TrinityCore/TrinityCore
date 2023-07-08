/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2020 TrinityCore <https://www.trinitycore.org/>
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
#include "IoContext.h"
#include "CompilerDefs.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>
#include <boost/version.hpp>

#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

#ifdef _WIN32
#include <Shlobj.h>
#endif

#ifdef __linux__
#include <pwd.h>
#endif

using namespace boost::asio;
using boost::asio::ip::tcp;

namespace Connection_Patcher
{
    void copyDir(boost::filesystem::path const& source, boost::filesystem::path const& destination);
    void GetFile(const std::string& serverName, int port, const std::string& getCommand, std::ostream& out);

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

            std::string const moduleName(Helper::GetFileChecksum(patcher.binary) + ".auth");
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
                GetFile("xx.depot.battle.net", 1119, "/" + moduleName, outFile);
                outFile.close();
                std::cout << "Done.\n";
            }

            PatchModule<PATCH, PATTERN>(module, path);
        }

        template<typename PATCH, typename PATTERN>
        void do_client_patches(Patcher* patcher, boost::filesystem::path output)
        {
            std::cout << "Patching client binary...\n";

            std::cout << "patching redirect RSA Modulus\n";
            patcher->Patch(Patches::Common::Modulus(), Patterns::Common::Modulus());     
            patcher->Finish(output);

            std::cout << "Patching done.\n";
        }

        template<typename PATCH, typename PATTERN>
        void do_dll_patches(Patcher* patcher, boost::filesystem::path output)
        {
            std::cout << "Patching battle.net binary...\n";

            std::cout << "patching Portal\n";
            patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

            std::cout << "patching Bnet\n";
            patcher->Patch(PATCH::BNet(), PATTERN::BNet());

            std::cout << "patching Signature\n";
            patcher->Patch(PATCH::Signature(), PATTERN::Signature());
            patcher->Finish(output);

            std::cout << "Patching done.\n";
        }
    }

    // adapted from http://stackoverflow.com/questions/8593608/how-can-i-copy-a-directory-using-boost-filesystem
    void copyDir(boost::filesystem::path const& source, boost::filesystem::path const& destination)
    {
        namespace fs = boost::filesystem;
        if (!fs::exists(source) || !fs::is_directory(source))
            throw std::invalid_argument("Source directory " + source.string() + " does not exist or is not a directory.");

        if (fs::exists(destination))
            throw std::invalid_argument("Destination directory " + destination.string() + " already exists.");

        if (!fs::create_directory(destination))
            throw std::runtime_error("Unable to create destination directory" + destination.string());

        for (fs::directory_iterator file(source); file != fs::directory_iterator(); ++file)
        {
            fs::path current(file->path());
            if (fs::is_directory(current))
                copyDir(current, destination / current.filename());
            else
                fs::copy_file(current, destination / current.filename());
        }
    }

    // adapted from http://stackoverflow.com/questions/21422094/boostasio-download-image-file-from-server
    void GetFile(const std::string& serverName, int port, const std::string& getCommand, std::ostream& out)
    {
        Trinity::Asio::IoContext io_service;
        boost::system::error_code error = boost::asio::error::host_not_found;
        tcp::resolver resolver(io_service);
        tcp::socket socket(io_service);

        #if BOOST_VERSION >= 106600
            // Get a list of endpoints corresponding to the server name.
            tcp::resolver::results_type endpoints = resolver.resolve(serverName, std::to_string(port), error);
            if (error)
                throw std::runtime_error("Could not resolve server address for auth module download");

            // Try each endpoint until we successfully establish a connection.
            error = boost::asio::error::host_not_found;
            boost::asio::connect(socket, endpoints, error);
            if (error)
                throw std::runtime_error("Could not connect to server adress for auth module download");
        #else
            // Get a list of endpoints corresponding to the server name.
            tcp::resolver::query query(serverName, std::to_string(port));
            tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
            tcp::resolver::iterator end;

            // Try each endpoint until we successfully establish a connection.
            while (error && endpoint_iterator != end)
            {
                socket.close();
                socket.connect(*endpoint_iterator++, error);
            }
        #endif

        boost::asio::streambuf request;
        std::ostream request_stream(&request);

        request_stream << "GET " << getCommand << " HTTP/1.0\r\n";
        request_stream << "Host: " << serverName << ':' << port << "\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: close\r\n\r\n";

        // Send the request.
        boost::asio::write(socket, request);

        // Read the response status line.
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // Check that response is OK.
        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);


        // Read the response headers, which are terminated by a blank line.
        boost::asio::read_until(socket, response, "\r\n\r\n");

        // Process the response headers.
        std::string header;
        while (std::getline(response_stream, header) && header != "\r")
        {
        }

        // Write whatever content we already have to output.
        if (response.size() > 0)
        {
            out << &response;
        }

        // Read until EOF, writing data to output as we go.
        while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
        {
            out << &response;
        }
    }

}

int main(int argc, char** argv)
{
    using namespace Connection_Patcher;

    try
    {
        Trinity::Banner::Show("connection_patcher", [](char const* text) { std::cout << text << std::endl; }, nullptr);

        if (argc != 2)
            throw std::invalid_argument("Wrong number of arguments: Missing client file.");

        std::string const binary_path(argv[1]);
        std::string renamed_binary_path(binary_path);
#ifdef _WIN32
        wchar_t* commonAppData(nullptr);
        SHGetKnownFolderPath(FOLDERID_ProgramData, 0, nullptr, &commonAppData);
#endif

        std::cout << "Creating patched binary..." << std::endl;


#ifdef __APPLE__
        // we are using the '.app' directory on the patcher, due to that the type is determined wrongly
        // lets do some checks
        boost::filesystem::path mp(binary_path);
        mp = mp.append("Contents").append("MacOS").append("World of Warcraft-64");
        if (!boost::filesystem::exists(mp))
            throw std::runtime_error("Use World of Warcraft-64.app instead of files inside, I'm doing da stuff inside");
        Patcher patcher(mp);
#else
        Patcher patcher(binary_path);
#endif

        switch (patcher.Type)
        {
            case Constants::BinaryTypes::Pe32:
            {
                std::cout << "Win32 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_client_patches<Patches::Windows::x86, Patterns::Windows::x86>
                    (&patcher, renamed_binary_path);

                boost::filesystem::path p(binary_path);
                p.remove_filename();
                p.append("Battle.net.dll");

                std::string renamed_dll_path(p.string());
                Patcher bnetPatcher(p.string());

                boost::algorithm::replace_all(renamed_dll_path, ".dll", "_Patched.dll");
                do_dll_patches<Patches::Windows::x86, Patterns::Windows::x86>
                    (&bnetPatcher, renamed_dll_path);
                
                #ifdef __linux__
                const char *homedir;
                if ((homedir = getenv("HOME")) == NULL) {
                    homedir = getpwuid(getuid())->pw_dir;
                }
                const size_t length = strlen(homedir);

                std::wstring homedir_wstring(length, L'#');
                mbstowcs(&homedir_wstring[0], homedir, length);

                do_module<Patches::Windows::x86, Patterns::Windows::x86>
                    ("8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth",
                     homedir_wstring + 
                     std::wstring(L"/.wine/drive_c/ProgramData/Blizzard Entertainment/Battle.net/Cache/"));
                #endif

                #ifdef _WIN32
                do_module<Patches::Windows::x86, Patterns::Windows::x86>
                    ("8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth"
                        , std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                        );
                #endif

                break;
            }
            case Constants::BinaryTypes::Pe64:
            {
                std::cout << "Win64 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_client_patches<Patches::Windows::x64, Patterns::Windows::x64>
                    (&patcher, renamed_binary_path);

                boost::filesystem::path p(binary_path);
                p.remove_filename();
                p.append("Battle.net-64.dll");

                std::string renamed_dll_path(p.string());
                Patcher bnetPatcher(p.string());

                boost::algorithm::replace_all(renamed_dll_path, ".dll", "_Patched.dll");
                do_dll_patches<Patches::Windows::x64, Patterns::Windows::x64>
                    (&bnetPatcher, renamed_dll_path);
                
                #ifdef __linux__
                const char *homedir;
                if ((homedir = getenv("HOME")) == NULL) {
                    homedir = getpwuid(getuid())->pw_dir;
                }
                const size_t length = strlen(homedir);

                std::wstring homedir_wstring(length, L'#');
                mbstowcs(&homedir_wstring[0], homedir, length);

                do_module<Patches::Windows::x64, Patterns::Windows::x64>
                    ("0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth",
                     homedir_wstring + 
                     std::wstring(L"/.wine/drive_c/ProgramData/Blizzard Entertainment/Battle.net/Cache/"));
                #endif

                #ifdef _WIN32
                do_module<Patches::Windows::x64, Patterns::Windows::x64>
                    ("0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth"
                        , std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                        );
                #endif

                break;
            }
            case Constants::BinaryTypes::Mach64:
            {
                std::cout << "Mac client...\n";

                boost::filesystem::path originalPath(renamed_binary_path);
                boost::algorithm::replace_all(renamed_binary_path, ".app", "_Patched.app");
                boost::filesystem::path renamedApp(renamed_binary_path);
                copyDir(originalPath, renamedApp);

                boost::filesystem::path binaryPath(renamed_binary_path);
                binaryPath = binaryPath.append("Contents").append("MacOS").append("World of Warcraft-64");
                do_client_patches<Patches::Mac::x64, Patterns::Mac::x64>
                    (&patcher, binaryPath);
                boost::filesystem::permissions(binaryPath, boost::filesystem::owner_exe | boost::filesystem::group_exe | boost::filesystem::others_exe);

                boost::filesystem::path renamedDll = renamedApp.append("Contents").append("Frameworks").append("Battle.net.bundle");
                std::string renamed_dll_path(renamedDll.string());
                Patcher bnetPatcher(renamed_dll_path);

                do_dll_patches<Patches::Mac::x64, Patterns::Mac::x64>
                    (&bnetPatcher, renamed_dll_path);

                do_module<Patches::Mac::x64, Patterns::Mac::x64>
                    ("97eeb2e28e9e56ed6a22d09f44e2ff43c93315e006bbad43bafc0defaa6f50ae.auth"
                        , "/Users/Shared/Blizzard/Battle.net/Cache/"
                        );

                break;
            }
            default:
                throw std::runtime_error("Type: " + std::to_string(static_cast<uint32_t>(patcher.Type)) + " not supported!");
        }

        std::cout << "Successfully created your patched binaries.\n";
        std::cin.get();

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

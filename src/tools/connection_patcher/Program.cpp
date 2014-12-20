/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include <boost/filesystem.hpp>

#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

#if PLATFORM == PLATFORM_WINDOWS
#include <Shlobj.h>
#endif

using namespace boost::asio;
using boost::asio::ip::tcp;

namespace Connection_Patcher
{
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

            if (fs::exists(modulePath / modulePath))
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
        void do_patches(Patcher* patcher, boost::filesystem::path output)
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

            patcher->Finish(output);

            std::cout << "Patching done.\n";
        }
    }

    // adapted from http://stackoverflow.com/questions/8593608/how-can-i-copy-a-directory-using-boost-filesystem
    void copyDir(boost::filesystem::path const & source, boost::filesystem::path const & destination)
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
        boost::asio::io_service io_service;

        // Get a list of endpoints corresponding to the server name.
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(serverName, std::to_string(port));
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::resolver::iterator end;

        // Try each endpoint until we successfully establish a connection.
        tcp::socket socket(io_service);
        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpoint_iterator != end)
        {
            socket.close();
            socket.connect(*endpoint_iterator++, error);
        }

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
        if (argc != 2)
            throw std::invalid_argument("Wrong number of arguments: Missing client file.");

        std::string const binary_path(argv[1]);

        std::string renamed_binary_path(binary_path);

        wchar_t* commonAppData(nullptr);
#if PLATFORM == PLATFORM_WINDOWS
        SHGetKnownFolderPath(FOLDERID_ProgramData, 0, NULL, &commonAppData);
#endif

        std::cout << "Creating patched binaries for ";

        Patcher patcher(binary_path);

        switch (patcher.Type)
        {
            case Constants::BinaryTypes::Pe32:
                std::cout << "Win32 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_patches<Patches::Windows::x86, Patterns::Windows::x86>
                    (&patcher, renamed_binary_path);

                do_module<Patches::Windows::x86, Patterns::Windows::x86>
                    ( "8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth"
                    , std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                    );

                break;
            case Constants::BinaryTypes::Pe64:
                std::cout << "Win64 client...\n";

                boost::algorithm::replace_all(renamed_binary_path, ".exe", "_Patched.exe");
                do_patches<Patches::Windows::x64, Patterns::Windows::x64>
                    (&patcher, renamed_binary_path);

                do_module<Patches::Windows::x64, Patterns::Windows::x64>
                    ( "0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth"
                    , std::wstring(commonAppData) + std::wstring(L"/Blizzard Entertainment/Battle.net/Cache/")
                    );

                break;
            case Constants::BinaryTypes::Mach64:
                std::cout << "Mac client...\n";

                boost::algorithm::replace_all (renamed_binary_path, ".app", " Patched.app");
                copyDir ( boost::filesystem::path(binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        , boost::filesystem::path(renamed_binary_path).parent_path()/*MacOS*/.parent_path()/*Contents*/.parent_path()
                        );

                do_patches<Patches::Mac::x64, Patterns::Mac::x64>
                    (&patcher, renamed_binary_path);

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
                throw std::runtime_error("Type: " + std::to_string(static_cast<uint32_t>(patcher.Type)) + " not supported!");
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

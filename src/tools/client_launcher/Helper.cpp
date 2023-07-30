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

#include "Helper.hpp"
#include "IoContext.h"

#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <fstream>
#include <iostream>
#include <SHA256.h>
#include <stdexcept>
#include <Util.h>

namespace asio = boost::asio;
namespace ssl = asio::ssl;
namespace http = boost::beast::http;

namespace ClientLauncher
{
    namespace Helper
    {
        std::string GetFileChecksum(std::vector<unsigned char> const& data)
        {
            SHA256Hash h;
            h.UpdateData(data.data(), data.size());
            h.Finalize();

            std::string checksum = ByteArrayToHexStr(h.GetDigest(), h.GetLength());
            boost::algorithm::to_lower(checksum);
            return checksum;
        }

        std::vector<unsigned char> ReadFile(boost::filesystem::path const& path)
        {
            std::ifstream ifs(path.string(), std::ifstream::binary);
            if (!ifs)
                throw std::runtime_error("could not open " + path.string());

            std::vector<unsigned char> binary;
            ifs >> std::noskipws;
            ifs.seekg(0, std::ios_base::end);
            binary.reserve(ifs.tellg());
            ifs.seekg(0, std::ios_base::beg);

            std::copy(std::istream_iterator<unsigned char>(ifs), std::istream_iterator<unsigned char>(), std::back_inserter(binary));

            return binary;
        }

        void GetFile(std::string const& url, std::ostream& out)
        {
            try
            {
                Trinity::Asio::IoContext io_context;
                ssl::context ssl_context(ssl::context::tlsv12_client);

                ssl_context.set_verify_mode(ssl::verify_peer);
                ssl_context.set_default_verify_paths();
                ssl_context.set_verify_mode(ssl::verify_none);

                ssl::stream<asio::ip::tcp::socket> socket(io_context, ssl_context);
                asio::ip::tcp::resolver resolver(io_context);

                auto const host = url.substr(url.find("://") + 3, url.find('/', 8) - (url.find("://") + 3));
                auto const port = "443";
                auto const target = url.substr(url.find('/', 8));

                asio::connect(socket.next_layer(), resolver.resolve(host, port));
                socket.handshake(ssl::stream_base::client);

                http::request<http::string_body> request(http::verb::get, target, 11);
                request.set(http::field::host, host);
                request.set(http::field::user_agent, "TCPP ClientLauncher");

                http::write(socket, request);

                boost::beast::flat_buffer buffer;
                http::response<http::string_body> response;
                http::read(socket, buffer, response);

                out << response.body();
            }
            catch (std::exception& e)
            {
                std::cerr << "ERROR: " << e.what() << std::endl;
            }
        }

        bool VerifyRequirements(const boost::filesystem::path& commonAppData)
        {
            std::vector<std::string> requiredFiles
            {
                {"047329d08d433da2622e9fc2ee96c8dd8f35e7770699d07cf74855b9c8ea9125.pfty"},
                {"0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth"},
                {"0a3f6f3f0535ea21dbe620085192afc796203047e270e0e1b76f15a739fe1797.pfty"},
                {"2753d31092f1978bdd78ebd4fae2d189364ad7108ceb22fbf1413be1f43bef04.pfty"},
                {"305bbdab1953e65974a249e276867e13ad2c3cabca3668983cb5ed406251bb7b.pfty"},
                {"36b27cd911b33c61730a8b82c8b2495fd16e8024fc3b2dde08861c77a852941c.auth"},
                {"3e381d4f83201f4e3c482eb74da12e5ff9dd924da2413d8fb33f5eea9a02c2c2.pfty"},
                {"5813f318f7e40a07a7cdfeeec9827942e6fdc5ccee0d4171148443e429ad0ead.pfty"},
                {"5e298e530698af905e1247e51ef0b109b352ac310ce7802a1f63613db980ed17.auth"},
                {"63bc118937e6ea2faa7b7192676daeb1b7ca87a9c24ed9f5acd60e630b4dd7a4.auth"},
                {"7466b2db3f03768aa2527535d4b3c6c9ef9e8fb07c6db88b1019f3d25a2942e8.pfty"},
                {"83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03.pfty"},
                {"870f53d10b4e1b09d6b622cd5671ba4ff1ad69512dfa2c676072c52e45c7f0f9.pfty"},
                {"8c43bda10be33a32abbc09fb2279126c7f5953336391276cff588565332fcd40.auth"},
                {"8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth"},
                {"97eeb2e28e9e56ed6a22d09f44e2ff43c93315e006bbad43bafc0defaa6f50ae.auth"},
                {"a2ec4b41148214037a2e89a2e557af716d085241b81f5244494bdc77a891ca38.pfty"},
                {"a8c77051991b1a6c5dfe412e9f46d8f584349996fbde37c4f2a527c192163502.pfty"},
                {"b72e65b6b34d8f859e79b5f28952e26553a796d5e1d75c2b5930bc0daeaa728c.pfty"},
                {"c3a1ac0694979e709c3b5486927e558af1e2be02ca96e5615c5a65aacc829226.auth"},
                {"e8b82becbe0a0a1bbb5561df69320edbd770897a8deaab23caa6736255e0dc33.pfty"}
            };

            std::cout << "Validating required module files...\n";

            for (uint32 i = 0; i < requiredFiles.size(); i++)
            {
                boost::filesystem::path modulePath
                (commonAppData / std::string(&requiredFiles[i][0], 2) / std::string(&requiredFiles[i][2], 2));
                boost::filesystem::path module(modulePath / requiredFiles[i]);

                if (!boost::filesystem::exists(module.make_preferred()))
                {
                    std::cout << requiredFiles[i] << " doesn't exist, downloading it...\n";

                    if (!boost::filesystem::exists(modulePath.make_preferred()))
                        boost::filesystem::create_directories(modulePath.make_preferred());
                }
                else
                {
                    if (module.make_preferred().stem().string().compare(Helper::GetFileChecksum(Helper::ReadFile(module.make_preferred()))) == 0)
                        continue;
                    else
                        std::cout << requiredFiles[i] << " is corrupted! Redownloading it...\n";
                }

                std::ofstream outFile(module.string(), std::ofstream::out | std::ofstream::binary);
                GetFile("https://raw.githubusercontent.com/The-Cataclysm-Preservation-Project/AuthModules/master/Windows/ProgramData/Blizzard%20Entertainment/Battle.net/Cache/" +
                    std::string(&requiredFiles[i][0], 2) + "/" + std::string(&requiredFiles[i][2], 2) + "/" + requiredFiles[i], outFile);
                outFile.close();
            }
            std::cout << "Done.\n";
            return true;
        }
    }
}

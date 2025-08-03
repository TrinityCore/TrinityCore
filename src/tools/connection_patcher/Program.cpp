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
#include "Patterns/Common.hpp"

#include "Banner.h"
#include "BigNumber.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/program_options.hpp>


namespace po = boost::program_options;

namespace Connection_Patcher
{
    po::variables_map GetConsoleArguments(int argc, char** argv);

    namespace
    {
        void do_patches(Patcher* patcher, boost::filesystem::path output, uint32_t buildNumber)
        {
            std::cout << "Build: " << std::to_string(buildNumber) << "\n\n";
            std::cout << "patching Portal\n";
            // '.actual.battle.net' -> '' to allow for set portal 'host'
            patcher->Patch(Patches::Common::Portal(), Patterns::Common::Portal());

            std::cout << "patching RSA Modulus\n";
            // public component of connection signing key to use known key pair
            patcher->Patch(Patches::Common::RSAModulus(), Patterns::Common::RSAModulus());

			std::cout << "patching CryptoEd25519 PublicKey\n";
			// public key of ed25519 key pair
            patcher->Patch(Patches::Common::CryptoEd25519PublicKey(), Patterns::Common::CryptoEd25519PublicKey());

            std::cout << "patching Debug information\n";
            // replace arctium with patched. Debug info should not go to blizz with this.
            patcher->Patch(Patches::Common::Debug(), Patterns::Common::Debug());

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

        std::cout << "Creating patched binary..." << std::endl;

        Patcher patcher(binary_path);

        // always set wowBuild to current build of the .exe files
        int wowBuild = Helper::GetBuildNumber(patcher.GetBinary());

        // define logical limits in case the exe was tinkered with and the build number was changed
        if (wowBuild == 0 || wowBuild < 10000 || wowBuild > 99999) // Build number has to be exactly 5 characters long
            throw std::runtime_error("Build number was out of range. Build: " + std::to_string(wowBuild));

        std::cout << "Determined build number: " << std::to_string(wowBuild) << std::endl;

        boost::algorithm::replace_all(renamed_binary_path, ".exe", "_patched.exe");
        do_patches(&patcher, renamed_binary_path, wowBuild);

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

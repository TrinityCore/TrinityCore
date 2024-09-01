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

#include <string>
#include <iostream>

#include "TileAssembler.h"
#include "Banner.h"
#include "Locales.h"
#include "Util.h"

// @tswow-begin
#include <cxxopts.h>

std::string src;
std::string dest;

void HandleArgs(int argc, char** argv)
{
    cxxopts::Options options("vmap4_assembler", "Assemble vmaps");
    options.add_options()
        ("i,input", "Input path", cxxopts::value<std::string>()->default_value("Buildings"))
        ("o,output", "Output path", cxxopts::value<std::string>()->default_value("vmaps"))
        ("maps", "Specify individual maps to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ("tiles", "Specify individual tiles to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ;

    auto result = options.parse(argc, argv);
    src = result["input"].as<std::string>();
    dest = result["output"].as<std::string>();

    // TODO: Handle individual maps
}
// @tswow-end

int main(int argc, char* argv[])
{
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    Trinity::Banner::Show("VMAP assembler", [](char const* text) { std::cout << text << std::endl; }, nullptr);

    // @tswow-begin
    HandleArgs(argc, argv);
    // @tswow-end

    if (argc > 3)
    {
        std::cout << "usage: " << argv[0] << " <raw data dir> <vmap dest dir>" << std::endl;
        return 1;
    }
    else
    {
        if (argc > 1)
            src = argv[1];
        if (argc > 2)
            dest = argv[2];
    }

    std::cout << "using " << src << " as source directory and writing output to " << dest << std::endl;

    VMAP::TileAssembler* ta = new VMAP::TileAssembler(src, dest);

    if (!ta->convertWorld2())
    {
        std::cout << "exit with errors" << std::endl;
        delete ta;
        return 1;
    }

    delete ta;
    std::cout << "Ok, all done" << std::endl;
    return 0;
}

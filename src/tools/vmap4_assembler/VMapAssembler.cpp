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

int main(int argc, char* argv[])
{
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    Trinity::Banner::Show("VMAP assembler", [](char const* text) { std::cout << text << std::endl; }, nullptr);

    std::string src = "Buildings";
    std::string dest = "vmaps";

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

    VMAP::TileAssembler ta(std::move(src), std::move(dest));

    if (!ta.convertWorld2())
    {
        std::cout << "exit with errors" << std::endl;
        return 1;
    }

    std::cout << "Ok, all done" << std::endl;
    return 0;
}

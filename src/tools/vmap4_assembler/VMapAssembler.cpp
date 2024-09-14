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
#include "GitRevision.h"
#include "Locales.h"
#include "Optional.h"
#include "TileAssembler.h"
#include "Util.h"
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <thread>

namespace po = boost::program_options;

/**
 * Parses command line arguments
 *
 * @param [in] argc command line argument count
 * @param [in] argv raw command line arguments
 * @param [out] src raw data dir
 * @param [out] dest vmap dest dir
 * @param [out] threads number of threads to use
 * @return Non-empty optional if program should exit immediately (holds exit code in that case)
 */
Optional<int> HandleArgs(int argc, char* argv[], std::string* src, std::string* dest, uint32* threads);

int main(int argc, char* argv[])
{
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    std::string src, dest;
    uint32 threads = 0;
    if (Optional<int> exitCode = HandleArgs(argc, argv, &src, &dest, &threads))
        return *exitCode;

    Trinity::Banner::Show("VMAP assembler", [](char const* text) { std::cout << text << std::endl; }, nullptr);

    std::cout << "using " << src << " as source directory and writing output to " << dest << std::endl;

    VMAP::TileAssembler ta(src, dest, threads);

    if (!ta.convertWorld2())
    {
        std::cout << "exit with errors" << std::endl;
        return 1;
    }

    std::cout << "Ok, all done" << std::endl;
    return 0;
}

Optional<int> HandleArgs(int argc, char* argv[], std::string* src, std::string* dest, uint32* threads)
{
    po::options_description visible("Usage: vmap4assembler [OPTION]... [SRC] [DEST]\n\nWhere OPTION can be any of");
    visible.add_options()
        ("threads", po::value<uint32>(threads)->default_value(std::thread::hardware_concurrency()), "number of threads to use")
        ("help,h", "print usage message")
        ("version,v", "print version build info");

    po::options_description all;
    all.add(visible);
    all.add_options()
        ("src", po::value(src)->default_value("Buildings"), "raw data dir")
        ("dest", po::value(dest)->default_value("vmaps"), "vmap dest dir");

    po::positional_options_description positional;
    positional.add("src", 1);
    positional.add("dest", 1);

    po::variables_map variablesMap;
    try
    {
        store(po::command_line_parser(argc, argv).options(all).positional(positional).run(), variablesMap);
        notify(variablesMap);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    if (variablesMap.find("help") != variablesMap.end())
    {
        std::cout << visible << '\n';
        return 0;
    }

    if (variablesMap.find("version") != variablesMap.end())
    {
        std::cout << GitRevision::GetFullVersion() << '\n';
        return 0;
    }

    return {};
}

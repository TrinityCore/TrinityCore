// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_SEARCH_PATH_HPP
#define BOOST_PROCESS_POSIX_SEARCH_PATH_HPP

#include <boost/process/config.hpp>
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include <unistd.h>

namespace boost { namespace process { namespace posix {

inline std::string search_path(const std::string &filename,
    std::string path = "")
{
    if (path.empty())
    {
        path = ::getenv("PATH");
        if (path.empty())
            BOOST_PROCESS_THROW(std::runtime_error(
                "Environment variable PATH not found"));
    }

    std::string result;
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(":");
    tokenizer tok(path, sep);
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
    {
        boost::filesystem::path p = *it;
        p /= filename;
        if (!::access(p.c_str(), X_OK))
        {
            result = p.string();
            break;
        }
    }
    return result;
}

}}}

#endif

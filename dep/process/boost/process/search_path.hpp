// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/search_path.hpp
 *
 * Defines a function to search for an executable in path.
 */

#ifndef BOOST_PROCESS_SEARCH_PATH_HPP
#define BOOST_PROCESS_SEARCH_PATH_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(search_path)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(search_path)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Searches for an executable in path.
 *
 * filename must be a basename including the file extension.
 * It must not include any directory separators (like a slash).
 * On Windows the file extension may be omitted. The function
 * will then try the various file extensions for executables on
 * Windows to find filename.
 *
 * path must be a set of directories. Directories must be
 * separated by colons on POSIX and by semicolons on Windows.
 * If path is empty, the environment variable PATH is used.
 *
 * \returns the absolute path to the executable filename or an
 *          empty string if filename isn't found
 *
 * \throws std::runtime_error if path is empty and no environment
 *                            variable PATH exists
 */
string_type search_path(const string_type &filename, string_type path = "");

}}
#endif

#endif

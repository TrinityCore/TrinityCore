// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/mitigate.hpp
 *
 * Helpers to mitigate platform differences.
 */

#ifndef BOOST_PROCESS_MITIGATE_HPP
#define BOOST_PROCESS_MITIGATE_HPP

#include <boost/asio.hpp>
#if defined(BOOST_POSIX_API)
#   include <sys/wait.h>
#endif

namespace boost { namespace process {

#if defined(BOOST_WINDOWS_API)
typedef boost::asio::windows::stream_handle pipe_end;
#elif defined(BOOST_POSIX_API)
typedef boost::asio::posix::stream_descriptor pipe_end;
#endif

inline const char *zero_device()
{
#if defined(BOOST_WINDOWS_API)
    return "NUL";
#elif defined(BOOST_POSIX_API)
    return "/dev/zero";
#endif
}

inline const char *null_device()
{
#if defined(BOOST_WINDOWS_API)
    return "NUL";
#elif defined(BOOST_POSIX_API)
    return "/dev/null";
#endif
}

#if defined(BOOST_WINDOWS_API)
#   define BOOST_PROCESS_EXITSTATUS(a) static_cast<int>(a)
#elif defined(BOOST_POSIX_API)
#   define BOOST_PROCESS_EXITSTATUS WEXITSTATUS
#endif

#if defined(BOOST_PROCESS_DOXYGEN)
/**
 * Type definition for the end of a pipe.
 *
 * On Windows the type is based on boost::asio::windows::stream_handle. On
 * POSIX it is based on boost::asio::posix::stream_descriptor.
 *
 * You can use this type definition for asynchronous I/O with streams of
 * child processes.
 */
typedef boost_asio_type pipe_end;

/**
 * Gets the name of the zero device.
 *
 * You can use zero_device to initialize a
 * boost::iostreams::file_descriptor_source to read
 * null characters from.
 *
 * \returns NUL on Windows and /dev/zero on POSIX.
 */
const char *zero_device();

/**
 * Gets the name of the null device.
 *
 * You can use null_device to initialize a
 * boost::iostreams::file_descriptor_sink which discards
 * data written to it.
 *
 * \returns NUL on Windows and /dev/null on POSIX.
 */
const char *null_device();

/**
 * \def BOOST_PROCESS_EXITSTATUS
 *
 * On Windows \c BOOST_PROCESS_EXITSTATUS is a static cast to \c int.
 * On POSIX it is set to \c WEXITSTATUS.
 *
 * You can use \c BOOST_PROCESS_EXITSTATUS for the return value of
 * boost::process::wait_for_exit to get the exit status of a process.
 */
#define BOOST_PROCESS_EXITSTATUS
#endif

}}

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/wait_for_exit.hpp
 *
 * Defines a function to wait for a process to exit.
 */

#ifndef BOOST_PROCESS_WAIT_FOR_EXIT_HPP
#define BOOST_PROCESS_WAIT_FOR_EXIT_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(wait_for_exit)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(wait_for_exit)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Waits for a process to exit.
 *
 * On Window boost::process::wait_for_exit returns the exit code
 * of the process. On POSIX the exit status is returned. You must
 * use the macro \c WEXITSTATUS (defined in sys/wait.h) to fetch
 * the exit code from the exit status.
 *
 * \note This is a blocking function.
 *
 * \throws boost::system::system_error in case of an error
 */
template <class Process>
int_type wait_for_exit(const Process &p);

/**
 * Waits for a process to exit.
 *
 * On Window boost::process::wait_for_exit returns the exit code
 * of the process. On POSIX the exit status is returned. You must
 * use the macro \c WEXITSTATUS (defined in sys/wait.h) to fetch
 * the exit code from the exit status.
 *
 * \note This is a blocking function.
 */
template <class Process>
int_type wait_for_exit(const Process &p, boost::system::error_code &ec);

}}
#endif

#endif

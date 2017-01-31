// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/terminate.hpp
 *
 * Defines a function to terminate a process.
 */

#ifndef BOOST_PROCESS_TERMINATE_HPP
#define BOOST_PROCESS_TERMINATE_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(terminate)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(terminate)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Terminates a process.
 *
 * \warning Call this function only as a last resort. The process
 *          is terminated immediately and forcefully and has no
 *          chance to close or clean up resources properly.
 *
 * \throws boost::system::system_error in case of an error
 */
template <class Process>
void terminate(const Process &p);

/**
 * Terminates a process.
 *
 * \warning Call this function only as a last resort. The process
 *          is terminated immediately and forcefully and has no
 *          chance to close or clean up resources properly.
 */
template <class Process>
void terminate(const Process &p, boost::system::error_code &ec);

}}
#endif

#endif

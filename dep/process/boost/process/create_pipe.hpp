// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/create_pipe.hpp
 *
 * Defines a function to create a pipe.
 */

#ifndef BOOST_PROCESS_CREATE_PIPE_HPP
#define BOOST_PROCESS_CREATE_PIPE_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(create_pipe)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(create_pipe)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Creates an anonymous pipe.
 *
 * \note On Windows anonymous pipes don't support
 *       asynchronous I/O.
 *
 * \throws boost::system::system_error in case of an error
 */
pipe create_pipe();

/**
 * Creates an anonymous pipe.
 *
 * \note On Windows anonymous pipes don't support
 *       asynchronous I/O.
 */
pipe create_pipe(boost::system::error_code &ec);

}}
#endif

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/pipe.hpp
 *
 * Defines a pipe.
 */

#ifndef BOOST_PROCESS_PIPE_HPP
#define BOOST_PROCESS_PIPE_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(pipe)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(pipe)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(make_pipe)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Represents a pipe.
 */
struct pipe
{
    /**
     * Read-end.
     */
    pipe_end_type source;

    /**
     * Write-end.
     */
    pipe_end_type sink;

    /**
     * Constructor.
     */
    pipe(pipe_end_type source, pipe_end_type sink);
};

/**
 * Returns a pipe instance.
 *
 * This is a helper function to instantiate boost::process::pipe.
 *
 * \note boost::process::make_pipe does not create a pipe.
 *       You must pass existing pipe ends to this function.
 *       If you want to create an anonymous pipe, call
 *       boost::process::create_pipe.
 */
pipe make_pipe(pipe_end_type source, pipe_end_type sink);

}}
#endif

#endif

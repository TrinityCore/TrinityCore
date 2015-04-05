// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/execute.hpp
 *
 * Defines a function to execute a program.
 */

#ifndef BOOST_PROCESS_EXECUTE_HPP
#define BOOST_PROCESS_EXECUTE_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(execute)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(execute)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Starts a program.
 *
 * \tparam initializers define what and how the program is started
 */
template <class Initializer, class... Initializers>
child execute(const Initializer &initializer, const Initializers... &initializers);

}}
#endif

#endif

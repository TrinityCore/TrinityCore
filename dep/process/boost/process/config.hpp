// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/config.hpp
 *
 * Defines various macros.
 */

#ifndef BOOST_PROCESS_CONFIG_HPP
#define BOOST_PROCESS_CONFIG_HPP

#include <boost/config.hpp>
#include <boost/system/config.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

#if defined(BOOST_POSIX_API)
#   include <errno.h>
#   define BOOST_PROCESS_LAST_ERROR errno
#   define BOOST_PROCESS_PLATFORM posix
#elif defined(BOOST_WINDOWS_API)
#   include <Windows.h>
#   define BOOST_PROCESS_LAST_ERROR GetLastError()
#   define BOOST_PROCESS_PLATFORM windows
#endif

/** \cond */
#define BOOST_PROCESS_PLATFORM_PROMOTE_PATH(COMPONENT) \
    <boost/process/BOOST_PROCESS_PLATFORM/COMPONENT.hpp>
#define BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(COMPONENT) \
    namespace boost { namespace process { using BOOST_PROCESS_PLATFORM::COMPONENT; }}
#define BOOST_PROCESS_PLATFORM_PROMOTE_INITIALIZERS_NAMESPACE \
    namespace boost { namespace process { namespace initializers { \
    using namespace boost::process::BOOST_PROCESS_PLATFORM::initializers; }}}
/** \endcond */

#if defined(BOOST_PROCESS_DOXYGEN)
/**
 * \def BOOST_POSIX_API
 *
 * This macro is defined on POSIX.
 */
#define BOOST_POSIX_API
/**
 * \def BOOST_WINDOWS_API
 *
 * This macro is defined on Windows.
 */
#define BOOST_WINDOWS_API
#endif

/**
 * \def BOOST_PROCESS_THROW(EX)
 *
 * Defines how exceptions are thrown. Set this macro for example
 * to \c BOOST_THROW_EXCEPTION if you like to use Boost.Exception.
 */
#define BOOST_PROCESS_THROW(EX) throw EX

/** \cond */
#define BOOST_PROCESS_SOURCE_LOCATION \
    "in file '" __FILE__ "', line " BOOST_STRINGIZE(__LINE__) ": "

#define BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR(what) \
    BOOST_PROCESS_THROW(boost::system::system_error( \
        boost::system::error_code(BOOST_PROCESS_LAST_ERROR, \
            boost::system::system_category()), \
        BOOST_PROCESS_SOURCE_LOCATION what))

#define BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec) \
    ec = boost::system::error_code(BOOST_PROCESS_LAST_ERROR, \
        boost::system::system_category())
/** \endcond */

#endif

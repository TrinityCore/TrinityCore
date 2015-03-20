// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/child.hpp
 *
 * Defines a child process class.
 */

#ifndef BOOST_PROCESS_CHILD_HPP
#define BOOST_PROCESS_CHILD_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(child)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(child)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Represents a child process.
 *
 * On Windows child is movable but non-copyable. The destructor
 * automatically closes handles to the child process.
 */
struct child
{
    /**
     * Process information.
     *
     * \remark <em>Windows only.</em>
     */
    PROCESS_INFORMATION proc_info;

    /**
     * Constructor.
     *
     * \remark <em>Windows only.<em/>
     */
    explicit child(const PROCESS_INFORMATION &pi) : proc_info(pi) {}

    /**
     * Returns the process handle.
     *
     * \remark <em>Windows only.</em>
     */
    HANDLE process_handle() const { return proc_info.hProcess; }

    /**
     * Process identifier.
     *
     * \remark <em>POSIX only.</em>
     */
    pid_t pid;

    /**
     * Constructor.
     *
     * \remark <em>POSIX only.</em>
     */
    explicit child(pid_t p) : pid(p) {}
};

}}
#endif

#endif

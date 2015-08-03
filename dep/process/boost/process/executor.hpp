// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/executor.hpp
 *
 * Defines an executor which can create child processes.
 */

#ifndef BOOST_PROCESS_EXECUTOR_HPP
#define BOOST_PROCESS_EXECUTOR_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(executor)
BOOST_PROCESS_PLATFORM_PROMOTE_NAMESPACE(executor)

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process {

/**
 * Starts a program.
 *
 * boost::process::executor is a functor which calls the system functions
 * to start a program. Before system functions are called it iterates
 * over initializers and calls a member function passing a reference
 * to itself as a parameter. Initializers get then a chance to setup
 * the executor. If system functions fail boost::process::executor again
 * iterates over initializers and calls another member function passing a
 * reference to itself as a parameter. This gives initializers a
 * chance to handle the error.
 *
 * \note Library users shouldn't need to use boost::process::executor.
 *       It is recommended to call boost::process::execute which uses
 *       boost::pocess::executor internally.
 */
struct executor
{
    /**
     * Default constructor.
     */
    executor();

    /**
     * Starts a program.
     *
     * \tparam initializers define what and how the program is started
     */
    template <class Initializer, class... Initializers>
    child operator()(const Initializer &initializer, const Initializers... &initializers);

    ///\defgroup WindowsOnly Windows only.
    ///@{

    /**
     * Program name.
     *
     * \remark <em>Windows only.</em>
     */
    LPCTSTR exe;

    /**
     * Command line.
     *
     * \remark <em>Windows only.</em>
     */
    LPTSTR cmd_line;

    /**
     * Process attributes.
     *
     * \remark <em>Windows only.</em>
     */
    LPSECURITY_ATTRIBUTES proc_attrs;

    /**
     * Thread attributes.
     *
     * \remark <em>Windows only.</em>
     */
    LPSECURITY_ATTRIBUTES thread_attrs;

    /**
     * Flag to inherit handles.
     *
     * \remark <em>Windows only.</em>
     */
    BOOL inherit_handles;

    /**
     * Creation flags.
     *
     * \remark <em>Windows only.</em>
     */
    DWORD creation_flags;

    /**
     * Environment variables.
     *
     * \remark <em>Windows only.</em>
     */
    LPVOID env;

    /**
     * Work directory.
     *
     * \remark <em>Windows only.</em>
     */
    LPCTSTR work_dir;

    /**
     * Startupinfo structure.
     *
     * \remark <em>Windows only.</em>
     */
    STARTUPINFO startup_info;

    /**
     * Startupinfoex structure.
     *
     * If this member variable is available, \c startup_info is a reference
     * to \c StartupInfo in STARTUPINFOEX.
     *
     * \remark <em>Windows Vista, Windows Server 2008 or better.</em>
     */
    STARTUPINFOEX startup_info_ex;

    /**
     * Process information.
     *
     * \c proc_info contains the result after a child process
     * could be started successfully.
     *
     * \remark <em>Windows only.</em>
     */
    PROCESS_INFORMATION proc_info;

    ///@}

    ///\defgroup POSIXOnly POSIX only.
    ///@{

    /**
     * Program name.
     *
     * \remark <em>POSIX only.</em>
     */
    const char *exe;

    /**
     * Command line arguments.
     *
     * \remark <em>POSIX only.</em>
     */
    char **cmd_line;

    /**
     * Environment variables.
     *
     * \remark <em>POSIX only.</em>
     */
    char **env;

    ///@}
};

}}
#endif

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/initializers.hpp
 *
 * Defines initializers.
 */

#ifndef BOOST_PROCESS_INITIALIZERS_HPP
#define BOOST_PROCESS_INITIALIZERS_HPP

#include <boost/process/config.hpp>

#include BOOST_PROCESS_PLATFORM_PROMOTE_PATH(initializers)
BOOST_PROCESS_PLATFORM_PROMOTE_INITIALIZERS_NAMESPACE

#if defined(BOOST_PROCESS_DOXYGEN)
namespace boost { namespace process { namespace initializers {

/**
 * Binds the standard error stream.
 */
class bind_stderr : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit bind_stderr(const boost::iostreams::file_descriptor_sink &sink);
};

/**
 * Binds the standard input stream.
 */
class bind_stdin : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit bind_stdin(const boost::iostreams::file_descriptor_source &source);
};

/**
 * Binds the standard output stream.
 */
class bind_stdout : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit bind_stdout(const boost::iostreams::file_descriptor_sink &sink);
};

/**
 * Binds a file descriptor.
 *
 * \remark <em>POSIX only.</em>
 */
class bind_fd : public initializer_base
{
public:
    /**
     * Constructor.
     */
    bind_fd(int id, const boost::iostreams::file_descriptor &fd);
};

/**
 * Closes a file descriptor.
 *
 * \remark <em>POSIX only.</em>
 */
class close_fd : public initializer_base
{
    /**
     * Constructor.
     */
    explicit close_fd(int fd);
};

/**
 * Closes file descriptors.
 *
 * \remark <em>POSIX only.</em>
 */
class close_fds : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c range_type must be an <tt>int</tt>-range.
     */
    explicit close_fds(const range_type &fds);
};

/**
 * Closes all file descriptors a predicate returns
 * true for.
 *
 * This initializer doesn't close file descriptors
 * immediately. Instead it sets the \c FD_CLOEXEC
 * flag. File descriptors are closed when \c execve
 * is called and the call succeeds.
 *
 * \remark <em>POSIX only.</em>
 */
class close_fds_if : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c predicate_type must be a function or functor with
     * this signature: <tt>bool(int)</tt>
     */
    explicit close_fds_if(const predicate_type &pred);
};

/**
 * Closes the standard error stream.
 */
class close_stderr : public initializer_base
{
    /**
     * Constructor.
     */
    close_stderr();
};

/**
 * Closes the standard input stream.
 */
class close_stdin : public initializer_base
{
    /**
     * Constructor.
     */
    close_stdin();
};

/**
 * Closes the standard output stream.
 */
class close_stdout : public initializer_base
{
    /**
     * Constructor.
     */
    close_stdout();
};

/**
 * Hides the console.
 */
class hide_console : public initializer_base
{
public:
    /**
     * Constructor.
     */
    hide_console();
};

/**
 * Inherits environment variables.
 */
class inherit_env : public initializer_base
{
public:
    /**
     * Constructor.
     */
    inherit_env();
};

/**
 * Notifies an I/O service object of fork-related events.
 *
 * \see boost::asio::io_service::notify_fork
 *
 * \remark <em>POSIX only.</em>
 */
class notify_io_service : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit notify_io_service(boost::asio::io_service &io_service);
};

/**
 * Generic initializer to execute any code if \c execve
 * failed.
 *
 * \remark <em>POSIX only.</em>
 */
class on_exec_error : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_exec_error(handler_type handler);
};

/**
 * Generic initializer to execute any code before \c execve
 * is called.
 *
 * \remark <em>POSIX only.</em>
 */
class on_exec_setup : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_exec_setup(handler_type handler);
};

/**
 * Generic initializer to execute any code if \c fork
 * failed.
 *
 * \remark <em>POSIX only.</em>
 */
class on_fork_error : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_fork_error(handler_type handler);
};

/**
 * Generic initializer to execute any code before \c fork
 * is called.
 *
 * \remark <em>POSIX only.</em>
 */
class on_fork_setup : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_fork_setup(handler_type handler);
};

/**
 * Generic initializer to execute any code in the parent
 * process after \c fork has been called successfully.
 *
 * \remark <em>POSIX only.</em>
 */
class on_fork_success : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_fork_success(handler_type handler);
};

/**
 * Generic initializer to execute any code if \c CreateProcess
 * failed.
 *
 * \remark <em>Windows only.</em>
 */
class on_CreateProcess_error : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_CreateProcess_error(handler_type handler);
};

/**
 * Generic initializer to execute any code before \c CreateProcess
 * is called.
 *
 * \remark <em>Windows only.</em>
 */
class on_CreateProcess_setup : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_CreateProcess_setup(handler_type handler);
};

/**
 * Generic initializer to execute any code after \c CreateProcess
 * has been called successfully.
 *
 * \remark <em>Windows only.</em>
 */
class on_CreateProcess_success : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * \c handler_type must be a function or functor with
     * this signature: <tt>void(executor&)</tt>
     */
    explicit on_CreateProcess_success(handler_type handler);
};

/**
 * Specifies the executable to start.
 *
 * This initializer must always be used. The only exception is
 * if you use \c set_args or a generic initializer which
 * specifies the executable.
 */
class run_exe : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * On Windows \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     * If Unicode is used, \c string_type must be
     * <tt>const wchar_t*</tt>, <tt>std::wstring</tt> or
     * <tt>boost::filesystem::path</tt>.
     *
     * On POSIX \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     */
    explicit run_exe(const string_type &s);
};

/**
 * Sets the command line arguments.
 *
 * The first argument specifies the executable to start unless
 * \c run_exe is used.
 *
 * Use \c set_cmd_line if you don't want to pass a collection of
 * command line arguments but set the command line as one string.
 */
class set_args : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * On Windows \c range_type must be a <tt>std::string</tt>-range.
     * If Unicode is used, \c range_type must be a
     * <tt>std::wstring</tt>-range.
     *
     * On POSIX \c range_type must be a <tt>std::string</tt>-range.
     */
    explicit set_args(const range_type &r);
};

/**
 * Sets the command line.
 *
 * Use \c set_args if you don't want to set the command line as
 * one string but pass a collection of command line arguments.
 */
class set_cmd_line : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * On Windows \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     * If Unicode is used, \c string_type must be
     * <tt>const wchar_t*</tt>, <tt>std::wstring</tt> or
     * <tt>boost::filesystem::path</tt>.
     *
     * On POSIX \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     */
    explicit set_cmd_line(const string_type &s);
};

/**
 * Sets the environment.
 */
class set_env : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * On Windows \c range_type must be a <tt>std::string</tt>-range.
     * If Unicode is used, \c range_type must be a
     * <tt>std::wstring</tt>-range.
     *
     * On POSIX \c range_type must be a <tt>std::string</tt>-range.
     */
    explicit set_env(const range_type &r);
};

/**
 * Sets an error if a child process can't be created.
 */
class set_on_error : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit set_on_error(boost::system::error_code &ec);
};

/**
 * Sets the flag \c wShowWindow in \c STARTUPINFO.
 *
 * \remark <em>Windows only.</em>
 */
class show_window : public initializer_base
{
public:
    /**
     * Constructor.
     */
    explicit show_window(WORD flags);
};

/**
 * Sets the work directory.
 */
class start_in_dir : public initializer_base
{
public:
    /**
     * Constructor.
     *
     * On Windows \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     * If Unicode is used, \c string_type must be
     * <tt>const wchar_t*</tt>, <tt>std::wstring</tt> or
     * <tt>boost::filesystem::path</tt>.
     *
     * On POSIX \c string_type must be <tt>const char*</tt>,
     * <tt>std::string</tt> or <tt>boost::filesystem::path</tt>.
     */
    explicit start_in_dir(const string_type &s);
};

/**
 * Throws an error if a child process can't be created.
 *
 * The type of the error thrown is \c boost::system::system_error.
 */
class throw_on_error : public initializer_base
{
public:
};

}}}
#endif

#endif

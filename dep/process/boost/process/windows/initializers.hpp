// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_HPP

#include <boost/process/windows/initializers/bind_stderr.hpp>
#include <boost/process/windows/initializers/bind_stdin.hpp>
#include <boost/process/windows/initializers/bind_stdout.hpp>
#include <boost/process/windows/initializers/close_stderr.hpp>
#include <boost/process/windows/initializers/close_stdin.hpp>
#include <boost/process/windows/initializers/close_stdout.hpp>
#include <boost/process/windows/initializers/hide_console.hpp>
#include <boost/process/windows/initializers/inherit_env.hpp>
#include <boost/process/windows/initializers/on_CreateProcess_error.hpp>
#include <boost/process/windows/initializers/on_CreateProcess_setup.hpp>
#include <boost/process/windows/initializers/on_CreateProcess_success.hpp>
#include <boost/process/windows/initializers/run_exe.hpp>
#include <boost/process/windows/initializers/set_args.hpp>
#include <boost/process/windows/initializers/set_cmd_line.hpp>
#include <boost/process/windows/initializers/set_env.hpp>
#include <boost/process/windows/initializers/set_on_error.hpp>
#include <boost/process/windows/initializers/show_window.hpp>
#include <boost/process/windows/initializers/start_in_dir.hpp>
#include <boost/process/windows/initializers/throw_on_error.hpp>

#endif

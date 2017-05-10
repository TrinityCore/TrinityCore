// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_EXECUTOR_HPP
#define BOOST_PROCESS_WINDOWS_EXECUTOR_HPP

#include <boost/process/windows/child.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows {

struct executor
{
    executor() : exe(0), cmd_line(0), proc_attrs(0), thread_attrs(0),
        inherit_handles(FALSE),
#if (_WIN32_WINNT >= 0x0600)
        creation_flags(EXTENDED_STARTUPINFO_PRESENT),
#else
        creation_flags(0),
#endif
        env(0), work_dir(0)
#if (_WIN32_WINNT >= 0x0600)
        ,startup_info(startup_info_ex.StartupInfo)
#endif
    {
#if (_WIN32_WINNT >= 0x0600)
        ZeroMemory(&startup_info_ex, sizeof(STARTUPINFOEX));
        startup_info.cb = sizeof(STARTUPINFOEX);
#else
        ZeroMemory(&startup_info, sizeof(STARTUPINFO));
        startup_info.cb = sizeof(STARTUPINFO);
#endif
        startup_info.hStdInput = INVALID_HANDLE_VALUE;
        startup_info.hStdOutput = INVALID_HANDLE_VALUE;
        startup_info.hStdError = INVALID_HANDLE_VALUE;
    }

    struct call_on_CreateProcess_setup
    {
        executor &e_;

        call_on_CreateProcess_setup(executor &e) : e_(e) {}

        template <class Arg>
        void operator()(Arg &arg) const
        {
            arg.on_CreateProcess_setup(e_);
        }
    };

    struct call_on_CreateProcess_error
    {
        executor &e_;

        call_on_CreateProcess_error(executor &e) : e_(e) {}

        template <class Arg>
        void operator()(Arg &arg) const
        {
            arg.on_CreateProcess_error(e_);
        }
    };

    struct call_on_CreateProcess_success
    {
        executor &e_;

        call_on_CreateProcess_success(executor &e) : e_(e) {}

        template <class Arg>
        void operator()(Arg &arg) const
        {
            arg.on_CreateProcess_success(e_);
        }
    };

    template <class InitializerSequence>
    child operator()(const InitializerSequence &seq)
    {
        boost::fusion::for_each(seq, call_on_CreateProcess_setup(*this));

        if (!::CreateProcess(
            exe,
            cmd_line,
            proc_attrs,
            thread_attrs,
            inherit_handles,
            creation_flags,
            env,
            work_dir,
            &startup_info,
            &proc_info))
        {
            boost::fusion::for_each(seq, call_on_CreateProcess_error(*this));
        }
        else
        {
            boost::fusion::for_each(seq, call_on_CreateProcess_success(*this));
        }

        return child(proc_info);
    }

    LPCTSTR exe;
    LPTSTR cmd_line;
    LPSECURITY_ATTRIBUTES proc_attrs;
    LPSECURITY_ATTRIBUTES thread_attrs;
    BOOL inherit_handles;
    DWORD creation_flags;
    LPVOID env;
    LPCTSTR work_dir;
#if (_WIN32_WINNT >= 0x0600)
    STARTUPINFOEX startup_info_ex;
    STARTUPINFO &startup_info;
#else
    STARTUPINFO startup_info;
#endif
    PROCESS_INFORMATION proc_info;
};

}}}

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_CHILD_HPP
#define BOOST_PROCESS_WINDOWS_CHILD_HPP

#include <boost/move/move.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows {

class child
{
public:
    PROCESS_INFORMATION proc_info;

    explicit child(const PROCESS_INFORMATION &pi) : proc_info(pi) {}

    ~child()
    {
        ::CloseHandle(proc_info.hProcess);
        ::CloseHandle(proc_info.hThread);
    }

    child(BOOST_RV_REF(child) c) : proc_info(c.proc_info)
    {
        c.proc_info.hProcess = INVALID_HANDLE_VALUE;
        c.proc_info.hThread = INVALID_HANDLE_VALUE;
    }

    child &operator=(BOOST_RV_REF(child) c)
    {
        ::CloseHandle(proc_info.hProcess);
        ::CloseHandle(proc_info.hThread);
        proc_info = c.proc_info;
        c.proc_info.hProcess = INVALID_HANDLE_VALUE;
        c.proc_info.hThread = INVALID_HANDLE_VALUE;
        return *this;
    }

    HANDLE process_handle() const { return proc_info.hProcess; }

private:
    BOOST_MOVABLE_BUT_NOT_COPYABLE(child);
};

}}}

#endif

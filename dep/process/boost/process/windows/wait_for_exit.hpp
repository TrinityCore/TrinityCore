// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_WAIT_FOR_EXIT_HPP
#define BOOST_PROCESS_WINDOWS_WAIT_FOR_EXIT_HPP

#include <boost/process/config.hpp>
#include <boost/system/error_code.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows {

template <class Process>
inline DWORD wait_for_exit(const Process &p)
{
    if (::WaitForSingleObject(p.process_handle(), INFINITE) == WAIT_FAILED)
        BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("WaitForSingleObject() failed");

    DWORD exit_code;
    if (!::GetExitCodeProcess(p.process_handle(), &exit_code))
        BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("GetExitCodeProcess() failed");

    return exit_code;
}

template <class Process>
inline DWORD wait_for_exit(const Process &p, boost::system::error_code &ec)
{
    DWORD exit_code = 1;

    if (::WaitForSingleObject(p.process_handle(), INFINITE) == WAIT_FAILED)
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec);
    else if (!::GetExitCodeProcess(p.process_handle(), &exit_code))
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec);
    else
        ec.clear();

    return exit_code;
}

}}}

#endif

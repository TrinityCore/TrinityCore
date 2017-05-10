// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_CREATE_PIPE_HPP
#define BOOST_PROCESS_WINDOWS_CREATE_PIPE_HPP

#include <boost/process/config.hpp>
#include <boost/process/windows/pipe.hpp>
#include <boost/system/error_code.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows {

inline pipe create_pipe()
{
    HANDLE handles[2];
    if (!::CreatePipe(&handles[0], &handles[1], NULL, 0))
        BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("CreatePipe() failed");
    return make_pipe(handles[0], handles[1]);
}

inline pipe create_pipe(boost::system::error_code &ec)
{
    HANDLE handles[2];
    if (!::CreatePipe(&handles[0], &handles[1], NULL, 0))
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec);
    else
        ec.clear();
    return make_pipe(handles[0], handles[1]);
}

}}}

#endif

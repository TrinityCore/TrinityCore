// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_CREATE_PIPE_HPP
#define BOOST_PROCESS_POSIX_CREATE_PIPE_HPP

#include <boost/process/config.hpp>
#include <boost/process/posix/pipe.hpp>
#include <boost/system/error_code.hpp>
#include <unistd.h>

namespace boost { namespace process { namespace posix {

inline pipe create_pipe()
{
    int fds[2];
    if (::pipe(fds) == -1)
        BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("pipe(2) failed");
    return pipe(fds[0], fds[1]);
}

inline pipe create_pipe(boost::system::error_code &ec)
{
    int fds[2];
    if (::pipe(fds) == -1)
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec);
    else
        ec.clear();
    return pipe(fds[0], fds[1]);
}

}}}

#endif

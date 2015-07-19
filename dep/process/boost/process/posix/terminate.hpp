// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_TERMINATE_HPP
#define BOOST_PROCESS_POSIX_TERMINATE_HPP

#include <boost/process/config.hpp>
#include <boost/system/error_code.hpp>
#include <signal.h>

namespace boost { namespace process { namespace posix {

template <class Process>
void terminate(const Process &p)
{
    if (::kill(p.pid, SIGKILL) == -1)
        BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("kill(2) failed");
}

template <class Process>
void terminate(const Process &p, boost::system::error_code &ec)
{
    if (::kill(p.pid, SIGKILL) == -1)
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec);
    else
        ec.clear();
}

}}}

#endif

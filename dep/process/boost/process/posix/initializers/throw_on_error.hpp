// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_THROW_ON_ERROR_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_THROW_ON_ERROR_HPP

#include <boost/process/config.hpp>
#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

namespace boost { namespace process { namespace posix { namespace initializers {

class throw_on_error : public initializer_base
{
public:
    template <class PosixExecutor>
    void on_fork_setup(PosixExecutor&) const
    {
        if (::pipe(fds_) == -1)
            BOOST_PROCESS_THROW_LAST_SYSTEM_ERROR("pipe(2) failed");
        if (::fcntl(fds_[1], F_SETFD, FD_CLOEXEC) == -1)
        {
            int e = errno;
            ::close(fds_[0]);
            ::close(fds_[1]);
            BOOST_PROCESS_THROW(boost::system::system_error(
                boost::system::error_code(e, boost::system::system_category()),
                BOOST_PROCESS_SOURCE_LOCATION "fcntl(2) failed"));
        }
    }

    template <class PosixExecutor>
    void on_fork_error(PosixExecutor&) const
    {
        int e = errno;
        ::close(fds_[0]);
        ::close(fds_[1]);
        BOOST_PROCESS_THROW(boost::system::system_error(
            boost::system::error_code(e, boost::system::system_category()),
            BOOST_PROCESS_SOURCE_LOCATION "fork(2) failed"));
    }

    template <class PosixExecutor>
    void on_fork_success(PosixExecutor&) const
    {
        ::close(fds_[1]);
        int code;
        if (::read(fds_[0], &code, sizeof(int)) > 0)
        {
            ::close(fds_[0]);
            BOOST_PROCESS_THROW(boost::system::system_error(
                boost::system::error_code(code,
                boost::system::system_category()),
                BOOST_PROCESS_SOURCE_LOCATION "execve(2) failed"));
        }
        ::close(fds_[0]);
    }

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        ::close(fds_[0]);
    }

    template <class PosixExecutor>
    void on_exec_error(PosixExecutor&) const
    {
        int e = errno;
        while (::write(fds_[1], &e, sizeof(int)) == -1 && errno == EINTR)
            ;
        ::close(fds_[1]);
    }

private:
    mutable int fds_[2];
};

}}}}

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_SET_ON_ERROR_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_SET_ON_ERROR_HPP

#include <boost/process/config.hpp>
#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/system/error_code.hpp>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

namespace boost { namespace process { namespace posix { namespace initializers {

class set_on_error : public initializer_base
{
public:
    explicit set_on_error(boost::system::error_code &ec) : ec_(ec) {}

    template <class PosixExecutor>
    void on_fork_setup(PosixExecutor&) const
    {
        if (::pipe(fds_) == -1)
            BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec_);
        if (::fcntl(fds_[1], F_SETFD, FD_CLOEXEC) == -1)
        {
            BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec_);
            ::close(fds_[0]);
            ::close(fds_[1]);
        }
    }

    template <class PosixExecutor>
    void on_fork_error(PosixExecutor&) const
    {
        if (!ec_)
        {
            BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec_);
            ::close(fds_[0]);
            ::close(fds_[1]);
        }
    }

    template <class PosixExecutor>
    void on_fork_success(PosixExecutor&) const
    {
        if (!ec_)
        {
            ::close(fds_[1]);
            int code;
            if (::read(fds_[0], &code, sizeof(int)) > 0)
            {
                ec_ = boost::system::error_code(code,
                    boost::system::system_category());
            }
            ::close(fds_[0]);
        }
    }

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        if (!ec_)
        {
            ::close(fds_[0]);
        }
    }

    template <class PosixExecutor>
    void on_exec_error(PosixExecutor&) const
    {
        if (!ec_)
        {
            int e = errno;
            while (::write(fds_[1], &e, sizeof(int)) == -1 && errno == EINTR)
                ;
            ::close(fds_[1]);
        }
    }

private:
    boost::system::error_code &ec_;
    mutable int fds_[2];
};

}}}}

#endif

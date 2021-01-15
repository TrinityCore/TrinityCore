// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_CLOSE_FDS_IF_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_CLOSE_FDS_IF_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/range/counting_range.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#ifndef BOOST_PROCESS_POSIX_MAX_FD
#   define BOOST_PROCESS_POSIX_MAX_FD 32
#endif

namespace boost { namespace process { namespace posix { namespace initializers {

template <class Predicate>
class close_fds_if_ : public initializer_base
{
private:
    static void close(int fd)
    {
        ::fcntl(fd, F_SETFD, FD_CLOEXEC);
    }

public:
    explicit close_fds_if_(const Predicate &pred) : pred_(pred) {}

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        boost::for_each(
            boost::adaptors::filter(
                boost::counting_range(0, upper_bound()),
                pred_
            ),
            close
        );
    }

private:
    static int upper_bound()
    {
        int up;
#if defined(F_MAXFD)
        do
        {
            up = ::fcntl(0, F_MAXFD);
        } while (up == -1 && errno == EINTR);
        if (up == -1)
#endif
            up = ::sysconf(_SC_OPEN_MAX);
        if (up == -1)
            up = BOOST_PROCESS_POSIX_MAX_FD;
        return up;
    }

    Predicate pred_;
};

template <class Predicate>
close_fds_if_<Predicate> close_fds_if(const Predicate &pred)
{
    return close_fds_if_<Predicate>(pred);
}

}}}}

#endif

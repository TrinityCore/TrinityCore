// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_CLOSE_FDS_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_CLOSE_FDS_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <unistd.h>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class Range>
class close_fds_ : public initializer_base
{
public:
    explicit close_fds_(const Range &fds) : fds_(fds) {}

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        boost::for_each(fds_, ::close);
    }

private:
    Range fds_;
};

template <class Range>
close_fds_<Range> close_fds(const Range &fds)
{
    return close_fds_<Range>(fds);
}

}}}}

#endif

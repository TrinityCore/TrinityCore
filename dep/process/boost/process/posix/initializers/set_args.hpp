// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_SET_ARGS_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_SET_ARGS_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/shared_array.hpp>
#include <string>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class Range>
class set_args_ : public initializer_base
{
private:
    static char *c_str(const std::string &s)
    {
        return const_cast<char*>(s.c_str());
    }

public:
    explicit set_args_(const Range &args)
    {
        args_.reset(new char*[args.size() + 1]);
        boost::transform(args, args_.get(), c_str);
        args_[args.size()] = 0;
    }

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor &e) const
    {
        e.cmd_line = args_.get();
        if (!e.exe && *args_[0])
            e.exe = args_[0];
    }

private:
    boost::shared_array<char*> args_;
};

template <class Range>
set_args_<Range> set_args(const Range &range)
{
    return set_args_<Range>(range);
}

}}}}

#endif

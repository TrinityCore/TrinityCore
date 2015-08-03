// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_SET_ENV_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_SET_ENV_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/shared_array.hpp>
#include <string>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class Range>
class set_env_ : public initializer_base
{
private:
    static char *get_ptr(const std::string &s)
    {
        return const_cast<char*>(s.c_str());
    }

public:
    explicit set_env_(const Range &envs) : env_(new char*[envs.size() + 1])
    {
        boost::transform(envs, env_.get(), get_ptr);
        env_[envs.size()] = 0;
    }

    template <class PosixExecutor>
    void on_fork_setup(PosixExecutor &e) const
    {
        e.env = env_.get();
    }

private:
    boost::shared_array<char*> env_;
};

template <class Range>
set_env_<Range> set_env(const Range &envs)
{
    return set_env_<Range>(envs);
}

}}}}

#endif

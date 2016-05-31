// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_ENV_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_ENV_HPP

#include <Windows.h>
#include <boost/process/windows/initializers/initializer_base.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <boost/shared_array.hpp>
#include <iterator>
#include <cstddef>

namespace boost { namespace process { namespace windows { namespace initializers {

template <class Range, bool Unicode>
class set_env_ : public initializer_base
{
private:
    typedef typename Range::value_type String;
    typedef typename String::value_type Char;

    static std::size_t add_size(std::size_t size, const String &s)
    {
        return size + s.size() + 1u;
    }

    struct copy
    {
        Char *it_;

        copy(Char *it) : it_(it) {}

        void operator()(const String &s)
        {
            it_ = boost::copy(s, it_);
            *it_ = 0;
            ++it_;
        }
    };

public:
    set_env_(const Range &envs)
        : size_(boost::accumulate(envs, 0, add_size) + 1),
        env_(new Char[size_])
    {
        boost::for_each(envs, copy(env_.get()));
        env_[size_ - 1] = 0;
    }

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        e.env = env_.get();
        if (Unicode)
            e.creation_flags |= CREATE_UNICODE_ENVIRONMENT;
    }

private:
    std::size_t size_;
    boost::shared_array<Char> env_;
};

#if defined(_UNICODE) || defined(UNICODE)
template <class Range>
set_env_<Range, true> set_env(const Range &envs)
{
    return set_env_<Range, true>(envs);
}
#else
template <class Range>
set_env_<Range, false> set_env(const Range &envs)
{
    return set_env_<Range, false>(envs);
}
#endif

}}}}

#endif

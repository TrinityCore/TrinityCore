// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_ON_CREATEPROCESS_SETUP_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_ON_CREATEPROCESS_SETUP_HPP

#include <boost/process/config.hpp>
#include <boost/process/windows/initializers/initializer_base.hpp>

namespace boost { namespace process { namespace windows { namespace initializers {

template <class Handler>
class on_CreateProcess_setup_ : public initializer_base
{
public:
    explicit on_CreateProcess_setup_(Handler handler) : handler_(handler) {}

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        handler_(e);
    }

private:
    Handler handler_;
};

template <class Handler>
on_CreateProcess_setup_<Handler> on_CreateProcess_setup(Handler handler)
{
    return on_CreateProcess_setup_<Handler>(handler);
}

}}}}

#endif

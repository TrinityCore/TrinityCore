// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_SHOW_WINDOW_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_SHOW_WINDOW_HPP

#include <boost/process/windows/initializers/initializer_base.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows { namespace initializers {

class show_window : public initializer_base
{
public:
    explicit show_window(WORD flags) : flags_(flags) {}

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        e.startup_info.dwFlags |= STARTF_USESHOWWINDOW;
        e.startup_info.wShowWindow |= flags_;
    }

private:
    WORD flags_;
};

}}}}

#endif

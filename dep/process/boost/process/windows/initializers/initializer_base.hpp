// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_INITIALIZER_BASE_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_INITIALIZER_BASE_HPP

namespace boost { namespace process { namespace windows { namespace initializers {

struct initializer_base
{
    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor&) const {}

    template <class WindowsExecutor>
    void on_CreateProcess_error(WindowsExecutor&) const {}

    template <class WindowsExecutor>
    void on_CreateProcess_success(WindowsExecutor&) const {}
};

}}}}

#endif

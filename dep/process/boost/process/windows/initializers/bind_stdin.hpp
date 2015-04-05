// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_BIND_STDIN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_BIND_STDIN_HPP

#include <boost/process/windows/initializers/initializer_base.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <Windows.h>

namespace boost { namespace process { namespace windows { namespace initializers {

class bind_stdin : public initializer_base
{
public:
    explicit bind_stdin(const boost::iostreams::file_descriptor_source &source) : source_(source) {}

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        ::SetHandleInformation(source_.handle(), HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
        e.startup_info.hStdInput = source_.handle();
        e.startup_info.dwFlags |= STARTF_USESTDHANDLES;
        e.inherit_handles = true;
    }

private:
    boost::iostreams::file_descriptor_source source_;
};

}}}}

#endif

// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_ON_ERROR_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_ON_ERROR_HPP

#include <boost/process/config.hpp>
#include <boost/process/windows/initializers/initializer_base.hpp>
#include <boost/system/error_code.hpp>

namespace boost { namespace process { namespace windows { namespace initializers {

class set_on_error : public initializer_base
{
public:
    explicit set_on_error(boost::system::error_code &ec) : ec_(ec) {}

    template <class WindowsExecutor>
    void on_CreateProcess_error(WindowsExecutor&) const
    {
        BOOST_PROCESS_RETURN_LAST_SYSTEM_ERROR(ec_);
    }

private:
    boost::system::error_code &ec_;
};

}}}}

#endif

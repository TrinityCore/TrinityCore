// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_BIND_STDERR_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_BIND_STDERR_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <unistd.h>

namespace boost { namespace process { namespace posix { namespace initializers {

class bind_stderr : public initializer_base
{
public:
    explicit bind_stderr(const boost::iostreams::file_descriptor_sink &sink)
        : sink_(sink) {}

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        ::dup2(sink_.handle(), STDERR_FILENO);
    }

private:
    boost::iostreams::file_descriptor_sink sink_;
};

}}}}

#endif

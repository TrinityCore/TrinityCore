// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_NOTIFY_IO_SERVICE_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_NOTIFY_IO_SERVICE_HPP

#include <boost/process/config.hpp>
#include <boost/process/posix/initializers/initializer_base.hpp>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class IOService>
class notify_io_service_ : public initializer_base
{
public:
    explicit notify_io_service_(IOService &io_service) :
        io_service_(io_service) {}

    template <class PosixExecutor>
    void on_fork_setup(PosixExecutor&) const
    {
        io_service_.notify_fork(IOService::fork_prepare);
    }

    template <class PosixExecutor>
    void on_fork_success(PosixExecutor&) const
    {
        io_service_.notify_fork(IOService::fork_parent);
    }

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        io_service_.notify_fork(IOService::fork_child);
    }

private:
    IOService &io_service_;
};

template <class IOService>
notify_io_service_<IOService> notify_io_service(IOService &io_service)
{
    return notify_io_service_<IOService>(io_service);
}

}}}}

#endif

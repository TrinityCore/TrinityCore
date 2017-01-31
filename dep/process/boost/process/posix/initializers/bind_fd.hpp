// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_BIND_FD_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_BIND_FD_HPP

#include <boost/process/posix/initializers/initializer_base.hpp>
#include <unistd.h>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class FileDescriptor>
class bind_fd_ : public initializer_base
{
public:
    bind_fd_(int id, const FileDescriptor &fd) : id_(id), fd_(fd) {}

    template <class PosixExecutor>
    void on_exec_setup(PosixExecutor&) const
    {
        ::dup2(fd_.handle(), id_);
    }

private:
    int id_;
    FileDescriptor fd_;
};

template <class FileDescriptor>
bind_fd_<FileDescriptor> bind_fd(int id, const FileDescriptor &fd)
{
    return bind_fd_<FileDescriptor>(id, fd);
}

}}}}

#endif

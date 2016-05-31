// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_CHILD_HPP
#define BOOST_PROCESS_POSIX_CHILD_HPP

#include <sys/types.h>

namespace boost { namespace process { namespace posix {

struct child
{
    pid_t pid;

    explicit child(pid_t p) : pid(p) {}
};

}}}

#endif

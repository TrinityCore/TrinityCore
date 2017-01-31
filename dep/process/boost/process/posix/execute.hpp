// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_POSIX_EXECUTE_HPP
#define BOOST_PROCESS_POSIX_EXECUTE_HPP

#include <boost/process/posix/executor.hpp>
#include <boost/process/posix/child.hpp>
#include <boost/fusion/tuple/make_tuple.hpp>
#include <boost/ref.hpp>

namespace boost { namespace process { namespace posix {

template <class I0>
child execute(const I0 &i0)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0)));
}

template <class I0, class I1>
child execute(const I0 &i0, const I1 &i1)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1)));
}

template <class I0, class I1, class I2>
child execute(const I0 &i0, const I1 &i1, const I2 &i2)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2)));
}

template <class I0, class I1, class I2, class I3>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3)));
}

template <class I0, class I1, class I2, class I3, class I4>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4)));
}

template <class I0, class I1, class I2, class I3, class I4, class I5>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4, const I5 &i5)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4), boost::cref(i5)));
}

template <class I0, class I1, class I2, class I3, class I4, class I5, class I6>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4, const I5 &i5, const I6 &i6)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4), boost::cref(i5), boost::cref(i6)));
}

template <class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4, const I5 &i5, const I6 &i6, const I7 &i7)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4), boost::cref(i5), boost::cref(i6), boost::cref(i7)));
}

template <class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7, class I8>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4, const I5 &i5, const I6 &i6, const I7 &i7, const I8 &i8)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4), boost::cref(i5), boost::cref(i6), boost::cref(i7), boost::cref(i8)));
}

template <class I0, class I1, class I2, class I3, class I4, class I5, class I6, class I7, class I8, class I9>
child execute(const I0 &i0, const I1 &i1, const I2 &i2, const I3 &i3, const I4 &i4, const I5 &i5, const I6 &i6, const I7 &i7, const I8 &i8, const I9 &i9)
{
    return executor()(boost::fusion::make_tuple(boost::cref(i0), boost::cref(i1), boost::cref(i2), boost::cref(i3), boost::cref(i4), boost::cref(i5), boost::cref(i6), boost::cref(i7), boost::cref(i8), boost::cref(i9)));
}

}}}

#endif

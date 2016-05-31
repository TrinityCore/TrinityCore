// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_CMD_LINE_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_SET_CMD_LINE_HPP

#include <boost/process/windows/initializers/initializer_base.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/shared_array.hpp>
#include <memory>

namespace boost { namespace process { namespace windows { namespace initializers {

template <class String>
class set_cmd_line_ : public initializer_base
{
private:
    typedef typename String::value_type Char;

public:
    explicit set_cmd_line_(const String &s)
        : cmd_line_(new Char[s.size() + 1])
    {
        boost::copy(s, cmd_line_.get());
        cmd_line_[s.size()] = 0;
    }

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        e.cmd_line = cmd_line_.get();
    }

private:
    boost::shared_array<Char> cmd_line_;
};

#if defined(_UNICODE) || defined(UNICODE)
inline set_cmd_line_<std::wstring> set_cmd_line(const wchar_t *ws)
{
    return set_cmd_line_<std::wstring>(ws);
}

inline set_cmd_line_<std::wstring> set_cmd_line(const std::wstring &ws)
{
    return set_cmd_line_<std::wstring>(ws);
}
#else
inline set_cmd_line_<std::string> set_cmd_line(const char *s)
{
    return set_cmd_line_<std::string>(s);
}

inline set_cmd_line_<std::string> set_cmd_line(const std::string &s)
{
    return set_cmd_line_<std::string>(s);
}
#endif

}}}}

#endif

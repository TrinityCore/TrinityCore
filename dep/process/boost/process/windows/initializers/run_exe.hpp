// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_RUN_EXE_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_RUN_EXE_HPP

#include <boost/process/windows/initializers/initializer_base.hpp>
#include <boost/filesystem.hpp>
#include <string>

namespace boost { namespace process { namespace windows { namespace initializers {

template <class String>
class run_exe_ : public initializer_base
{
public:
    explicit run_exe_(const String &s) : s_(s) {}

    template <class WindowsExecutor>
    void on_CreateProcess_setup(WindowsExecutor &e) const
    {
        e.exe = s_.c_str();
    }

private:
    String s_;
};

#if defined(_UNICODE) || defined(UNICODE)
inline run_exe_<std::wstring> run_exe(const wchar_t *ws)
{
    return run_exe_<std::wstring>(ws);
}

inline run_exe_<std::wstring> run_exe(const std::wstring &ws)
{
    return run_exe_<std::wstring>(ws);
}

inline run_exe_<std::wstring> run_exe(const boost::filesystem::path &p)
{
    return run_exe_<std::wstring>(p.wstring());
}
#else
inline run_exe_<std::string> run_exe(const char *s)
{
    return run_exe_<std::string>(s);
}

inline run_exe_<std::string> run_exe(const std::string &s)
{
    return run_exe_<std::string>(s);
}

inline run_exe_<std::string> run_exe(const boost::filesystem::path &p)
{
    return run_exe_<std::string>(p.string());
}
#endif

}}}}

#endif

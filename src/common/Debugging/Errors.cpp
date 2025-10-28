/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Errors.h"
#include "StringFormat.h"
#include <thread>
#include <cstdarg>
#include <cstdio>
#include <cstring>

/**
    @file Errors.cpp

    @brief This file contains definitions of functions used for reporting critical application errors

    It is very important that (std::)abort is NEVER called in place of *((volatile int*)nullptr) = 0;
    Calling abort() on Windows does not invoke unhandled exception filters - a mechanism used by WheatyExceptionReport
    to log crashes. exit(1) calls here are for static analysis tools to indicate that calling functions defined in this file
    terminates the application.
 */

#if TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT
#define Unreachable() (__assume(false))
#else
#define Unreachable() (__builtin_unreachable())
#endif

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include <Windows.h>
#include <intrin.h>
#define Crash(message) \
    ULONG_PTR execeptionArgs[] = { reinterpret_cast<ULONG_PTR>(strdup(message)), reinterpret_cast<ULONG_PTR>(_ReturnAddress()) }; \
    RaiseException(EXCEPTION_ASSERTION_FAILURE, 0, 2, execeptionArgs); \
    Unreachable()
#else
// should be easily accessible in gdb
extern "C" { TC_COMMON_API char const* TrinityAssertionFailedMessage = nullptr; }
#define Crash(message) \
    TrinityAssertionFailedMessage = strdup(message); \
    *((volatile int*)nullptr) = 0; \
    Unreachable()
#endif

namespace
{
    void FormatAssertionMessageTo(std::string& formatted, char const* format, va_list args) noexcept
    {
        va_list len;

        va_copy(len, args);
        int32 length = vsnprintf(nullptr, 0, format, len);
        va_end(len);

        std::size_t offset = formatted.length();
        formatted.resize(offset + length);
        vsnprintf(&formatted[offset], length + 1, format, args);
    }
}

namespace Trinity
{
void Assert(char const* file, int line, char const* function, char const* message, std::string debugInfo) noexcept
{
    std::string formattedMessage = StringFormat("\n{}:{} in {} ASSERTION FAILED:\n  {}\n{}\n", file, line, function, message, debugInfo);
    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);
    Crash(formattedMessage.c_str());
}

void Assert(char const* file, int line, char const* function, char const* message, std::string debugInfo, char const* format, ...) noexcept
{
    va_list args;
    va_start(args, format);

    std::string formattedMessage = StringFormat("\n{}:{} in {} ASSERTION FAILED:\n  {}\n", file, line, function, message);
    FormatAssertionMessageTo(formattedMessage, format, args);
    va_end(args);

    formattedMessage.append(1, '\n');
    formattedMessage.append(debugInfo);
    formattedMessage.append(1, '\n');

    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);

    Crash(formattedMessage.c_str());
}

void Fatal(char const* file, int line, char const* function, char const* message, ...) noexcept
{
    va_list args;
    va_start(args, message);

    std::string formattedMessage = StringFormat("\n{}:{} in {} FATAL ERROR:\n", file, line, function);
    FormatAssertionMessageTo(formattedMessage, message, args);
    va_end(args);

    formattedMessage.append(1, '\n');

    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);

    std::this_thread::sleep_for(std::chrono::seconds(10));
    Crash(formattedMessage.c_str());
}

void Error(char const* file, int line, char const* function, char const* message) noexcept
{
    std::string formattedMessage = StringFormat("\n{}:{} in {} ERROR:\n  {}\n", file, line, function, message);
    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);
    Crash(formattedMessage.c_str());
}

void Warning(char const* file, int line, char const* function, char const* message) noexcept
{
    fprintf(stderr, "\n%s:%i in %s WARNING:\n  %s\n",
                   file, line, function, message);
}

void Abort(char const* file, int line, char const* function) noexcept
{
    std::string formattedMessage = StringFormat("\n{}:{} in {} ABORTED.\n", file, line, function);
    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);
    Crash(formattedMessage.c_str());
}

void Abort(char const* file, int line, char const* function, char const* message, ...) noexcept
{
    va_list args;
    va_start(args, message);

    std::string formattedMessage = StringFormat("\n{}:{} in {} ABORTED:\n", file, line, function);
    FormatAssertionMessageTo(formattedMessage, message, args);
    va_end(args);

    formattedMessage.append(1, '\n');

    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);

    Crash(formattedMessage.c_str());
}

void AbortHandler(int sigval) noexcept
{
    // nothing useful to log here, no way to pass args
    std::string formattedMessage = StringFormat("Caught signal {}\n", sigval);
    fprintf(stderr, "%s", formattedMessage.c_str());
    fflush(stderr);
    Crash(formattedMessage.c_str());
}
} // namespace Trinity

std::string GetDebugInfo()
{
    return "";
}

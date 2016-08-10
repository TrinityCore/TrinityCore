/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "StartProcess.h"

#include <atomic>
#include <thread>
#include <functional>

#include <boost/algorithm/string/join.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/concepts.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/process.hpp>
#include <boost/system/system_error.hpp>

#include "Common.h"
#include "Log.h"

using namespace boost::process;
using namespace boost::process::initializers;
using namespace boost::iostreams;

namespace Trinity {

template<typename T>
class TCLogSink
{
    T callback_;

public:
    typedef char      char_type;
    typedef sink_tag  category;

    // Requires a callback type which has a void(std::string) signature
    TCLogSink(T callback)
        : callback_(std::move(callback)) { }

    std::streamsize write(const char* str, std::streamsize size)
    {
        callback_(std::string(str, size));
        return size;
    }
};

template<typename T>
auto MakeTCLogSink(T&& callback)
    -> TCLogSink<typename std::decay<T>::type>
{
    return { std::forward<T>(callback) };
}

template<typename T>
static int CreateChildProcess(T waiter, std::string const& executable,
                              std::vector<std::string> const& args,
                              std::string const& logger, std::string const& input,
                              bool secure)
{
    auto outPipe = create_pipe();
    auto errPipe = create_pipe();

    Optional<file_descriptor_source> inputSource;

    if (!secure)
    {
        TC_LOG_TRACE(logger, "Starting process \"%s\" with arguments: \"%s\".",
                executable.c_str(), boost::algorithm::join(args, " ").c_str());
    }

    // Start the child process
    child c = [&]
    {
        if (!input.empty())
        {
            inputSource = file_descriptor_source(input);

            // With binding stdin
            return execute(run_exe(boost::filesystem::absolute(executable)),
                set_args(args),
                inherit_env(),
                bind_stdin(*inputSource),
                bind_stdout(file_descriptor_sink(outPipe.sink, close_handle)),
                bind_stderr(file_descriptor_sink(errPipe.sink, close_handle)));
        }
        else
        {
            // Without binding stdin
            return execute(run_exe(boost::filesystem::absolute(executable)),
                set_args(args),
                inherit_env(),
                bind_stdout(file_descriptor_sink(outPipe.sink, close_handle)),
                bind_stderr(file_descriptor_sink(errPipe.sink, close_handle)));
        }
    }();

    file_descriptor_source outFd(outPipe.source, close_handle);
    file_descriptor_source errFd(errPipe.source, close_handle);

    auto outInfo = MakeTCLogSink([&](std::string msg)
    {
        TC_LOG_INFO(logger, "%s", msg.c_str());
    });

    auto outError = MakeTCLogSink([&](std::string msg)
    {
        TC_LOG_ERROR(logger, "%s", msg.c_str());
    });

    copy(outFd, outInfo);
    copy(errFd, outError);

    // Call the waiter in the current scope to prevent
    // the streams from closing too early on leaving the scope.
    int const result = waiter(c);

    if (!secure)
    {
        TC_LOG_TRACE(logger, ">> Process \"%s\" finished with return value %i.",
                executable.c_str(), result);
    }

    if (inputSource)
        inputSource->close();

    return result;
}

int StartProcess(std::string const& executable, std::vector<std::string> const& args,
                 std::string const& logger, std::string input_file, bool secure)
{
    return CreateChildProcess([](child& c) -> int
    {
        try
        {
            return wait_for_exit(c);
        }
        catch (...)
        {
            return EXIT_FAILURE;
        }
    }, executable, args, logger, input_file, secure);
}

class AsyncProcessResultImplementation
    : public AsyncProcessResult
{
    std::string const executable;
    std::vector<std::string> const args;
    std::string const logger;
    std::string const input_file;
    bool const is_secure;

    std::atomic<bool> was_terminated;

    // Workaround for missing move support in boost < 1.57
    Optional<std::shared_ptr<std::future<int>>> result;
    Optional<std::reference_wrapper<child>> my_child;

public:
    explicit AsyncProcessResultImplementation(std::string executable_, std::vector<std::string> args_,
                                     std::string logger_, std::string input_file_,
                                     bool secure)
        : executable(std::move(executable_)), args(std::move(args_)),
          logger(std::move(logger_)), input_file(input_file_),
          is_secure(secure), was_terminated(false) { }

    AsyncProcessResultImplementation(AsyncProcessResultImplementation const&) = delete;
    AsyncProcessResultImplementation& operator= (AsyncProcessResultImplementation const&) = delete;
    AsyncProcessResultImplementation(AsyncProcessResultImplementation&&) = delete;
    AsyncProcessResultImplementation& operator= (AsyncProcessResultImplementation&&) = delete;

    int StartProcess()
    {
        ASSERT(!my_child, "Process started already!");

        return CreateChildProcess([&](child& c) -> int
        {
            int result;
            my_child = std::reference_wrapper<child>(c);

            try
            {
                result = wait_for_exit(c);
            }
            catch (...)
            {
                result = EXIT_FAILURE;
            }

            my_child.reset();
            return was_terminated ? EXIT_FAILURE : result;

        }, executable, args, logger, input_file, is_secure);
    }

    void SetFuture(std::future<int> result_)
    {
        result = std::make_shared<std::future<int>>(std::move(result_));
    }

    /// Returns the future which contains the result of the process
    /// as soon it is finished.
    std::future<int>& GetFutureResult() override
    {
        ASSERT(*result, "The process wasn't started!");
        return **result;
    }

    /// Tries to terminate the process
    void Terminate() override
    {
        if (!my_child)
        {
            was_terminated = true;
            try
            {
                terminate(my_child->get());
            }
            catch(...)
            {
                // Do nothing
            }
        }
    }
};

std::shared_ptr<AsyncProcessResult>
    StartAsyncProcess(std::string executable, std::vector<std::string> args,
                      std::string logger, std::string input_file, bool secure)
{
    auto handle = std::make_shared<AsyncProcessResultImplementation>(
        std::move(executable), std::move(args), std::move(logger), std::move(input_file), secure);

    handle->SetFuture(std::async(std::launch::async, [handle] { return handle->StartProcess(); }));
    return handle;
}

Optional<std::string> SearchExecutableInPath(std::string const& filename)
{
    try
    {
        auto result = search_path(filename);
        if (result.empty())
            return boost::none;
        else
            return result;
    }
    catch (...)
    {
        return boost::none;
    }
}

} // namespace Trinity

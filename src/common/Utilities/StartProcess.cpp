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

#include "StartProcess.h"
#include "Errors.h"
#include "Log.h"
#include "Memory.h"
#include "Optional.h"
#include <boost/process/args.hpp>
#include <boost/process/child.hpp>
#include <boost/process/env.hpp>
#include <boost/process/exe.hpp>
#include <boost/process/io.hpp>
#include <boost/process/pipe.hpp>
#include <boost/process/search_path.hpp>
#include <fmt/ranges.h>

using namespace boost::process;

namespace Trinity
{
template<typename T>
static int CreateChildProcess(T waiter, std::string const& executable,
                              std::vector<std::string> const& argsVector,
                              std::string const& logger, std::string const& input,
                              bool secure)
{
#if TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT
#pragma warning(push)
#pragma warning(disable:4297)
/*
  Silence warning with boost 1.83

    boost/process/pipe.hpp(132,5): warning C4297: 'boost::process::basic_pipebuf<char,std::char_traits<char>>::~basic_pipebuf': function assumed not to throw an exception but does
    boost/process/pipe.hpp(132,5): message : destructor or deallocator has a (possibly implicit) non-throwing exception specification
    boost/process/pipe.hpp(124,6): message : while compiling class template member function 'boost::process::basic_pipebuf<char,std::char_traits<char>>::~basic_pipebuf(void)'
    boost/process/pipe.hpp(304,42): message : see reference to class template instantiation 'boost::process::basic_pipebuf<char,std::char_traits<char>>' being compiled
*/
#endif
    ipstream outStream;
    ipstream errStream;
#if TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT
#pragma warning(pop)
#endif

    if (!secure)
    {
        TC_LOG_TRACE(logger, "Starting process \"{}\" with arguments: \"{}\".",
                executable, fmt::join(argsVector, " "));
    }

    // prepare file with only read permission (boost process opens with read_write)
    auto inputFile = Trinity::make_unique_ptr_with_deleter(!input.empty() ? fopen(input.c_str(), "rb") : nullptr, &::fclose);

    // Start the child process
    child c = [&]()
    {
        if (inputFile)
        {
            // With binding stdin
            return child{
                exe = boost::filesystem::absolute(executable).string(),
                args = argsVector,
                env = environment(boost::this_process::environment()),
                std_in = inputFile.get(),
                std_out = outStream,
                std_err = errStream
            };
        }
        else
        {
            // Without binding stdin
            return child{
                exe = boost::filesystem::absolute(executable).string(),
                args = argsVector,
                env = environment(boost::this_process::environment()),
                std_in = boost::process::close,
                std_out = outStream,
                std_err = errStream
            };
        }
    }();

    std::string line;
    while (std::getline(outStream, line, '\n'))
    {
        std::erase(line, '\r');
        if (!line.empty())
            TC_LOG_INFO(logger, "{}", line);
    }

    while (std::getline(errStream, line, '\n'))
    {
        std::erase(line, '\r');
        if (!line.empty())
            TC_LOG_ERROR(logger, "{}", line);
    }

    // Call the waiter in the current scope to prevent
    // the streams from closing too early on leaving the scope.
    int const result = waiter(c);

    if (!secure)
    {
        TC_LOG_TRACE(logger, ">> Process \"{}\" finished with return value {}.",
                executable, result);
    }

    return result;
}

int StartProcess(std::string const& executable, std::vector<std::string> const& args,
                 std::string const& logger, std::string input_file, bool secure)
{
    return CreateChildProcess([](child& c) -> int
    {
        try
        {
            c.wait();
            return c.exit_code();
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
                c.wait();
                result = c.exit_code();
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
        if (my_child)
        {
            was_terminated = true;
            try
            {
                my_child->get().terminate();
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

std::string SearchExecutableInPath(std::string const& filename)
{
    try
    {
        return search_path(filename).string();
    }
    catch (...)
    {
        return "";
    }
}

} // namespace Trinity

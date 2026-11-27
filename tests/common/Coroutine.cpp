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

#include "tc_catch2.h"

#include "Common.h"
#include "Coro/AllOf.h"
#include "Coro/AllocatorImpl.h"
#include "Coro/Awaitable.h"
#include "Coro/AwaitableValue.h"
#include "Coro/CurrentCoroutine.h"
#include "Coro/MultiThreadedExecutor.h"
#include "Coro/Sleep.h"
#include "Coro/Start.h"
#include "Coro/SwitchExecutor.h"
#include "Duration.h"
#include "IoContext.h"
#include <thread>

class CoroutineFixture
{
public:
    Trinity::unique_trackable_ptr<Trinity::Coro::MultiThreadedExecutor> executor = Trinity::make_unique_trackable<Trinity::Coro::MultiThreadedExecutor>();
    std::variant<bool, std::exception_ptr> testCoroutineStatus = false;
    Trinity::Asio::IoContext timerContext;
    boost::asio::executor_work_guard<Trinity::Asio::IoContextExecutor> timerWorkGuard = boost::asio::make_work_guard(timerContext);
    std::thread timerThread;
    advstd::stop_source cancelSource;

    CoroutineFixture()
    {
        Trinity::Coro::InitializeTimerExecutor(&timerContext);
        timerThread = std::thread([this] { timerContext.run(); });
    }

    ~CoroutineFixture() noexcept(false)
    {
        bool timedOut = !executor->WaitForReadyCoroutinesAndResume(30s);

        timerWorkGuard.reset();
        timerThread.join();
        Trinity::Coro::ShutdownTimerExecutor();

        if (timedOut)
            FAIL("executor->WaitForReadyCoroutinesAndResume(30s) timed out");

        if (std::holds_alternative<std::exception_ptr>(testCoroutineStatus))
            std::rethrow_exception(std::get<std::exception_ptr>(testCoroutineStatus));

        if (!std::get<bool>(testCoroutineStatus))
            FAIL("Test coroutine not finished");
    }

    CoroutineFixture(CoroutineFixture const& other) = delete;
    CoroutineFixture(CoroutineFixture&& other) noexcept = delete;
    CoroutineFixture& operator=(CoroutineFixture const& other) = delete;
    CoroutineFixture& operator=(CoroutineFixture&& other) noexcept = delete;
};

template<std::derived_from<CoroutineFixture> TestFixture>
struct std::coroutine_traits<void, TestFixture&>
{
    struct promise_type : Trinity::Coro::CoroutineExecutionContext
    {
        promise_type(TestFixture& fixture) : CoroutineExecutionContext(std::coroutine_handle<promise_type>::from_promise(*this)),
            _testFixture(fixture)
        {
            CurrentExecutor = fixture.executor->weak_from_this();
            CurrentAllocator = &_allocator;
            CancelToken = fixture.cancelSource.get_token();
            Trinity::Coro::Impl::CurrentAllocator::Set(CurrentAllocator);
        }

        ~promise_type()
        {
            Trinity::Coro::Impl::CurrentAllocator::Set(nullptr);
        }

        void get_return_object() noexcept { }

        std::suspend_never initial_suspend() noexcept { return { }; }

        std::suspend_never final_suspend() noexcept { return { }; }

        void return_void() noexcept
        {
            _testFixture.testCoroutineStatus = true;
            _testFixture.executor->StopWaiting();
        }

        void unhandled_exception() noexcept
        {
            _testFixture.testCoroutineStatus = std::current_exception();
            _testFixture.executor->StopWaiting();
        }

        TestFixture& _testFixture;
        Trinity::Coro::Impl::Allocator _allocator;

        promise_type(promise_type const& other) = delete;
        promise_type(promise_type&& other) noexcept = delete;
        promise_type& operator=(promise_type const& other) = delete;
        promise_type& operator=(promise_type&& other) noexcept = delete;
    };
};

Trinity::Coro::Awaitable<int32> TestCoro1()
{
    co_return 1;
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::Allocator is available to nested coroutines", "[Coroutine][Allocator]")
{
    // test failure is a segfault
    REQUIRE(co_await TestCoro1() == 1);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::AwaitableValue resumes coroutine after obtaining value", "[Coroutine][AwaitableValue]")
{
    Trinity::Coro::AwaitableValue<int32> asyncValue;

    std::thread thrd([&asyncValue]
    {
        std::this_thread::sleep_for(0.5s);
        asyncValue.set_value(1);
    });

    int32 result = co_await asyncValue;

    thrd.join();

    REQUIRE(result == 1);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::AwaitableValue doesn't suspend coroutine when value is ready before co_await", "[Coroutine][AwaitableValue]")
{
    Trinity::Coro::AwaitableValue<int32> asyncValue;

    asyncValue.set_value(1);

    int32 result = co_await asyncValue;

    REQUIRE(result == 1);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::CurrentExecutor returns current executor associated with coroutine", "[Coroutine][AwaitableValue]")
{
    Trinity::unique_weak_ptr<Trinity::Coro::Executor> result = co_await Trinity::Coro::CurrentExecutor;

    REQUIRE(result.lock().get() == executor.get());
}

TEST_CASE("Coro::Start starts a new coroutine", "[Coroutine][Start]")
{
    Trinity::unique_trackable_ptr<Trinity::Coro::MultiThreadedExecutor> executor = Trinity::make_unique_trackable<Trinity::Coro::MultiThreadedExecutor>();
    bool executed = false;

    Trinity::Coro::Start(*executor, [&executor, &executed]() -> Trinity::Coro::Awaitable<void>
    {
        executed = true;
        executor->StopWaiting();
        co_return;
    });

    REQUIRE(executor->WaitForReadyCoroutinesAndResume(30s));
    REQUIRE(executed);
}

TEST_CASE("Coro::Start allows cancelling coroutines on initial suspend", "[Coroutine][Start]")
{
    Trinity::unique_trackable_ptr<Trinity::Coro::MultiThreadedExecutor> executor = Trinity::make_unique_trackable<Trinity::Coro::MultiThreadedExecutor>();
    advstd::stop_source cancelSource;

    Trinity::Coro::Start(*executor, [&executor]() -> Trinity::Coro::Awaitable<void>
    {
        executor->StopWaiting();
        co_return;
    }, cancelSource.get_token());

    cancelSource.request_stop();

    REQUIRE(executor->WaitForReadyCoroutinesAndResume(3s) == false);
}

TEST_CASE("Coro::Start allows cancelling coroutines in progress", "[Coroutine][Start]")
{
    Trinity::unique_trackable_ptr<Trinity::Coro::MultiThreadedExecutor> executor = Trinity::make_unique_trackable<Trinity::Coro::MultiThreadedExecutor>();
    advstd::stop_source cancelSource;

    Trinity::Coro::Start(*executor, [&executor, &cancelSource]() -> Trinity::Coro::Awaitable<void>
    {
        cancelSource.request_stop();
        co_await TestCoro1();
        executor->StopWaiting();
        co_return;
    }, cancelSource.get_token());

    REQUIRE(executor->WaitForReadyCoroutinesAndResume(3s) == false);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::SwitchToExecutor changes executor associated with coroutine", "[Coroutine][SwitchToExecutor]")
{
    Trinity::unique_trackable_ptr<Trinity::Coro::MultiThreadedExecutor> otherExecutor = Trinity::make_unique_trackable<Trinity::Coro::MultiThreadedExecutor>();
    std::thread otherExecutorThread([&otherExecutor] { otherExecutor->WaitForReadyCoroutinesAndResume(30s); });

    co_await Trinity::Coro::SwitchToExecutor(*otherExecutor);

    auto current = co_await Trinity::Coro::CurrentExecutor;

    REQUIRE(current.lock().get() == otherExecutor.get());

    co_await Trinity::Coro::SwitchToExecutor(*executor);

    current = co_await Trinity::Coro::CurrentExecutor;

    REQUIRE(current.lock().get() == executor.get());

    otherExecutor->StopWaiting();
    otherExecutorThread.join();
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::SleepFor delays coroutine", "[Coroutine][Sleep]")
{
    Seconds sleepDuration = 1s;

    TimePoint start = TimePoint::clock::now();

    co_await Trinity::Coro::SleepFor(sleepDuration);

    TimePoint now = TimePoint::clock::now();

    REQUIRE(now >= start + sleepDuration);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::SleepUntil delays coroutine", "[Coroutine][Sleep]")
{
    Seconds sleepDuration = 1s;

    TimePoint expiry = TimePoint::clock::now() + sleepDuration;

    co_await Trinity::Coro::SleepUntil(expiry);

    TimePoint now = TimePoint::clock::now();

    REQUIRE(now >= expiry);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::AllOf starts all awaitables at the same time and finishes when all are done", "[Coroutine][AllOf]")
{
    bool startedFlags[3] = { };

    auto testCoro = [&]<typename T>(std::size_t flagIndex, std::type_identity<T>) -> Trinity::Coro::Awaitable<T>
    {
        startedFlags[flagIndex] = true;
        co_await Trinity::Coro::SleepFor(100ms);
        REQUIRE(advstd::ranges::contains(startedFlags, false) == false);

        if constexpr (std::is_same_v<T, void>)
            co_return;
        else
            co_return static_cast<T>(flagIndex);
    };

    Trinity::Coro::Awaitable<std::size_t> coro1 = testCoro(0, std::type_identity<std::size_t>());
    Trinity::Coro::Awaitable<std::size_t> coro2 = testCoro(1, std::type_identity<std::size_t>());
    Trinity::Coro::Awaitable<void> coro3 = testCoro(2, std::type_identity<void>());

    auto allOf = co_await Trinity::Coro::AllOf(coro1, std::move(coro2), coro3);

    using AllResultOfTuple = decltype(allOf);
    STATIC_REQUIRE(std::tuple_size_v<AllResultOfTuple> == 2);
    STATIC_REQUIRE(std::is_lvalue_reference_v<std::tuple_element_t<0, AllResultOfTuple>>);
    STATIC_REQUIRE(std::is_reference_v<std::tuple_element_t<1, AllResultOfTuple>> == false);
    REQUIRE(std::get<0>(allOf) == 0);
    REQUIRE(std::get<1>(allOf) == 1);
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::AllOf rethrows exception from one of its nested awaitables", "[Coroutine][AllOf]")
{
    bool startedFlags[3] = { };

    auto testCoro = [&]<typename T>(std::size_t flagIndex, std::type_identity<T>, bool throws = false) -> Trinity::Coro::Awaitable<T>
    {
        startedFlags[flagIndex] = true;
        co_await Trinity::Coro::SleepFor(100ms);
        REQUIRE(advstd::ranges::contains(startedFlags, false) == false);

        if (throws)
            throw std::runtime_error("Controlled failure");

        if constexpr (std::is_same_v<T, void>)
            co_return;
        else
            co_return flagIndex;
    };

    Trinity::Coro::Awaitable<std::size_t> coro1 = testCoro(0, std::type_identity<std::size_t>());
    Trinity::Coro::Awaitable<std::size_t> coro2 = testCoro(1, std::type_identity<std::size_t>());
    Trinity::Coro::Awaitable<void> coro3 = testCoro(2, std::type_identity<void>(), true);

    REQUIRE_THROWS_WITH(co_await Trinity::Coro::AllOf(coro1, std::move(coro2), coro3), Catch::Matchers::ContainsSubstring("Controlled failure"));
}

TEST_CASE_METHOD(CoroutineFixture, "Coro::AllOf propagates cancellation from/to nested awaitables", "[Coroutine][AllOf]")
{
    auto testCoro = [&](bool cancels = false) -> Trinity::Coro::Awaitable<int32>
    {
        if (cancels)
            cancelSource.request_stop();

        co_await Trinity::Coro::SleepFor(100ms);

        co_return 1;
    };

    REQUIRE_THROWS_WITH(co_await Trinity::Coro::AllOf(testCoro(), testCoro(true)), Catch::Matchers::ContainsSubstring("Coroutine cancellation requested"));
}

TEST_CASE_METHOD(CoroutineFixture, "Coro:: cancellation works inside entry point function", "[Coroutine][AllOf]")
{
    cancelSource.request_stop();

    REQUIRE_THROWS_WITH(co_await Trinity::Coro::SleepFor(100ms), Catch::Matchers::ContainsSubstring("Coroutine cancellation requested"));
}

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

#ifndef TRINITYCORE_EXPECTED_COMPLETION_HANDLER_H
#define TRINITYCORE_EXPECTED_COMPLETION_HANDLER_H

#include <boost/asio/associated_executor.hpp>
#include <boost/asio/async_result.hpp>
#include <boost/asio/detail/handler_cont_helpers.hpp>
#include <boost/outcome/result.hpp>
#include <boost/preprocessor/empty.hpp>
#include <type_traits>

namespace Trinity::Asio
{
/// The AsExpected class is used to indicate that any arguments to the
/// completion handler should be combined and passed as a single @c boost::outcome_v2::result argument.
/// The arguments are first moved into a @c boost::outcome_v2::result and that is then
/// passed to the completion handler.
template <typename CompletionToken>
class AsExpected
{
public:
    // First dummy argument is used to prevent the "default" constructor from being used for implicit conversions
    constexpr AsExpected(std::type_identity<void> = {}, CompletionToken token = {})
        : token_(std::forward<CompletionToken>(token))
    {
    }

    template <typename T> requires (!std::same_as<T, AsExpected>)
    constexpr explicit AsExpected(T&& completion_token)
        : token_(std::forward<T>(completion_token))
    {
    }

    /// Adapts an executor to add the @c AsExpected completion token as the
    /// default.
    template <typename InnerExecutor>
    struct executor_with_default : InnerExecutor
    {
        /// Specify @c AsExpected as the default completion token type.
        typedef AsExpected default_completion_token_type;

        /// Construct the adapted executor from the inner executor type.
        template <typename InnerExecutor1>
        executor_with_default(InnerExecutor1 const& ex,
            std::enable_if_t<
                std::conditional_t<
                    !std::is_same_v<InnerExecutor1, executor_with_default>,
                    std::is_convertible<InnerExecutor1, InnerExecutor>,
                    std::false_type
                >::value,
                int
            > = 0) noexcept
            : InnerExecutor(ex)
        {
        }
    };

    /// Type alias to adapt an I/O object to use @c AsExpected as its
    /// default completion token type.
    template <typename T>
    using as_default_on_t = typename T::template rebind_executor<executor_with_default<typename T::executor_type>>::other;

    /// Function helper to adapt an I/O object to use @c AsExpected as its
    /// default completion token type.
    template <typename T>
    static auto as_default_on(T&& object)
    {
        return as_default_on_t<std::decay_t<T>>(static_cast<T&&>(object));
    }

    CompletionToken token_;
};

struct AsExpectedFn
{
    /// Adapt a @ref completion_token to specify that the completion handler
    /// arguments should be combined into a single @c boost::outcome_v2::result argument.
    template <typename CompletionToken>
    [[nodiscard]] inline constexpr AsExpected<std::decay_t<CompletionToken>> operator()(CompletionToken&& completion_token) const
    {
        return AsExpected<std::decay_t<CompletionToken>>(static_cast<CompletionToken&&>(completion_token));
    }
};

/// A function object that adapts a @ref completion_token to specify that the
/// completion handler arguments should be combined into a single @c boost::outcome_v2::result
/// argument.
///
/// May also be used directly as a completion token, in which case it adapts the
/// asynchronous operation's default completion token (or @ref boost::asio::deferred
/// if no default is available).
inline constexpr AsExpectedFn as_expected;

namespace Impl
{
template <typename T>
concept CompletionTokenError = std::same_as<std::remove_cvref_t<T>, boost::system::error_code>
    || std::same_as<std::remove_cvref_t<T>, std::exception_ptr>;

template <typename Handler>
class AsExpectedHandler
{
public:
    typedef void result_type;

    template <typename CompletionToken>
    AsExpectedHandler(AsExpected<CompletionToken> e) : handler_(static_cast<CompletionToken&&>(e.token_)) { }

    template <typename RedirectedHandler> requires (!std::same_as<RedirectedHandler, AsExpectedHandler>)
    AsExpectedHandler(RedirectedHandler&& h) : handler_(std::forward<RedirectedHandler>(h)) { }

    template <CompletionTokenError Error>
    inline void operator()(Error&& e)
    {
        using return_type = boost::outcome_v2::result<void, std::remove_cvref_t<Error>>;

        if (e)
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::failure(std::forward<Error>(e))));
        else
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::success()));
    }

    template <CompletionTokenError Error, typename Arg>
    inline void operator()(Error&& e, Arg&& value)
    {
        using return_type = boost::outcome_v2::result<std::decay_t<Arg>, std::remove_cvref_t<Error>>;

        if (e)
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::failure(std::forward<Error>(e))));
        else
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::success(std::forward<Arg>(value))));
    }

    template <CompletionTokenError Error, typename Arg, typename... Args>
    inline void operator()(Error&& e, Arg&& first, Args&&... rest)
    {
        using return_type = boost::outcome_v2::result<std::tuple<std::decay_t<Arg>, std::decay_t<Args>...>, std::remove_cvref_t<Error>>;

        if (e)
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::failure(std::forward<Error>(e))));
        else
            static_cast<Handler&&>(handler_)(return_type(boost::outcome_v2::success(std::make_tuple(std::forward<Arg>(first), std::forward<Args>(rest)...))));
    }

    Handler handler_;
};

template <typename Handler>
inline bool asio_handler_is_continuation(AsExpectedHandler<Handler>* this_handler)
{
    return boost_asio_handler_cont_helpers::is_continuation(this_handler->handler_);
}

template <typename Signature>
struct AsExpectedSignature;

#define STAMP_AS_EXPECTED_SIGNATURE(qualifier) \
    template <typename R, CompletionTokenError Error> \
    struct AsExpectedSignature<R(Error) qualifier> \
    { \
        using type = R(boost::outcome_v2::result<void, std::remove_cvref_t<Error>>) qualifier; \
    }; \
    template <typename R, CompletionTokenError Error, typename Arg> \
    struct AsExpectedSignature<R(Error, Arg) qualifier> \
    { \
        using type = R(boost::outcome_v2::result<std::decay_t<Arg>, std::remove_cvref_t<Error>>) qualifier; \
    }; \
    template <typename R, CompletionTokenError Error, typename Arg, typename... Args> \
    struct AsExpectedSignature<R(Error, Arg, Args...) qualifier> \
    { \
        using type = R(boost::outcome_v2::result<std::tuple<std::decay_t<Arg>, std::decay_t<Args>...>, std::remove_cvref_t<Error>>) qualifier; \
    };

STAMP_AS_EXPECTED_SIGNATURE(BOOST_PP_EMPTY());
STAMP_AS_EXPECTED_SIGNATURE(&);
STAMP_AS_EXPECTED_SIGNATURE(&&);
STAMP_AS_EXPECTED_SIGNATURE(noexcept);
STAMP_AS_EXPECTED_SIGNATURE(& noexcept);
STAMP_AS_EXPECTED_SIGNATURE(&& noexcept);

} // namespace Impl
}

namespace boost::asio
{
#if BOOST_VERSION >= 107700
template <typename CompletionToken, typename... Signatures>
class async_result<Trinity::Asio::AsExpected<CompletionToken>, Signatures...> : async_result<CompletionToken, typename Trinity::Asio::Impl::AsExpectedSignature<Signatures>::type...>
{
    template <typename Initiation>
    struct init_wrapper
    {
        explicit init_wrapper(Initiation const& initiation) : initiation_(initiation) { }
        explicit init_wrapper(Initiation&& initiation) : initiation_(std::move(initiation)) { }

        template <typename Handler, typename... Args>
        inline void operator()(Handler&& handler, Args&&... args) &&
        {
            static_cast<Initiation&&>(initiation_)(Trinity::Asio::Impl::AsExpectedHandler<std::decay_t<Handler>>(std::forward<Handler>(handler)), std::forward<Args>(args)...);
        }

        template <typename Handler, typename... Args>
        inline void operator()(Handler&& handler, Args&&... args) const &
        {
            static_cast<Initiation const&>(initiation_)(Trinity::Asio::Impl::AsExpectedHandler<std::decay_t<Handler>>(std::forward<Handler>(handler)), std::forward<Args>(args)...);
        }

        Initiation initiation_;
    };

public:
    template <typename Initiation, typename RawCompletionToken, typename... Args>
    static inline auto initiate(Initiation&& initiation, RawCompletionToken&& token, Args&&... args)
    {
        return async_initiate<
            conditional_t<
            is_const<remove_reference_t<RawCompletionToken>>::value,
            CompletionToken const, CompletionToken>,
            typename Trinity::Asio::Impl::AsExpectedSignature<Signatures>::type...>(
                init_wrapper<std::decay_t<Initiation>>(
                    std::forward<Initiation>(initiation)),
                token.token_, std::forward<Args>(args)...);
    }
};

template <template <typename, typename> class Associator, typename Handler, typename DefaultCandidate, typename _>
struct associator;

template <template <typename, typename> class Associator, typename Handler, typename DefaultCandidate>
struct associator<Associator, Trinity::Asio::Impl::AsExpectedHandler<Handler>, DefaultCandidate, void> : Associator<Handler, DefaultCandidate>
{
    static inline auto get(Trinity::Asio::Impl::AsExpectedHandler<Handler> const& h) noexcept
    {
        return Associator<Handler, DefaultCandidate>::get(h.handler_);
    }

    static inline auto get(Trinity::Asio::Impl::AsExpectedHandler<Handler> const& h, DefaultCandidate const& c) noexcept
    {
        return Associator<Handler, DefaultCandidate>::get(h.handler_, c);
    }
};

template <typename... Signatures>
class async_result<Trinity::Asio::AsExpectedFn, Signatures...>
{
public:
    template <typename Initiation, typename RawCompletionToken, typename... Args>
    static inline auto initiate(Initiation&& initiation, RawCompletionToken&&, Args&&... args)
    {
        return async_initiate<Signatures...>(
            std::forward<Initiation>(initiation),
            Trinity::Asio::AsExpected<
            default_completion_token_t<associated_executor_t<Initiation>>>{},
            std::forward<Args>(args)...);
    }
};
#else
template <typename CompletionToken, typename Signature>
class async_result<Trinity::Asio::AsExpected<CompletionToken>, Signature> : async_result<CompletionToken, typename Trinity::Asio::Impl::AsExpectedSignature<Signature>::type>
{
    template <typename Initiation>
    struct init_wrapper
    {
        explicit init_wrapper(Initiation const& initiation) : initiation_(initiation) { }
        explicit init_wrapper(Initiation&& initiation) : initiation_(std::move(initiation)) { }

        template <typename Handler, typename... Args>
        inline void operator()(Handler&& handler, Args&&... args) &&
        {
            static_cast<Initiation&&>(initiation_)(Trinity::Asio::Impl::AsExpectedHandler<std::decay_t<Handler>>(std::forward<Handler>(handler)), std::forward<Args>(args)...);
        }

        template <typename Handler, typename... Args>
        inline void operator()(Handler&& handler, Args&&... args) const &
        {
            static_cast<Initiation const&>(initiation_)(Trinity::Asio::Impl::AsExpectedHandler<std::decay_t<Handler>>(std::forward<Handler>(handler)), std::forward<Args>(args)...);
        }

        Initiation initiation_;
    };

public:
    template <typename Initiation, typename RawCompletionToken, typename... Args>
    static inline auto initiate(Initiation&& initiation, RawCompletionToken&& token, Args&&... args)
    {
        return async_initiate<
            conditional_t<
            is_const<remove_reference_t<RawCompletionToken>>::value,
            CompletionToken const, CompletionToken>,
            typename Trinity::Asio::Impl::AsExpectedSignature<Signature>::type>(
                init_wrapper<std::decay_t<Initiation>>(
                    std::forward<Initiation>(initiation)),
                token.token_, std::forward<Args>(args)...);
    }
};
#endif
} // namespace boost::asio

#endif // TRINITYCORE_EXPECTED_COMPLETION_HANDLER_H

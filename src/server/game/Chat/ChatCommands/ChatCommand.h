/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_CHATCOMMAND_H
#define TRINITY_CHATCOMMAND_H

#include "advstd.h"
#include "ChatCommandArgs.h"
#include "ChatCommandTags.h"
#include "Define.h"
#include "Errors.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <vector>

class ChatHandler;
class CommandArgs;

template <typename T>
struct CommandArgsConsumerSingle
{
    using arginfo = Trinity::ChatCommands::ArgInfo<T>;
    static char const* TryConsumeTo(T& val, char const* args)
    {
        return arginfo::TryConsume(val, args);
    }
};

struct CommandArgsVariantConsumer
{
    template <typename V, typename T1, typename T2, typename... Ts>
    static char const* TryConsumeTo(V& val, char const* args)
    {
        T1 v;
        if (char const* next = CommandArgsConsumerSingle<T1>::TryConsumeTo(v, args))
        {
            val = std::move(v);
            return next;
        }
        else
            return TryConsumeTo<V, T2, Ts...>(val, args);
    }

    template <typename V, typename T1>
    static char const* TryConsumeTo(V& val, char const* args)
    {
        T1 v;
        if (char const* next = CommandArgsConsumerSingle<T1>::TryConsumeTo(v, args))
        {
            val = std::move(v);
            return next;
        }
        else
            return nullptr;
    }
};

template <typename... Ts>
struct CommandArgsConsumerSingle<Trinity::ChatCommands::Variant<Ts...>>
{
    static char const* TryConsumeTo(Trinity::ChatCommands::Variant<Ts...>& val, char const* args)
    {
        return CommandArgsVariantConsumer::TryConsumeTo<Trinity::ChatCommands::Variant<Ts...>, Ts...>(val, args);
    }
};

template <typename T>
struct CommandArgsConsumerSingle<std::vector<T>>
{
    static char const* TryConsumeTo(std::vector<T>& val, char const* args)
    {
        char const* last;
        val.clear();

        do val.emplace_back();
        while ((args = CommandArgsConsumerSingle<T>::TryConsumeTo(val.back(), (last = args))));

        val.pop_back();
        return last;
    }
};

template <>
struct CommandArgsConsumerSingle<CommandArgs*>
{
    static char const* TryConsumeTo(CommandArgs*&, char const* args) { return args; }
};

template <>
struct CommandArgsConsumerSingle<char const*>
{
    static char const* TryConsumeTo(char const*&, char const* args) { return args; }
};

template <typename T, size_t offset>
struct CommandArgsConsumerNext;

template <typename Tuple, typename NextType, size_t offset>
struct CommandArgsConsumerMulti
{
    static char const* TryConsumeTo(Tuple& tuple, char const* args)
    {
        if (char const* next = CommandArgsConsumerSingle<NextType>::TryConsumeTo(std::get<offset>(tuple), args))
            return CommandArgsConsumerNext<Tuple, offset+1>::GoNext(tuple, next);
        else
            return nullptr;
    }
};

template <typename Tuple, typename NestedNextType, size_t offset>
struct CommandArgsConsumerMulti<Tuple, Optional<NestedNextType>, offset>
{
    static char const* TryConsumeTo(Tuple& tuple, char const* args)
    {
        // try with the argument
        auto& myArg = std::get<offset>(tuple);
        myArg.emplace();
        if (char const* next = CommandArgsConsumerSingle<NestedNextType>::TryConsumeTo(*(myArg.get_ptr()), args))
            if ((next = CommandArgsConsumerNext<Tuple, offset+1>::GoNext(tuple, next)))
                return next;
        // try again omitting the argument
        myArg = boost::none;
        if (char const* next = CommandArgsConsumerNext<Tuple, offset+1>::GoNext(tuple, args))
            return next;
        return nullptr;
    }
};

template <size_t offset, typename... Ts>
struct CommandArgsConsumerNext<std::tuple<Ts...>, offset>
{
    using tuple_type = std::tuple<Ts...>;

    template <bool C = (offset < sizeof...(Ts))>
    static std::enable_if_t<C, char const*> GoNext(tuple_type& tuple, char const* args)
    {
        return CommandArgsConsumerMulti<tuple_type, std::tuple_element_t<offset, tuple_type>, offset>::TryConsumeTo(tuple, args);
    }

    template <bool C = (offset < sizeof...(Ts))>
    static std::enable_if_t<!C, char const*> GoNext(tuple_type&, char const* args)
    {
        return args;
    }
};

class TC_GAME_API CommandArgs
{
    public:
        CommandArgs(char const* args) : _original(args), _args(args) {}

        template <typename T1, typename T2, typename... Ts>
        auto TryConsume()
        {
            Optional<std::tuple<advstd::remove_cvref_t<T1>, advstd::remove_cvref_t<T2>, advstd::remove_cvref_t<Ts>...>> rv;
            rv.emplace();
            if (!TryConsumeToTuple<0>(*(rv.get_ptr())))
                rv = boost::none;
            return rv;
        }

        template <typename T1>
        auto TryConsume()
        {
            using T = advstd::remove_cvref_t<T1>;
            Optional<T> rv;
            rv.emplace();
            if (char const* next = CommandArgsConsumerSingle<T>::TryConsumeTo(*(rv.get_ptr()), _args))
                _args = next;
            else
                rv = boost::none;
            return rv;
        }

        template <size_t offset = 0, typename T>
        bool TryConsumeToTuple(T& tuple)
        {
            if (char const* next = CommandArgsConsumerNext<T, offset>::GoNext(tuple, _args))
            {
                _args = next;
                return true;
            }
            else
                return false;
        }

        void Reset() { _args = _original; }

        char const* GetFullArgs() const { return _original; }
        char const* GetRemainingArgs() const { return _args; }

        bool IsEmpty() const { return !!*_args; }
        explicit operator bool() const { return IsEmpty(); }

    private:
        char const* const _original;
        char const* _args;
};

template <typename T> struct ChatCommandHandlerToTuple { static_assert(!advstd::is_same_v<T,T>, "Invalid command handler signature"); };
template <typename... Ts> struct ChatCommandHandlerToTuple<bool(*)(ChatHandler*, Ts...)> { using type = std::tuple<ChatHandler*, advstd::remove_cvref_t<Ts>...>; };

template <typename T> struct ChatCommandStoreLastArg { static void store(T&, CommandArgs&) {} };
template <> struct ChatCommandStoreLastArg<char const*> { static void store(char const*& arg, CommandArgs& args) { arg = args.GetRemainingArgs(); } };
template <> struct ChatCommandStoreLastArg<CommandArgs*> { static void store(CommandArgs*& arg, CommandArgs& args) { arg = &args; } };

class TC_GAME_API ChatCommand
{
    using wrapper_func = bool(void*, ChatHandler*, char const*);

    public:
        template <typename TypedHandler>
        ChatCommand(char const* name, uint32 permission, bool allowConsole, TypedHandler handler, std::string help)
            : Name(ASSERT_NOTNULL(name)), Permission(permission), AllowConsole(allowConsole), Help(std::move(help)), ChildCommands({})
        {
            _wrapper = [](void* handler, ChatHandler* chatHandler, char const* argsStr)
            {
                using tuple_type = typename ChatCommandHandlerToTuple<TypedHandler>::type;

                tuple_type arguments;
                std::get<0>(arguments) = chatHandler;

                CommandArgs args(argsStr);
                if (args.TryConsumeToTuple<1>(arguments))
                {
                    auto& last = std::get<advstd::tuple_size_v<tuple_type>-1>(arguments);
                    ChatCommandStoreLastArg<advstd::remove_cvref_t<decltype(last)>>::store(last, args);
                    return advstd::apply(reinterpret_cast<TypedHandler>(handler), std::move(arguments));
                }
                else
                    return false;
            };
            _handler = reinterpret_cast<void*>(handler);
        }

        ChatCommand(char const* name, uint32 permission, bool allowConsole, std::nullptr_t, std::string help, std::vector<ChatCommand> childCommands = {})
            : Name(ASSERT_NOTNULL(name)), Permission(permission), AllowConsole(allowConsole), Help(std::move(help)), ChildCommands(std::move(childCommands))
        {
            _wrapper = nullptr;
            _handler = nullptr;
        }

        bool operator()(ChatHandler* chatHandler, char const* args) const
        {
            ASSERT(_wrapper && _handler);
            return _wrapper(_handler, chatHandler, args);
        }

        bool HasHandler() const { return !!_handler; }

        char const* Name;
        uint32 Permission;                   // function pointer required correct align (use uint32)
        bool AllowConsole;
        std::string Help;
        std::vector<ChatCommand> ChildCommands;

    private:
        wrapper_func* _wrapper;
        void* _handler;
};

#endif

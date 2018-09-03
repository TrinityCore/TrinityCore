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

#ifndef TRINITY_CHATCOMMAND_HPP
#define TRINITY_CHATCOMMAND_HPP

#include "apply.hpp"
#include "ChatCommandArgs.hpp"
#include "Define.h"
#include "Errors.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <tuple>
#include <type_traits>

class ChatHandler;

class TC_GAME_API CommandArgs
{
    public:
        CommandArgs(char const* args) : _original(args), _args(args) {}

        template <typename... Args>
        Optional<Trinity::ChatCommandArgs::Tuple<Args...>> tryConsume()
        {
            Optional<Trinity::ChatCommandArgs::Tuple<Args...>> ret;
            ret.emplace();
            if (char const* next = ret->fill(_args))
                _args = next;
            else
                ret = boost::none;
            return ret;
        }

        void reset() { _args = _original; }

        char const* all() const { return _original; }
        char const* remainder() const { return _args; }

        explicit operator bool() const { return !!*_args; }

    private:
        char const* const _original;
        char const* _args;
};

namespace Trinity {
    namespace ChatCommandHelpers {
        template <typename T> struct HandlerToArgTypes { static_assert(!std::is_same_v<T,T>, "Invalid command handler signature"); };
        template <typename... Ts> struct HandlerToArgTypes<bool(*)(ChatHandler*, Ts...)> { typedef std::tuple<ChatHandler*, typename std::remove_reference<Ts>::type...> type; };

        template <typename T, size_t i> struct TupleFiller{ };
        template <size_t i, typename T1, typename... Ts>
        struct TupleFiller<std::tuple<ChatHandler*, T1, Ts...>, i>
        {
            template <typename U>
            static bool consume(CommandArgs& args, U& tuple)
            {
                using arginfo = Trinity::ChatCommandArgs::ArgInfo<T1>;
                if (auto arg = args.tryConsume<typename arginfo::tag>())
                    return arginfo::assign(std::get<i>(tuple), arg->get_tag<0>());
                else
                    return false;
            }

            template <typename U, size_t n = sizeof...(Ts)>
            static std::enable_if_t<(n > 0), bool> fill(CommandArgs& args, U& tuple)
            {
                return consume(args, tuple) && TupleFiller<std::tuple<ChatHandler*, Ts...>, i + 1>::fill(args, tuple);
            }

            template <typename U, typename V = T1, size_t n = sizeof...(Ts)>
            static std::enable_if_t<(n == 0) && !(std::is_same_v<V, CommandArgs*> || std::is_same_v<V, char const*>), bool> fill(CommandArgs& args, U& tuple)
            {
                return consume(args, tuple);
            }

            // trailing ChatCommandArgs& gets args object
            template <typename U, typename V = T1, size_t n = sizeof...(Ts)>
            static std::enable_if_t<(n == 0) && std::is_same_v<V, CommandArgs*>, bool> fill(CommandArgs& args, U& tuple)
            {
                std::get<i>(tuple) = &args;
                return true;
            }

            // trailing char const* gets rest of string
            template <typename U, typename V = T1, size_t n = sizeof...(Ts)>
            static std::enable_if_t<(n == 0) && std::is_same_v<V, char const*>, bool> fill(CommandArgs& args, U& tuple)
            {
                std::get<i>(tuple) = args.remainder();
                return true;
            }
        };
    }
}

class TC_GAME_API ChatCommand
{
    typedef bool(*WrappedHandler)(void*, ChatHandler*, char const*);

    public:
        template <typename TypedHandler>
        ChatCommand(char const* name, uint32 permission, bool allowConsole, TypedHandler handler, std::string help)
            : Name(ASSERT_NOTNULL(name)), Permission(permission), AllowConsole(allowConsole), Help(std::move(help)), ChildCommands({})
        {
            _wrapper = [](void* handler, ChatHandler* chatHandler, char const* argsStr)
            {
                typedef typename Trinity::ChatCommandHelpers::HandlerToArgTypes<TypedHandler>::type ArgTuple;
                ArgTuple arguments = {};
                std::get<0>(arguments) = chatHandler;

                CommandArgs args(argsStr);
                if (Trinity::ChatCommandHelpers::TupleFiller<ArgTuple, 1>::fill(args, arguments))
                    return Trinity::apply(reinterpret_cast<TypedHandler>(handler), arguments);
                else
                    return false;
            };
            _handler = reinterpret_cast<void*>(handler);
        }

        ChatCommand(char const* name, uint32 permission, bool allowConsole, nullptr_t, std::string help, std::vector<ChatCommand> childCommands = {})
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
        WrappedHandler _wrapper;
        void* _handler;
};

#endif

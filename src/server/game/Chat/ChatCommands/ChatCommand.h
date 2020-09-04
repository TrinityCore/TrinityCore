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

namespace Trinity::Impl::ChatCommands
{
    template <typename T>
    struct SingleConsumer
    {
        static Optional<std::string_view> TryConsumeTo(T& val, std::string_view args)
        {
            return ArgInfo<T>::TryConsume(val, args);
        }
    };

    /*
      for backwards compatibility, consumes the rest of the string
      new code should use the Tail/WTail tags defined in ChatCommandTags
    */
    template <>
    struct SingleConsumer<char const*>
    {
        static Optional<std::string_view> TryConsumeTo(char const*& arg, std::string_view args) { arg = args.data(); return std::string_view(); }
    };


    // forward declaration
    // ConsumeFromOffset contains the bounds check for offset, then hands off to MultiConsumer
    // the call stack is MultiConsumer -> ConsumeFromOffset -> MultiConsumer -> ConsumeFromOffset etc
    // MultiConsumer calls SingleConsumer in each iteration
    template <typename Tuple, size_t offset>
    Optional<std::string_view> ConsumeFromOffset(Tuple&, std::string_view args);

    template <typename Tuple, typename NextType, size_t offset>
    struct MultiConsumer
    {
        static Optional<std::string_view> TryConsumeTo(Tuple& tuple, std::string_view args)
        {
            if (Optional<std::string_view> next = SingleConsumer<NextType>::TryConsumeTo(std::get<offset>(tuple), args))
                return ConsumeFromOffset<Tuple, offset + 1>(tuple, *next);
            else
                return std::nullopt;
        }
    };

    template <typename Tuple, typename NestedNextType, size_t offset>
    struct MultiConsumer<Tuple, Optional<NestedNextType>, offset>
    {
        static Optional<std::string_view> TryConsumeTo(Tuple& tuple, std::string_view args)
        {
            // try with the argument
            auto& myArg = std::get<offset>(tuple);
            myArg.emplace();
            if (Optional<std::string_view> next = SingleConsumer<NestedNextType>::TryConsumeTo(myArg.value(), args))
                if ((next = ConsumeFromOffset<Tuple, offset + 1>(tuple, *next)))
                    return next;
            // try again omitting the argument
            myArg = std::nullopt;
            return ConsumeFromOffset<Tuple, offset + 1>(tuple, args);
        }
    };

    template <typename Tuple, size_t offset>
    Optional<std::string_view> ConsumeFromOffset(Tuple& tuple, std::string_view args)
    {
        if constexpr (offset < std::tuple_size_v<Tuple>)
            return MultiConsumer<Tuple, std::tuple_element_t<offset, Tuple>, offset>::TryConsumeTo(tuple, args);
        else if (!args.empty()) /* the entire string must be consumed */
            return std::nullopt;
        else
            return args;
    }

    template <typename T> struct HandlerToTuple { static_assert(Trinity::dependant_false_v<T>, "Invalid command handler signature"); };
    template <typename... Ts> struct HandlerToTuple<bool(*)(ChatHandler*, Ts...)> { using type = std::tuple<ChatHandler*, advstd::remove_cvref_t<Ts>...>; };
    template <typename T> using TupleType = typename HandlerToTuple<T>::type;
}


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
                using Tuple = Trinity::Impl::ChatCommands::TupleType<TypedHandler>;

                Tuple arguments;
                std::get<0>(arguments) = chatHandler;
                if (Trinity::Impl::ChatCommands::ConsumeFromOffset<Tuple, 1>(arguments, argsStr))
                    return std::apply(reinterpret_cast<TypedHandler>(handler), std::move(arguments));
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
        uint32 Permission;
        bool AllowConsole;
        std::string Help;
        std::vector<ChatCommand> ChildCommands;

    private:
        wrapper_func* _wrapper;
        void* _handler;
};

#endif

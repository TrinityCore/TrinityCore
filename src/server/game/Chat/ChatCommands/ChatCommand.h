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
#include "StringFormat.h"
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <vector>

class ChatHandler;

namespace Trinity::Impl::ChatCommands
{
    // forward declaration
    // ConsumeFromOffset contains the bounds check for offset, then hands off to MultiConsumer
    // the call stack is MultiConsumer -> ConsumeFromOffset -> MultiConsumer -> ConsumeFromOffset etc
    // MultiConsumer goes into ArgInfo for parsing on each iteration
    template <typename Tuple, size_t offset>
    ChatCommandResult ConsumeFromOffset(Tuple&, ChatHandler const* handler, std::string_view args);

    template <typename Tuple, typename NextType, size_t offset>
    struct MultiConsumer
    {
        static ChatCommandResult TryConsumeTo(Tuple& tuple, ChatHandler const* handler, std::string_view args)
        {
            ChatCommandResult next = ArgInfo<NextType>::TryConsume(std::get<offset>(tuple), handler, args);
            if (next)
                return ConsumeFromOffset<Tuple, offset + 1>(tuple, handler, *next);
            else
                return next;
        }
    };

    template <typename Tuple, typename NestedNextType, size_t offset>
    struct MultiConsumer<Tuple, Optional<NestedNextType>, offset>
    {
        static ChatCommandResult TryConsumeTo(Tuple& tuple, ChatHandler const* handler, std::string_view args)
        {
            // try with the argument
            auto& myArg = std::get<offset>(tuple);
            myArg.emplace();

            ChatCommandResult result1 = ArgInfo<NestedNextType>::TryConsume(myArg.value(), handler, args);
            if (result1)
                if ((result1 = ConsumeFromOffset<Tuple, offset + 1>(tuple, handler, *result1)))
                    return result1;
            // try again omitting the argument
            myArg = std::nullopt;
            ChatCommandResult result2 = ConsumeFromOffset<Tuple, offset + 1>(tuple, handler, args);
            if (result2)
                return result2;
            if (result1.HasErrorMessage() && result2.HasErrorMessage())
            {
                return Trinity::StringFormat("%s \"%s\"\n%s \"%s\"",
                    GetTrinityString(handler, LANG_CMDPARSER_EITHER), result2.GetErrorMessage().c_str(),
                    GetTrinityString(handler, LANG_CMDPARSER_OR), result1.GetErrorMessage().c_str());
            }
            else if (result1.HasErrorMessage())
                return result1;
            else
                return result2;
        }
    };

    template <typename Tuple, size_t offset>
    ChatCommandResult ConsumeFromOffset([[maybe_unused]] Tuple& tuple, [[maybe_unused]] ChatHandler const* handler, std::string_view args)
    {
        if constexpr (offset < std::tuple_size_v<Tuple>)
            return MultiConsumer<Tuple, std::tuple_element_t<offset, Tuple>, offset>::TryConsumeTo(tuple, handler, args);
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
                Trinity::Impl::ChatCommands::ChatCommandResult result = Trinity::Impl::ChatCommands::ConsumeFromOffset<Tuple, 1>(arguments, chatHandler, argsStr);
                if (result)
                    return std::apply(reinterpret_cast<TypedHandler>(handler), std::move(arguments));
                else
                {
                    if (result.HasErrorMessage())
                        Trinity::Impl::ChatCommands::SendErrorMessageToHandler(chatHandler, result.GetErrorMessage());
                    return false;
                }
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

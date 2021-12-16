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
#include "Language.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "RBAC.h"
#include "StringFormat.h"
#include "Util.h"
#include <cstddef>
#include <map>
#include <utility>
#include <tuple>
#include <type_traits>
#include <variant>
#include <vector>

class ChatHandler;

namespace Trinity::ChatCommands
{
    enum class Console : bool
    {
        No = false,
        Yes = true
    };

    struct ChatCommandBuilder;
    using ChatCommandTable = std::vector<ChatCommandBuilder>;
}

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
    template <typename... Ts> struct HandlerToTuple<bool(ChatHandler*, Ts...)> { using type = std::tuple<ChatHandler*, advstd::remove_cvref_t<Ts>...>; };
    template <typename T> using TupleType = typename HandlerToTuple<T>::type;

    struct CommandInvoker
    {
        CommandInvoker() : _wrapper(nullptr), _handler(nullptr) {}
        template <typename TypedHandler>
        CommandInvoker(TypedHandler& handler)
        {
            _wrapper = [](void* handler, ChatHandler* chatHandler, std::string_view argsStr)
            {
                using Tuple = TupleType<TypedHandler>;

                Tuple arguments;
                std::get<0>(arguments) = chatHandler;
                ChatCommandResult result = ConsumeFromOffset<Tuple, 1>(arguments, chatHandler, argsStr);
                if (result)
                    return std::apply(reinterpret_cast<TypedHandler*>(handler), std::move(arguments));
                else
                {
                    if (result.HasErrorMessage())
                        SendErrorMessageToHandler(chatHandler, result.GetErrorMessage());
                    return false;
                }
            };
            _handler = reinterpret_cast<void*>(handler);
        }
        CommandInvoker(bool(&handler)(ChatHandler*, char const*))
        {
            _wrapper = [](void* handler, ChatHandler* chatHandler, std::string_view argsStr)
            {
                // make a copy of the argument string
                // legacy handlers can destroy input strings with strtok
                std::string argsStrCopy(argsStr);
                return reinterpret_cast<bool(*)(ChatHandler*, char const*)>(handler)(chatHandler, argsStrCopy.c_str());
            };
            _handler = reinterpret_cast<void*>(handler);
        }

        explicit operator bool() const { return (_wrapper != nullptr); }
        bool operator()(ChatHandler* chatHandler, std::string_view args) const
        {
            ASSERT(_wrapper && _handler);
            return _wrapper(_handler, chatHandler, args);
        }

    private:
        using wrapper_func = bool(void*, ChatHandler*, std::string_view);
        wrapper_func* _wrapper;
        void* _handler;
    };

    struct CommandPermissions
    {
        CommandPermissions() : RequiredPermission{}, AllowConsole{} {}
        CommandPermissions(rbac::RBACPermissions perm, Trinity::ChatCommands::Console console) : RequiredPermission{ perm }, AllowConsole{ console } {}
        rbac::RBACPermissions RequiredPermission;
        Trinity::ChatCommands::Console AllowConsole;
    };

    class ChatCommandNode
    {
        friend struct FilteredCommandListIterator;
        using ChatCommandBuilder = Trinity::ChatCommands::ChatCommandBuilder;

        public:
            static void LoadCommandMap();
            static void InvalidateCommandMap();
            static bool TryExecuteCommand(ChatHandler& handler, std::string_view cmd);
            static void SendCommandHelpFor(ChatHandler& handler, std::string_view cmd);
            static std::vector<std::string> GetAutoCompletionsFor(ChatHandler const& handler, std::string_view cmd);

            ChatCommandNode() : _name{}, _invoker {}, _permission{}, _help{}, _subCommands{} {}

        private:
            static std::map<std::string_view, ChatCommandNode, StringCompareLessI_T> const& GetTopLevelMap();
            static void LoadCommandsIntoMap(ChatCommandNode* blank, std::map<std::string_view, ChatCommandNode, StringCompareLessI_T>& map, Trinity::ChatCommands::ChatCommandTable const& commands);

            void LoadFromBuilder(ChatCommandBuilder const& builder);
            ChatCommandNode(ChatCommandNode&& other) = default;

            void ResolveNames(std::string name);
            void SendCommandHelp(ChatHandler& handler) const;

            bool IsVisible(ChatHandler const& who) const { return (IsInvokerVisible(who) || HasVisibleSubCommands(who)); }
            bool IsInvokerVisible(ChatHandler const& who) const;
            bool HasVisibleSubCommands(ChatHandler const& who) const;

            std::string _name;
            CommandInvoker _invoker;
            CommandPermissions _permission;
            std::variant<std::monostate, TrinityStrings, std::string> _help;
            std::map<std::string_view, ChatCommandNode, StringCompareLessI_T> _subCommands;
    };
}

namespace Trinity::ChatCommands
{
    struct ChatCommandBuilder
    {
        friend class Trinity::Impl::ChatCommands::ChatCommandNode;
        struct InvokerEntry
        {
            template <typename T>
            InvokerEntry(T& handler, TrinityStrings help, rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
                : _invoker{ handler }, _help{ help }, _permissions{ permission, allowConsole }
            {}
            InvokerEntry(InvokerEntry const&) = default;
            InvokerEntry(InvokerEntry&&) = default;

            Trinity::Impl::ChatCommands::CommandInvoker _invoker;
            TrinityStrings _help;
            Trinity::Impl::ChatCommands::CommandPermissions _permissions;

            auto operator*() const { return std::tie(_invoker, _help, _permissions); }
        };
        using SubCommandEntry = std::reference_wrapper<std::vector<ChatCommandBuilder> const>;

        ChatCommandBuilder(ChatCommandBuilder&&) = default;
        ChatCommandBuilder(ChatCommandBuilder const&) = default;

        template <typename TypedHandler>
        ChatCommandBuilder(char const* name, TypedHandler& handler, TrinityStrings help, rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
            : _name{ ASSERT_NOTNULL(name) }, _data{ std::in_place_type<InvokerEntry>, handler, help, permission, allowConsole }
        {}

        template <typename TypedHandler>
        ChatCommandBuilder(char const* name, TypedHandler& handler, rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
            : ChatCommandBuilder(name, handler, TrinityStrings(), permission, allowConsole)
        {}
        ChatCommandBuilder(char const* name, std::vector<ChatCommandBuilder> const& subCommands)
            : _name{ ASSERT_NOTNULL(name) }, _data{ std::in_place_type<SubCommandEntry>, subCommands }
        {}

        [[deprecated("char const* parameters to command handlers are deprecated; convert this to a typed argument handler instead")]]
        ChatCommandBuilder(char const* name, bool(&handler)(ChatHandler*, char const*), rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
            : ChatCommandBuilder(name, handler, TrinityStrings(), permission, allowConsole)
        {}

        template <typename TypedHandler>
        [[deprecated("you are using the old-style command format; convert this to the new format ({ name, handler (not a pointer!), permission, Console::(Yes/No) })")]]
        ChatCommandBuilder(char const* name, rbac::RBACPermissions permission, bool console, TypedHandler* handler, char const*)
            : ChatCommandBuilder(name, *handler, TrinityStrings(), permission, static_cast<Trinity::ChatCommands::Console>(console))
        {}

        [[deprecated("you are using the old-style command format; convert this to the new format ({ name, subCommands })")]]
        ChatCommandBuilder(char const* name, rbac::RBACPermissions, bool, std::nullptr_t, char const*, std::vector <ChatCommandBuilder> const& sub)
            : ChatCommandBuilder(name, sub)
        {}

    private:
        std::string_view _name;
        std::variant<InvokerEntry, SubCommandEntry> _data;
    };

    TC_GAME_API void LoadCommandMap();
    TC_GAME_API void InvalidateCommandMap();
    TC_GAME_API bool TryExecuteCommand(ChatHandler& handler, std::string_view cmd);
    TC_GAME_API void SendCommandHelpFor(ChatHandler& handler, std::string_view cmd);
    TC_GAME_API std::vector<std::string> GetAutoCompletionsFor(ChatHandler const& handler, std::string_view cmd);
}

// backwards compatibility with old patches
using ChatCommand [[deprecated("std::vector<ChatCommand> should be ChatCommandTable! (using namespace Trinity::ChatCommands)")]] = Trinity::ChatCommands::ChatCommandBuilder;

#endif

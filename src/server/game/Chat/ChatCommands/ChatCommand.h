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

#include "ChatCommandArgs.h"
#include "ChatCommandTags.h"
#include "Define.h"
#include "Errors.h"
#include "Language.h"
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
    using ChatCommandTable = ChatCommandBuilder const[];
}

namespace Trinity::Impl::ChatCommands
{
    // forward declaration
    // ConsumeFromOffset contains the bounds check for offset, then hands off to MultiConsumer
    // the call stack is MultiConsumer -> ConsumeFromOffset -> MultiConsumer -> ConsumeFromOffset etc
    // MultiConsumer goes into ArgInfo for parsing on each iteration
    template <typename Tuple, size_t offset>
    void ConsumeFromOffset(ChatCommandResult& result, Tuple&, ChatHandler const* handler, std::string_view args) noexcept;

    template <typename Tuple, typename NextType, size_t offset>
    struct MultiConsumer
    {
        inline static ChatCommandResult TryConsumeTo(Tuple& tuple, ChatHandler const* handler, std::string_view args) noexcept
        {
            ChatCommandResult next = ArgInfo<NextType>::TryConsume(std::get<offset>(tuple), handler, args);
            if (next)
                ConsumeFromOffset<Tuple, offset + 1>(next, tuple, handler, *next);
            return next;
        }
    };

    TC_GAME_API void MergeChatCommandResults(ChatHandler const* handler, ChatCommandResult& result1, ChatCommandResult& result2) noexcept;

    template <typename Tuple, typename NestedNextType, size_t offset>
    struct MultiConsumer<Tuple, Optional<NestedNextType>, offset>
    {
        static ChatCommandResult TryConsumeTo(Tuple& tuple, ChatHandler const* handler, std::string_view args) noexcept
        {
            // try with the argument
            auto& myArg = std::get<offset>(tuple);

            ChatCommandResult result1 = ArgInfo<NestedNextType>::TryConsume(myArg.emplace(), handler, args);
            if (result1)
            {
                ConsumeFromOffset<Tuple, offset + 1>(result1, tuple, handler, *result1);
                if (result1)
                    return result1;
            }

            // try again omitting the argument
            myArg.reset();
            ChatCommandResult result2 = std::nullopt;
            ConsumeFromOffset<Tuple, offset + 1>(result2, tuple, handler, args);
            MergeChatCommandResults(handler, result1, result2);
            return result1;
        }
    };

    template <typename Tuple, size_t offset>
    void ConsumeFromOffset([[maybe_unused]] ChatCommandResult& result, [[maybe_unused]] Tuple& tuple, [[maybe_unused]] ChatHandler const* handler, std::string_view args) noexcept
    {
        if constexpr (offset < std::tuple_size_v<Tuple>)
            result = MultiConsumer<Tuple, std::tuple_element_t<offset, Tuple>, offset>::TryConsumeTo(tuple, handler, args);
        else if (!args.empty()) /* the entire string must be consumed */
            result = std::nullopt;
        else
            result = args;
    }

    template <typename T> struct CommandInvokerTraits { static_assert(Trinity::dependant_false_v<T>, "Invalid command handler signature"); };
    template <typename... Ts> struct CommandInvokerTraits<bool(ChatHandler*, Ts...)>
    {
        using Func = bool(ChatHandler*, Ts...);
        using Refs = std::tuple<Ts...>;
        using Vals = std::tuple<std::remove_cvref_t<Ts>...>;

        static bool Wrapper(void* handler, ChatHandler* chatHandler, std::string_view argsStr) noexcept
        {
            Vals arguments;
            ChatCommandResult result = std::nullopt;
            ConsumeFromOffset<Vals, 0>(result, arguments, chatHandler, argsStr);
            if (result.IsSuccessful())
                return Invoke(reinterpret_cast<Func*>(handler), chatHandler, arguments, std::make_index_sequence<std::tuple_size_v<Vals>>{});

            if (result.HasErrorMessage())
                SendErrorMessageToHandler(chatHandler, result.GetErrorMessage());

            return false;
        }

        template <std::size_t... I>
        inline static constexpr bool Invoke(Func* handler, ChatHandler* chatHandler, Vals& arguments, std::index_sequence<I...>) noexcept
        {
            // Invoke command handler preserving original reference category of each argument
            return handler(chatHandler, std::get<I>(advstd::forward_like<std::tuple_element_t<I, Refs>>(arguments))...);
        }
    };

    template <typename... Ts> struct CommandInvokerTraits<bool(ChatHandler const*, Ts...)> : CommandInvokerTraits<bool(ChatHandler*, Ts...)> { };

    struct CommandInvoker
    {
        CommandInvoker() = default;
        template <typename TypedHandler>
        CommandInvoker(TypedHandler& handler) : _wrapper(&CommandInvokerTraits<TypedHandler>::Wrapper), _handler(reinterpret_cast<void*>(handler)) { }
        CommandInvoker(bool(&handler)(ChatHandler*, char const*)) : _wrapper(&LegacyWrapper), _handler(reinterpret_cast<void*>(handler)) { }

        explicit operator bool() const { return (_wrapper != nullptr); }
        bool operator()(ChatHandler* chatHandler, std::string_view args) const
        {
            ASSERT(_wrapper && _handler);
            return _wrapper(_handler, chatHandler, args);
        }

    private:
        static bool LegacyWrapper(void* handler, ChatHandler* chatHandler, std::string_view argsStr) noexcept
        {
            // make a copy of the argument string
            // legacy handlers can destroy input strings with strtok
            std::string argsStrCopy(argsStr);
            return reinterpret_cast<bool(*)(ChatHandler*, char const*)>(handler)(chatHandler, argsStrCopy.c_str());
        }

        using wrapper_func = std::add_pointer_t<bool(void*, ChatHandler*, std::string_view) noexcept>;
        wrapper_func _wrapper = nullptr;
        void* _handler = nullptr;
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

            ChatCommandNode() = default;
            ~ChatCommandNode() = default;

        private:
            static std::map<std::string_view, ChatCommandNode, StringCompareLessI_T> const& GetTopLevelMap();
            static void LoadCommandsIntoMap(ChatCommandNode* blank, std::map<std::string_view, ChatCommandNode, StringCompareLessI_T>& map, std::span<ChatCommandBuilder const> commands);

            void LoadFromBuilder(ChatCommandBuilder const& builder);
            ChatCommandNode(ChatCommandNode const& other) = delete;
            ChatCommandNode(ChatCommandNode&& other) noexcept = default;
            ChatCommandNode& operator=(ChatCommandNode const& other) = delete;
            ChatCommandNode& operator=(ChatCommandNode&& other) noexcept = default;

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

            Trinity::Impl::ChatCommands::CommandInvoker _invoker;
            TrinityStrings _help;
            Trinity::Impl::ChatCommands::CommandPermissions _permissions;
        };
        using SubCommandEntry = std::span<ChatCommandBuilder const>;

        template <typename TypedHandler>
        ChatCommandBuilder(std::string_view name, TypedHandler& handler, TrinityStrings help, rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
            : _name{ name }, _data{ InvokerEntry { handler, help, permission, allowConsole } }
        {}

        template <typename TypedHandler>
        ChatCommandBuilder(std::string_view name, TypedHandler& handler, rbac::RBACPermissions permission, Trinity::ChatCommands::Console allowConsole)
            : ChatCommandBuilder(name, handler, TrinityStrings(), permission, allowConsole)
        {}
        ChatCommandBuilder(std::string_view name, std::span<ChatCommandBuilder const> subCommands)
            : _name{ name }, _data{ std::in_place_index<1>, subCommands.data(), subCommands.size() }
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
        ChatCommandBuilder(char const* name, rbac::RBACPermissions, bool, std::nullptr_t, char const*, SubCommandEntry sub)
            : ChatCommandBuilder(name, sub)
        {}

    private:
        std::string_view _name;
        std::variant<InvokerEntry, std::pair<ChatCommandBuilder const*, std::size_t> /*workaround: span requires type to be complete*/> _data;
    };

    TC_GAME_API void LoadCommandMap();
    TC_GAME_API void InvalidateCommandMap();
    TC_GAME_API bool TryExecuteCommand(ChatHandler& handler, std::string_view cmd);
    TC_GAME_API void SendCommandHelpFor(ChatHandler& handler, std::string_view cmd);
    TC_GAME_API std::vector<std::string> GetAutoCompletionsFor(ChatHandler const& handler, std::string_view cmd);
}

#endif

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

#include "ChatCommandTags.h"

#include "CharacterCache.h"
#include "Chat.h"
#include "ChatCommandArgs.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"

Optional<std::string_view> Trinity::ChatCommands::QuotedString::TryConsume(std::string_view args)
{
    if (args.empty())
        return std::nullopt;
    if ((args[0] != '"') && (args[0] != '\''))
        return Trinity::Impl::ChatCommands::ArgInfo<std::string>::TryConsume(*this, args);

    char const QUOTE = args[0];
    for (size_t i = 1; i < args.length(); ++i)
    {
        if (args[i] == QUOTE)
        {
            auto [remainingToken, tail] = Trinity::Impl::ChatCommands::tokenize(args.substr(i + 1));
            if (remainingToken.empty()) // if this is not empty, then we did not consume the full token
                return tail;
            else
                return std::nullopt;
        }

        if (args[i] == '\\')
        {
            ++i;
            if (!(i < args.length()))
                break;
        }
        std::string::push_back(args[i]);
    }
    // if we reach this, we did not find a closing quote
    return std::nullopt;
}

Optional<std::string_view> Trinity::ChatCommands::PlayerIdentifier::TryConsume(std::string_view args)
{
    Variant<Hyperlink<player>, std::string_view> name;
    Optional<std::string_view> next = Trinity::Impl::ChatCommands::ArgInfo<decltype(name)>::TryConsume(name, args);
    if (!next)
        return std::nullopt;

    _name = static_cast<std::string_view>(name);
    normalizePlayerName(_name);

    if ((_player = ObjectAccessor::FindPlayerByName(_name)))
        _guid = _player->GetGUID();
    else if (!(_guid = sCharacterCache->GetCharacterGuidByName(_name)))
        return std::nullopt;

    return next;
}

Trinity::ChatCommands::PlayerIdentifier::PlayerIdentifier(Player& player)
    : _name(player.GetName()), _guid(player.GetGUID()), _player(&player) {}

/*static*/ Optional<Trinity::ChatCommands::PlayerIdentifier> Trinity::ChatCommands::PlayerIdentifier::FromTarget(ChatHandler* handler)
{
    if (Player* player = handler->GetPlayer())
        if (Player* target = player->GetSelectedPlayer())
            return { *target };
    return std::nullopt;

}

/*static*/ Optional<Trinity::ChatCommands::PlayerIdentifier> Trinity::ChatCommands::PlayerIdentifier::FromSelf(ChatHandler* handler)
{
    if (Player* player = handler->GetPlayer())
        return { *player };
    return std::nullopt;
}

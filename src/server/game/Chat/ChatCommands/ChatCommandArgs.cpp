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

#include "ChatCommandArgs.h"
#include "AchievementMgr.h"
#include "ChatCommand.h"
#include "ChatCommandHyperlinks.h"
#include "ObjectMgr.h"

using namespace Trinity::ChatCommands;

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> achData) const { return achData->achievement; }
    value_type operator()(uint32 achId) const { return sAchievementMgr->GetAchievement(achId); }
};
char const* Trinity::ChatCommands::ArgInfo<AchievementEntry const*>::TryConsume(AchievementEntry const*& data, char const* args)
{
    Variant <Hyperlink<achievement>, uint32> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::TryConsumeTo(val, args)))
        data = boost::apply_visitor(AchievementVisitor(), val);
    return args;
}

struct GameTeleVisitor
{
    using value_type = GameTele const*;
    value_type operator()(Hyperlink<tele> tele) const { return sObjectMgr->GetGameTele(tele); }
    value_type operator()(std::string const& tele) const { return sObjectMgr->GetGameTele(tele); }
};
char const* Trinity::ChatCommands::ArgInfo<GameTele const*>::TryConsume(GameTele const*& data, char const* args)
{
    Variant<Hyperlink<tele>, std::string> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::TryConsumeTo(val, args)))
        data = boost::apply_visitor(GameTeleVisitor(), val);
    return args;
}

struct BoolVisitor
{
    using value_type = bool;
    value_type operator()(uint32 i) const { return !!i; }
    value_type operator()(ExactSequence<'o', 'n'>) const { return true; }
    value_type operator()(ExactSequence<'o', 'f', 'f'>) const { return false; }
};
char const* Trinity::ChatCommands::ArgInfo<bool>::TryConsume(bool& data, char const* args)
{
    Variant<uint32, ExactSequence<'o', 'n'>, ExactSequence<'o', 'f', 'f'>> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::TryConsumeTo(val, args)))
        data = boost::apply_visitor(BoolVisitor(), val);
    return args;
}

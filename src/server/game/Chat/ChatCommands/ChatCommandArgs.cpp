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
#include "ObjectMgr.h"
#include "SpellMgr.h"

using namespace Trinity::ChatCommands;

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> achData) const { return achData->Achievement; }
    value_type operator()(uint32 achId) const { return sAchievementMgr->GetAchievement(achId); }
};
char const* Trinity::ChatCommands::ArgInfo<AchievementEntry const*>::TryConsume(AchievementEntry const*& data, char const* args)
{
    Variant<Hyperlink<achievement>, uint32> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::TryConsumeTo(val, args)))
        data = val.visit(AchievementVisitor());
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
        data = val.visit(GameTeleVisitor());
    return args;
}

struct SpellInfoVisitor
{
    using value_type = SpellInfo const*;
    value_type operator()(Hyperlink<enchant> enchant) const { return enchant; };
    value_type operator()(Hyperlink<glyph> glyph) const { return operator()(glyph->Glyph->SpellID); };
    value_type operator()(Hyperlink<spell> spell) const { return *spell; }
    value_type operator()(Hyperlink<talent> talent) const
    {
        return operator()(talent->Talent->SpellRank[talent->Rank - 1]);
    };
    value_type operator()(Hyperlink<trade> trade) const { return trade->Spell; };

    value_type operator()(uint32 spellId) const { return sSpellMgr->GetSpellInfo(spellId); }
};
char const* Trinity::ChatCommands::ArgInfo<SpellInfo const*>::TryConsume(SpellInfo const*& data, char const* args)
{
    Variant<Hyperlink<enchant>, Hyperlink<glyph>, Hyperlink<spell>, Hyperlink<talent>, Hyperlink<trade>, uint32> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::TryConsumeTo(val, args)))
        data = val.visit(SpellInfoVisitor());
    return args;
}

char const* Trinity::ChatCommands::ArgInfo<bool>::TryConsume(bool& data, char const* args)
{
    std::string val;
    if ((args = CommandArgsConsumerSingle<std::string>::TryConsumeTo(val, args)))
    {
        strToLower(val);
        if (val == "on" || val == "yes" || val == "true" || val == "1" || val == "y")
            data = true;
        else if (val == "off" || val == "no" || val == "false" || val == "0" || val == "n")
            data = false;
        else
            return nullptr;
    }
    return args;
}

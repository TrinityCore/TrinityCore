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
#include "Util.h"

using namespace Trinity::ChatCommands;

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> achData) const { return achData->Achievement; }
    value_type operator()(uint32 achId) const { return sAchievementMgr->GetAchievement(achId); }
};
Optional<std::string_view> Trinity::Impl::ChatCommands::ArgInfo<AchievementEntry const*>::TryConsume(AchievementEntry const*& data, std::string_view args)
{
    Variant<Hyperlink<achievement>, uint32> val;
    Optional<std::string_view> next = SingleConsumer<decltype(val)>::TryConsumeTo(val, args);
    if (next)
        if ((data = val.visit(AchievementVisitor())))
            return next;
    return std::nullopt;
}

struct GameTeleVisitor
{
    using value_type = GameTele const*;
    value_type operator()(Hyperlink<tele> tele) const { return sObjectMgr->GetGameTele(tele); }
    value_type operator()(std::string const& tele) const { return sObjectMgr->GetGameTele(tele); }
};
Optional<std::string_view> Trinity::Impl::ChatCommands::ArgInfo<GameTele const*>::TryConsume(GameTele const*& data, std::string_view args)
{
    Variant<Hyperlink<tele>, std::string> val;
    Optional<std::string_view> next = SingleConsumer<decltype(val)>::TryConsumeTo(val, args);
    if (next)
        if ((data = val.visit(GameTeleVisitor())))
            return next;
    return std::nullopt;
}

struct ItemTemplateVisitor
{
    using value_type = ItemTemplate const*;
    value_type operator()(Hyperlink<item> item) const { return item->Item; }
    value_type operator()(uint32 item) { return sObjectMgr->GetItemTemplate(item); }
};
Optional<std::string_view> Trinity::Impl::ChatCommands::ArgInfo<ItemTemplate const*>::TryConsume(ItemTemplate const*& data, std::string_view args)
{
    Variant<Hyperlink<item>, uint32> val;
    Optional<std::string_view> next = SingleConsumer<decltype(val)>::TryConsumeTo(val, args);
    if (next)
        if ((data = val.visit(ItemTemplateVisitor())))
            return next;
    return std::nullopt;
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
Optional<std::string_view> Trinity::Impl::ChatCommands::ArgInfo<SpellInfo const*>::TryConsume(SpellInfo const*& data, std::string_view args)
{
    Variant<Hyperlink<enchant>, Hyperlink<glyph>, Hyperlink<spell>, Hyperlink<talent>, Hyperlink<trade>, uint32> val;
    Optional<std::string_view> next = SingleConsumer<decltype(val)>::TryConsumeTo(val, args);
    if (next)
        if ((data = val.visit(SpellInfoVisitor())))
            return next;
    return std::nullopt;
}

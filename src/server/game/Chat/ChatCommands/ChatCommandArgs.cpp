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
using ChatCommandResult = Trinity::Impl::ChatCommands::ChatCommandResult;

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> achData) const { return achData->Achievement; }
    value_type operator()(uint32 achId) const { return sAchievementMgr->GetAchievement(achId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<AchievementEntry const*>::TryConsume(AchievementEntry const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<achievement>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(AchievementVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_ACHIEVEMENT_NO_EXIST, *id);
    return std::nullopt;
}

struct GameTeleVisitor
{
    using value_type = GameTele const*;
    value_type operator()(Hyperlink<tele> tele) const { return sObjectMgr->GetGameTele(tele); }
    value_type operator()(std::string_view tele) const { return sObjectMgr->GetGameTele(tele); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<GameTele const*>::TryConsume(GameTele const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<tele>, std::string_view> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(GameTeleVisitor())))
        return result;
    if (val.holds_alternative<Hyperlink<tele>>())
        return FormatTrinityString(handler, LANG_CMDPARSER_GAME_TELE_ID_NO_EXIST, static_cast<uint32>(std::get<Hyperlink<tele>>(val)));
    else
        return FormatTrinityString(handler, LANG_CMDPARSER_GAME_TELE_NO_EXIST, STRING_VIEW_FMT_ARG(std::get<std::string_view>(val)));
}

struct ItemTemplateVisitor
{
    using value_type = ItemTemplate const*;
    value_type operator()(Hyperlink<item> item) const { return item->Item; }
    value_type operator()(uint32 item) { return sObjectMgr->GetItemTemplate(item); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<ItemTemplate const*>::TryConsume(ItemTemplate const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<item>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(ItemTemplateVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_ITEM_NO_EXIST, *id);
    return std::nullopt;
}

struct QuestVisitor
{
    using value_type = Quest const*;
    value_type operator()(Hyperlink<quest> quest) const { return quest->Quest; }
    value_type operator()(uint32 questId) const { return sObjectMgr->GetQuestTemplate(questId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<Quest const*, void>::TryConsume(Quest const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<quest>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(QuestVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_QUEST_NO_EXIST, *id);
    return std::nullopt;
}

struct SpellInfoVisitor
{
    using value_type = SpellInfo const*;
    value_type operator()(Hyperlink<enchant> enchant) const { return enchant; };
    value_type operator()(Hyperlink<glyph> glyph) const { return operator()(glyph->Glyph->SpellID); };
    value_type operator()(Hyperlink<spell> spell) const { return *spell; }
    value_type operator()(Hyperlink<talent> talent) const { return talent->Spell; };
    value_type operator()(Hyperlink<trade> trade) const { return trade->Spell; };

    value_type operator()(uint32 spellId) const { return sSpellMgr->GetSpellInfo(spellId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<SpellInfo const*>::TryConsume(SpellInfo const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<enchant>, Hyperlink<glyph>, Hyperlink<spell>, Hyperlink<talent>, Hyperlink<trade>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(SpellInfoVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_SPELL_NO_EXIST, *id);
    return std::nullopt;
}

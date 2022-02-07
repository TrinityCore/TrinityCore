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
#include "ChatCommand.h"
#include "DB2Stores.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Util.h"

using namespace Trinity::ChatCommands;
using ChatCommandResult = Trinity::Impl::ChatCommands::ChatCommandResult;

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> achData) const { return achData->Achievement; }
    value_type operator()(uint32 achId) const { return sAchievementStore.LookupEntry(achId); }
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

struct CurrencyTypesVisitor
{
    using value_type = CurrencyTypesEntry const*;
    value_type operator()(Hyperlink<currency> currency) const { return currency->Currency; }
    value_type operator()(uint32 currencyId) const { return sCurrencyTypesStore.LookupEntry(currencyId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<CurrencyTypesEntry const*>::TryConsume(CurrencyTypesEntry const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<currency>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(CurrencyTypesVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_CURRENCY_NO_EXIST, *id);
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
    value_type operator()(uint32 item) const { return sObjectMgr->GetItemTemplate(item); }
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

struct SpellInfoVisitor
{
    using value_type = SpellInfo const*;

    value_type operator()(Hyperlink<apower> artifactPower) const { return operator()(artifactPower->ArtifactPower->SpellID); }
    value_type operator()(Hyperlink<conduit> soulbindConduit) const { return operator()((*soulbindConduit)->SpellID); }
    value_type operator()(Hyperlink<enchant> enchant) const { return enchant; }
    value_type operator()(Hyperlink<mawpower> mawPower) const { return operator()((*mawPower)->SpellID); }
    value_type operator()(Hyperlink<pvptal> pvpTalent) const { return operator()((*pvpTalent)->SpellID); }
    value_type operator()(Hyperlink<spell> spell) const { return spell->Spell; }
    value_type operator()(Hyperlink<talent> talent) const { return operator()((*talent)->SpellID); }
    value_type operator()(Hyperlink<trade> trade) const { return trade->Spell; }

    value_type operator()(uint32 spellId) const { return sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<SpellInfo const*>::TryConsume(SpellInfo const*& data, ChatHandler const* handler, std::string_view args)
{
    Variant<Hyperlink<apower>, Hyperlink<conduit>, Hyperlink<enchant>, Hyperlink<mawpower>, Hyperlink<pvptal>, Hyperlink<spell>, Hyperlink<talent>, Hyperlink<trade>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(SpellInfoVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        return FormatTrinityString(handler, LANG_CMDPARSER_SPELL_NO_EXIST, *id);
    return std::nullopt;
}

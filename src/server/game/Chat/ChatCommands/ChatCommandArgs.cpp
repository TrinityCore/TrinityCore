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
#include "MapUtils.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"

using namespace Trinity::ChatCommands;
using ChatCommandResult = Trinity::Impl::ChatCommands::ChatCommandResult;

void Trinity::Impl::ChatCommands::InvalidStringValueFormatError(ChatCommandResult& result, ChatHandler const* handler, std::string_view arg, std::type_info const& type) noexcept
{
    result = FormatTrinityString(handler, LANG_CMDPARSER_STRING_VALUE_INVALID, STRING_VIEW_FMT_ARG(arg), Trinity::GetTypeName(type).c_str());
}

void Trinity::Impl::ChatCommands::EnumArgInfoBase::AddSearchMapEntry(SearchMap& map, int64 val, EnumText const& text) noexcept
{
    std::string_view title(text.Title);
    std::string_view constant(text.Constant);

    StringCompareLessI_T compare;

    auto constantIt = std::ranges::lower_bound(map, constant, compare, Containers::MapKey);
    if (constantIt == map.end() || compare(constant, constantIt->first))
        map.emplace(constantIt, constant, val);  // not unique
    else
        constantIt->second = std::nullopt;

    if (title != constant)
    {
        auto titleIt = std::ranges::lower_bound(map, title, compare, Containers::MapKey);
        if (titleIt == map.end() || compare(title, titleIt->first))
            map.emplace(titleIt, title, val);  // not unique
        else
            titleIt->second = std::nullopt;
    }
}

int64 const* Trinity::Impl::ChatCommands::EnumArgInfoBase::Match(SearchMap const& map, std::string_view s) noexcept
{
    auto it = std::ranges::lower_bound(map, s, StringCompareLessI_T(), Containers::MapKey);
    auto end = map.end();
    if (it == end || !StringStartsWithI(it->first, s)) // not a match
        return nullptr;

    if (!StringEqualI(it->first, s)) // we don't have an exact match - check if it is unique
    {
        auto it2 = it;
        ++it2;
        if (it2 != end && StringStartsWithI(it2->first, s)) // not unique
            return nullptr;
    }

    if (it->second)
        return &*it->second;
    else
        return nullptr;
}

bool Trinity::Impl::ChatCommands::HandleVariantChatCommandConsumeResults(ChatCommandResult& combined, ChatCommandResult&& current, ChatHandler const* handler) noexcept
{
    if (!current.IsSuccessful())
    {
        if (current.HasErrorMessage())
        {
            if (combined.HasErrorMessage())
            {
                std::string mergedError = std::move(combined).GetErrorMessage();
                mergedError.append(1, '\n');
                mergedError.append(GetTrinityString(handler, LANG_CMDPARSER_OR));
                mergedError.append(1, ' ');
                mergedError.append(current.GetErrorMessage());
                combined = std::move(mergedError);
            }
            else
                combined = std::move(current).GetErrorMessage();
        }

        return false;
    }

    combined = *current;
    return true;
}

void Trinity::Impl::ChatCommands::PrefixVariantChatCommandError(ChatCommandResult& combined, ChatHandler const* handler) noexcept
{
    if (combined.HasErrorMessage() && combined.GetErrorMessage().find('\n') != std::string::npos)
    {
        std::string error = std::string(GetTrinityString(handler, LANG_CMDPARSER_EITHER))
            .append(1, ' ')
            .append(combined.GetErrorMessage());
        combined = std::move(error);
    }
}

struct AchievementVisitor
{
    using value_type = AchievementEntry const*;
    value_type operator()(Hyperlink<achievement> const& achData) const { return achData->Achievement; }
    value_type operator()(uint32 achId) const { return sAchievementStore.LookupEntry(achId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<AchievementEntry const*>::TryConsume(AchievementEntry const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<achievement>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(AchievementVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        result = FormatTrinityString(handler, LANG_CMDPARSER_ACHIEVEMENT_NO_EXIST, *id);
    else
        result = std::nullopt;
    return result;
}

struct CurrencyTypesVisitor
{
    using value_type = CurrencyTypesEntry const*;
    value_type operator()(Hyperlink<currency> currency) const { return currency->Currency; }
    value_type operator()(uint32 currencyId) const { return sCurrencyTypesStore.LookupEntry(currencyId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<CurrencyTypesEntry const*>::TryConsume(CurrencyTypesEntry const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<currency>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(CurrencyTypesVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        result = FormatTrinityString(handler, LANG_CMDPARSER_CURRENCY_NO_EXIST, *id);
    else
        result = std::nullopt;
    return result;
}

struct GameTeleVisitor
{
    using value_type = GameTele const*;
    value_type operator()(Hyperlink<tele> tele) const { return sObjectMgr->GetGameTele(tele); }
    value_type operator()(std::string_view tele) const { return sObjectMgr->GetGameTele(tele); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<GameTele const*>::TryConsume(GameTele const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<tele>, std::string_view> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(GameTeleVisitor())))
        return result;
    if (val.holds_alternative<Hyperlink<tele>>())
        result = FormatTrinityString(handler, LANG_CMDPARSER_GAME_TELE_ID_NO_EXIST, static_cast<uint32>(std::get<Hyperlink<tele>>(val)));
    else
        result = FormatTrinityString(handler, LANG_CMDPARSER_GAME_TELE_NO_EXIST, STRING_VIEW_FMT_ARG(std::get<std::string_view>(val)));
    return result;
}

struct ItemTemplateVisitor
{
    using value_type = ItemTemplate const*;
    value_type operator()(Hyperlink<item> const& item) const { return item->Item; }
    value_type operator()(uint32 item) const { return sObjectMgr->GetItemTemplate(item); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<ItemTemplate const*>::TryConsume(ItemTemplate const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<item>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(ItemTemplateVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        result = FormatTrinityString(handler, LANG_CMDPARSER_ITEM_NO_EXIST, *id);
    else
        result = std::nullopt;
    return result;
}

struct QuestVisitor
{
    using value_type = Quest const*;
    value_type operator()(Hyperlink<quest> quest) const { return quest->Quest; }
    value_type operator()(uint32 questId) const { return sObjectMgr->GetQuestTemplate(questId); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<Quest const*>::TryConsume(Quest const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<quest>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(QuestVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        result = FormatTrinityString(handler, LANG_CMDPARSER_QUEST_NO_EXIST, *id);
    else
        result = std::nullopt;
    return result;
}

struct SpellInfoVisitor
{
    using value_type = SpellInfo const*;

    value_type operator()(Hyperlink<apower> artifactPower) const { return operator()(artifactPower->ArtifactPower->SpellID); }
    value_type operator()(Hyperlink<conduit> soulbindConduit) const { return operator()((*soulbindConduit)->SpellID); }
    value_type operator()(Hyperlink<enchant> enchant) const { return enchant; }
    value_type operator()(Hyperlink<mawpower> mawPower) const { return operator()((*mawPower)->SpellID); }
    value_type operator()(Hyperlink<mount> const& mount) const { return mount->Spell; }
    value_type operator()(Hyperlink<pvptal> pvpTalent) const { return operator()((*pvpTalent)->SpellID); }
    value_type operator()(Hyperlink<spell> spell) const { return spell->Spell; }
    value_type operator()(Hyperlink<talent> talent) const { return operator()((*talent)->SpellID); }
    value_type operator()(Hyperlink<trade> const& trade) const { return trade->Spell; }

    value_type operator()(uint32 spellId) const { return sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE); }
};
ChatCommandResult Trinity::Impl::ChatCommands::ArgInfo<SpellInfo const*>::TryConsume(SpellInfo const*& data, ChatHandler const* handler, std::string_view args) noexcept
{
    Variant<Hyperlink<apower>, Hyperlink<conduit>, Hyperlink<enchant>, Hyperlink<mawpower>, Hyperlink<mount>, Hyperlink<pvptal>, Hyperlink<spell>, Hyperlink<talent>, Hyperlink<trade>, uint32> val;
    ChatCommandResult result = ArgInfo<decltype(val)>::TryConsume(val, handler, args);
    if (!result || (data = val.visit(SpellInfoVisitor())))
        return result;
    if (uint32* id = std::get_if<uint32>(&val))
        result = FormatTrinityString(handler, LANG_CMDPARSER_SPELL_NO_EXIST, *id);
    else
        result = std::nullopt;
    return result;
}

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

#include "Hyperlinks.h"
#include "Common.h"
#include "DB2Stores.h"
#include "Errors.h"
#include "ItemTemplate.h"
#include "ObjectMgr.h"
#include "QuestDef.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "StringFormat.h"
#include "World.h"

using namespace Trinity::Hyperlinks;

inline uint8 toHex(char c) { return (c >= '0' && c <= '9') ? c - '0' + 0x10 : (c >= 'a' && c <= 'f') ? c - 'a' + 0x1a : 0x00; }
// Validates a single hyperlink
HyperlinkInfo Trinity::Hyperlinks::ParseSingleHyperlink(std::string_view str)
{
    uint32 color = 0;
    std::string_view tag;
    std::string_view data;
    std::string_view text;

    //color tag
    if (str.substr(0, 2) != "|c")
        return {};
    str.remove_prefix(2);

    if (str.length() < 8)
        return {};

    for (uint8 i = 0; i < 8; ++i)
    {
        if (uint8 hex = toHex(str[i]))
            color = (color << 4) | (hex & 0xf);
        else
            return {};
    }
    str.remove_prefix(8);

    if (str.substr(0, 2) != "|H")
        return {};
    str.remove_prefix(2);

    // tag+data part follows
    if (size_t delimPos = str.find('|'); delimPos != std::string_view::npos)
    {
        tag = str.substr(0, delimPos);
        str.remove_prefix(delimPos+1);
    }
    else
        return {};

    // split tag if : is present (data separator)
    if (size_t dataStart = tag.find(':'); dataStart != std::string_view::npos)
    {
        data = tag.substr(dataStart+1);
        tag = tag.substr(0, dataStart);
    }

    // ok, next should be link data end tag...
    if (str.substr(0, 1) != "h")
        return {};
    str.remove_prefix(1);
    // skip to final |
    if (size_t end = str.find('|'); end != std::string_view::npos)
    {
        // check end tag
        if (str.substr(end, 4) != "|h|r")
            return {};
        // check text brackets
        if ((str[0] != '[') || (str[end - 1] != ']'))
            return {};
        text = str.substr(1, end - 2);
        // tail
        str = str.substr(end + 4);
    }
    else
        return {};

    // ok, valid hyperlink, return info
    return { str, color, tag, data, text };
}

template <typename T>
struct LinkValidator
{
    static bool IsTextValid(typename T::value_type, std::string_view) { return true; }
    static bool IsColorValid(typename T::value_type, HyperlinkColor) { return true; }
};

static bool IsCreatureNameValid(uint32 creatureId, std::string_view text)
{
    if (CreatureTemplate const* creatureTemplate = sObjectMgr->GetCreatureTemplate(creatureId))
    {
        CreatureLocale const* locale = sObjectMgr->GetCreatureLocale(creatureId);
        if (!locale)
            return creatureTemplate->Name == text;

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            std::string const& name = (i == DEFAULT_LOCALE) ? creatureTemplate->Name : locale->Name[i];
            if (name.empty())
                continue;
            if (name == text)
                return true;
        }
    }

    return false;
}

template <>
struct LinkValidator<LinkTags::spell>
{
    static bool IsTextValid(SpellLinkData const& data, std::string_view text)
    {
        return IsTextValid(data.Spell, text);
    }

    static bool IsTextValid(SpellInfo const* info, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if ((*info->SpellName)[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(SpellLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_SPELL;
    }
};

template <>
struct LinkValidator<LinkTags::achievement>
{
    static bool IsTextValid(AchievementLinkData const& data, std::string_view text)
    {
        if (text.empty())
            return false;
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (text == data.Achievement->Title[i])
                return true;
        return false;
    }

    static bool IsColorValid(AchievementLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_ACHIEVEMENT;
    }
};

template <>
struct LinkValidator<LinkTags::apower>
{
    static bool IsTextValid(ArtifactPowerLinkData const& data, std::string_view text)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.ArtifactPower->SpellID, DIFFICULTY_NONE))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, text);
        return false;
    }

    static bool IsColorValid(ArtifactPowerLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_ARTIFACT_POWER;
    }
};

template <>
struct LinkValidator<LinkTags::azessence>
{
    static bool IsTextValid(AzeriteEssenceLinkData const& data, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (data.Essence->Name[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(AzeriteEssenceLinkData const& data, HyperlinkColor c)
    {
        return c == ItemQualityColors[data.Rank + 1];
    }
};

template <>
struct LinkValidator<LinkTags::battlepet>
{
    static bool IsTextValid(BattlePetLinkData const& data, std::string_view text)
    {
        return IsCreatureNameValid(data.Species->CreatureID, text);
    }

    static bool IsColorValid(BattlePetLinkData const& data, HyperlinkColor c)
    {
        return c == ItemQualityColors[data.Quality];
    }
};

template <>
struct LinkValidator<LinkTags::battlePetAbil>
{
    static bool IsTextValid(BattlePetAbilLinkData const& data, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (data.Ability->Name[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(BattlePetAbilLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_BATTLE_PET_ABIL;
    }
};

template <>
struct LinkValidator<LinkTags::currency>
{
    static bool IsTextValid(CurrencyLinkData const& data, std::string_view text)
    {
        LocalizedString const* name = data.Container ? &data.Container->ContainerName : &data.Currency->Name;
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if ((*name)[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(CurrencyLinkData const& data, HyperlinkColor c)
    {
        return c == ItemQualityColors[(data.Container ? data.Container->ContainerQuality : data.Currency->Quality)];
    }
};

template <>
struct LinkValidator<LinkTags::enchant>
{
    static bool IsTextValid(SpellInfo const* info, std::string_view text)
    {
        if (LinkValidator<LinkTags::spell>::IsTextValid(info, text))
            return true;
        SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(info->Id);
        if (bounds.first == bounds.second)
            return false;

        for (auto pair = bounds.first; pair != bounds.second; ++pair)
        {
            SkillLineEntry const* skill = sSkillLineStore.LookupEntry(pair->second->SkillupSkillLineID
                ? pair->second->SkillupSkillLineID
                : pair->second->SkillLine);
            if (!skill)
                return false;

            for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            {
                std::string_view skillName = skill->DisplayName[i];
                std::string_view spellName = (*info->SpellName)[i];
                if ((text.length() == (skillName.length() + 2 + spellName.length())) &&
                    (text.substr(0, skillName.length()) == skillName) &&
                    (text.substr(skillName.length(), 2) == ": ") &&
                    (text.substr(skillName.length() + 2) == spellName))
                    return true;
            }
        }
        return false;
    }

    static bool IsColorValid(SpellInfo const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_ENCHANT;
    }
};

template <>
struct LinkValidator<LinkTags::garrfollower>
{
    static bool IsTextValid(GarrisonFollowerLinkData const& data, std::string_view text)
    {
        return IsCreatureNameValid(data.Follower->HordeCreatureID, text)
            || IsCreatureNameValid(data.Follower->AllianceCreatureID, text);
    }

    static bool IsColorValid(GarrisonFollowerLinkData const& data, HyperlinkColor c)
    {
        return c == ItemQualityColors[data.Quality];
    }
};

template <>
struct LinkValidator<LinkTags::garrfollowerability>
{
    static bool IsTextValid(GarrAbilityEntry const* ability, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (ability->Name[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(GarrAbilityEntry const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_GARR_ABILITY;
    }
};

template <>
struct LinkValidator<LinkTags::garrmission>
{
    static bool IsTextValid(GarrisonMissionLinkData const& data, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (data.Mission->Name[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(GarrisonMissionLinkData const&, HyperlinkColor c)
    {
        return c == QuestDifficultyColors[2];
    }
};

template <>
struct LinkValidator<LinkTags::instancelock>
{
    static bool IsTextValid(InstanceLockLinkData const& data, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if (data.Map->MapName[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(InstanceLockLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_INSTANCE_LOCK;
    }
};

template <>
struct LinkValidator<LinkTags::item>
{
    static bool IsTextValid(ItemLinkData const& data, std::string_view text)
    {
        LocalizedString const* suffixStrings = nullptr;
        if (!data.Item->HasFlag(ITEM_FLAG3_HIDE_NAME_SUFFIX) && data.Suffix)
            suffixStrings = &data.Suffix->Description;

        return IsTextValid(data.Item, suffixStrings, text);
    }

    static bool IsTextValid(ItemTemplate const* itemTemplate, LocalizedString const* suffixStrings, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
        {
            std::string_view name = itemTemplate->GetName(i);
            if (name.empty())
                continue;
            if (suffixStrings)
            {
                std::string_view suffix = (*suffixStrings)[i];
                if (
                    (!suffix.empty()) &&
                    (text.length() == (name.length() + 1 + suffix.length())) &&
                    (text.substr(0, name.length()) == name) &&
                    (text[name.length()] == ' ') &&
                    (text.substr(name.length() + 1) == suffix)
                    )
                    return true;
            }
            else if (text == name)
                return true;
        }
        return false;
    }

    static bool IsColorValid(ItemLinkData const& data, HyperlinkColor c)
    {
        return c == ItemQualityColors[data.Quality];
    }
};

template <>
struct LinkValidator<LinkTags::journal>
{
    static bool IsTextValid(JournalLinkData const& data, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
            if ((*data.ExpectedText)[i] == text)
                return true;
        return false;
    }

    static bool IsColorValid(JournalLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_JOURNAL;
    }
};

template <>
struct LinkValidator<LinkTags::keystone>
{
    static bool IsTextValid(KeystoneLinkData const& data, std::string_view text)
    {
        // Skip "Keystone" prefix - not loading GlobalStrings.db2
        size_t validateStartPos = text.find(": ");
        if (validateStartPos == std::string_view::npos)
            return false;

        text.remove_prefix(validateStartPos);
        text.remove_prefix(2); // skip ": " too

        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
        {
            std::string expectedText = Trinity::StringFormat("{} ({})", data.Map->Name[i], data.Level);
            if (expectedText == text)
                return true;
        }
        return false;
    }

    static bool IsColorValid(KeystoneLinkData const&, HyperlinkColor c)
    {
        return c == ItemQualityColors[ITEM_QUALITY_EPIC];
    }
};

template <>
struct LinkValidator<LinkTags::quest>
{
    static bool IsTextValid(QuestLinkData const& data, std::string_view text)
    {
        if (text.empty())
            return false;

        if (text == data.Quest->GetLogTitle())
            return true;

        QuestTemplateLocale const* locale = sObjectMgr->GetQuestLocale(data.Quest->GetQuestId());
        if (!locale)
            return false;

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (i == DEFAULT_LOCALE)
                continue;

            std::string_view name = ObjectMgr::GetLocaleString(locale->LogTitle, LocaleConstant(i));
            if (!name.empty() && (text == name))
                return true;
        }

        return false;
    }

    static bool IsColorValid(QuestLinkData const&, HyperlinkColor c)
    {
        for (uint8 i = 0; i < MAX_QUEST_DIFFICULTY; ++i)
            if (c == QuestDifficultyColors[i])
                return true;
        return false;
    }
};

template <>
struct LinkValidator<LinkTags::mount>
{
    static bool IsTextValid(MountLinkData const& data, std::string_view text)
    {
        return LinkValidator<LinkTags::spell>::IsTextValid(data.Spell, text);
    }

    static bool IsColorValid(MountLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_SPELL;
    }
};

template <>
struct LinkValidator<LinkTags::outfit>
{
    static bool IsTextValid(std::string_view, std::string_view)
    {
        return true;
    }

    static bool IsColorValid(std::string_view, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TRANSMOG;
    }
};

template <>
struct LinkValidator<LinkTags::pvptal>
{
    static bool IsTextValid(PvpTalentEntry const* pvpTalent, std::string_view text)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(pvpTalent->SpellID, DIFFICULTY_NONE))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, text);
        return false;
    }

    static bool IsColorValid(PvpTalentEntry const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TALENT;
    }
};

template <>
struct LinkValidator<LinkTags::talent>
{
    static bool IsTextValid(TalentEntry const* talent, std::string_view text)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(talent->SpellID, DIFFICULTY_NONE))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, text);
        return false;
    }

    static bool IsColorValid(TalentEntry const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TALENT;
    }
};

template <>
struct LinkValidator<LinkTags::trade>
{
    static bool IsTextValid(TradeskillLinkData const& data, std::string_view text)
    {
        return LinkValidator<LinkTags::spell>::IsTextValid(data.Spell, text);
    }

    static bool IsColorValid(TradeskillLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TRADE;
    }
};

template <>
struct LinkValidator<LinkTags::transmogappearance>
{
    static bool IsTextValid(ItemModifiedAppearanceEntry const* enchantment, std::string_view text)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(enchantment->ItemID))
            return LinkValidator<LinkTags::item>::IsTextValid(itemTemplate, nullptr, text);
        return false;
    }

    static bool IsColorValid(ItemModifiedAppearanceEntry const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TRANSMOG;
    }
};

template <>
struct LinkValidator<LinkTags::transmogset>
{
    static bool IsTextValid(TransmogSetEntry const* set, std::string_view text)
    {
        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
        {
            if (ItemNameDescriptionEntry const* itemNameDescription = sItemNameDescriptionStore.LookupEntry(set->ItemNameDescriptionID))
            {
                std::string expectedText = Trinity::StringFormat("{} ({})", set->Name[i], itemNameDescription->Description[i]);
                if (expectedText.c_str() == text)
                    return true;
            }
            else if (set->Name[i] == text)
                return true;
        }
        return false;
    }

    static bool IsColorValid(TransmogSetEntry const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TRANSMOG;
    }
};

template <>
struct LinkValidator<LinkTags::worldmap>
{
    static bool IsTextValid(WorldMapLinkData const&, std::string_view)
    {
        return true;
    }

    static bool IsColorValid(WorldMapLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_ACHIEVEMENT;
    }
};

template <typename TAG>
static bool ValidateAs(HyperlinkInfo const& info)
{
    std::decay_t<typename TAG::value_type> t;
    if (!TAG::StoreTo(t, info.data))
        return false;

    int32 const severity = static_cast<int32>(sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY));
    if (severity >= 0)
    {
        if (!LinkValidator<TAG>::IsColorValid(t, info.color))
            return false;
        if (severity >= 1)
        {
            if (!LinkValidator<TAG>::IsTextValid(t, info.text))
                return false;
        }
    }
    return true;
}

#define TryValidateAs(T) do { if (info.tag == T::tag()) return ValidateAs<T>(info); } while (0)

static bool ValidateLinkInfo(HyperlinkInfo const& info)
{
    using namespace LinkTags;
    TryValidateAs(achievement);
    TryValidateAs(api);
    TryValidateAs(apower);
    TryValidateAs(azessence);
    TryValidateAs(area);
    TryValidateAs(areatrigger);
    TryValidateAs(battlepet);
    TryValidateAs(battlePetAbil);
    TryValidateAs(clubFinder);
    TryValidateAs(clubTicket);
    TryValidateAs(creature);
    TryValidateAs(creature_entry);
    TryValidateAs(currency);
    TryValidateAs(dungeonScore);
    TryValidateAs(enchant);
    TryValidateAs(gameevent);
    TryValidateAs(gameobject);
    TryValidateAs(gameobject_entry);
    TryValidateAs(garrfollower);
    TryValidateAs(garrfollowerability);
    TryValidateAs(garrmission);
    TryValidateAs(instancelock);
    TryValidateAs(item);
    TryValidateAs(itemset);
    TryValidateAs(journal);
    TryValidateAs(keystone);
    TryValidateAs(mount);
    TryValidateAs(outfit);
    TryValidateAs(player);
    TryValidateAs(pvptal);
    TryValidateAs(quest);
    TryValidateAs(skill);
    TryValidateAs(spell);
    TryValidateAs(talent);
    TryValidateAs(talentbuild);
    TryValidateAs(taxinode);
    TryValidateAs(tele);
    TryValidateAs(title);
    TryValidateAs(trade);
    TryValidateAs(transmogappearance);
    TryValidateAs(transmogset);
    TryValidateAs(worldmap);
    return false;
}

// Validates all hyperlinks and control sequences contained in str
bool Trinity::Hyperlinks::CheckAllLinks(std::string_view str)
{
    // Step 1: Disallow all control sequences except ||, |H, |h, |c and |r
    {
        std::string_view::size_type pos = 0;
        while ((pos = str.find('|', pos)) != std::string::npos)
        {
            ++pos;
            if (pos == str.length())
                return false;
            char next = str[pos];
            if (next == 'H' || next == 'h' || next == 'c' || next == 'r' || next == '|')
                ++pos;
            else
                return false;
        }
    }

    // Step 2: Parse all link sequences
    // They look like this: |c<color>|H<linktag>:<linkdata>|h[<linktext>]|h|r
    // - <color> is 8 hex characters AARRGGBB
    // - <linktag> is arbitrary length [a-z_]
    // - <linkdata> is arbitrary length, no | contained
    // - <linktext> is printable
    {
        std::string::size_type pos;
        while ((pos = str.find('|')) != std::string::npos)
        {
            if (str[pos + 1] == '|') // this is an escaped pipe character (||)
            {
                str = str.substr(pos + 2);
                continue;
            }

            HyperlinkInfo info = ParseSingleHyperlink(str.substr(pos));
            if (!info || !ValidateLinkInfo(info))
                return false;

            // tag is fine, find the next one
            str = info.tail;
        }
    }

    // all tags are valid
    return true;
}

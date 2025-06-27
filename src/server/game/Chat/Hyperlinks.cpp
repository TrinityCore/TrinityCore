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
#include "advstd.h"
#include "Common.h"
#include "DBCStores.h"
#include "Errors.h"
#include "ObjectMgr.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "QuestDef.h"
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

template <>
struct LinkValidator<LinkTags::achievement>
{
    static bool IsTextValid(AchievementLinkData const& data, std::string_view text)
    {
        if (text.empty())
            return false;
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
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
struct LinkValidator<LinkTags::item>
{
    static bool IsTextValid(ItemLinkData const& data, std::string_view text)
    {
        ItemLocale const* locale = sObjectMgr->GetItemLocale(data.Item->ItemId);

        std::array<char const*, 16> const* randomSuffixes = nullptr;
        if (data.RandomProperty)
            randomSuffixes = &data.RandomProperty->Name;
        else if (data.RandomSuffix)
            randomSuffixes = &data.RandomSuffix->Name;

        if (data.IsBuggedInspectLink) /* DBC lookup will have failed on the client, so the link should've arrived without suffix */
            randomSuffixes = nullptr;

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (!locale && i != DEFAULT_LOCALE)
                continue;
            std::string_view name = (i == DEFAULT_LOCALE) ? data.Item->Name1 : ObjectMgr::GetLocaleString(locale->Name, i);
            if (name.empty())
                continue;
            if (randomSuffixes)
            {
                std::string_view randomSuffix((*randomSuffixes)[i]);
                if (
                  (!randomSuffix.empty()) &&
                  (text.length() == (name.length() + 1 + randomSuffix.length())) &&
                  (text.substr(0, name.length()) == name) &&
                  (text[name.length()] == ' ') &&
                  (text.substr(name.length() + 1) == randomSuffix)
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
        return c == ItemQualityColors[data.Item->Quality];
    }
};

template <>
struct LinkValidator<LinkTags::quest>
{
    static bool IsTextValid(QuestLinkData const& data, std::string_view text)
    {
        if (text.empty())
            return false;

        if (text == data.Quest->GetTitle())
            return true;

        QuestLocale const* locale = sObjectMgr->GetQuestLocale(data.Quest->GetQuestId());
        if (!locale)
            return false;

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (i == DEFAULT_LOCALE)
                continue;

            std::string_view name = ObjectMgr::GetLocaleString(locale->Title, i);
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
struct LinkValidator<LinkTags::spell>
{
    static bool IsTextValid(SpellInfo const* info, std::string_view text)
    {
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            if (text == info->SpellName[i])
                return true;
        return false;
    }

    static bool IsColorValid(SpellInfo const*, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_SPELL;
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
            SkillLineEntry const* skill = sSkillLineStore.LookupEntry(pair->second->SkillLine);
            if (!skill)
                return false;

            for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            {
                std::string_view skillName = skill->DisplayName[i];
                std::string_view spellName = info->SpellName[i];
                // alternate form [Skill Name: Spell Name]
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
struct LinkValidator<LinkTags::glyph>
{
    static bool IsTextValid(GlyphLinkData const& data, std::string_view text)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.Glyph->SpellID))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, text);
        return false;
    }

    static bool IsColorValid(GlyphLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_GLYPH;
    }
};

template <>
struct LinkValidator<LinkTags::talent>
{
    static bool IsTextValid(TalentLinkData const& data, std::string_view text)
    {
        SpellInfo const* info = data.Spell;
        if (!info)
            info = sSpellMgr->GetSpellInfo(data.Talent->SpellRank[0]);
        if (!info)
            return false;
        return LinkValidator<LinkTags::spell>::IsTextValid(info, text);
    }

    static bool IsColorValid(TalentLinkData const&, HyperlinkColor c)
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

#define TryValidateAs(T) do { if (info.tag == T::tag()) return ValidateAs<T>(info); } while (0);

static bool ValidateLinkInfo(HyperlinkInfo const& info)
{
    using namespace LinkTags;
    TryValidateAs(achievement);
    TryValidateAs(area);
    TryValidateAs(areatrigger);
    TryValidateAs(creature);
    TryValidateAs(creature_entry);
    TryValidateAs(enchant);
    TryValidateAs(gameevent);
    TryValidateAs(gameobject);
    TryValidateAs(gameobject_entry);
    TryValidateAs(glyph);
    TryValidateAs(item);
    TryValidateAs(itemset);
    TryValidateAs(player);
    TryValidateAs(quest);
    TryValidateAs(skill);
    TryValidateAs(spell);
    TryValidateAs(talent);
    TryValidateAs(taxinode);
    TryValidateAs(tele);
    TryValidateAs(title);
    TryValidateAs(trade);
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

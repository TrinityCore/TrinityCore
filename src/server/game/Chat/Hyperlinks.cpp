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
HyperlinkInfo Trinity::Hyperlinks::ParseHyperlink(char const* pos)
{
    //color tag
    if (*(pos++) != '|' || *(pos++) != 'c')
        return nullptr;
    uint32 color = 0;
    for (uint8 i = 0; i < 8; ++i)
    {
        if (uint8 hex = toHex(*(pos++)))
            color = (color << 4) | (hex & 0xf);
        else
            return nullptr;
    }
    // link data start tag
    if (*(pos++) != '|' || *(pos++) != 'H')
        return nullptr;
    // link tag, find next : or |
    char const* tagStart = pos;
    size_t tagLength = 0;
    while (*pos && *pos != '|' && *(pos++) != ':') // we only advance pointer to one past if the last thing is : (not for |), this is intentional!
        ++tagLength;
    // ok, link data, skip to next |
    char const* dataStart = pos;
    size_t dataLength = 0;
    while (*pos && *(pos++) != '|')
        ++dataLength;
    // ok, next should be link data end tag...
    if (*(pos++) != 'h')
        return nullptr;
    // then visible link text, starts with [
    if (*(pos++) != '[')
        return nullptr;
    // skip until we hit the next ], abort on unexpected |
    char const* textStart = pos;
    size_t textLength = 0;
    while (*pos)
    {
        if (*pos == '|')
            return nullptr;
        if (*(pos++) == ']')
            break;
        ++textLength;
    }
    // link end tag
    if (*(pos++) != '|' || *(pos++) != 'h' || *(pos++) != '|' || *(pos++) != 'r')
        return nullptr;
    // ok, valid hyperlink, return info
    return { pos, color, tagStart, tagLength, dataStart, dataLength, textStart, textLength };
}

template <typename T>
struct LinkValidator
{
    static bool IsTextValid(typename T::value_type, char const*, size_t) { return true; }
    static bool IsColorValid(typename T::value_type, HyperlinkColor) { return true; }
};

// str1 is null-terminated, str2 is length-terminated, check if they are exactly equal
static bool equal_with_len(char const* str1, char const* str2, size_t len)
{
    if (!*str1)
        return false;
    while (len && *str1 && *(str1++) == *(str2++))
        --len;
    return !len && !*str1;
}

template <>
struct LinkValidator<LinkTags::achievement>
{
    static bool IsTextValid(AchievementLinkData const& data, char const* pos, size_t len)
    {
        if (!len)
            return false;
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            if (equal_with_len(data.Achievement->Title[i], pos, len))
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
    static bool IsTextValid(ItemLinkData const& data, char const* pos, size_t len)
    {
        ItemLocale const* locale = sObjectMgr->GetItemLocale(data.Item->ItemId);

        char const* const* randomSuffix = nullptr;
        if (data.RandomPropertyId < 0)
        {
            if (ItemRandomSuffixEntry const* suffixEntry = sItemRandomSuffixStore.LookupEntry(-data.RandomPropertyId))
                randomSuffix = suffixEntry->nameSuffix;
            else
                return false;
        }
        else if (data.RandomPropertyId > 0)
        {
            if (ItemRandomPropertiesEntry const* propEntry = sItemRandomPropertiesStore.LookupEntry(data.RandomPropertyId))
                randomSuffix = propEntry->nameSuffix;
            else
                return false;
        }

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (!locale && i != DEFAULT_LOCALE)
                continue;
            std::string const& name = (i == DEFAULT_LOCALE) ? data.Item->Name1 : locale->Name[i];
            if (name.empty())
                continue;
            if (randomSuffix)
            {
                if (len > name.length() + 1 &&
                  (strncmp(name.c_str(), pos, name.length()) == 0) &&
                  (*(pos + name.length()) == ' ') &&
                  equal_with_len(randomSuffix[i], pos + name.length() + 1, len - name.length() - 1))
                    return true;
            }
            else if (equal_with_len(name.c_str(), pos, len))
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
    static bool IsTextValid(QuestLinkData const& data, char const* pos, size_t len)
    {
        QuestLocale const* locale = sObjectMgr->GetQuestLocale(data.Quest->GetQuestId());
        if (!locale)
            return equal_with_len(data.Quest->GetTitle().c_str(), pos, len);

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            std::string const& name = (i == DEFAULT_LOCALE) ? data.Quest->GetTitle() : locale->Title[i];
            if (name.empty())
                continue;
            if (equal_with_len(name.c_str(), pos, len))
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
    static bool IsTextValid(SpellInfo const* info, char const* pos, size_t len)
    {
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            if (equal_with_len(info->SpellName[i], pos, len))
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
    static bool IsTextValid(SpellInfo const* info, char const* pos, size_t len)
    {
        if (LinkValidator<LinkTags::spell>::IsTextValid(info, pos, len))
            return true;
        SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(info->Id);
        if (bounds.first == bounds.second)
            return false;

        for (auto pair = bounds.first; pair != bounds.second; ++pair)
        {
            SkillLineEntry const* skill = sSkillLineStore.LookupEntry(pair->second->skillId);
            if (!skill)
                return false;

            for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            {
                char const* skillName = skill->name[i];
                size_t skillLen = strlen(skillName);
                if (len > skillLen + 2 &&                         // or of form [Skill Name: Spell Name]
                    !strncmp(pos, skillName, skillLen) && !strncmp(pos + skillLen, ": ", 2) &&
                    equal_with_len(info->SpellName[i], pos + (skillLen + 2), len - (skillLen + 2)))
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
    static bool IsTextValid(GlyphLinkData const& data, char const* pos, size_t len)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.Glyph->SpellId))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, pos, len);
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
    static bool IsTextValid(TalentLinkData const& data, char const* pos, size_t len)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.Talent->RankID[0]))
            return LinkValidator<LinkTags::spell>::IsTextValid(info, pos, len);
        return false;
    }

    static bool IsColorValid(TalentLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TALENT;
    }
};

template <>
struct LinkValidator<LinkTags::trade>
{
    static bool IsTextValid(TradeskillLinkData const& data, char const* pos, size_t len)
    {
        return LinkValidator<LinkTags::spell>::IsTextValid(data.Spell, pos, len);
    }

    static bool IsColorValid(TradeskillLinkData const&, HyperlinkColor c)
    {
        return c == CHAT_LINK_COLOR_TRADE;
    }
};

#define TryValidateAs(tagname)                                                                          \
{                                                                                                       \
    ASSERT(!strcmp(LinkTags::tagname::tag(), #tagname));                                                \
    if (info.tag.second == strlen(LinkTags::tagname::tag()) &&                                          \
        !strncmp(info.tag.first, LinkTags::tagname::tag(), strlen(LinkTags::tagname::tag())))           \
    {                                                                                                   \
        advstd::remove_cvref_t<typename LinkTags::tagname::value_type> t;                               \
        if (!LinkTags::tagname::StoreTo(t, info.data.first, info.data.second))                          \
            return false;                                                                               \
        if (!LinkValidator<LinkTags::tagname>::IsColorValid(t, info.color))                             \
            return false;                                                                               \
        if (sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY))                            \
            if (!LinkValidator<LinkTags::tagname>::IsTextValid(t, info.text.first, info.text.second))   \
                return false;                                                                           \
        return true;                                                                                    \
    }                                                                                                   \
}

static bool ValidateLinkInfo(HyperlinkInfo const& info)
{
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
bool Trinity::Hyperlinks::CheckAllLinks(std::string const& str)
{
    // Step 1: Disallow all control sequences except ||, |H, |h, |c and |r
    {
        std::string::size_type pos = 0;
        while ((pos = str.find('|', pos)) != std::string::npos)
        {
            char next = str[pos + 1];
            if (next == 'H' || next == 'h' || next == 'c' || next == 'r' || next == '|')
                pos += 2;
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
        std::string::size_type pos = 0;
        while ((pos = str.find('|', pos)) != std::string::npos)
        {
            if (str[pos + 1] == '|') // this is an escaped pipe character (||)
            {
                pos += 2;
                continue;
            }

            HyperlinkInfo info = ParseHyperlink(str.c_str() + pos);
            if (!info || !ValidateLinkInfo(info))
                return false;

            // tag is fine, find the next one
            pos = info.next - str.c_str();
        }
    }

    // all tags are valid
    return true;
}

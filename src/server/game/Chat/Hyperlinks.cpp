/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "QuestDef.h"
#include "World.h"

using namespace Trinity::Hyperlinks;

inline bool isHex(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'); }
// Validates a single hyperlink
HyperlinkInfo Trinity::Hyperlinks::ParseHyperlink(char const* pos)
{
    //color tag
    if (*(pos++) != '|' || *(pos++) != 'c')
        return nullptr;
    for (uint8 i = 0; i < 8; ++i)
        if (!isHex(*(pos++))) // make sure we don't overrun a terminator
            return nullptr;
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
    return { pos, tagStart, tagLength, dataStart, dataLength, textStart, textLength };
}

template <typename T>
struct LinkTextValidator
{
    static bool IsValid(typename T::value_type, char const*, size_t) { return true; }
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
struct LinkTextValidator<LinkTags::achievement>
{
    static bool IsValid(AchievementLinkData const& data, char const* pos, size_t len)
    {
        if (!len)
            return false;
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            if (equal_with_len(data.achievement->Title[i], pos, len))
                return true;
        return false;
    }
};

template <>
struct LinkTextValidator<LinkTags::item>
{
    static bool IsValid(ItemLinkData const& data, char const* pos, size_t len)
    {
        ItemLocale const* locale = sObjectMgr->GetItemLocale(data.item->ItemId);
        if (!locale)
            return false;

        char const* const* randomSuffix = nullptr;
        if (data.randomPropertyId < 0)
        {
            if (ItemRandomSuffixEntry const* suffixEntry = sItemRandomSuffixStore.LookupEntry(-data.randomPropertyId))
                randomSuffix = suffixEntry->nameSuffix;
            else
                return false;
        }
        else if (data.randomPropertyId > 0)
        {
            if (ItemRandomPropertiesEntry const* propEntry = sItemRandomPropertiesStore.LookupEntry(data.randomPropertyId))
                randomSuffix = propEntry->nameSuffix;
            else
                return false;
        }

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            std::string const& name = (i == DEFAULT_LOCALE) ? data.item->Name1 : locale->Name[i];
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
};

template <>
struct LinkTextValidator<LinkTags::quest>
{
    static bool IsValid(QuestLinkData const& data, char const* pos, size_t len)
    {
        QuestLocale const* locale = sObjectMgr->GetQuestLocale(data.quest->GetQuestId());
        if (!locale)
            return false;

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            std::string const& name = (i == DEFAULT_LOCALE) ? data.quest->GetTitle() : locale->Title[i];
            if (name.empty())
                continue;
            if (equal_with_len(name.c_str(), pos, len))
                return true;
        }

        return false;
    }
};

template <>
struct LinkTextValidator<LinkTags::spell>
{
    static bool IsValid(SpellInfo const* info, char const* pos, size_t len)
    {
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
            if (equal_with_len(info->SpellName[i], pos, len))
                return true;
        return false;
    }
};
template <> struct LinkTextValidator<LinkTags::enchant> : public LinkTextValidator<LinkTags::spell> {};

template <>
struct LinkTextValidator<LinkTags::glyph>
{
    static bool IsValid(GlyphLinkData const& data, char const* pos, size_t len)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.glyph->SpellId))
            return LinkTextValidator<LinkTags::spell>::IsValid(info, pos, len);
        return false;
    }
};

template <>
struct LinkTextValidator<LinkTags::talent>
{
    static bool IsValid(TalentLinkData const& data, char const* pos, size_t len)
    {
        if (SpellInfo const* info = sSpellMgr->GetSpellInfo(data.talent->RankID[data.rank-1]))
            return LinkTextValidator<LinkTags::spell>::IsValid(info, pos, len);
        return false;
    }
};

template <>
struct LinkTextValidator<LinkTags::trade>
{
    static bool IsValid(TradeskillLinkData const& data, char const* pos, size_t len)
    {
        return LinkTextValidator<LinkTags::spell>::IsValid(data.spell, pos, len);
    }
};

#define TryValidateAs(tagname)                                                                  \
{                                                                                               \
    using taginfo = typename LinkTags::tagname;                                                 \
    ASSERT(!strcmp(taginfo::tag(), #tagname));                                                  \
    if (info.tag.second == strlen(taginfo::tag()) &&                                            \
        !strncmp(info.tag.first, taginfo::tag(), strlen(taginfo::tag())))                       \
    {                                                                                           \
        advstd::remove_cvref_t<typename taginfo::value_type> t;                                 \
        if (!taginfo::StoreTo(t, info.data.first, info.data.second))                            \
            return false;                                                                       \
        if (!sWorld->getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY))                   \
            return true;                                                                        \
        return LinkTextValidator<taginfo>::IsValid(t, info.text.first, info.text.second);       \
    }                                                                                           \
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
bool Trinity::Hyperlinks::ValidateLinks(std::string& str)
{
    bool allValid = true;
    std::string::size_type pos = std::string::npos;
    // Step 1: Strip all control sequences except ||, |H, |h, |c and |r
    do
    {
        if ((pos = str.rfind('|', pos)) == std::string::npos)
            break;
        if (pos && str[pos - 1] == '|')
        {
            --pos;
            continue;
        }
        char next = str[pos + 1];
        if (next == 'H' || next == 'h' || next == 'c' || next == 'r')
            continue;

        allValid = false;
        str.erase(pos, 2);
    } while (pos--);

    // Step 2: Parse all link sequences
    // They look like this: |c<color>|H<linktag>:<linkdata>|h[<linktext>]|h|r
    // - <color> is 8 hex characters AARRGGBB
    // - <linktag> is arbitrary length [a-z_]
    // - <linkdata> is arbitrary length, no | contained
    // - <linktext> is printable
    pos = 0;
    while (pos < str.size() && (pos = str.find('|', pos)) != std::string::npos)
    {
        if (str[pos + 1] == '|') // this is an escaped pipe character (||)
        {
            pos += 2;
            continue;
        }

        HyperlinkInfo info = ParseHyperlink(str.c_str() + pos);
        if (!info) 
        {   // cannot be parsed at all, so we'll need to cut it out entirely
            // find the next start of a link
            std::string::size_type next = str.find("|c", pos + 1);
            // then backtrack to the previous return control sequence
            std::string::size_type end = str.rfind("|r", next);
            if (end == std::string::npos || end <= pos) // there is no potential end tag, remove everything after pos (up to next, if available)
            {
                if (next == std::string::npos)
                    str.erase(pos);
                else
                    str.erase(pos, next - pos);
            }
            else
                str.erase(pos, end - pos + 2);

            allValid = false;
            continue;
        }

        // ok, link parsed successfully - now validate it based on the tag
        if (!ValidateLinkInfo(info))
        {
            // invalid link info, replace with just text
            str.replace(pos, (info.next - str.c_str()) - pos, str, info.text.first - str.c_str(), info.text.second);
            allValid = false;
            continue;
        }

        // tag is fine, find the next one
        pos = info.next - str.c_str();
    }

    // all tags validated
    return allValid;
}

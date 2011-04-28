/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ChatLink.h"
#include "SpellMgr.h"
#include "ObjectMgr.h"

// Supported shift-links (client generated and server side)
// |color|Hachievement:achievement_id:player_guid:0:0:0:0:0:0:0:0|h[name]|h|r
//                                                                        - client, item icon shift click, not used in server currently
// |color|Harea:area_id|h[name]|h|r
// |color|Hcreature:creature_guid|h[name]|h|r
// |color|Hcreature_entry:creature_id|h[name]|h|r
// |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r          - client, at shift click in recipes list dialog
// |color|Hgameevent:id|h[name]|h|r
// |color|Hgameobject:go_guid|h[name]|h|r
// |color|Hgameobject_entry:go_id|h[name]|h|r
// |color|Hglyph:glyph_slot_id:glyph_prop_id|h[%s]|h|r                    - client, at shift click in glyphs dialog, GlyphSlot.dbc, GlyphProperties.dbc
// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:0:0:0:reporter_level|h[name]|h|r
//                                                                        - client, item icon shift click
// |color|Hitemset:itemset_id|h[name]|h|r
// |color|Hplayer:name|h[name]|h|r                                        - client, in some messages, at click copy only name instead link
// |color|Hquest:quest_id:quest_level|h[name]|h|r                         - client, quest list name shift-click
// |color|Hskill:skill_id|h[name]|h|r
// |color|Hspell:spell_id|h[name]|h|r                                     - client, spellbook spell icon shift-click
// |color|Htalent:talent_id,rank|h[name]|h|r                              - client, talent icon shift-click
// |color|Htaxinode:id|h[name]|h|r
// |color|Htele:id|h[name]|h|r
// |color|Htitle:id|h[name]|h|r
// |color|Htrade:spell_id:cur_value:max_value:unk3int:unk3str|h[name]|h|r - client, spellbook profession icon shift-click

inline bool ReadUInt32(std::istringstream& iss, uint32& res)
{
    iss >> std::dec >> res;
    return !iss.fail() && !iss.eof();
}

inline bool ReadInt32(std::istringstream& iss, int32& res)
{
    iss >> std::dec >> res;
    return !iss.fail() && !iss.eof();
}

inline std::string ReadSkip(std::istringstream& iss, char term)
{
    std::string res;
    char c = iss.peek();
    while (c != term && c != '\0')
    {
        res += c;
        iss.ignore(1);
        c = iss.peek();
    }
    return res;
}

inline bool CheckDelimiter(std::istringstream& iss, char delimiter, const char* context)
{
    char c = iss.peek();
    if (c != delimiter)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): invalid %s link structure ('%c' expected, '%c' found)", iss.str().c_str(), context, delimiter, c);
        return false;
    }
    iss.ignore(1);
    return true;
}

inline bool ReadHex(std::istringstream& iss, uint32& res, uint32 length)
{
    std::istringstream::pos_type pos = iss.tellg();
    iss >> std::hex >> res;
    uint32 size = uint32(iss.gcount());
    if (length && uint32(iss.tellg() - pos) != length)
        return false;
    return !iss.fail() && !iss.eof();
}

#define DELIMITER ':'
#define PIPE_CHAR '|'

bool ChatLink::ValidateName(char* buffer, const char* context)
{
    _name = buffer;
    return true;
}

// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:random_property:0:reporter_level|h[name]|h|r
// |cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
bool ItemChatLink::Initialize(std::istringstream& iss)
{
    // Read item entry
    uint32 itemEntry = 0;
    if (!ReadUInt32(iss, itemEntry))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading item entry", iss.str().c_str());
        return false;
    }
    // Validate item
    _item = sObjectMgr->GetItemTemplate(itemEntry);
    if (!_item)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid itemEntry %u in |item command", iss.str().c_str(), itemEntry);
        return false;
    }
    // Validate item's color
    if (_color != ItemQualityColors[_item->Quality])
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): linked item has color %u, but user claims %u", iss.str().c_str(), ItemQualityColors[_item->Quality], _color);
        return false;
    }
    // Number of various item properties after item entry
    const uint8 propsCount = 8;
    const uint8 randomPropertyPosition = 5;
    for (uint8 index = 0; index < propsCount; ++index)
    {
        if (!CheckDelimiter(iss, DELIMITER, "item"))
            return false;

        int32 id = 0;
        if (!ReadInt32(iss, id))
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading item property (%u)", iss.str().c_str(), index);
            return false;
        }
        if (id && (index == randomPropertyPosition))
        {
            // Validate random property
            if (id > 0)
            {
                _property = sItemRandomPropertiesStore.LookupEntry(id);
                if (!_property)
                {
                    sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid item property id %u in |item command", iss.str().c_str(), id);
                    return false;
                }
            }
            else if (id < 0)
            {
                _suffix = sItemRandomSuffixStore.LookupEntry(-id);
                if (!_suffix)
                {
                    sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid item suffix id %u in |item command", iss.str().c_str(), -id);
                    return false;
                }
            }
        }
        _data[index] = id;
    }
    return true;
}

inline std::string ItemChatLink::FormatName(uint8 index, ItemLocale const *locale, char* const* suffixStrings) const
{
    std::stringstream ss;
    if (locale == NULL || index >= locale->Name.size())
        ss << _item->Name1;
    else
        ss << locale->Name[index];
    if (suffixStrings)
        ss << " " << suffixStrings[index];
    return ss.str();
}

bool ItemChatLink::ValidateName(char* buffer, const char* context)
{
    ChatLink::ValidateName(buffer, context);

    char* const* suffixStrings = _suffix ? _suffix->nameSuffix : (_property ? _property->nameSuffix : NULL);

    bool res = (FormatName(LOCALE_enUS, NULL, suffixStrings) == buffer);
    if (!res)
    {
        ItemLocale const *il = sObjectMgr->GetItemLocale(_item->ItemId);
        for (uint8 index = LOCALE_koKR; index < TOTAL_LOCALES; ++index)
        {
            if (FormatName(index, il, suffixStrings) == buffer)
            {
                res = true;
                break;
            }
        }
    }
    if (!res)
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): linked item (id: %u) name wasn't found in any localization", context, _item->ItemId);
    return res;
}

// |color|Hquest:quest_id:quest_level|h[name]|h|r
// |cff808080|Hquest:2278:47|h[The Platinum Discs]|h|r
bool QuestChatLink::Initialize(std::istringstream& iss)
{
    // Read quest id
    uint32 questId = 0;
    if (!ReadUInt32(iss, questId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading quest entry", iss.str().c_str());
        return false;
    }
    // Validate quest
    _quest = sObjectMgr->GetQuestTemplate(questId);
    if (!_quest)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): quest template %u not found", iss.str().c_str(), questId);
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "quest"))
        return false;
    // Read quest level
    if (!ReadInt32(iss, _questLevel))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading quest level", iss.str().c_str());
        return false;
    }
    // Validate quest level
    if (_questLevel >= STRONG_MAX_LEVEL)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): quest level %d is too big", iss.str().c_str(), _questLevel);
        return false;
    }
    return true;
}

bool QuestChatLink::ValidateName(char* buffer, const char* context)
{
    ChatLink::ValidateName(buffer, context);

    bool res = (_quest->GetTitle() == buffer);
    if (!res)
        if (QuestLocale const *ql = sObjectMgr->GetQuestLocale(_quest->GetQuestId()))
            for (uint8 i = 0; i < ql->Title.size(); i++)
                if (ql->Title[i] == buffer)
                {
                    res = true;
                    break;
                }
    if (!res)
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): linked quest (id: %u) title wasn't found in any localization", context, _quest->GetQuestId());
    return res;
}

// |color|Hspell:spell_id|h[name]|h|r
// |cff71d5ff|Hspell:21563|h[Command]|h|r
bool SpellChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_SPELL)
        return false;
    // Read spell id
    uint32 spellId = 0;
    if (!ReadUInt32(iss, spellId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading spell entry", iss.str().c_str());
        return false;
    }
    // Validate spell
    _spell = sSpellStore.LookupEntry(spellId);
    if (!_spell)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid spell id %u in |spell command", iss.str().c_str(), spellId);
        return false;
    }
    return true;
}

bool SpellChatLink::ValidateName(char* buffer, const char* context)
{
    ChatLink::ValidateName(buffer, context);

    // spells with that flag have a prefix of "$PROFESSION: "
    if (_spell->Attributes & SPELL_ATTR0_TRADESPELL)
    {
        SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(_spell->Id);
        if (bounds.first == bounds.second)
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): skill line not found for spell %u", context, _spell->Id);
            return false;
        }
        SkillLineAbilityEntry const *skillInfo = bounds.first->second;
        if (!skillInfo)
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): skill line ability not found for spell %u", context, _spell->Id);
            return false;
        }
        SkillLineEntry const *skillLine = sSkillLineStore.LookupEntry(skillInfo->skillId);
        if (!skillLine)
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): skill line not found for skill %u", context, skillInfo->skillId);
            return false;
        }

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            uint32 skillLineNameLength = strlen(skillLine->name[i]);
            if (skillLineNameLength > 0 && strncmp(skillLine->name[i], buffer, skillLineNameLength) == 0)
            {
                // found the prefix, remove it to perform spellname validation below
                // -2 = strlen(": ")
                uint32 spellNameLength = strlen(buffer) - skillLineNameLength - 2;
                memcpy(buffer, buffer + skillLineNameLength + 2, spellNameLength + 1);
            }
        }
    }

    bool res = false;
    for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        if (*_spell->SpellName[i] && strcmp(_spell->SpellName[i], buffer) == 0)
        {
            res = true;
            break;
        }

    if (!res)
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): linked spell (id: %u) name wasn't found in any localization", context, _spell->Id);
    return res;
}

// |color|Hachievement:achievement_id:player_guid:0:0:0:0:0:0:0:0|h[name]|h|r
// |cffffff00|Hachievement:546:0000000000000001:0:0:0:-1:0:0:0:0|h[Safe Deposit]|h|r
bool AchievementChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_ACHIEVEMENT)
        return false;
    // Read achievemnt Id
    uint32 achievementId = 0;
    if (!ReadUInt32(iss, achievementId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading achievement entry", iss.str().c_str());
        return false;
    }
    // Validate achievement
    _achievement = sAchievementStore.LookupEntry(achievementId);
    if (!_achievement)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid achivement id %u in |achievement command", iss.str().c_str(), achievementId);
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "achievement"))
        return false;
    // Read HEX
    if (!ReadHex(iss, _guid, 0))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): invalid hexadecimal number while reading char's guid", iss.str().c_str());
        return false;
    }
    // Skip progress
    const uint8 propsCount = 8;
    for (uint8 index = 0; index < propsCount; ++index)
    {
        if (!CheckDelimiter(iss, DELIMITER, "achievement"))
            return false;

        if (!ReadUInt32(iss, _data[index]))
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading achievement property (%u)", iss.str().c_str(), index);
            return false;
        }
    }
    return true;
}

bool AchievementChatLink::ValidateName(char* buffer, const char* context)
{
    ChatLink::ValidateName(buffer, context);

    bool res = false;
    for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        if (*_achievement->name[i] && strcmp(_achievement->name[i], buffer) == 0)
        {
            res = true;
            break;
        }

    if (!res)
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): linked achievement (id: %u) name wasn't found in any localization", context, _achievement->ID);
    return res;
}

// |color|Htrade:spell_id:cur_value:max_value:player_guid:base64_data|h[name]|h|r
// |cffffd000|Htrade:4037:1:150:1:6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA|h[Engineering]|h|r
bool TradeChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_TRADE)
        return false;
    // Spell Id
    uint32 spellId = 0;
    if (!ReadUInt32(iss, spellId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading achievement entry", iss.str().c_str());
        return false;
    }
    // Validate spell
    _spell = sSpellStore.LookupEntry(spellId);
    if (!_spell)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid spell id %u in |trade command", iss.str().c_str(), spellId);
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "trade"))
        return false;
    // Minimum talent level
    if (!ReadInt32(iss, _minSkillLevel))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading minimum talent level", iss.str().c_str());
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "trade"))
        return false;
    // Maximum talent level
    if (!ReadInt32(iss, _maxSkillLevel))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading maximum talent level", iss.str().c_str());
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "trade"))
        return false;
    // Something hexadecimal
    if (!ReadHex(iss, _guid, 0))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading achievement's owner guid", iss.str().c_str());
        return false;
    }
    // Skip base64 encoded stuff
    _base64 = ReadSkip(iss, PIPE_CHAR);
    return true;
}

// |color|Htalent:talent_id:rank|h[name]|h|r
// |cff4e96f7|Htalent:2232:-1|h[Taste for Blood]|h|r
bool TalentChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_TALENT)
        return false;
    // Read talent entry
    if (!ReadUInt32(iss, _talentId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading talent entry", iss.str().c_str());
        return false;
    }
    // Validate talent
    TalentEntry const *talentInfo = sTalentStore.LookupEntry(_talentId);
    if (!talentInfo)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid talent id %u in |talent command", iss.str().c_str(), _talentId);
        return false;
    }
    // Validate talent's spell
    _spell = sSpellStore.LookupEntry(talentInfo->RankID[0]);
    if (!_spell)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid spell id %u in |trade command", iss.str().c_str(), talentInfo->RankID[0]);
        return false;
    }
    // Delimiter
    if (!CheckDelimiter(iss, DELIMITER, "talent"))
        return false;
    // Rank
    if (!ReadInt32(iss, _rankId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading talent rank", iss.str().c_str());
        return false;
    }
    return true;
}

// |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r
// |cffffd000|Henchant:3919|h[Engineering: Rough Dynamite]|h|r
bool EnchantmentChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_ENCHANT)
        return false;
    // Spell Id
    uint32 spellId = 0;
    if (!ReadUInt32(iss, spellId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading enchantment spell entry", iss.str().c_str());
        return false;
    }
    // Validate spell
    _spell = sSpellStore.LookupEntry(spellId);
    if (!_spell)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid spell id %u in |enchant command", iss.str().c_str(), spellId);
        return false;
    }
    return true;
}

// |color|Hglyph:glyph_slot_id:glyph_prop_id|h[%s]|h|r
// |cff66bbff|Hglyph:21:762|h[Glyph of Bladestorm]|h|r
bool GlyphChatLink::Initialize(std::istringstream& iss)
{
    if (_color != CHAT_LINK_COLOR_GLYPH)
        return false;
    // Slot
    if (!ReadUInt32(iss, _slotId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading slot id", iss.str().c_str());
        return false;
    }
    // Check delimiter
    if (!CheckDelimiter(iss, DELIMITER, "glyph"))
        return false;
    // Glyph Id
    uint32 glyphId = 0;
    if (!ReadUInt32(iss, glyphId))
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly while reading glyph entry", iss.str().c_str());
        return false;
    }
    // Validate glyph
    _glyph = sGlyphPropertiesStore.LookupEntry(glyphId);
    if (!_glyph)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid glyph id %u in |glyph command", iss.str().c_str(), glyphId);
        return false;
    }
    // Validate glyph's spell
    _spell = sSpellStore.LookupEntry(_glyph->SpellId);
    if (!_spell)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid spell id %u in |glyph command", iss.str().c_str(), _glyph->SpellId);
        return false;
    }
    return true;
}

LinkExtractor::LinkExtractor(const char* msg) : _iss(msg)
{
}

LinkExtractor::~LinkExtractor()
{
    for (Links::iterator itr = _links.begin(); itr != _links.end(); ++itr)
        delete *itr;
    _links.clear();
}

bool LinkExtractor::IsValidMessage()
{
    const char validSequence[6] = "cHhhr";
    const char* validSequenceIterator = validSequence;

    char buffer[256];

    std::istringstream::pos_type startPos = 0;
    uint32 color = 0;

    ChatLink* link = NULL;
    while (!_iss.eof())
    {
        if (validSequence == validSequenceIterator)
        {
            link = NULL;
            _iss.ignore(255, PIPE_CHAR);
            startPos = _iss.tellg() - std::istringstream::pos_type(1);
        }
        else if (_iss.get() != PIPE_CHAR)
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence aborted unexpectedly", _iss.str().c_str());
            return false;
        }

        // pipe has always to be followed by at least one char
        if (_iss.peek() == '\0')
        {
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): pipe followed by '\\0'", _iss.str().c_str());
            return false;
        }

        // no further pipe commands
        if (_iss.eof())
            break;

        char commandChar;
        _iss >> commandChar;

        // | in normal messages is escaped by ||
        if (commandChar != PIPE_CHAR)
        {
            if (commandChar == *validSequenceIterator)
            {
                if (validSequenceIterator == validSequence+4)
                    validSequenceIterator = validSequence;
                else
                    ++validSequenceIterator;
            }
            else
            {
                sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): invalid sequence, expected '%c' but got '%c'", _iss.str().c_str(), *validSequenceIterator, commandChar);
                return false;
            }
        }
        else if (validSequence != validSequenceIterator)
        {
            // no escaped pipes in sequences
            sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got escaped pipe in sequence", _iss.str().c_str());
            return false;
        }

        switch (commandChar)
        {
            case 'c':
                if (!ReadHex(_iss, color, 8))
                {
                    sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): invalid hexadecimal number while reading color", _iss.str().c_str());
                    return false;
                }
                break;
            case 'H':
                // read chars up to colon = link type
                _iss.getline(buffer, 256, DELIMITER);
                if (_iss.eof())
                {
                    sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly", _iss.str().c_str());
                    return false;
                }

                if (strcmp(buffer, "item") == 0)
                    link = new ItemChatLink();
                else if (strcmp(buffer, "quest") == 0)
                    link = new QuestChatLink();
                else if (strcmp(buffer, "trade") == 0)
                    link = new TradeChatLink();
                else if (strcmp(buffer, "talent") == 0)
                    link = new TalentChatLink();
                else if (strcmp(buffer, "spell") == 0)
                    link = new SpellChatLink();
                else if (strcmp(buffer, "enchant") == 0)
                    link = new EnchantmentChatLink();
                else if (strcmp(buffer, "achievement") == 0)
                    link = new AchievementChatLink();
                else if (strcmp(buffer, "glyph") == 0)
                    link = new GlyphChatLink();
                else
                {
                    sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): user sent unsupported link type '%s'", _iss.str().c_str(), buffer);
                    return false;
                }
                _links.push_back(link);
                link->SetColor(color);
                if (!link->Initialize(_iss))
                    return false;
                break;
            case 'h':
                // if h is next element in sequence, this one must contain the linked text :)
                if (*validSequenceIterator == 'h')
                {
                    // links start with '['
                    if (_iss.get() != '[')
                    {
                        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): link caption doesn't start with '['", _iss.str().c_str());
                        return false;
                    }
                    _iss.getline(buffer, 256, ']');
                    if (_iss.eof())
                    {
                        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): sequence finished unexpectedly", _iss.str().c_str());
                        return false;
                    }

                    if (!link)
                        return false;

                    if (!link->ValidateName(buffer, _iss.str().c_str()))
                        return false;
                }
                break;
            case 'r':
                if (link)
                    link->SetBounds(startPos, _iss.tellg());
            case '|':
                // no further payload
                break;
            default:
                sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): got invalid command |%c", _iss.str().c_str(), commandChar);
                return false;
        }
    }

    // check if every opened sequence was also closed properly
    if (validSequence != validSequenceIterator)
    {
        sLog->outDebug(LOG_FILTER_CHATSYS, "ChatHandler::isValidChatMessage('%s'): EOF in active sequence", _iss.str().c_str());
        return false;
    }

    return true;
}

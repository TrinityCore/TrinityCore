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

#ifndef TRINITYCORE_CHATLINK_H
#define TRINITYCORE_CHATLINK_H

#include "SharedDefines.h"
#include "Common.h"
#include <list>
#include <sstream>
#include <vector>
#include <cstring>

struct ItemLocale;
struct ItemTemplate;
struct ItemRandomSuffixEntry;
struct ItemRandomPropertiesEntry;
class SpellInfo;
struct AchievementEntry;
struct GlyphPropertiesEntry;
class Quest;

///////////////////////////////////////////////////////////////////////////////////////////////////
// ChatLink - abstract base class for various links
class TC_GAME_API ChatLink
{
public:
    ChatLink() : _color(0), _startPos(0), _endPos(0) { }
    virtual ~ChatLink() { }
    void SetColor(uint32 color) { _color = color; }
    // This will allow to extract the whole link string from the message, if necessary.
    void SetBounds(std::istringstream::pos_type startPos, std::istringstream::pos_type endPos) { _startPos = startPos; _endPos = endPos; }

    virtual bool Initialize(std::istringstream& iss) = 0;
    virtual bool ValidateName(char* buffer, const char* context) = 0;

protected:
    uint32 _color;
    std::string _name;
    std::istringstream::pos_type _startPos;
    std::istringstream::pos_type _endPos;
};

// ItemChatLink - link to item
class TC_GAME_API ItemChatLink : public ChatLink
{
public:
    ItemChatLink() : ChatLink(), _item(nullptr), _enchantId(0), _reporterLevel(0), _reporterSpec(0), _context(0)
    {
        memset(_gemItemId, 0, sizeof(_gemItemId));
    }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, const char* context) override;

protected:
    std::string FormatName(uint8 index, LocalizedString* suffixStrings) const;
    bool HasValue(std::istringstream& iss) const;

    ItemTemplate const* _item;
    int32 _enchantId;
    int32 _gemItemId[3];
    int32 _reporterLevel;
    int32 _reporterSpec;
    int32 _context;
    std::vector<int32> _bonusListIDs;
    std::vector<std::pair<uint32, int32>> _modifiers;
    std::vector<int32> _gemBonusListIDs[3];
};

// QuestChatLink - link to quest
class TC_GAME_API QuestChatLink : public ChatLink
{
public:
    QuestChatLink() : ChatLink(), _quest(nullptr), _questLevel(0), _minLevel(0), _maxLevel(0), _scalingFaction(0) { }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, const char* context) override;

protected:
    Quest const* _quest;
    int32 _questLevel;
    int32 _minLevel;
    int32 _maxLevel;
    int32 _scalingFaction;
};

// SpellChatLink - link to quest
class TC_GAME_API SpellChatLink : public ChatLink
{
public:
    SpellChatLink() : ChatLink(), _spell(nullptr) { }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, const char* context) override;

protected:
    SpellInfo const* _spell;
};

// AchievementChatLink - link to quest
class TC_GAME_API AchievementChatLink : public ChatLink
{
public:
    AchievementChatLink() : ChatLink(), _guid(0), _achievement(NULL)
    {
        memset(_data, 0, sizeof(_data));
    }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, const char* context) override;

protected:
    uint32 _guid;
    AchievementEntry const* _achievement;
    uint32 _data[8];
};

// TradeChatLink - link to trade info
class TC_GAME_API TradeChatLink : public SpellChatLink
{
public:
    TradeChatLink() : SpellChatLink(), _minSkillLevel(0), _maxSkillLevel(0), _guid(0) { }
    virtual bool Initialize(std::istringstream& iss) override;
private:
    int32 _minSkillLevel;
    int32 _maxSkillLevel;
    uint32 _guid;
    std::string _base64;
};

// TalentChatLink - link to talent
class TC_GAME_API TalentChatLink : public SpellChatLink
{
public:
    TalentChatLink() : SpellChatLink(), _talentId(0), _rankId(0) { }
    virtual bool Initialize(std::istringstream& iss) override;

private:
    uint32 _talentId;
    int32 _rankId;
};

// EnchantmentChatLink - link to enchantment
class TC_GAME_API EnchantmentChatLink : public SpellChatLink
{
public:
    EnchantmentChatLink() : SpellChatLink() { }
    virtual bool Initialize(std::istringstream& iss) override;
};

// GlyphChatLink - link to glyph
class TC_GAME_API GlyphChatLink : public SpellChatLink
{
public:
    GlyphChatLink() : SpellChatLink(), _slotId(0), _glyph(NULL) { }
    virtual bool Initialize(std::istringstream& iss) override;
private:
    uint32 _slotId;
    GlyphPropertiesEntry const* _glyph;
};

class TC_GAME_API LinkExtractor
{
public:
    explicit LinkExtractor(const char* msg);
    ~LinkExtractor();

    bool IsValidMessage();

private:
    typedef std::list<ChatLink*> Links;
    Links _links;
    std::istringstream _iss;
};


#endif // TRINITYCORE_CHATLINK_H

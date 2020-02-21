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

#include "Common.h"
#include "SharedDefines.h"
#include <cstring>
#include <list>
#include <sstream>
#include <vector>

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
    virtual bool ValidateName(char* buffer, char const* context) = 0;

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
    ItemChatLink() : ChatLink(), _item(nullptr), _suffix(nullptr), _property(nullptr)
    {
        memset(_data, 0, sizeof(_data));
    }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, char const* context) override;

protected:
    std::string FormatName(uint8 index, char* suffixStrings) const;

    ItemTemplate const* _item;
    int32 _data[8];
    ItemRandomSuffixEntry const* _suffix;
    ItemRandomPropertiesEntry const* _property;
};

// QuestChatLink - link to quest
class TC_GAME_API QuestChatLink : public ChatLink
{
public:
    QuestChatLink() : ChatLink(), _quest(nullptr), _questLevel(0) { }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, char const* context) override;

protected:
    Quest const* _quest;
    int32 _questLevel;
};

// SpellChatLink - link to quest
class TC_GAME_API SpellChatLink : public ChatLink
{
public:
    SpellChatLink() : ChatLink(), _spell(nullptr) { }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, char const* context) override;

protected:
    SpellInfo const* _spell;
};

// AchievementChatLink - link to quest
class TC_GAME_API AchievementChatLink : public ChatLink
{
public:
    AchievementChatLink() : ChatLink(), _guid(0), _achievement(nullptr)
    {
        memset(_data, 0, sizeof(_data));
    }
    virtual bool Initialize(std::istringstream& iss) override;
    virtual bool ValidateName(char* buffer, char const* context) override;

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
    GlyphChatLink() : SpellChatLink(), _slotId(0), _glyph(nullptr) { }
    virtual bool Initialize(std::istringstream& iss) override;
private:
    uint32 _slotId;
    GlyphPropertiesEntry const* _glyph;
};

class TC_GAME_API LinkExtractor
{
public:
    explicit LinkExtractor(char const* msg);
    ~LinkExtractor();

    bool IsValidMessage();

private:
    typedef std::list<ChatLink*> Links;
    Links _links;
    std::istringstream _iss;
};


#endif // TRINITYCORE_CHATLINK_H

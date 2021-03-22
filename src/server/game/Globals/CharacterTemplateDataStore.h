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

#ifndef CharacterTemplateDataStore_h__
#define CharacterTemplateDataStore_h__

#include "Define.h"

#include <unordered_map>
#include <vector>
#include <string>

struct CharacterTemplateClass
{
    CharacterTemplateClass(uint8 factionGroup, uint8 classID)
        : FactionGroup(factionGroup), ClassID(classID) { }

    uint8 FactionGroup;
    uint8 ClassID;
};

struct CharacterTemplate
{
    uint32 TemplateSetId;
    std::vector<CharacterTemplateClass> Classes;
    std::string Name;
    std::string Description;
    uint8 Level;
};

typedef std::unordered_map<uint32, CharacterTemplate> CharacterTemplateContainer;

class TC_GAME_API CharacterTemplateDataStore
{
public:
    void LoadCharacterTemplates();

    CharacterTemplateContainer const& GetCharacterTemplates() const;
    CharacterTemplate const* GetCharacterTemplate(uint32 templateId) const;

    static CharacterTemplateDataStore* Instance();
};

#define sCharacterTemplateDataStore CharacterTemplateDataStore::Instance()

#endif // CharacterTemplateDataStore_h__

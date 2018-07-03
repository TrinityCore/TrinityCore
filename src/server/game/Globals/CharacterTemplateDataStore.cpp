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

#include "CharacterTemplateDataStore.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "Timer.h"

namespace
{
    CharacterTemplateContainer _characterTemplateStore;
}

void CharacterTemplateDataStore::LoadCharacterTemplates()
{
    uint32 oldMSTime = getMSTime();
    _characterTemplateStore.clear();

    std::unordered_map<uint32, std::vector<CharacterTemplateClass>> characterTemplateClasses;

    if (QueryResult classesResult = WorldDatabase.Query("SELECT TemplateId, FactionGroup, Class FROM character_template_class"))
    {
        do
        {
            Field* fields = classesResult->Fetch();

            uint32 templateId = fields[0].GetUInt32();
            uint8 factionGroup = fields[1].GetUInt8();
            uint8 classID = fields[2].GetUInt8();

            if (!((factionGroup & (FACTION_MASK_PLAYER | FACTION_MASK_ALLIANCE)) == (FACTION_MASK_PLAYER | FACTION_MASK_ALLIANCE)) &&
                !((factionGroup & (FACTION_MASK_PLAYER | FACTION_MASK_HORDE)) == (FACTION_MASK_PLAYER | FACTION_MASK_HORDE)))
            {
                TC_LOG_ERROR("sql.sql", "Faction group %u defined for character template %u in `character_template_class` is invalid. Skipped.", factionGroup, templateId);
                continue;
            }

            ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(classID);
            if (!classEntry)
            {
                TC_LOG_ERROR("sql.sql", "Class %u defined for character template %u in `character_template_class` does not exists, skipped.", classID, templateId);
                continue;
            }

            characterTemplateClasses[templateId].emplace_back(factionGroup, classID);
        }
        while (classesResult->NextRow());
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 character template classes. DB table `character_template_class` is empty.");
    }

    QueryResult templates = WorldDatabase.Query("SELECT Id, Name, Description, Level FROM character_template");
    if (!templates)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 character templates. DB table `character_template` is empty.");
        return;
    }

    do
    {
        Field* fields = templates->Fetch();

        CharacterTemplate templ;
        templ.TemplateSetId = fields[0].GetUInt32();
        templ.Name = fields[1].GetString();
        templ.Description = fields[2].GetString();
        templ.Level = fields[3].GetUInt8();
        templ.Classes = std::move(characterTemplateClasses[templ.TemplateSetId]);

        if (templ.Classes.empty())
        {
            TC_LOG_ERROR("sql.sql", "Character template %u does not have any classes defined in `character_template_class`. Skipped.", templ.TemplateSetId);
            continue;
        }

        _characterTemplateStore[templ.TemplateSetId] = templ;
    }
    while (templates->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " character templates in %u ms.", _characterTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

CharacterTemplateContainer const& CharacterTemplateDataStore::GetCharacterTemplates() const
{
    return _characterTemplateStore;
}

CharacterTemplate const* CharacterTemplateDataStore::GetCharacterTemplate(uint32 templateId) const
{
    auto itr = _characterTemplateStore.find(templateId);
    if (itr != _characterTemplateStore.end())
        return &itr->second;

    return nullptr;
}

CharacterTemplateDataStore* CharacterTemplateDataStore::Instance()
{
    static CharacterTemplateDataStore instance;
    return &instance;
}

/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "SkillExtraItems.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Player.h"
#include "ObjectMgr.h"
#include <map>

// some type definitions
// no use putting them in the header file, they're only used in this .cpp

// struct to store information about perfection procs
// one entry per spell
struct SkillPerfectItemEntry
{
    // the spell id of the spell required - it's named "specialization" to conform with SkillExtraItemEntry
    uint32 requiredSpecialization;
    // perfection proc chance
    float perfectCreateChance;
    // itemid of the resulting perfect item
    uint32 perfectItemType;

    SkillPerfectItemEntry()
        : requiredSpecialization(0), perfectCreateChance(0.0f), perfectItemType(0) { }
    SkillPerfectItemEntry(uint32 rS, float pCC, uint32 pIT)
        : requiredSpecialization(rS), perfectCreateChance(pCC), perfectItemType(pIT) { }
};

// map to store perfection info. key = spellId of the creation spell, value is the perfectitementry as specified above
typedef std::map<uint32, SkillPerfectItemEntry> SkillPerfectItemMap;

SkillPerfectItemMap SkillPerfectItemStore;

// loads the perfection proc info from DB
void LoadSkillPerfectItemTable()
{
    uint32 oldMSTime = getMSTime();

    SkillPerfectItemStore.clear(); // reload capability

    //                                                  0               1                      2                  3
    QueryResult result = WorldDatabase.Query("SELECT spellId, requiredSpecialization, perfectCreateChance, perfectItemType FROM skill_perfect_item_template");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 spell perfection definitions. DB table `skill_perfect_item_template` is empty.");
        return;
    }

    uint32 count = 0;

    do /* fetch data and run sanity checks */
    {
        Field* fields = result->Fetch();

        uint32 spellId = fields[0].GetUInt32();

        if (!sSpellMgr->GetSpellInfo(spellId))
        {
            TC_LOG_ERROR("sql.sql", "Skill perfection data for spell %u has a non-existing spell id in the `skill_perfect_item_template`!", spellId);
            continue;
        }

        uint32 requiredSpecialization = fields[1].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(requiredSpecialization))
        {
            TC_LOG_ERROR("sql.sql", "Skill perfection data for spell %u has a non-existing required specialization spell id %u in the `skill_perfect_item_template`!", spellId, requiredSpecialization);
            continue;
        }

        float perfectCreateChance = fields[2].GetFloat();
        if (perfectCreateChance <= 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Skill perfection data for spell %u has impossibly low proc chance in the `skill_perfect_item_template`!", spellId);
            continue;
        }

        uint32 perfectItemType = fields[3].GetUInt32();
        if (!sObjectMgr->GetItemTemplate(perfectItemType))
        {
            TC_LOG_ERROR("sql.sql", "Skill perfection data for spell %u references a non-existing perfect item id %u in the `skill_perfect_item_template`!", spellId, perfectItemType);
            continue;
        }

        SkillPerfectItemEntry& skillPerfectItemEntry = SkillPerfectItemStore[spellId];

        skillPerfectItemEntry.requiredSpecialization = requiredSpecialization;
        skillPerfectItemEntry.perfectCreateChance = perfectCreateChance;
        skillPerfectItemEntry.perfectItemType = perfectItemType;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell perfection definitions in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

// struct to store information about extra item creation
// one entry for every spell that is able to create an extra item
struct SkillExtraItemEntry
{
    // the spell id of the specialization required to create extra items
    uint32 requiredSpecialization;
    // the chance to create one additional item
    float additionalCreateChance;
    // maximum number of extra items created per crafting
    uint8 additionalMaxNum;

    SkillExtraItemEntry()
        : requiredSpecialization(0), additionalCreateChance(0.0f), additionalMaxNum(0) { }

    SkillExtraItemEntry(uint32 rS, float aCC, uint8 aMN)
        : requiredSpecialization(rS), additionalCreateChance(aCC), additionalMaxNum(aMN) { }
};

// map to store the extra item creation info, the key is the spellId of the creation spell, the mapped value is the assigned SkillExtraItemEntry
typedef std::map<uint32, SkillExtraItemEntry> SkillExtraItemMap;

SkillExtraItemMap SkillExtraItemStore;

// loads the extra item creation info from DB
void LoadSkillExtraItemTable()
{
    uint32 oldMSTime = getMSTime();

    SkillExtraItemStore.clear();                            // need for reload

    //                                                  0               1                       2                    3
    QueryResult result = WorldDatabase.Query("SELECT spellId, requiredSpecialization, additionalCreateChance, additionalMaxNum FROM skill_extra_item_template");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 spell specialization definitions. DB table `skill_extra_item_template` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 spellId = fields[0].GetUInt32();

        if (!sSpellMgr->GetSpellInfo(spellId))
        {
            TC_LOG_ERROR("sql.sql", "Skill specialization %u has a non-existing spell id in the `skill_extra_item_template`!", spellId);
            continue;
        }

        uint32 requiredSpecialization = fields[1].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(requiredSpecialization))
        {
            TC_LOG_ERROR("sql.sql", "Skill specialization %u has a non-existing required specialization spell id %u in the `skill_extra_item_template`!", spellId, requiredSpecialization);
            continue;
        }

        float additionalCreateChance = fields[2].GetFloat();
        if (additionalCreateChance <= 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Skill specialization %u has too low additional create chance in the `skill_extra_item_template`!", spellId);
            continue;
        }

        uint8 additionalMaxNum = fields[3].GetUInt8();
        if (!additionalMaxNum)
        {
            TC_LOG_ERROR("sql.sql", "Skill specialization %u has 0 max number of extra items in the `skill_extra_item_template`!", spellId);
            continue;
        }

        SkillExtraItemEntry& skillExtraItemEntry = SkillExtraItemStore[spellId];

        skillExtraItemEntry.requiredSpecialization = requiredSpecialization;
        skillExtraItemEntry.additionalCreateChance = additionalCreateChance;
        skillExtraItemEntry.additionalMaxNum       = additionalMaxNum;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell specialization definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool CanCreatePerfectItem(Player* player, uint32 spellId, float &perfectCreateChance, uint32 &perfectItemType)
{
    SkillPerfectItemMap::const_iterator ret = SkillPerfectItemStore.find(spellId);
    // no entry in DB means no perfection proc possible
    if (ret == SkillPerfectItemStore.end())
        return false;

    SkillPerfectItemEntry const* thisEntry = &ret->second;
    // lack of entry means no perfection proc possible
    if (!thisEntry)
        return false;

    // if you don't have the spell needed, then no procs for you
    if (!player->HasSpell(thisEntry->requiredSpecialization))
        return false;

    // set values as appropriate
    perfectCreateChance = thisEntry->perfectCreateChance;
    perfectItemType = thisEntry->perfectItemType;

    // and tell the caller to start rolling the dice
    return true;
}

bool CanCreateExtraItems(Player* player, uint32 spellId, float &additionalChance, uint8 &additionalMax)
{
    // get the info for the specified spell
    SkillExtraItemMap::const_iterator ret = SkillExtraItemStore.find(spellId);
    if (ret == SkillExtraItemStore.end())
        return false;

    SkillExtraItemEntry const* specEntry = &ret->second;

    // if no entry, then no extra items can be created
    if (!specEntry)
        return false;

    // the player doesn't have the required specialization, return false
    if (!player->HasSpell(specEntry->requiredSpecialization))
        return false;

    // set the arguments to the appropriate values
    additionalChance = specEntry->additionalCreateChance;
    additionalMax = specEntry->additionalMaxNum;

    // enable extra item creation
    return true;
}

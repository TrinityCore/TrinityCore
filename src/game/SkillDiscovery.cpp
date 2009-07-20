/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Database/DatabaseEnv.h"
#include "Log.h"
#include "ProgressBar.h"
#include "Policies/SingletonImp.h"
#include "World.h"
#include "Util.h"
#include "SkillDiscovery.h"
#include "SpellMgr.h"
#include "Player.h"
#include <map>

struct SkillDiscoveryEntry
{
    uint32  spellId;                                        // discavered spell
    uint32  reqSkillValue;                                  // skill level limitation
    float   chance;                                         // chance

    SkillDiscoveryEntry()
        : spellId(0), reqSkillValue(0), chance(0) {}

    SkillDiscoveryEntry(uint32 _spellId, uint32 req_skill_val, float _chance)
        : spellId(_spellId), reqSkillValue(req_skill_val), chance(_chance) {}
};

typedef std::list<SkillDiscoveryEntry> SkillDiscoveryList;
typedef UNORDERED_MAP<int32, SkillDiscoveryList> SkillDiscoveryMap;

static SkillDiscoveryMap SkillDiscoveryStore;

void LoadSkillDiscoveryTable()
{

    SkillDiscoveryStore.clear();                            // need for reload

    uint32 count = 0;

    //                                                0        1         2              3
    QueryResult *result = WorldDatabase.Query("SELECT spellId, reqSpell, reqSkillValue, chance FROM skill_discovery_template");

    if (!result)
    {
        sLog.outString();
        sLog.outString( ">> Loaded 0 skill discovery definitions. DB table `skill_discovery_template` is empty." );
        return;
    }

    barGoLink bar(result->GetRowCount());

    std::ostringstream ssNonDiscoverableEntries;
    std::set<uint32> reportedReqSpells;

    do
    {
        Field *fields = result->Fetch();
        bar.step();

        uint32 spellId         = fields[0].GetUInt32();
        int32  reqSkillOrSpell = fields[1].GetInt32();
        uint32 reqSkillValue   = fields[2].GetInt32();
        float  chance          = fields[3].GetFloat();

        if (chance <= 0)                                    // chance
        {
            ssNonDiscoverableEntries << "spellId = " << spellId << " reqSkillOrSpell = " << reqSkillOrSpell
                << " reqSkillValue = " << reqSkillValue << " chance = " << chance << "(chance problem)\n";
            continue;
        }

        if (reqSkillOrSpell > 0)                            // spell case
        {
            SpellEntry const* reqSpellEntry = sSpellStore.LookupEntry(reqSkillOrSpell);
            if (!reqSpellEntry)
            {
                if(reportedReqSpells.count(reqSkillOrSpell)==0)
                {
                    sLog.outErrorDb("Spell (ID: %u) have not existed spell (ID: %i) in `reqSpell` field in `skill_discovery_template` table",spellId,reqSkillOrSpell);
                    reportedReqSpells.insert(reqSkillOrSpell);
                }
                continue;
            }

            // mechanic discovery
            if (reqSpellEntry->Mechanic != MECHANIC_DISCOVERY &&
                // explicit discovery ability
                !IsExplicitDiscoverySpell(reqSpellEntry))
            {
                if (reportedReqSpells.count(reqSkillOrSpell)==0)
                {
                    sLog.outErrorDb("Spell (ID: %u) not have have MECHANIC_DISCOVERY (28) value in Mechanic field in spell.dbc and not 100%% chance random discovery ability but listed for spellId %u (and maybe more) in `skill_discovery_template` table",reqSkillOrSpell,spellId);
                    reportedReqSpells.insert(reqSkillOrSpell);
                }
                continue;
            }

            SkillDiscoveryStore[reqSkillOrSpell].push_back( SkillDiscoveryEntry(spellId, reqSkillValue, chance) );
        }
        else if( reqSkillOrSpell == 0 )                     // skill case
        {
            SkillLineAbilityMap::const_iterator lower = spellmgr.GetBeginSkillLineAbilityMap(spellId);
            SkillLineAbilityMap::const_iterator upper = spellmgr.GetEndSkillLineAbilityMap(spellId);

            if(lower==upper)
            {
                sLog.outErrorDb("Spell (ID: %u) not listed in `SkillLineAbility.dbc` but listed with `reqSpell`=0 in `skill_discovery_template` table",spellId);
                continue;
            }

            for(SkillLineAbilityMap::const_iterator _spell_idx = lower; _spell_idx != upper; ++_spell_idx)
            {
                SkillDiscoveryStore[-int32(_spell_idx->second->skillId)].push_back( SkillDiscoveryEntry(spellId, reqSkillValue, chance) );
            }
        }
        else
        {
            sLog.outErrorDb("Spell (ID: %u) have negative value in `reqSpell` field in `skill_discovery_template` table",spellId);
            continue;
        }

        ++count;
    } while (result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u skill discovery definitions", count );
    if(!ssNonDiscoverableEntries.str().empty())
        sLog.outErrorDb("Some items can't be successfully discovered: have in chance field value < 0.000001 in `skill_discovery_template` DB table . List:\n%s",ssNonDiscoverableEntries.str().c_str());
}

uint32 GetExplicitDiscoverySpell(uint32 spellId, Player* player)
{
    // explicit discovery spell chances (always success if case exist)
    // in this case we have both skill and spell
    SkillDiscoveryMap::const_iterator tab = SkillDiscoveryStore.find(spellId);
    if (tab == SkillDiscoveryStore.end())
        return 0;

    SkillLineAbilityMap::const_iterator lower = spellmgr.GetBeginSkillLineAbilityMap(spellId);
    SkillLineAbilityMap::const_iterator upper = spellmgr.GetEndSkillLineAbilityMap(spellId);
    uint32 skillvalue = lower != upper ? player->GetSkillValue(lower->second->skillId) : 0;

    float full_chance = 0;
    for(SkillDiscoveryList::const_iterator item_iter = tab->second.begin(); item_iter != tab->second.end(); ++item_iter)
        if (item_iter->reqSkillValue <= skillvalue)
            if (!player->HasSpell(item_iter->spellId))
                full_chance += item_iter->chance;

    float rate = full_chance / 100.0f;
    float roll = rand_chance() * rate;                      // roll now in range 0..full_chance

    for(SkillDiscoveryList::const_iterator item_iter = tab->second.begin(); item_iter != tab->second.end(); ++item_iter)
    {
        if (item_iter->reqSkillValue > skillvalue)
            continue;

        if (player->HasSpell(item_iter->spellId))
            continue;

        if (item_iter->chance > roll)
            return item_iter->spellId;

        roll -= item_iter->chance;
    }

    return 0;
}

uint32 GetSkillDiscoverySpell(uint32 skillId, uint32 spellId, Player* player)
{
    uint32 skillvalue = skillId ? player->GetSkillValue(skillId) : 0;

    // check spell case
    SkillDiscoveryMap::const_iterator tab = SkillDiscoveryStore.find(spellId);

    if (tab != SkillDiscoveryStore.end())
    {
        for(SkillDiscoveryList::const_iterator item_iter = tab->second.begin(); item_iter != tab->second.end(); ++item_iter)
        {
            if (roll_chance_f(item_iter->chance * sWorld.getRate(RATE_SKILL_DISCOVERY)) &&
                item_iter->reqSkillValue <= skillvalue &&
                !player->HasSpell(item_iter->spellId))
                return item_iter->spellId;
        }

        return 0;
    }

    if (!skillId)
        return 0;

    // check skill line case
    tab = SkillDiscoveryStore.find(-(int32)skillId);
    if (tab != SkillDiscoveryStore.end())
    {
        for(SkillDiscoveryList::const_iterator item_iter = tab->second.begin(); item_iter != tab->second.end(); ++item_iter)
        {
            if (roll_chance_f(item_iter->chance * sWorld.getRate(RATE_SKILL_DISCOVERY)) &&
                item_iter->reqSkillValue <= skillvalue &&
                !player->HasSpell(item_iter->spellId))
                return item_iter->spellId;
        }

        return 0;
    }

    return 0;
}


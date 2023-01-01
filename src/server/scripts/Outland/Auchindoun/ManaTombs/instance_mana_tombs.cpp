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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "mana_tombs.h"

DungeonEncounterData const encounters[] =
{
    { DATA_PANDEMONIUS, {{ 1900 }} },
    { DATA_TAVAROK, {{ 1901 }} },
    { DATA_NEXUSPRINCE_SHAFFAR, {{ 1899 }} },
    { DATA_YOR, {{ 250 }} }
};

class instance_mana_tombs : public InstanceMapScript
{
    public:
        instance_mana_tombs() : InstanceMapScript(MTScriptName, 557) { }

        struct instance_mana_tombs_InstanceMapScript : public InstanceScript
        {
            instance_mana_tombs_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDungeonEncounterData(encounters);
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetEntry() == NPC_TAVAROK)
                    SetBossState(DATA_TAVAROK, DONE);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_mana_tombs_InstanceMapScript(map);
        }
};

void AddSC_instance_mana_tombs()
{
    new instance_mana_tombs();
}

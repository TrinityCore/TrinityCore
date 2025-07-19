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

#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "azure_vault.h"

static BossBoundaryData const boundaries =
{
    { DATA_LEYMOR, new CircleBoundary(Position(-5129.39f, 1253.30f), 75.0f) }
};

static constexpr ObjectData creatureData[] =
{
    { BOSS_LEYMOR,              DATA_LEYMOR             },
    { BOSS_AZUREBLADE,          DATA_AZUREBLADE         },
    { BOSS_TELASH_GREYWING,     DATA_TELASH_GREYWING    },
    { BOSS_UMBRELSKUL,          DATA_UMBRELSKUL         },
    { 0,                        0                       }  // END
};

static constexpr DoorData doorData[] =
{
    { GO_ARCANE_VAULTS_DOOR_LEYMOR_ENTRANCE,    DATA_LEYMOR,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_ARCANE_VAULTS_DOOR_LEYMOR_EXIT,        DATA_LEYMOR,  EncounterDoorBehavior::OpenWhenDone },
    { 0,                                        0,            EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

static constexpr DungeonEncounterData encounters[] =
{
    { DATA_LEYMOR,          {{ 2582 }} },
    { DATA_AZUREBLADE,      {{ 2585 }} },
    { DATA_TELASH_GREYWING, {{ 2583 }} },
    { DATA_UMBRELSKUL,      {{ 2584 }} },
};

class instance_azure_vault : public InstanceMapScript
{
    public:
        instance_azure_vault() : InstanceMapScript(AVScriptName, 2515) { }

        struct instance_azure_vault_InstanceMapScript: public InstanceScript
        {
            instance_azure_vault_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
                LoadDungeonEncounterData(encounters);

                _leymorIntroDone = false;
            }

            uint32 GetData(uint32 dataId) const override
            {
                switch (dataId)
                {
                    case DATA_LEYMOR_INTRO_DONE:
                        return _leymorIntroDone ? 1 : 0;
                    default:
                        break;
                }
                return 0;
            }

            void OnCreatureGroupDepleted(CreatureGroup const* creatureGroup) override
            {
                if (!_leymorIntroDone && creatureGroup->LeaderHasStringId("leymor_arcane_tender"))
                {
                    _leymorIntroDone = true;
                    if (Creature* leymor = GetCreature(DATA_LEYMOR); leymor && leymor->IsAIEnabled())
                        leymor->AI()->DoAction(ACTION_FINISH_LEYMOR_INTRO);
                }
            }

        private:
            bool _leymorIntroDone;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_azure_vault_InstanceMapScript(map);
        }
};

void AddSC_instance_azure_vault()
{
    new instance_azure_vault();
}

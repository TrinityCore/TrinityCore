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
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "the_stonevault.h"

BossBoundaryData const boundaries =
{
    { DATA_EDNA, new CircleBoundary({ 0.0f, 0.0f }, 58.0f)}
};

ObjectData const creatureData[] =
{
    { BOSS_EDNA,                DATA_EDNA                },
    { BOSS_SKARMORAX,           DATA_SKARMORAK           },
    { BOSS_SPEAKER_DORLITA,     DATA_SPEAKER_DORLITA     },
    { BOSS_SPEAKER_BROKK,       DATA_SPEAKER_BROKK       },
    { BOSS_VOID_SPEAKER_EIRICH, DATA_VOID_SPEAKER_EIRICH },
    { 0,                        0                        }  // END
};

static DoorData const doorData[] =
{
    { GO_FOUNDRY_DOOR_ENTRANCE,             DATA_EDNA,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_FOUNDRY_DOOR_TOWARDS_SKARMORAK,    DATA_EDNA,  EncounterDoorBehavior::OpenWhenDone },
    { GO_FOUNDRY_DOOR_TOWARDS_MACHINISTS,   DATA_EDNA,  EncounterDoorBehavior::OpenWhenDone },
    { 0,                                    0,          EncounterDoorBehavior::OpenWhenNotInProgress }
};

DungeonEncounterData const encounters[] =
{
    { DATA_EDNA,                {{ 2854 }} },
    { DATA_SKARMORAK,           {{ 2880 }} },
    { DATA_MASTER_MACHINISTS,   {{ 2883 }} },
    { DATA_VOID_SPEAKER_EIRICH, {{ 2888 }} }
};

constexpr uint8 EDNA_INTRO_REQUIRED_KILLS = 5;

class instance_the_stonevault : public InstanceMapScript
{
public:
    instance_the_stonevault() : InstanceMapScript(TSVScriptName, 2652) { }

    struct instance_the_stonevault_InstanceMapScript: public InstanceScript
    {
        instance_the_stonevault_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);

            _ednaIntroState = NOT_STARTED;
            _ednaIntroNPCsKillCount = 0;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_EDNA_INTRO_STATE:
                    return _ednaIntroState;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 value) override
        {
            switch (dataId)
            {
                case DATA_EDNA_INTRO_STATE:
                    _ednaIntroState = value;
                    break;
                default:
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("edna_intro_trash"))
            {
                if (_ednaIntroState != NOT_STARTED)
                    return;

                _ednaIntroNPCsKillCount++;
                if (_ednaIntroNPCsKillCount < EDNA_INTRO_REQUIRED_KILLS)
                    return;

                _ednaIntroState = IN_PROGRESS;

                Creature* edna = GetCreature(DATA_EDNA);
                if (!edna)
                    return;

                edna->AI()->DoAction(ACTION_START_EDNA_INTRO);
            }
        }

    private:
        uint8 _ednaIntroState;
        uint8 _ednaIntroNPCsKillCount;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_stonevault_InstanceMapScript(map);
    }
};

void AddSC_instance_the_stonevault()
{
    new instance_the_stonevault();
}

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
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "terrace_of_endless_spring.h"

ObjectData const creatureData[] =
{
    { BOSS_PROTECTOR_KAOLAN,      DATA_PROTECTOR_KAOLAN      },
    { BOSS_ELDER_REGAIL,          DATA_ELDER_REGAIL          },
    { BOSS_ELDER_ASANI,           DATA_ELDER_ASANI           },
    { BOSS_TSULONG,               DATA_TSULONG               },
    { BOSS_LEI_SHI,               DATA_LEI_SHI               },
    { BOSS_SHA_OF_FEAR,           DATA_SHA_OF_FEAR           },
    { 0,                          0                          }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_PROTECTORS_OF_THE_ENDLESS, {{ 1409 }} },
    { DATA_TSULONG,                   {{ 1505 }} },
    { DATA_LEI_SHI,                   {{ 1506 }} },
    { DATA_SHA_OF_FEAR,               {{ 1431 }} }
};

BossBoundaryData const boundaries =
{
    { DATA_PROTECTORS_OF_THE_ENDLESS, new CircleBoundary(Position(-1017.799988f, -3049.110107f), 95.0f) }
};

class instance_terrace_of_endless_spring : public InstanceMapScript
{
public:
    instance_terrace_of_endless_spring() : InstanceMapScript(TOESScriptName, 996) { }

    struct instance_terrace_of_endless_spring_InstanceMapScript: public InstanceScript
    {
        instance_terrace_of_endless_spring_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);

            _protectorsIntroState = NOT_STARTED;
            _protectorsAliveIntroNPCs = 0;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_PROTECTORS_INTRO_STATE:
                    return _protectorsIntroState;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 value) override
        {
            switch (dataId)
            {
                case DATA_PROTECTORS_INTRO_STATE:
                    _protectorsIntroState = value;
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->HasStringId("protectors_intro_trash"))
                _protectorsAliveIntroNPCs++;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("protectors_intro_trash"))
            {
                if (_protectorsIntroState != NOT_STARTED)
                    return;

                --_protectorsAliveIntroNPCs;
                if (_protectorsAliveIntroNPCs > 0)
                    return;

                _protectorsIntroState = IN_PROGRESS;

                Creature* protectorKaolan = GetCreature(DATA_PROTECTOR_KAOLAN);
                if (!protectorKaolan)
                    return;

                protectorKaolan->AI()->DoAction(ACTION_PROTECTORS_INTRO);
            }
        }

    private:
        uint8 _protectorsAliveIntroNPCs;
        uint8 _protectorsIntroState;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_terrace_of_endless_spring_InstanceMapScript(map);
    }
};

void AddSC_instance_terrace_of_endless_spring()
{
    new instance_terrace_of_endless_spring();
}

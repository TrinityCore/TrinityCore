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
#include "blackrock_caverns.h"
#include "InstanceScript.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "CreatureAI.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_ROMOGG_BONECRUSHER,          DATA_ROMOGG_BONECRUSHER         },
    { BOSS_CORLA_HERALD_OF_TWILIGHT,    DATA_CORLA_HERALD_OF_TWILIGHT   },
    { BOSS_KARSH_STEELBENDER,           DATA_KARSH_STEELBENDER          },
    { BOSS_BEAUTY,                      DATA_BEAUTY                     },
    { BOSS_ASCENDANT_LORD_OBSIDIUS,     DATA_ASCENDANT_LORD_OBSIDIUS    },
    { NPC_RAZ_THE_CRAZED,               DATA_RAZ_THE_CRAZED             },
    { 0,                                0                               }
};

class instance_blackrock_caverns : public InstanceMapScript
{
    public:
        instance_blackrock_caverns(): InstanceMapScript(BCScriptName, 645) {  }

        struct instance_blackrock_caverns_InstanceMapScript : public InstanceScript
        {
            instance_blackrock_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                _lastRazAreaIndex = RAZ_AREA_INDEX_ROMOGG;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ROMOGG_BONECRUSHER:
                        if (state == DONE)
                            if (Creature* raz = GetCreature(DATA_RAZ_THE_CRAZED))
                                raz->AI()->DoAction(ACTION_BREAK_OUT_OF_PRISON);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_QUAKE:
                    case NPC_ANGERED_EARTH:
                        if (Creature* romogg = GetCreature(DATA_ROMOGG_BONECRUSHER))
                            romogg->AI()->JustSummoned(creature);
                        break;
                    case NPC_BOUND_FLAMES:
                        if (Creature* karsh = GetCreature(DATA_KARSH_STEELBENDER))
                            karsh->AI()->JustSummoned(creature);
                        break;
                    case NPC_TWILIGHT_PORTAL:
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK); // Set spellclick flag manually because the seats are flagged as unusable due to their flags
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_RAZ_LAST_AREA_INDEX)
                    return _lastRazAreaIndex;

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_RAZ_LAST_AREA_INDEX)
                {
                    _lastRazAreaIndex = data;

                    switch (data)
                    {
                        case RAZ_AREA_INDEX_ROMOGG:
                            instance->SummonCreature(NPC_RAZ_THE_CRAZED, RazTheCrazedSummonPositions[RAZ_AREA_INDEX_ROMOGG]);
                            break;
                        case RAZ_AREA_INDEX_CORLA:
                            instance->SummonCreature(NPC_RAZ_THE_CRAZED, RazTheCrazedSummonPositions[RAZ_AREA_INDEX_CORLA]);
                            break;
                        case RAZ_AREA_INDEX_OBSIDIUS:
                            instance->SummonCreature(NPC_RAZ_THE_CRAZED, RazTheCrazedSummonPositions[RAZ_AREA_INDEX_OBSIDIUS]);
                            break;
                        default:
                            break;
                    }
                    SaveToDB();
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _lastRazAreaIndex;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _lastRazAreaIndex;
            }

        private:
            uint8 _lastRazAreaIndex;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blackrock_caverns_InstanceMapScript(map);
        }
};

void AddSC_instance_blackrock_caverns()
{
    new instance_blackrock_caverns();
}

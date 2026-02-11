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

#include "Creature.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "well_of_eternity.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_PEROTHARN,      BOSS_PEROTHARN     },
    { NPC_QUEEN_AZSHARA,  BOSS_QUEEN_AZSHARA },
    { NPC_MANNOROTH,      BOSS_MANNOROTH     },

    // Additional Datas
    { NPC_NOZDORMU,       DATA_NOZDORMU                    },
    { NPC_ILLIDAN_PART_1, DATA_ILLIDAN_COURTYARD_OF_LIGHTS },
    { 0,                  0                                }  // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_PEROTHARN,       {{ 1272 }}  },
    { BOSS_QUEEN_AZSHARA,   {{ 1273 }}  },
    { BOSS_MANNOROTH,       {{ 1274 }}  }
};

class instance_well_of_eternity : public InstanceMapScript
{
public:
    instance_well_of_eternity() : InstanceMapScript(WoEScriptName, 939) { }

    struct instance_well_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_well_of_eternity_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);

            PerotharnIntroState = NOT_STARTED;
            IllidanEscortState = NOT_STARTED;
            IllidanIntroState = NOT_STARTED;
            IllidanFirstCrystalState = NOT_STARTED;
            _crystalOneCreaturesAlive = 0;
            //_crystalTwoCreaturesAlive = 0;
            //_crystalThreeCreaturesAlive = 0;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetData(DATA_ILLIDAN_START_ESCORT) == DONE)
                DoCastSpellOnPlayer(player, SPELL_SHADOWCLOAK_PLAYER);
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_PEROTHARN_INTRO:
                {
                    PerotharnIntroState = data;
                    break;
                }
                case DATA_ILLIDAN_START_ESCORT:
                {
                    IllidanEscortState = data;
                    break;
                }
                case DATA_ILLIDAN_START_INTRO:
                {
                    IllidanIntroState = data;
                    break;
                }
                case DATA_ILLIDAN_FIRST_CRYSTAL:
                {
                    IllidanFirstCrystalState = data;
                    break;
                }
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_ILLIDAN_START_ESCORT:
                    return IllidanEscortState;
                case DATA_ILLIDAN_START_INTRO:
                    return IllidanIntroState;
                case DATA_ILLIDAN_FIRST_CRYSTAL:
                    return IllidanFirstCrystalState;
                case DATA_PEROTHARN_INTRO:
                    return PerotharnIntroState;
                default:
                    break;
            }

            return 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->HasStringId("crystal_1_creature"))
                _crystalOneCreaturesAlive++;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("crystal_1_creature"))
            {
                --_crystalOneCreaturesAlive;
                if (_crystalOneCreaturesAlive > 0)
                    return;

                Creature* illidan = GetCreature(DATA_ILLIDAN_COURTYARD_OF_LIGHTS);
                if (!illidan)
                    return;

                illidan->AI()->DoAction(ACTION_ILLIDAN_ON_FIRST_CRYSTAL);
            }
        }

    private:
        uint8 PerotharnIntroState;
        uint8 IllidanEscortState;
        uint8 IllidanIntroState;
        uint8 IllidanFirstCrystalState;
        uint8 _crystalOneCreaturesAlive;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_well_of_eternity_InstanceMapScript(map);
    }
};

void AddSC_instance_well_of_eternity()
{
    new instance_well_of_eternity();
}

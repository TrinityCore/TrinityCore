/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

/* # Script : ThroneOfThunder Dungeon # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ThroneOfThunder.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_ThroneOfThunder : public InstanceMapScript
{
    public:
        instance_ThroneOfThunder() : InstanceMapScript("instance_ThroneOfThunder", 1098) { }

        struct instance_ThroneOfThunder_InstanceMapScript : public InstanceScript
        {
            instance_ThroneOfThunder_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_Jinrokh:
                    case BOSS_Horridon:
                    case BOSS_Council:
                    case BOSS_Tortos:
                    case BOSS_Megaera:
                    case BOSS_JiKun:
                    case BOSS_Durumu:
                    case BOSS_Primordius:
                    case BOSS_DarkAnimus:
                    case BOSS_IronQon:
                    case BOSS_TwinConsorts:
                    case BOSS_LeiShen:
                    case BOSS_Raden:
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state != DONE)
                   return true;

                switch (type)
                {
                    case DATA_Jinrokh:
                    case DATA_Horridon:
                    case DATA_Council:
                    case DATA_Tortos:
                    case DATA_Megaera:
                    case DATA_JiKun:
                    case DATA_Durumu:
                    case DATA_Primordius:
                    case DATA_DarkAnimus:
                    case DATA_IronQon:
                    case DATA_TwinConsorts:
                    case DATA_LeiShen:
                    case DATA_Raden:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ThroneOfThunder_InstanceMapScript(map);
        }
};

void AddSC_instance_ThroneOfThunder()
{
    new instance_ThroneOfThunder();
}

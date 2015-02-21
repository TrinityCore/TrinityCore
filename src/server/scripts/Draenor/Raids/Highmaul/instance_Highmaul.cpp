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

/* # Script : Highmaul Raid # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Highmaul.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_Highmaul : public InstanceMapScript
{
    public:
        instance_Highmaul() : InstanceMapScript("instance_Highmaul", 1228) { }

        struct instance_Highmaul_InstanceMapScript : public InstanceScript
        {
            instance_Highmaul_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_BRACKENSPORE:
                    case BOSS_KARGATHBLADEFIST:
                    case BOSS_KORAGH:
                    case BOSS_MARGOK:
                    case BOSS_TECTUS:
                    case BOSS_THEBUTCHER:
                    case BOSS_TWINOGRONPOL:
                    case BOSS_TWINOGRONPHEMOS:
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
                    case DATA_BRACKENSPORE:
                    case DATA_KARGATHBLADEFIST:
                    case DATA_KORAGH:
                    case DATA_MARGOK:
                    case DATA_TECTUS:
                    case DATA_THEBUTCHER:
                    case DATA_TWINOGRONPOL:
                    case DATA_TWINOGRONPHEMOS:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_Highmaul_InstanceMapScript(map);
        }
};

void AddSC_instance_Highmaul()
{
    new instance_Highmaul();
}

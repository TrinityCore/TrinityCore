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

/* # Script : Skyreach Dungeon # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Skyreach.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_Skyreach : public InstanceMapScript
{
    public:
        instance_Skyreach() : InstanceMapScript("instance_Skyreach", 1209) { }

        struct instance_Skyreach_InstanceMapScript : public InstanceScript
        {
            instance_Skyreach_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_ARAKNATH:
                    case BOSS_RANJIT:
                    case BOSS_RUKHRAN:
                    case BOSS_VIRYX:
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
                    case DATA_ARAKNATH:
                    case DATA_RANJIT:
                    case DATA_RUKHRAN:
                    case DATA_VIRYX:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_Skyreach_InstanceMapScript(map);
        }
};

void AddSC_instance_Skyreach()
{
    new instance_Skyreach();
}

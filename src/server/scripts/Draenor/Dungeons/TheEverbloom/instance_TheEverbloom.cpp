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

/* # Script : TheEverbloom Dungeon # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "TheEverbloom.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_TheEverbloom : public InstanceMapScript
{
    public:
        instance_TheEverbloom() : InstanceMapScript("instance_TheEverbloom", 1279) { }

        struct instance_TheEverbloom_InstanceMapScript : public InstanceScript
        {
            instance_TheEverbloom_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_ANCIENTPROTECTOR:
                    case BOSS_PROTECTORDULHU:
                    case BOSS_PROTECTORGOLA:
                    case BOSS_ARCHMAGESOL:
                    case BOSS_WITHERBARK:
                    case BOSS_XERITAC:
                    case BOSS_YALNU:
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
                    case DATA_ANCIENTPROTECTOR:
                    case DATA_PROTECTORDULHU:
                    case DATA_PROTECTORGOLA:
                    case DATA_ARCHMAGESOL:
                    case DATA_WITHERBARK:
                    case DATA_XERITAC:
                    case DATA_YALNU:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_TheEverbloom_InstanceMapScript(map);
        }
};

void AddSC_instance_TheEverbloom()
{
    new instance_TheEverbloom();
}

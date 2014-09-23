/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "blackrock_caverns.h"

class instance_blackrock_caverns : public InstanceMapScript
{
    public:
        instance_blackrock_caverns(): InstanceMapScript(BCScriptName, 645) { }

        struct instance_blackrock_caverns_InstanceMapScript : public InstanceScript
        {
            instance_blackrock_caverns_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_RAZ_THE_CRAZED:
                        RaztheCrazed = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                case NPC_RAZ_THE_CRAZED:
                    return RaztheCrazed;
                default:
                    break;
                }
                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ROMOGG_BONECRUSHER:
                    case DATA_CORLA:
                    case DATA_KARSH_STEELBENDER:
                    case DATA_BEAUTY:
                    case DATA_ASCENDANT_LORD_OBSIDIUS:
                        break;
                    default:
                        break;
                }

                return true;
            }
        protected:
            ObjectGuid RaztheCrazed;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_blackrock_caverns_InstanceMapScript(map);
        }
};

void AddSC_instance_blackrock_caverns()
{
    new instance_blackrock_caverns();
}

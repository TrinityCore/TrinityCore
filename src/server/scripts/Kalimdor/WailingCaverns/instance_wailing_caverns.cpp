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
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "wailing_caverns.h"

static constexpr ObjectData creatureData[] =
{
    { NPC_DISCIPLE,              DATA_DISCIPLE },
    { NPC_NARALEX,               DATA_NARALEX  },
    { 0,                         0             } // END
};

class instance_wailing_caverns : public InstanceMapScript
{
public:
    instance_wailing_caverns() : InstanceMapScript(WCScriptName, 43) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_wailing_caverns_InstanceMapScript(map);
    }

    struct instance_wailing_caverns_InstanceMapScript : public InstanceScript
    {
        instance_wailing_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_LORD_COBRAHN:
                case DATA_LORD_PYTHAS:
                case DATA_LADY_ANACONDRA:
                case DATA_LORD_SERPENTIS:
                    if (state == DONE)
                    {
                        if (GetBossState(DATA_LORD_COBRAHN) == DONE && GetBossState(DATA_LORD_PYTHAS) == DONE
                            && GetBossState(DATA_LADY_ANACONDRA) == DONE && GetBossState(DATA_LORD_SERPENTIS) == DONE)
                        {
                            if (Creature* disciple = GetCreature(DATA_DISCIPLE))
                                disciple->AI()->DoAction(ACTION_ALL_DONE);
                        }
                    }
                    break;
                default:
                    break;
            }
            return true;
        }
    };
};

void AddSC_instance_wailing_caverns()
{
    new instance_wailing_caverns();
}

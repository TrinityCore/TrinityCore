/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "baradin_hold.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_ARGALOTH,    DATA_ARGALOTH },
    { BOSS_OCCUTHAR,    DATA_OCCUTHAR },
    { BOSS_ALIZABAL,    DATA_ALIZABAL },
    { 0,                0             }  // END
};

DoorData const doorData[] =
{
    { GO_ARGALOTH_DOOR,  DATA_ARGALOTH, DOOR_TYPE_ROOM },
    { GO_OCCUTHAR_DOOR,  DATA_OCCUTHAR, DOOR_TYPE_ROOM },
    { GO_ALIZABAL_DOOR,  DATA_ALIZABAL, DOOR_TYPE_ROOM },
    { 0,                 0,             DOOR_TYPE_ROOM }  // END
};

class instance_baradin_hold: public InstanceMapScript
{
    public:
        instance_baradin_hold() : InstanceMapScript(BHScriptName, 757) { }

        struct instance_baradin_hold_InstanceMapScript: public InstanceScript
        {
            instance_baradin_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_FEL_FLAMES:
                        if (Creature* argaloth = GetCreature(DATA_ARGALOTH))
                            argaloth->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_baradin_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_baradin_hold()
{
    new instance_baradin_hold();
}

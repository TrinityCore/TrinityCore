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
#include "EventMap.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "hellfire_ramparts.h"
#include "InstanceScript.h"
#include "Map.h"

static constexpr ObjectData creatureData[] =
{
    { NPC_VAZRUDEN_HERALD,         DATA_VAZRUDEN_THE_HERALD },
    { NPC_VAZRUDEN,                DATA_VAZRUDEN            },
    { 0,                           0                        } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_FEL_IRON_CHEST_NORMAL,    DATA_FEL_IRON_CHEST },
    { GO_FEL_IRON_CHEST_HEROIC,    DATA_FEL_IRON_CHEST },
    { 0,                           0                   } // END
};

class instance_ramparts : public InstanceMapScript
{
    public:
        instance_ramparts() : InstanceMapScript(HRScriptName, 543) { }

        struct instance_ramparts_InstanceMapScript : public InstanceScript
        {
            instance_ramparts_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);

                HellfireSentryDeadCount = 0;
                ShouldResetVazruden = false;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (ShouldResetVazruden)
                    Events.ScheduleEvent(EVENT_RESET_VAZRUDEN, 0s);
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                if (unit->GetEntry() == NPC_HELLFIRE_SENTRY)
                {
                    HellfireSentryDeadCount++;

                    if (HellfireSentryDeadCount == 2)
                    {
                        if (Creature* vazruden = GetCreature(DATA_VAZRUDEN_THE_HERALD))
                            vazruden->AI()->DoAction(ACTION_START_ENCOUNTER);

                        HellfireSentryDeadCount = 0;
                    }
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (type == DATA_VAZRUDEN_THE_HERALD)
                {
                    if (state == DONE)
                    {
                        if (GameObject* chest = GetGameObject(DATA_FEL_IRON_CHEST))
                            chest->ActivateObject(GameObjectActions(GameObjectActions::MakeActive));
                    }
                    else if (state == FAIL)
                        Events.ScheduleEvent(EVENT_RESET_VAZRUDEN, 30s);
                }

                return true;
            }

            void Update(uint32 diff) override
            {
                Events.Update(diff);

                if (Events.ExecuteEvent() == EVENT_RESET_VAZRUDEN)
                {
                    instance->SpawnGroupSpawn(SPAWN_GROUP_VAZRUDEN, true);

                    HellfireSentryDeadCount = 0;

                    ShouldResetVazruden = false;

                    if (Creature* vazruden = GetCreature(DATA_VAZRUDEN))
                        vazruden->DespawnOrUnsummon();
                }
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
                if (GetBossState(DATA_VAZRUDEN_THE_HERALD) != DONE)
                    ShouldResetVazruden = true;
            }

        protected:
            EventMap Events;
            uint8 HellfireSentryDeadCount;
            bool ShouldResetVazruden;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ramparts_InstanceMapScript(map);
        }
};

void AddSC_instance_ramparts()
{
    new instance_ramparts();
}

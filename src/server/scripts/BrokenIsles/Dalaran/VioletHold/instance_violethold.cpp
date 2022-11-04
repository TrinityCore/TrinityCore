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

#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureGroups.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "violethold.h"

#define MAX_ENCOUNTER 8

/* Stonecore encounters:
0 - Festerface               0% Done
1 - Shivermaw                0% Done
2 - Blood-Princess Thal'ena  0% Done
3 - Mindflayer Haahrj        0% Done
4 - Millificent Manastorm    0% Done
5 - Anub'esset               0% Done
6 - Sael'orn                 0% Done
7 - Fel Lord Betrug          0% Done
*/

// TO-DO:
// - Find Any and All.

class instance_violethold : public InstanceMapScript
{
    public:
        instance_violethold() : InstanceMapScript(SCScriptName, 1544) { }

        struct instance_violethold_InstanceScript : public InstanceScript
        {
            instance_violethold_InstanceScript(InstanceMap* map) : InstanceScript(map) { }

            void OnPlayerEnter(Player* player) override
            {
                return InstanceScript::OnPlayerEnter(player);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                return InstanceScript::OnGameObjectCreate(go);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                return InstanceScript::OnCreatureCreate(creature);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                return InstanceScript::SetBossState(type, state);
            }

        private:
            //
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_violethold_InstanceScript(map);
        }
};

struct areatrigger_violet_hold_entrance_conversation : AreaTriggerAI
{
    enum MiscIds
    {
        CONVERSATION_WARMING_UP = 3418
    };

    areatrigger_violet_hold_entrance_conversation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

            Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
    }
};

void AddSC_instance_violethold()
{
    new instance_violethold();
    RegisterAreaTriggerAI(areatrigger_violet_hold_entrance_conversation);
}

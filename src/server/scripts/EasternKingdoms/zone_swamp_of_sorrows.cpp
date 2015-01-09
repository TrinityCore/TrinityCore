/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_galen_goodward
######*/

enum Galen
{
    QUEST_GALENS_ESCAPE     = 1393,
    GO_GALENS_CAGE          = 37118,
    SAY_PERIODIC            = 0,
    SAY_QUEST_ACCEPTED      = 1,
    SAY_ATTACKED            = 2,
    SAY_QUEST_COMPLETE      = 3,
    EMOTE_WHISPER           = 4,
    EMOTE_DISAPPEAR         = 5
};

class npc_galen_goodward : public CreatureScript
{
public:
    npc_galen_goodward() : CreatureScript("npc_galen_goodward") { }

    struct npc_galen_goodwardAI : public npc_escortAI
    {
        npc_galen_goodwardAI(Creature* creature) : npc_escortAI(creature)
        {
            galensCageGUID.Clear();
            Reset();
        }

        void Reset() override
        {
            periodicSay = 6000;
        }

        void EnterCombat(Unit* who) override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                Talk(SAY_ATTACKED, who);
        }

        void sQuestAccept(Player* player, Quest const* quest)
        {
            if (quest->GetQuestId() == QUEST_GALENS_ESCAPE)
            {
                Talk(SAY_QUEST_ACCEPTED, player);
                npc_escortAI::Start(false, false, player->GetGUID(), quest);
            }
        }

        void WaypointStart(uint32 uiPointId) override
        {
            switch (uiPointId)
            {
            case 0:
                {
                    GameObject* cage = NULL;
                    if (galensCageGUID)
                        cage = me->GetMap()->GetGameObject(galensCageGUID);
                    else
                        cage = GetClosestGameObjectWithEntry(me, GO_GALENS_CAGE, INTERACTION_DISTANCE);
                    if (cage)
                    {
                        cage->UseDoorOrButton();
                        galensCageGUID = cage->GetGUID();
                    }
                    break;
                }
            case 21:
                Talk(EMOTE_DISAPPEAR);
                break;
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 0:
                    if (GameObject* cage = me->GetMap()->GetGameObject(galensCageGUID))
                        cage->ResetDoorOrButton();
                    break;
                case 20:
                    if (Player* player = GetPlayerForEscort())
                    {
                        me->SetFacingToObject(player);
                        Talk(SAY_QUEST_COMPLETE, player);
                        Talk(EMOTE_WHISPER, player);
                        player->GroupEventHappens(QUEST_GALENS_ESCAPE, me);
                    }
                    SetRun(true);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);

            if (HasEscortState(STATE_ESCORT_NONE))
                return;

            if (periodicSay < diff)
            {
                if (!HasEscortState(STATE_ESCORT_ESCORTING))
                    Talk(SAY_PERIODIC);
                periodicSay = 15000;
            }
            else
                periodicSay -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        ObjectGuid galensCageGUID;
        uint32 periodicSay;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_galen_goodwardAI(creature);
    }
};

void AddSC_swamp_of_sorrows()
{
    new npc_galen_goodward();
}

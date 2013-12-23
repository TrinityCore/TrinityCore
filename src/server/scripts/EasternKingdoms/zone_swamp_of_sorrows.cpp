/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
    EMOTE_DISAPPEAR         = 5,
};

class npc_galen_goodward : public CreatureScript
{
public:

    npc_galen_goodward() : CreatureScript("npc_galen_goodward") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_GALENS_ESCAPE)
        {
            CAST_AI(npc_galen_goodward::npc_galen_goodwardAI, creature->AI())->Start(false, false, player->GetGUID());
            creature->setFaction(FACTION_ESCORT_N_NEUTRAL_ACTIVE);
            creature->AI()->Talk(SAY_QUEST_ACCEPTED);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_galen_goodwardAI(creature);
    }

    struct npc_galen_goodwardAI : public npc_escortAI
    {
        npc_galen_goodwardAI(Creature* creature) : npc_escortAI(creature)
        {
            m_uiGalensCageGUID = 0;
            Reset();
        }

        uint64 m_uiGalensCageGUID;
        uint32 m_uiPeriodicSay;

        void Reset() OVERRIDE
        {
            m_uiPeriodicSay = 6000;
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                Talk(SAY_ATTACKED, who);
        }

        void WaypointStart(uint32 uiPointId) OVERRIDE
        {
            switch (uiPointId)
            {
            case 0:
                {
                    GameObject* pCage = NULL;
                    if (m_uiGalensCageGUID)
                        pCage = me->GetMap()->GetGameObject(m_uiGalensCageGUID);
                    else
                        pCage = GetClosestGameObjectWithEntry(me, GO_GALENS_CAGE, INTERACTION_DISTANCE);
                    if (pCage)
                    {
                        pCage->UseDoorOrButton();
                        m_uiGalensCageGUID = pCage->GetGUID();
                    }
                    break;
                }
            case 21:
                Talk(EMOTE_DISAPPEAR);
                break;
            }
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    if (GameObject* pCage = me->GetMap()->GetGameObject(m_uiGalensCageGUID))
                        pCage->ResetDoorOrButton();
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

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (HasEscortState(STATE_ESCORT_NONE))
                return;

            if (m_uiPeriodicSay < uiDiff)
            {
                if (!HasEscortState(STATE_ESCORT_ESCORTING))
                    Talk(SAY_PERIODIC);
                m_uiPeriodicSay = 15000;
            }
            else
                m_uiPeriodicSay -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_swamp_of_sorrows()
{
    new npc_galen_goodward();
}

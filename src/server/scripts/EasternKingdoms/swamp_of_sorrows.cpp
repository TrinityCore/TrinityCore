/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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


#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_galen_goodward
######*/

enum Galen
{
    QUEST_GALENS_ESCAPE     = 1393,

    GO_GALENS_CAGE          = 37118,

    SAY_PERIODIC            = -1000500,
    SAY_QUEST_ACCEPTED      = -1000501,
    SAY_ATTACKED_1          = -1000502,
    SAY_ATTACKED_2          = -1000503,
    SAY_QUEST_COMPLETE      = -1000504,
    EMOTE_WHISPER           = -1000505,
    EMOTE_DISAPPEAR         = -1000506
};

class npc_galen_goodward : public CreatureScript
{
public:

    npc_galen_goodward() : CreatureScript("npc_galen_goodward") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const *quest)
    {
        if (quest->GetQuestId() == QUEST_GALENS_ESCAPE)
        {
            CAST_AI(npc_galen_goodward::npc_galen_goodwardAI, pCreature->AI())->Start(false, false, pPlayer->GetGUID());
            pCreature->setFaction(FACTION_ESCORT_N_NEUTRAL_ACTIVE);
            DoScriptText(SAY_QUEST_ACCEPTED, pCreature);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_galen_goodwardAI(pCreature);
    }

    struct npc_galen_goodwardAI : public npc_escortAI
    {
        npc_galen_goodwardAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            m_uiGalensCageGUID = 0;
            Reset();
        }

        uint64 m_uiGalensCageGUID;
        uint32 m_uiPeriodicSay;

        void Reset()
        {
            m_uiPeriodicSay = 6000;
        }

        void EnterCombat(Unit* pWho)
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                DoScriptText(RAND(SAY_ATTACKED_1, SAY_ATTACKED_2), me, pWho);
        }

        void WaypointStart(uint32 uiPointId)
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
                DoScriptText(EMOTE_DISAPPEAR, me);
                break;
            }
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch (uiPointId)
            {
            case 0:
                if (GameObject* pCage = me->GetMap()->GetGameObject(m_uiGalensCageGUID))
                    pCage->ResetDoorOrButton();
                break;
            case 20:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    me->SetFacingToObject(pPlayer);
                    DoScriptText(SAY_QUEST_COMPLETE, me, pPlayer);
                    DoScriptText(EMOTE_WHISPER, me, pPlayer);
                    pPlayer->GroupEventHappens(QUEST_GALENS_ESCAPE, me);
                }
                SetRun(true);
                break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (HasEscortState(STATE_ESCORT_NONE))
                return;

            if (m_uiPeriodicSay < uiDiff)
            {
                if (!HasEscortState(STATE_ESCORT_ESCORTING))
                    DoScriptText(SAY_PERIODIC, me);
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

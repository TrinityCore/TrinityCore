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

/* ScriptData
SDName: Teldrassil
SD%Complete: 100
SDComment: Quest support: 938
SDCategory: Teldrassil
EndScriptData */

/* ContentData
npc_mist
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedFollowerAI.h"

/*####
# npc_mist
####*/

enum eMist
{
    SAY_AT_HOME             = -1000323,
    EMOTE_AT_HOME           = -1000324,
    QUEST_MIST              = 938,
    NPC_ARYNIA              = 3519,
    FACTION_DARNASSUS       = 79
};

class npc_mist : public CreatureScript
{
public:
    npc_mist() : CreatureScript("npc_mist") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_MIST)
        {
            if (npc_mistAI* pMistAI = CAST_AI(npc_mist::npc_mistAI, pCreature->AI()))
                pMistAI->StartFollow(pPlayer, FACTION_DARNASSUS, pQuest);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_mistAI(pCreature);
    }

    struct npc_mistAI : public FollowerAI
    {
        npc_mistAI(Creature* pCreature) : FollowerAI(pCreature) { }

        void Reset() { }

        void MoveInLineOfSight(Unit* pWho)
        {
            FollowerAI::MoveInLineOfSight(pWho);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && pWho->GetEntry() == NPC_ARYNIA)
            {
                if (me->IsWithinDistInMap(pWho, 10.0f))
                {
                    DoScriptText(SAY_AT_HOME, pWho);
                    DoComplete();
                }
            }
        }

        void DoComplete()
        {
            DoScriptText(EMOTE_AT_HOME, me);

            if (Player* pPlayer = GetLeaderForFollower())
            {
                if (pPlayer->GetQuestStatus(QUEST_MIST) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->GroupEventHappens(QUEST_MIST, me);
            }

            //The follow is over (and for later development, run off to the woods before really end)
            SetFollowComplete();
        }

        //call not needed here, no known abilities
        /*void UpdateFollowerAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }*/
    };

};

void AddSC_teldrassil()
{
    new npc_mist();
}

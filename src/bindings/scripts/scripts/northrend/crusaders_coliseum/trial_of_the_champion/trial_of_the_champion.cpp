/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Trial Of the Champion
SD%Complete: 80%
SDComment: event script
SDCategory: trial_of_the_champion
EndScriptData */

/* ContentData
npc_toc5_announcer
EndContentData */

#include "precompiled.h"
#include "trial_of_the_champion.h"

#define GOSSIP_START_EVENT1     "I'm ready to start challenge."
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge."

/*######
## npc_toc5_announcer
######*/

struct TRINITY_DLL_DECL npc_toc5_announcerAI : public ScriptedAI
{
    npc_toc5_announcerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* pInstance;
 
    uint32 chmp1, chmp2, chmp3, argent;

    void Reset()
    {
    }

    void StartEvent(Player* pPlayer)
    {
        if(pInstance->GetData(TYPE_GRAND_CHAMPIONS) == NOT_STARTED && pInstance->GetData(TYPE_ARGENT_CHALLENGE) == NOT_STARTED && pInstance->GetData(TYPE_BLACK_KNIGHT) == NOT_STARTED)
        {
            chmp1 = RAND(35572,35569,35571,35570,35617);
            chmp2 = RAND(35572,35569,35571,35570,35617);
            chmp3 = RAND(35572,35569,35571,35570,35617);
            if(chmp1 != chmp2 && chmp2 != chmp3 && chmp1 != chmp3)
            {
                m_creature->SummonCreature(chmp1, 738.665771, 661.031433, 412.394623, 4.698702, TEMPSUMMON_MANUAL_DESPAWN, 0);
                m_creature->SummonCreature(chmp2, 746.864441, 660.918762, 411.695465, 4.698700, TEMPSUMMON_MANUAL_DESPAWN, 0);
                m_creature->SummonCreature(chmp3, 754.360779, 660.816162, 412.395996, 4.698700, TEMPSUMMON_MANUAL_DESPAWN, 0);
                pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
            } else return;
        }

        if(pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE && pInstance->GetData(TYPE_ARGENT_CHALLENGE) == NOT_STARTED && pInstance->GetData(TYPE_BLACK_KNIGHT) == NOT_STARTED)
        {
           argent = RAND(35119,34928);
	    m_creature->SummonCreature(argent, 746.864441, 660.918762, 411.695465, 4.698700, TEMPSUMMON_MANUAL_DESPAWN, 0);
           pInstance->SetData(TYPE_ARGENT_CHALLENGE, IN_PROGRESS);
        }

        if(pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE && pInstance->GetData(TYPE_ARGENT_CHALLENGE) == DONE && pInstance->GetData(TYPE_BLACK_KNIGHT) == NOT_STARTED)
        {
	    m_creature->SummonCreature(NPC_BLACK_KNIGHT, 746.864441, 660.918762, 411.695465, 4.698700, TEMPSUMMON_MANUAL_DESPAWN, 0);
	    pInstance->SetData(TYPE_BLACK_KNIGHT, IN_PROGRESS);
           m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    }

    void UpdateAI(const uint32 diff)
    {

    }
};

CreatureAI* GetAI_npc_toc5_announcer(Creature* pCreature)
{
    return new npc_toc5_announcerAI(pCreature);
}

bool GossipHello_npc_toc5_announcer(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();

    if(pInstance->GetData(TYPE_GRAND_CHAMPIONS) == NOT_STARTED && pInstance->GetData(TYPE_ARGENT_CHALLENGE) == NOT_STARTED && pInstance->GetData(TYPE_BLACK_KNIGHT) == NOT_STARTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    else 
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetEntry(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_toc5_announcer(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        CAST_AI(npc_toc5_announcerAI, pCreature->AI())->StartEvent(pPlayer);
    }

    return true;
}

void AddSC_trial_of_the_champion()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "npc_toc5_announcer";
    NewScript->GetAI = &GetAI_npc_toc5_announcer;
    NewScript->pGossipHello = &GossipHello_npc_toc5_announcer;
    NewScript->pGossipSelect = &GossipSelect_npc_toc5_announcer;
    NewScript->RegisterSelf();
}

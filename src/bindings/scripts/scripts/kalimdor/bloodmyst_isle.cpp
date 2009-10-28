/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Bloodmyst_Isle
SD%Complete: 80
SDComment: Quest support: 9670, 9756(gossip items text needed).
SDCategory: Bloodmyst Isle
EndScriptData */

/* ContentData
mob_webbed_creature
npc_captured_sunhawk_agent
EndContentData */

#include "precompiled.h"

/*######
## mob_webbed_creature
######*/

//possible creatures to be spawned
const uint32 possibleSpawns[32] = {17322, 17661, 17496, 17522, 17340, 17352, 17333, 17524, 17654, 17348, 17339, 17345, 17359, 17353, 17336, 17550, 17330, 17701, 17321, 17680, 17325, 17320, 17683, 17342, 17715, 17334, 17341, 17338, 17337, 17346, 17344, 17327};

struct TRINITY_DLL_DECL mob_webbed_creatureAI : public ScriptedAI
{
    mob_webbed_creatureAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
    }

    void EnterCombat(Unit* who)
    {
    }

    void JustDied(Unit* Killer)
    {
        uint32 spawnCreatureID = 0;

        switch (urand(0,2))
        {
            case 0:
                spawnCreatureID = 17681;
                if (Killer->GetTypeId() == TYPEID_PLAYER)
                    CAST_PLR(Killer)->KilledMonsterCredit(spawnCreatureID, m_creature->GetGUID());
                break;
            case 1:
            case 2:
                spawnCreatureID = possibleSpawns[urand(0,30)];
                break;
        }

        if (spawnCreatureID)
            m_creature->SummonCreature(spawnCreatureID, 0.0f, 0.0f, 0.0f, m_creature->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
    }
};
CreatureAI* GetAI_mob_webbed_creature(Creature* pCreature)
{
    return new mob_webbed_creatureAI (pCreature);
}

/*######
## npc_captured_sunhawk_agent
######*/

#define C_SUNHAWK_TRIGGER 17974

#define GOSSIP_HELLO_CSA     "[PH] "
#define GOSSIP_SELECT_CSA1   "[PH] "
#define GOSSIP_SELECT_CSA2   "[PH] "
#define GOSSIP_SELECT_CSA3   "[PH] "
#define GOSSIP_SELECT_CSA4   "[PH] "
#define GOSSIP_SELECT_CSA5   "[PH] "

bool GossipHello_npc_captured_sunhawk_agent(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->HasAura(31609) && pPlayer->GetQuestStatus(9756) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_CSA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(9136, pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(9134, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_captured_sunhawk_agent(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(9137, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->SEND_GOSSIP_MENU(9138, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->SEND_GOSSIP_MENU(9139, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            pPlayer->SEND_GOSSIP_MENU(9140, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            pPlayer->SEND_GOSSIP_MENU(9141, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->TalkedToCreature(C_SUNHAWK_TRIGGER, pCreature->GetGUID());
            break;
    }
    return true;
}

void AddSC_bloodmyst_isle()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mob_webbed_creature";
    newscript->GetAI = &GetAI_mob_webbed_creature;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_captured_sunhawk_agent";
    newscript->pGossipHello =  &GossipHello_npc_captured_sunhawk_agent;
    newscript->pGossipSelect = &GossipSelect_npc_captured_sunhawk_agent;
    newscript->RegisterSelf();
}


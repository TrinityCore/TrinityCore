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
SDName: Stonetalon_Mountains
SD%Complete: 95
SDComment: Quest support: 6627, 6523
SDCategory: Stonetalon Mountains
EndScriptData */

/* ContentData
npc_braug_dimspirit
npc_kaya_flathoof
EndContentData */

#include "precompiled.h"
#include "escortAI.h"

/*######
## npc_braug_dimspirit
######*/

#define GOSSIP_HBD1 "Ysera"
#define GOSSIP_HBD2 "Neltharion"
#define GOSSIP_HBD3 "Nozdormu"
#define GOSSIP_HBD4 "Alexstrasza"
#define GOSSIP_HBD5 "Malygos"

bool GossipHello_npc_braug_dimspirit(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(6627) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HBD1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HBD2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HBD3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HBD4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HBD5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(5820, pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(5819, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_braug_dimspirit(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->CastSpell(pPlayer,6766,false);

    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->AreaExploredOrEventHappens(6627);
    }
    return true;
}

/*######
## npc_kaya_flathoof
######*/

enum
{
    FACTION_ESCORTEE_H          = 775,

    NPC_GRIMTOTEM_RUFFIAN       = 11910,
    NPC_GRIMTOTEM_BRUTE         = 11912,
    NPC_GRIMTOTEM_SORCERER      = 11913,

    SAY_START                   = -1000347,
    SAY_AMBUSH                  = -1000348,
    SAY_END                     = -1000349,

    QUEST_PROTECT_KAYA          = 6523
};

struct TRINITY_DLL_DECL npc_kaya_flathoofAI : public npc_escortAI
{
    npc_kaya_flathoofAI(Creature* c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        switch(i)
        {
        case 16:
            DoScriptText(SAY_AMBUSH, m_creature);
            m_creature->SummonCreature(NPC_GRIMTOTEM_BRUTE, -48.53, -503.34, -46.31, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            m_creature->SummonCreature(NPC_GRIMTOTEM_RUFFIAN, -38.85, -503.77, -45.90, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            m_creature->SummonCreature(NPC_GRIMTOTEM_SORCERER, -36.37, -496.23, -45.71, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            break;
        case 18: m_creature->SetInFront(pPlayer);
            DoScriptText(SAY_END, m_creature, pPlayer);
            if (pPlayer && pPlayer->GetTypeId() == TYPEID_PLAYER)
                CAST_PLR(pPlayer)->GroupEventHappens(QUEST_PROTECT_KAYA, m_creature);
            break;
        }
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void Reset(){}
};

bool QuestAccept_npc_kaya_flathoof(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_PROTECT_KAYA)
    {
        if (npc_escortAI* pEscortAI = CAST_AI(npc_kaya_flathoofAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());

        DoScriptText(SAY_START, pCreature);
        pCreature->setFaction(113);
        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
    }
    return true;
}

CreatureAI* GetAI_npc_kaya_flathoofAI(Creature* pCreature)
{
    return new npc_kaya_flathoofAI(pCreature);
}

/*######
## AddSC
######*/

void AddSC_stonetalon_mountains()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_braug_dimspirit";
    newscript->pGossipHello = &GossipHello_npc_braug_dimspirit;
    newscript->pGossipSelect = &GossipSelect_npc_braug_dimspirit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_kaya_flathoof";
    newscript->GetAI = &GetAI_npc_kaya_flathoofAI;
    newscript->pQuestAccept = &QuestAccept_npc_kaya_flathoof;
    newscript->RegisterSelf();
}


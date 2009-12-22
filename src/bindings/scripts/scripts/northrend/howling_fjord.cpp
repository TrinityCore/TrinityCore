/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: Sholazar_Basin
SD%Complete: 100
SDComment: Quest support: 11253, 11241.
SDCategory: howling_fjord
EndScriptData */

/* ContentData
npc_plaguehound_tracker
npc_apothecary_hanes
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## npc_apothecary_hanes
######*/
enum Entries
{
    NPC_APOTHECARY_HANES         = 23784,
    FACTION_ESCORTEE_A           = 774,
    FACTION_ESCORTEE_H           = 775,
    NPC_HANES_FIRE_TRIGGER       = 23968,
    QUEST_TRAIL_OF_FIRE          = 11241,
    SPELL_COSMETIC_LOW_POLY_FIRE = 56274
};

bool QuestAccept_npc_apothecary_hanes(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_TRAIL_OF_FIRE)
    {
        switch (pPlayer->GetTeam())
        {
            case ALLIANCE:
                pCreature->setFaction(FACTION_ESCORTEE_A);
                break;
            case HORDE:
                pCreature->setFaction(FACTION_ESCORTEE_H);
                break;
        }
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}

struct TRINITY_DLL_DECL npc_Apothecary_HanesAI : public npc_escortAI
{
    npc_Apothecary_HanesAI(Creature* pCreature) : npc_escortAI(pCreature){}
    uint32 PotTimer;

    void Reset ()
    {
        SetDespawnAtFar(false);
        PotTimer = 10000; //10 sec cooldown on potion
    }

    void JustDied(Unit* killer)
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->FailQuest(QUEST_TRAIL_OF_FIRE);
    }

    void UpdateEscortAI(const uint32 diff)
    {
        if(HealthBelowPct(75))
        {
            if (PotTimer <= diff)
            {
                DoCast(me, 17534, true);
                PotTimer = 10000;
            } else PotTimer -= diff;
        }
        if (GetAttack() && UpdateVictim())
            DoMeleeAttackIfReady();
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;
        switch(i)
        {
            case 1:
                me->SetReactState(REACT_AGGRESSIVE);
                SetRun(true);
                break;
            case 23:
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_TRAIL_OF_FIRE, m_creature);
                me->ForcedDespawn();
                break;
            case 5:
                if (Unit* Trigger = m_creature->FindNearestCreature(NPC_HANES_FIRE_TRIGGER,10.0f))
                    Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                SetRun(false);
                break;
            case 6:
                if (Unit* Trigger = m_creature->FindNearestCreature(NPC_HANES_FIRE_TRIGGER,10.0f))
                    Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                SetRun(true);
                break;
            case 8:
                if (Unit* Trigger = m_creature->FindNearestCreature(NPC_HANES_FIRE_TRIGGER,10.0f))
                    Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                SetRun(false);
                break;
            case 9:
                if (Unit* Trigger = m_creature->FindNearestCreature(NPC_HANES_FIRE_TRIGGER,10.0f))
                    Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                break;
            case 10:
                SetRun(true);
                break;
            case 13:
                SetRun(false);
                break;
            case 14:
                if (Unit* Trigger = m_creature->FindNearestCreature(NPC_HANES_FIRE_TRIGGER,10.0f))
                    Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                SetRun(true);
                break;
        }
    }
};
CreatureAI* GetAI_npc_apothecary_hanes(Creature* pCreature)
{
    return new npc_Apothecary_HanesAI(pCreature);
}
/*######
## npc_plaguehound_tracker
######*/

enum ePlaguehound
{
    QUEST_SNIFF_OUT_ENEMY        = 11253
};

struct TRINITY_DLL_DECL npc_plaguehound_trackerAI : public npc_escortAI
{
    npc_plaguehound_trackerAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset()
    {
        InitScriptData();
    }

    void InitScriptData()
    {
        Player* pPlayer = NULL;
        if(me->isSummon())
            if(Unit* summoner = CAST_SUM(me)->GetSummoner())
                if(summoner->GetTypeId() == TYPEID_PLAYER)
                    pPlayer = CAST_PLR(summoner);

        if (!pPlayer)
            return;

        me->SetUnitMovementFlags(MOVEMENTFLAG_WALK_MODE);
        Start(false, false, pPlayer->GetGUID());
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = NULL;
        if(me->isSummon())
            if(Unit* summoner = CAST_SUM(me)->GetSummoner())
                if(summoner->GetTypeId() == TYPEID_PLAYER)
                    pPlayer = CAST_PLR(summoner);

        if (!pPlayer)
            return;

        switch(i)
        {
        case 26:
            me->ForcedDespawn();
            break;
        }
    }
};

CreatureAI* GetAI_npc_plaguehound_tracker(Creature* pCreature)
{
    return new npc_plaguehound_trackerAI(pCreature);
}

/*######
## npc_razael_and_lyana
######*/

#define GOSSIP_RAZAEL_REPORT "High Executor Anselm wants a report on the situation."
#define GOSSIP_LYANA_REPORT "High Executor Anselm requests your report."

enum eRazael
{
    QUEST_REPORTS_FROM_THE_FIELD = 11221,
    NPC_RAZAEL = 23998,
    NPC_LYANA = 23778,
    GOSSIP_TEXTID_RAZAEL1 = 11562,
    GOSSIP_TEXTID_RAZAEL2 = 11564,
    GOSSIP_TEXTID_LYANA1 = 11586,
    GOSSIP_TEXTID_LYANA2 = 11588
};

bool GossipHello_npc_razael_and_lyana(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_REPORTS_FROM_THE_FIELD) == QUEST_STATUS_INCOMPLETE)
        switch (pCreature->GetEntry())
        {
            case NPC_RAZAEL:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_REPORTS_FROM_THE_FIELD, NPC_RAZAEL))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_RAZAEL_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_RAZAEL1, pCreature->GetGUID());
                    return true;
                }
            break;
            case NPC_LYANA:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_REPORTS_FROM_THE_FIELD, NPC_LYANA))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LYANA_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LYANA1, pCreature->GetGUID());
                    return true;
                }
            break;
        }
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_razael_and_lyana(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_RAZAEL2, pCreature->GetGUID());
            pPlayer->TalkedToCreature(NPC_RAZAEL, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LYANA2, pCreature->GetGUID());
            pPlayer->TalkedToCreature(NPC_LYANA, pCreature->GetGUID());
            break;
    }
    return true;
}

/*######
## npc_mcgoyver
######*/

#define GOSSIP_ITEM_MG_I  "Walt sent me to pick up some dark iron ingots."
#define GOSSIP_ITEM_MG_II "Yarp."

enum eMcGoyver
{
    QUEST_WE_CAN_REBUILD_IT             = 11483,

    SPELL_CREATURE_DARK_IRON_INGOTS     = 44512,
    SPELL_TAXI_EXPLORERS_LEAGUE         = 44280,

    GOSSIP_TEXTID_MCGOYVER              = 12193
};

bool GossipHello_npc_mcgoyver(Player* pPlayer, Creature* pCreature)
{
    if(pPlayer->GetQuestStatus(QUEST_WE_CAN_REBUILD_IT) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_MG_I, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_mcgoyver(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_MG_II, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_MCGOYVER, pCreature->GetGUID());
            pPlayer->CastSpell(pPlayer, SPELL_CREATURE_DARK_IRON_INGOTS, true);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CastSpell(pPlayer, SPELL_TAXI_EXPLORERS_LEAGUE, true);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
    }
    return true;
}

void AddSC_howling_fjord()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_apothecary_hanes";
    newscript->GetAI = &GetAI_npc_apothecary_hanes;
    newscript->pQuestAccept = &QuestAccept_npc_apothecary_hanes;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_plaguehound_tracker";
    newscript->GetAI = &GetAI_npc_plaguehound_tracker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_razael_and_lyana";
    newscript->pGossipHello =  &GossipHello_npc_razael_and_lyana;
    newscript->pGossipSelect = &GossipSelect_npc_razael_and_lyana;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mcgoyver";
    newscript->pGossipHello = &GossipHello_npc_mcgoyver;
    newscript->pGossipSelect = &GossipSelect_npc_mcgoyver;
    newscript->RegisterSelf();
 }

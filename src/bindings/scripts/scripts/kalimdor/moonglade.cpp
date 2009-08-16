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
SDName: Moonglade
SD%Complete: 100
SDComment: Quest support: 30, 272, 5929, 5930, 10965. Special Flight Paths for Druid class.
SDCategory: Moonglade
EndScriptData */

/* ContentData
npc_bunthen_plainswind
npc_great_bear_spirit
npc_silva_filnaveth
npc_clintar_spirit
npc_clintar_dreamwalker
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## npc_bunthen_plainswind
######*/

enum
{
    QUEST_SEA_LION_HORDE        = 30,
    QUEST_SEA_LION_ALLY         = 272,
    TAXI_PATH_ID_ALLY           = 315,
    TAXI_PATH_ID_HORDE          = 316
};

#define GOSSIP_ITEM_THUNDER     "I'd like to fly to Thunder Bluff."
#define GOSSIP_ITEM_AQ_END      "Do you know where I can find Half Pendant of Aquatic Endurance?"

bool GossipHello_npc_bunthen_plainswind(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->getClass() != CLASS_DRUID)
        pPlayer->SEND_GOSSIP_MENU(4916, pCreature->GetGUID());
    else if (pPlayer->GetTeam() != HORDE)
    {
        if (pPlayer->GetQuestStatus(QUEST_SEA_LION_ALLY) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_END, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        pPlayer->SEND_GOSSIP_MENU(4917, pCreature->GetGUID());
    }
    else if (pPlayer->getClass() == CLASS_DRUID && pPlayer->GetTeam() == HORDE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THUNDER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (pPlayer->GetQuestStatus(QUEST_SEA_LION_HORDE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_END, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        pPlayer->SEND_GOSSIP_MENU(4918, pCreature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_bunthen_plainswind(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pPlayer->getClass() == CLASS_DRUID && pPlayer->GetTeam() == HORDE)
                pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_HORDE);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->SEND_GOSSIP_MENU(5373, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->SEND_GOSSIP_MENU(5376, pCreature->GetGUID());
            break;
    }
    return true;
}

/*######
## npc_great_bear_spirit
######*/

#define GOSSIP_BEAR1 "What do you represent, spirit?"
#define GOSSIP_BEAR2 "I seek to understand the importance of strength of the body."
#define GOSSIP_BEAR3 "I seek to understand the importance of strength of the heart."
#define GOSSIP_BEAR4 "I have heard your words, Great Bear Spirit, and I understand. I now seek your blessings to fully learn the way of the Claw."

bool GossipHello_npc_great_bear_spirit(Player* pPlayer, Creature* pCreature)
{
    //ally or horde quest
    if (pPlayer->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(4719, pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(4718, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_great_bear_spirit(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(4721, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(4733, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(4734, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->SEND_GOSSIP_MENU(4735, pCreature->GetGUID());
            if (pPlayer->GetQuestStatus(5929)==QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(5929);
            if (pPlayer->GetQuestStatus(5930)==QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(5930);
            break;
    }
    return true;
}

/*######
## npc_silva_filnaveth
######*/

#define GOSSIP_ITEM_RUTHERAN    "I'd like to fly to Rut'theran Village."
#define GOSSIP_ITEM_AQ_AGI      "Do you know where I can find Half Pendant of Aquatic Agility?"

bool GossipHello_npc_silva_filnaveth(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->getClass() != CLASS_DRUID)
        pPlayer->SEND_GOSSIP_MENU(4913, pCreature->GetGUID());
    else if (pPlayer->GetTeam() != ALLIANCE)
    {
        if (pPlayer->GetQuestStatus(QUEST_SEA_LION_HORDE) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_AGI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        pPlayer->SEND_GOSSIP_MENU(4915, pCreature->GetGUID());
    }
    else if (pPlayer->getClass() == CLASS_DRUID && pPlayer->GetTeam() == ALLIANCE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTHERAN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (pPlayer->GetQuestStatus(QUEST_SEA_LION_ALLY) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_AGI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        pPlayer->SEND_GOSSIP_MENU(4914, pCreature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_silva_filnaveth(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pPlayer->getClass() == CLASS_DRUID && pPlayer->GetTeam() == ALLIANCE)
                pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_ALLY);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->SEND_GOSSIP_MENU(5374, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->SEND_GOSSIP_MENU(5375, pCreature->GetGUID());
            break;
    }
    return true;
}

/*######
## npc_clintar_spirit
######*/

float Clintar_spirit_WP[41][5] =
{
 //pos_x   pos_y    pos_z    orien waitTime
{7465.28, -3115.46, 439.327, 0.83, 4000},
{7476.49, -3101,    443.457, 0.89, 0},
{7486.57, -3085.59, 439.478, 1.07, 0},
{7472.19, -3085.06, 443.142, 3.07, 0},
{7456.92, -3085.91, 438.862, 3.24, 0},
{7446.68, -3083.43, 438.245, 2.40, 0},
{7446.17, -3080.21, 439.826, 1.10, 6000},
{7452.41, -3085.8,  438.984, 5.78, 0},
{7469.11, -3084.94, 443.048, 6.25, 0},
{7483.79, -3085.44, 439.607, 6.25, 0},
{7491.14, -3090.96, 439.983, 5.44, 0},
{7497.62, -3098.22, 436.854, 5.44, 0},
{7498.72, -3113.41, 434.596, 4.84, 0},
{7500.06, -3122.51, 434.749, 5.17, 0},
{7504.96, -3131.53, 434.475, 4.74, 0},
{7504.31, -3133.53, 435.693, 3.84, 6000},
{7504.55, -3133.27, 435.476, 0.68, 15000},
{7501.99, -3126.01, 434.93,  1.83, 0},
{7490.76, -3114.97, 434.431, 2.51, 0},
{7479.64, -3105.51, 431.123, 1.83, 0},
{7474.63, -3086.59, 428.994, 1.83, 2000},
{7472.96, -3074.18, 427.566, 1.57, 0},
{7472.25, -3063,    428.268, 1.55, 0},
{7473.46, -3054.22, 427.588, 0.36, 0},
{7475.08, -3053.6,  428.653, 0.36, 6000},
{7474.66, -3053.56, 428.433, 3.19, 4000},
{7471.81, -3058.84, 427.073, 4.29, 0},
{7472.16, -3064.91, 427.772, 4.95, 0},
{7471.56, -3085.36, 428.924, 4.72, 0},
{7473.56, -3093.48, 429.294, 5.04, 0},
{7478.94, -3104.29, 430.638, 5.23, 0},
{7484.46, -3109.61, 432.769, 5.79, 0},
{7490.23, -3111.08, 434.431, 0.02, 0},
{7496.29, -3108,    434.783, 1.15, 0},
{7497.46, -3100.66, 436.191, 1.50, 0},
{7495.64, -3093.39, 438.349, 2.10, 0},
{7492.44, -3086.01, 440.267, 1.38, 0},
{7498.26, -3076.44, 440.808, 0.71, 0},
{7506.4,  -3067.35, 443.64,  0.77, 0},
{7518.37, -3057.42, 445.584, 0.74, 0},
{7517.51, -3056.3,  444.568, 2.49, 4500}
};

#define ASPECT_RAVEN 22915

#define ASPECT_RAVEN_SUMMON_X 7472.96
#define ASPECT_RAVEN_SUMMON_Y -3074.18
#define ASPECT_RAVEN_SUMMON_Z 427.566
#define CLINTAR_SPIRIT_SUMMON_X 7459.2275
#define CLINTAR_SPIRIT_SUMMON_Y -3122.5632
#define CLINTAR_SPIRIT_SUMMON_Z 438.9842
#define CLINTAR_SPIRIT_SUMMON_O 0.8594

#define CLINTAR_SPIRIT_SAY_START -1000286
#define CLINTAR_SPIRIT_SAY_UNDER_ATTACK_1 -1000287
#define CLINTAR_SPIRIT_SAY_UNDER_ATTACK_2 -1000288
#define CLINTAR_SPIRIT_SAY_GET_ONE -1000289
#define CLINTAR_SPIRIT_SAY_GET_TWO -1000290
#define CLINTAR_SPIRIT_SAY_GET_THREE -1000291
#define CLINTAR_SPIRIT_SAY_GET_FINAL -1000292

struct TRINITY_DLL_DECL npc_clintar_spiritAI : public npc_escortAI
{
public:
    npc_clintar_spiritAI(Creature *c) : npc_escortAI(c) {}

    uint32 Step;
    uint32 CurrWP;
    uint32 Event_Timer;
    uint32 checkPlayer_Timer;

    uint64 PlayerGUID;

    bool Event_onWait;

    void Reset()
    {
        if (!PlayerGUID)
        {
            Step = 0;
            CurrWP = 0;
            Event_Timer = 0;
            PlayerGUID = 0;
            checkPlayer_Timer = 1000;
            Event_onWait = false;
        }
    }

    void JustDied(Unit *killer)
    {
        if (!PlayerGUID)
            return;

        Player* pPlayer = Unit::GetPlayer(PlayerGUID);
        if (pPlayer && pPlayer->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->FailQuest(10965);
            PlayerGUID = 0;
            Reset();
        }
    }

    void EnterEvadeMode()
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);
        if (pPlayer && pPlayer->isInCombat() && pPlayer->getAttackerForHelper())
        {
            AttackStart(pPlayer->getAttackerForHelper());
            return;
        }
        npc_escortAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* who)
    {
        uint32 rnd = rand()%2;
        switch(rnd)
        {
            case 0: DoScriptText(CLINTAR_SPIRIT_SAY_UNDER_ATTACK_1, m_creature, who); break;
            case 1: DoScriptText(CLINTAR_SPIRIT_SAY_UNDER_ATTACK_2, m_creature, who); break;
        }
    }

    void StartEvent(Player* pPlayer)
    {
        if (!pPlayer)
            return;
        if (pPlayer->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
        {
            for(uint8 i = 0; i < 41; ++i)
            {
                AddWaypoint(i, Clintar_spirit_WP[i][0], Clintar_spirit_WP[i][1], Clintar_spirit_WP[i][2], (uint32)Clintar_spirit_WP[i][4]);
            }
            PlayerGUID = pPlayer->GetGUID();
            Start(true,false,PlayerGUID);
        }
        return;
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (!PlayerGUID)
        {
            m_creature->setDeathState(JUST_DIED);
            return;
        }

        if (!m_creature->isInCombat() && !Event_onWait)
        {
            if (checkPlayer_Timer < diff)
            {
                Player* pPlayer = Unit::GetPlayer(PlayerGUID);
                if (pPlayer && pPlayer->isInCombat() && pPlayer->getAttackerForHelper())
                    AttackStart(pPlayer->getAttackerForHelper());
                checkPlayer_Timer = 1000;
            }else checkPlayer_Timer -= diff;
        }

        if (Event_onWait && Event_Timer < diff)
        {

            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            if (!pPlayer || (pPlayer && pPlayer->GetQuestStatus(10965) == QUEST_STATUS_NONE))
            {
                m_creature->setDeathState(JUST_DIED);
                return;
            }

            switch(CurrWP)
            {
                case 0:
                    switch(Step)
                    {
                        case 0:
                            m_creature->Say(CLINTAR_SPIRIT_SAY_START,0,PlayerGUID);
                            Event_Timer = 8000;
                            Step = 1;
                            break;
                        case 1:
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 6:
                    switch(Step)
                    {
                        case 0:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                            Event_Timer = 5000;
                            Step = 1;
                            break;
                        case 1:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                            DoScriptText(CLINTAR_SPIRIT_SAY_GET_ONE, m_creature, pPlayer);
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 15:
                    switch(Step)
                    {
                        case 0:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                            Event_Timer = 5000;
                            Step = 1;
                            break;
                        case 1:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 16:
                    switch(Step)
                    {
                        case 0:
                            DoScriptText(CLINTAR_SPIRIT_SAY_GET_TWO, m_creature, pPlayer);
                            Event_Timer = 15000;
                            Step = 1;
                            break;
                        case 1:
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 20:
                    switch(Step)
                    {
                        case 0:
                            {
                            Creature *mob = m_creature->SummonCreature(ASPECT_RAVEN, ASPECT_RAVEN_SUMMON_X, ASPECT_RAVEN_SUMMON_Y, ASPECT_RAVEN_SUMMON_Z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);
                            if (mob)
                            {
                                mob->AddThreat(m_creature,10000.0f);
                                mob->AI()->AttackStart(m_creature);
                            }
                            Event_Timer = 2000;
                            Step = 1;
                            break;
                            }
                        case 1:
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 24:
                    switch(Step)
                    {
                        case 0:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                            Event_Timer = 5000;
                            Step = 1;
                            break;
                        case 1:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 25:
                    switch(Step)
                    {
                        case 0:
                            DoScriptText(CLINTAR_SPIRIT_SAY_GET_THREE, m_creature, pPlayer);
                            Event_Timer = 4000;
                            Step = 1;
                            break;
                        case 1:
                            Event_onWait = false;
                            break;
                    }
                    break;
                case 40:
                    switch(Step)
                    {
                        case 0:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 2);
                            DoScriptText(CLINTAR_SPIRIT_SAY_GET_FINAL, m_creature, pPlayer);
                            pPlayer->CompleteQuest(10965);
                            Event_Timer = 1500;
                            Step = 1;
                            break;
                        case 1:
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                            Event_Timer = 3000;
                            Step = 2;
                            break;
                        case 2:
                            pPlayer->TalkedToCreature(m_creature->GetEntry(), m_creature->GetGUID());
                            PlayerGUID = 0;
                            Reset();
                            m_creature->setDeathState(JUST_DIED);
                            break;
                    }
                    break;
                default:
                    Event_onWait = false;
                    break;
            }

        } else if (Event_onWait) Event_Timer -= diff;
    }

    void WaypointReached(uint32 id)
    {
        CurrWP = id;
        Event_Timer = 0;
        Step = 0;
        Event_onWait = true;
    }
};

CreatureAI* GetAI_npc_clintar_spirit(Creature* pCreature)
{
    return new npc_clintar_spiritAI (pCreature);
}

/*####
# npc_clintar_dreamwalker
####*/

#define CLINTAR_SPIRIT 22916

bool QuestAccept_npc_clintar_dreamwalker(Player* pPlayer, Creature* pCreature, Quest const *quest)
{
    if (quest->GetQuestId() == 10965)
    {
        Creature *clintar_spirit = pCreature->SummonCreature(CLINTAR_SPIRIT, CLINTAR_SPIRIT_SUMMON_X, CLINTAR_SPIRIT_SUMMON_Y, CLINTAR_SPIRIT_SUMMON_Z, CLINTAR_SPIRIT_SUMMON_O, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 100000);
        if (clintar_spirit)
            CAST_AI(npc_clintar_spiritAI, clintar_spirit->AI())->StartEvent(pPlayer);
    }
    return true;
}

/*####
#
####*/

void AddSC_moonglade()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_bunthen_plainswind";
    newscript->pGossipHello =  &GossipHello_npc_bunthen_plainswind;
    newscript->pGossipSelect = &GossipSelect_npc_bunthen_plainswind;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_great_bear_spirit";
    newscript->pGossipHello =  &GossipHello_npc_great_bear_spirit;
    newscript->pGossipSelect = &GossipSelect_npc_great_bear_spirit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_silva_filnaveth";
    newscript->pGossipHello =  &GossipHello_npc_silva_filnaveth;
    newscript->pGossipSelect = &GossipSelect_npc_silva_filnaveth;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_clintar_dreamwalker";
    newscript->pQuestAccept = &QuestAccept_npc_clintar_dreamwalker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_clintar_spirit";
    newscript->GetAI = &GetAI_npc_clintar_spirit;
    newscript->RegisterSelf();
}


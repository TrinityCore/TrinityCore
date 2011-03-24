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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_bunthen_plainswind
######*/

enum eBunthen
{
    QUEST_SEA_LION_HORDE        = 30,
    QUEST_SEA_LION_ALLY         = 272,
    TAXI_PATH_ID_ALLY           = 315,
    TAXI_PATH_ID_HORDE          = 316
};

#define GOSSIP_ITEM_THUNDER     "I'd like to fly to Thunder Bluff."
#define GOSSIP_ITEM_AQ_END      "Do you know where I can find Half Pendant of Aquatic Endurance?"

class npc_bunthen_plainswind : public CreatureScript
{
public:
    npc_bunthen_plainswind() : CreatureScript("npc_bunthen_plainswind") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
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

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
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

};

/*######
## npc_great_bear_spirit
######*/

#define GOSSIP_BEAR1 "What do you represent, spirit?"
#define GOSSIP_BEAR2 "I seek to understand the importance of strength of the body."
#define GOSSIP_BEAR3 "I seek to understand the importance of strength of the heart."
#define GOSSIP_BEAR4 "I have heard your words, Great Bear Spirit, and I understand. I now seek your blessings to fully learn the way of the Claw."

class npc_great_bear_spirit : public CreatureScript
{
public:
    npc_great_bear_spirit() : CreatureScript("npc_great_bear_spirit") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
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
                if (pPlayer->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->AreaExploredOrEventHappens(5929);
                if (pPlayer->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
                    pPlayer->AreaExploredOrEventHappens(5930);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
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

};

/*######
## npc_silva_filnaveth
######*/

#define GOSSIP_ITEM_RUTHERAN    "I'd like to fly to Rut'theran Village."
#define GOSSIP_ITEM_AQ_AGI      "Do you know where I can find Half Pendant of Aquatic Agility?"

class npc_silva_filnaveth : public CreatureScript
{
public:
    npc_silva_filnaveth() : CreatureScript("npc_silva_filnaveth") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
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

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
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

};

/*######
## npc_clintar_spirit
######*/

float Clintar_spirit_WP[41][5] =
{
 //pos_x   pos_y    pos_z    orien waitTime
{7465.28f, -3115.46f, 439.327f, 0.83f, 4000},
{7476.49f, -3101,    443.457f, 0.89f, 0},
{7486.57f, -3085.59f, 439.478f, 1.07f, 0},
{7472.19f, -3085.06f, 443.142f, 3.07f, 0},
{7456.92f, -3085.91f, 438.862f, 3.24f, 0},
{7446.68f, -3083.43f, 438.245f, 2.40f, 0},
{7446.17f, -3080.21f, 439.826f, 1.10f, 6000},
{7452.41f, -3085.8f,  438.984f, 5.78f, 0},
{7469.11f, -3084.94f, 443.048f, 6.25f, 0},
{7483.79f, -3085.44f, 439.607f, 6.25f, 0},
{7491.14f, -3090.96f, 439.983f, 5.44f, 0},
{7497.62f, -3098.22f, 436.854f, 5.44f, 0},
{7498.72f, -3113.41f, 434.596f, 4.84f, 0},
{7500.06f, -3122.51f, 434.749f, 5.17f, 0},
{7504.96f, -3131.53f, 434.475f, 4.74f, 0},
{7504.31f, -3133.53f, 435.693f, 3.84f, 6000},
{7504.55f, -3133.27f, 435.476f, 0.68f, 15000},
{7501.99f, -3126.01f, 434.93f,  1.83f, 0},
{7490.76f, -3114.97f, 434.431f, 2.51f, 0},
{7479.64f, -3105.51f, 431.123f, 1.83f, 0},
{7474.63f, -3086.59f, 428.994f, 1.83f, 2000},
{7472.96f, -3074.18f, 427.566f, 1.57f, 0},
{7472.25f, -3063,    428.268f, 1.55f, 0},
{7473.46f, -3054.22f, 427.588f, 0.36f, 0},
{7475.08f, -3053.6f,  428.653f, 0.36f, 6000},
{7474.66f, -3053.56f, 428.433f, 3.19f, 4000},
{7471.81f, -3058.84f, 427.073f, 4.29f, 0},
{7472.16f, -3064.91f, 427.772f, 4.95f, 0},
{7471.56f, -3085.36f, 428.924f, 4.72f, 0},
{7473.56f, -3093.48f, 429.294f, 5.04f, 0},
{7478.94f, -3104.29f, 430.638f, 5.23f, 0},
{7484.46f, -3109.61f, 432.769f, 5.79f, 0},
{7490.23f, -3111.08f, 434.431f, 0.02f, 0},
{7496.29f, -3108,    434.783f, 1.15f, 0},
{7497.46f, -3100.66f, 436.191f, 1.50f, 0},
{7495.64f, -3093.39f, 438.349f, 2.10f, 0},
{7492.44f, -3086.01f, 440.267f, 1.38f, 0},
{7498.26f, -3076.44f, 440.808f, 0.71f, 0},
{7506.4f,  -3067.35f, 443.64f,  0.77f, 0},
{7518.37f, -3057.42f, 445.584f, 0.74f, 0},
{7517.51f, -3056.3f,  444.568f, 2.49f, 4500}
};

#define ASPECT_RAVEN 22915

#define ASPECT_RAVEN_SUMMON_X 7472.96f
#define ASPECT_RAVEN_SUMMON_Y -3074.18f
#define ASPECT_RAVEN_SUMMON_Z 427.566f
#define CLINTAR_SPIRIT_SUMMON_X 7459.2275f
#define CLINTAR_SPIRIT_SUMMON_Y -3122.5632f
#define CLINTAR_SPIRIT_SUMMON_Z 438.9842f
#define CLINTAR_SPIRIT_SUMMON_O 0.8594f

//from -1000292 to -1000287 are signed for 7806. but all this texts ids wrong.
#define CLINTAR_SPIRIT_SAY_START -1000286
#define CLINTAR_SPIRIT_SAY_UNDER_ATTACK_1 -1000287
#define CLINTAR_SPIRIT_SAY_UNDER_ATTACK_2 -1000288
#define CLINTAR_SPIRIT_SAY_GET_ONE -1000289
#define CLINTAR_SPIRIT_SAY_GET_TWO -1000290
#define CLINTAR_SPIRIT_SAY_GET_THREE -1000291
#define CLINTAR_SPIRIT_SAY_GET_FINAL -1000292

class npc_clintar_spirit : public CreatureScript
{
public:
    npc_clintar_spirit() : CreatureScript("npc_clintar_spirit") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_clintar_spiritAI (pCreature);
    }

    struct npc_clintar_spiritAI : public npc_escortAI
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

        void JustDied(Unit * /*killer*/)
        {
            if (!PlayerGUID)
                return;

            Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);
            if (pPlayer && pPlayer->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
            {
                pPlayer->FailQuest(10965);
                PlayerGUID = 0;
                Reset();
            }
        }

        void EnterEvadeMode()
        {
            Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);
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
                case 0: DoScriptText(CLINTAR_SPIRIT_SAY_UNDER_ATTACK_1, me, who); break;
                case 1: DoScriptText(CLINTAR_SPIRIT_SAY_UNDER_ATTACK_2, me, who); break;
            }
        }

        void StartEvent(Player* pPlayer)
        {
            if (!pPlayer)
                return;
            if (pPlayer->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
            {
                for (uint8 i = 0; i < 41; ++i)
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
                me->setDeathState(JUST_DIED);
                return;
            }

            if (!me->isInCombat() && !Event_onWait)
            {
                if (checkPlayer_Timer <= diff)
                {
                    Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);
                    if (pPlayer && pPlayer->isInCombat() && pPlayer->getAttackerForHelper())
                        AttackStart(pPlayer->getAttackerForHelper());
                    checkPlayer_Timer = 1000;
                } else checkPlayer_Timer -= diff;
            }

            if (Event_onWait && Event_Timer <= diff)
            {

                Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);
                if (!pPlayer || (pPlayer && pPlayer->GetQuestStatus(10965) == QUEST_STATUS_NONE))
                {
                    me->setDeathState(JUST_DIED);
                    return;
                }

                switch(CurrWP)
                {
                    case 0:
                        switch(Step)
                        {
                            case 0:
                                me->Say(CLINTAR_SPIRIT_SAY_START,0,PlayerGUID);
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
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                Event_Timer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                DoScriptText(CLINTAR_SPIRIT_SAY_GET_ONE, me, pPlayer);
                                Event_onWait = false;
                                break;
                        }
                        break;
                    case 15:
                        switch(Step)
                        {
                            case 0:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                Event_Timer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                Event_onWait = false;
                                break;
                        }
                        break;
                    case 16:
                        switch(Step)
                        {
                            case 0:
                                DoScriptText(CLINTAR_SPIRIT_SAY_GET_TWO, me, pPlayer);
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
                                Creature *mob = me->SummonCreature(ASPECT_RAVEN, ASPECT_RAVEN_SUMMON_X, ASPECT_RAVEN_SUMMON_Y, ASPECT_RAVEN_SUMMON_Z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000);
                                if (mob)
                                {
                                    mob->AddThreat(me,10000.0f);
                                    mob->AI()->AttackStart(me);
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
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                Event_Timer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                Event_onWait = false;
                                break;
                        }
                        break;
                    case 25:
                        switch(Step)
                        {
                            case 0:
                                DoScriptText(CLINTAR_SPIRIT_SAY_GET_THREE, me, pPlayer);
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
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 2);
                                DoScriptText(CLINTAR_SPIRIT_SAY_GET_FINAL, me, pPlayer);
                                pPlayer->CompleteQuest(10965);
                                Event_Timer = 1500;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                Event_Timer = 3000;
                                Step = 2;
                                break;
                            case 2:
                                pPlayer->TalkedToCreature(me->GetEntry(), me->GetGUID());
                                PlayerGUID = 0;
                                Reset();
                                me->setDeathState(JUST_DIED);
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

};

/*####
# npc_clintar_dreamwalker
####*/

#define CLINTAR_SPIRIT 22916

class npc_clintar_dreamwalker : public CreatureScript
{
public:
    npc_clintar_dreamwalker() : CreatureScript("npc_clintar_dreamwalker") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const *quest)
    {
        if (quest->GetQuestId() == 10965)
        {
            Creature *clintar_spirit = pCreature->SummonCreature(CLINTAR_SPIRIT, CLINTAR_SPIRIT_SUMMON_X, CLINTAR_SPIRIT_SUMMON_Y, CLINTAR_SPIRIT_SUMMON_Z, CLINTAR_SPIRIT_SUMMON_O, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 100000);
            if (clintar_spirit)
                CAST_AI(npc_clintar_spirit::npc_clintar_spiritAI, clintar_spirit->AI())->StartEvent(pPlayer);
        }
        return true;
    }

};

/*####
#
####*/

void AddSC_moonglade()
{
    new npc_bunthen_plainswind();
    new npc_great_bear_spirit();
    new npc_silva_filnaveth();
    new npc_clintar_dreamwalker();
    new npc_clintar_spirit();
}

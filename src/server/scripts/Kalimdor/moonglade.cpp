/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "SpellInfo.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"

/*######
## npc_bunthen_plainswind
######*/

enum Bunthen
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CLOSE_GOSSIP_MENU();
                if (player->getClass() == CLASS_DRUID && player->GetTeam() == HORDE)
                    player->ActivateTaxiPathTo(TAXI_PATH_ID_HORDE);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->SEND_GOSSIP_MENU(5373, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                player->SEND_GOSSIP_MENU(5376, creature->GetGUID());
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->getClass() != CLASS_DRUID)
            player->SEND_GOSSIP_MENU(4916, creature->GetGUID());
        else if (player->GetTeam() != HORDE)
        {
            if (player->GetQuestStatus(QUEST_SEA_LION_ALLY) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_END, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            player->SEND_GOSSIP_MENU(4917, creature->GetGUID());
        }
        else if (player->getClass() == CLASS_DRUID && player->GetTeam() == HORDE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THUNDER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (player->GetQuestStatus(QUEST_SEA_LION_HORDE) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_END, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

            player->SEND_GOSSIP_MENU(4918, creature->GetGUID());
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(4721, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(4733, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(4734, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                player->SEND_GOSSIP_MENU(4735, creature->GetGUID());
                if (player->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE)
                    player->AreaExploredOrEventHappens(5929);
                if (player->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
                    player->AreaExploredOrEventHappens(5930);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        //ally or horde quest
        if (player->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            player->SEND_GOSSIP_MENU(4719, creature->GetGUID());
        }
        else
            player->SEND_GOSSIP_MENU(4718, creature->GetGUID());

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CLOSE_GOSSIP_MENU();
                if (player->getClass() == CLASS_DRUID && player->GetTeam() == ALLIANCE)
                    player->ActivateTaxiPathTo(TAXI_PATH_ID_ALLY);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->SEND_GOSSIP_MENU(5374, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                player->SEND_GOSSIP_MENU(5375, creature->GetGUID());
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->getClass() != CLASS_DRUID)
            player->SEND_GOSSIP_MENU(4913, creature->GetGUID());
        else if (player->GetTeam() != ALLIANCE)
        {
            if (player->GetQuestStatus(QUEST_SEA_LION_HORDE) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_AGI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            player->SEND_GOSSIP_MENU(4915, creature->GetGUID());
        }
        else if (player->getClass() == CLASS_DRUID && player->GetTeam() == ALLIANCE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTHERAN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (player->GetQuestStatus(QUEST_SEA_LION_ALLY) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AQ_AGI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

            player->SEND_GOSSIP_MENU(4914, creature->GetGUID());
        }
        return true;
    }

};

/*######
## npc_clintar_spirit
######*/

float const Clintar_spirit_WP[41][5] =
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

Position const AspectRavenSummon    = {7472.96f, -3074.18f, 427.566f, 0.0f};
Position const ClintarSpiritSummon  = {7459.2275f, -3122.5632f, 438.9842f, 0.8594f};

enum ClintarSpirit
{
    ASPECT_RAVEN                        = 22915,

    // Texts for EnterCombat, the event and the end of the event are missing
    CLINTAR_SPIRIT_SAY_START            = 0,
};

class npc_clintar_spirit : public CreatureScript
{
public:
    npc_clintar_spirit() : CreatureScript("npc_clintar_spirit") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_clintar_spiritAI (creature);
    }

    struct npc_clintar_spiritAI : public npc_escortAI
    {
    public:
        npc_clintar_spiritAI(Creature* creature) : npc_escortAI(creature)
        {
            PlayerGUID = 0;
        }

        uint8 Step;
        uint32 CurrWP;
        uint32 EventTimer;
        uint32 checkPlayerTimer;

        uint64 PlayerGUID;

        bool EventOnWait;

        void Reset()
        {
            if (!PlayerGUID)
            {
                Step = 0;
                CurrWP = 0;
                EventTimer = 0;
                PlayerGUID = 0;
                checkPlayerTimer = 1000;
                EventOnWait = false;
            }
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {            
            std::list<Player*> playerOnQuestList;
            Trinity::AnyPlayerInObjectRangeCheck checker(me, 5.0f);
            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, playerOnQuestList, checker);
            me->VisitNearbyWorldObject(5.0f, searcher);
            for (std::list<Player*>::const_iterator itr = playerOnQuestList.begin(); itr != playerOnQuestList.end(); ++itr)
            {
                // Check if found player target has active quest
                if (Player* player = (*itr))
                {
                    if (player->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
                    {
                        StartEvent(player);
                        break;
                    }
                }
                else
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (!PlayerGUID)
                return;

            Player* player = Unit::GetPlayer(*me, PlayerGUID);
            if (player && player->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
            {
                player->FailQuest(10965);
                PlayerGUID = 0;
                Reset();
            }
        }

        void EnterEvadeMode()
        {
            Player* player = Unit::GetPlayer(*me, PlayerGUID);
            if (player && player->isInCombat() && player->getAttackerForHelper())
            {
                AttackStart(player->getAttackerForHelper());
                return;
            }
            npc_escortAI::EnterEvadeMode();
        }

        void StartEvent(Player* player)
        {
            if (player && player->GetQuestStatus(10965) == QUEST_STATUS_INCOMPLETE)
            {
                for (uint8 i = 0; i < 41; ++i)
                {
                    AddWaypoint(i, Clintar_spirit_WP[i][0], Clintar_spirit_WP[i][1], Clintar_spirit_WP[i][2], (uint32)Clintar_spirit_WP[i][4]);
                }
                PlayerGUID = player->GetGUID();
                Start(true, false, PlayerGUID);
            }
            return;
        }

        void UpdateAI(uint32 const diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!PlayerGUID)
            {
                me->setDeathState(JUST_DIED);
                return;
            }

            if (!me->isInCombat() && !EventOnWait)
            {
                if (checkPlayerTimer <= diff)
                {
                    Player* player = Unit::GetPlayer(*me, PlayerGUID);
                    if (player && player->isInCombat() && player->getAttackerForHelper())
                        AttackStart(player->getAttackerForHelper());
                    checkPlayerTimer = 1000;
                } else checkPlayerTimer -= diff;
            }

            if (EventOnWait && EventTimer <= diff)
            {

                Player* player = Unit::GetPlayer(*me, PlayerGUID);
                if (!player || (player && player->GetQuestStatus(10965) == QUEST_STATUS_NONE))
                {
                    me->setDeathState(JUST_DIED);
                    return;
                }

                switch (CurrWP)
                {
                    case 0:
                        switch (Step)
                        {
                            case 0:
                                Talk(CLINTAR_SPIRIT_SAY_START, PlayerGUID);
                                EventTimer = 8000;
                                Step = 1;
                                break;
                            case 1:
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 6:
                        switch (Step)
                        {
                            case 0:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                EventTimer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                // Needs text
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 15:
                        switch (Step)
                        {
                            case 0:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                EventTimer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 16:
                        switch (Step)
                        {
                            case 0:
                                // Needs text
                                EventTimer = 15000;
                                Step = 1;
                                break;
                            case 1:
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 20:
                        switch (Step)
                        {
                            case 0:
                                if (Creature* mob = me->SummonCreature(ASPECT_RAVEN, AspectRavenSummon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000))
                                {
                                    mob->AddThreat(me, 10000.0f);
                                    mob->AI()->AttackStart(me);
                                }
                                EventTimer = 2000;
                                Step = 1;
                                break;
                            case 1:
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 24:
                        switch (Step)
                        {
                            case 0:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 133);
                                EventTimer = 5000;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 25:
                        switch (Step)
                        {
                            case 0:
                                // Needs text
                                EventTimer = 4000;
                                Step = 1;
                                break;
                            case 1:
                                EventOnWait = false;
                                break;
                        }
                        break;
                    case 40:
                        switch (Step)
                        {
                            case 0:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 2);
                                // Needs text
                                player->CompleteQuest(10965);
                                EventTimer = 1500;
                                Step = 1;
                                break;
                            case 1:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                                EventTimer = 3000;
                                Step = 2;
                                break;
                            case 2:
                                player->TalkedToCreature(me->GetEntry(), me->GetGUID());
                                PlayerGUID = 0;
                                Reset();
                                me->setDeathState(JUST_DIED);
                                break;
                        }
                        break;
                    default:
                        EventOnWait = false;
                        break;
                }

            } else if (EventOnWait) EventTimer -= diff;
        }

        void WaypointReached(uint32 waypointId)
        {
            CurrWP = waypointId;
            EventTimer = 0;
            Step = 0;
            EventOnWait = true;
        }
    };

};

/*####
# npc_omen
####*/

enum Omen
{
    NPC_OMEN                    = 15467,

    SPELL_OMEN_CLEAVE           = 15284,
    SPELL_OMEN_STARFALL         = 26540,
    SPELL_OMEN_SUMMON_SPOTLIGHT = 26392,
    SPELL_ELUNE_CANDLE          = 26374,

    GO_ELUNE_TRAP_1             = 180876,
    GO_ELUNE_TRAP_2             = 180877,

    EVENT_CAST_CLEAVE           = 1,
    EVENT_CAST_STARFALL         = 2,
    EVENT_DESPAWN               = 3,
};

class npc_omen : public CreatureScript
{
public:
    npc_omen() : CreatureScript("npc_omen") { }

    struct npc_omenAI : public ScriptedAI
    {
        npc_omenAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->GetMotionMaster()->MovePoint(1, 7549.977f, -2855.137f, 456.9678f);
        }

        EventMap events;

        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                if (Player* player = me->SelectNearestPlayer(40.0f))
                    AttackStart(player);
            }
        }

        void EnterCombat(Unit* /*attacker*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_CAST_CLEAVE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_CAST_STARFALL, urand(8000, 10000));
        }

        void JustDied(Unit* /*killer*/)
        {
            DoCast(SPELL_OMEN_SUMMON_SPOTLIGHT);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_ELUNE_CANDLE)
            {
                if (me->HasAura(SPELL_OMEN_STARFALL))
                    me->RemoveAurasDueToSpell(SPELL_OMEN_STARFALL);

                events.RescheduleEvent(EVENT_CAST_STARFALL, urand(14000, 16000));
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_CAST_CLEAVE:
                    DoCastVictim(SPELL_OMEN_CLEAVE);
                    events.ScheduleEvent(EVENT_CAST_CLEAVE, urand(8000, 10000));
                    break;
                case EVENT_CAST_STARFALL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_OMEN_STARFALL);
                    events.ScheduleEvent(EVENT_CAST_STARFALL, urand(14000, 16000));
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_omenAI(creature);
    }
};

class npc_giant_spotlight : public CreatureScript
{
public:
    npc_giant_spotlight() : CreatureScript("npc_giant_spotlight") { }

    struct npc_giant_spotlightAI : public ScriptedAI
    {
        npc_giant_spotlightAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_DESPAWN, 5*MINUTE*IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_DESPAWN)
            {
                if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_1, 5.0f))
                    trap->RemoveFromWorld();

                if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_2, 5.0f))
                    trap->RemoveFromWorld();

                if (Creature* omen = me->FindNearestCreature(NPC_OMEN, 5.0f, false))
                    omen->DespawnOrUnsummon();

                me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_giant_spotlightAI(creature);
    }
};

void AddSC_moonglade()
{
    new npc_bunthen_plainswind();
    new npc_great_bear_spirit();
    new npc_silva_filnaveth();
    new npc_clintar_spirit();
    new npc_omen();
    new npc_giant_spotlight();
}

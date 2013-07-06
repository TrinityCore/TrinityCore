/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedGossip.h"
#include "blackrock_depths.h"
#include "Player.h"
#include "WorldSession.h"

//go_shadowforge_brazier
class go_shadowforge_brazier : public GameObjectScript
{
public:
    go_shadowforge_brazier() : GameObjectScript("go_shadowforge_brazier") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
    {
        if (InstanceScript* instance = go->GetInstanceScript())
        {
            if (instance->GetData(TYPE_LYCEUM) == IN_PROGRESS)
                instance->SetData(TYPE_LYCEUM, DONE);
            else
                instance->SetData(TYPE_LYCEUM, IN_PROGRESS);
            // If used brazier open linked doors (North or South)
            if (go->GetGUID() == instance->GetData64(DATA_SF_BRAZIER_N))
                instance->HandleGameObject(instance->GetData64(DATA_GOLEM_DOOR_N), true);
            else if (go->GetGUID() == instance->GetData64(DATA_SF_BRAZIER_S))
                instance->HandleGameObject(instance->GetData64(DATA_GOLEM_DOOR_S), true);
        }
        return false;
    }
};

// npc_grimstone
enum Grimstone
{
    NPC_GRIMSTONE                                          = 10096,
    NPC_THELDREN                                           = 16059,

    //4 or 6 in total? 1+2+1 / 2+2+2 / 3+3. Depending on this, code should be changed.
    MAX_NPC_AMOUNT                                         = 4
};

uint32 RingMob[]=
{
    8925,                                                   // Dredge Worm
    8926,                                                   // Deep Stinger
    8927,                                                   // Dark Screecher
    8928,                                                   // Burrowing Thundersnout
    8933,                                                   // Cave Creeper
    8932,                                                   // Borer Beetle
};

uint32 RingBoss[]=
{
    9027,                                                   // Gorosh
    9028,                                                   // Grizzle
    9029,                                                   // Eviscerator
    9030,                                                   // Ok'thor
    9031,                                                   // Anub'shiah
    9032,                                                   // Hedrum
};

class at_ring_of_law : public AreaTriggerScript
{
public:
    at_ring_of_law() : AreaTriggerScript("at_ring_of_law") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) OVERRIDE
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (instance->GetData(TYPE_RING_OF_LAW) == IN_PROGRESS || instance->GetData(TYPE_RING_OF_LAW) == DONE)
                return false;

            instance->SetData(TYPE_RING_OF_LAW, IN_PROGRESS);
            player->SummonCreature(NPC_GRIMSTONE, 625.559f, -205.618f, -52.735f, 2.609f, TEMPSUMMON_DEAD_DESPAWN, 0);

            return false;
        }
        return false;
    }
};

// npc_grimstone
enum GrimstoneTexts
{
    SAY_TEXT1          = 0,
    SAY_TEXT2          = 1,
    SAY_TEXT3          = 2,
    SAY_TEXT4          = 3,
    SAY_TEXT5          = 4,
    SAY_TEXT6          = 5
};

/// @todo implement quest part of event (different end boss)
class npc_grimstone : public CreatureScript
{
public:
    npc_grimstone() : CreatureScript("npc_grimstone") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_grimstoneAI(creature);
    }

    struct npc_grimstoneAI : public npc_escortAI
    {
        npc_grimstoneAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            MobSpawnId = rand()%6;
        }

        InstanceScript* instance;

        uint8 EventPhase;
        uint32 Event_Timer;

        uint8 MobSpawnId;
        uint8 MobCount;
        uint32 MobDeath_Timer;

        uint64 RingMobGUID[4];
        uint64 RingBossGUID;

        bool CanWalk;

        void Reset() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            EventPhase = 0;
            Event_Timer = 1000;

            MobCount = 0;
            MobDeath_Timer = 0;

            for (uint8 i = 0; i < MAX_NPC_AMOUNT; ++i)
                RingMobGUID[i] = 0;

            RingBossGUID = 0;

            CanWalk = false;
        }

        /// @todo move them to center
        void SummonRingMob()
        {
            if (Creature* tmp = me->SummonCreature(RingMob[MobSpawnId], 608.960f, -235.322f, -53.907f, 1.857f, TEMPSUMMON_DEAD_DESPAWN, 0))
                RingMobGUID[MobCount] = tmp->GetGUID();

            ++MobCount;

            if (MobCount == MAX_NPC_AMOUNT)
                MobDeath_Timer = 2500;
        }

        /// @todo move them to center
        void SummonRingBoss()
        {
            if (Creature* tmp = me->SummonCreature(RingBoss[rand()%6], 644.300f, -175.989f, -53.739f, 3.418f, TEMPSUMMON_DEAD_DESPAWN, 0))
                RingBossGUID = tmp->GetGUID();

            MobDeath_Timer = 2500;
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    Talk(SAY_TEXT1);
                    CanWalk = false;
                    Event_Timer = 5000;
                    break;
                case 1:
                    Talk(SAY_TEXT2);
                    CanWalk = false;
                    Event_Timer = 5000;
                    break;
                case 2:
                    CanWalk = false;
                    break;
                case 3:
                    Talk(SAY_TEXT3);
                    break;
                case 4:
                    Talk(SAY_TEXT4);
                    CanWalk = false;
                    Event_Timer = 5000;
                    break;
                case 5:
                    if (instance)
                    {
                        instance->UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_GRIMSTONE, me);
                        instance->SetData(TYPE_RING_OF_LAW, DONE);
                        TC_LOG_DEBUG(LOG_FILTER_TSCR, "npc_grimstone: event reached end and set complete.");
                    }
                    break;
            }
        }

        void HandleGameObject(uint32 id, bool open)
        {
            instance->HandleGameObject(instance->GetData64(id), open);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!instance)
                return;

            if (MobDeath_Timer)
            {
                if (MobDeath_Timer <= diff)
                {
                    MobDeath_Timer = 2500;

                    if (RingBossGUID)
                    {
                        Creature* boss = Unit::GetCreature(*me, RingBossGUID);
                        if (boss && !boss->IsAlive() && boss->isDead())
                        {
                            RingBossGUID = 0;
                            Event_Timer = 5000;
                            MobDeath_Timer = 0;
                            return;
                        }
                        return;
                    }

                    for (uint8 i = 0; i < MAX_NPC_AMOUNT; ++i)
                    {
                        Creature* mob = Unit::GetCreature(*me, RingMobGUID[i]);
                        if (mob && !mob->IsAlive() && mob->isDead())
                        {
                            RingMobGUID[i] = 0;
                            --MobCount;

                            //seems all are gone, so set timer to continue and discontinue this
                            if (!MobCount)
                            {
                                Event_Timer = 5000;
                                MobDeath_Timer = 0;
                            }
                        }
                    }
                } else MobDeath_Timer -= diff;
            }

            if (Event_Timer)
            {
                if (Event_Timer <= diff)
                {
                    switch (EventPhase)
                    {
                    case 0:
                        Talk(SAY_TEXT5);
                        HandleGameObject(DATA_ARENA4, false);
                        Start(false, false);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 1:
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 2:
                        Event_Timer = 2000;
                        break;
                    case 3:
                        HandleGameObject(DATA_ARENA1, true);
                        Event_Timer = 3000;
                        break;
                    case 4:
                        CanWalk = true;
                        me->SetVisible(false);
                        SummonRingMob();
                        Event_Timer = 8000;
                        break;
                    case 5:
                        SummonRingMob();
                        SummonRingMob();
                        Event_Timer = 8000;
                        break;
                    case 6:
                        SummonRingMob();
                        Event_Timer = 0;
                        break;
                    case 7:
                        me->SetVisible(true);
                        HandleGameObject(DATA_ARENA1, false);
                        Talk(SAY_TEXT6);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 8:
                        HandleGameObject(DATA_ARENA2, true);
                        Event_Timer = 5000;
                        break;
                    case 9:
                        me->SetVisible(false);
                        SummonRingBoss();
                        Event_Timer = 0;
                        break;
                    case 10:
                        //if quest, complete
                        HandleGameObject(DATA_ARENA2, false);
                        HandleGameObject(DATA_ARENA3, true);
                        HandleGameObject(DATA_ARENA4, true);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    }
                    ++EventPhase;
                } else Event_Timer -= diff;
            }

            if (CanWalk)
                npc_escortAI::UpdateAI(diff);
           }
    };
};

// npc_phalanx
enum PhalanxSpells
{
    SPELL_THUNDERCLAP                   = 8732,
    SPELL_FIREBALLVOLLEY                = 22425,
    SPELL_MIGHTYBLOW                    = 14099
};

class npc_phalanx : public CreatureScript
{
public:
    npc_phalanx() : CreatureScript("npc_phalanx") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_phalanxAI (creature);
    }

    struct npc_phalanxAI : public ScriptedAI
    {
        npc_phalanxAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 ThunderClap_Timer;
        uint32 FireballVolley_Timer;
        uint32 MightyBlow_Timer;

        void Reset() OVERRIDE
        {
            ThunderClap_Timer = 12000;
            FireballVolley_Timer = 0;
            MightyBlow_Timer = 15000;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //ThunderClap_Timer
            if (ThunderClap_Timer <= diff)
            {
                DoCastVictim(SPELL_THUNDERCLAP);
                ThunderClap_Timer = 10000;
            } else ThunderClap_Timer -= diff;

            //FireballVolley_Timer
            if (HealthBelowPct(51))
            {
                if (FireballVolley_Timer <= diff)
                {
                    DoCastVictim(SPELL_FIREBALLVOLLEY);
                    FireballVolley_Timer = 15000;
                } else FireballVolley_Timer -= diff;
            }

            //MightyBlow_Timer
            if (MightyBlow_Timer <= diff)
            {
                DoCastVictim(SPELL_MIGHTYBLOW);
                MightyBlow_Timer = 10000;
            } else MightyBlow_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

// npc_kharan_mighthammer
enum KharamQuests
{
    QUEST_4001                          = 4001,
    QUEST_4342                          = 4342
};

#define GOSSIP_ITEM_KHARAN_1    "I need to know where the princess are, Kharan!"
#define GOSSIP_ITEM_KHARAN_2    "All is not lost, Kharan!"
#define GOSSIP_ITEM_KHARAN_3    "Gor'shak is my friend, you can trust me."
#define GOSSIP_ITEM_KHARAN_4    "Not enough, you need to tell me more."
#define GOSSIP_ITEM_KHARAN_5    "So what happened?"
#define GOSSIP_ITEM_KHARAN_6    "Continue..."
#define GOSSIP_ITEM_KHARAN_7    "So you suspect that someone on the inside was involved? That they were tipped off?"
#define GOSSIP_ITEM_KHARAN_8    "Continue with your story please."
#define GOSSIP_ITEM_KHARAN_9    "Indeed."
#define GOSSIP_ITEM_KHARAN_10   "The door is open, Kharan. You are a free man."

class npc_kharan_mighthammer : public CreatureScript
{
public:
    npc_kharan_mighthammer() : CreatureScript("npc_kharan_mighthammer") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(2475, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(2476, creature->GetGUID());
                break;

            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(2477, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(2478, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->SEND_GOSSIP_MENU(2479, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
                player->SEND_GOSSIP_MENU(2480, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
                player->SEND_GOSSIP_MENU(2481, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+8:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_10, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
                player->SEND_GOSSIP_MENU(2482, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+9:
                player->CLOSE_GOSSIP_MENU();
                if (player->GetTeam() == HORDE)
                    player->AreaExploredOrEventHappens(QUEST_4001);
                else
                    player->AreaExploredOrEventHappens(QUEST_4342);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_4001) == QUEST_STATUS_INCOMPLETE)
             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (player->GetQuestStatus(4342) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KHARAN_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);

        if (player->GetTeam() == HORDE)
            player->SEND_GOSSIP_MENU(2473, creature->GetGUID());
        else
            player->SEND_GOSSIP_MENU(2474, creature->GetGUID());

        return true;
    }
};

// npc_lokhtos_darkbargainer
enum LokhtosItems
{
    ITEM_THRORIUM_BROTHERHOOD_CONTRACT                     = 18628,
    ITEM_SULFURON_INGOT                                    = 17203
};

enum LokhtosQuests
{
    QUEST_A_BINDING_CONTRACT                               = 7604
};

enum LokhtosSpells
{
    SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND          = 23059
};

#define GOSSIP_ITEM_SHOW_ACCESS     "Show me what I have access to, Lothos."
#define GOSSIP_ITEM_GET_CONTRACT    "Get Thorium Brotherhood Contract"

class npc_lokhtos_darkbargainer : public CreatureScript
{
public:
    npc_lokhtos_darkbargainer() : CreatureScript("npc_lokhtos_darkbargainer") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CLOSE_GOSSIP_MENU();
            player->CastSpell(player, SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND, false);
        }
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor() && player->GetReputationRank(59) >= REP_FRIENDLY)
              player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_ITEM_SHOW_ACCESS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        if (player->GetQuestRewardStatus(QUEST_A_BINDING_CONTRACT) != 1 &&
            !player->HasItemCount(ITEM_THRORIUM_BROTHERHOOD_CONTRACT, 1, true) &&
            player->HasItemCount(ITEM_SULFURON_INGOT))
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GET_CONTRACT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }

        if (player->GetReputationRank(59) < REP_FRIENDLY)
            player->SEND_GOSSIP_MENU(3673, creature->GetGUID());
        else
            player->SEND_GOSSIP_MENU(3677, creature->GetGUID());

        return true;
    }
};

// npc_dughal_stormwing
enum DughalQuests
{
    QUEST_JAIL_BREAK                      = 4322
};

#define SAY_DUGHAL_FREE         "Thank you, $N! I'm free!!!"
#define GOSSIP_DUGHAL           "You're free, Dughal! Get out of here!"

/*
class npc_dughal_stormwing : public CreatureScript
{
public:
    npc_dughal_stormwing() : CreatureScript("npc_dughal_stormwing") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        npc_dughal_stormwingAI* dughal_stormwingAI = new npc_dughal_stormwingAI(creature);

        dughal_stormwingAI->AddWaypoint(0, 280.42f, -82.86f, -77.12f, 0);
        dughal_stormwingAI->AddWaypoint(1, 287.64f, -87.01f, -76.79f, 0);
        dughal_stormwingAI->AddWaypoint(2, 354.63f, -64.95f, -67.53f, 0);

        return dughal_stormwingAI;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_escort::npc_escortAI, (creature->AI()))->Start(false, true, player->GetGUID());
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            instance->SetData(DATA_QUEST_JAIL_BREAK, ENCOUNTER_STATE_IN_PROGRESS);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_JAIL_BREAK) == QUEST_STATUS_INCOMPLETE && instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DUGHAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(2846, creature->GetGUID());
        }
        return true;
    }

    struct npc_dughal_stormwingAI : public npc_escortAI
    {
        npc_dughal_stormwingAI(Creature* creature) : npc_escortAI(creature) {}

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    me->Say(SAY_DUGHAL_FREE, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 1:
                    instance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_OBJECTIVE_COMPLETED);
                    break;
                case 2:
                    me->SetVisible(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    instance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_ENDED);
                    break;
            }
        }

        void EnterCombat(Unit* who) OVERRIDE {}
        void Reset() OVERRIDE {}

        void JustDied(Unit* killer) OVERRIDE
        {
            if (IsBeingEscorted && killer == me)
            {
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                instance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_ENDED);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED) return;
            if ((instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& instance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_ENDED)
            {
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            else
            {
                me->SetVisible(true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            npc_escortAI::UpdateAI(diff);
        }
    };
};

 */

// npc_marshal_windsor
#define SAY_WINDSOR_AGGRO1          "You locked up the wrong Marshal. Prepare to be destroyed!"
#define SAY_WINDSOR_AGGRO2          "I bet you're sorry now, aren't you !?!!"
#define SAY_WINDSOR_AGGRO3          "You better hold me back $N or they are going to feel some prison house beatings."
#define SAY_WINDSOR_1               "Let's get a move on. My gear should be in the storage area up this way..."
#define SAY_WINDSOR_4_1             "Check that cell, $N. If someone is alive in there, we need to get them out."
#define SAY_WINDSOR_4_2             "Get him out of there!"
#define SAY_WINDSOR_4_3             "Good work! We're almost there, $N. This way."
#define SAY_WINDSOR_6               "This is it, $N. My stuff should be in that room. Cover me, I'm going in!"
#define SAY_WINDSOR_9               "Ah, there it is!"

enum MarshalWindsor
{
    NPC_REGINALD_WINDSOR            = 9682
};

/*
Player* playerStart;
class npc_marshal_windsor : public CreatureScript
{
public:
    npc_marshal_windsor() : CreatureScript("npc_marshal_windsor") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        npc_marshal_windsorAI* marshal_windsorAI = new npc_marshal_windsorAI(creature);

        marshal_windsorAI->AddWaypoint(0, 316.336f, -225.528f, -77.7258f, 7000);
        marshal_windsorAI->AddWaypoint(1, 316.336f, -225.528f, -77.7258f, 2000);
        marshal_windsorAI->AddWaypoint(2, 322.96f, -207.13f, -77.87f, 0);
        marshal_windsorAI->AddWaypoint(3, 281.05f, -172.16f, -75.12f, 0);
        marshal_windsorAI->AddWaypoint(4, 272.19f, -139.14f, -70.61f, 0);
        marshal_windsorAI->AddWaypoint(5, 283.62f, -116.09f, -70.21f, 0);
        marshal_windsorAI->AddWaypoint(6, 296.18f, -94.30f, -74.08f, 0);
        marshal_windsorAI->AddWaypoint(7, 294.57f, -93.11f, -74.08f, 0);
        marshal_windsorAI->AddWaypoint(8, 314.31f, -74.31f, -76.09f, 0);
        marshal_windsorAI->AddWaypoint(9, 360.22f, -62.93f, -66.77f, 0);
        marshal_windsorAI->AddWaypoint(10, 383.38f, -69.40f, -63.25f, 0);
        marshal_windsorAI->AddWaypoint(11, 389.99f, -67.86f, -62.57f, 0);
        marshal_windsorAI->AddWaypoint(12, 400.98f, -72.01f, -62.31f, 0);
        marshal_windsorAI->AddWaypoint(13, 404.22f, -62.30f, -63.50f, 2300);
        marshal_windsorAI->AddWaypoint(14, 404.22f, -62.30f, -63.50f, 1500);
        marshal_windsorAI->AddWaypoint(15, 407.65f, -51.86f, -63.96f, 0);
        marshal_windsorAI->AddWaypoint(16, 403.61f, -51.71f, -63.92f, 1000);
        marshal_windsorAI->AddWaypoint(17, 403.61f, -51.71f, -63.92f, 2000);
        marshal_windsorAI->AddWaypoint(18, 403.61f, -51.71f, -63.92f, 1000);
        marshal_windsorAI->AddWaypoint(19, 403.61f, -51.71f, -63.92f, 0);

        return marshal_windsorAI;
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == 4322)
        {
            PlayerStart = player;
            if (instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED)
            {
                CAST_AI(npc_escort::npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
                instance->SetData(DATA_QUEST_JAIL_BREAK, ENCOUNTER_STATE_IN_PROGRESS);
                creature->setFaction(11);
            }
        }
        return false;
    }

    struct npc_marshal_windsorAI : public npc_escortAI
    {
        npc_marshal_windsorAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 1:
                    me->Say(SAY_WINDSOR_1, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 7:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    me->Say(SAY_WINDSOR_4_1, LANG_UNIVERSAL, PlayerGUID);
                    IsOnHold = true;
                    break;
                case 10:
                    me->setFaction(534);
                    break;
                case 12:
                    me->Say(SAY_WINDSOR_6, LANG_UNIVERSAL, PlayerGUID);
                    instance->SetData(DATA_SUPPLY_ROOM, ENCOUNTER_STATE_IN_PROGRESS);
                    break;
                case 13:
                    me->HandleEmoteCommand(EMOTE_STATE_USESTANDING);//EMOTE_STATE_WORK
                    break;
                case 14:
                    instance->SetData(DATA_GATE_SR, 0);
                    me->setFaction(11);
                    break;
                case 16:
                    me->Say(SAY_WINDSOR_9, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 17:
                    me->HandleEmoteCommand(EMOTE_STATE_USESTANDING);//EMOTE_STATE_WORK
                    break;
                case 18:
                    instance->SetData(DATA_GATE_SC, 0);
                    break;
                case 19:
                    me->SetVisible(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SummonCreature(NPC_REGINALD_WINDSOR, 403.61f, -51.71f, -63.92f, 3.600434f, TEMPSUMMON_DEAD_DESPAWN, 0);
                    instance->SetData(DATA_SUPPLY_ROOM, ENCOUNTER_STATE_ENDED);
                    break;
            }
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            switch (urand(0, 2))
            {
                case 0:
                    me->Say(SAY_WINDSOR_AGGRO1, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 1:
                    me->Say(SAY_WINDSOR_AGGRO2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 2:
                    me->Say(SAY_WINDSOR_AGGRO3, LANG_UNIVERSAL, PlayerGUID);
                    break;
            }
        }

        void Reset() OVERRIDE {}

        void JustDied(Unit* slayer) OVERRIDE
        {
            instance->SetData(DATA_QUEST_JAIL_BREAK, ENCOUNTER_STATE_FAILED);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED)
                return;

            if (instance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_OBJECTIVE_COMPLETED)
                SetEscortPaused(false);

            if (!instance->GetData(DATA_GATE_D) && instance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_NOT_STARTED)
            {
                me->Say(SAY_WINDSOR_4_2, LANG_UNIVERSAL, PlayerGUID);
                instance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_BEFORE_START);
            }
            if (instance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_OBJECTIVE_COMPLETED)
            {
                me->Say(SAY_WINDSOR_4_3, LANG_UNIVERSAL, PlayerGUID);
                instance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_ENDED);
            }
            if ((instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& instance->GetData(DATA_SUPPLY_ROOM) == ENCOUNTER_STATE_ENDED)
            {
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            else
            {
                me->SetVisible(true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            npc_escortAI::UpdateAI(diff);
        }
    };
};

  */

// npc_marshal_reginald_windsor
#define SAY_REGINALD_WINDSOR_0_1    "Can you feel the power, $N??? It's time to ROCK!"
#define SAY_REGINALD_WINDSOR_0_2    "Now we just have to free Tobias and we can get out of here. This way!"
#define SAY_REGINALD_WINDSOR_5_1    "Open it."
#define SAY_REGINALD_WINDSOR_5_2    "I never did like those two. Let's get moving."
#define SAY_REGINALD_WINDSOR_7_1    "Open it and be careful this time!"
#define SAY_REGINALD_WINDSOR_7_2    "That intolerant dirtbag finally got what was coming to him. Good riddance!"
#define SAY_REGINALD_WINDSOR_7_3    "Alright, let's go."
#define SAY_REGINALD_WINDSOR_13_1   "Open it. We need to hurry up. I can smell those Dark Irons coming a mile away and I can tell you one thing, they're COMING!"
#define SAY_REGINALD_WINDSOR_13_2   "Administering fists of fury on Crest Killer!"
#define SAY_REGINALD_WINDSOR_13_3   "He has to be in the last cell. Unless... they killed him."
#define SAY_REGINALD_WINDSOR_14_1   "Get him out of there!"
#define SAY_REGINALD_WINDSOR_14_2   "Excellent work, $N. Let's find the exit. I think I know the way. Follow me!"
#define SAY_REGINALD_WINDSOR_20_1   "We made it!"
#define SAY_REGINALD_WINDSOR_20_2   "Meet me at Maxwell's encampment. We'll go over the next stages of the plan there and figure out a way to decode my tablets without the decryption ring."

enum MarshalReginaldWindor
{
    NPC_SHILL_DINGER                = 9678,
    NPC_CREST_KILLER                = 9680
};

/*
int wp = 0;
class npc_marshal_reginald_windsor : public CreatureScript
{
public:
    npc_marshal_reginald_windsor() : CreatureScript("npc_marshal_reginald_windsor") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        npc_marshal_reginald_windsorAI* marshal_reginald_windsorAI = new npc_marshal_reginald_windsorAI(creature);

        marshal_reginald_windsorAI->AddWaypoint(0, 403.61f, -52.71f, -63.92f, 4000);
        marshal_reginald_windsorAI->AddWaypoint(1, 403.61f, -52.71f, -63.92f, 4000);
        marshal_reginald_windsorAI->AddWaypoint(2, 406.33f, -54.87f, -63.95f, 0);
        marshal_reginald_windsorAI->AddWaypoint(3, 407.99f, -73.91f, -62.26f, 0);
        marshal_reginald_windsorAI->AddWaypoint(4, 557.03f, -119.71f, -61.83f, 0);
        marshal_reginald_windsorAI->AddWaypoint(5, 573.40f, -124.39f, -65.07f, 0);
        marshal_reginald_windsorAI->AddWaypoint(6, 593.91f, -130.29f, -69.25f, 0);
        marshal_reginald_windsorAI->AddWaypoint(7, 593.21f, -132.16f, -69.25f, 0);
        marshal_reginald_windsorAI->AddWaypoint(8, 593.21f, -132.16f, -69.25f, 3000);
        marshal_reginald_windsorAI->AddWaypoint(9, 622.81f, -135.55f, -71.92f, 0);
        marshal_reginald_windsorAI->AddWaypoint(10, 634.68f, -151.29f, -70.32f, 0);
        marshal_reginald_windsorAI->AddWaypoint(11, 635.06f, -153.25f, -70.32f, 0);
        marshal_reginald_windsorAI->AddWaypoint(12, 635.06f, -153.25f, -70.32f, 3000);
        marshal_reginald_windsorAI->AddWaypoint(13, 635.06f, -153.25f, -70.32f, 1500);
        marshal_reginald_windsorAI->AddWaypoint(14, 655.25f, -172.39f, -73.72f, 0);
        marshal_reginald_windsorAI->AddWaypoint(15, 654.79f, -226.30f, -83.06f, 0);
        marshal_reginald_windsorAI->AddWaypoint(16, 622.85f, -268.85f, -83.96f, 0);
        marshal_reginald_windsorAI->AddWaypoint(17, 579.45f, -275.56f, -80.44f, 0);
        marshal_reginald_windsorAI->AddWaypoint(18, 561.19f, -266.85f, -75.59f, 0);
        marshal_reginald_windsorAI->AddWaypoint(19, 547.91f, -253.92f, -70.34f, 0);
        marshal_reginald_windsorAI->AddWaypoint(20, 549.20f, -252.40f, -70.34f, 0);
        marshal_reginald_windsorAI->AddWaypoint(21, 549.20f, -252.40f, -70.34f, 4000);
        marshal_reginald_windsorAI->AddWaypoint(22, 555.33f, -269.16f, -74.40f, 0);
        marshal_reginald_windsorAI->AddWaypoint(23, 554.31f, -270.88f, -74.40f, 0);
        marshal_reginald_windsorAI->AddWaypoint(24, 554.31f, -270.88f, -74.40f, 4000);
        marshal_reginald_windsorAI->AddWaypoint(25, 536.10f, -249.60f, -67.47f, 0);
        marshal_reginald_windsorAI->AddWaypoint(26, 520.94f, -216.65f, -59.28f, 0);
        marshal_reginald_windsorAI->AddWaypoint(27, 505.99f, -148.74f, -62.17f, 0);
        marshal_reginald_windsorAI->AddWaypoint(28, 484.21f, -56.24f, -62.43f, 0);
        marshal_reginald_windsorAI->AddWaypoint(29, 470.39f, -6.01f, -70.10f, 0);
        marshal_reginald_windsorAI->AddWaypoint(30, 451.27f, 30.85f, -70.07f, 0);
        marshal_reginald_windsorAI->AddWaypoint(31, 452.45f, 29.85f, -70.37f, 1500);
        marshal_reginald_windsorAI->AddWaypoint(32, 452.45f, 29.85f, -70.37f, 7000);
        marshal_reginald_windsorAI->AddWaypoint(33, 452.45f, 29.85f, -70.37f, 10000);
        marshal_reginald_windsorAI->AddWaypoint(34, 451.27f, 31.85f, -70.07f, 0);

        return marshal_reginald_windsorAI;
    }

    struct npc_marshal_reginald_windsorAI : public npc_escortAI
    {
        npc_marshal_reginald_windsorAI(Creature* creature) : npc_escortAI(creature)
        {
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            wp = waypointId;
            switch (waypointId)
            {
                case 0:
                    me->setFaction(11);
                    me->Say(SAY_REGINALD_WINDSOR_0_1, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 1:
                    me->Say(SAY_REGINALD_WINDSOR_0_2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 7:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    me->Say(SAY_REGINALD_WINDSOR_5_1, LANG_UNIVERSAL, PlayerGUID);
                    IsOnHold=true;
                    break;
                case 8:
                    me->Say(SAY_REGINALD_WINDSOR_5_2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 11:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    me->Say(SAY_REGINALD_WINDSOR_7_1, LANG_UNIVERSAL, PlayerGUID);
                    IsOnHold=true;
                    break;
                case 12:
                    me->Say(SAY_REGINALD_WINDSOR_7_2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 13:
                    me->Say(SAY_REGINALD_WINDSOR_7_3, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 20:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    me->Say(SAY_REGINALD_WINDSOR_13_1, LANG_UNIVERSAL, PlayerGUID);
                    IsOnHold=true;
                    break;
                case 21:
                    me->Say(SAY_REGINALD_WINDSOR_13_3, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 23:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    me->Say(SAY_REGINALD_WINDSOR_14_1, LANG_UNIVERSAL, PlayerGUID);
                    IsOnHold=true;
                    break;
                case 24:
                    me->Say(SAY_REGINALD_WINDSOR_14_2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 31:
                    me->Say(SAY_REGINALD_WINDSOR_20_1, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 32:
                    me->Say(SAY_REGINALD_WINDSOR_20_2, LANG_UNIVERSAL, PlayerGUID);
                    PlayerStart->GroupEventHappens(QUEST_JAIL_BREAK, me);
                    instance->SetData(DATA_SHILL, ENCOUNTER_STATE_ENDED);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(4322) == QUEST_STATUS_INCOMPLETE)
                {
                    float Radius = 10.0f;
                    if (me->IsWithinDistInMap(who, Radius))
                    {
                        SetEscortPaused(false);
                        Start(true, false, who->GetGUID());
                    }
                }
            }
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            switch (urand(0, 2))
            {
                case 0:
                    me->Say(SAY_WINDSOR_AGGRO1, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 1:
                    me->Say(SAY_WINDSOR_AGGRO2, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 2:
                    me->Say(SAY_WINDSOR_AGGRO3, LANG_UNIVERSAL, PlayerGUID);
                    break;
            }
        }
        void Reset() OVERRIDE {}

        void JustDied(Unit* slayer) OVERRIDE
        {
            instance->SetData(DATA_QUEST_JAIL_BREAK, ENCOUNTER_STATE_FAILED);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED)
                return;

            if (wp == 7)
            {
                if (!instance->GetData(DATA_GATE_J) && instance->GetData(DATA_JAZ) == ENCOUNTER_STATE_NOT_STARTED)
                {
                    instance->SetData(DATA_NPC_JAZ, 1);
                    instance->SetData(DATA_JAZ, ENCOUNTER_STATE_IN_PROGRESS);
                }
                if (instance->GetData(DATA_NPC_JAZ) && instance->GetData(DATA_NPC_OGRABISI) && instance->GetData(DATA_JAZ) == ENCOUNTER_STATE_IN_PROGRESS)
                {
                    SetEscortPaused(false);
                    instance->SetData(DATA_JAZ, ENCOUNTER_STATE_ENDED);
                }
            }
            else if (wp == 11)
            {
                if (!instance->GetData(DATA_GATE_S) && instance->GetData(DATA_SHILL) == ENCOUNTER_STATE_NOT_STARTED)
                {
                    instance->SetData(DATA_NPC_SHILL, 1);
                    instance->SetData(DATA_SHILL, ENCOUNTER_STATE_IN_PROGRESS);
                }
                if (instance->GetData(DATA_NPC_SHILL) && instance->GetData(DATA_SHILL) == ENCOUNTER_STATE_IN_PROGRESS)
                {
                    instance->SetData(DATA_SHILL, ENCOUNTER_STATE_ENDED);
                    SetEscortPaused(false);
                }
            }
            else if (wp == 20)
            {
                if (!instance->GetData(DATA_GATE_C) && instance->GetData(DATA_CREST) == ENCOUNTER_STATE_NOT_STARTED)
                {
                    instance->SetData(DATA_NPC_CREST, 1);
                    me->Say(SAY_REGINALD_WINDSOR_13_2, LANG_UNIVERSAL, PlayerGUID);
                    instance->SetData(DATA_CREST, ENCOUNTER_STATE_IN_PROGRESS);
                }
                if (instance->GetData(DATA_NPC_CREST) && instance->GetData(DATA_CREST) == ENCOUNTER_STATE_IN_PROGRESS)
                {
                    SetEscortPaused(false);
                    instance->SetData(DATA_CREST, ENCOUNTER_STATE_ENDED);
                }
            }
            if (instance->GetData(DATA_TOBIAS) == ENCOUNTER_STATE_OBJECTIVE_COMPLETED) SetEscortPaused(false);
            npc_escortAI::UpdateAI(diff);
        }
    };
};
*/

// npc_tobias_seecher
#define SAY_TOBIAS_FREE         "Thank you! I will run for safety immediately!"

/*
class npc_tobias_seecher : public CreatureScript
{
public:
    npc_tobias_seecher() : CreatureScript("npc_tobias_seecher") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        npc_tobias_seecherAI* tobias_seecherAI = new npc_tobias_seecherAI(creature);

        tobias_seecherAI->AddWaypoint(0, 549.21f, -281.07f, -75.27f);
        tobias_seecherAI->AddWaypoint(1, 554.39f, -267.39f, -73.68f);
        tobias_seecherAI->AddWaypoint(2, 533.59f, -249.38f, -67.04f);
        tobias_seecherAI->AddWaypoint(3, 519.44f, -217.02f, -59.34f);
        tobias_seecherAI->AddWaypoint(4, 506.55f, -153.49f, -62.34f);

        return tobias_seecherAI;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_escort::npc_escortAI, (creature->AI()))->Start(false, true, player->GetGUID());
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            instance->SetData(DATA_TOBIAS, ENCOUNTER_STATE_IN_PROGRESS);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_JAIL_BREAK) == QUEST_STATUS_INCOMPLETE && instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Get out of here, Tobias, you're free!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(2847, creature->GetGUID());
        }
        return true;
    }

    struct npc_tobias_seecherAI : public npc_escortAI
    {
        npc_tobias_seecherAI(Creature* creature) : npc_escortAI(creature) {}

        void EnterCombat(Unit* who) OVERRIDE {}
        void Reset() OVERRIDE {}

        void JustDied(Unit* killer) OVERRIDE
        {
            if (IsBeingEscorted && killer == me)
            {
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                instance->SetData(DATA_TOBIAS, ENCOUNTER_STATE_ENDED);
            }
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    me->Say(SAY_TOBIAS_FREE, LANG_UNIVERSAL, PlayerGUID);
                    break;
                case 2:
                    instance->SetData(DATA_TOBIAS, ENCOUNTER_STATE_OBJECTIVE_COMPLETED);
                    break;
                case 4:
                    me->SetVisible(false);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    instance->SetData(DATA_TOBIAS, ENCOUNTER_STATE_ENDED);
                    break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED)
                return;

            if ((instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || instance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& instance->GetData(DATA_TOBIAS) == ENCOUNTER_STATE_ENDED)
            {
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            else
            {
                me->SetVisible(true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            npc_escortAI::UpdateAI(diff);
        }
    };
};

*/

// npc_rocknot
enum RocknotSays
{
    SAY_GOT_BEER                       = 0
};

enum RocknotSpells
{
    SPELL_DRUNKEN_RAGE                 = 14872
};

enum RocknotQuests
{
    QUEST_ALE                          = 4295
};

class npc_rocknot : public CreatureScript
{
public:
    npc_rocknot() : CreatureScript("npc_rocknot") { }

    bool OnQuestReward(Player* /*player*/, Creature* creature, Quest const* quest, uint32 /*item*/) OVERRIDE
    {
        InstanceScript* instance = creature->GetInstanceScript();
        if (!instance)
            return true;

        if (instance->GetData(TYPE_BAR) == DONE || instance->GetData(TYPE_BAR) == SPECIAL)
            return true;

        if (quest->GetQuestId() == QUEST_ALE)
        {
            if (instance->GetData(TYPE_BAR) != IN_PROGRESS)
                instance->SetData(TYPE_BAR, IN_PROGRESS);

            instance->SetData(TYPE_BAR, SPECIAL);

            //keep track of amount in instance script, returns SPECIAL if amount ok and event in progress
            if (instance->GetData(TYPE_BAR) == SPECIAL)
            {
                creature->AI()->Talk(SAY_GOT_BEER);
                creature->CastSpell(creature, SPELL_DRUNKEN_RAGE, false);

                if (npc_escortAI* escortAI = CAST_AI(npc_rocknot::npc_rocknotAI, creature->AI()))
                    escortAI->Start(false, false);
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_rocknotAI(creature);
    }

    struct npc_rocknotAI : public npc_escortAI
    {
        npc_rocknotAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 BreakKeg_Timer;
        uint32 BreakDoor_Timer;

        void Reset() OVERRIDE
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            BreakKeg_Timer = 0;
            BreakDoor_Timer = 0;
        }

        void DoGo(uint32 id, uint32 state)
        {
            if (GameObject* go = instance->instance->GetGameObject(instance->GetData64(id)))
                go->SetGoState((GOState)state);
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            if (!instance)
                return;

            switch (waypointId)
            {
                case 1:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
                    break;
                case 2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
                    break;
                case 3:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
                    break;
                case 4:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
                    break;
                case 5:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
                    BreakKeg_Timer = 2000;
                    break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!instance)
                return;

            if (BreakKeg_Timer)
            {
                if (BreakKeg_Timer <= diff)
                {
                    DoGo(DATA_GO_BAR_KEG, 0);
                    BreakKeg_Timer = 0;
                    BreakDoor_Timer = 1000;
                } else BreakKeg_Timer -= diff;
            }

            if (BreakDoor_Timer)
            {
                if (BreakDoor_Timer <= diff)
                {
                    DoGo(DATA_GO_BAR_DOOR, 2);
                    DoGo(DATA_GO_BAR_KEG_TRAP, 0);               //doesn't work very well, leaving code here for future
                    //spell by trap has effect61, this indicate the bar go hostile

                    if (Unit* tmp = Unit::GetUnit(*me, instance->GetData64(DATA_PHALANX)))
                        tmp->setFaction(14);

                    //for later, this event(s) has alot more to it.
                    //optionally, DONE can trigger bar to go hostile.
                    instance->SetData(TYPE_BAR, DONE);

                    BreakDoor_Timer = 0;
                } else BreakDoor_Timer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
};

void AddSC_blackrock_depths()
{
    new go_shadowforge_brazier();
    new at_ring_of_law();
    new npc_grimstone();
    new npc_phalanx();
    new npc_kharan_mighthammer();
    new npc_lokhtos_darkbargainer();
    new npc_rocknot();
    // Fix us
    /*new npc_dughal_stormwing();
      new npc_tobias_seecher();
      new npc_marshal_windsor();
      new npc_marshal_reginald_windsor();
    */
}

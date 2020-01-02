/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "blackrock_depths.h"
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

//go_shadowforge_brazier
class go_shadowforge_brazier : public GameObjectScript
{
public:
    go_shadowforge_brazier() : GameObjectScript("go_shadowforge_brazier") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) override
    {
        if (InstanceScript* instance = go->GetInstanceScript())
        {
            if (instance->GetData(TYPE_LYCEUM) == IN_PROGRESS)
                instance->SetData(TYPE_LYCEUM, DONE);
            else
                instance->SetData(TYPE_LYCEUM, IN_PROGRESS);
            // If used brazier open linked doors (North or South)
            if (go->GetGUID() == instance->GetGuidData(DATA_SF_BRAZIER_N))
                instance->HandleGameObject(instance->GetGuidData(DATA_GOLEM_DOOR_N), true);
            else if (go->GetGUID() == instance->GetGuidData(DATA_SF_BRAZIER_S))
                instance->HandleGameObject(instance->GetGuidData(DATA_GOLEM_DOOR_S), true);
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

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*areaTrigger*/, bool /*entered*/) override
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockDepthsAI<npc_grimstoneAI>(creature);
    }

    struct npc_grimstoneAI : public npc_escortAI
    {
        npc_grimstoneAI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            MobSpawnId = rand32() % 6;
        }

        void Initialize()
        {
            EventPhase = 0;
            Event_Timer = 1000;

            MobCount = 0;
            MobDeath_Timer = 0;

            for (uint8 i = 0; i < MAX_NPC_AMOUNT; ++i)
                RingMobGUID[i].Clear();

            RingBossGUID.Clear();

            CanWalk = false;
        }

        InstanceScript* instance;

        uint8 EventPhase;
        uint32 Event_Timer;

        uint8 MobSpawnId;
        uint8 MobCount;
        uint32 MobDeath_Timer;

        ObjectGuid RingMobGUID[4];
        ObjectGuid RingBossGUID;

        bool CanWalk;

        void Reset() override
        {
            Initialize();

            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
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
            if (Creature* tmp = me->SummonCreature(RingBoss[rand32() % 6], 644.300f, -175.989f, -53.739f, 3.418f, TEMPSUMMON_DEAD_DESPAWN, 0))
                RingBossGUID = tmp->GetGUID();

            MobDeath_Timer = 2500;
        }

        void WaypointReached(uint32 waypointId) override
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
                    instance->UpdateEncounterStateForKilledCreature(NPC_GRIMSTONE, me);
                    instance->SetData(TYPE_RING_OF_LAW, DONE);
                    TC_LOG_DEBUG("scripts", "npc_grimstone: event reached end and set complete.");
                    break;
            }
        }

        void HandleGameObject(uint32 id, bool open)
        {
            instance->HandleGameObject(instance->GetGuidData(id), open);
        }

        void UpdateAI(uint32 diff) override
        {
            if (MobDeath_Timer)
            {
                if (MobDeath_Timer <= diff)
                {
                    MobDeath_Timer = 2500;

                    if (!RingBossGUID.IsEmpty())
                    {
                        Creature* boss = ObjectAccessor::GetCreature(*me, RingBossGUID);
                        if (boss && !boss->IsAlive() && boss->isDead())
                        {
                            RingBossGUID.Clear();
                            Event_Timer = 5000;
                            MobDeath_Timer = 0;
                            return;
                        }
                        return;
                    }

                    for (uint8 i = 0; i < MAX_NPC_AMOUNT; ++i)
                    {
                        Creature* mob = ObjectAccessor::GetCreature(*me, RingMobGUID[i]);
                        if (mob && !mob->IsAlive() && mob->isDead())
                        {
                            RingMobGUID[i].Clear();
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_phalanxAI(creature);
    }

    struct npc_phalanxAI : public ScriptedAI
    {
        npc_phalanxAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ThunderClap_Timer = 12000;
            FireballVolley_Timer = 0;
            MightyBlow_Timer = 15000;
        }

        uint32 ThunderClap_Timer;
        uint32 FireballVolley_Timer;
        uint32 MightyBlow_Timer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
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

// npc_lokhtos_darkbargainer
enum Lokhtos
{
    QUEST_A_BINDING_CONTRACT                               = 7604,
    ITEM_SULFURON_INGOT                                    = 17203,
    ITEM_THRORIUM_BROTHERHOOD_CONTRACT                     = 18628,
    SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND          = 23059
};

#define GOSSIP_ITEM_SHOW_ACCESS     "Show me what I have access to, Lothos."
#define GOSSIP_ITEM_GET_CONTRACT    "Get Thorium Brotherhood Contract"

class npc_lokhtos_darkbargainer : public CreatureScript
{
public:
    npc_lokhtos_darkbargainer() : CreatureScript("npc_lokhtos_darkbargainer") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            CloseGossipMenuFor(player);
            player->CastSpell(player, SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND, false);
        }
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor() && player->GetReputationRank(59) >= REP_FRIENDLY)
              AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_ITEM_SHOW_ACCESS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        if (player->GetQuestRewardStatus(QUEST_A_BINDING_CONTRACT) != 1 &&
            !player->HasItemCount(ITEM_THRORIUM_BROTHERHOOD_CONTRACT, 1, true) &&
            player->HasItemCount(ITEM_SULFURON_INGOT))
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_GET_CONTRACT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }

        if (player->GetReputationRank(59) < REP_FRIENDLY)
            SendGossipMenuFor(player, 3673, creature->GetGUID());
        else
            SendGossipMenuFor(player, 3677, creature->GetGUID());

        return true;
    }
};

// npc_rocknot
enum Rocknot
{
    SAY_GOT_BEER       = 0,
    QUEST_ALE          = 4295,
    SPELL_DRUNKEN_RAGE = 14872
};

class npc_rocknot : public CreatureScript
{
public:
    npc_rocknot() : CreatureScript("npc_rocknot") { }

    bool OnQuestReward(Player* /*player*/, Creature* creature, Quest const* quest, uint32 /*item*/) override
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockDepthsAI<npc_rocknotAI>(creature);
    }

    struct npc_rocknotAI : public npc_escortAI
    {
        npc_rocknotAI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            BreakKeg_Timer = 0;
            BreakDoor_Timer = 0;
        }

        InstanceScript* instance;

        uint32 BreakKeg_Timer;
        uint32 BreakDoor_Timer;

        void Reset() override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            Initialize();
        }

        void DoGo(uint32 id, uint32 state)
        {
            if (GameObject* go = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(id)))
                go->SetGoState((GOState)state);
        }

        void WaypointReached(uint32 waypointId) override
        {
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

        void UpdateAI(uint32 diff) override
        {
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

                    if (Unit* tmp = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_PHALANX)))
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
    new npc_lokhtos_darkbargainer();
    new npc_rocknot();
}

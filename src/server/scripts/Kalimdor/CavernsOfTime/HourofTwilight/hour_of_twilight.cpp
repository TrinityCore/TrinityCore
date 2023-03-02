/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
#include "hour_of_twilight.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "GameObject.h"

// In sto file ce vanno gli script dei trash, se serve
enum Spells
{
    // Thrall spells
    SPELL_LAVA_BURST = 107980,
    SPELL_HEALING_WAVE = 104088,
    SPELL_ARCURION_SPAWN_VISUAL = 104767,
    SPELL_GHOST_WOLF = 2645,

    // NPC spells
    SPELL_TRASH_ICY_BOULDER = 105433,
    SPELL_IMPALE = 104019,
    SPELL_STEALTH = 102921,
    SPELL_GARROTE = 102925,
    SPELL_BACKSTAB = 102924,
    SPELL_EVISCERATE = 102967,
    SPELL_STAGGERING_BLOW = 103000,
    SPELL_CLEAVE = 103001,
    SPELL_MORTAL_STRIKE = 103002,
    SPELL_FROZEN_SERVITOR_SPAWN_VISUAL = 103595,
    SPELL_SHOOT = 102978,
    SPELL_DISENGAGE = 102975,
    SPELL_ICE_ARROW = 108443,
    SPELL_BASH = 102990,
    SPELL_BEATDOWN = 102989,
    SPELL_MIND_FLAY = 103024,
    SPELL_HUNGERING_SHADOWS = 103021,
    SPELL_TENTACLE_SMASH = 102848,
    SPELL_SQUEEZE_LIFELESS = 102861,
    SPELL_SHADOW_VOLLEY = 102992,
    SPELL_SEEKING_SHADOWS = 102984,
    SPELL_SHADOW_BORE = 102995

};

enum Says
{
    //Thrall
    SAY_101                                = 0
};

enum eEvents
{
    EVENT_WAIT_WAVE_2 = 1,
    EVENT_MOVE_WAVE_3,
    EVENT_ARCURION_START,
    EVENT_TWILIGHT_ASSASSIN,
    EVENT_FS_SPELL,
    EVENT_EVISCERATE,
    EVENT_STAGGERING_BLOW,
    EVENT_CLEAVE,
    EVENT_MORTAL_STRIKE,
    EVENT_KILL_FROZEN_SERVITOR,
    EVENT_FS_MOVE,
    EVENT_SHOOT,
    EVENT_ICE_ARROW,
    EVENT_COOLDOWN_DISENGAGE,
    EVENT_BASH,
    EVENT_BEATDOWN,
    EVENT_HUNGERING_SHADOWS,
    EVENT_MIND_FLAY,
    EVENT_LAVA_BURST,
    EVENT_ASIRA_VISIBLE,
    EVENT_ASIRA_AGGRESSIVE,
    EVENT_LAVA_BURST_ASIRA,
    EVENT_RISING_FIRE_TOTEM,
    EVENT_CLEANSE_SPIRIT,
    EVENT_LAVA_BURST_BENEDICTUS,
    EVENT_CHAIN_LIGHTNING,
    EVENT_TENTACLE_SMASH,
    EVENT_SQUEEZE_LIFELESS,
    EVENT_SHADOW_VOLLEY,
    EVENT_SEEKING_SHADOWS,
    EVENT_SHADOW_BORE,
    EVENT_ATTACK_ARCURION,
    EVENT_RESPAWN,
    EVENT_WATER_SHELL,
    EVENT_WATER_SHELL_RANGE,
    EVENT_DESPAWN_LIGHTS,
    EVENT_CHECK_PLAYER,
    EVENT_DELETE_WALL
};

#define GOSSIP_ITEM_THRALL_0 "Yes, Thrall."
#define GOSSIP_ITEM_THRALL_1 "Teleport me."

class npc_thrall_hot : public CreatureScript
{
public:
    npc_thrall_hot() : CreatureScript("npc_thrall_hot") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->PlayerTalkClass->ClearMenus();
        npc_thrall_hotAI* ai = CAST_AI(npc_thrall_hot::npc_thrall_hotAI, creature->AI());

        if (!ai)
            return false;

        if (!ai->HasEscortState(STATE_ESCORT_ESCORTING))
        {
            ai->Start(true, true, player->GetGUID(), 0, false, false);
            ai->SetDespawnAtEnd(false);
        }
        else
        {
            ai->SetEscortPaused(false);
        }

        CloseGossipMenuFor(player);
        creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_hotAI(creature);
    }

    struct npc_thrall_hotAI : public npc_escortAI
    {
        npc_thrall_hotAI(Creature* creature) : npc_escortAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        uint32 gossipStep;

        void Reset() override
        {
            events.Reset();
            /*if(instance)
                instance->SetData(DATA_RESET_TOTALTRASH, 1);*/
            gossipStep = 0;
            SetDespawnAtEnd(false);
            SetDespawnAtFar(false);
            //SetEscortPaused(false);
            me->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            /*if (instance)
                if (instance->GetData(DATA_ARCURION_EVENT) != IN_PROGRESS)*/
                    //events.ScheduleEvent(EVENT_LAVA_BURST, 1000);
            events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Reset();
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_HEAL:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    break;
                case ACTION_SUMMON_WAVE_3:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    me->SummonCreature(NPC_FROZEN_SERVITOR, SpawnTrash[5], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[6], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[7], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[7], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[8], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[8], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[9], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SHARD, SpawnTrash[9], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case ACTION_MOVE:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    SetEscortPaused(false);
                    break;
                case ACTION_START_ARCURION:
                    if (me->FindNearestCreature(BOSS_ARCURION, 200.0f, true))
                    {
                        events.ScheduleEvent(EVENT_KILL_FROZEN_SERVITOR, 6000);
                    }
                    break;
                case ACTION_LAVA_BURST_ARCURION:
                    events.ScheduleEvent(EVENT_ATTACK_ARCURION, 1000);
                    break;
                case ACTION_THRALL_STOP_CAST:
                    events.CancelEvent(EVENT_KILL_FROZEN_SERVITOR);
                    break;
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 0:
                    me->SummonCreature(NPC_FROZEN_SERVITOR, SpawnTrash[0], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FROZEN_SERVITOR, SpawnTrash[1], TEMPSUMMON_DEAD_DESPAWN, 0);
                    SetEscortPaused(true);
                    break;
                case 2:
                    events.ScheduleEvent(EVENT_WAIT_WAVE_2, 3000);
                    SetEscortPaused(true);
                    break;
                case 3:
                    SetEscortPaused(true);
                    gossipStep = 1;
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    break;
                case 4:
                {
                    if (Creature* arcurion = me->FindNearestCreature(BOSS_ARCURION, 100.0f, true))
                    {
                        if (instance)
                            instance->SetData(DATA_TRASH_KILLED, 1);
                        me->SetHomePosition(HomePoints[2]);
                        arcurion->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        arcurion->SetVisible(true);
                        arcurion->CastSpell(arcurion, SPELL_ARCURION_SPAWN_VISUAL, false);
                        arcurion->SetReactState(REACT_AGGRESSIVE);
                        SetEscortPaused(true);
                        me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    }
                    events.CancelEvent(EVENT_CHECK_PLAYER);
                    break;
                }
                case 5:
                {
                    if (instance)
                    {
                        if (GameObject* icewall = me->FindNearestGameObject(GO_ICE_WALL, 100.0f))
                        {
                            instance->HandleGameObject(icewall->GetGUID(), true);
                            events.ScheduleEvent(EVENT_DELETE_WALL, 2000);
                        }
                    }
                    me->CastSpell(me, SPELL_GHOST_WOLF, false);
                    break;
                }
                case 12:
                {
                    //me->RemoveAura(SPELL_GHOST_WOLF);
                    me->SetVisible(false);
                    if (Creature* otherThrall = me->FindNearestCreature(NPC_THRALL_SECOND, 50.0f, true))
                    {
                        otherThrall->SetVisible(true);
                    }
                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            npc_escortAI::UpdateAI(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LAVA_BURST:
                        me->CastSpell(me->GetVictim(), SPELL_LAVA_BURST, false);
                        events.ScheduleEvent(EVENT_LAVA_BURST, 3000);
                        break;
                    case EVENT_WAIT_WAVE_2:
                        me->SummonCreature(NPC_FROZEN_SERVITOR, SpawnTrash[2], TEMPSUMMON_DEAD_DESPAWN, 0);
                        me->SummonCreature(NPC_FROZEN_SERVITOR, SpawnTrash[3], TEMPSUMMON_DEAD_DESPAWN, 0);
                        me->SummonCreature(NPC_CRYSTALLINE_ELEMENT, SpawnTrash[4], TEMPSUMMON_DEAD_DESPAWN, 0);
                        break;
                    case EVENT_KILL_FROZEN_SERVITOR:
                        if (Creature* frozenServitor = me->FindNearestCreature(NPC_FS_ARCURION, 200.0f, true))
                        {
                            me->CastSpell(frozenServitor, SPELL_LAVA_BURST, false);
                        }
                        events.ScheduleEvent(EVENT_KILL_FROZEN_SERVITOR, 2000);
                        break;
                    case EVENT_ATTACK_ARCURION:
                        events.CancelEvent(EVENT_KILL_FROZEN_SERVITOR);
                        if (Creature* arcurion = me->FindNearestCreature(BOSS_ARCURION, 200.0f, true))
                        {
                            me->CastSpell(arcurion, SPELL_LAVA_BURST, false);
                        }
                        events.ScheduleEvent(EVENT_ATTACK_ARCURION, 1000);
                        break;
                    case EVENT_CHECK_PLAYER:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 100.0f);

                        if (targets.size() == 0)
                        {
                            for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                            {
                                if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                {
                                    summon->AttackStop();
                                    summon->AI()->Reset();
                                    summon->SetReactState(REACT_DEFENSIVE);
                                }
                            }
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                        }
                        events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                        break;
                    }
                    case EVENT_DELETE_WALL:
                        if (GameObject* icewall = me->FindNearestGameObject(GO_ICE_WALL, 100.0f))
                        {
                            icewall->Delete();
                        }
                        break;
                }
            }

            DoMeleeAttackIfReady();

        }
        public:
            bool moveTrash;
    };

};

class npc_trash_hot : public CreatureScript
{
public:
    npc_trash_hot() : CreatureScript("npc_trash_hot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_trash_hotAI(creature);
    }

    struct npc_trash_hotAI: public ScriptedAI
    {
        npc_trash_hotAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (instance)
            {
                if (instance->GetData(DATA_TRASH_KILLED) >= 5 && instance->GetData(DATA_TRASH_KILLED) < 13)
                {
                    events.ScheduleEvent(EVENT_MOVE_WAVE_3, 4000);
                    me->GetMotionMaster()->MovePoint(0, MovePoints[0]);
                }
            }

        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_WAVE_3:
                        me->GetMotionMaster()->MovePoint(1, MovePoints[1]);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_frozen_servitor : public CreatureScript
{
public:
    npc_frozen_servitor() : CreatureScript("npc_frozen_servitor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_servitorAI(creature);
    }

    struct npc_frozen_servitorAI: public ScriptedAI
    {
        npc_frozen_servitorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void InitializeAI() override
        {
           me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_FS_SPELL, urand(3000, 7000));
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (instance)
            {
                if (instance->GetData(DATA_TRASH_KILLED) >= 5 && instance->GetData(DATA_TRASH_KILLED) < 13)
                {
                    events.ScheduleEvent(EVENT_MOVE_WAVE_3, 4000);
                    me->GetMotionMaster()->MovePoint(0, MovePoints[0]);
                }
                else
                {
                    me->CastSpell(me, SPELL_FROZEN_SERVITOR_SPAWN_VISUAL, false);
                    events.ScheduleEvent(EVENT_FS_MOVE, 1000);
                }
            }

        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_WAVE_3:
                        me->GetMotionMaster()->MovePoint(1, MovePoints[1]);
                        break;
                    case EVENT_FS_SPELL:
                    {
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            if(me->GetEntry() == NPC_FROZEN_SERVITOR)
                            {
                                me->CastSpell(target, SPELL_TRASH_ICY_BOULDER, false);
                            }
                            else if(me->GetEntry() == NPC_CRYSTALLINE_ELEMENT)
                            {
                                me->CastSpell(target, SPELL_IMPALE, false);
                            }
                        }
                        events.ScheduleEvent(EVENT_FS_SPELL, urand(3000, 7000));
                        break;
                    }
                    case EVENT_FS_MOVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;

                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_thrall_second_hot : public CreatureScript
{
public:
    npc_thrall_second_hot() : CreatureScript("npc_thrall_second_hot") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->PlayerTalkClass->ClearMenus();
        npc_thrall_second_hotAI* ai = CAST_AI(npc_thrall_second_hot::npc_thrall_second_hotAI, creature->AI());

        if (!ai)
            return false;

        switch (ai->gossipStep)
        {
            case 0:
                ai->Start(true, true, player->GetGUID(), 0, false, false);
                ai->SetDespawnAtEnd(false);
                creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                break;
            case 1:
                player->NearTeleportTo(3933.69f, 297.74f, 10.14f, player->GetOrientation());
                break;
        }

        CloseGossipMenuFor(player);

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_second_hotAI(creature);
    }

    struct npc_thrall_second_hotAI : public npc_escortAI
    {
        npc_thrall_second_hotAI(Creature* creature) : npc_escortAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        uint32 gossipStep;

        void InitializeAI() override
        {
            me->SetVisible(false);
            gossipStep = 0;
        }

        void Reset() override
        {
            events.Reset();
            gossipStep = 0;
            SetDespawnAtEnd(false);
            SetDespawnAtFar(false);
            summons.DespawnAll();

            std::list<Creature*> unitList;
            me->GetCreatureListWithEntryInGrid(unitList, 55474, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {
                (*itr)->DespawnOrUnsummon();
            }

        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
            if (instance)
                if (instance->GetData(DATA_ASIRA_DAWNSLAYER_EVENT) != IN_PROGRESS)
                    events.ScheduleEvent(EVENT_LAVA_BURST, 1000);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_HEAL:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    break;
                case ACTION_MOVE:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    SetEscortPaused(false);
                    break;
                case ACTION_START_ASIRA:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_LAVA_BURST_ASIRA, 1000);
                    events.ScheduleEvent(EVENT_RISING_FIRE_TOTEM, 15000);
                    break;
                case ACTION_THRALL_STOP_CAST:
                    events.CancelEvent(EVENT_LAVA_BURST_ASIRA);
                    events.CancelEvent(EVENT_RISING_FIRE_TOTEM);
                    break;
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 2:
                    SetEscortPaused(true);
                    me->SummonCreature(NPC_TWILIGHT_BRUISER, SpawnTrash[11], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_RANGER, SpawnTrash[12], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_SHADOW_WALKER, SpawnTrash[13], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_THUG, SpawnTrash[14], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 4:
                    SetEscortPaused(true);
                    me->SummonCreature(NPC_TWILIGHT_BRUISER, SpawnTrash[15], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_RANGER, SpawnTrash[16], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_SHADOW_WALKER, SpawnTrash[17], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_THUG, SpawnTrash[18], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 5:
                    SetEscortPaused(true);
                    me->SummonCreature(NPC_TWILIGHT_BRUISER, SpawnTrash[19], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_RANGER, SpawnTrash[20], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_SHADOW_WALKER, SpawnTrash[21], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_TWILIGHT_THUG, SpawnTrash[22], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 6:
                    SetEscortPaused(true);
                    asira = me->FindNearestCreature(BOSS_ASIRA_DAWNSLAYER, 100.0f, true);
                    if (asira != nullptr)
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->SetHomePosition(HomePoints[3]);
                        asira->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        asira->SetVisible(true);
                        events.ScheduleEvent(EVENT_ASIRA_AGGRESSIVE, 2000);
                        if (instance)
                            instance->SetData(DATA_TRASH_KILLED, 1);

                        events.CancelEvent(EVENT_CHECK_PLAYER);
                        //SetEscortPaused(true);
                    }
                    //me->SummonCreature(BOSS_ASIRA_DAWNSLAYER, 4250.38f, 570.115f, -6.52593f, 0.125407f, TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 8:
                    events.Reset();
                    SetEscortPaused(true);
                    gossipStep = 1;
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override

        {
            npc_escortAI::UpdateAI(diff);

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
                return;*/

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LAVA_BURST:
                        me->CastSpell(me->GetVictim(), SPELL_LAVA_BURST, false);
                        if (instance)
                            if (instance->GetData(DATA_ASIRA_DAWNSLAYER_EVENT) != IN_PROGRESS)
                                 events.ScheduleEvent(EVENT_LAVA_BURST, 3000);
                        break;
                    case EVENT_ASIRA_AGGRESSIVE:
                        asira->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_LAVA_BURST_ASIRA:
                        me->CastSpell(asira, SPELL_LAVA_BURST, false);
                        events.ScheduleEvent(EVENT_LAVA_BURST_ASIRA, urand(3000, 5000));
                        break;
                    case EVENT_RISING_FIRE_TOTEM:
                        events.CancelEvent(EVENT_LAVA_BURST_ASIRA);
                        if (Unit* player = me->SelectNearestPlayer(200.0f))
                        {
                            me->CastSpell(player, 103819, false);
                        }
                        events.ScheduleEvent(EVENT_LAVA_BURST_ASIRA, urand(5000, 8000));
                        events.ScheduleEvent(EVENT_RISING_FIRE_TOTEM, 15000);
                        break;
                    case EVENT_CHECK_PLAYER:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 100.0f);
                        if (targets.size() == 0)
                        {
                            for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                            {
                                if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                {
                                    summon->AttackStop();
                                    summon->AI()->Reset();
                                    summon->SetReactState(REACT_DEFENSIVE);
                                }
                            }
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                        }
                        events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();

        }
    public:
        bool moveTrash;
        Creature* asira;
    };

};

class npc_twilight_assassin : public CreatureScript
{
public:
    npc_twilight_assassin() : CreatureScript("npc_twilight_assassin") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_assassinAI(creature);
    }

    struct npc_twilight_assassinAI: public ScriptedAI
    {
        npc_twilight_assassinAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void InitializeAI() override
        {
            me->CastSpell(me, SPELL_STEALTH, false);
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_EVISCERATE, 6000);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            //instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(me->ToTempSummon())
            {
                if(Unit* thrall = me->ToTempSummon()->GetSummoner())
                {
                    if(me->IsWithinMeleeRange(thrall))
                    {
                        me->AI()->AttackStart(thrall);
                        me->CastSpell(thrall, SPELL_GARROTE, false);
                        me->CastSpell(thrall, SPELL_BACKSTAB, false);
                    }
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EVISCERATE:
                        me->CastSpell(me->GetVictim(), SPELL_EVISCERATE, false);
                        events.ScheduleEvent(EVENT_EVISCERATE, 25000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_twilight_bruiser : public CreatureScript
{
public:
    npc_twilight_bruiser() : CreatureScript("npc_twilight_bruiser") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_bruiserAI(creature);
    }

    struct npc_twilight_bruiserAI: public ScriptedAI
    {
        npc_twilight_bruiserAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_STAGGERING_BLOW, 4000);
            events.ScheduleEvent(EVENT_CLEAVE, 3000);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 7000);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STAGGERING_BLOW:
                        me->CastSpell(me->GetVictim(), SPELL_STAGGERING_BLOW, false);
                        events.ScheduleEvent(EVENT_STAGGERING_BLOW, urand(10000, 12000));
                        break;
                    case EVENT_CLEAVE:
                        me->CastSpell(me->GetVictim(), SPELL_CLEAVE, false);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 7000));
                        break;
                    case EVENT_MORTAL_STRIKE:
                        me->CastSpell(me->GetVictim(), SPELL_MORTAL_STRIKE, false);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(10000, 12000));
                        break;

                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_twilight_ranger : public CreatureScript
{
public:
    npc_twilight_ranger() : CreatureScript("npc_twilight_ranger") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_rangerAI(creature);
    }

    struct npc_twilight_rangerAI: public ScriptedAI
    {
        npc_twilight_rangerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;
        bool cooldownDisengage;

        void Reset() override
        {
            events.Reset();
            cooldownDisengage = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_SHOOT, 1000);
            events.ScheduleEvent(EVENT_ICE_ARROW, urand(3000, 7000));
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if(damage > 0 && cooldownDisengage == false)
            {
                me->CastSpell(me, SPELL_DISENGAGE, false);
                cooldownDisengage = true;
                events.ScheduleEvent(EVENT_COOLDOWN_DISENGAGE, 15000);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHOOT:
                        me->CastSpell(me->GetVictim(), SPELL_SHOOT, false);
                        events.ScheduleEvent(EVENT_SHOOT, 2000);
                        break;
                    case EVENT_ICE_ARROW:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_ICE_ARROW, false);
                        }
                        events.ScheduleEvent(EVENT_ICE_ARROW, urand(7000, 10000));
                        break;
                    case EVENT_COOLDOWN_DISENGAGE:
                        cooldownDisengage = false;
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_twilight_thug : public CreatureScript
{
public:
    npc_twilight_thug() : CreatureScript("npc_twilight_thug") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_thugAI(creature);
    }

    struct npc_twilight_thugAI: public ScriptedAI
    {
        npc_twilight_thugAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_BASH, urand(3000, 7000));
            events.ScheduleEvent(EVENT_BEATDOWN, 10000);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BASH:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_BASH, false);
                        }
                         events.ScheduleEvent(EVENT_BASH, urand(3000, 7000));
                        break;
                    case EVENT_BEATDOWN:
                        me->CastSpell(me, SPELL_BEATDOWN, false);
                        events.ScheduleEvent(EVENT_BEATDOWN, 15000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_twilight_shadow_walker : public CreatureScript
{
public:
    npc_twilight_shadow_walker() : CreatureScript("npc_twilight_shadow_walker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_shadow_walkerAI(creature);
    }

    struct npc_twilight_shadow_walkerAI: public ScriptedAI
    {
        npc_twilight_shadow_walkerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_MIND_FLAY, urand(2000, 5000));
            events.ScheduleEvent(EVENT_HUNGERING_SHADOWS, 10000);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MIND_FLAY:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_MIND_FLAY, false);
                        }
                         events.ScheduleEvent(EVENT_MIND_FLAY, urand(3000, 7000));
                        break;
                    case EVENT_HUNGERING_SHADOWS:
                        me->CastSpell(me, SPELL_HUNGERING_SHADOWS, false);
                        events.ScheduleEvent(EVENT_HUNGERING_SHADOWS, 6000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class TargetFilter
{
public:
    bool operator()(WorldObject* unit) const
    {
        return !unit->ToPlayer();
    }
};

class npc_thrall_final_hot : public CreatureScript
{
public:
    npc_thrall_final_hot() : CreatureScript("npc_thrall_final_hot") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        npc_thrall_final_hotAI* ai = CAST_AI(npc_thrall_final_hot::npc_thrall_final_hotAI, creature->AI());

        if (!ai)
            return false;

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF:
            ai->Start(true, true, player->GetGUID(), 0, false, false);
            ai->SetDespawnAtEnd(false);
            break;
        }

        CloseGossipMenuFor(player);
        creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        npc_thrall_final_hotAI* ai = CAST_AI(npc_thrall_final_hot::npc_thrall_final_hotAI, creature->AI());

        switch (ai->gossipStep)
        {
            case 0: //This one is a workaround since the very beggining of the script is wrong.
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_THRALL_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, 18583, creature->GetGUID());
                break;
            }
            default:
                return false;
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_final_hotAI(creature);
    }

    struct npc_thrall_final_hotAI : public npc_escortAI
    {
        npc_thrall_final_hotAI(Creature* creature) : npc_escortAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;

        uint32 gossipStep;

        /*void InitializeAI() override
        {
            me->SetVisible(false);
        }*/

        void Reset() override
        {
            events.Reset();
            gossipStep = 0;
            SetDespawnAtEnd(false);
            SetDespawnAtFar(false);
            summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoZoneInCombat();
        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_MOVE:
                    me->CastSpell(me, SPELL_HEALING_WAVE, false);
                    SetEscortPaused(false);
                    break;
                case ACTION_START_BENEDICTUS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_CLEANSE_SPIRIT, 12000);
                    events.ScheduleEvent(EVENT_LAVA_BURST_BENEDICTUS, 1000);
                    //events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 12000);
                    break;
                case ACTION_WATER_SHELL:
                    events.CancelEvent(EVENT_CLEANSE_SPIRIT);
                    events.CancelEvent(EVENT_LAVA_BURST_BENEDICTUS);

                    events.ScheduleEvent(EVENT_WATER_SHELL, 500);
                    events.ScheduleEvent(EVENT_LAVA_BURST_BENEDICTUS, 15000);
                    break;
                case ACTION_CHAIN_LIGHTNING:
                    events.CancelEvent(EVENT_LAVA_BURST_BENEDICTUS);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 1000);
                    break;
                case ACTION_THRALL_STOP_CAST:
                    events.CancelEvent(EVENT_CLEANSE_SPIRIT);
                    events.CancelEvent(EVENT_LAVA_BURST_BENEDICTUS);
                    break;
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 0:
                    SetEscortPaused(true);
                    me->SetReactState(REACT_PASSIVE);
                    me->SummonCreature(NPC_FACELESS_BRUTE, SpawnTrash[24], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_SHADOW_BORER, SpawnTrash[25], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FACELESS_SHADOW_WEAVER, SpawnTrash[26], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 1:
                    SetEscortPaused(true);
                    me->SetReactState(REACT_PASSIVE);
                    me->SummonCreature(NPC_SHADOW_BORER, SpawnTrash[27], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FACELESS_BRUTE, SpawnTrash[28], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FACELESS_SHADOW_WEAVER, SpawnTrash[29], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 4:
                    SetEscortPaused(true);
                    me->SetReactState(REACT_PASSIVE);
                    me->SummonCreature(NPC_SHADOW_BORER, SpawnTrash[30], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FACELESS_BRUTE, SpawnTrash[31], TEMPSUMMON_DEAD_DESPAWN, 0);
                    me->SummonCreature(NPC_FACELESS_SHADOW_WEAVER, SpawnTrash[32], TEMPSUMMON_DEAD_DESPAWN, 0);
                    break;
                case 9:
                    if (instance)
                        instance->SetData(DATA_TRASH_KILLED, 1);
                    me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetHomePosition(HomePoints[0]);
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_CHECK_PLAYER);
                    break;

            }
        }

        void UpdateAI(uint32 diff) override

        {
            npc_escortAI::UpdateAI(diff);

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
                return;*/

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEANSE_SPIRIT:
                        events.CancelEvent(EVENT_LAVA_BURST_BENEDICTUS);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 103151))
                        {
                            me->CastSpell(target, 103550, false);
                        }
                        events.ScheduleEvent(EVENT_LAVA_BURST_BENEDICTUS, 1000);
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (Creature* light = me->FindNearestCreature(55377, 100.0f, true))
                        {
                            me->CastSpell(light, 103637, false);
                        }
                        events.ScheduleEvent(EVENT_LAVA_BURST_BENEDICTUS, 5000);
                        events.ScheduleEvent(EVENT_DESPAWN_LIGHTS, 3000);
                        break;
                    case EVENT_LAVA_BURST_BENEDICTUS:
                        if(Creature* boss = me->FindNearestCreature(BOSS_ARCHBISHOP_BENEDICTUS, 100.0f, true))
                        {
                            me->CastSpell(boss, SPELL_LAVA_BURST, false);
                        }
                        events.ScheduleEvent(EVENT_LAVA_BURST_BENEDICTUS, 3000);
                        break;
                    case EVENT_WATER_SHELL:
                        if (Creature * waterShell = me->SummonCreature(55447, 3539.34f, 262.37f, -115.97f, 2.424074f, TEMPSUMMON_TIMED_DESPAWN, 20000))
                        {
                            me->CastSpell(waterShell, 103688, false);
                        }
                        break;
                    case EVENT_DESPAWN_LIGHTS:
                        if (Creature* light = me->FindNearestCreature(55377, 100.0f, true))
                            light->DespawnOrUnsummon();
                        if (Creature* light = me->FindNearestCreature(55377, 100.0f, true))
                            light->DespawnOrUnsummon();
                        break;
                }
            }

            //DoMeleeAttackIfReady();

        }
    public:
        bool moveTrash;
    };

};

class npc_faceless_brute : public CreatureScript
{
public:
    npc_faceless_brute() : CreatureScript("npc_faceless_brute") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_faceless_bruteAI(creature);
    }

    struct npc_faceless_bruteAI : public ScriptedAI
    {
        npc_faceless_bruteAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_TENTACLE_SMASH, urand(2000, 5000));
            events.ScheduleEvent(EVENT_HUNGERING_SHADOWS, 10000);
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TENTACLE_SMASH:
                        me->CastSpell(me->GetVictim(), SPELL_TENTACLE_SMASH, false);
                        break;
                    case EVENT_SQUEEZE_LIFELESS:
                        me->CastSpell(me->GetVictim(), SPELL_SQUEEZE_LIFELESS, false);
                        events.ScheduleEvent(EVENT_TENTACLE_SMASH, urand(2000, 5000));
                        events.ScheduleEvent(EVENT_HUNGERING_SHADOWS, 10000);
                        break;

                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_faceless_shadow_weaver : public CreatureScript
{
public:
    npc_faceless_shadow_weaver() : CreatureScript("npc_faceless_shadow_weaver") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_faceless_shadow_weaverAI(creature);
    }

    struct npc_faceless_shadow_weaverAI : public ScriptedAI
    {
        npc_faceless_shadow_weaverAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_SEEKING_SHADOWS, urand(2000, 5000));
            events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(7000, 10000));
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SEEKING_SHADOWS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_SEEKING_SHADOWS, false);
                        }
                        events.ScheduleEvent(EVENT_SEEKING_SHADOWS, 5000);
                        break;
                    case EVENT_SHADOW_VOLLEY:
                        me->CastSpell(me, SPELL_SHADOW_VOLLEY, false);
                        events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 5000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_shadow_borer : public CreatureScript
{
public:
    npc_shadow_borer() : CreatureScript("npc_shadow_borer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadow_borerAI(creature);
    }

    struct npc_shadow_borerAI : public ScriptedAI
    {
        npc_shadow_borerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 100.0f, true))
                thrall->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_SHADOW_BORE, urand(2000, 5000));
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
                instance->SetData(DATA_TRASH_KILLED, 1);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_BORE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_SHADOW_BORE, false);
                        }
                        events.ScheduleEvent(EVENT_SHADOW_BORE, urand(12000, 15000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_water_shell : public CreatureScript
{
public:
    npc_water_shell() : CreatureScript("npc_water_shell") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_water_shellAI(creature);
    }

    struct npc_water_shellAI : public ScriptedAI
    {
        npc_water_shellAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            events.ScheduleEvent(EVENT_WATER_SHELL_RANGE, 250);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WATER_SHELL_RANGE:
                        me->CastSpell(me, 103744, false);
                        events.ScheduleEvent(EVENT_WATER_SHELL_RANGE, 500);
                        break;
                }
            }
        }
    };

};

void AddSC_hourl_of_twilight()
{
    new npc_thrall_hot();
    new npc_trash_hot();
    new npc_frozen_servitor();
    new npc_thrall_second_hot();
    new npc_twilight_assassin();
    new npc_twilight_bruiser();
    new npc_twilight_ranger();
    new npc_twilight_thug();
    new npc_twilight_shadow_walker();
    new npc_thrall_final_hot();
    new npc_faceless_brute();
    new npc_faceless_shadow_weaver();
    new npc_shadow_borer();
    new npc_water_shell();
}

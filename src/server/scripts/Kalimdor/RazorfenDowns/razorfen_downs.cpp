/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
SDName: Razorfen_Downs
SD%Complete: 100
SDComment: Support for Henry Stern(2 recipes)
SDCategory: Razorfen Downs
EndScriptData */

/* ContentData
npc_henry_stern
EndContentData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "razorfen_downs.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"

/*###
## npc_belnistrasz for Quest 3525 "Extinguishing the Idol"
######*/

Position const PosSummonSpawner[3] =
{
    { 2582.789f, 954.3925f, 52.48214f, 3.787364f  },
    { 2569.42f,  956.3801f, 52.27323f, 5.427974f  },
    { 2570.62f,  942.3934f, 53.7433f,  0.715585f  }
};

enum Belnistrasz
{
    EVENT_CHANNEL                = 1,
    EVENT_IDOL_ROOM_SPAWNER      = 2,
    EVENT_PROGRESS               = 3,
    EVENT_COMPLETE               = 4,
    EVENT_FIREBALL               = 5,
    EVENT_FROST_NOVA             = 6,

    PATH_ESCORT                  = 871710,
    POINT_REACH_IDOL             = 17,

    QUEST_EXTINGUISHING_THE_IDOL = 3525,

    SAY_QUEST_ACCEPTED           = 0,
    SAY_EVENT_START              = 1,
    SAY_EVENT_THREE_MIN_LEFT     = 2,
    SAY_EVENT_TWO_MIN_LEFT       = 3,
    SAY_EVENT_ONE_MIN_LEFT       = 4,
    SAY_EVENT_END                = 5,
    SAY_AGGRO                    = 6, // Combat
    SAY_WATCH_OUT                = 7, // 25% chance to target random creature and say on wave spawn

    SPELL_ARCANE_INTELLECT       = 13326,
    SPELL_FIREBALL               = 9053,
    SPELL_FROST_NOVA             = 11831,
    SPELL_IDOL_SHUTDOWN_VISUAL   = 12774, // Hits Unit Entry: 8662
    SPELL_IDOM_ROOM_CAMERA_SHAKE = 12816  // Dummy needs scripting
};

class npc_belnistrasz : public CreatureScript
{
public:
    npc_belnistrasz() : CreatureScript("npc_belnistrasz") { }

    struct npc_belnistraszAI : public ScriptedAI
    {
        npc_belnistraszAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            eventInProgress = false;
            channeling = false;
            eventProgress = 0;
            spawnerCount = 0;
        }

        void Reset() override
        {
            if (!eventInProgress)
            {
                if (!me->HasAura(SPELL_ARCANE_INTELLECT))
                    DoCast(me, SPELL_ARCANE_INTELLECT);

                channeling = false;
                eventProgress = 0;
                spawnerCount  = 0;
                me->SetFlag(UNIT_NPC_FLAGS, GOSSIP_OPTION_QUESTGIVER);
            }
        }

        void EnterCombat(Unit* who) override
        {
            if (channeling)
                Talk(SAY_WATCH_OUT, who);
            else
            {
                events.ScheduleEvent(EVENT_FIREBALL, 1000);
                events.ScheduleEvent(EVENT_FROST_NOVA, urand(8000, 12000));
                if (urand(0, 100) > 40)
                    Talk(SAY_AGGRO, who);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetBossState(DATA_EXTINGUISHING_THE_IDOL, DONE);
            me->DespawnOrUnsummon(5000);
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_EXTINGUISHING_THE_IDOL)
            {
                eventInProgress = true;
                Talk(SAY_QUEST_ACCEPTED);
                me->RemoveFlag(UNIT_NPC_FLAGS, GOSSIP_OPTION_QUESTGIVER);
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_ACTIVE);
                me->GetMotionMaster()->MovePath(PATH_ESCORT, false);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE && id == POINT_REACH_IDOL)
            {
                channeling = true;
                events.ScheduleEvent(EVENT_CHANNEL, 2000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!eventInProgress)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHANNEL:
                        Talk(SAY_EVENT_START);
                        DoCast(me, SPELL_IDOL_SHUTDOWN_VISUAL);
                        events.ScheduleEvent(EVENT_IDOL_ROOM_SPAWNER, 100);
                        events.ScheduleEvent(EVENT_PROGRESS, 120000);
                        break;
                    case EVENT_IDOL_ROOM_SPAWNER:
                        if (Creature* creature = me->SummonCreature(NPC_IDOL_ROOM_SPAWNER, PosSummonSpawner[urand(0,2)], TEMPSUMMON_TIMED_DESPAWN, 4000))
                            creature->AI()->SetData(0,spawnerCount);
                        if (++spawnerCount < 8)
                            events.ScheduleEvent(EVENT_IDOL_ROOM_SPAWNER, 35000);
                        break;
                    case EVENT_PROGRESS:
                    {
                        switch (eventProgress)
                        {
                            case 0:
                                Talk(SAY_EVENT_THREE_MIN_LEFT);
                                ++eventProgress;
                                 events.ScheduleEvent(EVENT_PROGRESS, 60000);
                                 break;
                            case 1:
                                Talk(SAY_EVENT_TWO_MIN_LEFT);
                                ++eventProgress;
                                events.ScheduleEvent(EVENT_PROGRESS, 60000);
                                break;
                            case 2:
                                Talk(SAY_EVENT_ONE_MIN_LEFT);
                                ++eventProgress;
                                events.ScheduleEvent(EVENT_PROGRESS, 60000);
                                break;
                            case 3:
                                events.CancelEvent(EVENT_IDOL_ROOM_SPAWNER);
                                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                                Talk(SAY_EVENT_END);
                                events.ScheduleEvent(EVENT_COMPLETE, 3000);
                                break;
                        }
                          break;
                    }
                    case EVENT_COMPLETE:
                    {
                        DoCast(me, SPELL_IDOM_ROOM_CAMERA_SHAKE);
                        me->SummonGameObject(GO_BELNISTRASZS_BRAZIER, 2577.196f, 947.0781f, 53.16757f, 2.356195f, QuaternionData(0.f, 0.f, 0.9238796f, 0.3826832f), 3600);
                        std::list<WorldObject*> ClusterList;
                        Trinity::AllWorldObjectsInRange objects(me, 50.0f);
                        Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, ClusterList, objects);
                        Cell::VisitAllObjects(me, searcher, 50.0f);
                        for (std::list<WorldObject*>::const_iterator itr = ClusterList.begin(); itr != ClusterList.end(); ++itr)
                        {
                            if (Player* player = (*itr)->ToPlayer())
                            {
                                if (player->GetQuestStatus(QUEST_EXTINGUISHING_THE_IDOL) == QUEST_STATUS_INCOMPLETE)
                                    player->CompleteQuest(QUEST_EXTINGUISHING_THE_IDOL);
                            }
                            else if (GameObject* go = (*itr)->ToGameObject())
                            {
                                if (go->GetEntry() == GO_IDOL_OVEN_FIRE || go->GetEntry() == GO_IDOL_CUP_FIRE || go->GetEntry() == GO_IDOL_MOUTH_FIRE)
                                    go->Delete();
                            }
                        }
                        instance->SetBossState(DATA_EXTINGUISHING_THE_IDOL, DONE);
                        me->DespawnOrUnsummon();
                        break;
                    }
                    case EVENT_FIREBALL:
                        if (me->HasUnitState(UNIT_STATE_CASTING) || !UpdateVictim())
                            return;
                        DoCastVictim(SPELL_FIREBALL);
                        events.ScheduleEvent(EVENT_FIREBALL, 8000);
                        break;
                    case EVENT_FROST_NOVA:
                        if (me->HasUnitState(UNIT_STATE_CASTING) || !UpdateVictim())
                            return;
                        DoCast(me, SPELL_FROST_NOVA);
                        events.ScheduleEvent(EVENT_FROST_NOVA, 15000);
                        break;
                }
            }
            if (!channeling)
                DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
        bool eventInProgress;
        bool channeling;
        uint8 eventProgress;
        uint8 spawnerCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetRazorfenDownsAI<npc_belnistraszAI>(creature);
    }
};

class npc_idol_room_spawner : public CreatureScript
{
public:
    npc_idol_room_spawner() : CreatureScript("npc_idol_room_spawner") { }

    struct npc_idol_room_spawnerAI : public ScriptedAI
    {
        npc_idol_room_spawnerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override { }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            if (data < 7)
            {
                me->SummonCreature(NPC_WITHERED_BATTLE_BOAR, me->GetPositionX(),  me->GetPositionY(),  me->GetPositionZ(),  me->GetOrientation());
                if (data > 0 && me->GetOrientation() < 4.0f)
                    me->SummonCreature(NPC_WITHERED_BATTLE_BOAR, me->GetPositionX(),  me->GetPositionY(),  me->GetPositionZ(),  me->GetOrientation());
                me->SummonCreature(NPC_DEATHS_HEAD_GEOMANCER, me->GetPositionX() + (std::cos(me->GetOrientation() - (float(M_PI) / 2)) * 2), me->GetPositionY() + (std::sin(me->GetOrientation() - (float(M_PI) / 2)) * 2), me->GetPositionZ(), me->GetOrientation());
                me->SummonCreature(NPC_WITHERED_QUILGUARD, me->GetPositionX() + (std::cos(me->GetOrientation() + (float(M_PI) / 2)) * 2), me->GetPositionY() + (std::sin(me->GetOrientation() + (float(M_PI) / 2)) * 2), me->GetPositionZ(), me->GetOrientation());
            }
            else if (data == 7)
                me->SummonCreature(NPC_PLAGUEMAW_THE_ROTTING, me->GetPositionX(),  me->GetPositionY(),  me->GetPositionZ(),  me->GetOrientation());
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetRazorfenDownsAI<npc_idol_room_spawnerAI>(creature);
    }
};

enum TombCreature
{
    EVENT_WEB                   = 7,
    SPELL_POISON_PROC           = 3616,
    SPELL_VIRULENT_POISON_PROC  = 12254,
    SPELL_WEB                   = 745
};

class npc_tomb_creature : public CreatureScript
{
public:
    npc_tomb_creature() : CreatureScript("npc_tomb_creature") { }

    struct npc_tomb_creatureAI : public ScriptedAI
    {
        npc_tomb_creatureAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (!me->HasAura(SPELL_POISON_PROC) && me->GetEntry() == NPC_TOMB_FIEND)
                DoCast(me, SPELL_POISON_PROC);

            if (!me->HasAura(SPELL_VIRULENT_POISON_PROC) && me->GetEntry() == NPC_TOMB_REAVER)
                DoCast(me, SPELL_VIRULENT_POISON_PROC);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_WAVE, me->GetEntry());
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_WEB, urand(5000, 8000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WEB:
                        DoCastVictim(SPELL_WEB);
                        events.ScheduleEvent(EVENT_WEB, urand(7000, 16000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetRazorfenDownsAI<npc_tomb_creatureAI>(creature);
    }
};

/*######
## go_gong
######*/

class go_gong : public GameObjectScript
{
public:
    go_gong() : GameObjectScript("go_gong") { }

    struct go_gongAI : public GameObjectAI
    {
        go_gongAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool GossipHello(Player* /*player*/) override
        {
            me->SendCustomAnim(0);
            instance->SetData(DATA_WAVE, IN_PROGRESS);
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetRazorfenDownsAI<go_gongAI>(go);
    }
};

void AddSC_razorfen_downs()
{
    new npc_belnistrasz();
    new npc_idol_room_spawner();
    new npc_tomb_creature();
    new go_gong();
}

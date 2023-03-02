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

#include"ScriptMgr.h"
#include"hour_of_twilight.h"
#include "GameObject.h"
#include "GridNotifiers.h"

enum Spells
{
    SPELL_SMITE                         = 104503,
    SPELL_RIGHTEOUS_SHEAR               = 103151,
    SPELL_PURIFYING_LIGHT_SUMMON1       = 103584,
    SPELL_PURIFYING_LIGHT_SUMMON2       = 103585,
    SPELL_PURIFYING_LIGHT_SUMMON3       = 103586,
    SPELL_PURIFYING_LIGHT_VISUAL        = 103578,
    SPELL_PURIFYING_LIGHT_CAST          = 103565,
    SPELL_PURIFIED                      = 103654,
    SPELL_PURIFYING_BLAST               = 103648,
    SPELL_PURIFYING_BLAST_DAMAGE        = 103651,
    SPELL_TWILIGHT_BLAST                = 104504,
    SPELL_TWILIGHT_SHEAR                = 103363,
    SPELL_CORRUPTING_TWILIGHT_SUMMON1   = 103770,
    SPELL_CORRUPTING_TWILIGHT_SUMMON2   = 103771,
    SPELL_CORRUPTING_TWILIGHT_SUMMON3   = 103772,
    SPELL_CORRUPTING_TWILIGHT_VISUAL    = 103769,
    SPELL_CORRUPTING_TWILIGHT_CAST      = 103767,
    SPELL_TWILIGHT                      = 103774,
    SPELL_TWILIGHT_BOLT                 = 103776,
    SPELL_TWILIGHT_BOLT_DAMAGE          = 103777,
    SPELL_WAVE_OF_TWILIGHT_SUMMON       = 103783,
    SPELL_WAVE_OF_TWILIGHT_WAVE         = 103780,
    SPELL_WAVE_OF_TWILIGHT_DAMAGE       = 103781,
    SPELL_TWILIGHT_EPIPHANY             = 103754,
    SPELL_TWILIGHT_EPIPHANY_SCREEN      = 103755,
    SPELL_WATER_SHELL                   = 103744,
    SPELL_SEAPING_TWILIGHT              = 104534
};

enum Events
{
    EVENT_MOVEMENT_1 = 1,
    EVENT_MOVEMENT_2,
    EVENT_MOVEMENT_3,
    EVENT_MOVEMENT_4,
    EVENT_MOVEMENT_5,
    EVENT_MOVEMENT_6,
    EVENT_ACTIVATE_WALL,
    EVENT_SUMMON_HOLY_WALL,
    EVENT_START_BENEDICTUS,
    EVENT_SMITE,
    EVENT_RIGHTEOUS_SHEAR,
    EVENT_PURIFYING_LIGHT,
    EVENT_LIGHT_VISUAL,
    EVENT_LIGHT_CHARGE,
    EVENT_PURIFIED,
    EVENT_WAVE_OF_VIRTUE,
    EVENT_WAVE_OF_VIRTUE_DAMAGE,
    EVENT_TWILIGHT_BLAST,
    EVENT_TWILIGHT_SHEAR,
    EVENT_CORRUPTING_TWILIGHT,
    EVENT_WAVE_OF_TWILIGHT,
    EVENT_WAVE_OF_TWILIGHT_DAMAGE,
    EVENT_TWILIGHT_VISUAL,
    EVENT_TWILIGHT_CHARGE,
    EVENT_TWILIGHT_BOLT,
    EVENT_CHECK_PLAYER,
    EVENT_THRALL_CAST,
    EVENT_RESTART
};


class boss_archbishop_benedictus : public CreatureScript
{
public:
    boss_archbishop_benedictus() : CreatureScript("boss_archbishop_benedictus") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_archbishop_benedictusAI (creature);
    }

    struct boss_archbishop_benedictusAI : public BossAI
    {
        boss_archbishop_benedictusAI(Creature* creature) : BossAI(creature, DATA_ARCHBISHOP_BENEDICTUS_EVENT)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript *instance;
        EventMap events;

        bool intro;
        bool twilightPhase;
        bool cooldownVictim;

        void Reset() override
        {
            _Reset();
            events.Reset();
            cooldownVictim = false;
            intro = true;

            if (instance)
            {
                if (GameObject* holyWall = me->FindNearestGameObject(GO_HOLY_WALL, 100.0f))
                    instance->HandleGameObject(holyWall->GetGUID(), true, holyWall);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_EPIPHANY_SCREEN);
            }

            if (Creature* seaping = me->FindNearestCreature(600000, 100.0f, true))
            {
                seaping->RemoveAura(SPELL_SEAPING_TWILIGHT);
            }

            std::list<Creature*> unitList;
            me->GetCreatureListWithEntryInGrid(unitList, 55427, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {
                (*itr)->DespawnOrUnsummon();
            }

            me->GetCreatureListWithEntryInGrid(unitList, 55468, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {
                (*itr)->DespawnOrUnsummon();
            }

            twilightPhase = false;
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_MOVE_BENEDICTUS:
                    me->GetMotionMaster()->MovePoint(0, ArchbishopPoints[0]);
                    events.ScheduleEvent(EVENT_MOVEMENT_1, 12000);
                    break;
            }
        }

        void JustDied(Unit* /*Kill*/) override
        {
            _JustDied();
            if (instance)
            {
                if (GameObject* holyWall = me->FindNearestGameObject(GO_HOLY_WALL, 100.0f))
                    instance->HandleGameObject(holyWall->GetGUID(), true, holyWall);

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_EPIPHANY_SCREEN);
            }

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 200.0f, true))
            {
                thrall->RemoveAura(103762);
                thrall->DespawnOrUnsummon();
            }

            if (Creature* seaping = me->FindNearestCreature(600000, 100.0f, true))
            {
                seaping->RemoveAura(SPELL_SEAPING_TWILIGHT);
            }

            std::list<Creature*> unitList;
            me->GetCreatureListWithEntryInGrid(unitList, 55427, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {
                (*itr)->DespawnOrUnsummon();
            }

            me->GetCreatureListWithEntryInGrid(unitList, 55468, 100.0f);
            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {
                (*itr)->DespawnOrUnsummon();
            }


            me->SummonCreature(54548, HomePoints[0], TEMPSUMMON_DEAD_DESPAWN, 0);

        }

        void EnterCombat(Unit* /*Ent*/) override
        {
            _EnterCombat();

            if (instance)
                instance->SetData(DATA_ARCHBISHOP_BENEDICTUS_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_ACTIVATE_WALL, 1000);

            if (me->FindNearestCreature(NPC_THRALL_FINAL, 100.0f, true))
            {
                events.ScheduleEvent(EVENT_SMITE, 4000);
                events.ScheduleEvent(EVENT_RIGHTEOUS_SHEAR, 7000);
                events.ScheduleEvent(EVENT_PURIFYING_LIGHT, 10000);
                events.ScheduleEvent(EVENT_WAVE_OF_VIRTUE, 30000);
            }
            me->SetHomePosition(HomePoints[1]);
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if (me->HealthBelowPct(60) && twilightPhase == false)
            {
                if (damage > 0 )
                {
                    events.CancelEvent(EVENT_SMITE);
                    events.CancelEvent(EVENT_RIGHTEOUS_SHEAR);
                    events.CancelEvent(EVENT_PURIFYING_LIGHT);
                    events.CancelEvent(EVENT_WAVE_OF_VIRTUE);
                    twilightPhase = true;

                    std::list<Creature*> unitList;
                    me->GetCreatureListWithEntryInGrid(unitList, 55427, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {
                        (*itr)->DespawnOrUnsummon();
                    }

                    me->CastSpell(me, SPELL_TWILIGHT_EPIPHANY, false);

                    events.ScheduleEvent(EVENT_TWILIGHT_BLAST, 15000);
                    events.ScheduleEvent(EVENT_TWILIGHT_SHEAR, 19000);
                    events.ScheduleEvent(EVENT_CORRUPTING_TWILIGHT, 22000);
                    events.ScheduleEvent(EVENT_WAVE_OF_TWILIGHT, 40000);
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (intro == false)
            {
                if (!UpdateVictim())
                    return;
            }

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 100.0f, true))
            {
                if (me->GetVictim() == thrall && cooldownVictim == false)
                {
                    cooldownVictim = true;
                    events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                }
            }

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
                return;*/

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVEMENT_1:
                        me->GetMotionMaster()->MovePoint(1, ArchbishopPoints[1]);
                        events.ScheduleEvent(EVENT_MOVEMENT_2, 10000);
                        break;
                    case EVENT_MOVEMENT_2:
                        me->GetMotionMaster()->MovePoint(2, ArchbishopPoints[2]);
                        if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 200.0f, true))
                        {
                            thrall->AI()->DoAction(ACTION_MOVE);
                        }
                        events.ScheduleEvent(EVENT_MOVEMENT_3, 8000);
                        break;
                    case EVENT_MOVEMENT_3:
                        me->GetMotionMaster()->MovePoint(3, ArchbishopPoints[3]);
                        events.ScheduleEvent(EVENT_SUMMON_HOLY_WALL, 7000);
                        break;
                    case EVENT_SUMMON_HOLY_WALL:
                        me->CastSpell(me, 102629, false);
                        events.ScheduleEvent(EVENT_MOVEMENT_4, 3000);
                        break;
                    case EVENT_ACTIVATE_WALL:
                        if (GameObject* holyWall = me->FindNearestGameObject(210097, 100.0f))
                            instance->HandleGameObject(holyWall->GetGUID(), false, holyWall);
                        break;
                    case EVENT_MOVEMENT_4:
                        me->GetMotionMaster()->MovePoint(4, ArchbishopPoints[4]);
                        events.ScheduleEvent(EVENT_MOVEMENT_5, 5000);
                        break;
                    case EVENT_MOVEMENT_5:
                        me->GetMotionMaster()->MovePoint(5, ArchbishopPoints[5]);
                        events.ScheduleEvent(EVENT_MOVEMENT_6, 3500);
                        break;
                    case EVENT_MOVEMENT_6:
                        me->GetMotionMaster()->MovePoint(6, ArchbishopPoints[6]);
                        events.ScheduleEvent(EVENT_START_BENEDICTUS, 22000);
                        break;
                    case EVENT_START_BENEDICTUS:
                        intro = false;
                        me->SetFaction(14);
                        break;
                    case EVENT_SMITE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_SMITE, false);
                        }
                        events.ScheduleEvent(EVENT_SMITE, 14000);
                        break;
                    case EVENT_RIGHTEOUS_SHEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_RIGHTEOUS_SHEAR, false);
                        }
                        break;
                    case EVENT_PURIFYING_LIGHT:
                        me->CastSpell(me, SPELL_PURIFYING_LIGHT_CAST, false);
                        me->CastSpell(me, SPELL_PURIFYING_LIGHT_SUMMON1, true);
                        me->CastSpell(me, SPELL_PURIFYING_LIGHT_SUMMON2, true);
                        me->CastSpell(me, SPELL_PURIFYING_LIGHT_SUMMON3, true);
                        if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 200.0f, true))
                        {
                            thrall->AI()->DoAction(ACTION_CHAIN_LIGHTNING);
                        }
                        events.ScheduleEvent(EVENT_PURIFYING_LIGHT, 45000);
                        break;
                    case EVENT_WAVE_OF_VIRTUE:
                        me->SummonCreature(55441, 3483.79f, 229.25f, -120.10f, 0.614074f, TEMPSUMMON_TIMED_DESPAWN, 10000);

                        if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 200.0f, true))
                        {
                            thrall->AI()->DoAction(ACTION_WATER_SHELL);
                        }
                        events.ScheduleEvent(EVENT_WAVE_OF_VIRTUE, 45000);
                        break;
                    case EVENT_TWILIGHT_BLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_TWILIGHT_BLAST, false);
                        }
                        events.ScheduleEvent(EVENT_TWILIGHT_BLAST, 14000);
                        break;
                    case EVENT_TWILIGHT_SHEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_TWILIGHT_SHEAR, false);
                        }
                        break;
                    case EVENT_CORRUPTING_TWILIGHT:
                        me->CastSpell(me, SPELL_CORRUPTING_TWILIGHT_CAST, false);
                        me->CastSpell(me, SPELL_CORRUPTING_TWILIGHT_SUMMON1, true);
                        me->CastSpell(me, SPELL_CORRUPTING_TWILIGHT_SUMMON2, true);
                        me->CastSpell(me, SPELL_CORRUPTING_TWILIGHT_SUMMON3, true);
                        events.ScheduleEvent(EVENT_CORRUPTING_TWILIGHT, 45000);
                        break;
                    case EVENT_WAVE_OF_TWILIGHT:
                        me->SummonCreature(55469, 3483.79f, 229.25f, -120.10f, 0.614074f, TEMPSUMMON_TIMED_DESPAWN, 10000);
                        if (Creature* seaping = me->FindNearestCreature(600000, 100.0f, true))
                        {
                            seaping->CastSpell(seaping, SPELL_SEAPING_TWILIGHT, false);
                        }
                        events.ScheduleEvent(EVENT_WAVE_OF_TWILIGHT, 45000);
                        break;
                    case EVENT_CHECK_PLAYER:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 100.0f);

                        if (targets.size() == 0)
                        {
                            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_FINAL, 200.0f, true))
                            {
                                me->SetReactState(REACT_PASSIVE);
                                thrall->RemoveAura(103762);
                                thrall->SetReactState(REACT_PASSIVE);
                                thrall->AI()->EnterEvadeMode();
                                thrall->AI()->DoAction(ACTION_THRALL_STOP_CAST);

                                if (instance)
                                {
                                    instance->SetData(DATA_ARCHBISHOP_BENEDICTUS_EVENT, NOT_STARTED);
                                    instance->SetBossState(DATA_ARCHBISHOP_BENEDICTUS, NOT_STARTED);
                                }
                                EnterEvadeMode();

                                thrall->AI()->Reset();
                                Reset();
                                me->SetReactState(REACT_AGGRESSIVE);
                            }
                        }
                        cooldownVictim = false;
                        break;
                    }
                    /*case EVENT_THRALL_CAST:
                        thrall->AI()->DoAction(ACTION_THRALL_START_CAST);
                        break;*/

                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_purifying_light : public CreatureScript
{
public:
    npc_purifying_light() : CreatureScript("npc_purifying_light") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_purifying_lightAI(creature);
    }

    struct npc_purifying_lightAI : public ScriptedAI
    {
        npc_purifying_lightAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetObjectScale(0.1f);
            me->SetDisableGravity(true);
            me->SetAnimTier(UnitBytes1_Flags(UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER), true);
            me->SetHover(true);
            me->SetCanFly(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + urand(0, 10), me->GetPositionY() + urand(0, 10), me->GetPositionZ() + 5.0f);
            events.ScheduleEvent(EVENT_LIGHT_VISUAL, 2000);
            events.ScheduleEvent(EVENT_LIGHT_CHARGE, 8000);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
                return;*/

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LIGHT_VISUAL:
                        me->SetObjectScale(1.0f);
                        me->CastSpell(me, SPELL_PURIFYING_LIGHT_VISUAL, true);
                        break;
                    case EVENT_LIGHT_CHARGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            me->CastSpell(target, SPELL_PURIFYING_BLAST, false);
                            events.ScheduleEvent(EVENT_PURIFIED, 500);
                        }
                        break;
                    case EVENT_PURIFIED:
                        me->CastSpell(me, SPELL_PURIFYING_BLAST_DAMAGE, false);
                        me->RemoveAura(SPELL_PURIFYING_LIGHT_VISUAL);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        break;
                }
            }
        }
    };

};

class npc_wave_of_virtue : public CreatureScript
{
public:
    npc_wave_of_virtue() : CreatureScript("npc_wave_of_virtue") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wave_of_virtueAI(creature);
    }

    struct npc_wave_of_virtueAI : public ScriptedAI
    {
        npc_wave_of_virtueAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 2.0f);
        }

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->GetMotionMaster()->MovePoint(0, 3606.74f, 301.41f, -120.10f);
            events.ScheduleEvent(EVENT_WAVE_OF_VIRTUE_DAMAGE, 1000);
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
                    case EVENT_WAVE_OF_VIRTUE_DAMAGE:
                        me->GetMotionMaster()->MovePoint(0, 3606.74f, 301.41f, -120.10f);
                        events.ScheduleEvent(EVENT_WAVE_OF_VIRTUE_DAMAGE, 750);
                        break;
                }
            }
        }
    };

};

class npc_corrupting_twilight : public CreatureScript
{
public:
    npc_corrupting_twilight() : CreatureScript("npc_corrupting_twilight") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corrupting_twilightAI(creature);
    }

    struct npc_corrupting_twilightAI : public ScriptedAI
    {
        npc_corrupting_twilightAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetObjectScale(0.1f);
            me->SetDisableGravity(true);
            me->SetAnimTier(UnitBytes1_Flags(UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER), true);
            me->SetHover(true);
            me->SetCanFly(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + urand(0, 10), me->GetPositionY() + urand(0, 10), me->GetPositionZ() + 5.0f);
            events.ScheduleEvent(EVENT_TWILIGHT_VISUAL, 2000);
            events.ScheduleEvent(EVENT_TWILIGHT_CHARGE, 8000);
        }

        void DamageTaken(Unit* /*done_by*/, uint32&/*damage*/) override
        {
            /*if (damage > 0)
            {

            }*/
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            /*if (me->HasUnitState(UNIT_STATE_CASTING))
            return;*/

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TWILIGHT_VISUAL:
                    me->SetObjectScale(1.0f);
                    me->CastSpell(me, SPELL_CORRUPTING_TWILIGHT_VISUAL, true);
                    break;
                case EVENT_TWILIGHT_CHARGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        me->CastSpell(target, SPELL_TWILIGHT_BOLT, false);
                        events.ScheduleEvent(EVENT_TWILIGHT_BOLT, 500);
                    }
                    break;
                case EVENT_TWILIGHT_BOLT:
                    me->CastSpell(me, SPELL_TWILIGHT_BOLT_DAMAGE, false);
                    me->RemoveAura(SPELL_CORRUPTING_TWILIGHT_VISUAL);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    break;
                }
            }
        }
    };

};

class npc_wave_of_twilight : public CreatureScript
{
public:
    npc_wave_of_twilight() : CreatureScript("npc_wave_of_twilight") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wave_of_twilightAI(creature);
    }

    struct npc_wave_of_twilightAI : public ScriptedAI
    {
        npc_wave_of_twilightAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }
        InstanceScript *instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 2.0f);
        }

        void Reset() override
        {
            events.Reset();
        }

        void AttackStart(Unit* /*victim*/) override
        {
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->CastSpell(me, SPELL_WAVE_OF_TWILIGHT_WAVE, true);

            me->GetMotionMaster()->MovePoint(0, 3606.74f, 301.41f, -120.10f);
            events.ScheduleEvent(EVENT_WAVE_OF_TWILIGHT_DAMAGE, 1000);
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
                    case EVENT_WAVE_OF_TWILIGHT_DAMAGE:
                        me->CastSpell(me, SPELL_WAVE_OF_TWILIGHT_DAMAGE, true);
                        me->GetMotionMaster()->MovePoint(0, 3606.74f, 301.41f, -120.10f);
                        events.ScheduleEvent(EVENT_WAVE_OF_TWILIGHT_DAMAGE, 750);
                        break;

                }
            }
        }
    };

};

void AddSC_boss_archbishop_benedictus()
{
    new boss_archbishop_benedictus();
    new npc_purifying_light();
    new npc_wave_of_virtue();
    new npc_corrupting_twilight();
    new npc_wave_of_twilight();
}

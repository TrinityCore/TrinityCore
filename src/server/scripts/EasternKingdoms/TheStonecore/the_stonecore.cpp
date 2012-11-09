/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "the_stonecore.h"

enum Spells
{
    SPELL_QUAKE              = 81008,
    H_SPELL_QUAKE            = 92631,
    SPELL_FELL_FIREBALL      = 80344,
    H_SPELL_FELL_FIREBALL    = 92638,
    SPELL_BLUR               = 81216,
    SPELL_MILL_FEAR          = 81442,
    SPELL_FROSTBOLT_VOLLEY   = 81440,
    H_SPELL_FROSTBOLT_VOLLEY = 92642,
    SPELL_IMPENDING_DOOM     = 86830,
    SPELL_SHADOW_BOLT        = 81439,
    H_SPELL_SHADOW_BOLT      = 92641,
    SPELL_SHADOWFURY         = 81441,
    H_SPELL_SHADOWFURY       = 92644,
    SPELL_TIGULE             = 81220,
    SPELL_ROCK_BORE          = 80028,
    H_SPELL_ROCK_BORE        = 92630,
    SPELL_SCHARGE            = 81574,
    SPELL_SPINNING_SLASH     = 81568,
    SPELL_BODY_SLAM          = 80180,
    SPELL_SHOCKWAVE          = 80195,
    H_SPELL_SHOCKWAVE        = 92640,
    SPELL_DUST_STORM         = 81463,
    SPELL_FORCE_OF_EARTH     = 81459,
    SPELL_GROUND_SHOCK       = 81530,
    H_SPELL_GROUND_SHOCK     = 92628,
    SPELL_LAVA_BURST         = 81576,
    H_SPELL_LAVA_BURST       = 92626,
    SPELL_FLAY               = 79922,
    SPELL_IGNITE             = 80151,
    H_SPELL_IGNITE           = 92636,
    SPELL_MAGMA_ERUPTION     = 80038,
    SPELL_DEMON_PORTAL       = 80308,
    SPELL_SHADOWBOLT         = 80279,
    H_SPELL_SHADOWBOLT       = 92637,
    SPELL_CLEAVE             = 15496,
    SPELL_RAGE               = 80158,
};

enum eEvents
{
    EVENT_NONE,
    EVENT_QUAKE,
    EVENT_FELL_FIREBALL,
    EVENT_BLUR,
    EVENT_MILL_FEAR,
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_IMPENDING_DOOM,
    EVENT_SHADOW_BOLT,
    EVENT_SHADOWFURY,
    EVENT_TIGULE,
    EVENT_ROCK_BORE,
    EVENT_SCHARGE,
    EVENT_SPINNING_SLASH,
    EVENT_BODY_SLAM,
    EVENT_SHOCKWAVE,
    EVENT_DUST_STORM,
    EVENT_FORCE_OF_EARTH,
    EVENT_GROUND_SHOCK,
    EVENT_LAVA_BURST,
    EVENT_FLAY,
    EVENT_IGNITE,
    EVENT_MAGMA_ERUPTION,
    EVENT_DEMON_PORTAL,
    EVENT_SHADOWBOLT,
    EVENT_CLEAVE,
    EVENT_RAGE,
};

class mob_crystalspawn_giant : public CreatureScript
{
public:
    mob_crystalspawn_giant() : CreatureScript("mob_crystalspawn_giant") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_crystalspawn_giantAI(creature);
    }

    struct mob_crystalspawn_giantAI : public ScriptedAI
    {
        mob_crystalspawn_giantAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_QUAKE, 5000 + rand()%5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_QUAKE:
                        DoCast(me->getVictim(), SPELL_QUAKE);
                        events.RescheduleEvent(EVENT_QUAKE, 5000 + rand()%5000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_impp : public CreatureScript
{
public:
    mob_impp() : CreatureScript("mob_impp") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_imppAI(creature);
    }

    struct mob_imppAI : public ScriptedAI
    {
        mob_imppAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FELL_FIREBALL, 1000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FELL_FIREBALL:
                        if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FELL_FIREBALL);
                        events.RescheduleEvent(EVENT_FELL_FIREBALL, 1000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_rock_borer : public CreatureScript
{
public:
    mob_rock_borer() : CreatureScript("mob_rock_borer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_rock_borerAI(creature);
    }

    struct mob_rock_borerAI : public ScriptedAI
    {
        mob_rock_borerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 _SpellBoreTimer;

        void Reset()
        {
            _SpellBoreTimer = 6000;
        }

        void EnterCombar(Unit* ) { }

        void MoveInLineOfSight(Unit* who) { }

        void UpdateAI(const uint32 Diff)
        {
            if(instance->GetData(DATA_CORBORUS_EVENT) == DONE || instance->GetData(DATA_CORBORUS_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();
            if (_SpellBoreTimer <= Diff)
            {
                if(!IsHeroic())
                    DoCast(me->getVictim(),SPELL_ROCK_BORE);
                if(IsHeroic())
                    DoCast(me->getVictim(),H_SPELL_ROCK_BORE);
                _SpellBoreTimer = 6000;
            }
            else
                _SpellBoreTimer -= Diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_millhouse_manastorm : public CreatureScript
{
public:
    mob_millhouse_manastorm() : CreatureScript("mob_millhouse_manastorm") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_millhouse_manastormAI(creature);
    }

    struct mob_millhouse_manastormAI : public ScriptedAI
    {
        mob_millhouse_manastormAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_MILL_FEAR, 10000);
            events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 7000 + rand()%10000);
            events.ScheduleEvent(EVENT_IMPENDING_DOOM, 10000 + rand()%10000);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 1000);
            events.ScheduleEvent(EVENT_SHADOWFURY, 5000 + rand()%15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MILL_FEAR:
                        if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_MILL_FEAR);
                        events.RescheduleEvent(EVENT_MILL_FEAR, 10000);
                        return;
                    case EVENT_SHADOW_BOLT:
                        DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOWBOLT, 1000);
                        return;
                    case EVENT_FROSTBOLT_VOLLEY:
                        if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FROSTBOLT_VOLLEY);
                        events.RescheduleEvent(EVENT_FROSTBOLT_VOLLEY, rand()%15000);
                        return;
                    case EVENT_IMPENDING_DOOM:
                        if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_IMPENDING_DOOM);
                        events.RescheduleEvent(EVENT_IMPENDING_DOOM, rand()%15000);
                        return;
                    case EVENT_SHADOWFURY:
                        if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOWFURY);
                        events.RescheduleEvent(SPELL_SHADOWFURY, 5000 + rand()%15000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_the_stonecore()
{
    new mob_crystalspawn_giant();
    new mob_impp();
    new mob_millhouse_manastorm();
    new mob_rock_borer;
}
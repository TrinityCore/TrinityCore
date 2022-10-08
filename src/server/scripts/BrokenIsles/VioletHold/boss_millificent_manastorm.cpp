/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "SpellHistory.h"
#include <G3D/Vector3.h>
#include "violet_hold_assault.h"

enum Spells
{
    // Millificient Manastorm
    SPELL_ELEMENTIUM_SQUIRREL_BOMB              = 201240,
    SPELL_THORIUM_ROCKET_CHICKEN                = 201392,
    SPELL_OVERLOADED_ELEMENTIUM_SQUIRREL_BOMB   = 201432,
    SPELL_REINFORCED_THORIUM_ROCKET_CHICKEN     = 201438,
    SPELL_DELTA_FINGER_LASER_X                  = 201159,
    SPELL_HYPER_ZAP_ULTIMATE_MARK               = 202310,
    SPELL_MEGA_MINIATURIZATION                  = 201581,
    SPELL_MILLIFICENT_RAGE                      = 201572,

    // Squirrel Bomb
    SPELL_EXPLOSION                             = 201291,
    SPELL_DISARMING                             = 201265,
    SPELL_OVERLOADED                            = 201434,

    // Rocket Chicken
    SPELL_ROCKET_CHICKEN_ROCKET                 = 201369,
    SPELL_CHICKEN_SWARN_ROCKETS                 = 201356,
    SPELL_CHICKEN_SWARN_ROCKETS_TRIGGER         = 201384,
    SPELL_CHICKEN_SWARN_ROCKETS_TARGETING       = 201385,
    SPELL_CHICKEN_SWARN_ROCKETS_TARGETING_2     = 201386,
    SPELL_CHICKEN_SWARN_DMG                     = 201387,
    SPELL_THORIUM_PLATING                       = 201441,

    // Mechanical Bomb Squirrel
    SPELL_BOMB_SQUIRREL_BOMB                    = 201302,
};

enum Events
{
    // Millificent
    EVENT_ELEMENTIUM_SQUIRREL_BOMB  = 1,
    EVENT_THORIUM_ROCKET_CHICKEN    = 2,
    EVENT_DELTA_FINGER_LASER_X      = 3,
    EVENT_END_COMBAT                = 4,

    // Squirrel Bomb
    EVENT_OVERLOADED                = 5,

    // Mechanical Squirrel Bomb
    EVENT_BOMB_SQUIRREL_BOMB        = 6,

    // Thorium Rocket Chicken
    EVENT_SWARN_ROCKETS             = 7,
    EVENT_ROCKET_CHICKEN_ROCKET     = 8,
};

enum Adds
{
    NPC_THORIUM_ROCKET_CHICKEN              = 102103,
    NPC_ELEMENTIUM_SQUIRREL_BOMB            = 102043,
    NPC_MECHANICAL_BOMB_SQUIRELL            = 102137,
    NPC_OVERLOADED_ELEMENTIUM_SQUIRELL_BOMB = 102136,
    NPC_REINFORCED_THORIUM_ROCKET_CHICKEN   = 102139,
};

enum Says
{
    SAY_INTRO_1     = 0,
    SAY_INTRO_2     = 1,
    SAY_AGGRO       = 2,
    SAY_SQUIRREL    = 3,
    SAY_CHICKEN     = 4,
    SAY_INSULT      = 5,
    SAY_INSULT_2    = 6,
    SAY_WIPE        = 7,
    SAY_DEFEAT      = 8,
};

class boss_millificent_manastorm : public CreatureScript
{
    public:
        boss_millificent_manastorm() : CreatureScript("boss_millificent_manastorm")
        {}

        struct boss_millificent_manastorm_AI : public BossAI
        {
            boss_millificent_manastorm_AI(Creature* creature) : BossAI(creature, DATA_MANASTORM)
            {}

            void Reset() override
            {
                _Reset();
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                _enraged = false;
                _ended = false;
                events.ScheduleEvent(EVENT_ELEMENTIUM_SQUIRREL_BOMB, Seconds(10));
                events.ScheduleEvent(EVENT_THORIUM_ROCKET_CHICKEN, Seconds(25));
                events.ScheduleEvent(EVENT_DELTA_FINGER_LASER_X, Seconds(5));
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (me->HealthBelowPct(45) && !_enraged)
                {
                    _enraged = true;
                    DoCast(me, SPELL_MILLIFICENT_RAGE, true);
                }
                else if (me->HealthBelowPct(10) && !_ended)
                {
                    _ended = true;
                    damage = 0;
                    _killer = me->GetVictim();
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->CastStop();
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1));
                    Talk(SAY_DEFEAT);
                    DoCast(me, SPELL_HYPER_ZAP_ULTIMATE_MARK);
                    events.ScheduleEvent(EVENT_END_COMBAT, Seconds(2));
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                me->GetSpellHistory()->ResetAllCooldowns();

                switch (eventId)
                {
                    case EVENT_ELEMENTIUM_SQUIRREL_BOMB:
                    {
                        Talk(SAY_SQUIRREL);

                        if (_enraged)
                            DoCast(SPELL_OVERLOADED_ELEMENTIUM_SQUIRREL_BOMB);
                        else
                            DoCast(SPELL_ELEMENTIUM_SQUIRREL_BOMB);

                        events.ScheduleEvent(EVENT_ELEMENTIUM_SQUIRREL_BOMB, Seconds(15));
                        break;
                    }

                    case EVENT_THORIUM_ROCKET_CHICKEN:
                    {
                        Talk(SAY_CHICKEN);

                        if (_enraged)
                            DoCast(SPELL_REINFORCED_THORIUM_ROCKET_CHICKEN);
                        else
                            DoCast(SPELL_THORIUM_ROCKET_CHICKEN);
                        events.ScheduleEvent(EVENT_THORIUM_ROCKET_CHICKEN, Seconds(20));
                        break;
                    }

                    case EVENT_DELTA_FINGER_LASER_X:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                            DoCast(target, SPELL_DELTA_FINGER_LASER_X);
                        events.ScheduleEvent(EVENT_DELTA_FINGER_LASER_X, Seconds(10));
                        break;
                    }

                    case EVENT_END_COMBAT:
                    {
                        DoCast(me, SPELL_MEGA_MINIATURIZATION);
                        instance->SetBossState(DATA_MANASTORM, DONE);
                        me->DespawnOrUnsummon(Seconds(5));
                        break;
                    }
                }
            }

            private:
                bool _enraged, _ended;
                Unit* _killer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_millificent_manastorm_AI(creature);
        }
};

class npc_vha_squirrel_bomb : public CreatureScript
{
    public:
        npc_vha_squirrel_bomb() : CreatureScript("npc_vha_squirrel_bomb")
        {}

        struct npc_vha_squirrel_bomb_AI : public ScriptedAI
        {
            npc_vha_squirrel_bomb_AI(Creature* creature) : ScriptedAI(creature)
            {}

            void IsSummonedBy(Unit* /**/) override
            {
                if (me->GetEntry() == NPC_OVERLOADED_ELEMENTIUM_SQUIRELL_BOMB)
                    DoCast(me, SPELL_OVERLOADED, true);

                DoCast(me, SPELL_EXPLOSION);
                _events.ScheduleEvent(EVENT_OVERLOADED, Seconds(10));
            }

            void SpellHit(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;

                if (spell->Id == SPELL_DISARMING)
                {
                    me->CastStop();
                    DoCast(me, SPELL_OVERLOADED);
                    me->AddUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
                    me->DespawnOrUnsummon(Seconds(7));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_OVERLOADED)
                    {
                        DoCast(me, SPELL_OVERLOADED);
                        me->AddUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
                        me->DespawnOrUnsummon(Seconds(6));
                    }
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_squirrel_bomb_AI(creature);
        }
};

class npc_vha_mechanical_squirrel_bomb : public CreatureScript
{
    public:
        npc_vha_mechanical_squirrel_bomb() : CreatureScript("npc_vha_mechanical_squirrel_bomb")
        {}

        struct npc_vha_mechanical_squirrel_bomb_AI : public ScriptedAI
        {
            npc_vha_mechanical_squirrel_bomb_AI(Creature* creature) : ScriptedAI(creature)
            {}

            void IsSummonedBy(Unit* /**/) override
            {
                _events.ScheduleEvent(EVENT_BOMB_SQUIRREL_BOMB, Seconds(1));
            }

            void SpellHitTarget(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;

                if (spell->Id == SPELL_BOMB_SQUIRREL_BOMB)
                {
                    _events.Reset();
                    me->Kill(me);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_BOMB_SQUIRREL_BOMB)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                            DoCast(target, SPELL_BOMB_SQUIRREL_BOMB);
                        else
                            _events.ScheduleEvent(EVENT_BOMB_SQUIRREL_BOMB, Seconds(2));
                    }
                }
            }

            private:
                EventMap _events;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_mechanical_squirrel_bomb_AI(creature);
        }
};

class npc_vha_rocket_chicken : public CreatureScript
{
    public:
        npc_vha_rocket_chicken() : CreatureScript("npc_vha_rocket_chicken")
        {}

        struct npc_vha_rocket_chicken_AI : public ScriptedAI
        {
            npc_vha_rocket_chicken_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void IsSummonedBy(Unit* /**/) override
            {
                if (IsHeroic())
                    _events.ScheduleEvent(EVENT_SWARN_ROCKETS, Seconds(2));

                _events.ScheduleEvent(EVENT_ROCKET_CHICKEN_ROCKET, Seconds(2));

                if (me->GetEntry() == NPC_REINFORCED_THORIUM_ROCKET_CHICKEN)
                    DoCast(me, SPELL_THORIUM_PLATING, true);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_SWARN_ROCKETS)
                    {
                        DoCast(me, SPELL_CHICKEN_SWARN_ROCKETS_TRIGGER, true);
                        _events.ScheduleEvent(EVENT_SWARN_ROCKETS, Seconds(2));
                    }
                    else if (eventId == EVENT_ROCKET_CHICKEN_ROCKET)
                    {
                        me->AttackStop();
                        me->StopMoving();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        {
                            me->SetFacingToObject(target, true);
                            DoCast(target, SPELL_ROCKET_CHICKEN_ROCKET);
                        }

                        _events.ScheduleEvent(EVENT_ROCKET_CHICKEN_ROCKET, Seconds(3));
                    }
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_rocket_chicken_AI(creature);
        }
};

class spell_vha_swarn_rockets : public SpellScriptLoader
{
    public:
        spell_vha_swarn_rockets() : SpellScriptLoader("spell_vha_swarn_rockets")
        {}

        class spell_swarn_rockets_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_swarn_rockets_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    Unit* caster = GetCaster();

                    caster->CastSpell(GetHitUnit(), SPELL_CHICKEN_SWARN_DMG, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_swarn_rockets_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_swarn_rockets_SpellScript();
        }
};

void AddSC_boss_millificient_manastorm()
{
    new boss_millificent_manastorm();
    new npc_vha_rocket_chicken();
    new npc_vha_squirrel_bomb();
    new npc_vha_mechanical_squirrel_bomb();
    new spell_vha_swarn_rockets();
}

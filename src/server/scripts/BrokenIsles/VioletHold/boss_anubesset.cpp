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
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellMgr.h"
#include "violet_hold_assault.h"

enum Spells
{
    SPELL_IMPALE                = 202341,
    SPELL_IMPALE_TRIGGER        = 202350,
    SPELL_IMPALE_DMG            = 202353,
    SPELL_MANDIBLE_STRIKE       = 202217,
    SPELL_CALL_OF_SWARN         = 201863,
    SPELL_SUMMON_BETTLE_TRIGGER = 202526,
    SPELL_SUMMON_BETTLE         = 202513,

    // Spitting Scarab
    SPELL_POISON_SPIT           = 202300,
    SPELL_BURROW                = 202304,

    // Blistering Bettle
    SPELL_BLISTERING_OOZE       = 202487,
    SPELL_BLISTERING_OOZE_AREA  = 202483,
    SPELL_BLISTERING_OOZE_DMG   = 202485,
    SPELL_FIXATE                = 202480,
};

enum Events
{
    // Anub'esset
    EVENT_MANDIBLE_STRIKE   = 1,
    EVENT_IMPALE            = 2,
    EVENT_CALL_OF_THE_SWARN = 3,

    // Spitting Scarab
    EVENT_POISON_SPIT       = 4,

    // Blistering Bettle
    EVENT_BLISTERING_OOZE   = 5,
};

enum Adds
{
    NPC_SPITTING_SCARAB     = 102271,
    NPC_BLISTERING_BETTLES  = 102540,
    NPC_IMPALE_DUMMY        = 999850,
};

enum Says
{
    SAY_AGGRO           = 1,
    SAY_MANDIBLE_STRIKE = 2,
    SAY_IMPALE          = 3,
    SAY_CALL_OF_SWARN   = 4,
    SAY_KILL            = 5,
    SAY_WIPE            = 6,
    SAY_DEATH           = 7,
};

enum Points
{
    POINT_REACHED = 1,
};

class boss_anubesset : public CreatureScript
{
    public:
        boss_anubesset() : CreatureScript("boss_anubesset")
        {}

        struct boss_anubesset_AI : public BossAI
        {
            boss_anubesset_AI(Creature* creature) : BossAI(creature, DATA_ANUBESSET)
            {}

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_IMPALE, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MANDIBLE_STRIKE, 9 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_CALL_OF_THE_SWARN, 30 * IN_MILLISECONDS);
            }

            void EnterEvadeMode(EvadeReason) override
            {
                Talk(SAY_WIPE);
                CreatureAI::EnterEvadeMode();
            }

            void KilledUnit(Unit* unit) override
            {
                if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_IMPALE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                Talk(SAY_IMPALE);
                                DoCast(target, SPELL_IMPALE);
                            }
                            events.ScheduleEvent(EVENT_IMPALE, 23 * IN_MILLISECONDS);
                            break;

                        case EVENT_MANDIBLE_STRIKE:
                            if (Unit* victim = me->GetVictim())
                            {
                                Talk(SAY_MANDIBLE_STRIKE);
                                DoCast(victim, SPELL_MANDIBLE_STRIKE);
                            }
                            events.ScheduleEvent(EVENT_MANDIBLE_STRIKE, 23 * IN_MILLISECONDS);
                            break;

                        case EVENT_CALL_OF_THE_SWARN:
                            Talk(SAY_CALL_OF_SWARN);
                            DoCast(me, SPELL_CALL_OF_SWARN);
                            events.ScheduleEvent(EVENT_CALL_OF_THE_SWARN, 60 * IN_MILLISECONDS);
                            break;

                        default : break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_anubesset_AI(creature);
        }
};

class npc_vha_spitting_scarab : public CreatureScript
{
  public:
    npc_vha_spitting_scarab() : CreatureScript("npc_vha_spitting_scarab")
    {}

    struct npc_vha_spitting_scarab_AI : public ScriptedAI
    {
        npc_vha_spitting_scarab_AI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset() override
        {
            _anubesset = nullptr;
            _poisonTimer = 0;

            if (SpellInfo const * spell = sSpellMgr->GetSpellInfo(SPELL_BURROW))
            {
                Position burrow_pos = me->GetRandomNearPosition(spell->GetEffect(EFFECT_0)->RadiusEntry->Radius);
                me->CastSpell(burrow_pos.GetPositionX(), burrow_pos.GetPositionY(), burrow_pos.GetPositionZ(), SPELL_BURROW, true);
            }
        }

        void EnterCombat(Unit* /**/) override
        {
            _poisonTimer = 0;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner && summoner->ToCreature())
                _anubesset = summoner->ToCreature();
        }

        void UpdateAI(uint32 diff) override
        {
            _poisonTimer += diff;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (_poisonTimer >= 3 * IN_MILLISECONDS && _anubesset)
            {
                if (Unit* target = _anubesset->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    DoCast(target, SPELL_POISON_SPIT);

                _poisonTimer = 0;
            }
        }

        private:
            uint32 _poisonTimer;
            Creature* _anubesset;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vha_spitting_scarab_AI(creature);
    }
};

class npc_vha_blistering_bettle : public CreatureScript
{
    public:
        npc_vha_blistering_bettle() : CreatureScript("npc_vha_blistering_bettle")
        {

        }

        struct npc_vha_blistering_bettle_AI : ScriptedAI
        {
            npc_vha_blistering_bettle_AI(Creature* creature) : ScriptedAI(creature)
            {

            }

            void Reset() override
            {
                _initTimer = 0;
                _fixateTimer = 0;
                _prepared = false;
                _target = nullptr;
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (summoner && summoner->ToCreature())
                    _anubesset = summoner->ToCreature();
            }

            void FindNewTarget()
            {
                if (!_anubesset)
                    return;

                _target = nullptr;

                while (!_target)
                {
                    _target = _anubesset->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true);
                }

                _fixateTimer = 0;
                DoCast(_target, SPELL_FIXATE, true);
                me->GetMotionMaster()->MoveFollow(_target, 0, 0);
            }

            void CheckDistForExplode()
            {
                if (!_target)
                    return;

                me->GetMotionMaster()->MoveFollow(_target, 0, 0);
                if (me->IsWithinMeleeRange(_target))
                    _target->Kill(me);
            }

            void JustDied(Unit* /**/) override
            {
                DoCast(me, SPELL_BLISTERING_OOZE, true);
                DoCast(me, SPELL_BLISTERING_OOZE_AREA, true);
            }

            void UpdateAI(uint32 diff) override
            {
                _initTimer += diff;
                _fixateTimer += diff;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (_initTimer >= 5 * IN_MILLISECONDS && !_prepared)
                {
                    _prepared = true;
                    FindNewTarget();

                }

                if (_fixateTimer >= 10 * IN_MILLISECONDS)
                    FindNewTarget();

                if (_target && _target->isDead())
                    FindNewTarget();

                CheckDistForExplode();

            }

            private:
                uint32 _initTimer;
                uint32 _fixateTimer;
                bool _prepared;
                Unit* _target;
                Creature* _anubesset;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_blistering_bettle_AI(creature);
        }
};

class npc_vha_impale_dummy : public CreatureScript
{
    public:
        npc_vha_impale_dummy() : CreatureScript("npc_vha_impale_dummy")
        {}

        struct npc_vha_impale_dummy_AI : public ScriptedAI
        {
            npc_vha_impale_dummy_AI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset() override
            {
                _timer = 0;
                me->SetReactState(REACT_PASSIVE);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == POINT_REACHED)
                    me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff) override
            {
                _timer += diff;

                if (_timer >= 250)
                {
                    _timer = 0;
                    DoCast(me, SPELL_IMPALE_TRIGGER, true);
                }
            }

            private:
                uint32 _timer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_impale_dummy_AI(creature);
        }
};

class spell_anubesset_impale : public SpellScriptLoader
{
    public:
        spell_anubesset_impale() : SpellScriptLoader("spell_anubesset_impale")
        {}

        class spell_anubesset_impale_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_anubesset_impale_SpellScript);

                void HandleDummy(SpellEffIndex)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    if (Creature* dummy = GetCaster()->SummonCreature(NPC_IMPALE_DUMMY, GetCaster()->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 10000))
                        dummy->GetMotionMaster()->MovePoint(POINT_REACHED, GetHitUnit()->GetPosition());
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_anubesset_impale_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_anubesset_impale_SpellScript();
        }
};

class spell_anubesset_call_of_swarm : public SpellScriptLoader
{
    public:
        spell_anubesset_call_of_swarm() : SpellScriptLoader("spell_anubesset_call_of_swarm")
        {}

        class spell_anubesset_call_of_swarm_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_anubesset_call_of_swarm_AuraScript);

                void HandleSummons(AuraEffect const* /**/)
                {
                    if (!GetCaster())
                        return;

                    if (Map* map = GetCaster()->GetMap())
                    {
                        if (map->IsHeroic())
                            GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_BETTLE_TRIGGER, true);
                    }
                }

                void Register()
                {
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_anubesset_call_of_swarm_AuraScript::HandleSummons, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_anubesset_call_of_swarm_AuraScript();
        }
};

class at_blistering_ooze : public AreaTriggerEntityScript
{
    public:
        at_blistering_ooze() : AreaTriggerEntityScript("at_blistering_ooze")
        {}

        struct at_blistering_ooze_AI : public AreaTriggerAI
        {
            at_blistering_ooze_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;

                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_BLISTERING_OOZE_DMG, true);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_blistering_ooze_AI(at);
        }
};

void AddSC_boss_anubesset()
{
    new boss_anubesset();
    new npc_vha_spitting_scarab();
    new npc_vha_blistering_bettle();
    new npc_vha_impale_dummy();
    new spell_anubesset_impale();
    new spell_anubesset_call_of_swarm();
    new at_blistering_ooze();
}

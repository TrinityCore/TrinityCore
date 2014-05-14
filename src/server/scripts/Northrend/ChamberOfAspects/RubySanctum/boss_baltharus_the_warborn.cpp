/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_BALTHARUS_INTRO         = 0,    // Your power wanes, ancient one.... Soon you will join your friends.
    SAY_AGGRO                   = 1,    // Ah, the entertainment has arrived.
    SAY_KILL                    = 2,    // Baltharus leaves no survivors! - This world has enough heroes.
    SAY_CLONE                   = 3,    // Twice the pain and half the fun.
    SAY_DEATH                   = 4,    // I... didn't see that coming....
};

enum Spells
{
    SPELL_BARRIER_CHANNEL       = 76221,
    SPELL_ENERVATING_BRAND      = 74502,
    SPELL_SIPHONED_MIGHT        = 74507,
    SPELL_CLEAVE                = 40504,
    SPELL_BLADE_TEMPEST         = 75125,
    SPELL_CLONE                 = 74511,
    SPELL_REPELLING_WAVE        = 74509,
    SPELL_CLEAR_DEBUFFS         = 34098,
    SPELL_SPAWN_EFFECT          = 64195,
};

enum Events
{
    EVENT_BLADE_TEMPEST         = 1,
    EVENT_CLEAVE                = 2,
    EVENT_ENERVATING_BRAND      = 3,
    EVENT_INTRO_TALK            = 4,
    EVENT_OOC_CHANNEL           = 5,
};

enum Actions
{
    ACTION_CLONE                = 1,
};

enum Phases
{
    PHASE_ALL       = 0,
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2
};

class boss_baltharus_the_warborn : public CreatureScript
{
    public:
        boss_baltharus_the_warborn() : CreatureScript("boss_baltharus_the_warborn") { }

        struct boss_baltharus_the_warbornAI : public BossAI
        {
            boss_baltharus_the_warbornAI(Creature* creature) : BossAI(creature, DATA_BALTHARUS_THE_WARBORN)
            {
                _introDone = false;
            }

            void Reset() override
            {
                _Reset();
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_OOC_CHANNEL, 0, 0, PHASE_INTRO);
                _cloneCount = RAID_MODE<uint8>(1, 2, 2, 2);
                instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetMaxHealth());
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_INTRO_BALTHARUS:
                        if (_introDone)
                            return;
                        _introDone = true;
                        me->setActive(true);
                        events.ScheduleEvent(EVENT_INTRO_TALK, 7000, 0, PHASE_INTRO);
                        break;
                    case ACTION_CLONE:
                    {
                        DoCast(me, SPELL_CLEAR_DEBUFFS);
                        DoCast(me, SPELL_CLONE);
                        DoCast(me, SPELL_REPELLING_WAVE);
                        Talk(SAY_CLONE);
                        --_cloneCount;
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->InterruptNonMeleeSpells(false);
                _EnterCombat();
                events.Reset();
                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_CLEAVE, 11000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_ENERVATING_BRAND, 13000, 0, PHASE_COMBAT);
                events.ScheduleEvent(EVENT_BLADE_TEMPEST, 15000, 0, PHASE_COMBAT);
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (Creature* xerestrasza = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_XERESTRASZA)))
                    xerestrasza->AI()->DoAction(ACTION_BALTHARUS_DEATH);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                summon->SetHealth(me->GetHealth());
                summon->CastSpell(summon, SPELL_SPAWN_EFFECT, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                {
                    if (me->HealthBelowPctDamaged(50, damage) && _cloneCount == 1)
                        DoAction(ACTION_CLONE);
                }
                else
                {
                    if (me->HealthBelowPctDamaged(66, damage) && _cloneCount == 2)
                        DoAction(ACTION_CLONE);
                    else if (me->HealthBelowPctDamaged(33, damage) && _cloneCount == 1)
                        DoAction(ACTION_CLONE);
                }

                if (me->GetHealth() > damage)
                    instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetHealth() - damage);
            }

            void UpdateAI(uint32 diff) override
            {
                bool introPhase = events.IsInPhase(PHASE_INTRO);
                if (!UpdateVictim() && !introPhase)
                    return;

                if (!introPhase)
                    me->SetHealth(instance->GetData(DATA_BALTHARUS_SHARED_HEALTH));

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) && !introPhase)
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_TALK:
                            Talk(SAY_BALTHARUS_INTRO);
                            break;
                        case EVENT_OOC_CHANNEL:
                            if (Creature* channelTarget = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_CRYSTAL_CHANNEL_TARGET)))
                                DoCast(channelTarget, SPELL_BARRIER_CHANNEL);
                            events.ScheduleEvent(EVENT_OOC_CHANNEL, 7000, 0, PHASE_INTRO);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, 24000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCast(me, SPELL_BLADE_TEMPEST);
                            events.ScheduleEvent(EVENT_BLADE_TEMPEST, 24000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_ENERVATING_BRAND:
                            for (uint8 i = 0; i < RAID_MODE<uint8>(4, 8, 8, 10); i++)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                    DoCast(target, SPELL_ENERVATING_BRAND);
                            events.ScheduleEvent(EVENT_ENERVATING_BRAND, 26000, 0, PHASE_COMBAT);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _cloneCount;
            bool _introDone;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<boss_baltharus_the_warbornAI>(creature);
        }
};

class npc_baltharus_the_warborn_clone : public CreatureScript
{
    public:
        npc_baltharus_the_warborn_clone() : CreatureScript("npc_baltharus_the_warborn_clone") { }

        struct npc_baltharus_the_warborn_cloneAI : public ScriptedAI
        {
            npc_baltharus_the_warborn_cloneAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoZoneInCombat();
                _events.Reset();
                _events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 10000));
                _events.ScheduleEvent(EVENT_BLADE_TEMPEST, urand(18000, 25000));
                _events.ScheduleEvent(EVENT_ENERVATING_BRAND, urand(10000, 15000));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                // Setting DATA_BALTHARUS_SHARED_HEALTH to 0 when killed would bug the boss.
                if (_instance && me->GetHealth() > damage)
                    _instance->SetData(DATA_BALTHARUS_SHARED_HEALTH, me->GetHealth() - damage);
            }

            void JustDied(Unit* killer) override
            {
                // This is here because DamageTaken wont trigger if the damage is deadly.
                if (Creature* baltharus = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_BALTHARUS_THE_WARBORN)))
                    killer->Kill(baltharus);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                me->SetHealth(_instance->GetData(DATA_BALTHARUS_SHARED_HEALTH));

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.ScheduleEvent(EVENT_CLEAVE, 24000);
                            break;
                        case EVENT_BLADE_TEMPEST:
                            DoCastVictim(SPELL_BLADE_TEMPEST);
                            _events.ScheduleEvent(EVENT_BLADE_TEMPEST, 24000);
                           break;
                        case EVENT_ENERVATING_BRAND:
                            for (uint8 i = 0; i < RAID_MODE<uint8>(4, 8, 8, 10); i++)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                    DoCast(target, SPELL_ENERVATING_BRAND);
                            _events.ScheduleEvent(EVENT_ENERVATING_BRAND, 26000);
                            break;
                        default:
                            break;
                    }
               }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_baltharus_the_warborn_cloneAI>(creature);
        }
};

class spell_baltharus_enervating_brand_trigger : public SpellScriptLoader
{
    public:
        spell_baltharus_enervating_brand_trigger() : SpellScriptLoader("spell_baltharus_enervating_brand_trigger") { }

        class spell_baltharus_enervating_brand_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_baltharus_enervating_brand_trigger_SpellScript)

            void CheckDistance()
            {
                if (Unit* caster = GetOriginalCaster())
                {
                    if (Unit* target = GetHitUnit())
                        target->CastSpell(caster, SPELL_SIPHONED_MIGHT, true);
                }
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_baltharus_enervating_brand_trigger_SpellScript::CheckDistance);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_baltharus_enervating_brand_trigger_SpellScript();
        }
};

void AddSC_boss_baltharus_the_warborn()
{
    new boss_baltharus_the_warborn();
    new npc_baltharus_the_warborn_clone();
    new spell_baltharus_enervating_brand_trigger();
}

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

#include "shadowfang_keep.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_SLAY  = 2
};

enum Events
{
    // Baron Silverlaine
    EVENT_VEIL_OF_SHADOW = 1,
    EVENT_CURSED_VEIL,
    EVENT_SUMMON_WORGEN_SPIRIT,

    // Odo the Blindwatcher
    EVENT_HOWLING_RAGE,

    // Wolf Master Nandos
    EVENT_CLAW,

    // Razorclaw the Butcher
    EVENT_SPECTRAL_RUSH,
    EVENT_SPECTRAL_RAVAGING,
    EVENT_BUTCHER_DRAIN,

    // Rethilgore
    EVENT_SOUL_DRAIN
};

enum Actions
{
    ACTION_DESPAWN = 0
};

enum Spells
{
    SPELL_VEIL_OF_SHADOWS                           = 23224,
    SPELL_CURSED_VEIL                               = 93956,
    SPELL_SUMMON_WORGEN_SPIRIT                      = 93857,

    SPELL_SUMMON_WORGEN_SPIRIT_NANDOS_DUMMY         = 93896, // Dummy Summon
    SPELL_SUMMON_WORGEN_SPIRIT_NANDOS_SUMMON        = 93899,

    SPELL_SUMMON_WORGEN_SPIRIT_ODO_DUMMY            = 93859, // Dummy Summon
    SPELL_SUMMON_WORGEN_SPIRIT_ODO_SUMMON           = 93899,

    SPELL_SUMMON_WORGEN_SPIRIT_RAZORCLAW_DUMMY      = 93921, // Dummy Summon
    SPELL_SUMMON_WORGEN_SPIRIT_RAZORCLAW_SUMMON     = 93924,
    
    SPELL_SUMMON_WORGEN_SPIRIT_RETHILGORE_DUMMY     = 93925, // Dummy Summon
    SPELL_SUMMON_WORGEN_SPIRIT_RETHILGORE_SUMMON    = 93927,

    // Odo the Blindwatcher
    SPELL_HOWLING_RAGE                              = 93931,
    SPELL_BLINDING_SHADOWS                          = 93952,

    // Wolf Master Nandos
    SPELL_CLAW                                      = 16827,
    SPELL_SUMMON_LUPINE_SPECTRE                     = 94199,

    // Razorclaw the Butcher
    SPELL_SPECTRAL_RAVAGING                         = 93930,
    SPELL_SPECTRAL_RUSH                             = 93914,
    SPELL_BUTCHER_DRAIN                             = 7485,

    // Rethilgore
    SPELL_SOUL_DRAIN                                = 93863
};

class boss_baron_silverlaine : public CreatureScript
{
public:
    boss_baron_silverlaine() : CreatureScript("boss_baron_silverlaine") { }

    struct boss_baron_silverlaineAI : public BossAI
    {
        boss_baron_silverlaineAI(Creature* creature) : BossAI(creature, DATA_BARON_SILVERLAINE) { }

        void Reset() override
        {
            _Reset();
            _worgenCounter = 0;
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CURSED_VEIL, Seconds(6));
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnWorgenSpirits();
            _JustDied();
        }

        void KilledUnit(Unit* target) override
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            instance->SetBossState(DATA_BARON_SILVERLAINE, FAIL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnWorgenSpirits();
            _DespawnAtEvade();
        }

        void DespawnWorgenSpirits()
        {
            EntryCheckPredicate nandos(NPC_WOLF_MASTER_NANDOS);
            summons.DoAction(ACTION_DESPAWN, nandos);

            EntryCheckPredicate odo(NPC_ODO_THE_BLINDWATCHER);
            summons.DoAction(ACTION_DESPAWN, odo);

            EntryCheckPredicate razorclaw(NPC_RAZORCLAW_THE_BUTCHER);
            summons.DoAction(ACTION_DESPAWN, razorclaw);

            EntryCheckPredicate rethilgore(NPC_RETHILGORE);
            summons.DoAction(ACTION_DESPAWN, rethilgore);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            switch (summon->GetEntry())
            {
                case NPC_ODO_DUMMY:
                    summon->CastSpell(summon, SPELL_SUMMON_WORGEN_SPIRIT_ODO_SUMMON);
                    break;
                case NPC_NANDOS_DUMMY:
                    summon->CastSpell(summon, SPELL_SUMMON_WORGEN_SPIRIT_NANDOS_SUMMON);
                    break;
                case NPC_RAZORCLAW_DUMMY:
                    summon->CastSpell(summon, SPELL_SUMMON_WORGEN_SPIRIT_RAZORCLAW_SUMMON);
                    break;
                case NPC_RETHILGORE_DUMMY:
                    summon->CastSpell(summon, SPELL_SUMMON_WORGEN_SPIRIT_RETHILGORE_SUMMON);
                    break;
                default:
                    break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (IsHeroic())
            {
                if (me->HealthBelowPctDamaged(90, damage) && _worgenCounter == 0)
                {
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, (Milliseconds(1)));
                    _worgenCounter++;
                }
                else if (me->HealthBelowPctDamaged(60, damage) && _worgenCounter == 1)
                {
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, (Milliseconds(1)));
                    _worgenCounter++;
                }
                else if (me->HealthBelowPctDamaged(30, damage) && _worgenCounter == 2)
                {
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, (Milliseconds(1)));
                    _worgenCounter++;
                }
            }
            else
            {
                if (me->HealthBelowPctDamaged(75, damage) && _worgenCounter == 0)
                {
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, (Milliseconds(1)));
                    _worgenCounter++;
                }
                else if (me->HealthBelowPctDamaged(35, damage) && _worgenCounter == 1)
                {
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, (Milliseconds(1)));
                    _worgenCounter++;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CURSED_VEIL:
                        DoCastAOE(SPELL_CURSED_VEIL);
                        events.Repeat(Seconds(26) + Milliseconds(500));
                        break;
                    case EVENT_SUMMON_WORGEN_SPIRIT:
                        DoCastAOE(SPELL_SUMMON_WORGEN_SPIRIT);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        uint8 _worgenCounter;
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<boss_baron_silverlaineAI>(creature);
    }
};

class npc_wolf_master_nandos : public CreatureScript
{
public:
    npc_wolf_master_nandos() :  CreatureScript("npc_wolf_master_nandos") { }

    struct npc_wolf_master_nandosAI : public ScriptedAI
    {
        npc_wolf_master_nandosAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* silverlaine = _instance->GetCreature(DATA_BARON_SILVERLAINE))
                silverlaine->AI()->JustSummoned(me);

            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_CLAW, Seconds(1) + Milliseconds(600));
            for (uint8 i = 0; i < 3; i++)
                DoCast(me, SPELL_SUMMON_LUPINE_SPECTRE, true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Seconds(5));
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLAW:
                        DoCastVictim(SPELL_CLAW);
                        events.Repeat(Seconds(3));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* _instance;
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_wolf_master_nandosAI>(creature);
    }
};

class npc_odo_the_blindwatcher : public CreatureScript
{
public:
    npc_odo_the_blindwatcher() :  CreatureScript("npc_odo_the_blindwatcher") { }

    struct npc_odo_the_blindwatcherAI : public ScriptedAI
    {
        npc_odo_the_blindwatcherAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* silverlaine = _instance->GetCreature(DATA_BARON_SILVERLAINE))
                silverlaine->AI()->JustSummoned(me);

            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            DoZoneInCombat();
            _events.ScheduleEvent(EVENT_HOWLING_RAGE, Seconds(5) + Milliseconds(500));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Seconds(5));
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HOWLING_RAGE:
                        DoCastVictim(SPELL_BLINDING_SHADOWS);
                        DoCastAOE(SPELL_HOWLING_RAGE);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* _instance;
        EventMap _events;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_odo_the_blindwatcherAI>(creature);
    }
};

class npc_razorclaw_the_butcher : public CreatureScript
{
public:
    npc_razorclaw_the_butcher() :  CreatureScript("npc_razorclaw_the_butcher") { }

    struct npc_razorclaw_the_butcherAI : public ScriptedAI
    {
        npc_razorclaw_the_butcherAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            _player = ObjectGuid::Empty;
            if (Creature* silverlaine = _instance->GetCreature(DATA_BARON_SILVERLAINE))
                silverlaine->AI()->JustSummoned(me);

            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            DoZoneInCombat();
            _events.ScheduleEvent(EVENT_SPECTRAL_RUSH, Seconds(16));
            _events.ScheduleEvent(EVENT_BUTCHER_DRAIN, Seconds(2) + Milliseconds(500));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Seconds(5));
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPECTRAL_RUSH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 50.0f, true))
                        {
                            _events.ScheduleEvent(EVENT_SPECTRAL_RAVAGING, Milliseconds(500));
                            DoCast(target, SPELL_SPECTRAL_RUSH);
                            _player = target->GetGUID();
                        }
                        break;
                    case EVENT_SPECTRAL_RAVAGING:
                        if (Unit* target = ObjectAccessor::GetPlayer(*me, _player))
                            DoCast(target, SPELL_SPECTRAL_RAVAGING);
                        break;
                    case EVENT_BUTCHER_DRAIN:
                        DoCastVictim(SPELL_BUTCHER_DRAIN);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* _instance;
        EventMap _events;
        ObjectGuid _player;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_razorclaw_the_butcherAI>(creature);
    }
};

class npc_rethilgore : public CreatureScript
{
public:
    npc_rethilgore() : CreatureScript("npc_rethilgore") { }

    struct npc_rethilgoreAI : public ScriptedAI
    {
        npc_rethilgoreAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* silverlaine = _instance->GetCreature(DATA_BARON_SILVERLAINE))
                silverlaine->AI()->JustSummoned(me);

            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            DoZoneInCombat();
            _events.ScheduleEvent(EVENT_SOUL_DRAIN, Seconds(10));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Seconds(5));
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon(Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOUL_DRAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_SOUL_DRAIN);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetShadowfangKeepAI<npc_rethilgoreAI>(creature);
    }
};

class spell_sfk_summon_worgen_spirit : public SpellScriptLoader
{
public:
    spell_sfk_summon_worgen_spirit() : SpellScriptLoader("spell_sfk_summon_worgen_spirit") { }

    class spell_sfk_summon_worgen_spirit_SpellScript : public SpellScript
    {
             bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_SUMMON_WORGEN_SPIRIT_NANDOS_DUMMY,
                SPELL_SUMMON_WORGEN_SPIRIT_ODO_DUMMY,
                SPELL_SUMMON_WORGEN_SPIRIT_RAZORCLAW_DUMMY,
                SPELL_SUMMON_WORGEN_SPIRIT_RETHILGORE_DUMMY
            });
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                switch (RAND(0, 3))
                {
                    case 0: // Nandos
                        caster->CastSpell((Unit*)NULL, SPELL_SUMMON_WORGEN_SPIRIT_NANDOS_DUMMY, true);
                        break;
                    case 1: // Odo
                        caster->CastSpell((Unit*)NULL, SPELL_SUMMON_WORGEN_SPIRIT_ODO_DUMMY, true);
                        break;
                    case 2: // Razorclaw
                        caster->CastSpell((Unit*)NULL, SPELL_SUMMON_WORGEN_SPIRIT_RAZORCLAW_DUMMY, true);
                        break;
                    case 3: // Rethilgore
                        caster->CastSpell((Unit*)NULL, SPELL_SUMMON_WORGEN_SPIRIT_RETHILGORE_DUMMY, true);
                        break;
                }
            }
        }

        void Register() override
        {
            OnEffectLaunch.Register(&spell_sfk_summon_worgen_spirit_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_summon_worgen_spirit_SpellScript();
    }
};

void AddSC_boss_baron_silverlaine()
{
    new boss_baron_silverlaine();
    new npc_wolf_master_nandos();
    new npc_odo_the_blindwatcher();
    new npc_razorclaw_the_butcher();
    new npc_rethilgore();
    new spell_sfk_summon_worgen_spirit();
}

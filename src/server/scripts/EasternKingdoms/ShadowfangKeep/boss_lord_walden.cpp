/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

enum Texts
{
    SAY_AGGRO   = 0,
    SAY_SLAY    = 1,
    SAY_DEATH   = 2
};

enum Spells
{
    // Lord Walden
    SPELL_ICE_SHARDS                        = 93527,
    SPELL_CONJURE_FROST_MIXTURE             = 93505,
    SPELL_CONJURE_POISONOUS_MIXTURE         = 93697,
    SPELL_CONJURE_MYSTERY_MIXTURE           = 93695,
    SPELL_CONJURE_MYSTERY_MIXTURE_CHANNEL   = 93562,
    SPELL_FULLY_COAGULATED                  = 93660,

    // Mystery Toxine
    SPELL_TOXIC_COAGULANT                   = 93572,
    SPELL_TOXIC_COAGULANT_SLOW              = 93617,
    SPELL_TOXIC_CATALYST                    = 93573,
    SPELL_TOXIC_CATALYST_AURA               = 93689

};

enum Events
{
    EVENT_ICE_SHARDS = 1,
    EVENT_CONJURE_FROST_MIXTURE,
    EVENT_CONJURE_POISONOUS_MIXTURE,
    EVENT_CONJURE_MYSTERY_TOXINE,
    EVENT_ADD_CATALYST
};

class boss_lord_walden : public CreatureScript
{
public:
    boss_lord_walden() : CreatureScript("boss_lord_walden") { }

    struct boss_lord_waldenAI : public BossAI
    {
        boss_lord_waldenAI(Creature* creature) : BossAI(creature, DATA_LORD_WALDEN) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_ICE_SHARDS, Seconds(23));
            events.ScheduleEvent(EVENT_CONJURE_FROST_MIXTURE, Seconds(8));
            events.ScheduleEvent(EVENT_CONJURE_POISONOUS_MIXTURE, Seconds(21));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CONJURE_MYSTERY_TOXINE, Seconds(10) + Milliseconds(500));

        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
            instance->SetBossState(DATA_LORD_WALDEN, FAIL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _DespawnAtEvade();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            switch (summon->GetEntry())
            {
                case NPC_MYSTERY_MIXTURE:
                    if (!me->HealthBelowPct(35))
                        summon->CastSpell((Unit*)NULL, SPELL_TOXIC_COAGULANT, true);
                    else
                    {
                        summon->CastSpell((Unit*)NULL, SPELL_TOXIC_CATALYST, true);
                        events.ScheduleEvent(EVENT_ADD_CATALYST, Seconds(2));
                    }
                    // Since summon above caster is not implemented yet
                    summon->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 4.5f, me->GetOrientation());
                    break;
                default:
                    break;
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
                    case EVENT_ICE_SHARDS:
                        me->StopMoving();
                        DoCastAOE(SPELL_ICE_SHARDS);
                        events.Repeat(Seconds(21) + Milliseconds(500));
                        break;
                    case EVENT_CONJURE_FROST_MIXTURE:
                        me->StopMoving();
                        DoCastAOE(SPELL_CONJURE_FROST_MIXTURE);
                        events.Repeat(Seconds(21) + Milliseconds(500));
                        break;
                    case EVENT_CONJURE_POISONOUS_MIXTURE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_CONJURE_POISONOUS_MIXTURE);
                        events.Repeat(Seconds(21) + Milliseconds(500));
                        break;
                    case EVENT_CONJURE_MYSTERY_TOXINE:
                        DoCast(SPELL_CONJURE_MYSTERY_MIXTURE);
                        DoCast(SPELL_CONJURE_MYSTERY_MIXTURE_CHANNEL);
                        events.Repeat(Seconds(21) + Milliseconds(500));
                        break;
                    case EVENT_ADD_CATALYST:
                        if (Unit* mixture = me->FindNearestCreature(NPC_MYSTERY_MIXTURE, 20.0f, true))
                            mixture->CastSpell(mixture, SPELL_TOXIC_CATALYST_AURA, false);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetShadowfangKeepAI<boss_lord_waldenAI>(creature);
    }
};

class spell_sfk_toxic_coagulant : public SpellScriptLoader
{
public:
    spell_sfk_toxic_coagulant() : SpellScriptLoader("spell_sfk_toxic_coagulant") { }

    class spell_sfk_toxic_coagulant_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sfk_toxic_coagulant_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_FULLY_COAGULATED,
                SPELL_TOXIC_COAGULANT_SLOW
            });
        }

        void HandleStacks()
        {
            if (Unit* target = GetHitUnit())
            {
                Aura* aura = nullptr;
                aura = target->GetAura(SPELL_TOXIC_COAGULANT_SLOW);

                if (aura)
                {
                    if (aura->GetStackAmount() == 3)
                    {
                        target->RemoveAurasDueToSpell(SPELL_TOXIC_COAGULANT_SLOW);
                        target->CastSpell(target, SPELL_FULLY_COAGULATED, true);
                    }
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_sfk_toxic_coagulant_SpellScript::HandleStacks);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_toxic_coagulant_SpellScript();
    }
};

class spell_sfk_conjure_poisonous_mixture : public SpellScriptLoader
{
public:
    spell_sfk_conjure_poisonous_mixture() : SpellScriptLoader("spell_sfk_conjure_poisonous_mixture") { }

    class spell_sfk_conjure_poisonous_mixture_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sfk_conjure_poisonous_mixture_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sfk_conjure_poisonous_mixture_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_conjure_poisonous_mixture_SpellScript();
    }
};

void AddSC_boss_lord_walden()
{
    new boss_lord_walden();
    new spell_sfk_toxic_coagulant();
    new spell_sfk_conjure_poisonous_mixture();
}

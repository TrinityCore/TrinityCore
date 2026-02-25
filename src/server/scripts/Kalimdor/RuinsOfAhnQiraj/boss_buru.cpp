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
#include "InstanceScript.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum BuruTexts
{
    EMOTE_TARGET                    = 0
};

enum BuruSpells
{
    // Phase 1
    SPELL_DISMEMBER                 = 96,
    SPELL_GATHERING_SPEED           = 1834,
    SPELL_FULL_SPEED                = 1557,

    // Phase 2
    SPELL_CREEPING_PLAGUE           = 20512,

    // Misc
    SPELL_THORNS                    = 25640,
    SPELL_CREATURE_SPECIAL          = 7155,
    SPELL_BURU_TRANSFORM            = 24721,
    SPELL_CANCEL_CREEPING_PLAGUE    = 27027,

    // Buru Egg
    SPELL_EGG_EXPLOSION             = 19593,
    SPELL_SUMMON_HATCHLING          = 1881,

    // Scripts
    SPELL_EXPLOSION                 = 5255
};

enum BuruEvents
{
    EVENT_DISMEMBER                 = 1,
    EVENT_GATHERING_SPEED,
    EVENT_FULL_SPEED,
    EVENT_CREEPING_PLAGUE,

    EVENT_TRANSFORM_1,
    EVENT_TRANSFORM_2,
    EVENT_TRANSFORM_3
};

enum BuruPhases
{
    PHASE_EGG                       = 0,
    PHASE_TRANSFORM                 = 1
};

// 15370 - Buru the Gorger
struct boss_buru : public BossAI
{
    boss_buru(Creature* creature) : BossAI(creature, DATA_BURU), _phase(PHASE_EGG) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_EGG;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_THORNS);

        ChaseNewVictim();

        events.ScheduleEvent(EVENT_DISMEMBER, 10s, 15s);
        events.ScheduleEvent(EVENT_GATHERING_SPEED, 2s);
        events.ScheduleEvent(EVENT_FULL_SPEED, 1min);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_EXPLOSION:
                me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
                me->RemoveAurasDueToSpell(SPELL_FULL_SPEED);
                DoCastSelf(SPELL_CREATURE_SPECIAL);
                break;
            case SPELL_CREATURE_SPECIAL:
                ChaseNewVictim();
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase == PHASE_EGG && me->HealthBelowPctDamaged(20, damage))
        {
            _phase = PHASE_TRANSFORM;
            events.ScheduleEvent(EVENT_TRANSFORM_1, 0s);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        // Triggers even if victim is a creature. Victim can be a creature if it reaches first position in threat list
        ChaseNewVictim();
    }

    void ChaseNewVictim()
    {
        if (_phase != PHASE_EGG)
            return;

        events.RescheduleEvent(EVENT_GATHERING_SPEED, 9s);
        events.RescheduleEvent(EVENT_FULL_SPEED, 1min);

        ResetThreatList();

        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
        {
            AddThreat(target, 1000000.0f);
            AttackStart(target);
            Talk(EMOTE_TARGET, target);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastSelf(SPELL_CANCEL_CREEPING_PLAGUE);
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
                // Phase 1
                case EVENT_DISMEMBER:
                    DoCastVictim(SPELL_DISMEMBER);
                    events.Repeat(6s, 8s);
                    break;
                case EVENT_GATHERING_SPEED:
                    DoCastSelf(SPELL_GATHERING_SPEED);
                    events.Repeat(9s);
                    break;
                case EVENT_FULL_SPEED:
                    DoCastSelf(SPELL_FULL_SPEED);
                    break;

                // Phase 2
                case EVENT_CREEPING_PLAGUE:
                    DoCastSelf(SPELL_CREEPING_PLAGUE);
                    events.Repeat(6s);
                    break;

                // Transform
                case EVENT_TRANSFORM_1:
                    me->ResetPlayerDamageReq();
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_DISMEMBER);
                    events.CancelEvent(EVENT_GATHERING_SPEED);
                    events.CancelEvent(EVENT_FULL_SPEED);
                    ResetThreatList();
                    events.ScheduleEvent(EVENT_TRANSFORM_2, 3s + 500ms);
                    break;
                case EVENT_TRANSFORM_2:
                    me->RemoveAurasDueToSpell(SPELL_THORNS);
                    DoCastSelf(SPELL_BURU_TRANSFORM);
                    events.ScheduleEvent(EVENT_TRANSFORM_3, 6s);
                    break;
                case EVENT_TRANSFORM_3:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_FULL_SPEED);
                    events.ScheduleEvent(EVENT_CREEPING_PLAGUE, 2s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
};

// 15514 - Buru Egg
struct npc_buru_egg : public ScriptedAI
{
    npc_buru_egg(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(4, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (Creature* buru = _instance->GetCreature(DATA_BURU))
            if (!buru->IsInCombat())
                buru->AI()->AttackStart(who);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BURU_TRANSFORM)
        {
            DoCastSelf(SPELL_SUMMON_HATCHLING);
            me->DespawnOrUnsummon();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_EGG_EXPLOSION);
        DoCastSelf(SPELL_SUMMON_HATCHLING, true);
    }

private:
    InstanceScript* _instance;
};

// 19593 - Egg Explosion
class spell_buru_egg_explosion : public SpellScript
{
    PrepareSpellScript(spell_buru_egg_explosion);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXPLOSION });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        int32 damage = 0;

        if (target->IsPet() || target->IsPlayer())
            // Damage from 100 - 500 based on proximity - max range 25. Pets are valid targets here
            damage = 100 + ((25 - std::min(caster->GetExactDist2d(target), 25.f)) / 25.f) * 400;

        // Buru has different formula
        else if (target->GetEntry() == NPC_BURU)
            if (target->GetHealthPct() > 20.0f)
                /// @todo: This requires additional research as it doesn't seem right, doesn't it depend on proximity?
                damage = target->GetMaxHealth() * 15 / 100;

        CastSpellExtraArgs args;
        args.AddSpellBP0(damage);
        caster->CastSpell(target, SPELL_EXPLOSION, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_buru_egg_explosion::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 27027 - Cancel Creeping Plague
class spell_buru_cancel_creeping_plague : public SpellScript
{
    PrepareSpellScript(spell_buru_cancel_creeping_plague);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CREEPING_PLAGUE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_CREEPING_PLAGUE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_buru_cancel_creeping_plague::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_buru()
{
    RegisterAQ20CreatureAI(boss_buru);
    RegisterAQ20CreatureAI(npc_buru_egg);
    RegisterSpellScript(spell_buru_egg_explosion);
    RegisterSpellScript(spell_buru_cancel_creeping_plague);
}

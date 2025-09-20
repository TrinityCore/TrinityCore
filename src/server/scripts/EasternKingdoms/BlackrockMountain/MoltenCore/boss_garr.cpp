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
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum GarrTexts
{
    EMOTE_MASSIVE_ERUPTION             = 0
};

enum GarrSpells
{
    // Garr
    SPELL_ANTIMAGIC_PULSE              = 19492,
    SPELL_MAGMA_SHACKLES               = 19496,
    SPELL_ERUPTION_TRIGGER             = 20482,

    SPELL_FRENZY                       = 19516,
    SPELL_SEPARATION_ANXIETY           = 23487,

    // Firesworn
    SPELL_THRASH                       = 8876,
    SPELL_IMMOLATE                     = 15733,

    SPELL_ERUPTION                     = 19497,
    SPELL_FRENZY_TRIGGER               = 19515,
    SPELL_MASSIVE_ERUPTION             = 20483,

    // Scripts
    SPELL_SEPARATION_ANXIETY_EFFECT    = 23492
};

enum GarrEvents
{
    EVENT_ANTIMAGIC_PULSE              = 1,
    EVENT_MAGMA_SHACKLES,
    EVENT_MASSIVE_ERUPTION
};

// 12057 - Garr
struct boss_garr : public BossAI
{
    boss_garr(Creature* creature) : BossAI(creature, BOSS_GARR) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_SEPARATION_ANXIETY);

        events.ScheduleEvent(EVENT_ANTIMAGIC_PULSE, 10s, 15s);
        events.ScheduleEvent(EVENT_MAGMA_SHACKLES, 5s, 10s);
        events.ScheduleEvent(EVENT_MASSIVE_ERUPTION, 6min);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ERUPTION_TRIGGER)
            Talk(EMOTE_MASSIVE_ERUPTION);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FRENZY_TRIGGER)
            DoCastSelf(SPELL_FRENZY);
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
                case EVENT_ANTIMAGIC_PULSE:
                    DoCastSelf(SPELL_ANTIMAGIC_PULSE);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_MAGMA_SHACKLES:
                    DoCastSelf(SPELL_MAGMA_SHACKLES);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_MASSIVE_ERUPTION:
                    DoCastSelf(SPELL_ERUPTION_TRIGGER);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 12099 - Firesworn
struct npc_firesworn : public ScriptedAI
{
    npc_firesworn(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        DoCastSelf(SPELL_THRASH);
        DoCastSelf(SPELL_IMMOLATE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ERUPTION_TRIGGER)
            DoCastSelf(SPELL_MASSIVE_ERUPTION);
    }

    void JustDied(Unit* killer) override
    {
        if (killer != me)
            DoCastSelf(SPELL_ERUPTION, true);

        DoCastSelf(SPELL_FRENZY_TRIGGER, true);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// 23487 - Separation Anxiety
class spell_garr_separation_anxiety : public AuraScript
{
    PrepareAuraScript(spell_garr_separation_anxiety);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEPARATION_ANXIETY_EFFECT });
    }

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 5 * IN_MILLISECONDS;
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (Unit* caster = GetCaster())
            if (caster->IsAlive() && !caster->IsWithinDistInMap(target, aurEff->GetSpellEffectInfo().CalcRadius()))
                target->CastSpell(target, SPELL_SEPARATION_ANXIETY_EFFECT, true);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_garr_separation_anxiety::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_garr_separation_anxiety::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_boss_garr()
{
    RegisterMoltenCoreCreatureAI(boss_garr);
    RegisterMoltenCoreCreatureAI(npc_firesworn);
    RegisterSpellScript(spell_garr_separation_anxiety);
}

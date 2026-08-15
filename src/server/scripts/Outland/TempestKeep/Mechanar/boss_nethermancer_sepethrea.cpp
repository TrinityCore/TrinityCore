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

/*
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "mechanar.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum SepethreaTexts
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DRAGONS_BREATH             = 2,
    SAY_SUMMON                     = 3,     // Was never used or used under unknown conditions
    SAY_DEATH                      = 4
};

enum SepethreaSpells
{
    // Sepethrea - Initial
    SPELL_FROST_ATTACK             = 45196, // This is definitely spell added in TBC but did it replaced both 35264 and 39086 or only normal version?
    SPELL_SUMMON_RAGING_FLAMES     = 35275,

    // Sepethrea - Combat
    SPELL_ARCANE_BLAST             = 35314,
    SPELL_DRAGONS_BREATH           = 35250,

    // Sepethrea - Combat - Misc
    SPELL_QUELL_RAGING_FLAMES      = 35277,

    // Raging Flames
    SPELL_RAGING_FLAMES_AREA_AURA  = 35281,
    SPELL_INVIS_STEALTH_DETECTION  = 18950,
    SPELL_INFERNO                  = 35268,

    // Scripts
    SPELL_INFERNO_DAMAGE           = 35283
};

enum SepethreaEvents
{
    EVENT_ARCANE_BLAST             = 1,
    EVENT_DRAGONS_BREATH
};

// 19221 - Nethermancer Sepethrea
struct boss_nethermancer_sepethrea : public BossAI
{
    boss_nethermancer_sepethrea(Creature* creature) : BossAI(creature, DATA_NETHERMANCER_SEPRETHREA) { }

    void Reset() override
    {
        _Reset();
        DoCastSelf(SPELL_FROST_ATTACK);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_SUMMON_RAGING_FLAMES);

        events.ScheduleEvent(EVENT_ARCANE_BLAST, 15s, 25s);
        events.ScheduleEvent(EVENT_DRAGONS_BREATH, 20s, 30s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DRAGONS_BREATH)
            if (roll_chance_i(50))
                Talk(SAY_DRAGONS_BREATH);
    }

    // Despawn is handled by spell, don't store anything
    void JustSummoned(Creature* /*summon*/) override { }

    void EnterEvadeMode(EvadeReason why) override
    {
        // Fails probably because target is in evade mode (yes, she kills them on evade too). We'll kill them directly in their script for now
        DoCastSelf(SPELL_QUELL_RAGING_FLAMES);
        BossAI::EnterEvadeMode(why);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_FROST_ATTACK);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCastSelf(SPELL_QUELL_RAGING_FLAMES);
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
                case EVENT_ARCANE_BLAST:
                    DoCastVictim(SPELL_ARCANE_BLAST);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_DRAGONS_BREATH:
                    DoCastSelf(SPELL_DRAGONS_BREATH);
                    events.Repeat(25s, 35s);
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

// 20481 - Raging Flames
struct npc_raging_flames : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetCorpseDelay(20, true);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        DoCastSelf(SPELL_RAGING_FLAMES_AREA_AURA);
        DoCastSelf(SPELL_INVIS_STEALTH_DETECTION);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .Schedule(15s, 25s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_INFERNO);
                task.Repeat(20s, 30s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                ResetThreatList();

                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                    AddThreat(target, 1000000.0f);
                task.Repeat(10s, 20s);
            });
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->KillSelf();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 35314 - Arcane Blast
class spell_nethermancer_sepethrea_arcane_blast : public SpellScript
{
    PrepareSpellScript(spell_nethermancer_sepethrea_arcane_blast);

    void HandleAfterHit()
    {
        if (GetCaster()->CanHaveThreatList())
            GetCaster()->GetThreatManager().ModifyThreatByPercent(GetHitUnit(), -50);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_nethermancer_sepethrea_arcane_blast::HandleAfterHit);
    }
};

// 35268, 39346 - Inferno
class spell_nethermancer_sepethrea_inferno : public AuraScript
{
    PrepareAuraScript(spell_nethermancer_sepethrea_inferno);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(nullptr, SPELL_INFERNO_DAMAGE, CastSpellExtraArgs()
            .AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_nethermancer_sepethrea_inferno::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_nethermancer_sepethrea()
{
    RegisterMechanarCreatureAI(boss_nethermancer_sepethrea);
    RegisterMechanarCreatureAI(npc_raging_flames);
    RegisterSpellScript(spell_nethermancer_sepethrea_arcane_blast);
    RegisterSpellScript(spell_nethermancer_sepethrea_inferno);
}

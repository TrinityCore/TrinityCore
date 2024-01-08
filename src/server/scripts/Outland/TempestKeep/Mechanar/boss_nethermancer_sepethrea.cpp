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
#include "mechanar.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Texts
{
    SAY_AGGRO                      = 0,
    SAY_SUMMON                     = 1,     // Was never used or used under unknown conditions
    SAY_DRAGONS_BREATH             = 2,
    SAY_SLAY                       = 3,
    SAY_DEATH                      = 4
};

enum Spells
{
    SPELL_FROST_ATTACK             = 45196, // This is definitely spell added in TBC but did it replaced both 35264 and 39086 or only normal version?
    SPELL_SUMMON_RAGING_FLAMES     = 35275,
    SPELL_QUELL_RAGING_FLAMES      = 35277,
    SPELL_ARCANE_BLAST             = 35314,
    SPELL_DRAGONS_BREATH           = 35250,

    // Raging Flames
    SPELL_RAGING_FLAMES_DUMMY      = 35274, // NYI, no clue what it can do
    SPELL_RAGING_FLAMES_AREA_AURA  = 35281,
    SPELL_INVIS_STEALTH_DETECTION  = 18950,
    SPELL_INFERNO                  = 35268,
    SPELL_INFERNO_DAMAGE           = 35283
};

enum Events
{
    EVENT_ARCANE_BLAST             = 1,
    EVENT_DRAGONS_BREATH
};

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
        events.ScheduleEvent(EVENT_ARCANE_BLAST, 15s, 25s);
        events.ScheduleEvent(EVENT_DRAGONS_BREATH, 20s, 30s);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_SUMMON_RAGING_FLAMES);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        // Fails probably because target is in evade mode (yes, she kills them on evade too). We'll kill them directly in their script for now
        DoCastSelf(SPELL_QUELL_RAGING_FLAMES, true);
        ScriptedAI::EnterEvadeMode(why);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_FROST_ATTACK);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCastSelf(SPELL_QUELL_RAGING_FLAMES, true);
    }

    // Despawn is handled by spell, don't store anything
    void JustSummoned(Creature* /*summon*/) override { }

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
                    if (GetThreat(me->GetVictim()))
                        ModifyThreatByPercent(me->GetVictim(), -50);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_DRAGONS_BREATH:
                    DoCastSelf(SPELL_DRAGONS_BREATH);
                    events.Repeat(25s, 35s);
                    if (roll_chance_i(50))
                        Talk(SAY_DRAGONS_BREATH);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

struct npc_raging_flames : public ScriptedAI
{
    npc_raging_flames(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(20, true);
    }

    // It's more tricky actually
    void FixateRandomTarget()
    {
        ResetThreatList();

        if (TempSummon* summon = me->ToTempSummon())
            if (Creature* summoner = summon->GetSummonerCreatureBase())
                if (summoner->IsAIEnabled())
                    if (Unit* target = summoner->AI()->SelectTarget(SelectTargetMethod::Random, 1, 100.0f, true, false))
                        AddThreat(target, 1000000.0f);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_RAGING_FLAMES_AREA_AURA);
        DoCastSelf(SPELL_INVIS_STEALTH_DETECTION);

        FixateRandomTarget();

        _scheduler.Schedule(15s, 25s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_INFERNO);
            FixateRandomTarget();

            task.Repeat(20s, 30s);
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
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
    }

private:
    TaskScheduler _scheduler;
};

// 35268, 39346 - Inferno
class spell_nethermancer_sepethrea_inferno : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(aurEff->GetAmount());
        GetTarget()->CastSpell(GetTarget(), SPELL_INFERNO_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_nethermancer_sepethrea_inferno::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_nethermancer_sepethrea()
{
    RegisterMechanarCreatureAI(boss_nethermancer_sepethrea);
    RegisterMechanarCreatureAI(npc_raging_flames);
    RegisterSpellScript(spell_nethermancer_sepethrea_inferno);
}

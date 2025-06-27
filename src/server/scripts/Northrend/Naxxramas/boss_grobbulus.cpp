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
 * He should call all stitched giants after aggro
 */

#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum GrobbulusTexts
{
    EMOTE_SLIME                 = 0,
    EMOTE_MUTAGEN               = 1
};

enum GrobbulusSpells
{
    // Grobbulus
    SPELL_BOMBARD_SLIME         = 28280,   // should be used out of combat (waypoint script?)
    SPELL_SLIME_SPRAY           = 28157,
    SPELL_SUMMON_FALLOUT_SLIME  = 28218,
    SPELL_MUTATING_INJECTION    = 28169,
    SPELL_MUTATING_EXPLOSION    = 28206,
    SPELL_POISON_CLOUD          = 28240,
    SPELL_BERSERK               = 26662,
    // Grobbulus Cloud
    SPELL_POISON_CLOUD_PASSIVE  = 28158,
    SPELL_PACIFY_SELF           = 19951,
    // Fallout Slime
    SPELL_DISEASE_CLOUD         = 54367
};

enum GrobbulusEvents
{
    EVENT_BERSERK               = 1,
    EVENT_CLOUD,
    EVENT_INJECT,
    EVENT_SPRAY
};

struct boss_grobbulus : public BossAI
{
    boss_grobbulus(Creature* creature) : BossAI(creature, BOSS_GROBBULUS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CLOUD, 5s, 10s);
        events.ScheduleEvent(EVENT_INJECT, 12s, 15s);
        events.ScheduleEvent(EVENT_SPRAY, RAND(25700ms, 27700ms, 30000ms));
        events.ScheduleEvent(EVENT_BERSERK, 12min);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_SLIME_SPRAY, me))
            target->CastSpell(target, SPELL_SUMMON_FALLOUT_SLIME, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLOUD:
                    DoCastSelf(SPELL_POISON_CLOUD);
                    events.Repeat(RAND(15600ms, 16800ms));
                    return;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    return;
                case EVENT_SPRAY:
                    DoCastAOE(SPELL_SLIME_SPRAY);
                    Talk(EMOTE_SLIME);
                    // timers must always looks like ~30 (initial) ~30 (first repeat) 55 (second repeat) ~30 55
                    // ~30 55 ~30 55 ~30 55. So after second cast timers are always flipped
                    events.Repeat(RAND(32500ms, 33700ms));
                    return;
                case EVENT_INJECT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true, true, -SPELL_MUTATING_INJECTION))
                    {
                        DoCast(target, SPELL_MUTATING_INJECTION);
                        Talk(EMOTE_MUTAGEN, target);
                    }
                    // The timers indeed depends on health but most likely they are just changed at health ptc
                    // Default timers are 10800ms, 12000ms, then changed to ~8000ms, 10000ms
                    events.Repeat(Seconds(8) + Milliseconds(uint32(std::round(120 * me->GetHealthPct()))));
                    return;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_grobbulus_poison_cloud : public NullCreatureAI
{
    npc_grobbulus_poison_cloud(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_POISON_CLOUD_PASSIVE);
        DoCastSelf(SPELL_PACIFY_SELF);
        me->DespawnOrUnsummon(61s);
    }
};

struct npc_fallout_slime : public ScriptedAI
{
    npc_fallout_slime(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(2, true);
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_DISEASE_CLOUD);

        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);

            if (Unit* summoner = ObjectAccessor::GetUnit(*me, _summonerGUID))
                // maybe only if threat list was empty?
                AddThreat(summoner, 100000.0f);
        });
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        _summonerGUID = summoner->GetGUID();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        // They don't despawn when Grobbulus dies. Calling despawn here is not entirely correct because originally
        // they just stuck after leaving combat(literally, they don't move), then they despawns after few seconds
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _summonerGUID;
};

// 28169 - Mutating Injection
class spell_grobbulus_mutating_injection : public AuraScript
{
    PrepareAuraScript(spell_grobbulus_mutating_injection);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MUTATING_EXPLOSION, SPELL_POISON_CLOUD });
    }

    void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
        if (removeMode != AURA_REMOVE_BY_ENEMY_SPELL && removeMode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetTarget(), SPELL_MUTATING_EXPLOSION, true);
            GetTarget()->CastSpell(GetTarget(), SPELL_POISON_CLOUD, { aurEff, GetCasterGUID() });
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_grobbulus_mutating_injection::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 28158, 54362 - Poison
class spell_grobbulus_poison_cloud : public AuraScript
{
    PrepareAuraScript(spell_grobbulus_poison_cloud);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (!aurEff->GetTotalTicks())
            return;

        uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell;
        int32 mod = int32(((float(aurEff->GetTickNumber()) / aurEff->GetTotalTicks()) * 0.9f + 0.1f) * 10000 * 2 / 3);

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_RADIUS_MOD, mod);
        GetTarget()->CastSpell(nullptr, triggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_grobbulus_poison_cloud::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_grobbulus()
{
    RegisterNaxxramasCreatureAI(boss_grobbulus);
    RegisterNaxxramasCreatureAI(npc_grobbulus_poison_cloud);
    RegisterNaxxramasCreatureAI(npc_fallout_slime);
    RegisterSpellScript(spell_grobbulus_mutating_injection);
    RegisterSpellScript(spell_grobbulus_poison_cloud);
}

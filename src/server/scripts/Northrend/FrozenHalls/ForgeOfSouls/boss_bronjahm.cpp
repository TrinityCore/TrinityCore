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
#include "forge_of_souls.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Yells
{
    SAY_AGGRO           = 0,
    SAY_SLAY            = 1,
    SAY_DEATH           = 2,
    SAY_SOUL_STORM      = 3,
    SAY_CORRUPT_SOUL    = 4
};

enum Spells
{
    SPELL_MAGIC_S_BANE          = 68793,
    SPELL_SHADOW_BOLT           = 70043,
    SPELL_CORRUPT_SOUL          = 68839,
    SPELL_CONSUME_SOUL          = 68861,
    SPELL_TELEPORT              = 68988,
    SPELL_FEAR                  = 68950,
    SPELL_SOULSTORM             = 68872,
    SPELL_SOULSTORM_CHANNEL     = 69008, // Pre-fight
    SPELL_SOULSTORM_VISUAL      = 68870, // Pre-cast Soulstorm
    SPELL_PURPLE_BANISH_VISUAL  = 68862  // Used by Soul Fragment (Aura)
};

enum Events
{
    EVENT_MAGIC_BANE    = 1,
    EVENT_SHADOW_BOLT   = 2,
    EVENT_CORRUPT_SOUL  = 3,
    EVENT_SOULSTORM     = 4,
    EVENT_FEAR          = 5
};

enum CombatPhases
{
    PHASE_1 = 1,
    PHASE_2 = 2
};

enum Misc
{
    DATA_SOUL_POWER = 1
};

struct boss_bronjahm : public BossAI
{
    boss_bronjahm(Creature* creature) : BossAI(creature, DATA_BRONJAHM)
    {
        DoCast(me, SPELL_SOULSTORM_CHANNEL, true);
    }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2s);
        events.ScheduleEvent(EVENT_MAGIC_BANE, 8s, 20s);
        events.ScheduleEvent(EVENT_CORRUPT_SOUL, 25s, 35s, 0, PHASE_1);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCast(me, SPELL_SOULSTORM_CHANNEL, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        me->RemoveAurasDueToSpell(SPELL_SOULSTORM_CHANNEL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (events.IsInPhase(PHASE_1) && !HealthAbovePct(30))
        {
            events.SetPhase(PHASE_2);
            DoCast(me, SPELL_TELEPORT);
            events.ScheduleEvent(EVENT_FEAR, 12s, 16s, 0, PHASE_2);
            events.ScheduleEvent(EVENT_SOULSTORM, 100ms, 0, PHASE_2);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_CORRUPTED_SOUL_FRAGMENT)
        {
            summons.Summon(summon);
            summon->SetReactState(REACT_PASSIVE);
            summon->GetMotionMaster()->MoveFollow(me, me->GetCombatReach(), 0.0f);
            summon->CastSpell(summon, SPELL_PURPLE_BANISH_VISUAL, true);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_SOUL_POWER)
        {
            uint32 count = 0;
            for (ObjectGuid const& guid : summons)
            {
                if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
                    if (summon->GetEntry() == NPC_CORRUPTED_SOUL_FRAGMENT && summon->IsAlive())
                        ++count;
            }
            return count;
        }

        return 0;
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
                case EVENT_MAGIC_BANE:
                    DoCastAOE(SPELL_MAGIC_S_BANE);
                    events.ScheduleEvent(EVENT_MAGIC_BANE, 8s, 20s);
                    break;
                case EVENT_SHADOW_BOLT:
                    if (events.IsInPhase(PHASE_2))
                    {
                        DoCastVictim(SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 1s, 2s);
                    }
                    else
                    {
                        if (!me->IsWithinMeleeRange(me->GetVictim()))
                            DoCastVictim(SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2s);
                    }
                    break;
                case EVENT_CORRUPT_SOUL:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    {
                        Talk(SAY_CORRUPT_SOUL);
                        DoCast(target, SPELL_CORRUPT_SOUL);
                    }
                    events.ScheduleEvent(EVENT_CORRUPT_SOUL, 25s, 35s, 0, PHASE_1);
                    break;
                case EVENT_SOULSTORM:
                    Talk(SAY_SOUL_STORM);
                    me->CastSpell(me, SPELL_SOULSTORM_VISUAL, true);
                    me->CastSpell(me, SPELL_SOULSTORM, false);
                    break;
                case EVENT_FEAR:
                    me->CastSpell(nullptr, SPELL_FEAR, { SPELLVALUE_MAX_TARGETS, 1 });
                    events.ScheduleEvent(EVENT_FEAR, 8s, 12s, 0, PHASE_2);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (!events.IsInPhase(PHASE_2))
            DoMeleeAttackIfReady();
    }
};

struct npc_corrupted_soul_fragment : public ScriptedAI
{
    npc_corrupted_soul_fragment(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* bronjahm = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BRONJAHM)))
            bronjahm->AI()->JustSummoned(me);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != FOLLOW_MOTION_TYPE)
            return;

        if (instance->GetGuidData(DATA_BRONJAHM).GetCounter() != id)
            return;

        me->CastSpell(nullptr, SPELL_CONSUME_SOUL, true);
        me->DespawnOrUnsummon();
    }

private:
    InstanceScript* instance;
};

// 68793, 69050 - Magic's Bane
class spell_bronjahm_magic_bane : public SpellScript
{
    PrepareSpellScript(spell_bronjahm_magic_bane);

    void RecalculateDamage(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->GetPowerType() != POWER_MANA)
            return;

        int32 const maxDamage = GetCaster()->GetMap()->IsHeroic() ? 15000 : 10000;
        int32 newDamage = GetEffectValue() + (GetHitUnit()->GetMaxPower(POWER_MANA) / 2);
        SetEffectValue(std::min<int32>(maxDamage, newDamage));
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_bronjahm_magic_bane::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 68861 - Consume Soul
class spell_bronjahm_consume_soul : public SpellScript
{
    PrepareSpellScript(spell_bronjahm_consume_soul);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bronjahm_consume_soul::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

static uint32 const SoulstormVisualSpells[] =
{
    68904,
    68886,
    68905,
    68896,
    68906,
    68897,
    68907,
    68898
};

class spell_bronjahm_soulstorm_visual : public AuraScript
{
    PrepareAuraScript(spell_bronjahm_soulstorm_visual);

    void HandlePeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SoulstormVisualSpells[aurEff->GetTickNumber() % 8], true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bronjahm_soulstorm_visual::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 68921, 69049 - Soulstorm
class spell_bronjahm_soulstorm_targeting : public SpellScript
{
    PrepareSpellScript(spell_bronjahm_soulstorm_targeting);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject* target)
        {
            return caster->GetExactDist2d(target) <= 10.0f;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_bronjahm_soulstorm_targeting::FilterTargets, EFFECT_ALL, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class achievement_bronjahm_soul_power : public AchievementCriteriaScript
{
    public:
        achievement_bronjahm_soul_power() : AchievementCriteriaScript("achievement_bronjahm_soul_power") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_SOUL_POWER) >= 4;
        }
};

void AddSC_boss_bronjahm()
{
    RegisterForgeOfSoulsCreatureAI(boss_bronjahm);
    RegisterForgeOfSoulsCreatureAI(npc_corrupted_soul_fragment);
    RegisterSpellScript(spell_bronjahm_magic_bane);
    RegisterSpellScript(spell_bronjahm_consume_soul);
    RegisterSpellScriptWithArgs(spell_bronjahm_soulstorm_visual, "spell_bronjahm_soulstorm_channel");
    RegisterSpellScriptWithArgs(spell_bronjahm_soulstorm_visual, "spell_bronjahm_soulstorm_visual");
    RegisterSpellScript(spell_bronjahm_soulstorm_targeting);
    RegisterSpellScript(achievement_bronjahm_soul_power);
}

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
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_WATER_BLAST                           = 54237,
    SPELL_WATER_BOLT_VOLLEY                     = 54241,
    SPELL_SPLATTER                              = 54259,
    SPELL_PROTECTIVE_BUBBLE                     = 54306,
    SPELL_FRENZY                                = 54312,
    SPELL_BURST                                 = 54379,
    SPELL_DRAINED                               = 59820,
    SPELL_THREAT_PROC                           = 61732,
    SPELL_SHRINK                                = 54297,

    SPELL_WATER_GLOBULE_SUMMON_1                = 54258,
    SPELL_WATER_GLOBULE_SUMMON_2                = 54264,
    SPELL_WATER_GLOBULE_SUMMON_3                = 54265,
    SPELL_WATER_GLOBULE_SUMMON_4                = 54266,
    SPELL_WATER_GLOBULE_SUMMON_5                = 54267,
    SPELL_WATER_GLOBULE_TRANSFORM               = 54268,
    SPELL_WATER_GLOBULE_VISUAL                  = 54260,

    SPELL_MERGE                                 = 54269,
    SPELL_SPLASH                                = 59516
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ENRAGE                                  = 4,
    SAY_SHATTER                                 = 5,
    SAY_BUBBLE                                  = 6,
    EMOTE_SHATTER                               = 7
};

enum Actions
{
    ACTION_WATER_GLOBULE_HIT                    = 1,
    ACTION_PROTECTIVE_BUBBLE_SHATTERED          = 2,
    ACTION_DRAINED                              = 3
};

enum Misc
{
    DATA_DEHYDRATION                            = 1
};

struct boss_ichoron : public BossAI
{
    boss_ichoron(Creature* creature) : BossAI(creature, DATA_ICHORON)
    {
        Initialize();

        /// for some reason ichoron can't walk back to it's water basin on evade
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
    }

    void Initialize()
    {
        _isFrenzy = false;
        _dehydration = true;
    }

    void Reset() override
    {
        Initialize();
        BossAI::Reset();

        DoCast(me, SPELL_THREAT_PROC, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetData(DATA_HANDLE_CELLS, DATA_ICHORON);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_WATER_GLOBULE_HIT:
                if (!me->IsAlive())
                    break;

                me->ModifyHealth(int32(me->CountPctFromMaxHealth(3)));
                _dehydration = false;
                break;
            case ACTION_PROTECTIVE_BUBBLE_SHATTERED:
            {
                Talk(SAY_SHATTER);
                Talk(EMOTE_SHATTER);

                DoCastAOE(SPELL_SPLATTER, true);
                DoCastAOE(SPELL_BURST, true);
                DoCast(me, SPELL_DRAINED, true);

                uint32 damage = me->CountPctFromMaxHealth(30);
                me->LowerPlayerDamageReq(damage);
                me->ModifyHealth(-std::min<int32>(damage, me->GetHealth() - 1));

                scheduler.DelayAll(Seconds(15));
                break;
            }
            case ACTION_DRAINED:
                if (HealthAbovePct(30))
                {
                    Talk(SAY_BUBBLE);
                    DoCast(me, SPELL_PROTECTIVE_BUBBLE, true);
                }
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_DEHYDRATION)
            return _dehydration ? 1 : 0;
        return 0;
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_ICHOR_GLOBULE)
            DoCast(summon, SPELL_WATER_GLOBULE_VISUAL);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);

        if (summons.empty())
            me->RemoveAurasDueToSpell(SPELL_DRAINED, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (!_isFrenzy && HealthBelowPct(25) && !me->HasAura(SPELL_DRAINED))
        {
            Talk(SAY_ENRAGE);
            DoCast(me, SPELL_FRENZY, true);
            _isFrenzy = true;
        }

        scheduler.Update(diff,
            std::bind(&BossAI::DoMeleeAttackIfReady, this));
    }

    void ScheduleTasks() override
    {
        scheduler.Async([this]
        {
            DoCast(me, SPELL_SHRINK);
            DoCast(me, SPELL_PROTECTIVE_BUBBLE);
        });

        scheduler.Schedule(Seconds(10), Seconds(15), [this](TaskContext task)
        {
            DoCastAOE(SPELL_WATER_BOLT_VOLLEY);
            task.Repeat(Seconds(10), Seconds(15));
        });

        scheduler.Schedule(Seconds(6), Seconds(9), [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f))
                DoCast(target, SPELL_WATER_BLAST);
            task.Repeat(Seconds(6), Seconds(9));
        });
    }

private:
    bool _isFrenzy;
    bool _dehydration;
};

struct npc_ichor_globule : public ScriptedAI
{
    npc_ichor_globule(Creature* creature) : ScriptedAI(creature), _splashTriggered(false)
    {
        _instance = creature->GetInstanceScript();
        creature->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Unit* unitCaster = caster->ToUnit();
        if (!unitCaster)
            return;

        if (spellInfo->Id == SPELL_WATER_GLOBULE_VISUAL)
        {
            DoCast(me, SPELL_WATER_GLOBULE_TRANSFORM);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->GetMotionMaster()->MoveFollow(unitCaster, 0.0f, 0.0f);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != FOLLOW_MOTION_TYPE)
            return;

        if (_instance->GetObjectGuid(DATA_ICHORON).GetCounter() != id)
            return;

        me->CastSpell(me, SPELL_MERGE);
        me->DespawnOrUnsummon(1ms);
    }

    // on retail spell casted on a creature's death are not casted after death but keeping mob at 1 health, casting it and then letting the mob die.
    // this feature should be still implemented
    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_splashTriggered)
            return;

        if (damage >= me->GetHealth())
        {
            _splashTriggered = true;
            DoCastAOE(SPELL_SPLASH);
        }
    }

    void UpdateAI(uint32 /*diff*/) override { }

private:
    InstanceScript* _instance;
    bool _splashTriggered;
};

// 59820 - Drained
class spell_ichoron_drained : public AuraScript
{
    PrepareAuraScript(spell_ichoron_drained);

    bool Load() override
    {
        return GetOwner()->GetEntry() == NPC_ICHORON || GetOwner()->GetEntry() == NPC_DUMMY_ICHORON;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        GetTarget()->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        GetTarget()->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (UnitAI* ai = GetTarget()->GetAI())
                ai->DoAction(ACTION_DRAINED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_ichoron_drained::HandleApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_drained::HandleRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 54269 - Merge
class spell_ichoron_merge : public SpellScript
{
    PrepareSpellScript(spell_ichoron_merge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHRINK });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
        {
            if (Aura* aura = target->GetAura(SPELL_SHRINK))
                aura->ModStackAmount(-1);

            target->AI()->DoAction(ACTION_WATER_GLOBULE_HIT);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ichoron_merge::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 54306 - Protective Bubble
class spell_ichoron_protective_bubble : public AuraScript
{
    PrepareAuraScript(spell_ichoron_protective_bubble);

    bool Load() override
    {
        return GetOwner()->GetEntry() == NPC_ICHORON || GetOwner()->GetEntry() == NPC_DUMMY_ICHORON;
    }

    void HandleShatter(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        //if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
        if (GetAura()->GetCharges() <= 1)
            if (UnitAI* targetAI = GetTarget()->GetAI())
                targetAI->DoAction(ACTION_PROTECTIVE_BUBBLE_SHATTERED);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_protective_bubble::HandleShatter, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 54259 - Splatter
class spell_ichoron_splatter : public AuraScript
{
    PrepareAuraScript(spell_ichoron_splatter);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_WATER_GLOBULE_SUMMON_1,
            SPELL_WATER_GLOBULE_SUMMON_2,
            SPELL_WATER_GLOBULE_SUMMON_3,
            SPELL_WATER_GLOBULE_SUMMON_4,
            SPELL_WATER_GLOBULE_SUMMON_5,
            SPELL_SHRINK
        });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), RAND(SPELL_WATER_GLOBULE_SUMMON_1, SPELL_WATER_GLOBULE_SUMMON_2, SPELL_WATER_GLOBULE_SUMMON_3, SPELL_WATER_GLOBULE_SUMMON_4, SPELL_WATER_GLOBULE_SUMMON_5), true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (Aura* aura = GetTarget()->GetAura(SPELL_SHRINK))
                aura->ModStackAmount(10);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ichoron_splatter::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ichoron_splatter::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_dehydration : public AchievementCriteriaScript
{
    public:
        achievement_dehydration() : AchievementCriteriaScript("achievement_dehydration") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Ichoron = target->ToCreature())
                if (Ichoron->AI()->GetData(DATA_DEHYDRATION))
                    return true;

            return false;
        }
};

void AddSC_boss_ichoron()
{
    RegisterVioletHoldCreatureAI(boss_ichoron);
    RegisterVioletHoldCreatureAI(npc_ichor_globule);
    RegisterSpellScript(spell_ichoron_drained);
    RegisterSpellScript(spell_ichoron_merge);
    RegisterSpellScript(spell_ichoron_protective_bubble);
    RegisterSpellScript(spell_ichoron_splatter);
    new achievement_dehydration();
}

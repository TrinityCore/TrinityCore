/*
 * Copyright 2023 AzgathCore
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

#include "tomb_of_sargeras.h"

enum Spells
{

    // 116689
    SPELL_BONE_SCYTHE = 233423, // aura
    SPELL_SCYTHE_SWEEP = 233426,

    SPELL_BONE_SAW = 233441, // 100% energy
    SPELL_BONE_SAW_ENERGY = 234550, // proc


    SPELL_DEBUFF_OVERRIDE = 233103,  // 233652
    SPELL_DEBUFF_OVER_AURA = 233104,
    SPELL_DEBUFF_OVER_AURA1 = 234364,
    SPELL_DEBUFF_UNBEAR_TOR = 233430,

    // not normal 
    SPELL_CALCIFIED_QUILS = 233431, // 233432(233435)

    // 116691
    SPELL_GET_ENERGY = 246454,
    SPELL_ECHOING_ANGUISH = 233983, // 22
    SPELL_FEL_SQUAL = 235230, // 100%
    SPELL_FEL_SQUAL_ENERGY = 235237,

    SPELL_TORMENTING_BURST = 234015, // 17
    SPELL_PANGS_OF_GUILT = 239401, // 10

    // not normal
    SPELL_SUFFOCATING_DARK = 233894, // 24

    SPELL_AOE_SILENCE = 250306, // ????
    SPELL_REGENERATE_ENERGY = 246455,
    SPELL_ENRAGE = 248671, // 720 secs

    SPELL_BELAC_PRISONER = 236283,
    SPELL_SOUL_CORRUPTION = 248713,
};

enum eEvents
{
    EVENT_SCYTHE_SWEEP = 1,
    EVENT_CALCIFIED_QUILS,

    EVENT_ECHOING_ANGUISH,
    EVENT_PANGS_OF_GUILT,
    EVENT_TORMENTING_BURST,
    EVENT_SUFFOCATING_DARK,

    EVENT_CHECK_ENERGY,
    EVENT_ENRAGE,
    EVENT_SUMMON_ADD,
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
};

std::map<uint32, uint32> hitSpells
{
    { SPELL_BONE_SAW , SPELL_BONE_SAW_ENERGY},
    { SPELL_FEL_SQUAL , SPELL_FEL_SQUAL_ENERGY}
};

// 116689, 116691
class boss_demonic_inquisition : public CreatureScript
{
public:
    boss_demonic_inquisition() : CreatureScript("boss_demonic_inquisition") {}

    struct boss_demonic_inquisitionAI : BossAI
    {
        boss_demonic_inquisitionAI(Creature* creature) : BossAI(creature, DATA_DEMONIC_INQUISITION)
        {
            if (me->GetEntry() == NPC_BELAK)
                SetCombatMovement(false);
        }

        std::unordered_map<ObjectGuid, std::array<bool, 2>> calcifiedQuilsTargets{};

        void Reset() override
        {
            if (me->IsAlive())
                _Reset();

            me->RemoveAurasDueToSpell(SPELL_DEBUFF_OVERRIDE);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEBUFF_OVER_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEBUFF_OVER_AURA1);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ECHOING_ANGUISH);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BELAC_PRISONER);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_CORRUPTION);
            KillAllDelayedEvents();
            me->RemoveAllAreaObjects();

            if (me->IsAlive())
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEBUFF_UNBEAR_TOR);
        }

        void JustEngagedWith(Unit* who) override
        {
            _JustEngagedWith();
            events.Reset();

            me->SetPower(me->GetPowerType(), 0);

            switch (me->GetEntry())
            {
            case NPC_ATRIGAN:
                DoCast(me, SPELL_DEBUFF_OVERRIDE);
                events.RescheduleEvent(EVENT_SCYTHE_SWEEP, 5200);
                if (IsHeroicRaid() || IsMythicRaid())
                    events.RescheduleEvent(EVENT_CALCIFIED_QUILS, 8500);
                Talk(0);
                events.RescheduleEvent(EVENT_SUMMON_ADD, 1000);
                break;
            case NPC_BELAK:
                DoCast(me, SPELL_GET_ENERGY);
                events.RescheduleEvent(EVENT_PANGS_OF_GUILT, 100);
                events.RescheduleEvent(EVENT_ECHOING_ANGUISH, 5000);
                events.RescheduleEvent(EVENT_TORMENTING_BURST, 9000);
                if (IsHeroicRaid() || IsMythicRaid())
                    events.RescheduleEvent(EVENT_SUFFOCATING_DARK, 10000);
                AddDelayedEvent(6500, [this]() -> void
                {
                    Talk(0);
                });
                break;
            }

            DoCast(me, SPELL_REGENERATE_ENERGY);
            events.RescheduleEvent(EVENT_CHECK_ENERGY, 100); // both

            if (!IsLFR())
                events.RescheduleEvent(EVENT_ENRAGE, 720000);

            if (Creature* other = instance->instance->GetCreature(instance->GetGuidData(me->GetEntry() == NPC_BELAK ? NPC_ATRIGAN : NPC_BELAK)))
            {
                AddDelayedEvent(100, [other, who]() -> void
                {
                    if (who)
                        if (!other->IsInCombat())
                            other->AI()->JustEngagedWith(who);
                });
            }
        }

        void EnterEvadeMode(EvadeReason w)
        {
            me->NearTeleportTo(me->GetHomePosition());

            if (Creature* other = instance->instance->GetCreature(instance->GetGuidData(me->GetEntry() == NPC_BELAK ? NPC_ATRIGAN : NPC_BELAK)))
            {
                AddDelayedEvent(100, [other]() -> void
                {
                    if (other->IsInCombat())
                        other->AI()->EnterEvadeMode();
                });
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (attacker == me)
                return;

            if (Creature* other = instance->instance->GetCreature(instance->GetGuidData(me->GetEntry() == NPC_BELAK ? NPC_ATRIGAN : NPC_BELAK)))
            {
                if (damage >= me->GetHealth())
                   Unit::Kill(other, other, true);
                else
                  Unit::DealDamage(other, other, damage);
            }

            if (damage != DIRECT_DAMAGE && damage != SPELL_DIRECT_DAMAGE)
                return;

            for (const auto& pair : hitSpells)
                if (me->HasAura(pair.first))
                    attacker->CastSpell(attacker, pair.second, true);

        }

        void JustDied(Unit* killer) override
        {
            //Talk(SAY_DEATH);
            if (me->GetEntry() == NPC_ATRIGAN)
                DoCast(240053);

            _JustDied();

            if (me->GetEntry() == NPC_ATRIGAN)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (player->HasAura(SPELL_DEBUFF_UNBEAR_TOR))
                        {
                            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 243355);
                            break;
                        }
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEBUFF_UNBEAR_TOR);

            }

            Reset();
        }

        void UpdateAI(uint32 diff) override
        {

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_CALCIFIED_QUILS) || me->HasAura(SPELL_BONE_SAW) || me->HasAura(SPELL_FEL_SQUAL))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SCYTHE_SWEEP:
                    DoCast(SPELL_SCYTHE_SWEEP);
                    events.RescheduleEvent(EVENT_SCYTHE_SWEEP, 24500);
                    break;
                case EVENT_CHECK_ENERGY:
                    if (me->GetPower(me->GetPowerType()) >= 100)
                    {
                        DoCast(me->GetEntry() == NPC_ATRIGAN ? SPELL_BONE_SAW : SPELL_FEL_SQUAL);
                        Talk(1);
                    }

                    events.RescheduleEvent(EVENT_CHECK_ENERGY, 100);
                    break;
                case EVENT_CALCIFIED_QUILS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        calcifiedQuilsTargets.clear();

                        DoCast(target, SPELL_CALCIFIED_QUILS);
                        AddDelayedEvent(5000, [this, target]()
                        {
                            if (!target)
                                return;

                            Position pos = target->GetPosition();
                            float diff_x = pos.GetPositionX() - me->GetPositionX();
                            float diff_y = pos.GetPositionY() - me->GetPositionY();
                            float dist = sqrt(diff_x * diff_x + diff_y * diff_y);
                            for (float mod = 2 / dist, time = 0; mod < 60.0f / dist; mod += (2 / dist), time++)
                            {
                                for (float i = -0.5f; i <= 0.5f; i += 0.2f)
                                {
                                    if (urand(1, 5) == 5)
                                        continue;

                                    float new_x = mod * diff_x * sqrt(3) / 2 - i * mod * diff_y / 2;
                                    float new_y = i * mod * diff_x / 2 + mod * diff_y * sqrt(3) / 2;
                                    AddDelayedEvent(1 + time * 50, [=]()
                                    {
                                        me->CastSpell({ me->GetPositionX() + new_x + frand(-2, 2), me->GetPositionY() + new_y + frand(-2, 2), me->GetPositionZ(), 0 }, 233435, true);

                                    });
                                }
                            }

                        });
                    }
                    events.RescheduleEvent(EVENT_CALCIFIED_QUILS, 20000);
                    break;
                case EVENT_PANGS_OF_GUILT:
                    DoCast(SPELL_PANGS_OF_GUILT);
                    events.RescheduleEvent(EVENT_PANGS_OF_GUILT, 10000);
                    break;
                case EVENT_ECHOING_ANGUISH:
                    DoCast(SPELL_ECHOING_ANGUISH);
                    events.RescheduleEvent(EVENT_ECHOING_ANGUISH, 22000);
                    break;
                case EVENT_TORMENTING_BURST:
                    DoCast(SPELL_TORMENTING_BURST);
                    events.RescheduleEvent(EVENT_TORMENTING_BURST, 17000);
                    break;
                case EVENT_SUFFOCATING_DARK:
                {

                            me->CastSpell(SPELL_SUFFOCATING_DARK, true);

                    events.RescheduleEvent(EVENT_SUFFOCATING_DARK, 24000);
                    break;
                }
                case EVENT_ENRAGE:
                    DoCast(SPELL_ENRAGE);
                    break;
                case EVENT_SUMMON_ADD:
                    me->SummonCreature(NPC_TORMENTED_SOUL, 6403.00f, -935.00f, 3037.16f);
                    break;
                }
            }

            if (me->GetEntry() != NPC_BELAK)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_demonic_inquisitionAI(creature);
    }
};

// 117957
class npc_tos_tormented_soul : public CreatureScript
{
public:
    npc_tos_tormented_soul() : CreatureScript("npc_tos_tormented_soul") {}

    struct npc_tos_tormented_soulAI : public ScriptedAI
    {
        npc_tos_tormented_soulAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->m_SightDistance = 20;
        }

        EventMap events;
        SummonList summons;

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->RemoveAurasDueToSpell(239135);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.RescheduleEvent(EVENT_1, 6000);
            events.RescheduleEvent(EVENT_2, 5000);
        }


        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (urand(1, 3) == 2)
                DoCast(attacker, 235301);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    DoCast(SPELL_SOUL_CORRUPTION);
                    events.RescheduleEvent(EVENT_1, 6000);
                    break;
                case EVENT_2:
                    DoCast(239135);
                    events.RescheduleEvent(EVENT_2, urand(16000, 19000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tos_tormented_soulAI(creature);
    }
};

// 233652
class spell_tos_confess : public SpellScriptLoader
{
public:
    spell_tos_confess() : SpellScriptLoader("spell_tos_confess") { }

    class spell_tos_confess_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_tos_confess_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetTarget())
            {
                if (!caster->IsPlayer())
                    return;

                //caster->GetMotionMaster()->MoveSmoothPath(0, { caster->GetPositionX() + frand(-3, 3), caster->GetPositionY() + frand(-3, 3), caster->GetPositionZ() + 10.0f, caster->GetOrientation()} );
                AddDelayedEvent(1500, [caster]() -> void {
                    caster->RemoveAurasDueToSpell(233652);
                    caster->GetMotionMaster()->Clear();
                    caster->ToPlayer()->TeleportTo(caster->GetMapId(), 6403.13f, -935.55f, 3060.23f, caster->GetOrientation(), TELE_TO_SEAMLESS);
                });
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_tos_confess_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_tos_confess_AuraScript();
    }
};

// 233104
class spell_tos_torment : public SpellScriptLoader
{
public:
    spell_tos_torment() : SpellScriptLoader("spell_tos_torment") { }

    class spell_tos_torment_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_tos_torment_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (target->GetPower(POWER_ALTERNATE_POWER) >= 100)
                target->CastSpell(target, SPELL_DEBUFF_UNBEAR_TOR, true);
            else if (target->GetPower(POWER_ALTERNATE_POWER) == 0)
                if (target->GetDistance2d(6403.13f, -935.55f) <= 30.0f)
                    target->CastSpell(target, 243560, true); // 235293

            if (target->GetDistance2d(6403.13f, -935.55f) > 40.0f && target->HasAura(SPELL_BELAC_PRISONER))
            {
                target->RemoveAurasDueToSpell(SPELL_BELAC_PRISONER);
                target->RemoveAurasDueToSpell(SPELL_DEBUFF_OVER_AURA1); // clear
                target->CastSpell(target, SPELL_DEBUFF_OVER_AURA1, true);
            }
        }

        void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (!target || !target->IsPlayer())
                return;

            if (target->GetDistance2d(6403.13f, -935.55f) <= 30.0f)
                if (target->IsAlive())
                    target->ToPlayer()->TeleportTo(target->GetMapId(), 6401.96f, -795.64f, 3020.17f, 0.01f, TELE_TO_SEAMLESS);
                else
                    target->NearTeleportTo(6401.96f, -795.64f, 3020.17f, 0.01f);

            target->RemoveAurasDueToSpell(SPELL_BELAC_PRISONER);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_torment_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectRemove += AuraEffectRemoveFn(spell_tos_torment_AuraScript::OnRemove, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_tos_torment_AuraScript();
    }
};

// 233435
class spell_tos_calcified_quils : public SpellScript
{
    PrepareSpellScript(spell_tos_calcified_quils);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
            if (GetCaster()->GetEntry() == NPC_ATRIGAN)
                SetHitDamage(0);
    }

    void RecalculateDamage(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (GetCaster() && GetHitUnit())
            if (GetCaster()->GetEntry() == NPC_ATRIGAN)
                GetHitUnit()->SetPower(POWER_ALTERNATE_POWER, GetHitUnit()->GetPower(POWER_ALTERNATE_POWER) + 10);
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_calcified_quils::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_tos_calcified_quils::RecalculateDamage, EFFECT_2, SPELL_EFFECT_ENERGIZE);
    }
};

// 235295
class spell_tos_adherent_fragment : public SpellScript
{
    PrepareSpellScript(spell_tos_adherent_fragment);

    void HandleAfterCast()
    {
        if (Unit* caster = GetCaster())
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (instance->instance->IsMythic())
                    caster->CastSpell(caster, 241505, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_tos_adherent_fragment::HandleAfterCast);
    }
};

class achievement_grin_and_bear_it : public AchievementCriteriaScript
{
public:
    achievement_grin_and_bear_it() : AchievementCriteriaScript("achievement_grin_and_bear_it") { }

    bool OnCheck(Player* source, Unit* /*target*/) override
    {
        if (source->IsAlive() && source->HasAura(233430))
            return true;

        return false;
    }
};

void AddSC_boss_demonic_inquisition()
{
    new boss_demonic_inquisition();
    new npc_tos_tormented_soul();
    new spell_tos_confess();
    new spell_tos_torment();
    RegisterSpellScript(spell_tos_calcified_quils);
    RegisterSpellScript(spell_tos_adherent_fragment);
    new achievement_grin_and_bear_it();

}

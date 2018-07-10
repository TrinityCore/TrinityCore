/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "eye_of_azshara.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_GAIN_ENERGY               = 193245,
    SPELL_CALL_THE_SEAS             = 193051,
    SPELL_CALL_THE_SEAS_DAMAGE      = 193055,
    SPELL_FRENZY                    = 197550,
    SPELL_GASEOUS_BUBBLES           = 193018,
    SPELL_GASEOUS_EXPLOSION         = 193047,
    SPELL_GROUND_SLAM               = 193093,
    SPELL_GROUND_SLAM_DAMAGE        = 193056,
    SPELL_QUAKE                     = 193152,
    SPELL_AFTERSHOCK                = 193167
};

// 91797
struct boss_king_deepbeard : public BossAI
{
    boss_king_deepbeard(Creature* creature) : BossAI(creature, DATA_KING_DEEPBEARD) { }

    void Reset() override
    {
        BossAI::Reset();

        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 30);

        _firstQuake = true;
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        DoCastSelf(SPELL_GAIN_ENERGY, true);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        me->GetInstanceScript()->SetData(DATA_BOSS_DIED, 0);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode(why);

        me->RemoveAurasDueToSpell(SPELL_GAIN_ENERGY);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_QUAKE, 1s);
        events.ScheduleEvent(SPELL_GROUND_SLAM, 6s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(30, damage))
        {
            Talk(4);
            DoCastSelf(SPELL_FRENZY, true);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_CALL_THE_SEAS:
            {
                Talk(3);
                DoCastSelf(SPELL_CALL_THE_SEAS, false);
                events.Repeat(30s);
                break;
            }
            case SPELL_QUAKE:
            {
                if (me->GetPower(POWER_ENERGY) == 100)
                {
                    Talk(2);
                    DoCastSelf(SPELL_QUAKE, false);

                    if (_firstQuake)
                    {
                        events.ScheduleEvent(SPELL_CALL_THE_SEAS, 2s, 3s);
                        events.ScheduleEvent(SPELL_GASEOUS_BUBBLES, 4s, 5s);
                        _firstQuake = false;
                    }
                }

                events.Repeat(1s);
                break;
            }
            case SPELL_GASEOUS_BUBBLES:
            {
                Talk(1);
                DoCastSelf(SPELL_GASEOUS_BUBBLES, false);
                events.Repeat(33s);
                break;
            }
            case SPELL_GROUND_SLAM:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                {
                    DoCast(target, SPELL_GROUND_SLAM, false);
                    DoCastSelf(SPELL_GROUND_SLAM_DAMAGE, true);
                }

                events.Repeat(20s);
                break;
            }
        }
    }

private:
    bool _firstQuake = true;
};

// 193018
class aura_king_deepbeard_gaseous_bubbles : public AuraScript
{
    PrepareAuraScript(aura_king_deepbeard_gaseous_bubbles);

    void OnRemove(AuraEffect const* /*auraEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();

            if (caster)
            {
                if (caster->GetMap()->IsHeroic())
                {
                    int32 damage = GetAura()->GetEffect(EFFECT_0)->GetAmount();
                    target->CastCustomSpell(target, SPELL_GASEOUS_EXPLOSION, &damage, nullptr, nullptr, true);
                }
                else
                    target->CastSpell(target, SPELL_GASEOUS_EXPLOSION, true);
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_king_deepbeard_gaseous_bubbles::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 97916
struct npc_king_deepbeard_quake : public ScriptedAI
{
    npc_king_deepbeard_quake(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->setFaction(16);
        DoCastSelf(SPELL_AFTERSHOCK, false);
    }
};

// Spell: 193054
// AT: 9683
struct at_king_deepbeard_call_the_seas : AreaTriggerAI
{
    at_king_deepbeard_call_the_seas(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        Player* player = unit->ToPlayer();

        if (caster && player && caster->IsValidAttackTarget(player))
            caster->CastSpell(player, SPELL_CALL_THE_SEAS_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CALL_THE_SEAS_DAMAGE);
    }
};

// 193245
class aura_king_deepbeard_gain_energy : public AuraScript
{
    PrepareAuraScript(aura_king_deepbeard_gain_energy);

    void OnPeriodic(AuraEffect const* /*auraEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->ModifyPower(POWER_ENERGY, 5);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_king_deepbeard_gain_energy::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

void AddSC_boss_king_deepbeard()
{
    RegisterCreatureAI(boss_king_deepbeard);
    RegisterCreatureAI(npc_king_deepbeard_quake);

    RegisterAuraScript(aura_king_deepbeard_gaseous_bubbles);
    RegisterAuraScript(aura_king_deepbeard_gain_energy);

    RegisterAreaTriggerAI(at_king_deepbeard_call_the_seas);
}

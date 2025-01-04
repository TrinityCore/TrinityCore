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

#include "halls_of_lightning.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    // Volkhan
    SAY_AGGRO                       = 0,
    SAY_ANNOUNCE_RUN_TO_ANVIL       = 1,
    SAY_RUN_TO_ANVIL                = 2,
    SAY_SHATTERING_STOMP            = 3,
    SAY_ANNOUNCE_SHATTERING_STOMP   = 4,
    SAY_DEATH                       = 5,
    SAY_SLAY                        = 6
};

enum Spells
{
    // Volkhan
    SPELL_TEMPER_SUMMON_OBJECT              = 52661,
    SPELL_TEMPER_DUMMY_INTRO                = 52654,
    SPELL_TEMPER_DUMMY_COMBAT               = 52238,
    SPELL_SHATTERING_STOMP                  = 52237,
    SPELL_HEAT                              = 52387,
    SPELL_DAZE_IMMUNITY_CANCEL              = 59556,

    // Volkhan's Anvil
    SPELL_SUMMON_MOLTEN_GOLEM               = 52405,

    // Molten Golem
    SPELL_COOL_DOWN                         = 52441,
    SPELL_COOL_DOWN_SLOW                    = 52443,
    SPELL_STUN_SELF                         = 47067, // Serverside spell @todo
    SPELL_COSMETIC_STUN_IMMUNE_FREEZE_AMNIM = 59123,
    SPELL_INSTAKILL_SELF                    = 29878, // Serverside spell
    SPELL_IMMOLATION_STRIKE                 = 52433
};

#define SPELL_SHATTER DUNGEON_MODE<uint32>(52429,59527)

enum Events
{
    // Volkhan
    EVENT_TEMPER_INTRO = 1,
    EVENT_RUN_TO_ANVIL,
    EVENT_TEMPER,
    EVENT_HEAT,
    EVENT_SHATTERING_STOMP,

    // Molten Golem
    EVENT_IMMOLATION_STRIKE
};

enum Actions
{
    // Volkhan
    ACTION_SHATTER_GOLEMS   = 0,
    ACTION_GOLEMS_TEMPERED  = 1,

    // Molten Golem
    ACTION_SHATTER          = 0
};

enum Phases
{
    // Volkhan
    PHASE_INTRO = 1,
    PHASE_COMBAT
};

enum MovePoints
{
    // Volkhan
    POINT_ID_ANVIL = 0
};

enum Misc
{
    ENTRY_BRITTLE_GOLEM = 28681
};

enum Data
{
    DATA_SHATTER_RESISTANT = 0
};

static Position const AnvilPosition = { 1333.5901f, -103.67797f, 56.7177f };

struct boss_volkhan : public BossAI
{
    boss_volkhan(Creature* creature) : BossAI(creature, DATA_VOLKHAN),
        _shatteredGolems(false), _temperingGolems(false), _temperCycles(0), _shatteredGolemsCount(0) { }

    void JustAppeared() override
    {
        events.SetPhase(PHASE_INTRO);
        events.ScheduleEvent(EVENT_TEMPER_INTRO, 13s, 0, PHASE_INTRO);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        events.SetPhase(PHASE_COMBAT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH, killer);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_SLAY, who);
    }

    void MovementInform(uint32 motionType, uint32 id) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_ID_ANVIL:
                events.ScheduleEvent(EVENT_TEMPER, 1s, 0, PHASE_COMBAT);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
    {
        if (damage >= me->GetHealth() || _shatteredGolems)
            return;

        if (_temperCycles >= 3 && !_temperingGolems && !_shatteredGolems && me->HealthBelowPctDamaged(25, damage))
        {
            events.CancelEvent(EVENT_RUN_TO_ANVIL);
            events.ScheduleEvent(EVENT_SHATTERING_STOMP, 1ms, 0, PHASE_COMBAT);
            _shatteredGolems = true;
            return;
        }

        if (_temperCycles < 3 && me->HealthBelowPctDamaged(100.f - (20.f + 20.f * _temperCycles), damage))
        {
            if (!_temperingGolems)
            {
                events.ScheduleEvent(EVENT_RUN_TO_ANVIL, 1ms, 0, PHASE_COMBAT);
                _temperingGolems = true;
            }
            ++_temperCycles;
        }

    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SHATTER_GOLEMS:
                summons.RemoveNotExisting();
                for (ObjectGuid const& guid : summons)
                {
                    if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                    {
                        if (golem->HasAura(SPELL_COSMETIC_STUN_IMMUNE_FREEZE_AMNIM))
                        {
                            if (CreatureAI* ai = golem->AI())
                            {
                                ai->DoAction(ACTION_SHATTER);
                                ++_shatteredGolemsCount;
                            }
                        }
                    }
                }
                break;
            case ACTION_GOLEMS_TEMPERED:
                _temperingGolems = false;
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_SHATTER_RESISTANT:
                return _shatteredGolemsCount;
            default:
                return 0;
        }

        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TEMPER_INTRO:
                    DoCastAOE(SPELL_TEMPER_SUMMON_OBJECT);
                    DoCastAOE(SPELL_TEMPER_DUMMY_INTRO);
                    events.Repeat(13s);
                    break;
                case EVENT_RUN_TO_ANVIL:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_ID_ANVIL, AnvilPosition);
                    events.CancelEvent(EVENT_HEAT);
                    Talk(SAY_ANNOUNCE_RUN_TO_ANVIL);
                    Talk(SAY_RUN_TO_ANVIL);
                    break;
                case EVENT_TEMPER:
                    if (Creature const* anvil = instance->GetCreature(DATA_VOLKHANS_ANVIL))
                    {
                        me->SetFacingToObject(anvil);
                        DoCastAOE(SPELL_TEMPER_SUMMON_OBJECT);
                        DoCastAOE(SPELL_TEMPER_DUMMY_COMBAT);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_HEAT, 8s + 500ms, 0, PHASE_COMBAT);
                    }
                    break;
                case EVENT_HEAT:
                    DoCastAOE(SPELL_HEAT);
                    events.Repeat(10s);
                    break;
                case EVENT_SHATTERING_STOMP:
                    events.CancelEvent(EVENT_HEAT);
                    Talk(SAY_SHATTERING_STOMP);
                    Talk(SAY_ANNOUNCE_SHATTERING_STOMP);
                    DoCastAOE(SPELL_SHATTERING_STOMP);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _shatteredGolems;
    bool _temperingGolems;
    uint8 _temperCycles;
    uint8 _shatteredGolemsCount;
};

struct npc_volkhan_molten_golem : public ScriptedAI
{
    npc_volkhan_molten_golem(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_COOL_DOWN);
        //DoCastSelf(SPELL_STUN_SELF);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_IMMOLATION_STRIKE, 7s, 12s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(5s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SHATTER:
                me->RemoveAurasDueToSpell(SPELL_COSMETIC_STUN_IMMUNE_FREEZE_AMNIM);
                DoCastAOE(SPELL_SHATTER);
                DoCastSelf(SPELL_INSTAKILL_SELF);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
    {
        // Molten Golems cannot die from foreign damage. They will kill themselves via suicide spell when getting shattered
        if (damage >= me->GetHealth() && attacker != me)
            damage = me->GetHealth() - 1;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_IMMOLATION_STRIKE:
                    DoCastVictim(SPELL_IMMOLATION_STRIKE);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

// 52654, 52238 - Temper
class spell_volkhan_temper_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TEMPER_DUMMY_COMBAT });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (InstanceScript* instance = target->GetInstanceScript())
            if (GameObject* temperVisual = instance->GetGameObject(DATA_VOLKHAN_TEMPER_VISUAL))
                temperVisual->SendCustomAnim(0);

        if (GetSpellInfo()->Id == SPELL_TEMPER_DUMMY_COMBAT)
        {
            for (uint8 i = 0; i < 2; ++i)
                GetHitUnit()->CastSpell(nullptr, SPELL_SUMMON_MOLTEN_GOLEM);

            if (Unit* caster = GetCaster())
                if (Creature* creatureCaster = caster->ToCreature())
                    if (CreatureAI* ai = creatureCaster->AI())
                        ai->DoAction(ACTION_GOLEMS_TEMPERED);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volkhan_temper_dummy::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 52441 - Cool Down
class spell_volkhan_cool_down : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COOL_DOWN_SLOW, SPELL_COSMETIC_STUN_IMMUNE_FREEZE_AMNIM });
    }

    void HandlePeriodicDummyEffect(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (target->GetHealthPct() > 1.f)
        {
            // This damage part feels weird but there is no trace of spells in sniffs that could do such thing otherwise.
            Unit::DealDamage(target, target, CalculatePct(target->GetMaxHealth(), target->GetMap()->IsHeroic() ? 1 : 2));
            int32 bp = 0 - static_cast<int32>(100.f - target->GetHealthPct());
            target->CastSpell(nullptr, SPELL_COOL_DOWN_SLOW, CastSpellExtraArgs().AddSpellBP0(bp));
        }
        else
        {
            target->CastSpell(nullptr, SPELL_COSMETIC_STUN_IMMUNE_FREEZE_AMNIM);
            target->RemoveAurasDueToSpell(SPELL_COOL_DOWN_SLOW);
            GetAura()->Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_volkhan_cool_down::HandlePeriodicDummyEffect, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 59123 Cosmetic - Stun + Immune Permanent (Freeze Anim)
class spell_volkhan_cosmetic_stun_immune_permanent : public AuraScript
{
    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->UpdateEntry(ENTRY_BRITTLE_GOLEM, nullptr, false);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_volkhan_cosmetic_stun_immune_permanent::HandleApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 52237, 59529 - Shattering Stomp
class spell_volkhan_shattering_stomp : public SpellScript
{
    void HandleShattering()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (CreatureAI* ai = caster->AI())
                ai->DoAction(ACTION_SHATTER_GOLEMS);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_volkhan_shattering_stomp::HandleShattering);
    }
};

class achievement_shatter_resistant : public AchievementCriteriaScript
{
    public:
        achievement_shatter_resistant() : AchievementCriteriaScript("achievement_shatter_resistant") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target || !target->IsCreature())
                return false;

            if (Creature* creature = target->ToCreature())
                if (CreatureAI* ai = creature->AI())
                    return ai->GetData(DATA_SHATTER_RESISTANT) < 5;

            return false;
        }
};

void AddSC_boss_volkhan()
{
    RegisterHallsOfLightningCreatureAI(boss_volkhan);
    RegisterHallsOfLightningCreatureAI(npc_volkhan_molten_golem);
    RegisterSpellScript(spell_volkhan_temper_dummy);
    RegisterSpellScript(spell_volkhan_cool_down);
    RegisterSpellScript(spell_volkhan_cosmetic_stun_immune_permanent);
    RegisterSpellScript(spell_volkhan_shattering_stomp);
    new achievement_shatter_resistant();
}

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

#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TaskScheduler.h"
#include "Unit.h"
#include "sepulcher_of_the_first_ones.h"

enum LordsOfDreadImitationSpells
{
    SPELL_GRAND_REVEAL_MALGANIS                         = 366518,
    SPELL_GRAND_REVEAL_KINTESSA                         = 366565,
    SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS                = 367410,
    SPELL_SWARMING_RETREAT                              = 366559,
    SPELL_CLEAR_ALL_DEBUFFS                             = 34098,
    SPELL_LEECHING_CLAWS_PROTECTOR                      = 366549,
    SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR      = 366550,
    SPELL_OPENED_VEINS_PROTECTOR                        = 366551,
    SPELL_LEECHING_CLAWS_HEAL_PROTECTOR                 = 366553,
    SPELL_CLOUD_OF_CARRION_PROTECTOR                    = 366573,
    SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR             = 366574,
    SPELL_ANGUISHING_STRIKE_PROTECTOR                   = 366629,
    SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR   = 366631,
    SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR            = 366632,
    SPELL_FEARFUL_TREPIDATION_PROTECTOR                 = 366633,
    SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR          = 366634,
};

enum LordsOfDreadImitationEvents
{
    // Overthrown Protector Malganis
    EVENT_LEECHING_CLAWS_PROTECTOR = 1,
    EVENT_CLOUD_OF_CARRION_PROTECTOR,

    // Overthrown Protector Kintessa
    EVENT_ANGUISHING_STRIKE_PROTECTOR,
    EVENT_FEARFUL_TREPIDATION_PROTECTOR,
};

enum LordsOfDreadImitationTexts
{
    // Lords of Dread Imitations
    SAY_MALGANIS_COPY_AGGRO                 = 0,
    SAY_MALGANIS_COPY_RETREAT               = 1,

    SAY_KINTESSA_COPY_AGGRO                 = 0,
    SAY_KINTESSA_COPY_RETREAT               = 1,
};

 // 185154 - Overthrown Protector (Mal'Ganis)
struct npc_overthrown_protector_malganis : public ScriptedAI
{
    npc_overthrown_protector_malganis(Creature* creature) : ScriptedAI(creature), _malganisRetreated(false) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_GRAND_REVEAL_MALGANIS, true);
        _events.ScheduleEvent(EVENT_LEECHING_CLAWS_PROTECTOR, 10s);
        _events.ScheduleEvent(EVENT_CLOUD_OF_CARRION_PROTECTOR, 15s);
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            Talk(SAY_MALGANIS_COPY_AGGRO);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(90, damage) && _malganisRetreated == false)
        {
            _malganisRetreated = true;
            DoCastSelf(SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS, true);
            DoCastSelf(SPELL_SWARMING_RETREAT);
            Talk(SAY_MALGANIS_COPY_RETREAT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LEECHING_CLAWS_PROTECTOR:
                {
                    DoCastVictim(SPELL_LEECHING_CLAWS_PROTECTOR);
                    _events.Repeat(10s);
                    break;
                }
                case EVENT_CLOUD_OF_CARRION_PROTECTOR:
                {
                    DoCastSelf(SPELL_CLOUD_OF_CARRION_PROTECTOR);
                    _events.Repeat(5s, 10s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    bool _malganisRetreated;
    TaskScheduler _scheduler;
    EventMap _events;
};

// 185155 - Overthrown Protector (Kin'tessa)
struct npc_overthrown_protector_kintessa : public ScriptedAI
{
    npc_overthrown_protector_kintessa(Creature* creature) : ScriptedAI(creature), _kintessaRetreated(false) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_GRAND_REVEAL_KINTESSA, true);
        _events.ScheduleEvent(EVENT_ANGUISHING_STRIKE_PROTECTOR, Milliseconds(urand(8000, 10000)));
        _events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION_PROTECTOR, Milliseconds(urand(15000, 20000)));
        me->SetObjectScale(2);
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            Talk(SAY_KINTESSA_COPY_AGGRO);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(90, damage) && _kintessaRetreated == false)
        {
            _kintessaRetreated = true;
            DoCastSelf(SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS, true);
            DoCastSelf(SPELL_SWARMING_RETREAT);
            Talk(SAY_KINTESSA_COPY_RETREAT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ANGUISHING_STRIKE_PROTECTOR:
                {
                    DoCastVictim(SPELL_ANGUISHING_STRIKE_PROTECTOR);
                    _events.Repeat(10s, 12s);
                    break;
                }
                case EVENT_FEARFUL_TREPIDATION_PROTECTOR:
                {
                    DoCastSelf(SPELL_FEARFUL_TREPIDATION_PROTECTOR);
                    _events.Repeat(15s, 20s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    bool _kintessaRetreated;
    TaskScheduler _scheduler;
    EventMap _events;
};

// 366518 - Grand Reveal Mal'Ganis
// 366565 - Grand Reveal Kin'Tessa
int32 constexpr MALGANIS_OVERRIDE_NAME = 279;
int32 constexpr KINTESSA_OVERRIDE_NAME = 280;
class spell_lords_of_dread_grand_reveal : public AuraScript
{
    // @TODO: drop me after SPELL_AURA_SPELL_OVERRIDE_NAME_GROUP impl
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (Creature* creature = target->ToCreature())
        {
            if (creature->GetEntry() == NPC_OVERTHROWN_PROTECTOR_MALGANIS)
                target->SetSpellOverrideNameID(MALGANIS_OVERRIDE_NAME);
            else
                target->SetSpellOverrideNameID(KINTESSA_OVERRIDE_NAME);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_lords_of_dread_grand_reveal::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 366549 - Leeching Claws Malganis Imitation
class spell_malganis_imitation_leeching_claws : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_OPENED_VEINS_PROTECTOR, SPELL_LEECHING_CLAWS_HEAL_PROTECTOR, SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (target->HasAura(SPELL_OPENED_VEINS_PROTECTOR))
            caster->CastSpell(caster, SPELL_LEECHING_CLAWS_HEAL_PROTECTOR, true);

        caster->CastSpell(target, SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR, true);
        caster->CastSpell(target, SPELL_OPENED_VEINS_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_imitation_leeching_claws::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366573 - Cloud of Carrion Malganis Imitation
class spell_malganis_imitation_cloud_of_carrion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_imitation_cloud_of_carrion::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366629 - Anguishing Strike Kintessa Imitation
class spell_kintessa_imitation_anguishing_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR, SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR, true);
        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_imitation_anguishing_strike::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366633 - Fearful Trepidation Kintessa Imitation
class spell_kintessa_imitation_fearful_trepidation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_imitation_fearful_trepidation::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

Position const SwarmingRetreatPos = { -5727.0454f, -4067.804f, 146.26663f };

// 366559 - Swarming Retreat
class spell_lords_of_dread_swarming_retreat : public SpellScript
{
    void HandleAfterCast()
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            instance->SetData(DATA_LORDS_OF_DREAD_RETREAT_COUNTER, instance->GetData(DATA_LORDS_OF_DREAD_RETREAT_COUNTER) + 1);

        GetCaster()->GetMotionMaster()->MovePoint(0, SwarmingRetreatPos);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_lords_of_dread_swarming_retreat::HandleAfterCast);
    }
};

void AddSC_sepulcher_of_the_first_ones()
{
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_overthrown_protector_malganis);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_overthrown_protector_kintessa);
    RegisterSpellScript(spell_lords_of_dread_grand_reveal);
    RegisterSpellScript(spell_malganis_imitation_leeching_claws);
    RegisterSpellScript(spell_malganis_imitation_cloud_of_carrion);
    RegisterSpellScript(spell_kintessa_imitation_anguishing_strike);
    RegisterSpellScript(spell_kintessa_imitation_fearful_trepidation);
    RegisterSpellScript(spell_lords_of_dread_swarming_retreat);
}

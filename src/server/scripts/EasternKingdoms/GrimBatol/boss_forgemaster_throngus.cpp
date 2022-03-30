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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "PassiveAI.h"
#include "Player.h"
#include "InstanceScript.h"
#include "Map.h"
#include "grim_batol.h"

enum Spells
{
    // Forgemaster Throngus
    SPELL_MIGHTY_STOMP                              = 74984,
    SPELL_PICK_WEAPON                               = 75000,
    SPELL_PERSONAL_PHALANX                          = 74908,
    SPELL_PERSONAL_PHALANX_SUMMON_FIXATE_TRIGGER    = 74914,
    SPELL_SHIELD_VISUAL                             = 94588,
    SPELL_FIXATE_EFFECT                             = 75071,
    SPELL_FLAMING_SHIELD                            = 90819,
    SPELL_BURNING_DUAL_BLADES                       = 74981,
    SPELL_DISORIENTING_ROAR                         = 74976,
    SPELL_BURNING_FLAMES                            = 90759,
    SPELL_ENCUMBERED                                = 75007,
    SPELL_IMPALING_SLAM                             = 75056,
    SPELL_GLANCING_BLOWS                            = 74909,

    // Cave In Stalker
    SPELL_CAVE_IN_VISUAL                            = 74987
};

enum Events
{
    EVENT_MIGHTY_STOMP = 1,
    EVENT_PICK_WEAPON,
    EVENT_FIXATE_PLAYER,
    EVENT_FIXATE_EFFECT,
    EVENT_FLAMING_SHIELD,
    EVENT_DISORIENTING_ROAR,
    EVENT_IMPALING_SLAM
};

enum Actions
{
    ACTION_PICK_WEAPON = 1,
    ACTION_START_PHALLANX,
    ACTION_END_PHALLANX,
};

enum Weapons
{
    WEAPON_TO_BE_DECIDED    = -1,
    WEAPON_PERSONAL_PHALANX = 0,
    WEAPON_DUAL_BLADES      = 1,
    WEAPON_MACE             = 2
};

enum WeaponModels
{
    WEAPON_MODEL_SWORD = 64435,
    WEAPON_MODEL_MACE  = 49737
};

enum Texts
{
    SAY_AGGRO                       = 0,
    SAY_PERSONAL_PHALANX            = 1,
    SAY_MACE                        = 2,
    SAY_DUAL_BLADES                 = 3,
    SAY_ANNOUNCE_PERSONAL_PHALANX   = 4,
    SAY_ANNOUNCE_MACE               = 5,
    SAY_ANNOUNCE_DUAL_BLADES        = 6,
    SAY_ANNOUNCE_IMPALE             = 7,
    SAY_SLAY                        = 8,
    SAY_DEATH                       = 9
};

struct boss_forgemaster_throngus : public BossAI
{
    boss_forgemaster_throngus(Creature* creature) : BossAI(creature, DATA_FORGEMASTER_THRONGUS),
        _lastWeapon(WEAPON_TO_BE_DECIDED) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_MIGHTY_STOMP, 7s);
        events.ScheduleEvent(EVENT_PICK_WEAPON, 10s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();
        Talk(SAY_DEATH, killer);
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PICK_WEAPON:
            {
                std::unordered_set<int8> availableWeaponSet = { WEAPON_PERSONAL_PHALANX, WEAPON_MACE, WEAPON_DUAL_BLADES };

                if (_lastWeapon != WEAPON_TO_BE_DECIDED)
                    availableWeaponSet.erase(_lastWeapon);

                uint8 selectedWeapon = Trinity::Containers::SelectRandomContainerElement(availableWeaponSet);

                _lastWeapon = selectedWeapon;
                switch (selectedWeapon)
                {
                    case WEAPON_PERSONAL_PHALANX:
                        DoCastSelf(SPELL_PERSONAL_PHALANX, true);
                        DoCastSelf(SPELL_SHIELD_VISUAL, true);
                        Talk(SAY_PERSONAL_PHALANX);
                        Talk(SAY_ANNOUNCE_PERSONAL_PHALANX);
                        events.RescheduleEvent(EVENT_FIXATE_PLAYER, 1s);
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_FLAMING_SHIELD, 3s);
                        break;
                    case WEAPON_DUAL_BLADES:
                        DoCastSelf(SPELL_BURNING_DUAL_BLADES, true);
                        Talk(SAY_DUAL_BLADES);
                        Talk(SAY_ANNOUNCE_DUAL_BLADES);
                        events.RescheduleEvent(EVENT_DISORIENTING_ROAR, 5s);
                        if (IsHeroic())
                            DoCastSelf(SPELL_BURNING_FLAMES, true);
                        break;
                    case WEAPON_MACE:
                        DoCastSelf(SPELL_ENCUMBERED, true);
                        Talk(SAY_MACE);
                        Talk(SAY_ANNOUNCE_MACE);
                        events.RescheduleEvent(EVENT_IMPALING_SLAM, 6s);
                        break;
                    default:
                        break;
                }
                break;
            }
            case ACTION_START_PHALLANX:
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                break;
            case ACTION_END_PHALLANX:
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_FLAMING_SHIELD);
                summons.DespawnEntry(NPC_FIXATE_STALKER);
                break;
            default:
                break;

        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!me->GetVehicleKit())
            return;

        if (apply)
            Talk(SAY_ANNOUNCE_IMPALE, passenger);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_FIXATE_STALKER:
                events.ScheduleEvent(EVENT_FIXATE_EFFECT, 400ms);
                break;
            case NPC_CAVE_IN_STALKER:
                summon->CastSpell(nullptr, SPELL_CAVE_IN_VISUAL);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !me->HasAura(SPELL_PERSONAL_PHALANX))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MIGHTY_STOMP:
                    if (!me->HasAura(SPELL_PERSONAL_PHALANX))
                        DoCastAOE(SPELL_MIGHTY_STOMP, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(49s);
                    break;
                case EVENT_PICK_WEAPON:
                    DoCastSelf(SPELL_PICK_WEAPON);
                    events.Repeat(35s + 500ms);
                    break;
                case EVENT_FIXATE_PLAYER:
                    if (me->HasAura(SPELL_PERSONAL_PHALANX))
                    {
                        summons.DespawnEntry(NPC_FIXATE_STALKER);
                        DoCastAOE(SPELL_PERSONAL_PHALANX_SUMMON_FIXATE_TRIGGER, true);
                        events.Repeat(8s + 500ms);
                    }
                    break;
                case EVENT_FIXATE_EFFECT:
                    if (Creature* stalker = me->FindNearestCreature(NPC_FIXATE_STALKER, 500.0f, true))
                        DoCast(stalker, SPELL_FIXATE_EFFECT);
                    break;
                case EVENT_FLAMING_SHIELD:
                    DoCastSelf(SPELL_FLAMING_SHIELD, true);
                    break;
                case EVENT_DISORIENTING_ROAR:
                    if (me->CanDualWield())
                    {
                        DoCastAOE(SPELL_DISORIENTING_ROAR, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_AURA_STACK, IsHeroic() ? 3 : 1));
                        events.Repeat(22s);
                    }
                    break;
                case EVENT_IMPALING_SLAM:
                    if (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) == WEAPON_MODEL_MACE)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true)))
                            DoCast(target, SPELL_IMPALING_SLAM);
                        events.Repeat(15s + 500ms);
                    }
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    int8 _lastWeapon;
};

class spell_throngus_mighty_stomp : public SpellScript
{
    void HandleHit(SpellEffIndex effIndex)
    {
        PreventHitEffect(effIndex);
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register()
    {
        OnEffectHitTarget.Register(&spell_throngus_mighty_stomp::HandleHit, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_throngus_pick_weapon : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_PICK_WEAPON);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_throngus_pick_weapon::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_throngus_flame_arrow_barrage : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() < 5)
            return;

        Trinity::Containers::RandomResize(targets, 5);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        PreventHitEffect(effIndex);
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, GetSpellInfo()->Effects[effIndex].TriggerSpell, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_throngus_flame_arrow_barrage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_throngus_flame_arrow_barrage::HandleHit, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_throngus_personal_phalanx : public AuraScript
{
    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, aurEff->GetAmount(), true);

        if (Creature* creature = target->ToCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_START_PHALLANX);

        target->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (Creature* throngus = target->ToCreature())
            if (throngus->IsAIEnabled())
                throngus->AI()->DoAction(ACTION_END_PHALLANX);

        target->ModifyAuraState(AURA_STATE_UNKNOWN22, false);
    }

    void Register() override
    {
        OnEffectApply.Register(&spell_throngus_personal_phalanx::AfterApply, EFFECT_2, SPELL_AURA_MOD_PACIFY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_throngus_personal_phalanx::AfterRemove, EFFECT_2, SPELL_AURA_MOD_PACIFY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_throngus_personal_phalanx_aoe : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_throngus_personal_phalanx_aoe::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_throngus_personal_phalanx_aoe::HandleSummon, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_throngus_burning_dual_blades : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetCanDualWield(true);
        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, WEAPON_MODEL_SWORD);
        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, WEAPON_MODEL_SWORD);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetCanDualWield(false);
        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, 0);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_throngus_burning_dual_blades::AfterApply, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_throngus_burning_dual_blades::AfterRemove, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_throngus_disorienting_roar : public AuraScript
{
    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetAura()->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_throngus_disorienting_roar::HandleProc, EFFECT_0, SPELL_AURA_MOD_SPEED_SLOW_ALL);
    }
};

class spell_throngus_encumbered : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, WEAPON_MODEL_MACE);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_throngus_encumbered::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_throngus_encumbered::AfterRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_throngus_impaling_slam : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // @todo: this should be handled by a serverside spell
        if (Unit* caster = GetCaster())
            if (Unit* target = GetTarget())
                target->CastSpell(caster, VEHICLE_SPELL_RIDE_HARDCODED, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetVehicleBase())
            target->ExitVehicle();
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_throngus_impaling_slam::AfterApply, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_throngus_impaling_slam::AfterRemove, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_forgemaster_throngus()
{
    RegisterGrimBatolCreatureAI(boss_forgemaster_throngus);
    RegisterSpellScript(spell_throngus_mighty_stomp);
    RegisterSpellScript(spell_throngus_pick_weapon);
    RegisterSpellScript(spell_throngus_flame_arrow_barrage);
    RegisterSpellScript(spell_throngus_personal_phalanx);
    RegisterSpellScript(spell_throngus_personal_phalanx_aoe);
    RegisterSpellScript(spell_throngus_burning_dual_blades);
    RegisterSpellScript(spell_throngus_disorienting_roar);
    RegisterSpellScript(spell_throngus_encumbered);
    RegisterSpellScript(spell_throngus_impaling_slam);
}

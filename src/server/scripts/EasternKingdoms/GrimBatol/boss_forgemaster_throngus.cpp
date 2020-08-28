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

enum AuraStacks
{
    STACK_AMOUNT_DISORIENTING_ROAR_HC = 3
};

class boss_forgemaster_throngus : public CreatureScript
{
    public:
        boss_forgemaster_throngus() : CreatureScript("boss_forgemaster_throngus") { }

        struct boss_forgemaster_throngusAI : public BossAI
        {
            boss_forgemaster_throngusAI(Creature* creature) : BossAI(creature, DATA_FORGEMASTER_THRONGUS)
            {
                Initialize();
            }

            void Initialize()
            {
                _lastWeapon = WEAPON_TO_BE_DECIDED;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_MIGHTY_STOMP, Seconds(6) + Milliseconds(500));
                events.ScheduleEvent(EVENT_PICK_WEAPON, Seconds(10));
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
                        uint8 selectedWeapon = urand(WEAPON_PERSONAL_PHALANX, WEAPON_MACE);
                        // Make sure that we will never get the same weapon twice in a row
                        if (_lastWeapon == selectedWeapon && selectedWeapon < WEAPON_MACE)
                            selectedWeapon += 1;
                        else if (_lastWeapon == selectedWeapon && selectedWeapon == WEAPON_MACE)
                            selectedWeapon = urand(WEAPON_PERSONAL_PHALANX, WEAPON_DUAL_BLADES);

                        _lastWeapon = selectedWeapon;
                        switch (selectedWeapon)
                        {
                            case WEAPON_PERSONAL_PHALANX:
                                DoCastSelf(SPELL_PERSONAL_PHALANX, true);
                                DoCastSelf(SPELL_SHIELD_VISUAL, true);
                                Talk(SAY_PERSONAL_PHALANX);
                                Talk(SAY_ANNOUNCE_PERSONAL_PHALANX);
                                events.RescheduleEvent(EVENT_FIXATE_PLAYER, Seconds(1));
                                if (IsHeroic())
                                    events.ScheduleEvent(EVENT_FLAMING_SHIELD, Seconds(3));
                                break;
                            case WEAPON_DUAL_BLADES:
                                DoCastSelf(SPELL_BURNING_DUAL_BLADES, true);
                                Talk(SAY_DUAL_BLADES);
                                Talk(SAY_ANNOUNCE_DUAL_BLADES);
                                events.RescheduleEvent(EVENT_DISORIENTING_ROAR, Seconds(5));
                                if (IsHeroic())
                                    DoCastSelf(SPELL_BURNING_FLAMES, true);
                                break;
                            case WEAPON_MACE:
                                DoCastSelf(SPELL_ENCUMBERED, true);
                                Talk(SAY_MACE);
                                Talk(SAY_ANNOUNCE_MACE);
                                events.RescheduleEvent(EVENT_IMPALING_SLAM, Seconds(6));
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                    case ACTION_START_PHALLANX:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->AddUnitState(UNIT_STATE_CANNOT_TURN);
                        break;
                    case ACTION_END_PHALLANX:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAurasDueToSpell(SPELL_FLAMING_SHIELD);
                        me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
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
                        events.ScheduleEvent(EVENT_FIXATE_EFFECT, Milliseconds(400));
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
                                DoCastAOE(SPELL_MIGHTY_STOMP);
                            events.Repeat(Seconds(49));
                            break;
                        case EVENT_PICK_WEAPON:
                            DoCastSelf(SPELL_PICK_WEAPON);
                            events.Repeat(Seconds(35) + Milliseconds(500));
                            break;
                        case EVENT_FIXATE_PLAYER:
                            if (me->HasAura(SPELL_PERSONAL_PHALANX))
                            {
                                summons.DespawnEntry(NPC_FIXATE_STALKER);
                                DoCastAOE(SPELL_PERSONAL_PHALANX_SUMMON_FIXATE_TRIGGER, true);
                                events.Repeat(Seconds(8) + Milliseconds(500));
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
                                DoCastAOE(SPELL_DISORIENTING_ROAR);
                                events.Repeat(Seconds(22));
                            }
                            break;
                        case EVENT_IMPALING_SLAM:
                            if (me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) == WEAPON_MODEL_MACE)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true)))
                                    DoCast(target, SPELL_IMPALING_SLAM);
                                events.Repeat(Seconds(15) + Milliseconds(500));
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

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetGrimBatolAI<boss_forgemaster_throngusAI>(creature);
        }
};

// The following script is needed to prevent permanent resets due to a core bug
class npc_throngus_cave_in : public CreatureScript
{
    public:
        npc_throngus_cave_in() : CreatureScript("npc_throngus_cave_in") { }

        struct npc_throngus_cave_inAI : public NullCreatureAI
        {
            npc_throngus_cave_inAI(Creature* creature) : NullCreatureAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastAOE(SPELL_CAVE_IN_VISUAL);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGrimBatolAI<npc_throngus_cave_inAI>(creature);
        }
};

class spell_throngus_mighty_stomp : public SpellScriptLoader
{
    public:
        spell_throngus_mighty_stomp() : SpellScriptLoader("spell_throngus_mighty_stomp") { }

        class spell_throngus_mighty_stomp_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                PreventHitEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect.Register(&spell_throngus_mighty_stomp_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_throngus_mighty_stomp_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_mighty_stomp_SpellScript();
        }
};

class spell_throngus_pick_weapon : public SpellScriptLoader
{
    public:
        spell_throngus_pick_weapon() : SpellScriptLoader("spell_throngus_pick_weapon") { }

        class spell_throngus_pick_weapon_SpellScript : public SpellScript
        {
            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->GetEntry() == BOSS_FORGEMASTER_THRONGUS)
                    GetCaster()->ToCreature()->AI()->DoAction(ACTION_PICK_WEAPON);
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_throngus_pick_weapon_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_pick_weapon_SpellScript();
        }
};

class spell_throngus_flame_arrow_barrage : public SpellScriptLoader
{
    public:
        spell_throngus_flame_arrow_barrage() : SpellScriptLoader("spell_throngus_flame_arrow_barrage") { }

        class spell_throngus_flame_arrow_barrage_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 5);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                PreventHitEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_throngus_flame_arrow_barrage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget.Register(&spell_throngus_flame_arrow_barrage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_flame_arrow_barrage_SpellScript();
        }
};

class spell_throngus_flaming_arrow : public SpellScriptLoader
{
    public:
        spell_throngus_flaming_arrow() : SpellScriptLoader("spell_throngus_flaming_arrow") { }

        class spell_throngus_flaming_arrow_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_throngus_flaming_arrow_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_flaming_arrow_SpellScript();
        }
};

class spell_throngus_personal_phalanx : public SpellScriptLoader
{
    public:
        spell_throngus_personal_phalanx() : SpellScriptLoader("spell_throngus_personal_phalanx") { }

        class spell_throngus_personal_phalanx_AuraScript : public AuraScript
        {
            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, aurEff->GetAmount(), true);

                if (Creature * throngus = target->ToCreature())
                    if (throngus->IsAIEnabled)
                        throngus->AI()->DoAction(ACTION_START_PHALLANX);

                target->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (Creature* throngus = target->ToCreature())
                    if (throngus->IsAIEnabled)
                        throngus->AI()->DoAction(ACTION_END_PHALLANX);

                target->ModifyAuraState(AURA_STATE_UNKNOWN22, false);
            }

            void Register() override
            {
                OnEffectApply.Register(&spell_throngus_personal_phalanx_AuraScript::AfterApply, EFFECT_2, SPELL_AURA_MOD_PACIFY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove.Register(&spell_throngus_personal_phalanx_AuraScript::AfterRemove, EFFECT_2, SPELL_AURA_MOD_PACIFY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_throngus_personal_phalanx_AuraScript();
        }
};

class spell_throngus_personal_phalanx_aoe : public SpellScriptLoader
{
    public:
        spell_throngus_personal_phalanx_aoe() : SpellScriptLoader("spell_throngus_personal_phalanx_aoe") { }

        class spell_throngus_personal_phalanx_aoe_SpellScript : public SpellScript
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
                OnObjectAreaTargetSelect.Register(&spell_throngus_personal_phalanx_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_throngus_personal_phalanx_aoe_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_personal_phalanx_aoe_SpellScript();
        }
};

class spell_throngus_fixate_effect : public SpellScriptLoader
{
    public:
        spell_throngus_fixate_effect() : SpellScriptLoader("spell_throngus_fixate_effect") { }

        class spell_throngus_fixate_effect_SpellScript : public SpellScript
        {
            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    caster->SetOrientation(caster->GetAngle(GetHitUnit()));
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_throngus_fixate_effect_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_fixate_effect_SpellScript();
        }
};

class spell_throngus_burning_dual_blades : public SpellScriptLoader
{
    public:
        spell_throngus_burning_dual_blades() : SpellScriptLoader("spell_throngus_burning_dual_blades") { }

        class spell_throngus_burning_dual_blades_AuraScript : public AuraScript
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
                AfterEffectApply.Register(&spell_throngus_burning_dual_blades_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove.Register(&spell_throngus_burning_dual_blades_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_throngus_burning_dual_blades_AuraScript();
        }
};

class spell_throngus_disorienting_roar : public SpellScriptLoader
{
    public:
        spell_throngus_disorienting_roar() : SpellScriptLoader("spell_throngus_disorienting_roar") { }

        class spell_throngus_disorienting_roar_SpellScript : public SpellScript
        {
            void HandleHeroicDifficulty()
            {
                if (Unit* target = GetHitUnit())
                    if (target->GetMap()->IsHeroic())
                        if (Aura* disorientingRoar = target->GetAura(GetSpellInfo()->Id))
                            disorientingRoar->SetStackAmount(STACK_AMOUNT_DISORIENTING_ROAR_HC);
            }

            void Register() override
            {
                AfterHit.Register(&spell_throngus_disorienting_roar_SpellScript::HandleHeroicDifficulty);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throngus_disorienting_roar_SpellScript();
        }

        class spell_throngus_disorienting_roar_AuraScript : public AuraScript
        {
            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                if (Aura* aura = GetAura())
                {
                    uint8 stack = aura->GetStackAmount();
                    if (stack > 1)
                    {
                        aura->SetStackAmount(stack - 1);
                        return false;
                    }
                    else
                        aura->Remove();
                }
                return false;
            }

            void Register() override
            {
                DoCheckProc.Register(&spell_throngus_disorienting_roar_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_throngus_disorienting_roar_AuraScript();
        }
};

class spell_throngus_encumbered : public SpellScriptLoader
{
    public:
        spell_throngus_encumbered() : SpellScriptLoader("spell_throngus_encumbered") { }

        class spell_throngus_encumbered_AuraScript : public AuraScript
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
                AfterEffectApply.Register(&spell_throngus_encumbered_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove.Register(&spell_throngus_encumbered_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_throngus_encumbered_AuraScript();
        }
};

class spell_throngus_impaling_slam : public SpellScriptLoader
{
    public:
        spell_throngus_impaling_slam() : SpellScriptLoader("spell_throngus_impaling_slam") { }

        class spell_throngus_impaling_slam_AuraScript : public AuraScript
        {
            void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Unit * target = GetTarget())
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
                AfterEffectApply.Register(&spell_throngus_impaling_slam_AuraScript::AfterApply, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove.Register(&spell_throngus_impaling_slam_AuraScript::AfterRemove, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_throngus_impaling_slam_AuraScript();
        }
};

void AddSC_boss_forgemaster_throngus()
{
    new boss_forgemaster_throngus();
    new npc_throngus_cave_in();
    new spell_throngus_mighty_stomp();
    new spell_throngus_pick_weapon();
    new spell_throngus_flame_arrow_barrage();
    new spell_throngus_flaming_arrow();
    new spell_throngus_personal_phalanx();
    new spell_throngus_personal_phalanx_aoe();
    new spell_throngus_fixate_effect();
    new spell_throngus_burning_dual_blades();
    new spell_throngus_disorienting_roar();
    new spell_throngus_encumbered();
    new spell_throngus_impaling_slam();
}

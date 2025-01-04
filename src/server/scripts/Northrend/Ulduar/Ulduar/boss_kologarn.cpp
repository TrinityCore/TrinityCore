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
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "ulduar.h"
#include "Vehicle.h"

/* ScriptData
SDName: boss_kologarn
SD%Complete: 90
SDComment: @todo Achievements
SDCategory: Ulduar
EndScriptData */

enum Spells
{
    SPELL_ONE_ARM_SMASH                 = 63573,
    SPELL_ARM_SWEEP                     = 63766,
    SPELL_STONE_SHOUT                   = 63716,
    SPELL_PETRIFY_BREATH                = 62030,
    SPELL_STONE_GRIP                    = 62166,
    SPELL_STONE_GRIP_CANCEL             = 65594,
    SPELL_SUMMON_RUBBLE                 = 63633,
    SPELL_ARM_ENTER_VEHICLE             = 65343,
    SPELL_ARM_ENTER_VISUAL              = 64753,

    SPELL_SUMMON_FOCUSED_EYEBEAM        = 63342,
    SPELL_FOCUSED_EYEBEAM_PERIODIC      = 63347,
    SPELL_FOCUSED_EYEBEAM_VISUAL        = 63369,
    SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT   = 63676,
    SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT  = 63702,

    // Passive
    SPELL_KOLOGARN_REDUCE_PARRY         = 64651,
    SPELL_KOLOGARN_PACIFY               = 63726,
    SPELL_KOLOGARN_UNK_0                = 65219, // Not found in DBC

    SPELL_BERSERK                       = 47008  // guess
};

#define SPELL_TWO_ARM_SMASH RAID_MODE<uint32>(63356,64003)
#define SPELL_FALLING_RUBBLE RAID_MODE<uint32>(63821,64001)
#define SPELL_ARM_DEAD_DAMAGE RAID_MODE<uint32>(63629,63979)

enum NPCs
{
    NPC_RUBBLE_STALKER                  = 33809,
    NPC_ARM_SWEEP_STALKER               = 33661
};

enum Events
{
    EVENT_NONE = 0,
    EVENT_INSTALL_ACCESSORIES,
    EVENT_MELEE_CHECK,
    EVENT_SMASH,
    EVENT_SWEEP,
    EVENT_STONE_SHOUT,
    EVENT_STONE_GRIP,
    EVENT_FOCUSED_EYEBEAM,
    EVENT_RESPAWN_LEFT_ARM,
    EVENT_RESPAWN_RIGHT_ARM,
    EVENT_ENRAGE,
};

enum Yells
{
    SAY_AGGRO                               = 0,
    SAY_SLAY                                = 1,
    SAY_LEFT_ARM_GONE                       = 2,
    SAY_RIGHT_ARM_GONE                      = 3,
    SAY_SHOCKWAVE                           = 4,
    SAY_GRAB_PLAYER                         = 5,
    SAY_DEATH                               = 6,
    SAY_BERSERK                             = 7,
    EMOTE_STONE_GRIP                        = 8
};

class boss_kologarn : public CreatureScript
{
    public:
        boss_kologarn() : CreatureScript("boss_kologarn") { }

        struct boss_kologarnAI : public BossAI
        {
            boss_kologarnAI(Creature* creature) : BossAI(creature, DATA_KOLOGARN),
                left(false), right(false)
            {
                me->SetUninteractible(false);
                me->SetControlled(true, UNIT_STATE_ROOT);

                DoCast(SPELL_KOLOGARN_REDUCE_PARRY);
                SetCombatMovement(false);
            }

            bool left, right;
            ObjectGuid eyebeamTarget;

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_MELEE_CHECK, 6s);
                events.ScheduleEvent(EVENT_SMASH, 5s);
                events.ScheduleEvent(EVENT_SWEEP, 19s);
                events.ScheduleEvent(EVENT_STONE_GRIP, 25s);
                events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, 21s);
                events.ScheduleEvent(EVENT_ENRAGE, 10min);

                if (Vehicle* vehicle = me->GetVehicleKit())
                    for (uint8 i = 0; i < 2; ++i)
                        if (Unit* arm = vehicle->GetPassenger(i))
                            DoZoneInCombat(arm->ToCreature());

                BossAI::JustEngagedWith(who);
            }

            void Reset() override
            {
                _Reset();
                me->SetUninteractible(false);
                eyebeamTarget.Clear();
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                DoCast(SPELL_KOLOGARN_PACIFY);
                me->GetMotionMaster()->MoveTargetedHome();
                me->SetUninteractible(true);
                me->SetCorpseDelay(604800); // Prevent corpse from despawning.
                _JustDied();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
            {
                bool isEncounterInProgress = instance->GetBossState(DATA_KOLOGARN) == IN_PROGRESS;
                if (who->GetEntry() == NPC_LEFT_ARM)
                {
                    left = apply;
                    if (!apply && isEncounterInProgress)
                    {
                        Talk(SAY_LEFT_ARM_GONE);
                        events.ScheduleEvent(EVENT_RESPAWN_LEFT_ARM, 40s);
                    }
                }

                else if (who->GetEntry() == NPC_RIGHT_ARM)
                {
                    right = apply;
                    if (!apply && isEncounterInProgress)
                    {
                        Talk(SAY_RIGHT_ARM_GONE);
                        events.ScheduleEvent(EVENT_RESPAWN_RIGHT_ARM, 40s);
                    }
                }

                if (!isEncounterInProgress)
                    return;

                if (!apply)
                {
                    who->CastSpell(me, SPELL_ARM_DEAD_DAMAGE, true);

                    if (Creature* rubbleStalker = who->FindNearestCreature(NPC_RUBBLE_STALKER, 70.0f))
                    {
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_FALLING_RUBBLE, true);
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_SUMMON_RUBBLE, true);
                        who->ToCreature()->DespawnOrUnsummon();
                    }

                    if (!right && !left)
                        events.ScheduleEvent(EVENT_STONE_SHOUT, 5s);

                    instance->TriggerGameEvent(CRITERIA_DISARMED);
                }
                else
                {
                    events.CancelEvent(EVENT_STONE_SHOUT);
                    DoZoneInCombat(who->ToCreature());
                }
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);
                switch (summon->GetEntry())
                {
                    case NPC_FOCUSED_EYEBEAM:
                        summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT, true);
                        break;
                    case NPC_FOCUSED_EYEBEAM_RIGHT:
                        summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT, true);
                        break;
                    case NPC_RUBBLE:
                        summons.Summon(summon);
                        [[fallthrough]];
                    default:
                        return;
                }

                summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_PERIODIC, true);
                summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_VISUAL, true);
                summon->SetReactState(REACT_PASSIVE);

                // Victim gets 67351
                if (!eyebeamTarget.IsEmpty())
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*summon, eyebeamTarget))
                    {
                        summon->Attack(target, false);
                        summon->GetMotionMaster()->MoveChase(target);
                    }
                }
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
                        case EVENT_MELEE_CHECK:
                            if (!me->IsWithinMeleeRange(me->GetVictim()))
                                DoCast(SPELL_PETRIFY_BREATH);
                            events.ScheduleEvent(EVENT_MELEE_CHECK, 1s);
                            break;
                        case EVENT_SWEEP:
                            if (left)
                                DoCast(me->FindNearestCreature(NPC_ARM_SWEEP_STALKER, 500.0f, true), SPELL_ARM_SWEEP, true);
                            events.ScheduleEvent(EVENT_SWEEP, 25s);
                            break;
                        case EVENT_SMASH:
                            if (left && right)
                                DoCastVictim(SPELL_TWO_ARM_SMASH);
                            else if (left || right)
                                DoCastVictim(SPELL_ONE_ARM_SMASH);
                            events.ScheduleEvent(EVENT_SMASH, 15s);
                            break;
                        case EVENT_STONE_SHOUT:
                            DoCast(SPELL_STONE_SHOUT);
                            events.ScheduleEvent(EVENT_STONE_SHOUT, 2s);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(SPELL_BERSERK);
                            Talk(SAY_BERSERK);
                            break;
                        case EVENT_RESPAWN_LEFT_ARM:
                        case EVENT_RESPAWN_RIGHT_ARM:
                        {
                            if (Vehicle* vehicle = me->GetVehicleKit())
                            {
                                int8 seat = eventId == EVENT_RESPAWN_LEFT_ARM ? 0 : 1;
                                uint32 entry = eventId == EVENT_RESPAWN_LEFT_ARM ? NPC_LEFT_ARM : NPC_RIGHT_ARM;
                                vehicle->InstallAccessory(entry, seat, true, TEMPSUMMON_MANUAL_DESPAWN, 0);
                            }
                            break;
                        }
                        case EVENT_STONE_GRIP:
                        {
                            if (right)
                            {
                                DoCast(SPELL_STONE_GRIP);
                                Talk(SAY_GRAB_PLAYER);
                                Talk(EMOTE_STONE_GRIP);
                            }
                            events.ScheduleEvent(EVENT_STONE_GRIP, 25s);
                            break;
                        }
                        case EVENT_FOCUSED_EYEBEAM:
                            if (Unit* eyebeamTargetUnit = SelectTarget(SelectTargetMethod::MaxDistance, 0, 0, true))
                            {
                                eyebeamTarget = eyebeamTargetUnit->GetGUID();
                                DoCast(me, SPELL_SUMMON_FOCUSED_EYEBEAM, true);
                            }
                            events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, 15s, 35s);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_kologarnAI>(creature);
        }
};

// 63633 - Summon Rubble
class spell_ulduar_rubble_summon : public SpellScriptLoader
{
    public:
        spell_ulduar_rubble_summon() : SpellScriptLoader("spell_ulduar_rubble_summon") { }

        class spell_ulduar_rubble_summonSpellScript : public SpellScript
        {
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                ObjectGuid originalCaster = caster->GetInstanceScript() ? caster->GetInstanceScript()->GetGuidData(DATA_KOLOGARN) : ObjectGuid::Empty;
                uint32 spellId = GetEffectValue();
                for (uint8 i = 0; i < 5; ++i)
                    caster->CastSpell(caster, spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .SetOriginalCaster(originalCaster));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_rubble_summonSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulduar_rubble_summonSpellScript();
        }
};

// predicate function to select non main tank target
class StoneGripTargetSelector
{
    public:
        StoneGripTargetSelector(Creature* me, Unit const* victim) : _me(me), _victim(victim) { }

        bool operator()(WorldObject* target)
        {
            if (target == _victim && _me->GetThreatManager().GetThreatListSize() > 1)
                return true;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return true;

            return false;
        }

        Creature* _me;
        Unit const* _victim;
};

// 62166, 63981 - Stone Grip
class spell_ulduar_stone_grip_cast_target : public SpellScriptLoader
{
    public:
        spell_ulduar_stone_grip_cast_target() : SpellScriptLoader("spell_ulduar_stone_grip_cast_target") { }

        class spell_ulduar_stone_grip_cast_target_SpellScript : public SpellScript
        {
            bool Load() override
            {
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return false;
                return true;
            }

            void FilterTargetsInitial(std::list<WorldObject*>& unitList)
            {
                // Remove "main tank" and non-player targets
                unitList.remove_if(StoneGripTargetSelector(GetCaster()->ToCreature(), GetCaster()->GetThreatManager().GetCurrentVictim()));
                // Maximum affected targets per difficulty mode
                uint32 maxTargets = 1;
                if (GetSpellInfo()->Id == 63981)
                    maxTargets = 3;

                // Return a random amount of targets based on maxTargets
                while (maxTargets < unitList.size())
                {
                    std::list<WorldObject*>::iterator itr = unitList.begin();
                    advance(itr, urand(0, unitList.size()-1));
                    unitList.erase(itr);
                }

                // For subsequent effects
                _unitList = unitList;
            }

            void FillTargetsSubsequential(std::list<WorldObject*>& unitList)
            {
                unitList = _unitList;
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FillTargetsSubsequential, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target_SpellScript::FillTargetsSubsequential, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            // Shared between effects
            std::list<WorldObject*> _unitList;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulduar_stone_grip_cast_target_SpellScript();
        }
};

// 65594 - Cancel Stone Grip
class spell_ulduar_cancel_stone_grip : public SpellScriptLoader
{
    public:
        spell_ulduar_cancel_stone_grip() : SpellScriptLoader("spell_ulduar_cancel_stone_grip") { }

        class spell_ulduar_cancel_stone_gripSpellScript : public SpellScript
        {
            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                if (!target || !target->GetVehicle())
                    return;

                SpellEffIndex effectIndexToCancel = EFFECT_0;
                if (target->GetMap()->Is25ManRaid())
                    effectIndexToCancel = EFFECT_1;

                target->RemoveAura(GetEffectInfo(effectIndexToCancel).CalcValue());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_cancel_stone_gripSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulduar_cancel_stone_gripSpellScript();
        }
};

// 64702 - Squeezed Lifeless
class spell_ulduar_squeezed_lifeless : public SpellScriptLoader
{
    public:
        spell_ulduar_squeezed_lifeless() : SpellScriptLoader("spell_ulduar_squeezed_lifeless") { }

        class spell_ulduar_squeezed_lifeless_SpellScript : public SpellScript
        {
            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->GetTypeId() != TYPEID_PLAYER || !GetHitUnit()->GetVehicle())
                    return;

                //! Proper exit position does not work currently,
                //! See documentation in void Unit::ExitVehicle(Position const* exitPosition)
                Position pos;
                pos.m_positionX = 1756.25f + irand(-3, 3);
                pos.m_positionY = -8.3f + irand(-3, 3);
                pos.m_positionZ = 448.8f;
                pos.SetOrientation(float(M_PI));
                GetHitUnit()->DestroyForNearbyPlayers();
                GetHitUnit()->ExitVehicle(&pos);
                GetHitUnit()->UpdateObjectVisibility(false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_squeezed_lifeless_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ulduar_squeezed_lifeless_SpellScript();
        }
};

// 64224, 64225 - Stone Grip Absorb
class spell_ulduar_stone_grip_absorb : public SpellScriptLoader
{
    public:
        spell_ulduar_stone_grip_absorb() : SpellScriptLoader("spell_ulduar_stone_grip_absorb") { }

        class spell_ulduar_stone_grip_absorb_AuraScript : public AuraScript
        {
            //! This will be called when Right Arm (vehicle) has sustained a specific amount of damage depending on instance mode
            //! What we do here is remove all harmful aura's related and teleport to safe spot.
            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
                    return;

                if (GetOwner()->GetTypeId() != TYPEID_UNIT)
                    return;

                uint32 rubbleStalkerEntry = (GetOwner()->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL ? 33809 : 33942);
                Creature* rubbleStalker = GetOwner()->FindNearestCreature(rubbleStalkerEntry, 200.0f, true);
                if (rubbleStalker)
                    rubbleStalker->CastSpell(rubbleStalker, SPELL_STONE_GRIP_CANCEL, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_absorb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ulduar_stone_grip_absorb_AuraScript();
        }
};

// 62056, 63985 - Stone Grip
class spell_ulduar_stone_grip : public SpellScriptLoader
{
    public:
        spell_ulduar_stone_grip() : SpellScriptLoader("spell_ulduar_stone_grip") { }

        class spell_ulduar_stone_grip_AuraScript : public AuraScript
        {
            void OnRemoveStun(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                GetUnitOwner()->RemoveAurasDueToSpell(aurEff->GetAmount());
            }

            void OnRemoveVehicle(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Position exitPosition;
                exitPosition.m_positionX = 1750.0f;
                exitPosition.m_positionY = -7.5f + frand(-3.0f, 3.0f);
                exitPosition.m_positionZ = 457.9322f;

                // Remove pending passengers before exiting vehicle - might cause an Uninstall
                GetTarget()->GetVehicleKit()->RemovePendingEventsForPassenger(caster);
                caster->_ExitVehicle(&exitPosition);
                caster->RemoveAurasDueToSpell(GetId());

                // Temporarily relocate player to vehicle exit dest serverside to send proper fall movement
                // beats me why blizzard sends these 2 spline packets one after another instantly
                Position oldPos = caster->GetPosition();
                caster->Relocate(exitPosition);
                caster->GetMotionMaster()->MoveFall();
                caster->Relocate(oldPos);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_AuraScript::OnRemoveVehicle, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_AuraScript::OnRemoveStun, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ulduar_stone_grip_AuraScript();
        }
};

// 63720, 64004 - Stone Shout
class spell_kologarn_stone_shout : public SpellScriptLoader
{
    public:
        spell_kologarn_stone_shout() : SpellScriptLoader("spell_kologarn_stone_shout") { }

        class spell_kologarn_stone_shout_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* object) -> bool
                {
                    if (object->GetTypeId() == TYPEID_PLAYER)
                        return false;

                    if (Creature* creature = object->ToCreature())
                        return !creature->IsPet();

                    return true;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_stone_shout_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_kologarn_stone_shout_SpellScript();
        }
};

// 63342 - Focused Eyebeam Summon Trigger
class spell_kologarn_summon_focused_eyebeam : public SpellScriptLoader
{
    public:
        spell_kologarn_summon_focused_eyebeam() : SpellScriptLoader("spell_kologarn_summon_focused_eyebeam") { }

        class spell_kologarn_summon_focused_eyebeam_SpellScript : public SpellScript
        {
            void HandleForceCast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), GetEffectInfo().TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_kologarn_summon_focused_eyebeam_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
                OnEffectHitTarget += SpellEffectFn(spell_kologarn_summon_focused_eyebeam_SpellScript::HandleForceCast, EFFECT_1, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_kologarn_summon_focused_eyebeam_SpellScript();
        }
};

void AddSC_boss_kologarn()
{
    new boss_kologarn();
    new spell_ulduar_rubble_summon();
    new spell_ulduar_squeezed_lifeless();
    new spell_ulduar_cancel_stone_grip();
    new spell_ulduar_stone_grip_cast_target();
    new spell_ulduar_stone_grip_absorb();
    new spell_ulduar_stone_grip();
    new spell_kologarn_stone_shout();
    new spell_kologarn_summon_focused_eyebeam();
}

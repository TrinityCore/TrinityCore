/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"
#include "Vehicle.h"

/* ScriptData
SDName: boss_kologarn
SD%Complete: 80
SDComment: TODO: Achievements, begin/end animations
SDCategory: Ulduar
EndScriptData */

#define SPELL_ARM_DEAD_DAMAGE   RAID_MODE(63629,63979)
#define SPELL_TWO_ARM_SMASH     RAID_MODE(63356,64003)
#define SPELL_ONE_ARM_SMASH     RAID_MODE(63573,64006)
#define SPELL_ARM_SWEEP         RAID_MODE(63766,63983)
#define SPELL_STONE_SHOUT       RAID_MODE(63716,64005)
#define SPELL_PETRIFY_BREATH    RAID_MODE(62030,63980)
#define SPELL_STONE_GRIP        RAID_MODE(62166,63981)
#define SPELL_STONE_GRIP_CANCEL 65594
#define SPELL_SUMMON_RUBBLE     63633
#define SPELL_FALLING_RUBBLE    63821
#define SPELL_ARM_ENTER_VEHICLE 65343
#define SPELL_ARM_ENTER_VISUAL  64753

#define SPELL_SUMMON_FOCUSED_EYEBEAM        63342
#define SPELL_FOCUSED_EYEBEAM_PERIODIC      RAID_MODE(63347,63977)
#define SPELL_FOCUSED_EYEBEAM_VISUAL        63369
#define SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT   63676
#define SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT  63702

#define SPELL_BERSERK           47008 // guess

#define NPC_RUBBLE_STALKER      33809
#define NPC_ARM_SWEEP_STALKER   33661

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
    SAY_AGGRO                                   = -1603230,
    SAY_SLAY_1                                  = -1603231,
    SAY_SLAY_2                                  = -1603232,
    SAY_LEFT_ARM_GONE                           = -1603233,
    SAY_RIGHT_ARM_GONE                          = -1603234,
    SAY_SHOCKWAVE                               = -1603235,
    SAY_GRAB_PLAYER                             = -1603236,
    SAY_DEATH                                   = -1603237,
    SAY_BERSERK                                 = -1603238,
};

enum
{
    ACHIEV_DISARMED_START_EVENT                   = 21687,
};

class boss_kologarn : public CreatureScript
{
public:
    boss_kologarn() : CreatureScript("boss_kologarn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kologarnAI (pCreature);
    }

    struct boss_kologarnAI : public BossAI
    {
        boss_kologarnAI(Creature *pCreature) : BossAI(pCreature, TYPE_KOLOGARN), vehicle(pCreature->GetVehicleKit()),
            left(false), right(false)
        {
            ASSERT(vehicle);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(false);
            Reset();
        }

        Vehicle *vehicle;
        bool left, right;
        uint64 eyebeamTarget;

        void EnterCombat(Unit * who)
        {
            DoScriptText(SAY_AGGRO, me);
            
            events.ScheduleEvent(EVENT_MELEE_CHECK, 6000);
            events.ScheduleEvent(EVENT_SMASH, 5000);
            events.ScheduleEvent(EVENT_SWEEP, 19000);
            events.ScheduleEvent(EVENT_STONE_GRIP, 25000);
            events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, 21000);
            events.ScheduleEvent(EVENT_ENRAGE, 600000);

            Unit* arm = NULL;
            if (arm = vehicle->GetPassenger(0))
                arm->Attack(who, true);
            if (arm = vehicle->GetPassenger(1))
                arm->Attack(who, true);

            _EnterCombat();
        }

        void Reset()
        {
            _Reset();

            if (Creature* arm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_LEFT_ARM) : 0))
                RespawnArm(arm);
            if (Creature* arm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_RIGHT_ARM) : 0))
                RespawnArm(arm);

            eyebeamTarget = 0;            
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
        }

        void KilledUnit(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void PassengerBoarded(Unit *who, int8 /*seatId*/, bool apply)
        {
            if (who->GetEntry() == NPC_LEFT_ARM)
            {
                left = apply;
                if (!apply)
                {
                    DoScriptText(SAY_LEFT_ARM_GONE, me);
                    events.ScheduleEvent(EVENT_RESPAWN_LEFT_ARM, 40000);
                }
                else
                    instance->SetData64(DATA_LEFT_ARM, who->GetGUID());
            }

            else if (who->GetEntry() == NPC_RIGHT_ARM)
            {
                right = apply;
                if (!apply)
                {
                    DoScriptText(SAY_RIGHT_ARM_GONE, me);
                    events.ScheduleEvent(EVENT_RESPAWN_RIGHT_ARM, 40000);
                }
                else
                    instance->SetData64(DATA_RIGHT_ARM, who->GetGUID());
            }

            if (!apply)
            {
                who->CastSpell(me, SPELL_ARM_DEAD_DAMAGE, true);
                who->GetMotionMaster()->MoveTargetedHome();
                
                if (Creature* rubbleStalker = me->FindNearestCreature(NPC_RUBBLE_STALKER, 20.0f))
                {
                    if (rubbleStalker)
                    {
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_FALLING_RUBBLE, true);
                        rubbleStalker->CastSpell(rubbleStalker, SPELL_SUMMON_RUBBLE, true);
                    }
                }

                if (!right && !left)
                    events.ScheduleEvent(EVENT_STONE_SHOUT, 5000);

                if (instance)
                    instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
            }
            else
                events.CancelEvent(EVENT_STONE_SHOUT);
        }

        void JustSummoned(Creature *summon)
        {
            switch (summon->GetEntry())
            {
                case NPC_FOCUSED_EYEBEAM:
                    summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT, true);
                    break;
                case NPC_FOCUSED_EYEBEAM_RIGHT:
                    summon->CastSpell(me, SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT, true);
                    break;
                default:
                    return;
            }

            summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_PERIODIC, true);
            summon->CastSpell(summon, SPELL_FOCUSED_EYEBEAM_VISUAL, true);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetFlag(UNIT_FIELD_ATTACK_POWER, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            // One of the above spells is a channeled spell, we need to clear this unit state for MoveChase to work
            summon->ClearUnitState(UNIT_STAT_CASTING);  

            // Victim gets 67351
            if (eyebeamTarget)
            {
                if (Unit* target = Unit::GetUnit(*summon, eyebeamTarget))
                {
                    summon->Attack(target, false);
                    summon->GetMotionMaster()->MoveChase(target);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            switch (events.GetEvent())
            {
                case EVENT_MELEE_CHECK:
                    if (!me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(SPELL_PETRIFY_BREATH);
                    events.RepeatEvent(1000);
                    break;
                case EVENT_SWEEP:
                    DoCast(me->FindNearestCreature(NPC_ARM_SWEEP_STALKER, 500.0f, true), SPELL_ARM_SWEEP, true);
                    events.RepeatEvent(25000);
                    break;
                case EVENT_SMASH:
                    if (left && right)
                        DoCastVictim(SPELL_TWO_ARM_SMASH);
                    else if (left || right)
                        DoCastVictim(SPELL_ONE_ARM_SMASH);
                    events.RepeatEvent(15000);
                    break;
                case EVENT_STONE_SHOUT:
                    DoCast(SPELL_STONE_SHOUT);
                    events.RepeatEvent(2000);
                    break;
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    DoScriptText(SAY_BERSERK, me);
                    events.CancelEvent(EVENT_ENRAGE);
                    break;
                case EVENT_RESPAWN_LEFT_ARM:
                {
                    if (Creature* arm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_LEFT_ARM) : 0))
                        RespawnArm(arm->ToCreature());
                    events.CancelEvent(EVENT_RESPAWN_LEFT_ARM);                   
                    break;
                }
                case EVENT_RESPAWN_RIGHT_ARM:
                {
                    if (Creature* arm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_RIGHT_ARM) : 0))
                        RespawnArm(arm->ToCreature());       
                    events.CancelEvent(EVENT_RESPAWN_RIGHT_ARM);             
                    break;
                }
                case EVENT_STONE_GRIP:
                {
                    if (right)
                    {
                        std::list<Unit*> targetList;
                        std::list<Unit*>::const_iterator itr;
                        SelectTargetList(targetList, RAID_MODE(1, 3), SELECT_TARGET_RANDOM, 0.0f, true);
                        for (itr = targetList.begin(); itr != targetList.end(); ++itr)
                        {
                            DoCast((*itr), SPELL_STONE_GRIP, true);
                            /* 10 man: */
                            // Cast 62056 -> HandleAuraLinked (64224) -> Apply 64224 -> Absorb damage
                            //            -> Apply Stun with basepoints 64290
                            // Cast 64290 -> Trigger spell (64708) Squeezed Lifeless
                            //            -> Periodic damage 
                            // Cast 63962 -> Visual
                        }
                        DoScriptText(SAY_GRAB_PLAYER, me);
                    }
                    events.RepeatEvent(25000);
                }
                break;
                case EVENT_FOCUSED_EYEBEAM:
                    Unit* eyebeamTargetUnit = SelectTarget(SELECT_TARGET_RANDOM);
                    if (!eyebeamTargetUnit)
                        return;

                    eyebeamTarget = eyebeamTargetUnit->GetGUID();
                    DoCast(SPELL_SUMMON_FOCUSED_EYEBEAM);
                    events.RepeatEvent(urand(15000, 35000));
                    break;
            }

            DoMeleeAttackIfReady();
        }

        void RespawnArm(Creature* arm)
        {
            if (!arm->isAlive())
                arm->Respawn();

            arm->EnterVehicle(vehicle);
            arm->CastSpell(arm, SPELL_ARM_ENTER_VISUAL, true);
        }
    };
};

class spell_ulduar_rubble_summon : public SpellScriptLoader
{
public:
    spell_ulduar_rubble_summon() : SpellScriptLoader("spell_ulduar_rubble_summon") { }

    class spell_ulduar_rubble_summonSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ulduar_rubble_summonSpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            uint32 spellId = GetEffectValue();
            for (uint8 i = 0; i < 5; ++i)
                caster->CastSpell(caster, spellId, true);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_ulduar_rubble_summonSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_ulduar_rubble_summonSpellScript();
    }
};

class spell_ulduar_cancel_stone_grip : public SpellScriptLoader
{
public:
    spell_ulduar_cancel_stone_grip() : SpellScriptLoader("spell_ulduar_cancel_stone_grip") { }

    class spell_ulduar_cancel_stone_gripSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ulduar_cancel_stone_gripSpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* target = this->GetHitPlayer();
            if (!target)
                return;

            switch (target->GetMap()->GetDifficulty())
            {
                case RAID_DIFFICULTY_10MAN_NORMAL:
                    target->RemoveAura(SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_0));
                    break;
                case RAID_DIFFICULTY_25MAN_NORMAL:
                    target->RemoveAura(SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_1));
                    break;
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_ulduar_cancel_stone_gripSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_ulduar_cancel_stone_gripSpellScript();
    }
};

class spell_ulduar_stone_grip_absorb : public SpellScriptLoader
{
public:
    spell_ulduar_stone_grip_absorb() : SpellScriptLoader("spell_ulduar_stone_grip_absorb") { }

    class spell_ulduar_stone_grip_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ulduar_stone_grip_absorb_AuraScript);

        //! This will be called when Right Arm (vehicle) has sustained a specific amount of damage depending on instance mode
        //! What we do here is remove all harmful aura's related and teleport to safe spot.
        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetOwner()->ToCreature())
                return;

            uint32 rubbleStalkerEntry = (GetOwner()->GetMap()->GetDifficulty() == DUNGEON_DIFFICULTY_NORMAL ? 33809 : 33942);
            Creature* rubbleStalker = GetOwner()->FindNearestCreature(rubbleStalkerEntry, 200.0f, true);
            if (rubbleStalker)
                rubbleStalker->CastSpell(rubbleStalker, SPELL_STONE_GRIP_CANCEL, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_absorb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_ulduar_stone_grip_absorb_AuraScript();
    }
};

class spell_ulduar_stone_grip : public SpellScriptLoader
{
public:
    spell_ulduar_stone_grip() : SpellScriptLoader("spell_ulduar_stone_grip") { }

    class spell_ulduar_stone_grip_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ulduar_stone_grip_AuraScript);

        void OnRemoveStun(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            GetOwner()->ToUnit()->RemoveAurasDueToSpell(SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), EFFECT_2));
            // Spellsystem doesn't recognize EFFECT_0 as actionable effect on dispel for some reason, manually do it here
            GetOwner()->ToUnit()->ExitVehicle();
            GetOwner()->ToUnit()->NearTeleportTo(1756.25f + irand(-3, 3), -8.3f + irand(-3, 3), 448.8f, 3.62f);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_AuraScript::OnRemoveStun, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_ulduar_stone_grip_AuraScript();
    }
};

void AddSC_boss_kologarn()
{
    new boss_kologarn();
    new spell_ulduar_rubble_summon();
    new spell_ulduar_cancel_stone_grip();
    new spell_ulduar_stone_grip_absorb();
    new spell_ulduar_stone_grip();
}

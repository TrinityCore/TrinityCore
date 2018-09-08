/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"
#include "Vehicle.h"

enum KologarnSpells
{
    //Kologarn
    SPELL_ARM_DEAD_DAMAGE              = 63629,
    SPELL_TWO_ARM_SMASH                = 63356,
    SPELL_ONE_ARM_SMASH                = 63573,
    SPELL_ARM_SWEEP                    = 63766,
    SPELL_STONE_SHOUT                  = 63716,
    SPELL_PETRIFY_BREATH               = 62030,
    SPELL_SUMMON_FOCUSED_EYEBEAM       = 63342,
    SPELL_INSTAKILL_KOLOGARN_ARM       = 63628,
    SPELL_KOLOGARN_PACIFY              = 63726,
    SPELL_BERSERK                      = 47008,  // guess
    //Arms
    SPELL_STONE_GRIP                   = 62166,
    SPELL_STONE_GRIP_CANCEL            = 65594,
    SPELL_STONE_GRIP_CONTROL_1         = 62056,
    SPELL_STONE_GRIP_CONTROL_2         = 63985,
    SPELL_ARM_RESPAWN_VISUAL           = 64753,
    SPELL_SUMMON_RUBBLE                = 63633,
    SPELL_FALLING_RUBBLE               = 63821,
    //Eyebeam
    SPELL_FOCUSED_EYEBEAM_PERIODIC     = 63347,
    SPELL_FOCUSED_EYEBEAM_VISUAL       = 63369,
    SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT  = 63676,
    SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT = 63702,
    SPELL_FOCUSED_EYEBEAM_VISUAL_DUMMY = 67351
};

enum KologarnNPCs
{
    NPC_RUBBLE_STALKER = 33809,
    NPC_PIT_KILL_BUNNY = 33742
};

enum KologarnEvents
{
    EVENT_MELEE_CHECK = 1,
    EVENT_SMASH,
    EVENT_SWEEP,
    EVENT_STONE_SHOUT,
    EVENT_STONE_GRIP,
    EVENT_FOCUSED_EYEBEAM,
    EVENT_RESPAWN_LEFT_ARM,
    EVENT_RESPAWN_RIGHT_ARM,
    EVENT_ENRAGE
};

enum Yells
{
    SAY_AGGRO          = 0,
    SAY_SLAY           = 1,
    SAY_LEFT_ARM_GONE  = 2,
    SAY_RIGHT_ARM_GONE = 3,
    SAY_SHOCKWAVE      = 4,
    SAY_GRAB_PLAYER    = 5,
    SAY_DEATH          = 6,
    SAY_BERSERK        = 7,
    EMOTE_STONE_GRIP   = 8
};

enum KologarnAchievements
{
    DATA_IF_LOOKS_COULD_KILL = 29552956,
    DATA_WITH_OPEN_ARMS      = 29512952,
    DATA_RUBBLE_AND_ROLL     = 29592960,
};

Position const KologarnSpawnPos = { 1797.151f, -24.40278f, 448.7409f, 3.193953f };

struct boss_kologarn : public BossAI
{
    boss_kologarn(Creature* creature) : BossAI(creature, BOSS_KOLOGARN), _leftArm(false), _rightArm(false), _eyebeam(true), _openArms(true), _rubbleCounter(0)
    {
        SetCombatMovement(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_MELEE_CHECK, 6s);
        events.ScheduleEvent(EVENT_SMASH, 5s);
        events.ScheduleEvent(EVENT_SWEEP, 19s);
        events.ScheduleEvent(EVENT_STONE_GRIP, 25s);
        events.ScheduleEvent(EVENT_FOCUSED_EYEBEAM, 21s);
        events.ScheduleEvent(EVENT_ENRAGE, 10min);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        DoCastSelf(SPELL_INSTAKILL_KOLOGARN_ARM, true);
        DoCastSelf(SPELL_KOLOGARN_PACIFY);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetCorpseDelay(604800); // Prevent corpse from despawning.
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SetBossState(BOSS_KOLOGARN, FAIL);
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        switch (summon->GetEntry())
        {
            case NPC_LEFT_ARM:
                _leftArm = true;
                break;
            case NPC_RIGHT_ARM:
                _rightArm = true;
                break;
            case NPC_RUBBLE:
                ++_rubbleCounter;
                return;
            default:
                return;
        }

        summon->CastSpell(summon, SPELL_ARM_RESPAWN_VISUAL, true);
        events.CancelEvent(EVENT_STONE_SHOUT);
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        if (killer == me)
            return;

        bool isLeft = false;
        switch (summon->GetEntry())
        {
            case NPC_LEFT_ARM:
                _leftArm = false;
                isLeft = true;
                Talk(SAY_LEFT_ARM_GONE);
                events.ScheduleEvent(EVENT_RESPAWN_LEFT_ARM, 40s);
                break;
            case NPC_RIGHT_ARM:
                _rightArm = false;
                Talk(SAY_RIGHT_ARM_GONE);
                events.ScheduleEvent(EVENT_RESPAWN_RIGHT_ARM, 40s);
                break;
            default:
                return;
        }

        _openArms = false;
        summon->CastSpell(me, SPELL_ARM_DEAD_DAMAGE, true);

        std::list<Creature*> rubbleStalkers;
        summon->GetCreatureListWithEntryInGrid(rubbleStalkers, NPC_RUBBLE_STALKER);
        for (Creature* rubbleStalker : rubbleStalkers)
        {
            if ((isLeft && rubbleStalker->GetPositionY() > -30.0f) || (!isLeft && rubbleStalker->GetPositionY() < -30.0f))
                continue;

            rubbleStalker->CastSpell(rubbleStalker, SPELL_FALLING_RUBBLE, true);
            rubbleStalker->CastSpell(rubbleStalker, SPELL_SUMMON_RUBBLE, true);
        }

        if (!_rightArm && !_leftArm)
            events.ScheduleEvent(EVENT_STONE_SHOUT, 5s);

        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, CRITERIA_DISARMED);
    }

    void SetData(uint32 type, uint32 /*data*/) override
    {
        if (type == DATA_IF_LOOKS_COULD_KILL)
            _eyebeam = false;
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_IF_LOOKS_COULD_KILL:
                return _eyebeam;
            case DATA_WITH_OPEN_ARMS:
                return _openArms;
            case DATA_RUBBLE_AND_ROLL:
                return _rubbleCounter;
            default:
                return 0;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_MELEE_CHECK:
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                    DoCastAOE(SPELL_PETRIFY_BREATH);
                events.Repeat(1s);
                break;
            case EVENT_SWEEP:
                if (_leftArm)
                    DoCastAOE(SPELL_ARM_SWEEP, true);
                events.Repeat(25s);
                break;
            case EVENT_SMASH:
                if (_leftArm && _rightArm)
                    DoCastVictim(SPELL_TWO_ARM_SMASH);
                else if (_leftArm || _rightArm)
                    DoCastVictim(SPELL_ONE_ARM_SMASH);
                events.Repeat(15s);
                break;
            case EVENT_STONE_SHOUT:
                DoCastAOE(SPELL_STONE_SHOUT);
                events.Repeat(2s);
                break;
            case EVENT_ENRAGE:
                DoCastSelf(SPELL_BERSERK);
                Talk(SAY_BERSERK);
                break;
            case EVENT_RESPAWN_LEFT_ARM:
                if (Vehicle* vehicle = me->GetVehicleKit())
                    vehicle->InstallAccessory(NPC_LEFT_ARM, 0, true, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    break;
            case EVENT_RESPAWN_RIGHT_ARM:
                if (Vehicle* vehicle = me->GetVehicleKit())
                    vehicle->InstallAccessory(NPC_RIGHT_ARM, 1, true, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                break;
            case EVENT_STONE_GRIP:
                if (_rightArm)
                    DoCastAOE(SPELL_STONE_GRIP);
                events.Repeat(25s);
                break;
            case EVENT_FOCUSED_EYEBEAM:
                DoCastSelf(SPELL_SUMMON_FOCUSED_EYEBEAM, true);
                events.Repeat(15s, 35s);
                break;
        }
    }

private:
    bool _leftArm;
    bool _rightArm;
    bool _eyebeam;
    bool _openArms;
    uint32 _rubbleCounter;
};

struct npc_focused_eyebeam : public ScriptedAI
{
    npc_focused_eyebeam(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        if (me->GetEntry() == NPC_FOCUSED_EYEBEAM)
            DoCastSelf(SPELL_FOCUSED_EYEBEAM_VISUAL_LEFT, true);
        else
            DoCastSelf(SPELL_FOCUSED_EYEBEAM_VISUAL_RIGHT, true);

        DoCastSelf(SPELL_FOCUSED_EYEBEAM_PERIODIC, true);

        if (Creature* kologarn = me->GetInstanceScript()->GetCreature(BOSS_KOLOGARN))
            kologarn->AI()->JustSummoned(me);

        _scheduler.Schedule(1s, [this](TaskContext /*context*/)
        {
            if (me->IsSummon())
                if (Unit* target = me->ToTempSummon()->GetSummoner())
                {
                    me->GetThreatManager().AddThreat(target, 50000000.0f);
                    me->Attack(target, false);
                    me->GetMotionMaster()->MoveChase(target);
                }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 63633 - Summon Rubble
class spell_ulduar_rubble_summon : public SpellScript
{
    PrepareSpellScript(spell_ulduar_rubble_summon);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        ObjectGuid originalCaster = caster->GetInstanceScript() ? caster->GetInstanceScript()->GetObjectGuid(BOSS_KOLOGARN) : ObjectGuid::Empty;
        uint32 spellId = GetEffectValue();
        for (uint8 i = 0; i < 5; ++i)
            caster->CastSpell(caster, spellId, originalCaster);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ulduar_rubble_summon::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
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

            if (target->ToUnit() && target->ToUnit()->HasAura(SPELL_FOCUSED_EYEBEAM_VISUAL_DUMMY))
                return true;

            return false;
        }

        Creature* _me;
        Unit const* _victim;
};

// 62166 63981 - Stone Grip
class spell_ulduar_stone_grip_cast_target : public SpellScript
{
    PrepareSpellScript(spell_ulduar_stone_grip_cast_target);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void FilterTargetsInitial(std::list<WorldObject*>& unitList)
    {
        Creature* caster = GetCaster()->ToCreature();
        // Remove "main tank" and non-player targets
        unitList.remove_if(StoneGripTargetSelector(caster, caster->GetThreatManager().GetCurrentVictim()));
        // Maximum affected targets per difficulty mode
        uint32 maxTargets = 1;
        if (GetSpellInfo()->Id == 63981)
            maxTargets = 3;

        Trinity::Containers::RandomResize(unitList, maxTargets);
        if (!unitList.empty())
        {
            caster->AI()->Talk(SAY_GRAB_PLAYER);
            caster->AI()->Talk(EMOTE_STONE_GRIP);
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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target::FillTargetsSubsequential, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ulduar_stone_grip_cast_target::FillTargetsSubsequential, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }

private:
    // Shared between effects
    std::list<WorldObject*> _unitList;
};

// 65594 - Cancel Stone Grip
class spell_ulduar_cancel_stone_grip : public SpellScript
{
    PrepareSpellScript(spell_ulduar_cancel_stone_grip);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (!target || !target->GetVehicle())
            return;

        switch (target->GetMap()->GetDifficulty())
        {
            case RAID_DIFFICULTY_10MAN_NORMAL:
                target->RemoveAura(GetSpellInfo()->Effects[EFFECT_0].CalcValue());
                break;
            case RAID_DIFFICULTY_25MAN_NORMAL:
                target->RemoveAura(GetSpellInfo()->Effects[EFFECT_1].CalcValue());
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ulduar_cancel_stone_grip::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 64702 - Squeezed Lifeless
class spell_ulduar_squeezed_lifeless : public SpellScript
{
    PrepareSpellScript(spell_ulduar_squeezed_lifeless);

    void HandleInstaKill(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitPlayer() || !GetHitPlayer()->GetVehicle())
            return;

        //! Proper exit position does not work currently,
        //! See documentation in void Unit::ExitVehicle(Position const* exitPosition)
        Position pos;
        pos.m_positionX = 1756.25f + irand(-3, 3);
        pos.m_positionY = -8.3f + irand(-3, 3);
        pos.m_positionZ = 448.8f;
        pos.SetOrientation(float(M_PI));
        GetHitPlayer()->DestroyForNearbyPlayers();
        GetHitPlayer()->ExitVehicle(&pos);
        GetHitPlayer()->UpdateObjectVisibility(false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ulduar_squeezed_lifeless::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
    }
};

// 64224 64225 - Stone Grip Absorb
class spell_ulduar_stone_grip_absorb : public AuraScript
{
    PrepareAuraScript(spell_ulduar_stone_grip_absorb);

    //! This will be called when Right Arm (vehicle) has sustained a specific amount of damage depending on instance mode
    //! What we do here is remove all harmful aura's related and teleport to safe spot.
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (!GetOwner()->ToCreature())
            return;

        uint32 rubbleStalkerEntry = (GetOwner()->GetMap()->GetDifficulty() == DUNGEON_DIFFICULTY_NORMAL ? 33809 : 33942);
        Creature* rubbleStalker = GetOwner()->FindNearestCreature(rubbleStalkerEntry, 200.0f, true);
        if (rubbleStalker)
            rubbleStalker->CastSpell(rubbleStalker, SPELL_STONE_GRIP_CANCEL, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip_absorb::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 62056 63985 - Stone Grip
class spell_ulduar_stone_grip : public AuraScript
{
    PrepareAuraScript(spell_ulduar_stone_grip);

    void OnRemoveStun(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Player* owner = GetTarget()->ToPlayer())
            owner->RemoveAurasDueToSpell(aurEff->GetAmount());
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
        OnEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip::OnRemoveVehicle, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ulduar_stone_grip::OnRemoveStun, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63720 64004 - Stone Shout
class spell_kologarn_stone_shout : public SpellScript
{
    PrepareSpellScript(spell_kologarn_stone_shout);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if(PlayerOrPetCheck());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_stone_shout::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 63342 Focused Eyebeam Summon Trigger
class spell_kologarn_focused_eyebeam_summon_trigger : public SpellScript
{
    PrepareSpellScript(spell_kologarn_focused_eyebeam_summon_trigger);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void FilterTargetsInitial(std::list<WorldObject*>& targets)
    {
        targets.clear();
        Unit* target = GetCaster()->ToCreature()->AI()->SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, [](Unit* target) -> bool
        {
            return !target->HasAura(SPELL_STONE_GRIP_CONTROL_1) && !target->HasAura(SPELL_STONE_GRIP_CONTROL_2);
        });
        if (!target)
            return;

        targets.push_back(target);
        _targets = targets;
    }

    void FillTargetsSubsequential(std::list<WorldObject*>& targets)
    {
        targets = _targets;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_focused_eyebeam_summon_trigger::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_focused_eyebeam_summon_trigger::FillTargetsSubsequential, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kologarn_focused_eyebeam_summon_trigger::FillTargetsSubsequential, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }

private:
    std::list<WorldObject*> _targets;
};

// 63346 63976 - Focused Eyebeam
class spell_kologarn_focused_eyebeam_damage : public SpellScript
{
    PrepareSpellScript(spell_kologarn_focused_eyebeam_damage);

    void CheckHit()
    {
        if (!GetHitPlayer())
            return;

        if (InstanceScript* instance = GetHitPlayer()->GetInstanceScript())
            if (Creature* kologarn = instance->GetCreature(BOSS_KOLOGARN))
                kologarn->AI()->SetData(DATA_IF_LOOKS_COULD_KILL, 1);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_kologarn_focused_eyebeam_damage::CheckHit);
    }
};

class achievement_if_looks_could_kill : public AchievementCriteriaScript
{
    public:
        achievement_if_looks_could_kill() : AchievementCriteriaScript("achievement_if_looks_could_kill") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_IF_LOOKS_COULD_KILL);
        }
};

class achievement_rubble_and_roll : public AchievementCriteriaScript
{
public:
    achievement_rubble_and_roll() : AchievementCriteriaScript("achievement_rubble_and_roll") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        return target && target->GetAI()->GetData(DATA_RUBBLE_AND_ROLL) >= 25;
    }
};

class achievement_with_open_arms : public AchievementCriteriaScript
{
public:
    achievement_with_open_arms() : AchievementCriteriaScript("achievement_with_open_arms") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        return target && target->GetAI()->GetData(DATA_WITH_OPEN_ARMS);
    }
};

class at_kologarn : public AreaTriggerScript
{
    public:
        at_kologarn() : AreaTriggerScript("at_kologarn") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || player->IsGameMaster())
                return true;

            if (!instance->GetCreature(BOSS_KOLOGARN) && instance->GetBossState(BOSS_KOLOGARN) != DONE)
                player->GetMap()->SummonCreature(NPC_KOLOGARN, KologarnSpawnPos);

            return true;
        }
};

class at_kologarn_pit : public AreaTriggerScript
{
    public:
        at_kologarn_pit() : AreaTriggerScript("at_kologarn_pit") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (player->IsGameMaster())
                return true;

            if (Creature* pitKillBunny = player->FindNearestCreature(NPC_PIT_KILL_BUNNY, 150.0f))
                Unit::Kill(pitKillBunny, player);

            return true;
        }
};

void AddSC_boss_kologarn()
{
    RegisterUlduarCreatureAI(boss_kologarn);
    RegisterUlduarCreatureAI(npc_focused_eyebeam);
    RegisterSpellScript(spell_ulduar_rubble_summon);
    RegisterSpellScript(spell_ulduar_squeezed_lifeless);
    RegisterSpellScript(spell_ulduar_cancel_stone_grip);
    RegisterSpellScript(spell_ulduar_stone_grip_cast_target);
    RegisterAuraScript(spell_ulduar_stone_grip_absorb);
    RegisterAuraScript(spell_ulduar_stone_grip);
    RegisterSpellScript(spell_kologarn_stone_shout);
    RegisterSpellScript(spell_kologarn_focused_eyebeam_summon_trigger);
    RegisterSpellScript(spell_kologarn_focused_eyebeam_damage);
    new achievement_if_looks_could_kill();
    new achievement_rubble_and_roll();
    new achievement_with_open_arms();
    new at_kologarn();
    new at_kologarn_pit();
}

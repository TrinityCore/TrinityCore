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

/*
 * Everything related to Flame Quills requires sniff verification
 * When moving to triggers, A'lar shouldn't move to exact trigger's position (positions in sniffs are always different)
 * Combat timers requires to be revisited
 * If summoned not on platform, embers should be summoned on the floor, not fall on the floor
 * SPELL_ASHTONGUE_RUSE_MASTER doesn't appear in sniffs despite it's an aura. Maybe it was a wrong decision to use it
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "the_eye.h"

enum AlarSpells
{
    // Phase 1
    SPELL_SUMMON_PHOENIX_ADDS_1  = 41824,
    SPELL_FLAME_QUILLS           = 34229,

    // Phase 1 & 2
    SPELL_FLAME_BUFFET           = 34121,

    // Transition
    SPELL_CLEAR_ALL_DEBUFFS      = 34098,
    SPELL_EMBER_BLAST_INVIS      = 34341,
    SPELL_FLIGHT_MODE            = 31514,
    SPELL_REBIRTH                = 34342,

    // Phase 2
    SPELL_SUMMON_FLAME_RING      = 29218,
    SPELL_MELT_ARMOR             = 35410,
    SPELL_CHARGE                 = 35412,
    SPELL_BERSERK                = 26662,

    // Phase 2: Dive Bomb
    SPELL_DIVE_BOMB_VISUAL       = 35367,
    SPELL_DIVE_BOMB              = 35181,
    SPELL_REBIRTH_2              = 35369,
    SPELL_SUMMON_PHOENIX_ADDS_2  = 39110,

    // Ember of Al'ar
    SPELL_EMBER_BLAST            = 34133,
    SPELL_EMBER_BLAST_DAMAGE     = 41910,

    // Flame Patch
    SPELL_FLAME_PATCH_PERIODIC   = 35380,

    // Ruse of the Ashtongue
    SPELL_ASHTONGUE_RUSE_DUMMY   = 39527,
    SPELL_ASHTONGUE_RUSE_MASTER  = 39555,
    SPELL_ASHTONGUE_RUSE_CREDIT  = 39701
};

enum AlarEvents
{
    // Phase 1
    EVENT_MOVE_TO_PLATFORM       = 1,
    EVENT_FLAME_QUILLS,

    // Phase 1 & 2
    EVENT_FLAME_BUFFET,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,
    EVENT_TRANSITION_3,
    EVENT_TRANSITION_4,
    EVENT_TRANSITION_5,

    // Phase 2
    EVENT_FLAME_RING,
    EVENT_MELT_ARMOR,
    EVENT_CHARGE_ALAR,
    EVENT_BERSERK,

    // Phase 2: Dive Bomb
    EVENT_DIVE_BOMB_1,
    EVENT_DIVE_BOMB_2,
    EVENT_DIVE_BOMB_3,
    EVENT_DIVE_BOMB_4,
    EVENT_DIVE_BOMB_5,
    EVENT_DIVE_BOMB_6,
    EVENT_DIVE_BOMB_7
};

enum AlarPoints
{
    POINT_PLATFORM               = 0,
    POINT_CENTER                 = 1,
    POINT_RESSURRECTION          = 2,
    POINT_DIVE_BOMB              = 3
};

enum AlarActions
{
    ACTION_FLAME_QUILLS_END      = 0
};

enum AlarMisc
{
    MODEL_INVISIBLE              = 14501
};

static constexpr std::array<std::string_view, 4> AlarPlatformTrigger =
{
    "AlarPlatformTrigger1",
    "AlarPlatformTrigger2",
    "AlarPlatformTrigger3",
    "AlarPlatformTrigger4"
};

static constexpr std::string_view CenterTriggerStringId = "AlarCenterTrigger";

static constexpr std::array<uint32, 24> FlameQuillsSpells =
{
    34269,
    34270,
    34271,
    34272,
    34273,
    34274,
    34275,
    34276,
    34277,
    34278,
    34279,
    34280,
    34281,
    34282,
    34283,
    34284,
    34285,
    34286,
    34287,
    34288,
    34289,
    34314,
    34315,
    34316
};

Position const AlarRessurrectionPosition = { 333.589f, -0.768249f, -2.38949f };

// 19514 - Al'ar
struct boss_alar : public BossAI
{
    boss_alar(Creature* creature) : BossAI(creature, DATA_ALAR),
        _isFirstPhase(true), _isInTransition(false), _isFirstPlatform(true), _shouldSpawnEmber(false), _currentPlatform(0) { }

    void JustAppeared() override
    {
        me->SetDisableGravity(true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        me->GetMotionMaster()->MoveIdle();
        me->SetReactState(REACT_PASSIVE);

        events.ScheduleEvent(EVENT_MOVE_TO_PLATFORM, 0s);
    }

    void DamageTaken(Unit* /*doneBy*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && _isFirstPhase)
        {
            damage = me->GetHealth() - 1;

            if (_isInTransition)
                return;

            _isInTransition = true;

            events.Reset();
            events.ScheduleEvent(EVENT_TRANSITION_1, 0s);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case POINT_PLATFORM:
                    events.ScheduleEvent(EVENT_FLAME_BUFFET, 1s);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case POINT_CENTER:
                    events.ScheduleEvent(EVENT_FLAME_QUILLS, 0s);
                    break;
                case POINT_DIVE_BOMB:
                    events.ScheduleEvent(EVENT_DIVE_BOMB_2, 2400ms);
                    break;
                default:
                    break;
            }
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DIVE_BOMB_VISUAL)
            events.ScheduleEvent(EVENT_DIVE_BOMB_3, 0s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        /// !HACK: Creature is immune to fire spells, we set full health manually
        if (spell->Id == SPELL_REBIRTH)
            me->SetFullHealth();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_FLAME_QUILLS_END)
        {
            DoMoveToPlatform();
            events.RescheduleEvent(EVENT_MOVE_TO_PLATFORM, 30s, 40s);
        }
    }

    void DoMoveToPlatform()
    {
        if (Creature* trigger = me->FindNearestCreatureWithOptions(250.0f, { .StringId = AlarPlatformTrigger[_currentPlatform] }))
            me->GetMotionMaster()->MovePoint(POINT_PLATFORM, trigger->GetPositionX(), trigger->GetPositionY(), trigger->GetPositionZ(), false);
    }

    void DoMoveToCenter()
    {
        if (Creature* trigger = me->FindNearestCreatureWithOptions(250.0f, { .StringId = CenterTriggerStringId }))
            me->GetMotionMaster()->MovePoint(POINT_CENTER, trigger->GetPositionX(), trigger->GetPositionY(), trigger->GetPositionZ());
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->DoCastSpellOnPlayers(SPELL_ASHTONGUE_RUSE_MASTER);

        _JustDied();

        /// @todo: Guessed. Needed if boss dies during Dive Bomb. What should happen?
        me->SetDisplayId(me->GetNativeDisplayId());
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
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
                // Phase 1
                case EVENT_MOVE_TO_PLATFORM:
                {
                    // Verified: A'lar can stay on the same platform (even twice in a row), will summon ember in this case
                    // Verified: After Flame Quills A'lar can move to the old platform
                    // Verified: After Flame Quills A'lar can move to the next platform
                    // Not verified: Can he perform more than one Flame Quills in a row? Currently he can

                    // Cancel Flame Buffet so it will be not used during moving
                    events.CancelEvent(EVENT_FLAME_BUFFET);

                    // If encounter just started, only move to the first platform
                    if (_isFirstPlatform)
                    {
                        DoMoveToPlatform();

                        _isFirstPlatform = false;

                        // We are leaving a small chance to stay on the first platform
                        if (roll_chance_i(80))
                            ++_currentPlatform;
                    }
                    else
                    {
                        me->SetControlled(false, UNIT_STATE_ROOT);
                        me->SetDisableGravity(true);
                        me->SetHover(true);
                        me->SetReactState(REACT_PASSIVE);

                        // Else, move either to platform or to center
                        if (roll_chance_i(80))
                        {
                            DoMoveToPlatform();

                            if (_currentPlatform == 3)
                            {
                                // If we are on the last platform, we are leaving a small chance to stay on it
                                if (roll_chance_i(80))
                                    _currentPlatform = 0;
                            }
                            else
                            {
                                // If we are not on the last platform, we leave a small chance to stay on current
                                if (roll_chance_i(80))
                                    ++_currentPlatform;
                            }

                            // If we are moving to the next platform or stay on the same, summon ember
                            _shouldSpawnEmber = true;
                        }
                        else
                        {
                            DoMoveToCenter();

                            // If we are moving to the center, do not summon ember
                            _shouldSpawnEmber = false;
                        }
                    }

                    if (_shouldSpawnEmber)
                        DoCastSelf(SPELL_SUMMON_PHOENIX_ADDS_1);

                    events.Repeat(30s, 40s);
                    break;
                }
                case EVENT_FLAME_QUILLS:
                    DoCastSelf(SPELL_FLAME_QUILLS);
                    break;

                // Phase 1 & 2
                case EVENT_FLAME_BUFFET:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastSelf(SPELL_FLAME_BUFFET);
                    events.Repeat(2400ms);
                    break;

                // Transition
                case EVENT_TRANSITION_1:
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    /// @todo: This should not be called. Clear All Debuffs should remove all debuffs. Does it work? Remove this
                    me->RemoveAllAuras();
                    /// @todo: Guessed, this is positive aura, will be not removed by Clear All Debuffs. What should happen if Flame Quills is active here?
                    me->RemoveAurasDueToSpell(SPELL_FLAME_QUILLS);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_EMBER_BLAST_INVIS);
                    /// !HACK: Creature is immune to fire spells, we make it invisible without SPELL_EMBER_BLAST_INVIS
                    me->SetVisible(false);
                    events.ScheduleEvent(EVENT_TRANSITION_2, 5s);
                    break;
                case EVENT_TRANSITION_2:
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    DoCastSelf(SPELL_FLIGHT_MODE);
                    me->GetMotionMaster()->MovePoint(POINT_RESSURRECTION, AlarRessurrectionPosition);
                    events.ScheduleEvent(EVENT_TRANSITION_3, 10s);
                    break;
                case EVENT_TRANSITION_3:
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    /// !HACK: Creature is immune to fire spells, we make it visible manually
                    me->SetVisible(true);
                    me->RemoveAurasDueToSpell(SPELL_EMBER_BLAST_INVIS);
                    events.ScheduleEvent(EVENT_TRANSITION_4, 1s);
                    break;
                case EVENT_TRANSITION_4:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    DoCastSelf(SPELL_REBIRTH);
                    events.ScheduleEvent(EVENT_TRANSITION_5, 3500ms);
                    break;
                case EVENT_TRANSITION_5:
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    ResetThreatList();
                    DoZoneInCombat();

                    _isFirstPhase = false;

                    events.ScheduleEvent(EVENT_FLAME_BUFFET, 1s);
                    events.ScheduleEvent(EVENT_FLAME_RING, 20s, 30s);
                    events.ScheduleEvent(EVENT_MELT_ARMOR, 60s);
                    events.ScheduleEvent(EVENT_CHARGE_ALAR, 25s, 40s);
                    events.ScheduleEvent(EVENT_BERSERK, 10min);
                    events.ScheduleEvent(EVENT_DIVE_BOMB_1, 30s, 40s);
                    break;

                // Phase 2
                case EVENT_FLAME_RING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_SUMMON_FLAME_RING);
                    events.Repeat(30s, 45s);
                    break;
                case EVENT_MELT_ARMOR:
                    DoCastVictim(SPELL_MELT_ARMOR);
                    events.Repeat(60s);
                    break;
                case EVENT_CHARGE_ALAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CHARGE);
                    events.Repeat(30s, 35s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;

                // Phase 2: Dive Bomb
                case EVENT_DIVE_BOMB_1:
                    me->SetReactState(REACT_PASSIVE);

                    events.CancelEvent(EVENT_FLAME_BUFFET);
                    events.RescheduleEvent(EVENT_CHARGE_ALAR, 30s, 35s);

                    me->SetDisableGravity(true);
                    me->SetHover(true);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(250.0f, { .StringId = CenterTriggerStringId }))
                        me->GetMotionMaster()->MovePoint(POINT_DIVE_BOMB, trigger->GetPositionX(), trigger->GetPositionY(), trigger->GetPositionZ());

                    events.Repeat(40s, 45s);
                    break;
                case EVENT_DIVE_BOMB_2:
                    DoCastSelf(SPELL_DIVE_BOMB_VISUAL);
                    break;
                case EVENT_DIVE_BOMB_3:
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetDisplayId(MODEL_INVISIBLE);
                    events.ScheduleEvent(EVENT_DIVE_BOMB_4, 2400ms);
                    break;
                case EVENT_DIVE_BOMB_4:
                    me->RemoveAurasDueToSpell(SPELL_DIVE_BOMB_VISUAL);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                        DoCast(target, SPELL_DIVE_BOMB);
                    }
                    events.ScheduleEvent(EVENT_DIVE_BOMB_5, 1200ms);
                    break;
                case EVENT_DIVE_BOMB_5:
                    DoCastSelf(SPELL_SUMMON_PHOENIX_ADDS_2);
                    events.ScheduleEvent(EVENT_DIVE_BOMB_6, 2400ms);
                    break;
                case EVENT_DIVE_BOMB_6:
                    DoCastSelf(SPELL_REBIRTH_2);
                    me->SetDisplayId(me->GetNativeDisplayId());
                    events.ScheduleEvent(EVENT_DIVE_BOMB_7, 2400ms);
                    break;
                case EVENT_DIVE_BOMB_7:
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_FLAME_BUFFET, 1s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isFirstPhase;
    bool _isInTransition;
    bool _isFirstPlatform;
    bool _shouldSpawnEmber;
    uint8 _currentPlatform;
};

// 19551 - Ember of Al'ar
struct npc_ember_of_alar : public ScriptedAI
{
    npc_ember_of_alar(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_EMBER_BLAST, true);
        /// @temporary: Should be triggered from the spell above, doesn't work currently
        DoCastSelf(SPELL_EMBER_BLAST_DAMAGE, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 20602 - Flame Patch (Al'ar)
struct npc_flame_patch_alar : public ScriptedAI
{
    npc_flame_patch_alar(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FLAME_PATCH_PERIODIC);
    }
};

// 34229 - Flame Quills
class spell_alar_flame_quills : public AuraScript
{
    PrepareAuraScript(spell_alar_flame_quills);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(FlameQuillsSpells);
    }

    bool Load() override
    {
        return InstanceHasScript(GetUnitOwner(), TheEyeScriptName);
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        for (uint32 spell : FlameQuillsSpells)
            GetTarget()->CastSpell(nullptr, spell, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Creature* target = GetTarget()->ToCreature())
            target->AI()->DoAction(ACTION_FLAME_QUILLS_END);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alar_flame_quills::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_alar_flame_quills::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 39555 - Ashtongue Ruse Master
class spell_alar_ashtongue_ruse_master : public AuraScript
{
    PrepareAuraScript(spell_alar_ashtongue_ruse_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ASHTONGUE_RUSE_DUMMY, SPELL_ASHTONGUE_RUSE_CREDIT });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_ASHTONGUE_RUSE_DUMMY))
            target->CastSpell(target, SPELL_ASHTONGUE_RUSE_CREDIT, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_alar_ashtongue_ruse_master::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_alar()
{
    RegisterTheEyeCreatureAI(boss_alar);
    RegisterTheEyeCreatureAI(npc_ember_of_alar);
    RegisterTheEyeCreatureAI(npc_flame_patch_alar);
    RegisterSpellScript(spell_alar_flame_quills);
    RegisterSpellScript(spell_alar_ashtongue_ruse_master);
}

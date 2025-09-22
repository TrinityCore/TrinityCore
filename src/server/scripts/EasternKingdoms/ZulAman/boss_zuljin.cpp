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
 * Timers requires to be revisited
 * SAY_INTRO is NYI, Zul'jin should say it when player opens Malacrass' door
 * Berserk requires additional research. Is it really used?
 * SPELL_ENERGY_STORM doesn't get removed on phase end
 * Damage of spell 43150 doesn't increase
 * SPELL_OVERPOWER should be used after the target dodges (?)
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "zulaman.h"

enum ZuljinTexts
{
    SAY_INTRO                     = 0,
    SAY_AGGRO                     = 1,
    SAY_TRANSFORM_TO_BEAR         = 2,
    SAY_TRANSFORM_TO_EAGLE        = 3,
    SAY_TRANSFORM_TO_LYNX         = 4,
    SAY_TRANSFORM_TO_DRAGONHAWK   = 5,
    SAY_FIRE_BREATH               = 6,
    SAY_BERSERK                   = 7,
    SAY_SLAY                      = 8,
    SAY_DEATH                     = 9,

    EMOTE_BEAR_SPIRIT             = 10,
    EMOTE_EAGLE_SPIRIT            = 11,
    EMOTE_LYNX_SPIRIT             = 12,
    EMOTE_DRAGONHAWK_SPIRIT       = 13,

    EMOTE_FADE_AWAY               = 0
};

enum ZuljinSpells
{
    // Troll Form
    SPELL_WHIRLWIND               = 17207,
    SPELL_GRIEVOUS_THROW          = 43093,

    // Bear Form
    SPELL_CREEPING_PARALYSIS      = 43095,
    SPELL_OVERPOWER               = 43456,

    // Eagle Form
    SPELL_SUMMON_CYCLONE          = 43112,
    SPELL_ENERGY_STORM            = 43983,

    // Lynx Form
    SPELL_CLAW_RAGE               = 42583,
    SPELL_LYNX_RUSH               = 43152,

    // Dragonhawk Form
    SPELL_FLAME_WHIRL             = 43213,
    SPELL_FLAME_BREATH            = 43215,
    SPELL_PILLAR_OF_FIRE          = 43216,

    // All forms
    SPELL_BERSERK                 = 45078,

    // Spirits
    SPELL_SPIRIT_DRAIN            = 42542,
    SPELL_SPIRIT_DRAINED          = 42520,
    SPELL_SPIRIT_REALM            = 44035,
    SPELL_SPIRIT_FADE             = 44036,

    // Transforms
    SPELL_SHAPE_OF_THE_BEAR       = 42594,
    SPELL_SHAPE_OF_THE_EAGLE      = 42606,
    SPELL_SHAPE_OF_THE_LYNX       = 42607,
    SPELL_SHAPE_OF_THE_DRAGONHAWK = 42608,

    // Feather Vortex
    SPELL_DREAM_FOG               = 24780,
    SPELL_BALL_OF_ENERGY          = 43457,
    SPELL_CYCLONE_VISUAL          = 43119,
    SPELL_CYCLONE                 = 43120,

    // Scripts
    SPELL_ZAP_DAMAGE              = 43137,
    SPELL_CLAW_RAGE_PERIODIC      = 43149,
    SPELL_LYNX_RUSH_DAMAGE        = 43153,

    // Misc
    SPELL_CYCLONE_EFFECT          = 43121,
    SPELL_INCINERATE_BLUE         = 42567
};

enum ZuljinEvents
{
    // Troll Form
    EVENT_WHIRLWIND               = 1,
    EVENT_GRIEVOUS_THROW,

    // Bear Form
    EVENT_CREEPING_PARALYSIS,
    EVENT_OVERPOWER,

    // Eagle Form
    EVENT_SUMMON_CYCLONE,
    EVENT_ENERGY_STORM,

    // Lynx Form
    EVENT_CLAW_RAGE,
    EVENT_LYNX_RUSH,

    // Dragonhawk Form
    EVENT_FLAME_WHIRL,
    EVENT_FLAME_BREATH,
    EVENT_PILLAR_OF_FIRE,

    // All forms
    EVENT_BERSERK,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,
    EVENT_TRANSITION_3,
    EVENT_TRANSITION_4
};

enum ZuljinEventGroups
{
    EVENT_GROUP_TROLL_PHASE       = 1,
    EVENT_GROUP_BEAR_PHASE        = 2,
    EVENT_GROUP_EAGLE_PHASE       = 3,
    EVENT_GROUP_LYNX_PHASE        = 4
};

enum ZuljinPhases
{
    PHASE_TROLL                   = 0,
    PHASE_BEAR                    = 1,
    PHASE_EAGLE                   = 2,
    PHASE_LYNX                    = 3,
    PHASE_DRAGONHAWK              = 4
};

enum ZuljinActions
{
    ACTION_CLEAR_FIXATE           = 1,
    ACTION_INTERRUPT_SPIRIT_DRAIN = 2,
    ACTION_CAST_SPIRIT_DRAIN      = 3,
    ACTION_CANCEL_SPIRIT_DRAINED  = 4
};

enum ZuljinMisc
{
    POINT_CENTER                  = 0,
    NPC_FEATHER_VORTEX            = 24136
};

static Position const CenterPos = { 120.172f, 706.444f, 45.111374f, 0.0f };

struct BossPhase
{
    uint32 spiritSpellId;
    uint8 sayId, emoteId;
    uint8 phaseGroup;
    uint32 spiritId;
};

static constexpr BossPhase ZuljinPhases[] =
{
    { SPELL_SHAPE_OF_THE_BEAR,       SAY_TRANSFORM_TO_BEAR,       EMOTE_BEAR_SPIRIT,       EVENT_GROUP_TROLL_PHASE, DATA_BEAR_SPIRIT       },
    { SPELL_SHAPE_OF_THE_EAGLE,      SAY_TRANSFORM_TO_EAGLE,      EMOTE_EAGLE_SPIRIT,      EVENT_GROUP_BEAR_PHASE,  DATA_EAGLE_SPIRIT      },
    { SPELL_SHAPE_OF_THE_LYNX,       SAY_TRANSFORM_TO_LYNX,       EMOTE_LYNX_SPIRIT,       EVENT_GROUP_EAGLE_PHASE, DATA_LYNX_SPIRIT       },
    { SPELL_SHAPE_OF_THE_DRAGONHAWK, SAY_TRANSFORM_TO_DRAGONHAWK, EMOTE_DRAGONHAWK_SPIRIT, EVENT_GROUP_LYNX_PHASE,  DATA_DRAGONHAWK_SPIRIT }
};

static constexpr uint32 SpiritData[] =
{
    DATA_BEAR_SPIRIT,
    DATA_EAGLE_SPIRIT,
    DATA_LYNX_SPIRIT,
    DATA_DRAGONHAWK_SPIRIT
};

// 23863 - Zul'jin
struct boss_zuljin : public BossAI
{
    boss_zuljin(Creature* creature) : BossAI(creature, BOSS_ZULJIN),
        _phase(PHASE_TROLL), _healthCheck(0), _rushCounter(0), _currentRushCount(0), _isInTransition(false) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_TROLL;
        _healthCheck = 80;
        _rushCounter = urand(4, 10);
        _currentRushCount = 0;
        _isInTransition = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        ScheduleEventsForPhase();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // Let creature finish current transition
        if (_isInTransition)
            return;

        if (me->HealthBelowPctDamaged(_healthCheck, damage))
        {
            _isInTransition = true;
            events.ScheduleEvent(EVENT_TRANSITION_1, 0s);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE && pointId == POINT_CENTER)
            events.ScheduleEvent(EVENT_TRANSITION_2, 0s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SHAPE_OF_THE_BEAR:
            case SPELL_SHAPE_OF_THE_EAGLE:
            case SPELL_SHAPE_OF_THE_LYNX:
            case SPELL_SHAPE_OF_THE_DRAGONHAWK:
                events.ScheduleEvent(EVENT_TRANSITION_4, 0s);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_LYNX_RUSH_DAMAGE:
                ++_currentRushCount;
                if (_currentRushCount != _rushCounter)
                {
                    DoCastSelf(SPELL_LYNX_RUSH, true);
                }
                else
                {
                    _rushCounter = urand(4, 10);
                    _currentRushCount = 0;
                }
                break;
            case SPELL_CLAW_RAGE:
                if (target->IsPlayer())
                {
                    _clawRageVictimGUID = target->GetGUID();
                    me->GetThreatManager().AddThreat(target->ToUnit(), 50000000.0f, nullptr, true, true);
                }
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_CLEAR_FIXATE)
            if (Unit* target = ObjectAccessor::GetUnit(*me, _clawRageVictimGUID))
                me->GetThreatManager().AddThreat(target, -50000000.0f, nullptr, true, true);
    }

    void ScheduleEventsForPhase()
    {
        switch (_phase)
        {
            case PHASE_TROLL:
                events.ScheduleEvent(EVENT_WHIRLWIND, 15s, 20s, EVENT_GROUP_TROLL_PHASE);
                events.ScheduleEvent(EVENT_GRIEVOUS_THROW, 10s, 20s, EVENT_GROUP_TROLL_PHASE);
                events.ScheduleEvent(EVENT_BERSERK, 10min);
                break;
            case PHASE_BEAR:
                events.ScheduleEvent(EVENT_CREEPING_PARALYSIS, 0s, 5s, EVENT_GROUP_BEAR_PHASE);
                events.ScheduleEvent(EVENT_OVERPOWER, 5s, 10s, EVENT_GROUP_BEAR_PHASE);
                break;
            case PHASE_EAGLE:
                events.ScheduleEvent(EVENT_SUMMON_CYCLONE, 0s, EVENT_GROUP_EAGLE_PHASE);
                events.ScheduleEvent(EVENT_ENERGY_STORM, 0s, EVENT_GROUP_EAGLE_PHASE);
                break;
            case PHASE_LYNX:
                events.ScheduleEvent(EVENT_CLAW_RAGE, 5s, 15s, EVENT_GROUP_LYNX_PHASE);
                events.ScheduleEvent(EVENT_LYNX_RUSH, 15s, 20s, EVENT_GROUP_LYNX_PHASE);
                break;
            case PHASE_DRAGONHAWK:
                events.ScheduleEvent(EVENT_FLAME_WHIRL, 0s, 15s);
                events.ScheduleEvent(EVENT_FLAME_BREATH, 5s, 10s);
                events.ScheduleEvent(EVENT_PILLAR_OF_FIRE, 5s, 10s);
                break;
            default:
                break;
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_FLAME_BREATH:
                Talk(SAY_FIRE_BREATH);
                break;
            case SPELL_BERSERK:
                Talk(SAY_BERSERK);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 spiritId : SpiritData)
            if (Creature* spirit = instance->GetCreature(spiritId))
                spirit->AI()->DoAction(ACTION_CANCEL_SPIRIT_DRAINED);

        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        // Last spirit, needs to be handled here
        if (Creature* spirit = instance->GetCreature(ZuljinPhases[_phase - 1].spiritId))
            spirit->AI()->DoAction(ACTION_INTERRUPT_SPIRIT_DRAIN);

        _JustDied();

        Talk(SAY_DEATH);
        DoCastSelf(SPELL_INCINERATE_BLUE, true);
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
                // Troll Form
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_GRIEVOUS_THROW:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 80.0f, true))
                        DoCast(target, SPELL_GRIEVOUS_THROW);
                    events.Repeat(10s, 20s);
                    break;

                // Bear Form
                case EVENT_CREEPING_PARALYSIS:
                    DoCastSelf(SPELL_CREEPING_PARALYSIS);
                    events.Repeat(20s);
                    break;
                case EVENT_OVERPOWER:
                    // Cast as triggered, otherwise it will not work
                    DoCastVictim(SPELL_OVERPOWER, true);
                    events.Repeat(10s, 15s);
                    break;

                // Eagle Form
                case EVENT_SUMMON_CYCLONE:
                    DoCastSelf(SPELL_SUMMON_CYCLONE);
                    break;
                case EVENT_ENERGY_STORM:
                    DoCastSelf(SPELL_ENERGY_STORM);
                    break;

                // Lynx Form
                case EVENT_CLAW_RAGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 80.0f, true))
                        DoCast(target, SPELL_CLAW_RAGE);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_LYNX_RUSH:
                    // For unknown reason Lynx Rush sequence works only if init spell was casted as triggered, but make sure we don't use it if Claw Rage is active
                    if (!me->HasAura(SPELL_CLAW_RAGE))
                        DoCastSelf(SPELL_LYNX_RUSH, true);
                    events.Repeat(20s, 25s);
                    break;

                // Dragonhawk Form
                case EVENT_FLAME_WHIRL:
                    DoCastSelf(SPELL_FLAME_WHIRL);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_FLAME_BREATH:
                    DoCastSelf(SPELL_FLAME_BREATH);
                    events.Repeat(5s, 10s);
                    break;
                case EVENT_PILLAR_OF_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 80.0f, true))
                        DoCast(target, SPELL_PILLAR_OF_FIRE);
                    events.Repeat(10s, 15s);
                    break;

                // All forms
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;

                // Transition
                case EVENT_TRANSITION_1:
                {
                    if (_phase == PHASE_EAGLE)
                    {
                        summons.DespawnEntry(NPC_FEATHER_VORTEX);
                        me->RemoveAurasDueToSpell(SPELL_ENERGY_STORM);
                    }

                    _healthCheck -= 20;
                    Talk(ZuljinPhases[_phase].sayId);
                    me->RemoveAurasDueToSpell(ZuljinPhases[_phase - 1].spiritSpellId);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_CENTER, CenterPos);

                    events.CancelEventGroup(ZuljinPhases[_phase].phaseGroup);
                    break;
                }
                case EVENT_TRANSITION_2:
                {
                    if (Creature* spirit = instance->GetCreature(ZuljinPhases[_phase - 1].spiritId))
                        spirit->AI()->DoAction(ACTION_INTERRUPT_SPIRIT_DRAIN);

                    if (Creature* spirit = instance->GetCreature(ZuljinPhases[_phase].spiritId))
                    {
                        me->SetFacingToObject(spirit);
                        Talk(ZuljinPhases[_phase].emoteId);
                        spirit->AI()->DoAction(ACTION_CAST_SPIRIT_DRAIN);
                    }
                    events.ScheduleEvent(EVENT_TRANSITION_3, 3s);
                    break;
                }
                case EVENT_TRANSITION_3:
                    DoCastSelf(ZuljinPhases[_phase].spiritSpellId);
                    break;
                case EVENT_TRANSITION_4:
                {
                    ++_phase;

                    ScheduleEventsForPhase();

                    ResetThreatList();
                    SetEquipmentSlots(false, EQUIP_UNEQUIP);

                    if (_phase != PHASE_EAGLE)
                        me->SetReactState(REACT_AGGRESSIVE);

                    _isInTransition = false;
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
    uint8 _healthCheck;
    uint8 _rushCounter;
    uint8 _currentRushCount;
    bool _isInTransition;
    ObjectGuid _clawRageVictimGUID;
};

// 24136 - Feather Vortex
struct npc_zuljin_vortex : public ScriptedAI
{
    npc_zuljin_vortex(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        /// @todo: After first tick makes creature stop movement, investigate this
        // DoCastSelf(SPELL_DREAM_FOG);

        _scheduler
            .Schedule(2s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_BALL_OF_ENERGY);
                DoCastSelf(SPELL_CYCLONE_VISUAL);
                DoCastSelf(SPELL_CYCLONE);
            })
            .Schedule(3s, [this](TaskContext /*task*/)
            {
                DoZoneInCombat();
                FixateRandomTarget();
            });
    }

    void FixateRandomTarget()
    {
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
        {
            ResetThreatList();
            AddThreat(target, 1000000.0f);
            AttackStart(target);
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_CYCLONE_EFFECT && target == me->GetVictim())
            FixateRandomTarget();
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 23877 - Amani Lynx Spirit
// 23878 - Amani Bear Spirit
// 23879 - Amani Dragonhawk Spirit
// 23880 - Amani Eagle Spirit
struct npc_zuljin_spirit : public ScriptedAI
{
    npc_zuljin_spirit(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CAST_SPIRIT_DRAIN:
                DoCastSelf(SPELL_SPIRIT_DRAIN);
                break;
            case ACTION_INTERRUPT_SPIRIT_DRAIN:
                me->InterruptNonMeleeSpells(false);
                DoCastSelf(SPELL_SPIRIT_DRAINED);
                break;
            case ACTION_CANCEL_SPIRIT_DRAINED:
                me->RemoveAurasDueToSpell(SPELL_SPIRIT_DRAINED);
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_INCINERATE_BLUE)
        {
            me->RemoveAurasDueToSpell(SPELL_SPIRIT_DRAINED);

            _scheduler.Schedule(13s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_SPIRIT_REALM);
                Talk(EMOTE_FADE_AWAY);

                _scheduler.Schedule(5s, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_SPIRIT_FADE);
                });
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 42577 - Zap
class spell_zuljin_zap : public SpellScript
{
    PrepareSpellScript(spell_zuljin_zap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ZAP_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_ZAP_DAMAGE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zuljin_zap::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 42583 - Claw Rage
class spell_zuljin_claw_rage : public SpellScript
{
    PrepareSpellScript(spell_zuljin_claw_rage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLAW_RAGE_PERIODIC });
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_CLAW_RAGE_PERIODIC, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_zuljin_claw_rage::HandleAfterCast);
    }
};

// 43149 - Claw Rage
class spell_zuljin_claw_rage_periodic : public AuraScript
{
    PrepareAuraScript(spell_zuljin_claw_rage_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        Unit* victim = target->GetVictim();
        if (victim)
        {
            uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell;
            target->CastSpell(victim, triggerSpell, true);
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->AI()->DoAction(ACTION_CLEAR_FIXATE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_zuljin_claw_rage_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_zuljin_claw_rage_periodic::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 43152 - Lynx Rush
class spell_zuljin_lynx_rush : public SpellScript
{
    PrepareSpellScript(spell_zuljin_lynx_rush);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LYNX_RUSH_DAMAGE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (Unit* target = caster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 80.0f, true))
                caster->CastSpell(target, SPELL_LYNX_RUSH_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zuljin_lynx_rush::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_zuljin()
{
    RegisterZulAmanCreatureAI(boss_zuljin);
    RegisterZulAmanCreatureAI(npc_zuljin_vortex);
    RegisterZulAmanCreatureAI(npc_zuljin_spirit);
    RegisterSpellScript(spell_zuljin_zap);
    RegisterSpellScript(spell_zuljin_claw_rage);
    RegisterSpellScript(spell_zuljin_claw_rage_periodic);
    RegisterSpellScript(spell_zuljin_lynx_rush);
}

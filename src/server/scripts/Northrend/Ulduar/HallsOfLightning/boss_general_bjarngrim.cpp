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
#include "halls_of_lightning.h"
#include "SpellScript.h"
#include "CreatureGroups.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"

enum Spells
{
    // General Bjarngrim
    SPELL_CHARGE_UP                     = 52098,
    SPELL_TEMPOARY_ELECTRICAL_CHARGE    = 52092,
    SPELL_STANCE_COOLDOWN               = 41102,
    SPELL_DEFENSIVE_STANCE              = 53790,
    SPELL_DEFENSIVE_AURA                = 41105,
    SPELL_KNOCK_AWAY                    = 52029,
    SPELL_SPELL_REFLECTION              = 36096,
    SPELL_BERSERKER_STANCE              = 53791,
    SPELL_BERSERKER_AURA                = 41107,
    SPELL_WHIRLWIND                     = 52027,
    SPELL_INTERCEPT                     = 58769,
    SPELL_CLEAVE                        = 15284,
    SPELL_BATTLE_STANCE                 = 53792,
    SPELL_BATTLE_AURA                   = 41106,
    SPELL_MORTAL_STRIKE                 = 16856,
    SPELL_SLAM                          = 52026,

    // Stormforged Lieutenant
    SPELL_ARC_WELD                      = 59085,
    SPELL_ARC_WELD_DAMAGE               = 59097,
    SPELL_RENEW_STEEL                   = 52774,

    // Invisible Stalker
    SPELL_CHARGE_UP_DUMMY               = 56458
};

enum Events
{
    // General Bjarngrim
    EVENT_CHARGE_UP = 1,
    EVENT_CHECK_STANCE_COOLDOWN,
    EVENT_KNOCK_AWAY,
    EVENT_SPELL_REFLECTION,
    EVENT_WHIRLWIND,
    EVENT_INTERCEPT,
    EVENT_CLEAVE,
    EVENT_MORTAL_STRIKE,
    EVENT_SLAM,

    // Stormforged Lieutenant
    EVENT_ARC_WELD = 1,
    EVENT_CHECK_BJARNGRIMS_HEALTH
};

enum EventGroups
{
    EVENT_GROUP_DEFENSIVE_STANCE = 1,
    EVENT_GROUP_BERSERKER_STANCE,
    EVENT_GROUP_BATTLE_STANCE
};

enum Actions
{
    ACTION_SWITCH_STANCE = 0
};

enum Phases
{
    PHASE_OUT_OF_COMBAT = 1
};

enum Texts
{
    // General Bjarngrim
    SAY_AGGRO                       = 0,
    SAY_ANNOUNCE_DEFENSIVE_STANCE   = 1,
    SAY_DEFENSIVE_STANCE            = 2,
    SAY_ANNOUNCE_BERSERKER_STANCE   = 3,
    SAY_BERSERKER_STANCE            = 4,
    SAY_ANNOUNCE_BATTLE_STANCE      = 5,
    SAY_BATTLE_STANCE               = 6,
    SAY_SLAY                        = 7,
    SAY_DEATH                       = 8
};

enum VirtualItemIds
{
    ITEM_ID_AXE         = 43625,
    ITEM_ID_SHIELD      = 39384,
    ITEM_ID_GREATAXE    = 43623
};

enum Stances
{
    STANCE_DEFENSIVE = 0,
    STANCE_BERSERKER = 1,
    STANCE_BATTLE    = 2,

    MAX_STANCE
};

// These values must be sync with the data in waypoint_data.
// Each of these points is going to trigger a Charge Up sequence
static std::array<uint8, 2> const ChargeUpWaypointIds = { 7, 15 };
// Each of these points is going to remove the Tempoary Electrical Charge buff from General Bjarngrim
static std::array<uint8, 2> const ClearTempoaryChargeWaypointIds = { 5, 13 };

// This value must be sync with the data in spawngroup_template
static constexpr uint32 SPAWN_GROUP_ID_STORMFORGED_LIEUTENANTS = 325;

struct StanceTextInfo
{
    StanceTextInfo(uint32 announceTextId, uint32 sayTextId) :
        AnnounceTextId(announceTextId), SayTextId(sayTextId) { }

    uint32 AnnounceTextId;
    uint32 SayTextId;
};

struct StanceInfo
{
    StanceInfo(StanceTextInfo textInfo, uint32 stanceSpellId) :
        TextInfo(textInfo), StanceSpellId(stanceSpellId) { }

    StanceTextInfo TextInfo;
    uint32 StanceSpellId;
};

static std::array<StanceInfo, MAX_STANCE> const StanceData =
{
    StanceInfo(StanceTextInfo(SAY_ANNOUNCE_DEFENSIVE_STANCE, SAY_DEFENSIVE_STANCE), SPELL_DEFENSIVE_STANCE),
    StanceInfo(StanceTextInfo(SAY_ANNOUNCE_BERSERKER_STANCE, SAY_BERSERKER_STANCE), SPELL_BERSERKER_STANCE),
    StanceInfo(StanceTextInfo(SAY_ANNOUNCE_BATTLE_STANCE, SAY_BATTLE_STANCE), SPELL_BATTLE_STANCE)
};

struct boss_general_bjarngrim : public BossAI
{
    boss_general_bjarngrim(Creature* creature) : BossAI(creature, DATA_GENERAL_BJARNGRIM), _currentStanceId(STANCE_BATTLE) { }

    void JustAppeared() override
    {
        events.SetPhase(PHASE_OUT_OF_COMBAT);
        instance->instance->SpawnGroupSpawn(SPAWN_GROUP_ID_STORMFORGED_LIEUTENANTS, true, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        events.Reset();
        events.ScheduleEvent(EVENT_CHECK_STANCE_COOLDOWN, 1s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _DespawnAtEvade();
        instance->instance->SpawnGroupDespawn(SPAWN_GROUP_ID_STORMFORGED_LIEUTENANTS, true);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY, victim);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH, killer);
        instance->instance->SpawnGroupDespawn(SPAWN_GROUP_ID_STORMFORGED_LIEUTENANTS, true);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != WAYPOINT_MOTION_TYPE)
            return;

        if (std::find(ChargeUpWaypointIds.begin(), ChargeUpWaypointIds.end(), pointId) != ChargeUpWaypointIds.end())
            events.ScheduleEvent(EVENT_CHARGE_UP, 4s, 0, PHASE_OUT_OF_COMBAT);
        else if (std::find(ClearTempoaryChargeWaypointIds.begin(), ClearTempoaryChargeWaypointIds.end(), pointId) != ClearTempoaryChargeWaypointIds.end())
            me->RemoveAurasDueToSpell(SPELL_TEMPOARY_ELECTRICAL_CHARGE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SWITCH_STANCE:
            {
                me->RemoveAurasDueToSpell(StanceData[_currentStanceId].StanceSpellId);

                // @todo: figure out if the stances just cycle or if they are random
                _currentStanceId = (_currentStanceId + 1) % StanceData.size();

                DoCastSelf(StanceData[_currentStanceId].StanceSpellId);
                Talk(StanceData[_currentStanceId].TextInfo.AnnounceTextId);
                Talk(StanceData[_currentStanceId].TextInfo.SayTextId);

                switch (_currentStanceId)
                {
                    case STANCE_DEFENSIVE:
                        events.CancelEventGroup(EVENT_GROUP_BERSERKER_STANCE);
                        events.CancelEventGroup(EVENT_GROUP_BATTLE_STANCE);
                        events.ScheduleEvent(EVENT_KNOCK_AWAY, 5s, EVENT_GROUP_DEFENSIVE_STANCE);
                        events.ScheduleEvent(EVENT_SPELL_REFLECTION, 7s, EVENT_GROUP_DEFENSIVE_STANCE);
                        break;
                    case STANCE_BERSERKER:
                        events.CancelEventGroup(EVENT_GROUP_DEFENSIVE_STANCE);
                        events.CancelEventGroup(EVENT_GROUP_BATTLE_STANCE);
                        events.ScheduleEvent(EVENT_WHIRLWIND, 7s, EVENT_GROUP_BERSERKER_STANCE);
                        events.ScheduleEvent(EVENT_INTERCEPT, 16s, EVENT_GROUP_BERSERKER_STANCE);
                        events.ScheduleEvent(EVENT_CLEAVE, 19s + 500ms, EVENT_GROUP_BERSERKER_STANCE);
                        break;
                    case STANCE_BATTLE:
                        events.CancelEventGroup(EVENT_GROUP_DEFENSIVE_STANCE);
                        events.CancelEventGroup(EVENT_GROUP_BERSERKER_STANCE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5s, EVENT_GROUP_BATTLE_STANCE);
                        events.ScheduleEvent(EVENT_SLAM, 9s, EVENT_GROUP_BATTLE_STANCE);
                        break;
                    default:
                        break;
                }

                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_OUT_OF_COMBAT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHARGE_UP:
                    DoCastSelf(SPELL_CHARGE_UP);
                    if (Creature* stalker = instance->GetCreature(DATA_INVISIBLE_STALKER))
                        stalker->m_Events.AddEventAtOffset([stalker]() { stalker->CastSpell(nullptr, SPELL_CHARGE_UP_DUMMY); }, 4s);
                    break;
                case EVENT_CHECK_STANCE_COOLDOWN:
                    // General Bjarngrim uses a category cooldown to handle the stance switching, so we do as well.
                    if (!me->GetSpellHistory()->GetRemainingCooldown(sSpellMgr->AssertSpellInfo(SPELL_STANCE_COOLDOWN)))
                        DoAction(ACTION_SWITCH_STANCE);
                    events.Repeat(1s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastAOE(SPELL_KNOCK_AWAY);
                    events.Repeat(11s);
                    break;
                case EVENT_SPELL_REFLECTION:
                    DoCastSelf(SPELL_SPELL_REFLECTION);
                    events.Repeat(8s + 500ms);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    break;
                case EVENT_INTERCEPT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, -8.f, true, true))
                        DoCast(target, SPELL_INTERCEPT);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    break;
                case EVENT_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    break;
                case EVENT_SLAM:
                    DoCastVictim(SPELL_SLAM);
                    events.Repeat(5s);
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
     uint8 _currentStanceId;
};

struct npc_bjarngrim_stormforged_lieutenant : public ScriptedAI
{
    npc_bjarngrim_stormforged_lieutenant(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ARC_WELD, 5s, 6s);
        _events.ScheduleEvent(EVENT_CHECK_BJARNGRIMS_HEALTH, 10s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
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
                case EVENT_ARC_WELD:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.f, true))
                        DoCast(target, SPELL_ARC_WELD);
                    _events.Repeat(22s);
                    break;
                case EVENT_CHECK_BJARNGRIMS_HEALTH:
                    if (Creature* bjarngrim = _instance->GetCreature(DATA_GENERAL_BJARNGRIM))
                        if (bjarngrim->GetHealthPct() <= 75.f) // @todo: validate
                            DoCast(bjarngrim, SPELL_RENEW_STEEL);

                    _events.Repeat(10s, 14s); // @todo: these are just taken from the old code. We know that these heals are pct based so we need the cooldown rather than a timer
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    InstanceScript* _instance;
};

// 53790 - Defensive Stance
// 53791 - Berserker Stance
// 53792 - Battle Stance
class spell_bjarngrim_stance_dummy : public AuraScript
{
    PrepareAuraScript(spell_bjarngrim_stance_dummy);

public:
    spell_bjarngrim_stance_dummy(uint8 stanceId) : AuraScript(), _stanceId(stanceId) { }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEFENSIVE_AURA, SPELL_BERSERKER_AURA, SPELL_BATTLE_AURA, SPELL_STANCE_COOLDOWN });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* target = GetTarget()->ToCreature();
        if (!target)
            return;

        switch (_stanceId)
        {
            case STANCE_DEFENSIVE:
                target->SetVirtualItem(0, ITEM_ID_AXE);
                target->SetVirtualItem(1, ITEM_ID_SHIELD);
                target->CastSpell(nullptr, SPELL_DEFENSIVE_AURA);
                break;
            case STANCE_BERSERKER:
                target->SetVirtualItem(0, ITEM_ID_AXE);
                target->SetVirtualItem(1, ITEM_ID_AXE);
                target->CastSpell(nullptr, SPELL_BERSERKER_AURA);
                target->SetCanDualWield(true);
                break;
            case STANCE_BATTLE:
                target->SetVirtualItem(0, ITEM_ID_GREATAXE);
                target->SetVirtualItem(1, 0);
                target->CastSpell(nullptr, SPELL_BATTLE_AURA);
                break;
            default:
                break;
        }

        target->CastSpell(nullptr, SPELL_STANCE_COOLDOWN);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* target = GetTarget()->ToCreature();
        if (!target)
            return;

        switch (_stanceId)
        {
            case STANCE_DEFENSIVE:
                target->RemoveAurasDueToSpell(SPELL_DEFENSIVE_AURA);
                break;
            case STANCE_BERSERKER:
                target->RemoveAurasDueToSpell(SPELL_BERSERKER_AURA);
                target->SetCanDualWield(false);
                break;
            case STANCE_BATTLE:
                target->RemoveAurasDueToSpell(SPELL_BATTLE_AURA);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_bjarngrim_stance_dummy::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_bjarngrim_stance_dummy::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
private:
    uint8 _stanceId;
};

// 52098 - Charge Up
class spell_bjarngrim_charge_up : public AuraScript
{
    PrepareAuraScript(spell_bjarngrim_charge_up);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TEMPOARY_ELECTRICAL_CHARGE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->CastSpell(nullptr, SPELL_TEMPOARY_ELECTRICAL_CHARGE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_bjarngrim_charge_up::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 59085 - Arc Weld
class spell_bjarngrim_arc_weld : public AuraScript
{
    PrepareAuraScript(spell_bjarngrim_arc_weld);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ARC_WELD_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (GetTarget()->isMoving())
            GetTarget()->CastSpell(nullptr, SPELL_ARC_WELD_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bjarngrim_arc_weld::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_general_bjarngrim()
{
    RegisterHallsOfLightningCreatureAI(boss_general_bjarngrim);
    RegisterHallsOfLightningCreatureAI(npc_bjarngrim_stormforged_lieutenant);
    RegisterSpellScriptWithArgs(spell_bjarngrim_stance_dummy, "spell_bjarngrim_defensive_stance_dummy", STANCE_DEFENSIVE);
    RegisterSpellScriptWithArgs(spell_bjarngrim_stance_dummy, "spell_bjarngrim_battle_stance_dummy", STANCE_BATTLE);
    RegisterSpellScriptWithArgs(spell_bjarngrim_stance_dummy, "spell_bjarngrim_berserker_stance_dummy", STANCE_BERSERKER);
    RegisterSpellScript(spell_bjarngrim_charge_up);
    RegisterSpellScript(spell_bjarngrim_arc_weld);
}

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

/* To-do: */
// - AreaTrigger: unknown purpose (id: 1843; pos: front-right stairs) - dust animation, aggro snakes? 

#include "halls_of_origination.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "World.h"

enum Texts
{
    SAY_AGGRO                    = 0,
    SAY_SHIELD                   = 1,
    EMOTE_SHIELD                 = 2, 
    EMOTE_SHIELD_REMOVED         = 3,
    SAY_KILL                     = 4,
    SAY_DEATH                    = 5
};

enum Events
{
    EVENT_BURNING_LIGHT          = 1,
    EVENT_SEARING_LIGHT          = 2,
    EVENT_DIVINE_RECKONING       = 3,
    EVENT_CAST_SHIELD            = 4,
    EVENT_ACTIVATE_BEACONS       = 5,
    EVENT_CAST_BEAMS             = 6,
    EVENT_ACHIEVEMENT_FAILED     = 7
};

enum Spells
{
    // Fight phase
    SPELL_DIVINE_RECKONING       = 75592,
    SPELL_BURNING_LIGHT          = 75115,
    SPELL_TELEPORT               = 74969,
    SPELL_SHIELD_OF_LIGHT        = 74938,
    SPELL_REVERBERATING_HYMN     = 75322,
    SPELL_ACTIVATE_BEACONS       = 76599,
    SPELL_DEACTIVATE_BEACONS     = 76600,

    // Cave In Stalker (eyes)
    SPELL_BURNING_LIGHT_SEAR     = 75194
};

enum Phases
{
    PHASE_FIGHT  = 1,
    PHASE_SHIELD = 2
};

enum Actions
{
    ACTION_DISABLE_BEACON_L,
    ACTION_DISABLE_BEACON_R,
    ACTION_HYMN_EXPIRED
};

enum Data
{
    DATA_ACHIEVEMENT_ENLIGIBLE = 0
};

struct boss_temple_guardian_anhuur : public BossAI
{
    boss_temple_guardian_anhuur(Creature* creature) : BossAI(creature, DATA_TEMPLE_GUARDIAN_ANHUUR)
    {
        Initialize();
    }

    void Initialize()
    {
        _countShield = 0;
        _leftBeaconDisabled = false;
        _rightBeaconDisabled = false;
        _achievementEnligible = true;
    }

    void Reset() override
    {
        Initialize();
        _Reset();
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_FIGHT);
        events.ScheduleEvent(EVENT_DIVINE_RECKONING, Seconds(10), 0, PHASE_FIGHT);
        events.ScheduleEvent(EVENT_BURNING_LIGHT, Seconds(12), 0, PHASE_FIGHT);
        instance->DoUpdateWorldState(WS_I_HATE_THIS_SONG, 0);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
        _JustDied();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (reason != SPELL_FINISHED_CANCELED)
            return;

        me->MakeInterruptable(false);

        if (spell->Id == SPELL_REVERBERATING_HYMN)
        {
            events.CancelEvent(EVENT_ACHIEVEMENT_FAILED);
            events.SetPhase(PHASE_FIGHT);
            events.ScheduleEvent(EVENT_DIVINE_RECKONING, 10s, 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_BURNING_LIGHT, 12s, 0, PHASE_FIGHT);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // One-hit cases
        if (damage >= me->GetHealth())
            return;

        // Already in shield phase? 2 shields are enough.
        if (events.IsInPhase(PHASE_SHIELD) || _countShield == 2)
            return;

        // Shield phase happens at 66% and 33% health remaining.
        if ((me->HealthBelowPctDamaged(66, damage) && _countShield == 0) ||
            (me->HealthBelowPctDamaged(33, damage) && _countShield == 1))
            EnterShieldPhase();
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ACHIEVEMENT_ENLIGIBLE)
            return uint8(_achievementEnligible);

        return 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISABLE_BEACON_L:
                _leftBeaconDisabled = true;
                break;
            case ACTION_DISABLE_BEACON_R:
                _rightBeaconDisabled = true;
                break;
            case ACTION_HYMN_EXPIRED:
                RemoveShieldOfLight();
                DoCastAOE(SPELL_DEACTIVATE_BEACONS, true);
                break;
            default:
                break;
        }

        // Exit shield phase if both beacons are disabled or channeling Reverberating Hymn finished.
        if (_leftBeaconDisabled && _rightBeaconDisabled)
            RemoveShieldOfLight();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !events.IsInPhase(PHASE_SHIELD))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BURNING_LIGHT:
                    DoCastAOE(SPELL_BURNING_LIGHT);
                    events.ScheduleEvent(EVENT_SEARING_LIGHT, 2s);
                    break;
                case EVENT_SEARING_LIGHT:
                    HandleSearingLight();
                    events.ScheduleEvent(EVENT_BURNING_LIGHT, 10s, 0, PHASE_FIGHT);
                    break;
                case EVENT_DIVINE_RECKONING:
                    DoCastVictim(SPELL_DIVINE_RECKONING);
                    events.ScheduleEvent(EVENT_DIVINE_RECKONING, 10s, 0, PHASE_FIGHT);
                    break;
                case EVENT_CAST_SHIELD:
                    me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
                    me->SetFacingTo(1.5708f);
                    DoCastSelf(SPELL_SHIELD_OF_LIGHT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE);
                    events.ScheduleEvent(EVENT_ACTIVATE_BEACONS, 2s, 0, PHASE_SHIELD);
                    break;
                case EVENT_ACTIVATE_BEACONS:
                    Talk(EMOTE_SHIELD);
                    DoCastAOE(SPELL_ACTIVATE_BEACONS, true);
                    DoCastSelf(SPELL_REVERBERATING_HYMN);
                    instance->SetData(DATA_HANDLE_SHIELD_VISUAL, IN_PROGRESS);
                    events.ScheduleEvent(EVENT_CAST_BEAMS, 1s, 0, PHASE_SHIELD);
                    events.ScheduleEvent(EVENT_ACHIEVEMENT_FAILED, 15s, 0, PHASE_SHIELD);
                    break;
                case EVENT_CAST_BEAMS:
                    instance->SetData(DATA_HANDLE_BEAM_OF_LIGHT, IN_PROGRESS);
                    break;
                case EVENT_ACHIEVEMENT_FAILED:
                    instance->DoUpdateWorldState(WS_I_HATE_THIS_SONG, 1);
                    _achievementEnligible = false;
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (!events.IsInPhase(PHASE_SHIELD))
            DoMeleeAttackIfReady();
    }

    void HandleSearingLight()
    {
        Unit* target = me->FindNearestCreature(NPC_SEARING_LIGHT, 100.0f);
        GameObject* door = instance->GetGameObject(DATA_ANHUUR_DOOR);
        if (!target || !door)
            return;

        std::list<Creature*> stalkers;
        GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
        stalkers.remove_if(Trinity::HeightDifferenceCheck(door, 5.0f, true));
        if (stalkers.empty())
            return;

        stalkers.sort(Trinity::ObjectDistanceOrderPred(target));

        // Get the closest statue face (any of its eyes)
        Creature* eye1 = stalkers.front();
        stalkers.remove(eye1); // Remove the eye.
        stalkers.sort(Trinity::ObjectDistanceOrderPred(eye1)); // Find the second eye.
        Creature* eye2 = stalkers.front();

        eye1->CastSpell(eye1, SPELL_BURNING_LIGHT_SEAR, true);
        eye2->CastSpell(eye2, SPELL_BURNING_LIGHT_SEAR, true);
        return;
    }

    void EnterShieldPhase()
    {
        events.SetPhase(PHASE_SHIELD);
        _countShield++;
        _leftBeaconDisabled = false;
        _rightBeaconDisabled = false;

        me->SetReactState(REACT_PASSIVE);
        me->InterruptNonMeleeSpells(true);
        me->AttackStop();
        DoCastSelf(SPELL_TELEPORT);
        me->SetFacingTo(1.5708f, true);
        Talk(SAY_SHIELD);

        events.ScheduleEvent(EVENT_CAST_SHIELD, 1s, 0, PHASE_SHIELD);
    }

    void RemoveShieldOfLight()
    {
        instance->SetData(DATA_HANDLE_BEAM_OF_LIGHT, NOT_STARTED);
        me->MakeInterruptable(true);
        me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
        me->SetReactState(REACT_AGGRESSIVE);
        Talk(EMOTE_SHIELD_REMOVED);
    }

    uint8 _countShield;
    bool _leftBeaconDisabled;
    bool _rightBeaconDisabled;
    bool _achievementEnligible;
};

struct go_anhuur_beacon_of_light : public GameObjectAI
{
    go_anhuur_beacon_of_light(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* /*player*/) override
    {
        me->SendCustomAnim(0);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        me->DespawnOrUnsummon(1s + 200ms, 5s);
        me->CastSpell(nullptr, me->GetGOInfo()->goober.spellId);
        return true;
    }
};

// 75592 - Divine Reckoning
class spell_anhuur_divine_reckoning : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (!caster->isDead())
                caster->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, { SPELLVALUE_BASE_POINT0, aurEff->GetAmount() });
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_anhuur_divine_reckoning::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 74930 - Shield of Light (left)
// 76573 - Shield of Light (right)
class spell_anhuur_shield_of_light : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove(GetCaster());
        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

        if (targets.size() > 2)
            targets.resize(2);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_anhuur_shield_of_light::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 75322 - Reverberating Hymn
class spell_anhuur_reverberating_hymn : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            if (Creature * anhuur = GetCaster()->ToCreature())
                if (anhuur->IsAIEnabled)
                    anhuur->AI()->DoAction(ACTION_HYMN_EXPIRED);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_anhuur_reverberating_hymn::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 76606 - Disable Beacon Beams L
// 76608 - Disable Beacon Beams R
class spell_anhuur_disable_beacon_beams : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->InterruptNonMeleeSpells(true, GetEffectValue());
    }

    void Notify(SpellEffIndex /*index*/)
    {
        if (InstanceScript * instance = GetCaster()->GetInstanceScript())
            if (Creature * anhuur = instance->GetCreature(DATA_TEMPLE_GUARDIAN_ANHUUR))
                anhuur->AI()->DoAction(GetEffectValue() == SPELL_BEAM_OF_LIGHT_LEFT ? ACTION_DISABLE_BEACON_L : ACTION_DISABLE_BEACON_R);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_anhuur_disable_beacon_beams::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHit.Register(&spell_anhuur_disable_beacon_beams::Notify, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_anhuur_burning_light_forcecast : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (targets.size() > 1)
            targets.remove_if([caster](WorldObject const* obj)->bool
            {
                return caster->GetVictim() == obj;
            });

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_anhuur_burning_light_forcecast::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class achievement_i_hate_that_song : public AchievementCriteriaScript
{
    public:
        achievement_i_hate_that_song() : AchievementCriteriaScript("achievement_i_hate_that_song") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            return target && target->GetAI()->GetData(DATA_ACHIEVEMENT_ENLIGIBLE);
        }
};

void AddSC_boss_temple_guardian_anhuur()
{
    RegisterHallsOfOriginationCreatureAI(boss_temple_guardian_anhuur);
    RegisterGameObjectAI(go_anhuur_beacon_of_light);
    RegisterSpellScript(spell_anhuur_divine_reckoning);
    RegisterSpellScript(spell_anhuur_shield_of_light),
    RegisterSpellScript(spell_anhuur_reverberating_hymn);
    RegisterSpellScript(spell_anhuur_disable_beacon_beams);
    RegisterSpellScript(spell_anhuur_burning_light_forcecast);
    new achievement_i_hate_that_song();
}

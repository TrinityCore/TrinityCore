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

/* To-do: */
// - AreaTrigger: unknown purpose (id: 1843; pos: front-right stairs) - dust animation, aggro snakes? 

#include "halls_of_origination.h"
#include "ScriptMgr.h"
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
    EMOTE_UNSHIELD               = 3,
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
    SPELL_BURNING_LIGHT          = 75115, // Forces victim to summon Searing Light dummy at its location.

    // Shield phase
    SPELL_TELEPORT               = 74969,
    SPELL_SHIELD_OF_LIGHT        = 74938,
    SPELL_REVERBERATING_HYMN     = 75322,
    SPELL_ACTIVATE_BEACONS       = 76599,
    SPELL_DEACTIVATE_BEACONS     = 76600,

    // Cave In Stalker (eyes)
    SPELL_BURNING_LIGHT_SEAR     = 75194,

    // Cave In Stalker (beacons)
    SPELL_SHIELD_VISUAL_LEFT     = 83697,
    SPELL_SHIELD_VISUAL_RIGHT    = 83698,
    SPELL_BEAM_OF_LIGHT_LEFT     = 74930,
    SPELL_BEAM_OF_LIGHT_RIGHT    = 76573
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

class boss_temple_guardian_anhuur : public CreatureScript
{
public:
    boss_temple_guardian_anhuur() : CreatureScript("boss_temple_guardian_anhuur") { }

    struct boss_temple_guardian_anhuurAI : public BossAI
    {
        boss_temple_guardian_anhuurAI(Creature* creature) : BossAI(creature, DATA_TEMPLE_GUARDIAN_ANHUUR)
        {
            Initialize();
        }

        void Initialize()
        {
            _countShield = 0;
            _leftBeaconDisabled = false;
            _rightBeaconDisabled = false;
        }

        void Reset() override
        {
            Initialize();
            _Reset();
            CleanStalkers();
            me->MakeInterruptable(false);
            me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
            DoCastAOE(SPELL_DEACTIVATE_BEACONS, true);
            me->SetReactState(REACT_AGGRESSIVE);
            events.SetPhase(PHASE_FIGHT);
            ScheduleEvents();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            // Already in shield phase? 2 shields are enough.
            if (events.IsInPhase(PHASE_SHIELD) || _countShield == 2)
                return;
            
            // About to die? One-hit cases...
            if (int64(me->GetHealth()) - int64(damage) <= 0)
                return;

            // Shield phase happens at 66% and 33% health remaining.
            if ((me->HealthBelowPctDamaged(66, damage) && _countShield == 0) ||
                (me->HealthBelowPctDamaged(33, damage) && _countShield == 1))
                EnterShieldPhase();
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_DISABLE_BEACON_L)
                _leftBeaconDisabled = true;
            else if (action == ACTION_DISABLE_BEACON_R)
                _rightBeaconDisabled = true;
            else if (action == ACTION_HYMN_EXPIRED) // We manually deactivate beacons.
                DoCastAOE(SPELL_DEACTIVATE_BEACONS, true);

            // Exit shield phase if both beacons are disabled or channeling Reverberating Hymn finished.
            if ((_leftBeaconDisabled && _rightBeaconDisabled) || action == ACTION_HYMN_EXPIRED)
                ExitShieldPhase();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            Talk(SAY_AGGRO);
            _JustEngagedWith();

            instance->DoUpdateWorldState(WS_I_HATE_THIS_SONG, 0);
            sWorld->setWorldState(WS_I_HATE_THIS_SONG, 0); // To-do: make InstanceScript::DoUpdateWorldState do the World::setWorldState.
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

        void EnterEvadeMode(EvadeReason why) override
        {
            DoCastAOE(SPELL_DEACTIVATE_BEACONS, true);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _EnterEvadeMode();
            _DespawnAtEvade();
        }

        void OnSpellCastInterrupt(SpellInfo const* spell) override
        {
            me->MakeInterruptable(false);

            if (spell->Id == SPELL_REVERBERATING_HYMN)
            {
                events.CancelEvent(EVENT_ACHIEVEMENT_FAILED);
                DoAction(ACTION_HYMN_EXPIRED);
                ScheduleEvents();
            }
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
                    {
                        Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));
                        if (!unit)
                            unit = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                        DoCast(unit, SPELL_BURNING_LIGHT);
                        events.ScheduleEvent(EVENT_SEARING_LIGHT, Seconds(2)); // No phase.
                        break;
                    }
                    case EVENT_SEARING_LIGHT:
                        HandleSearingLight();
                        events.ScheduleEvent(EVENT_BURNING_LIGHT, Seconds(10), 0, PHASE_FIGHT);
                        break;
                    case EVENT_DIVINE_RECKONING:
                        DoCastVictim(SPELL_DIVINE_RECKONING);
                        events.ScheduleEvent(EVENT_DIVINE_RECKONING, Seconds(10), 0, PHASE_FIGHT);
                        break;
                    case EVENT_CAST_SHIELD:
                        me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
                        me->SetFacingTo(1.5708f); // Sniffs set it again
                        DoCastSelf(SPELL_SHIELD_OF_LIGHT); // Note: stun!
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_31);
                        events.ScheduleEvent(EVENT_ACTIVATE_BEACONS, Seconds(2), 0, PHASE_SHIELD);
                        break;
                    case EVENT_ACTIVATE_BEACONS:
                        Talk(EMOTE_SHIELD);
                        DoCastAOE(SPELL_ACTIVATE_BEACONS, true);
                        DoCastSelf(SPELL_REVERBERATING_HYMN);
                        HandleVisuals(SPELL_SHIELD_VISUAL_LEFT, SPELL_SHIELD_VISUAL_RIGHT, true);
                        events.ScheduleEvent(EVENT_CAST_BEAMS, Seconds(1), 0, PHASE_SHIELD);
                        events.ScheduleEvent(EVENT_ACHIEVEMENT_FAILED, Seconds(15), 0, PHASE_SHIELD);
                        break;
                    case EVENT_CAST_BEAMS:
                        HandleVisuals(SPELL_BEAM_OF_LIGHT_LEFT, SPELL_BEAM_OF_LIGHT_RIGHT, true);
                        break;
                    case EVENT_ACHIEVEMENT_FAILED: // Happens on normal too, heroic check is in dbc.
                        instance->DoUpdateWorldState(WS_I_HATE_THIS_SONG, 1);
                        sWorld->setWorldState(WS_I_HATE_THIS_SONG, 1); // To-do: make InstanceScript::DoUpdateWorldState do the World::setWorldState.
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

    private:
        void ScheduleEvents()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_DIVINE_RECKONING, Seconds(10), 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_BURNING_LIGHT, Seconds(12), 0, PHASE_FIGHT);
        }

        // To-do: Ideal for a custom spell.
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
            ++_countShield;
            _leftBeaconDisabled = false;
            _rightBeaconDisabled = false;

            me->SetReactState(REACT_PASSIVE);
            me->InterruptNonMeleeSpells(true);
            me->AttackStop();
            DoCastSelf(SPELL_TELEPORT);
            me->SetFacingTo(1.5708f, true); // Note: Wrong orientation in old sniffs - 5.144157f.
            Talk(SAY_SHIELD);

            events.ScheduleEvent(EVENT_CAST_SHIELD, Seconds(1), 0, PHASE_SHIELD);
        }

        void ExitShieldPhase()
        {
            CleanStalkers();
            me->MakeInterruptable(true);
            me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
            me->SetReactState(REACT_AGGRESSIVE);
            Talk(EMOTE_UNSHIELD);
            events.SetPhase(PHASE_FIGHT);
        }

        void CleanStalkers()
        {
            HandleVisuals(SPELL_SHIELD_VISUAL_LEFT, SPELL_SHIELD_VISUAL_RIGHT, false);
            HandleVisuals(SPELL_BEAM_OF_LIGHT_LEFT, SPELL_BEAM_OF_LIGHT_RIGHT, false);
        }

        void HandleVisuals(uint32 leftSpellId, uint32 rightSpellId, bool apply)
        {
            std::list<Creature*> stalkers;
            GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
            for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
            {
                // Target only the bottom stalkers (Y: 65.392f and 64.9004f)
                if ((*itr)->GetPositionZ() > 70.f)
                    return;

                // Left stalker X: -603.465f; right stalker X: -678.132f
                uint32 spellId = ((*itr)->GetPositionX() > -640.0f) ? leftSpellId : rightSpellId;
                if (apply)
                    (*itr)->CastSpell((*itr), spellId, true);
                else
                {
                    (*itr)->InterruptNonMeleeSpells(true, spellId);
                    (*itr)->RemoveAurasDueToSpell(spellId);
                }
            }
        }

        uint8 _countShield;
        bool _leftBeaconDisabled;
        bool _rightBeaconDisabled;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<boss_temple_guardian_anhuurAI>(creature);
    }
};

// 75592 - Divine Reckoning
class spell_anhuur_divine_reckoning : public SpellScriptLoader
{
public:
    spell_anhuur_divine_reckoning() : SpellScriptLoader("spell_anhuur_divine_reckoning") { }

    class spell_anhuur_divine_reckoning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_anhuur_divine_reckoning_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                if (!caster->isDead())
                {
                    CustomSpellValues values;
                    values.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
                    caster->CastCustomSpell(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, values, GetTarget());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_anhuur_divine_reckoning_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_anhuur_divine_reckoning_AuraScript();
    }
};

// 74930 - Shield of Light (left)
// 76573 - Shield of Light (right)

class spell_anhuur_shield_of_light : public SpellScriptLoader
{
    public:
        spell_anhuur_shield_of_light() : SpellScriptLoader("spell_anhuur_shield_of_light") { }

        class spell_anhuur_shield_of_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anhuur_shield_of_light_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                {
                    if (GameObject* go = instance->GetGameObject(DATA_ANHUUR_DOOR))
                    {
                        targets.remove_if(Trinity::HeightDifferenceCheck(go, 5.0f, false));
                        targets.remove(GetCaster());
                        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
                        targets.resize(2);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anhuur_shield_of_light_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_anhuur_shield_of_light_SpellScript();
        }
};

// 75322 - Reverberating Hymn
class spell_anhuur_reverberating_hymn : public SpellScriptLoader
{
public:
    spell_anhuur_reverberating_hymn() : SpellScriptLoader("spell_anhuur_reverberating_hymn") { }

    class spell_anhuur_reverberating_hymn_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_anhuur_reverberating_hymn_AuraScript);

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                if (Creature* anhuur = GetCaster()->ToCreature())
                    anhuur->AI()->DoAction(ACTION_HYMN_EXPIRED);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_anhuur_reverberating_hymn_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_anhuur_reverberating_hymn_AuraScript();
    }
};

// 76606 - Disable Beacon Beams L
// 76608 - Disable Beacon Beams R
class spell_anhuur_disable_beacon_beams : public SpellScriptLoader
{
    public:
        spell_anhuur_disable_beacon_beams() : SpellScriptLoader("spell_anhuur_disable_beacon_beams") { }

        class spell_anhuur_disable_beacon_beams_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anhuur_disable_beacon_beams_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->InterruptNonMeleeSpells(true, GetEffectValue());
            }

            void Notify(SpellEffIndex /*index*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* anhuur = instance->GetCreature(DATA_TEMPLE_GUARDIAN_ANHUUR))
                        anhuur->AI()->DoAction(GetEffectValue() == SPELL_BEAM_OF_LIGHT_LEFT ? ACTION_DISABLE_BEACON_L : ACTION_DISABLE_BEACON_R);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_anhuur_disable_beacon_beams_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHit += SpellEffectFn(spell_anhuur_disable_beacon_beams_SpellScript::Notify, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_anhuur_disable_beacon_beams_SpellScript();
        }
};

// 76599 - Activate Beacons
// 76600 - Deactivate Beacons
// Temporary script until Spell::EffectActivateObject is scripted.
class spell_anhuur_handle_beacons : public SpellScriptLoader
{
    public:
        spell_anhuur_handle_beacons() : SpellScriptLoader("spell_anhuur_handle_beacons") { }

        class spell_anhuur_handle_beacons_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anhuur_handle_beacons_SpellScript);

            void HandleEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                int32 script = GetSpellInfo()->Effects[effIndex].MiscValue;
                
                GameObject* beacon = GetHitGObj();
                if (!beacon)
                    return;

                beacon->SetLootState(GO_READY);
                if (script == 16) // 16 => Disable
                    beacon->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                else if (script == 17) // 17 => Activate
                    beacon->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_anhuur_handle_beacons_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ACTIVATE_OBJECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_anhuur_handle_beacons_SpellScript();
        }
};

void AddSC_boss_temple_guardian_anhuur()
{
    new boss_temple_guardian_anhuur();
    new spell_anhuur_divine_reckoning();
    new spell_anhuur_shield_of_light();
    new spell_anhuur_reverberating_hymn();
    new spell_anhuur_disable_beacon_beams();
    new spell_anhuur_handle_beacons();
}

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
#include "GridNotifiers.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

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
    EVENT_DIVINE_RECKONING       = 1,
    EVENT_BURNING_LIGHT          = 2,
    EVENT_SEAR                   = 3,
};

enum Spells
{
    SPELL_DIVINE_RECKONING       = 75592,
    SPELL_BURNING_LIGHT          = 75115,
    SPELL_REVERBERATING_HYMN     = 75322,
    SPELL_SHIELD_OF_LIGHT        = 74938,

    SPELL_ACTIVATE_BEACONS       = 76599,
    SPELL_TELEPORT               = 74969,

    SPELL_SHIELD_VISUAL_RIGHT    = 83698,
    SPELL_BEAM_OF_LIGHT_RIGHT    = 76573,

    SPELL_SHIELD_VISUAL_LEFT     = 83697,
    SPELL_BEAM_OF_LIGHT_LEFT     = 74930,

    SPELL_SEARING_LIGHT          = 75194,
};

enum Phases
{
    PHASE_SHIELDED               = 0,
    PHASE_FIRST_SHIELD           = 1, // Ready to be shielded for the first time
    PHASE_SECOND_SHIELD          = 2, // First shield already happened, ready to be shielded a second time
    PHASE_FINAL                  = 3  // Already shielded twice, ready to finish the encounter normally.
};

enum Actions
{
    ACTION_DISABLE_BEACON,
};

struct boss_temple_guardian_anhuur : public BossAI
{
    boss_temple_guardian_anhuur(Creature* creature) : BossAI(creature, BOSS_TEMPLE_GUARDIAN_ANHUUR)
    {
        Initialize();
    }

    void Initialize()
    {
        _phase = PHASE_FIRST_SHIELD;
        _oldPhase = PHASE_FIRST_SHIELD;
        _beacons = 0;
    }

    void CleanStalkers()
    {
        std::list<Creature*> stalkers;
        GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
        for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
        {
            (*itr)->RemoveAurasDueToSpell(SPELL_BEAM_OF_LIGHT_RIGHT);
            (*itr)->RemoveAurasDueToSpell(SPELL_BEAM_OF_LIGHT_LEFT);
        }
    }

    void Reset() override
    {
        Initialize();
        _Reset();
        CleanStalkers();
        me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
        events.ScheduleEvent(EVENT_DIVINE_RECKONING, 10s, 12s);
        events.ScheduleEvent(EVENT_BURNING_LIGHT, 12s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if ((me->HealthBelowPctDamaged(66, damage) && _phase == PHASE_FIRST_SHIELD) ||
            (me->HealthBelowPctDamaged(33, damage) && _phase == PHASE_SECOND_SHIELD))
        {
            _beacons = 2;
            _phase++; // Increase the phase
            _oldPhase = _phase;

            _phase = PHASE_SHIELDED;

            me->InterruptNonMeleeSpells(true);
            me->AttackStop();
            DoCast(me, SPELL_TELEPORT);

            DoCast(me, SPELL_SHIELD_OF_LIGHT);

            DoCastAOE(SPELL_ACTIVATE_BEACONS);

            GameObject* door = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ANHUUR_DOOR));
            if (door)
            {
                std::list<Creature*> stalkers;
                GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);

                stalkers.remove_if(Trinity::HeightDifferenceCheck(door, 0.0f, false)); // Target only the bottom ones
                for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                {
                    if ((*itr)->GetPositionX() > door->GetPositionX())
                    {
                        (*itr)->CastSpell((*itr), SPELL_SHIELD_VISUAL_LEFT, true);
                        (*itr)->CastSpell((*itr), SPELL_BEAM_OF_LIGHT_LEFT, true);
                    }
                    else
                    {
                        (*itr)->CastSpell((*itr), SPELL_SHIELD_VISUAL_RIGHT, true);
                        (*itr)->CastSpell((*itr), SPELL_BEAM_OF_LIGHT_RIGHT, true);
                    }
                }
            }

            DoCast(me, SPELL_REVERBERATING_HYMN);

            Talk(EMOTE_SHIELD);
            Talk(SAY_SHIELD);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_DISABLE_BEACON)
        {
            --_beacons;
            if (!_beacons)
            {
                me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
                Talk(EMOTE_UNSHIELD);
                _phase = _oldPhase;
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
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

    void JustReachedHome() override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustReachedHome();
        instance->SetBossState(BOSS_TEMPLE_GUARDIAN_ANHUUR, FAIL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom() || me->GetCurrentSpell(CURRENT_CHANNELED_SPELL) || _phase == PHASE_SHIELDED)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DIVINE_RECKONING:
                    DoCastVictim(SPELL_DIVINE_RECKONING);
                    events.ScheduleEvent(EVENT_DIVINE_RECKONING, 10s, 12s);
                    break;
                case EVENT_BURNING_LIGHT:
                {
                    Unit* unit = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me));
                    if (!unit)
                        unit = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);
                    DoCast(unit, SPELL_BURNING_LIGHT);
                    events.ScheduleEvent(EVENT_SEAR, 2s);
                    events.ScheduleEvent(EVENT_BURNING_LIGHT, 12s);
                    break;
                }
                case EVENT_SEAR:
                {
                    Unit* target = me->FindNearestCreature(NPC_SEARING_LIGHT, 100.0f);
                    if (!target)
                        break;

                    std::list<Creature*> stalkers;
                    GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
                    stalkers.remove_if(Trinity::HeightDifferenceCheck(ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ANHUUR_DOOR)), 5.0f, true));

                    if (stalkers.empty())
                        break;

                    stalkers.sort(Trinity::ObjectDistanceOrderPred(target));

                    // Get the closest statue face (any of its eyes)
                    Creature* eye1 = stalkers.front();
                    stalkers.remove(eye1); // Remove the eye.
                    stalkers.sort(Trinity::ObjectDistanceOrderPred(eye1)); // Find the second eye.
                    Creature* eye2 = stalkers.front();

                    eye1->CastSpell(eye1, SPELL_SEARING_LIGHT, true);
                    eye2->CastSpell(eye2, SPELL_SEARING_LIGHT, true);
                    break;
                }
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
    uint8 _oldPhase;
    uint8 _beacons;
};

class spell_anhuur_shield_of_light : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (InstanceScript* const script = GetCaster()->GetInstanceScript())
        {
            if (GameObject* go = ObjectAccessor::GetGameObject(*GetCaster(), script->GetGuidData(DATA_ANHUUR_DOOR)))
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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anhuur_shield_of_light::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_anhuur_disable_beacon_beams : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(GetEffectValue());
    }

    void Notify(SpellEffIndex /*index*/)
    {
        GameObject* caster = GetGObjCaster();
        if (!caster)
            return;

        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* anhuur = instance->GetCreature(BOSS_TEMPLE_GUARDIAN_ANHUUR))
                if (CreatureAI* ai = anhuur->AI())
                    ai->DoAction(ACTION_DISABLE_BEACON);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anhuur_disable_beacon_beams::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHit += SpellEffectFn(spell_anhuur_disable_beacon_beams::Notify, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_anhuur_divine_reckoning : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
        {
            CastSpellExtraArgs args;
            args.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
            caster->CastSpell(GetTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, args);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anhuur_divine_reckoning::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_boss_temple_guardian_anhuur()
{
    RegisterHallsOfOriginationCreatureAI(boss_temple_guardian_anhuur);
    RegisterSpellScript(spell_anhuur_shield_of_light);
    RegisterSpellScript(spell_anhuur_disable_beacon_beams);
    RegisterSpellScript(spell_anhuur_divine_reckoning);
}

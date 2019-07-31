/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "CommonPredicates.h"
#include "GridNotifiers.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "blackwing_descent.h"

enum Spells
{
    // Maloriak
    SPELL_ARCANE_STORM                  = 77896,
    SPELL_REMEDY                        = 77912,

    SPELL_THROW_RED_BOTTLE              = 77925,
    SPELL_THROW_BLUE_BOTTLE             = 77932,
    SPELL_THROW_GREEN_BOTTLE            = 77937,
    SPELL_DRINK_RED_BOTTLE              = 88699,
    SPELL_DRINK_BLUE_BOTTLE             = 88700,
    SPELL_DRINK_BLACK_BOTTLE            = 92828,
    SPELL_FIRE_IMBUED                   = 78896,
    SPELL_FROST_IMBUED                  = 78895,
    SPELL_SHADOW_IMBUED                 = 92716,
    SPELL_SLIME_IMBUED                  = 92917,
    SPELL_THROW_RED_BOTTLE_TRIGGERED    = 77928,
    SPELL_THROW_BLUE_BOTTLE_TRIGGERED   = 77934,
    SPELL_THROW_GREEN_BOTTLE_TRIGGERED  = 77938,
    SPELL_THROW_BLACK_BOTTLE_TRIGGERED  = 92837,
    SPELL_RELEASE_ABERRATIONS           = 77569,

    // Cauldron Trigger
    SPELL_DEBILITATING_SLIME_CAST       = 77602,
    SPELL_DEBILITATING_SLIME_KNOCKBACK  = 77948,
    SPELL_DEBILITATING_SLIME_DEBUFF     = 77615,

};

enum Events
{
    // Maloriak
    EVENT_ARCANE_STORM = 1,
    EVENT_REMEDY,
    EVENT_RELEASE_ABERRATIONS,
    EVENT_FACE_TO_CAULDRON,
    EVENT_THROW_VIAL,
    EVENT_MOVE_TO_CAULDRON,
    EVENT_DRINK_BOTTLE,
    EVENT_IMBUED_BUFF,
    EVENT_EXPLODE_CAULDRON,
    EVENT_ATTACK_PLAYERS,
};

enum Actions
{
    ACTION_SCHEDULE_EVENTS_FOR_PHASE = 1
};

enum MovePoints
{
    POINT_CAULDRON = 1
};

enum Texts
{
    // Maloriak
    SAY_AGGRO               = 0,
    SAY_RED_VIAL            = 1,
    SAY_ANNOUNCE_RED_VIAL   = 2,
    SAY_BLUE_VIAL           = 3,
    SAY_ANNOUNCE_BLUE_VIAL  = 4,
    SAY_GREEN_VIAL          = 5,
    SAY_ANNOUNCE_GREEN_VIAL = 6,
    SAY_RELEASE_ABERRATIONS = 7,
};

enum Vials
{
    VIAL_RED    = 0,
    VIAL_BLUE   = 1,
    VIAL_GREEN  = 2
};

enum GameObjectCustomAnim
{
    CUSTOM_ANIM_RED_CAULDRON    = 0,
    CUSTOM_ANIM_BLUE_CAULDRON   = 1,
    CUSTOM_ANIM_GREEN_CAULDRON  = 2,
    CUSTOM_ANIM_BLACK_CAULDRON  = 3
};

Position const CauldronMovePosition = { -106.6782f, -475.4438f, 73.45684f };

struct VialData
{
    uint8 SayTextId;
    uint8 AnnounceTextId;
    uint32 ThrowSpellId;
    uint32 DrinkSpellId;
    uint32 ImbuedSpellId;
};

std::unordered_map<uint8, VialData> vialData =
{
    { VIAL_RED,    { SAY_RED_VIAL,   SAY_ANNOUNCE_RED_VIAL,      SPELL_THROW_RED_BOTTLE,     SPELL_DRINK_RED_BOTTLE,    SPELL_FIRE_IMBUED   }},
    { VIAL_BLUE,   { SAY_BLUE_VIAL,  SAY_ANNOUNCE_BLUE_VIAL,     SPELL_THROW_BLUE_BOTTLE,    SPELL_DRINK_BLUE_BOTTLE,   SPELL_FROST_IMBUED  }},
    { VIAL_GREEN,  { SAY_GREEN_VIAL, SAY_ANNOUNCE_GREEN_VIAL,    SPELL_THROW_GREEN_BOTTLE,   0,                         SPELL_SLIME_IMBUED  }},
};

struct boss_maloriak : public BossAI
{
    boss_maloriak(Creature* creature) : BossAI(creature, DATA_MALORIAK),
        _currentVial(urand(VIAL_RED, VIAL_BLUE)), _usedVialsCount(0) { }

    void Reset() override
    {
        _Reset();
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_FACE_TO_CAULDRON, 15s + 500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_ARCANE_STORM:
                me->MakeInterruptable(false);
                me->m_Events.KillAllEvents(true);
                break;
            case SPELL_RELEASE_ABERRATIONS:
                me->MakeInterruptable(false);
                break;
            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_RELEASE_ABERRATIONS:
                Talk(SAY_RELEASE_ABERRATIONS);
                me->MakeInterruptable(false);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && motionType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_CAULDRON:
                events.ScheduleEvent(EVENT_DRINK_BOTTLE, 1s + 500ms);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SCHEDULE_EVENTS_FOR_PHASE:
                events.ScheduleEvent(EVENT_ATTACK_PLAYERS, _currentVial != VIAL_GREEN ? 1ms : 4s);

                if (_currentVial == VIAL_RED || _currentVial == VIAL_BLUE)
                {
                    events.ScheduleEvent(EVENT_ARCANE_STORM, 14s + 500ms);
                    events.ScheduleEvent(EVENT_REMEDY, 21s + 500ms);
                    events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 11s);
                }
                else if (_currentVial == VIAL_GREEN)
                {
                    if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                        cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_DEBUFF);

                    events.ScheduleEvent(EVENT_ARCANE_STORM, 8s);
                    events.ScheduleEvent(EVENT_REMEDY, 33s + 500ms);
                    events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 15s);
                }
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

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_STORM:
                {
                    me->MakeInterruptable(true);
                    DoCastSelf(SPELL_ARCANE_STORM);
                    Creature* maloriak = me;
                    me->m_Events.AddEventAtOffset([maloriak]() { maloriak->MakeInterruptable(false); }, 6s + 500ms);
                    events.Repeat(13s + 500ms);
                    break;
                }
                case EVENT_REMEDY:
                    DoCastSelf(SPELL_REMEDY);
                    break;
                case EVENT_RELEASE_ABERRATIONS:
                    me->MakeInterruptable(true);
                    DoCastAOE(SPELL_RELEASE_ABERRATIONS);
                    events.Repeat(24s + 500ms);
                    break;
                case EVENT_FACE_TO_CAULDRON:
                    events.Reset();
                    if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                    {
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFacingToObject(cauldron);

                        _currentVial = _usedVialsCount < 2 ? _currentVial == VIAL_BLUE ? VIAL_RED : VIAL_BLUE : VIAL_GREEN;
                        Talk(vialData[_currentVial].SayTextId);
                        _usedVialsCount = _usedVialsCount < 2 ? _usedVialsCount + 1 : 0;

                        events.Repeat(50s);
                        events.ScheduleEvent(EVENT_THROW_VIAL, 1s + 300ms);
                    }
                    break;
                case EVENT_THROW_VIAL:
                    DoCastSelf(vialData[_currentVial].ThrowSpellId);
                    Talk(vialData[_currentVial].AnnounceTextId);
                    events.ScheduleEvent(EVENT_MOVE_TO_CAULDRON, 1s);
                    break;
                case EVENT_MOVE_TO_CAULDRON:
                    me->GetMotionMaster()->MovePoint(POINT_CAULDRON, CauldronMovePosition);
                    break;
                case EVENT_DRINK_BOTTLE:
                    DoCastSelf(vialData[_currentVial].DrinkSpellId);
                    events.ScheduleEvent(EVENT_IMBUED_BUFF, 2s + 500ms);

                    if (_currentVial == VIAL_GREEN)
                        events.ScheduleEvent(EVENT_EXPLODE_CAULDRON, 1s);
                    break;
                case EVENT_IMBUED_BUFF:
                    DoCastSelf(vialData[_currentVial].ImbuedSpellId);
                    DoAction(ACTION_SCHEDULE_EVENTS_FOR_PHASE);
                    break;
                case EVENT_EXPLODE_CAULDRON:
                    if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                    {
                        cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_CAST);
                        cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_KNOCKBACK);
                    }
                    break;
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    uint8 _currentVial;
    uint8 _usedVialsCount;
};

class spell_maloriak_throw_bottle : public SpellScript
{
    PrepareSpellScript(spell_maloriak_throw_bottle);

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_maloriak_throw_bottle::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_maloriak_throw_bottle_triggered : public SpellScript
{
    PrepareSpellScript(spell_maloriak_throw_bottle_triggered);

        bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_THROW_RED_BOTTLE_TRIGGERED,
                SPELL_THROW_BLUE_BOTTLE_TRIGGERED,
                SPELL_THROW_GREEN_BOTTLE_TRIGGERED,
                SPELL_THROW_BLACK_BOTTLE_TRIGGERED
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        InstanceScript* instance = GetHitUnit()->GetInstanceScript();
        if (!instance)
            return;

        if (GameObject* cauldron = instance->GetGameObject(DATA_CAULDRON))
        {
            switch (GetSpellInfo()->Id)
            {
                case SPELL_THROW_RED_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_RED_CAULDRON);
                    break;
                case SPELL_THROW_BLUE_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_BLUE_CAULDRON);
                    break;
                case SPELL_THROW_GREEN_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_GREEN_CAULDRON);
                    break;
                case SPELL_THROW_BLACK_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_BLACK_CAULDRON);
                    break;
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_maloriak_throw_bottle_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_maloriak()
{
    RegisterBlackwingDescentCreatureAI(boss_maloriak);
    RegisterSpellScript(spell_maloriak_throw_bottle);
    RegisterSpellScript(spell_maloriak_throw_bottle_triggered);
}

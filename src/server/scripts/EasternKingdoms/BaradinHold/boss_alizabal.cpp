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
#include "baradin_hold.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    // Alizabal
    SAY_INTRO           = 0,
    SAY_AGGRO           = 1,
    SAY_SEETHING_HATE   = 2,
    SAY_ANNOUNCE_SKEWER = 3,
    SAY_SKEWER          = 4,
    SAY_BLADE_DANCE     = 5,
    SAY_SLAY            = 6,
    SAY_DEATH           = 7,
    SAY_DISENGAGE       = 8
};

enum Spells
{
    // Alizabal
    SPELL_SKEWER                    = 104936,
    SPELL_BLADE_DANCE               = 105828,
    SPELL_BLADE_DANCE_CHARGE        = 105726,
    SPELL_BLADE_DANCE_ROOT          = 105784,
    SPELL_SEETHING_HATE_PERIODIC    = 105067,
    SPELL_BERSERK                   = 47008
};

#define SPELL_SEETHING_HATE_TARGETING RAID_MODE<uint32>(105065, 108090)

enum Actions
{
    // Alizabal
    ACTION_INTRO = 1
};

enum Events
{
    // Alizabal
    EVENT_SEETHING_HATE = 1,
    EVENT_SKEWER,
    EVENT_BLADE_DANCE,
    EVENT_BLADE_DANCE_CHARGE,
    EVENT_BERSERK
};

struct boss_alizabal : public BossAI
{
    boss_alizabal(Creature* creature) : BossAI(creature, DATA_ALIZABAL), _bladeDanceChargeCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_SEETHING_HATE, 9s + 500ms);
        events.ScheduleEvent(EVENT_SKEWER, 18s);
        events.ScheduleEvent(EVENT_BLADE_DANCE, 27s + 500ms);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SKEWER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SEETHING_HATE_PERIODIC);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SKEWER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SEETHING_HATE_PERIODIC);
        Talk(SAY_DISENGAGE);
        _DespawnAtEvade();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INTRO:
                Talk(SAY_INTRO);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SEETHING_HATE_TARGETING)
            Talk(SAY_SEETHING_HATE, target);
        else if (spell->Id == SPELL_SKEWER)
        {
            Talk(SAY_ANNOUNCE_SKEWER, target);
            Talk(SAY_SKEWER, target);
        }
    }

    void MovementInform(uint32 motionType, uint32 id) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        if (id == EVENT_CHARGE)
            DoCastSelf(SPELL_BLADE_DANCE_ROOT);
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
                case EVENT_SEETHING_HATE:
                    DoCastAOE(SPELL_SEETHING_HATE_TARGETING);
                    break;
                case EVENT_SKEWER:
                    DoCastVictim(SPELL_SKEWER);
                    break;
                case EVENT_BLADE_DANCE:
                    Talk(SAY_BLADE_DANCE, me);
                    DoCastSelf(SPELL_BLADE_DANCE);
                    _bladeDanceChargeCount = 0;
                    events.ScheduleEvent(EVENT_BLADE_DANCE_CHARGE, 100ms);
                    events.Repeat(1min);
                    ScheduleEvents();
                    break;
                case EVENT_BLADE_DANCE_CHARGE:
                    if (_bladeDanceChargeCount < 3)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.f, true))
                            DoCast(target, SPELL_BLADE_DANCE_CHARGE);
                        else
                            DoCastVictim(SPELL_BLADE_DANCE_CHARGE);

                        events.Repeat(4s + 100ms);
                        ++_bladeDanceChargeCount;
                    }
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    uint8 _bladeDanceChargeCount;

    void ScheduleEvents()
    {
        events.ScheduleEvent(EVENT_SKEWER, 23s);
        events.ScheduleEvent(EVENT_SEETHING_HATE, 31s + 400ms);
        events.ScheduleEvent(EVENT_SKEWER, 43s + 400ms);
        events.ScheduleEvent(EVENT_SEETHING_HATE, 51s + 800ms);
    }
};

class spell_alizabal_seething_hate : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();

        if (targets.size() > 1)
        {
            targets.remove_if([caster](WorldObject* target)->bool
            {
                return caster->GetVictim() == target;
            });
        }

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetEffectValue());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_alizabal_seething_hate::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_alizabal_seething_hate::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class at_alizabal_intro : public OnlyOnceAreaTriggerScript
{
public:
    at_alizabal_intro() : OnlyOnceAreaTriggerScript("at_alizabal_intro") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* alizabal = instance->GetCreature(DATA_ALIZABAL))
                if (alizabal->IsAIEnabled)
                    alizabal->AI()->DoAction(ACTION_INTRO);

        return true;
    }
};

void AddSC_boss_alizabal()
{
    RegisterBaradinHoldCreatureAI(boss_alizabal);
    RegisterSpellScript(spell_alizabal_seething_hate);
    new at_alizabal_intro();
}

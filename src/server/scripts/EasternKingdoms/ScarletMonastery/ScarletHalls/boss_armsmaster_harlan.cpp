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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "scarlet_halls.h"

enum HarlanSpells
{
    SPELL_HARLAN_DRAGONS_REACH      = 111217,
    SPELL_HARLAN_HEROIC_LEAP_JUMP   = 111219,
    SPELL_HARLAN_BLADES_OF_LIGHT    = 111216
};

enum HarlanEvents
{
    EVENT_HARLAN_DRAGONS_REACH      = 1,
    EVENT_HARLAN_CALL_FOR_HELP,
    EVENT_HARLAN_HEROIC_LEAP,
    EVENT_HARLAN_BERSERKER_RAGE,
    EVENT_HARLAN_BLADES_OF_LIGHT
};

enum HarlanTexts
{
    SAY_HARLAN_AGGRO                = 0,
    SAY_HARLAN_CALL_FOR_HELP        = 1,
    ANNOUNCE_HARLAN_CALL_FOR_HELP   = 2,
    ANNOUNCE_HARLAN_BLADE_FOR_LIGHT = 3,
    SAY_HARLAN_SCARLET_DEFENDER_DIE = 4,
    SAY_HARLAN_DEATH                = 5
};

enum HarlanPathIds
{
    PATH_HARLAN_BLADES_OF_LIGHT_LEFT    = 5863200,
    PATH_HARLAN_BLADES_OF_LIGHT_RIGHT   = 5863201
};

// 58632 - Armsmaster Harlan
struct boss_armsmaster_harlan : public BossAI
{
    boss_armsmaster_harlan(Creature* creature) : BossAI(creature, DATA_ARMSMASTER_HARAN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_HARLAN_AGGRO);
        events.ScheduleEvent(EVENT_HARLAN_DRAGONS_REACH, 7s);
        events.ScheduleEvent(EVENT_HARLAN_CALL_FOR_HELP, 20s);
        events.ScheduleEvent(EVENT_HARLAN_HEROIC_LEAP, 41s);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_HARLAN_DEATH);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == EVENT_JUMP)
        {
            me->SetReactState(REACT_PASSIVE);
            events.ScheduleEvent(EVENT_HARLAN_BLADES_OF_LIGHT, 10s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_HARLAN_DRAGONS_REACH:
                DoCastVictim(SPELL_HARLAN_DRAGONS_REACH);
                events.ScheduleEvent(EVENT_HARLAN_DRAGONS_REACH, 7s);
                break;
            case EVENT_HARLAN_CALL_FOR_HELP:
                Talk(SAY_HARLAN_CALL_FOR_HELP);
                break;
            case EVENT_HARLAN_HEROIC_LEAP:
                DoCast(SPELL_HARLAN_HEROIC_LEAP_JUMP);
                events.ScheduleEvent(EVENT_HARLAN_HEROIC_LEAP, 41s);
                break;
            case EVENT_HARLAN_BERSERKER_RAGE:
                break;
            case EVENT_HARLAN_BLADES_OF_LIGHT:
                Talk(ANNOUNCE_HARLAN_BLADE_FOR_LIGHT);
                DoCastSelf(SPELL_HARLAN_BLADES_OF_LIGHT);
                break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        
    }
};

void AddSC_boss_armsmaster_harlan()
{
    // Creature
    RegisterScarletHallsCreatureAI(boss_armsmaster_harlan);

    // Spells
}

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

#include "zulgurub.h"
#include "DBCStructure.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_FLEEING                 = 1,
    SAY_MINION_DESTROY          = 2,
    SAY_PROTECT_ALTAR           = 3,
    SAY_ENTRANCE                = 4
};

enum Spells
{
    SPELL_BLOOD_SIPHON          = 24322, // Buggy ?
    SPELL_CORRUPTED_BLOOD       = 24328,
    SPELL_CAUSE_INSANITY        = 24327, // Spell needs scripting.
    SPELL_WILL_OF_HAKKAR        = 24178,
    SPELL_ENRAGE                = 24318,

    // The Aspects of all High Priests spells
    SPELL_ASPECT_OF_JEKLIK      = 24687,
    SPELL_ASPECT_OF_VENOXIS     = 24688,
    SPELL_ASPECT_OF_MARLI       = 24686,
    SPELL_ASPECT_OF_THEKAL      = 24689,
    SPELL_ASPECT_OF_ARLOKK      = 24690
};

enum Events
{
    EVENT_BLOOD_SIPHON          = 1,
    EVENT_CORRUPTED_BLOOD       = 2,
    EVENT_CAUSE_INSANITY        = 3,     // Spell needs scripting. Event disabled
    EVENT_WILL_OF_HAKKAR        = 4,
    EVENT_ENRAGE                = 5,

    // The Aspects of all High Priests events
    EVENT_ASPECT_OF_JEKLIK      = 6,
    EVENT_ASPECT_OF_VENOXIS     = 7,
    EVENT_ASPECT_OF_MARLI       = 8,
    EVENT_ASPECT_OF_THEKAL      = 9,
    EVENT_ASPECT_OF_ARLOKK      = 10
};

struct boss_hakkar : public BossAI
{
    boss_hakkar(Creature* creature) : BossAI(creature, DATA_HAKKAR) { }

    void Reset() override
    {
        _Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_BLOOD_SIPHON, 90s);
        events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, 25s);
        events.ScheduleEvent(EVENT_CAUSE_INSANITY, 15s);
        events.ScheduleEvent(EVENT_WILL_OF_HAKKAR, 15s);
        events.ScheduleEvent(EVENT_ENRAGE, 10min);
        if (instance->GetBossState(DATA_JEKLIK) != DONE)
            events.ScheduleEvent(EVENT_ASPECT_OF_JEKLIK, 4s);
        if (instance->GetBossState(DATA_VENOXIS) != DONE)
            events.ScheduleEvent(EVENT_ASPECT_OF_VENOXIS, 7s);
        if (instance->GetBossState(DATA_MARLI) != DONE)
            events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 12s);
        if (instance->GetBossState(DATA_THEKAL) != DONE)
            events.ScheduleEvent(EVENT_ASPECT_OF_THEKAL, 8s);
        if (instance->GetBossState(DATA_ARLOKK) != DONE)
            events.ScheduleEvent(EVENT_ASPECT_OF_ARLOKK, 18s);
        Talk(SAY_AGGRO);
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
                case EVENT_BLOOD_SIPHON:
                    DoCastVictim(SPELL_BLOOD_SIPHON, true);
                    events.ScheduleEvent(EVENT_BLOOD_SIPHON, 90s);
                    break;
                case EVENT_CORRUPTED_BLOOD:
                    DoCastVictim(SPELL_CORRUPTED_BLOOD, true);
                    events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, 30s, 45s);
                    break;
                case EVENT_CAUSE_INSANITY:
                    // DoCast(SelectTarget(SelectTargetMethod::Random, 0, 100, true), SPELL_CAUSE_INSANITY);
                    // events.ScheduleEvent(EVENT_CAUSE_INSANITY, 35s, 45s);
                    break;
                case EVENT_WILL_OF_HAKKAR:
                {
                    // Mind Control is only triggered when there is more than one unit currently fighting Hakkar, including pets/guardians
                    // But it is only actually cast on the player with the highest threat
                    std::list<Unit*> unitList;
                    SelectTargetList(unitList, 2, SelectTargetMethod::MaxThreat, 0, 0.0f, false);
                    if (unitList.size() > 1)
                        DoCast(SelectTarget(SelectTargetMethod::MaxThreat, 0, 100, true), SPELL_WILL_OF_HAKKAR);
                    events.ScheduleEvent(EVENT_WILL_OF_HAKKAR, 25s, 35s);
                    break;
                }
                case EVENT_ENRAGE:
                    if (!me->HasAura(SPELL_ENRAGE))
                        DoCast(me, SPELL_ENRAGE);
                    events.ScheduleEvent(EVENT_ENRAGE, 90s);
                    break;
                case EVENT_ASPECT_OF_JEKLIK:
                    DoCastVictim(SPELL_ASPECT_OF_JEKLIK, true);
                    events.ScheduleEvent(EVENT_ASPECT_OF_JEKLIK, 10s, 14s);
                    break;
                case EVENT_ASPECT_OF_VENOXIS:
                    DoCastVictim(SPELL_ASPECT_OF_VENOXIS, true);
                    events.ScheduleEvent(EVENT_ASPECT_OF_VENOXIS, 8s);
                    break;
                case EVENT_ASPECT_OF_MARLI:
                    DoCastVictim(SPELL_ASPECT_OF_MARLI, true);
                    events.ScheduleEvent(EVENT_ASPECT_OF_MARLI, 10s);
                    break;
                case EVENT_ASPECT_OF_THEKAL:
                    DoCastVictim(SPELL_ASPECT_OF_THEKAL, true);
                    events.ScheduleEvent(EVENT_ASPECT_OF_THEKAL, 15s);
                    break;
                case EVENT_ASPECT_OF_ARLOKK:
                    DoCastVictim(SPELL_ASPECT_OF_ARLOKK, true);
                    events.ScheduleEvent(EVENT_ASPECT_OF_ARLOKK, 10s, 15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

class at_zulgurub_entrance : public OnlyOnceAreaTriggerScript
{
public:
    at_zulgurub_entrance() : OnlyOnceAreaTriggerScript("at_zulgurub_entrance") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* areaTrigger) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance || instance->GetBossState(DATA_HAKKAR) == DONE)
            return true;

        if (Creature* hakkar = instance->GetCreature(DATA_HAKKAR))
        {
            switch (areaTrigger->ID)
            {
                case AREA_TRIGGER_1:
                    hakkar->AI()->Talk(SAY_ENTRANCE);
                    break;
                case AREA_TRIGGER_2:
                    hakkar->AI()->Talk(SAY_PROTECT_ALTAR);
                    break;
                case AREA_TRIGGER_3:
                    hakkar->AI()->Talk(SAY_MINION_DESTROY);
                    break;
                default:
                    break;
            }
        }

        return true;
    }
};

void AddSC_boss_hakkar()
{
    RegisterZulGurubCreatureAI(boss_hakkar);
    new at_zulgurub_entrance();
}

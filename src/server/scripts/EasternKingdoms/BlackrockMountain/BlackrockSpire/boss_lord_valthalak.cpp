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
#include "blackrock_spire.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_FRENZY                    = 8269,
    SPELL_SUMMON_SPECTRAL_ASSASSIN  = 27249,
    SPELL_SHADOW_BOLT_VOLLEY        = 27382,
    SPELL_SHADOW_WRATH              = 27286
};

enum Says
{
    EMOTE_FRENZY                    = 0
};

enum Events
{
    EVENT_SUMMON_SPECTRAL_ASSASSIN  = 1,
    EVENT_SHADOW_BOLT_VOLLEY        = 2,
    EVENT_SHADOW_WRATH              = 3
};

struct boss_lord_valthalak : public BossAI
{
    boss_lord_valthalak(Creature* creature) : BossAI(creature, DATA_LORD_VALTHALAK)
    {
        Initialize();
    }

    void Initialize()
    {
        frenzy40 = false;
        frenzy15 = false;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_SUMMON_SPECTRAL_ASSASSIN, 6s, 8s);
        events.ScheduleEvent(EVENT_SHADOW_WRATH, 9s, 18s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SetData(DATA_LORD_VALTHALAK, DONE);
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
                case EVENT_SUMMON_SPECTRAL_ASSASSIN:
                    DoCast(me, SPELL_SUMMON_SPECTRAL_ASSASSIN);
                    events.ScheduleEvent(EVENT_SUMMON_SPECTRAL_ASSASSIN, 30s, 35s);
                    break;
                case EVENT_SHADOW_BOLT_VOLLEY:
                    DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 4s, 6s);
                    break;
                case EVENT_SHADOW_WRATH:
                    DoCastVictim(SPELL_SHADOW_WRATH);
                    events.ScheduleEvent(EVENT_SHADOW_WRATH, 19s, 24s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (!frenzy40)
        {
            if (HealthBelowPct(40))
            {
                DoCast(me, SPELL_FRENZY);
                events.CancelEvent(EVENT_SUMMON_SPECTRAL_ASSASSIN);
                frenzy40 = true;
            }
        }

        if (!frenzy15)
        {
            if (HealthBelowPct(15))
            {
                DoCast(me, SPELL_FRENZY);
                events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 7s, 14s);
                frenzy15 = true;
            }
        }
    }
    private:
        bool frenzy40;
        bool frenzy15;
};

void AddSC_boss_lord_valthalak()
{
    RegisterBlackrockSpireCreatureAI(boss_lord_valthalak);
}

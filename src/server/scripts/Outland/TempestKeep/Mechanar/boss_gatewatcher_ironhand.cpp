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
#include "mechanar.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

enum IronHandTexts
{
    SAY_AGGRO                      = 0,
    SAY_HAMMER                     = 1,
    SAY_SLAY                       = 2,
    SAY_DEATH                      = 3,
    EMOTE_HAMMER                   = 4,
    EMOTE_DEATH                    = 5
};

enum IronHandSpells
{
    SPELL_STREAM_OF_MACHINE_FLUID  = 35311,
    SPELL_HAMMER_PUNCH             = 35326,
    SPELL_JACKHAMMER               = 35327,
    SPELL_SHADOW_POWER             = 35322
};

enum IronHandEvents
{
    EVENT_STREAM_OF_MACHINE_FLUID  = 1,
    EVENT_HAMMER_PUNCH,
    EVENT_JACKHAMMER,
    EVENT_SHADOW_POWER
};

// 19710 - Gatewatcher Iron-Hand
struct boss_gatewatcher_iron_hand : public BossAI
{
    boss_gatewatcher_iron_hand(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_IRON_HAND) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 15s, 25s);
        events.ScheduleEvent(EVENT_HAMMER_PUNCH, 15s, 25s);
        events.ScheduleEvent(EVENT_JACKHAMMER, 10s, 30s);
        events.ScheduleEvent(EVENT_SHADOW_POWER, 25s);
        Talk(SAY_AGGRO);
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_JACKHAMMER, me))
            Talk(EMOTE_HAMMER);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        // Only in normal mode
        if (spell->Id == SPELL_JACKHAMMER)
            Talk(SAY_HAMMER);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        Talk(EMOTE_DEATH);
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
                case EVENT_STREAM_OF_MACHINE_FLUID:
                    DoCastSelf(SPELL_STREAM_OF_MACHINE_FLUID);
                    events.Repeat(35s, 50s);
                    break;
                case EVENT_HAMMER_PUNCH:
                    DoCastVictim(SPELL_HAMMER_PUNCH);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_JACKHAMMER:
                    DoCastSelf(SPELL_JACKHAMMER);
                    events.Repeat(30s);
                    break;
                case EVENT_SHADOW_POWER:
                    DoCastSelf(SPELL_SHADOW_POWER);
                    events.Repeat(25s, 35s);
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

void AddSC_boss_gatewatcher_iron_hand()
{
    RegisterMechanarCreatureAI(boss_gatewatcher_iron_hand);
}

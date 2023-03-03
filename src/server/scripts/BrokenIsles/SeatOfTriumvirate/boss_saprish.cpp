/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "seat_of_triumvirate.h"

enum Spells
{
    //Breath of Corruption
    SPELL_BOC_TARGET = 191325, //Targets a tank
    SPELL_BOC_DAMAGE = 191326, //Ticks every second for 3 seconds

    //Down Draft
    SPELL_DD_TARGET = 199345,
    SPELL_DD_AT = 199348,
    SPELL_DD_DOT = 220855,
    SPELL_DD_CHARGE = 199351,

    //Earthshaking Roar
    //                        199385 ?
    SPELL_ER_TARGET = 199389,
    SPELL_ER_DAMAGE = 218587,

    //Falling Rocks
    SPELL_FR_TRIGGERMISSILE = 141461,
    SPELL_FR_MISSILE = 141463,
    SPELL_FR_AT = 163897,
    SPELL_FR_DOT = 163900,
    SPELL_FR_AT_1 = 199458,

    SPELL_DISTURB_EGG = 199313
};

// 122316
struct boss_saprish : public BossAI
{
    boss_saprish(Creature* creature) : BossAI(creature, DATA_SAPRISH) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_BOC_TARGET, 15s);
        events.ScheduleEvent(SPELL_ER_TARGET, 21s);
        events.ScheduleEvent(SPELL_DD_TARGET, 40s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_BOC_TARGET:
        {
            events.Repeat(15s);
            DoCastVictim(SPELL_BOC_TARGET);
            break;
        }
        case SPELL_ER_TARGET:
        {
            events.Repeat(21s);
            DoCastAOE(SPELL_ER_TARGET);
            break;
        }
        case SPELL_DD_TARGET:
        {
            events.Repeat(40s);
            DoCastSelf(SPELL_DD_TARGET);
        }
        }
    }
};

void AddSC_boss_saprish()
{
    RegisterCreatureAI(boss_saprish);
}

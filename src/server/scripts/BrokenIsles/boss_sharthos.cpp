/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

enum Spells
{
    SPELL_TAIL_LASH             = 215806,
    SPELL_NIGHTMARE_BREATH      = 215821,
    SPELL_BURNING_EARTH         = 215860, // Todo : Fill spell_areatrigger table
    SPELL_DREAD_FLAME           = 216043,
    SPELL_CRY_OF_THE_TORMENTED  = 216044,
};

// 108678
struct boss_sharthos : public WorldBossAI
{
    boss_sharthos(Creature* creature) : WorldBossAI(creature) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_TAIL_LASH,               5s, 7s);
        events.ScheduleEvent(SPELL_NIGHTMARE_BREATH,        5s);
        events.ScheduleEvent(SPELL_BURNING_EARTH,           10s);
        events.ScheduleEvent(SPELL_DREAD_FLAME,             10s, 20s);
        events.ScheduleEvent(SPELL_CRY_OF_THE_TORMENTED,    55s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_TAIL_LASH:
                DoCastAOE(SPELL_TAIL_LASH);
                events.Repeat(5s, 7s);
                break;
            case SPELL_NIGHTMARE_BREATH:
                DoCastVictim(SPELL_NIGHTMARE_BREATH);
                events.Repeat(30s);
                break;
            case SPELL_BURNING_EARTH:
                DoCastRandom(SPELL_BURNING_EARTH, 0.f);
                events.Repeat(20s);
                break;
            case SPELL_DREAD_FLAME:
                DoCastRandom(SPELL_DREAD_FLAME, 0.f);
                events.Repeat(10s, 20s);
                break;
            case SPELL_CRY_OF_THE_TORMENTED:
                DoCastAOE(SPELL_CRY_OF_THE_TORMENTED);
                events.Repeat(55s);
                break;
            default:
                break;
        }
    }
};

void AddSC_boss_sharthos()
{
    RegisterCreatureAI(boss_sharthos);
}

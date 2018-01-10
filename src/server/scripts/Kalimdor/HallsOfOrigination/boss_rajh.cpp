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

#include "halls_of_origination.h"

enum Spells
{
    // Rajh
    SPELL_SOLAR_WINDS_DUMMY     = 74104,
    SPELL_SOLAR_WINDS_SUMMON    = 74106,
    SPELL_SUMMON_SUN_ORB        = 80352,
    SPELL_SUN_STRIKE            = 73872,
    SPELL_BLESSING_OF_THE_SUN   = 76352,
    SPELL_INFERNO_LEAP_DUMMY    = 87650,
    SPELL_INFERNO_LEAP_VEHICLE  = 87653,

    // Solar Winds
    SPELL_SOLAR_WINDS_PERIODIC  = 74107,

    // Orb of the Sun
    SPELL_SUMMON_METEOR         = 76375,
    SPELL_RIDE_VEHICLE          = 43671,
};

enum Texts
{
    SAY_DEATH           = 0,
    SAY_AGGRO           = 1,
    SAY_SPECIAL         = 2,
    SAY_PLAYER_KILL     = 3,
};

Position const RajhMiddlePos = { -318.5936f, 192.8621f, 343.9443f };

// 39378 Rajh <Construct of the Sun>
class boss_rajh : public CreatureScript
{
public:
    boss_rajh() : CreatureScript("boss_rajh") { }

    struct boss_rajhAI : public BossAI
    {
        boss_rajhAI(Creature* creature) : BossAI(creature, DATA_RAJH) { }

        // To-do
    };
    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetHallsOfOriginationAI<boss_rajhAI>(creature);
    }
};

void AddSC_boss_rajh()
{
    new boss_rajh();
}

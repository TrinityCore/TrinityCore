/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ArenaMap.h"

void ArenaMap::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

void ArenaMap::InitializePreparationDelayTimes()
{
    PreparationDelayTimers[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    PreparationDelayTimers[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    PreparationDelayTimers[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    PreparationDelayTimers[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
}

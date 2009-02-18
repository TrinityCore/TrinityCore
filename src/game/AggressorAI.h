/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_AGGRESSORAI_H
#define TRINITY_AGGRESSORAI_H

#include "CreatureAI.h"
#include "Timer.h"

class Creature;

class TRINITY_DLL_DECL AggressorAI : public CreatureAI
{
    enum AggressorState
    {
        STATE_NORMAL = 1,
        STATE_LOOK_AT_VICTIM = 2
    };

    public:

        AggressorAI(Creature *c);

        void EnterEvadeMode();

        void UpdateAI(const uint32);
        static int Permissible(const Creature *);

    private:
        Creature &i_creature;
        uint64 i_victimGuid;
        AggressorState i_state;
        TimeTracker i_tracker;
};
#endif


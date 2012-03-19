/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_GRIDSTATES_H
#define TRINITY_GRIDSTATES_H

#include "Map.h"
#include "Object.h"

class GridState
{
    public:
#ifdef TRINITY_DEBUG
#define MAGIC_TESTVAL 0xFBE823BA
        GridState() { i_Magic = MAGIC_TESTVAL; }
        bool checkMagic()
        {
            if (i_Magic != MAGIC_TESTVAL)
            {
                sLog->outError("!!! GridState: Magic value gone !!!");
                return false;
            }
            return true;
        }
        void setMagic() { i_Magic = MAGIC_TESTVAL; }
        unsigned int i_Magic;
#endif
        virtual void Update(Map &, NGridType&, GridInfo &, const uint32 t_diff) const = 0;
};

class InvalidState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, const uint32 t_diff) const;
};

class ActiveState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, const uint32 t_diff) const;
};

class IdleState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, const uint32 t_diff) const;
};

class RemovalState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, const uint32 t_diff) const;
};
#endif


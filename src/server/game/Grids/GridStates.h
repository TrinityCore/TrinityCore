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

#ifndef TRINITY_GRIDSTATES_H
#define TRINITY_GRIDSTATES_H

#include "GridDefines.h"
#include "NGrid.h"

class Map;

class TC_GAME_API GridState
{
    public:
        virtual ~GridState() { };
        virtual void Update(Map &, NGridType&, GridInfo &, uint32 t_diff) const = 0;
};

class TC_GAME_API InvalidState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, uint32 t_diff) const override;
};

class TC_GAME_API ActiveState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, uint32 t_diff) const override;
};

class TC_GAME_API IdleState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, uint32 t_diff) const override;
};

class TC_GAME_API RemovalState : public GridState
{
    public:
        void Update(Map &, NGridType &, GridInfo &, uint32 t_diff) const override;
};
#endif

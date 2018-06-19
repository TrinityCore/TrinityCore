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

#ifndef TRINITY_GARRISONAI_H
#define TRINITY_GARRISONAI_H

#include "Define.h"

class Garrison;
class Player;

class TC_GAME_API GarrisonAI
{
    protected:
        Garrison* const garrison;
    public:
        explicit GarrisonAI(Garrison* gar);
        virtual ~GarrisonAI();

        // Called when player check if he can upgrade his garrison
        virtual bool OnCheckUpgradeable() { return true; }

        // Called when a player enter the garrison
        virtual void OnPlayerEnter(Player* /*player*/) { }

        // Called when a player leave the garrison
        virtual void OnPlayerLeave(Player* /*player*/) { }
};

class NullGarrisonAI : public GarrisonAI
{
    public:
        explicit NullGarrisonAI(Garrison* garrison) : GarrisonAI(garrison) { }
};

#endif

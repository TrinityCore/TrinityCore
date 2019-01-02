/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_COMMONHELPERS_H
#define TRINITY_COMMONHELPERS_H

#include "Define.h"

class Player;

namespace Trinity
{
    namespace Helpers
    {
        namespace Entity
        {
            // Return values range from 0 (left-most spec) to 2 (right-most spec). If two specs have the same number of talent points, the left-most of those specs is returned.
            TC_GAME_API uint8 GetPlayerSpecialization(Player const* who);
            TC_GAME_API bool IsPlayerHealer(Player const* who);
            bool IsPlayerRangedAttacker(Player const* who);
        }
    }
}

#endif //TRINITY_COMMONHELPERS_H

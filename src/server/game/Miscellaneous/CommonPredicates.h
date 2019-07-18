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

#ifndef TRINITY_COMMONPREDICATES_H
#define TRINITY_COMMONPREDICATES_H

#include "Define.h"

class Unit;
class WorldObject;

namespace Trinity
{
    namespace Predicates
    {
        /// Checks the given container for the attacker's current victim and either keeps it as only element or removes it
        class TC_GAME_API UnitVictimCheck
        {
            public:
                UnitVictimCheck(Unit* attacker, bool keepVictim) : _attacker(attacker), _keepVictim(keepVictim) { }
                bool operator()(WorldObject* obj) const;
                bool operator()(Unit* obj) const;
            private:
                bool _keepVictim;
                Unit* _attacker;
        };
    }
}


#endif //TRINITY_COMMONPREDICATES_H

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
        /// Checks the given container's elements for the attacker's current victim and removes it
        class TC_GAME_API IsVictimOfAttacker
        {
            public:
                IsVictimOfAttacker(Unit* attacker) : _attacker(attacker) { }
                bool operator()(WorldObject* obj) const;
                bool operator()(Unit* obj) const;
            private:
                Unit* _attacker;
        };

        template <typename PRED>
        class TC_GAME_API Inverter
        {
            public:
                Inverter(PRED&& p) : _child(std::move(p)) { }

                template <typename... Args>
                bool operator()(Args&&... args)
                {
                    return !_child(std::forward<Args>(args)...);
                }

                template <typename... Args>
                bool operator()(Args&&... args) const
                {
                    return !_child(std::forward<Args>(args)...);
                }

            private:
                PRED _child;
        };

        template <typename PRED>
        /// Inverts the given predicate to return the opposite result
        Inverter<PRED> Invert(PRED&& p) { return Inverter<PRED>(std::forward<PRED>(p)); }
    }
}


#endif //TRINITY_COMMONPREDICATES_H

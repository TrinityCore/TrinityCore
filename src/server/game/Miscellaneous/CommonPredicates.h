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

#ifndef TRINITY_COMMONPREDICATES_H
#define TRINITY_COMMONPREDICATES_H

#include "Define.h"
#include <utility>

class WorldObject;
class Unit;

namespace Trinity
{
    namespace Predicates
    {
        /// Only returns true for the given attacker's current victim, if any
        class TC_GAME_API IsVictimOf
        {
            public:
                IsVictimOf(Unit const* attacker);
                bool operator()(WorldObject const* obj) const { return obj && (_victim == obj); }
            private:
                WorldObject const* _victim;
        };

        /// Only returns true when the object is in the given phase ID
        class TC_GAME_API HasPhaseId
        {
            public:
                HasPhaseId(uint32 const phaseId) : _phaseId(phaseId) { }
                bool operator()(WorldObject const* obj) const;
            private:
                uint32 const _phaseId;
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

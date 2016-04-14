/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_HOMEMOVEMENTGENERATOR_H
#define TRINITY_HOMEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "Timer.h"

template <class T>
class HomeMovementGenerator;

template <>
class HomeMovementGenerator<Creature> : public MovementGeneratorMedium< Creature, HomeMovementGenerator<Creature> >
{
    public:

        HomeMovementGenerator() : m_arrived(false), m_travelInitialized(false), m_despawnTimer(30 * IN_MILLISECONDS) { }
        ~HomeMovementGenerator() { }

        void DoInitialize(Creature*);
        void DoFinalize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, const uint32);
        MovementGeneratorType GetMovementGeneratorType() const override { return HOME_MOTION_TYPE; }

    protected:
        void SetTargetLocation(Creature*);
        bool m_arrived;
        bool m_travelInitialized;
        TimeTrackerSmall m_despawnTimer;
};
#endif

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

#ifndef TRINITY_FLEEINGMOVEMENTGENERATOR_H
#define TRINITY_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class FleeingMovementGenerator : public MovementGeneratorMedium< T, FleeingMovementGenerator<T> >
{
    public:
        FleeingMovementGenerator(uint64 fright) : _frightGUID(fright), _nextCheckTime(0) {}

        void Initialize(T*);
        void Finalize(T*);
        void Reset(T*);
        bool Update(T*, const uint32&);

        MovementGeneratorType GetMovementGeneratorType() { return FLEEING_MOTION_TYPE; }

    private:
        void _setTargetLocation(T* owner);
        bool _getPoint(T* owner, float &x, float &y, float &z);
        bool _setMoveData(T* owner);
        void _Init(T*);

        bool is_water_ok   :1;
        bool is_land_ok    :1;
        bool _only_forward :1;

        float _caster_x;
        float _caster_y;
        float _caster_z;
        float _last_distance_from_caster;
        float _to_distance_from_caster;
        float _cur_angle;
        uint64 _frightGUID;
        TimeTracker _nextCheckTime;
};

class TimedFleeingMovementGenerator : public FleeingMovementGenerator<Creature>
{
    public:
        TimedFleeingMovementGenerator(uint64 fright, uint32 time) : FleeingMovementGenerator<Creature>(fright), _totalFleeTime(time) {}

        MovementGeneratorType GetMovementGeneratorType() { return TIMED_FLEEING_MOTION_TYPE; }
        bool Update(Unit* , const uint32&);
        void Finalize(Unit* );

    private:
        TimeTracker _totalFleeTime;
};

#endif

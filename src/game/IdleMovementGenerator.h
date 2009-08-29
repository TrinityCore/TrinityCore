/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef TRINITY_IDLEMOVEMENTGENERATOR_H
#define TRINITY_IDLEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class TRINITY_DLL_SPEC IdleMovementGenerator : public MovementGenerator
{
    public:

        void Initialize(Unit &);
        void Finalize(Unit &) {  }
        void Reset(Unit &);
        bool Update(Unit &, const uint32 &) { return true; }
        MovementGeneratorType GetMovementGeneratorType() { return IDLE_MOTION_TYPE; }
};

extern IdleMovementGenerator si_idleMovement;

class TRINITY_DLL_SPEC RotateMovementGenerator : public MovementGenerator
{
    public:
        explicit RotateMovementGenerator(uint32 time, RotateDirection direction) : m_duration(time), m_direction(direction) {}

        void Initialize(Unit& owner);
        void Finalize(Unit& owner);
        void Reset(Unit& owner) { Initialize(owner); }
        bool Update(Unit& owner, const uint32& time_diff);
        MovementGeneratorType GetMovementGeneratorType() { return ROTATE_MOTION_TYPE; }

    private:
        uint32 m_duration;
        RotateDirection m_direction;
};

class TRINITY_DLL_SPEC DistractMovementGenerator : public MovementGenerator
{
    public:
        explicit DistractMovementGenerator(uint32 timer) : m_timer(timer) {}

        void Initialize(Unit& owner);
        void Finalize(Unit& owner);
        void Reset(Unit& owner) { Initialize(owner); }
        bool Update(Unit& owner, const uint32& time_diff);
        MovementGeneratorType GetMovementGeneratorType() { return DISTRACT_MOTION_TYPE; }

    private:
        uint32 m_timer;
};

class MANGOS_DLL_SPEC AssistanceDistractMovementGenerator : public DistractMovementGenerator
{
    public:
        AssistanceDistractMovementGenerator(uint32 timer) :
            DistractMovementGenerator(timer) {}

        MovementGeneratorType GetMovementGeneratorType() { return ASSISTANCE_DISTRACT_MOTION_TYPE; }
        void Finalize(Unit& unit);
};

#endif


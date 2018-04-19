/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_IDLEMOVEMENTGENERATOR_H
#define TRINITY_IDLEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "Timer.h"

enum RotateDirection : uint8;

class IdleMovementGenerator : public MovementGenerator
{
    public:
        void Initialize(Unit*) override;
        void Finalize(Unit*) override {  }
        void Reset(Unit*) override;
        bool Update(Unit*, uint32) override { return true; }
        MovementGeneratorType GetMovementGeneratorType() const override;
};

class RotateMovementGenerator : public MovementGenerator
{
    public:
        explicit RotateMovementGenerator(uint32 time, RotateDirection direction) : _duration(time), _maxDuration(time), _direction(direction) { }

        void Initialize(Unit*) override;
        void Finalize(Unit*) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit*, uint32) override;
        MovementGeneratorType GetMovementGeneratorType() const override;

    private:
        uint32 _duration, _maxDuration;
        RotateDirection _direction;
};

class DistractMovementGenerator : public MovementGenerator
{
    public:
        explicit DistractMovementGenerator(uint32 timer) : _timer(timer) { }

        void Initialize(Unit*) override;
        void Finalize(Unit*) override;
        void Reset(Unit* owner) override { Initialize(owner); }
        bool Update(Unit*, uint32) override;
        MovementGeneratorType GetMovementGeneratorType() const override;

    private:
        uint32 _timer;
};

class AssistanceDistractMovementGenerator : public DistractMovementGenerator
{
    public:
        explicit AssistanceDistractMovementGenerator(uint32 timer) : DistractMovementGenerator(timer) { }

        MovementGeneratorType GetMovementGeneratorType() const override;
        void Finalize(Unit*) override;
};

#endif

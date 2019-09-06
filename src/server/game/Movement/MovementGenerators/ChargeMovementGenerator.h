/*
 * Copyright (C) 2019 AtieshCore <https://at-wow.org/>
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

#ifndef TRINITY_CHARGEMOVEMENTGENERATOR_H
#define TRINITY_CHARGEMOVEMENTGENERATOR_H

#include "MovementDefines.h"
#include "MovementGenerator.h"
#include "Optional.h"
#include "Position.h"

class PathGenerator;
class Unit;
class Creature;

template<class T>
class ChargeMovementGenerator : public MovementGeneratorMedium<T, ChargeMovementGenerator<T>>
{
    public:
        explicit ChargeMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, float speed = 0.0f, Optional<float> finalOrient = {});

        MovementGeneratorType GetMovementGeneratorType() const override;

        void DoInitialize(T*);
        void DoReset(T*);
        bool DoUpdate(T*, uint32);
        void DoDeactivate(T*);
        void DoFinalize(T*, bool, bool);

        uint32 GetId() const { return _movementId; }

    private:
        uint32 _movementId;
        float _x, _y, _z;
        float _speed;
        bool _generatePath;
        //! if set then unit will turn to specified _orient in provided _pos
        Optional<float> _finalOrient;
        std::unique_ptr<PathGenerator> _path;
};

template<class T>
class ChargePathMovementGenerator : public MovementGeneratorMedium<T, ChargePathMovementGenerator<T>>
{
public:
    explicit ChargePathMovementGenerator(uint32 id, float x, float y, float z, PathGenerator const& path, float speed = 0.0f, Optional<float> finalOrient = {});

    MovementGeneratorType GetMovementGeneratorType() const override;

    void DoInitialize(T*);
    void DoReset(T*);
    bool DoUpdate(T*, uint32);
    void DoDeactivate(T*);
    void DoFinalize(T*, bool, bool);

    uint32 GetId() const { return _movementId; }

private:
    uint32 _movementId;
    float _x, _y, _z;
    PathGenerator const& _path;
    float _speed;
    //! if set then unit will turn to specified _orient in provided _pos
    Optional<float> _finalOrient;
};

#endif

/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

#define SCScriptName "instance_vortex_pinnacle"
#define DataHeader "VP"

#include "G3D/Vector3.h"
#include "G3D/Triangle.h"
#include "G3D/Plane.h"
#include "G3D/CollisionDetection.h"

uint32 const Slipstreams = 13;
uint32 const PrismGroundingFieldPoints = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_GRAND_VIZIER_ERTAN,
    DATA_ALTAIRUS,
    DATA_ASAAD,

    // Additional Data
    DATA_SLIPSTREAM,
    DATA_SLIPSTREAM_1,
    DATA_SLIPSTREAM_2,
    DATA_SLIPSTREAM_3,
    DATA_SLIPSTREAM_4,
    DATA_SLIPSTREAM_5,
    DATA_SLIPSTREAM_6,
    DATA_SLIPSTREAM_7,
    DATA_SLIPSTREAM_8,
    DATA_SLIPSTREAM_9,
    DATA_SLIPSTREAM_10,
    DATA_SLIPSTREAM_11,
};

enum Misc
{
    NPC_GRAND_VIZIER_ERTAN      = 43878,
    NPC_ALTAIRUS                = 43873,
    NPC_ASAAD                   = 43875,

    NPC_SLIPSTREAM              = 45455,
    NPC_SLIPSTREAM_LANDING_ZONE = 45504,

    NPC_HOWLING_GALE            = 45572,

    // Grounding Field
    NPC_GROUNDING_FIELD         = 47085,
    SPELL_BEAM_A                = 87721,
    SPELL_BEAM_B                = 87722,
    SPELL_BEAM_C                = 87723,
    ACTION_GROUNDING_FIELD_TOP  = 1,

    // Zephyr
    NPC_ZEPHYR                  = 45991,
    EVENT_SUMMON_ZEPHYRS        = 1,
    PATH_ZEPHYR_SOUTH           = 4599100,
    PATH_ZEPHYR_NORTH           = 4599101,
};

class TargetInTriangleCheck
{
    public:
        TargetInTriangleCheck(bool negate, Position positionA, Position positionB, Position positionC)
            : _negate(negate), _positionA(positionA), _positionB(positionB), _positionC(positionC) { }

        bool operator()(WorldObject* target) const
        {
            return _negate != IsInTriangle(target);
        }

    private:

        bool IsInTriangle(WorldObject* target) const
        {
            G3D::Triangle const triangle(PositionToVector3(_positionA), PositionToVector3(_positionB), PositionToVector3(_positionC));
            G3D::Vector3 const vector(PositionToVector3(*target));

            return G3D::CollisionDetection::isPointInsideTriangle(triangle.vertex(0), triangle.vertex(1), triangle.vertex(2), triangle.normal(), vector, triangle.primaryAxis());
        }

        inline static G3D::Vector3 PositionToVector3(Position const& position)
        {
            return G3D::Vector3(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ());
        }

        bool _negate;
        Position _positionA;
        Position _positionB;
        Position _positionC;
};

#endif // DEF_VORTEX_PINNACLE_H

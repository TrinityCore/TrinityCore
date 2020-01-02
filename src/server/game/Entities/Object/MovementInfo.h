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

#ifndef MovementInfo_h__
#define MovementInfo_h__

#include "ObjectGuid.h"
#include "Position.h"
#include <algorithm>
#include <vector>

struct MovementInfo
{
    // common
    ObjectGuid guid;
    uint32 flags;
    uint32 flags2;
    Position pos;
    uint32 time;

    // transport
    struct TransportInfo
    {
        void Reset()
        {
            guid.Clear();
            pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
            seat = -1;
            time = 0;
            prevTime = 0;
            vehicleId = 0;
        }

        ObjectGuid guid;
        Position pos;
        int8 seat;
        uint32 time;
        uint32 prevTime;
        uint32 vehicleId;
    } transport;

    // swimming/flying
    float pitch;

    // jumping
    struct JumpInfo
    {
        void Reset()
        {
            fallTime = 0;
            zspeed = sinAngle = cosAngle = xyspeed = 0.0f;
        }

        uint32 fallTime;

        float zspeed, sinAngle, cosAngle, xyspeed;

    } jump;

    // spline
    float splineElevation;

    MovementInfo() :
        flags(0), flags2(0), time(0), pitch(0.0f), splineElevation(0.0f)
    {
        pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
        transport.Reset();
        jump.Reset();
    }

    uint32 GetMovementFlags() const { return flags; }
    void SetMovementFlags(uint32 flag) { flags = flag; }
    void AddMovementFlag(uint32 flag) { flags |= flag; }
    void RemoveMovementFlag(uint32 flag) { flags &= ~flag; }
    bool HasMovementFlag(uint32 flag) const { return (flags & flag) != 0; }

    uint32 GetExtraMovementFlags() const { return flags2; }
    void SetExtraMovementFlags(uint32 flag) { flags2 = flag; }
    void AddExtraMovementFlag(uint32 flag) { flags2 |= flag; }
    void RemoveExtraMovementFlag(uint32 flag) { flags2 &= ~flag; }
    bool HasExtraMovementFlag(uint32 flag) const { return (flags2 & flag) != 0; }

    uint32 GetFallTime() const { return jump.fallTime; }
    void SetFallTime(uint32 fallTime) { jump.fallTime = fallTime; }

    void ResetTransport()
    {
        transport.Reset();
    }

    void ResetJump()
    {
        jump.Reset();
    }

    void OutDebug();
};

struct MovementForce
{
    ObjectGuid ID;
    TaggedPosition<Position::XYZ> Origin;
    TaggedPosition<Position::XYZ> Direction;
    uint32 TransportID = 0;
    float Magnitude = 0.0f;
    uint8 Type = 0;
};

class MovementForces
{
public:
    using Container = std::vector<MovementForce>;

    Container const* GetForces() const { return &_forces; }
    bool Add(MovementForce const& newForce)
    {
        auto itr = FindMovementForce(newForce.ID);
        if (itr == _forces.end())
        {
            _forces.push_back(newForce);
            return true;
        }

        return false;
    }

    bool Remove(ObjectGuid id)
    {
        auto itr = FindMovementForce(id);
        if (itr != _forces.end())
        {
            _forces.erase(itr);
            return true;
        }

        return false;
    }

    float GetModMagnitude() const { return _modMagnitude; }
    void SetModMagnitude(float modMagnitude) { _modMagnitude = modMagnitude; }

    bool IsEmpty() const { return _forces.empty() && _modMagnitude == 1.0f; }

private:
    Container::iterator FindMovementForce(ObjectGuid id)
    {
        return std::find_if(_forces.begin(), _forces.end(), [id](MovementForce const& force) { return force.ID == id; });
    }

    Container _forces;
    float _modMagnitude = 1.0f;
};

#endif // MovementInfo_h__

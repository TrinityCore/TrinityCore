/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"
#include "TransportMgr.h"
#include "MapManager.h"

#include <map>
#include <set>

typedef std::set<Unit*> PassengerSet;

class GenericTransport : public GameObject
{
public:
    GenericTransport() : m_passengerTeleportItr(m_passengers.end()), m_pathProgress(0) {}
    void CleanupsBeforeDelete() override;

    void SendOutOfRangeUpdateToMap();
    void SendCreateUpdateToMap();

    void AddPassenger(Unit* passenger, bool adjustCoords = true);
    void RemovePassenger(Unit* passenger);
    void AddFollowerToTransport(Unit* passenger, Unit* follower);
    void RemoveFollowerFromTransport(Unit* passenger, Unit* follower);

    void UpdatePosition(float x, float y, float z, float o);
    void UpdatePassengerPosition(Unit* object);

    typedef std::set<Player*> PlayerSet;
    PassengerSet& GetPassengers() { return m_passengers; }

    /// This method transforms supplied transport offsets into global coordinates
    void CalculatePassengerPosition(float& x, float& y, float& z, float* o = nullptr) const
    {
        CalculatePassengerPosition(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
    }

    /// This method transforms supplied global coordinates into local offsets
    void CalculatePassengerOffset(float& x, float& y, float& z, float* o = nullptr) const
    {
        CalculatePassengerOffset(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
    }

    void CalculatePassengerOrientation(float& o) const;

    static void CalculatePassengerPosition(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO);
    static void CalculatePassengerOffset(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO);

    uint32 GetPathProgress() const { return m_pathProgress; }
protected:
    void UpdatePassengerPositions(PassengerSet& passengers);

    PassengerSet m_passengers;
    PassengerSet::iterator m_passengerTeleportItr;

    uint32 m_pathProgress; // for MO transport its full time since start for normal time in cycle
};

class ElevatorTransport : public GenericTransport
{
public:
    bool Create(uint32 guidlow, uint32 name_id, Map* map, float x, float y, float z, float ang,
        float rotation0 = 0.0f, float rotation1 = 0.0f, float rotation2 = 0.0f, float rotation3 = 0.0f, uint32 animprogress = GO_ANIMPROGRESS_DEFAULT, GOState go_state = GO_STATE_READY) override;
    void Update(uint32 update_diff, uint32 /*time_diff*/) override;

private:
    TransportAnimation const* m_animationInfo;
    uint32 m_currentSeg;
};

class Transport : public GenericTransport
{
public:
    explicit Transport(TransportTemplate const& transportTemplate);

    bool Create(uint32 guidlow, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress);
    void Update(uint32 update_diff, uint32 /*time_diff*/) override;

    uint32 GetPeriod() const { return m_period; }
    void SetPeriod(uint32 period) { m_period = period; }

    KeyFrameVec const& GetKeyFrames() const { return m_transportTemplate.keyFrames; }
private:
    bool TeleportTransport(uint32 newMapid, float x, float y, float z, float o);
    void MoveToNextWayPoint();                          // move m_next/m_cur to next points
    float CalculateSegmentPos(float perc);

    bool IsMoving() const { return m_isMoving; }
    void SetMoving(bool val) { m_isMoving = val; }

    ShortTimeTracker m_positionChangeTimer;
    bool m_isMoving;
    bool m_pendingStop;

    KeyFrameVec::const_iterator m_currentFrame;
    KeyFrameVec::const_iterator m_nextFrame;

    uint32 m_period;

    TransportTemplate const& m_transportTemplate;
};

inline GenericTransport* GameObject::ToTransport()
{
    return IsTransport() ? static_cast<GenericTransport*>(this) : nullptr;
}

inline GenericTransport const* GameObject::ToTransport() const
{
    return IsTransport() ? static_cast<GenericTransport const*>(this) : nullptr;
}

#endif

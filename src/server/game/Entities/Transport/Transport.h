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

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"
#include "TransportMgr.h"
#include "VehicleDefines.h"

struct CreatureData;

class TC_GAME_API Transport : public GameObject, public TransportBase
{
    public:
        typedef std::set<WorldObject*> PassengerSet;

        Transport();
        ~Transport();

        bool Create(ObjectGuid::LowType guidlow, uint32 entry, Map* map, uint32 /*phaseMask*/, Position const& pos, QuaternionData const& rotation, uint32 animprogress, GOState go_state, uint32 artKit = 0, bool dynamic = false, ObjectGuid::LowType spawnid = 0) override;
        bool CreateTransport(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, Position const& pos, uint32 animprogress);

        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        void AddPassenger(WorldObject* passenger);
        virtual void RemovePassenger(WorldObject* passenger);
        PassengerSet const& GetPassengers() const { return _passengers; }

        /// This method transforms supplied transport offsets into global coordinates
        void CalculatePassengerPosition(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerPosition(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        }

        /// This method transforms supplied global coordinates into local offsets
        void CalculatePassengerOffset(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerOffset(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        }

        void Update(uint32 diff) override;

        bool IsDynamicTransport() const { return _isDynamicTransport; }

        uint32 GetPathProgress() const { return GetGOValue()->Transport.PathProgress; }
        void SetPathProgress(uint32 val) { m_goValue.Transport.PathProgress = val; }

        virtual uint32 GetTransportPeriod() const;
        void SetTransportState(GOState state, uint32 stopFrame = 0);

        void RelocateToProgress(uint32 progress);

        void SetDestinationStopFrameTime(uint32 time) { _destinationStopFrameTime = time; }
        uint32 GetDestinationStopFrameTime() const { return _destinationStopFrameTime;  }

        void SetCurrentTransportTime(uint32 time) { _currentTransportTime = time; }
        uint32 GetCurrentTransportTime() const { return _currentTransportTime; }

        void SetAlignmentTransportTime(uint32 time) { _alignmentTransportTime = time; }
        uint32 GetAlightmentTransportTime() const { return _alignmentTransportTime; }

        void SetLastStopFrameTime(uint32 time) { _lastStopFrameTime = time; }
        uint32 GetLastStopFrameTime() const { return _lastStopFrameTime; }

        uint32 GetTransportCreationTime() const { return _creationGameTime;  }

    protected:
        void UpdatePassengerPositions(PassengerSet& passengers);

        PassengerSet _passengers;
        PassengerSet::iterator _passengerTeleportItr;

        uint32 _destinationStopFrameTime;
        uint32 _currentTransportTime;
        uint32 _alignmentTransportTime;
        uint32 _lastStopFrameTime;
        uint32 _creationGameTime;
        bool _isDynamicTransport;
        bool _initialRelocate;
};

class TC_GAME_API MapTransport : public Transport
{
        friend MapTransport* TransportMgr::CreateTransport(uint32, ObjectGuid::LowType, Map*, uint8, uint32, uint32);

        MapTransport();
    public:
        ~MapTransport();

        bool CreateMapTransport(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress);
        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        void Update(uint32 diff) override;
        void DelayedUpdate(uint32 diff);

        void BuildUpdate(UpdateDataMapType& data_map) override;

        void RemovePassenger(WorldObject* passenger) override;

        Creature* CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data);
        GameObject* CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data);

        /**
        * @fn bool Transport::SummonPassenger(uint32, Position const&, TempSummonType, SummonPropertiesEntry const*, uint32, Unit*, uint32, uint32)
        *
        * @brief Temporarily summons a creature as passenger on this transport.
        *
        * @param entry Id of the creature from creature_template table
        * @param pos Initial position of the creature (transport offsets)
        * @param summonType
        * @param properties
        * @param duration Determines how long the creauture will exist in world depending on @summonType (in milliseconds)
        * @param summoner Summoner of the creature (for AI purposes)
        * @param spellId
        * @param vehId If set, this value overrides vehicle id from creature_template that the creature will use
        *
        * @return Summoned creature.
        */
        TempSummon* SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties = nullptr, uint32 duration = 0, Unit* summoner = nullptr, uint32 spellId = 0, uint32 vehId = 0);

        uint32 GetTransportPeriod() const override { return GetUInt32Value(GAMEOBJECT_LEVEL); }
        void SetPeriod(uint32 period) { SetUInt32Value(GAMEOBJECT_LEVEL, period); }

        KeyFrameVec const& GetKeyFrames() const { return _transportInfo->keyFrames; }

        void UpdatePosition(float x, float y, float z, float o);

        //! Needed when transport moves from inactive to active grid
        void LoadStaticPassengers();

        //! Needed when transport enters inactive grid
        void UnloadStaticPassengers();

        void EnableMovement(bool enabled);

        void SetDelayedAddModelToMap() { _delayedAddModel = true; }

        TransportTemplate const* GetTransportTemplate() const { return _transportInfo; }

    private:
        void MoveToNextWaypoint();
        float CalculateSegmentPos(float perc);
        bool TeleportTransport(uint32 newMapid, float x, float y, float z, float o);
        void DelayedTeleportTransport();
        void DoEventIfAny(KeyFrame const& node, bool departure);

        //! Helpers to know if stop frame was reached
        bool IsMoving() const { return _isMoving; }
        void SetMoving(bool val) { _isMoving = val; }

        TransportTemplate const* _transportInfo;

        KeyFrameVec::const_iterator _currentFrame;
        KeyFrameVec::const_iterator _nextFrame;
        TimeTrackerSmall _positionChangeTimer;
        bool _isMoving;
        bool _pendingStop;

        //! These are needed to properly control events triggering only once for each frame
        bool _triggeredArrivalEvent;
        bool _triggeredDepartureEvent;

        PassengerSet _staticPassengers;

        bool _delayedAddModel;
        bool _delayedTeleport;
};

#endif

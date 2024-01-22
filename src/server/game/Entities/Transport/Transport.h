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

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"
#include "TransportMgr.h"
#include "VehicleDefines.h"
#include <boost/dynamic_bitset_fwd.hpp>

struct CreatureData;
struct SummonPropertiesEntry;

class TC_GAME_API Transport final : public GameObject, public TransportBase
{
        friend Transport* TransportMgr::CreateTransport(uint32, Map*, ObjectGuid::LowType, uint8, uint32, uint32);

        Transport();
    public:
        typedef std::set<WorldObject*> PassengerSet;

        ~Transport();

        bool Create(ObjectGuid::LowType guidlow, uint32 entry, float x, float y, float z, float ang);
        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        void Update(uint32 diff) override;

        void BuildUpdate(UpdateDataMapType& data_map) override;

        void AddPassenger(WorldObject* passenger) override;
        Transport* RemovePassenger(WorldObject* passenger) override;
        PassengerSet const& GetPassengers() const { return _passengers; }

        Creature* CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data);
        GameObject* CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data);

        /**
        * @fn bool Transport::SummonPassenger(uint64, Position const&, TempSummonType, SummonPropertiesEntry const*, uint32, Unit*, uint32, uint32)
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
        TempSummon* SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties = nullptr, Milliseconds duration = 0ms, Unit* summoner = nullptr, uint32 spellId = 0, uint32 vehId = 0);

        ObjectGuid GetTransportGUID() const override { return GetGUID(); }

        float GetTransportOrientation() const override { return GetOrientation(); }

        /// This method transforms supplied transport offsets into global coordinates
        void CalculatePassengerPosition(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerPosition(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetTransportOrientation());
        }

        /// This method transforms supplied global coordinates into local offsets
        void CalculatePassengerOffset(float& x, float& y, float& z, float* o = nullptr) const override
        {
            TransportBase::CalculatePassengerOffset(x, y, z, o, GetPositionX(), GetPositionY(), GetPositionZ(), GetTransportOrientation());
        }

        int32 GetMapIdForSpawning() const override;

        uint32 GetTransportPeriod() const { return m_gameObjectData->Level; }
        void SetPeriod(uint32 period) { SetLevel(period); }
        uint32 GetTimer() const { return _pathProgress; }

        void UpdatePosition(float x, float y, float z, float o);

        //! Needed when transport moves from inactive to active grid
        void LoadStaticPassengers();

        //! Needed when transport enters inactive grid
        void UnloadStaticPassengers();

        void EnableMovement(bool enabled);

        void SetDelayedAddModelToMap() { _delayedAddModel = true; }

        std::string GetDebugInfo() const override;

        //! Returns id of the map that transport is expected to be on, according to current path progress
        uint32 GetExpectedMapId() const;

    private:
        bool TeleportTransport(uint32 oldMapId, uint32 newMapId, float x, float y, float z, float o);
        void TeleportPassengersAndHideTransport(uint32 newMapid, float x, float y, float z, float o);
        void UpdatePassengerPositions(PassengerSet const& passengers);

        TransportTemplate const* _transportInfo;
        TransportMovementState _movementState;
        std::unique_ptr<boost::dynamic_bitset<uint8>> _eventsToTrigger;
        size_t _currentPathLeg;
        Optional<uint32> _requestStopTimestamp;
        uint32 _pathProgress;
        TimeTracker _positionChangeTimer;

        PassengerSet _passengers;
        PassengerSet _staticPassengers;

        bool _delayedAddModel;
};

#endif

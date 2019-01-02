/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef SpellPackets_h__
#define SpellPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellMissStatus
        {
            ObjectGuid TargetGUID;
            uint8 Reason = 0;
            uint8 ReflectStatus = 0;
        };

        struct RuneData
        {
            uint8 Start = 0;
            uint8 Count = 0;
            std::vector<uint8> Cooldowns;
        };

        struct MissileTrajectoryResult
        {
            uint32 TravelTime = 0;
            float Pitch = 0.0f;
        };

        struct SpellAmmo
        {
            uint32 DisplayID = 0;
            uint32 InventoryType = 0;
        };

        struct CreatureImmunities
        {
            uint32 School = 0;
            uint32 Value = 0;
        };

        struct TargetLocation
        {
            ObjectGuid Transport;
            Position Location;
        };

        struct SpellTargetData
        {
            uint32 Flags = 0;
            Optional<ObjectGuid> Unit;
            Optional<ObjectGuid> Item;
            Optional<TargetLocation> SrcLocation;
            Optional<TargetLocation> DstLocation;
            Optional<std::string> Name;
        };

        struct SpellCastData
        {
            ObjectGuid CasterGUID;
            ObjectGuid CasterUnit;
            uint8 CastID               = 0;
            uint32 SpellID             = 0;
            uint32 CastFlags           = 0;
            uint32 CastTime            = 0;
            mutable Optional<std::vector<ObjectGuid>> HitTargets;
            mutable Optional<std::vector<SpellMissStatus>> MissStatus;
            SpellTargetData Target;
            Optional<uint32> RemainingPower;
            Optional<RuneData> RemainingRunes;
            Optional<MissileTrajectoryResult> MissileTrajectory;
            Optional<SpellAmmo> Ammo;
            Optional<CreatureImmunities> Immunities;
        };

        class SpellGo final : public ServerPacket
        {
            public:
                SpellGo() : ServerPacket(SMSG_SPELL_GO) { }

                WorldPacket const* Write() override;

                SpellCastData Cast;
        };

        class SpellStart final : public ServerPacket
        {
            public:
                SpellStart() : ServerPacket(SMSG_SPELL_START) { }

                WorldPacket const* Write() override;

                SpellCastData Cast;
        };
    }
}

#endif // SpellPackets_h__

/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef PetBattlePackets_h__
#define PetBattlePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "UnitDefines.h"

namespace WorldPackets
{
    namespace PetBattle
    {
        struct PetBattleLocation
        {
            int32 LocationResult;
            TaggedPosition<Position::XYZ> BattleOrigin;
            float BattleFacing;
            TaggedPosition<Position::XYZ> PlayerPositions[2];
        };

        struct PetBattleActiveAbility
        {
            int32 AbilityID;
            int16 CooldownRemaining;
            int16 LockdownRemaining;
            uint8 AbilityIndex;
            uint8 Pboid;
        };

        struct PetBattleActiveAura
        {
            int32 AbilityID;
            int32 InstanceID;
            int32 RoundsRemaining;
            int32 CurrentRound;
            uint8 CasterPBOID;
        };

        struct PetBattleActiveState
        {
            int32 StateID;
            int32 StateValue;
        };

        struct PetBattleEnviroUpdate
        {
            std::vector<PetBattleActiveAura> PetBattleActiveAuras;
            std::vector<PetBattleActiveState> PetBattleActiveStates;
        };

        struct PetBattlePetUpdate
        {
            ObjectGuid BattlePetGUID;

            int32 SpeciesID;
            int32 DisplayID;
            int32 CollarID;

            int16 Level;
            int16 Xp;

            int32 CurHealth;
            int32 MaxHealth;
            int32 Power;
            int32 Speed;
            int32 NpcTeamMemberID;

            int16 BreedQuality;
            int16 StatusFlags;

            uint8 Slot;

            std::vector<PetBattleActiveAbility> PetBattleActiveAbilities;
            std::vector<PetBattleActiveAura> PetBattleActiveAuras;
            std::vector<PetBattleActiveState> PetBattleActiveStates;
        };

        struct PetBattlePlayerUpdate
        {
            ObjectGuid PlayerGUID;
            int32 TrapAbilityID;
            int32 TrapStatus;

            int16 RoundTimeSecs;

            int8 FrontPet;
            uint8 InputFlags;

            std::vector<PetBattlePetUpdate> PetBattlePetUpdates;
        };

        struct PetBattleFullUpdate
        {
            PetBattlePlayerUpdate PetBattlePlayerUpdates[2];
            PetBattleEnviroUpdate PetBattleEnviroUpdates[3];

            int16 WaitingForFrontPetsMaxSecs;
            int16 PvpMaxRoundTime;

            int32 CurRound;
            int32 NpcCreatureID;
            int32 NpcDisplayID;

            uint8 CurPetBattleState;
            uint8 ForfeitPenalty;

            ObjectGuid InitialWildPetGUID;

            bool IsPVP;
            bool CanAwardXP;
        };

        class RequestWild final : public ClientPacket
        {
        public:
            RequestWild(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_REQUEST_WILD, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetGUID;
            PetBattleLocation Location;
        };

        class RequestFailed final : public ServerPacket
        {
        public:
            RequestFailed() : ServerPacket(SMSG_PET_BATTLE_REQUEST_FAILED, 1) { }

            uint8 Reason;

            WorldPacket const* Write() override;
        };

        class FinalizeLocation final : public ServerPacket
        {
        public:
            FinalizeLocation() : ServerPacket(SMSG_PET_BATTLE_FINALIZE_LOCATION, 1) { }

            PetBattleLocation Location;

            WorldPacket const* Write() override;
        };

        class InitialUpdate final : public ServerPacket
        {
        public:
            InitialUpdate() : ServerPacket(SMSG_PET_BATTLE_INITIAL_UPDATE, 1) { }

            PetBattleLocation Location;

            WorldPacket const* Write() override;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::PetBattle::PetBattleLocation& petBattleLocation);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::PetBattle::PetBattleLocation& petBattleLocation);

#endif // PetBattlePackets_h__

#ifndef PROJECT_PACKETS_BATTLE_PET_H
#define PROJECT_PACKETS_BATTLE_PET_H

#include "LFGPackets.h"
#include "project_battle_pet_battle_placeholder.h"

namespace PROJECT
{
    namespace Packets
    {
        namespace PetBattles
        {
            class QueueStatus final : public WorldPackets::ServerPacket
            {
                public:
                    QueueStatus() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_QUEUE_STATUS) { }

                    WorldPacket const* Write() override;

                    WorldPackets::LFG::RideTicket Ticket;
                    uint32 Status = 0;
                    std::vector<uint32> SlotResult;
                    Optional<uint32> ClientWaitTime;
                    Optional<uint32> AverageWaitTime;
            };

            class RequestFailed final : public WorldPackets::ServerPacket
            {
                public:
                    RequestFailed() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_REQUEST_FAILED) { }

                    WorldPacket const* Write() override;

                    uint8 Reason;
            };

            struct FinalPet
            {
                ObjectGuid GUID = ObjectGuid::Empty;
                bool Captured = false;
                bool Caged = false;
                bool AwardedXP = false;
                bool SeenAction = false;
                uint16 Level = 0;
                uint16 Xp = 0;
                int32 Health = 0;
                int32 MaxHealth = 0;
                uint16 InitialLevel = 0;
                uint8 Pboid = 0;
            };

            class FinalRound final : public WorldPackets::ServerPacket
            {
                public:
                    FinalRound() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_FINAL_ROUND) { }
            
                    WorldPacket const* Write() override;
            
                    bool Abandoned;
                    bool PvpBattle;
                    bool Winners[PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS];
                    int NpcCreatureID[PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS];

                    std::vector<FinalPet> Pets;
            };

            struct Locations
            {
                int32 LocationResult = 21; // unk
                TaggedPosition<Position::XYZ> BattleOrigin;
                float BattleFacing = 0.0f;
                TaggedPosition<Position::XYZ> PlayerPositions[PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS];
            };

            class FinalizeLocation final : public WorldPackets::ServerPacket
            {
                public:
                    FinalizeLocation() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_FINALIZE_LOCATION) { }
            
                    WorldPacket const* Write() override;

                    Locations Location;
            };

            class QueueProposeMatch final : public WorldPackets::ServerPacket
            {
                public:
                    QueueProposeMatch() : ServerPacket(SMSG_PET_BATTLE_QUEUE_PROPOSE_MATCH, 0) { }

                    WorldPacket const* Write() override { return &_worldPacket; }
            };

            class Finished final : public WorldPackets::ServerPacket
            {
                public:
                    Finished() : ServerPacket(SMSG_PET_BATTLE_FINISHED, 0) { }

                    WorldPacket const* Write() override { return &_worldPacket; }
            };

            struct EnviroUpdate
            {
                std::vector<PROJECT::BattlePets::Battles::ActiveAura> Auras;
                std::vector<PROJECT::BattlePets::Battles::ActiveState> States;
            };

            struct PetUpdate
            {
                ObjectGuid BattlePetGUID;
                int32 SpeciesID = 0;
                int32 DisplayID = 0;
                int32 CollarID = 0;
                int16 Level = 0;
                int16 Xp = 0;
                int32 CurHealth = 0;
                int32 MaxHealth = 0;
                int32 Power = 0;
                int32 Speed = 0;
                int32 NpcTeamMemberID = 0;
                uint16 BreedQuality = 0;
                uint16 StatusFlags = 0;
                int8 Slot = 0;
                std::string CustomName;
                std::vector<PROJECT::BattlePets::Battles::ActiveAbility> Abilities;
                std::vector<PROJECT::BattlePets::Battles::ActiveAura> Auras;
                std::vector<PROJECT::BattlePets::Battles::ActiveState> States;
            };

            struct PlayerUpdate
            {
                ObjectGuid CharacterID;
                int32 TrapAbilityID = 0;
                int32 TrapStatus = 0;
                uint16 RoundTimeSecs = 0;
                std::vector<PetUpdate> Pets;
                int8 FrontPet = 0;
                uint8 InputFlags = 6; // unk
            };

            class InitialUpdate final : public WorldPackets::ServerPacket
            {
                public:
                    InitialUpdate() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_INITIAL_UPDATE) { }
            
                    WorldPacket const* Write() override;
            
                    uint16 WaitingForFrontPetsMaxSecs = 0;
                    uint16 PvpMaxRoundTime = 0;
                    int32 CurRound = 0;
                    uint32 NpcCreatureID = 0;
                    uint32 NpcDisplayID = 0;
                    int8 CurPetBattleState = 1; // unk
                    uint8 ForfeitPenalty = 0;
                    ObjectGuid InitialWildPetGUID;
                    bool IsPVP = false;
                    bool CanAwardXP = false;
                    PlayerUpdate Players[PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS];
                    EnviroUpdate Enviros[PROJECT::BattlePets::Constants::TOTAL_ENVIROS];
            };

            class FirstRound final : public WorldPackets::ServerPacket
            {
                public:
                    FirstRound() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_FIRST_ROUND) { }
            
                    WorldPacket const* Write() override;

                    PROJECT::BattlePets::Battles::RoundData RoundData;
            };

            class RoundResult final : public WorldPackets::ServerPacket
            {
                public:
                    RoundResult() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_ROUND_RESULT) { }
            
                    WorldPacket const* Write() override;

                    PROJECT::BattlePets::Battles::RoundData RoundData;
            };

            class ReplacementsMade final : public WorldPackets::ServerPacket
            {
                public:
                    ReplacementsMade() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_REPLACEMENTS_MADE) { }
            
                    WorldPacket const* Write() override;

                    PROJECT::BattlePets::Battles::RoundData RoundData;
            };

            class PvPChallenge final : public WorldPackets::ServerPacket
            {
                public:
                    PvPChallenge() : WorldPackets::ServerPacket(SMSG_PET_BATTLE_PVP_CHALLENGE) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid ChallengerGUID;
                    Locations Location;
            };

            class QueueProposeMatchResult final : public WorldPackets::ClientPacket
            {
            	public:
            	    QueueProposeMatchResult(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_QUEUE_PROPOSE_MATCH_RESULT, std::move(packet)) { }
            	
                    void Read() override;

                    bool Accepted;
            };

            class RequestPvP final : public WorldPackets::ClientPacket
            {
            	public:
            	    RequestPvP(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_REQUEST_PVP, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid TargetGUID;
                    Locations Location;
            };

            class RequestWild final : public WorldPackets::ClientPacket
            {
            	public:
                    RequestWild(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_REQUEST_WILD, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid TargetGUID;
                    Locations Location;
            };

            class Input final : public WorldPackets::ClientPacket
            {
            	public:
            	    Input(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_INPUT, std::move(packet)) { }
            	
                    void Read() override;

                    uint8 MoveType = 0;
                    int8 NewFrontPet = 0;
                    uint8 DebugFlags = 0;
                    uint8 BattleInterrupted = 0;
                    bool IgnoreAbandonPenalty = false;
                    int32 AbilityID = 0;
                    int32 Round = 0;
            };

            class ReplaceFrontPet final : public WorldPackets::ClientPacket
            {
            	public:
            	    ReplaceFrontPet(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_REPLACE_FRONT_PET, std::move(packet)) { }
            	
                    void Read() override;

                    int8 FrontPet = 0;
            };

            class RequestUpdate final : public WorldPackets::ClientPacket
            {
            	public:
            	    RequestUpdate(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_PET_BATTLE_REQUEST_UPDATE, std::move(packet)) { }
            	
                    void Read() override;

                    bool Canceled = false;
                    ObjectGuid TargetGUID;
            };
        }

        namespace BattlePets
        {
            class QueryBattlePetName final : public WorldPackets::ClientPacket
            {
            	public:
                    QueryBattlePetName(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_QUERY_BATTLE_PET_NAME, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid BattlePetID;
                    ObjectGuid UnitGUID;
            };

            class QueryBattlePetNameResponse final : public WorldPackets::ServerPacket
            {
                public:
                    QueryBattlePetNameResponse() : WorldPackets::ServerPacket(SMSG_QUERY_BATTLE_PET_NAME_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid BattlePetID;
                    int32 CreatureID = 0;
                    bool Allow = false;
                    std::string Name;
                    bool HasDeclined = false;
                    std::string DeclinedNames[5] = {};
                    uint32 Timestamp = 0;
            };
        }
    }
}

#endif

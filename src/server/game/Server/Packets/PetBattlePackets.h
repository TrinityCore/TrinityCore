/*
 * PetBattlePackets.h
 * Pet Battle system packet structures for TrinityCore
 * Wire format is reconstructed from raw 12.0.7 packet bytes. Older parser
 * layouts are not treated as protocol definitions for the retail client.
 */
#ifndef PetBattlePackets_h__
#define PetBattlePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Position.h"
#include <array>
#include <vector>

namespace WorldPackets::PetBattle
{
    // ---------------------------------------------------------------------
    // Shared sub-structures
    // ---------------------------------------------------------------------

    struct PetBattleActiveAbility
    {
        int32 AbilityID = 0;
        int16 CooldownRemaining = 0;
        int16 LockdownRemaining = 0;
        int8 AbilityIndex = 0;
        uint8 Pboid = 0; // pet battle object id (0/1/2 slot within team)
    };

    struct PetBattleActiveAura
    {
        int32 AbilityID = 0;
        uint32 InstanceID = 0;
        int32 RoundsRemaining = 0;
        int32 CurrentRound = 0;
        uint8 CasterPBOID = 0;
    };

    struct PetBattleActiveState
    {
        uint32 StateID = 0;
        int32 StateValue = 0;
    };

    // One pet inside a PlayerUpdate block
    struct PetBattlePetUpdate
    {
        ObjectGuid BattlePetGUID;
        int32 SpeciesID = 0;
        int32 DisplayID = 0;
        int32 CollarID  = 0;    // present since V6_0_2; always 0 for wild/npc pets
        int16 Level = 1;
        int16 Xp = 0;
        int32 CurHealth = 0;
        int32 MaxHealth = 0;
        int32 Power = 0;
        int32 Speed = 0;
        int32 NpcTeamMemberID = 0;
        uint8 BreedQuality = 0;
        int16 StatusFlags = 0;
        int8 Slot = 0;
        std::vector<PetBattleActiveAbility> Abilities;
        std::vector<PetBattleActiveAura> Auras;
        std::vector<PetBattleActiveState> States;
        std::string CustomName;
    };

    // One side (player or wild/npc) inside a FullUpdate
    struct PetBattlePlayerUpdate
    {
        ObjectGuid CharacterID; // 0 for wild/npc side
        int32 TrapAbilityID = 0;
        int32 TrapStatus = 0;
        uint16 RoundTimeSecs = 0;
        int8 FrontPet = 0;
        uint8 InputFlags = 0;
        std::vector<PetBattlePetUpdate> Pets; // max 3
    };

    struct PetBattleEnviroUpdate
    {
        std::vector<PetBattleActiveAura> Auras;
        std::vector<PetBattleActiveState> States;
    };

    // ---------------------------------------------------------------------
    // Effect / round-result sub-structures
    // ---------------------------------------------------------------------

    enum class PetBattleEffectTargetEx : uint8
    {
        Aura        = 1,
        State       = 2,
        Health      = 3,
        StatChange  = 4,
        Trigger     = 5,
        Ability     = 6,
        Text        = 7,
        FullPet     = 8, // embeds a full PetBattlePetUpdate (e.g. on capture/replace)
        Unk9        = 9
    };

    struct PetBattleEffectTarget
    {
        uint8 Petx = 0;
        PetBattleEffectTargetEx Type = PetBattleEffectTargetEx(0);

        uint32 AuraInstanceID = 0;
        uint32 AuraAbilityID = 0;
        int32 RoundsRemaining = 0;
        int32 CurrentRound = 0;

        uint32 StateID = 0;
        int32 StateValue = 0;

        int32 Health = 0;

        int32 NewStatValue = 0;

        int32 TriggerAbilityID = 0;

        int32 ChangedAbilityID = 0;
        int32 CooldownRemaining = 0;
        int32 LockdownRemaining = 0;

        int32 BroadcastTextID = 0;

        PetBattlePetUpdate FullPet; // used when Type == FullPet
    };

    struct PetBattleEffect
    {
        uint32 AbilityEffectID = 0;
        uint16 Flags = 0;
        uint16 SourceAuraInstanceID = 0;
        uint16 TurnInstanceID = 0;
        int8 PetBattleEffectType = 0;
        uint8 CasterPBOID = 0;
        uint8 StackDepth = 0;
        std::vector<uint8> OptionalFields;
        std::vector<PetBattleEffectTarget> Targets;
    };

    struct PetBattleNextInput
    {
        uint8 NextInputFlags = 0;
        int8 NextTrapStatus = 0;
        uint16 RoundTimeSecs = 0;
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_FINALIZE_LOCATION  (sent before INITIAL_UPDATE;
    // tells client where to place the camera / players on the battle grid)
    // ---------------------------------------------------------------------
    class PetBattleFinalizeLocation final : public ServerPacket
    {
    public:
        PetBattleFinalizeLocation() : ServerPacket(SMSG_PET_BATTLE_FINALIZE_LOCATION) { }
        WorldPacket const* Write() override;

        int32 LocationResult = 0;   // 0 = success
        float BattleOriginX = 0.0f;
        float BattleOriginY = 0.0f;
        float BattleOriginZ = 0.0f;
        float BattleFacing  = 0.0f;

        // Two positions: [0] = player side, [1] = wild-pet side
        struct SimpleXYZ { float X = 0.0f, Y = 0.0f, Z = 0.0f; };
        std::array<SimpleXYZ, 2> PlayerPositions;
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_INITIAL_UPDATE (full snapshot at battle start)
    // ---------------------------------------------------------------------
    class PetBattleInitialUpdate final : public ServerPacket
    {
    public:
        PetBattleInitialUpdate() : ServerPacket(SMSG_PET_BATTLE_INITIAL_UPDATE) { }
        WorldPacket const* Write() override;

        std::array<PetBattlePlayerUpdate, 2> Players;
        std::array<PetBattleEnviroUpdate, 3> Enviros;

        int16 WaitingForFrontPetsMaxSecs = 0;
        int16 PvpMaxRoundTime = 0;

        int32 CurRound = 0;
        uint32 NpcCreatureID = 0;
        uint32 NpcDisplayID = 0;

        int8 CurPetBattleState = 0;
        uint8 ForfeitPenalty = 0;

        ObjectGuid InitialWildPetGUID;

        bool IsPVP = false;
        bool CanAwardXP = true;
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_FIRST_ROUND / SMSG_PET_BATTLE_ROUND_RESULT /
    // SMSG_PET_BATTLE_REPLACEMENTS_MADE (all share the same body)
    // ---------------------------------------------------------------------
    class PetBattleRoundResult final : public ServerPacket
    {
    public:
        explicit PetBattleRoundResult(OpcodeServer opcode = SMSG_PET_BATTLE_ROUND_RESULT)
            : ServerPacket(opcode) { }
        WorldPacket const* Write() override;

        int32 CurRound = 0;
        int8 NextPetBattleState = 0;

        std::array<PetBattleNextInput, 2> NextInput;

        std::vector<PetBattleActiveAbility> Cooldowns;
        std::vector<PetBattleEffect> Effects;
        // Some start-of-battle system effects are not ability casts.  Their
        // wire representation was captured verbatim and is kept separate
        // until every internal client effect type has a named server model.
        uint32 RawEffectsCount = 0;
        std::vector<uint8> RawEffects;
        std::vector<int8> PetXDied; // max 3 (bitfield count is 3 bits wide)
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_FINAL_ROUND (battle over: winners + captured pets)
    // ---------------------------------------------------------------------
    struct PetBattleFinalPet
    {
        ObjectGuid Guid;
        uint16 Level = 1;
        uint16 Xp = 0;
        int32 Health = 0;
        int32 MaxHealth = 0;
        uint16 InitialLevel = 1;
        uint8 Pboid = 0;

        bool Captured = false;
        bool Caged = false;
        bool SeenAction = false;
        bool AwardedXP = false;
    };

    class PetBattleFinalRound final : public ServerPacket
    {
    public:
        PetBattleFinalRound() : ServerPacket(SMSG_PET_BATTLE_FINAL_ROUND) { }
        WorldPacket const* Write() override;

        bool Abandoned = false;
        bool PvpBattle = false;

        std::array<bool, 2> Winner = { false, false };
        std::array<int32, 2> NpcCreatureID = { 0, 0 };

        std::vector<PetBattleFinalPet> Pets;
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_FINISHED (just signals battle teardown)
    // ---------------------------------------------------------------------
    class PetBattleFinished final : public ServerPacket
    {
    public:
        PetBattleFinished() : ServerPacket(SMSG_PET_BATTLE_FINISHED) { }
        WorldPacket const* Write() override
        {
            return &_worldPacket;
        }

        ObjectGuid SceneObjectGUID;
    };

    // ---------------------------------------------------------------------
    // SMSG_PET_BATTLE_REQUEST_FAILED
    // ---------------------------------------------------------------------
    class PetBattleRequestFailed final : public ServerPacket
    {
    public:
        PetBattleRequestFailed() : ServerPacket(SMSG_PET_BATTLE_REQUEST_FAILED, 1) { }
        WorldPacket const* Write() override;

        uint8 Reason = 0; // TODO: enum
    };

    // ---------------------------------------------------------------------
    // CMSG_PET_BATTLE_REQUEST_WILD  (player attacks a wild pet in the world)
    // ---------------------------------------------------------------------
    struct PetBattleLocation
    {
        int32 LocationResult = 0;
        TaggedPosition<Position::XYZ> BattleOrigin;
        float BattleFacing = 0.0f;
        std::array<TaggedPosition<Position::XYZ>, 2> PlayerPositions;
    };

    class PetBattleRequestWild final : public ClientPacket
    {
    public:
        PetBattleRequestWild(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_REQUEST_WILD, std::move(packet)) { }
        void Read() override;

        ObjectGuid TargetGUID; // the wild pet creature GUID
        PetBattleLocation Location;
    };

    // ---------------------------------------------------------------------
    // CMSG_PET_BATTLE_INPUT (player chooses an action for the round)
    // ---------------------------------------------------------------------
    enum class PetBattleMoveType : int32
    {
        UseAbility  = 1, // uses AbilityID / uses "Round"
        SwitchPet   = 2, // uses NewFrontPet
        Trap        = 3,
        Forfeit     = 4
    };

    class PetBattleInput final : public ClientPacket
    {
    public:
        PetBattleInput(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_INPUT, std::move(packet)) { }
        void Read() override;

        int32 MoveType = 0;      // see PetBattleMoveType
        int8 NewFrontPet = -1;   // used for SwitchPet
        int32 DebugFlags = 0;
        uint8 BattleInterrupted = 0;
        int32 AbilityID = 0;     // used for UseAbility
        int32 Round = 0;
        bool IgnoreAbandonPenalty = false;
    };

    // ---------------------------------------------------------------------
    // CMSG_PET_BATTLE_REPLACE_FRONT_PET
    // ---------------------------------------------------------------------
    class PetBattleReplaceFrontPet final : public ClientPacket
    {
    public:
        PetBattleReplaceFrontPet(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_REPLACE_FRONT_PET, std::move(packet)) { }
        void Read() override;

        int8 FrontPet = 0;
    };

    // The retail client sends this empty acknowledgement after FINAL_ROUND.
    // FINISHED must be delayed until it arrives (the supplied capture shows
    // exactly that order).
    class PetBattleFinalNotify final : public ClientPacket
    {
    public:
        PetBattleFinalNotify(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_FINAL_NOTIFY, std::move(packet)) { }
        void Read() override { }
    };

    // Sent when the player closes an active pet battle through the surrender
    // button. It has no payload; the active session supplies all context.
    class PetBattleQuitNotify final : public ClientPacket
    {
    public:
        PetBattleQuitNotify(WorldPacket&& packet) : ClientPacket(CMSG_PET_BATTLE_QUIT_NOTIFY, std::move(packet)) { }
        void Read() override { }
    };
}

#endif // PetBattlePackets_h__

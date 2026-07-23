/*
 * PetBattle.h
 * Server-side session object representing one active pet battle
 * (PvE vs wild pet, minimal viable version - no PvP, no NPC tamers yet)
 */
#ifndef PetBattle_h__
#define PetBattle_h__

#include "ObjectGuid.h"
#include "PetBattlePackets.h"
#include <array>
#include <memory>
#include <unordered_map>

class Player;
class Creature;
struct BattlePetAbilityEffectEntry;

namespace PetBattleSystem
{
    // The 10 pet families from Wowpedia; index also used for the
    // strong/weak damage multiplier lookup table below.
    enum class PetFamily : uint8
    {
        Humanoid    = 0,
        Dragonkin   = 1,
        Flying      = 2,
        Undead      = 3,
        Critter     = 4,
        Magic       = 5,
        Elemental   = 6,
        Beast       = 7,
        Aquatic     = 8,
        Mechanical  = 9,

        Count
    };

    // multiplier[attacker][defender]: 1.5 = strong, 0.667 = weak, 1.0 = neutral
    // Beast -> Critter (strong), Critter -> Flying (strong), Flying -> Magic (strong),
    // Magic -> Elemental? (approx classic wheel; refine against sniff later)
    extern const float DamageMultiplier[static_cast<size_t>(PetFamily::Count)][static_cast<size_t>(PetFamily::Count)];

    struct BattlePetCombatant
    {
        ObjectGuid Guid;
        uint32 SpeciesID = 0;
        uint32 CreatureID = 0; // wild pet creature entry, 0 for player-owned
        uint32 DisplayID = 0;
        PetFamily Family = PetFamily::Beast;

        uint16 Level = 1;
        uint16 Xp = 0;
        uint16 Breed = 0;
        int32 Health = 0;
        int32 MaxHealth = 0;
        int32 InitialHealth = 0;
        int32 Power = 0;   // attack power stat
        int32 Speed = 0;   // determines turn order

        uint8 BreedQuality = 0;

        std::array<uint32, 3> AbilityIds = { 0, 0, 0 }; // 3 equipped abilities
        std::array<int16, 3> AbilityCooldowns = { 0, 0, 0 };
        std::array<int16, 3> AbilityLockdowns = { 0, 0, 0 };

        struct ActiveAura
        {
            uint32 AbilityID = 0;
            uint32 SourceAbilityID = 0;
            uint32 SourceEffectID = 0;
            uint32 InstanceID = 0;
            int32 RoundsRemaining = 0;
            int32 CurrentRound = 0;
            uint8 CasterPBOID = 0;
        };
        std::vector<ActiveAura> Auras;

        // Runtime state changes produced by BattlePetAbilityEffect.db2. Aura
        // states are evaluated separately from BattlePetAbilityState.db2 so
        // that removing an aura also removes all of its modifiers.
        std::unordered_map<uint32, int32> StateValues;

        uint32 LastDamageDealt = 0;
        uint32 LastDamageTaken = 0;
        uint32 DamageTakenThisBattle = 0;
        uint32 RampingAbilityID = 0;
        uint32 PendingAbilityID = 0;
        uint8 PendingAbilityTurn = 0;
        uint8 RampingUses = 0;
        bool DidDamageThisRound = false;
        bool WasDamagedThisRound = false;
        bool Participated = false;

        bool Captured = false;
        bool FamilyPassiveUsed = false;
        bool DragonkinBonusPending = false;
        bool DragonkinBonusActive = false;
        uint8 UndeadRoundsRemaining = 0;
        uint32 DeathEffectID = 0;
        uint8 DeathCasterPBOID = 0;
        bool IsDead() const { return Health <= 0 && UndeadRoundsRemaining == 0; }

        uint8 GetUnlockedAbilityCount() const
        {
            if (Level >= 4)
                return 3;
            if (Level >= 2)
                return 2;
            return 1;
        }

        int8 GetAbilityIndex(uint32 abilityId) const
        {
            for (uint8 index = 0; index < GetUnlockedAbilityCount(); ++index)
                if (AbilityIds[index] == abilityId)
                    return int8(index);

            return -1;
        }
    };

    struct BattleSide
    {
        ObjectGuid CharacterGuid; // empty for the wild/NPC side
        std::array<BattlePetCombatant, 3> Pets;
        uint8 PetCount = 0;
        int8 FrontPet = 0; // index of active pet (0-2)

        int32 TrapAbilityID = 0;
        int32 TrapStatus = 0; // 0 = not available, >0 = number of failed attempts

        BattlePetCombatant& Active() { return Pets[FrontPet]; }
        BattlePetCombatant const& Active() const { return Pets[FrontPet]; }

        bool HasLivingPet() const
        {
            for (uint8 index = 0; index < PetCount; ++index)
                if (!Pets[index].IsDead())
                    return true;

            return false;
        }

        int8 FirstLivingPet() const
        {
            for (uint8 index = 0; index < PetCount; ++index)
                if (!Pets[index].IsDead())
                    return int8(index);

            return -1;
        }
    };

    enum class BattleState : int8
    {
        WaitingForFrontPets = 1,
        InProgress          = 2,
        Finished            = 3
    };

    struct PlayerInput
    {
        int32 MoveType = 0;
        int8 NewFrontPet = -1;
        int32 AbilityID = 0;
        int32 Round = 0;
    };

    class PetBattleSession
    {
    public:
        PetBattleSession(Player* player, Creature* wildPet, WorldPackets::PetBattle::PetBattleLocation const& location);
        ~PetBattleSession();

        ObjectGuid const& GetPlayerGuid() const { return _sides[0].CharacterGuid; }

        // Called from CMSG_PET_BATTLE_INPUT handler
        void HandleInput(WorldPackets::PetBattle::PetBattleInput const& input);
        void Forfeit(bool ignorePenalty = false);

        // Sends SMSG_PET_BATTLE_INITIAL_UPDATE + SMSG_PET_BATTLE_FIRST_ROUND
        void SendBattleStart(Player* player);

        void OnFrontPetChosen(Player* player, int8 frontPet);
        void ContinuePendingRound();

        bool IsFinished() const { return _state == BattleState::Finished; }
        bool IsFinalRoundSent() const { return _finalRoundSent; }
        bool HasLivingPlayerPet() const { return _sides[0].HasLivingPet(); }
        void AwardExperienceAndFinish();

    private:
        void ResolveRound();
        int32 CalculateEffectAmount(BattlePetCombatant& attacker, BattlePetCombatant const& defender,
            BattlePetAbilityEffectEntry const& effect, bool healing, bool attackerActsFirst) const;
        int32 GetStateValue(BattlePetCombatant const& pet, uint32 stateId) const;
        int32 GetBattleSpeed(BattlePetCombatant const& pet) const;
        int32 ApplyDamage(BattlePetCombatant& target, int32 amount);
        void ApplyHealing(BattlePetCombatant& target, int32 amount);
        void CheckCaptureWindow();
        void ProcessAbility(BattlePetCombatant& attacker, BattlePetCombatant& defender, uint32 abilityId,
            WorldPackets::PetBattle::PetBattleRoundResult& result, bool attackerActsFirst, uint8 turnIndex = 1, bool putOnCooldown = true);
        BattlePetCombatant::ActiveAura const* ApplyAura(BattlePetCombatant& caster, BattlePetCombatant& target, uint32 sourceAbilityId,
            BattlePetAbilityEffectEntry const& effect, uint8 casterPboid);
        void ProcessAuras(WorldPackets::PetBattle::PetBattleRoundResult& result);
        bool CanUseAbility(BattlePetCombatant const& pet, uint32 abilityId) const;
        void PutAbilityOnCooldown(BattlePetCombatant& pet, uint32 abilityId);
        void AdvanceRoundTimers();
        void SchedulePendingRound();
        void AppendAuraStateEffects(WorldPackets::PetBattle::PetBattleRoundResult& result, uint32 effectId,
            uint8 casterPboid, uint8 targetPboid, uint16 turnInstance, BattlePetCombatant::ActiveAura const& aura, bool removing = false);
        bool SelectFrontPet(BattleSide& side, int8 petIndex);
        void ApplyFamilyPassives(BattlePetCombatant& attacker, BattlePetCombatant const& defender, int32& damage) const;

        void BuildFullUpdate(WorldPackets::PetBattle::PetBattleInitialUpdate& packet) const;
        void BuildRoundResult(WorldPackets::PetBattle::PetBattleRoundResult& packet);

        ObjectGuid _wildPetGuid;
        WorldPackets::PetBattle::PetBattleLocation _location;
        std::array<BattleSide, 2> _sides; // [0] = player, [1] = wild/npc
        int32 _currentRound = 0;
        BattleState _state = BattleState::WaitingForFrontPets;
        bool _waitingForFrontPet = true;
        bool _finalRoundSent = false;
        bool _forfeited = false;
        bool _ignoreForfeitPenalty = false;
        bool _forfeitPenaltyApplied = false;
        bool _wildCapturable = false;
        uint8 _trapFailures = 0;
        uint8 _trapFailureBonusPct = 20;
        uint32 _nextAuraInstanceID = 1;
        BattlePetCombatant::ActiveAura _weatherAura;
        bool _hasWeatherAura = false;
        bool _continuationScheduled = false;

        // pending action chosen this round for each side (player input / simple AI)
        std::array<PlayerInput, 2> _pendingInput;
        std::array<bool, 2> _hasPendingInput = { false, false };
    };

    // Simple registry: one active session per player at a time.
    class PetBattleMgr
    {
    public:
        static PetBattleMgr* instance();

        void StartWildBattle(Player* player, Creature* wildPet, WorldPackets::PetBattle::PetBattleLocation const& location);
        void HandleInput(Player* player, WorldPackets::PetBattle::PetBattleInput const& input);
        void HandleReplaceFrontPet(Player* player, WorldPackets::PetBattle::PetBattleReplaceFrontPet const& packet);
        void HandleFinalNotify(Player* player);
        void HandleQuitNotify(Player* player);
        void EndBattle(Player* player);

        PetBattleSession* GetSession(ObjectGuid const& playerGuid);

    private:
        std::unordered_map<ObjectGuid, std::unique_ptr<PetBattleSession>> _sessions;
    };
}

#define sPetBattleMgr PetBattleSystem::PetBattleMgr::instance()

#endif // PetBattle_h__

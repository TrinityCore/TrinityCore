/*
 * Copyright 2021 DekkCore
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

#include "BattlePetPackets.h"
#include "BattlePet.h"
#include "ObjectAccessor.h"

#ifndef PetBattle_h__
#define PetBattle_h__

enum PetBattleType : uint8
{
    PET_BATTLE_TYPE_PVE,
    PET_BATTLE_TYPE_PVP_DUEL,
    PET_BATTLE_TYPE_PVP_MATCHMAKING
};

enum PvePetBattleType
{
    PVE_PET_BATTLE_WILD,
    PVE_PET_BATTLE_TRAINER
};

enum PetBattleStatus
{
    PET_BATTLE_STATUS_CREATION,
    PET_BATTLE_STATUS_RUNNING,
    PET_BATTLE_STATUS_FINISHED,
    PET_BATTLE_STATUS_PENDING_DELETE
};

enum PetBattleCastTriggerFlag
{
    PET_BATTLE_CAST_TRIGGER_NONE             = 0x00,
    PET_BATTLE_CAST_TRIGGER_IGNORE_COOLDOWN  = 0x01,

    PET_BATTLE_CAST_TRIGGER_ALL              = 0xFFFFFFFF
};

enum PetBattleCastResult
{
    PET_BATTLE_CAST_OK,
    PET_BATTLE_CAST_INVALID_ID,
    PET_BATTLE_CAST_INTERNAL_ERROR
};

enum PetBattleResult
{
    PET_BATTLE_RESULT_WON,
    PET_BATTLE_RESULT_LOOSE,
    PET_BATTLE_RESULT_ABANDON
};

enum ePetBattleRounds
{
    PET_BATTLE_ROUND_RUNNING,
    PET_BATTLE_ROUND_FINISHED
};

enum PetBattleRoundResult
{
    PET_BATTLE_ROUND_RESULT_NONE             = 0,
    PET_BATTLE_ROUND_RESULT_NORMAL           = 2,
    PET_BATTLE_ROUND_RESULT_CATCH_OR_KILL    = 3
};

enum ePetBattleAbilities
{
    PET_BATTLE_ABILITY_TURN_PROC_ON_APPLY           = 0,
    PET_BATTLE_ABILITY_TURN_PROC_ON_DAMAGE_TAKEN    = 1,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_DAMAGE_DEALT    = 2,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_HEAL_TAKEN      = 3,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_HEAL_DEALT      = 4,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_AURA_REMOVED    = 5,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_ROUND_START     = 6,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_ROUND_END       = 7,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_TURN            = 8,
    PET_BATTLE_ABILITY_TURN_PROC_ON_ABILITY         = 9,        /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_SWAP_IN         = 10,       /// implemented
    PET_BATTLE_ABILITY_TURN_PROC_ON_SWAP_OUT        = 11,       /// implemented

    PET_BATTLE_ABILITY_TURN_PROC_ON_NONE = 0xFF      /// Custom value
};

class PetBattle;

class BattlePetInstance : public BattlePet
{
public:
    BattlePetInstance();
    virtual ~BattlePetInstance() = default;

    static std::shared_ptr<BattlePetInstance> CloneForBattle(std::shared_ptr<BattlePetInstance> const& p_BattlePet);

    bool IsAlive();
    bool CanAttack();

    int32 GetMaxHealth();
    int32 GetSpeed();
    uint32 GetMaxXPForCurrentLevel();
    uint32 GetXPEarn(uint32 targetPetID);

    void UpdateOriginalInstance(Player* l_Player);

    bool Caged = false;
    bool Captured = false;

    uint32 TeamID;                                 ///< Team ID
    uint32 ID;                                     ///< Rel id for battle (0 - 1 - 2 - 3 - 4 - 5)

    int32 Cooldowns[MAX_PET_BATTLE_ABILITIES];     ///< Pet cooldowns
    int32 Lockdowns[MAX_PET_BATTLE_ABILITIES];     ///< Pet lockdowns
    int32 States[NUM_BATTLE_PET_STATES];           ///< Pet states

    PetBattle* PetBattleInstance;                      ///< Pet battle instance helper

    uint32 OldLevel;
    uint32 OldXP;

    std::shared_ptr<BattlePet> OriginalBattlePet;
    ObjectGuid OriginalCreature;
};

struct PetBattleEventUpdate
{
    PetBattleEventUpdate();

    uint32  UpdateType;     ///< Update type
    int8    TargetPetID;    ///< Target pet id

    /// Update data here
    union
    {
        int32 Health;
        int32 MaxHealth;
        int32 TriggerAbilityId;
        int32 Speed;

        /// Buff update data
        struct
        {
            uint32  ID;                     ///< Aura display slot
            uint32  AbilityID;              ///< Aura ability ID
            int32   Duration;               ///< Remaining duration
            uint32  Turn;                   ///< Aura turn
        } Buff;

        /// State npc emote
        struct
        {
            uint32  ID;                     ///< State ID
            int32   Value;                  ///< State value
        } State;

        /// State npc emote
        struct
        {
            uint32  BroadcastTextID;        ///< State ID
        } NpcEmote;
    };
};

typedef std::list<PetBattleEventUpdate> PetBattleEventUpdateList;

/// Event types
enum ePetBattleEvents
{
    PETBATTLE_EVENT_SET_HEALTH              = 0,
    PETBATTLE_EVENT_BUFF_APPLY              = 1,
    PETBATTLE_EVENT_BUFF_CANCEL             = 2,
    PETBATTLE_EVENT_BUFF_CHANGE             = 3,
    PETBATTLE_EVENT_PET_SWAP                = 4,
    PETBATTLE_EVENT_CATCH                   = 5,
    PETBATTLE_EVENT_SET_STATE               = 6,
    PETBATTLE_EVENT_SET_MAX_HEALTH          = 7,
    PETBATTLE_EVENT_SET_SPEED               = 8,
    PETBATTLE_EVENT_SET_POWER               = 9,
    PETBATTLE_EVENT_TRIGGER_ABILITY         = 10,
    PETBATTLE_EVENT_ABILITY_CHANGE          = 11,
    PETBATTLE_EVENT_NPC_EMOTE               = 12,
    PETBATTLE_EVENT_AURA_PROCESSING_BEGIN   = 13,
    PETBATTLE_EVENT_AURA_PROCESSING_END     = 14
};

/// Event flags
enum ePetBattleEventFlags
{
    PETBATTLE_EVENT_FLAG_SKIP_TURN  = 0x0001,
    PETBATTLE_EVENT_FLAG_MISS       = 0x0002,
    PETBATTLE_EVENT_FLAG_CRITICAL   = 0x0004,
    PETBATTLE_EVENT_FLAG_BLOCKED    = 0x0008,
    PETBATTLE_EVENT_FLAG_DODGE      = 0x0010,
    PETBATTLE_EVENT_FLAG_HEAL       = 0x0020,
    PETBATTLE_EVENT_FLAG_REFLECT    = 0x0080,
    PETBATTLE_EVENT_FLAG_ABSORB     = 0x0100,
    PETBATTLE_EVENT_FLAG_IMMUNE     = 0x0200,
    PETBATTLE_EVENT_FLAG_STRONG     = 0x0400,
    PETBATTLE_EVENT_FLAG_WEAK       = 0x0800,
    PETBATTLE_EVENT_FLAG_UNK_KILL   = 0x1000,

    PETBATTLE_EVENT_FLAG_PERIODIC   = 0x00010000 // Not exist in client, flags field is actually on 16 bits
};

struct PetBattleEvent
{
    PetBattleEvent(uint32 eventType = 0, int32 sourcePetID = PET_BATTLE_NULL_ID, uint32 flags = 0, uint32 abilityEffectID = 0, uint32 roundTurn = 0, uint32 buffTurn = 0, uint32 stackDepth = 0);

    PetBattleEvent& UpdateHealth(int8 targetPetID, int32 p_Health);
    PetBattleEvent& UpdateMaxHealth(int8 targetPetID, int32 p_MaxHealth);
    PetBattleEvent& UpdateState(int8 targetPetID, uint32 stateID, int32 value);
    PetBattleEvent& UpdateFrontPet(int8 newFrontPet = PET_BATTLE_NULL_ID);
    PetBattleEvent& UpdateBuff(int8 targetPetID, uint32 p_ID, uint32 abilityID, int32 duration, uint32 turn);
    PetBattleEvent& UpdateSpeed(int8 targetPetID, int32 p_Speed);
    PetBattleEvent& Trigger(int8 targetPetID, uint32 abilityID);

    uint32 EventType;               ///< Type of event (PETBATTLE_EVENT_SET_HEALTH, PETBATTLE_EVENT_BUFF_APPLY, PETBATTLE_EVENT_BUFF_CANCEL,PETBATTLE_EVENT_BUFF_CHANGE, PETBATTLE_EVENT_PET_SWAP, ...)
    uint32 Flags;                   ///< Event flags (PETBATTLE_EVENT_FLAG_SKIP_TURN,PETBATTLE_EVENT_FLAG_MISS, PETBATTLE_EVENT_FLAG_CRITICAL, PETBATTLE_EVENT_FLAG_BLOCKED, ...)
    int32  SourcePetID;             ///< Caster pet id
    uint32 AbilityEffectID;         ///< Id of an ability effect (used for client animation)
    uint32 BuffTurn;                ///< Buff rel turn count/id
    uint32 RoundTurn;               ///< Turn in round turn see  PetBattle::RoundTurn (used for order sync)
    uint32 StackDepth;              ///< unk

    PetBattleEventUpdateList Updates;   ///< Event updates, client support more than 1 update pet event, but never seen more than 1 update per event on retails
};

typedef std::list<PetBattleEvent> PetBattleEventList;

struct PetBattleRequest
{
    PetBattleRequest() = default;

    ObjectGuid RequesterGuid;
    ObjectGuid OpponentGuid;
    Position TeamPosition[MAX_PET_BATTLE_TEAM] = { };
    Position PetBattleCenterPosition;
    uint32 LocationResult = false;
    PetBattleType RequestType = PET_BATTLE_TYPE_PVE;
    bool IsPvPReady[MAX_PET_BATTLE_TEAM] = { };
};

class PetBattleAura
{
public:
    void Apply(PetBattle* petBattle);
    void Remove(PetBattle* petBattle);

    void Process(PetBattle* petBattle);
    void Expire(PetBattle* petBattle);

    uint32 AbilityID;              ///< Ability ID
    uint32 TriggerId;              /// Ability effect id
    uint32 CasterPetID;            ///< Caster pet id
    uint32 TargetPetID;            ///< Target pet id
    int32 Turn;                   ///< Turn (increment every aura process)
    uint32 ID;                     ///< Slot (client side)
    int32 Duration;               ///< Remaining duration (client sinc)
    int32 MaxDuration;            ///< Max aura duration
    bool Expired;                ///< Aura is expired ?
};

/// Team flags 1
enum PetBattleTeamInputFlags
{
    PETBATTLE_TEAM_INPUT_FLAG_LOCK_ABILITIES_1  = 0x01,
    PETBATTLE_TEAM_INPUT_FLAG_LOCK_ABILITIES_2  = 0x02,
    PETBATTLE_TEAM_INPUT_FLAG_LOCK_PET_SWAP     = 0x04,
    PETBATTLE_TEAM_INPUT_FLAG_SELECT_NEW_PET    = 0x08,
};

/// Team flags 2
enum PetBattleTeamCatchFlags
{
    PETBATTLE_TEAM_CATCH_FLAG_ENABLE_TRAP           = 0x01,
    PETBATTLE_TEAM_CATCH_FLAG_NEED_LVL3_PET         = 0x02,
    PETBATTLE_TEAM_CATCH_FLAG_TOO_MUCH_HP           = 0x04,
    PETBATTLE_TEAM_CATCH_FLAG_ONE_CATCH_PER_FIGHT   = 0x08,
};

class PetBattleTeam
{
public:
    bool Update();

    void DoCasts(uint32 p_Turn0ProcCond = PET_BATTLE_ABILITY_TURN_PROC_ON_NONE);

    bool HasPendingMultiTurnCast();

    bool CanCastAny();
    bool CanSwap(int8 replacementPet = PET_BATTLE_NULL_ID);
    uint8 CanCatchOpponentTeamFrontPet();

    uint32 GetTeamInputFlags();
    uint32 GetTeamTrapStatus();
    std::vector<uint32> GetAvailablesPets();

    uint32 GetCatchAbilityID();

    ObjectGuid OwnerGuid;                                       ///< Team owner guid
    ObjectGuid PlayerGuid;                                      ///< Team player owner guid

    PetBattle* PetBattleInstance;                          ///< Pet battle instance

    std::shared_ptr<BattlePetInstance> TeamPets[MAX_PET_BATTLE_SLOTS];   ///< Team pets
    uint32 TeamPetCount;                                    ///< Team pet count

    std::map<uint32, uint32> CapturedSpeciesCount;          ///< Captured species count

    int32 ActivePetID;                                     ///< Team active pet

    uint32 ActiveAbilityId;
    uint32 activeAbilityTurn;
    uint8 activeAbilityTurnMax;

    int8 CapturedPet;                                       ///< Captured pet id

    bool Ready;                                             ///< Team is ready to process next round
    bool isRun;                                             ///< Team is ready to run
};

class PetBattle
{
public:
    PetBattle();
    ~PetBattle();

    void AddPet(uint32 teamID, std::shared_ptr<BattlePetInstance> pet);

    void Begin();
    void ProceedRound();
    void Finish(uint32 winnerTeamID, bool aborted, bool ignoreAbandonPenalty);

    void Update(uint32 diff);

    void SwapPet(uint32 teamID, int32 newFrontPetID, bool initial = false);

    bool CanCast(uint32 teamID, uint32 abilityID);
    void PrepareCast(uint32 teamID, uint32 abilityID);
    PetBattleCastResult Cast(uint32 casterPetID, uint32 abilityID, uint32 turn, uint32 p_Turn0ProcCondition, uint32 triggerFlag);

    bool AddAura(uint32 casterPetID, uint32 targetPetID, uint32 abilityID, int32 duration, int32 p_MaxAllowed, uint32 fromAbilityEffectID, uint32 flags);
    void SetPetState(uint32 sourcePetID, uint32 targetPetID, uint32 fromAbilityEffectID, uint32 stateID, int32 value, bool fromCapture = false, uint32 flags = 0);
    void Kill(int8 killer, int8 target, uint32 killerAbibilityEffectID, bool fromCapture = false, uint32 flags = 0);
    void Catch(int8 p_Catcher, int8 p_CatchedTarget, uint32 fromAbilityEffectID);

    uint32 GetFirstAttackingTeam();

    int32 GetForfeitHealthPenalityPct();

    ObjectGuid ID;                                                          ///< Battle global unique ID
    PetBattleType BattleType;                                               ///< Battle type (PETBATTLE_TYPE_PVE / PETBATTLE_TYPE_PVP_DUEL / PETBATTLE_TYPE_PVP_MATCHMAKING)
    PveBattlePetType PveBattleType;                                         ///< PVE battle type (PVE_PETBATTLE_WILD / PVE_PETBATTLE_TRAINER)
    uint32 Turn;                                                            ///< Battle current turn id
    PetBattleResult CombatResult;                                           ///< Combat result (PETBATTLE_RESULT_WON, PETBATTLE_RESULT_LOOSE, PETBATTLE_RESULT_ABANDON)
    PetBattleRequest PvPMatchMakingRequest;                                 ///< PVP request

    uint32 BattleStatus;                                                    ///< PETBATTLE_STATUS_CREATION / PETBATTLE_STATUS_RUNNING / PETBATTLE_STATUS_FINISHED

    uint32 RoundStatus;                                                     ///< Current round status (PETBATTLE_ROUND_RUNNING / PETBATTLE_ROUND_FINISHED)
    uint32 RoundTurn;                                                       ///< Current round turn for spells cast (independant of PetBattle::Turn)
    PetBattleRoundResult RoundResult;                                       ///< Current round result
    uint32 RoundFirstTeamCasting;                                           ///< Team id who has the priority in ProceedRound (base on active pets speed)
    PetBattleEventList RoundEvents;                                         ///< Current round event queue (for client update)
    std::vector<uint8> PetXDied;                                            ///< Pets who died during this round
    std::vector<std::pair<uint32, uint32>> RoundPetSpeedUpdate;             ///< Round pet speed update <petid, abilityeffectid>

    PetBattleTeam * Teams[MAX_PET_BATTLE_TEAM];                              ///< Battle teams
    std::shared_ptr<BattlePetInstance> Pets[MAX_PET_BATTLE_TEAM * MAX_PET_BATTLE_SLOTS];      ///< All pets involved in the battle
    uint32 TotalPetCount;                                                   ///< Battle total pet count

    std::list<PetBattleAura*> PetAuras;                                             ///< Current battle pets auras
    uint32 WeatherAbilityId;                                                ///< Only one weather at a time on battle

    int32 WinnerTeamId;
    std::map<uint8, bool> FightedPets;
    int8 CatchedPetId;
    ObjectGuid InitialWildPetGUID;

private:
    IntervalTimer m_UpdateTimer;

};

enum LFBUpdateStatus : uint32
{
    LFB_NONE                                    = 0,
    LFB_JOIN_QUEUE                              = 1, // ERR_PETBATTLE_QUEUE_QUEUED
    LFB_UPDATE_STATUS                           = 2,
    LFB_ALREADY_QUEUED                          = 3, // ERR_PETBATTLE_QUEUE_ALREADY_QUEUED
    LFB_CANT_JOIN_QUEUE                         = 4, // ERR_PETBATTLE_QUEUE_JOIN_FAILED
    LFB_CANT_JOINT_QUEUE_DUE_TO_PET_STATUS      = 5,
    LFB_PET_ATLAS_IS_UNAVAILABLE_DURING_BATTLE  = 6, // ERR_PETBATTLE_QUEUE_JOURNAL_LOCK
    LFB_CANT_JOIN_DUE_TO_UNSELECTED_FACTION     = 7, // ERR_PETBATTLE_QUEUE_NOT_WHILE_NEUTRAL
    LFB_PROPOSAL_BEGIN                          = 8,
    LFB_PROPOSAL_DECLINED                       = 9, // ERR_PETBATTLE_QUEUE_PROPOSAL_DECLINED
    LFB_OPPONENT_PROPOSAL_DECLINED              = 10, // ERR_PETBATTLE_QUEUE_OPPONENT_DECLINED
    LFB_PROPOSAL_FAILED                         = 11, // ERR_PETBATTLE_QUEUE_PROPOSAL_TIMEOUT
    LFB_LEAVE_QUEUE                             = 12, // ERR_PETBATTLE_QUEUE_REMOVED
    LFB_QUEUE_ERROR                             = 13, // ERR_PETBATTLE_QUEUE_REQUEUED_INTERNAL
    LFB_OPPONENT_IS_UNAVAILABLE                 = 14, // ERR_PETBATTLE_QUEUE_REQUEUED_REMOVED
    // 18
    // 19
    LFB_PET_BATTLE_IS_STARTED                   = 20, // ERR_PETBATTLE_IN_BATTLE
    LFB_INVALIDE_LOCATION                       = 21 // ERR_PETBATTLE_NOT_HERE
};

enum LFBProposalState : uint32
{
    LFB_PROPOSAL_STATE_INITIATING   = 0,
    LFB_PROPOSAL_STATE_FAILED       = 1,
    LFB_PROPOSAL_STATE_SUCCESS      = 2
};

#endif // PetBattle_h__

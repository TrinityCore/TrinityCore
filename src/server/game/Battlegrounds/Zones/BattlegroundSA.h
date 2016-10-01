/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLEGROUNDSA_H
#define __BATTLEGROUNDSA_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Object.h"

enum BG_SA_Status
{
    BG_SA_NOT_STARTED = 0,
    BG_SA_WARMUP,
    BG_SA_ROUND_ONE,
    BG_SA_SECOND_WARMUP,
    BG_SA_ROUND_TWO,
    BG_SA_BONUS_ROUND
};

enum BG_SA_GateState
{
    BG_SA_GATE_OK           = 1,
    BG_SA_GATE_DAMAGED      = 2,
    BG_SA_GATE_DESTROYED    = 3
};

enum BG_SA_EventIds
{
    BG_SA_EVENT_BLUE_GATE_DAMAGED           = 19040,
    BG_SA_EVENT_BLUE_GATE_DESTROYED         = 19045,

    BG_SA_EVENT_GREEN_GATE_DAMAGED          = 19041,
    BG_SA_EVENT_GREEN_GATE_DESTROYED        = 19046,

    BG_SA_EVENT_RED_GATE_DAMAGED            = 19042,
    BG_SA_EVENT_RED_GATE_DESTROYED          = 19047,

    BG_SA_EVENT_PURPLE_GATE_DAMAGED         = 19043,
    BG_SA_EVENT_PURPLE_GATE_DESTROYED       = 19048,

    BG_SA_EVENT_YELLOW_GATE_DAMAGED         = 19044,
    BG_SA_EVENT_YELLOW_GATE_DESTROYED       = 19049,

    BG_SA_EVENT_ANCIENT_GATE_DAMAGED        = 19836,
    BG_SA_EVENT_ANCIENT_GATE_DESTROYED      = 19837,

    BG_SA_EVENT_TITAN_RELIC_ACTIVATED       = 20572
};

enum SASpellIds
{
    SPELL_TELEPORT_DEFENDER                 = 52364,
    SPELL_TELEPORT_ATTACKERS                = 60178,
    SPELL_END_OF_ROUND                      = 52459,
    SPELL_REMOVE_SEAFORIUM                  = 59077,
    SPELL_ALLIANCE_CONTROL_PHASE_SHIFT      = 60027,
    SPELL_HORDE_CONTROL_PHASE_SHIFT         = 60028,
    SPELL_STORM_THE_BEACH_CREDIT            = 65246
};

enum SACreatureIds
{
    NPC_KANRETHAD                                   = 29,
    NPC_INVISIBLE_STALKER                           = 15214,
    NPC_WORLD_TRIGGER                               = 22515,
    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC   = 23472,

    NPC_ANTI_PERSONNAL_CANNON                       = 27894,
    NPC_DEMOLISHER_SA                               = 28781,
    NPC_RIGGER_SPARKLIGHT                           = 29260,
    NPC_GORGRIL_RIGSPARK                            = 29262
};

enum SAGameObjectIds
{
    GO_GATE_OF_THE_GREEN_EMERALD            = 190722,
    GO_GATE_OF_THE_PURPLE_AMETHYST          = 190723,
    GO_GATE_OF_THE_BLUE_SAPPHIRE            = 190724,
    GO_GATE_OF_THE_RED_SUN                  = 190726,
    GO_GATE_OF_THE_YELLOW_MOON              = 190727,
    GO_CHAMBER_OF_ANCIENT_RELICS            = 192549,

    GO_TITAN_RELIC_A                        = 194083,
    GO_TITAN_RELIC_H                        = 194082,

    GO_DEFENDER_PORTAL_A                    = 191575,
    GO_DEFENDER_PORTAL_H                    = 190763,

    GO_GREEN_MOON_SIGIL                     = 192687,
    GO_YELLOW_MOON_SIGIL                    = 192685,
    GO_BLUE_MOON_SIGIL                      = 192689,
    GO_RED_MOON_SIGIL                       = 192690,
    GO_PURPLE_MOON_SIGIL                    = 192691,

    GO_FLAGPOLE                             = 191311,

    GO_ALLIANCE_BANNER_CENTER               = 191310,
    GO_HORDE_BANNER_CENTER                  = 191309,
    GO_ALLIANCE_BANNER_RIGHT                = 191306,
    GO_HORDE_BANNER_RIGHT                   = 191305,
    GO_ALLIANCE_BANNER_LEFT                 = 191308,
    GO_HORDE_BANNER_LEFT                    = 191307,

    GO_SEAFORIUM_BOMB_A                     = 190753,
    GO_SEAFORIUM_BOMB_H                     = 194086
};

enum BG_SA_Timers
{
    BG_SA_BOAT_START    =  60 * IN_MILLISECONDS,
    BG_SA_WARMUPLENGTH  = 120 * IN_MILLISECONDS,
    BG_SA_ROUNDLENGTH   = 600 * IN_MILLISECONDS
};

enum SASounds
{
    SOUND_GRAVEYARD_TAKEN_HORDE     = 8174,
    SOUND_GRAVEYARD_TAKEN_ALLIANCE  = 8212,
    SOUND_DEFEAT_HORDE              = 15905,
    SOUND_VICTORY_HORDE             = 15906,
    SOUND_VICTORY_ALLIANCE          = 15907,
    SOUND_DEFEAT_ALLIANCE           = 15908,
    SOUND_WALL_DESTROYED_ALLIANCE   = 15909,
    SOUND_WALL_DESTROYED_HORDE      = 15910,
    SOUND_WALL_ATTACKED_HORDE       = 15911,
    SOUND_WALL_ATTACKED_ALLIANCE    = 15912
};

enum SATexts
{
    // Kanrethad
    TEXT_ROUND_STARTED              = 1,
    TEXT_ROUND_1_FINISHED           = 2,

    // Rigger Sparklight / Gorgril Rigspark
    TEXT_SPARKLIGHT_RIGSPARK_SPAWN  = 1,

    // World Trigger
    TEXT_BLUE_GATE_UNDER_ATTACK     = 1,
    TEXT_GREEN_GATE_UNDER_ATTACK    = 2,
    TEXT_RED_GATE_UNDER_ATTACK      = 3,
    TEXT_PURPLE_GATE_UNDER_ATTACK   = 4,
    TEXT_YELLOW_GATE_UNDER_ATTACK   = 5,
    TEXT_YELLOW_GATE_DESTROYED      = 6,
    TEXT_PURPLE_GATE_DESTROYED      = 7,
    TEXT_RED_GATE_DESTROYED         = 8,
    TEXT_GREEN_GATE_DESTROYED       = 9,
    TEXT_BLUE_GATE_DESTROYED        = 10,
    TEXT_EAST_GRAVEYARD_CAPTURED_A  = 11,
    TEXT_WEST_GRAVEYARD_CAPTURED_A  = 12,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_A = 13,
    TEXT_EAST_GRAVEYARD_CAPTURED_H  = 14,
    TEXT_WEST_GRAVEYARD_CAPTURED_H  = 15,
    TEXT_SOUTH_GRAVEYARD_CAPTURED_H = 16,
    TEXT_ANCIENT_GATE_UNDER_ATTACK  = 17,
    TEXT_ANCIENT_GATE_DESTROYED     = 18
};

enum SAWorldStates
{
    BG_SA_TIMER_MINS                = 3559,
    BG_SA_TIMER_SEC_TENS            = 3560,
    BG_SA_TIMER_SEC_DECS            = 3561,
    BG_SA_ALLY_ATTACKS              = 4352,
    BG_SA_HORDE_ATTACKS             = 4353,
    BG_SA_PURPLE_GATEWS             = 3614,
    BG_SA_RED_GATEWS                = 3617,
    BG_SA_BLUE_GATEWS               = 3620,
    BG_SA_GREEN_GATEWS              = 3623,
    BG_SA_YELLOW_GATEWS             = 3638,
    BG_SA_ANCIENT_GATEWS            = 3849,
    BG_SA_LEFT_GY_ALLIANCE          = 3635,
    BG_SA_RIGHT_GY_ALLIANCE         = 3636,
    BG_SA_CENTER_GY_ALLIANCE        = 3637,
    BG_SA_RIGHT_ATT_TOKEN_ALL       = 3627,
    BG_SA_LEFT_ATT_TOKEN_ALL        = 3626,
    BG_SA_LEFT_ATT_TOKEN_HRD        = 3629,
    BG_SA_RIGHT_ATT_TOKEN_HRD       = 3628,
    BG_SA_HORDE_DEFENCE_TOKEN       = 3631,
    BG_SA_ALLIANCE_DEFENCE_TOKEN    = 3630,
    BG_SA_RIGHT_GY_HORDE            = 3632,
    BG_SA_LEFT_GY_HORDE             = 3633,
    BG_SA_CENTER_GY_HORDE           = 3634,
    BG_SA_BONUS_TIMER               = 3571,
    BG_SA_ENABLE_TIMER              = 3564
};

enum BG_SA_NPCs
{
    BG_SA_GUN_1 = 0,
    BG_SA_GUN_2,
    BG_SA_GUN_3,
    BG_SA_GUN_4,
    BG_SA_GUN_5,
    BG_SA_GUN_6,
    BG_SA_GUN_7,
    BG_SA_GUN_8,
    BG_SA_GUN_9,
    BG_SA_GUN_10,
    BG_SA_DEMOLISHER_1,
    BG_SA_DEMOLISHER_2,
    BG_SA_DEMOLISHER_3,
    BG_SA_DEMOLISHER_4,
    BG_SA_DEMOLISHER_5,
    BG_SA_DEMOLISHER_6,
    BG_SA_DEMOLISHER_7,
    BG_SA_DEMOLISHER_8,
    BG_SA_NPC_SPARKLIGHT,
    BG_SA_NPC_RIGSPARK,
    BG_SA_NPC_KANRETHAD,
    BG_SA_TELEPORT_TRIGGER_GREEN,
    BG_SA_TELEPORT_TRIGGER_YELLOW,
    BG_SA_TELEPORT_TRIGGER_BLUE,
    BG_SA_TELEPORT_TRIGGER_RED,
    BG_SA_TELEPORT_TRIGGER_PURPLE,
    BG_SA_MAXNPC,

    BG_SA_DEMOLISHER_AMOUNT = BG_SA_DEMOLISHER_8 - BG_SA_DEMOLISHER_1 + 1
};

enum BG_SA_Boat
{
    BG_SA_BOAT_ONE_A    = 193182,
    BG_SA_BOAT_TWO_H    = 193183,

    BG_SA_BOAT_ONE_H    = 193184,
    BG_SA_BOAT_TWO_A    = 193185
};

enum BG_SA_Objects
{
    BG_SA_GREEN_GATE = 0,
    BG_SA_YELLOW_GATE,
    BG_SA_BLUE_GATE,
    BG_SA_RED_GATE,
    BG_SA_PURPLE_GATE,
    BG_SA_ANCIENT_GATE,
    BG_SA_TITAN_RELIC_A,
    BG_SA_TITAN_RELIC_H,
    BG_SA_PORTAL_DEFENDER_BLUE_A,
    BG_SA_PORTAL_DEFENDER_BLUE_H,
    BG_SA_PORTAL_DEFENDER_GREEN_A,
    BG_SA_PORTAL_DEFENDER_GREEN_H,
    BG_SA_PORTAL_DEFENDER_YELLOW_A,
    BG_SA_PORTAL_DEFENDER_YELLOW_H,
    BG_SA_PORTAL_DEFENDER_PURPLE_A,
    BG_SA_PORTAL_DEFENDER_PURPLE_H,
    BG_SA_PORTAL_DEFENDER_RED_A,
    BG_SA_PORTAL_DEFENDER_RED_H,
    BG_SA_GREEN_SIGIL,
    BG_SA_YELLOW_SIGIL,
    BG_SA_BLUE_SIGIL,
    BG_SA_RED_SIGIL,
    BG_SA_PURPLE_SIGIL,
    BG_SA_CENTRAL_FLAGPOLE,
    BG_SA_RIGHT_FLAGPOLE,
    BG_SA_LEFT_FLAGPOLE,
    BG_SA_CENTRAL_FLAG_A,
    BG_SA_CENTRAL_FLAG_H,
    BG_SA_RIGHT_FLAG_A,
    BG_SA_RIGHT_FLAG_H,
    BG_SA_LEFT_FLAG_A,
    BG_SA_LEFT_FLAG_H,
    BG_SA_BOMB_A_1,
    BG_SA_BOMB_A_91 = BG_SA_BOMB_A_1 + 90 * BG_TEAMS_COUNT,
    BG_SA_BOMB_H_91,

    BG_SA_MAXOBJ = BG_SA_BOMB_H_91 + 1,

    BG_SA_BOAT_ONE = BG_SA_MAXOBJ,
    BG_SA_BOAT_TWO,

    BG_SA_MAX_SHIPS_PER_TEAM = BG_SA_BOAT_TWO - BG_SA_BOAT_ONE + 1,
    BG_SA_MAX_GATES = BG_SA_ANCIENT_GATE + 1
};

enum BG_SA_Graveyards
{
    BG_SA_BEACH_GY = 0,
    BG_SA_DEFENDER_LAST_GY,
    BG_SA_RIGHT_CAPTURABLE_GY,
    BG_SA_LEFT_CAPTURABLE_GY,
    BG_SA_CENTRAL_CAPTURABLE_GY,
    BG_SA_MAX_GY
};

struct GateInfo
{
    uint32 GateId;
    uint32 LinkedGateId;
    uint32 GameObjectId;
    uint32 WorldState;
    uint8 DamagedText;
    uint8 DestroyedText;
};

struct BG_SA_RoundScore
{
    TeamId winner;
    uint32 time;
};

struct BattlegroundSAScore final : public BattlegroundScore
{
    friend class BattlegroundSA;

    protected:
        BattlegroundSAScore(ObjectGuid playerGuid) : BattlegroundScore(playerGuid), DemolishersDestroyed(0), GatesDestroyed(0) { }

        void UpdateScore(uint32 type, uint32 value) override
        {
            switch (type)
            {
                case SCORE_DESTROYED_DEMOLISHER:
                    DemolishersDestroyed += value;
                    break;
                case SCORE_DESTROYED_WALL:
                    GatesDestroyed += value;
                    break;
                default:
                    BattlegroundScore::UpdateScore(type, value);
                    break;
            }
        }

        void BuildObjectivesBlock(WorldPacket& data) final override
        {
            data << uint32(2); // Objectives Count
            data << uint32(DemolishersDestroyed);
            data << uint32(GatesDestroyed);
        }

        uint32 GetAttr1() const final override { return DemolishersDestroyed; }
        uint32 GetAttr2() const final override { return GatesDestroyed; }

        uint32 DemolishersDestroyed;
        uint32 GatesDestroyed;
};

/// Class for manage Strand of Ancient battleground
class BattlegroundSA : public Battleground
{
    public:
        BattlegroundSA();
        ~BattlegroundSA();

        /**
         * \brief Called every time for update battle data
         * -Update timer
         * -Round switch
         */
        void PostUpdateImpl(uint32 diff) override;

        /* inherited from BattlegroundClass */
        /// Called when a player join battle
        void AddPlayer(Player* player) override;
        /// Called when battle start
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;
        /// Called for ini battleground, after that the first player be entered
        bool SetupBattleground() override;
        void Reset() override;
        /// Called for generate packet contain worldstate data
        void FillInitialWorldStates(WorldPacket& data) override;
        /// Called when a player kill a unit in bg
        void HandleKillUnit(Creature* creature, Player* killer) override;
        /// Return the nearest graveyard where player can respawn
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;
        /// Called when someone activates an event
        void ProcessEvent(WorldObject* /*obj*/, uint32 /*eventId*/, WorldObject* /*invoker*/ = nullptr) override;
        /// Called when a player click on flag (graveyard flag)
        void EventPlayerClickedOnFlag(Player* source, GameObject* go) override;
        /// Called when a player clicked on relic
        void TitanRelicActivated(Player* clicker);

        /// Return GateInfo, relative to bg data, according to gameobject entry
        static GateInfo const* GetGate(uint32 entry);

        /// Called on battleground ending
        void EndBattleground(uint32 winner) override;

        /// Called when a player leave battleground
        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* Source, uint32 Trigger) override;

        /* Scorekeeping */

        // Achievement: Not Even a Scratch
        bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target = nullptr, uint32 miscValue = 0) override;

        // Control Phase Shift
        bool IsSpellAllowed(uint32 spellId, Player const* player) const override;

    private:

        /**
         * \brief Called on setup and between the two round
         * -Delete all gameobject / creature
         * -Respawn all gameobject / creature to have good faction
         */
        bool ResetObjs();
        /// Called for start ship movement
        void StartShips();
        /**
         * \brief Called between the two round
         * -Teleport all players to good location
         */
        void TeleportPlayers();
        void TeleportToEntrancePosition(Player* player);
        /**
         * \brief Called on start and between the two round
         * -Update faction of all vehicle
         */
        void OverrideGunFaction();
        /// Set selectable or not demolisher, called on battle start, when boats arrive to dock
        void DemolisherStartState(bool start);
        /// Checks if a player can interact with the given object
        bool CanInteractWithObject(uint32 objectId);
        /// Updates interaction flags of specific objects
        void UpdateObjectInteractionFlags(uint32 objectId);
        void UpdateObjectInteractionFlags();
        void UpdateBombInteractionFlags();
        /**
         * \brief Called when a gate is destroy
         * -Give honor to player witch destroy it
         * -Update worldstate
         * -Delete gameobject in front of door (lighting object, with different colours for each door)
         */
        void DestroyGate(Player* player, GameObject* go) override;
        /// Update timer worldstate
        void SendTime();
        /**
         * \brief Called when a graveyard is capture
         * -Update spiritguide
         * -Update gameobject (flag)
         * -Update Worldstate
         * -Send warning for announce this
         * \param i : id of graveyard
         * \param Source : Player who capture gy
         */
        void CaptureGraveyard(BG_SA_Graveyards i, Player* Source);
        /// Switch on/off timer worldstate
        void ToggleTimer();

        /// Respawn dead demolisher
        void UpdateDemolisherSpawns();

        /// Send packet to player for create boats (client part)
        void SendTransportInit(Player* player);
        /// Send packet to player for destroy boats (client part)
        void SendTransportsRemove(Player* player);

        /// Id of attacker team
        TeamId Attackers;

        /// Totale elapsed time of current round
        uint32 TotalTime;
        /// Max time of round
        uint32 EndRoundTimer;
        /// For know if boats has start moving or not yet
        bool ShipsStarted;
        /// Status of each gate (Destroy/Damage/Intact)
        BG_SA_GateState GateStatus[BG_SA_MAX_GATES];
        /// Statu of battle (Start or not, and what round)
        BG_SA_Status Status;
        /// Team witch conntrol each graveyard
        TeamId GraveyardStatus[BG_SA_MAX_GY];
        /// Score of each round
        BG_SA_RoundScore RoundScores[2];
        /// used for know we are in timer phase or not (used for worldstate update)
        bool TimerEnabled;
        /// 5secs before starting the 1min countdown for second round
        uint32 UpdateWaitTimer;
        /// for know if warning about second round start has been sent
        bool SignaledRoundTwo;
        /// for know if warning about second round start has been sent
        bool SignaledRoundTwoHalfMin;
        /// for know if second round has been init
        bool InitSecondRound;

        std::array<uint32 /*respawnTime*/, BG_SA_DEMOLISHER_AMOUNT> DemolisherRespawnTimes;

        // Achievement: Defense of the Ancients
        bool _gateDestroyed;

        // Achievement: Not Even a Scratch
        bool _allVehiclesAlive[BG_TEAMS_COUNT];
};
#endif

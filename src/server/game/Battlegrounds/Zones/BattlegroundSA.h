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

#ifndef __BATTLEGROUNDSA_H
#define __BATTLEGROUNDSA_H

#include "Battleground.h"
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
    // alliance is defender
    BG_SA_ALLIANCE_GATE_OK          = 1,
    BG_SA_ALLIANCE_GATE_DAMAGED     = 2,
    BG_SA_ALLIANCE_GATE_DESTROYED   = 3,
    // horde is defender
    BG_SA_HORDE_GATE_OK             = 4,
    BG_SA_HORDE_GATE_DAMAGED        = 5,
    BG_SA_HORDE_GATE_DESTROYED      = 6,
};

enum StrandOfTheAncientsGameObjects
{
    GO_SEAFORIUM_BOMB_H = 194086, // Used by horde players
    GO_SEAFORIUM_BOMB_A = 190753, // Used by alliance players
    GO_SEAFORIUM_CHARGE_H = 257572,
    GO_SEAFORIUM_CHARGE_A = 257565,

    GO_GRAVEYARD_WEST_H = 191307,
    GO_GRAVEYARD_WEST_A = 191308,

    GO_GRAVEYARD_EAST_H = 191305,
    GO_GRAVEYARD_EAST_A = 191306,

    GO_GRAVEYARD_CENTRAL_H = 191309,
    GO_GRAVEYARD_CENTRAL_A = 191310,

    GO_COLLISION_DOOR = 194162,
    GO_TITAN_RELIC_A = 194083,
    GO_TITAN_RELIC_H = 194082,

    GO_GATE_OF_THE_GREEN_EMERALD            = 190722,
    GO_GATE_OF_THE_PURPLE_AMETHYST          = 190723,
    GO_GATE_OF_THE_BLUE_SAPPHIRE            = 190724,
    GO_GATE_OF_THE_RED_SUN                  = 190726,
    GO_GATE_OF_THE_YELLOW_MOON              = 190727,
    GO_CHAMBER_OF_ANCIENT_RELICS            = 192549
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
    BG_SA_TIMER                     = 3557,
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

    BG_SA_ENABLE_TIMER              = 3564,
    BG_SA_ATTACKER_TEAM             = 3690,
    BG_SA_DESTROYED_ALLIANCE_VEHICLES   = 3955,
    BG_SA_DESTROYED_HORDE_VEHICLES      = 3956,
};

enum BG_SA_Boat
{
    BG_SA_BOAT_ONE_A    = 208000,
    BG_SA_BOAT_TWO_H    = 208001,
    BG_SA_BOAT_ONE_H    = 193184,
    BG_SA_BOAT_TWO_A    = 193185
};

uint32 const BG_SA_Factions[2] =
{
    1732,
    1735,
};

enum class StrandOfTheAncientsGraveyard
{
    West,
    East,
    Central
};

enum BG_SA_BroadcastTexts
{
    BG_SA_TEXT_ALLIANCE_CAPTURED_TITAN_PORTAL   = 28944,
    BG_SA_TEXT_HORDE_CAPTURED_TITAN_PORTAL      = 28945,

    BG_SA_TEXT_ROUND_TWO_START_ONE_MINUTE       = 29448,
    BG_SA_TEXT_ROUND_TWO_START_HALF_MINUTE      = 29449
};

enum class DefenseLine
{
    First,
    Second,
    Third,
    Last
};

struct GateInfo
{
    uint32 GameObjectId;
    uint32 WorldState;
    uint8 DamagedText;
    uint8 DestroyedText;
    DefenseLine LineOfDefense;
};

GateInfo const Gates[] =
{
    { GO_GATE_OF_THE_GREEN_EMERALD,   BG_SA_GREEN_GATEWS,   TEXT_GREEN_GATE_UNDER_ATTACK,   TEXT_GREEN_GATE_DESTROYED,      DefenseLine::First  },
    { GO_GATE_OF_THE_YELLOW_MOON,     BG_SA_YELLOW_GATEWS,  TEXT_YELLOW_GATE_UNDER_ATTACK,  TEXT_YELLOW_GATE_DESTROYED,     DefenseLine::Third  },
    { GO_GATE_OF_THE_BLUE_SAPPHIRE,   BG_SA_BLUE_GATEWS,    TEXT_BLUE_GATE_UNDER_ATTACK,    TEXT_BLUE_GATE_DESTROYED,       DefenseLine::First  },
    { GO_GATE_OF_THE_RED_SUN,         BG_SA_RED_GATEWS,     TEXT_RED_GATE_UNDER_ATTACK,     TEXT_RED_GATE_DESTROYED,        DefenseLine::Second },
    { GO_GATE_OF_THE_PURPLE_AMETHYST, BG_SA_PURPLE_GATEWS,  TEXT_PURPLE_GATE_UNDER_ATTACK,  TEXT_PURPLE_GATE_DESTROYED,     DefenseLine::Second },
    { GO_CHAMBER_OF_ANCIENT_RELICS,   BG_SA_ANCIENT_GATEWS, TEXT_ANCIENT_GATE_UNDER_ATTACK, TEXT_ANCIENT_GATE_DESTROYED,    DefenseLine::Last   }
};

struct BG_SA_RoundScore
{
    TeamId winner;
    uint32 time;
};

enum StrandOfTheAncientSharedActions
{
    ACTION_SOTA_CAPTURE_GRAVEYARD
};

/// Class for manage Strand of Ancient battleground
class BattlegroundSA : public Battleground
{
    public:
        BattlegroundSA(BattlegroundTemplate const* battlegroundTemplate);
        ~BattlegroundSA();

        /**
         * \brief Called every time for update battle data
         * -Update timer
         * -Round switch
         */
        void PostUpdateImpl(uint32 diff) override;

        /* inherited from BattlegroundClass */
        /// Called when a player join battle
        void AddPlayer(Player* player, BattlegroundQueueTypeId queueId) override;
        /// Called for ini battleground, after that the first player be entered
        bool SetupBattleground() override;
        void Reset() override;
        /// Called when a player kill a unit in bg
        void HandleKillUnit(Creature* creature, Unit* killer) override;
        /// Called when someone activates an event
        void ProcessEvent(WorldObject* /*obj*/, uint32 /*eventId*/, WorldObject* /*invoker*/ = nullptr) override;
        /// Called when a player clicked on relic
        void TitanRelicActivated(Player* clicker);

        /// Return GateInfo, relative to bg data, according to gameobject entry
        GateInfo const* GetGate(uint32 entry)
        {
            for (GateInfo const& gate : Gates)
                if (gate.GameObjectId == entry)
                    return &gate;

            return nullptr;
        }

        /// Called on battleground ending
        void EndBattleground(Team winner) override;

        /// Called when a player leave battleground
        void RemovePlayer(Player* player, ObjectGuid guid, uint32 team) override;
        void HandleAreaTrigger(Player* source, uint32 trigger, bool entered) override;

        void OnGameObjectCreate(GameObject* gameobject) override;
        void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override;
        void OnCreatureCreate(Creature* creature) override;

        void OnMapSet(BattlegroundMap* map) override;
        uint32 GetData(uint32 dataId) const override;
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
        void TeleportPlayers() const;
        void TeleportToEntrancePosition(Player* player) const;
        /**
         * \brief Called when a gate is destroy
         * -Give honor to player witch destroy it
         * -Update worldstate
         * -Delete gameobject in front of door (lighting object, with different colours for each door)
         */
        void DestroyGate(Player* player, GameObject* go) override;
        /**
         * \brief Called when a graveyard is capture
         * -Update spiritguide
         * -Update gameobject (flag)
         * -Update Worldstate
         * -Send warning for announce this
         * \param i : id of graveyard
         * \param Source : Player who capture gy
         */
        void CaptureGraveyard(StrandOfTheAncientsGraveyard graveyard, TeamId teamId);
        /// Switch on/off timer worldstate
        void ToggleTimer();

        /// Send packet to player for create boats (client part)
        void SendTransportInit(Player* player);
        /// Send packet to player for destroy boats (client part)
        void SendTransportsRemove(Player* player);

        bool IsGateDestroyed(GateInfo const* gateInfo) const;

        void HandleCaptureGraveyardAction(GameObject* graveyardBanner, Player* player);

        void MakeObjectsInteractable(DefenseLine defenseLine);

        Creature* FindKanrethad() const;

        void EndRound();

        /// Id of attacker team
        TeamId Attackers;

        /// Totale elapsed time of current round
        uint32 TotalTime;
        /// Max time of round
        uint32 EndRoundTimer;
        /// For know if boats has start moving or not yet
        bool ShipsStarted;
        /// Statu of battle (Start or not, and what round)
        BG_SA_Status Status;
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

        // [team][boat_idx]
        std::array<std::array<ObjectGuid, 2 /*BOAT_COUNT*/>, PVP_TEAMS_COUNT> _boatGUIDs;
        std::array<GuidUnorderedSet, PVP_TEAMS_COUNT> _staticBombGUIDs; // bombs ready to be picked up
        GuidUnorderedSet _dynamicBombGUIDs; // bombs thrown by players, ready to explode/disarm

        ObjectGuid _graveyardWest;
        ObjectGuid _graveyardEast;
        ObjectGuid _graveyardCentral;
        GuidUnorderedSet _gateGUIDs;
        ObjectGuid _collisionDoorGUID;
        ObjectGuid _kanrethadGUID;
        ObjectGuid _titanRelicGUID;
};
#endif

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

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "BattlegroundScript.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"

namespace SilvershardMines
{
    namespace Actions
    {
        static constexpr uint32 MineCartCaptured = 1;
        static constexpr uint32 TrackChanged = 2;
        static constexpr uint32 MineCartControlChanged = 3;
        static constexpr uint32 MineCartCapturedPlayer = 4;
    }

    namespace BroadcastTexts
    {
        static constexpr uint32 AllianceControlsMineCart = 60441;
        static constexpr uint32 HordeControlsMineCart = 60442;

        static constexpr uint32 EasternCrossroadsChangedTracks = 60030;
        static constexpr uint32 NorthernCrossroadsChangedTracks = 60032;
    }

    namespace Creatures
    {
        static constexpr uint32 MineCart = 60140;

        static constexpr uint32 MineCartCosmetic1 = 60379;
        static constexpr uint32 MineCartCosmetic2 = 60378;
        static constexpr uint32 MineCartCosmetic3 = 60380;

        static constexpr std::array<std::pair<uint32, double>, 3> CosmeticCarts =
        {{
            { MineCartCosmetic1, 1.0 },
            { MineCartCosmetic2, 0.05 },
            { MineCartCosmetic3, 0.05 }
        }};
    }

    namespace CreatureTexts::MineCart
    {
        static constexpr uint32 Spawned = 1;
        static constexpr uint32 CapturedByAlliance = 2;
        static constexpr uint32 CapturedByHorde = 3;
    }

    namespace Events
    {
        static constexpr uint32 ProgressEventHordeEast = 32909;
        static constexpr uint32 ProgressEventAllianceEast = 32910;
        static constexpr uint32 ProgressEventNeutralEast = 32912;

        static constexpr uint32 ProgressEventHordeNorth = 31167;
        static constexpr uint32 ProgressEventAllianceNorth = 31166;

        static constexpr uint32 ProgressEventHordeSouth = 32937;
        static constexpr uint32 ProgressEventAllianceSouth = 32938;
        static constexpr uint32 ProgressEventNeutralSouth = 32951;
    }

    namespace GameObjects
    {
        static constexpr uint32 Gate1 = 212939;
        static constexpr uint32 Gate2 = 212940;
        static constexpr uint32 Gate3 = 212941;
        static constexpr uint32 Gate4 = 212942;

    }

    namespace Maps
    {
        static constexpr uint32 BattlegroundMap = 727;
    }

    namespace PathIds
    {
        static constexpr uint32 South = Creatures::MineCart * 100 + 0;
        static constexpr uint32 SouthEnd = Creatures::MineCart * 100 + 1;

        static constexpr uint32 North = Creatures::MineCart * 100 + 2;
        static constexpr uint32 NorthEast = Creatures::MineCart * 100 + 3;
        static constexpr uint32 NorthEastEnd = Creatures::MineCart * 100 + 4;
        static constexpr uint32 NorthWest = Creatures::MineCart * 100 + 5;
        static constexpr uint32 NorthWestEnd = Creatures::MineCart * 100 + 6;

        static constexpr uint32 East = Creatures::MineCart * 100 + 7;
        static constexpr uint32 EastSouth = Creatures::MineCart * 100 + 8;
        static constexpr uint32 EastSouthEnd = Creatures::MineCart * 100 + 9;
        static constexpr uint32 EastNorth = Creatures::MineCart * 100 + 10;
        static constexpr uint32 EastNorthEnd = Creatures::MineCart * 100 + 11;

        static constexpr uint32 CosmeticCart1 = Creatures::MineCartCosmetic1 * 100 + 0;
        static constexpr uint32 CosmeticCart2 = Creatures::MineCartCosmetic1 * 100 + 1;
        static constexpr uint32 CosmeticCart3 = Creatures::MineCartCosmetic1 * 100 + 2;
    }

    namespace PvpStats
    {
        static constexpr uint32 CartsCaptured = 428;
    }

    namespace Score
    {
        static constexpr uint32 Max = 1500;
        static constexpr uint32 Capture = 150;
    }

    namespace SpawnPositions
    {
        static constexpr Position MineCartSouth = { 739.29517f, 203.76389f, 319.54398f, 2.261440753936767578f };
        static constexpr Position MineCartEast = { 744.5174f, 183.19792f, 319.54395f, 4.338116168975830078f };
        static constexpr Position MineCartNorth = { 759.32465f, 198.3316f, 319.53058f, 0.421508282423019409f };

        static constexpr std::array<std::pair<uint32, Position>, 3> CosmeticCartsSpawnPositions =
        { {
            { PathIds::CosmeticCart1, { 735.7135f, 293.2292f, 398.70938f } },
            { PathIds::CosmeticCart2, { 580.17706f, 305.46524f, 395.6946f } },
            { PathIds::CosmeticCart3, { 1117.7551f, 285.7205f, 389.8406f } }
        }};
    }

    namespace Spells
    {
        static constexpr uint32 ControlVisualNeutral = 118001;
        static constexpr uint32 ControlVisualHorde = 116085;
        static constexpr uint32 ControlVisualAlliance = 116086;

        static constexpr uint32 CartControlCapturePointUnitEast = 125620;
        static constexpr uint32 CartControlCapturePointUnitNorth = 125695;
        static constexpr uint32 CartControlCapturePointUnitSouth = 125696;

        static constexpr uint32 DefendingCartAura = 128646; // triggers 128648

        static constexpr uint32 CartCap = 115904;

        static constexpr uint32 Capturing = 124492;

        static constexpr uint32 TrackSwitchVisualOpened = 120228;
        static constexpr uint32 TrackSwitchVisualClosed = 120229;

        // Achievements

        // Mine Cart Courier
        // Capture a mine cart using each of the 5 sets of tracks in a single match
        static constexpr uint32 MineCartCourierEastSouth = 128702;
        static constexpr uint32 MineCartCourierEastNorth = 128703;
        static constexpr uint32 MineCartCourierNorthWest = 128706;
        static constexpr uint32 MineCartCourierNorthEast = 128705;
        static constexpr uint32 MineCartCourierSouth = 128704;

        // End of the Line
        // Seize control of a mine that is controlled by the opposing team within 20yards of the depot, and then capture it
        static constexpr uint32 EndOfTheLineAchievementCheck = 128720;

        // The Long Riders
        // Escort a mine from its spawn to a depot and capture it without losing control
        static constexpr uint32 LongRiderAchievementEastAlliance = 128672;
        static constexpr uint32 LongRiderAchievementEastHorde = 128668;
        static constexpr uint32 LongRiderAchievementNorthAlliance = 128673;
        static constexpr uint32 LongRiderAchievementNorthHorde = 128669;
        static constexpr uint32 LongRiderAchievementSouthAlliance = 128674;
        static constexpr uint32 LongRiderAchievementSouthHorde = 128670;

        // Five for Five
        // Capture five mine carts in a single Silvershard Mines battle without dying
        static constexpr uint32 ThreeForThreeComplete = 128650;
    }

    namespace StringIds
    {
        static constexpr std::string_view MineDepot = "bg_silvershard_mine_depot";
        static constexpr std::string_view TrackSwitchEast = "bg_silvershard_mines_track_switch_east";
        static constexpr std::string_view TrackSwitchNorth = "bg_silvershard_mines_track_switch_north";
    }

    namespace WorldStates
    {
        static constexpr int32 EasternCrossroadsTrackSwitchState = 6467; // 1 (closed) or 2 (open)
        static constexpr int32 NorthernCrossroadsTrackSwitchState = 6468; // 1 (closed) or 2 (open)

        static constexpr int32 AllianceTeamScore = 6437;
        static constexpr int32 HordeTeamScore = 6438;

        static constexpr int32 HordeControlsSouthCart = 6882;
        static constexpr int32 AllianceControlsSouthCart = 6881;

        static constexpr int32 HordeControlsNorthCart = 6879;
        static constexpr int32 AllianceControlsNorthCart = 6880;

        static constexpr int32 HordeControlsEastCart = 6440;
        static constexpr int32 AllianceControlsEastCart = 6439;

        static constexpr std::array<int32, 3> AllianceControlWorldStates = { AllianceControlsSouthCart, AllianceControlsNorthCart, AllianceControlsEastCart };
        static constexpr std::array<int32, 3> HordeControlWorldStates = { HordeControlsSouthCart, HordeControlsNorthCart, HordeControlsEastCart };

        // My Diamonds and Your Rust
        // Win a Silvershard Mines battle without letting the enemy team capture a mine cart
        // WSE: 12385, "(WorldState(6954) + WorldState(6955)) == 1")
        // values might be swapped, they are not send to client
        static constexpr int32 AllianceCapturedMineCart = 6954;
        static constexpr int32 HordeCapturedMineCart = 6955;
    }

    enum class TrackSwitchState : uint32
    {
        Closed = 1,
        Open
    };
}

struct battleground_silvershard_mines final : BattlegroundScript
{
    explicit battleground_silvershard_mines(BattlegroundMap* map) : BattlegroundScript(map) { }

    void OnInit() override
    {
        // setup spawning of cosmetic carts
        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            for (auto const& [pathId, spawnPosition] : SilvershardMines::SpawnPositions::CosmeticCartsSpawnPositions)
            {
                auto const& [entry, weight] = *Trinity::Containers::SelectRandomWeightedContainerElement(SilvershardMines::Creatures::CosmeticCarts, [](std::pair<uint32, double> const& pair)
                {
                    return pair.second;
                });

                if (Creature* creature = battlegroundMap->SummonCreature(entry, spawnPosition))
                    creature->GetMotionMaster()->MovePath(pathId, false);
            }

            context.Repeat();
        });
    }

    void OnUpdate(uint32 diff) override
    {
        BattlegroundScript::OnUpdate(diff);
        _scheduler.Update(diff);
    }

    void OnPrepareStage2() override
    {
        BattlegroundScript::OnPrepareStage2();
        SpawnSouthernMineCart();
        SpawnNorthernMineCart();
    }

    void OnStart() override
    {
        BattlegroundScript::OnStart();
        for (ObjectGuid door : _doors)
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(door))
            {
                gameObject->UseDoorOrButton();
                gameObject->DespawnOrUnsummon(3s);
            }
        }

        SpawnEasternMineCart();
        _scheduler.Schedule(2s, [&](TaskContext context)
        {
            uint32 const underAllianceControl = std::ranges::count_if(SilvershardMines::WorldStates::AllianceControlWorldStates, [&](int32 worldState)
            {
                return battlegroundMap->GetWorldStateValue(worldState) == 1;
            });

            uint32 const underHordeControl = std::ranges::count_if(SilvershardMines::WorldStates::HordeControlWorldStates, [&](int32 worldState)
            {
                return battlegroundMap->GetWorldStateValue(worldState) == 1;
            });

            uint32 const hordeScoreToAdd = std::min<uint32>(SilvershardMines::Score::Max - battleground->GetTeamScore(TEAM_HORDE), underHordeControl);
            uint32 const allianceScoreToAdd = std::min<uint32>(SilvershardMines::Score::Max - battleground->GetTeamScore(TEAM_ALLIANCE), underAllianceControl);

            battleground->AddPoint(HORDE, hordeScoreToAdd);
            battleground->AddPoint(ALLIANCE, allianceScoreToAdd);

            SendTeamScores();
            if (!CheckWinner())
                context.Repeat();
        });
    }

    void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker) override
    {
        BattlegroundScript::ProcessEvent(obj, eventId, invoker);

        switch (eventId)
        {
            case SilvershardMines::Events::ProgressEventHordeSouth:
            case SilvershardMines::Events::ProgressEventHordeEast:
            case SilvershardMines::Events::ProgressEventHordeNorth:
                HandleProgressEvent(WorldObject::ToGameObject(invoker), HORDE, CHAT_MSG_BG_SYSTEM_HORDE, SilvershardMines::BroadcastTexts::HordeControlsMineCart, SilvershardMines::Spells::ControlVisualHorde);
                break;
            case SilvershardMines::Events::ProgressEventAllianceSouth:
            case SilvershardMines::Events::ProgressEventAllianceEast:
            case SilvershardMines::Events::ProgressEventAllianceNorth:
                HandleProgressEvent(WorldObject::ToGameObject(invoker), ALLIANCE, CHAT_MSG_BG_SYSTEM_ALLIANCE, SilvershardMines::BroadcastTexts::AllianceControlsMineCart, SilvershardMines::Spells::ControlVisualAlliance);
                break;
            case SilvershardMines::Events::ProgressEventNeutralEast:
            case SilvershardMines::Events::ProgressEventNeutralSouth:
                HandleProgressEvent(WorldObject::ToGameObject(invoker), TEAM_OTHER);
                break;
            default:
                break;
        }
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        BattlegroundScript::DoAction(actionId, source, target);

        switch (actionId)
        {
            case SilvershardMines::Actions::MineCartCaptured:
                OnMineCartCaptured(Object::ToCreature(source));
                break;
            case SilvershardMines::Actions::TrackChanged:
                OnTrackSwitched(Object::ToPlayer(source), Object::ToCreature(target));
                break;
            case SilvershardMines::Actions::MineCartCapturedPlayer:
                OnPlayerCapturedMineCart(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameobject);

        switch (gameobject->GetEntry())
        {
            case SilvershardMines::GameObjects::Gate1:
            case SilvershardMines::GameObjects::Gate2:
            case SilvershardMines::GameObjects::Gate3:
            case SilvershardMines::GameObjects::Gate4:
                _doors.push_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        BattlegroundScript::OnCreatureCreate(creature);

        if (creature->GetEntry() == SilvershardMines::Creatures::MineCart && battleground->GetStatus() == STATUS_IN_PROGRESS)
            creature->AI()->Talk(SilvershardMines::CreatureTexts::MineCart::Spawned);
    }

    void HandleProgressEvent(GameObject const* controlZone, Team team, ChatMsg msgType = CHAT_MSG_ADDON, uint32 broadcastTextId = 0, uint32 visualSpellId = 0) const
    {
        if (!controlZone)
            return;

        Creature* mineCart = Object::ToCreature(controlZone->GetOwner());
        if (!mineCart)
            return;

        mineCart->RemoveAurasDueToSpell(SilvershardMines::Spells::ControlVisualNeutral);
        mineCart->RemoveAurasDueToSpell(SilvershardMines::Spells::ControlVisualHorde);
        mineCart->RemoveAurasDueToSpell(SilvershardMines::Spells::ControlVisualAlliance);
        mineCart->CastSpell(mineCart, visualSpellId, true);
        UpdateCartWorldStates(controlZone);

        if (team == TEAM_OTHER)
            return;

        battleground->SendBroadcastText(broadcastTextId, msgType, controlZone);
        mineCart->AI()->DoAction(SilvershardMines::Actions::MineCartControlChanged);

        for (ObjectGuid const& guid : *controlZone->GetInsidePlayers())
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                if (player->GetBGTeam() == team)
                    battleground->UpdatePvpStat(player, SilvershardMines::PvpStats::CartsCaptured, 1);
    }

    void SpawnSouthernMineCart() const
    {
        if (TempSummon* creature = battlegroundMap->SummonCreature(SilvershardMines::Creatures::MineCart, SilvershardMines::SpawnPositions::MineCartSouth))
        {
            creature->GetMotionMaster()->MovePath(SilvershardMines::PathIds::South, false);
            creature->CastSpell(creature, SilvershardMines::Spells::CartControlCapturePointUnitSouth, true);
        }
    }

    void SpawnEasternMineCart() const
    {
        if (TempSummon* creature = battlegroundMap->SummonCreature(SilvershardMines::Creatures::MineCart, SilvershardMines::SpawnPositions::MineCartEast))
        {
            creature->GetMotionMaster()->MovePath(SilvershardMines::PathIds::East, false);
            creature->CastSpell(creature, SilvershardMines::Spells::CartControlCapturePointUnitEast, true);
        }
    }

    void SpawnNorthernMineCart() const
    {
        if (TempSummon* creature = battlegroundMap->SummonCreature(SilvershardMines::Creatures::MineCart, SilvershardMines::SpawnPositions::MineCartNorth))
        {
            creature->GetMotionMaster()->MovePath(SilvershardMines::PathIds::North, false);
            creature->CastSpell(creature, SilvershardMines::Spells::CartControlCapturePointUnitNorth, true);
        }
    }

    void UpdateCartWorldStates(GameObject const* controlZone) const
    {
        if (!controlZone)
            return;

        TeamId const controllingTeam = controlZone->GetControllingTeam();
        Creature const* creature = Object::ToCreature(controlZone->GetOwner());

        if (creature->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitEast))
        {
            UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsEastCart, controllingTeam == TEAM_ALLIANCE);
            UpdateWorldState(SilvershardMines::WorldStates::HordeControlsEastCart, controllingTeam == TEAM_HORDE);
        }
        else if (creature->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitNorth))
        {
            UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsNorthCart, controllingTeam == TEAM_ALLIANCE);
            UpdateWorldState(SilvershardMines::WorldStates::HordeControlsNorthCart, controllingTeam == TEAM_HORDE);
        }
        else if (creature->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitSouth))
        {
            UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsSouthCart, controllingTeam == TEAM_ALLIANCE);
            UpdateWorldState(SilvershardMines::WorldStates::HordeControlsSouthCart, controllingTeam == TEAM_HORDE);
        }
    }

    void SendTeamScores() const
    {
        UpdateWorldState(SilvershardMines::WorldStates::HordeTeamScore, battleground->GetTeamScore(TEAM_HORDE));
        UpdateWorldState(SilvershardMines::WorldStates::AllianceTeamScore, battleground->GetTeamScore(TEAM_ALLIANCE));
    }

    void OnMineCartCaptured(Creature const* mineCart)
    {
        if (!mineCart)
            return;

        GameObject* controlZone = nullptr;
        if (mineCart->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitEast))
        {
            controlZone = mineCart->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitEast);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsEastCart, 0);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::HordeControlsEastCart, 0);

            _scheduler.Schedule(5s, [&](TaskContext const&)
            {
                SpawnEasternMineCart();
            });
        }
        else if (mineCart->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitNorth))
        {
            controlZone = mineCart->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitNorth);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsNorthCart, 0);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::HordeControlsNorthCart, 0);

            _scheduler.Schedule(5s, [&](TaskContext const&)
            {
                SpawnNorthernMineCart();
            });
        }
        else if (mineCart->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitSouth))
        {
            controlZone = mineCart->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitSouth);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::AllianceControlsSouthCart, 0);
            battleground->UpdateWorldState(SilvershardMines::WorldStates::HordeControlsSouthCart, 0);

            _scheduler.Schedule(5s, [&](TaskContext const&)
            {
                SpawnSouthernMineCart();
            });
        }

        if (!controlZone || controlZone->GetControllingTeam() == TEAM_NEUTRAL)
            return;

        uint32 const scoreToAdd = std::min<uint32>(SilvershardMines::Score::Max - battleground->GetTeamScore(controlZone->GetControllingTeam()), SilvershardMines::Score::Capture);
        if (controlZone->GetControllingTeam() == TEAM_HORDE)
        {
            mineCart->AI()->Talk(SilvershardMines::CreatureTexts::MineCart::CapturedByHorde);
            if (battleground->GetStatus() != STATUS_WAIT_LEAVE)
            {
                battleground->AddPoint(HORDE, scoreToAdd);
                UpdateWorldState(SilvershardMines::WorldStates::HordeCapturedMineCart, 1, true);
                CheckWinner();
            }
        }
        else if (controlZone->GetControllingTeam() == TEAM_ALLIANCE)
        {
            mineCart->AI()->Talk(SilvershardMines::CreatureTexts::MineCart::CapturedByAlliance);
            if (battleground->GetStatus() != STATUS_WAIT_LEAVE)
            {
                battleground->AddPoint(ALLIANCE, scoreToAdd);
                UpdateWorldState(SilvershardMines::WorldStates::AllianceCapturedMineCart, 1, true);
                CheckWinner();
            }
        }
    }

    void OnPlayerCapturedMineCart(Player* player)
    {
        if (!player)
            return;

        if (_capturedMineCartsByPlayer.contains(player->GetGUID()))
            _capturedMineCartsByPlayer[player->GetGUID()] = _capturedMineCartsByPlayer[player->GetGUID()] + 1;
        else
            _capturedMineCartsByPlayer[player->GetGUID()] = 1;

        BattlegroundScore const* score = battleground->GetBattlegroundScore(player);
        if (!score)
            return;

        if (score->GetDeaths() && _capturedMineCartsByPlayer[player->GetGUID()] >= 5)
            player->CastSpell(player, SilvershardMines::Spells::ThreeForThreeComplete, true);
    }

    void OnTrackSwitched(Player const* invoker, Creature* trackSwitch) const
    {
        if (!invoker || !trackSwitch)
            return;

        int32 worldStateId = 0;
        int32 broadcastTextId = 0;
        if (trackSwitch->HasStringId(SilvershardMines::StringIds::TrackSwitchEast))
        {
            worldStateId = SilvershardMines::WorldStates::EasternCrossroadsTrackSwitchState;
            broadcastTextId = SilvershardMines::BroadcastTexts::EasternCrossroadsChangedTracks;
        }
        else if (trackSwitch->HasStringId(SilvershardMines::StringIds::TrackSwitchNorth))
        {
            worldStateId = SilvershardMines::WorldStates::NorthernCrossroadsTrackSwitchState;
            broadcastTextId = SilvershardMines::BroadcastTexts::NorthernCrossroadsChangedTracks;
        }

        if (!worldStateId)
            return;

        uint32 const currentState = trackSwitch->GetMap()->GetWorldStateValue(worldStateId);
        if (currentState == AsUnderlyingType(SilvershardMines::TrackSwitchState::Closed))
        {
            trackSwitch->GetMap()->SetWorldStateValue(worldStateId, AsUnderlyingType(SilvershardMines::TrackSwitchState::Open), false);
            trackSwitch->RemoveAurasDueToSpell(SilvershardMines::Spells::TrackSwitchVisualClosed);
            trackSwitch->CastSpell(trackSwitch, SilvershardMines::Spells::TrackSwitchVisualOpened, true);
        }
        else if (currentState == AsUnderlyingType(SilvershardMines::TrackSwitchState::Open))
        {
            trackSwitch->GetMap()->SetWorldStateValue(worldStateId, AsUnderlyingType(SilvershardMines::TrackSwitchState::Closed), false);
            trackSwitch->RemoveAurasDueToSpell(SilvershardMines::Spells::TrackSwitchVisualOpened);
            trackSwitch->CastSpell(trackSwitch, SilvershardMines::Spells::TrackSwitchVisualClosed, true);
        }

        if (broadcastTextId)
            battleground->SendBroadcastText(broadcastTextId, CHAT_MSG_BG_SYSTEM_NEUTRAL, invoker);
    }

    bool CheckWinner() const
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return true;

        uint32 const hordeScore = battleground->GetTeamScore(TEAM_HORDE);
        uint32 const allianceScore = battleground->GetTeamScore(TEAM_ALLIANCE);
        if (hordeScore >= SilvershardMines::Score::Max || allianceScore >= SilvershardMines::Score::Max)
        {
            SendTeamScores();

            if (hordeScore >= SilvershardMines::Score::Max && allianceScore >= SilvershardMines::Score::Max)
            {
                battleground->EndBattleground(TEAM_OTHER);
                return true;
            }

            if (hordeScore >= SilvershardMines::Score::Max)
            {
                battleground->EndBattleground(HORDE);
                return true;
            }

            if (allianceScore >= SilvershardMines::Score::Max)
            {
                battleground->EndBattleground(ALLIANCE);
                return true;
            }
        }

        return false;
    }
private:
    TaskScheduler _scheduler;
    GuidVector _doors;
    std::unordered_map<ObjectGuid, uint16> _capturedMineCartsByPlayer;
};

// 60140 - Mine Cart
class npc_bg_silvershard_mines_mine_cart final : public ScriptedAI
{
public:
    explicit npc_bg_silvershard_mines_mine_cart(Creature* creature) : ScriptedAI(creature), _endOfTheLineTeam(TEAM_NEUTRAL), _theLongRidersSpawnTime(GameTime::GetGameTime()) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void JustAppeared() override
    {
        DoCastSelf(SilvershardMines::Spells::ControlVisualNeutral, true);
        DoCastSelf(SilvershardMines::Spells::DefendingCartAura, true);

        // give a bit of grace time for The Long Rider achievement (guessed behaviour)
        _scheduler.Schedule(2s, [&](TaskContext context)
        {
            _theLongRidersSpawnTime = GameTime::GetGameTime();

            // initialize the long riders eligible players
            DoForPlayersInControlZone([&](GameObject const* controlZone, Player const* player)
            {
                if (controlZone->GetControllingTeam() == GetTeamIdForTeam(player->GetBGTeam()))
                    _theLongRidersPlayers.insert(player->GetGUID());
            });

            // each second, check if eligible players are still inside
            context.Schedule(1s, [&](TaskContext context2)
            {
                if (GameObject const* controlZone = GetControlZone())
                {
                    GuidUnorderedSet currentPlayers = *controlZone->GetInsidePlayers();
                    GuidSet theLongRidersPlayers;
                    std::ranges::set_intersection(_theLongRidersPlayers, currentPlayers, std::inserter(theLongRidersPlayers, theLongRidersPlayers.begin()));
                    _theLongRidersPlayers = std::move(theLongRidersPlayers);
                }

                context2.Repeat();
            });
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case SilvershardMines::PathIds::South:
                me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::SouthEnd, false);
                break;
            case SilvershardMines::PathIds::North:
                if (me->GetMap()->GetWorldStateValue(SilvershardMines::WorldStates::NorthernCrossroadsTrackSwitchState) == 1)
                    me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::NorthWest, false);
                else if (me->GetMap()->GetWorldStateValue(SilvershardMines::WorldStates::NorthernCrossroadsTrackSwitchState) == 2)
                    me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::NorthEast, false);
                break;
            case SilvershardMines::PathIds::NorthEast:
                me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::NorthEastEnd, false);
                break;
            case SilvershardMines::PathIds::NorthWest:
                me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::NorthWestEnd, false);
                break;
            case SilvershardMines::PathIds::East:
                if (me->GetMap()->GetWorldStateValue(SilvershardMines::WorldStates::EasternCrossroadsTrackSwitchState) == 1)
                    me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::EastNorth, false);
                else if (me->GetMap()->GetWorldStateValue(SilvershardMines::WorldStates::EasternCrossroadsTrackSwitchState) == 2)
                    me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::EastSouth, false);
                break;
            case SilvershardMines::PathIds::EastSouth:
                me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::EastSouthEnd, false);
                break;
            case SilvershardMines::PathIds::EastNorth:
                me->GetMotionMaster()->MovePath(SilvershardMines::PathIds::EastNorthEnd, false);
                break;
            case SilvershardMines::PathIds::SouthEnd:
            case SilvershardMines::PathIds::NorthEastEnd:
            case SilvershardMines::PathIds::EastSouthEnd:
            case SilvershardMines::PathIds::EastNorthEnd:
            case SilvershardMines::PathIds::NorthWestEnd:
                HandleCapture(pathId);
                break;
            default:
                break;
        }
    }

    void DoForPlayersInControlZone(std::function<void(GameObject const*, Player*)> const& fn) const
    {
        if (GameObject const* controlZone = GetControlZone())
            for (ObjectGuid const& playerGuid : *controlZone->GetInsidePlayers())
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    fn(controlZone, player);
    }

    void HandleCapture(uint32 pathId) const
    {
        if (uint32 const mineCartCourierSpell = GetMineCartCourierSpell(pathId))
        {
            DoForPlayersInControlZone([&](GameObject const* controlZone, Player* player)
            {
                if (GetTeamIdForTeam(player->GetBGTeam()) == controlZone->GetControllingTeam())
                {
                    player->CastSpell(player, mineCartCourierSpell, true);
                    if (controlZone->GetControllingTeam() == _endOfTheLineTeam)
                        player->CastSpell(player, SilvershardMines::Spells::EndOfTheLineAchievementCheck, true);
                }
            });
        }

        if (_endOfTheLineTeam != TEAM_NEUTRAL)
        {
            DoForPlayersInControlZone([&](GameObject const* controlZone, Player* player)
            {
                if (GetTeamIdForTeam(player->GetBGTeam()) == controlZone->GetControllingTeam() && controlZone->GetControllingTeam() == _endOfTheLineTeam)
                    player->CastSpell(player, SilvershardMines::Spells::EndOfTheLineAchievementCheck, true);
            });
        }

        if (uint32 const longRiderSpell = GetTheLongRiderAchievementSpell(pathId))
        {
            time_t controlAuraApplyTime = GameTime::GetGameTime();

            if (Aura const* aura = me->GetAura(SilvershardMines::Spells::ControlVisualHorde))
                controlAuraApplyTime = aura->GetApplyTime();
            else if (Aura const* aura = me->GetAura(SilvershardMines::Spells::ControlVisualAlliance))
                controlAuraApplyTime = aura->GetApplyTime();

            if (controlAuraApplyTime <= _theLongRidersSpawnTime)
                for (ObjectGuid const& playerGuid : _theLongRidersPlayers)
                    if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                        player->CastSpell(player, longRiderSpell, true);
        }

        DoForPlayersInControlZone([&](GameObject const* controlZone, Player* player)
        {
            if (GetTeamIdForTeam(player->GetBGTeam()) != controlZone->GetControllingTeam())
                return;

            if (ZoneScript* zs = me->GetZoneScript())
                zs->DoAction(SilvershardMines::Actions::MineCartCapturedPlayer, me, player);
        });

        me->CastSpell(me, SilvershardMines::Spells::CartCap, true);
    }

    static uint32 GetMineCartCourierSpell(uint32 pathId)
    {
        switch (pathId)
        {
            case SilvershardMines::PathIds::SouthEnd:
                return SilvershardMines::Spells::MineCartCourierSouth;
            case SilvershardMines::PathIds::NorthEastEnd:
                return SilvershardMines::Spells::MineCartCourierNorthEast;
            case SilvershardMines::PathIds::EastSouthEnd:
                return SilvershardMines::Spells::MineCartCourierEastSouth;
            case SilvershardMines::PathIds::EastNorthEnd:
                return SilvershardMines::Spells::MineCartCourierEastNorth;
            case SilvershardMines::PathIds::NorthWestEnd:
                return SilvershardMines::Spells::MineCartCourierNorthWest;
            default:
                return 0;
        }
    }

    uint32 GetTheLongRiderAchievementSpell(uint32 pathId) const
    {
        TeamId controllingTeam = TEAM_NEUTRAL;
        if (GameObject const* controlZone = GetControlZone())
            controllingTeam = controlZone->GetControllingTeam();

        if (controllingTeam == TEAM_NEUTRAL)
            return 0;

        switch (pathId)
        {
            case SilvershardMines::PathIds::SouthEnd:
                return controllingTeam == TEAM_ALLIANCE ? SilvershardMines::Spells::LongRiderAchievementSouthAlliance : SilvershardMines::Spells::LongRiderAchievementSouthHorde;
            case SilvershardMines::PathIds::EastSouthEnd:
            case SilvershardMines::PathIds::EastNorthEnd:
                return controllingTeam == TEAM_ALLIANCE ? SilvershardMines::Spells::LongRiderAchievementEastAlliance : SilvershardMines::Spells::LongRiderAchievementEastHorde;
            case SilvershardMines::PathIds::NorthWestEnd:
            case SilvershardMines::PathIds::NorthEastEnd:
                return controllingTeam == TEAM_ALLIANCE ? SilvershardMines::Spells::LongRiderAchievementNorthAlliance : SilvershardMines::Spells::LongRiderAchievementNorthHorde;
            default:
                return 0;
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId != SilvershardMines::Actions::MineCartControlChanged)
            return;

        if (me->FindNearestGameObjectWithOptions(20.0f, { .StringId = SilvershardMines::StringIds::MineDepot }))
            if (GameObject const* controlZone = GetControlZone())
                _endOfTheLineTeam = controlZone->GetControllingTeam();
    }

    GameObject* GetControlZone() const
    {
        if (me->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitEast))
            return me->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitEast);

        if (me->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitNorth))
            return me->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitNorth);

        if (me->HasAura(SilvershardMines::Spells::CartControlCapturePointUnitSouth))
            return me->GetGameObject(SilvershardMines::Spells::CartControlCapturePointUnitSouth);

        return nullptr;
    }

private:
    TaskScheduler _scheduler;
    TeamId _endOfTheLineTeam;
    GuidSet _theLongRidersPlayers;
    time_t _theLongRidersSpawnTime;
};

// 115904 - Cart Cap
class spell_bg_silvershard_mines_cart_cap final : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        Creature* hitCreature = GetHitCreature();
        if (!hitCreature)
            return;

        if (ZoneScript* zoneScript = hitCreature->GetZoneScript())
            zoneScript->DoAction(SilvershardMines::Actions::MineCartCaptured, hitCreature, hitCreature);

        if (GameObject* depot = hitCreature->FindNearestGameObjectWithOptions(15.0f, { .StringId = SilvershardMines::StringIds::MineDepot }))
            depot->ActivateObject(GameObjectActions::Open, 0, hitCreature);

        hitCreature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_silvershard_mines_cart_cap::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 124491 - capturing
class spell_bg_silvershard_mines_capturing final : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SilvershardMines::Spells::Capturing });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        if (Player* player = GetHitPlayer())
            player->CastSpell(player, SilvershardMines::Spells::Capturing);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_silvershard_mines_capturing::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 97372 - Capturing
class spell_bg_silvershard_mines_capturing_switch_track final : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SilvershardMines::Spells::TrackSwitchVisualClosed, SilvershardMines::Spells::TrackSwitchVisualOpened });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        Creature* hitCreature = GetHitCreature();
        if (!hitCreature)
            return;

        if (ZoneScript* zoneScript = hitCreature->GetZoneScript())
            zoneScript->DoAction(SilvershardMines::Actions::TrackChanged, GetCaster(), hitCreature);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_silvershard_mines_capturing_switch_track::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 60379, 60378, 60380 - Mine Cart
class npc_bg_silvershard_mines_mine_cart_cosmetic final : public ScriptedAI
{
public:
    explicit npc_bg_silvershard_mines_mine_cart_cosmetic(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case SilvershardMines::PathIds::CosmeticCart1:
            case SilvershardMines::PathIds::CosmeticCart2:
            case SilvershardMines::PathIds::CosmeticCart3:
                me->DespawnOrUnsummon(500ms);
                break;
            default:
                break;
        }
    }
};

void AddSC_battleground_silvershard_mines()
{
    RegisterBattlegroundMapScript(battleground_silvershard_mines, SilvershardMines::Maps::BattlegroundMap);

    RegisterSpellScript(spell_bg_silvershard_mines_cart_cap);
    RegisterSpellScript(spell_bg_silvershard_mines_capturing);
    RegisterSpellScript(spell_bg_silvershard_mines_capturing_switch_track);
    RegisterCreatureAI(npc_bg_silvershard_mines_mine_cart);
    RegisterCreatureAI(npc_bg_silvershard_mines_mine_cart_cosmetic);
}

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

#include "AreaTrigger.h"
#include "BattlegroundScript.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Timer.h"

enum EyeOfTheStormWorldStates
{
    EY_ALLIANCE_RESOURCES                   = 1776,
    EY_HORDE_RESOURCES                      = 1777,
    EY_MAX_RESOURCES                        = 1780,
    EY_ALLIANCE_BASE                        = 2752,
    EY_HORDE_BASE                           = 2753,
    DRAENEI_RUINS_HORDE_CONTROL             = 2733,
    DRAENEI_RUINS_ALLIANCE_CONTROL          = 2732,
    DRAENEI_RUINS_UNCONTROL                 = 2731,
    MAGE_TOWER_ALLIANCE_CONTROL             = 2730,
    MAGE_TOWER_HORDE_CONTROL                = 2729,
    MAGE_TOWER_UNCONTROL                    = 2728,
    FEL_REAVER_HORDE_CONTROL                = 2727,
    FEL_REAVER_ALLIANCE_CONTROL             = 2726,
    FEL_REAVER_UNCONTROL                    = 2725,
    BLOOD_ELF_HORDE_CONTROL                 = 2724,
    BLOOD_ELF_ALLIANCE_CONTROL              = 2723,
    BLOOD_ELF_UNCONTROL                     = 2722,
    PROGRESS_BAR_PERCENT_GREY               = 2720,                 //100 = empty (only grey), 0 = blue|red (no grey)
    PROGRESS_BAR_STATUS                     = 2719,                 //50 init!, 48 ... hordak bere .. 33 .. 0 = full 100% hordacky, 100 = full alliance
    PROGRESS_BAR_SHOW                       = 2718,                 //1 init, 0 druhy send - bez messagu, 1 = controlled aliance
    NETHERSTORM_FLAG                        = 8863,
    //set to 2 when flag is picked up, and to 1 if it is dropped
    NETHERSTORM_FLAG_STATE_ALLIANCE         = 9808,
    NETHERSTORM_FLAG_STATE_HORDE            = 9809,

    DRAENEI_RUINS_HORDE_CONTROL_STATE       = 17362,
    DRAENEI_RUINS_ALLIANCE_CONTROL_STATE    = 17366,
    MAGE_TOWER_HORDE_CONTROL_STATE          = 17361,
    MAGE_TOWER_ALLIANCE_CONTROL_STATE       = 17368,
    FEL_REAVER_HORDE_CONTROL_STATE          = 17364,
    FEL_REAVER_ALLIANCE_CONTROL_STATE       = 17367,
    BLOOD_ELF_HORDE_CONTROL_STATE           = 17363,
    BLOOD_ELF_ALLIANCE_CONTROL_STATE        = 17365,
};

enum EyeOfTheStormSounds
{
    //strange ids, but sure about them
    BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE     = 8212,
    BG_EY_SOUND_FLAG_CAPTURED_HORDE         = 8213,
    BG_EY_SOUND_FLAG_PICKED_UP_HORDE        = 8174,
    BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE      = 8173,
    BG_EY_SOUND_FLAG_RESET                  = 8192
};

enum EyeOfTheStormSpells
{
    BG_EY_NETHERSTORM_FLAG_SPELL            = 34976,
    BG_EY_PLAYER_DROPPED_FLAG_SPELL         = 34991,

    // Focused/Brutal Assault
    BG_EY_FOCUSED_ASSAULT_SPELL             = 46392,
    BG_EY_BRUTAL_ASSAULT_SPELL              = 46393
};

enum EyeOfTheStormObjectEntry
{
    BG_OBJECT_A_DOOR_EY_ENTRY               = 184719,           //Alliance door
    BG_OBJECT_H_DOOR_EY_ENTRY               = 184720,           //Horde door
    BG_OBJECT_FLAG2_EY_ENTRY                = 208977,           //Netherstorm flag (flagstand)
    BG_OBJECT_BE_TOWER_CAP_EY_ENTRY         = 184080,           //BE Tower Cap Pt
    BG_OBJECT_FR_TOWER_CAP_EY_ENTRY         = 184081,           //Fel Reaver Cap Pt
    BG_OBJECT_HU_TOWER_CAP_EY_ENTRY         = 184082,           //Human Tower Cap Pt
    BG_OBJECT_DR_TOWER_CAP_EY_ENTRY         = 184083,           //Draenei Tower Cap Pt
};

enum EyeOfTheStormPointsTrigger
{
    AREATRIGGER_CAPTURE_FLAG                = 33
};

enum EyeOfTheStormPoints
{
    FEL_REAVER                              = 0,
    BLOOD_ELF                               = 1,
    DRAENEI_RUINS                           = 2,
    MAGE_TOWER                              = 3,

    EY_PLAYERS_OUT_OF_POINTS                = 4,
    EY_POINTS_MAX                           = 4
};

constexpr uint32 BG_EY_NotEYWeekendHonorTicks = 260;
constexpr uint32 BG_EY_EYWeekendHonorTicks = 160;

enum BG_EY_Score
{
    BG_EY_WARNING_NEAR_VICTORY_SCORE        = 1200,
    BG_EY_MAX_TEAM_SCORE                    = 1500
};

enum BG_EY_FlagState
{
    BG_EY_FLAG_STATE_ON_BASE                = 0,
    BG_EY_FLAG_STATE_WAIT_RESPAWN           = 1,
    BG_EY_FLAG_STATE_ON_PLAYER              = 2,
    BG_EY_FLAG_STATE_ON_GROUND              = 3
};

enum EYBattlegroundPointState
{
    EY_POINT_NO_OWNER                       = 0,
    EY_POINT_STATE_UNCONTROLLED             = 0,
    EY_POINT_UNDER_CONTROL                  = 3
};

enum BG_EY_ExploitTeleportLocations
{
    EY_EXPLOIT_TELEPORT_LOCATION_ALLIANCE   = 3773,
    EY_EXPLOIT_TELEPORT_LOCATION_HORDE      = 3772
};

enum EyeOFtheStormBroadcastTexts
{
    BG_EY_TEXT_ALLIANCE_TAKEN_FEL_REAVER_RUINS  = 17828,
    BG_EY_TEXT_HORDE_TAKEN_FEL_REAVER_RUINS     = 17829,
    BG_EY_TEXT_ALLIANCE_LOST_FEL_REAVER_RUINS   = 91961,
    BG_EY_TEXT_HORDE_LOST_FEL_REAVER_RUINS      = 91962,

    BG_EY_TEXT_ALLIANCE_TAKEN_BLOOD_ELF_TOWER   = 17819,
    BG_EY_TEXT_HORDE_TAKEN_BLOOD_ELF_TOWER      = 17823,
    BG_EY_TEXT_ALLIANCE_LOST_BLOOD_ELF_TOWER    = 91957,
    BG_EY_TEXT_HORDE_LOST_BLOOD_ELF_TOWER       = 91958,

    BG_EY_TEXT_ALLIANCE_TAKEN_DRAENEI_RUINS     = 17827,
    BG_EY_TEXT_HORDE_TAKEN_DRAENEI_RUINS        = 91917,
    BG_EY_TEXT_ALLIANCE_LOST_DRAENEI_RUINS      = 91959,
    BG_EY_TEXT_HORDE_LOST_DRAENEI_RUINS         = 91960,

    BG_EY_TEXT_ALLIANCE_TAKEN_MAGE_TOWER        = 17824,
    BG_EY_TEXT_HORDE_TAKEN_MAGE_TOWER           = 17825,
    BG_EY_TEXT_ALLIANCE_LOST_MAGE_TOWER         = 91963,
    BG_EY_TEXT_HORDE_LOST_MAGE_TOWER            = 91964,

    BG_EY_TEXT_TAKEN_FLAG                       = 18359,
    BG_EY_TEXT_FLAG_DROPPED                     = 18361,
    BG_EY_TEXT_FLAG_RESET                       = 18364,
    BG_EY_TEXT_ALLIANCE_CAPTURED_FLAG           = 18375,
    BG_EY_TEXT_HORDE_CAPTURED_FLAG              = 18384,
};

struct BattlegroundEYPointIconsStruct
{
    BattlegroundEYPointIconsStruct(uint32 _WorldStateControlIndex, uint32 _WorldStateAllianceControlledIndex, uint32 _WorldStateHordeControlledIndex,
        uint32 worldStateAllianceStatusBarIcon, uint32 worldStateHordeStatusBarIcon)
        : WorldStateControlIndex(_WorldStateControlIndex), WorldStateAllianceControlledIndex(_WorldStateAllianceControlledIndex), WorldStateHordeControlledIndex(_WorldStateHordeControlledIndex),
        WorldStateAllianceStatusBarIcon(worldStateAllianceStatusBarIcon), WorldStateHordeStatusBarIcon(worldStateHordeStatusBarIcon) { }
    uint32 WorldStateControlIndex;
    uint32 WorldStateAllianceControlledIndex;
    uint32 WorldStateHordeControlledIndex;
    uint32 WorldStateAllianceStatusBarIcon;
    uint32 WorldStateHordeStatusBarIcon;
};

struct BattlegroundEYLosingPointStruct
{
    BattlegroundEYLosingPointStruct(uint32 _MessageIdAlliance, uint32 _MessageIdHorde)
        : MessageIdAlliance(_MessageIdAlliance), MessageIdHorde(_MessageIdHorde)
    { }

    uint32 MessageIdAlliance;
    uint32 MessageIdHorde;
};

struct BattlegroundEYCapturingPointStruct
{
    BattlegroundEYCapturingPointStruct(uint32 _MessageIdAlliance, uint32 _MessageIdHorde)
        : MessageIdAlliance(_MessageIdAlliance), MessageIdHorde(_MessageIdHorde)
    { }

    uint32 MessageIdAlliance;
    uint32 MessageIdHorde;
};

class BattlegroundEYControlZoneHandler : public ControlZoneHandler
{
public:
    explicit BattlegroundEYControlZoneHandler(uint32 point) :  _point(point) { }

    uint32 GetPoint() const { return _point; }

private:
    uint32 _point;
};

const std::array<BattlegroundEYPointIconsStruct, EY_POINTS_MAX> m_PointsIconStruct =
{
    BattlegroundEYPointIconsStruct(FEL_REAVER_UNCONTROL, FEL_REAVER_ALLIANCE_CONTROL, FEL_REAVER_HORDE_CONTROL, FEL_REAVER_ALLIANCE_CONTROL_STATE, FEL_REAVER_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(BLOOD_ELF_UNCONTROL, BLOOD_ELF_ALLIANCE_CONTROL, BLOOD_ELF_HORDE_CONTROL, BLOOD_ELF_ALLIANCE_CONTROL_STATE, BLOOD_ELF_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(DRAENEI_RUINS_UNCONTROL, DRAENEI_RUINS_ALLIANCE_CONTROL, DRAENEI_RUINS_HORDE_CONTROL, DRAENEI_RUINS_ALLIANCE_CONTROL_STATE, DRAENEI_RUINS_HORDE_CONTROL_STATE),
    BattlegroundEYPointIconsStruct(MAGE_TOWER_UNCONTROL, MAGE_TOWER_ALLIANCE_CONTROL, MAGE_TOWER_HORDE_CONTROL, MAGE_TOWER_ALLIANCE_CONTROL_STATE, MAGE_TOWER_HORDE_CONTROL_STATE)
};

const std::array<BattlegroundEYLosingPointStruct, EY_POINTS_MAX> m_LosingPointTypes =
{
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_FEL_REAVER_RUINS, BG_EY_TEXT_HORDE_LOST_FEL_REAVER_RUINS),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_BLOOD_ELF_TOWER, BG_EY_TEXT_HORDE_LOST_BLOOD_ELF_TOWER),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_DRAENEI_RUINS, BG_EY_TEXT_HORDE_LOST_DRAENEI_RUINS),
    BattlegroundEYLosingPointStruct(BG_EY_TEXT_ALLIANCE_LOST_MAGE_TOWER, BG_EY_TEXT_HORDE_LOST_MAGE_TOWER)
};

const std::array<BattlegroundEYCapturingPointStruct, EY_POINTS_MAX> m_CapturingPointTypes =
{
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_FEL_REAVER_RUINS, BG_EY_TEXT_HORDE_TAKEN_FEL_REAVER_RUINS),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_BLOOD_ELF_TOWER, BG_EY_TEXT_HORDE_TAKEN_BLOOD_ELF_TOWER),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_DRAENEI_RUINS, BG_EY_TEXT_HORDE_TAKEN_DRAENEI_RUINS),
    BattlegroundEYCapturingPointStruct(BG_EY_TEXT_ALLIANCE_TAKEN_MAGE_TOWER, BG_EY_TEXT_HORDE_TAKEN_MAGE_TOWER)
};

struct battleground_eye_of_the_storm : BattlegroundScript
{
    enum PvpStats
    {
        PVP_STAT_FLAG_CAPTURES = 183
    };

    static constexpr Seconds POINTS_TICK_TIME = 2s;
    static constexpr Seconds BG_EY_FLAG_ASSAULT_TIMER = 30s;
    static constexpr uint16 BG_EY_FLAG_BRUTAL_ASSAULT_STACK_COUNT = 5;
    static constexpr uint32 BG_EY_EVENT_START_BATTLE = 13180;

    static constexpr std::array<uint8, EY_POINTS_MAX> BG_EY_TickPoints = { 1, 2, 5, 10 };
    static constexpr std::array<uint32, EY_POINTS_MAX> BG_EY_FlagPoints = { 75, 85, 100, 500 };

    explicit battleground_eye_of_the_storm(BattlegroundMap* map) : BattlegroundScript(map)
    {
        _honorScoreTics = { 0, 0 };
        _honorTics = 0;
        _pointsTimer.Reset(POINTS_TICK_TIME);
        _assaultEnabled = false;
        _assaultStackCount = 0;
        _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);

        _controlZoneHandlers[BG_OBJECT_FR_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(FEL_REAVER);
        _controlZoneHandlers[BG_OBJECT_BE_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(BLOOD_ELF);
        _controlZoneHandlers[BG_OBJECT_DR_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(DRAENEI_RUINS);
        _controlZoneHandlers[BG_OBJECT_HU_TOWER_CAP_EY_ENTRY] = std::make_unique<BattlegroundEYControlZoneHandler>(MAGE_TOWER);

        bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(battleground->GetTypeID());
        _honorTics = (isBGWeekend) ? BG_EY_EYWeekendHonorTicks : BG_EY_NotEYWeekendHonorTicks;
    }

    void OnInit() override
    {
        UpdateWorldState(EY_MAX_RESOURCES, BG_EY_MAX_TEAM_SCORE);
    }

    void OnUpdate(uint32 diff) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        _pointsTimer.Update(diff);
        if (_pointsTimer.Passed())
        {
            _pointsTimer.Reset(POINTS_TICK_TIME);

            uint8 baseCountAlliance = GetControlledBaseCount(TEAM_ALLIANCE);
            uint8 baseCountHorde = GetControlledBaseCount(TEAM_HORDE);
            if (baseCountAlliance > 0)
                AddPoint(ALLIANCE, BG_EY_TickPoints[baseCountAlliance - 1]);
            if (baseCountHorde > 0)
                AddPoint(HORDE, BG_EY_TickPoints[baseCountHorde - 1]);
        }

        if (_assaultEnabled)
        {
            _flagAssaultTimer.Update(diff);
            if (_flagAssaultTimer.Passed())
            {
                _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);
                if (_assaultStackCount < std::numeric_limits<uint8>::max())
                {
                    _assaultStackCount++;

                    // update assault debuff stacks
                    DoForFlagKeepers([&](Player* player) -> void
                    {
                        ApplyAssaultDebuffToPlayer(player);
                    });
                }
            }
        }
    }

    void OnStart() override
    {
        for (ObjectGuid const& door : _doorGUIDs)
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(door))
            {
                gameObject->UseDoorOrButton();
                gameObject->DespawnOrUnsummon(3s);
            }
        }

        // Achievement: Flurry
        TriggerGameEvent(BG_EY_EVENT_START_BATTLE);
    }

    void AddPoint(Team team, uint32 points)
    {
        battleground->AddPoint(team, points);
        TeamId const team_index = Battleground::GetTeamIndexByTeamId(team);
        _honorScoreTics[team_index] += points;
        if (_honorScoreTics[team_index] >= _honorTics)
        {
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), team);
            _honorScoreTics[team_index] -= _honorTics;
        }

        UpdateTeamScore(team_index);
    }

    uint8 GetControlledBaseCount(TeamId teamId) const
    {
        uint8 baseCount = 0;
        for (auto const& controlZoneHandler : _controlZoneHandlers)
        {
            uint32 point = controlZoneHandler.second->GetPoint();
            switch (teamId)
            {
                case TEAM_ALLIANCE:
                    if (battlegroundMap->GetWorldStateValue(m_PointsIconStruct[point].WorldStateAllianceControlledIndex) == 1)
                        baseCount++;
                    break;
                case TEAM_HORDE:
                    if (battlegroundMap->GetWorldStateValue(m_PointsIconStruct[point].WorldStateHordeControlledIndex) == 1)
                        baseCount++;
                    break;
                default:
                    break;
            }
        }
        return baseCount;
    }

    void DoForFlagKeepers(std::function<void(Player*)> const& action) const
    {
        if (GameObject const* flag = battlegroundMap->GetGameObject(_flagGUID))
            if (Player* carrier = ObjectAccessor::FindPlayer(flag->GetFlagCarrierGUID()))
                action(carrier);
    }

    void ResetAssaultDebuff()
    {
        _assaultEnabled = false;
        _assaultStackCount = 0;
        _flagAssaultTimer.Reset(BG_EY_FLAG_ASSAULT_TIMER);
        DoForFlagKeepers([&](Player* player) -> void
        {
            RemoveAssaultDebuffFromPlayer(player);
        });
    }

    void ApplyAssaultDebuffToPlayer(Player* player)
    {
        if (_assaultStackCount == 0)
            return;

        uint32 spellId = BG_EY_FOCUSED_ASSAULT_SPELL;
        if (_assaultStackCount >= BG_EY_FLAG_BRUTAL_ASSAULT_STACK_COUNT)
        {
            player->RemoveAurasDueToSpell(BG_EY_FOCUSED_ASSAULT_SPELL);
            spellId = BG_EY_BRUTAL_ASSAULT_SPELL;
        }

        Aura* aura = player->GetAura(spellId);
        if (!aura)
        {
            player->CastSpell(player, spellId, true);
            aura = player->GetAura(spellId);
        }

        if (aura)
            aura->SetStackAmount(_assaultStackCount);
    }

    void RemoveAssaultDebuffFromPlayer(Player* player)
    {
        player->RemoveAurasDueToSpell(BG_EY_FOCUSED_ASSAULT_SPELL);
        player->RemoveAurasDueToSpell(BG_EY_BRUTAL_ASSAULT_SPELL);
    }

    void UpdateTeamScore(TeamId Team) const
    {
        uint32 score = battleground->GetTeamScore(Team);

        if (score >= BG_EY_MAX_TEAM_SCORE)
        {
            score = BG_EY_MAX_TEAM_SCORE;
            if (Team == TEAM_ALLIANCE)
                battleground->EndBattleground(ALLIANCE);
            else
                battleground->EndBattleground(HORDE);
        }

        if (Team == TEAM_ALLIANCE)
            UpdateWorldState(EY_ALLIANCE_RESOURCES, score);
        else
            UpdateWorldState(EY_HORDE_RESOURCES, score);
    }

    void OnEnd(Team winner) override
    {
        BattlegroundScript::OnEnd(winner);
        // Win reward
        if (winner == ALLIANCE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), ALLIANCE);
        if (winner == HORDE)
            battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), HORDE);

        // Complete map reward
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), ALLIANCE);
        battleground->RewardHonorToTeam(battleground->GetBonusHonorFromKill(1), HORDE);
    }

    void UpdatePointsCount(TeamId teamId) const
    {
        if (teamId == TEAM_ALLIANCE)
            UpdateWorldState(EY_ALLIANCE_BASE, GetControlledBaseCount(TEAM_ALLIANCE));
        else
            UpdateWorldState(EY_HORDE_BASE, GetControlledBaseCount(TEAM_HORDE));
    }

    void OnGameObjectCreate(GameObject* gameObject) override
    {
        switch (gameObject->GetEntry())
        {
            case BG_OBJECT_A_DOOR_EY_ENTRY:
            case BG_OBJECT_H_DOOR_EY_ENTRY:
                _doorGUIDs.insert(gameObject->GetGUID());
                break;
            case BG_OBJECT_FLAG2_EY_ENTRY:
                _flagGUID = gameObject->GetGUID();
                break;
            default:
                break;
        }
    }

    bool CanCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        if (areaTrigger->GetEntry() != AREATRIGGER_CAPTURE_FLAG)
            return false;

        if (GameObject const* flag = battlegroundMap->GetGameObject(_flagGUID))
        {
            if (flag->GetFlagCarrierGUID() != player->GetGUID())
                return false;
        }

        if (GameObject const* controlzone = player->FindNearestGameObjectWithOptions(40.0f, { .StringId = "bg_eye_of_the_storm_control_zone" }))
        {
            uint32 const point = _controlZoneHandlers[controlzone->GetEntry()]->GetPoint();
            switch (battleground->GetPlayerTeam(player->GetGUID()))
            {
                case ALLIANCE:
                    return battlegroundMap->GetWorldStateValue(m_PointsIconStruct[point].WorldStateAllianceControlledIndex) == 1;
                case HORDE:
                    return battlegroundMap->GetWorldStateValue(m_PointsIconStruct[point].WorldStateHordeControlledIndex) == 1;
                default:
                    return false;
            }
        }

        return false;
    }

    void OnCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        if (areaTrigger->GetEntry() != AREATRIGGER_CAPTURE_FLAG)
            return;

        uint32 const baseCount = GetControlledBaseCount(Battleground::GetTeamIndexByTeamId(battleground->GetPlayerTeam(player->GetGUID())));

        if (GameObject const* gameObject = battlegroundMap->GetGameObject(_flagGUID))
            gameObject->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

        Team const team = Team(battleground->GetPlayerTeam(player->GetGUID()));
        if (team == ALLIANCE)
        {
            battleground->SendBroadcastText(BG_EY_TEXT_ALLIANCE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            battleground->PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE);
        }
        else
        {
            battleground->SendBroadcastText(BG_EY_TEXT_HORDE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
            battleground->PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_HORDE);
        }

        if (baseCount > 0)
            AddPoint(team, BG_EY_FlagPoints[baseCount - 1]);

        UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_BASE);
        UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_BASE);

        battleground->UpdatePvpStat(player, PVP_STAT_FLAG_CAPTURES, 1);

        ResetAssaultDebuff();
        player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
        player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
    }

    void OnFlagStateChange(GameObject* /*flagInBase*/, FlagState /*oldValue*/, FlagState newValue, Player* player) override
    {
        switch (newValue)
        {
            case FlagState::InBase:
                ResetAssaultDebuff();
                break;
            case FlagState::Dropped:
                player->CastSpell(player, SPELL_RECENTLY_DROPPED_NEUTRAL_FLAG, true);
                RemoveAssaultDebuffFromPlayer(player);

                UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_WAIT_RESPAWN);
                UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_WAIT_RESPAWN);

                if (battleground->GetPlayerTeam(player->GetGUID()) == ALLIANCE)
                    battleground->SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE);
                else
                    battleground->SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE);
                break;
            case FlagState::Taken:
                if (battleground->GetPlayerTeam(player->GetGUID()) == ALLIANCE)
                {
                    UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_PLAYER);
                    battleground->PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE);
                    battleground->SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                }
                else
                {
                    UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_PLAYER);
                    battleground->PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_HORDE);
                    battleground->SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
                }

                ApplyAssaultDebuffToPlayer(player);
                _assaultEnabled = true;

                player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
                break;
            case FlagState::Respawning:
                ResetAssaultDebuff();
                break;
            default:
                break;
        }

        UpdateWorldState(NETHERSTORM_FLAG, AsUnderlyingType(newValue));
    }

    void EventTeamLostPoint(TeamId teamId, uint32 point, GameObject* controlZone) const
    {
        if (teamId == TEAM_ALLIANCE)
        {
            battleground->SendBroadcastText(m_LosingPointTypes[point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, controlZone);
            UpdateWorldState(m_PointsIconStruct[point].WorldStateAllianceControlledIndex, 0);
        }
        else if (teamId == TEAM_HORDE)
        {
            battleground->SendBroadcastText(m_LosingPointTypes[point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, controlZone);
            UpdateWorldState(m_PointsIconStruct[point].WorldStateHordeControlledIndex, 0);
        }

        UpdateWorldState(m_PointsIconStruct[point].WorldStateControlIndex, 1);
        UpdatePointsCount(teamId);
    }

    void EventTeamCapturedPoint(TeamId teamId, uint32 point, GameObject* controlZone) const
    {
        if (teamId == TEAM_ALLIANCE)
        {
            battleground->SendBroadcastText(m_CapturingPointTypes[point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, controlZone);
            UpdateWorldState(m_PointsIconStruct[point].WorldStateAllianceControlledIndex, 1);
        }
        else if (teamId == TEAM_HORDE)
        {
            battleground->SendBroadcastText(m_CapturingPointTypes[point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, controlZone);
            UpdateWorldState(m_PointsIconStruct[point].WorldStateHordeControlledIndex, 1);
        }

        UpdateWorldState(m_PointsIconStruct[point].WorldStateControlIndex, 0);
        UpdatePointsCount(teamId);
    }

    Team GetPrematureWinner() override
    {
        if (battleground->GetTeamScore(TEAM_ALLIANCE) > battleground->GetTeamScore(TEAM_HORDE))
            return ALLIANCE;

        if (battleground->GetTeamScore(TEAM_HORDE) > battleground->GetTeamScore(TEAM_ALLIANCE))
            return HORDE;

        return BattlegroundScript::GetPrematureWinner();
    }

    void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker) override
    {
        BattlegroundScript::ProcessEvent(obj, eventId, invoker);

        if (invoker)
        {
            if (GameObject* gameobject = invoker->ToGameObject())
            {
                if (gameobject->GetGoType() == GAMEOBJECT_TYPE_CONTROL_ZONE)
                {
                    if (!_controlZoneHandlers.contains(gameobject->GetEntry()))
                        return;

                    auto controlzone = gameobject->GetGOInfo()->controlZone;
                    BattlegroundEYControlZoneHandler& handler = *_controlZoneHandlers[invoker->GetEntry()];
                    if (eventId == controlzone.NeutralEventAlliance)
                        EventTeamLostPoint(TEAM_ALLIANCE, handler.GetPoint(), gameobject);
                    else if (eventId == controlzone.NeutralEventHorde)
                        EventTeamLostPoint(TEAM_HORDE, handler.GetPoint(), gameobject);
                    else if (eventId == controlzone.ProgressEventAlliance)
                        EventTeamCapturedPoint(TEAM_ALLIANCE, handler.GetPoint(), gameobject);
                    else if (eventId == controlzone.ProgressEventHorde)
                        EventTeamCapturedPoint(TEAM_HORDE, handler.GetPoint(), gameobject);
                }
            }
        }
    }

private:
    std::array<uint32, PVP_TEAMS_COUNT> _honorScoreTics;

    TimeTracker _pointsTimer;
    uint32 _honorTics;

    std::unordered_map<uint32, std::unique_ptr<BattlegroundEYControlZoneHandler>> _controlZoneHandlers;
    GuidUnorderedSet _doorGUIDs;
    ObjectGuid _flagGUID;

    // Focused/Brutal Assault
    bool _assaultEnabled;
    TimeTracker _flagAssaultTimer;
    uint8 _assaultStackCount;
};

void AddSC_battleground_eye_of_the_storm()
{
    RegisterBattlegroundMapScript(battleground_eye_of_the_storm, 566);
}

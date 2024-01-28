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

#include "GameObject.h"
#include "ArtifactPackets.h"
#include "AzeritePackets.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "CellImpl.h"
#include "Containers.h"
#include "CreatureAISelector.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "G3DPosition.hpp"
#include "GameEventSender.h"
#include "GameObjectAI.h"
#include "GameObjectModel.h"
#include "GameObjectPackets.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Item.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "Map.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PhasingHandler.h"
#include "PoolMgr.h"
#include "QueryPackets.h"
#include "Util.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "World.h"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Quat.h>
#include <sstream>

void GameObjectTemplate::InitializeQueryData()
{
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc));
}

WorldPacket GameObjectTemplate::BuildQueryData(LocaleConstant loc) const
{
    WorldPackets::Query::QueryGameObjectResponse queryTemp;

    queryTemp.GameObjectID = entry;

    queryTemp.Allow = true;
    WorldPackets::Query::GameObjectStats& stats = queryTemp.Stats;

    stats.Type = type;
    stats.DisplayID = displayId;

    stats.Name[0] = name;
    stats.IconName = IconName;
    stats.CastBarCaption = castBarCaption;
    stats.UnkString = unk1;

    if (loc != LOCALE_enUS)
        if (GameObjectLocale const* gameObjectLocale = sObjectMgr->GetGameObjectLocale(entry))
        {
            ObjectMgr::GetLocaleString(gameObjectLocale->Name, loc, stats.Name[0]);
            ObjectMgr::GetLocaleString(gameObjectLocale->CastBarCaption, loc, stats.CastBarCaption);
            ObjectMgr::GetLocaleString(gameObjectLocale->Unk1, loc, stats.UnkString);
        }

    stats.Size = size;

    if (std::vector<uint32> const* items = sObjectMgr->GetGameObjectQuestItemList(entry))
        for (int32 item : *items)
            stats.QuestItems.push_back(item);

    memcpy(stats.Data.data(), raw.data, MAX_GAMEOBJECT_DATA * sizeof(int32));
    stats.ContentTuningId = ContentTuningId;

    queryTemp.Write();
    queryTemp.ShrinkToFit();
    return queryTemp.Move();
}

bool QuaternionData::isUnit() const
{
    return fabs(x * x + y * y + z * z + w * w - 1.0f) < 1e-5f;
}

void QuaternionData::toEulerAnglesZYX(float& Z, float& Y, float& X) const
{
    G3D::Matrix3(G3D::Quat(x, y, z, w)).toEulerAnglesZYX(Z, Y, X);
}

QuaternionData QuaternionData::fromEulerAnglesZYX(float Z, float Y, float X)
{
    G3D::Quat quat(G3D::Matrix3::fromEulerAnglesZYX(Z, Y, X));
    return QuaternionData(quat.x, quat.y, quat.z, quat.w);
}

GameObjectTypeBase::CustomCommand::~CustomCommand() = default;

namespace GameObjectType
{
//11 GAMEOBJECT_TYPE_TRANSPORT
class Transport : public GameObjectTypeBase, public TransportBase
{
public:
    static constexpr Milliseconds PositionUpdateInterval = 50ms;

    explicit Transport(GameObject& owner) : GameObjectTypeBase(owner), _animationInfo(sTransportMgr->GetTransportAnimInfo(owner.GetGOInfo()->entry)),
        _pathProgress(GameTime::GetGameTimeMS() % GetTransportPeriod()), _stateChangeTime(GameTime::GetGameTimeMS()), _stateChangeProgress(_pathProgress),
        _autoCycleBetweenStopFrames(false)
    {
        GameObjectTemplate const* goInfo = _owner.GetGOInfo();
        if (goInfo->transport.Timeto2ndfloor > 0)
        {
            _stopFrames.push_back(goInfo->transport.Timeto2ndfloor);
            if (goInfo->transport.Timeto3rdfloor > 0)
            {
                _stopFrames.push_back(goInfo->transport.Timeto3rdfloor);
                if (goInfo->transport.Timeto4thfloor > 0)
                {
                    _stopFrames.push_back(goInfo->transport.Timeto4thfloor);
                    if (goInfo->transport.Timeto5thfloor > 0)
                    {
                        _stopFrames.push_back(goInfo->transport.Timeto5thfloor);
                        if (goInfo->transport.Timeto6thfloor > 0)
                        {
                            _stopFrames.push_back(goInfo->transport.Timeto6thfloor);
                            if (goInfo->transport.Timeto7thfloor > 0)
                            {
                                _stopFrames.push_back(goInfo->transport.Timeto7thfloor);
                                if (goInfo->transport.Timeto8thfloor > 0)
                                {
                                    _stopFrames.push_back(goInfo->transport.Timeto8thfloor);
                                    if (goInfo->transport.Timeto9thfloor > 0)
                                    {
                                        _stopFrames.push_back(goInfo->transport.Timeto9thfloor);
                                        if (goInfo->transport.Timeto10thfloor > 0)
                                            _stopFrames.push_back(goInfo->transport.Timeto10thfloor);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (!_stopFrames.empty())
        {
            _pathProgress = 0;
            _stateChangeProgress = 0;
        }

        _positionUpdateTimer.Reset(PositionUpdateInterval);
    }

    void Update(uint32 diff) override
    {
        if (!_animationInfo)
            return;

        _positionUpdateTimer.Update(diff);
        if (!_positionUpdateTimer.Passed())
            return;

        _positionUpdateTimer.Reset(PositionUpdateInterval);

        uint32 now = GameTime::GetGameTimeMS();
        uint32 period = GetTransportPeriod();
        uint32 newProgress = 0;
        if (_stopFrames.empty())
            newProgress = now % period;
        else
        {
            int32 stopTargetTime = 0;
            if (_owner.GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
                stopTargetTime = 0;
            else
                stopTargetTime = _stopFrames[_owner.GetGoState() - GO_STATE_TRANSPORT_STOPPED];

            if (now < uint32(*_owner.m_gameObjectData->Level))
            {
                int32 timeToStop = _owner.m_gameObjectData->Level - _stateChangeTime;
                float stopSourcePathPct = float(_stateChangeProgress) / float(period);
                float stopTargetPathPct = float(stopTargetTime) / float(period);
                float timeSinceStopProgressPct = float(now - _stateChangeTime) / float(timeToStop);

                float progressPct;
                if (!_owner.HasDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT))
                {
                    if (_owner.GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
                        stopTargetPathPct = 1.0f;

                    float pathPctBetweenStops = stopTargetPathPct - stopSourcePathPct;
                    if (pathPctBetweenStops < 0.0f)
                        pathPctBetweenStops += 1.0f;

                    progressPct = pathPctBetweenStops * timeSinceStopProgressPct + stopSourcePathPct;
                    if (progressPct > 1.0f)
                        progressPct = progressPct - 1.0f;
                }
                else
                {
                    float pathPctBetweenStops = stopSourcePathPct - stopTargetPathPct;
                    if (pathPctBetweenStops < 0.0f)
                        pathPctBetweenStops += 1.0f;

                    progressPct = stopSourcePathPct - pathPctBetweenStops * timeSinceStopProgressPct;
                    if (progressPct < 0.0f)
                        progressPct += 1.0f;
                }

                newProgress = uint32(float(period) * progressPct) % period;
            }
            else
                newProgress = stopTargetTime;

            if (int32(newProgress) == stopTargetTime && newProgress != _pathProgress)
            {
                uint32 eventId = [&]()
                {
                    switch (_owner.GetGoState() - GO_STATE_TRANSPORT_ACTIVE)
                    {
                        case 0:
                            return _owner.GetGOInfo()->transport.Reached1stfloor;
                        case 1:
                            return _owner.GetGOInfo()->transport.Reached2ndfloor;
                        case 2:
                            return _owner.GetGOInfo()->transport.Reached3rdfloor;
                        case 3:
                            return _owner.GetGOInfo()->transport.Reached4thfloor;
                        case 4:
                            return _owner.GetGOInfo()->transport.Reached5thfloor;
                        case 5:
                            return _owner.GetGOInfo()->transport.Reached6thfloor;
                        case 6:
                            return _owner.GetGOInfo()->transport.Reached7thfloor;
                        case 7:
                            return _owner.GetGOInfo()->transport.Reached8thfloor;
                        case 8:
                            return _owner.GetGOInfo()->transport.Reached9thfloor;
                        case 9:
                            return _owner.GetGOInfo()->transport.Reached10thfloor;
                        default:
                            return 0u;
                    }
                }();
                if (eventId)
                    GameEvents::Trigger(eventId, &_owner, &_owner);

                if (_autoCycleBetweenStopFrames)
                {
                    GOState currentState = _owner.GetGoState();
                    GOState newState;
                    if (currentState == GO_STATE_TRANSPORT_ACTIVE)
                        newState = GO_STATE_TRANSPORT_STOPPED;
                    else if (currentState - GO_STATE_TRANSPORT_ACTIVE == int32(_stopFrames.size()))
                        newState = GOState(currentState - 1);
                    else if (_owner.HasDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT))
                        newState = GOState(currentState - 1);
                    else
                        newState = GOState(currentState + 1);

                    _owner.SetGoState(newState);
                }
            }
        }

        if (_pathProgress == newProgress)
            return;

        _pathProgress = newProgress;

        TransportAnimationEntry const* oldAnimation = _animationInfo->GetPrevAnimNode(newProgress);
        TransportAnimationEntry const* newAnimation = _animationInfo->GetNextAnimNode(newProgress);
        if (oldAnimation && newAnimation)
        {
            G3D::Matrix3 pathRotation = G3D::Quat(_owner.m_gameObjectData->ParentRotation->x, _owner.m_gameObjectData->ParentRotation->y,
                _owner.m_gameObjectData->ParentRotation->z, _owner.m_gameObjectData->ParentRotation->w).toRotationMatrix();

            G3D::Vector3 prev(oldAnimation->Pos.X, oldAnimation->Pos.Y, oldAnimation->Pos.Z);
            G3D::Vector3 next(newAnimation->Pos.X, newAnimation->Pos.Y, newAnimation->Pos.Z);

            G3D::Vector3 dst = next;
            if (prev != next)
            {
                float animProgress = float(newProgress - oldAnimation->TimeIndex) / float(newAnimation->TimeIndex - oldAnimation->TimeIndex);

                dst = prev.lerp(next, animProgress);
            }

            dst = dst * pathRotation;
            dst += PositionToVector3(&_owner.GetStationaryPosition());

            _owner.GetMap()->GameObjectRelocation(&_owner, dst.x, dst.y, dst.z, _owner.GetOrientation());
        }

        TransportRotationEntry const* oldRotation = _animationInfo->GetPrevAnimRotation(newProgress);
        TransportRotationEntry const* newRotation = _animationInfo->GetNextAnimRotation(newProgress);
        if (oldRotation && newRotation)
        {
            G3D::Quat prev(oldRotation->Rot[0], oldRotation->Rot[1], oldRotation->Rot[2], oldRotation->Rot[3]);
            G3D::Quat next(newRotation->Rot[0], newRotation->Rot[1], newRotation->Rot[2], newRotation->Rot[3]);

            G3D::Quat rotation = next;

            if (prev != next)
            {
                float animProgress = float(newProgress - oldRotation->TimeIndex) / float(newRotation->TimeIndex - oldRotation->TimeIndex);

                rotation = prev.slerp(next, animProgress);
            }

            _owner.SetLocalRotation(rotation.x, rotation.y, rotation.z, rotation.w);
            _owner.UpdateModelPosition();
        }

        // update progress marker for client
        _owner.SetPathProgressForClient(float(_pathProgress) / float(period));
    }

    void OnStateChanged(GOState oldState, GOState newState) override
    {
        ASSERT(newState >= GO_STATE_TRANSPORT_ACTIVE);

        // transports without stop frames just keep animating in state 24
        if (_stopFrames.empty())
        {
            if (newState != GO_STATE_TRANSPORT_ACTIVE)
                _owner.SetGoState(GO_STATE_TRANSPORT_ACTIVE);
            return;
        }

        int32 stopPathProgress = 0;

        if (newState != GO_STATE_TRANSPORT_ACTIVE)
        {
            ASSERT(newState < GOState(GO_STATE_TRANSPORT_STOPPED + MAX_GO_STATE_TRANSPORT_STOP_FRAMES));
            uint32 stopFrame = newState - GO_STATE_TRANSPORT_STOPPED;
            ASSERT(stopFrame < _stopFrames.size());
            stopPathProgress = _stopFrames[stopFrame];
        }

        _stateChangeTime = GameTime::GetGameTimeMS();
        _stateChangeProgress = _pathProgress;
        uint32 timeToStop = std::abs(int32(_pathProgress) - stopPathProgress);
        _owner.SetLevel(GameTime::GetGameTimeMS() + timeToStop);
        _owner.SetPathProgressForClient(float(_pathProgress) / float(GetTransportPeriod()));

        if (oldState == GO_STATE_ACTIVE || oldState == newState)
        {
            // initialization
            if (int32(_pathProgress) > stopPathProgress)
                _owner.SetDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT);
            else
                _owner.RemoveDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT);

             return;
        }

        int32 pauseTimesCount = _stopFrames.size();
        int32 newToOldStateDelta = newState - oldState;
        if (newToOldStateDelta < 0)
            newToOldStateDelta += pauseTimesCount + 1;

        int32 oldToNewStateDelta = oldState - newState;
        if (oldToNewStateDelta < 0)
            oldToNewStateDelta += pauseTimesCount + 1;

        // this additional check is neccessary because client doesn't check dynamic flags on progress update
        // instead it multiplies progress from dynamicflags field by -1 and then compares that against 0
        // when calculating path progress while we simply check the flag if (!_owner.HasDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT))
        bool isAtStartOfPath = _stateChangeProgress == 0;

        if (oldToNewStateDelta < newToOldStateDelta && !isAtStartOfPath)
            _owner.SetDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT);
        else
            _owner.RemoveDynamicFlag(GO_DYNFLAG_LO_INVERTED_MOVEMENT);
    }

    void OnRelocated() override
    {
        UpdatePassengerPositions();
    }

    void UpdatePassengerPositions()
    {
        for (WorldObject* passenger : _passengers)
        {
            float x, y, z, o;
            passenger->m_movementInfo.transport.pos.GetPosition(x, y, z, o);
            CalculatePassengerPosition(x, y, z, &o);
            UpdatePassengerPosition(_owner.GetMap(), passenger, x, y, z, o, true);
        }
    }

    uint32 GetTransportPeriod() const
    {
        if (_animationInfo)
            return _animationInfo->TotalTime;

        return 1;
    }

    std::vector<uint32> const* GetPauseTimes() const
    {
        return &_stopFrames;
    }

    ObjectGuid GetTransportGUID() const override { return _owner.GetGUID(); }

    float GetTransportOrientation() const override { return _owner.GetOrientation(); }

    void AddPassenger(WorldObject* passenger) override
    {
        if (!_owner.IsInWorld())
            return;

        if (_passengers.insert(passenger).second)
        {
            passenger->SetTransport(this);
            passenger->m_movementInfo.transport.guid = GetTransportGUID();
            TC_LOG_DEBUG("entities.transport", "Object {} boarded transport {}.", passenger->GetName(), _owner.GetName());
        }
    }

    TransportBase* RemovePassenger(WorldObject* passenger) override
    {
        if (_passengers.erase(passenger) > 0)
        {
            passenger->SetTransport(nullptr);
            passenger->m_movementInfo.transport.Reset();
            TC_LOG_DEBUG("entities.transport", "Object {} removed from transport {}.", passenger->GetName(), _owner.GetName());

            if (Player* plr = passenger->ToPlayer())
                plr->SetFallInformation(0, plr->GetPositionZ());
        }

        return this;
    }

    void CalculatePassengerPosition(float& x, float& y, float& z, float* o) const override
    {
        TransportBase::CalculatePassengerPosition(x, y, z, o, _owner.GetPositionX(), _owner.GetPositionY(), _owner.GetPositionZ(), _owner.GetOrientation());
    }

    void CalculatePassengerOffset(float& x, float& y, float& z, float* o) const override
    {
        TransportBase::CalculatePassengerOffset(x, y, z, o, _owner.GetPositionX(), _owner.GetPositionY(), _owner.GetPositionZ(), _owner.GetOrientation());
    }

    int32 GetMapIdForSpawning() const override
    {
        return _owner.GetGOInfo()->transport.SpawnMap;
    }

    void SetAutoCycleBetweenStopFrames(bool on)
    {
        _autoCycleBetweenStopFrames = on;
    }

private:
    TransportAnimation const* _animationInfo;
    uint32 _pathProgress;
    uint32 _stateChangeTime;
    uint32 _stateChangeProgress;
    std::vector<uint32> _stopFrames;
    bool _autoCycleBetweenStopFrames;
    TimeTracker _positionUpdateTimer;
    std::unordered_set<WorldObject*> _passengers;
};

SetTransportAutoCycleBetweenStopFrames::SetTransportAutoCycleBetweenStopFrames(bool on) : _on(on)
{
}

void SetTransportAutoCycleBetweenStopFrames::Execute(GameObjectTypeBase& type) const
{
    if (Transport* transport = dynamic_cast<Transport*>(&type))
        transport->SetAutoCycleBetweenStopFrames(_on);
}

class NewFlag : public GameObjectTypeBase
{
public:
    explicit NewFlag(GameObject& owner) : GameObjectTypeBase(owner), _state(FlagState::InBase), _respawnTime(0), _takenFromBaseTime(0) { }

    void SetState(FlagState newState, Player* player)
    {
        if (_state == newState)
            return;

        FlagState oldState = _state;
        _state = newState;

        if (player && newState == FlagState::Taken)
            _carrierGUID = player->GetGUID();
        else
            _carrierGUID = ObjectGuid::Empty;

        if (newState == FlagState::Taken && oldState == FlagState::InBase)
            _takenFromBaseTime = GameTime::GetGameTime();
        else if (newState == FlagState::InBase || newState == FlagState::Respawning)
            _takenFromBaseTime = 0;

        _owner.UpdateObjectVisibility();

        if (newState == FlagState::Respawning)
            _respawnTime = GameTime::GetGameTimeMS() + _owner.GetGOInfo()->newflag.RespawnTime;
        else
            _respawnTime = 0;

        if (ZoneScript* zoneScript = _owner.GetZoneScript())
            zoneScript->OnFlagStateChange(&_owner, oldState, _state, player);
    }

    void Update([[maybe_unused]] uint32 diff) override
    {
        if (_state == FlagState::Respawning && GameTime::GetGameTimeMS() >= _respawnTime)
            SetState(FlagState::InBase, nullptr);
    }

    bool IsNeverVisibleFor([[maybe_unused]] WorldObject const* seer, [[maybe_unused]] bool allowServersideObjects) const override
    {
        return _state != FlagState::InBase;
    }

    FlagState GetState() const { return _state; }
    ObjectGuid const& GetCarrierGUID() const { return _carrierGUID; }
    time_t GetTakenFromBaseTime() const { return _takenFromBaseTime; }

private:
    FlagState _state;
    time_t _respawnTime;
    ObjectGuid _carrierGUID;
    time_t _takenFromBaseTime;
};

SetNewFlagState::SetNewFlagState(FlagState state, Player* player) : _state(state), _player(player)
{
}

void SetNewFlagState::Execute(GameObjectTypeBase& type) const
{
    if (NewFlag* newFlag = dynamic_cast<NewFlag*>(&type))
        newFlag->SetState(_state, _player);
}

class ControlZone : public GameObjectTypeBase
{
public:
    explicit ControlZone(GameObject& owner) : GameObjectTypeBase(owner), _value(static_cast<float>(owner.GetGOInfo()->controlZone.startingValue))
    {
        if (owner.GetMap()->Instanceable())
            _heartbeatRate = 1s;
        else if (owner.GetGOInfo()->controlZone.FrequentHeartbeat)
            _heartbeatRate = 2500ms;
        else
            _heartbeatRate = 5s;

        _heartbeatTracker.Reset(_heartbeatRate);
        _previousTeamId = GetControllingTeam();
        _contestedTriggered = false;
    }

    void Update(uint32 diff) override
    {
        if (_owner.HasFlag(GO_FLAG_NOT_SELECTABLE))
            return;

        _heartbeatTracker.Update(diff);
        if (_heartbeatTracker.Passed())
        {
            _heartbeatTracker.Reset(_heartbeatRate);
            HandleHeartbeat();
        }
    }

    TeamId GetControllingTeam() const
    {
        if (_value < GetMaxHordeValue())
            return TEAM_HORDE;

        if (_value > GetMinAllianceValue())
            return TEAM_ALLIANCE;

        return TEAM_NEUTRAL;
    }

    GuidUnorderedSet const* GetInsidePlayers() const { return &_insidePlayers; }

    void ActivateObject(GameObjectActions action, int32 /*param*/, WorldObject* /*spellCaster*/, uint32 /*spellId*/, int32 /*effectIndex*/) override
    {
        switch (action)
        {
            case GameObjectActions::MakeInert:
                for (ObjectGuid const& guid : _insidePlayers)
                    if (Player* player = ObjectAccessor::GetPlayer(_owner, guid))
                        player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldState1, 0);

                _insidePlayers.clear();
                break;
            default:
                break;
        }
    }

    void SetValue(float value)
    {
        _value = RoundToInterval<float>(value, 0.0f, 100.0f);
    }

    void HandleHeartbeat()
    {
        // update player list inside control zone
        std::vector<Player*> targetList;
        SearchTargets(targetList);

        TeamId oldControllingTeam = GetControllingTeam();
        float pointsGained = CalculatePointsPerSecond(targetList) * _heartbeatRate.count() / 1000.0f;
        if (pointsGained == 0)
            return;

        int32 oldRoundedValue = static_cast<int32>(_value);
        SetValue(_value + pointsGained);
        int32 roundedValue = static_cast<int32>(_value);
        if (oldRoundedValue == roundedValue)
            return;

        TeamId newControllingTeam = GetControllingTeam();
        TeamId assaultingTeam = pointsGained > 0 ? TEAM_ALLIANCE : TEAM_HORDE;

        if (oldControllingTeam != newControllingTeam)
            _contestedTriggered = false;

        if (oldControllingTeam != TEAM_ALLIANCE && newControllingTeam == TEAM_ALLIANCE)
            TriggerEvent(_owner.GetGOInfo()->controlZone.ProgressEventAlliance);
        else if (oldControllingTeam != TEAM_HORDE && newControllingTeam == TEAM_HORDE)
            TriggerEvent(_owner.GetGOInfo()->controlZone.ProgressEventHorde);
        else if (oldControllingTeam == TEAM_HORDE && newControllingTeam == TEAM_NEUTRAL)
            TriggerEvent(_owner.GetGOInfo()->controlZone.NeutralEventHorde);
        else if (oldControllingTeam == TEAM_ALLIANCE && newControllingTeam == TEAM_NEUTRAL)
            TriggerEvent(_owner.GetGOInfo()->controlZone.NeutralEventAlliance);

        if (roundedValue == 100 && newControllingTeam == TEAM_ALLIANCE && assaultingTeam == TEAM_ALLIANCE)
            TriggerEvent(_owner.GetGOInfo()->controlZone.CaptureEventAlliance);
        else if (roundedValue == 0 && newControllingTeam == TEAM_HORDE && assaultingTeam == TEAM_HORDE)
            TriggerEvent(_owner.GetGOInfo()->controlZone.CaptureEventHorde);

        if (oldRoundedValue == 100 && assaultingTeam == TEAM_HORDE && !_contestedTriggered)
        {
            TriggerEvent(_owner.GetGOInfo()->controlZone.ContestedEventHorde);
            _contestedTriggered = true;
        }
        else if (oldRoundedValue == 0 && assaultingTeam == TEAM_ALLIANCE && !_contestedTriggered)
        {
            TriggerEvent(_owner.GetGOInfo()->controlZone.ContestedEventAlliance);
            _contestedTriggered = true;
        }

        for (Player* player : targetList)
            player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldstate2, roundedValue);
    }

    void SearchTargets(std::vector<Player*>& targetList)
    {
        Trinity::AnyUnitInObjectRangeCheck check(&_owner, _owner.GetGOInfo()->controlZone.radius, true);
        Trinity::PlayerListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(&_owner, targetList, check);
        Cell::VisitWorldObjects(&_owner, searcher, _owner.GetGOInfo()->controlZone.radius);
        HandleUnitEnterExit(targetList);
    }

    float CalculatePointsPerSecond(std::vector<Player*> const& targetList)
    {
        int32 delta = 0;

        for (Player* player : targetList)
        {
            if (!player->IsOutdoorPvPActive())
                continue;

            if (player->GetTeamId() == TEAM_HORDE)
                delta--;
            else
                delta++;
        }

        uint32 minTime = _owner.GetGOInfo()->controlZone.minTime;
        uint32 maxTime = _owner.GetGOInfo()->controlZone.maxTime;
        uint32 minSuperiority = _owner.GetGOInfo()->controlZone.minSuperiority;
        uint32 maxSuperiority = _owner.GetGOInfo()->controlZone.maxSuperiority;

        if (static_cast<uint32>(std::abs(delta)) < minSuperiority)
            return 0;

        float slope = (static_cast<float>(minTime) - maxTime) / (maxSuperiority - minSuperiority);
        float intercept = maxTime - slope * minSuperiority;
        float timeNeeded = slope * std::abs(delta) + intercept;
        float percentageIncrease = 100.0f / timeNeeded;

        if (delta < 0)
            percentageIncrease *= -1;

        return percentageIncrease;
    }

    void HandleUnitEnterExit(std::vector<Player*> const& newTargetList)
    {
        GuidUnorderedSet exitPlayers(std::move(_insidePlayers));

        std::vector<Player*> enteringPlayers;

        for (Player* unit : newTargetList)
        {
            if (exitPlayers.erase(unit->GetGUID()) == 0) // erase(key_type) returns number of elements erased
                enteringPlayers.push_back(unit);

            _insidePlayers.insert(unit->GetGUID());
        }

        for (Player* player : enteringPlayers)
        {
            player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldState1, 1);
            player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldstate2, static_cast<int32>(_value));
            player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldstate3, _owner.GetGOInfo()->controlZone.neutralPercent);
        }

        for (ObjectGuid const& exitPlayerGuid : exitPlayers)
        {
            if (Player* player = ObjectAccessor::GetPlayer(_owner, exitPlayerGuid))
            {
                player->SendUpdateWorldState(_owner.GetGOInfo()->controlZone.worldState1, 0);
            }
        }
    }

    float GetMaxHordeValue() const
    {
        // ex: if neutralPercent is 40; then 0 - 30 is Horde Controlled
        return 50.0f - _owner.GetGOInfo()->controlZone.neutralPercent / 2.0f;
    }

    float GetMinAllianceValue() const
    {
        // ex: if neutralPercent is 40; then 70 - 100 is Alliance Controlled
        return 50.0f + _owner.GetGOInfo()->controlZone.neutralPercent / 2.0f;
    }

    void TriggerEvent(uint32 eventId) const
    {
        if (eventId <= 0)
            return;

        _owner.GetMap()->UpdateSpawnGroupConditions();
        GameEvents::Trigger(eventId, &_owner, nullptr);
    }

    uint32 GetStartingValue() const
    {
        return _owner.GetGOInfo()->controlZone.startingValue;
    }

private:
    Milliseconds _heartbeatRate;
    TimeTracker _heartbeatTracker;
    GuidUnorderedSet _insidePlayers;
    TeamId _previousTeamId;
    float _value;
    bool _contestedTriggered;
};

SetControlZoneValue::SetControlZoneValue(Optional<uint32> value /*= { }*/) : _value(value)
{
}

void SetControlZoneValue::Execute(GameObjectTypeBase& type) const
{
    if (ControlZone* controlZone = dynamic_cast<ControlZone*>(&type))
    {
        uint32 value = controlZone->GetStartingValue();
        if (_value.has_value())
            value = *_value;

        controlZone->SetValue(value);
    }
}
}

GameObject::GameObject() : WorldObject(false), MapObject(),
    m_model(nullptr), m_goValue(), m_AI(nullptr), m_respawnCompatibilityMode(false), _animKitId(0), _worldEffectID(0)
{
    m_objectType |= TYPEMASK_GAMEOBJECT;
    m_objectTypeId = TYPEID_GAMEOBJECT;

    m_updateFlag.Stationary = true;
    m_updateFlag.Rotation = true;

    m_respawnTime = 0;
    m_respawnDelayTime = 300;
    m_despawnDelay = 0;
    m_despawnRespawnTime = 0s;
    m_restockTime = 0;
    m_lootState = GO_NOT_READY;
    m_spawnedByDefault = true;
    m_usetimes = 0;
    m_spellId = 0;
    m_cooldownTime = 0;
    m_prevGoState = GO_STATE_ACTIVE;
    m_goInfo = nullptr;
    m_goData = nullptr;
    m_packedRotation = 0;
    m_goTemplateAddon = nullptr;

    m_spawnId = UI64LIT(0);

    ResetLootMode(); // restore default loot mode
    m_stationaryPosition.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
}

GameObject::~GameObject()
{
    delete m_AI;
    delete m_model;
}

void GameObject::AIM_Destroy()
{
    delete m_AI;
    m_AI = nullptr;
}

bool GameObject::AIM_Initialize()
{
    AIM_Destroy();

    m_AI = FactorySelector::SelectGameObjectAI(this);

    if (!m_AI)
        return false;

    m_AI->InitializeAI();
    return true;
}

std::string const& GameObject::GetAIName() const
{
    return sObjectMgr->GetGameObjectTemplate(GetEntry())->AIName;
}

void GameObject::CleanupsBeforeDelete(bool finalCleanup)
{
    WorldObject::CleanupsBeforeDelete(finalCleanup);

    RemoveFromOwner();
}

void GameObject::RemoveFromOwner()
{
    ObjectGuid ownerGUID = GetOwnerGUID();
    if (!ownerGUID)
        return;

    if (Unit* owner = ObjectAccessor::GetUnit(*this, ownerGUID))
    {
        owner->RemoveGameObject(this, false);
        ASSERT(!GetOwnerGUID());
        return;
    }

    // This happens when a mage portal is despawned after the caster changes map (for example using the portal)
    TC_LOG_DEBUG("misc", "Removed GameObject ({} Entry: {} SpellId: {} LinkedGO: {}) that just lost any reference to the owner ({}) GO list",
        GetGUID().ToString(), GetGOInfo()->entry, m_spellId, GetGOInfo()->GetLinkedGameObjectEntry(), ownerGUID.ToString());
    SetOwnerGUID(ObjectGuid::Empty);
}

void GameObject::AddToWorld()
{
    ///- Register the gameobject for guid lookup
    if (!IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnGameObjectCreate(this);

        GetMap()->GetObjectsStore().Insert<GameObject>(GetGUID(), this);
        if (m_spawnId)
            GetMap()->GetGameObjectBySpawnIdStore().insert(std::make_pair(m_spawnId, this));

        // The state can be changed after GameObject::Create but before GameObject::AddToWorld
        bool toggledState = GetGoType() == GAMEOBJECT_TYPE_CHEST ? getLootState() == GO_READY : (GetGoState() == GO_STATE_READY || IsTransport());
        if (m_model)
        {
            if (Transport* trans = ToTransport())
                trans->SetDelayedAddModelToMap();
            else
                GetMap()->InsertGameObjectModel(*m_model);
        }

        EnableCollision(toggledState);
        WorldObject::AddToWorld();
    }
}

void GameObject::RemoveFromWorld()
{
    ///- Remove the gameobject from the accessor
    if (IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnGameObjectRemove(this);

        RemoveFromOwner();
        if (m_model)
            if (GetMap()->ContainsGameObjectModel(*m_model))
                GetMap()->RemoveGameObjectModel(*m_model);

        // If linked trap exists, despawn it
        if (GameObject* linkedTrap = GetLinkedTrap())
            linkedTrap->DespawnOrUnsummon();

        WorldObject::RemoveFromWorld();

        if (m_spawnId)
            Trinity::Containers::MultimapErasePair(GetMap()->GetGameObjectBySpawnIdStore(), m_spawnId, this);
        GetMap()->GetObjectsStore().Remove<GameObject>(GetGUID());
    }
}

bool GameObject::Create(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit, bool dynamic, ObjectGuid::LowType spawnid)
{
    ASSERT(map);
    SetMap(map);

    Relocate(pos);
    m_stationaryPosition.Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("misc", "Gameobject (Spawn id: {} Entry: {}) not created. Suggested coordinates isn't valid (X: {} Y: {})", GetSpawnId(), entry, pos.GetPositionX(), pos.GetPositionY());
        return false;
    }

    // Set if this object can handle dynamic spawns
    if (!dynamic)
        SetRespawnCompatibilityMode();

    UpdatePositionData();

    SetZoneScript();
    if (m_zoneScript)
    {
        entry = m_zoneScript->GetGameObjectEntry(m_spawnId, entry);
        if (!entry)
            return false;
    }

    GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goInfo)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (Spawn id: {} Entry: {}) not created: non-existing entry in `gameobject_template`. Map: {} (X: {} Y: {} Z: {})", GetSpawnId(), entry, map->GetId(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        return false;
    }

    if (goInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (Spawn id: {} Entry: {}) not created: gameobject type GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT cannot be manually created.", GetSpawnId(), entry);
        return false;
    }

    ObjectGuid guid;
    if (goInfo->type != GAMEOBJECT_TYPE_TRANSPORT)
        guid = ObjectGuid::Create<HighGuid::GameObject>(map->GetId(), goInfo->entry, map->GenerateLowGuid<HighGuid::GameObject>());
    else
    {
        guid = ObjectGuid::Create<HighGuid::Transport>(map->GenerateLowGuid<HighGuid::Transport>());
        m_updateFlag.ServerTime = true;
    }

    Object::_Create(guid);

    m_goInfo = goInfo;
    m_goTemplateAddon = sObjectMgr->GetGameObjectTemplateAddon(entry);

    if (goInfo->type >= MAX_GAMEOBJECT_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject ({} Spawn id: {} Entry: {}) not created: non-existing GO type '{}' in `gameobject_template`. It will crash client if created.", guid.ToString(), GetSpawnId(), entry, goInfo->type);
        return false;
    }

    SetLocalRotation(rotation.x, rotation.y, rotation.z, rotation.w);
    GameObjectAddon const* gameObjectAddon = sObjectMgr->GetGameObjectAddon(GetSpawnId());

    // For most of gameobjects is (0, 0, 0, 1) quaternion, there are only some transports with not standard rotation
    QuaternionData parentRotation;
    if (gameObjectAddon)
        parentRotation = gameObjectAddon->ParentRotation;

    SetParentRotation(parentRotation);

    SetObjectScale(goInfo->size);

    if (GameObjectOverride const* goOverride = GetGameObjectOverride())
    {
        SetFaction(goOverride->Faction);
        ReplaceAllFlags(GameObjectFlags(goOverride->Flags));
    }

    if (m_goTemplateAddon)
    {
        if (m_goTemplateAddon->WorldEffectID)
        {
            m_updateFlag.GameObject = true;
            SetWorldEffectID(m_goTemplateAddon->WorldEffectID);
        }

        if (m_goTemplateAddon->AIAnimKitID)
            _animKitId = m_goTemplateAddon->AIAnimKitID;
    }

    SetEntry(goInfo->entry);

    // set name for logs usage, doesn't affect anything ingame
    SetName(goInfo->name);

    SetDisplayId(goInfo->displayId);

    CreateModel();
    // GAMEOBJECT_BYTES_1, index at 0, 1, 2 and 3
    SetGoType(GameobjectTypes(goInfo->type));
    m_prevGoState = goState;
    SetGoState(goState);
    SetGoArtKit(artKit);

    //SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::SpawnTrackingStateAnimID), sDB2Manager.GetEmptyAnimStateID());
    constexpr uint32 spawnTrackingAnimId = 1772; // the WotLK classic client expects the retail AnimationEntry db2 storage size so we have to hardcode it for the time being
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::SpawnTrackingStateAnimID), spawnTrackingAnimId);

    switch (goInfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGHOLE:
            SetGoAnimProgress(animProgress);
            m_goValue.FishingHole.MaxOpens = urand(GetGOInfo()->fishingHole.minRestock, GetGOInfo()->fishingHole.maxRestock);
            break;
        case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
        {
            // TODO: Get the values somehow, no longer in gameobject_template
            m_goValue.Building.Health = 20000/*goinfo->destructibleBuilding.intactNumHits + goinfo->destructibleBuilding.damagedNumHits*/;
            m_goValue.Building.MaxHealth = m_goValue.Building.Health;
            SetGoAnimProgress(255);
            // yes, even after the updatefield rewrite this garbage hack is still in client
            QuaternionData reinterpretId;
            memcpy(&reinterpretId.x, &m_goInfo->destructibleBuilding.DestructibleModelRec, sizeof(float));
            SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::ParentRotation), reinterpretId);
            break;
        }
        case GAMEOBJECT_TYPE_TRANSPORT:
        {
            m_goTypeImpl = std::make_unique<GameObjectType::Transport>(*this);
            if (goInfo->transport.startOpen)
                SetGoState(GO_STATE_TRANSPORT_STOPPED);
            else
                SetGoState(GO_STATE_TRANSPORT_ACTIVE);

            SetGoAnimProgress(animProgress);
            setActive(true);
            break;
        }
        case GAMEOBJECT_TYPE_FISHINGNODE:
            SetLevel(0);
            SetGoAnimProgress(255);
            break;
        case GAMEOBJECT_TYPE_TRAP:
            if (GetGOInfo()->trap.stealthed)
            {
                m_stealth.AddFlag(STEALTH_TRAP);
                m_stealth.AddValue(STEALTH_TRAP, 70);
            }

            if (GetGOInfo()->trap.stealthAffected)
            {
                m_invisibility.AddFlag(INVISIBILITY_TRAP);
                m_invisibility.AddValue(INVISIBILITY_TRAP, 300);
            }
            break;
        case GAMEOBJECT_TYPE_CONTROL_ZONE:
            m_goTypeImpl = std::make_unique<GameObjectType::ControlZone>(*this);
            setActive(true);
            break;
        case GAMEOBJECT_TYPE_NEW_FLAG:
            m_goTypeImpl = std::make_unique<GameObjectType::NewFlag>(*this);
            if (map->Instanceable())
                setActive(true);
            break;
        case GAMEOBJECT_TYPE_NEW_FLAG_DROP:
            if (map->Instanceable())
                setActive(true);
            break;
        case GAMEOBJECT_TYPE_PHASEABLE_MO:
            RemoveFlag(GameObjectFlags(0xF00));
            SetFlag(GameObjectFlags((m_goInfo->phaseableMO.AreaNameSet & 0xF) << 8));
            break;
        case GAMEOBJECT_TYPE_CAPTURE_POINT:
            SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::SpellVisualID), m_goInfo->capturePoint.SpellVisual1);
            m_goValue.CapturePoint.AssaultTimer = 0;
            m_goValue.CapturePoint.LastTeamCapture = TEAM_NEUTRAL;
            m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::Neutral;
            UpdateCapturePoint();
            if (map->Instanceable())
                setActive(true);
            break;
        default:
            SetGoAnimProgress(animProgress);
            break;
    }

    if (gameObjectAddon)
    {
        if (gameObjectAddon->InvisibilityValue)
        {
            m_invisibility.AddFlag(gameObjectAddon->invisibilityType);
            m_invisibility.AddValue(gameObjectAddon->invisibilityType, gameObjectAddon->InvisibilityValue);
        }

        if (gameObjectAddon->WorldEffectID)
        {
            m_updateFlag.GameObject = true;
            SetWorldEffectID(gameObjectAddon->WorldEffectID);
        }

        if (gameObjectAddon->AIAnimKitID)
            _animKitId = gameObjectAddon->AIAnimKitID;
    }

    LastUsedScriptID = GetGOInfo()->ScriptId;

    m_stringIds[0] = goInfo->StringId;

    AIM_Initialize();

    if (spawnid)
        m_spawnId = spawnid;

    if (uint32 linkedEntry = GetGOInfo()->GetLinkedGameObjectEntry())
    {
        if (GameObject* linkedGo = GameObject::CreateGameObject(linkedEntry, map, pos, rotation, 255, GO_STATE_READY))
        {
            SetLinkedTrap(linkedGo);
            if (!map->AddToMap(linkedGo))
                delete linkedGo;
        }
    }

    // Check if GameObject is Infinite
    if (goInfo->IsInfiniteGameObject())
        SetVisibilityDistanceOverride(VisibilityDistanceType::Infinite);

    // Check if GameObject is Gigantic
    if (goInfo->IsGiganticGameObject())
        SetVisibilityDistanceOverride(VisibilityDistanceType::Gigantic);

    // Check if GameObject is Large
    if (goInfo->IsLargeGameObject())
        SetVisibilityDistanceOverride(VisibilityDistanceType::Large);

    return true;
}

GameObject* GameObject::CreateGameObject(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit /*= 0*/)
{
    GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goInfo)
        return nullptr;

    GameObject* go = new GameObject();
    if (!go->Create(entry, map, pos, rotation, animProgress, goState, artKit, false, 0))
    {
        delete go;
        return nullptr;
    }

    return go;
}

GameObject* GameObject::CreateGameObjectFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap /*= true*/)
{
    GameObject* go = new GameObject();
    if (!go->LoadFromDB(spawnId, map, addToMap))
    {
        delete go;
        return nullptr;
    }

    return go;
}

void GameObject::Update(uint32 diff)
{
    WorldObject::Update(diff);

    if (AI())
        AI()->UpdateAI(diff);
    else if (!AIM_Initialize())
        TC_LOG_ERROR("misc", "Could not initialize GameObjectAI");

    if (m_despawnDelay)
    {
        if (m_despawnDelay > diff)
            m_despawnDelay -= diff;
        else
        {
            m_despawnDelay = 0;
            DespawnOrUnsummon(0ms, m_despawnRespawnTime);
        }
    }

    if (m_goTypeImpl)
        m_goTypeImpl->Update(diff);

    if (m_perPlayerState)
    {
        for (auto itr = m_perPlayerState->begin(); itr != m_perPlayerState->end(); )
        {
            if (itr->second.ValidUntil > GameTime::GetSystemTime())
            {
                ++itr;
                continue;
            }

            Player* seer = ObjectAccessor::GetPlayer(*this, itr->first);
            bool needsStateUpdate = itr->second.State != GetGoState();
            bool despawned = itr->second.Despawned;

            itr = m_perPlayerState->erase(itr);

            if (seer)
            {
                if (despawned)
                {
                    seer->UpdateVisibilityOf(this);
                }
                else if (needsStateUpdate)
                {
                    UF::ObjectData::Base objMask;
                    UF::GameObjectData::Base goMask;
                    goMask.MarkChanged(&UF::GameObjectData::State);

                    UpdateData udata(GetMapId());
                    BuildValuesUpdateForPlayerWithMask(&udata, objMask.GetChangesMask(), goMask.GetChangesMask(), seer);
                    WorldPacket packet;
                    udata.BuildPacket(&packet);
                    seer->SendDirectMessage(&packet);
                }
            }
        }
    }

    switch (m_lootState)
    {
        case GO_NOT_READY:
        {
            switch (GetGoType())
            {
                case GAMEOBJECT_TYPE_TRAP:
                {
                    // Arming Time for GAMEOBJECT_TYPE_TRAP (6)
                    GameObjectTemplate const* goInfo = GetGOInfo();
                    // Bombs
                    if (goInfo->trap.charges == 2)
                        // Hardcoded tooltip value
                        m_cooldownTime = GameTime::GetGameTimeMS() + 10 * IN_MILLISECONDS;
                    else if (Unit* owner = GetOwner())
                        if (owner->IsInCombat())
                            m_cooldownTime = GameTime::GetGameTimeMS() + goInfo->trap.startDelay * IN_MILLISECONDS;

                    SetLootState(GO_READY);
                    break;
                }
                case GAMEOBJECT_TYPE_FISHINGNODE:
                {
                    // fishing code (bobber ready)
                    if (GameTime::GetGameTime() > m_respawnTime - FISHING_BOBBER_READY_TIME)
                    {
                        // splash bobber (bobber ready now)
                        Unit* caster = GetOwner();
                        if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                            SendCustomAnim(0);

                        m_lootState = GO_READY;                 // can be successfully open with some chance
                    }
                    return;
                }
                case GAMEOBJECT_TYPE_CHEST:
                    if (m_restockTime > GameTime::GetGameTime())
                        return;
                    // If there is no restock timer, or if the restock timer passed, the chest becomes ready to loot
                    m_restockTime = 0;
                    m_lootState = GO_READY;
                    ClearLoot();
                    UpdateDynamicFlagsForNearbyPlayers();
                    break;
                default:
                    m_lootState = GO_READY;                         // for other GOis same switched without delay to GO_READY
                    break;
            }
            [[fallthrough]];
        }
        case GO_READY:
        {
            if (m_respawnCompatibilityMode)
            {
                if (m_respawnTime > 0)                          // timer on
                {
                    time_t now = GameTime::GetGameTime();
                    if (m_respawnTime <= now)            // timer expired
                    {
                        ObjectGuid dbtableHighGuid = ObjectGuid::Create<HighGuid::GameObject>(GetMapId(), GetEntry(), m_spawnId);
                        time_t linkedRespawntime = GetMap()->GetLinkedRespawnTime(dbtableHighGuid);
                        if (linkedRespawntime)             // Can't respawn, the master is dead
                        {
                            ObjectGuid targetGuid = sObjectMgr->GetLinkedRespawnGuid(dbtableHighGuid);
                            if (targetGuid == dbtableHighGuid) // if linking self, never respawn
                                SetRespawnTime(WEEK);
                            else
                                m_respawnTime = (now > linkedRespawntime ? now : linkedRespawntime) + urand(5, MINUTE); // else copy time from master and add a little
                            SaveRespawnTime();
                            return;
                        }

                        m_respawnTime = 0;
                        m_SkillupList.clear();
                        m_usetimes = 0;

                        switch (GetGoType())
                        {
                            case GAMEOBJECT_TYPE_FISHINGNODE:   //  can't fish now
                            {
                                Unit* caster = GetOwner();
                                if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                                {
                                    caster->ToPlayer()->RemoveGameObject(this, false);

                                    caster->ToPlayer()->SendDirectMessage(WorldPackets::GameObject::FishEscaped().Write());
                                }
                                // can be delete
                                m_lootState = GO_JUST_DEACTIVATED;
                                return;
                            }
                            case GAMEOBJECT_TYPE_DOOR:
                            case GAMEOBJECT_TYPE_BUTTON:
                                // We need to open doors if they are closed (add there another condition if this code breaks some usage, but it need to be here for battlegrounds)
                                if (GetGoState() != GO_STATE_READY)
                                    ResetDoorOrButton();
                                break;
                            case GAMEOBJECT_TYPE_FISHINGHOLE:
                                // Initialize a new max fish count on respawn
                                m_goValue.FishingHole.MaxOpens = urand(GetGOInfo()->fishingHole.minRestock, GetGOInfo()->fishingHole.maxRestock);
                                break;
                            default:
                                break;
                        }

                        // Despawn timer
                        if (!m_spawnedByDefault)
                        {
                            // Can be despawned or destroyed
                            SetLootState(GO_JUST_DEACTIVATED);
                            return;
                        }

                        // Call AI Reset (required for example in SmartAI to clear one time events)
                        if (AI())
                            AI()->Reset();

                        // Respawn timer
                        uint32 poolid = GetGameObjectData() ? GetGameObjectData()->poolId : 0;
                        if (poolid)
                            sPoolMgr->UpdatePool<GameObject>(GetMap()->GetPoolData(), poolid, GetSpawnId());
                        else
                            GetMap()->AddToMap(this);
                    }
                }
            }

            // Set respawn timer
            if (!m_respawnCompatibilityMode && m_respawnTime > 0)
                SaveRespawnTime();

            if (isSpawned())
            {
                GameObjectTemplate const* goInfo = GetGOInfo();
                if (goInfo->type == GAMEOBJECT_TYPE_TRAP)
                {
                    if (GameTime::GetGameTimeMS() < m_cooldownTime)
                        break;

                    // Type 2 (bomb) does not need to be triggered by a unit and despawns after casting its spell.
                    if (goInfo->trap.charges == 2)
                    {
                        SetLootState(GO_ACTIVATED);
                        break;
                    }

                    // Type 0 despawns after being triggered, type 1 does not.
                    /// @todo This is activation radius. Casting radius must be selected from spell data.
                    float radius = goInfo->trap.radius / 2.f; // this division seems to date back to when the field was called diameter, don't think it is still relevant.
                    if (!radius)
                        break;

                    // Pointer to appropriate target if found any
                    Unit* target = nullptr;

                    if (GetOwner() || goInfo->trap.Checkallunits)
                    {
                        // Hunter trap: Search units which are unfriendly to the trap's owner
                        Trinity::NearestAttackableNoTotemUnitInObjectRangeCheck checker(this, radius);
                        Trinity::UnitLastSearcher<Trinity::NearestAttackableNoTotemUnitInObjectRangeCheck> searcher(this, target, checker);
                        Cell::VisitAllObjects(this, searcher, radius);
                    }
                    else
                    {
                        // Environmental trap: Any player
                        Player* player = nullptr;
                        Trinity::AnyPlayerInObjectRangeCheck checker(this, radius);
                        Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(this, player, checker);
                        Cell::VisitWorldObjects(this, searcher, radius);
                        target = player;
                    }

                    if (target)
                        SetLootState(GO_ACTIVATED, target);

                }
                else if (goInfo->type == GAMEOBJECT_TYPE_CAPTURE_POINT)
                {
                    bool hordeCapturing = m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::ContestedHorde;
                    bool allianceCapturing = m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::ContestedAlliance;
                    if (hordeCapturing || allianceCapturing)
                    {
                        if (m_goValue.CapturePoint.AssaultTimer <= diff)
                        {
                            m_goValue.CapturePoint.State = hordeCapturing ? WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured : WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured;
                            if (hordeCapturing)
                            {
                                m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured;
                                if (BattlegroundMap* map = GetMap()->ToBattlegroundMap())
                                {
                                    if (Battleground* bg = map->GetBG())
                                    {
                                        if (goInfo->capturePoint.CaptureEventHorde)
                                            GameEvents::Trigger(goInfo->capturePoint.CaptureEventHorde, this, this);
                                        bg->SendBroadcastText(goInfo->capturePoint.CaptureBroadcastHorde, CHAT_MSG_BG_SYSTEM_HORDE);
                                    }
                                }
                            }
                            else
                            {
                                m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured;
                                if (BattlegroundMap* map = GetMap()->ToBattlegroundMap())
                                {
                                    if (Battleground* bg = map->GetBG())
                                    {
                                        if (goInfo->capturePoint.CaptureEventAlliance)
                                            GameEvents::Trigger(goInfo->capturePoint.CaptureEventAlliance, this, this);
                                        bg->SendBroadcastText(goInfo->capturePoint.CaptureBroadcastAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE);
                                    }
                                }
                            }

                            m_goValue.CapturePoint.LastTeamCapture = hordeCapturing ? TEAM_HORDE : TEAM_ALLIANCE;
                            UpdateCapturePoint();
                        }
                        else
                            m_goValue.CapturePoint.AssaultTimer -= diff;
                    }
                }
                else if (uint32 max_charges = goInfo->GetCharges())
                {
                    if (m_usetimes >= max_charges)
                    {
                        m_usetimes = 0;
                        SetLootState(GO_JUST_DEACTIVATED);      // can be despawned or destroyed
                    }
                }
            }

            break;
        }
        case GO_ACTIVATED:
        {
            switch (GetGoType())
            {
                case GAMEOBJECT_TYPE_DOOR:
                case GAMEOBJECT_TYPE_BUTTON:
                    if (m_cooldownTime && GameTime::GetGameTimeMS() >= m_cooldownTime)
                        ResetDoorOrButton();
                    break;
                case GAMEOBJECT_TYPE_GOOBER:
                    if (GameTime::GetGameTimeMS() >= m_cooldownTime)
                    {
                        RemoveFlag(GO_FLAG_IN_USE);

                        SetLootState(GO_JUST_DEACTIVATED);
                        m_cooldownTime = 0;
                    }
                    break;
                case GAMEOBJECT_TYPE_CHEST:
                    if (m_loot)
                    {
                        m_loot->Update();

                        // Non-consumable chest was partially looted and restock time passed, restock all loot now
                        if (GetGOInfo()->chest.consumable == 0 && m_restockTime && GameTime::GetGameTime() >= m_restockTime)
                        {
                            m_restockTime = 0;
                            m_lootState = GO_READY;
                            ClearLoot();
                            UpdateDynamicFlagsForNearbyPlayers();
                        }
                    }

                    for (auto&& [playerOwner, loot] : m_personalLoot)
                        loot->Update();
                    break;
                case GAMEOBJECT_TYPE_TRAP:
                {
                    GameObjectTemplate const* goInfo = GetGOInfo();
                    if (goInfo->trap.charges == 2 && goInfo->trap.spell)
                    {
                        /// @todo nullptr target won't work for target type 1
                        CastSpell(nullptr, goInfo->trap.spell);
                        SetLootState(GO_JUST_DEACTIVATED);
                    }
                    else if (Unit* target = ObjectAccessor::GetUnit(*this, m_lootStateUnitGUID))
                    {
                        // Some traps do not have a spell but should be triggered
                        CastSpellExtraArgs args;
                        args.SetOriginalCaster(GetOwnerGUID());
                        if (goInfo->trap.spell)
                            CastSpell(target, goInfo->trap.spell, args);

                        // Template value or 4 seconds
                        m_cooldownTime = GameTime::GetGameTimeMS() + (goInfo->trap.cooldown ? goInfo->trap.cooldown : uint32(4)) * IN_MILLISECONDS;

                        if (goInfo->trap.charges == 1)
                            SetLootState(GO_JUST_DEACTIVATED);
                        else if (!goInfo->trap.charges)
                            SetLootState(GO_READY);
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case GO_JUST_DEACTIVATED:
        {
            // If nearby linked trap exists, despawn it
            if (GameObject* linkedTrap = GetLinkedTrap())
                linkedTrap->DespawnOrUnsummon();

            //if Gameobject should cast spell, then this, but some GOs (type = 10) should be destroyed
            if (GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            {
                uint32 spellId = GetGOInfo()->goober.spell;

                if (spellId)
                {
                    for (GuidSet::const_iterator it = m_unique_users.begin(); it != m_unique_users.end(); ++it)
                        // m_unique_users can contain only player GUIDs
                        if (Player* owner = ObjectAccessor::GetPlayer(*this, *it))
                            owner->CastSpell(owner, spellId, false);

                    m_unique_users.clear();
                    m_usetimes = 0;
                }

                // Only goobers with a lock id or a reset time may reset their go state
                if (GetGOInfo()->GetLockId() || GetGOInfo()->GetAutoCloseTime())
                    SetGoState(GO_STATE_READY);

                //any return here in case battleground traps
                if (GameObjectOverride const* goOverride = GetGameObjectOverride())
                    if (goOverride->Flags & GO_FLAG_NODESPAWN)
                        return;
            }

            ClearLoot();

            // Do not delete chests or goobers that are not consumed on loot, while still allowing them to despawn when they expire if summoned
            bool isSummonedAndExpired = (GetOwner() || GetSpellId()) && m_respawnTime == 0;
            if ((GetGoType() == GAMEOBJECT_TYPE_CHEST || GetGoType() == GAMEOBJECT_TYPE_GOOBER) && !GetGOInfo()->IsDespawnAtAction() && !isSummonedAndExpired)
            {
                if (GetGoType() == GAMEOBJECT_TYPE_CHEST && GetGOInfo()->chest.chestRestockTime > 0)
                {
                    // Start restock timer when the chest is fully looted
                    m_restockTime = GameTime::GetGameTime() + GetGOInfo()->chest.chestRestockTime;
                    SetLootState(GO_NOT_READY);
                    UpdateDynamicFlagsForNearbyPlayers();
                }
                else
                    SetLootState(GO_READY);
                UpdateObjectVisibility();
                return;
            }
            else if (!GetOwnerGUID().IsEmpty() || GetSpellId())
            {
                SetRespawnTime(0);

                if (GetGoType() == GAMEOBJECT_TYPE_NEW_FLAG_DROP)
                {
                    if (GameObject* go = GetMap()->GetGameObject(GetOwnerGUID()))
                        go->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::InBase, nullptr));
                }

                Delete();
                return;
            }

            SetLootState(GO_NOT_READY);

            //burning flags in some battlegrounds, if you find better condition, just add it
            if (GetGOInfo()->IsDespawnAtAction() || GetGoAnimProgress() > 0)
            {
                SendGameObjectDespawn();
                //reset flags
                if (GameObjectOverride const* goOverride = GetGameObjectOverride())
                    ReplaceAllFlags(GameObjectFlags(goOverride->Flags));
            }

            if (!m_respawnDelayTime)
                return;

            if (!m_spawnedByDefault)
            {
                m_respawnTime = 0;

                if (m_spawnId)
                    UpdateObjectVisibilityOnDestroy();
                else
                    Delete();

                return;
            }

            uint32 respawnDelay = m_respawnDelayTime;
            if (uint32 scalingMode = sWorld->getIntConfig(CONFIG_RESPAWN_DYNAMICMODE))
                GetMap()->ApplyDynamicModeRespawnScaling(this, this->m_spawnId, respawnDelay, scalingMode);
            m_respawnTime = GameTime::GetGameTime() + respawnDelay;

            // if option not set then object will be saved at grid unload
            // Otherwise just save respawn time to map object memory
            SaveRespawnTime();

            if (m_respawnCompatibilityMode)
                UpdateObjectVisibilityOnDestroy();
            else
                AddObjectToRemoveList();

            break;
        }
    }
}

GameObjectOverride const* GameObject::GetGameObjectOverride() const
{
    if (m_spawnId)
    {
        if (GameObjectOverride const* goOverride = sObjectMgr->GetGameObjectOverride(m_spawnId))
            return goOverride;
    }

    return m_goTemplateAddon;
}

void GameObject::Refresh()
{
    // Do not refresh despawned GO from spellcast (GO's from spellcast are destroyed after despawn)
    if (m_respawnTime > 0 && m_spawnedByDefault)
        return;

    if (isSpawned())
        GetMap()->AddToMap(this);
}

void GameObject::AddUniqueUse(Player* player)
{
    AddUse();
    m_unique_users.insert(player->GetGUID());
}

void GameObject::DespawnOrUnsummon(Milliseconds delay, Seconds forceRespawnTime)
{
    if (delay > 0ms)
    {
        if (!m_despawnDelay || m_despawnDelay > delay.count())
        {
            m_despawnDelay = delay.count();
            m_despawnRespawnTime = forceRespawnTime;
        }
    }
    else
    {
        if (m_goData)
        {
            uint32 const respawnDelay = (forceRespawnTime > 0s) ? forceRespawnTime.count() : m_goData->spawntimesecs;
            SaveRespawnTime(respawnDelay);
        }
        Delete();
    }
}

void GameObject::DespawnForPlayer(Player* seer, Seconds respawnTime)
{
    PerPlayerState& perPlayerState = GetOrCreatePerPlayerStates()[seer->GetGUID()];
    perPlayerState.ValidUntil = GameTime::GetSystemTime() + respawnTime;
    perPlayerState.Despawned = true;
    seer->UpdateVisibilityOf(this);
}

void GameObject::Delete()
{
    SetLootState(GO_NOT_READY);
    RemoveFromOwner();

    if (m_goInfo->type == GAMEOBJECT_TYPE_CAPTURE_POINT)
    {
        WorldPackets::Battleground::CapturePointRemoved packet(GetGUID());
        SendMessageToSet(packet.Write(), true);
    }

    SendGameObjectDespawn();

    if (m_goInfo->type != GAMEOBJECT_TYPE_TRANSPORT)
        SetGoState(GO_STATE_READY);

    if (GameObjectOverride const* goOverride = GetGameObjectOverride())
        ReplaceAllFlags(GameObjectFlags(goOverride->Flags));

    uint32 poolid = GetGameObjectData() ? GetGameObjectData()->poolId : 0;
    if (m_respawnCompatibilityMode && poolid)
        sPoolMgr->UpdatePool<GameObject>(GetMap()->GetPoolData(), poolid, GetSpawnId());
    else
        AddObjectToRemoveList();
}

void GameObject::SendGameObjectDespawn()
{
    WorldPackets::GameObject::GameObjectDespawn packet;
    packet.ObjectGUID = GetGUID();
    SendMessageToSet(packet.Write(), true);
}

Loot* GameObject::GetFishLoot(Player* lootOwner)
{
    uint32 defaultzone = 1;

    Loot* fishLoot = new Loot(GetMap(), GetGUID(), LOOT_FISHING, nullptr);

    uint32 areaId = GetAreaId();
    while (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId))
    {
        fishLoot->FillLoot(areaId, LootTemplates_Fishing, lootOwner, true, true, LOOT_MODE_DEFAULT);
        if (!fishLoot->isLooted())
            break;

        areaId = areaEntry->ParentAreaID;
    }

    if (fishLoot->isLooted())
        fishLoot->FillLoot(defaultzone, LootTemplates_Fishing, lootOwner, true, true, LOOT_MODE_DEFAULT);

    return fishLoot;
}

Loot* GameObject::GetFishLootJunk(Player* lootOwner)
{
    uint32 defaultzone = 1;

    Loot* fishLoot = new Loot(GetMap(), GetGUID(), LOOT_FISHING_JUNK, nullptr);

    uint32 areaId = GetAreaId();
    while (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId))
    {
        fishLoot->FillLoot(areaId, LootTemplates_Fishing, lootOwner, true, true, LOOT_MODE_JUNK_FISH);
        if (!fishLoot->isLooted())
            break;

        areaId = areaEntry->ParentAreaID;
    }

    if (fishLoot->isLooted())
        fishLoot->FillLoot(defaultzone, LootTemplates_Fishing, lootOwner, true, true, LOOT_MODE_JUNK_FISH);

    return fishLoot;
}

void GameObject::SaveToDB()
{
    // this should only be used when the gameobject has already been loaded
    // preferably after adding to map, because mapid may not be valid otherwise
    GameObjectData const* data = sObjectMgr->GetGameObjectData(m_spawnId);
    if (!data)
    {
        TC_LOG_ERROR("misc", "GameObject::SaveToDB failed, cannot get gameobject data!");
        return;
    }

    uint32 mapId = GetMapId();
    if (TransportBase* transport = GetTransport())
        if (transport->GetMapIdForSpawning() >= 0)
            mapId = transport->GetMapIdForSpawning();

    SaveToDB(mapId, data->spawnDifficulties);
}

void GameObject::SaveToDB(uint32 mapid, std::vector<Difficulty> const& spawnDifficulties)
{
    GameObjectTemplate const* goI = GetGOInfo();
    if (!goI)
        return;

    if (!m_spawnId)
        m_spawnId = sObjectMgr->GenerateGameObjectSpawnId();

    // update in loaded data (changing data only in this place)
    GameObjectData& data = sObjectMgr->NewOrExistGameObjectData(m_spawnId);

    if (!data.spawnId)
        data.spawnId = m_spawnId;
    ASSERT(data.spawnId == m_spawnId);
    data.id = GetEntry();
    data.mapId = GetMapId();
    data.spawnPoint.Relocate(this);
    data.rotation = m_localRotation;
    data.spawntimesecs = m_spawnedByDefault ? m_respawnDelayTime : -(int32)m_respawnDelayTime;
    data.animprogress = GetGoAnimProgress();
    data.goState = GetGoState();
    data.spawnDifficulties = spawnDifficulties;
    data.artKit = GetGoArtKit();
    if (!data.spawnGroupData)
        data.spawnGroupData = sObjectMgr->GetDefaultSpawnGroup();

    data.phaseId = GetDBPhase() > 0 ? GetDBPhase() : data.phaseId;
    data.phaseGroup = GetDBPhase() < 0 ? -GetDBPhase() : data.phaseGroup;

    // Update in DB
    WorldDatabaseTransaction trans = WorldDatabase.BeginTransaction();

    uint8 index = 0;

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAMEOBJECT);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GAMEOBJECT);
    stmt->setUInt64(index++, m_spawnId);
    stmt->setUInt32(index++, GetEntry());
    stmt->setUInt16(index++, uint16(mapid));
    stmt->setString(index++, [&data]() -> std::string
    {
        if (data.spawnDifficulties.empty())
            return "";

        std::ostringstream os;
        auto itr = data.spawnDifficulties.begin();
        os << int32(*itr++);

        for (; itr != data.spawnDifficulties.end(); ++itr)
            os << ',' << int32(*itr);

        return os.str();
    }());
    stmt->setUInt32(index++, data.phaseId);
    stmt->setUInt32(index++, data.phaseGroup);
    stmt->setFloat(index++, GetPositionX());
    stmt->setFloat(index++, GetPositionY());
    stmt->setFloat(index++, GetPositionZ());
    stmt->setFloat(index++, GetOrientation());
    stmt->setFloat(index++, m_localRotation.x);
    stmt->setFloat(index++, m_localRotation.y);
    stmt->setFloat(index++, m_localRotation.z);
    stmt->setFloat(index++, m_localRotation.w);
    stmt->setInt32(index++, int32(m_respawnDelayTime));
    stmt->setUInt8(index++, GetGoAnimProgress());
    stmt->setUInt8(index++, uint8(GetGoState()));
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);
}

bool GameObject::LoadFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool)
{
    GameObjectData const* data = sObjectMgr->GetGameObjectData(spawnId);
    if (!data)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (GUID: {}) not found in table `gameobject`, can't load. ", spawnId);
        return false;
    }

    uint32 entry = data->id;
    //uint32 map_id = data->mapid;                          // already used before call

    uint32 animprogress = data->animprogress;
    GOState go_state = data->goState;
    uint32 artKit = data->artKit;

    m_spawnId = spawnId;
    m_respawnCompatibilityMode = ((data->spawnGroupData->flags & SPAWNGROUP_FLAG_COMPATIBILITY_MODE) != 0);
    if (!Create(entry, map, data->spawnPoint, data->rotation, animprogress, go_state, artKit, !m_respawnCompatibilityMode, spawnId))
        return false;

    PhasingHandler::InitDbPhaseShift(GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
    PhasingHandler::InitDbVisibleMapId(GetPhaseShift(), data->terrainSwapMap);

    if (data->spawntimesecs >= 0)
    {
        m_spawnedByDefault = true;

        if (!GetGOInfo()->GetDespawnPossibility() && !GetGOInfo()->IsDespawnAtAction())
        {
            SetFlag(GO_FLAG_NODESPAWN);
            m_respawnDelayTime = 0;
            m_respawnTime = 0;
        }
        else
        {
            m_respawnDelayTime = data->spawntimesecs;
            m_respawnTime = GetMap()->GetGORespawnTime(m_spawnId);

            // ready to respawn
            if (m_respawnTime && m_respawnTime <= GameTime::GetGameTime())
            {
                m_respawnTime = 0;
                GetMap()->RemoveRespawnTime(SPAWN_TYPE_GAMEOBJECT, m_spawnId);
            }
        }
    }
    else
    {
        if (!m_respawnCompatibilityMode)
        {
            TC_LOG_WARN("sql.sql", "GameObject {} (SpawnID {}) is not spawned by default, but tries to use a non-hack spawn system. This will not work. Defaulting to compatibility mode.", entry, spawnId);
            m_respawnCompatibilityMode = true;
        }

        m_spawnedByDefault = false;
        m_respawnDelayTime = -data->spawntimesecs;
        m_respawnTime = 0;
    }

    m_goData = data;

    m_stringIds[1] = data->StringId;

    if (addToMap && !GetMap()->AddToMap(this))
        return false;

    return true;
}

/*static*/ bool GameObject::DeleteFromDB(ObjectGuid::LowType spawnId)
{
    GameObjectData const* data = sObjectMgr->GetGameObjectData(spawnId);
    if (!data)
        return false;

    CharacterDatabaseTransaction charTrans = CharacterDatabase.BeginTransaction();

    sMapMgr->DoForAllMapsWithMapId(data->mapId,
        [spawnId, charTrans](Map* map) -> void
        {
            // despawn all active objects, and remove their respawns
            std::vector<GameObject*> toUnload;
            for (auto const& pair : Trinity::Containers::MapEqualRange(map->GetGameObjectBySpawnIdStore(), spawnId))
                toUnload.push_back(pair.second);
            for (GameObject* obj : toUnload)
                map->AddObjectToRemoveList(obj);
            map->RemoveRespawnTime(SPAWN_TYPE_GAMEOBJECT, spawnId, charTrans);
        }
    );

    // delete data from memory
    sObjectMgr->DeleteGameObjectData(spawnId);

    CharacterDatabase.CommitTransaction(charTrans);

    WorldDatabaseTransaction trans = WorldDatabase.BeginTransaction();

    // ... and the database
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAMEOBJECT);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_SPAWNGROUP_MEMBER);
    stmt->setUInt8(0, uint8(SPAWN_TYPE_GAMEOBJECT));
    stmt->setUInt64(1, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_EVENT_GAMEOBJECT);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_GO_TO_GO);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_GO_TO_CREATURE);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN_MASTER);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_GO_TO_GO);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN_MASTER);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_CREATURE_TO_GO);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAMEOBJECT_ADDON);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);

    return true;
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/
bool GameObject::hasQuest(uint32 quest_id) const
{
    return sObjectMgr->GetGOQuestRelations(GetEntry()).HasQuest(quest_id);
}

bool GameObject::hasInvolvedQuest(uint32 quest_id) const
{
    return sObjectMgr->GetGOQuestInvolvedRelations(GetEntry()).HasQuest(quest_id);
}

bool GameObject::IsTransport() const
{
    // If something is marked as a transport, don't transmit an out of range packet for it.
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_TRANSPORT || gInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT;
}

// is Dynamic transport = non-stop Transport
bool GameObject::IsDynTransport() const
{
    // If something is marked as a transport, don't transmit an out of range packet for it.
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT || gInfo->type == GAMEOBJECT_TYPE_TRANSPORT;
}

bool GameObject::IsDestructibleBuilding() const
{
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING;
}

void GameObject::SaveRespawnTime(uint32 forceDelay)
{
    if (m_goData && (forceDelay || m_respawnTime > GameTime::GetGameTime()) && m_spawnedByDefault)
    {
        if (m_respawnCompatibilityMode)
        {
            RespawnInfo ri;
            ri.type = SPAWN_TYPE_GAMEOBJECT;
            ri.spawnId = m_spawnId;
            ri.respawnTime = m_respawnTime;
            GetMap()->SaveRespawnInfoDB(ri);
            return;
        }

        uint32 thisRespawnTime = forceDelay ? GameTime::GetGameTime() + forceDelay : m_respawnTime;
        GetMap()->SaveRespawnTime(SPAWN_TYPE_GAMEOBJECT, m_spawnId, GetEntry(), thisRespawnTime, Trinity::ComputeGridCoord(GetPositionX(), GetPositionY()).GetId());
    }
}

bool GameObject::IsNeverVisibleFor(WorldObject const* seer, bool allowServersideObjects) const
{
    if (WorldObject::IsNeverVisibleFor(seer))
        return true;

    if (GetGOInfo()->GetServerOnly() && !allowServersideObjects)
        return true;

    if (!GetDisplayId() && GetGOInfo()->IsDisplayMandatory())
        return true;

    if (m_goTypeImpl)
        return m_goTypeImpl->IsNeverVisibleFor(seer, allowServersideObjects);

    return false;
}

bool GameObject::IsAlwaysVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::IsAlwaysVisibleFor(seer))
        return true;

    if (IsTransport() || IsDestructibleBuilding())
        return true;

    if (!seer)
        return false;

    // Always seen by owner and friendly units
    if (!GetOwnerGUID().IsEmpty())
    {
        if (seer->GetGUID() == GetOwnerGUID())
            return true;

        Unit* owner = GetOwner();
        if (Unit const* unitSeer = seer->ToUnit())
            if (owner && owner->IsFriendlyTo(unitSeer))
                return true;
    }

    return false;
}

bool GameObject::IsInvisibleDueToDespawn(WorldObject const* seer) const
{
    if (WorldObject::IsInvisibleDueToDespawn(seer))
        return true;

    // Despawned
    if (!isSpawned())
        return true;

    if (m_perPlayerState)
        if (PerPlayerState const* state = Trinity::Containers::MapGetValuePtr(*m_perPlayerState, seer->GetGUID()))
            if (state->Despawned)
                return true;

    return false;
}

uint8 GameObject::GetLevelForTarget(WorldObject const* target) const
{
    if (Unit* owner = GetOwner())
        return owner->GetLevelForTarget(target);

    if (GetGoType() == GAMEOBJECT_TYPE_TRAP)
    {
        if (Player const* player = target->ToPlayer())
            if (Optional<ContentTuningLevels> userLevels = sDB2Manager.GetContentTuningData(GetGOInfo()->ContentTuningId))
                return uint8(std::clamp<int16>(player->GetLevel(), userLevels->MinLevel, userLevels->MaxLevel));

        if (Unit const* targetUnit = target->ToUnit())
            return targetUnit->GetLevel();
    }

    return 1;
}

time_t GameObject::GetRespawnTimeEx() const
{
    time_t now = GameTime::GetGameTime();
    if (m_respawnTime > now)
        return m_respawnTime;
    else
        return now;
}

void GameObject::SetRespawnTime(int32 respawn)
{
    m_respawnTime = respawn > 0 ? GameTime::GetGameTime() + respawn : 0;
    m_respawnDelayTime = respawn > 0 ? respawn : 0;
    if (respawn && !m_spawnedByDefault)
        UpdateObjectVisibility(true);
}

void GameObject::Respawn()
{
    if (m_spawnedByDefault && m_respawnTime > 0)
    {
        m_respawnTime = GameTime::GetGameTime();
        GetMap()->Respawn(SPAWN_TYPE_GAMEOBJECT, m_spawnId);
    }
}

bool GameObject::ActivateToQuest(Player const* target) const
{
    if (target->HasQuestForGO(GetEntry()))
        return true;

    if (!sObjectMgr->IsGameObjectForQuests(GetEntry()))
        return false;

    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_QUESTGIVER:
        {
            GameObject* go = const_cast<GameObject*>(this);
            QuestGiverStatus questStatus = const_cast<Player*>(target)->GetQuestDialogStatus(go);
            if (questStatus != QuestGiverStatus::None && questStatus != QuestGiverStatus::Future)
                return true;
            break;
        }
        case GAMEOBJECT_TYPE_CHEST:
        {
            // Chests become inactive while not ready to be looted
            if (getLootState() == GO_NOT_READY)
                return false;

            // scan GO chest with loot including quest items
            if (target->GetQuestStatus(GetGOInfo()->chest.questID) == QUEST_STATUS_INCOMPLETE
                || LootTemplates_Gameobject.HaveQuestLootForPlayer(GetGOInfo()->chest.chestLoot, target)
                || LootTemplates_Gameobject.HaveQuestLootForPlayer(GetGOInfo()->chest.chestPersonalLoot, target)
                || LootTemplates_Gameobject.HaveQuestLootForPlayer(GetGOInfo()->chest.chestPushLoot, target))
            {
                if (Battleground const* bg = target->GetBattleground())
                    return bg->CanActivateGO(GetEntry(), bg->GetPlayerTeam(target->GetGUID()));
                return true;
            }
            break;
        }
        case GAMEOBJECT_TYPE_GENERIC:
        {
            if (target->GetQuestStatus(GetGOInfo()->generic.questID) == QUEST_STATUS_INCOMPLETE)
                return true;
            break;
        }
        case GAMEOBJECT_TYPE_GOOBER:
        {
            if (target->GetQuestStatus(GetGOInfo()->goober.questID) == QUEST_STATUS_INCOMPLETE)
                return true;
            break;
        }
        default:
            break;
    }

    return false;
}

void GameObject::TriggeringLinkedGameObject(uint32 trapEntry, Unit* target)
{
    GameObjectTemplate const* trapInfo = sObjectMgr->GetGameObjectTemplate(trapEntry);
    if (!trapInfo || trapInfo->type != GAMEOBJECT_TYPE_TRAP)
        return;

    SpellInfo const* trapSpell = sSpellMgr->GetSpellInfo(trapInfo->trap.spell, GetMap()->GetDifficultyID());
    if (!trapSpell)                                          // checked at load already
        return;

    if (GameObject* trapGO = GetLinkedTrap())
        trapGO->CastSpell(target, trapSpell->Id);
}

GameObject* GameObject::LookupFishingHoleAround(float range)
{
    GameObject* ok = nullptr;
    Trinity::NearestGameObjectFishingHole u_check(*this, range);
    Trinity::GameObjectSearcher<Trinity::NearestGameObjectFishingHole> checker(this, ok, u_check);
    Cell::VisitGridObjects(this, checker, range);
    return ok;
}

void GameObject::ResetDoorOrButton()
{
    if (m_lootState == GO_READY || m_lootState == GO_JUST_DEACTIVATED)
        return;

    RemoveFlag(GO_FLAG_IN_USE);
    SetGoState(m_prevGoState);

    SetLootState(GO_JUST_DEACTIVATED);
    m_cooldownTime = 0;
}

void GameObject::UseDoorOrButton(uint32 time_to_restore, bool alternative /* = false */, Unit* user /*=nullptr*/)
{
    if (m_lootState != GO_READY)
        return;

    if (!time_to_restore)
        time_to_restore = GetGOInfo()->GetAutoCloseTime();

    SwitchDoorOrButton(true, alternative);
    SetLootState(GO_ACTIVATED, user);

    m_cooldownTime = time_to_restore ? (GameTime::GetGameTimeMS() + time_to_restore) : 0;
}

void GameObject::ActivateObject(GameObjectActions action, int32 param, WorldObject* spellCaster /*= nullptr*/, uint32 spellId /*= 0*/, int32 effectIndex /*= -1*/)
{
    Unit* unitCaster = spellCaster ? spellCaster->ToUnit() : nullptr;

    switch (action)
    {
        case GameObjectActions::None:
            TC_LOG_FATAL("spell", "Spell {} has action type NONE in effect {}", spellId, effectIndex);
            break;
        case GameObjectActions::AnimateCustom0:
        case GameObjectActions::AnimateCustom1:
        case GameObjectActions::AnimateCustom2:
        case GameObjectActions::AnimateCustom3:
            SendCustomAnim(uint32(action) - uint32(GameObjectActions::AnimateCustom0));
            break;
        case GameObjectActions::Disturb: // What's the difference with Open?
            if (unitCaster)
                Use(unitCaster);
            break;
        case GameObjectActions::Unlock:
            RemoveFlag(GO_FLAG_LOCKED);
            break;
        case GameObjectActions::Lock:
            SetFlag(GO_FLAG_LOCKED);
            break;
        case GameObjectActions::Open:
            if (unitCaster)
                Use(unitCaster);
            break;
        case GameObjectActions::OpenAndUnlock:
            if (unitCaster)
                UseDoorOrButton(0, false, unitCaster);
            RemoveFlag(GO_FLAG_LOCKED);
            break;
        case GameObjectActions::Close:
            ResetDoorOrButton();
            break;
        case GameObjectActions::ToggleOpen:
            // No use cases, implementation unknown
            break;
        case GameObjectActions::Destroy:
            if (unitCaster)
                UseDoorOrButton(0, true, unitCaster);
            break;
        case GameObjectActions::Rebuild:
            ResetDoorOrButton();
            break;
        case GameObjectActions::Creation:
            // No use cases, implementation unknown
            break;
        case GameObjectActions::Despawn:
            DespawnOrUnsummon();
            break;
        case GameObjectActions::MakeInert:
            SetFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GameObjectActions::MakeActive:
            RemoveFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GameObjectActions::CloseAndLock:
            ResetDoorOrButton();
            SetFlag(GO_FLAG_LOCKED);
            break;
        case GameObjectActions::UseArtKit0:
        case GameObjectActions::UseArtKit1:
        case GameObjectActions::UseArtKit2:
        case GameObjectActions::UseArtKit3:
        case GameObjectActions::UseArtKit4:
        {
            GameObjectTemplateAddon const* templateAddon = GetTemplateAddon();

            uint32 artKitIndex = action != GameObjectActions::UseArtKit4 ? uint32(action) - uint32(GameObjectActions::UseArtKit0) : 4;

            uint32 artKitValue = 0;
            if (templateAddon != nullptr)
                artKitValue = templateAddon->ArtKits[artKitIndex];

            if (artKitValue == 0)
                TC_LOG_ERROR("sql.sql", "GameObject {} hit by spell {} needs `artkit{}` in `gameobject_template_addon`", GetEntry(), spellId, artKitIndex);
            else
                SetGoArtKit(artKitValue);

            break;
        }
        case GameObjectActions::GoTo1stFloor:
        case GameObjectActions::GoTo2ndFloor:
        case GameObjectActions::GoTo3rdFloor:
        case GameObjectActions::GoTo4thFloor:
        case GameObjectActions::GoTo5thFloor:
        case GameObjectActions::GoTo6thFloor:
        case GameObjectActions::GoTo7thFloor:
        case GameObjectActions::GoTo8thFloor:
        case GameObjectActions::GoTo9thFloor:
        case GameObjectActions::GoTo10thFloor:
            static_assert(int32(GO_STATE_TRANSPORT_ACTIVE) == int32(GameObjectActions::GoTo1stFloor));
            if (GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
                SetGoState(GOState(action));
            else
                TC_LOG_ERROR("spell", "Spell {} targeted non-transport gameobject for transport only action \"Go to Floor\" {} in effect {}", spellId, int32(action), effectIndex);
            break;
        case GameObjectActions::PlayAnimKit:
            SetAnimKitId(param, false);
            break;
        case GameObjectActions::OpenAndPlayAnimKit:
            if (unitCaster)
                UseDoorOrButton(0, false, unitCaster);
            SetAnimKitId(param, false);
            break;
        case GameObjectActions::CloseAndPlayAnimKit:
            ResetDoorOrButton();
            SetAnimKitId(param, false);
            break;
        case GameObjectActions::PlayOneShotAnimKit:
            SetAnimKitId(param, true);
            break;
        case GameObjectActions::StopAnimKit:
            SetAnimKitId(0, false);
            break;
        case GameObjectActions::OpenAndStopAnimKit:
            if (unitCaster)
                UseDoorOrButton(0, false, unitCaster);
            SetAnimKitId(0, false);
            break;
        case GameObjectActions::CloseAndStopAnimKit:
            ResetDoorOrButton();
            SetAnimKitId(0, false);
            break;
        case GameObjectActions::PlaySpellVisual:
            SetSpellVisualId(param, Object::GetGUID(spellCaster));
            break;
        case GameObjectActions::StopSpellVisual:
            SetSpellVisualId(0);
            break;
        default:
            TC_LOG_ERROR("spell", "Spell {} has unhandled action {} in effect {}", spellId, int32(action), effectIndex);
            break;
    }

    // Apply side effects of type
    if (m_goTypeImpl)
        m_goTypeImpl->ActivateObject(action, param, spellCaster, spellId, effectIndex);
}

void GameObject::SetGoArtKit(uint32 kit)
{
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::ArtKit), kit);
    GameObjectData* data = const_cast<GameObjectData*>(sObjectMgr->GetGameObjectData(m_spawnId));
    if (data)
        data->artKit = kit;
}

void GameObject::SetGoArtKit(uint32 artkit, GameObject* go, ObjectGuid::LowType lowguid)
{
    GameObjectData const* data = nullptr;
    if (go)
    {
        go->SetGoArtKit(artkit);
        data = go->GetGameObjectData();
    }
    else if (lowguid)
        data = sObjectMgr->GetGameObjectData(lowguid);

    if (data)
        const_cast<GameObjectData*>(data)->artKit = artkit;
}

void GameObject::SwitchDoorOrButton(bool activate, bool alternative /* = false */)
{
    if (activate)
        SetFlag(GO_FLAG_IN_USE);
    else
        RemoveFlag(GO_FLAG_IN_USE);

    if (GetGoState() == GO_STATE_READY)                      //if closed -> open
        SetGoState(alternative ? GO_STATE_DESTROYED : GO_STATE_ACTIVE);
    else                                                    //if open -> close
        SetGoState(GO_STATE_READY);
}

void GameObject::Use(Unit* user)
{
    // by default spell caster is user
    Unit* spellCaster = user;
    uint32 spellId = 0;
    bool triggered = false;

    if (Player* playerUser = user->ToPlayer())
    {
        if (m_goInfo->GetNoDamageImmune() && playerUser->HasUnitFlag(UNIT_FLAG_IMMUNE))
            return;

        if (!m_goInfo->IsUsableMounted())
            playerUser->RemoveAurasByType(SPELL_AURA_MOUNTED);

        playerUser->PlayerTalkClass->ClearMenus();
        if (AI()->OnGossipHello(playerUser))
            return;
    }

    // If cooldown data present in template
    if (uint32 cooldown = GetGOInfo()->GetCooldown())
    {
        if (m_cooldownTime > GameTime::GetGameTime())
            return;

        m_cooldownTime = GameTime::GetGameTimeMS() + cooldown * IN_MILLISECONDS;
    }

    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_DOOR:                          //0
        case GAMEOBJECT_TYPE_BUTTON:                        //1
            //doors/buttons never really despawn, only reset to default state/flags
            UseDoorOrButton(0, false, user);
            return;
        case GAMEOBJECT_TYPE_QUESTGIVER:                    //2
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            player->PrepareGossipMenu(this, GetGOInfo()->questgiver.gossipID, true);
            player->SendPreparedGossip(this);
            return;
        }
        case GAMEOBJECT_TYPE_CHEST:                         //3
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            if (Battleground* bg = player->GetBattleground())
                if (!bg->CanActivateGO(GetEntry(), bg->GetPlayerTeam(user->GetGUID())))
                    return;

            GameObjectTemplate const* info = GetGOInfo();
            if (!m_loot && info->GetLootId())
            {
                if (info->GetLootId())
                {
                    Group const* group = player->GetGroup();
                    bool groupRules = group && info->chest.usegrouplootrules;

                    Loot* loot = new Loot(GetMap(), GetGUID(), LOOT_CHEST, groupRules ? group : nullptr);
                    m_loot.reset(loot);

                    loot->SetDungeonEncounterId(info->chest.DungeonEncounter);
                    loot->FillLoot(info->GetLootId(), LootTemplates_Gameobject, player, !groupRules, false, GetLootMode());

                    if (GetLootMode() > 0)
                        if (GameObjectTemplateAddon const* addon = GetTemplateAddon())
                            loot->generateMoneyLoot(addon->Mingold, addon->Maxgold);
                }

                if (info->chest.triggeredEvent)
                    GameEvents::Trigger(info->chest.triggeredEvent, player, this);

                // triggering linked GO
                if (uint32 trapEntry = info->chest.linkedTrap)
                    TriggeringLinkedGameObject(trapEntry, player);
            }
            else if (!m_personalLoot.count(player->GetGUID()))
            {
                if (info->chest.chestPersonalLoot)
                {
                    GameObjectTemplateAddon const* addon = GetTemplateAddon();
                    if (info->chest.DungeonEncounter)
                    {
                        std::vector<Player*> tappers;
                        for (ObjectGuid tapperGuid : GetTapList())
                            if (Player* tapper = ObjectAccessor::GetPlayer(*this, tapperGuid))
                                tappers.push_back(tapper);

                        if (tappers.empty())
                            tappers.push_back(player);

                        m_personalLoot = GenerateDungeonEncounterPersonalLoot(info->chest.DungeonEncounter, info->chest.chestPersonalLoot,
                            LootTemplates_Gameobject, LOOT_CHEST, this, addon ? addon->Mingold : 0, addon ? addon->Maxgold : 0,
                            GetLootMode(), GetMap()->GetMapDifficulty(), tappers);
                    }
                    else
                    {
                        Loot* loot = new Loot(GetMap(), GetGUID(), LOOT_CHEST, nullptr);
                        m_personalLoot[player->GetGUID()].reset(loot);

                        loot->SetDungeonEncounterId(info->chest.DungeonEncounter);
                        loot->FillLoot(info->chest.chestPersonalLoot, LootTemplates_Gameobject, player, true, false, GetLootMode());

                        if (GetLootMode() > 0 && addon)
                            loot->generateMoneyLoot(addon->Mingold, addon->Maxgold);
                    }
                }
            }

            if (!m_unique_users.count(player->GetGUID()) && !info->GetLootId())
            {
                if (info->chest.chestPushLoot)
                {
                    Loot pushLoot(GetMap(), GetGUID(), LOOT_CHEST, nullptr);
                    pushLoot.FillLoot(info->chest.chestPushLoot, LootTemplates_Gameobject, player, true, false, GetLootMode());
                    pushLoot.AutoStore(player, NULL_BAG, NULL_SLOT);
                }

                if (info->chest.triggeredEvent)
                    GameEvents::Trigger(info->chest.triggeredEvent, player, this);

                // triggering linked GO
                if (uint32 trapEntry = info->chest.linkedTrap)
                    TriggeringLinkedGameObject(trapEntry, player);

                AddUniqueUse(player);
            }

            if (getLootState() != GO_ACTIVATED)
                SetLootState(GO_ACTIVATED, player);

            // Send loot
            if (Loot* loot = GetLootForPlayer(player))
                player->SendLoot(*loot);
            break;
        }
        case GAMEOBJECT_TYPE_TRAP:                          //6
        {
            GameObjectTemplate const* goInfo = GetGOInfo();
            if (goInfo->trap.spell)
                CastSpell(user, goInfo->trap.spell);

            m_cooldownTime = GameTime::GetGameTimeMS() + (goInfo->trap.cooldown ? goInfo->trap.cooldown :  uint32(4)) * IN_MILLISECONDS;   // template or 4 seconds

            if (goInfo->trap.charges == 1)         // Deactivate after trigger
                SetLootState(GO_JUST_DEACTIVATED);

            return;
        }
        //Sitting: Wooden bench, chairs enzz
        case GAMEOBJECT_TYPE_CHAIR:                         //7
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (ChairListSlots.empty())        // this is called once at first chair use to make list of available slots
            {
                if (info->chair.chairslots > 0)     // sometimes chairs in DB have error in fields and we dont know number of slots
                    for (uint32 i = 0; i < info->chair.chairslots; ++i)
                        ChairListSlots[i].Clear(); // Last user of current slot set to 0 (none sit here yet)
                else
                    ChairListSlots[0].Clear();     // error in DB, make one default slot
            }

            // a chair may have n slots. we have to calculate their positions and teleport the player to the nearest one

            float lowestDist = DEFAULT_VISIBILITY_DISTANCE;

            uint32 nearest_slot = 0;
            float x_lowest = GetPositionX();
            float y_lowest = GetPositionY();

            // the object orientation + 1/2 pi
            // every slot will be on that straight line
            float orthogonalOrientation = GetOrientation() + float(M_PI) * 0.5f;
            // find nearest slot
            bool found_free_slot = false;
            for (auto& [slot, sittingUnit] : ChairListSlots)
            {
                // the distance between this slot and the center of the go - imagine a 1D space
                float relativeDistance = (info->size * slot) - (info->size * (info->chair.chairslots - 1) / 2.0f);

                float x_i = GetPositionX() + relativeDistance * std::cos(orthogonalOrientation);
                float y_i = GetPositionY() + relativeDistance * std::sin(orthogonalOrientation);

                if (!sittingUnit.IsEmpty())
                {
                    if (Unit* chairUser = ObjectAccessor::GetUnit(*this, sittingUnit))
                    {
                        if (chairUser->IsSitState() && chairUser->GetStandState() != UNIT_STAND_STATE_SIT && chairUser->GetExactDist2d(x_i, y_i) < 0.1f)
                            continue;        // This seat is already occupied by ChairUser. NOTE: Not sure if the ChairUser->GetStandState() != UNIT_STAND_STATE_SIT check is required.

                        sittingUnit.Clear(); // This seat is unoccupied.
                    }
                    else
                        sittingUnit.Clear();     // The seat may of had an occupant, but they're offline.
                }

                found_free_slot = true;

                // calculate the distance between the player and this slot
                float thisDistance = user->GetDistance2d(x_i, y_i);

                if (thisDistance <= lowestDist)
                {
                    nearest_slot = slot;
                    lowestDist = thisDistance;
                    x_lowest = x_i;
                    y_lowest = y_i;
                }
            }

            if (found_free_slot)
            {
                auto itr = ChairListSlots.find(nearest_slot);
                if (itr != ChairListSlots.end())
                {
                    itr->second = user->GetGUID(); //this slot in now used by player
                    user->NearTeleportTo(x_lowest, y_lowest, GetPositionZ(), GetOrientation());
                    user->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + info->chair.chairheight));
                    if (info->chair.triggeredEvent)
                        GameEvents::Trigger(info->chair.triggeredEvent, user, this);
                    return;
                }
            }

            return;
        }
        case GAMEOBJECT_TYPE_SPELL_FOCUS:                   //8
            // triggering linked GO
            if (uint32 trapEntry = GetGOInfo()->spellFocus.linkedTrap)
                TriggeringLinkedGameObject(trapEntry, user);
            break;
        //big gun, its a spell/aura
        case GAMEOBJECT_TYPE_GOOBER:                        //10
        {
            GameObjectTemplate const* info = GetGOInfo();
            Player* player = user->ToPlayer();

            if (player)
            {
                if (info->goober.pageID)                    // show page...
                {
                    WorldPackets::GameObject::PageText data;
                    data.GameObjectGUID = GetGUID();
                    player->SendDirectMessage(data.Write());
                }
                else if (info->goober.gossipID)
                {
                    player->PrepareGossipMenu(this, info->goober.gossipID);
                    player->SendPreparedGossip(this);
                }

                if (info->goober.eventID)
                {
                    TC_LOG_DEBUG("maps.script", "Goober ScriptStart id {} for GO entry {} (GUID {}).", info->goober.eventID, GetEntry(), GetSpawnId());
                    GameEvents::Trigger(info->goober.eventID, player, this);
                }

                // possible quest objective for active quests
                if (info->goober.questID && sObjectMgr->GetQuestTemplate(info->goober.questID))
                {
                    //Quest require to be active for GO using
                    if (player->GetQuestStatus(info->goober.questID) != QUEST_STATUS_INCOMPLETE)
                        break;
                }

                if (Group* group = player->GetGroup())
                {
                    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                        if (Player* member = itr->GetSource())
                            if (member->IsAtGroupRewardDistance(this))
                                member->KillCreditGO(info->entry, GetGUID());
                }
                else
                    player->KillCreditGO(info->entry, GetGUID());
            }

            if (uint32 trapEntry = info->goober.linkedTrap)
                TriggeringLinkedGameObject(trapEntry, user);

            if (info->goober.AllowMultiInteract && player)
            {
                if (info->IsDespawnAtAction())
                    DespawnForPlayer(player, Seconds(m_respawnDelayTime));
                else
                    SetGoStateFor(GO_STATE_ACTIVE, player);
            }
            else
            {
                SetFlag(GO_FLAG_IN_USE);
                SetLootState(GO_ACTIVATED, user);

                // this appear to be ok, however others exist in addition to this that should have custom (ex: 190510, 188692, 187389)
                if (info->goober.customAnim)
                    SendCustomAnim(GetGoAnimProgress());
                else
                    SetGoState(GO_STATE_ACTIVE);

                m_cooldownTime = GameTime::GetGameTimeMS() + info->GetAutoCloseTime();
            }

            // cast this spell later if provided
            spellId = info->goober.spell;
            if (!info->goober.playerCast)
                spellCaster = nullptr;

            break;
        }
        case GAMEOBJECT_TYPE_CAMERA:                        //13
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (info->camera.camera)
                player->SendCinematicStart(info->camera.camera);

            if (info->camera.eventID)
                GameEvents::Trigger(info->camera.eventID, player, this);

            return;
        }
        //fishing bobber
        case GAMEOBJECT_TYPE_FISHINGNODE:                   //17
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            if (player->GetGUID() != GetOwnerGUID())
                return;

            switch (getLootState())
            {
                case GO_READY:                              // ready for loot
                {
                    SetLootState(GO_ACTIVATED, player);

                    SetGoState(GO_STATE_ACTIVE);
                    ReplaceAllFlags(GO_FLAG_IN_MULTI_USE);

                    SendUpdateToPlayer(player);

                    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(GetAreaId());
                    if (!areaEntry)
                    {
                        TC_LOG_ERROR("entities.gameobject", "Gameobject '{}' ({}) spawned in unknown area (x: {} y: {} z: {} map: {})",
                            GetEntry(), GetGUID().ToString(), GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId());
                        break;
                    }

                    // Update the correct fishing skill according to the area's ContentTuning
                    player->UpdateFishingSkill(0);

                    // Send loot
                    int32 areaFishingLevel = sObjectMgr->GetFishingBaseSkillLevel(areaEntry);

                    uint32 playerFishingSkill = player->GetProfessionSkillForExp(SKILL_FISHING, 0);
                    int32 playerFishingLevel = player->GetSkillValue(playerFishingSkill);

                    int32 roll = irand(1, 100);
                    int32 chance = 100;
                    if (playerFishingLevel < areaFishingLevel)
                    {
                        chance = int32(pow((double)playerFishingLevel / areaFishingLevel, 2) * 100);
                        if (chance < 1)
                            chance = 1;
                    }

                    TC_LOG_DEBUG("misc", "Fishing check (skill {} level: {} area skill level: {} chance {} roll: {}", playerFishingSkill, playerFishingLevel, areaFishingLevel, chance, roll);

                    /// @todo find reasonable value for fishing hole search
                    GameObject* fishingPool = LookupFishingHoleAround(20.0f + CONTACT_DISTANCE);

                    // If fishing skill is high enough, or if fishing on a pool, send correct loot.
                    // Fishing pools have no skill requirement as of patch 3.3.0 (undocumented change).
                    if (chance >= roll || fishingPool)
                    {
                        /// @todo I do not understand this hack. Need some explanation.
                        // prevent removing GO at spell cancel
                        RemoveFromOwner();
                        SetOwnerGUID(player->GetGUID());
                        SetSpellId(0); // prevent removing unintended auras at Unit::RemoveGameObject

                        if (fishingPool)
                        {
                            fishingPool->Use(player);
                            SetLootState(GO_JUST_DEACTIVATED);
                        }
                        else
                        {
                            m_loot.reset(GetFishLoot(player));
                            player->SendLoot(*m_loot);
                        }
                    }
                    else // If fishing skill is too low, send junk loot.
                    {
                        m_loot.reset(GetFishLootJunk(player));
                        player->SendLoot(*m_loot);
                    }
                    break;
                }
                case GO_JUST_DEACTIVATED:                   // nothing to do, will be deleted at next update
                    break;
                default:
                {
                    SetLootState(GO_JUST_DEACTIVATED);
                    player->SendDirectMessage(WorldPackets::GameObject::FishNotHooked().Write());
                    break;
                }
            }

            player->FinishSpell(CURRENT_CHANNELED_SPELL);
            return;
        }

        case GAMEOBJECT_TYPE_RITUAL:              //18
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            Unit* owner = GetOwner();

            GameObjectTemplate const* info = GetGOInfo();

            Player* m_ritualOwner = nullptr;
            if (!m_ritualOwnerGUID.IsEmpty())
                m_ritualOwner = ObjectAccessor::FindPlayer(m_ritualOwnerGUID);

            // ritual owner is set for GO's without owner (not summoned)
            if (!m_ritualOwner && !owner)
            {
                m_ritualOwnerGUID = player->GetGUID();
                m_ritualOwner = player;
            }

            if (owner)
            {
                if (owner->GetTypeId() != TYPEID_PLAYER)
                    return;

                // accept only use by player from same group as owner, excluding owner itself (unique use already added in spell effect)
                if (player == owner->ToPlayer() || (info->ritual.castersGrouped && !player->IsInSameRaidWith(owner->ToPlayer())))
                    return;

                // expect owner to already be channeling, so if not...
                if (!owner->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                    return;

                // in case summoning ritual caster is GO creator
                spellCaster = owner;
            }
            else
            {
                if (player != m_ritualOwner && (info->ritual.castersGrouped && !player->IsInSameRaidWith(m_ritualOwner)))
                    return;

                spellCaster = player;
            }

            AddUniqueUse(player);

            if (info->ritual.animSpell)
            {
                player->CastSpell(player, info->ritual.animSpell, true);

                // for this case, summoningRitual.spellId is always triggered
                triggered = true;
            }

            // full amount unique participants including original summoner
            if (GetUniqueUseCount() == info->ritual.casters)
            {
                if (m_ritualOwner)
                    spellCaster = m_ritualOwner;

                spellId = info->ritual.spell;

                if (spellId == 62330)                       // GO store nonexistent spell, replace by expected
                {
                    // spell have reagent and mana cost but it not expected use its
                    // it triggered spell in fact cast at currently channeled GO
                    spellId = 61993;
                    triggered = true;
                }

                // Cast casterTargetSpell at a random GO user
                // on the current DB there is only one gameobject that uses this (Ritual of Doom)
                // and its required target number is 1 (outter for loop will run once)
                if (info->ritual.casterTargetSpell && info->ritual.casterTargetSpell != 1) // No idea why this field is a bool in some cases
                    for (uint32 i = 0; i < info->ritual.casterTargetSpellTargets; i++)
                        // m_unique_users can contain only player GUIDs
                        if (Player* target = ObjectAccessor::GetPlayer(*this, Trinity::Containers::SelectRandomContainerElement(m_unique_users)))
                            spellCaster->CastSpell(target, info->ritual.casterTargetSpell, true);

                // finish owners spell
                if (owner)
                    owner->FinishSpell(CURRENT_CHANNELED_SPELL);

                // can be deleted now, if
                if (!info->ritual.ritualPersistent)
                    SetLootState(GO_JUST_DEACTIVATED);
                else
                {
                    // reset ritual for this GO
                    m_ritualOwnerGUID.Clear();
                    m_unique_users.clear();
                    m_usetimes = 0;
                }
            }
            else
                return;

            // go to end function to spell casting
            break;
        }
        case GAMEOBJECT_TYPE_SPELLCASTER:                   //22
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (info->spellCaster.partyOnly)
            {
                Unit* caster = GetOwner();
                if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (user->GetTypeId() != TYPEID_PLAYER || !user->ToPlayer()->IsInSameRaidWith(caster->ToPlayer()))
                    return;
            }

            user->RemoveAurasByType(SPELL_AURA_MOUNTED);
            spellId = info->spellCaster.spell;

            AddUse();
            break;
        }
        case GAMEOBJECT_TYPE_MEETINGSTONE:                  //23
        {
            GameObjectTemplate const* info = GetGOInfo();

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            Player* targetPlayer = ObjectAccessor::FindPlayer(player->GetTarget());

            // accept only use by player from same raid as caster, except caster itself
            if (!targetPlayer || targetPlayer == player || !targetPlayer->IsInSameRaidWith(player))
                return;

            //required lvl checks!
            if (Optional<ContentTuningLevels> userLevels = sDB2Manager.GetContentTuningData(info->ContentTuningId))
                if (player->GetLevel() < userLevels->MaxLevel)
                    return;

            if (Optional<ContentTuningLevels> targetLevels = sDB2Manager.GetContentTuningData(info->ContentTuningId))
                if (targetPlayer->GetLevel() < targetLevels->MaxLevel)
                    return;

            if (info->entry == 194097)
                spellId = 61994;                            // Ritual of Summoning
            else
                spellId = 59782;                            // Summoning Stone Effect

            break;
        }

        case GAMEOBJECT_TYPE_FLAGSTAND:                     // 24
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (player->CanUseBattlegroundObject(this))
            {
                // in battleground check
                Battleground* bg = player->GetBattleground();
                if (!bg)
                    return;

                if (player->GetVehicle())
                    return;

                player->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                player->RemoveAurasByType(SPELL_AURA_MOD_INVISIBILITY);
                // BG flag click
                // AB:
                // 15001
                // 15002
                // 15003
                // 15004
                // 15005
                bg->EventPlayerClickedOnFlag(player, this);
                return;                                     //we don;t need to delete flag ... it is despawned!
            }
            break;
        }

        case GAMEOBJECT_TYPE_FISHINGHOLE:                   // 25
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            Loot* loot = new Loot(GetMap(), GetGUID(), LOOT_FISHINGHOLE, nullptr);
            loot->FillLoot(GetGOInfo()->GetLootId(), LootTemplates_Gameobject, player, true, false, LOOT_MODE_DEFAULT);
            m_personalLoot[player->GetGUID()].reset(loot);

            player->SendLoot(*loot);
            player->UpdateCriteria(CriteriaType::CatchFishInFishingHole, GetGOInfo()->entry);
            return;
        }

        case GAMEOBJECT_TYPE_FLAGDROP:                      // 26
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (player->CanUseBattlegroundObject(this))
            {
                // in battleground check
                Battleground* bg = player->GetBattleground();
                if (!bg)
                    return;

                if (player->GetVehicle())
                    return;

                player->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                player->RemoveAurasByType(SPELL_AURA_MOD_INVISIBILITY);
                // BG flag dropped
                // WS:
                // 179785 - Silverwing Flag
                // 179786 - Warsong Flag
                // EotS:
                // 184142 - Netherstorm Flag
                GameObjectTemplate const* info = GetGOInfo();
                if (info)
                {
                    switch (info->entry)
                    {
                        case 179785:                        // Silverwing Flag
                        case 179786:                        // Warsong Flag
                            if (bg->GetTypeID() == BATTLEGROUND_WS)
                                bg->EventPlayerClickedOnFlag(player, this);
                            break;
                        case 184142:                        // Netherstorm Flag
                            if (bg->GetTypeID() == BATTLEGROUND_EY)
                                bg->EventPlayerClickedOnFlag(player, this);
                            break;
                    }

                    if (info->flagDrop.eventID)
                        GameEvents::Trigger(info->flagDrop.eventID, player, this);
                }
                //this cause to call return, all flags must be deleted here!!
                spellId = 0;
                Delete();
            }
            break;
        }
        case GAMEOBJECT_TYPE_BARBER_CHAIR:                  //32
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            WorldPackets::Misc::EnableBarberShop enableBarberShop;
            enableBarberShop.CustomizationScope = info->barberChair.CustomizationScope;
            player->SendDirectMessage(enableBarberShop.Write());

            // fallback, will always work
            player->TeleportTo(GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);

            player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + info->barberChair.chairheight), info->barberChair.SitAnimKit);
            return;
        }
        case GAMEOBJECT_TYPE_NEW_FLAG:
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            Player* player = user->ToPlayer();
            if (!player)
                return;

            if (!player->CanUseBattlegroundObject(this))
                return;

            GameObjectType::NewFlag const* newFlag = dynamic_cast<GameObjectType::NewFlag const*>(m_goTypeImpl.get());
            if (!newFlag)
                return;

            if (newFlag->GetState() != FlagState::InBase)
                return;

            spellId = info->newflag.pickupSpell;
            spellCaster = nullptr;
            break;
        }
        case GAMEOBJECT_TYPE_NEW_FLAG_DROP:
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!user->IsAlive())
                return;

            if (GameObject* owner = GetMap()->GetGameObject(GetOwnerGUID()))
            {
                if (owner->GetGoType() == GAMEOBJECT_TYPE_NEW_FLAG)
                {
                    GameObjectType::NewFlag const* newFlag = dynamic_cast<GameObjectType::NewFlag const*>(owner->m_goTypeImpl.get());
                    if (!newFlag)
                        return;

                    if (newFlag->GetState() != FlagState::Dropped)
                        return;

                    // friendly with enemy flag means you're taking it
                    bool defenderInteract = !owner->IsFriendlyTo(user);
                    if (defenderInteract && owner->GetGOInfo()->newflag.ReturnonDefenderInteract)
                    {
                        Delete();
                        owner->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::InBase, user->ToPlayer()));
                        return;
                    }
                    else
                    {
                        // we let the owner cast the spell for now
                        // so that caster guid is set correctly
                        SpellCastResult result = owner->CastSpell(user, owner->GetGOInfo()->newflag.pickupSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
                        if (result == SPELL_CAST_OK)
                        {
                            Delete();
                            owner->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Taken, user->ToPlayer()));
                            return;
                        }
                    }
                }
            }

            Delete();
            return;
        }
        case GAMEOBJECT_TYPE_CAPTURE_POINT:
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            AssaultCapturePoint(player);
            return;
        }
        case GAMEOBJECT_TYPE_ITEM_FORGE:
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();
            if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(info->itemForge.conditionID1))
                if (!sConditionMgr->IsPlayerMeetingCondition(player, playerCondition))
                    return;
            return;
        }
        case GAMEOBJECT_TYPE_UI_LINK:
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            WorldPackets::GameObject::GameObjectInteraction gameObjectUILink;
            gameObjectUILink.ObjectGUID = GetGUID();
            switch (GetGOInfo()->UILink.UILinkType)
            {
                case 0:
                    gameObjectUILink.InteractionType = PlayerInteractionType::AdventureJournal;
                    break;
                case 1:
                    gameObjectUILink.InteractionType = PlayerInteractionType::ObliterumForge;
                    break;
                case 2:
                    gameObjectUILink.InteractionType = PlayerInteractionType::ScrappingMachine;
                    break;
                case 3:
                    gameObjectUILink.InteractionType = PlayerInteractionType::ItemInteraction;
                    break;
                default:
                    break;
            }
            player->SendDirectMessage(gameObjectUILink.Write());
            return;
        }
        case GAMEOBJECT_TYPE_GATHERING_NODE:                //50
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            GameObjectTemplate const* info = GetGOInfo();
            if (!m_personalLoot.count(player->GetGUID()))
            {
                if (info->gatheringNode.chestLoot)
                {
                    Loot* loot = new Loot(GetMap(), GetGUID(), LOOT_CHEST, nullptr);
                    m_personalLoot[player->GetGUID()].reset(loot);

                    loot->FillLoot(info->gatheringNode.chestLoot, LootTemplates_Gameobject, player, true, false, GetLootMode());
                }

                if (info->gatheringNode.triggeredEvent)
                    GameEvents::Trigger(info->gatheringNode.triggeredEvent, player, this);

                // triggering linked GO
                if (uint32 trapEntry = info->gatheringNode.linkedTrap)
                    TriggeringLinkedGameObject(trapEntry, player);

                if (info->gatheringNode.xpDifficulty && info->gatheringNode.xpDifficulty < 10)
                    if (QuestXPEntry const* questXp = sQuestXPStore.LookupEntry(player->GetLevel()))
                        if (uint32 xp = Quest::RoundXPValue(questXp->Difficulty[info->gatheringNode.xpDifficulty]))
                            player->GiveXP(xp, nullptr);

                spellId = info->gatheringNode.spell;
            }

            if (m_personalLoot.size() >= info->gatheringNode.MaxNumberofLoots)
            {
                SetGoState(GO_STATE_ACTIVE);
                SetDynamicFlag(GO_DYNFLAG_LO_NO_INTERACT);
            }

            if (getLootState() != GO_ACTIVATED)
            {
                SetLootState(GO_ACTIVATED, player);
                if (info->gatheringNode.ObjectDespawnDelay)
                    DespawnOrUnsummon(Seconds(info->gatheringNode.ObjectDespawnDelay));
            }

            // Send loot
            if (Loot* loot = GetLootForPlayer(player))
                player->SendLoot(*loot);
            break;
        }
        default:
            if (GetGoType() >= MAX_GAMEOBJECT_TYPE)
                TC_LOG_ERROR("misc", "GameObject::Use(): unit ({}, name: {}) tries to use object ({}, name: {}) of unknown type ({})",
                    user->GetGUID().ToString(), user->GetName(), GetGUID().ToString(), GetGOInfo()->name, GetGoType());
            break;
    }

    if (!spellId)
        return;

    if (!sSpellMgr->GetSpellInfo(spellId, GetMap()->GetDifficultyID()))
    {
        if (user->GetTypeId() != TYPEID_PLAYER || !sOutdoorPvPMgr->HandleCustomSpell(user->ToPlayer(), spellId, this))
            TC_LOG_ERROR("misc", "WORLD: unknown spell id {} at use action for gameobject (Entry: {} GoType: {})", spellId, GetEntry(), GetGoType());
        else
            TC_LOG_DEBUG("outdoorpvp", "WORLD: {} non-dbc spell was handled by OutdoorPvP", spellId);
        return;
    }

    if (Player* player = user->ToPlayer())
        sOutdoorPvPMgr->HandleCustomSpell(player, spellId, this);

    if (spellCaster)
        spellCaster->CastSpell(user, spellId, triggered);
    else
    {
        SpellCastResult castResult = CastSpell(user, spellId);
        if (castResult == SPELL_FAILED_SUCCESS)
        {
            if (GetGoType() == GAMEOBJECT_TYPE_NEW_FLAG)
                HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Taken, user->ToPlayer()));
        }
    }
}

void GameObject::SendCustomAnim(uint32 anim)
{
    WorldPackets::GameObject::GameObjectCustomAnim customAnim;
    customAnim.ObjectGUID = GetGUID();
    customAnim.CustomAnim = anim;
    SendMessageToSet(customAnim.Write(), true);
}

bool GameObject::IsInRange(float x, float y, float z, float radius) const
{
    GameObjectDisplayInfoEntry const* info = sGameObjectDisplayInfoStore.LookupEntry(m_goInfo->displayId);
    if (!info)
        return IsWithinDist3d(x, y, z, radius);

    float sinA = std::sin(GetOrientation());
    float cosA = std::cos(GetOrientation());
    float dx = x - GetPositionX();
    float dy = y - GetPositionY();
    float dz = z - GetPositionZ();
    float dist = std::sqrt(dx*dx + dy*dy);
    //! Check if the distance between the 2 objects is 0, can happen if both objects are on the same position.
    //! The code below this check wont crash if dist is 0 because 0/0 in float operations is valid, and returns infinite
    if (G3D::fuzzyEq(dist, 0.0f))
        return true;

    float sinB = dx / dist;
    float cosB = dy / dist;
    dx = dist * (cosA * cosB + sinA * sinB);
    dy = dist * (cosA * sinB - sinA * cosB);
    return dx < info->GeoBoxMax.X + radius && dx > info->GeoBoxMin.X - radius
        && dy < info->GeoBoxMax.Y + radius && dy > info->GeoBoxMin.Y - radius
        && dz < info->GeoBoxMax.Z + radius && dz > info->GeoBoxMin.Z - radius;
}

uint32 GameObject::GetScriptId() const
{
    if (GameObjectData const* gameObjectData = GetGameObjectData())
        if (uint32 scriptId = gameObjectData->scriptId)
            return scriptId;

    return GetGOInfo()->ScriptId;
}

bool GameObject::HasStringId(std::string_view id) const
{
    return std::find(m_stringIds.begin(), m_stringIds.end(), id) != m_stringIds.end();
}

void GameObject::SetScriptStringId(std::string id)
{
    if (!id.empty())
    {
        m_scriptStringId.emplace(std::move(id));
        m_stringIds[2] = *m_scriptStringId;
    }
    else
    {
        m_scriptStringId.reset();
        m_stringIds[2] = {};
    }
}

// overwrite WorldObject function for proper name localization
std::string GameObject::GetNameForLocaleIdx(LocaleConstant locale) const
{
    if (locale != DEFAULT_LOCALE)
        if (GameObjectLocale const* cl = sObjectMgr->GetGameObjectLocale(GetEntry()))
            if (cl->Name.size() > locale && !cl->Name[locale].empty())
                return cl->Name[locale];

    return GetName();
}

void GameObject::UpdatePackedRotation()
{
    static const int32 PACK_YZ = 1 << 20;
    static const int32 PACK_X = PACK_YZ << 1;

    static const int32 PACK_YZ_MASK = (PACK_YZ << 1) - 1;
    static const int32 PACK_X_MASK = (PACK_X << 1) - 1;

    int8 w_sign = (m_localRotation.w >= 0.f ? 1 : -1);
    int64 x = int32(m_localRotation.x * PACK_X)  * w_sign & PACK_X_MASK;
    int64 y = int32(m_localRotation.y * PACK_YZ) * w_sign & PACK_YZ_MASK;
    int64 z = int32(m_localRotation.z * PACK_YZ) * w_sign & PACK_YZ_MASK;
    m_packedRotation = z | (y << 21) | (x << 42);
}

void GameObject::SetLocalRotation(float qx, float qy, float qz, float qw)
{
    G3D::Quat rotation(qx, qy, qz, qw);
    rotation.unitize();
    m_localRotation.x = rotation.x;
    m_localRotation.y = rotation.y;
    m_localRotation.z = rotation.z;
    m_localRotation.w = rotation.w;
    UpdatePackedRotation();
}

void GameObject::SetParentRotation(QuaternionData const& rotation)
{
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::ParentRotation), rotation);
}

void GameObject::SetLocalRotationAngles(float z_rot, float y_rot, float x_rot)
{
    G3D::Quat quat(G3D::Matrix3::fromEulerAnglesZYX(z_rot, y_rot, x_rot));
    SetLocalRotation(quat.x, quat.y, quat.z, quat.w);
}

QuaternionData GameObject::GetWorldRotation() const
{
    QuaternionData localRotation = GetLocalRotation();
    if (Transport* transport = dynamic_cast<Transport*>(GetTransport()))
    {
        QuaternionData worldRotation = transport->GetWorldRotation();

        G3D::Quat worldRotationQuat(worldRotation.x, worldRotation.y, worldRotation.z, worldRotation.w);
        G3D::Quat localRotationQuat(localRotation.x, localRotation.y, localRotation.z, localRotation.w);

        G3D::Quat resultRotation = localRotationQuat * worldRotationQuat;

        return QuaternionData(resultRotation.x, resultRotation.y, resultRotation.z, resultRotation.w);
    }
    return localRotation;
}

void GameObject::ModifyHealth(int32 change, WorldObject* attackerOrHealer /*= nullptr*/, uint32 spellId /*= 0*/)
{
    if (!m_goValue.Building.MaxHealth || !change)
        return;

    // prevent double destructions of the same object
    if (change < 0 && !m_goValue.Building.Health)
        return;

    if (int32(m_goValue.Building.Health) + change <= 0)
        m_goValue.Building.Health = 0;
    else if (int32(m_goValue.Building.Health) + change >= int32(m_goValue.Building.MaxHealth))
        m_goValue.Building.Health = m_goValue.Building.MaxHealth;
    else
        m_goValue.Building.Health += change;

    // Set the health bar, value = 255 * healthPct;
    SetGoAnimProgress(m_goValue.Building.Health * 255 / m_goValue.Building.MaxHealth);

    // dealing damage, send packet
    if (Player* player = attackerOrHealer ? attackerOrHealer->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr)
    {
        WorldPackets::GameObject::DestructibleBuildingDamage packet;
        packet.Caster = attackerOrHealer->GetGUID(); // todo: this can be a GameObject
        packet.Target = GetGUID();
        packet.Damage = -change;
        packet.Owner = player->GetGUID();
        packet.SpellID = spellId;
        player->SendDirectMessage(packet.Write());
    }

    if (change < 0 && GetGOInfo()->destructibleBuilding.DamageEvent)
        GameEvents::Trigger(GetGOInfo()->destructibleBuilding.DamageEvent, attackerOrHealer, this);

    GameObjectDestructibleState newState = GetDestructibleState();

    if (!m_goValue.Building.Health)
        newState = GO_DESTRUCTIBLE_DESTROYED;
    else if (m_goValue.Building.Health <= 10000/*GetGOInfo()->destructibleBuilding.damagedNumHits*/) // TODO: Get health somewhere
        newState = GO_DESTRUCTIBLE_DAMAGED;
    else if (m_goValue.Building.Health == m_goValue.Building.MaxHealth)
        newState = GO_DESTRUCTIBLE_INTACT;

    if (newState == GetDestructibleState())
        return;

    SetDestructibleState(newState, attackerOrHealer, false);
}

void GameObject::SetDestructibleState(GameObjectDestructibleState state, WorldObject* attackerOrHealer /*= nullptr*/, bool setHealth /*= false*/)
{
    // the user calling this must know he is already operating on destructible gameobject
    ASSERT(GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING);

    switch (state)
    {
        case GO_DESTRUCTIBLE_INTACT:
            RemoveFlag(GO_FLAG_DAMAGED | GO_FLAG_DESTROYED);
            SetDisplayId(m_goInfo->displayId);
            if (setHealth)
            {
                m_goValue.Building.Health = m_goValue.Building.MaxHealth;
                SetGoAnimProgress(255);
            }
            EnableCollision(true);
            break;
        case GO_DESTRUCTIBLE_DAMAGED:
        {
            if (GetGOInfo()->destructibleBuilding.DamagedEvent && attackerOrHealer)
                GameEvents::Trigger(GetGOInfo()->destructibleBuilding.DamagedEvent, attackerOrHealer, this);
            AI()->Damaged(attackerOrHealer, m_goInfo->destructibleBuilding.DamagedEvent);

            RemoveFlag(GO_FLAG_DESTROYED);
            SetFlag(GO_FLAG_DAMAGED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State1Wmo)
                    modelId = modelData->State1Wmo;
            SetDisplayId(modelId);

            if (setHealth)
            {
                m_goValue.Building.Health = 10000/*m_goInfo->destructibleBuilding.damagedNumHits*/;
                uint32 maxHealth = m_goValue.Building.MaxHealth;
                // in this case current health is 0 anyway so just prevent crashing here
                if (!maxHealth)
                    maxHealth = 1;
                SetGoAnimProgress(m_goValue.Building.Health * 255 / maxHealth);
            }
            break;
        }
        case GO_DESTRUCTIBLE_DESTROYED:
        {
            if (GetGOInfo()->destructibleBuilding.DestroyedEvent && attackerOrHealer)
                GameEvents::Trigger(GetGOInfo()->destructibleBuilding.DestroyedEvent, attackerOrHealer, this);
            AI()->Destroyed(attackerOrHealer, m_goInfo->destructibleBuilding.DestroyedEvent);

            if (Player* player = attackerOrHealer ? attackerOrHealer->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr)
                if (Battleground* bg = player->GetBattleground())
                    bg->DestroyGate(player, this);

            RemoveFlag(GO_FLAG_DAMAGED);
            SetFlag(GO_FLAG_DESTROYED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State2Wmo)
                    modelId = modelData->State2Wmo;
            SetDisplayId(modelId);

            if (setHealth)
            {
                m_goValue.Building.Health = 0;
                SetGoAnimProgress(0);
            }
            EnableCollision(false);
            break;
        }
        case GO_DESTRUCTIBLE_REBUILDING:
        {
            if (GetGOInfo()->destructibleBuilding.RebuildingEvent && attackerOrHealer)
                GameEvents::Trigger(GetGOInfo()->destructibleBuilding.RebuildingEvent, attackerOrHealer, this);
            RemoveFlag(GO_FLAG_DAMAGED | GO_FLAG_DESTROYED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State3Wmo)
                    modelId = modelData->State3Wmo;
            SetDisplayId(modelId);

            // restores to full health
            if (setHealth)
            {
                m_goValue.Building.Health = m_goValue.Building.MaxHealth;
                SetGoAnimProgress(255);
            }
            EnableCollision(true);
            break;
        }
    }
}

void GameObject::SetLootState(LootState state, Unit* unit)
{
    m_lootState = state;
    if (unit)
        m_lootStateUnitGUID = unit->GetGUID();
    else
        m_lootStateUnitGUID.Clear();

    AI()->OnLootStateChanged(state, unit);

    // Start restock timer if the chest is partially looted or not looted at all
    if (GetGoType() == GAMEOBJECT_TYPE_CHEST && state == GO_ACTIVATED && GetGOInfo()->chest.chestRestockTime > 0 && m_restockTime == 0 && m_loot && m_loot->IsChanged())
        m_restockTime = GameTime::GetGameTime() + GetGOInfo()->chest.chestRestockTime;

    if (GetGoType() == GAMEOBJECT_TYPE_DOOR) // only set collision for doors on SetGoState
        return;

    if (m_model)
    {
        bool collision = false;
        // Use the current go state
        if ((GetGoState() != GO_STATE_READY && (state == GO_ACTIVATED || state == GO_JUST_DEACTIVATED)) || state == GO_READY)
            collision = !collision;

        EnableCollision(collision);
    }
}

void GameObject::ClearLoot()
{
    // Unlink loot objects from this GameObject before destroying to avoid accessing freed memory from Loot destructor
    std::unique_ptr<Loot> loot(std::move(m_loot));
    std::unordered_map<ObjectGuid, std::unique_ptr<Loot>> personalLoot(std::move(m_personalLoot));

    loot.reset();
    personalLoot.clear();
    m_unique_users.clear();
    m_usetimes = 0;
}

bool GameObject::IsFullyLooted() const
{
    if (m_loot && !m_loot->isLooted())
        return false;

    for (auto const& [_, loot] : m_personalLoot)
        if (!loot->isLooted())
            return false;

    return true;
}

void GameObject::OnLootRelease(Player* looter)
{
    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_CHEST:
        {
            GameObjectTemplate const* goInfo = GetGOInfo();
            if (!goInfo->chest.consumable && goInfo->chest.chestPersonalLoot)
            {
                DespawnForPlayer(looter, goInfo->chest.chestRestockTime
                    ? Seconds(goInfo->chest.chestRestockTime)
                    : Seconds(m_respawnDelayTime)); // not hiding this object permanently to prevent infinite growth of m_perPlayerState
                                                    // while also maintaining some sort of cheater protection (not getting rid of entries on logout)
            }
            break;
        }
        case GAMEOBJECT_TYPE_GATHERING_NODE:
        {
            SetGoStateFor(GO_STATE_ACTIVE, looter);

            UF::ObjectData::Base objMask;
            UF::GameObjectData::Base goMask;
            objMask.MarkChanged(&UF::ObjectData::DynamicFlags);

            UpdateData udata(GetMapId());
            BuildValuesUpdateForPlayerWithMask(&udata, objMask.GetChangesMask(), goMask.GetChangesMask(), looter);
            WorldPacket packet;
            udata.BuildPacket(&packet);
            looter->SendDirectMessage(&packet);
            break;
        }
        default:
            break;
    }
}

void GameObject::SetGoState(GOState state)
{
    GOState oldState = GetGoState();
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::State), state);
    if (AI())
        AI()->OnStateChanged(state);

    if (m_goTypeImpl)
        m_goTypeImpl->OnStateChanged(oldState, state);

    if (m_model && !IsTransport())
    {
        if (!IsInWorld())
            return;

        // startOpen determines whether we are going to add or remove the LoS on activation
        bool collision = false;
        if (state == GO_STATE_READY)
            collision = !collision;

        EnableCollision(collision);
    }
}

GOState GameObject::GetGoStateFor(ObjectGuid const& viewer) const
{
    if (m_perPlayerState)
        if (PerPlayerState const* state = Trinity::Containers::MapGetValuePtr(*m_perPlayerState, viewer))
            if (state->State)
                return *state->State;

    return GetGoState();
}

void GameObject::SetGoStateFor(GOState state, Player const* viewer)
{
    PerPlayerState& perPlayerState = GetOrCreatePerPlayerStates()[viewer->GetGUID()];
    perPlayerState.ValidUntil = GameTime::GetSystemTime() + Seconds(m_respawnDelayTime);
    perPlayerState.State = state;

    WorldPackets::GameObject::GameObjectSetStateLocal setStateLocal;
    setStateLocal.ObjectGUID = GetGUID();
    setStateLocal.State = state;
    viewer->SendDirectMessage(setStateLocal.Write());
}

void GameObject::SetDisplayId(uint32 displayid)
{
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::DisplayID), displayid);
    UpdateModel();
}

uint8 GameObject::GetNameSetId() const
{
    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
            {
                switch (GetDestructibleState())
                {
                    case GO_DESTRUCTIBLE_INTACT:
                        return modelData->State0NameSet;
                    case GO_DESTRUCTIBLE_DAMAGED:
                        return modelData->State1NameSet;
                    case GO_DESTRUCTIBLE_DESTROYED:
                        return modelData->State2NameSet;
                    case GO_DESTRUCTIBLE_REBUILDING:
                        return modelData->State3NameSet;
                    default:
                        break;
                }
            }
            break;
        case GAMEOBJECT_TYPE_GARRISON_BUILDING:
        case GAMEOBJECT_TYPE_GARRISON_PLOT:
        case GAMEOBJECT_TYPE_PHASEABLE_MO:
            return ((*m_gameObjectData->Flags) >> 8) & 0xF;
        default:
            break;
    }

    return 0;
}

void GameObject::EnableCollision(bool enable)
{
    if (!m_model)
        return;

    /*if (enable && !GetMap()->ContainsGameObjectModel(*m_model))
        GetMap()->InsertGameObjectModel(*m_model);*/

    m_model->enableCollision(enable);
}

void GameObject::UpdateModel()
{
    if (!IsInWorld())
        return;
    if (m_model)
        if (GetMap()->ContainsGameObjectModel(*m_model))
            GetMap()->RemoveGameObjectModel(*m_model);
    RemoveFlag(GO_FLAG_MAP_OBJECT);
    delete m_model;
    m_model = nullptr;
    CreateModel();
    if (m_model)
        GetMap()->InsertGameObjectModel(*m_model);
}

bool GameObject::IsLootAllowedFor(Player const* player) const
{
    if (Loot const* loot = GetLootForPlayer(player)) // check only if loot was already generated
    {
        if (loot->isLooted()) // nothing to loot or everything looted.
            return false;
        if (!loot->HasAllowedLooter(GetGUID()) || (!loot->hasItemForAll() && !loot->hasItemFor(player))) // no loot in chest for this player
            return false;
    }

    if (HasLootRecipient())
        return m_tapList.find(player->GetGUID()) != m_tapList.end();

    return true;
}

Loot* GameObject::GetLootForPlayer(Player const* player) const
{
    if (m_personalLoot.empty())
        return m_loot.get();

    if (std::unique_ptr<Loot> const* loot = Trinity::Containers::MapGetValuePtr(m_personalLoot, player->GetGUID()))
        return loot->get();

    return nullptr;
}

GameObject* GameObject::GetLinkedTrap()
{
    return ObjectAccessor::GetGameObject(*this, m_linkedTrap);
}

void GameObject::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_gameObjectData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void GameObject::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_GAMEOBJECT))
        m_gameObjectData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void GameObject::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::GameObjectData::Mask const& requestedGameObjectMask, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    if (requestedGameObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_GAMEOBJECT);

    ByteBuffer& buffer = PrepareValuesUpdateBuffer(data);
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_GAMEOBJECT])
        m_gameObjectData->WriteUpdate(buffer, requestedGameObjectMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void GameObject::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), GameObjectMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void GameObject::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&GameObject::m_gameObjectData);
    Object::ClearUpdateMask(remove);
}

std::vector<uint32> const* GameObject::GetPauseTimes() const
{
    if (GameObjectType::Transport const* transport = dynamic_cast<GameObjectType::Transport const*>(m_goTypeImpl.get()))
        return transport->GetPauseTimes();

    return nullptr;
}

void GameObject::SetPathProgressForClient(float progress)
{
    DoWithSuppressingObjectUpdates([&]()
    {
        UF::ObjectData::Base dynflagMask;
        dynflagMask.MarkChanged(&UF::ObjectData::DynamicFlags);
        bool marked = (m_objectData->GetChangesMask() & dynflagMask.GetChangesMask()).IsAnySet();

        uint32 dynamicFlags = GetDynamicFlags();
        dynamicFlags &= 0xFFFF; // remove high bits
        dynamicFlags |= uint32(progress * 65535.0f) << 16;
        ReplaceAllDynamicFlags(dynamicFlags);

        if (!marked)
            const_cast<UF::ObjectData&>(*m_objectData).ClearChanged(&UF::ObjectData::DynamicFlags);
    });
}

void GameObject::GetRespawnPosition(float &x, float &y, float &z, float* ori /* = nullptr*/) const
{
    if (m_goData)
    {
        if (ori)
            m_goData->spawnPoint.GetPosition(x, y, z, *ori);
        else
            m_goData->spawnPoint.GetPosition(x, y, z);
    }
    else
    {
        if (ori)
            GetPosition(x, y, z, *ori);
        else
            GetPosition(x, y, z);
    }
}

TransportBase const* GameObject::ToTransportBase() const
{
    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_TRANSPORT:
            return static_cast<GameObjectType::Transport const*>(m_goTypeImpl.get());
        case GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT:
            return static_cast<Transport const*>(this);
        default:
            break;
    }

    return nullptr;
}

void GameObject::AfterRelocation()
{
    UpdateModelPosition();
    UpdatePositionData();
    if (m_goTypeImpl)
        m_goTypeImpl->OnRelocated();

    UpdateObjectVisibility(false);
}

float GameObject::GetInteractionDistance() const
{
    if (GetGOInfo()->GetInteractRadiusOverride())
        return float(GetGOInfo()->GetInteractRadiusOverride()) / 100.0f;

    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_AREADAMAGE:
            return 0.0f;
        case GAMEOBJECT_TYPE_QUESTGIVER:
        case GAMEOBJECT_TYPE_TEXT:
        case GAMEOBJECT_TYPE_FLAGSTAND:
        case GAMEOBJECT_TYPE_FLAGDROP:
        case GAMEOBJECT_TYPE_MINI_GAME:
            return 5.5555553f;
        case GAMEOBJECT_TYPE_BINDER:
            return 10.0f;
        case GAMEOBJECT_TYPE_CHAIR:
        case GAMEOBJECT_TYPE_BARBER_CHAIR:
            return 3.0f;
        case GAMEOBJECT_TYPE_FISHINGNODE:
            return 100.0f;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
            return 20.0f + CONTACT_DISTANCE; // max spell range
        case GAMEOBJECT_TYPE_CAMERA:
        case GAMEOBJECT_TYPE_MAP_OBJECT:
        case GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY:
        case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
        case GAMEOBJECT_TYPE_DOOR:
            return 5.0f;
        // Following values are not blizzlike
        case GAMEOBJECT_TYPE_GUILD_BANK:
        case GAMEOBJECT_TYPE_MAILBOX:
            // Successful mailbox interaction is rather critical to the client, failing it will start a minute-long cooldown until the next mail query may be executed.
            // And since movement info update is not sent with mailbox interaction query, server may find the player outside of interaction range. Thus we increase it.
            return 10.0f; // 5.0f is blizzlike
        default:
            return INTERACTION_DISTANCE;
    }
}

void GameObject::UpdateModelPosition()
{
    if (!m_model)
        return;

    if (GetMap()->ContainsGameObjectModel(*m_model))
    {
        GetMap()->RemoveGameObjectModel(*m_model);
        m_model->UpdatePosition();
        GetMap()->InsertGameObjectModel(*m_model);
    }
}

void GameObject::SetAnimKitId(uint16 animKitId, bool oneshot)
{
    if (_animKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    if (!oneshot)
        _animKitId = animKitId;
    else
        _animKitId = 0;

    WorldPackets::GameObject::GameObjectActivateAnimKit activateAnimKit;
    activateAnimKit.ObjectGUID = GetGUID();
    activateAnimKit.AnimKitID = animKitId;
    activateAnimKit.Maintain = !oneshot;
    SendMessageToSet(activateAnimKit.Write(), true);
}

void GameObject::SetSpellVisualId(int32 spellVisualId, ObjectGuid activatorGuid)
{
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::SpellVisualID), spellVisualId);

    WorldPackets::GameObject::GameObjectPlaySpellVisual packet;
    packet.ObjectGUID = GetGUID();
    packet.ActivatorGUID = activatorGuid;
    packet.SpellVisualID = spellVisualId;
    SendMessageToSet(packet.Write(), true);
}

void GameObject::AssaultCapturePoint(Player* player)
{
    if (!CanInteractWithCapturePoint(player))
        return;

    if (GameObjectAI* ai = AI())
        if (ai->OnCapturePointAssaulted(player))
            return;

    // only supported in battlegrounds
    Battleground* battleground = nullptr;
    if (BattlegroundMap* map = GetMap()->ToBattlegroundMap())
        if (Battleground* bg = map->GetBG())
            battleground = bg;

    if (!battleground)
        return;

    // Cancel current timer
    m_goValue.CapturePoint.AssaultTimer = 0;

    if (player->GetBGTeam() == HORDE)
    {
        if (m_goValue.CapturePoint.LastTeamCapture == TEAM_HORDE)
        {
            // defended. capture instantly.
            m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured;
            battleground->SendBroadcastText(GetGOInfo()->capturePoint.DefendedBroadcastHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);
            UpdateCapturePoint();
            if (GetGOInfo()->capturePoint.DefendedEventHorde)
                GameEvents::Trigger(GetGOInfo()->capturePoint.DefendedEventHorde, player, this);
            return;
        }

        switch (m_goValue.CapturePoint.State)
        {
            case WorldPackets::Battleground::BattlegroundCapturePointState::Neutral:
            case WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured:
            case WorldPackets::Battleground::BattlegroundCapturePointState::ContestedAlliance:
                m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::ContestedHorde;
                battleground->SendBroadcastText(GetGOInfo()->capturePoint.AssaultBroadcastHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);
                UpdateCapturePoint();
                if (GetGOInfo()->capturePoint.ContestedEventHorde)
                    GameEvents::Trigger(GetGOInfo()->capturePoint.ContestedEventHorde, player, this);
                m_goValue.CapturePoint.AssaultTimer = GetGOInfo()->capturePoint.CaptureTime;
                break;
            default:
                break;
        }
    }
    else
    {
        if (m_goValue.CapturePoint.LastTeamCapture == TEAM_ALLIANCE)
        {
            // defended. capture instantly.
            m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured;
            battleground->SendBroadcastText(GetGOInfo()->capturePoint.DefendedBroadcastAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            UpdateCapturePoint();
            if (GetGOInfo()->capturePoint.DefendedEventAlliance)
                GameEvents::Trigger(GetGOInfo()->capturePoint.DefendedEventAlliance, player, this);
            return;
        }

        switch (m_goValue.CapturePoint.State)
        {
            case WorldPackets::Battleground::BattlegroundCapturePointState::Neutral:
            case WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured:
            case WorldPackets::Battleground::BattlegroundCapturePointState::ContestedHorde:
                m_goValue.CapturePoint.State = WorldPackets::Battleground::BattlegroundCapturePointState::ContestedAlliance;
                battleground->SendBroadcastText(GetGOInfo()->capturePoint.AssaultBroadcastAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                UpdateCapturePoint();
                if (GetGOInfo()->capturePoint.ContestedEventAlliance)
                    GameEvents::Trigger(GetGOInfo()->capturePoint.ContestedEventAlliance, player, this);
                m_goValue.CapturePoint.AssaultTimer = GetGOInfo()->capturePoint.CaptureTime;
                break;
            default:
                break;
        }
    }
}

void GameObject::UpdateCapturePoint()
{
    if (GetGoType() != GAMEOBJECT_TYPE_CAPTURE_POINT)
        return;

    if (GameObjectAI* ai = AI())
        if (ai->OnCapturePointUpdated(m_goValue.CapturePoint.State))
            return;

    uint32 spellVisualId = 0;
    uint32 customAnim = 0;

    switch (m_goValue.CapturePoint.State)
    {
        case WorldPackets::Battleground::BattlegroundCapturePointState::Neutral:
            spellVisualId = GetGOInfo()->capturePoint.SpellVisual1;
            break;
        case WorldPackets::Battleground::BattlegroundCapturePointState::ContestedHorde:
            customAnim = 1;
            spellVisualId = GetGOInfo()->capturePoint.SpellVisual2;
            break;
        case WorldPackets::Battleground::BattlegroundCapturePointState::ContestedAlliance:
            customAnim = 2;
            spellVisualId = GetGOInfo()->capturePoint.SpellVisual3;
            break;
        case WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured:
            customAnim = 3;
            spellVisualId = GetGOInfo()->capturePoint.SpellVisual4;
            break;
        case WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured:
            customAnim = 4;
            spellVisualId = GetGOInfo()->capturePoint.SpellVisual5;
            break;
        default:
            break;
    }

    if (customAnim != 0)
        SendCustomAnim(customAnim);

    SetSpellVisualId(spellVisualId);
    UpdateDynamicFlagsForNearbyPlayers();

    if (BattlegroundMap* map = GetMap()->ToBattlegroundMap())
    {
        if (Battleground* bg = map->GetBG())
        {
            WorldPackets::Battleground::UpdateCapturePoint packet;
            packet.CapturePointInfo.State = m_goValue.CapturePoint.State;
            packet.CapturePointInfo.Pos = GetPosition();
            packet.CapturePointInfo.Guid = GetGUID();
            packet.CapturePointInfo.CaptureTotalDuration = Milliseconds(GetGOInfo()->capturePoint.CaptureTime);
            packet.CapturePointInfo.CaptureTime = m_goValue.CapturePoint.AssaultTimer;
            bg->SendPacketToAll(packet.Write());
            bg->UpdateWorldState(GetGOInfo()->capturePoint.worldState1, AsUnderlyingType(m_goValue.CapturePoint.State));
        }
    }

    GetMap()->UpdateSpawnGroupConditions();
}

bool GameObject::CanInteractWithCapturePoint(Player const* target) const
{
    if (m_goInfo->type != GAMEOBJECT_TYPE_CAPTURE_POINT)
        return false;

    if (m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::Neutral)
        return true;

    if (target->GetBGTeam() == HORDE)
    {
        return m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::ContestedAlliance
            || m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured;
    }

    // For Alliance players
    return m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::ContestedHorde
        || m_goValue.CapturePoint.State == WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured;
}

FlagState GameObject::GetFlagState() const
{
    if (GetGoType() != GAMEOBJECT_TYPE_NEW_FLAG)
        return FlagState(0);

    GameObjectType::NewFlag const* newFlag = dynamic_cast<GameObjectType::NewFlag const*>(m_goTypeImpl.get());
    if (!newFlag)
        return FlagState(0);

    return newFlag->GetState();
}

ObjectGuid const& GameObject::GetFlagCarrierGUID() const
{
    if (GetGoType() != GAMEOBJECT_TYPE_NEW_FLAG)
        return ObjectGuid::Empty;

    GameObjectType::NewFlag const* newFlag = dynamic_cast<GameObjectType::NewFlag const*>(m_goTypeImpl.get());
    if (!newFlag)
        return ObjectGuid::Empty;

    return newFlag->GetCarrierGUID();
}

time_t GameObject::GetFlagTakenFromBaseTime() const
{
    if (GetGoType() != GAMEOBJECT_TYPE_NEW_FLAG)
        return time_t(0);

    GameObjectType::NewFlag const* newFlag = dynamic_cast<GameObjectType::NewFlag const*>(m_goTypeImpl.get());
    if (!newFlag)
        return time_t(0);

    return newFlag->GetTakenFromBaseTime();
}

GuidUnorderedSet const* GameObject::GetInsidePlayers() const
{
    if (GameObjectType::ControlZone const* controlZone = dynamic_cast<GameObjectType::ControlZone const*>(m_goTypeImpl.get()))
        return controlZone->GetInsidePlayers();

    return nullptr;
}

bool GameObject::MeetsInteractCondition(Player const* user) const
{
    if (!m_goInfo->GetConditionID1())
        return true;

    if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(m_goInfo->GetConditionID1()))
        if (!ConditionMgr::IsPlayerMeetingCondition(user, playerCondition))
            return false;

    return true;
}

std::unordered_map<ObjectGuid, GameObject::PerPlayerState>& GameObject::GetOrCreatePerPlayerStates()
{
    if (!m_perPlayerState)
        m_perPlayerState = std::make_unique<std::unordered_map<ObjectGuid, PerPlayerState>>();

    return *m_perPlayerState;
}

class GameObjectModelOwnerImpl : public GameObjectModelOwnerBase
{
public:
    explicit GameObjectModelOwnerImpl(GameObject* owner) : _owner(owner) { }
    virtual ~GameObjectModelOwnerImpl() = default;

    bool IsSpawned() const override { return _owner->isSpawned(); }
    uint32 GetDisplayId() const override { return _owner->GetDisplayId(); }
    uint8 GetNameSetId() const override { return _owner->GetNameSetId(); }
    bool IsInPhase(PhaseShift const& phaseShift) const override { return _owner->GetPhaseShift().CanSee(phaseShift); }
    G3D::Vector3 GetPosition() const override { return G3D::Vector3(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ()); }
    G3D::Quat GetRotation() const override { return G3D::Quat(_owner->GetLocalRotation().x, _owner->GetLocalRotation().y, _owner->GetLocalRotation().z, _owner->GetLocalRotation().w); }
    float GetScale() const override { return _owner->GetObjectScale(); }
    void DebugVisualizeCorner(G3D::Vector3 const& corner) const override { _owner->SummonCreature(1, corner.x, corner.y, corner.z, 0, TEMPSUMMON_MANUAL_DESPAWN); }

private:
    GameObject* _owner;
};

void GameObject::UpdateDynamicFlagsForNearbyPlayers()
{
    m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::DynamicFlags);
    AddToObjectUpdateIfNeeded();
}

void GameObject::HandleCustomTypeCommand(GameObjectTypeBase::CustomCommand const& command) const
{
    if (m_goTypeImpl)
        command.Execute(*m_goTypeImpl);
}

void GameObject::CreateModel()
{
    m_model = GameObjectModel::Create(std::make_unique<GameObjectModelOwnerImpl>(this), sWorld->GetDataPath());
    if (m_model && m_model->isMapObject())
        SetFlag(GO_FLAG_MAP_OBJECT);
}

std::string GameObject::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << WorldObject::GetDebugInfo() << "\n"
        << "SpawnId: " << GetSpawnId() << " GoState: " << std::to_string(GetGoState()) << " ScriptId: " << GetScriptId() << " AIName: " << GetAIName();
    return sstr.str();
}

bool GameObject::IsAtInteractDistance(Player const* player, SpellInfo const* spell) const
{
    if (spell || (spell = GetSpellForLock(player)))
    {
        float maxRange = spell->GetMaxRange(spell->IsPositive());

        if (GetGoType() == GAMEOBJECT_TYPE_SPELL_FOCUS)
            return maxRange * maxRange >= GetExactDistSq(player);

        if (sGameObjectDisplayInfoStore.LookupEntry(GetGOInfo()->displayId))
            return IsAtInteractDistance(*player, maxRange);
    }

    return IsAtInteractDistance(*player, GetInteractionDistance());
}

bool GameObject::IsAtInteractDistance(Position const& pos, float radius) const
{
    if (GameObjectDisplayInfoEntry const* displayInfo = sGameObjectDisplayInfoStore.LookupEntry(GetGOInfo()->displayId))
    {
        float scale = GetObjectScale();

        float minX = displayInfo->GeoBoxMin.X * scale - radius;
        float minY = displayInfo->GeoBoxMin.Y * scale - radius;
        float minZ = displayInfo->GeoBoxMin.Z * scale - radius;
        float maxX = displayInfo->GeoBoxMax.X * scale + radius;
        float maxY = displayInfo->GeoBoxMax.Y * scale + radius;
        float maxZ = displayInfo->GeoBoxMax.Z * scale + radius;

        QuaternionData worldRotation = GetWorldRotation();
        G3D::Quat worldRotationQuat(worldRotation.x, worldRotation.y, worldRotation.z, worldRotation.w);

        return G3D::CoordinateFrame { { worldRotationQuat }, { GetPositionX(), GetPositionY(), GetPositionZ() } }
                .toWorldSpace(G3D::Box { { minX, minY, minZ }, { maxX, maxY, maxZ } })
                .contains({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() });
    }

    return GetExactDist(&pos) <= radius;
}

bool GameObject::IsWithinDistInMap(Player const* player) const
{
    return IsInMap(player) && InSamePhase(player) && IsAtInteractDistance(player);
}

SpellInfo const* GameObject::GetSpellForLock(Player const* player) const
{
    if (!player)
        return nullptr;

    uint32 lockId = GetGOInfo()->GetLockId();
    if (!lockId)
        return nullptr;

    LockEntry const* lock = sLockStore.LookupEntry(lockId);
    if (!lock)
        return nullptr;

    for (uint8 i = 0; i < MAX_LOCK_CASE; ++i)
    {
        if (!lock->Type[i])
            continue;

        if (lock->Type[i] == LOCK_KEY_SPELL)
            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(lock->Index[i], GetMap()->GetDifficultyID()))
                return spell;

        if (lock->Type[i] != LOCK_KEY_SKILL)
            break;

        for (auto&& playerSpell : player->GetSpellMap())
            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(playerSpell.first, GetMap()->GetDifficultyID()))
                for (auto&& effect : spell->GetEffects())
                    if (effect.Effect == SPELL_EFFECT_OPEN_LOCK && effect.MiscValue == lock->Index[i])
                        if (effect.CalcValue(player) >= int32(lock->Skill[i]))
                            return spell;
    }

    return nullptr;
}

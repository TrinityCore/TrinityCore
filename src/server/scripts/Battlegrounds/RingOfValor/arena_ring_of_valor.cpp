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
#include "BattlegroundScript.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"

struct arena_ring_of_valor : ArenaScript
{
    enum BattlegroundRVGameObjects
    {
        BG_RV_OBJECT_TYPE_BUFF_1                = 184663,
        BG_RV_OBJECT_TYPE_BUFF_2                = 184664,
        BG_RV_OBJECT_TYPE_FIRE_1                = 192704,
        BG_RV_OBJECT_TYPE_FIRE_2                = 192705,

        BG_RV_OBJECT_TYPE_FIREDOOR_2            = 192387,
        BG_RV_OBJECT_TYPE_FIREDOOR_1            = 192388,
        BG_RV_OBJECT_TYPE_PULLEY_1              = 192389,
        BG_RV_OBJECT_TYPE_PULLEY_2              = 192390,
        BG_RV_OBJECT_TYPE_GEAR_1                = 192393,
        BG_RV_OBJECT_TYPE_GEAR_2                = 192394,
        BG_RV_OBJECT_TYPE_ELEVATOR_1            = 194582,
        BG_RV_OBJECT_TYPE_ELEVATOR_2            = 194586,

        BG_RV_OBJECT_TYPE_PILAR_COLLISION_1     = 194580, // axe
        BG_RV_OBJECT_TYPE_PILAR_COLLISION_2     = 194579, // arena // big
        BG_RV_OBJECT_TYPE_PILAR_COLLISION_3     = 194581, // lightning
        BG_RV_OBJECT_TYPE_PILAR_COLLISION_4     = 194578, // ivory // big

        BG_RV_OBJECT_TYPE_PILAR_1               = 194583, // axe
        BG_RV_OBJECT_TYPE_PILAR_2               = 194584, // arena
        BG_RV_OBJECT_TYPE_PILAR_3               = 194585, // lightning
        BG_RV_OBJECT_TYPE_PILAR_4               = 194587  // ivory
    };

    enum BattlegroundRVData
    {
        BG_RV_STATE_OPEN_FENCES,
        BG_RV_STATE_SWITCH_PILLARS,
        BG_RV_STATE_CLOSE_FIRE,

        BG_RV_PILLAR_SWITCH_TIMER               = 25000,
        BG_RV_FIRE_TO_PILLAR_TIMER              = 20000,
        BG_RV_CLOSE_FIRE_TIMER                  = 5000,
        BG_RV_FIRST_TIMER                       = 20133,
    };

    explicit arena_ring_of_valor(BattlegroundMap* map) : ArenaScript(map), _timer(0), _state(0), _pillarCollision(false) { }

    void OnUpdate(uint32 diff) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        _scheduler.Update(diff);

        if (_timer < diff)
        {
            switch (_state)
            {
                case BG_RV_STATE_OPEN_FENCES:
                    // Open fire (only at game start)
                    for (ObjectGuid const& guid : _fireGUIDs)
                        if (GameObject* go = battlegroundMap->GetGameObject(guid))
                            go->UseDoorOrButton();
                    for (ObjectGuid const& guid : _firedoorGUIDs)
                        if (GameObject* go = battlegroundMap->GetGameObject(guid))
                            go->UseDoorOrButton();
                    _timer = BG_RV_CLOSE_FIRE_TIMER;
                    _state = BG_RV_STATE_CLOSE_FIRE;
                    break;
                case BG_RV_STATE_CLOSE_FIRE:
                    for (ObjectGuid const& guid : _fireGUIDs)
                        if (GameObject* go = battlegroundMap->GetGameObject(guid))
                            go->ResetDoorOrButton();
                    for (ObjectGuid const& guid : _firedoorGUIDs)
                        if (GameObject* go = battlegroundMap->GetGameObject(guid))
                            go->ResetDoorOrButton();
                    // Fire got closed after five seconds, leaves twenty seconds before toggling pillars
                    _timer = BG_RV_FIRE_TO_PILLAR_TIMER;
                    _state = BG_RV_STATE_SWITCH_PILLARS;
                    break;
                case BG_RV_STATE_SWITCH_PILLARS:
                    TogglePillarCollision();
                    _timer = BG_RV_PILLAR_SWITCH_TIMER;
                    break;
                default:
                    break;
            }
        }
        else
            _timer -= diff;
    }

    void OnInit() override
    {
        CreateObject(BG_RV_OBJECT_TYPE_ELEVATOR_1, 763.536377f, -294.535767f, 0.505383f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_ELEVATOR_2, 763.506348f, -273.873352f, 0.505383f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);

        CreateObject(BG_RV_OBJECT_TYPE_FIRE_1, 743.543457f, -283.799469f, 28.286655f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_FIRE_2, 782.971802f, -283.799469f, 28.286655f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_FIREDOOR_1, 743.711060f, -284.099609f, 27.542587f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_FIREDOOR_2, 783.221252f, -284.133362f, 27.535686f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);

        CreateObject(BG_RV_OBJECT_TYPE_GEAR_1, 763.664551f, -261.872986f, 26.686588f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_GEAR_2, 763.578979f, -306.146149f, 26.665222f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PULLEY_1, 700.722290f, -283.990662f, 39.517582f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PULLEY_2, 826.303833f, -283.996429f, 39.517582f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_1, 763.632385f, -306.162384f, 25.909504f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_2, 723.644287f, -284.493256f, 24.648525f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_3, 763.611145f, -261.856750f, 25.909504f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_4, 802.211609f, -284.493256f, 24.648525f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_COLLISION_1, 763.632385f, -306.162384f, 30.639660f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_COLLISION_2, 723.644287f, -284.493256f, 32.382710f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_COLLISION_3, 763.611145f, -261.856750f, 30.639660f, 0.000000f, 0.0f, 0.0f, 0.0f, 0.0f);
        CreateObject(BG_RV_OBJECT_TYPE_PILAR_COLLISION_4, 802.211609f, -284.493256f, 32.382710f, 3.141593f, 0.0f, 0.0f, 0.0f, 0.0f);
    }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _elevatorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }

        _state = BG_RV_STATE_OPEN_FENCES;
        _timer = BG_RV_FIRST_TIMER;

        // Should be false at first, TogglePillarCollision will do it.
        _pillarCollision = true;
        TogglePillarCollision();

        _scheduler.Schedule(1min, [&](TaskContext)
        {
            CreateObject(BG_RV_OBJECT_TYPE_BUFF_1, 735.551819f, -284.794678f, 28.276682f, 0.034906f, 0.0f, 0.0f, 0.0f, 0.0f);
            CreateObject(BG_RV_OBJECT_TYPE_BUFF_2, 791.224487f, -284.794464f, 28.276682f, 2.600535f, 0.0f, 0.0f, 0.0f, 0.0f);
        });
    }

    void TogglePillarCollision()
    {
        // Toggle visual pillars, pulley, gear, and collision based on previous state

        GuidVector smallPillarGuids;
        smallPillarGuids.insert(std::end(smallPillarGuids), std::begin(_pillarSmallGUIDs), std::end(_pillarSmallGUIDs));
        smallPillarGuids.insert(std::end(smallPillarGuids), std::begin(_gearGUIDs), std::end(_gearGUIDs));

        for (ObjectGuid const& guid : smallPillarGuids)
        {
            if (GameObject* go = battlegroundMap->GetGameObject(guid))
            {
                if (_pillarCollision)
                    go->UseDoorOrButton();
                else
                    go->ResetDoorOrButton();
            }
        }

        GuidVector bigPillarGuids;
        bigPillarGuids.insert(std::end(bigPillarGuids), std::begin(_pillarBigGUIDs), std::end(_pillarBigGUIDs));
        bigPillarGuids.insert(std::end(bigPillarGuids), std::begin(_pulleyGUIDs), std::end(_pulleyGUIDs));

        for (ObjectGuid const& guid : bigPillarGuids)
        {
            if (GameObject* go = battlegroundMap->GetGameObject(guid))
            {
                if (_pillarCollision)
                    go->ResetDoorOrButton();
                else
                    go->UseDoorOrButton();
            }
        }

        GuidVector allObjects;
        allObjects.insert(std::end(allObjects), std::begin(smallPillarGuids), std::end(smallPillarGuids));
        allObjects.insert(std::end(allObjects), std::begin(bigPillarGuids), std::end(bigPillarGuids));
        allObjects.insert(std::end(allObjects), std::begin(_pillarSmallCollisionGUIDs), std::end(_pillarSmallCollisionGUIDs));
        allObjects.insert(std::end(allObjects), std::begin(_pillarBigCollisionGUIDs), std::end(_pillarBigCollisionGUIDs));

        for (ObjectGuid const& guid : allObjects)
        {
            if (GameObject* go = battlegroundMap->GetGameObject(guid))
            {
                bool isCollision = false;
                switch (go->GetEntry())
                {
                    case BG_RV_OBJECT_TYPE_PILAR_COLLISION_1:
                    case BG_RV_OBJECT_TYPE_PILAR_COLLISION_2:
                    case BG_RV_OBJECT_TYPE_PILAR_COLLISION_3:
                    case BG_RV_OBJECT_TYPE_PILAR_COLLISION_4:
                        isCollision = true;
                    break;
                    default:
                        break;
                }

                if (isCollision)
                {
                    GOState state = ((go->GetGOInfo()->door.startOpen != 0) == _pillarCollision) ? GO_STATE_ACTIVE : GO_STATE_READY;
                    go->SetGoState(state);
                }

                for (auto const& [playerGuid, _]: battleground->GetPlayers())
                    if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                        go->SendUpdateToPlayer(player);
            }
        }

        _pillarCollision = !_pillarCollision;
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        ArenaScript::OnGameObjectCreate(gameobject);

        switch (gameobject->GetEntry())
        {
            case BG_RV_OBJECT_TYPE_ELEVATOR_1:
            case BG_RV_OBJECT_TYPE_ELEVATOR_2:
                _elevatorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_FIRE_1:
            case BG_RV_OBJECT_TYPE_FIRE_2:
                _fireGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_FIREDOOR_1:
            case BG_RV_OBJECT_TYPE_FIREDOOR_2:
                _firedoorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_GEAR_1:
            case BG_RV_OBJECT_TYPE_GEAR_2:
                _gearGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_PILAR_1:
            case BG_RV_OBJECT_TYPE_PILAR_3:
                _pillarSmallGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_PILAR_2:
            case BG_RV_OBJECT_TYPE_PILAR_4:
                _pillarBigGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_PILAR_COLLISION_1:
            case BG_RV_OBJECT_TYPE_PILAR_COLLISION_3:
                _pillarSmallCollisionGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_PILAR_COLLISION_2:
            case BG_RV_OBJECT_TYPE_PILAR_COLLISION_4:
                _pillarBigCollisionGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case BG_RV_OBJECT_TYPE_PULLEY_1:
            case BG_RV_OBJECT_TYPE_PULLEY_2:
                _pulleyGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    GuidVector _elevatorGUIDs;
    GuidVector _gearGUIDs;
    GuidVector _fireGUIDs;
    GuidVector _firedoorGUIDs;
    GuidVector _pillarSmallCollisionGUIDs;
    GuidVector _pillarBigCollisionGUIDs;
    GuidVector _pillarSmallGUIDs;
    GuidVector _pillarBigGUIDs;
    GuidVector _pulleyGUIDs;
    TaskScheduler _scheduler;

    uint32 _timer;
    uint32 _state;
    bool   _pillarCollision;
};

void AddSC_arena_ring_of_valor()
{
    RegisterBattlegroundMapScript(arena_ring_of_valor, 618);
}

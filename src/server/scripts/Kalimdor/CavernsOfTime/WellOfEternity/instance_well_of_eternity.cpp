/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

// 108469
#include "ScriptMgr.h"
#include "well_of_eternity.h"
#include "GameObject.h"

#define MAX_ENCOUNTER 3

static const DoorData doordata[] =
{
    {GO_INVISIBLE_FIREWALL_DOOR,    DATA_PEROTHARN, DOOR_TYPE_PASSAGE   },
    {0,                             0,              DOOR_TYPE_ROOM      },
};

class instance_well_of_eternity : public InstanceMapScript
{
public:
    instance_well_of_eternity() : InstanceMapScript("instance_well_of_eternity", 939) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_well_of_eternity_InstanceMapScript(map);
    }

    struct instance_well_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_well_of_eternity_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doordata);

            uiEventNozdormu = 0;
            uiEventDemon = 0;
            uiEventIllidan1 = 0;

            uiPerotharnGUID = ObjectGuid::Empty;
            uiIllidan2GUID = ObjectGuid::Empty;
            uiVarothenGUID = ObjectGuid::Empty;
            uiMannorothGUID = ObjectGuid::Empty;

            uiRoyalCacheGUID = ObjectGuid::Empty;
            uiMinorCacheGUID = ObjectGuid::Empty;
            uiCourtyardDoor1GUID = ObjectGuid::Empty;
            uiLargeFirewallDoorGUID = ObjectGuid::Empty;
            uiPerotharnDoors.clear();
            uiAfterPerotharnDoors.clear();
        }

        void OnCreatureCreate(Creature* pCreature) override
        {
            switch (pCreature->GetEntry())
            {
                case NPC_PEROTHARN:
                    uiPerotharnGUID = pCreature->GetGUID();
                    break;
                case NPC_ILLIDAN_2:
                    uiIllidan2GUID = pCreature->GetGUID();
                    break;
                case NPC_VAROTHEN:
                    uiVarothenGUID = pCreature->GetGUID();
                    break;
                case NPC_MANNOROTH:
                    uiMannorothGUID = pCreature->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* pGo) override
        {
            switch (pGo->GetEntry())
            {
                case GO_ROYAL_CACHE:
                    uiRoyalCacheGUID = pGo->GetGUID();
                    break;
                case GO_MINOR_CACHE:
                    uiMinorCacheGUID = pGo->GetGUID();
                    break;
                case GO_INVISIBLE_FIREWALL_DOOR:
                    AddDoor(pGo, true);
                    break;
                case GO_COURTYARD_DOOR_1:
                    uiCourtyardDoor1GUID = pGo->GetGUID();
                    if (uiEventDemon == DONE)
                        HandleGameObject(uiCourtyardDoor1GUID, true, pGo);
                    break;
                case GO_LARGE_FIREWALL_DOOR:
                    if (pGo->GetPositionX() <= 3200.0f)
                    {
                        uiLargeFirewallDoorGUID = pGo->GetGUID();
                        if (uiEventDemon == DONE)
                            HandleGameObject(uiLargeFirewallDoorGUID, true, pGo);
                    } else
                    {
                        uiPerotharnDoors.push_back(pGo->GetGUID());
                        if (GetBossState(DATA_PEROTHARN) == IN_PROGRESS)
                            HandleGameObject(pGo->GetGUID(), false, pGo);
                        else
                            HandleGameObject(pGo->GetGUID(), true, pGo);
                    }
                    break;
                case GO_SMALL_FIREWALL_DOOR:
                    if (pGo->GetPositionX() <= 3340.0f)
                    {
                        uiPerotharnDoors.push_back(pGo->GetGUID());
                        if (GetBossState(DATA_PEROTHARN) == IN_PROGRESS)
                            HandleGameObject(pGo->GetGUID(), false, pGo);
                        else
                            HandleGameObject(pGo->GetGUID(), true, pGo);
                    } else
                    {
                        uiAfterPerotharnDoors.push_back(pGo->GetGUID());
                        if (GetBossState(DATA_PEROTHARN) == DONE)
                            HandleGameObject(pGo->GetGUID(), true, pGo);
                        else
                            HandleGameObject(pGo->GetGUID(), false, pGo);
                    }
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_EVENT_NOZDORMU:
                    uiEventNozdormu = data;
                    if (data == DONE)
                        SaveToDB();
                    break;
                case DATA_EVENT_DEMON:
                    uiEventDemon = data;
                    if (data == DONE)
                    {
                        HandleGameObject(uiCourtyardDoor1GUID, true);
                        HandleGameObject(uiLargeFirewallDoorGUID, true);
                        SaveToDB();
                    }
                    break;
                case DATA_EVENT_ILLIDAN_1:
                    uiEventIllidan1 = data;
                    if (data == DONE)
                        SaveToDB();
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override 
        {
            switch (type)
            {
                case DATA_EVENT_NOZDORMU:
                    return uiEventNozdormu;
                case DATA_EVENT_DEMON:
                    return uiEventDemon;
                case DATA_EVENT_ILLIDAN_1:
                    return uiEventIllidan1;
                default:
                    return 0;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_PEROTHARN:
                    return uiPerotharnGUID;
                case DATA_ROYAL_CACHE:
                    return uiRoyalCacheGUID;
                case DATA_MINOR_CACHE:
                    return uiMinorCacheGUID;
                case DATA_EVENT_ILLIDAN_2:
                    return uiIllidan2GUID;
                case DATA_VAROTHEN:
                    return uiVarothenGUID;
                case DATA_MANNOROTH:
                    return uiMannorothGUID;
                default:
                    break;
            }

            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type == DATA_PEROTHARN)
            {
                if (state == IN_PROGRESS)
                {
                    if (!uiPerotharnDoors.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = uiPerotharnDoors.begin(); itr != uiPerotharnDoors.end(); ++itr)
                        HandleGameObject((*itr), false);
                } else
                {
                    if (!uiPerotharnDoors.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = uiPerotharnDoors.begin(); itr != uiPerotharnDoors.end(); ++itr)
                        HandleGameObject((*itr), true);
                }
                if (state == DONE)
                {
                    if (!uiAfterPerotharnDoors.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = uiAfterPerotharnDoors.begin(); itr != uiAfterPerotharnDoors.end(); ++itr)
                        HandleGameObject((*itr), true);
                } else
                {
                    if (!uiAfterPerotharnDoors.empty())
                    for (std::vector<ObjectGuid>::const_iterator itr = uiAfterPerotharnDoors.begin(); itr != uiAfterPerotharnDoors.end(); ++itr)
                        HandleGameObject((*itr), false);
                }
            }

            return true;
        }

    private:
        uint32 uiEventNozdormu;
        uint32 uiEventDemon;
        uint32 uiEventIllidan1;

        ObjectGuid uiPerotharnGUID;
        ObjectGuid uiIllidan2GUID;
        ObjectGuid uiVarothenGUID;
        ObjectGuid uiMannorothGUID;

        ObjectGuid uiRoyalCacheGUID;
        ObjectGuid uiMinorCacheGUID;
        ObjectGuid uiCourtyardDoor1GUID;
        ObjectGuid uiLargeFirewallDoorGUID;
        std::vector<ObjectGuid> uiAfterPerotharnDoors;
        std::vector<ObjectGuid> uiPerotharnDoors;

    };
};

void AddSC_instance_well_of_eternity()
{
    new instance_well_of_eternity();
}

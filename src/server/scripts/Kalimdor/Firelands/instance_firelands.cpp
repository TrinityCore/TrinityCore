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

#include "firelands.h"
#include "GameObject.h"
#include "ScriptMgr.h"

// areatrigger
// 6929 - quest1
// 6861 - near miniboss 1

#define MAX_ENCOUNTER 7

static const DoorData doordata[] =
{
    { GO_BRIDGE_OF_RHYOLITH,    DATA_RHYOLITH,  DOOR_TYPE_ROOM          },
    { GO_FIRE_WALL_BALEROC,     DATA_BALEROC,   DOOR_TYPE_ROOM          },
    { GO_RAID_BRIDGE_FORMING,   DATA_BALEROC,   DOOR_TYPE_PASSAGE       },
    { GO_STICKY_WEB,            DATA_BETHTILAC, DOOR_TYPE_ROOM          },
    { GO_BRIDGE_OF_RHYOLITH,    DATA_RHYOLITH,  DOOR_TYPE_SPAWN_HOLE    },
    { GO_FIRE_WALL_FENDRAL,     DATA_STAGHELM,  DOOR_TYPE_PASSAGE       },
    { GO_DOOR_RAGNAROS,         DATA_RAGNAROS,  DOOR_TYPE_ROOM          },
    { 0,                        0,              DOOR_TYPE_ROOM          },
};

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript("instance_firelands", 720) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_firelands_InstanceMapScript(map);
        }

        struct instance_firelands_InstanceMapScript : public InstanceScript
        {
            instance_firelands_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doordata);

                uiRhyolithHealth        = 0;
                uiTimer                 = 0;
                bEvent                  = false;
                AEvent                  = EVENT_MAJORDOMO_NOT_DONE;

                creaturePortals.clear();
                gameobjectPortals.clear();
            }

            void OnPlayerEnter(Player* pPlayer) override
            {
                if (!uiTeamInInstance)
                    uiTeamInInstance = pPlayer->GetTeam();
            }

            void OnCreatureCreate(Creature* pCreature) override
            {
                switch (pCreature->GetEntry())
                {
                    case NPC_SHANNOX:
                        uiShannoxGUID = pCreature->GetGUID();
                        break;
                    case NPC_RIPLIMB:
                        uiRiplimbGUID = pCreature->GetGUID();
                        break;
                    case NPC_RAGEFACE:
                        uiRagefaceGUID = pCreature->GetGUID();
                        break;
                    case NPC_CIRCLE_OF_THRONES_PORTAL:
                        creaturePortals.push_back(pCreature);
                        if (uiEvent == DONE)
                        {
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_SPELLCLICK);
                        }
                        break;
                    case NPC_SMOULDERING_HATCHLING:
                        // Cannot directly start attacking here as the creature is not yet on map
                        pCreature->m_Events.AddEvent(new DelayedAttackStartEvent(pCreature), pCreature->m_Events.CalculateTime(500));
                        break;
                    case NPC_RAGNAROS:
                        uiRagnarosGUID = pCreature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* pGo) override
            {
                switch (pGo->GetEntry())
                {
                    case GO_FIRE_WALL_BALEROC:
                    {
                        BalerocDoorGUID = pGo->GetGUID();

                        if (GetBossState(DATA_SHANNOX) == DONE && GetBossState(NPC_BETHTILAC) == DONE && GetBossState(NPC_RHYOLITH) == DONE && GetBossState(NPC_ALYSRAZOR) == DONE)
                            HandleGameObject(BalerocDoorGUID, true, pGo);

                        break;
                    }
                    case GO_STICKY_WEB:
                    case GO_RAID_BRIDGE_FORMING:
                    case GO_BRIDGE_OF_RHYOLITH:
                    case GO_FIRE_WALL_FENDRAL:
                    case GO_DOOR_RAGNAROS:
                        AddDoor(pGo, true);
                        break;
                    case GO_CIRCLE_OF_THORNS_PORTAL3:
                        gameobjectPortals.push_back(pGo);
                        if (uiEvent == DONE)
                            HandleGameObject(pGo->GetGUID(), true, pGo);
                        break;
                    case GO_SULFURON_BRIDGE:
                    {
                        uiSulfuronBrideGUID = pGo->GetGUID();
                        pGo->SetDestructibleState(GetBossState(DATA_BALEROC) == DONE ? GO_DESTRUCTIBLE_DESTROYED: GO_DESTRUCTIBLE_INTACT);
                        break;
                    }
                    case GO_PLATFORM_RAGN:
                        uiRagnarosPlatformGUID = pGo->GetGUID();
                        break;

                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_RHYOLITH_HEALTH_SHARED)
                    uiRhyolithHealth = data;
                else if (type == DATA_EVENT)
                {
                    uiEvent = data;
                    if (uiEvent == DONE)
                    {
                        if (!gameobjectPortals.empty())
                        {
                            for (std::list<GameObject*>::const_iterator itr = gameobjectPortals.begin(); itr != gameobjectPortals.end(); ++itr)
                                if (GameObject* pGo = (*itr)->ToGameObject())
                                    HandleGameObject(pGo->GetGUID(), true, pGo);
                        }

                        if (!creaturePortals.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = creaturePortals.begin(); itr != creaturePortals.end(); ++itr)
                                if (Creature* pCreature = (*itr)->ToCreature())
                                {
                                    pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_SPELLCLICK);
                                }
                        }

                        SaveToDB();
                    }
                }
                else if (type == DATA_MAJORDOMO_ALYSRAZOR)
                {
                    AEvent = data;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_RHYOLITH_HEALTH_SHARED:   return uiRhyolithHealth;
                    case DATA_EVENT:                    return uiEvent;
                    case DATA_MAJORDOMO_ALYSRAZOR:      return AEvent;
                    case DATA_TEAM:                     return uiTeamInInstance;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SHANNOX:              return uiShannoxGUID;
                    case DATA_RIPLIMB:              return uiRiplimbGUID;
                    case DATA_RAGEFACE:             return uiRagefaceGUID;
                    case GO_SULFURON_BRIDGE:        return uiSulfuronBrideGUID;
                    case DATA_RAGNAROS_PLATFORM:    return uiRagnarosPlatformGUID;
                    case NPC_RAGNAROS:              return uiRagnarosGUID;
                    default: return ObjectGuid::Empty;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_SHANNOX:
                    case DATA_RHYOLITH:
                    case DATA_BETHTILAC:
                    case DATA_ALYSRAZOR:
                    {
                        if (state == DONE)
                        {
                            if (GetBossState(DATA_SHANNOX) == DONE && GetBossState(DATA_BETHTILAC) == DONE && GetBossState(DATA_RHYOLITH) == DONE && GetBossState(DATA_ALYSRAZOR) == DONE)
                            {
                                //on ouvre la porte de baleroc
                                HandleGameObject(BalerocDoorGUID, true);
                            }
                        }
                        break;
                    }
                    case DATA_BALEROC:
                    {
                        if (GameObject* bridge = instance->GetGameObject(GetGuidData(GO_SULFURON_BRIDGE)))
                            bridge->SetDestructibleState(state == DONE ? GO_DESTRUCTIBLE_DESTROYED: GO_DESTRUCTIBLE_INTACT);
                        break;
                    }
                    case DATA_STAGHELM:
                    case DATA_RAGNAROS:
                        break;
                }

                return true;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* /*player = nullptr*/) const override
            {
                switch (bossId)
                {
                    case DATA_BALEROC:
                        return GetBossState(DATA_SHANNOX) == DONE && GetBossState(NPC_BETHTILAC) == DONE && GetBossState(NPC_RHYOLITH) == DONE && GetBossState(NPC_ALYSRAZOR) == DONE;
                    default:
                        break;
                }

                return true;
            }

            void ProcessEvent(WorldObject* /*source*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_PORTALS:
                    {
                        if ((uiEvent == DONE) || bEvent)
                            return;
                        bEvent = true;
                        uiTimer = 7000;
                        if (!creaturePortals.empty())
                            for (std::list<Creature*>::const_iterator itr = creaturePortals.begin(); itr != creaturePortals.end(); ++itr)
                                if (Creature* pCreature = (*itr)->ToCreature())
                                    pCreature->CastSpell(pCreature, SPELL_LEGENDARY_PORTAL_OPENING);
                        break;
                    }
                }
            }

            void Update(uint32 diff) override
            {
                if (bEvent)
                {
                    if (uiTimer <= diff)
                    {
                        bEvent = false;
                        SetData(DATA_EVENT, DONE);
                    }
                    else
                        uiTimer -= diff;
                }
            }

            private:
                uint32 uiTeamInInstance;
                uint32 uiRhyolithHealth;
                uint32 uiEvent;
                uint32 uiTimer;
                bool bEvent;
                ObjectGuid uiShannoxGUID;
                ObjectGuid uiRiplimbGUID;
                ObjectGuid uiRagefaceGUID;
                ObjectGuid uiSulfuronBrideGUID;
                ObjectGuid uiRagnarosGUID;
                ObjectGuid uiRagnarosPlatformGUID;
                ObjectGuid BalerocDoorGUID;
                std::list<GameObject*> gameobjectPortals;
                std::list<Creature*> creaturePortals;
                uint32 AEvent;
        };
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}

/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "gate_of_the_setting_sun.h"

enum Spells
{
    SPELL_EXPLOSION = 115456
};

DoorData const doorData[] =
{
    { GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM,    },
    { GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM,    },
    { GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM,    },
    { GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM,    },
    { GO_KIPTILAK_EXIT_DOOR,                 DATA_KIPTILAK,              DOOR_TYPE_PASSAGE, },
    { GO_RIMAK_AFTER_DOOR,                   DATA_RIMOK,                 DOOR_TYPE_ROOM,    },
    { GO_RAIGONN_DOOR,                       DATA_RAIGONN,               DOOR_TYPE_ROOM,    },
    { GO_RAIGONN_AFTER_DOOR,                 DATA_RAIGONN,               DOOR_TYPE_PASSAGE, },
    { 0,                                     0,                          DOOR_TYPE_ROOM,    }  // END
};

ObjectData const creatureData[] =
{
    { NPC_KIPTILAK,     DATA_KIPTILAK },
    { NPC_GADOK,        DATA_GADOK    },
    { NPC_RIMOK,        DATA_RIMOK    },
    { NPC_RAIGONN,      DATA_RAIGONN  },
    { 0,                0             } // END
};

class instance_gate_of_the_setting_sun : public InstanceMapScript
{
    public:
        instance_gate_of_the_setting_sun() : InstanceMapScript(GSSScriptName, 962) { }

        struct instance_gate_of_the_setting_sun_InstanceMapScript : public InstanceScript
        {
            ObjectGuid raigonWeakGuid;

            ObjectGuid firstDoorGuid;
            ObjectGuid fireSignalGuid;

            ObjectGuid wallCGuid;
            ObjectGuid portalTempGadokGuid;

            uint32 cinematicTimer;
            uint8 cinematicEventProgress;

            std::list<ObjectGuid> bombarderGuids;
            std::list<ObjectGuid> bombStalkerGuids;
            std::list<ObjectGuid> mantidBombsGUIDs;
            std::list<ObjectGuid> rimokAddGenetarorsGUIDs;
            std::list<ObjectGuid> artilleryGUIDs;
            std::list<ObjectGuid> secondaryDoorGUIDs;

            uint32 dataStorage[MAX_DATA];

            instance_gate_of_the_setting_sun_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, nullptr);

                cinematicTimer = 0;
                cinematicEventProgress = 0;

                memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
            }

            void OnDestroy(InstanceMap* /*map*/) override
            {
                if (Creature* weakSpot = instance->GetCreature(GetObjectGuid(NPC_WEAK_SPOT)))
                    weakSpot->_ExitVehicle();
            }

            void OnPlayerEnter(Player* player) override
            {
                if (GetData(DATA_BRASIER_CLICKED) == NOT_STARTED)
                    player->SetInPhase(1, true, true);
                else
                    player->SetInPhase(2, true, true);
            }

            void OnPlayerLeave(Player* player) override
            {
                player->SetInPhase(1, true, true);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_KRITHUK_BOMBARDER:
                        bombarderGuids.push_back(creature->GetGUID());
                        return;
                    case NPC_BOMB_STALKER:
                        bombStalkerGuids.push_back(creature->GetGUID());
                        return;
                    case NPC_ADD_GENERATOR:
                        rimokAddGenetarorsGUIDs.push_back(creature->GetGUID());
                        return;
                    case NPC_ARTILLERY:
                        artilleryGUIDs.push_back(creature->GetGUID());
                        return;
                    default:
                        return;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_KRITHUK_BOMBARDER:
                        bombarderGuids.remove(creature->GetGUID());
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureRemove(creature);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_KIPTILAK_ENTRANCE_DOOR:
                        firstDoorGuid = go->GetGUID();
                        break;
                    case GO_SIGNAL_FIRE:
                        fireSignalGuid = go->GetGUID();
                        break;
                    case GO_KIPTILAK_MANTID_BOMBS:
                        mantidBombsGUIDs.push_back(go->GetGUID());
                        return;
                    case GO_GREATDOOR_SECOND_DOOR:
                        secondaryDoorGUIDs.push_back(go->GetGUID());
                        HandleGameObject(go->GetGUID(), true, go);
                        return;
                    case GO_WALL_C:
                        wallCGuid = go->GetGUID();
                        return;
                    case GO_PORTAL_TEMP_GADOK:
                        portalTempGadokGuid = go->GetGUID();
                        return;
                    default:
                        break;
                }

                InstanceScript::OnGameObjectCreate(go);
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case DATA_KIPTILAK:
                    {
                        if (state == DONE)
                            for (ObjectGuid const& guid : mantidBombsGUIDs)
                                if (GameObject* bomb = instance->GetGameObject(guid))
                                    bomb->SetInPhase(32768, true, true); // Set Invisible
                        break;
                    }
                    case DATA_GADOK:
                    {
                        if (GameObject* portal = instance->GetGameObject(portalTempGadokGuid))
                            portal->SetInPhase(state == IN_PROGRESS ? 4 : 3, true, true);
                        break;
                    }
                    case DATA_RIMOK:
                    {
                        uint8 generatorsCount = 0;

                        for (ObjectGuid const& guid : secondaryDoorGUIDs)
                            HandleGameObject(guid, state != DONE);

                        for (ObjectGuid const& guid : rimokAddGenetarorsGUIDs)
                        {
                            if (Creature* generator = instance->GetCreature(guid))
                            {
                                if (generator->AI())
                                {
                                    // There is 7 add generators, the middle one spawn saboteur
                                    if (state == IN_PROGRESS && (++generatorsCount == 4))
                                        generator->AI()->DoAction(SPECIAL);
                                    else
                                        generator->AI()->DoAction(state);
                                }
                            }
                        }
                        break;
                    }
                    case DATA_RAIGONN:
                    {
                        for (ObjectGuid const& guid : artilleryGUIDs)
                        {
                            if (Creature* artillery = instance->GetCreature(guid))
                            {
                                artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, state != IN_PROGRESS);
                                artillery->ApplyModFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, state == IN_PROGRESS);
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_OPEN_FIRST_DOOR:
                    {
                        if (dataStorage[type] == DONE)
                            return;

                        HandleGameObject(firstDoorGuid, true);

                        dataStorage[type] = data;

                        if (GameObject* firstDoor = instance->GetGameObject(firstDoorGuid))
                        {
                            if (Creature* trigger = firstDoor->SummonTrigger(firstDoor->GetPositionX(), firstDoor->GetPositionY(), firstDoor->GetPositionZ(), 0, 500))
                            {
                                std::list<Creature*> defensorList;
                                GetCreatureListWithEntryInGrid(defensorList, trigger, 65337, 20.0f);

                                trigger->CastSpell(trigger, SPELL_EXPLOSION); // Explosion

                                for (std::list<Creature*>::iterator itr = defensorList.begin(); itr != defensorList.end(); ++itr)
                                {
                                    uint8 random = urand(0, 1);

                                    float posX = random ? 814.0f:  640.0f;
                                    float posY = random ? 2102.0f: 2112.0f;
                                    (*itr)->KnockbackFrom(posX, posY, 25.0f, 20.0f);
                                    (*itr)->DespawnOrUnsummon(1000);
                                }
                            }
                        }
                        break;
                    }
                    case DATA_BRASIER_CLICKED:
                    {
                        if (dataStorage[type] == DONE)
                            return;

                        if (GetBossState(DATA_GADOK) != DONE)
                            return;

                        Map::PlayerList const &PlayerList = instance->GetPlayers();
                        for (Map::PlayerList::const_iterator it = PlayerList.begin(); it != PlayerList.end(); ++it)
                        {
                            if (Player* player = it->GetSource())
                            {
                                player->SendCinematicStart(CINEMATIC_SETTING_SUN);
                                player->SetInPhase(2, true, true);
                                player->NearTeleportTo(1370.0f, 2283.6f, 402.328f, 2.70f);
                            }
                        }

                        cinematicTimer = 100;
                        dataStorage[type] = data;
                        break;
                    }
                    default:
                        if (type < MAX_DATA)
                            dataStorage[type] = data;
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_OPEN_FIRST_DOOR:
                    default:
                        if (type < MAX_DATA)
                            return dataStorage[type];
                        break;
                }

                return 0;
            }

            void SetData64(uint32 type, uint64 value) override
            {
                switch (type)
                {
                    case NPC_WEAK_SPOT:
                        raigonWeakGuid = GetObjectGuid(value);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case NPC_WEAK_SPOT:
                        return raigonWeakGuid.GetEntry();
                    case DATA_RANDOM_BOMBARDER:
                        return Trinity::Containers::SelectRandomContainerElement(bombarderGuids).GetEntry();
                    case DATA_RANDOM_BOMB_STALKER:
                        return Trinity::Containers::SelectRandomContainerElement(bombStalkerGuids).GetEntry();
                }

                return 0;
            }

            void doEventCinematic()
            {
                switch (cinematicEventProgress)
                {
                    case 0:
                        // On allume le brasier & la meche
                        cinematicTimer = 6000;
                        break;
                    case 1:
                        if (GameObject* go = instance->GetGameObject(fireSignalGuid))
                            go->UseDoorOrButton();
                        cinematicTimer = 5000;
                        break;
                    case 2:
                        if (GameObject* go = instance->GetGameObject(wallCGuid))
                            go->ModifyHealth(-100000);
                        cinematicTimer = 0;
                        break;
                }

                ++cinematicEventProgress;
            }

            void Update(uint32 diff) override
            {
                if (cinematicTimer)
                {
                    if (cinematicTimer <= diff)
                        doEventCinematic();
                    else
                        cinematicTimer -= diff;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_gate_of_the_setting_sun_InstanceMapScript(map);
        }
};

void AddSC_instance_gate_of_the_setting_sun()
{
    new instance_gate_of_the_setting_sun();
}

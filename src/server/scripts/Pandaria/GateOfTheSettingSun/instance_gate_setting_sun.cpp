/*
 * Copyright 2021 ShadowCore
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
#include "InstanceScript.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "gate_setting_sun.h"

DoorData const doorData[] =
{
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM},
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM},
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM},
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM},
    {GO_KIPTILAK_EXIT_DOOR,                 DATA_KIPTILAK,              DOOR_TYPE_PASSAGE},
    {GO_RIMAK_AFTER_DOOR,                   DATA_RIMOK,                 DOOR_TYPE_ROOM},
    {GO_RAIGONN_DOOR,                       DATA_RAIGONN,               DOOR_TYPE_ROOM},
    {GO_RAIGONN_AFTER_DOOR,                 DATA_RAIGONN,               DOOR_TYPE_PASSAGE},
    {0,                                     0,                          DOOR_TYPE_ROOM},// END
};

class instance_gate_setting_sun : public InstanceMapScript
{
public:
    instance_gate_setting_sun() : InstanceMapScript("instance_gate_setting_sun", 962) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_gate_setting_sun_InstanceMapScript(map);
    }

    struct instance_gate_setting_sun_InstanceMapScript : public InstanceScript
    {
        ObjectGuid kiptilakGUID;
        ObjectGuid gadokGUID;
        ObjectGuid rimokGUID;
        ObjectGuid raigonnGUID;
        ObjectGuid raigonWeakGUID;

        ObjectGuid firstDoorGUID;
        ObjectGuid fireSignalGUID;

        ObjectGuid wallCGUID;
        ObjectGuid portalTempGadokGUID;

        uint32 cinematicTimer;
        uint8 cinematicEventProgress;

        std::list<ObjectGuid> bombarderGuids;
        std::list<ObjectGuid> bombStalkerGuids;
        std::list<ObjectGuid> mantidBombsGUIDs;
        std::list<ObjectGuid> rimokAddGenetarorsGUIDs;
        std::list<ObjectGuid> artilleryGUIDs;
        std::list<ObjectGuid> secondaryDoorGUIDs;

        uint32 dataStorage[MAX_DATA];

        instance_gate_setting_sun_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);

            kiptilakGUID            = ObjectGuid::Empty;
            gadokGUID               = ObjectGuid::Empty;
            rimokGUID               = ObjectGuid::Empty;
            raigonnGUID             = ObjectGuid::Empty;
            raigonWeakGUID          = ObjectGuid::Empty;

            firstDoorGUID           = ObjectGuid::Empty;

            cinematicTimer          = 0;
            cinematicEventProgress  = 0;

            wallCGUID               = ObjectGuid::Empty;
            portalTempGadokGUID     = ObjectGuid::Empty;

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));

            bombarderGuids.clear();
            bombStalkerGuids.clear();
            mantidBombsGUIDs.clear();
            rimokAddGenetarorsGUIDs.clear();
            artilleryGUIDs.clear();
            secondaryDoorGUIDs.clear();
        }

        void OnDestroy(InstanceMap* /*map*/)
        {
            if (Creature* weakSpot = instance->GetCreature(GetGuidData(NPC_WEAK_SPOT)))
                weakSpot->_ExitVehicle();
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetData(DATA_BRASIER_CLICKED) == NOT_STARTED)
                PhasingHandler::ResetPhaseShift(player);
            else
                PhasingHandler::AddPhase(player, 50);
        }

        void OnPlayerLeave(Player* player)
        {
            PhasingHandler::ResetPhaseShift(player);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_KIPTILAK:
                    kiptilakGUID = creature->GetGUID();
                    return;
                case NPC_GADOK:
                    gadokGUID = creature->GetGUID();
                    return;
                case NPC_RIMOK:
                    rimokGUID = creature->GetGUID();
                    return;
                case NPC_RAIGONN:
                    raigonnGUID = creature->GetGUID();
                    return;
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
        }

        void OnCreatureRemove(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_KRITHUK_BOMBARDER:
                    for (std::list<ObjectGuid>::iterator it = bombarderGuids.begin(); it != bombarderGuids.end(); ++it)
                    {
                        if (*it == creature->GetGUID())
                        {
                            bombarderGuids.erase(it);
                            break;
                        }
                    }
                    break;
                default:
                    return;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_KIPTILAK_ENTRANCE_DOOR:
                    firstDoorGUID = go->GetGUID();
                    break;
                case GO_SIGNAL_FIRE:
                    fireSignalGUID = go->GetGUID();
                    break;
                case GO_KIPTILAK_WALLS:
                case GO_KIPTILAK_EXIT_DOOR:
                case GO_RIMAK_AFTER_DOOR:
                case GO_RAIGONN_AFTER_DOOR:
                    AddDoor(go, true);
                    return;
                case GO_KIPTILAK_MANTID_BOMBS:
                    mantidBombsGUIDs.push_back(go->GetGUID());
                    return;
                case GO_GREATDOOR_SECOND_DOOR:
                    secondaryDoorGUIDs.push_back(go->GetGUID());
                    HandleGameObject(go->GetGUID(), true, go);
                    return;
                case GO_WALL_C:
                    wallCGUID = go->GetGUID();
                    return;
                case GO_PORTAL_TEMP_GADOK:
                    portalTempGadokGUID = go->GetGUID();
                    return;
                default:
                    return;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_KIPTILAK:
                {
                    /*if (state == DONE)
                        for (auto itr: mantidBombsGUIDs)
                            if (GameObject* bomb = instance->GetGameObject(itr))
                                bomb->SetPhaseMask(32768, true); // Set Invisible*/
                    break;
                }
                case DATA_GADOK:
                {
                    /*if (GameObject* portal = instance->GetGameObject(portalTempGadokGUID))
                        portal->SetPhaseMask(state == IN_PROGRESS ? 4 : 3, true);*/
                    break;
                }
                case DATA_RIMOK:
                {
                    uint8 generatorsCount = 0;

                    for (auto itr: secondaryDoorGUIDs)
                        HandleGameObject(itr, state != DONE);

                    for (auto itr: rimokAddGenetarorsGUIDs)
                    {
                        if (Creature* generator = instance->GetCreature(itr))
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
                    for (auto itr: artilleryGUIDs)
                    {
                        if (Creature* artillery = instance->GetCreature(itr))
                        {
                            if (state != IN_PROGRESS)
                            {
                                artillery->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                artillery->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                            }
                            else
                            {
                                artillery->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                artillery->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                            }
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

                    HandleGameObject(firstDoorGUID, true);

                    dataStorage[type] = data;

                    if (GameObject* firstDoor = instance->GetGameObject(firstDoorGUID))
                    {

                        if (Creature* trigger = firstDoor->SummonTrigger(firstDoor->GetPositionX(), firstDoor->GetPositionY(), firstDoor->GetPositionZ(), 0, 500))
                        {
                            std::list<Creature*> defensorList;
                            GetCreatureListWithEntryInGrid(defensorList, trigger, 65337, 20.0f);

                            trigger->CastSpell(trigger, 115456); // Explosion

                            for (auto itr: defensorList)
                            {
                                uint8 random = rand() % 2;

                                float posX = random ? 814.0f:  640.0f;
                                float posY = random ? 2102.0f: 2112.0f;
                                itr->KnockbackFrom(posX, posY, 25.0f, 20.0f);
                                itr->DespawnOrUnsummon(1000);
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
                            PhasingHandler::AddPhase(player, 50);
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

        void SetGuidData(uint32 type, ObjectGuid value) override
        {
            switch (type)
            {
                case NPC_WEAK_SPOT:
                    raigonWeakGUID = value;
                    break;
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_KIPTILAK:
                    return kiptilakGUID;
                case NPC_GADOK:
                    return gadokGUID;
                case NPC_RIMOK:
                    return rimokGUID;
                case NPC_RAIGONN:
                    return raigonnGUID;
                case NPC_WEAK_SPOT:
                    return raigonWeakGUID;
                case DATA_RANDOM_BOMBARDER:
                    return Trinity::Containers::SelectRandomContainerElement(bombarderGuids);
                case DATA_RANDOM_BOMB_STALKER:
                    return Trinity::Containers::SelectRandomContainerElement(bombStalkerGuids);
            }

            return ObjectGuid::Empty;
        }

        void doEventCinematic()
        {
            switch(cinematicEventProgress)
            {
                case 0:
                    // On allume le brasier & la meche
                    cinematicTimer = 6000;
                    break;
                case 1:
                    if (GameObject* go = instance->GetGameObject(fireSignalGUID))
                        go->UseDoorOrButton();
                    cinematicTimer = 5000;
                    break;
                case 2:
                    if (GameObject* go = instance->GetGameObject(wallCGUID))
                        go->ModifyHealth(-100000);
                    cinematicTimer = 0;
                    break;
            }

            ++cinematicEventProgress;
        }

        void Update(uint32 diff) override
        {
            UpdateOperations(diff);

            if (cinematicTimer)
            {
                if (cinematicTimer <= diff)
                    doEventCinematic();
                else
                    cinematicTimer -= diff;
            }
        }
    };

};

void AddSC_instance_gate_setting_sun()
{
    new instance_gate_setting_sun();
}

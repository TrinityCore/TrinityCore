/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "gate_setting_sun.h"

enum Spells
{
    SPELL_EXPLOSION = 115456
};

DoorData const doorData[] =
{
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM, },
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM, },
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM, },
    {GO_KIPTILAK_WALLS,                     DATA_KIPTILAK,              DOOR_TYPE_ROOM, },
    {GO_KIPTILAK_EXIT_DOOR,                 DATA_KIPTILAK,              DOOR_TYPE_PASSAGE, },
    {GO_RIMAK_AFTER_DOOR,                   DATA_RIMOK,                 DOOR_TYPE_ROOM, },
    {GO_RAIGONN_DOOR,                       DATA_RAIGONN,               DOOR_TYPE_ROOM, },
    {GO_RAIGONN_AFTER_DOOR,                 DATA_RAIGONN,               DOOR_TYPE_PASSAGE, },
    {0,                                     0,                          DOOR_TYPE_ROOM, },// END
};

class instance_gate_setting_sun : public InstanceMapScript
{
public:
    instance_gate_setting_sun() : InstanceMapScript("instance_gate_setting_sun", 962) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_gate_setting_sun_InstanceMapScript(map);
    }

    struct instance_gate_setting_sun_InstanceMapScript : public InstanceScript
    {
        ObjectGuid kiptilakGuid;
        ObjectGuid gadokGuid;
        ObjectGuid rimokGuid;
        ObjectGuid raigonnGuid;
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

        instance_gate_setting_sun_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);

            kiptilakGuid            = GetObjectGuid(0);
            gadokGuid               = GetObjectGuid(0);
            rimokGuid               = GetObjectGuid(0);
            raigonnGuid             = GetObjectGuid(0);
            raigonWeakGuid          = GetObjectGuid(0);

            firstDoorGuid           = GetObjectGuid(0);

            cinematicTimer          = 0;
            cinematicEventProgress  = 0;

            wallCGuid               = GetObjectGuid(0);
            portalTempGadokGuid     = GetObjectGuid(0);

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));

            bombarderGuids.clear();
            bombStalkerGuids.clear();
            mantidBombsGUIDs.clear();
            rimokAddGenetarorsGUIDs.clear();
            artilleryGUIDs.clear();
            secondaryDoorGUIDs.clear();
        }

        void OnDestroy(InstanceMap* /*pMap*/)
        {
            if (Creature* weakSpot = instance->GetCreature(GetObjectGuid(NPC_WEAK_SPOT)))
                weakSpot->_ExitVehicle();
        }

        void OnPlayerEnter(Player* player)
        {
            if (GetData(DATA_BRASIER_CLICKED) == NOT_STARTED)
                player->SetInPhase(1, true, true);
            else
                player->SetInPhase(2, true, true);
        }

        void OnPlayerLeave(Player* player)
        {
            player->SetInPhase(1, true, true);
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_KIPTILAK:
                kiptilakGuid = creature->GetGUID();
                return;
            case NPC_GADOK:
                gadokGuid = creature->GetGUID();
                return;
            case NPC_RIMOK:
                rimokGuid = creature->GetGUID();
                return;
            case NPC_RAIGONN:
                raigonnGuid = creature->GetGUID();
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

        void OnCreatureRemove(Creature* creature)
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
                default:                                                                            return;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_KIPTILAK_ENTRANCE_DOOR:
                    firstDoorGuid = go->GetGUID();
                    break;
                case GO_SIGNAL_FIRE:
                    fireSignalGuid = go->GetGUID();
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
                    wallCGuid = go->GetGUID();
                    return;
                case GO_PORTAL_TEMP_GADOK:
                    portalTempGadokGuid = go->GetGUID();
                    return;
                default:
                    return;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_KIPTILAK:
                {
                    if (state == DONE)
                        for (std::list<ObjectGuid>::const_iterator itr = mantidBombsGUIDs.begin(); itr != mantidBombsGUIDs.end(); ++itr)
                            if (GameObject* bomb = instance->GetGameObject(*itr))
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

                    for (std::list<ObjectGuid>::const_iterator itr = secondaryDoorGUIDs.begin(); itr != secondaryDoorGUIDs.end(); ++itr)
                        HandleGameObject(*itr, state != DONE);

                    for (std::list<ObjectGuid>::const_iterator itr = rimokAddGenetarorsGUIDs.begin(); itr != rimokAddGenetarorsGUIDs.end(); ++itr)
                    {
                        if (Creature* generator = instance->GetCreature(*itr))
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
                    for (std::list<ObjectGuid>::const_iterator itr = artilleryGUIDs.begin(); itr != artilleryGUIDs.end(); ++itr)
                    {
                        if (Creature* artillery = instance->GetCreature(*itr))
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

        void SetData(uint32 type, uint32 data)
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

        void SetData64(uint32 type, uint64 value)
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
            case NPC_KIPTILAK:
                return kiptilakGuid.GetEntry();
            case NPC_GADOK:
                return gadokGuid.GetEntry();
            case NPC_RIMOK:
                return rimokGuid.GetEntry();
            case NPC_RAIGONN:
                return raigonnGuid.GetEntry();
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
            switch(cinematicEventProgress)
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

        void Update(uint32 diff)
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

};

void AddSC_instance_gate_setting_sun()
{
    new instance_gate_setting_sun();
}

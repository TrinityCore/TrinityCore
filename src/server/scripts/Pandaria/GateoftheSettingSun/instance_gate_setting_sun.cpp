#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "gate_setting_sun.h"

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
        uint64 kiptilakGuid;
        uint64 gadokGuid;
        uint64 rimokGuid;
        uint64 raigonnGuid;
        uint64 raigonWeakGuid;

        uint64 firstDoorGuid;
        uint64 fireSignalGuid;

        uint64 wallCGuid;
        uint64 portalTempGadokGuid;

        uint32 cinematicTimer;
        uint8 cinematicEventProgress;

        std::list<uint64> bombarderGuids;
        std::list<uint64> bombStalkerGuids;
        std::list<uint64> mantidBombsGUIDs;
        std::list<uint64> rimokAddGenetarorsGUIDs;
        std::list<uint64> artilleryGUIDs;
        std::list<uint64> secondaryDoorGUIDs;

        uint32 dataStorage[MAX_DATA];

        instance_gate_setting_sun_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);

            kiptilakGuid            = 0;
            gadokGuid               = 0;
            rimokGuid               = 0;
            raigonnGuid             = 0;
            raigonWeakGuid          = 0;
            
            firstDoorGuid           = 0;

            cinematicTimer          = 0;
            cinematicEventProgress  = 0;

            wallCGuid               = 0;
            portalTempGadokGuid     = 0;

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));

            bombarderGuids.clear();
            bombStalkerGuids.clear();
            mantidBombsGUIDs.clear();
            rimokAddGenetarorsGUIDs.clear();
            artilleryGUIDs.clear();
            secondaryDoorGUIDs.clear();
        }

        void OnDestroy(InstanceMap* pMap)
        {
            if (Creature* weakSpot = instance->GetCreature(GetObjectGuid(NPC_WEAK_SPOT)))
                weakSpot->_ExitVehicle();
        }

        void OnPlayerEnter(Player* player)
        {
            if (GetData(DATA_BRASIER_CLICKED) == NOT_STARTED)
                player->SetPhaseMask(1, true);
            else
                player->SetPhaseMask(2, true);
        }

        void OnPlayerLeave(Player* player)
        {
            player->SetPhaseMask(1, true);
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_KIPTILAK:          kiptilakGuid    = creature->GetGUID().GetEntry();                  return;
                case NPC_GADOK:             gadokGuid       = creature->GetGUID().GetEntry();                  return;
                case NPC_RIMOK:             rimokGuid       = creature->GetGUID().GetEntry();                  return;
                case NPC_RAIGONN:           raigonnGuid     = creature->GetGUID().GetEntry();                  return;
                case NPC_KRITHUK_BOMBARDER: bombarderGuids.push_back(creature->GetGUID().GetEntry());          return;
                case NPC_BOMB_STALKER:      bombStalkerGuids.push_back(creature->GetGUID().GetEntry());        return;
                case NPC_ADD_GENERATOR:     rimokAddGenetarorsGUIDs.push_back(creature->GetGUID().GetEntry()); return;
                case NPC_ARTILLERY:         artilleryGUIDs.push_back(creature->GetGUID().GetEntry());          return;
                default:                                                                            return;
            }
        }

        virtual void OnCreatureRemove(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_KRITHUK_BOMBARDER:
                    for (std::list<uint64>::iterator it = bombarderGuids.begin(); it != bombarderGuids.end(); ++it)
                    {
                        if (*it == creature->GetGUID().GetEntry())
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
                    firstDoorGuid = go->GetGUID().GetEntry();
                    break;
                case GO_SIGNAL_FIRE:
                    fireSignalGuid = go->GetGUID().GetEntry();
                    break;
                case GO_KIPTILAK_WALLS:
                case GO_KIPTILAK_EXIT_DOOR:
                case GO_RIMAK_AFTER_DOOR:
                case GO_RAIGONN_AFTER_DOOR:
                    AddDoor(go, true);
                    return;
                case GO_KIPTILAK_MANTID_BOMBS:
                    mantidBombsGUIDs.push_back(go->GetGUID().GetEntry());
                    return;
                case GO_GREATDOOR_SECOND_DOOR:
                    secondaryDoorGUIDs.push_back(go->GetGUID().GetEntry());
                    HandleGameObject(go->GetGUID(), true, go);
                    return;
                case GO_WALL_C:
                    wallCGuid = go->GetGUID().GetEntry();
                    return;
                case GO_PORTAL_TEMP_GADOK:
                    portalTempGadokGuid = go->GetGUID().GetEntry();
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
                        for (std::list<uint64>::const_iterator itr = mantidBombsGUIDs.begin(); itr != mantidBombsGUIDs.end(); ++itr)
                            if (GameObject* bomb = instance->GetGameObject(GetObjectGuid(*itr)))
                                bomb->SetPhaseMask(32768, true); // Set Invisible
                    break;
                }
                case DATA_GADOK:
                {
                    if (GameObject* portal = instance->GetGameObject(GetObjectGuid(portalTempGadokGuid)))
                        portal->SetPhaseMask(state == IN_PROGRESS ? 4 : 3, true);
                    break;
                }
                case DATA_RIMOK:
                {
                    uint8 generatorsCount = 0;

                    for (std::list<uint64>::const_iterator itr = secondaryDoorGUIDs.begin(); itr != secondaryDoorGUIDs.end(); ++itr)
                        HandleGameObject(GetObjectGuid(*itr), state != DONE);

                    for (std::list<uint64>::const_iterator itr = rimokAddGenetarorsGUIDs.begin(); itr != rimokAddGenetarorsGUIDs.end(); ++itr)
                    {
                        if (Creature* generator = instance->GetCreature(GetObjectGuid(*itr)))
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
                    for (std::list<uint64>::const_iterator itr = artilleryGUIDs.begin(); itr != artilleryGUIDs.end(); ++itr)
                    {
                        if (Creature* artillery = instance->GetCreature(GetObjectGuid(*itr)))
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

                    HandleGameObject(GetObjectGuid(firstDoorGuid), true);

                    dataStorage[type] = data;
                    
                    if (GameObject* firstDoor = instance->GetGameObject(GetObjectGuid(firstDoorGuid)))
                    {

                        if (Creature* trigger = firstDoor->SummonTrigger(firstDoor->GetPositionX(), firstDoor->GetPositionY(), firstDoor->GetPositionZ(), 0, 500))
                        {
                            std::list<Creature*> defensorList;
                            GetCreatureListWithEntryInGrid(defensorList, trigger, 65337, 20.0f);

                            trigger->CastSpell(trigger, 115456); // Explosion

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
                            player->SetPhaseMask(2, true);
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
                case NPC_WEAK_SPOT:     raigonWeakGuid = value;     break;
                default:                                            break;
            }
        }

        uint64 GetData64(uint32 type) const override 
        {
            switch (type)
            {
                case NPC_KIPTILAK:              return kiptilakGuid;
                case NPC_GADOK:                 return gadokGuid;
                case NPC_RIMOK:                 return rimokGuid;
                case NPC_RAIGONN:               return raigonnGuid;
                case NPC_WEAK_SPOT:             return raigonWeakGuid;
                case DATA_RANDOM_BOMBARDER:     return Trinity::Containers::SelectRandomContainerElement(bombarderGuids);
                case DATA_RANDOM_BOMB_STALKER:  return Trinity::Containers::SelectRandomContainerElement(bombStalkerGuids);
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
                    if (GameObject* go = instance->GetGameObject(GetObjectGuid(fireSignalGuid)))
                        go->UseDoorOrButton();
                    cinematicTimer = 5000;
                    break;
                case 2:
                    if (GameObject* go = instance->GetGameObject(GetObjectGuid(wallCGuid)))
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

/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "gundrak.h"
#include "Player.h"
#include "TemporarySummon.h"

#define MAX_ENCOUNTER     5

/* GunDrak encounters:
0 - Slad'Ran
1 - Moorabi
2 - Drakkari Colossus
3 - Gal'Darah
4 - Eck the Ferocious
*/

class instance_gundrak : public InstanceMapScript
{
public:
    instance_gundrak() : InstanceMapScript("instance_gundrak", 604) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_gundrak_InstanceMapScript(map);
    }

    struct instance_gundrak_InstanceMapScript : public InstanceScript
    {
        instance_gundrak_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            isHeroic = map->IsHeroic();
        }

        bool isHeroic;
        bool spawnSupport;

        uint32 timer;
        uint32 phase;
        uint64 toActivate;

        uint64 sladRanGUID;
        uint64 moorabiGUID;
        uint64 drakkariColossusGUID;
        uint64 galDarahGUID;
        uint64 eckTheFerociousGUID;

        uint64 sladRanAltarGUID;
        uint64 moorabiAltarGUID;
        uint64 drakkariColossusAltarGUID;
        uint64 sladRanStatueGUID;
        uint64 moorabiStatueGUID;
        uint64 drakkariColossusStatueGUID;
        uint64 galDarahStatueGUID;
        uint64 eckTheFerociousDoorGUID;
        uint64 eckTheFerociousDoorBehindGUID;
        uint64 galDarahDoor1GUID;
        uint64 galDarahDoor2GUID;
        uint64 galDarahDoor3GUID;
        uint64 bridgeGUID;
        uint64 collisionGUID;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        GOState sladRanStatueState;
        GOState moorabiStatueState;
        GOState drakkariColossusStatueState;
        GOState galDarahStatueState;
        GOState bridgeState;
        GOState collisionState;

        std::set<uint64> DwellerGUIDs;

        std::string str_data;

        void Initialize() OVERRIDE
        {
            spawnSupport = false;

            timer = 0;
            phase = 0;
            toActivate = 0;

            sladRanGUID = 0;
            moorabiGUID = 0;
            drakkariColossusGUID = 0;
            galDarahGUID = 0;
            eckTheFerociousGUID = 0;

            sladRanAltarGUID = 0;
            moorabiAltarGUID = 0;
            drakkariColossusAltarGUID = 0;

            sladRanStatueGUID = 0;
            moorabiStatueGUID = 0;
            drakkariColossusStatueGUID = 0;
            galDarahStatueGUID = 0;

            eckTheFerociousDoorGUID = 0;
            eckTheFerociousDoorBehindGUID = 0;
            galDarahDoor1GUID = 0;
            galDarahDoor2GUID = 0;
            galDarahDoor3GUID = 0;

            bridgeGUID = 0;
            collisionGUID = 0;

            sladRanStatueState = GO_STATE_ACTIVE;
            moorabiStatueState = GO_STATE_ACTIVE;
            drakkariColossusStatueState = GO_STATE_ACTIVE;
            galDarahStatueState = GO_STATE_READY;
            bridgeState = GO_STATE_ACTIVE;
            collisionState = GO_STATE_READY;

            DwellerGUIDs.clear();

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

       bool IsEncounterInProgress() const OVERRIDE
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature) OVERRIDE
        {
            switch (creature->GetEntry())
            {
                case CREATURE_SLAD_RAN:
                    sladRanGUID = creature->GetGUID();
                    break;
                case CREATURE_MOORABI:
                    moorabiGUID = creature->GetGUID();
                    break;
                case CREATURE_GALDARAH:
                    galDarahGUID = creature->GetGUID();
                    break;
                case CREATURE_DRAKKARICOLOSSUS:
                    drakkariColossusGUID = creature->GetGUID();
                    break;
                case CREATURE_ECK:
                    eckTheFerociousGUID = creature->GetGUID();
                    break;
                case CREATURE_RUIN_DWELLER:
                    if (creature->IsAlive())
                        DwellerGUIDs.insert(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) OVERRIDE
        {
            switch (go->GetEntry())
            {
                case GO_SLADRAN_ALTAR:
                    sladRanAltarGUID = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (sladRanStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case GO_MOORABI_ALTAR:
                    moorabiAltarGUID = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (moorabiStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case GO_DRAKKARI_COLOSSUS_ALTAR:
                    drakkariColossusAltarGUID = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (drakkariColossusStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case GO_SLADRAN_STATUE:
                    sladRanStatueGUID = go->GetGUID();
                    go->SetGoState(sladRanStatueState);
                    break;
                case GO_MOORABI_STATUE:
                    moorabiStatueGUID = go->GetGUID();
                    go->SetGoState(moorabiStatueState);
                    break;
                case GO_GALDARAH_STATUE:
                    galDarahStatueGUID = go->GetGUID();
                    go->SetGoState(galDarahStatueState);
                    break;
                case GO_DRAKKARI_COLOSSUS_STATUE:
                    drakkariColossusStatueGUID = go->GetGUID();
                    go->SetGoState(drakkariColossusStatueState);
                    break;
                case GO_ECK_THE_FEROCIOUS_DOOR:
                    eckTheFerociousDoorGUID = go->GetGUID();
                    if (isHeroic && m_auiEncounter[1] == DONE)
                        HandleGameObject(0, true, go);
                    break;
                case GO_ECK_THE_FEROCIOUS_DOOR_BEHIND:
                    eckTheFerociousDoorBehindGUID = go->GetGUID();
                    if (isHeroic && m_auiEncounter[4] == DONE)
                        HandleGameObject(0, true, go);
                    break;
                case GO_GALDARAH_DOOR1:
                    galDarahDoor1GUID = go->GetGUID();
                    if (m_auiEncounter[3] == DONE)
                        HandleGameObject(0, true, go);
                    break;
                case GO_GALDARAH_DOOR2:
                    galDarahDoor2GUID = go->GetGUID();
                    if (m_auiEncounter[3] == DONE)
                        HandleGameObject(0, true, go);
                    break;
                case GO_BRIDGE:
                    bridgeGUID = go->GetGUID();
                    go->SetGoState(bridgeState);
                    break;
                case GO_COLLISION:
                    collisionGUID = go->GetGUID();
                    go->SetGoState(collisionState);

                    // Can't spawn here with SpawnGameObject because go isn't added to world yet...
                    if (collisionState == GO_STATE_ACTIVE_ALTERNATIVE)
                        spawnSupport = true;
                    break;
                case GO_GALDARAH_DOOR3:
                    galDarahDoor3GUID = go->GetGUID();
                    if (m_auiEncounter[3] != IN_PROGRESS)
                        HandleGameObject(galDarahDoor3GUID, true, go);
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) OVERRIDE
        {
            switch (type)
            {
            case DATA_SLAD_RAN_EVENT:
                m_auiEncounter[0] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(sladRanAltarGUID);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }
                break;
            case DATA_MOORABI_EVENT:
                m_auiEncounter[1] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(moorabiAltarGUID);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                  if (isHeroic)
                      HandleGameObject(eckTheFerociousDoorGUID, true);
                }
                break;
            case DATA_DRAKKARI_COLOSSUS_EVENT:
                m_auiEncounter[2] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(drakkariColossusAltarGUID);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }
                break;
            case DATA_GAL_DARAH_EVENT:
                m_auiEncounter[3] = data;
                if (data == DONE)
                {
                    HandleGameObject(galDarahDoor1GUID, true);
                    HandleGameObject(galDarahDoor2GUID, true);
                }
                HandleGameObject(galDarahDoor3GUID, data == IN_PROGRESS ? false : true);
                break;
            case DATA_ECK_THE_FEROCIOUS_EVENT:
                m_auiEncounter[4] = data;
                if (isHeroic && data == DONE)
                    HandleGameObject(eckTheFerociousDoorBehindGUID, true);
                break;
            }

            if (data == DONE)
                SaveToDB();
        }

        void SetData64(uint32 type, uint64 data) OVERRIDE
        {
            if (type == DATA_RUIN_DWELLER_DIED)
                DwellerGUIDs.erase(data);
            else if (type == DATA_STATUE_ACTIVATE)
            {
                toActivate = data;
                timer = 3500;
                ++phase;
            }
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            switch (type)
            {
                case DATA_SLAD_RAN_EVENT:
                    return m_auiEncounter[0];
                case DATA_MOORABI_EVENT:
                    return m_auiEncounter[1];
                case DATA_GAL_DARAH_EVENT:
                    return m_auiEncounter[2];
                case DATA_DRAKKARI_COLOSSUS_EVENT:
                    return m_auiEncounter[3];
                case DATA_ECK_THE_FEROCIOUS_EVENT:
                    return m_auiEncounter[4];
                case DATA_ALIVE_RUIN_DWELLERS:
                    return DwellerGUIDs.size();
            }

            return 0;
        }

        uint64 GetData64(uint32 type) const OVERRIDE
        {
            switch (type)
            {
                case DATA_SLAD_RAN_ALTAR:
                    return sladRanAltarGUID;
                case DATA_MOORABI_ALTAR:
                    return moorabiAltarGUID;
                case DATA_DRAKKARI_COLOSSUS_ALTAR:
                    return drakkariColossusAltarGUID;
                case DATA_SLAD_RAN_STATUE:
                    return sladRanStatueGUID;
                case DATA_MOORABI_STATUE:
                    return moorabiStatueGUID;
                case DATA_DRAKKARI_COLOSSUS_STATUE:
                    return drakkariColossusStatueGUID;
                case DATA_DRAKKARI_COLOSSUS:
                    return drakkariColossusGUID;
                case DATA_STATUE_ACTIVATE:
                    return toActivate;
            }

            return 0;
        }

        std::string GetSaveData() OVERRIDE
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "G D " << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
                 << m_auiEncounter[2] << ' ' << m_auiEncounter[3] << ' ' << m_auiEncounter[4] << ' '
                 << (sladRanStatueGUID ? GetObjState(sladRanStatueGUID) : GO_STATE_ACTIVE) << ' ' << (moorabiStatueGUID ? GetObjState(moorabiStatueGUID) : GO_STATE_ACTIVE) << ' '
                 << (drakkariColossusStatueGUID ? GetObjState(drakkariColossusStatueGUID) : GO_STATE_ACTIVE) << ' ' << (galDarahStatueGUID ? GetObjState(galDarahStatueGUID) : GO_STATE_READY) << ' '
                 << (bridgeGUID ? GetObjState(bridgeGUID) : GO_STATE_ACTIVE) << ' ' << (collisionGUID ? GetObjState(collisionGUID) : GO_STATE_READY);

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in) OVERRIDE
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3, data4, data5, data6, data7, data8, data9, data10;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3
                       >> data4 >> data5 >> data6 >> data7 >> data8 >> data9 >> data10;

            if (dataHead1 == 'G' && dataHead2 == 'D')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;
                m_auiEncounter[4] = data4;
                sladRanStatueState            = GOState(data5);
                moorabiStatueState            = GOState(data6);
                drakkariColossusStatueState   = GOState(data7);
                galDarahStatueState           = GOState(data8);
                bridgeState                   = GOState(data9);
                collisionState                = GOState(data10);

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

         void Update(uint32 diff) OVERRIDE
         {
             // Spawn the support for the bridge if necessary
             if (spawnSupport)
             {
                 if (GameObject* collision = instance->GetGameObject(collisionGUID))
                     collision->SummonGameObject(192743, collision->GetPositionX(), collision->GetPositionY(), collision->GetPositionZ(), collision->GetOrientation(), 0, 0, 0, 0, 0);
                 spawnSupport = false;
             }

             // If there is nothing to activate, then return
             if (!toActivate)
                 return;

             if (timer < diff)
             {
                 timer = 0;
                 if (toActivate == bridgeGUID)
                 {
                     GameObject* bridge = instance->GetGameObject(bridgeGUID);
                     GameObject* collision = instance->GetGameObject(collisionGUID);
                     GameObject* sladRanStatue = instance->GetGameObject(sladRanStatueGUID);
                     GameObject* moorabiStatue = instance->GetGameObject(moorabiStatueGUID);
                     GameObject* drakkariColossusStatue = instance->GetGameObject(drakkariColossusStatueGUID);
                     GameObject* galDarahStatue = instance->GetGameObject(galDarahStatueGUID);

                     toActivate = 0;

                     if (bridge && collision && sladRanStatue && moorabiStatue && drakkariColossusStatue && galDarahStatue)
                     {
                         bridge->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         collision->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         sladRanStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         moorabiStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         drakkariColossusStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         galDarahStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

                         // Add the GO that solidifies the bridge so you can walk on it
                         spawnSupport = true;
                         SaveToDB();
                     }
                 }
                 else
                 {
                     uint32 spell = 0;
                     GameObject* altar = NULL;
                     if (toActivate == sladRanStatueGUID)
                     {
                         spell = 57071;
                         altar = instance->GetGameObject(sladRanAltarGUID);
                     }
                     else if (toActivate == moorabiStatueGUID)
                     {
                         spell = 57068;
                         altar = instance->GetGameObject(moorabiAltarGUID);
                     }
                     else if (toActivate == drakkariColossusStatueGUID)
                     {
                         spell = 57072;
                         altar = instance->GetGameObject(drakkariColossusAltarGUID);
                     }

                     // This is a workaround to make the beam cast properly. The caster should be ID 30298 but since the spells
                     // all are with scripted target for that same ID, it will hit itself.
                     if (altar)
                         if (Creature* trigger = altar->SummonCreature(18721, altar->GetPositionX(), altar->GetPositionY(), altar->GetPositionZ() + 3, altar->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 5000))
                         {
                             // Set the trigger model to invisible
                             trigger->SetDisplayId(11686);
                             trigger->CastSpell(trigger, spell, false);
                         }

                     if (GameObject* statueGO = instance->GetGameObject(toActivate))
                         statueGO->SetGoState(GO_STATE_READY);

                     toActivate = 0;

                     if (phase == 3)
                         SetData64(DATA_STATUE_ACTIVATE, bridgeGUID);
                     else
                         SaveToDB(); // Don't save in between last statue and bridge turning in case of crash leading to stuck instance
                }
            }
            else
                timer -= diff;
        }

         GOState GetObjState(uint64 guid)
         {
             if (GameObject* go = instance->GetGameObject(guid))
                 return go->GetGoState();
             return GO_STATE_ACTIVE;
         }
    };

};

class go_gundrak_altar : public GameObjectScript
{
public:
    go_gundrak_altar() : GameObjectScript("go_gundrak_altar") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
    {
        InstanceScript* instance = go->GetInstanceScript();
        uint64 statueGUID = 0;

        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        go->SetGoState(GO_STATE_ACTIVE);

        if (instance)
        {
            switch (go->GetEntry())
            {
                case GO_SLADRAN_ALTAR:
                    statueGUID = instance->GetData64(DATA_SLAD_RAN_STATUE);
                    break;
                case GO_MOORABI_ALTAR:
                    statueGUID = instance->GetData64(DATA_MOORABI_STATUE);
                    break;
                case GO_DRAKKARI_COLOSSUS_ALTAR:
                    statueGUID = instance->GetData64(DATA_DRAKKARI_COLOSSUS_STATUE);
                    break;
            }

            if (!instance->GetData64(DATA_STATUE_ACTIVATE))
            {
                instance->SetData64(DATA_STATUE_ACTIVATE, statueGUID);
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                go->SetGoState(GO_STATE_ACTIVE);
            }
            return true;
        }
        return false;
    }

};

void AddSC_instance_gundrak()
{
    new instance_gundrak();
    new go_gundrak_altar();
}

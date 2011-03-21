/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "gundrak.h"

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

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_gundrak_InstanceMapScript(pMap);
    }

    struct instance_gundrak_InstanceMapScript : public InstanceScript
    {
        instance_gundrak_InstanceMapScript(Map* pMap) : InstanceScript(pMap)
        {
            bHeroicMode = pMap->IsHeroic();
            Initialize();
        };

        bool bHeroicMode;
        bool spawnSupport;

        uint32 timer;
        uint32 phase;
        uint64 toActivate;

        uint64 uiSladRan;
        uint64 uiMoorabi;
        uint64 uiDrakkariColossus;
        uint64 uiGalDarah;
        uint64 uiEckTheFerocious;

        uint64 uiSladRanAltar;
        uint64 uiMoorabiAltar;
        uint64 uiDrakkariColossusAltar;
        uint64 uiSladRanStatue;
        uint64 uiMoorabiStatue;
        uint64 uiDrakkariColossusStatue;
        uint64 uiGalDarahStatue;
        uint64 uiEckTheFerociousDoor;
        uint64 uiEckTheFerociousDoorBehind;
        uint64 uiGalDarahDoor1;
        uint64 uiGalDarahDoor2;
        uint64 uiBridge;
        uint64 uiCollision;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        GOState uiSladRanStatueState;
        GOState uiMoorabiStatueState;
        GOState uiDrakkariColossusStatueState;
        GOState uiGalDarahStatueState;
        GOState uiBridgeState;
        GOState uiCollisionState;

        std::set<uint64> DwellerGUIDs;

        std::string str_data;

        void Initialize()
        {
            spawnSupport = false;

            timer = 0;
            phase = 0;
            toActivate = 0;

            uiSladRan = 0;
            uiMoorabi = 0;
            uiDrakkariColossus = 0;
            uiGalDarah = 0;
            uiEckTheFerocious = 0;

            uiSladRanAltar = 0;
            uiMoorabiAltar = 0;
            uiDrakkariColossusAltar = 0;

            uiSladRanStatue = 0;
            uiMoorabiStatue = 0;
            uiDrakkariColossusStatue = 0;
            uiGalDarahStatue = 0;

            uiEckTheFerociousDoor = 0;
            uiEckTheFerociousDoorBehind = 0;
            uiGalDarahDoor1 = 0;
            uiGalDarahDoor2 = 0;

            uiBridge = 0;
            uiCollision = 0;

            uiSladRanStatueState = GO_STATE_ACTIVE;
            uiMoorabiStatueState = GO_STATE_ACTIVE;
            uiDrakkariColossusStatueState = GO_STATE_ACTIVE;
            uiGalDarahStatueState = GO_STATE_READY;
            uiBridgeState = GO_STATE_ACTIVE;
            uiCollisionState = GO_STATE_READY;

            DwellerGUIDs.clear();

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

       bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS) return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case CREATURE_SLAD_RAN: uiSladRan = creature->GetGUID(); break;
                case CREATURE_MOORABI: uiMoorabi = creature->GetGUID(); break;
                case CREATURE_GALDARAH: uiGalDarah = creature->GetGUID(); break;
                case CREATURE_DRAKKARICOLOSSUS: uiDrakkariColossus = creature->GetGUID(); break;
                case CREATURE_ECK: uiEckTheFerocious = creature->GetGUID(); break;
                case CREATURE_RUIN_DWELLER:
                    if (creature->isAlive())
                        DwellerGUIDs.insert(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case 192518:
                    uiSladRanAltar = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (uiSladRanStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case 192519:
                    uiMoorabiAltar = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (uiMoorabiStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case 192520:
                    uiDrakkariColossusAltar = go->GetGUID();
                    // Make sure that they start out as unusuable
                    go->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    if (m_auiEncounter[0] == DONE)
                    {
                        if (uiDrakkariColossusStatueState == GO_STATE_ACTIVE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                        else
                        {
                            ++phase;
                            go->SetGoState(GO_STATE_ACTIVE);
                        }
                    }
                    break;
                case 192564:
                    uiSladRanStatue = go->GetGUID();
                    go->SetGoState(uiSladRanStatueState);
                    break;
                case 192565:
                    uiMoorabiStatue = go->GetGUID();
                    go->SetGoState(uiMoorabiStatueState);
                    break;
                case 192566:
                    uiGalDarahStatue = go->GetGUID();
                    go->SetGoState(uiGalDarahStatueState);
                    break;
                case 192567:
                    uiDrakkariColossusStatue = go->GetGUID();
                    go->SetGoState(uiDrakkariColossusStatueState);
                    break;
                case 192632:
                    uiEckTheFerociousDoor = go->GetGUID();
                    if (bHeroicMode && m_auiEncounter[1] == DONE)
                        HandleGameObject(NULL,true,go);
                    break;
                case 192569:
                    uiEckTheFerociousDoorBehind = go->GetGUID();
                    if (bHeroicMode && m_auiEncounter[4] == DONE)
                        HandleGameObject(NULL,true,go);
                case 193208:
                    uiGalDarahDoor1 = go->GetGUID();
                    if (m_auiEncounter[3] == DONE)
                        HandleGameObject(NULL,true,go);
                    break;
                case 193209:
                    uiGalDarahDoor2 = go->GetGUID();
                    if (m_auiEncounter[3] == DONE)
                        HandleGameObject(NULL,true,go);
                    break;
                case 193188:
                    uiBridge = go->GetGUID();
                    go->SetGoState(uiBridgeState);
                    break;
                case 192633:
                    uiCollision = go->GetGUID();
                    go->SetGoState(uiCollisionState);

                    // Can't spawn here with SpawnGameObject because go isn't added to world yet...
                    if (uiCollisionState == GO_STATE_ACTIVE_ALTERNATIVE)
                        spawnSupport = true;
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
            case DATA_SLAD_RAN_EVENT:
                m_auiEncounter[0] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(uiSladRanAltar);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                }
                break;
            case DATA_MOORABI_EVENT:
                m_auiEncounter[1] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(uiMoorabiAltar);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                  if (bHeroicMode)
                      HandleGameObject(uiEckTheFerociousDoor,true);
                }
                break;
            case DATA_DRAKKARI_COLOSSUS_EVENT:
                m_auiEncounter[2] = data;
                if (data == DONE)
                {
                  GameObject* go = instance->GetGameObject(uiDrakkariColossusAltar);
                  if (go)
                      go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                }
                break;
            case DATA_GAL_DARAH_EVENT:
                m_auiEncounter[3] = data;
                if (data == DONE)
                {
                    HandleGameObject(uiGalDarahDoor1,true);
                    HandleGameObject(uiGalDarahDoor2,true);
                }
                break;
            case DATA_ECK_THE_FEROCIOUS_EVENT:
                m_auiEncounter[4] = data;
                if (bHeroicMode && data == DONE)
                    HandleGameObject(uiEckTheFerociousDoorBehind,true);
                break;
            }

            if (data == DONE)
                SaveToDB();
        }

        void SetData64(uint32 type, uint64 data)
        {
            if (type == DATA_RUIN_DWELLER_DIED)
            DwellerGUIDs.erase(data);
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_SLAD_RAN_EVENT:             return m_auiEncounter[0];
                case DATA_MOORABI_EVENT:              return m_auiEncounter[1];
                case DATA_GAL_DARAH_EVENT:            return m_auiEncounter[2];
                case DATA_DRAKKARI_COLOSSUS_EVENT:    return m_auiEncounter[3];
                case DATA_ECK_THE_FEROCIOUS_EVENT:    return m_auiEncounter[4];
                case DATA_ALIVE_RUIN_DWELLERS:        return DwellerGUIDs.size();
            }

            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch(type)
            {
                case DATA_SLAD_RAN_ALTAR:             return uiSladRanAltar;
                case DATA_MOORABI_ALTAR:              return uiMoorabiAltar;
                case DATA_DRAKKARI_COLOSSUS_ALTAR:    return uiDrakkariColossusAltar;
                case DATA_SLAD_RAN_STATUE:            return uiSladRanStatue;
                case DATA_MOORABI_STATUE:             return uiMoorabiStatue;
                case DATA_DRAKKARI_COLOSSUS_STATUE:   return uiDrakkariColossusStatue;
                case DATA_DRAKKARI_COLOSSUS:          return uiDrakkariColossus;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "G D " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
                 << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " "
                 << (uiSladRanStatue ? GetObjState(uiSladRanStatue) : GO_STATE_ACTIVE) << " " << (uiMoorabiStatue ? GetObjState(uiMoorabiStatue) : GO_STATE_ACTIVE) << " "
                 << (uiDrakkariColossusStatue ? GetObjState(uiDrakkariColossusStatue) : GO_STATE_ACTIVE) << " " << (uiGalDarahStatue ? GetObjState(uiGalDarahStatue) : GO_STATE_READY) << " "
                 << (uiBridge ? GetObjState(uiBridge) : GO_STATE_ACTIVE) << " " << (uiCollision ? GetObjState(uiCollision) : GO_STATE_READY);

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
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
                uiSladRanStatueState            = GOState(data5);
                uiMoorabiStatueState            = GOState(data6);
                uiDrakkariColossusStatueState   = GOState(data7);
                uiGalDarahStatueState           = GOState(data8);
                uiBridgeState                   = GOState(data9);
                uiCollisionState                = GOState(data10);

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

         bool QueueActivation(uint64 guid, uint32 time)
         {
             if (timer)
                 return false;

             toActivate = guid;
             timer = time;
             phase++;
             return true;
         }

         void Update(uint32 diff)
         {
             // Spawn the support for the bridge if necessary
             if (spawnSupport)
             {
                 if (GameObject* pCollision = instance->GetGameObject(uiCollision))
                     pCollision->SummonGameObject(192743, pCollision->GetPositionX(), pCollision->GetPositionY(), pCollision->GetPositionZ(), pCollision->GetOrientation(), 0, 0, 0, 0, 0);
                 spawnSupport = false;
             }

             // If there is nothing to activate, then return
             if (!toActivate)
                 return;

             if (timer < diff)
             {
                 timer = 0;
                 if (toActivate == uiBridge)
                 {
                     toActivate = 0;
                     GameObject* pBridge = instance->GetGameObject(uiBridge);
                     GameObject* pCollision = instance->GetGameObject(uiCollision);
                     GameObject* pSladRanStatue = instance->GetGameObject(uiSladRanStatue);
                     GameObject* pMoorabiStatue = instance->GetGameObject(uiMoorabiStatue);
                     GameObject* pDrakkariColossusStatue = instance->GetGameObject(uiDrakkariColossusStatue);
                     GameObject* pGalDarahStatue = instance->GetGameObject(uiGalDarahStatue);

                     if (pBridge && pCollision && pSladRanStatue && pMoorabiStatue && pDrakkariColossusStatue && pGalDarahStatue)
                     {
                         pBridge->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         pCollision->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         pSladRanStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         pMoorabiStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         pDrakkariColossusStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                         pGalDarahStatue->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

                         // Add the GO that solidifies the bridge so you can walk on it
                         spawnSupport = true;
                         SaveToDB();
                     }
                 }
                 else
                 {
                     uint32 spell = 0;
                     GameObject* pAltar = NULL;
                     if (toActivate == uiSladRanStatue)
                     {
                         spell = 57071;
                         pAltar = instance->GetGameObject(uiSladRanAltar);
                     } else if (toActivate == uiMoorabiStatue)
                     {
                         spell = 57068;
                         pAltar = instance->GetGameObject(uiMoorabiAltar);
                     } else if (toActivate == uiDrakkariColossusStatue)
                     {
                         spell = 57072;
                         pAltar = instance->GetGameObject(uiDrakkariColossusAltar);
                     }

                     // This is a workaround to make the beam cast properly. The caster should be ID 30298 but since the spells
                     // all are with scripted target for that same ID, it will hit itself.
                     if (pAltar)
                         if (Creature* trigger = pAltar->SummonCreature(18721, pAltar->GetPositionX(), pAltar->GetPositionY(), pAltar->GetPositionZ() + 3, pAltar->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 5000))
                         {
                             // Set the trigger model to invisible
                             trigger->SetDisplayId(11686);
                             trigger->CastSpell(trigger, spell, false);
                         }

                     if (GameObject* statueGO = instance->GetGameObject(toActivate))
                         statueGO->SetGoState(GO_STATE_READY);

                     toActivate = 0;

                     if (phase == 3)
                         QueueActivation(uiBridge, 3000);
                     else
                         SaveToDB(); // Don't save in between last statue and bridge turning in case of crash leading to stuck instance
                 }
             } else timer -= diff;
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

    bool OnGossipHello(Player * /*pPlayer*/, GameObject* pGO)
    {
        InstanceScript *pInstance = pGO->GetInstanceScript();
        uint64 uiStatue = 0;

        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        pGO->SetGoState(GO_STATE_ACTIVE);

        if (pInstance)
        {
            switch(pGO->GetEntry())
            {
                case 192518: uiStatue = pInstance->GetData64(DATA_SLAD_RAN_STATUE); break;
                case 192519: uiStatue = pInstance->GetData64(DATA_MOORABI_STATUE); break;
                case 192520: uiStatue = pInstance->GetData64(DATA_DRAKKARI_COLOSSUS_STATUE); break;
            }
            if (CAST_INST(instance_gundrak::instance_gundrak_InstanceMapScript, pInstance)->QueueActivation(uiStatue, 3500))
            {
                pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                pGO->SetGoState(GO_STATE_ACTIVE);
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

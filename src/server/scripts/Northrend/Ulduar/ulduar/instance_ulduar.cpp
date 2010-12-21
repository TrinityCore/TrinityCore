/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"

enum eGameObjects
{
    GO_KOLOGARN_CHEST_HERO  = 195047,
    GO_KOLOGARN_CHEST       = 195046,
    GO_THORIM_CHEST_HERO    = 194315,
    GO_THORIM_CHEST         = 194314,
    GO_HODIR_CHEST_HERO     = 194308,
    GO_HODIR_CHEST          = 194307,
    GO_FREYA_CHEST_HERO     = 194325,
    GO_FREYA_CHEST          = 194324,
    GO_LEVIATHAN_DOOR       = 194905,
    GO_LEVIATHAN_GATE       = 194630
};

class instance_ulduar : public InstanceMapScript
{
public:
    instance_ulduar() : InstanceMapScript("instance_ulduar", 603) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_ulduar_InstanceMapScript(pMap);
    }

    struct instance_ulduar_InstanceMapScript : public InstanceScript
    {
        instance_ulduar_InstanceMapScript(Map* pMap) : InstanceScript(pMap) { Initialize(); };

        uint32 uiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;
        uint8  flag;

        uint64 uiLeviathanGUID;
        uint64 uiIgnisGUID;
        uint64 uiRazorscaleGUID;
        uint64 uiExpCommanderGUID;
        uint64 uiXT002GUID;
        uint64 uiAssemblyGUIDs[3];
        uint64 uiKologarnGUID;
        uint64 uiAuriayaGUID;
        uint64 uiMimironGUID;
        uint64 uiHodirGUID;
        uint64 uiThorimGUID;
        uint64 uiFreyaGUID;
        uint64 uiVezaxGUID;
        uint64 uiYoggSaronGUID;
        uint64 uiAlgalonGUID;
        uint64 uiLeviathanDoor[7];
        uint64 uiLeviathanGateGUID;

        uint64 uiKologarnChestGUID;
        uint64 uiThorimChestGUID;
        uint64 uiHodirChestGUID;
        uint64 uiFreyaChestGUID;

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);
            uiIgnisGUID           = 0;
            uiRazorscaleGUID      = 0;
            uiExpCommanderGUID    = 0;
            uiXT002GUID           = 0;
            uiKologarnGUID        = 0;
            uiAuriayaGUID         = 0;
            uiMimironGUID         = 0;
            uiHodirGUID           = 0;
            uiThorimGUID          = 0;
            uiFreyaGUID           = 0;
            uiVezaxGUID           = 0;
            uiYoggSaronGUID       = 0;
            uiAlgalonGUID         = 0;
            uiKologarnChestGUID   = 0;
            uiThorimChestGUID     = 0;
            uiHodirChestGUID      = 0;
            uiFreyaChestGUID      = 0;
            uiLeviathanGateGUID   = 0;
            flag                  = 0;

            memset(&uiEncounter, 0, sizeof(uiEncounter));
            memset(&uiAssemblyGUIDs, 0, sizeof(uiAssemblyGUIDs));
            memset(&uiLeviathanDoor, 0, sizeof(uiLeviathanDoor));
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case NPC_LEVIATHAN:
                    uiLeviathanGUID = creature->GetGUID();
                    break;
                case NPC_IGNIS:
                    uiIgnisGUID = creature->GetGUID();
                    break;
                case NPC_RAZORSCALE:
                    uiRazorscaleGUID = creature->GetGUID();
                    break;
                case NPC_EXPEDITION_COMMANDER:
                    uiExpCommanderGUID = creature->GetGUID();
                    return;
                case NPC_XT002:
                    uiXT002GUID = creature->GetGUID();
                    break;

                // Assembly of Iron
                case NPC_STEELBREAKER:
                    uiAssemblyGUIDs[0] = creature->GetGUID();
                    break;
                case NPC_MOLGEIM:
                    uiAssemblyGUIDs[1] = creature->GetGUID();
                    break;
                case NPC_BRUNDIR:
                    uiAssemblyGUIDs[2] = creature->GetGUID();
                    break;

                case NPC_KOLOGARN:
                    uiKologarnGUID = creature->GetGUID();
                    break;
                case NPC_AURIAYA:
                    uiAuriayaGUID = creature->GetGUID();
                    break;
                case NPC_MIMIRON:
                    uiMimironGUID = creature->GetGUID();
                    break;
                case NPC_HODIR:
                    uiHodirGUID = creature->GetGUID();
                    break;
                case NPC_THORIM:
                    uiThorimGUID = creature->GetGUID();
                    break;
                case NPC_FREYA:
                    uiFreyaGUID = creature->GetGUID();
                    break;
                case NPC_VEZAX:
                    uiVezaxGUID = creature->GetGUID();
                    break;
                case NPC_YOGGSARON:
                    uiYoggSaronGUID = creature->GetGUID();
                    break;
                case NPC_ALGALON:
                    uiAlgalonGUID = creature->GetGUID();
                    break;
            }

         }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_KOLOGARN_CHEST_HERO:
                case GO_KOLOGARN_CHEST:
                    uiKologarnChestGUID = go->GetGUID();
                    break;
                case GO_THORIM_CHEST_HERO:
                case GO_THORIM_CHEST:
                    uiThorimChestGUID =go->GetGUID();
                    break;
                case GO_HODIR_CHEST_HERO:
                case GO_HODIR_CHEST:
                    uiHodirChestGUID = go->GetGUID();
                    break;
                case GO_FREYA_CHEST_HERO:
                case GO_FREYA_CHEST:
                    uiFreyaChestGUID = go->GetGUID();
                    break;
                case GO_LEVIATHAN_DOOR:
                    uiLeviathanDoor[flag] = go->GetGUID();
                    HandleGameObject(NULL, true, go);
                    flag++;
                    if (flag == 7)
                        flag =0;
                    break;
                case GO_LEVIATHAN_GATE:
                    uiLeviathanGateGUID = go->GetGUID();
                    HandleGameObject(NULL, false, go);
                    break;
            }
        }

        void ProcessEvent(GameObject* /*go*/, uint32 uiEventId)
        {
            // Flame Leviathan's Tower Event triggers
           Creature* pFlameLeviathan = instance->GetCreature(uiLeviathanGUID);

            if (pFlameLeviathan && pFlameLeviathan->isAlive()) //No leviathan, no event triggering ;)
                switch(uiEventId)
                {
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        pFlameLeviathan->AI()->DoAction(1);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        pFlameLeviathan->AI()->DoAction(2);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        pFlameLeviathan->AI()->DoAction(3);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        pFlameLeviathan->AI()->DoAction(4);
                        break;
                }
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case TYPE_LEVIATHAN:
                    if (state == IN_PROGRESS)
                        for (uint8 uiI = 0; uiI < 7; ++uiI)
                            HandleGameObject(uiLeviathanDoor[uiI],false);
                    else
                        for (uint8 uiI = 0; uiI < 7; ++uiI)
                            HandleGameObject(uiLeviathanDoor[uiI],true);
                    break;
                case TYPE_IGNIS:
                case TYPE_RAZORSCALE:
                case TYPE_XT002:
                case TYPE_ASSEMBLY:
                case TYPE_AURIAYA:
                case TYPE_MIMIRON:
                case TYPE_VEZAX:
                case TYPE_YOGGSARON:
                    break;
                case TYPE_KOLOGARN:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(uiKologarnChestGUID))
                            go->SetRespawnTime(go->GetRespawnDelay());
                    break;
                case TYPE_HODIR:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(uiHodirChestGUID))
                            go->SetRespawnTime(go->GetRespawnDelay());
                    break;
                case TYPE_THORIM:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(uiThorimChestGUID))
                            go->SetRespawnTime(go->GetRespawnDelay());
                    break;
                case TYPE_FREYA:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(uiFreyaChestGUID))
                            go->SetRespawnTime(go->GetRespawnDelay());
                    break;
                case TYPE_COLOSSUS:
                    SetData(type, state);
                    break;
             }

             return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case TYPE_COLOSSUS:
                    uiEncounter[TYPE_COLOSSUS] = data;
                    if (data == 2)
                    {
                        if (Creature* pBoss = instance->GetCreature(uiLeviathanGUID))
                            pBoss->AI()->DoAction(10);
                        if (GameObject* pGate = instance->GetGameObject(uiLeviathanGateGUID))
                            pGate->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        SaveToDB();
                    }
                    break;
                default:
                    break;
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch(data)
            {
                case TYPE_LEVIATHAN:            return uiLeviathanGUID;
                case TYPE_IGNIS:                return uiIgnisGUID;
                case TYPE_RAZORSCALE:           return uiRazorscaleGUID;
                case TYPE_XT002:                return uiXT002GUID;
                case TYPE_KOLOGARN:             return uiKologarnGUID;
                case TYPE_AURIAYA:              return uiAuriayaGUID;
                case TYPE_MIMIRON:              return uiMimironGUID;
                case TYPE_HODIR:                return uiHodirGUID;
                case TYPE_THORIM:               return uiThorimGUID;
                case TYPE_FREYA:                return uiFreyaGUID;
                case TYPE_VEZAX:                return uiVezaxGUID;
                case TYPE_YOGGSARON:            return uiYoggSaronGUID;
                case TYPE_ALGALON:              return uiAlgalonGUID;

                // razorscale expedition commander
                case DATA_EXP_COMMANDER:        return uiExpCommanderGUID;
                // Assembly of Iron
                case DATA_STEELBREAKER:         return uiAssemblyGUIDs[0];
                case DATA_MOLGEIM:              return uiAssemblyGUIDs[1];
                case DATA_BRUNDIR:              return uiAssemblyGUIDs[2];
            }

            return 0;
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
        {
            switch (criteria_id)
            {
                case ACHIEVEMENT_CRITERIA_HOT_POCKET_10:
                    return true;
                case ACHIEVEMENT_CRITERIA_HOT_POCKET_25:
                    return true;
                default:
                    break;
            }
            return false;
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case TYPE_COLOSSUS:
                    return uiEncounter[type];
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "U U " << GetBossSaveData() << " " << GetData[TYPE_COLOSSUS];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* strIn)
        {
            if (!strIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(strIn);

            char dataHead1, dataHead2;
            uint32 data14;

            std::istringstream loadStream(strIn);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'U' && dataHead2 == 'U')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};


void AddSC_instance_ulduar()
{
    new instance_ulduar();
}

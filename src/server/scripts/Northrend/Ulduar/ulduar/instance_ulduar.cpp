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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "ObjectMgr.h"
#include "ulduar.h"

static const DoorData doorData[] =
{
    {GO_LEVIATHAN_DOOR, TYPE_LEVIATHAN, DOOR_TYPE_ROOM,     BOUNDARY_S},
    {0,                 0,              DOOR_TYPE_ROOM,     BOUNDARY_NONE}
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
        instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        uint32 uiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint64 uiLeviathanGUID;
        uint64 uiIgnisGUID;
        uint64 uiRazorscaleGUID;
        uint64 uiRazorscaleController;
        uint64 uiRazorHarpoonGUIDs[4];
        uint64 uiExpCommanderGUID;
        uint64 uiXT002GUID;
        uint64 uiAssemblyGUIDs[3];
        uint64 uiKologarnGUID;
        uint64 uiLeftArmGUID;
        uint64 uiRightArmGUID;
        uint64 uiAuriayaGUID;
        uint64 uiMimironGUID;
        uint64 uiHodirGUID;
        uint64 uiThorimGUID;
        uint64 uiFreyaGUID;
        uint64 uiVezaxGUID;
        uint64 uiYoggSaronGUID;
        uint64 uiAlgalonGUID;
        uint64 uiLeviathanGateGUID;
        uint64 uiVezaxDoorGUID;

        uint64 uiKologarnChestGUID;
        uint64 uiKologarnBridgeGUID;
        uint64 uiKologarnDoorGUID;
        uint64 uiThorimChestGUID;
        uint64 uiHodirChestGUID;
        uint64 uiFreyaChestGUID;

        uint32 TeamInInstance;

        std::set<uint64> mRubbleSpawns;

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doorData);
            uiIgnisGUID             = 0;
            uiRazorscaleGUID        = 0;
            uiRazorscaleController  = 0;
            uiExpCommanderGUID      = 0;
            uiXT002GUID             = 0;
            uiKologarnGUID          = 0;
            uiLeftArmGUID           = 0;
            uiRightArmGUID          = 0;
            uiAuriayaGUID           = 0;
            uiMimironGUID           = 0;
            uiHodirGUID             = 0;
            uiThorimGUID            = 0;
            uiFreyaGUID             = 0;
            uiVezaxGUID             = 0;
            uiYoggSaronGUID         = 0;
            uiAlgalonGUID           = 0;
            uiKologarnChestGUID     = 0;
            uiKologarnBridgeGUID    = 0;
            uiKologarnChestGUID     = 0;
            uiThorimChestGUID       = 0;
            uiHodirChestGUID        = 0;
            uiFreyaChestGUID        = 0;
            uiLeviathanGateGUID     = 0;
            uiVezaxDoorGUID         = 0;
            TeamInInstance          = 0;

            memset(uiEncounter, 0, sizeof(uiEncounter));
            memset(uiAssemblyGUIDs, 0, sizeof(uiAssemblyGUIDs));
            memset(uiRazorHarpoonGUIDs, 0, sizeof(uiRazorHarpoonGUIDs));
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

        void OnPlayerEnter(Player* player)
        {
            if (!TeamInInstance)
                TeamInInstance = player->GetTeam();
        }

        void OnCreatureCreate(Creature* creature)
        {
            if (!TeamInInstance)
            {
                Map::PlayerList const& Players = instance->GetPlayers();
                if (!Players.isEmpty())
                    if (Player* player = Players.begin()->getSource())
                        TeamInInstance = player->GetTeam();
            }

            switch (creature->GetEntry())
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
                case NPC_RAZORSCALE_CONTROLLER:
                    uiRazorscaleController = creature->GetGUID();
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

                // Kologarn
                case NPC_KOLOGARN:
                    uiKologarnGUID = creature->GetGUID();
                    break;
                case NPC_KOLOGARN_BRIDGE:
                    // The below hacks are courtesy of the grid/visibilitysystem
                    if (GetBossState(TYPE_KOLOGARN) == DONE)
                    {
                        creature->SetDeadByDefault(true);
                        creature->setDeathState(CORPSE);
                        creature->DestroyForNearbyPlayers();
                        creature->UpdateObjectVisibility(true);
                    }
                    else
                    {
                        creature->SetDeadByDefault(false);
                        creature->setDeathState(CORPSE);
                        creature->RemoveCorpse(true);
                    }
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
                // Hodir's Helper NPCs
                case NPC_EIVI_NIGHTFEATHER:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_TOR_GREYCLOUD, HORDE);
                    break;
                case NPC_ELLIE_NIGHTFEATHER:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_KAR_GREYCLOUD, HORDE);
                    break;
                case NPC_ELEMENTALIST_MAHFUUN:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SPIRITWALKER_TARA, HORDE);
                    break;
                case NPC_ELEMENTALIST_AVUUN:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_SPIRITWALKER_YONA, HORDE);
                    break;
                case NPC_MISSY_FLAMECUFFS:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_AMIRA_BLAZEWEAVER, HORDE);
                    break;
                case NPC_SISSY_FLAMECUFFS:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_VEESHA_BLAZEWEAVER, HORDE);
                    break;
                case NPC_FIELD_MEDIC_PENNY:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_BATTLE_PRIEST_ELIZA, HORDE);
                    break;
                case NPC_FIELD_MEDIC_JESSI:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_BATTLE_PRIEST_GINA, HORDE);
                    break;
            }

         }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_KOLOGARN_CHEST_HERO:
                case GO_KOLOGARN_CHEST:
                    uiKologarnChestGUID = go->GetGUID();
                    break;
                case GO_KOLOGARN_BRIDGE:
                    uiKologarnBridgeGUID = go->GetGUID();
                    if (GetBossState(TYPE_KOLOGARN) == DONE)
                        HandleGameObject(0, false, go);
                    break;
                case GO_KOLOGARN_DOOR:
                    uiKologarnDoorGUID = go->GetGUID();
                    break;
                case GO_THORIM_CHEST_HERO:
                case GO_THORIM_CHEST:
                    uiThorimChestGUID = go->GetGUID();
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
                    AddDoor(go, true);
                    break;
                case GO_LEVIATHAN_GATE:
                    uiLeviathanGateGUID = go->GetGUID();
                    if (GetBossState(TYPE_LEVIATHAN) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    break;
                case GO_VEZAX_DOOR:
                    uiVezaxDoorGUID = go->GetGUID();
                    HandleGameObject(0, false, go);
                    break;
                case GO_RAZOR_HARPOON_1:
                    uiRazorHarpoonGUIDs[0] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_2:
                    uiRazorHarpoonGUIDs[1] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_3:
                    uiRazorHarpoonGUIDs[2] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_4:
                    uiRazorHarpoonGUIDs[3] = go->GetGUID();
                    break;
                case GO_MOLE_MACHINE:
                    if (GetBossState(TYPE_RAZORSCALE) == IN_PROGRESS)
                        go->SetGoState(GO_STATE_ACTIVE);
            }
        }

        void OnGameObjectRemove(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_LEVIATHAN_DOOR:
                    AddDoor(go, false);
                    break;
                default:
                    break;
            }
        }

        void ProcessEvent(GameObject* /*go*/, uint32 eventId)
        {
            // Flame Leviathan's Tower Event triggers
            Creature* FlameLeviathan = instance->GetCreature(uiLeviathanGUID);

            if (FlameLeviathan && FlameLeviathan->isAlive()) //No leviathan, no event triggering ;)
                switch (eventId)
                {
                    case EVENT_TOWER_OF_STORM_DESTROYED:
                        FlameLeviathan->AI()->DoAction(1);
                        break;
                    case EVENT_TOWER_OF_FROST_DESTROYED:
                        FlameLeviathan->AI()->DoAction(2);
                        break;
                    case EVENT_TOWER_OF_FLAMES_DESTROYED:
                        FlameLeviathan->AI()->DoAction(3);
                        break;
                    case EVENT_TOWER_OF_LIFE_DESTROYED:
                        FlameLeviathan->AI()->DoAction(4);
                        break;
                }
        }

        void ProcessEvent(Unit* /*unit*/, uint32 /*eventId*/)
        {
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case TYPE_LEVIATHAN:
                case TYPE_IGNIS:
                case TYPE_RAZORSCALE:
                case TYPE_XT002:
                case TYPE_ASSEMBLY:
                case TYPE_AURIAYA:
                case TYPE_MIMIRON:
                case TYPE_VEZAX:
                    if (state == DONE)
                        HandleGameObject(uiVezaxDoorGUID, true);
                    break;
                case TYPE_YOGGSARON:
                    break;
                case TYPE_KOLOGARN:
                    if (state == DONE)
                    {
                        if (GameObject* go = instance->GetGameObject(uiKologarnChestGUID))
                            go->SetRespawnTime(go->GetRespawnDelay());
                        HandleGameObject(uiKologarnBridgeGUID, false);
                    }
                    if (state == IN_PROGRESS)
                        HandleGameObject(uiKologarnDoorGUID, false);
                    else
                        HandleGameObject(uiKologarnDoorGUID, true);
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

        void SetData64(uint32 type, uint64 data)
        {
            switch (type)
            {
                case DATA_LEFT_ARM:
                    uiLeftArmGUID = data;
                    break;
                case DATA_RIGHT_ARM:
                    uiRightArmGUID = data;
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
                case DATA_RAZORSCALE_CONTROL:   return uiRazorscaleController;
                case TYPE_XT002:                return uiXT002GUID;
                case TYPE_KOLOGARN:             return uiKologarnGUID;
                case DATA_LEFT_ARM:             return uiLeftArmGUID;
                case DATA_RIGHT_ARM:            return uiRightArmGUID;
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
                case GO_RAZOR_HARPOON_1:        return uiRazorHarpoonGUIDs[0];
                case GO_RAZOR_HARPOON_2:        return uiRazorHarpoonGUIDs[1];
                case GO_RAZOR_HARPOON_3:        return uiRazorHarpoonGUIDs[2];
                case GO_RAZOR_HARPOON_4:        return uiRazorHarpoonGUIDs[3];
                // Assembly of Iron
                case DATA_STEELBREAKER:         return uiAssemblyGUIDs[0];
                case DATA_MOLGEIM:              return uiAssemblyGUIDs[1];
                case DATA_BRUNDIR:              return uiAssemblyGUIDs[2];
            }

            return 0;
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
            saveStream << "U U " << GetBossSaveData() << GetData(TYPE_COLOSSUS);

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

                    if (i == TYPE_COLOSSUS)
                        SetData(i, tmpState);
                    else
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

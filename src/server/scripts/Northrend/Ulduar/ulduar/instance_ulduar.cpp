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
    { GO_LEVIATHAN_DOOR, BOSS_LEVIATHAN, DOOR_TYPE_ROOM, BOUNDARY_S    },
    { 0,                 0,              DOOR_TYPE_ROOM, BOUNDARY_NONE },
};

class instance_ulduar : public InstanceMapScript
{
public:
    instance_ulduar() : InstanceMapScript("instance_ulduar", 603) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_ulduar_InstanceMapScript(map);
    }

    struct instance_ulduar_InstanceMapScript : public InstanceScript
    {
        instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        uint32 Encounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint64 LeviathanGUID;
        uint64 IgnisGUID;
        uint64 RazorscaleGUID;
        uint64 RazorscaleController;
        uint64 RazorHarpoonGUIDs[4];
        uint64 ExpeditionCommanderGUID;
        uint64 XT002GUID;
        uint64 XTToyPileGUIDs[4];
        uint64 AssemblyGUIDs[3];
        uint64 KologarnGUID;
        uint64 LeftArmGUID;
        uint64 RightArmGUID;
        uint64 AuriayaGUID;
        uint64 MimironGUID;
        uint64 HodirGUID;
        uint64 ThorimGUID;
        uint64 FreyaGUID;
        uint64 KeeperGUIDs[3];
        uint64 VezaxGUID;
        uint64 YoggSaronGUID;
        uint64 AlgalonGUID;
        uint64 LeviathanGateGUID;
        uint64 VezaxDoorGUID;

        uint64 KologarnChestGUID;
        uint64 KologarnBridgeGUID;
        uint64 KologarnDoorGUID;
        uint64 ThorimChestGUID;
        uint64 HodirRareCacheGUID;
        uint64 HodirChestGUID;
        uint64 FreyaChestGUID;
        uint64 HodirDoorGUID;
        uint64 HodirIceDoorGUID;

        uint32 TeamInInstance;
        uint32 HodirRareCacheData;

        std::set<uint64> mRubbleSpawns;

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);
            LoadDoorData(doorData);
            IgnisGUID                            = 0;
            RazorscaleGUID                       = 0;
            RazorscaleController                 = 0;
            ExpeditionCommanderGUID              = 0;
            XT002GUID                            = 0;
            KologarnGUID                         = 0;
            LeftArmGUID                          = 0;
            RightArmGUID                         = 0;
            AuriayaGUID                          = 0;
            MimironGUID                          = 0;
            HodirGUID                            = 0;
            ThorimGUID                           = 0;
            FreyaGUID                            = 0;
            VezaxGUID                            = 0;
            YoggSaronGUID                        = 0;
            AlgalonGUID                          = 0;
            KologarnChestGUID                    = 0;
            KologarnBridgeGUID                   = 0;
            KologarnChestGUID                    = 0;
            ThorimChestGUID                      = 0;
            HodirRareCacheGUID                   = 0;
            HodirChestGUID                       = 0;
            FreyaChestGUID                       = 0;
            LeviathanGateGUID                    = 0;
            VezaxDoorGUID                        = 0;
            HodirDoorGUID                        = 0;
            HodirIceDoorGUID                     = 0;
            TeamInInstance                       = 0;
            HodirRareCacheData                   = 0;

            memset(Encounter, 0, sizeof(Encounter));
            memset(XTToyPileGUIDs, 0, sizeof(XTToyPileGUIDs));
            memset(AssemblyGUIDs, 0, sizeof(AssemblyGUIDs));
            memset(RazorHarpoonGUIDs, 0, sizeof(RazorHarpoonGUIDs));
            memset(KeeperGUIDs, 0, sizeof(KeeperGUIDs));
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (Encounter[i] == IN_PROGRESS)
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
                    LeviathanGUID = creature->GetGUID();
                    break;
                case NPC_IGNIS:
                    IgnisGUID = creature->GetGUID();
                    break;
                case NPC_RAZORSCALE:
                    RazorscaleGUID = creature->GetGUID();
                    break;
                case NPC_RAZORSCALE_CONTROLLER:
                    RazorscaleController = creature->GetGUID();
                    break;
                case NPC_EXPEDITION_COMMANDER:
                    ExpeditionCommanderGUID = creature->GetGUID();
                    break;
                case NPC_XT002:
                    XT002GUID = creature->GetGUID();
                    break;
                case NPC_XT_TOY_PILE:
                    for (uint8 i = 0; i < 4; ++i)
                        if (!XTToyPileGUIDs[i])
                            XTToyPileGUIDs[i] = creature->GetGUID();
                    break;

                // Assembly of Iron
                case NPC_STEELBREAKER:
                    AssemblyGUIDs[0] = creature->GetGUID();
                    break;
                case NPC_MOLGEIM:
                    AssemblyGUIDs[1] = creature->GetGUID();
                    break;
                case NPC_BRUNDIR:
                    AssemblyGUIDs[2] = creature->GetGUID();
                    break;

                // Freya's Keeper
                case NPC_IRONBRANCH:
                    KeeperGUIDs[0] = creature->GetGUID();
                    if (GetBossState(BOSS_FREYA) == DONE)
                        creature->DespawnOrUnsummon();
                    break;
                case NPC_BRIGHTLEAF:
                    KeeperGUIDs[1] = creature->GetGUID();
                    if (GetBossState(BOSS_FREYA) == DONE)
                        creature->DespawnOrUnsummon();
                    break;
                case NPC_STONEBARK:
                    KeeperGUIDs[2] = creature->GetGUID();
                    if (GetBossState(BOSS_FREYA) == DONE)
                        creature->DespawnOrUnsummon();
                     break;

                // Kologarn
                case NPC_KOLOGARN:
                    KologarnGUID = creature->GetGUID();
                    break;
                case NPC_KOLOGARN_BRIDGE:
                    // The below hacks are courtesy of the grid/visibilitysystem
                    if (GetBossState(BOSS_KOLOGARN) == DONE)
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
                    AuriayaGUID = creature->GetGUID();
                    break;
                case NPC_MIMIRON:
                    MimironGUID = creature->GetGUID();
                    break;
                case NPC_HODIR:
                    HodirGUID = creature->GetGUID();
                    break;
                case NPC_THORIM:
                    ThorimGUID = creature->GetGUID();
                    break;
                case NPC_FREYA:
                    FreyaGUID = creature->GetGUID();
                    break;
                case NPC_VEZAX:
                    VezaxGUID = creature->GetGUID();
                    break;
                case NPC_YOGGSARON:
                    YoggSaronGUID = creature->GetGUID();
                    break;
                case NPC_ALGALON:
                    AlgalonGUID = creature->GetGUID();
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

        void OnGameObjectCreate(GameObject* gameObject)
        {
            switch (gameObject->GetEntry())
            {
                case GO_KOLOGARN_CHEST_HERO:
                case GO_KOLOGARN_CHEST:
                    KologarnChestGUID = gameObject->GetGUID();
                    break;
                case GO_KOLOGARN_BRIDGE:
                    KologarnBridgeGUID = gameObject->GetGUID();
                    if (GetBossState(BOSS_KOLOGARN) == DONE)
                        HandleGameObject(0, false, gameObject);
                    break;
                case GO_KOLOGARN_DOOR:
                    KologarnDoorGUID = gameObject->GetGUID();
                    break;
                case GO_THORIM_CHEST_HERO:
                case GO_THORIM_CHEST:
                    ThorimChestGUID = gameObject->GetGUID();
                    break;
                case GO_HODIR_RARE_CACHE_OF_WINTER_HERO:
                case GO_HODIR_RARE_CACHE_OF_WINTER:
                    HodirRareCacheGUID = gameObject->GetGUID();
                    break;
                case GO_HODIR_CHEST_HERO:
                case GO_HODIR_CHEST:
                    HodirChestGUID = gameObject->GetGUID();
                    break;
                case GO_FREYA_CHEST_HERO:
                case GO_FREYA_CHEST:
                    FreyaChestGUID = gameObject->GetGUID();
                    break;
                case GO_LEVIATHAN_DOOR:
                    AddDoor(gameObject, true);
                    break;
                case GO_LEVIATHAN_GATE:
                    LeviathanGateGUID = gameObject->GetGUID();
                    if (GetBossState(BOSS_LEVIATHAN) == DONE)
                        gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    break;
                case GO_VEZAX_DOOR:
                    VezaxDoorGUID = gameObject->GetGUID();
                    HandleGameObject(0, false, gameObject);
                    break;
                case GO_RAZOR_HARPOON_1:
                    RazorHarpoonGUIDs[0] = gameObject->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_2:
                    RazorHarpoonGUIDs[1] = gameObject->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_3:
                    RazorHarpoonGUIDs[2] = gameObject->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_4:
                    RazorHarpoonGUIDs[3] = gameObject->GetGUID();
                    break;
                case GO_MOLE_MACHINE:
                    if (GetBossState(BOSS_RAZORSCALE) == IN_PROGRESS)
                        gameObject->SetGoState(GO_STATE_ACTIVE);
                case GO_HODIR_DOOR:
                    HodirDoorGUID = gameObject->GetGUID();
                    break;
                case GO_HODIR_ICE_DOOR:
                    HodirIceDoorGUID = gameObject->GetGUID();
                    break;
            }
        }

        void OnGameObjectRemove(GameObject* gameObject)
        {
            switch (gameObject->GetEntry())
            {
                case GO_LEVIATHAN_DOOR:
                    AddDoor(gameObject, false);
                    break;
                default:
                    break;
            }
        }

        void ProcessEvent(GameObject* /*go*/, uint32 eventId)
        {
            // Flame Leviathan's Tower Event triggers
            Creature* FlameLeviathan = instance->GetCreature(LeviathanGUID);

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
                case BOSS_LEVIATHAN:
                case BOSS_IGNIS:
                case BOSS_RAZORSCALE:
                case BOSS_XT002:
                case BOSS_ASSEMBLY_OF_IRON:
                case BOSS_AURIAYA:
                case BOSS_MIMIRON:
                case BOSS_VEZAX:
                    if (state == DONE)
                        HandleGameObject(VezaxDoorGUID, true);
                    break;
                case BOSS_YOGGSARON:
                    break;
                case BOSS_KOLOGARN:
                    if (state == DONE)
                    {
                        if (GameObject* gameObject = instance->GetGameObject(KologarnChestGUID))
                            gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                        HandleGameObject(KologarnBridgeGUID, false);
                    }
                    if (state == IN_PROGRESS)
                        HandleGameObject(KologarnDoorGUID, false);
                    else
                        HandleGameObject(KologarnDoorGUID, true);
                    break;
                case BOSS_HODIR:
                    if (state == DONE)
                    {
                        if (GameObject* HodirRareCache = instance->GetGameObject(HodirRareCacheGUID))
                            if (GetData(DATA_HODIR_RARE_CACHE) == 1)
                                HodirRareCache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                        if (GameObject* HodirChest = instance->GetGameObject(HodirChestGUID))
                            HodirChest->SetRespawnTime(HodirChest->GetRespawnDelay());
                        HandleGameObject(HodirDoorGUID, true);
                        HandleGameObject(HodirIceDoorGUID, true);
                    }
                    break;
                case BOSS_THORIM:
                    if (state == DONE)
                        if (GameObject* gameObject = instance->GetGameObject(ThorimChestGUID))
                            gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                    break;
                case BOSS_FREYA:
                    if (state == DONE)
                        if (GameObject* gameObject = instance->GetGameObject(FreyaChestGUID))
                            gameObject->SetRespawnTime(gameObject->GetRespawnDelay());
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case TYPE_COLOSSUS:
                    Encounter[TYPE_COLOSSUS] = data;
                    if (data == 2)
                    {
                        if (Creature* Leviathan = instance->GetCreature(LeviathanGUID))
                            Leviathan->AI()->DoAction(10);
                        if (GameObject* gameObject = instance->GetGameObject(LeviathanGateGUID))
                            gameObject->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                        SaveToDB();
                    }
                    break;
                case DATA_HODIR_RARE_CACHE:
                    HodirRareCacheData = data;
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
                    LeftArmGUID = data;
                    break;
                case DATA_RIGHT_ARM:
                    RightArmGUID = data;
                    break;
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch (data)
            {
                case BOSS_LEVIATHAN:
                    return LeviathanGUID;
                case BOSS_IGNIS:
                    return IgnisGUID;
                case BOSS_RAZORSCALE:
                    return RazorscaleGUID;
                case DATA_RAZORSCALE_CONTROL:
                    return RazorscaleController;
                case BOSS_XT002:
                    return XT002GUID;
                case DATA_TOY_PILE_0:
                case DATA_TOY_PILE_1:
                case DATA_TOY_PILE_2:
                case DATA_TOY_PILE_3:
                    return XTToyPileGUIDs[data - DATA_TOY_PILE_0];
                case BOSS_KOLOGARN:
                    return KologarnGUID;
                case DATA_LEFT_ARM:
                    return LeftArmGUID;
                case DATA_RIGHT_ARM:
                    return RightArmGUID;
                case BOSS_AURIAYA:
                    return AuriayaGUID;
                case BOSS_MIMIRON:
                    return MimironGUID;
                case BOSS_HODIR:
                    return HodirGUID;
                case BOSS_THORIM:
                    return ThorimGUID;
                case BOSS_FREYA:
                    return FreyaGUID;
                case BOSS_VEZAX:
                    return VezaxGUID;
                case BOSS_YOGGSARON:
                    return YoggSaronGUID;
                case BOSS_ALGALON:
                    return AlgalonGUID;

                // Razorscale expedition commander
                case DATA_EXPEDITION_COMMANDER:
                    return ExpeditionCommanderGUID;
                case GO_RAZOR_HARPOON_1:
                    return RazorHarpoonGUIDs[0];
                case GO_RAZOR_HARPOON_2:
                    return RazorHarpoonGUIDs[1];
                case GO_RAZOR_HARPOON_3:
                    return RazorHarpoonGUIDs[2];
                case GO_RAZOR_HARPOON_4:
                    return RazorHarpoonGUIDs[3];

                // Assembly of Iron
                case BOSS_STEELBREAKER:
                    return AssemblyGUIDs[0];
                case BOSS_MOLGEIM:
                    return AssemblyGUIDs[1];
                case BOSS_BRUNDIR:
                    return AssemblyGUIDs[2];

                // Freya's Keepers
                case BOSS_BRIGHTLEAF:
                    return KeeperGUIDs[0];
                case BOSS_IRONBRANCH:
                    return KeeperGUIDs[1];
                case BOSS_STONEBARK:
                    return KeeperGUIDs[2];
            }

            return 0;
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case TYPE_COLOSSUS:
                    return Encounter[type];
                    break;
                case DATA_HODIR_RARE_CACHE:
                    return HodirRareCacheData;
                    break;
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

/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Blackfathom_Deeps
SD%Complete: 50
SDComment:
SDCategory: Blackfathom Deeps
EndScriptData */

#include "ScriptPCH.h"
#include "blackfathom_deeps.h"

#define MAX_ENCOUNTER 4

/* Encounter 0 = Gelihast
   Encounter 1 = Twilight Lord Kelris
   Encounter 2 = Shrine event
   Encounter 3 = Aku'Mai
 */

const Position LorgusPosition[4] =
{
    { -458.500610f, -38.343079f, -33.474445f, 0.0f },
    { -469.423615f, -88.400513f, -39.265102f, 0.0f },
    { -622.354980f, -10.350100f, -22.777000f, 0.0f },
    { -759.640564f,  16.658913f, -29.159529f, 0.0f }
};

const Position SpawnsLocation[] =
{
    {-775.431f, -153.853f, -25.871f, 3.207f},
    {-775.404f, -174.132f, -25.871f, 3.185f},
    {-862.430f, -154.937f, -25.871f, 0.060f},
    {-862.193f, -174.251f, -25.871f, 6.182f},
    {-863.895f, -458.899f, -33.891f, 5.637f}
};

class instance_blackfathom_deeps : public InstanceMapScript
{
public:
    instance_blackfathom_deeps() : InstanceMapScript("instance_blackfathom_deeps", 48) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_blackfathom_deeps_InstanceMapScript(pMap);
    }

    struct instance_blackfathom_deeps_InstanceMapScript : public InstanceScript
    {
        instance_blackfathom_deeps_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint64 m_uiTwilightLordKelrisGUID;
        uint64 m_uiShrine1GUID;
        uint64 m_uiShrine2GUID;
        uint64 m_uiShrine3GUID;
        uint64 m_uiShrine4GUID;
        uint64 m_uiShrineOfGelihastGUID;
        uint64 m_uiAltarOfTheDeepsGUID;
        uint64 m_uiMainDoorGUID;

        uint8 m_auiEncounter[MAX_ENCOUNTER];
        uint8 m_uiCountFires;
        uint8 uiDeathTimes;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            m_uiTwilightLordKelrisGUID = 0;
            m_uiShrine1GUID = 0;
            m_uiShrine2GUID = 0;
            m_uiShrine3GUID = 0;
            m_uiShrine4GUID = 0;
            m_uiShrineOfGelihastGUID = 0;
            m_uiAltarOfTheDeepsGUID = 0;
            m_uiMainDoorGUID = 0;
            m_uiCountFires = 0;
            uiDeathTimes = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_TWILIGHT_LORD_KELRIS:
                    m_uiTwilightLordKelrisGUID = creature->GetGUID();
                    break;
                case NPC_LORGUS_JETT:
                    creature->SetHomePosition(LorgusPosition[urand(0, 3)]);
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_FIRE_OF_AKU_MAI_1:
                    m_uiShrine1GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_2:
                    m_uiShrine2GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_3:
                    m_uiShrine3GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_4:
                    m_uiShrine4GUID = go->GetGUID();
                    break;
                case GO_SHRINE_OF_GELIHAST:
                    m_uiShrineOfGelihastGUID = go->GetGUID();
                    if (m_auiEncounter[0] != DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case GO_ALTAR_OF_THE_DEEPS:
                    m_uiAltarOfTheDeepsGUID = go->GetGUID();
                    if (m_auiEncounter[3] != DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case GO_AKU_MAI_DOOR:
                    if (m_auiEncounter[2] == DONE)
                        HandleGameObject(0, true, go);
                    m_uiMainDoorGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch (uiType)
            {
                case TYPE_GELIHAST:
                    m_auiEncounter[0] = uiData;
                    if (uiData == DONE)
                        if (GameObject* go = instance->GetGameObject(m_uiShrineOfGelihastGUID))
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case TYPE_AKU_MAI:
                    m_auiEncounter[3] = uiData;
                    if (uiData == DONE)
                        if (GameObject* go = instance->GetGameObject(m_uiAltarOfTheDeepsGUID))
                        {
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            go->SummonCreature(NPC_MORRIDUNE, SpawnsLocation[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                        }
                    break;
                case DATA_FIRE:
                    m_uiCountFires = uiData;
                    switch (m_uiCountFires)
                    {
                        case 1:
                            if (GameObject* pGO = instance->GetGameObject(m_uiShrine1GUID))
                            {
                                pGO->SummonCreature(NPC_AKU_MAI_SNAPJAW, SpawnsLocation[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_AKU_MAI_SNAPJAW, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_AKU_MAI_SNAPJAW, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_AKU_MAI_SNAPJAW, SpawnsLocation[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                        case 2:
                            if (GameObject* pGO = instance->GetGameObject(m_uiShrine1GUID))
                            {
                                for (uint8 i = 0; i < 2; ++i)
                                {
                                    pGO->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    pGO->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    pGO->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    pGO->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                }
                            }
                            break;
                        case 3:
                            if (GameObject* pGO = instance->GetGameObject(m_uiShrine1GUID))
                            {
                                pGO->SummonCreature(NPC_AKU_MAI_SERVANT, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_AKU_MAI_SERVANT, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                        case 4:
                            if (GameObject* pGO = instance->GetGameObject(m_uiShrine1GUID))
                            {
                                pGO->SummonCreature(NPC_BARBED_CRUSTACEAN, SpawnsLocation[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_BARBED_CRUSTACEAN, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_BARBED_CRUSTACEAN, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                pGO->SummonCreature(NPC_BARBED_CRUSTACEAN, SpawnsLocation[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                    }
                    break;
                case DATA_EVENT:
                    uiDeathTimes = uiData;
                    if (uiDeathTimes == 18)
                        HandleGameObject(m_uiMainDoorGUID, true);
                    break;
            }
        }

        uint32 GetData(uint32 uiType)
        {
            switch (uiType)
            {
                case TYPE_GELIHAST:
                    return m_auiEncounter[0];
                case TYPE_KELRIS:
                    return m_auiEncounter[1];
                case TYPE_SHRINE:
                    return m_auiEncounter[2];
                case TYPE_AKU_MAI:
                    return m_auiEncounter[3];
                case DATA_FIRE:
                    return m_uiCountFires;
                case DATA_EVENT:
                    return uiDeathTimes;
            }

            return 0;
        }

        uint64 GetData64(uint32 uiData)
        {
            switch (uiData)
            {
                case DATA_TWILIGHT_LORD_KELRIS:
                    return m_uiTwilightLordKelrisGUID;
                case DATA_SHRINE1:
                    return m_uiShrine1GUID;
                case DATA_SHRINE2:
                    return m_uiShrine2GUID;
                case DATA_SHRINE3:
                    return m_uiShrine3GUID;
                case DATA_SHRINE4:
                    return m_uiShrine4GUID;
                case DATA_SHRINE_OF_GELIHAST:
                    return m_uiShrineOfGelihastGUID;
                case DATA_MAINDOOR:
                    return m_uiMainDoorGUID;
            }

            return 0;
        }
    };

};

void AddSC_instance_blackfathom_deeps()
{
    new instance_blackfathom_deeps();
}

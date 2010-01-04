/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Blackfathom_Deeps
SD%Complete: 50
SDComment:
SDCategory: Blackfathom Deeps
EndScriptData */

#include "precompiled.h"
#include "blackfathom_deeps.h"

#define MAX_ENCOUNTER 4

/* Encounter 0 = Gelihast
   Encounter 1 = Twilight Lord Kelris
   Encounter 2 = Shrine event
   Encounter 3 = Aku'Mai
 */

const Position LorgusPosition[4] =
{
    { -458.500610, -38.343079, -33.474445 },
    { -469.423615, -88.400513, -39.265102 },
    { -622.354980, -10.350100, -22.777000 },
    { -759.640564,  16.658913, -29.159529 }
};

const Position SpawnsLocation[] =
{
    {-775.431, -153.853, -25.871, 3.207},
    {-775.404, -174.132, -25.871, 3.185},
    {-862.430, -154.937, -25.871, 0.060},
    {-862.193, -174.251, -25.871, 6.182},
    {-863.895, -458.899, -33.891, 5.637}
};

struct TRINITY_DLL_DECL instance_blackfathom_deeps : public ScriptedInstance
{
    instance_blackfathom_deeps(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

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

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch (pCreature->GetEntry())
        {
            case NPC_TWILIGHT_LORD_KELRIS:
                m_uiTwilightLordKelrisGUID = pCreature->GetGUID();
                break;
            case NPC_LORGUS_JETT:
                pCreature->SetHomePosition(LorgusPosition[urand(0,3)]);
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_FIRE_OF_AKU_MAI_1:
                m_uiShrine1GUID = pGo->GetGUID();
                break;
            case GO_FIRE_OF_AKU_MAI_2:
                m_uiShrine2GUID = pGo->GetGUID();
                break;
            case GO_FIRE_OF_AKU_MAI_3:
                m_uiShrine3GUID = pGo->GetGUID();
                break;
            case GO_FIRE_OF_AKU_MAI_4:
                m_uiShrine4GUID = pGo->GetGUID();
                break;
            case GO_SHRINE_OF_GELIHAST:
                m_uiShrineOfGelihastGUID = pGo->GetGUID();
                if (m_auiEncounter[0] != DONE)
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_ALTAR_OF_THE_DEEPS:
                m_uiAltarOfTheDeepsGUID = pGo->GetGUID();
                if (m_auiEncounter[3] != DONE)
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_AKU_MAI_DOOR:
                if (m_auiEncounter[2] == DONE)
                    HandleGameObject(NULL,true,pGo);
                m_uiMainDoorGUID = pGo->GetGUID();
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_GELIHAST:
                m_auiEncounter[0] = uiData;
                if (uiData == DONE)
                    if (GameObject *pGo = instance->GetGameObject(m_uiShrineOfGelihastGUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case TYPE_AKU_MAI:
                m_auiEncounter[3] = uiData;
                if (uiData == DONE)
                    if (GameObject *pGo = instance->GetGameObject(m_uiAltarOfTheDeepsGUID))
                    {
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                        pGo->SummonCreature(NPC_MORRIDUNE,SpawnsLocation[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
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
                    HandleGameObject(m_uiMainDoorGUID,true);
                break;
        }
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
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
        switch(uiData)
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

InstanceData* GetInstanceData_instance_blackfathom_deeps(Map* pMap)
{
    return new instance_blackfathom_deeps(pMap);
}

void AddSC_instance_blackfathom_deeps()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_blackfathom_deeps";
    newscript->GetInstanceData = &GetInstanceData_instance_blackfathom_deeps;
    newscript->RegisterSelf();
}

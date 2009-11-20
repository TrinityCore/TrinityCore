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

#define MAX_ENCOUNTER 3

/* Encounter 0 = Gelihast
   Encounter 1 = Twilight Lord Kelris
   Encounter 2 = Shrine event
   Must kill twilight lord for shrine event to be possible
 */

/*const Position LorgusPosition[4] =
{ { },
  { },
  { },
  { }
};*/

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
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        if (pCreature->GetEntry() == NPC_TWILIGHT_LORD_KELRIS)
            m_uiTwilightLordKelrisGUID = pCreature->GetGUID();
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_FIRE_OF_AKU_MAI_1:
                m_uiShrine1GUID = pGo->GetGUID();
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_FIRE_OF_AKU_MAI_2:
                m_uiShrine2GUID = pGo->GetGUID();
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_FIRE_OF_AKU_MAI_3:
                m_uiShrine3GUID = pGo->GetGUID();
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_FIRE_OF_AKU_MAI_4:
                m_uiShrine4GUID = pGo->GetGUID();
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_SHRINE_OF_GELIHAST:
                m_uiShrineOfGelihastGUID = pGo->GetGUID();
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_ALTAR_OF_THE_DEEPS:
                m_uiAltarOfTheDeepsGUID = pGo->GetGUID();
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case GO_AKU_MAI_DOOR:
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
            case TYPE_KELRIS:
                m_auiEncounter[1] = uiData;
                if (uiData == DONE)
                {
                    if (GameObject *pGo = instance->GetGameObject(m_uiShrine1GUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                    if (GameObject *pGo = instance->GetGameObject(m_uiShrine2GUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                    if (GameObject *pGo = instance->GetGameObject(m_uiShrine3GUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                    if (GameObject *pGo = instance->GetGameObject(m_uiShrine4GUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                break;
            case TYPE_SHRINE:
                m_auiEncounter[2] = uiData;
                if (uiData == DONE)
                    if (GameObject *pGo = instance->GetGameObject(m_uiAltarOfTheDeepsGUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
        }
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
            case TYPE_KELRIS:
                return m_auiEncounter[0];
            case TYPE_SHRINE:
                return m_auiEncounter[1];
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

    void CheckFires()
    {
        GameObject *pShrine1 = instance->GetGameObject(m_uiShrine1GUID);
        GameObject *pShrine2 = instance->GetGameObject(m_uiShrine2GUID);
        GameObject *pShrine3 = instance->GetGameObject(m_uiShrine3GUID);
        GameObject *pShrine4 = instance->GetGameObject(m_uiShrine4GUID);
        if (pShrine1 && pShrine1->GetGoState() == GO_STATE_ACTIVE &&
            pShrine2 && pShrine2->GetGoState() == GO_STATE_ACTIVE &&
            pShrine3 && pShrine3->GetGoState() == GO_STATE_ACTIVE &&
            pShrine4 && pShrine4->GetGoState() == GO_STATE_ACTIVE)
            HandleGameObject(m_uiMainDoorGUID,true);
    }
};

InstanceData* GetInstanceData_instance_blackfathom_deeps(Map* pMap)
{
    return new instance_blackfathom_deeps(pMap);
}

bool GoHello_blackfathom_fire(Player *pPlayer, GameObject* pGo)
{
    ScriptedInstance *pInstance = pGo->GetInstanceData();

    if (pInstance)
    {
        pGo->SetGoState(GO_STATE_ACTIVE);
        pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        ((instance_blackfathom_deeps*)pInstance)->CheckFires();
        return true;
    }
    return false;
}

void AddSC_instance_blackfathom_deeps()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_blackfathom_deeps";
    newscript->GetInstanceData = &GetInstanceData_instance_blackfathom_deeps;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_blackfathom_fire";
    newscript->pGOHello = &GoHello_blackfathom_fire;
    newscript->RegisterSelf();
}

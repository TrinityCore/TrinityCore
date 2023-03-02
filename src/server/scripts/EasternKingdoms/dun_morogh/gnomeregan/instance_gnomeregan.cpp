/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Gnomeregan
SD%Complete: 90%
SDComment:  Support for Grubbis and Thermaplugg Encounters
SDCategory: Gnomeregan
EndScriptData */

#include "scriptPCH.h"
#include "gnomeregan.h"

instance_gnomeregan::instance_gnomeregan(Map* pMap) : ScriptedInstance(pMap),
    m_uiBlastmasterShortfuseGUID(0),
    m_uiCaveInNorthGUID(0),
    m_uiCaveInSouthGUID(0),
    m_uiDoorFinalChamberGUID(0)
{
    Initialize();
}

void instance_gnomeregan::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    memset(&m_asBombFaces, 0, sizeof(m_asBombFaces));
    memset(&m_auiExplosiveSortedGUIDs, 0, sizeof(m_auiExplosiveSortedGUIDs));
}

void instance_gnomeregan::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_BLASTMASTER_SHORTFUSE:
            m_uiBlastmasterShortfuseGUID = pCreature->GetGUID();
            break;
        case NPC_ALARM_A_BOMB_2600:
            m_uiAlarmABomb2600GUID = pCreature->GetGUID();
            break;
    }
}

void instance_gnomeregan::OnObjectCreate(GameObject* pGo)
{
    switch (pGo->GetEntry())
    {
        case GO_RED_ROCKET:
            m_lRedRocketGUIDs.push_back(pGo->GetGUID());
            break;
        case GO_CAVE_IN_NORTH:
            m_uiCaveInNorthGUID = pGo->GetGUID();
            break;
        case GO_CAVE_IN_SOUTH:
            m_uiCaveInSouthGUID = pGo->GetGUID();
            break;
        case GO_EXPLOSIVE_CHARGE:
            m_lExplosiveCharges.push_back(pGo);
            break;
        case GO_THE_FINAL_CHAMBER:
            m_uiDoorFinalChamberGUID = pGo->GetGUID();
            break;

        case GO_GNOME_FACE_1:
            m_asBombFaces[0].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
        case GO_GNOME_FACE_2:
            m_asBombFaces[1].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
        case GO_GNOME_FACE_3:
            m_asBombFaces[2].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
        case GO_GNOME_FACE_4:
            m_asBombFaces[3].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
        case GO_GNOME_FACE_5:
            m_asBombFaces[4].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
        case GO_GNOME_FACE_6:
            m_asBombFaces[5].m_uiGnomeFaceGUID = pGo->GetGUID();
            break;
    }
}

static bool sortFromEastToWest(GameObject* pFirst, GameObject* pSecond)
{
    return pFirst && pSecond && pFirst->GetPositionY() < pSecond->GetPositionY();
}

void instance_gnomeregan::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
        case TYPE_GRUBBIS:
            m_auiEncounter[TYPE_GRUBBIS] = uiData;
            if (uiData == IN_PROGRESS)
            {
                // Sort the explosive charges if needed
                if (!m_lExplosiveCharges.empty())
                {
                    // Sort from east to west
                    m_lExplosiveCharges.sort(sortFromEastToWest);

                    // Sort to south and north
                    uint8 uiCounterSouth = 0;
                    uint8 uiCounterNorth = 0;
                    GameObject* pCaveInSouth = instance->GetGameObject(m_uiCaveInSouthGUID);
                    GameObject* pCaveInNorth = instance->GetGameObject(m_uiCaveInNorthGUID);
                    if (pCaveInSouth && pCaveInNorth)
                    {
                        for (const auto& pGo : m_lExplosiveCharges)
                        {
                            if (pGo->GetDistanceOrder(pCaveInSouth, pCaveInNorth) && uiCounterSouth < MAX_EXPLOSIVES_PER_SIDE)
                            {
                                m_auiExplosiveSortedGUIDs[0][uiCounterSouth] = pGo->GetGUID();
                                uiCounterSouth++;
                            }
                            else if (uiCounterNorth < MAX_EXPLOSIVES_PER_SIDE)
                            {
                                m_auiExplosiveSortedGUIDs[1][uiCounterNorth] = pGo->GetGUID();
                                uiCounterNorth++;
                            }
                        }
                        m_lExplosiveCharges.clear();
                    }
                }
            }
            if (uiData == FAIL)
            {
                // Despawn possible spawned explosive charges
                SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_USE);
            }
            if (uiData == DONE)
            {
                for (const auto& guid : m_lRedRocketGUIDs)
                    DoRespawnGameObject(guid, HOUR);
            }
            break;
        case TYPE_EXPLOSIVE_CHARGE:
            switch (uiData)
            {
                case DATA_EXPLOSIVE_CHARGE_1:
                    DoRespawnGameObject(m_auiExplosiveSortedGUIDs[0][0], HOUR);
                    m_luiSpawnedExplosiveChargeGUIDs.push_back(m_auiExplosiveSortedGUIDs[0][0]);
                    break;
                case DATA_EXPLOSIVE_CHARGE_2:
                    DoRespawnGameObject(m_auiExplosiveSortedGUIDs[0][1], HOUR);
                    m_luiSpawnedExplosiveChargeGUIDs.push_back(m_auiExplosiveSortedGUIDs[0][1]);
                    break;
                case DATA_EXPLOSIVE_CHARGE_3:
                    DoRespawnGameObject(m_auiExplosiveSortedGUIDs[1][0], HOUR);
                    m_luiSpawnedExplosiveChargeGUIDs.push_back(m_auiExplosiveSortedGUIDs[1][0]);
                    break;
                case DATA_EXPLOSIVE_CHARGE_4:
                    DoRespawnGameObject(m_auiExplosiveSortedGUIDs[1][1], HOUR);
                    m_luiSpawnedExplosiveChargeGUIDs.push_back(m_auiExplosiveSortedGUIDs[1][1]);
                    break;
                case DATA_EXPLOSIVE_CHARGE_USE:
                    Creature* pBlastmaster = instance->GetCreature(m_uiBlastmasterShortfuseGUID);
                    if (!pBlastmaster)
                        break;
                    for (const auto& guid : m_luiSpawnedExplosiveChargeGUIDs)
                    {
                        if (GameObject* pExplosive = instance->GetGameObject(guid))
                            pExplosive->Use(pBlastmaster);
                    }
                    m_luiSpawnedExplosiveChargeGUIDs.clear();
                    break;
            }
            return;
        case TYPE_THERMAPLUGG:
            m_auiEncounter[TYPE_THERMAPLUGG] = uiData;
            if (uiData == IN_PROGRESS)
            {
                // Make Door locked
                if (GameObject* pDoor = instance->GetGameObject(m_uiDoorFinalChamberGUID))
                {
                    if (pDoor->getLootState() == GO_ACTIVATED)
                        pDoor->ResetDoorOrButton();

                    // Doesn't work here, because the flags are to be reseted on next tick in GO::Update
                    pDoor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                }

                // Always directly activates this bomb-face
                DoActivateBombFace(2);
            }
            else if (uiData == DONE || uiData == FAIL)
            {
                // Make Door unlocked again
                if (GameObject* pDoor = instance->GetGameObject(m_uiDoorFinalChamberGUID))
                {
                    if (pDoor->getLootState() == GO_READY)
                        pDoor->UseDoorOrButton();
                    pDoor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                }

                // Deactivate all remaining BombFaces
                for (uint8 i = 0; i < MAX_GNOME_FACES; i++)
                    DoDeactivateBombFace(i);
            }
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_gnomeregan::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1];

    for (uint32 & i : m_auiEncounter)
        if (i == IN_PROGRESS)
            i = NOT_STARTED;

    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_gnomeregan::GetData(uint32 uiType)
{
    switch (uiType)
    {
        case TYPE_GRUBBIS:
            return m_auiEncounter[0];
        case TYPE_THERMAPLUGG:
            return m_auiEncounter[1];
        default:
            return 0;
    }
}

uint64 instance_gnomeregan::GetData64(uint32 uiData)
{
    switch (uiData)
    {
        case GO_CAVE_IN_NORTH:
            return m_uiCaveInNorthGUID;
        case GO_CAVE_IN_SOUTH:
            return m_uiCaveInSouthGUID;
        case NPC_ALARM_A_BOMB_2600:
            return m_uiAlarmABomb2600GUID;
        default:
            return 0;
    }
}

sBombFace* instance_gnomeregan::GetBombFaces()
{
    return m_asBombFaces;
}

void instance_gnomeregan::DoActivateBombFace(uint8 uiIndex)
{
    if (uiIndex >= MAX_GNOME_FACES)
        return;

    if (!m_asBombFaces[uiIndex].m_bActivated)
    {
        DoUseDoorOrButton(m_asBombFaces[uiIndex].m_uiGnomeFaceGUID);
        m_asBombFaces[uiIndex].m_bActivated = true;
        m_asBombFaces[uiIndex].m_uiBombTimer = 3000;
    }
}

void instance_gnomeregan::DoDeactivateBombFace(uint8 uiIndex)
{
    if (uiIndex >= MAX_GNOME_FACES)
        return;

    if (m_asBombFaces[uiIndex].m_bActivated)
    {
        DoUseDoorOrButton(m_asBombFaces[uiIndex].m_uiGnomeFaceGUID);
        m_asBombFaces[uiIndex].m_bActivated = false;
        m_asBombFaces[uiIndex].m_uiBombTimer = 0;
    }
}

InstanceData* GetInstanceData_instance_gnomeregan(Map* pMap)
{
    return new instance_gnomeregan(pMap);
}

void AddSC_instance_gnomeregan()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_gnomeregan";
    pNewScript->GetInstanceData = &GetInstanceData_instance_gnomeregan;
    pNewScript->RegisterSelf();
}

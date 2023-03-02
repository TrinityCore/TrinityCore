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

#include "scriptPCH.h"
#include "blackfathom_deeps.h"

/* Encounter 0 = Twilight Lord Kelris
   Encounter 1 = Shrine event
   Must kill twilight lord for shrine event to be possible
 */


/* This is the spawn pattern for the event mobs
*       D
*   0       3
*   1   S   4
*   2       5
*       E

* This event spawns 4 sets of mobs
* The order in whitch the fires are lit doesn't matter

* First: 3 Snapjaws: Positions 0, 1, 4, 5                   // 4 Aku'mai Snapjaw (Turtle) ID 4825
* Second: 2 Servants: Positions 1, 4                        // 2 Aku'mai Servant (water elemental) ID 4978
* Third: 4 Crabs: Positions 0, 2, 3, 4                      // 4 NPC_MURKSHALLOW_SNAPCLAW
* Fourth: 10 Murkshallows: Positions 2*0, 1, 2, 3, 4, 2*5   // 8

* On wipe the mobs don't despawn; they stay there until player returns
*/

struct Locations
{
    float m_fX, m_fY, m_fZ, m_fO;
};

static const Locations aSpawnLocations[6] = // Should be near the correct positions
{
    { -768.949f, -174.413f, -25.87f, 3.09f}, // Left side
    { -768.888f, -164.238f, -25.87f, 3.09f},
    { -768.951f, -153.911f, -25.88f, 3.09f},
    { -867.782f, -174.352f, -25.87f, 6.27f}, // Right side
    { -867.875f, -164.089f, -25.87f, 6.27f},
    { -867.859f, -153.927f, -25.88f, 6.27f}
};

struct PosCount
{
    uint8 m_uiCount, m_uiSummonPosition;
};

struct SummonInformation
{
    uint8 m_uiWaveIndex;
    uint32 m_uiNpcEntry;
    PosCount m_aCountAndPos[3];
};

static const SummonInformation aWaveSummonInformation[] =
{
    {0, NPC_AKUMAI_SNAPJAW, {{1, 0}, {1, 1}, {1, 5}}},
    {0, NPC_AKUMAI_SNAPJAW, {{1, 4}, {0, 0}, {0, 0}}},
    {1, NPC_AKUMAI_SERVANT, {{1, 1}, {1, 4}, {0, 0}}},
    {2, NPC_MURKSHALLOW_SNAPCLAW, {{1, 0}, {1, 2}, {0, 0}}},
    {2, NPC_MURKSHALLOW_SNAPCLAW, {{1, 3}, {1, 4}, {0, 0}}},
    {3, NPC_MURKSHALLOW_SOFTSHELL, {{2, 0}, {1, 1}, {1, 2}}},
    {3, NPC_MURKSHALLOW_SOFTSHELL, {{1, 3}, {1, 4}, {2, 5}}}
};

struct instance_blackfathom_deeps : public ScriptedInstance
{
    instance_blackfathom_deeps(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint64 m_uiTwilightLordKelrisGUID;
    uint64 m_uiShrine1GUID;
    uint64 m_uiShrine2GUID;
    uint64 m_uiShrine3GUID;
    uint64 m_uiShrine4GUID;
    uint64 m_uiShrineOfGelihastGUID;
    uint64 m_uiAltarOfTheDeepsGUID;
    uint64 m_uiMainDoorGUID;
    uint8  m_uiShrinesLit;
    uint32 m_uiSpawnMobsTimer[4];
    std::list<uint64> m_lWaveMobsGUIDList;
    uint32 m_uiCheckEventEnd;

    uint32 m_auiEncounter[INSTANCE_BFD_MAX_ENCOUNTER];
    std::string strInstData;

    void Initialize() override
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
        m_uiShrinesLit = 0;
        m_lWaveMobsGUIDList.clear();
        m_uiCheckEventEnd = 1000;

        for (uint32 & i : m_uiSpawnMobsTimer)
            i = 0;
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == 4832)
            m_uiTwilightLordKelrisGUID = pCreature->GetGUID();
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_SHRINE_1:
                m_uiShrine1GUID = pGo->GetGUID();
                break;
            case GO_SHRINE_2:
                m_uiShrine2GUID = pGo->GetGUID();
                break;
            case GO_SHRINE_3:
                m_uiShrine3GUID = pGo->GetGUID();
                break;
            case GO_SHRINE_4:
                m_uiShrine4GUID = pGo->GetGUID();
                break;
            case 103015:
                m_uiShrineOfGelihastGUID = pGo->GetGUID();
                break;
            case 103016:
                m_uiAltarOfTheDeepsGUID = pGo->GetGUID();
                break;
            case GO_PORTAL_DOOR:
                m_uiMainDoorGUID = pGo->GetGUID();
                if (m_auiEncounter[BFD_ENCOUNTER_SHRINE] == DONE && m_auiEncounter[BFD_ENCOUNTER_KELRIS] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_KELRIS:
                if (uiData == DONE && m_auiEncounter[BFD_ENCOUNTER_SHRINE] == DONE)
                    DoUseDoorOrButton(m_uiMainDoorGUID);

                m_auiEncounter[BFD_ENCOUNTER_KELRIS] = uiData;
                break;
            case TYPE_SHRINE:
                if (uiData == IN_PROGRESS)
                {
                    ASSERT(m_uiShrinesLit < 4);
                    m_uiSpawnMobsTimer[m_uiShrinesLit] = 3000;
                    m_uiCheckEventEnd = 5000;
                    ++m_uiShrinesLit;
                }
                /*if (m_uiShrinesLit > 3)
                    uiData = DONE;*/
                else if (uiData == DONE && m_auiEncounter[BFD_ENCOUNTER_KELRIS] == DONE)
                    DoUseDoorOrButton(m_uiMainDoorGUID);

                m_auiEncounter[BFD_ENCOUNTER_SHRINE] = uiData;
                break;
            case TYPE_AQUANIS:
                m_auiEncounter[BFD_ENCOUNTER_AQUANIS] = uiData;
                break;
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[BFD_ENCOUNTER_KELRIS] << " " << m_auiEncounter[BFD_ENCOUNTER_SHRINE] << " " << m_auiEncounter[BFD_ENCOUNTER_AQUANIS];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    char const* Save() override
    {
        return strInstData.c_str();
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_KELRIS:
                return m_auiEncounter[BFD_ENCOUNTER_KELRIS];
            case TYPE_SHRINE:
                return m_auiEncounter[BFD_ENCOUNTER_SHRINE];
            case TYPE_AQUANIS:
                return m_auiEncounter[BFD_ENCOUNTER_AQUANIS];
        }

        return 0;
    }

    uint64 GetData64(uint32 uiData) override
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

    void Load(char const* chrIn) override
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);
        loadStream >> m_auiEncounter[BFD_ENCOUNTER_KELRIS] >> m_auiEncounter[BFD_ENCOUNTER_SHRINE] >> m_auiEncounter[BFD_ENCOUNTER_AQUANIS];

        for (uint32 & i : m_auiEncounter)
            if (i == IN_PROGRESS)
                i = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
    void OnCreatureDeath(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == NPC_BARON_AQUANIS)
            SetData(TYPE_AQUANIS, DONE);
    }


    void DoSpawnMobs(uint8 uiWaveIndex)
    {
        Creature* pKelris = instance->GetCreature(m_uiTwilightLordKelrisGUID);
        if (!pKelris)
            return;

        float fX_resp, fY_resp, fZ_resp;
        pKelris->GetRespawnCoord(fX_resp, fY_resp, fZ_resp);

        for (const auto& i : aWaveSummonInformation)
        {
            if (i.m_uiWaveIndex != uiWaveIndex)
                continue;

            // Summon mobs at positions
            for (uint8 j = 0; j < 3; ++j)
            {
                for (uint8 k = 0; k < i.m_aCountAndPos[j].m_uiCount; ++k)
                {
                    uint8 uiPos = i.m_aCountAndPos[j].m_uiSummonPosition;
                    float fPosX = aSpawnLocations[uiPos].m_fX;
                    float fPosY = aSpawnLocations[uiPos].m_fY;
                    float fPosZ = aSpawnLocations[uiPos].m_fZ;
                    float fPosO = aSpawnLocations[uiPos].m_fO;

                    // Adapt fPosY slightly in case of higher summon-counts
                    if (i.m_aCountAndPos[j].m_uiCount > 1)
                        fPosY = fPosY - INTERACTION_DISTANCE / 2 + k * INTERACTION_DISTANCE / i.m_aCountAndPos[j].m_uiCount;

                    if (Creature* pSummoned = pKelris->SummonCreature(i.m_uiNpcEntry, fPosX, fPosY, fPosZ, fPosO, TEMPSUMMON_DEAD_DESPAWN, 0))
                    {
                        pSummoned->SetWalk(true);
                        pSummoned->CastSpell(pSummoned, 7741, true);  // Summoned Demon (Visual)
                        pSummoned->SetHomePosition(fX_resp, fY_resp, fZ_resp, 0);
                        pSummoned->SetInCombatWithZone();
                        //pSummoned->GetMotionMaster()->MovePoint(0, fX_resp, fY_resp, fZ_resp);
                        m_lWaveMobsGUIDList.push_back(pSummoned->GetGUID());
                    }
                }
            }
        }
    }

    // Check if all the summoned event mobs are dead
    bool IsWaveEventFinished()
    {
        // If not all fires are lighted return
        if (m_uiShrinesLit < 4)
            return false;

        // Check if all mobs are dead
        for (const auto& guid : m_lWaveMobsGUIDList)
        {
            if (Creature* WaveMob = instance->GetCreature(guid))
                if (WaveMob->IsAlive())
                    return false;
        }
        return true;
    }

    void Update(uint32 uiDiff) override
    {
        // Only use this function if shrine event is in progress
        if (m_auiEncounter[BFD_ENCOUNTER_SHRINE] != IN_PROGRESS)
            return;

        if (m_uiCheckEventEnd <= uiDiff)
        {
            if (IsWaveEventFinished())
                SetData(TYPE_SHRINE, DONE);
            else
                m_uiCheckEventEnd = 1000;
        }
        else
            m_uiCheckEventEnd -= uiDiff;

        for (uint8 i = 0; i < 4; ++i)
        {
            if (m_uiSpawnMobsTimer[i])
            {
                if (m_uiSpawnMobsTimer[i] <= uiDiff)
                {
                    DoSpawnMobs(i);
                    m_uiSpawnMobsTimer[i] = 0;
                }
                else
                    m_uiSpawnMobsTimer[i] -= uiDiff;
            }
        }
    }
};

InstanceData* GetInstanceData_instance_blackfathom_deeps(Map* pMap)
{
    return new instance_blackfathom_deeps(pMap);
}

struct go_fire_of_akumaiAI: public GameObjectAI
{
    go_fire_of_akumaiAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser) override
    {
        ScriptedInstance* pInstance = (ScriptedInstance*)me->GetInstanceData();

        if (!pInstance)
            return false;

        if (pInstance->GetData(TYPE_KELRIS) != DONE)
            return false;

        me->SetGoState(GO_STATE_ACTIVE);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        pInstance->SetData(TYPE_SHRINE, IN_PROGRESS);

        return true;
    }
};

GameObjectAI* GetAIgo_fire_of_akumai(GameObject *pGo)
{
    return new go_fire_of_akumaiAI(pGo);
}
static float const afAquanisPos[4] = { -782.21f, -63.26f, -42.43f, 2.36f };
bool GOUse_go_fathom_stone(Player* pPlayer, GameObject* pGo)
{
    instance_blackfathom_deeps* pInstance = (instance_blackfathom_deeps*)pGo->GetInstanceData();
    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_AQUANIS) == NOT_STARTED)
    {
        pPlayer->SummonCreature(NPC_BARON_AQUANIS, afAquanisPos[0], afAquanisPos[1], afAquanisPos[2], afAquanisPos[3], TEMPSUMMON_DEAD_DESPAWN, 0);
        pInstance->SetData(TYPE_AQUANIS, IN_PROGRESS);
    }

    return false;
}
void AddSC_instance_blackfathom_deeps()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "instance_blackfathom_deeps";
    newscript->GetInstanceData = &GetInstanceData_instance_blackfathom_deeps;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_fire_of_akumai";
    newscript->GOGetAI = &GetAIgo_fire_of_akumai;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_fathom_stone";
    newscript->pGOHello = &GOUse_go_fathom_stone;
    newscript->RegisterSelf();
}

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
SDName: Instance_Ruins_of_Ahnqiraj
SD%Complete: 80
SDComment: Add in DB and save/load for spawning andorov
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "CreatureGroups.h"
#include "ruins_of_ahnqiraj.h"

instance_ruins_of_ahnqiraj::instance_ruins_of_ahnqiraj(Map* pMap) : ScriptedInstance(pMap)
{
    Initialize();
};

void instance_ruins_of_ahnqiraj::Initialize()
{
    m_uiKurinnaxxGUID = 0;
    for (uint32 & waveIndex : m_uiWaveMembersCount)
        waveIndex = WAVE_MEMBERS_INIT_COUNT;
    m_uiBuruGUID = 0;
    m_uiOssirianGUID = 0;
    m_uiAndorovGUID = 0;
    m_lKaldoreiElites.clear();
    m_lOssirianPylons.clear();

    m_bIsAQDoorOn = false;
    p_doorGuid.Clear();

    m_uiGladiatorDeath = 0;

    m_uiQeezGUID = 0;
    m_uiTuubidGUID = 0;
    m_uiDrennGUID = 0;
    m_uiXurremGUID = 0;
    m_uiYeggethGUID = 0;
    m_uiPakkonGUID = 0;
    m_uiZerranGUID = 0;
    m_uiRajaxxGUID = 0;

    m_uiRajaxxEventResetTimer = 2000;
    m_bRajaxxEventIsToReset = false;
}

bool instance_ruins_of_ahnqiraj::IsEncounterInProgress() const
{
    for (uint32 i : m_auiEncounter)
        if (i == IN_PROGRESS || i == SPECIAL)
            return true;
    return false;
}

uint64 instance_ruins_of_ahnqiraj::GetData64(uint32 uiData)
{
    uint64 m_uiGUIDvalue;
    uint64 m_uiYeggethSizeList;
    uint64 m_uiRandomYeggethList;
    uint32 m_uiIterator;

    switch (uiData)
    {
        case DATA_OSSIRIAN:
            return m_uiOssirianGUID;
        case DATA_BURU:
            return m_uiBuruGUID;
        case DATA_ANDOROV:
            return m_uiAndorovGUID;
        case DATA_KURINNAXX:
            return m_uiKurinnaxxGUID;
        case DATA_QEEZ:
            return m_uiQeezGUID;
        case DATA_TUUBID:
            return m_uiTuubidGUID;
        case DATA_DRENN:
            return m_uiDrennGUID;
        case DATA_XURREM:
            return m_uiXurremGUID;
        case DATA_YEGGETH:
            return m_uiYeggethGUID;
        case DATA_PAKKON:
            return m_uiPakkonGUID;
        case DATA_ZERRAN:
            return m_uiZerranGUID;
        case DATA_RAJAXX:
            return m_uiRajaxxGUID;

        case DATA_YEGGETH_SHIELD:
            m_uiGUIDvalue = 0;
            m_uiYeggethSizeList = m_lYeggethShieldList.size();
            m_uiRandomYeggethList = urand(0, m_uiYeggethSizeList);
            m_uiIterator = 0;

            for (std::list<uint64>::const_iterator itr = m_lYeggethShieldList.begin();
                    itr != m_lYeggethShieldList.end() || m_uiIterator != m_uiRandomYeggethList; itr++)
            {
                m_uiGUIDvalue = instance->GetCreature(*itr)->GetObjectGuid();
                m_uiIterator++;
            }
            return m_uiGUIDvalue;

        default:
            return 0;
    }
}

void instance_ruins_of_ahnqiraj::OnCreatureEnterCombat(Creature * pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_CAPTAIN_QEEZ:
        case NPC_CAPTAIN_TUUBID:
        case NPC_CAPTAIN_DRENN:
        case NPC_CAPTAIN_XURREM:
        case NPC_MAJOR_YEGGETH:
        case NPC_MAJOR_PAKKON:
        case NPC_COLONEL_ZERRAN:
        case NPC_SWARMGUARD_NEEDLER:
        case NPC_QIRAJI_WARRIOR:
            /** Create Yeggeth list for Rajaxx Shield ability */
            if (CreatureGroup* g = pCreature->GetCreatureGroup())
                if (g->GetOriginalLeaderGuid().GetEntry() == NPC_MAJOR_YEGGETH)
                    m_lYeggethShieldList.push_back(pCreature->GetGUID());
            // If any creature from Rajaxx's wave enters combat, start Rajaxx event.
            if (m_auiEncounter[TYPE_RAJAXX] == NOT_STARTED)
                SetData(TYPE_RAJAXX, IN_PROGRESS);
            m_bRajaxxEventIsToReset = false;
        // no break
        case NPC_KURINNAXX:
        case NPC_RAJAXX:
        case NPC_BURU:
        case NPC_MOAM:
        case NPC_AYAMISS:
        case NPC_OSSIRIAN:
            if (!m_bIsAQDoorOn)
            {
                GameObject *pAQDoor = pCreature->SummonGameObject(176149,
                                        -8526,
                                        1507.4f,
                                        49,
                                        4.20662f, 0, 0, 0.861534f, -0.5077f, -1, false);

                p_doorGuid = pAQDoor->GetObjectGuid();
                m_bIsAQDoorOn = true;
            }
            break;
        default:
            break;
    }
}

void instance_ruins_of_ahnqiraj::OnCreatureEvade(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_CAPTAIN_QEEZ:
        case NPC_CAPTAIN_TUUBID:
        case NPC_CAPTAIN_DRENN:
        case NPC_CAPTAIN_XURREM:
        case NPC_MAJOR_YEGGETH:
        case NPC_MAJOR_PAKKON:
        case NPC_COLONEL_ZERRAN:
        case NPC_SWARMGUARD_NEEDLER:
        case NPC_QIRAJI_WARRIOR:
            // If any creature from Rajaxx's wave is on evade mode, reset Rajaxx.
            m_uiRajaxxEventResetTimer = 2000;
            m_bRajaxxEventIsToReset = true;
        // no break
        case NPC_KURINNAXX:
        case NPC_RAJAXX:
        case NPC_BURU:
        case NPC_MOAM:
        case NPC_AYAMISS:
        case NPC_OSSIRIAN:
            if (m_bIsAQDoorOn)
            {
                if (GameObject* door = pCreature->GetMap()->GetGameObject(p_doorGuid))
                    door->AddObjectToRemoveList();
                p_doorGuid.Clear();
                m_bIsAQDoorOn = false;
            }
            break;
        case NPC_KALDOREI_ELITE:
            if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
            {
                if (pAndorov->IsInCombat())
                {
                    pCreature->AddThreatsOf(pAndorov);
                    break;
                }
            }
            break;
        default:
            break;
    }
}

void instance_ruins_of_ahnqiraj::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_KURINNAXX:
            m_uiKurinnaxxGUID   = pCreature->GetGUID();
            break;
        case NPC_CAPTAIN_QEEZ:
            m_uiQeezGUID     = pCreature->GetGUID();
            break;
        case NPC_CAPTAIN_TUUBID:
            m_uiTuubidGUID = pCreature->GetGUID();
            break;
        case NPC_CAPTAIN_DRENN:
            m_uiDrennGUID   = pCreature->GetGUID();
            break;
        case NPC_CAPTAIN_XURREM:
            m_uiXurremGUID = pCreature->GetGUID();
            break;
        case NPC_MAJOR_YEGGETH:
            m_uiYeggethGUID = pCreature->GetGUID();
            break;
        case NPC_MAJOR_PAKKON:
            m_uiPakkonGUID   = pCreature->GetGUID();
            break;
        case NPC_COLONEL_ZERRAN:
            m_uiZerranGUID = pCreature->GetGUID();
            break;
        case NPC_RAJAXX:
            m_uiRajaxxGUID         = pCreature->GetGUID();
            break;
        case NPC_BURU:
            m_uiBuruGUID             = pCreature->GetGUID();
            break;
        case NPC_OSSIRIAN:
            m_uiOssirianGUID     = pCreature->GetGUID();
            break;
        case NPC_GENERAL_ANDOROV:
            // Andorov is spawn only if Kurinnaxx is dead and Rajaxx alive.
            m_uiAndorovGUID = pCreature->GetGUID();
            if ((m_auiEncounter[TYPE_KURINNAXX] != DONE) || (m_auiEncounter[TYPE_RAJAXX] == DONE))
            {
                pCreature->ForcedDespawn(0);
                pCreature->SetRespawnTime(AQ_RESPAWN_5_MINUTES);
                //    pCreature->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
            }
            break;
        case NPC_KALDOREI_ELITE:
            // Elites are spawn only if Kurinnaxx is dead and Rajaxx alive.
            m_lKaldoreiElites.push_back(pCreature->GetGUID());
            if ((m_auiEncounter[TYPE_KURINNAXX] != DONE) || (m_auiEncounter[TYPE_RAJAXX] == DONE))
            {
                pCreature->ForcedDespawn(0);
                pCreature->SetRespawnTime(AQ_RESPAWN_5_MINUTES);
                //    pCreature->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
            }
            break;
        default:
            break;
    }
}

void instance_ruins_of_ahnqiraj::OnObjectCreate(GameObject *pGo)
{
    switch (pGo->GetEntry())
    {
        case 180619:
            m_lOssirianPylons.push_back(pGo->GetGUID());
            if (pGo->GetGUID() == 399461)
            {
                pGo->SetSpawnedByDefault(false);
                pGo->SetRespawnTime(-10);
                pGo->Refresh();
                pGo->Respawn();
            }
            else
            {
                pGo->SetSpawnedByDefault(false);
                pGo->SetRespawnTime(-5);
                pGo->UpdateObjectVisibility();
            }
            break;
    }
}

void instance_ruins_of_ahnqiraj::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_KURINNAXX:
        case NPC_RAJAXX:
        case NPC_BURU:
        case NPC_MOAM:
        case NPC_AYAMISS:
        case NPC_OSSIRIAN:
            if (m_bIsAQDoorOn)
            {
                if (GameObject* door = pCreature->GetMap()->GetGameObject(p_doorGuid))
                    door->AddObjectToRemoveList();
                p_doorGuid.Clear();
                m_bIsAQDoorOn = false;
            }
            break;
        case NPC_CAPTAIN_QEEZ:
        case NPC_CAPTAIN_TUUBID:
        case NPC_CAPTAIN_DRENN:
        case NPC_CAPTAIN_XURREM:
        case NPC_MAJOR_YEGGETH:
        case NPC_MAJOR_PAKKON:
        case NPC_COLONEL_ZERRAN:
        case NPC_SWARMGUARD_NEEDLER:
        case NPC_QIRAJI_WARRIOR:

            if (pCreature->GetEntry() == NPC_SWARMGUARD_NEEDLER || pCreature->GetEntry() == NPC_QIRAJI_WARRIOR)
            {
                pCreature->ForcedDespawn(3000);
                pCreature->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
            }
            // Count deaths in Rajaxx's waves
            if (GetWaveFromCreature(pCreature) > 0)
            {
                uint8 waveIndex = GetWaveFromCreature(pCreature) - 1;
                ASSERT(waveIndex < WAVE_MAX);
                if (m_uiWaveMembersCount[waveIndex] > 0)
                    m_uiWaveMembersCount[waveIndex]--;
            }
            break;
        case NPC_GENERAL_ANDOROV:
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        // no break
        case NPC_KALDOREI_ELITE:
            // No respawn before Kurinaxx's death or during Rajaxx event.
            if ((m_auiEncounter[TYPE_KURINNAXX] != DONE) || (m_auiEncounter[TYPE_RAJAXX] == IN_PROGRESS))
                pCreature->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
            else
                pCreature->SetRespawnTime(AQ_RESPAWN_15_MINUTES);
            break;
        default:
            break;
    }
}

uint32 instance_ruins_of_ahnqiraj::GetData(uint32 uiType)
{
    switch (uiType)
    {
        case TYPE_QIRAJI_GLADIATOR:
            return m_uiGladiatorDeath;
            break;
        case TYPE_KURINNAXX:
        case TYPE_GENERAL_ANDOROV:
        case TYPE_RAJAXX:
        case TYPE_BURU:
        case TYPE_MOAM:
        case TYPE_AYAMISS:
        case TYPE_OSSIRIAN:
            return m_auiEncounter[uiType];
        case TYPE_WAVE1:
        case TYPE_WAVE2:
        case TYPE_WAVE3:
        case TYPE_WAVE4:
        case TYPE_WAVE5:
        case TYPE_WAVE6:
        case TYPE_WAVE7:
            ASSERT(uiType - WAVE_OFFSET < WAVE_MAX);
            return m_uiWaveMembersCount[uiType - WAVE_OFFSET];
        default:
            return 0;
    }
}

void instance_ruins_of_ahnqiraj::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
        case TYPE_QIRAJI_GLADIATOR:
            if (uiData > 0)
                m_uiGladiatorDeath = m_uiGladiatorDeath + uiData;
            else
                m_uiGladiatorDeath = 0;
            return;
        case TYPE_KURINNAXX:
            /** Spawn Andorov 3 minutes after Kurinaxx death */
            if (uiData == DONE)
                SetAndorovSquadRespawnTime(AQ_RESPAWN_3_MINUTES);

            m_auiEncounter[TYPE_KURINNAXX] = uiData;
            break;
        case TYPE_GENERAL_ANDOROV:
            if (uiData == NOT_STARTED || uiData == FAIL)
            {
                if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
                    pAndorov->SetDefaultGossipMenuId(ANDOROV_GOSSIP_NOT_STARTED);
            }
            if (uiData == IN_PROGRESS)
            {
                SetAndorovSquadFaction(1254);
                if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
                {
                    pAndorov->SetDefaultGossipMenuId(ANDOROV_GOSSIP_IN_PROGRESS);
                    pAndorov->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR);
                }
            }
            m_auiEncounter[TYPE_GENERAL_ANDOROV] = uiData;
            break;
        case TYPE_RAJAXX:
            if (uiData == NOT_STARTED)
            {
                /** Respawn Andorov and elite in 15 minutes */
                if (m_auiEncounter[TYPE_KURINNAXX] == DONE)
                    SetAndorovSquadRespawnTime(AQ_RESPAWN_15_MINUTES);

                /** Reset waves casualties count */
                for (uint32 & waveIndex : m_uiWaveMembersCount)
                    waveIndex = WAVE_MEMBERS_INIT_COUNT;
            }
            if (uiData == DONE)
            {
                if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
                {
                    // World of Warcraft Client Patch 1.10.0 (2006-03-28)
                    // - Lieutenant General Andorov will now offer supplies if kept alive
                    //   through the battle.
                    if (sWorld.GetWowPatch() >= WOW_PATCH_110)
                        pAndorov->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR);

                    pAndorov->SetDefaultGossipMenuId(ANDOROV_GOSSIP_DONE);
                    pAndorov->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
                }
                ForceAndorovSquadDespawn(120000); // Andorov disapears 2 minutes after end of combat
            }
            m_bRajaxxEventIsToReset = false;
            m_auiEncounter[TYPE_RAJAXX] = uiData;
            break;
        case TYPE_WAVE1:
        case TYPE_WAVE2:
        case TYPE_WAVE3:
        case TYPE_WAVE4:
        case TYPE_WAVE5:
        case TYPE_WAVE6:
        case TYPE_WAVE7:
            m_uiWaveMembersCount[uiType - WAVE_OFFSET] = uiData;
            break;
        case TYPE_OSSIRIAN:
            if (uiData == FAIL || uiData == DONE)
            {
                for (const auto& crystalGuid : crystalGuids)
                {
                    if (GameObject* invoc = instance->GetGameObject(crystalGuid))
                        invoc->AddObjectToRemoveList();
                }

                crystalGuids.clear();
                crystalIndexes.clear();
                crystalIndexHistory.clear();
            }
            m_auiEncounter[TYPE_OSSIRIAN] = uiData;
            break;
        case TYPE_BURU:
        case TYPE_MOAM:
        case TYPE_AYAMISS:
            m_auiEncounter[uiType] = uiData;
            break;
        default:
            return;
    }

    /** What is the goal of this ???? */
    if (uiType < INSTANCE_RUINS_AQ_MAX_ENCOUNTER && uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
            << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5] << " " << m_auiEncounter[6];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

char const* instance_ruins_of_ahnqiraj::Save()
{
    return strInstData.c_str();
}

void instance_ruins_of_ahnqiraj::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);

    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
        >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6];

    for (uint32 & i : m_auiEncounter)
        if (i == IN_PROGRESS || i > SPECIAL)           // Do not load an encounter as "In Progress" - reset it instead.
            i = NOT_STARTED;

    if (m_auiEncounter[TYPE_GENERAL_ANDOROV] == DONE)
        m_auiEncounter[TYPE_GENERAL_ANDOROV] = NOT_STARTED;

    OUT_LOAD_INST_DATA_COMPLETE;
}

void instance_ruins_of_ahnqiraj::Update(uint32 uiDiff)
{
    if (m_bRajaxxEventIsToReset)
    {
        if (m_uiRajaxxEventResetTimer < uiDiff)
        {
            if (Creature* pRajaxx = instance->GetCreature(m_uiRajaxxGUID))
                pRajaxx->AI()->EnterEvadeMode();
            m_bRajaxxEventIsToReset = false;
        }
        else
            m_uiRajaxxEventResetTimer -= uiDiff;
    }

    for (auto iter = crystalIndexes.begin(); iter != crystalIndexes.end();)
    {
        // Crystal was despawned but still in our index for some reason
        if (!instance->GetGameObject(iter->first))
        {
            iter = crystalIndexes.erase(iter);
        }
        else
            ++iter;
    }
}

/* Private methods */

uint8 instance_ruins_of_ahnqiraj::GetWaveFromCreature(Creature* creature)
{
    CreatureGroup* group = creature->GetCreatureGroup();
    if (!group)
    {
//sLog.nostalrius("no group");
        return 0;
    }
//sLog.nostalrius("group leader : %u",group->GetLeaderGuid().GetEntry());
    switch (group->GetOriginalLeaderGuid().GetEntry())
    {
        case NPC_CAPTAIN_QEEZ:
            return 1;
        case NPC_CAPTAIN_TUUBID:
            return 2;
        case NPC_CAPTAIN_DRENN:
            return 3;
        case NPC_CAPTAIN_XURREM:
            return 4;
        case NPC_MAJOR_YEGGETH:
            return 5;
        case NPC_MAJOR_PAKKON:
            return 6;
        case NPC_COLONEL_ZERRAN:
            return 7;
        default:
            return 0;
    }
}

void instance_ruins_of_ahnqiraj::SetAndorovSquadRespawnTime(uint32 nextRespawnDelay)
{
    if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
    {
        if (!pAndorov->IsAlive())
            pAndorov->SetRespawnTime(nextRespawnDelay);
    }
    for (const auto& guid : m_lKaldoreiElites)
    {
        if (Creature* pElite = instance->GetCreature(guid))
        {
            if (!pElite->IsAlive())
                pElite->SetRespawnTime(nextRespawnDelay);
        }
    }
}

void instance_ruins_of_ahnqiraj::SetAndorovSquadFaction(uint32 faction)
{
    if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
    {
        pAndorov->SetFactionTemplateId(faction);
        pAndorov->SetPvP(true);
    }
    for (const auto& guid : m_lKaldoreiElites)
    {
        if (Creature* pElite = instance->GetCreature(guid))
        {
            pElite->SetFactionTemplateId(faction);
            pElite->SetPvP(true);
        }
    }
}

void instance_ruins_of_ahnqiraj::ForceAndorovSquadDespawn(uint32 timeToDespawn)
{
    if (Creature* pAndorov = instance->GetCreature(m_uiAndorovGUID))
    {
        pAndorov->ForcedDespawn(timeToDespawn);
        pAndorov->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
    }
    for (const auto& guid : m_lKaldoreiElites)
    {
        if (Creature* pElite = instance->GetCreature(guid))
        {
            pElite->ForcedDespawn(timeToDespawn);
            pElite->SetRespawnTime(AQ_RESPAWN_FOUR_DAYS);
        }
    }
}

/**
* The spawn logic is as follows (approximated as much as possible from
* multiple videos):
* https://www.youtube.com/watch?v=Y2ITGk5_8hc
* https://www.youtube.com/watch?v=fyivFwDIAtI
* https://www.youtube.com/watch?v=qb0zZ3xkKLk
* https://www.youtube.com/watch?v=Mlh8lSaBqPk
* https://www.youtube.com/watch?v=Je2USKK2qhs
* 1. From the last crystal used, find a crystal location within 80 yards.
* 2. Spawn two crystals. One at, and one near to, this location
* There are some rules regarding how many crystals should be spawned and
* where.
* 1. Only 2 crystals should be spawned at once
* 2. We should not spawn the same crystal as the one used
* 3. We should maintain a short history of spawned locations to ensure some variety
*/
void instance_ruins_of_ahnqiraj::SpawnNewCrystals(ObjectGuid usedCrystal)
{
    uint32 used = 0;
    auto previous = crystalIndexes.find(usedCrystal);
    if (previous != crystalIndexes.end())
    {
        used = previous->second;
        crystalIndexes.erase(previous);
    }

    // Truncate the history first
    crystalIndexHistory.resize(2);

    crystalIndexHistory.push_front(used);

    SpawnLocations previousLoc = CrystalSpawn.at(used);
    // Expand the search after a certain number of attempts otherwise
    // it may be impossible to spawn one within range and we deadlock
    uint32 attempts = 0;
    float maxDistanceLimit = OSSIRIAN_CRYSTAL_INITIAL_DIST;
    float minDistanceLimit = maxDistanceLimit / 2;

    // We already have another crystal spawned. Use that as the hint
    if (!crystalIndexes.empty())
    {
        maxDistanceLimit *= 0.75f;
        minDistanceLimit *= 0.75f;
        uint32 hint = crystalIndexes.begin()->second;
        previousLoc = CrystalSpawn.at(hint);
        crystalIndexHistory.push_front(hint);
    }

    std::vector<uint32> possibleIndexes;
    possibleIndexes.reserve(CrystalSpawn.size());
    for (uint32 i = 0; i < CrystalSpawn.size(); ++i)
    {
        auto iter = std::find(crystalIndexHistory.cbegin(), crystalIndexHistory.cend(), i);
        if (iter != crystalIndexHistory.end())
            continue;

        possibleIndexes.push_back(i);
    }

    std::random_shuffle(possibleIndexes.begin(), possibleIndexes.end());

    while (crystalIndexes.size() < OSSIRIAN_CRYSTAL_NUM_ACTIVE)
    {
        for (auto iter = possibleIndexes.begin(); iter != possibleIndexes.end() && crystalIndexes.size() < OSSIRIAN_CRYSTAL_NUM_ACTIVE;)
        {
            if (++attempts >= 5)
            {
                // increase distance to search further each extra attempt
                minDistanceLimit *= 0.9f;
                maxDistanceLimit *= 1.1f;
            }

            uint32 newIndex = *iter;
            const SpawnLocations& newLoc = CrystalSpawn.at(newIndex);
            float dist = sqrt(pow(newLoc.x - previousLoc.x, 2) + pow(newLoc.y - previousLoc.y, 2));
            if (dist > maxDistanceLimit || dist < minDistanceLimit)
            {
                ++iter;
                continue;
            }

            GameObject* pCrystal = instance->SummonGameObject(GO_OSSIRIAN_CRYSTAL,
                newLoc.x,
                newLoc.y,
                newLoc.z,
                0, 0, 0, 0, 0, -1, 1);

            if (!pCrystal)
            {
                sLog.outError("[OSSIRIAN] Unable to spawn crystal %u at position #%u", GO_OSSIRIAN_CRYSTAL, newIndex);
                return;
            }

            // Use the new location as a hint and reduce the limit so the next one
            // spawns close as well
            maxDistanceLimit *= 0.50f;
            minDistanceLimit *= 0.50f;
            previousLoc = newLoc;
            iter = possibleIndexes.erase(iter); // remove selected index

            crystalGuids.push_back(pCrystal->GetObjectGuid());
            crystalIndexes[pCrystal->GetObjectGuid()] = newIndex;
        }
    }
}

InstanceData* GetInstanceData_instance_ruins_of_ahnqiraj(Map* pMap)
{
    return new instance_ruins_of_ahnqiraj(pMap);
}

void AddSC_instance_ruins_of_ahnqiraj()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_ruins_of_ahnqiraj";
    newscript->GetInstanceData = &GetInstanceData_instance_ruins_of_ahnqiraj;
    newscript->RegisterSelf();
}


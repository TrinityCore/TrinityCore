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
SDName: Instance_Molten_Core
SD%Complete: 0
SDComment: Place Holder
SDCategory: Molten Core
EndScriptData */

#include "scriptPCH.h"
#include "molten_core.h"

#define NPC_FLAMEWAKER_HEALER    11663
#define NPC_FLAMEWAKER_ELITE     11664

struct sSpawnLocation
{
    uint32 m_uiEntry;
    float m_fX;
    float m_fY;
    float m_fZ;
    float m_fO;
};

struct instance_molten_core : ScriptedInstance
{
    explicit instance_molten_core(Map* pMap) : ScriptedInstance(pMap)
    {
        instance_molten_core::Initialize();
    }

    uint32 m_auiEncounter[INSTANCE_MC_MAX_ENCOUNTER];

    uint64 m_uiLucifronGUID, m_uiMagmadarGUID, m_uiGehennasGUID, m_uiGarrGUID, m_uiGeddonGUID, m_uiShazzrahGUID, m_uiSulfuronGUID, m_uiGolemaggGUID, m_uiMajorDomoGUID, m_uiRagnarosGUID, m_uiFlamewakerPriestGUID;
    uint64 m_uiRuneKoroGUID, m_uiRuneZethGUID, m_uiRuneMazjGUID, m_uiRuneTheriGUID, m_uiRuneBlazGUID, m_uiRuneKressGUID, m_uiRuneMohnGUID, m_uiFirelordCacheGUID;
    uint64 RuneActive[7];
    uint32 DomoSpawn;
    uint32 RemoveTimer;

    uint64 GOUseGuidList[7];

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiLucifronGUID = 0;
        m_uiMagmadarGUID = 0;
        m_uiGehennasGUID = 0;
        m_uiGarrGUID = 0;
        m_uiGeddonGUID = 0;
        m_uiShazzrahGUID = 0;
        m_uiSulfuronGUID = 0;
        m_uiGolemaggGUID = 0;
        m_uiMajorDomoGUID = 0;
        m_uiRagnarosGUID = 0;
        m_uiFlamewakerPriestGUID = 0;

        m_uiRuneKoroGUID = 0;
        m_uiRuneZethGUID = 0;
        m_uiRuneMazjGUID = 0;
        m_uiRuneTheriGUID = 0;
        m_uiRuneBlazGUID = 0;
        m_uiRuneKressGUID = 0;
        m_uiRuneMohnGUID = 0;

        m_uiFirelordCacheGUID = 0;

        RemoveTimer = 5000;

        for (int i = 0; i < 7; i++)
        {
            RuneActive[i] = NOT_STARTED;
            GOUseGuidList[i] = 0;
        }

        DomoSpawn = NOT_STARTED;
    }

    bool IsEncounterInProgress() const override
    {
        for (uint32 i : m_auiEncounter)
            if (i == IN_PROGRESS || i == SPECIAL)
                return true;

        return false;
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case 176951:                                    //Sulfuron
                m_uiRuneKoroGUID = pGo->GetGUID();
                if (RuneActive[0] == DONE)
                    GOUseGuidList[0] = pGo->GetGUID();
                break;
            case 176952:                                    //Geddon
                m_uiRuneZethGUID = pGo->GetGUID();
                if (RuneActive[1] == DONE)
                    GOUseGuidList[1] = pGo->GetGUID();
                break;
            case 176953:                                    //Shazzrah
                m_uiRuneMazjGUID = pGo->GetGUID();
                if (RuneActive[2] == DONE)
                    GOUseGuidList[2] = pGo->GetGUID();
                break;
            case 176954:                                    //Golemagg
                m_uiRuneTheriGUID = pGo->GetGUID();
                if (RuneActive[3] == DONE)
                    GOUseGuidList[3] = pGo->GetGUID();
                break;
            case 176955:                                    //Garr
                m_uiRuneBlazGUID = pGo->GetGUID();
                if (RuneActive[4] == DONE)
                    GOUseGuidList[4] = pGo->GetGUID();
                break;
            case 176956:                                    //Magmadar
                m_uiRuneKressGUID = pGo->GetGUID();
                if (RuneActive[5] == DONE)
                    GOUseGuidList[5] = pGo->GetGUID();
                break;
            case 176957:                                    //Gehennas
                m_uiRuneMohnGUID = pGo->GetGUID();
                if (RuneActive[6] == DONE)
                    GOUseGuidList[6] = pGo->GetGUID();
                break;
            case 179703:
                m_uiFirelordCacheGUID = pGo->GetGUID(); //majordomo event chest
                break;
        }
    }

    void OnCreatureRespawn(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_FLAMEWAKER_PRIEST:
                if (m_auiEncounter[TYPE_SULFURON] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_CORE_RAGER:
                if (m_auiEncounter[TYPE_GOLEMAGG] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_FLAMEWAKER:
                if (m_auiEncounter[TYPE_GEHENNAS] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_FLAMEWAKER_PROTECTOR:
                if (m_auiEncounter[TYPE_LUCIFRON] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_CORE_HOUND:
            case NPC_ANCIENT_CORE_HOUND:
                if (m_auiEncounter[TYPE_MAGMADAR] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_GARR:
            case NPC_FIRESWORN:
            case NPC_LAVA_SURGER:
                if (m_auiEncounter[TYPE_GARR] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_DOMO:
                m_auiEncounter[TYPE_MAJORDOMO] = DONE;
                pCreature->AddObjectToRemoveList();
                break;
            case NPC_RAGNAROS:
                m_auiEncounter[TYPE_RAGNAROS] = DONE;
                pCreature->AddObjectToRemoveList();
                break;
            case NPC_LAVA_ANNIHILATOR:
                if (urand(0, 1))
                {
                    pCreature->SetEntry(NPC_FIRELORD);
                    pCreature->UpdateEntry(NPC_FIRELORD);
                }
                pCreature->AIM_Initialize();
                break;
            case NPC_FIRELORD:
                if (urand(0, 1))
                {
                    pCreature->SetEntry(NPC_LAVA_ANNIHILATOR);
                    pCreature->UpdateEntry(NPC_LAVA_ANNIHILATOR);
                }
                pCreature->AIM_Initialize();
                break;
        }
    }

    void OnCreatureEnterCombat(Creature* pCreature) override
    {
        Unit* victim = pCreature->GetVictim();
        if (!victim)
            return;
        std::list<Creature*> DomoListe;
        switch (pCreature->GetEntry())
        {
            case NPC_DOMO:
            case NPC_FLAMEWAKER_HEALER:
            case NPC_FLAMEWAKER_ELITE:
                GetCreatureListWithEntryInGrid(DomoListe, pCreature, NPC_FLAMEWAKER_HEALER, 150.0f);
                GetCreatureListWithEntryInGrid(DomoListe, pCreature, NPC_FLAMEWAKER_ELITE, 150.0f);
                GetCreatureListWithEntryInGrid(DomoListe, pCreature, NPC_DOMO, 150.0f);
                if (!DomoListe.empty())
                {
                    for (const auto& itr : DomoListe)
                    {
                        if (itr->IsAlive() && !itr->IsInCombat())
                            itr->SetInCombatWith(victim);
                    }
                }
                break;
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_LUCIFRON:
                m_uiLucifronGUID = pCreature->GetGUID();
                break;
            case NPC_MAGMADAR:
                m_uiMagmadarGUID = pCreature->GetGUID();
                break;
            case NPC_GEHENNAS:
                m_uiGehennasGUID = pCreature->GetGUID();
                break;
            case NPC_GEDDON:
                m_uiGeddonGUID = pCreature->GetGUID();
                break;
            case NPC_SHAZZRAH:
                m_uiShazzrahGUID = pCreature->GetGUID();
                break;
            case NPC_SULFURON:
                m_uiSulfuronGUID = pCreature->GetGUID();
                break;
            case NPC_GOLEMAGG:
                m_uiGolemaggGUID = pCreature->GetGUID();
                break;
            case NPC_DOMO:
                m_uiMajorDomoGUID = pCreature->GetGUID();
                break;
            case NPC_RAGNAROS:
                m_uiRagnarosGUID = pCreature->GetGUID();
                break;
            case NPC_FLAMEWAKER_PRIEST:
                m_uiFlamewakerPriestGUID = pCreature->GetGUID();
                if (m_auiEncounter[TYPE_SULFURON] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_CORE_RAGER:
                if (m_auiEncounter[TYPE_GOLEMAGG] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_FLAMEWAKER:
                if (m_auiEncounter[TYPE_GEHENNAS] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_FLAMEWAKER_PROTECTOR:
                if (m_auiEncounter[TYPE_LUCIFRON] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_LAVA_ANNIHILATOR:
                if (rand() % 2)
                {
                    pCreature->UpdateEntry(NPC_FIRELORD);
                    pCreature->SetEntry(NPC_FIRELORD);
                    pCreature->AIM_Initialize();
                }
                break;
            case NPC_FIRELORD:
                if (rand() % 2)
                {
                    pCreature->UpdateEntry(NPC_LAVA_ANNIHILATOR);
                    pCreature->SetEntry(NPC_LAVA_ANNIHILATOR);
                    pCreature->AIM_Initialize();
                }
                break;
            case NPC_CORE_HOUND:
            case NPC_ANCIENT_CORE_HOUND:
                if (m_auiEncounter[TYPE_MAGMADAR] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_GARR:
                m_uiGarrGUID = pCreature->GetGUID();
                m_mNpcEntryGuidStore[pCreature->GetEntry()] = pCreature->GetObjectGuid();
                break;
            case NPC_FIRESWORN:
            case NPC_LAVA_SURGER:
                if (m_auiEncounter[TYPE_GARR] == DONE)
                    pCreature->AddObjectToRemoveList();
                break;
            case NPC_LAVA_SPAWN:
                // prevent exponential lava spawn creation in case of evade bug
                std::list<Creature*> LavaSpawnList;
                GetCreatureListWithEntryInGrid(LavaSpawnList, pCreature, NPC_LAVA_SPAWN, 100.0f);
                if (LavaSpawnList.size() > MAX_LAVA_SPAWNS)
                    pCreature->ForcedDespawn();
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_SULFURON:
            case TYPE_GEDDON:
            case TYPE_SHAZZRAH:
            case TYPE_GOLEMAGG:
            case TYPE_GARR:
            case TYPE_MAGMADAR:
            case TYPE_GEHENNAS:
            case TYPE_LUCIFRON:
                m_auiEncounter[uiType] = uiData;
                break;
            case TYPE_MAJORDOMO:
                m_auiEncounter[TYPE_MAJORDOMO] = uiData;
                if (uiData == DONE)
                    DoRespawnGameObject(m_uiFirelordCacheGUID, HOUR);
                break;
            case TYPE_RAGNAROS:
                m_auiEncounter[9] = uiData;
                break;
            case TypeRuneActive0:
                RuneActive[0] = uiData;
                break;
            case TypeRuneActive1:
                RuneActive[1] = uiData;
                break;
            case TypeRuneActive2:
                RuneActive[2] = uiData;
                break;
            case TypeRuneActive3:
                RuneActive[3] = uiData;
                break;
            case TypeRuneActive4:
                RuneActive[4] = uiData;
                break;
            case TypeRuneActive5:
                RuneActive[5] = uiData;
                break;
            case TypeRuneActive6:
                RuneActive[6] = uiData;
                break;
            case TypeDomoSpawn:
                DomoSpawn = uiData;
                break;
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;
            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    char const* Save() override
    {
        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                   << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5] << " "
                   << m_auiEncounter[6] << " " << m_auiEncounter[7] << " " << m_auiEncounter[8] << " "
                   << m_auiEncounter[9] << " " << RuneActive[0] << " " << RuneActive[1] << " "
                   << RuneActive[2] << " " << RuneActive[3] << " " << RuneActive[4] << " "
                   << RuneActive[5] << " " << RuneActive[6];

        // TODO: Fuite de memoire. Mais empeche un crash.
        std::string* strInstData = new std::string(saveStream.str());
        return strInstData->c_str();
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_SULFURON:
            case TYPE_GEDDON:
            case TYPE_SHAZZRAH:
            case TYPE_GOLEMAGG:
            case TYPE_GARR:
            case TYPE_MAGMADAR:
            case TYPE_GEHENNAS:
            case TYPE_LUCIFRON:
            case TYPE_MAJORDOMO:
            case TYPE_RAGNAROS:
                return m_auiEncounter[uiType];
            case TypeRuneActive0:
                return RuneActive[0];
            case TypeRuneActive1:
                return RuneActive[1];
            case TypeRuneActive2:
                return RuneActive[2];
            case TypeRuneActive3:
                return RuneActive[3];
            case TypeRuneActive4:
                return RuneActive[4];
            case TypeRuneActive5:
                return RuneActive[5];
            case TypeRuneActive6:
                return RuneActive[6];
            case TypeDomoSpawn:
                return DomoSpawn;
        }
        return 0;
    }

    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case DATA_SULFURON:
                return m_uiSulfuronGUID;
            case DATA_GOLEMAGG:
                return m_uiGolemaggGUID;
            case DATA_GARR:
                return m_uiGarrGUID;
            case DATA_MAJORDOMO:
                return m_uiMajorDomoGUID;
        }

        return 0;
    }

    void Update(uint32 uiDiff) override
    {
        if (RemoveTimer < uiDiff)
        {
            instance->RemoveAllObjectsInRemoveList();
            RemoveTimer = 5000;
        }
        else RemoveTimer -= uiDiff;

        Map::PlayerList const &liste = instance->GetPlayers();
        if (liste.getFirst() != nullptr)
        {
            for (uint64 & i : GOUseGuidList)
            {
                if (i)
                {
                    GameObject* Rune = instance->GetGameObject(i);
                    switch (Rune->GetEntry())
                    {
                        case 176951:                                    //Sulfuron
                            if (GameObject* Feu = Rune->FindNearestGameObject(178187, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176952:                                    //Geddon
                            if (GameObject* Feu = Rune->FindNearestGameObject(178188, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176953:                                    //Shazzrah
                            if (GameObject* Feu = Rune->FindNearestGameObject(178189, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176954:                                    //Golemagg
                            if (GameObject* Feu = Rune->FindNearestGameObject(178190, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176955:                                    //Garr
                            if (GameObject* Feu = Rune->FindNearestGameObject(178191, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176956:                                    //Magmadar
                            if (GameObject* Feu = Rune->FindNearestGameObject(178192, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                        case 176957:                                    //Gehennas
                            if (GameObject* Feu = Rune->FindNearestGameObject(178193, 20.0f))
                            {
                                Feu->Delete();
                                Rune->Use(liste.getFirst()->getSource());
                                i = 0;
                            }
                            break;
                    }
                }
            }
        }
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

        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
                   >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6]
                   >> m_auiEncounter[7] >> m_auiEncounter[8] >> m_auiEncounter[9]
                   >> RuneActive[0] >> RuneActive[1] >> RuneActive[2] >> RuneActive[3]
                   >> RuneActive[4] >> RuneActive[5] >> RuneActive[6];

        for (uint32 & i : m_auiEncounter)
            if (i == IN_PROGRESS)           // Do not load an encounter as "In Progress" - reset it instead.
                i = NOT_STARTED;

        for (int i = 0; i < INSTANCE_MC_MAX_ENCOUNTER; i++)
            SetData(i, m_auiEncounter[i]);

        /*
        uint64 GuidRunes[7] =
        {
            m_uiRuneKoroGUID,
            m_uiRuneZethGUID,
            m_uiRuneMazjGUID,
            m_uiRuneTheriGUID,
            m_uiRuneBlazGUID,
            m_uiRuneKressGUID,
            m_uiRuneMohnGUID
        };
        */

        for (uint64 i : RuneActive)
            SetData((TypeRuneActive0 + 16), i);
    }
};

bool GOHello_go_rune_MC(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        switch (pGo->GetEntry())
        {
            case 176951:                                    //Sulfuron
                if (pInstance->GetData(TYPE_SULFURON) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive0) != DONE)
                        pInstance->SetData(TypeRuneActive0, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178187, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176952:                                    //Geddon
                if (pInstance->GetData(TYPE_GEDDON) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive1) != DONE)
                        pInstance->SetData(TypeRuneActive1, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178188, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176953:                                    //Shazzrah
                if (pInstance->GetData(TYPE_SHAZZRAH) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive2) != DONE)
                        pInstance->SetData(TypeRuneActive2, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178189, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176954:                                    //Golemagg
                if (pInstance->GetData(TYPE_GOLEMAGG) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive3) != DONE)
                        pInstance->SetData(TypeRuneActive3, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178190, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176955:                                    //Garr
                if (pInstance->GetData(TYPE_GARR) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive4) != DONE)
                        pInstance->SetData(TypeRuneActive4, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178191, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176956:                                    //Magmadar
                if (pInstance->GetData(TYPE_MAGMADAR) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive5) != DONE)
                        pInstance->SetData(TypeRuneActive5, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178192, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
            case 176957:                                    //Gehennas
                if (pInstance->GetData(TYPE_GEHENNAS) == DONE)
                {
                    if (pInstance->GetData(TypeRuneActive6) != DONE)
                        pInstance->SetData(TypeRuneActive6, DONE);
                    if (GameObject* Rune = pGo->FindNearestGameObject(178193, 20.0f))
                        Rune->Delete();
                }
                else
                    return true;
                break;
        }

        if (pInstance->GetData(TypeRuneActive0) == DONE &&
                pInstance->GetData(TypeRuneActive1) == DONE &&
                pInstance->GetData(TypeRuneActive2) == DONE &&
                pInstance->GetData(TypeRuneActive3) == DONE &&
                pInstance->GetData(TypeRuneActive4) == DONE &&
                pInstance->GetData(TypeRuneActive5) == DONE &&
                pInstance->GetData(TypeRuneActive6) == DONE &&
                pInstance->GetData(TypeDomoSpawn) != DONE &&
                pInstance->GetData(TYPE_RAGNAROS) != DONE)
        {
            pInstance->SetData(TypeDomoSpawn, DONE);
            if (Creature* Domo = pPlayer->SummonCreature(NPC_DOMO, 758.089f, -1176.71f, -118.640f, 3.12414f, TEMPSUMMON_MANUAL_DESPAWN, 2 * HOUR * IN_MILLISECONDS))
                DoScriptText(-1409004, Domo);
        }
    }

    return false;
}

InstanceData* GetInstance_instance_molten_core(Map* pMap)
{
    return new instance_molten_core(pMap);
}

void AddSC_instance_molten_core()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_molten_core";
    newscript->GetInstanceData = &GetInstance_instance_molten_core;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_rune_MC";
    newscript->pGOHello = &GOHello_go_rune_MC;
    newscript->RegisterSelf();
}

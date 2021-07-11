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
SDName: Instance_ZulGurub
SD%Complete: 80
SDComment: Missing reset function after killing a boss for Ohgan, Thekal.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

#define ZG_LOG sLog.outDebug
//#define ZG_LOG sLog.outError(

#define BOSS_GRILEK                     15082
#define BOSS_HAZZARAH                   15083
#define BOSS_RENATAKI                   15084
#define BOSS_WUSHOOLAY                  15085


void instance_zulgurub::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

    m_uiLorKhanGUID   = 0;
    m_uiZathGUID      = 0;
    m_uiThekalGUID    = 0;
    m_uiJindoGUID     = 0;
    m_uiHakkarGUID    = 0;
    m_uiMarliGUID     = 0;
    m_uiGahzrankaGUID = 0;
}

void instance_zulgurub::UpdateHakkarPowerStacks()
{
    if (Creature* pHakkar = instance->GetCreature(m_uiHakkarGUID))
    {
        if (pHakkar->IsAlive())
        {
            uint32 neededStacks = 0;
            for (uint8 i = 0; i < 5; ++i)
            {
                if (m_auiEncounter[i] != DONE)
                    neededStacks++;
            }

            uint32 currentStacks = 0;
            if (SpellAuraHolder* pAura = pHakkar->GetSpellAuraHolder(SPELL_HAKKAR_POWER))
                currentStacks = pAura->GetStackAmount();

            if (neededStacks == currentStacks)
                return;

            if (neededStacks == 0)
            {
                pHakkar->RemoveAurasDueToSpell(SPELL_HAKKAR_POWER);
                return;
            }

            if (currentStacks == 0)
            {
                for (uint8 i = 0; i < neededStacks; ++i)
                    pHakkar->CastSpell(pHakkar, SPELL_HAKKAR_POWER, true);
            }
            else
            {
                if (SpellAuraHolder* pAura = pHakkar->GetSpellAuraHolder(SPELL_HAKKAR_POWER))
                    pAura->SetStackAmount(neededStacks);
            }
        }
    }
}

bool instance_zulgurub::IsEncounterInProgress() const
{
    for (uint32 i : m_auiEncounter)
        if (i == IN_PROGRESS || i == SPECIAL)
            return true;
    return false;
}

void instance_zulgurub::OnCreatureCreate(Creature* pCreature)
{
    uint64 nullGuid = 0;
    switch (pCreature->GetEntry())
    {
        case NPC_LORKHAN:
            HandleLoadCreature(TYPE_LORKHAN, m_uiLorKhanGUID, pCreature);
            break;
        case NPC_ZATH:
            m_uiZathGUID = pCreature->GetGUID();
            break;
        case NPC_THEKAL:
            HandleLoadCreature(TYPE_THEKAL, m_uiThekalGUID, pCreature);
            UpdateHakkarPowerStacks();
            break;
        case NPC_JINDO:
            m_uiJindoGUID = pCreature->GetGUID();
            break;
        case NPC_HAKKAR:
            HandleLoadCreature(TYPE_HAKKAR, m_uiHakkarGUID, pCreature);
            UpdateHakkarPowerStacks();
            break;
        case NPC_VENOXIS:
            HandleLoadCreature(TYPE_VENOXIS, nullGuid, pCreature);
            UpdateHakkarPowerStacks();
            break;
        case NPC_ARLOKK:
            HandleLoadCreature(TYPE_ARLOKK, nullGuid, pCreature);
            UpdateHakkarPowerStacks();
            break;
        case NPC_MARLI:
            HandleLoadCreature(TYPE_MARLI, nullGuid, pCreature);
            m_uiMarliGUID = pCreature->GetGUID();
            UpdateHakkarPowerStacks();
            break;
        case NPC_JEKLIK:
            UpdateHakkarPowerStacks();
            break;
        case NPC_RAZZASHI_SKITTERER:
        case NPC_RAZZASHI_VENOMBROOD:
        case NPC_HAKARI_SHADOWCASTER:
        case NPC_RAZZASHI_BROODWIDOW:
            m_lMarliTrashGUIDList.push_back(pCreature->GetGUID());
            break;
        case NPC_GAHZRANKA:
            m_uiGahzrankaGUID = pCreature->GetGUID();
            break;
    }
}

void instance_zulgurub::HandleLoadCreature(uint32 dataType, uint64 &storeGuid, Creature* pCrea)
{
    if (GetData(dataType) == DONE)
    {
        storeGuid = 0;
        pCrea->AddObjectToRemoveList();
        return;
    }
    storeGuid = pCrea->GetGUID();
}

void instance_zulgurub::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
        case TYPE_HAKKAR_POWER:
            UpdateHakkarPowerStacks();
            break;
        case TYPE_ARLOKK:
            m_auiEncounter[0] = uiData;
            break;
        case TYPE_JEKLIK:
            m_auiEncounter[1] = uiData;
            break;
        case TYPE_VENOXIS:
            m_auiEncounter[2] = uiData;
            break;
        case TYPE_MARLI:
            m_auiEncounter[3] = uiData;
            if (uiData == IN_PROGRESS)
            {
                Creature *Marli = instance->GetCreature(m_uiMarliGUID);
                Unit* pVictim = Marli->GetVictim();
                for (const auto& guid : m_lMarliTrashGUIDList)
                {
                    if (Creature* MarliTrash = instance->GetCreature(guid))
                        if (MarliTrash->IsAlive() && !MarliTrash->IsInCombat())
                            if (MarliTrash->GetMapId() == 309 && MarliTrash->GetZoneId() == 1977 && MarliTrash->GetAreaId() == 3379)
                                MarliTrash->AI()->AttackStart(pVictim);
                }
            }
            break;
        case TYPE_THEKAL:
            m_auiEncounter[4] = uiData;
            break;
        case TYPE_LORKHAN:
            m_auiEncounter[5] = uiData;
            break;
        case TYPE_ZATH:
            m_auiEncounter[6] = uiData;
            break;
        case TYPE_OHGAN:
            m_auiEncounter[7] = uiData;
            break;
        case TYPE_HAKKAR:
            m_auiEncounter[8] = uiData;
            break;
        case TYPE_RANDOM_BOSS:
            if (uiData == 0)
//                m_auiEncounter[9] = GenerateRandomBoss();
            {
                if (sGameEventMgr.IsActiveEvent(29))
                    m_auiEncounter[9] = BOSS_GRILEK;
                else if (sGameEventMgr.IsActiveEvent(30))
                    m_auiEncounter[9] = BOSS_HAZZARAH;
                else if (sGameEventMgr.IsActiveEvent(31))
                    m_auiEncounter[9] = BOSS_RENATAKI;
                else if (sGameEventMgr.IsActiveEvent(32))
                    m_auiEncounter[9] = BOSS_WUSHOOLAY;
            }
            else
                m_auiEncounter[9] = uiData;
            break;
        case TYPE_JINDO:
            m_auiEncounter[10] = uiData;
            break;
        case TYPE_GAHZRANKA:
            m_auiEncounter[11] = uiData;
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;
        strInstData = GenSaveData(m_auiEncounter, 11);
        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

char const* instance_zulgurub::Save()
{
    return strInstData.c_str();
}

void instance_zulgurub::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    LoadSaveData(chrIn, m_auiEncounter, 11);

    for (uint32 & i : m_auiEncounter)
    {
        if (i == IN_PROGRESS)
            i = NOT_STARTED;
    }
    if (!m_randomBossSpawned)
        SpawnRandomBoss();

    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_zulgurub::GetData(uint32 uiType)
{
    switch (uiType)
    {
        case TYPE_ARLOKK:
            return m_auiEncounter[0];
        case TYPE_JEKLIK:
            return m_auiEncounter[1];
        case TYPE_VENOXIS:
            return m_auiEncounter[2];
        case TYPE_MARLI:
            return m_auiEncounter[3];
        case TYPE_THEKAL:
            return m_auiEncounter[4];
        case TYPE_LORKHAN:
            return m_auiEncounter[5];
        case TYPE_ZATH:
            return m_auiEncounter[6];
        case TYPE_OHGAN:
            return m_auiEncounter[7];
        case TYPE_HAKKAR:
            return m_auiEncounter[8];
        case TYPE_RANDOM_BOSS:
            if (m_auiEncounter[9] >= 15080 && m_auiEncounter[9] <= 15085)
                return m_auiEncounter[9];
            return 0;
        case TYPE_JINDO:
            return m_auiEncounter[10];
        case TYPE_GAHZRANKA:
            return m_auiEncounter[11];
    }
    return 0;
}

uint64 instance_zulgurub::GetData64(uint32 uiData)
{
    switch (uiData)
    {
        case DATA_LORKHAN:
            return m_uiLorKhanGUID;
        case DATA_ZATH:
            return m_uiZathGUID;
        case DATA_THEKAL:
            return m_uiThekalGUID;
        case DATA_JINDO:
            return m_uiJindoGUID;
        case DATA_HAKKAR:
            return m_uiHakkarGUID;
        case DATA_GAHZRANKA:
            return m_uiGahzrankaGUID;
    }
    return 0;
}

void instance_zulgurub::Create()
{
    m_auiEncounter[9] = GenerateRandomBoss();
    strInstData = GenSaveData(m_auiEncounter, 11);
    SaveToDB();
    if (!m_randomBossSpawned)
        SpawnRandomBoss();
}

void instance_zulgurub::OnCreatureDeath(Creature * pCreature)
{
    ZG_LOG("OnCreatureDeath %u", pCreature->GetEntry());
    if (pCreature->GetEntry() >= 15082 && pCreature->GetEntry() <= 15085)
        SetData(TYPE_RANDOM_BOSS, DONE);

    if (pCreature->GetEntry() ==  15163)
    {
        pCreature->ForcedDespawn(3000);
        pCreature->SetRespawnTime(345600000);
    }

}

uint32 instance_zulgurub::GenerateRandomBoss()
{
    uint32 dayCount = sWorld.GetGameDay();
    uint32 weekmod = ((dayCount - (dayCount % 14)) / 14) % 3;
    uint32 bossId = 15082 + weekmod;
    randomBossEntry = bossId;
    ZG_LOG("GenerateRandomBoss %u -> %u", weekmod, bossId);
    return bossId;
}

void instance_zulgurub::SpawnRandomBoss()
{
    m_randomBossSpawned = true;
    return; // function deactivated
    if (m_auiEncounter[9] < 15082 || m_auiEncounter[9] > 15085)
        return;
    Creature* pCrea = instance->SummonCreature(m_auiEncounter[9], -11901.45f, -1906.337f, 65.37f, TEMPSUMMON_DEAD_DESPAWN);
    if (!pCrea)
        return;
    pCrea->SetOrientation(M_PI_F / 4.0f);
    pCrea->GetMotionMaster()->MoveIdle();
    pCrea->CastSpell(pCrea, 25039, true); // Visuel de fantome vert
    m_randomBossSpawned = true;
}

Unit* instance_zulgurub::Thekal_GetUnitThatCanRez()
{
    if (Unit *pLorKhan = instance->GetUnit(GetData64(DATA_LORKHAN)))
        if (pLorKhan->IsAlive())
            return pLorKhan;
    if (Unit *pZath = instance->GetUnit(GetData64(DATA_ZATH)))
        if (pZath->IsAlive())
            return pZath;
    if (Unit *pThekal = instance->GetUnit(GetData64(DATA_THEKAL)))
        if (pThekal->IsAlive())
            return pThekal;
    return nullptr;
}

InstanceData* GetInstanceData_instance_zulgurub(Map* pMap)
{
    return new instance_zulgurub(pMap);
}

struct npc_brazierAI: public ScriptedAI
{
    npc_brazierAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Timer;
    uint32 Var;

    void Reset() override
    {
        Timer = 0;
        Var = 0;
    }

    void UseGo(int Nombre)
    {
        int var = 0;
        while (var < Nombre)
        {
            std::list<GameObject*> GOListe;
            GetGameObjectListWithEntryInGrid(GOListe, m_creature, 180252, 100.0f);
            std::list<GameObject*>::iterator itr = GOListe.begin();
            if (itr == GOListe.end())
                return;

            std::advance(itr, rand() % GOListe.size());
            if (GameObject* GO = *itr)
            {
                GO->Use(m_creature);
                GOListe.erase(itr);
                var++;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (Var > 24)
            m_creature->ForcedDespawn();

        if (Timer < uiDiff)
        {
            if (Var > 3)
                UseGo(4);
            else if (Var < 10)
                UseGo(12);
            else
                UseGo(6);
            Timer = 1000;
            Var++;
            return;
        }
        else Timer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_brazier(Creature* pCreature)
{
    return new npc_brazierAI(pCreature);
}

enum
{
    TABLET_GRILEK1 = 180358,
    TABLET_HAZZARAH1 = 180364,
    TABLET_RENATAKI1 = 180365,
    TABLET_WUSHOOLAY1 = 180393,
    TABLET_GRILEK2 = 987654,
    TABLET_HAZZARAH2 = 987655,
    TABLET_RENATAKI2 = 987656,
    TABLET_WUSHOOLAY2 = 987657,
    TABLET_ALCHEMIST_SPELL = 24266,
};


bool OnGossipHello_go_table_madness(Player* pPlayer, GameObject* pGo)
{
    //Check if the player has the alchemist skill at 300 and if he doesn't know yet Mojo Madness recipe
    if(pPlayer->HasSkill(171) && !pPlayer->HasSpell(24266))
        if(pPlayer->GetSkillValue(171) >= 300)    
            pPlayer->LearnSpell(TABLET_ALCHEMIST_SPELL,false);

    ScriptedInstance* m_pInstance = (ScriptedInstance*)pGo->GetInstanceData();
    if(!m_pInstance)
        return false;

    uint32 randomBoss = m_pInstance->GetData(TYPE_RANDOM_BOSS);
                if (sGameEventMgr.IsActiveEvent(29))
                    randomBoss = BOSS_GRILEK;
                else if (sGameEventMgr.IsActiveEvent(30))
                    randomBoss = BOSS_HAZZARAH;
                else if (sGameEventMgr.IsActiveEvent(31))
                    randomBoss = BOSS_RENATAKI;
                else if (sGameEventMgr.IsActiveEvent(32))
                    randomBoss = BOSS_WUSHOOLAY;


    if(randomBoss < 0 || randomBoss > 16000)
        return false;

    //DEBUG
    //char sMessage[200];
    //sprintf(sMessage, "boss ID=%d",randomBoss);
    //pPlayer->Say(sMessage,0);
    switch(pGo->GetEntry())
    {
        case TABLET_GRILEK1:
        case TABLET_GRILEK2:
            if (randomBoss == BOSS_GRILEK)
                pPlayer->SEND_GOSSIP_MENU(7669, pGo->GetGUID());
            else
                pPlayer->SEND_GOSSIP_MENU(7643, pGo->GetGUID());
            break;
    case TABLET_HAZZARAH1:
    case TABLET_HAZZARAH2:
            if (randomBoss == BOSS_HAZZARAH)
                pPlayer->SEND_GOSSIP_MENU(7675, pGo->GetGUID());
            else
                pPlayer->SEND_GOSSIP_MENU(7670, pGo->GetGUID());
            break;
    case TABLET_RENATAKI1:
    case TABLET_RENATAKI2:
            if (randomBoss == BOSS_RENATAKI)
                pPlayer->SEND_GOSSIP_MENU(7673, pGo->GetGUID());
            else
                pPlayer->SEND_GOSSIP_MENU(7672, pGo->GetGUID());
            break;
    case TABLET_WUSHOOLAY1:
    case TABLET_WUSHOOLAY2:
            if (randomBoss == BOSS_WUSHOOLAY)
                pPlayer->SEND_GOSSIP_MENU(7682, pGo->GetGUID());
            else
                pPlayer->SEND_GOSSIP_MENU(7674, pGo->GetGUID());
            break;
    }
    return true;
}

bool ProcessEventId_event_summon_gahzranka(uint32 uiEventId, Object* pSource, Object* pTarget, bool bIsStart)
{
    // No target or source, block event
    if (!pSource)
        return true;

    Player* pPlayer = pSource->ToPlayer();
    if (!pPlayer)
        return false;

    if (ScriptedInstance* m_pInstance = dynamic_cast<ScriptedInstance*>(pPlayer->GetInstanceData()))
    {
        // return if already summoned
        if (m_pInstance->GetData(TYPE_GAHZRANKA) != NOT_STARTED)
            return false;

        pPlayer->CastSpell(pPlayer, 12816, true);

        if (Creature* pCreature = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_GAHZRANKA)))
        {
            m_pInstance->SetData(TYPE_GAHZRANKA, IN_PROGRESS);
            pCreature->Respawn();
            return true;
        }
    }
    return false;
}

void AddSC_instance_zulgurub()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_zulgurub";
    newscript->GetInstanceData = &GetInstanceData_instance_zulgurub;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_table_madness";
    newscript->pGOHello = &OnGossipHello_go_table_madness;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_brazier";
    newscript->GetAI = &GetAI_npc_brazier;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "event_summon_gahzranka";
    newscript->pProcessEventId = &ProcessEventId_event_summon_gahzranka;
    newscript->RegisterSelf();
}

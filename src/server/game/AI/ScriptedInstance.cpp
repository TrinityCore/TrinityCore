/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "ScriptedInstance.h"
#include "Player.h"
#include "GameObject.h"

#define SAVE_LOAD_LOG sLog.outDebug

//Optional uiWithRestoreTime. If not defined, autoCloseTime will be used (if not 0 by default in *_template)
void ScriptedInstance::DoUseDoorOrButton(uint64 uiGuid, uint32 uiWithRestoreTime, bool bUseAlternativeState)
{
    if (!uiGuid)
        return;

    GameObject* pGo = instance->GetGameObject(uiGuid);

    if (pGo)
    {
        if (pGo->GetGoType() == GAMEOBJECT_TYPE_DOOR || pGo->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        {
            if (pGo->getLootState() == GO_READY)
                pGo->UseDoorOrButton(uiWithRestoreTime,bUseAlternativeState);
            else if (pGo->getLootState() == GO_ACTIVATED)
                pGo->ResetDoorOrButton();
        }
        else
            sLog.outError("Script call DoUseDoorOrButton, but gameobject entry %u is type %u.",pGo->GetEntry(),pGo->GetGoType());
    }
}

void ScriptedInstance::DoRespawnGameObject(uint64 uiGuid, uint32 uiTimeToDespawn)
{
    if (GameObject* pGo = instance->GetGameObject(uiGuid))
    {
        //not expect any of these should ever be handled
        if (pGo->GetGoType()==GAMEOBJECT_TYPE_FISHINGNODE || pGo->GetGoType()==GAMEOBJECT_TYPE_DOOR ||
            pGo->GetGoType()==GAMEOBJECT_TYPE_BUTTON || pGo->GetGoType()==GAMEOBJECT_TYPE_TRAP)
            return;

        if (pGo->isSpawned())
            return;

        pGo->SetRespawnTime(uiTimeToDespawn);
        pGo->Refresh();
    }
}

void ScriptedInstance::DoOpenDoor(uint64 uiGuid)
{
    if (!uiGuid)
        return;

    GameObject* pGo = instance->GetGameObject(uiGuid);

    if (pGo)
    {
        if (pGo->GetGoType() == GAMEOBJECT_TYPE_DOOR || pGo->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
        {
            if (pGo->getLootState() == GO_READY)
                pGo->UseDoorOrButton(0, false);
        }
        else
            sLog.outError("Script call DoOpenDoor, but gameobject entry %u is type %u.",pGo->GetEntry(),pGo->GetGoType());
    }
}

void ScriptedInstance::DoResetDoor(uint64 uiGuid)
{
    if (!uiGuid)
        return;

    GameObject* pGo = instance->GetGameObject(uiGuid);

    if (pGo)
    {
        if (pGo->GetGoType() == GAMEOBJECT_TYPE_DOOR || pGo->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
            pGo->ResetDoorOrButton();
        else
            sLog.outError("Script call DoResetDoor, but gameobject entry %u is type %u.",pGo->GetEntry(),pGo->GetGoType());
    }
}

void ScriptedInstance::DoUpdateWorldState(uint32 uiStateId, uint32 uiStateData)
{
    Map::PlayerList const& lPlayers = instance->GetPlayers();

    if (!lPlayers.isEmpty())
    {
        for(const auto & itr : lPlayers)
        {
            if (Player* pPlayer = itr.getSource())
                pPlayer->SendUpdateWorldState(uiStateId, uiStateData);
        }
    }
    else
        sLog.outDebug("DoUpdateWorldState attempt send data but no players in map.");
}

std::string ScriptedInstance::GenSaveData(uint32* encounters, uint32 maxIndex)
{
    bool first = true;
    std::ostringstream saveStream;
    for (uint32 i = 0; i <= maxIndex; ++i)
    {
        if (!first)
            saveStream << " ";
        first = false;
        saveStream << encounters[i];
    }
    SAVE_LOAD_LOG("Sauvegarde : `%s`", saveStream.str().c_str());
    return saveStream.str();
}

void ScriptedInstance::LoadSaveData(char const* pStr, uint32* encounters, uint32 maxIndex)
{
    SAVE_LOAD_LOG("Chargement : `%s`", pStr);
    std::istringstream loadStream(pStr);
    for (uint32 i = 0; i <= maxIndex; ++i)
    {
        loadStream >> encounters[i];
        SAVE_LOAD_LOG("* %u = %u", i, encounters[i]);
    }
}


/// Get the first found Player* (with requested properties) in the map. Can return nullptr.
Player* ScriptedInstance::GetPlayerInMap(bool bOnlyAlive /*=false*/, bool bCanBeGamemaster /*=true*/)
{
    Map::PlayerList const& lPlayers = instance->GetPlayers();

    for (const auto& itr : lPlayers)
    {
        Player* pPlayer = itr.getSource();
        if (pPlayer && (!bOnlyAlive || pPlayer->IsAlive()) && (bCanBeGamemaster || !pPlayer->IsGameMaster()))
            return pPlayer;
    }

    return nullptr;
}

/// Returns a pointer to a loaded GameObject that was stored in m_mGoEntryGuidStore. Can return nullptr
GameObject* ScriptedInstance::GetSingleGameObjectFromStorage(uint32 uiEntry)
{
    EntryGuidMap::iterator find = m_mGoEntryGuidStore.find(uiEntry);
    if (find != m_mGoEntryGuidStore.end())
        return instance->GetGameObject(find->second);

    // Output log, possible reason is not added GO to map, or not yet loaded;
    sLog.outError("Script requested gameobject with entry %u, but no gameobject of this entry was created yet, or it was not stored by script for map %u.", uiEntry, instance->GetId());

    return nullptr;
}

/// Returns a pointer to a loaded Creature that was stored in m_mGoEntryGuidStore. Can return nullptr
Creature* ScriptedInstance::GetSingleCreatureFromStorage(uint32 uiEntry, bool bSkipDebugLog /*=false*/)
{
    EntryGuidMap::iterator find = m_mNpcEntryGuidStore.find(uiEntry);
    if (find != m_mNpcEntryGuidStore.end())
        return instance->GetCreature(find->second);

    // Output log, possible reason is not added GO to map, or not yet loaded;
    if (!bSkipDebugLog)
        sLog.outError("Script requested creature with entry %u, but no npc of this entry was created yet, or it was not stored by script for map %u.", uiEntry, instance->GetId());

    return nullptr;
}

void ScriptedInstance_PTR::OnCreatureEnterCombat(Creature* creature)
{
    if (creature->IsWorldBoss())
    {
        std::map<ObjectGuid, time_t>::iterator it = boss_expirations.find(creature->GetObjectGuid());
        if (it == boss_expirations.end())
        {
            boss_expirations[creature->GetObjectGuid()] = time(nullptr);
            creature->MonsterSay("Remaining time before despawn: 30 minutes.");
        }
    }
    ScriptedInstance::OnCreatureEnterCombat(creature);
}

void ScriptedInstance_PTR::Update(uint32 diff)
{
    time_t expiration = time(nullptr) - 30*60;
    std::map<ObjectGuid, time_t>::iterator it = boss_expirations.begin();
    for (; it != boss_expirations.end(); ++it)
    {
        if (it->second < expiration)
            if (GetMap())
                if (Creature* c = GetMap()->GetCreature(it->first))
                {
                    if (!c->IsAlive())
                        c->DoKillUnit();
                    c->SaveRespawnTime();
                    c->AddObjectToRemoveList();
                }
    }
    ScriptedInstance::Update(diff);
}

/**
   Constructor for DialogueHelper
   @param   pDialogueArray The static const array of DialogueEntry holding the information about the dialogue. This array MUST be terminated by {0,0,0}
*/
DialogueHelper::DialogueHelper(SIDialogueEntry const* pDialogueArray) :
    m_pInstance(nullptr),
    m_pDialogueArray(pDialogueArray),
    m_pCurrentEntry(nullptr),
    m_pDialogueTwoSideArray(nullptr),
    m_pCurrentEntryTwoSide(nullptr),
    m_uiTimer(0),
    m_bIsFirstSide(true),
    m_bCanSimulate(false)
{}

/**
   Constructor for DialogueHelper (Two Sides)
   @param   pDialogueTwoSideArray The static const array of DialogueEntryTwoSide holding the information about the dialogue. This array MUST be terminated by {0,0,0,0,0}
*/
DialogueHelper::DialogueHelper(SIDialogueEntryTwoSide const* pDialogueTwoSideArray) :
    m_pInstance(nullptr),
    m_pDialogueArray(nullptr),
    m_pCurrentEntry(nullptr),
    m_pDialogueTwoSideArray(pDialogueTwoSideArray),
    m_pCurrentEntryTwoSide(nullptr),
    m_uiTimer(0),
    m_bIsFirstSide(true),
    m_bCanSimulate(false)
{}

/**
   Function to start a (part of a) dialogue
   @param   iTextEntry The TextEntry of the dialogue that will be started (must be always the entry of first side)
*/
void DialogueHelper::StartNextDialogueText(int32 iTextEntry)
{
    // Find iTextEntry
    bool bFound = false;

    if (m_pDialogueArray)                                   // One Side
    {
        for (SIDialogueEntry const* pEntry = m_pDialogueArray; pEntry->iTextEntry; ++pEntry)
        {
            if (pEntry->iTextEntry == iTextEntry)
            {
                m_pCurrentEntry = pEntry;
                bFound = true;
                break;
            }
        }
    }
    else                                                    // Two Sides
    {
        for (SIDialogueEntryTwoSide const* pEntry = m_pDialogueTwoSideArray; pEntry->iTextEntry; ++pEntry)
        {
            if (pEntry->iTextEntry == iTextEntry)
            {
                m_pCurrentEntryTwoSide = pEntry;
                bFound = true;
                break;
            }
        }
   }

    if (!bFound)
    {
        sLog.outError("Script call DialogueHelper::StartNextDialogueText, but textEntry %i is not in provided dialogue (on map id %u)", iTextEntry, m_pInstance ? m_pInstance->instance->GetId() : 0);
        return;
    }

    DoNextDialogueStep();
}

/// Internal helper function to do the actual say of a DialogueEntry
void DialogueHelper::DoNextDialogueStep()
{
    // Last Dialogue Entry done?
    if ((m_pCurrentEntry && !m_pCurrentEntry->iTextEntry) || (m_pCurrentEntryTwoSide && !m_pCurrentEntryTwoSide->iTextEntry))
    {
        m_uiTimer = 0;
        return;
    }

    // Get Text, SpeakerEntry and Timer
    int32 iTextEntry = 0;
    uint32 uiSpeakerEntry = 0;

    if (m_pDialogueArray)                               // One Side
    {
        uiSpeakerEntry = m_pCurrentEntry->uiSayerEntry;
        iTextEntry = m_pCurrentEntry->iTextEntry;

        m_uiTimer = m_pCurrentEntry->uiTimer;
    }
    else                                                // Two Sides
    {
        // Second Entries can be 0, if they are the entry from first side will be taken
        uiSpeakerEntry = !m_bIsFirstSide && m_pCurrentEntryTwoSide->uiSayerEntryAlt ? m_pCurrentEntryTwoSide->uiSayerEntryAlt : m_pCurrentEntryTwoSide->uiSayerEntry;
        iTextEntry = !m_bIsFirstSide && m_pCurrentEntryTwoSide->iTextEntryAlt ? m_pCurrentEntryTwoSide->iTextEntryAlt : m_pCurrentEntryTwoSide->iTextEntry;

        m_uiTimer = m_pCurrentEntryTwoSide->uiTimer;
    }

    // Simulate Case
    if (uiSpeakerEntry && iTextEntry)
    {
        // Use Speaker if directly provided
        Creature* pSpeaker = GetSpeakerByEntry(uiSpeakerEntry);
        if (m_pInstance && !pSpeaker)                       // Get Speaker from instance
        {
            if (m_bCanSimulate)                             // Simulate case
                m_pInstance->DoOrSimulateScriptTextForThisInstance(iTextEntry, uiSpeakerEntry);
            else
                pSpeaker = m_pInstance->GetSingleCreatureFromStorage(uiSpeakerEntry);
        }

        if (pSpeaker)
            DoScriptText(iTextEntry, pSpeaker);
    }

    JustDidDialogueStep(m_pDialogueArray ?  m_pCurrentEntry->iTextEntry : m_pCurrentEntryTwoSide->iTextEntry);

    // Increment position
    if (m_pDialogueArray)
        ++m_pCurrentEntry;
    else
        ++m_pCurrentEntryTwoSide;
}

/// Call this function within any DialogueUpdate method. This is required for saying next steps in a dialogue
void DialogueHelper::DialogueUpdate(uint32 uiDiff)
{
    if (m_uiTimer)
    {
        if (m_uiTimer <= uiDiff)
            DoNextDialogueStep();
        else
            m_uiTimer -= uiDiff;
    }
}

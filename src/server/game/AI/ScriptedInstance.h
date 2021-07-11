/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_INSTANCE_H
#define SC_INSTANCE_H

#include "InstanceData.h"
#include "Map.h"
#include "ScriptMgr.h"

class GameObject;
class Creature;

enum EncounterState
{
    NOT_STARTED   = 0,
    IN_PROGRESS   = 1,
    FAIL          = 2,
    DONE          = 3,
    SPECIAL       = 4
};

#define OUT_SAVE_INST_DATA             sLog.outDebug("Saving Instance Data for Instance %s (Map %d, Instance Id %d)", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_SAVE_INST_DATA_COMPLETE    sLog.outDebug("Saving Instance Data for Instance %s (Map %d, Instance Id %d) completed.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA(a)          sLog.outDebug("Loading Instance Data for Instance %s (Map %d, Instance Id %d). Input is '%s'", instance->GetMapName(), instance->GetId(), instance->GetInstanceId(), a)
#define OUT_LOAD_INST_DATA_COMPLETE    sLog.outDebug("Instance Data Load for Instance %s (Map %d, Instance Id: %d) is complete.",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA_FAIL        sLog.outError("Unable to load Instance Data for Instance %s (Map %d, Instance Id: %d).",instance->GetMapName(), instance->GetId(), instance->GetInstanceId())

class ScriptedInstance : public InstanceData
{
    public:

        explicit ScriptedInstance(Map* pMap) : InstanceData(pMap) {}
        ~ScriptedInstance() override {}

        // Default accessor functions
        GameObject* GetSingleGameObjectFromStorage(uint32 uiEntry);
        Creature* GetSingleCreatureFromStorage(uint32 uiEntry, bool bSkipDebugLog = false);

        //change active state of doors or buttons
        void DoUseDoorOrButton(uint64 uiGuid, uint32 uiWithRestoreTime = 0, bool bUseAlternativeState = false);
        void DoOpenDoor(uint64 guid);
        void DoResetDoor(uint64 guid);

        //Respawns a GO having negative spawntimesecs in gameobject-table
        void DoRespawnGameObject(uint64 uiGuid, uint32 uiTimeToDespawn = MINUTE);

        //sends world state update to all players in instance
        void DoUpdateWorldState(uint32 uiStateId, uint32 uiStateData);
        std::string GenSaveData(uint32* encounters, uint32 maxIndex);
        void LoadSaveData(char const* pStr, uint32* encounters, uint32 maxIndex);

        // Get a Player from map
        Player* GetPlayerInMap(bool bOnlyAlive = false, bool bCanBeGamemaster = true);

        /// Wrapper for simulating map-wide text in this instance. It is expected that the Creature is stored in m_mNpcEntryGuidStore if loaded.
        void DoOrSimulateScriptTextForThisInstance(int32 iTextEntry, uint32 uiCreatureEntry)
        {
          // Prevent debug output in GetSingleCreatureFromStorage
          DoOrSimulateScriptTextForMap(iTextEntry, uiCreatureEntry, instance, GetSingleCreatureFromStorage(uiCreatureEntry, true));
        }

    protected:
        // Storage for GO-Guids and NPC-Guids
        typedef std::map<uint32, ObjectGuid> EntryGuidMap;
        EntryGuidMap m_mGoEntryGuidStore;                   ///< Store unique GO-Guids by entry
        EntryGuidMap m_mNpcEntryGuidStore;                  ///< Store unique NPC-Guids by entry
};

class ScriptedInstance_PTR : public ScriptedInstance
{
public:
    explicit ScriptedInstance_PTR(Map* pMap) : ScriptedInstance(pMap) {}
    void OnCreatureEnterCombat(Creature* creature) override;
    void Update(uint32 diff) override;
protected:
    std::map<ObjectGuid, time_t> boss_expirations; // For PTR testes
};


/// A static const array of this structure must be handled to DialogueHelper
struct SIDialogueEntry
{
    int32 iTextEntry;                                       ///< To be said text entry
    uint32 uiSayerEntry;                                    ///< Entry of the mob who should say
    uint32 uiTimer;                                         ///< Time delay until next text of array is said (0 stops)
};

/// A static const array of this structure must be handled to DialogueHelper
struct SIDialogueEntryTwoSide
{
    int32 iTextEntry;                                       ///< To be said text entry (first side)
    uint32 uiSayerEntry;                                    ///< Entry of the mob who should say (first side)
    int32 iTextEntryAlt;                                    ///< To be said text entry (second side)
    uint32 uiSayerEntryAlt;                                 ///< Entry of the mob who should say (second side)
    uint32 uiTimer;                                         ///< Time delay until next text of array is said (0 stops)
};

/// Helper class handling a dialogue given as static const array of DialogueEntry or DialogueEntryTwoSide
class DialogueHelper
{
public:
    // The array MUST be terminated by {0,0,0}
    DialogueHelper(SIDialogueEntry const* pDialogueArray);
    // The array MUST be terminated by {0,0,0,0,0}
    DialogueHelper(SIDialogueEntryTwoSide const* aDialogueTwoSide);

    /// Function to initialize the dialogue helper for instances. If not used with instances, GetSpeakerByEntry MUST be overwritten to obtain the speakers
    void InitializeDialogueHelper(ScriptedInstance* pInstance, bool bCanSimulateText = false) { m_pInstance = pInstance; m_bCanSimulate = bCanSimulateText; }
    /// Set if take first entries or second entries
    void SetDialogueSide(bool bIsFirstSide) { m_bIsFirstSide = bIsFirstSide; }

    void StartNextDialogueText(int32 iTextEntry);

    void DialogueUpdate(uint32 uiDiff);

protected:
    /// Will be called when a dialogue step was done
    virtual void JustDidDialogueStep(int32 /*iEntry*/) {}
    /// Will be called to get a speaker, MUST be implemented if not used in instances
    virtual Creature* GetSpeakerByEntry(uint32 /*uiEntry*/) { return nullptr; }

    ScriptedInstance* m_pInstance;

private:
    void DoNextDialogueStep();


    SIDialogueEntry const* m_pDialogueArray;
    SIDialogueEntry const* m_pCurrentEntry;
    SIDialogueEntryTwoSide const* m_pDialogueTwoSideArray;
    SIDialogueEntryTwoSide const* m_pCurrentEntryTwoSide;

    uint32 m_uiTimer;
    bool m_bIsFirstSide;
    bool m_bCanSimulate;
};

#endif

/* Copyright (C) 2006 - 2008 TrinityScript <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"
#include "Config/Config.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "../system/ScriptLoader.h"
#include "../system/system.h"

#define _FULLVERSION "TrinityScript"

#ifndef _TRINITY_SCRIPT_CONFIG
# define _TRINITY_SCRIPT_CONFIG  "trinitycore.conf"
#endif _TRINITY_SCRIPT_CONFIG

int num_sc_scripts;
Script *m_scripts[MAX_SCRIPTS];

Config TScriptConfig;

void FillSpellSummary();
void LoadOverridenSQLData();
void LoadOverridenDBCData();

void LoadDatabase()
{
    //Get db string from file
    std::string dbstring = TScriptConfig.GetStringDefault("WorldDatabaseInfo", "");

    if (dbstring.empty())
    {
        error_log("TSCR: Missing world database info from configuration file. Load database aborted.");
        return;
    }

    //Initialize connection to DB
    if (!dbstring.empty() && TScriptDB.Initialize(dbstring.c_str()))
    {
        outstring_log("TSCR: TrinityScript database initialized successfully.");
        outstring_log("");

        pSystemMgr.LoadVersion();
        pSystemMgr.LoadScriptTexts();
        pSystemMgr.LoadScriptTextsCustom();
        pSystemMgr.LoadScriptWaypoints();
    }
    else
    {
        error_log("TSCR: Unable to connect to database at %s. Load database aborted.", dbstring.c_str());
        return;
    }

    TScriptDB.HaltDelayThread();

}

struct TSpellSummary {
    uint8 Targets;                                          // set of enum SelectTarget
    uint8 Effects;                                          // set of enum SelectEffect
}extern *SpellSummary;

TRINITY_DLL_EXPORT
void ScriptsFree()
{
    // Free Spell Summary
    delete []SpellSummary;

    // Free resources before library unload
    for(uint16 i =0;i<MAX_SCRIPTS;++i)
        delete m_scripts[i];

    num_sc_scripts = 0;
}

TRINITY_DLL_EXPORT
void ScriptsInit(char const* cfg_file = "trinitycore.conf")
{
    //Trinity Script startup
    outstring_log(" _____     _       _ _         ____            _       _");
    outstring_log("|_   _| __(_)_ __ (_) |_ _   _/ ___|  ___ _ __(_)_ __ | |_ ");
    outstring_log("  | || '__| | '_ \\| | __| | | \\___ \\ / __| \'__| | \'_ \\| __|");
    outstring_log("  | || |  | | | | | | |_| |_| |___) | (__| |  | | |_) | |_ ");
    outstring_log("  |_||_|  |_|_| |_|_|\\__|\\__, |____/ \\___|_|  |_| .__/ \\__|");
    outstring_log("                         |___/                  |_|        ");
    outstring_log("Trinity Script initializing %s", _FULLVERSION);
    outstring_log("");

    //Get configuration file
    if (!TScriptConfig.SetSource(cfg_file))
        error_log("TSCR: Unable to open configuration file. Database will be unaccessible. Configuration values will use default.");
    else
        outstring_log("TSCR: Using configuration file %s",cfg_file);

    outstring_log("");

    //Load database (must be called after SD2Config.SetSource).
    LoadDatabase();

    outstring_log("TSCR: Loading C++ scripts");
    barGoLink bar(1);
    bar.step();
    outstring_log("");

    for(uint16 i =0;i<MAX_SCRIPTS;++i)
        m_scripts[i]=NULL;

    FillSpellSummary();

    AddScripts();

    outstring_log(">> Loaded %i C++ Scripts.", num_sc_scripts);

    outstring_log(">> Load Overriden SQL Data.");
    LoadOverridenSQLData();
    outstring_log(">> Load Overriden DBC Data.");
    LoadOverridenDBCData();
}

//*********************************
//*** Functions used globally ***

void DoScriptText(int32 iTextEntry, WorldObject* pSource, Unit* pTarget)
{
    if (!pSource)
    {
        error_log("TSCR: DoScriptText entry %i, invalid Source pointer.", iTextEntry);
        return;
    }

    if (iTextEntry >= 0)
    {
        error_log("TSCR: DoScriptText with source entry %u (TypeId=%u, guid=%u) attempts to process text entry %i, but text entry must be negative.", pSource->GetEntry(), pSource->GetTypeId(), pSource->GetGUIDLow(), iTextEntry);
        return;
    }

    const StringTextData* pData = pSystemMgr.GetTextData(iTextEntry);

    if (!pData)
    {
        error_log("TSCR: DoScriptText with source entry %u (TypeId=%u, guid=%u) could not find text entry %i.", pSource->GetEntry(), pSource->GetTypeId(), pSource->GetGUIDLow(), iTextEntry);
        return;
    }

    debug_log("TSCR: DoScriptText: text entry=%i, Sound=%u, Type=%u, Language=%u, Emote=%u", iTextEntry, pData->uiSoundId, pData->uiType, pData->uiLanguage, pData->uiEmote);

    if(pData->uiSoundId)
    {
        if(GetSoundEntriesStore()->LookupEntry(pData->uiSoundId))
        {
            pSource->SendPlaySound(pData->uiSoundId, false);
        }
        else
            error_log("TSCR: DoScriptText entry %i tried to process invalid sound id %u.", iTextEntry, pData->uiSoundId);
    }

    if(pData->uiEmote)
    {
        if (pSource->GetTypeId() == TYPEID_UNIT || pSource->GetTypeId() == TYPEID_PLAYER)
            ((Unit*)pSource)->HandleEmoteCommand(pData->uiEmote);
        else
            error_log("TSCR: DoScriptText entry %i tried to process emote for invalid TypeId (%u).", iTextEntry, pSource->GetTypeId());
    }

    switch(pData->uiType)
    {
        case CHAT_TYPE_SAY:
            pSource->MonsterSay(iTextEntry, pData->uiLanguage, pTarget ? pTarget->GetGUID() : 0);
            break;
        case CHAT_TYPE_YELL:
            pSource->MonsterYell(iTextEntry, pData->uiLanguage, pTarget ? pTarget->GetGUID() : 0);
            break;
        case CHAT_TYPE_TEXT_EMOTE:
            pSource->MonsterTextEmote(iTextEntry, pTarget ? pTarget->GetGUID() : 0);
            break;
        case CHAT_TYPE_BOSS_EMOTE:
            pSource->MonsterTextEmote(iTextEntry, pTarget ? pTarget->GetGUID() : 0, true);
            break;
        case CHAT_TYPE_WHISPER:
            {
                if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
                    pSource->MonsterWhisper(iTextEntry, pTarget->GetGUID());
                else
                    error_log("TSCR: DoScriptText entry %i cannot whisper without target unit (TYPEID_PLAYER).", iTextEntry);
            }break;
        case CHAT_TYPE_BOSS_WHISPER:
            {
                if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
                    pSource->MonsterWhisper(iTextEntry, pTarget->GetGUID(), true);
                else
                    error_log("TSCR: DoScriptText entry %i cannot whisper without target unit (TYPEID_PLAYER).", iTextEntry);
            }break;
        case CHAT_TYPE_ZONE_YELL:
            pSource->MonsterYellToZone(iTextEntry, pData->uiLanguage, pTarget ? pTarget->GetGUID() : 0);
            break;
    }
}

//*********************************
//*** Functions used internally ***

void Script::RegisterSelf()
{
    int id = GetScriptId(Name.c_str());
    if(id)
    {
        m_scripts[id] = this;
        ++num_sc_scripts;
    }
    else if(Name.find("example") == std::string::npos)
    {
        error_db_log("CRASH ALERT! TrinityScript: RegisterSelf, but script named %s does not have ScriptName assigned in database.",(this)->Name.c_str());
        delete this;
    }
}

//********************************
//*** Functions to be Exported ***

TRINITY_DLL_EXPORT
void OnLogin(Player *pPlayer)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnLogin) return;
    tmpscript->pOnLogin(pPlayer);
}

TRINITY_DLL_EXPORT
void OnLogout(Player *pPlayer)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnLogout) return;
    tmpscript->pOnLogout(pPlayer);
}

TRINITY_DLL_EXPORT
void OnPVPKill(Player *killer, Player *killed)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnPVPKill) return;
    tmpscript->pOnPVPKill(killer, killed);
}

TRINITY_DLL_EXPORT
char const* ScriptsVersion()
{
    return "Default Trinity scripting library";
}

TRINITY_DLL_EXPORT
bool GossipHello (Player * pPlayer, Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipHello(pPlayer, pCreature);
}

TRINITY_DLL_EXPORT
bool GossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    debug_log("TSCR: Gossip selection, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelect(pPlayer, pCreature, uiSender, uiAction);
}

TRINITY_DLL_EXPORT
bool GossipSelectWithCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* sCode)
{
    debug_log("TSCR: Gossip selection with code, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelectWithCode) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelectWithCode(pPlayer, pCreature, uiSender, uiAction, sCode);
}

TRINITY_DLL_EXPORT
bool GOSelect(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction)
{
    if(!pGO)
    return false;
    debug_log("TSCR: Gossip selection, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if(!tmpscript || !tmpscript->pGOSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOSelect(pPlayer, pGO, uiSender, uiAction);
}

TRINITY_DLL_EXPORT
bool GOSelectWithCode(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction, const char* sCode)
{
    if(!pGO)
    return false;
    debug_log("TSCR: Gossip selection, sender: %d, action: %d",uiSender, uiAction);

    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if(!tmpscript || !tmpscript->pGOSelectWithCode) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOSelectWithCode(pPlayer, pGO, uiSender ,uiAction, sCode);
}

TRINITY_DLL_EXPORT
bool QuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestAccept(pPlayer, pCreature, pQuest);
}

TRINITY_DLL_EXPORT
bool QuestSelect(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestSelect(pPlayer, pCreature, pQuest);
}

TRINITY_DLL_EXPORT
bool QuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestComplete) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestComplete(pPlayer, pCreature, pQuest);
}

TRINITY_DLL_EXPORT
bool ChooseReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest, uint32 opt)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pChooseReward) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pChooseReward(pPlayer, pCreature, pQuest, opt);
}

TRINITY_DLL_EXPORT
uint32 NPCDialogStatus(Player* pPlayer, Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pNPCDialogStatus) return 100;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pNPCDialogStatus(pPlayer, pCreature);
}

TRINITY_DLL_EXPORT
uint32 GODialogStatus(Player* pPlayer, GameObject* pGO)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGODialogStatus) return 100;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGODialogStatus(pPlayer, pGO);
}

TRINITY_DLL_EXPORT
bool ItemHello(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemHello(pPlayer, pItem, pQuest);
}

TRINITY_DLL_EXPORT
bool ItemQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemQuestAccept(pPlayer, pItem, pQuest);
}

TRINITY_DLL_EXPORT
bool GOHello(Player* pPlayer, GameObject* pGO)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOHello(pPlayer, pGO);
}

TRINITY_DLL_EXPORT
bool GOQuestAccept(Player* pPlayer, GameObject* pGO, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOQuestAccept(pPlayer, pGO, pQuest);
}

TRINITY_DLL_EXPORT
bool GOChooseReward(Player* pPlayer, GameObject* pGO, Quest const* pQuest, uint32 opt)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOChooseReward) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOChooseReward(pPlayer, pGO, pQuest, opt);
}

TRINITY_DLL_EXPORT
bool AreaTrigger(Player* pPlayer, AreaTriggerEntry * atEntry)
{
    Script *tmpscript = m_scripts[GetAreaTriggerScriptId(atEntry->id)];
    if (!tmpscript || !tmpscript->pAreaTrigger) return false;

    return tmpscript->pAreaTrigger(pPlayer, atEntry);
}

TRINITY_DLL_EXPORT
CreatureAI* GetAI(Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->GetAI) return NULL;

    return tmpscript->GetAI(pCreature);
}

TRINITY_DLL_EXPORT
bool ItemUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemUse) return false;

    return tmpscript->pItemUse(pPlayer, pItem, targets);
}

TRINITY_DLL_EXPORT
bool ItemExpire(Player* pPlayer, ItemPrototype const * pItemProto)
{
    Script *tmpscript = m_scripts[pItemProto->ScriptId];
    if (!tmpscript || !tmpscript->pItemExpire) return true;

    return tmpscript->pItemExpire(pPlayer, pItemProto);
}

TRINITY_DLL_EXPORT
bool EffectDummyCreature(Unit *caster, uint32 spellId, uint32 effIndex, Creature *crTarget)
{
    Script *tmpscript = m_scripts[crTarget->GetScriptId()];

    if (!tmpscript || !tmpscript->pEffectDummyCreature) return false;

    return tmpscript->pEffectDummyCreature(caster, spellId, effIndex, crTarget);
}

TRINITY_DLL_EXPORT
bool EffectDummyGameObj(Unit *caster, uint32 spellId, uint32 effIndex, GameObject *gameObjTarget)
{
    Script *tmpscript = m_scripts[gameObjTarget->GetGOInfo()->ScriptId];

    if (!tmpscript || !tmpscript->pEffectDummyGameObj) return false;

    return tmpscript->pEffectDummyGameObj(caster, spellId, effIndex, gameObjTarget);
}

TRINITY_DLL_EXPORT
bool EffectDummyItem(Unit *caster, uint32 spellId, uint32 effIndex, Item *itemTarget)
{
    Script *tmpscript = m_scripts[itemTarget->GetProto()->ScriptId];

    if (!tmpscript || !tmpscript->pEffectDummyItem) return false;

    return tmpscript->pEffectDummyItem(caster, spellId, effIndex, itemTarget);
}

TRINITY_DLL_EXPORT
InstanceData* CreateInstanceData(Map *map)
{
    if (!map->IsDungeon()) return NULL;

    Script *tmpscript = m_scripts[((InstanceMap*)map)->GetScriptId()];
    if (!tmpscript || !tmpscript->GetInstanceData) return NULL;

    return tmpscript->GetInstanceData(map);
}


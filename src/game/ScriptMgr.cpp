/* Copyright (C) 2006 - 2008 TrinityScript <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "ScriptedPch.h"
#include "Config/Config.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "ScriptLoader.h"
#include "ScriptSystem.h"
#include "Policies/SingletonImp.h"

#define _FULLVERSION "TrinityScript"

INSTANTIATE_SINGLETON_1(ScriptMgr);

int num_sc_scripts;
Script *m_scripts[MAX_SCRIPTS];

Config TScriptConfig;

void FillSpellSummary();
void LoadOverridenSQLData();
void LoadOverridenDBCData();

void ScriptMgr::LoadDatabase()
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

ScriptMgr::ScriptMgr()
{
    
}
ScriptMgr::~ScriptMgr()
{
    
}

void ScriptMgr::ScriptsInit(char const* cfg_file)
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

    for (uint16 i =0; i<MAX_SCRIPTS; ++i)
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

std::string ScriptMgr:: GetConfigValueStr(char const* option)
{
    //Get db string from file
    std::string dbstring = TScriptConfig.GetStringDefault(option, "");

    if (dbstring.empty())
    {
        error_log("TSCR: %s is not a valid option.", option);
        return "error";
    }
    return dbstring;
}

int32 ScriptMgr::GetConfigValueInt32(char const* option)
{
    //Get db int from file
    int32 dbint = TScriptConfig.GetIntDefault(option, 0);

    return dbint;
}

float ScriptMgr::GetConfigValueFloat(char const* option)
{
    //Get db int from file
    float dbfloat = TScriptConfig.GetFloatDefault(option, 0);

    return dbfloat;
}

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
            }
            break;
        case CHAT_TYPE_BOSS_WHISPER:
            {
                if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
                    pSource->MonsterWhisper(iTextEntry, pTarget->GetGUID(), true);
                else
                    error_log("TSCR: DoScriptText entry %i cannot whisper without target unit (TYPEID_PLAYER).", iTextEntry);
            }
            break;
        case CHAT_TYPE_ZONE_YELL:
            pSource->MonsterYellToZone(iTextEntry, pData->uiLanguage, pTarget ? pTarget->GetGUID() : 0);
            break;
    }
}

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
        //error_db_log("CRASH ALERT! TrinityScript: RegisterSelf, but script named %s does not have ScriptName assigned in database.",(this)->Name.c_str());
        delete this;
    }
}

void ScriptMgr::OnLogin(Player *pPlayer)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnLogin) return;
    tmpscript->pOnLogin(pPlayer);
}

void ScriptMgr::OnLogout(Player *pPlayer)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnLogout) return;
    tmpscript->pOnLogout(pPlayer);
}

void ScriptMgr::OnPVPKill(Player *killer, Player *killed)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnPVPKill) return;
    tmpscript->pOnPVPKill(killer, killed);
}

bool ScriptMgr::OnSpellCast (Unit *pUnitTarget, Item *pItemTarget, GameObject *pGoTarget, uint32 i, SpellEntry const *spell)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnSpellCast) return true;
    return tmpscript->pOnSpellCast(pUnitTarget,pItemTarget,pGoTarget,i,spell);
}

uint32 ScriptMgr::OnGetXP(Player *pPlayer, uint32 amount)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnGetXP) return amount;
    return tmpscript->pOnGetXP(pPlayer,amount);
}

uint32 ScriptMgr::OnGetMoney(Player *pPlayer, int32 amount)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnGetMoney) return amount;
    return tmpscript->pOnGetMoney(pPlayer,amount);
}

bool ScriptMgr::OnPlayerChat(Player *pPlayer, const char *text)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnPlayerChat) return true;
    return tmpscript->pOnPlayerChat(pPlayer,text);
}

void ScriptMgr::OnServerStartup()
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnServerStartup) return;
    tmpscript->pOnServerStartup();
}

void ScriptMgr::OnServerShutdown()
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnServerShutdown) return;
    tmpscript->pOnServerShutdown();
}

void ScriptMgr::OnAreaChange(Player *pPlayer, AreaTableEntry const *pArea)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnAreaChange) return;
    tmpscript->pOnAreaChange(pPlayer, pArea);
}

bool ScriptMgr::OnItemClick (Player *pPlayer, Item *pItem)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnItemClick) return true;
    return tmpscript->pOnItemClick(pPlayer,pItem);
}

bool ScriptMgr::OnItemOpen (Player *pPlayer, Item *pItem)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnItemOpen) return true;
    return tmpscript->pOnItemOpen(pPlayer,pItem);
}

bool ScriptMgr::OnGoClick (Player *pPlayer, GameObject *pGameObject)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnGoClick) return true;
    return tmpscript->pOnGoClick(pPlayer,pGameObject);
}

void ScriptMgr::OnCreatureKill (Player *pPlayer, Creature *pCreature)
{
    Script *tmpscript = m_scripts[GetScriptId("scripted_on_events")];
    if (!tmpscript || !tmpscript->pOnCreatureKill) return;
    tmpscript->pOnCreatureKill(pPlayer,pCreature);
}

char const* ScriptMgr::ScriptsVersion()
{
    return "Integrated Trinity Scripts";
}

bool ScriptMgr::GossipHello (Player * pPlayer, Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipHello(pPlayer, pCreature);
}

bool ScriptMgr::GossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    debug_log("TSCR: Gossip selection, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelect(pPlayer, pCreature, uiSender, uiAction);
}

bool ScriptMgr::GossipSelectWithCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* sCode)
{
    debug_log("TSCR: Gossip selection with code, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelectWithCode) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelectWithCode(pPlayer, pCreature, uiSender, uiAction, sCode);
}

bool ScriptMgr::GOSelect(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction)
{
    if(!pGO)
    return false;
    debug_log("TSCR: Gossip selection, sender: %d, action: %d", uiSender, uiAction);

    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if(!tmpscript || !tmpscript->pGOSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOSelect(pPlayer, pGO, uiSender, uiAction);
}

bool ScriptMgr::GOSelectWithCode(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction, const char* sCode)
{
    if(!pGO)
    return false;
    debug_log("TSCR: Gossip selection, sender: %d, action: %d",uiSender, uiAction);

    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if(!tmpscript || !tmpscript->pGOSelectWithCode) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOSelectWithCode(pPlayer, pGO, uiSender ,uiAction, sCode);
}

bool ScriptMgr::QuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestAccept(pPlayer, pCreature, pQuest);
}

bool ScriptMgr::QuestSelect(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestSelect) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestSelect(pPlayer, pCreature, pQuest);
}

bool ScriptMgr::QuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestComplete) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestComplete(pPlayer, pCreature, pQuest);
}

bool ScriptMgr::ChooseReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest, uint32 opt)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pChooseReward) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pChooseReward(pPlayer, pCreature, pQuest, opt);
}

uint32 ScriptMgr::NPCDialogStatus(Player* pPlayer, Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->pNPCDialogStatus) return 100;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pNPCDialogStatus(pPlayer, pCreature);
}

uint32 ScriptMgr::GODialogStatus(Player* pPlayer, GameObject* pGO)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGODialogStatus) return 100;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGODialogStatus(pPlayer, pGO);
}

bool ScriptMgr::ItemHello(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemHello(pPlayer, pItem, pQuest);
}

bool ScriptMgr::ItemQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemQuestAccept(pPlayer, pItem, pQuest);
}

bool ScriptMgr::GOHello(Player* pPlayer, GameObject* pGO)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOHello) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOHello(pPlayer, pGO);
}

bool ScriptMgr::GOQuestAccept(Player* pPlayer, GameObject* pGO, Quest const* pQuest)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOQuestAccept) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOQuestAccept(pPlayer, pGO, pQuest);
}

bool ScriptMgr::GOChooseReward(Player* pPlayer, GameObject* pGO, Quest const* pQuest, uint32 opt)
{
    Script *tmpscript = m_scripts[pGO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOChooseReward) return false;

    pPlayer->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOChooseReward(pPlayer, pGO, pQuest, opt);
}

bool ScriptMgr::AreaTrigger(Player* pPlayer, AreaTriggerEntry const* atEntry)
{
    Script *tmpscript = m_scripts[GetAreaTriggerScriptId(atEntry->id)];
    if (!tmpscript || !tmpscript->pAreaTrigger) return false;

    return tmpscript->pAreaTrigger(pPlayer, atEntry);
}

CreatureAI* ScriptMgr::GetAI(Creature* pCreature)
{
    Script *tmpscript = m_scripts[pCreature->GetScriptId()];
    if (!tmpscript || !tmpscript->GetAI) return NULL;

    return tmpscript->GetAI(pCreature);
}

bool ScriptMgr::ItemUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    Script *tmpscript = m_scripts[pItem->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemUse) return false;

    return tmpscript->pItemUse(pPlayer, pItem, targets);
}

bool ScriptMgr::ItemExpire(Player* pPlayer, ItemPrototype const * pItemProto)
{
    Script *tmpscript = m_scripts[pItemProto->ScriptId];
    if (!tmpscript || !tmpscript->pItemExpire) return true;

    return tmpscript->pItemExpire(pPlayer, pItemProto);
}

bool ScriptMgr::EffectDummyCreature(Unit *caster, uint32 spellId, uint32 effIndex, Creature *crTarget)
{
    Script *tmpscript = m_scripts[crTarget->GetScriptId()];

    if (!tmpscript || !tmpscript->pEffectDummyCreature) return false;

    return tmpscript->pEffectDummyCreature(caster, spellId, effIndex, crTarget);
}

bool ScriptMgr::EffectDummyGameObj(Unit *caster, uint32 spellId, uint32 effIndex, GameObject *gameObjTarget)
{
    Script *tmpscript = m_scripts[gameObjTarget->GetGOInfo()->ScriptId];

    if (!tmpscript || !tmpscript->pEffectDummyGameObj) return false;

    return tmpscript->pEffectDummyGameObj(caster, spellId, effIndex, gameObjTarget);
}

bool ScriptMgr::EffectDummyItem(Unit *caster, uint32 spellId, uint32 effIndex, Item *itemTarget)
{
    Script *tmpscript = m_scripts[itemTarget->GetProto()->ScriptId];

    if (!tmpscript || !tmpscript->pEffectDummyItem) return false;

    return tmpscript->pEffectDummyItem(caster, spellId, effIndex, itemTarget);
}

InstanceData* ScriptMgr::CreateInstanceData(Map *map)
{
    if (!map->IsDungeon()) return NULL;

    Script *tmpscript = m_scripts[((InstanceMap*)map)->GetScriptId()];
    if (!tmpscript || !tmpscript->GetInstanceData) return NULL;

    return tmpscript->GetInstanceData(map);
}


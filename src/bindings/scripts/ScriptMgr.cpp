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

#define _FULLVERSION "TrinityScript"

#ifndef _TRINITY_SCRIPT_CONFIG
# define _TRINITY_SCRIPT_CONFIG  "trinitycore.conf"
#endif _TRINITY_SCRIPT_CONFIG

int num_sc_scripts;
Script *m_scripts[MAX_SCRIPTS];

DatabaseType TScriptDB;
Config TScriptConfig;

// String text additional data, used in TextMap
struct StringTextData
{
    uint32 SoundId;
    uint8  Type;
    uint32 Language;
    uint32 Emote;
};

#define TEXT_SOURCE_RANGE   -1000000                        //the amount of entries each text source has available

// Text Maps
UNORDERED_MAP<int32, StringTextData> TextMap;

// Waypoint map (escorts)
UNORDERED_MAP<uint32, std::vector<PointMovement> > PointMovementMap;

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
        outstring_log("TSCR: TrinityScript database: %s",dbstring.c_str());
    else
    {
        error_log("TSCR: Unable to connect to Database. Load database aborted.");
        return;
    }

    //***Preform all DB queries here***
    QueryResult *result;

    //Get Version information
    result = TScriptDB.PQuery("SELECT script_version FROM version LIMIT 1");

    if (result)
    {
        Field *fields = result->Fetch();
        outstring_log("TSCR: Database version is: %s", fields[0].GetString());
        outstring_log("");
        delete result;

    }else
    {
        error_log("TSCR: Missing `version.script_version` information.");
        outstring_log("");
    }

    // Drop Existing Text Map, only done once and we are ready to add data from multiple sources.
    TextMap.clear();

    // Load Script Text
    outstring_log("TSCR: Loading Script Texts...");
    LoadTrinityStrings(TScriptDB,"script_texts",TEXT_SOURCE_RANGE,1+(TEXT_SOURCE_RANGE*2));

    // Gather Additional data from Script Texts
    result = TScriptDB.PQuery("SELECT entry, sound, type, language, emote FROM script_texts");

    outstring_log("TSCR: Loading Script Texts additional data...");
    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 count = 0;

        do
        {
            bar.step();
            Field* fields = result->Fetch();
            StringTextData temp;

            int32 i             = fields[0].GetInt32();
            temp.SoundId        = fields[1].GetInt32();
            temp.Type           = fields[2].GetInt32();
            temp.Language       = fields[3].GetInt32();
            temp.Emote          = fields[4].GetInt32();

            if (i >= 0)
            {
                error_db_log("TSCR: Entry %i in table `script_texts` is not a negative value.",i);
                continue;
            }

            if (i > TEXT_SOURCE_RANGE || i <= TEXT_SOURCE_RANGE*2)
            {
                error_db_log("TSCR: Entry %i in table `script_texts` is out of accepted entry range for table.",i);
                continue;
            }

            if (temp.SoundId)
            {
                if (!GetSoundEntriesStore()->LookupEntry(temp.SoundId))
                    error_db_log("TSCR: Entry %i in table `script_texts` has soundId %u but sound does not exist.",i, temp.SoundId);
            }

            if (!GetLanguageDescByID(temp.Language))
                error_db_log("TSCR: Entry %i in table `script_texts` using Language %u but Language does not exist.",i, temp.Language);

            if (temp.Type > CHAT_TYPE_ZONE_YELL)
                error_db_log("TSCR: Entry %i in table `script_texts` has Type %u but this Chat Type does not exist.",i, temp.Type);

            TextMap[i] = temp;
            ++count;
        } while (result->NextRow());

        delete result;

        outstring_log("");
        outstring_log(">> TSCR: Loaded %u additional Script Texts data.", count);
    }else
    {
        barGoLink bar(1);
        bar.step();
        outstring_log("");
        outstring_log(">> Loaded 0 additional Script Texts data. DB table `script_texts` is empty.");
    }

    // Load Custom Text
    outstring_log("TSCR: Loading Custom Texts...");
    LoadTrinityStrings(TScriptDB,"custom_texts",TEXT_SOURCE_RANGE*2,1+(TEXT_SOURCE_RANGE*3));

    // Gather Additional data from Custom Texts
    result = TScriptDB.PQuery("SELECT entry, sound, type, language, emote FROM custom_texts");

    outstring_log("TSCR: Loading Custom Texts additional data...");
    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 count = 0;

        do
        {
            bar.step();
            Field* fields = result->Fetch();
            StringTextData temp;

            int32 i             = fields[0].GetInt32();
            temp.SoundId        = fields[1].GetInt32();
            temp.Type           = fields[2].GetInt32();
            temp.Language       = fields[3].GetInt32();
            temp.Emote          = fields[4].GetInt32();

            if (i >= 0)
            {
                error_db_log("TSCR: Entry %i in table `custom_texts` is not a negative value.",i);
                continue;
            }

            if (i > TEXT_SOURCE_RANGE*2 || i <= TEXT_SOURCE_RANGE*3)
            {
                error_db_log("TSCR: Entry %i in table `custom_texts` is out of accepted entry range for table.",i);
                continue;
            }

            if (temp.SoundId)
            {
                if (!GetSoundEntriesStore()->LookupEntry(temp.SoundId))
                    error_db_log("TSCR: Entry %i in table `custom_texts` has soundId %u but sound does not exist.",i, temp.SoundId);
            }

            if (!GetLanguageDescByID(temp.Language))
                error_db_log("TSCR: Entry %i in table `custom_texts` using Language %u but Language does not exist.",i, temp.Language);

            if (temp.Type > CHAT_TYPE_ZONE_YELL)
                error_db_log("TSCR: Entry %i in table `custom_texts` has Type %u but this Chat Type does not exist.",i, temp.Type);

            TextMap[i] = temp;
            ++count;
        } while (result->NextRow());

        delete result;

        outstring_log("");
        outstring_log(">> Loaded %u additional Custom Texts data.", count);
    }else
    {
        barGoLink bar(1);
        bar.step();
        outstring_log("");
        outstring_log(">> Loaded 0 additional Custom Texts data. DB table `custom_texts` is empty.");
    }

    // Drop Existing Waypoint list
    PointMovementMap.clear();
    uint64 uiCreatureCount = 0;

    // Load Waypoints
    result = TScriptDB.PQuery("SELECT COUNT(entry) FROM script_waypoint GROUP BY entry");
    if (result)
    {
        uiCreatureCount = result->GetRowCount();
        delete result;
    }

    outstring_log("TSCR: Loading Script Waypoints for %u creature(s)...", uiCreatureCount);

    result = TScriptDB.PQuery("SELECT entry, pointid, location_x, location_y, location_z, waittime FROM script_waypoint ORDER BY pointid");

    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 uiNodeCount = 0;

        do
        {
            bar.step();
            Field* pFields = result->Fetch();
            PointMovement pTemp;

            pTemp.m_uiCreatureEntry  = pFields[0].GetUInt32();
            uint32 uiCreatureEntry   = pTemp.m_uiCreatureEntry;
            pTemp.m_uiPointId        = pFields[1].GetUInt32();
            pTemp.m_fX               = pFields[2].GetFloat();
            pTemp.m_fY               = pFields[3].GetFloat();
            pTemp.m_fZ               = pFields[4].GetFloat();
            pTemp.m_uiWaitTime       = pFields[5].GetUInt32();

            CreatureInfo const* pCInfo = GetCreatureTemplateStore(pTemp.m_uiCreatureEntry);
            if (!pCInfo)
            {
                error_db_log("TSCR: DB table script_waypoint has waypoint for non-existant creature entry %u", pTemp.m_uiCreatureEntry);
                continue;
            }

            if (!pCInfo->ScriptID)
                error_db_log("TSCR: DB table script_waypoint has waypoint for creature entry %u, but creature does not have ScriptName defined and then useless.", pTemp.m_uiCreatureEntry);

            PointMovementMap[uiCreatureEntry].push_back(pTemp);
            ++uiNodeCount;
        } while (result->NextRow());

        delete result;

        outstring_log("");
        outstring_log(">> Loaded %u Script Waypoint nodes.", uiNodeCount);
    }
    else
    {
        barGoLink bar(1);
        bar.step();
        outstring_log("");
        outstring_log(">> Loaded 0 Script Waypoints. DB table `script_waypoint` is empty.");
    }

    //Free database thread and resources
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
    bool CanLoadDB = true;

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
    {
        CanLoadDB = false;
        error_log("TSCR: Unable to open configuration file. Database will be unaccessible. Configuration values will use default.");
    }
    else outstring_log("TSCR: Using configuration file %s",cfg_file);

    outstring_log("");

    //Load database (must be called after TScriptConfig.SetSource). In case it failed, no need to even try load.
    if (CanLoadDB)
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

void DoScriptText(int32 textEntry, WorldObject* pSource, Unit* target)
{
    if (!pSource)
    {
        error_log("TSCR: DoScriptText entry %i, invalid Source pointer.",textEntry);
        return;
    }

    if (textEntry >= 0)
    {
        error_log("TSCR: DoScriptText with source entry %u (TypeId=%u, guid=%u) attempts to process text entry %i, but text entry must be negative.",pSource->GetEntry(),pSource->GetTypeId(),pSource->GetGUIDLow(),textEntry);
        return;
    }

    UNORDERED_MAP<int32, StringTextData>::iterator i = TextMap.find(textEntry);

    if (i == TextMap.end())
    {
        error_log("TSCR: DoScriptText with source entry %u (TypeId=%u, guid=%u) could not find text entry %i.",pSource->GetEntry(),pSource->GetTypeId(),pSource->GetGUIDLow(),textEntry);
        return;
    }

    debug_log("TSCR: DoScriptText: text entry=%i, Sound=%u, Type=%u, Language=%u, Emote=%u",textEntry,(*i).second.SoundId,(*i).second.Type,(*i).second.Language,(*i).second.Emote);

    if((*i).second.SoundId)
    {
        if(GetSoundEntriesStore()->LookupEntry((*i).second.SoundId))
        {
            pSource->SendPlaySound((*i).second.SoundId, false);
        }
        else
            error_log("TSCR: DoScriptText entry %i tried to process invalid sound id %u.",textEntry,(*i).second.SoundId);
    }

    if((*i).second.Emote)
    {
        if (pSource->GetTypeId() == TYPEID_UNIT || pSource->GetTypeId() == TYPEID_PLAYER)
        {
            ((Unit*)pSource)->HandleEmoteCommand((*i).second.Emote);
        }
        else
            error_log("TSCR: DoScriptText entry %i tried to process emote for invalid TypeId (%u).",textEntry, pSource->GetTypeId());
    }

    switch((*i).second.Type)
    {
        case CHAT_TYPE_SAY:
            pSource->MonsterSay(textEntry, (*i).second.Language, target ? target->GetGUID() : 0);
            break;
        case CHAT_TYPE_YELL:
            pSource->MonsterYell(textEntry, (*i).second.Language, target ? target->GetGUID() : 0);
            break;
        case CHAT_TYPE_TEXT_EMOTE:
            pSource->MonsterTextEmote(textEntry, target ? target->GetGUID() : 0);
            break;
        case CHAT_TYPE_BOSS_EMOTE:
            pSource->MonsterTextEmote(textEntry, target ? target->GetGUID() : 0, true);
            break;
        case CHAT_TYPE_WHISPER:
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    pSource->MonsterWhisper(textEntry, target->GetGUID());
                else error_log("TSCR: DoScriptText entry %i cannot whisper without target unit (TYPEID_PLAYER).", textEntry);
            }break;
        case CHAT_TYPE_BOSS_WHISPER:
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    pSource->MonsterWhisper(textEntry, target->GetGUID(), true);
                else error_log("TSCR: DoScriptText entry %i cannot whisper without target unit (TYPEID_PLAYER).", textEntry);
            }break;
        case CHAT_TYPE_ZONE_YELL:
            pSource->MonsterYellToZone(textEntry, (*i).second.Language, target ? target->GetGUID() : 0);
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


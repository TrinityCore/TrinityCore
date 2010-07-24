/* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SCRIPTMGR_H
#define SC_SCRIPTMGR_H

#include "Common.h"
#include "CompilerDefs.h"
#include "DBCStructure.h"
#include "ConfigEnv.h"


class Player;
class Creature;
class CreatureAI;
class InstanceData;
class SpellScript;
class Quest;
class Item;
class GameObject;
class SpellCastTargets;
class Map;
class Unit;
class WorldObject;
struct ItemPrototype;
class Spell;

#define MAX_SCRIPTS         5000                            //72 bytes each (approx 351kb)
#define VISIBLE_RANGE       (166.0f)                        //MAX visible range (size of grid)
#define DEFAULT_TEXT        "<Trinity Script Text Entry Missing!>"

struct Script
{
    Script() :
        pOnLogin(NULL), pOnLogout(NULL), pOnPVPKill(NULL), pOnSpellCast(NULL), pOnGetXP(NULL),
        pOnGetMoney(NULL), pOnPlayerChat(NULL), pOnServerStartup(NULL), pOnServerShutdown(NULL),
        pOnAreaChange(NULL), pOnItemClick(NULL), pOnItemOpen(NULL), pOnGoClick(NULL), pOnCreatureKill(NULL),
        pGossipHello(NULL), pQuestAccept(NULL), pGossipSelect(NULL), pGossipSelectWithCode(NULL),
        pGOSelect(NULL), pGOSelectWithCode(NULL),
        pQuestSelect(NULL), pQuestComplete(NULL), pNPCDialogStatus(NULL), pGODialogStatus(NULL),
        pChooseReward(NULL), pGODestroyed(NULL), pItemHello(NULL), pGOHello(NULL), pAreaTrigger(NULL), pItemQuestAccept(NULL),
        pGOQuestAccept(NULL), pGOChooseReward(NULL),pItemUse(NULL), pItemExpire(NULL),
        pEffectDummyCreature(NULL), pEffectDummyGameObj(NULL), pEffectDummyItem(NULL),
        GetAI(NULL), GetInstanceData(NULL), GetSpellScript(NULL)
    {}

    std::string Name;

    //Methods to be scripted
    void (*pOnLogin)(Player*);
    void (*pOnLogout)(Player*);
    void (*pOnPVPKill)(Player*, Player*);
    bool (*pOnSpellCast)(Unit*, Item*, GameObject*, uint32, SpellEntry const*);
    uint32 (*pOnGetXP)(Player*, uint32);
    int32 (*pOnGetMoney)(Player*, int32);
    bool (*pOnPlayerChat)(Player*, const char*);
    void (*pOnServerStartup)();
    void (*pOnServerShutdown)();
    void (*pOnAreaChange)(Player*, AreaTableEntry const*);
    bool (*pOnItemClick)(Player*, Item*);
    bool (*pOnItemOpen)(Player*, Item*);
    bool (*pOnGoClick)(Player*, GameObject*);
    void (*pOnCreatureKill)(Player*, Creature*);
    bool (*pGossipHello)(Player*, Creature*);
    bool (*pQuestAccept)(Player*, Creature*, Quest const*);
    bool (*pGossipSelect)(Player*, Creature*, uint32 , uint32);
    bool (*pGossipSelectWithCode)(Player*, Creature*, uint32 , uint32 , const char*);
    bool (*pGOSelect)(Player*, GameObject*, uint32 , uint32);
    bool (*pGOSelectWithCode)(Player*, GameObject*, uint32 , uint32 , const char*);
    bool (*pQuestSelect)(Player*, Creature*, Quest const*);
    bool (*pQuestComplete)(Player*, Creature*, Quest const*);
    uint32 (*pNPCDialogStatus)(Player*, Creature*);
    uint32 (*pGODialogStatus)(Player*, GameObject * _GO);
    bool (*pChooseReward)(Player*, Creature*, Quest const*, uint32);
    bool (*pItemHello)(Player*, Item*, Quest const*);
    bool (*pGOHello)(Player*, GameObject*);
    bool (*pAreaTrigger)(Player*, AreaTriggerEntry const*);
    bool (*pItemQuestAccept)(Player*, Item *, Quest const*);
    bool (*pGOQuestAccept)(Player*, GameObject*, Quest const*);
    bool (*pGOChooseReward)(Player*, GameObject*, Quest const*, uint32);
    void (*pGODestroyed)(Player*, GameObject*, uint32);
    bool (*pItemUse)(Player*, Item*, SpellCastTargets const&);
    bool (*pItemExpire)(Player*, ItemPrototype const *);
    bool (*pEffectDummyCreature)(Unit*, uint32, uint32, Creature*);
    bool (*pEffectDummyGameObj)(Unit*, uint32, uint32, GameObject*);
    bool (*pEffectDummyItem)(Unit*, uint32, uint32, Item*);

    CreatureAI* (*GetAI)(Creature*);
    InstanceData* (*GetInstanceData)(Map*);

    SpellScript*(*GetSpellScript)();
    //AuraScript*(*GetAuraScript)();

    void RegisterSelf();
};

class ScriptMgr
{
    friend class ACE_Singleton<ScriptMgr, ACE_Null_Mutex>;
    ScriptMgr();
    public:
        ~ScriptMgr();

        void ScriptsInit();
        void LoadDatabase();
        char const* ScriptsVersion();

    //event handlers
        void OnLogin(Player *pPlayer);
        void OnLogout(Player *pPlayer);
        void OnPVPKill(Player *killer, Player *killed);
        bool OnSpellCast (Unit *pUnitTarget, Item *pItemTarget, GameObject *pGoTarget, uint32 i, SpellEntry const *spell);
        uint32 OnGetXP(Player *pPlayer, uint32 amount);
        uint32 OnGetMoney(Player *pPlayer, int32 amount);
        bool OnPlayerChat(Player *pPlayer, const char *text);
        void OnServerStartup();
        void OnServerShutdown();
        void OnAreaChange(Player *pPlayer, AreaTableEntry const *pArea);
        bool OnItemClick (Player *pPlayer, Item *pItem);
        bool OnItemOpen (Player *pPlayer, Item *pItem);
        bool OnGoClick (Player *pPlayer, GameObject *pGameObject);
        void OnCreatureKill (Player *pPlayer, Creature *pCreature);
        bool GossipHello (Player * pPlayer, Creature* pCreature);
        bool GossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction);
        bool GossipSelectWithCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* sCode);
        bool GOSelect(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction);
        bool GOSelectWithCode(Player* pPlayer, GameObject* pGO, uint32 uiSender, uint32 uiAction, const char* sCode);
        bool QuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
        bool QuestSelect(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
        bool QuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
        bool ChooseReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest, uint32 opt);
        uint32 NPCDialogStatus(Player* pPlayer, Creature* pCreature);
        uint32 GODialogStatus(Player* pPlayer, GameObject* pGO);
        bool ItemHello(Player* pPlayer, Item* pItem, Quest const* pQuest);
        bool ItemQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest);
        bool GOHello(Player* pPlayer, GameObject* pGO);
        bool GOQuestAccept(Player* pPlayer, GameObject* pGO, Quest const* pQuest);
        bool GOChooseReward(Player* pPlayer, GameObject* pGO, Quest const* pQuest, uint32 opt);
        void GODestroyed(Player* pPlayer, GameObject* pGO, uint32 destroyedEvent);
        bool AreaTrigger(Player* pPlayer,AreaTriggerEntry const* atEntry);
        CreatureAI* GetAI(Creature* pCreature);
        bool ItemUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets);
        bool ItemExpire(Player* pPlayer, ItemPrototype const * pItemProto);
        bool EffectDummyCreature(Unit *caster, uint32 spellId, uint32 effIndex, Creature *crTarget);
        bool EffectDummyGameObj(Unit *caster, uint32 spellId, uint32 effIndex, GameObject *gameObjTarget);
        bool EffectDummyItem(Unit *caster, uint32 spellId, uint32 effIndex, Item *itemTarget);
        InstanceData* CreateInstanceData(Map *map);
        void CreateSpellScripts(uint32 spell_id, std::list<SpellScript *> & script_vector);
        void CreateSpellScripts(uint32 spell_id, std::vector<std::pair<SpellScript *, SpellScriptsMap::iterator> > & script_vector);
};

//Config file accessors
//std::string GetConfigValueStr(char const* option);
//int32 GetConfigValueInt32(char const* option);
//float GetConfigValueFloat(char const* option);

//Generic scripting text function
void DoScriptText(int32 textEntry, WorldObject* pSource, Unit *pTarget = NULL);

#if COMPILER == COMPILER_GNU
#define FUNC_PTR(name,callconvention,returntype,parameters)    typedef returntype(*name)parameters __attribute__ ((callconvention));
#else
#define FUNC_PTR(name, callconvention, returntype, parameters)    typedef returntype(callconvention *name)parameters;
#endif

#define sScriptMgr (*ACE_Singleton<ScriptMgr, ACE_Null_Mutex>::instance())
#endif


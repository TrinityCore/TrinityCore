/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SCRIPTMGR_H
#define SC_SCRIPTMGR_H

#include "Common.h"
#include "Platform/CompilerDefs.h"
#include "DBCStructure.h"

class Player;
class Creature;
class CreatureAI;
class InstanceData;
class Quest;
class Item;
class GameObject;
class SpellCastTargets;
class Map;
class Unit;
class WorldObject;
struct ItemPrototype;

#define MAX_SCRIPTS         5000                            //72 bytes each (approx 351kb)
#define VISIBLE_RANGE       (166.0f)                        //MAX visible range (size of grid)
#define DEFAULT_TEXT        "<Trinity Script Text Entry Missing!>"

struct Script
{
    Script() :
        pGossipHello(NULL), pQuestAccept(NULL), pGossipSelect(NULL), pGossipSelectWithCode(NULL),
        pQuestSelect(NULL), pQuestComplete(NULL), pNPCDialogStatus(NULL), pGODialogStatus(NULL),
        pChooseReward(NULL), pItemHello(NULL), pGOHello(NULL), pAreaTrigger(NULL), pItemQuestAccept(NULL),
        pGOQuestAccept(NULL), pGOChooseReward(NULL),pItemUse(NULL), pItemExpire(NULL),
        pEffectDummyCreature(NULL), pEffectDummyGameObj(NULL), pEffectDummyItem(NULL),
        GetAI(NULL), GetInstanceData(NULL)
    {}

    std::string Name;

    //Methods to be scripted
    void (*pOnLogin             )(Player*);
    void (*pOnLogout            )(Player*);
    void (*pOnPVPKill           )(Player*, Player*);
    bool (*pOnSpellCast         )(Unit*, Item*, GameObject*, uint32, SpellEntry const*);
    uint32 (*pOnGetXP           )(Player*, uint32);
    int32 (*pOnGetMoney         )(Player*, int32);
    bool (*pOnPlayerChat        )(Player*, const char*);
    void (*pOnServerStartup     )();
    void (*pOnServerShutdown    )();
    void (*pOnAreaChange        )(Player*, AreaTableEntry const*);
    bool (*pOnItemClick         )(Player*, Item*);
    bool (*pOnItemOpen          )(Player*, Item*);
    bool (*pOnGoClick           )(Player*, GameObject*);
    void (*pOnCreatureKill      )(Player*, Creature*);
    bool (*pGossipHello         )(Player*, Creature*);
    bool (*pQuestAccept         )(Player*, Creature*, Quest const* );
    bool (*pGossipSelect        )(Player*, Creature*, uint32 , uint32 );
    bool (*pGossipSelectWithCode)(Player*, Creature*, uint32 , uint32 , const char* );
    bool (*pGOSelect            )(Player*, GameObject*, uint32 , uint32 );
    bool (*pGOSelectWithCode    )(Player*, GameObject*, uint32 , uint32 , const char* );
    bool (*pQuestSelect         )(Player*, Creature*, Quest const* );
    bool (*pQuestComplete       )(Player*, Creature*, Quest const* );
    uint32 (*pNPCDialogStatus   )(Player*, Creature* );
    uint32 (*pGODialogStatus    )(Player*, GameObject * _GO );
    bool (*pChooseReward        )(Player*, Creature*, Quest const*, uint32 );
    bool (*pItemHello           )(Player*, Item*, Quest const* );
    bool (*pGOHello             )(Player*, GameObject* );
    bool (*pAreaTrigger         )(Player*, AreaTriggerEntry* );
    bool (*pItemQuestAccept     )(Player*, Item *, Quest const* );
    bool (*pGOQuestAccept       )(Player*, GameObject*, Quest const* );
    bool (*pGOChooseReward      )(Player*, GameObject*, Quest const*, uint32 );
    bool (*pItemUse             )(Player*, Item*, SpellCastTargets const& );
    bool (*pItemExpire          )(Player*, ItemPrototype const *);
    bool (*pEffectDummyCreature )(Unit*, uint32, uint32, Creature* );
    bool (*pEffectDummyGameObj  )(Unit*, uint32, uint32, GameObject* );
    bool (*pEffectDummyItem     )(Unit*, uint32, uint32, Item* );

    CreatureAI* (*GetAI)(Creature*);
    InstanceData* (*GetInstanceData)(Map*);

    void RegisterSelf();
};

//Generic scripting text function
void DoScriptText(int32 textEntry, WorldObject* pSource, Unit *pTarget = NULL);

#if COMPILER == COMPILER_GNU
#define FUNC_PTR(name,callconvention,returntype,parameters)    typedef returntype(*name)parameters __attribute__ ((callconvention));
#else
#define FUNC_PTR(name, callconvention, returntype, parameters)    typedef returntype(callconvention *name)parameters;
#endif

#ifdef WIN32
  #define TRINITY_DLL_EXPORT extern "C" __declspec(dllexport)
#elif defined( __GNUC__ )
#define TRINITY_DLL_EXPORT extern "C"
#else
#define TRINITY_DLL_EXPORT extern "C" export
#endif

#endif


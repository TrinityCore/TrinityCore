/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _LUA_ENGINE_H
#define _LUA_ENGINE_H

#include "Common.h"
#include "SharedDefines.h"
#include "DBCEnums.h"

#include "Group.h"
#include "Item.h"
#ifndef TRINITY
#include "Player.h"
#endif
#include "Weather.h"
#include "World.h"
#include "Hooks.h"
#include "ElunaUtility.h"

#ifndef USING_BOOST
#include <ace/Recursive_Thread_Mutex.h>
#endif

extern "C"
{
#include "lua.h"
};

#ifdef TRINITY
struct ItemTemplate;
typedef BattlegroundTypeId BattleGroundTypeId;
#else
struct ItemPrototype;
typedef ItemPrototype ItemTemplate;
typedef SpellEffectIndex SpellEffIndex;
struct SpellEntry;
typedef SpellEntry SpellInfo;
#ifdef CLASSIC
typedef int Difficulty;
#endif
#endif

struct AreaTriggerEntry;
class AuctionHouseObject;
struct AuctionEntry;
#ifdef TRINITY
class Battleground;
typedef Battleground BattleGround;
#endif
class Channel;
class Corpse;
class Creature;
class CreatureAI;
class GameObject;
#ifdef TRINITY
class GameObjectAI;
#endif
class Guild;
class Group;
#ifdef TRINITY
class InstanceScript;
typedef InstanceScript InstanceData;
#else
class InstanceData;
#endif
class ElunaInstanceAI;
class Item;
class Pet;
class Player;
class Quest;
class Spell;
class SpellCastTargets;
#ifdef TRINITY
class TempSummon;
#else
class TemporarySummon;
typedef TemporarySummon TempSummon;
#endif
// class Transport;
class Unit;
class Weather;
class WorldPacket;
#ifndef CLASSIC
#ifndef TBC
#ifdef TRINITY
class Vehicle;
#else
class VehicleInfo;
typedef VehicleInfo Vehicle;
#endif
#endif
#endif

struct lua_State;
class EventMgr;
class ElunaObject;
template<typename T> class ElunaTemplate;

template<typename K> class BindingMap;
template<typename T> struct EventKey;
template<typename T> struct EntryKey;
template<typename T> struct UniqueObjectKey;

struct LuaScript
{
    std::string fileext;
    std::string filename;
    std::string filepath;
    std::string modulepath;
};

#define ELUNA_OBJECT_STORE  "Eluna Object Store"
#define LOCK_ELUNA Eluna::Guard __guard(Eluna::GetLock())

#ifndef TRINITY
#define TC_GAME_API
#endif
class TC_GAME_API Eluna
{
public:
    typedef std::list<LuaScript> ScriptList;
#ifdef TRINITY
    typedef std::recursive_mutex LockType;
    typedef std::lock_guard<LockType> Guard;
#else
    typedef ACE_Recursive_Thread_Mutex LockType;
    typedef ACE_Guard<LockType> Guard;
#endif

private:
    static bool reload;
    static bool initialized;
    static LockType lock;

    // Lua script locations
    static ScriptList lua_scripts;
    static ScriptList lua_extensions;

    // Lua script folder path
    static std::string lua_folderpath;
    // lua path variable for require() function
    static std::string lua_requirepath;

    uint32 event_level;
    // When a hook pushes arguments to be passed to event handlers,
    //  this is used to keep track of how many arguments were pushed.
    uint8 push_counter;
    bool enabled;

    // Map from instance ID -> Lua table ref
    std::unordered_map<uint32, int> instanceDataRefs;
    // Map from map ID -> Lua table ref
    std::unordered_map<uint32, int> continentDataRefs;

    Eluna();
    ~Eluna();

    // Prevent copy
    Eluna(Eluna const&);
    Eluna& operator=(const Eluna&);

    void OpenLua();
    void CloseLua();
    void DestroyBindStores();
    void CreateBindStores();
    void InvalidateObjects();
    bool ExecuteCall(int params, int res);

    // Use ReloadEluna() to make eluna reload
    // This is called on world update to reload eluna
    static void _ReloadEluna();
    static void LoadScriptPaths();
    static void GetScripts(std::string path);
    static void AddScriptPath(std::string filename, const std::string& fullpath);

    static int StackTrace(lua_State *_L);
    static void Report(lua_State* _L);

    // Some helpers for hooks to call event handlers.
    // The bodies of the templates are in HookHelpers.h, so if you want to use them you need to #include "HookHelpers.h".
    template<typename K1, typename K2> int SetupStack(BindingMap<K1>* bindings1, BindingMap<K2>* bindings2, const K1& key1, const K2& key2, int number_of_arguments);
                                       int CallOneFunction(int number_of_functions, int number_of_arguments, int number_of_results);          
                                       void CleanUpStack(int number_of_arguments);
    template<typename T>               void ReplaceArgument(T value, uint8 index);
    template<typename K1, typename K2> void CallAllFunctions(BindingMap<K1>* bindings1, BindingMap<K2>* bindings2, const K1& key1, const K2& key2);
    template<typename K1, typename K2> bool CallAllFunctionsBool(BindingMap<K1>* bindings1, BindingMap<K2>* bindings2, const K1& key1, const K2& key2, bool default_value = false);

    // Same as above but for only one binding instead of two.
    // `key` is passed twice because there's no NULL for references, but it's not actually used if `bindings2` is NULL.
    template<typename K> int SetupStack(BindingMap<K>* bindings, const K& key, int number_of_arguments)
    {
        return SetupStack<K, K>(bindings, NULL, key, key, number_of_arguments);
    }
    template<typename K> void CallAllFunctions(BindingMap<K>* bindings, const K& key)
    {
        CallAllFunctions<K, K>(bindings, NULL, key, key);
    }
    template<typename K> bool CallAllFunctionsBool(BindingMap<K>* bindings, const K& key, bool default_value = false)
    {
        return CallAllFunctionsBool<K, K>(bindings, NULL, key, key, default_value);
    }

    // Non-static pushes, to be used in hooks.
    // These just call the correct static version with the main thread's Lua state.
    void Push()                                 { Push(L); ++push_counter; }
    void Push(const long long value)            { Push(L, value); ++push_counter; }
    void Push(const unsigned long long value)   { Push(L, value); ++push_counter; }
    void Push(const long value)                 { Push(L, value); ++push_counter; }
    void Push(const unsigned long value)        { Push(L, value); ++push_counter; }
    void Push(const int value)                  { Push(L, value); ++push_counter; }
    void Push(const unsigned int value)         { Push(L, value); ++push_counter; }
    void Push(const bool value)                 { Push(L, value); ++push_counter; }
    void Push(const float value)                { Push(L, value); ++push_counter; }
    void Push(const double value)               { Push(L, value); ++push_counter; }
    void Push(const std::string& value)         { Push(L, value); ++push_counter; }
    void Push(const char* value)                { Push(L, value); ++push_counter; }
    template<typename T>
    void Push(T const* ptr)                     { Push(L, ptr); ++push_counter; }

public:
    static Eluna* GEluna;

    lua_State* L;
    EventMgr* eventMgr;

    BindingMap< EventKey<Hooks::ServerEvents> >*     ServerEventBindings;
    BindingMap< EventKey<Hooks::PlayerEvents> >*     PlayerEventBindings;
    BindingMap< EventKey<Hooks::GuildEvents> >*      GuildEventBindings;
    BindingMap< EventKey<Hooks::GroupEvents> >*      GroupEventBindings;
    BindingMap< EventKey<Hooks::VehicleEvents> >*    VehicleEventBindings;
    BindingMap< EventKey<Hooks::BGEvents> >*         BGEventBindings;

    BindingMap< EntryKey<Hooks::PacketEvents> >*     PacketEventBindings;
    BindingMap< EntryKey<Hooks::CreatureEvents> >*   CreatureEventBindings;
    BindingMap< EntryKey<Hooks::GossipEvents> >*     CreatureGossipBindings;
    BindingMap< EntryKey<Hooks::GameObjectEvents> >* GameObjectEventBindings;
    BindingMap< EntryKey<Hooks::GossipEvents> >*     GameObjectGossipBindings;
    BindingMap< EntryKey<Hooks::ItemEvents> >*       ItemEventBindings;
    BindingMap< EntryKey<Hooks::GossipEvents> >*     ItemGossipBindings;
    BindingMap< EntryKey<Hooks::GossipEvents> >*     PlayerGossipBindings;
    BindingMap< EntryKey<Hooks::InstanceEvents> >*   MapEventBindings;
    BindingMap< EntryKey<Hooks::InstanceEvents> >*   InstanceEventBindings;

    BindingMap< UniqueObjectKey<Hooks::CreatureEvents> >*  CreatureUniqueBindings;

    static void Initialize();
    static void Uninitialize();
    // This function is used to make eluna reload
    static void ReloadEluna() { LOCK_ELUNA; reload = true; }
    static LockType& GetLock() { return lock; };
    static bool IsInitialized() { return initialized; }

    // Static pushes, can be used by anything, including methods.
    static void Push(lua_State* luastate); // nil
    static void Push(lua_State* luastate, const long long);
    static void Push(lua_State* luastate, const unsigned long long);
    static void Push(lua_State* luastate, const long);
    static void Push(lua_State* luastate, const unsigned long);
    static void Push(lua_State* luastate, const int);
    static void Push(lua_State* luastate, const unsigned int);
    static void Push(lua_State* luastate, const bool);
    static void Push(lua_State* luastate, const float);
    static void Push(lua_State* luastate, const double);
    static void Push(lua_State* luastate, const std::string&);
    static void Push(lua_State* luastate, const char*);
    static void Push(lua_State* luastate, Object const* obj);
    static void Push(lua_State* luastate, WorldObject const* obj);
    static void Push(lua_State* luastate, Unit const* unit);
    static void Push(lua_State* luastate, Pet const* pet);
    static void Push(lua_State* luastate, TempSummon const* summon);
    template<typename T>
    static void Push(lua_State* luastate, T const* ptr)
    {
        ElunaTemplate<T>::Push(luastate, ptr);
    }

    /*
     * Returns `true` if Eluna has instance data for `map`.
     */
    bool HasInstanceData(Map const* map);

    /*
     * Use the top element of the stack as the instance data table for `map`,
     *   then pops it off the stack.
     */
    void CreateInstanceData(Map const* map);

    /*
     * Retrieve the instance data for the `Map` scripted by `ai` and push it
     *   onto the stack.
     *
     * An `ElunaInstanceAI` is needed because the instance data might
     *   not exist (i.e. Eluna has been reloaded).
     *
     * In that case, the AI is "reloaded" (new instance data table is created
     *   and loaded with the last known save state, and `Load`/`Initialize`
     *   hooks are called).
     */
    void PushInstanceData(lua_State* L, ElunaInstanceAI* ai, bool incrementCounter = true);

    void RunScripts();
    bool ShouldReload() const { return reload; }
    bool IsEnabled() const { return enabled && IsInitialized(); }
    bool HasLuaState() const { return L != NULL; }
    int Register(lua_State* L, uint8 reg, uint32 entry, uint64 guid, uint32 instanceId, uint32 event_id, int functionRef, uint32 shots);

    // Checks
    template<typename T> static T CHECKVAL(lua_State* luastate, int narg);
    template<typename T> static T CHECKVAL(lua_State* luastate, int narg, T def)
    {
        return lua_isnoneornil(luastate, narg) ? def : CHECKVAL<T>(luastate, narg);
    }
    template<typename T> static T* CHECKOBJ(lua_State* luastate, int narg, bool error = true)
    {
        return ElunaTemplate<T>::Check(luastate, narg, error);
    }
    static ElunaObject* CHECKTYPE(lua_State* luastate, int narg, const char *tname, bool error = true);

    CreatureAI* GetAI(Creature* creature);
    InstanceData* GetInstanceData(Map* map);
    void FreeInstanceId(uint32 instanceId);

    /* Custom */
    void OnTimedEvent(int funcRef, uint32 delay, uint32 calls, WorldObject* obj);
    bool OnCommand(Player* player, const char* text);
    void OnWorldUpdate(uint32 diff);
    void OnLootItem(Player* pPlayer, Item* pItem, uint32 count, uint64 guid);
    void OnLootMoney(Player* pPlayer, uint32 amount);
    void OnFirstLogin(Player* pPlayer);
    void OnEquip(Player* pPlayer, Item* pItem, uint8 bag, uint8 slot);
    void OnRepop(Player* pPlayer);
    void OnResurrect(Player* pPlayer);
    void OnQuestAbandon(Player* pPlayer, uint32 questId);
    void OnLearnTalents(Player* pPlayer, uint32 talentId, uint32 talentRank, uint32 spellid);
    InventoryResult OnCanUseItem(const Player* pPlayer, uint32 itemEntry);
    void OnLuaStateClose();
    void OnLuaStateOpen();
    bool OnAddonMessage(Player* sender, uint32 type, std::string& msg, Player* receiver, Guild* guild, Group* group, Channel* channel);

    /* Item */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Item* pTarget);
    bool OnQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest);
    bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets);
    bool OnItemUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets);
    bool OnItemGossip(Player* pPlayer, Item* pItem, SpellCastTargets const& targets);
    bool OnExpire(Player* pPlayer, ItemTemplate const* pProto);
    bool OnRemove(Player* pPlayer, Item* item);
    void HandleGossipSelectOption(Player* pPlayer, Item* item, uint32 sender, uint32 action, const std::string& code);

    /* Creature */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Creature* pTarget);
    bool OnGossipHello(Player* pPlayer, Creature* pCreature);
    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
    bool OnQuestReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest, uint32 opt);
    uint32 GetDialogStatus(Player* pPlayer, Creature* pCreature);

    bool OnSummoned(Creature* creature, Unit* summoner);
    bool UpdateAI(Creature* me, const uint32 diff);
    bool EnterCombat(Creature* me, Unit* target);
    bool DamageTaken(Creature* me, Unit* attacker, uint32& damage);
    bool JustDied(Creature* me, Unit* killer);
    bool KilledUnit(Creature* me, Unit* victim);
    bool JustSummoned(Creature* me, Creature* summon);
    bool SummonedCreatureDespawn(Creature* me, Creature* summon);
    bool MovementInform(Creature* me, uint32 type, uint32 id);
    bool AttackStart(Creature* me, Unit* target);
    bool EnterEvadeMode(Creature* me);
    bool AttackedBy(Creature* me, Unit* attacker);
    bool JustRespawned(Creature* me);
    bool JustReachedHome(Creature* me);
    bool ReceiveEmote(Creature* me, Player* player, uint32 emoteId);
    bool CorpseRemoved(Creature* me, uint32& respawnDelay);
    bool MoveInLineOfSight(Creature* me, Unit* who);
    bool SpellHit(Creature* me, Unit* caster, SpellInfo const* spell);
    bool SpellHitTarget(Creature* me, Unit* target, SpellInfo const* spell);
    bool SummonedCreatureDies(Creature* me, Creature* summon, Unit* killer);
    bool OwnerAttackedBy(Creature* me, Unit* attacker);
    bool OwnerAttacked(Creature* me, Unit* target);
    void On_Reset(Creature* me);

    /* GameObject */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, GameObject* pTarget);
    bool OnGameObjectUse(Player* pPlayer, GameObject* pGameObject);
    bool OnGossipHello(Player* pPlayer, GameObject* pGameObject);
    bool OnGossipSelect(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest);
    bool OnQuestReward(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest, uint32 opt);
    uint32 GetDialogStatus(Player* pPlayer, GameObject* pGameObject);
#ifndef CLASSIC
#ifndef TBC
    void OnDestroyed(GameObject* pGameObject, Player* pPlayer);
    void OnDamaged(GameObject* pGameObject, Player* pPlayer);
#endif
#endif
    void OnLootStateChanged(GameObject* pGameObject, uint32 state);
    void OnGameObjectStateChanged(GameObject* pGameObject, uint32 state);
    void UpdateAI(GameObject* pGameObject, uint32 diff);
    void OnSpawn(GameObject* gameobject);

    /* Packet */
    bool OnPacketSend(WorldSession* session, const WorldPacket& packet);
    void OnPacketSendAny(Player* player, const WorldPacket& packet, bool& result);
    void OnPacketSendOne(Player* player, const WorldPacket& packet, bool& result);
    bool OnPacketReceive(WorldSession* session, WorldPacket& packet);
    void OnPacketReceiveAny(Player* player, WorldPacket& packet, bool& result);
    void OnPacketReceiveOne(Player* player, WorldPacket& packet, bool& result);

    /* Player */
    void OnPlayerEnterCombat(Player* pPlayer, Unit* pEnemy);
    void OnPlayerLeaveCombat(Player* pPlayer);
    void OnPVPKill(Player* pKiller, Player* pKilled);
    void OnCreatureKill(Player* pKiller, Creature* pKilled);
    void OnPlayerKilledByCreature(Creature* pKiller, Player* pKilled);
    void OnLevelChanged(Player* pPlayer, uint8 oldLevel);
    void OnFreeTalentPointsChanged(Player* pPlayer, uint32 newPoints);
    void OnTalentsReset(Player* pPlayer, bool noCost);
    void OnMoneyChanged(Player* pPlayer, int32& amount);
    void OnGiveXP(Player* pPlayer, uint32& amount, Unit* pVictim);
    void OnReputationChange(Player* pPlayer, uint32 factionID, int32& standing, bool incremental);
    void OnDuelRequest(Player* pTarget, Player* pChallenger);
    void OnDuelStart(Player* pStarter, Player* pChallenger);
    void OnDuelEnd(Player* pWinner, Player* pLoser, DuelCompleteType type);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Group* pGroup);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Guild* pGuild);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Channel* pChannel);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Player* pReceiver);
    void OnEmote(Player* pPlayer, uint32 emote);
    void OnTextEmote(Player* pPlayer, uint32 textEmote, uint32 emoteNum, uint64 guid);
    void OnSpellCast(Player* pPlayer, Spell* pSpell, bool skipCheck);
    void OnLogin(Player* pPlayer);
    void OnLogout(Player* pPlayer);
    void OnCreate(Player* pPlayer);
    void OnDelete(uint32 guid);
    void OnSave(Player* pPlayer);
    void OnBindToInstance(Player* pPlayer, Difficulty difficulty, uint32 mapid, bool permanent);
    void OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea);
    void OnMapChanged(Player* pPlayer);
    void HandleGossipSelectOption(Player* pPlayer, uint32 menuId, uint32 sender, uint32 action, const std::string& code);

#ifndef CLASSIC
#ifndef TBC
    /* Vehicle */
    void OnInstall(Vehicle* vehicle);
    void OnUninstall(Vehicle* vehicle);
    void OnInstallAccessory(Vehicle* vehicle, Creature* accessory);
    void OnAddPassenger(Vehicle* vehicle, Unit* passenger, int8 seatId);
    void OnRemovePassenger(Vehicle* vehicle, Unit* passenger);
#endif
#endif

    /* AreaTrigger */
    bool OnAreaTrigger(Player* pPlayer, AreaTriggerEntry const* pTrigger);

    /* Weather */
    void OnChange(Weather* weather, uint32 zone, WeatherState state, float grade);

    /* Auction House */
    void OnAdd(AuctionHouseObject* ah, AuctionEntry* entry);
    void OnRemove(AuctionHouseObject* ah, AuctionEntry* entry);
    void OnSuccessful(AuctionHouseObject* ah, AuctionEntry* entry);
    void OnExpire(AuctionHouseObject* ah, AuctionEntry* entry);

    /* Guild */
    void OnAddMember(Guild* guild, Player* player, uint32 plRank);
    void OnRemoveMember(Guild* guild, Player* player, bool isDisbanding);
    void OnMOTDChanged(Guild* guild, const std::string& newMotd);
    void OnInfoChanged(Guild* guild, const std::string& newInfo);
    void OnCreate(Guild* guild, Player* leader, const std::string& name);
    void OnDisband(Guild* guild);
    void OnMemberWitdrawMoney(Guild* guild, Player* player, uint32& amount, bool isRepair);
    void OnMemberDepositMoney(Guild* guild, Player* player, uint32& amount);
    void OnItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId, bool isDestBank, uint8 destContainer, uint8 destSlotId);
    void OnEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank);
    void OnBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId);

    /* Group */
    void OnAddMember(Group* group, uint64 guid);
    void OnInviteMember(Group* group, uint64 guid);
    void OnRemoveMember(Group* group, uint64 guid, uint8 method);
    void OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid);
    void OnDisband(Group* group);
    void OnCreate(Group* group, uint64 leaderGuid, GroupType groupType);

    /* Map */
    void OnCreate(Map* map);
    void OnDestroy(Map* map);
    void OnPlayerEnter(Map* map, Player* player);
    void OnPlayerLeave(Map* map, Player* player);
    void OnUpdate(Map* map, uint32 diff);
    void OnAddToWorld(Creature* creature);
    void OnRemoveFromWorld(Creature* creature);
    void OnAddToWorld(GameObject* gameobject);
    void OnRemoveFromWorld(GameObject* gameobject);
    void OnRemove(Creature* creature);
    void OnRemove(GameObject* gameobject);

    /* Instance */
    void OnInitialize(ElunaInstanceAI* ai);
    void OnLoad(ElunaInstanceAI* ai);
    void OnUpdateInstance(ElunaInstanceAI* ai, uint32 diff);
    void OnPlayerEnterInstance(ElunaInstanceAI* ai, Player* player);
    void OnCreatureCreate(ElunaInstanceAI* ai, Creature* creature);
    void OnGameObjectCreate(ElunaInstanceAI* ai, GameObject* gameobject);
    bool OnCheckEncounterInProgress(ElunaInstanceAI* ai);

    /* World */
    void OnOpenStateChange(bool open);
    void OnConfigLoad(bool reload);
    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask);
    void OnShutdownCancel();
    void OnStartup();
    void OnShutdown();

    /* Battle Ground */
    void OnBGStart(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId);
    void OnBGEnd(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId, Team winner);
    void OnBGCreate(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId);
    void OnBGDestroy(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId);
};
template<> Unit* Eluna::CHECKOBJ<Unit>(lua_State* L, int narg, bool error);
template<> Object* Eluna::CHECKOBJ<Object>(lua_State* L, int narg, bool error);
template<> WorldObject* Eluna::CHECKOBJ<WorldObject>(lua_State* L, int narg, bool error);
template<> ElunaObject* Eluna::CHECKOBJ<ElunaObject>(lua_State* L, int narg, bool error);

#define sEluna Eluna::GEluna
#endif

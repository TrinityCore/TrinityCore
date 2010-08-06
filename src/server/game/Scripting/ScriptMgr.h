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
#include "Config.h"
#include "ObjectMgr.h"
#include "BattleGround.h"
#include "OutdoorPvPMgr.h"
#include "SharedDefines.h"
#include "Chat.h"
#include "Weather.h"
#include "AuctionHouseMgr.h"
#include "ConditionMgr.h"
#include "Vehicle.h"
#include "Transport.h"

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
class ScriptMgr;
class WorldSocket;

#define VISIBLE_RANGE       (166.0f)                        //MAX visible range (size of grid)
#define DEFAULT_TEXT        "<Trinity Script Text Entry Missing!>"

// Generic scripting text function.
void DoScriptText(int32 textEntry, WorldObject* pSource, Unit *pTarget = NULL);

/*
    TODO: Add more script type classes.

    ChatScript
    MailScript
    SessionScript
    CollisionScript
    GroupScript
    ArenaTeamScript
    GuildScript

*/

/*
    Standard procedure when adding new script type classes:

    First of all, define the actual class, and have it inherit from ScriptObject, like so:

    class MyScriptType : public ScriptObject
    {
        uint32 _someId;

        protected:

            MyScriptType(const char* name, uint32 someId)
                : ScriptObject(name), _someId(someId)
            { }

            void RegisterSelf();

        public:

            // If a virtual function in your script type class is not necessarily
            // required to be overridden, just declare it virtual with an empty
            // body. If, on the other hand, it's logical only to override it (i.e.
            // if it's the only method in the class), make it pure virtual, by adding
            // = 0 to it.
            virtual void OnSomeEvent(uint32 someArg1, std::string& someArg2) { }

            // This is a pure virtual function:
            virtual void OnAnotherEvent(uint32 someArg) = 0;
    }

    RegisterSelf() should be defined in ScriptMgr.cpp, and simply registers the script
    with ScriptRegistry:

    void MyScriptType::RegisterSelf()
    {
        ScriptMgr::ScriptRegistry<MyScriptType>::AddScript(this);
    }

    Next, you need to add a specialization for ScriptRegistry. Put this in the bottom of
    ScriptMgr.cpp:

    template class ScriptMgr::ScriptRegistry<MyScriptType>;

    Now, add a cleanup routine in ScriptMgr::~ScriptMgr:

    SCR_CLEAR(MyScriptType);

    Now your script type is good to go with the script system. What you need to do now
    is add functions to ScriptMgr that can be called from the core to actually trigger
    certain events. For example, in ScriptMgr.h:

    void OnSomeEvent(uint32 someArg1, std::string& someArg2);
    void OnAnotherEvent(uint32 someArg);

    In ScriptMgr.cpp:

    void ScriptMgr::OnSomeEvent(uint32 someArg1, std::string& someArg2)
    {
        FOREACH_SCRIPT(MyScriptType)->OnSomeEvent(someArg1, someArg2);
    }

    void ScriptMgr::OnAnotherEvent(uint32 someArg)
    {
        FOREACH_SCRIPT(MyScriptType)->OnAnotherEvent(someArg1, someArg2);
    }

    Now you simply call these two functions from anywhere in the core to trigger the
    event on all registered scripts of that type.
*/

class ScriptObject
{
    friend class ScriptMgr;

    public:

        // Called when the script is initialized. Use it to initialize any properties of the script.
        virtual void OnInitialize() { }

        // Called when the script is deleted. Use it to free memory, etc.
        virtual void OnTeardown() { }

        // Do not override this in scripts; it should be overridden by the various script type classes. It indicates
        // whether or not this script type must be assigned in the database.
        virtual bool IsDatabaseBound() const { return false; }

        const std::string& GetName() const { return _name; }

        const char* ToString() const { return _name.c_str(); }

    protected:

        // Call this to register the script with ScriptMgr.
        virtual void RegisterSelf() = 0;

        ScriptObject(const char* name)
            : _name(std::string(name))
        {
            // Allow the script to do startup routines.
            OnInitialize();

            // Register with ScriptMgr.
            RegisterSelf();
        }

        virtual ~ScriptObject()
        {
            // Allow the script to do cleanup routines.
            OnTeardown();
        }

    private:

        const std::string _name;
};

template<class TObject> class UpdatableScript
{
    protected:

        UpdatableScript()
        {
        }

    public:

        virtual void OnUpdate(TObject* obj, uint32 diff) { }
};

class SpellHandlerScript : public ScriptObject
{
    protected:

        SpellHandlerScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid SpellScript pointer.
        virtual SpellScript* GetSpellScript() const = 0;
};

class AuraHandlerScript : public ScriptObject
{
    protected:

        AuraHandlerScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid AuraScript pointer.
        // virtual AuraScript* GetAuraScript() const = 0;
};

class ServerScript : public ScriptObject
{
    protected:

        ServerScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Called when reactive socket I/O is started (WorldSocketMgr).
        virtual void OnNetworkStart() { }

        // Called when reactive I/O is stopped.
        virtual void OnNetworkStop() { }

        // Called when a remote socket establishes a connection to the server. Do not store the socket object.
        virtual void OnSocketOpen(WorldSocket* socket) { }

        // Called when a socket is closed. Do not store the socket object, and do not rely on the connection
        // being open; it is not.
        virtual void OnSocketClose(WorldSocket* socket, bool wasNew) { }

        // Called when a packet is sent to a client. The packet object is a copy of the original packet, so reading
        // and modifying it is safe.
        virtual void OnPacketSend(WorldSocket* socket, WorldPacket& packet) { }

        // Called when a (valid) packet is received by a client. The packet object is a copy of the original packet, so
        // reading and modifying it is safe.
        virtual void OnPacketReceive(WorldSocket* socket, WorldPacket& packet) { }

        // Called when an invalid (unknown opcode) packet is received by a client. The packet is a reference to the orignal
        // packet; not a copy. This allows you to actually handle unknown packets (for whatever purpose).
        virtual void OnUnknownPacketReceive(WorldSocket* socket, WorldPacket& packet) { }
};

class WorldScript : public ScriptObject, public UpdatableScript<void>
{
    protected:

        WorldScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Called when the open/closed state of the world changes.
        virtual void OnOpenStateChange(bool open) { }

        // Called after the world configuration is (re)loaded.
        virtual void OnConfigLoad(bool reload) { }

        // Called before the message of the day is changed.
        virtual void OnMotdChange(std::string& newMotd) { }

        // Called when a world shutdown is initiated.
        virtual void OnShutdown(ShutdownExitCode code, ShutdownMask mask) { }

        // Called when a world shutdown is cancelled.
        virtual void OnShutdownCancel() { }

        // Called on every world tick (don't execute too heavy code here).
        virtual void OnUpdate(void* null, uint32 diff) { }
};

class FormulaScript : public ScriptObject
{
    protected:

        FormulaScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Called after calculating honor.
        virtual void OnHonorCalculation(float& honor, uint8 level, uint32 count) { }

        // Called after calculating honor.
        virtual void OnHonorCalculation(uint32& honor, uint8 level, uint32 count) { }

        // Called after gray level calculation.
        virtual void OnGetGrayLevel(uint8& grayLevel, uint8 playerLevel) { }

        // Called after calculating experience color.
        virtual void OnGetColorCode(XPColorChar& color, uint8 playerLevel, uint8 mobLevel) { }

        // Called after calculating zero difference.
        virtual void OnGetZeroDifference(uint8& diff, uint8 playerLevel) { }

        // Called after calculating base experience gain.
        virtual void OnGetBaseGain(uint32& gain, uint8 playerLevel, uint8 mobLevel, ContentLevels content) { }

        // Called after calculating experience gain.
        virtual void OnGetGain(uint32& gain, Player* player, Unit* unit) { }

        virtual void OnGetGroupRate(float& rate, uint32 count, bool isRaid) { }
};

template<class TMap> class MapScript : public UpdatableScript<TMap>
{
    MapEntry const* _mapEntry;

    protected:

        MapScript(uint32 mapId)
            : _mapEntry(sMapStore.LookupEntry(mapId))
        {
            if (!_mapEntry)
                sLog.outError("Invalid MapScript for %u; no such map ID.", mapId);
        }

    public:

        // Gets the MapEntry structure associated with this script. Can return NULL.
        MapEntry const* GetEntry() { return _mapEntry; }

        // Called when the map is created.
        virtual void OnCreate(TMap* map) { }

        // Called just before the map is destroyed.
        virtual void OnDestroy(TMap* map) { }

        // Called when a grid map is loaded.
        virtual void OnLoadGridMap(TMap* map, uint32 gx, uint32 gy) { }

        // Called when a grid map is unloaded.
        virtual void OnUnloadGridMap(TMap* map, uint32 gx, uint32 gy)  { }

        // Called when a player enters the map.
        virtual void OnPlayerEnter(TMap* map, Player* player) { }

        // Called when a player leaves the map.
        virtual void OnPlayerLeave(TMap* map, Player* player) { }

        // Called on every map update tick.
        virtual void OnUpdate(TMap* map, uint32 diff) { }
};

class WorldMapScript : public ScriptObject, public MapScript<Map>
{
    protected:

        WorldMapScript(const char* name, uint32 mapId)
            : ScriptObject(name), MapScript(mapId)
        {
            if (GetEntry() && !GetEntry()->IsContinent())
                sLog.outError("WorldMapScript for map %u is invalid.", mapId);
        }

        void RegisterSelf();
};

class InstanceMapScript : public ScriptObject, public MapScript<InstanceMap>
{
    protected:

        InstanceMapScript(const char* name, uint32 mapId = 0)
            : ScriptObject(name), MapScript(mapId)
        {
            if (GetEntry() && !GetEntry()->IsDungeon())
                sLog.outError("InstanceMapScript for map %u is invalid.", mapId);
        }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Gets an InstanceData object for this instance.
        virtual InstanceData* OnGetInstanceData(InstanceMap* map) { return NULL; }
};

class BattlegroundMapScript : public ScriptObject, public MapScript<BattleGroundMap>
{
    protected:

        BattlegroundMapScript(const char* name, uint32 mapId)
            : ScriptObject(name), MapScript(mapId)
        {
            if (GetEntry() && !GetEntry()->IsBattleGround())
                sLog.outError("BattlegroundMapScript for map %u is invalid.", mapId);
        }

        void RegisterSelf();
};

class ItemScript : public ScriptObject
{
    protected:

        ItemScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a dummy spell effect is triggered on the item.
        virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target) { return false; }

        // Called when a player accepts a quest from the item.
        virtual bool OnQuestAccept(Player* player, Item* item, Quest const* quest) { return false; }

        // Called when a player uses the item.
        virtual bool OnUse(Player* player, Item* item, SpellCastTargets const& targets) { return false; }

        // Called when the item expires (is destroyed).
        virtual bool OnExpire(Player* player, ItemPrototype const* proto) { return false; }
};

class CreatureScript : public ScriptObject, public UpdatableScript<Creature>
{
    protected:

        CreatureScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }
        
        // Called when a dummy spell effect is triggered on the creature.
        virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target) { return false; }

        // Called when a player opens a gossip dialog with the creature.
        virtual bool OnGossipHello(Player* player, Creature* creature) { return false; }

        // Called when a player selects a gossip item in the creature's gossip menu.
        virtual bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) { return false; }

        // Called when a player selects a gossip with a code in the creature's gossip menu.
        virtual bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code) { return false; }

        // Called when a player accepts a quest from the creature.
        virtual bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) { return false; }

        // Called when a player selects a quest in the creature's quest menu.
        virtual bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest) { return false; }

        // Called when a player completes a quest with the creature.
        virtual bool OnQuestComplete(Player* player, Creature* creature, Quest const* quest) { return false; }

        // Called when a player selects a quest reward.
        virtual bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt) { return false; }

        // Called when the dialog status between a player and the creature is requested.
        virtual uint32 OnDialogStatus(Player* player, Creature* creature) { return 0; }

        // Called when a CreatureAI object is needed for the creature.
        virtual CreatureAI* OnGetAI() { return NULL; }
};

class GameObjectScript : public ScriptObject, public UpdatableScript<GameObject>
{
    protected:

        GameObjectScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }
        
        // Called when a dummy spell effect is triggered on the gameobject.
        virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target) { return false; }
        
        // Called when a player opens a gossip dialog with the gameobject.
        virtual bool OnGossipHello(Player* player, GameObject* go) { return false; }
        
        // Called when a player selects a gossip item in the gameobject's gossip menu.
        virtual bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) { return false; }
        
        // Called when a player selects a gossip with a code in the gameobject's gossip menu.
        virtual bool OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code) { return false; }
        
        // Called when a player accepts a quest from the gameobject.
        virtual bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest) { return false; }
        
        // Called when a player selects a quest reward.
        virtual bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt) { return false; }
        
        // Called when the dialog status between a player and the gameobject is requested.
        virtual uint32 OnDialogStatus(Player* player, GameObject* go) { return 0; }

        // Called when the gameobject is destroyed (destructible buildings only).
        virtual void OnDestroyed(Player* player, GameObject* go, uint32 eventId) { }
};

class AreaTriggerScript : public ScriptObject
{
    protected:

        AreaTriggerScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when the area trigger is activated by a player.
        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger) { return false; }
};

class BattlegroundScript : public ScriptObject
{
    protected:

        BattlegroundScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid BattleGround object for the type ID.
        virtual BattleGround* OnGetBattleground() = 0;
};

class OutdoorPvPScript : public ScriptObject
{
    protected:

        OutdoorPvPScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid OutdoorPvP object for the type ID.
        virtual OutdoorPvP* OnGetOutdoorPvP() = 0;
};

class CommandScript : public ScriptObject
{
    protected:

        CommandScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Should return a pointer to a valid command table (ChatCommand array) to be used by ChatHandler.
        virtual ChatCommand* OnGetCommands() = 0;
};

class WeatherScript : public ScriptObject, public UpdatableScript<Weather>
{
    protected:

        WeatherScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when the weather changes in the zone this script is associated with.
        virtual void OnChange(Weather* weather, WeatherState state, float grade) { }
};

class AuctionHouseScript : public ScriptObject
{
    protected:

        AuctionHouseScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Called when an auction is added to an auction house.
        void OnAuctionAdd(AuctionHouseObject* ah, AuctionEntry* entry) { }

        // Called when an auction is removed from an auction house.
        void OnAuctionRemove(AuctionHouseObject* ah, AuctionEntry* entry) { }

        // Called when an auction was succesfully completed.
        void OnAuctionSuccessful(AuctionHouseObject* ah, AuctionEntry* entry) { }

        // Called when an auction expires.
        void OnAuctionExpire(AuctionHouseObject* ah, AuctionEntry* entry) { }
};

class ConditionScript : public ScriptObject
{
    protected:

        ConditionScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a single condition is checked for a player.
        bool OnConditionCheck(Condition* condition, Player* player, Unit* targetOverride) { return true; }
};

class VehicleScript : public ScriptObject
{
    protected:

        VehicleScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();

    public:

        // Called after a vehicle is installed.
        virtual void OnInstall(Vehicle* veh) { }

        // Called after a vehicle is uninstalled.
        virtual void OnUninstall(Vehicle* veh) { }

        // Called after a vehicle dies.
        virtual void OnDie(Vehicle* veh) { }

        // Called when a vehicle resets.
        virtual void OnReset(Vehicle* veh) { }

        // Called after an accessory is installed in a vehicle.
        virtual void OnInstallAccessory(Vehicle* veh, Creature* accessory) { }

        // Called after a passenger is added to a vehicle.
        virtual void OnAddPassenger(Vehicle* veh, Unit* passenger, int8 seatId) { }

        // Called after a passenger is removed from a vehicle.
        virtual void OnRemovePassenger(Vehicle* veh, Unit* passenger) { }
};

class DynamicObjectScript : public ScriptObject, public UpdatableScript<DynamicObject>
{
    protected:

        DynamicObjectScript(const char* name)
            : ScriptObject(name)
        { }

        void RegisterSelf();
};

class TransportScript : public ScriptObject, public UpdatableScript<Transport>
{
    protected:

        TransportScript(const char* name)
            : ScriptObject(name)
        {
        }

        void RegisterSelf();

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a player boards the transport.
        virtual void OnAddPassenger(Transport* transport, Player* player) { }

        // Called when a creature boards the transport.
        virtual void OnAddCreaturePassenger(Transport* transport, Creature* creature) { }

        // Called when a player exits the transport.
        virtual void OnRemovePassenger(Transport* transport, Player* player) { }
};

// Placed here due to ScriptRegistry::AddScript dependency.
#define sScriptMgr (*ACE_Singleton<ScriptMgr, ACE_Null_Mutex>::instance())

// Manages registration, loading, and execution of scripts.
class ScriptMgr
{
    friend class ACE_Singleton<ScriptMgr, ACE_Null_Mutex>;
    friend class ScriptObject;

    ScriptMgr();
    ~ScriptMgr();

    uint32 _scriptCount;
    
    void LoadDatabase();
    void FillSpellSummary();

    public: /* Initialization */

        void Initialize();
        const char* ScriptsVersion() const { return "Integrated Trinity Scripts"; }

        void IncrementScriptCount() { ++_scriptCount; }
        uint32 GetScriptCount() const { return _scriptCount; }

    public: /* SpellHandlerScript */

        void CreateSpellScripts(uint32 spell_id, std::list<SpellScript*>& script_vector);
        void CreateSpellScripts(uint32 spell_id, std::vector<std::pair<SpellScript*, SpellScriptsMap::iterator> >& script_vector);

    public: /* AuraHandlerScript */

        // void CreateAuraScripts(uint32 spell_id, std::list<AuraScript*>& script_vector);
        // void CreateAuraScripts(uint32 spell_id, std::vector<std::pair<AuraScript*, SpellScriptsMap::iterator> >& script_vector);

    public: /* ServerScript */

        void OnNetworkStart();
        void OnNetworkStop();
        void OnSocketOpen(WorldSocket* socket);
        void OnSocketClose(WorldSocket* socket, bool wasNew);
        void OnPacketReceive(WorldSocket* socket, WorldPacket& packet);
        void OnPacketSend(WorldSocket* socket, WorldPacket& packet);
        void OnUnknownPacketReceive(WorldSocket* socket, WorldPacket& packet);

    public: /* WorldScript */

        void OnOpenStateChange(bool open);
        void OnConfigLoad(bool reload);
        void OnMotdChange(std::string& newMotd);
        void OnShutdown(ShutdownExitCode code, ShutdownMask mask);
        void OnShutdownCancel();
        void OnWorldUpdate(uint32 diff);

    public: /* FormulaScript */

        void OnHonorCalculation(float& honor, uint8 level, uint32 count);
        void OnHonorCalculation(uint32& honor, uint8 level, uint32 count);
        void OnGetGrayLevel(uint8& grayLevel, uint8 playerLevel);
        void OnGetColorCode(XPColorChar& color, uint8 playerLevel, uint8 mobLevel);
        void OnGetZeroDifference(uint8& diff, uint8 playerLevel);
        void OnGetBaseGain(uint32& gain, uint8 playerLevel, uint8 mobLevel, ContentLevels content);
        void OnGetGain(uint32& gain, Player* player, Unit* unit);
        void OnGetGroupRate(float& rate, uint32 count, bool isRaid);

    public: /* MapScript */

        void OnCreateMap(Map* map);
        void OnDestroyMap(Map* map);
        void OnLoadGridMap(Map* map, uint32 gx, uint32 gy);
        void OnUnloadGridMap(Map* map, uint32 gx, uint32 gy);
        void OnPlayerEnter(Map* map, Player* player);
        void OnPlayerLeave(Map* map, Player* player);
        void OnMapUpdate(Map* map, uint32 diff);

    public: /* InstanceMapScript */

        InstanceData* CreateInstanceData(InstanceMap* map);

    public: /* ItemScript */

        bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target);
        bool OnQuestAccept(Player* player, Item* item, Quest const* quest);
        bool OnItemUse(Player* player, Item* item, SpellCastTargets const& targets);
        bool OnItemExpire(Player* player, ItemPrototype const* proto);

    public: /* CreatureScript */

        bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target);
        bool OnGossipHello(Player* player, Creature* creature);
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action);
        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code);
        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest);
        bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest);
        bool OnQuestComplete(Player* player, Creature* creature, Quest const* quest);
        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt);
        uint32 GetDialogStatus(Player* player, Creature* creature);
        CreatureAI* GetCreatureAI(Creature* creature);
        void OnCreatureUpdate(Creature* creature, uint32 diff);

    public: /* GameObjectScript */

        bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target);
        bool OnGossipHello(Player* player, GameObject* go);
        bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action);
        bool OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code);
        bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest);
        bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt);
        uint32 GetDialogStatus(Player* player, GameObject* go);
        void OnGameObjectDestroyed(Player* player, GameObject* go, uint32 eventId);
        void OnGameObjectUpdate(GameObject* go, uint32 diff);

    public: /* AreaTriggerScript */

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger);

    public: /* BattlegroundScript */

        BattleGround* CreateBattleground(BattleGroundTypeId typeId);

    public: /* OutdoorPvPScript */

        OutdoorPvP* CreateOutdoorPvP(OutdoorPvPData const* data);

    public: /* CommandScript */

        std::vector<ChatCommand*> GetChatCommands();

    public: /* WeatherScript */

        void OnWeatherChange(Weather* weather, WeatherState state, float grade);
        void OnWeatherUpdate(Weather* weather, uint32 diff);

    public: /* AuctionHouseScript */

        void OnAuctionAdd(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnRemoveAuction(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionSuccessful(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionExpire(AuctionHouseObject* ah, AuctionEntry* entry);

    public: /* ConditionScript */

        bool OnConditionCheck(Condition* condition, Player* player, Unit* targetOverride);

    public: /* VehicleScript */

        void OnInstall(Vehicle* veh);
        void OnUninstall(Vehicle* veh);
        void OnDie(Vehicle* veh);
        void OnReset(Vehicle* veh);
        void OnInstallAccessory(Vehicle* veh, Creature* accessory);
        void OnAddPassenger(Vehicle* veh, Unit* passenger, int8 seatId);
        void OnRemovePassenger(Vehicle* veh, Unit* passenger);

    public: /* DynamicObjectScript */

        void OnDynamicObjectUpdate(DynamicObject* dynobj, uint32 diff);

    public: /* TransportScript */

        void OnAddPassenger(Transport* transport, Player* player);
        void OnAddCreaturePassenger(Transport* transport, Creature* creature);
        void OnRemovePassenger(Transport* transport, Player* player);
        void OnTransportUpdate(Transport* transport, uint32 diff);

    public: /* ScriptRegistry */

        // This is the global static registry of scripts.
        template<class TScript> class ScriptRegistry
        {
            // Counter used for code-only scripts.
            static uint32 _scriptIdCounter;

            public:

                typedef std::map<uint32, TScript*> ScriptMap;

                // The actual list of scripts. This will be accessed concurrently, so it must not be modified
                // after server startup.
                static ScriptMap ScriptPointerList;

                // Gets a script by its ID (assigned by ObjectMgr).
                static TScript* GetScriptById(uint32 id)
                {
                    for (ScriptMap::iterator it = ScriptPointerList.begin(); it != ScriptPointerList.end(); ++it)
                        if (it->first == id)
                            return it->second;

                    return NULL;
                }

                // Attempts to add a new script to the list.
                static void AddScript(TScript* const script);
        };
};

#endif

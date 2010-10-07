/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SC_SCRIPTMGR_H
#define SC_SCRIPTMGR_H

#include "Common.h"
#include <ace/Singleton.h>

#include "DBCStores.h"
#include "Player.h"
#include "SharedDefines.h"
#include "World.h"
#include "Weather.h"

class AuctionHouseObject;
class AuraScript;
class Battleground;
class BattlegroundMap;
class Channel;
class ChatCommand;
class Creature;
class CreatureAI;
class DynamicObject;
class GameObject;
class Guild;
class GridMap;
class Group;
class InstanceMap;
class InstanceScript;
class Item;
class Map;
class OutdoorPvP;
class Player;
class Quest;
class ScriptMgr;
class Spell;
class SpellScript;
class SpellCastTargets;
class Transport;
class Unit;
class Vehicle;
class WorldPacket;
class WorldSocket;
class WorldObject;

struct AchievementCriteriaData;
struct AuctionEntry;
struct Condition;
struct ItemPrototype;
struct OutdoorPvPData;

#define VISIBLE_RANGE       (166.0f)                        //MAX visible range (size of grid)
#define DEFAULT_TEXT        "<Trinity Script Text Entry Missing!>"

// Generic scripting text function.
void DoScriptText(int32 textEntry, WorldObject* pSource, Unit *pTarget = NULL);

/*
    TODO: Add more script type classes.

    MailScript
    SessionScript
    CollisionScript
    ArenaTeamScript

*/

/*
    Standard procedure when adding new script type classes:

    First of all, define the actual class, and have it inherit from ScriptObject, like so:

    class MyScriptType : public ScriptObject
    {
        uint32 _someId;

        private:

            void RegisterSelf();

        protected:

            MyScriptType(const char* name, uint32 someId)
                : ScriptObject(name), _someId(someId)
            {
                ScriptMgr::ScriptRegistry<MyScriptType>::AddScript(this);
            }

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

        // Do not override this in scripts; it should be overridden by the various script type classes. It indicates
        // whether or not this script type must be assigned in the database.
        virtual bool IsDatabaseBound() const { return false; }

        const std::string& GetName() const { return _name; }

    protected:

        ScriptObject(const char* name)
            : _name(std::string(name))
        {
        }

        virtual ~ScriptObject()
        {
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

        virtual void OnUpdate(TObject* /*obj*/, uint32 /*diff*/) { }
};

class SpellScriptLoader : public ScriptObject
{
    protected:

        SpellScriptLoader(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid SpellScript pointer.
        virtual SpellScript* GetSpellScript() const { return NULL; };
        // Should return a fully valid AuraScript pointer.
        virtual AuraScript* GetAuraScript() const { return NULL; };
};

class ServerScript : public ScriptObject
{
    protected:

        ServerScript(const char* name);

    public:

        // Called when reactive socket I/O is started (WorldSocketMgr).
        virtual void OnNetworkStart() { }

        // Called when reactive I/O is stopped.
        virtual void OnNetworkStop() { }

        // Called when a remote socket establishes a connection to the server. Do not store the socket object.
        virtual void OnSocketOpen(WorldSocket* /*socket*/) { }

        // Called when a socket is closed. Do not store the socket object, and do not rely on the connection
        // being open; it is not.
        virtual void OnSocketClose(WorldSocket* /*socket*/, bool /*wasNew*/) { }

        // Called when a packet is sent to a client. The packet object is a copy of the original packet, so reading
        // and modifying it is safe.
        virtual void OnPacketSend(WorldSocket* /*socket*/, WorldPacket& /*packet*/) { }

        // Called when a (valid) packet is received by a client. The packet object is a copy of the original packet, so
        // reading and modifying it is safe.
        virtual void OnPacketReceive(WorldSocket* /*socket*/, WorldPacket& /*packet*/) { }

        // Called when an invalid (unknown opcode) packet is received by a client. The packet is a reference to the orignal
        // packet; not a copy. This allows you to actually handle unknown packets (for whatever purpose).
        virtual void OnUnknownPacketReceive(WorldSocket* /*socket*/, WorldPacket& /*packet*/) { }
};

class WorldScript : public ScriptObject, public UpdatableScript<void>
{
    protected:

        WorldScript(const char* name);

    public:

        // Called when the open/closed state of the world changes.
        virtual void OnOpenStateChange(bool /*open*/) { }

        // Called after the world configuration is (re)loaded.
        virtual void OnConfigLoad(bool /*reload*/) { }

        // Called before the message of the day is changed.
        virtual void OnMotdChange(std::string& /*newMotd*/) { }

        // Called when a world shutdown is initiated.
        virtual void OnShutdownInitiate(ShutdownExitCode /*code*/, ShutdownMask /*mask*/) { }

        // Called when a world shutdown is cancelled.
        virtual void OnShutdownCancel() { }

        // Called on every world tick (don't execute too heavy code here).
        virtual void OnUpdate(void* /*null*/, uint32 /*diff*/) { }

        // Called when the world is started.
        virtual void OnStartup() { }

        // Called when the world is actually shut down.
        virtual void OnShutdown() { }
};

class FormulaScript : public ScriptObject
{
    protected:

        FormulaScript(const char* name);

    public:

        // Called after calculating honor.
        virtual void OnHonorCalculation(float& /*honor*/, uint8 /*level*/, uint32 /*count*/) { }

        // Called after calculating honor.
        virtual void OnHonorCalculation(uint32& /*honor*/, uint8 /*level*/, uint32 /*count*/) { }

        // Called after gray level calculation.
        virtual void OnGrayLevelCalculation(uint8& /*grayLevel*/, uint8 /*playerLevel*/) { }

        // Called after calculating experience color.
        virtual void OnColorCodeCalculation(XPColorChar& /*color*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/) { }

        // Called after calculating zero difference.
        virtual void OnZeroDifferenceCalculation(uint8& /*diff*/, uint8 /*playerLevel*/) { }

        // Called after calculating base experience gain.
        virtual void OnBaseGainCalculation(uint32& /*gain*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/, ContentLevels /*content*/) { }

        // Called after calculating experience gain.
        virtual void OnGainCalculation(uint32& /*gain*/, Player* /*player*/, Unit* /*unit*/) { }

        // Called when calculating the experience rate for group experience.
        virtual void OnGroupRateCalculation(float& /*rate*/, uint32 /*count*/, bool /*isRaid*/) { }
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
        virtual void OnCreate(TMap* /*map*/) { }

        // Called just before the map is destroyed.
        virtual void OnDestroy(TMap* /*map*/) { }

        // Called when a grid map is loaded.
        virtual void OnLoadGridMap(TMap* /*map*/, GridMap* /*gmap*/, uint32 /*gx*/, uint32 /*gy*/) { }

        // Called when a grid map is unloaded.
        virtual void OnUnloadGridMap(TMap* /*map*/, GridMap* /*gmap*/, uint32 /*gx*/, uint32 /*gy*/)  { }

        // Called when a player enters the map.
        virtual void OnPlayerEnter(TMap* /*map*/, Player* /*player*/) { }

        // Called when a player leaves the map.
        virtual void OnPlayerLeave(TMap* /*map*/, Player* /*player*/) { }

        // Called on every map update tick.
        virtual void OnUpdate(TMap* /*map*/, uint32 /*diff*/) { }
};

class WorldMapScript : public ScriptObject, public MapScript<Map>
{
    protected:

        WorldMapScript(const char* name, uint32 mapId);
};

class InstanceMapScript : public ScriptObject, public MapScript<InstanceMap>
{
    protected:

        InstanceMapScript(const char* name, uint32 mapId);

    public:

        bool IsDatabaseBound() const { return true; }

        // Gets an InstanceScript object for this instance.
        virtual InstanceScript* GetInstanceScript(InstanceMap* /*map*/) const { return NULL; }
};

class BattlegroundMapScript : public ScriptObject, public MapScript<BattlegroundMap>
{
    protected:

        BattlegroundMapScript(const char* name, uint32 mapId);
};

class ItemScript : public ScriptObject
{
    protected:

        ItemScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a dummy spell effect is triggered on the item.
        virtual bool OnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/, Item* /*target*/) { return false; }

        // Called when a player accepts a quest from the item.
        virtual bool OnQuestAccept(Player* /*player*/, Item* /*item*/, Quest const* /*quest*/) { return false; }

        // Called when a player uses the item.
        virtual bool OnUse(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/) { return false; }

        // Called when the item expires (is destroyed).
        virtual bool OnExpire(Player* /*player*/, ItemPrototype const* /*proto*/) { return false; }
};

class CreatureScript : public ScriptObject, public UpdatableScript<Creature>
{
    protected:

        CreatureScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a dummy spell effect is triggered on the creature.
        virtual bool OnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/, Creature* /*target*/) { return false; }

        // Called when a player opens a gossip dialog with the creature.
        virtual bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) { return false; }

        // Called when a player selects a gossip item in the creature's gossip menu.
        virtual bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) { return false; }

        // Called when a player selects a gossip with a code in the creature's gossip menu.
        virtual bool OnGossipSelectCode(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/) { return false; }

        // Called when a player accepts a quest from the creature.
        virtual bool OnQuestAccept(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/) { return false; }

        // Called when a player selects a quest in the creature's quest menu.
        virtual bool OnQuestSelect(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/) { return false; }

        // Called when a player completes a quest with the creature.
        virtual bool OnQuestComplete(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/) { return false; }

        // Called when a player selects a quest reward.
        virtual bool OnQuestReward(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/, uint32 /*opt*/) { return false; }

        // Called when the dialog status between a player and the creature is requested.
        virtual uint32 GetDialogStatus(Player* /*player*/, Creature* /*creature*/) { return 100; }

        // Called when a CreatureAI object is needed for the creature.
        virtual CreatureAI* GetAI(Creature* /*creature*/) const { return NULL; }
};

class GameObjectScript : public ScriptObject, public UpdatableScript<GameObject>
{
    protected:

        GameObjectScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a dummy spell effect is triggered on the gameobject.
        virtual bool OnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/, GameObject* /*target*/) { return false; }

        // Called when a player opens a gossip dialog with the gameobject.
        virtual bool OnGossipHello(Player* /*player*/, GameObject* /*go*/) { return false; }

        // Called when a player selects a gossip item in the gameobject's gossip menu.
        virtual bool OnGossipSelect(Player* /*player*/, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/) { return false; }

        // Called when a player selects a gossip with a code in the gameobject's gossip menu.
        virtual bool OnGossipSelectCode(Player* /*player*/, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/) { return false; }

        // Called when a player accepts a quest from the gameobject.
        virtual bool OnQuestAccept(Player* /*player*/, GameObject* /*go*/, Quest const* /*quest*/) { return false; }

        // Called when a player selects a quest reward.
        virtual bool OnQuestReward(Player* /*player*/, GameObject* /*go*/, Quest const* /*quest*/, uint32 /*opt*/) { return false; }

        // Called when the dialog status between a player and the gameobject is requested.
        virtual uint32 GetDialogStatus(Player* /*player*/, GameObject* /*go*/) { return 100; }

        // Called when the gameobject is destroyed (destructible buildings only).
        virtual void OnDestroyed(Player* /*player*/, GameObject* /*go*/, uint32 /*eventId*/) { }
};

class AreaTriggerScript : public ScriptObject
{
    protected:

        AreaTriggerScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when the area trigger is activated by a player.
        virtual bool OnTrigger(Player* /*player*/, AreaTriggerEntry const* /*trigger*/) { return false; }
};

class BattlegroundScript : public ScriptObject
{
    protected:

        BattlegroundScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid Battleground object for the type ID.
        virtual Battleground* GetBattleground() const = 0;
};

class OutdoorPvPScript : public ScriptObject
{
    protected:

        OutdoorPvPScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Should return a fully valid OutdoorPvP object for the type ID.
        virtual OutdoorPvP* GetOutdoorPvP() const = 0;
};

class CommandScript : public ScriptObject
{
    protected:

        CommandScript(const char* name);

    public:

        // Should return a pointer to a valid command table (ChatCommand array) to be used by ChatHandler.
        virtual ChatCommand* GetCommands() const = 0;
};

class WeatherScript : public ScriptObject, public UpdatableScript<Weather>
{
    protected:

        WeatherScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when the weather changes in the zone this script is associated with.
        virtual void OnChange(Weather* /*weather*/, WeatherState /*state*/, float /*grade*/) { }
};

class AuctionHouseScript : public ScriptObject
{
    protected:

        AuctionHouseScript(const char* name);

    public:

        // Called when an auction is added to an auction house.
        virtual void OnAuctionAdd(AuctionHouseObject* /*ah*/, AuctionEntry* /*entry*/) { }

        // Called when an auction is removed from an auction house.
        virtual void OnAuctionRemove(AuctionHouseObject* /*ah*/, AuctionEntry* /*entry*/) { }

        // Called when an auction was succesfully completed.
        virtual void OnAuctionSuccessful(AuctionHouseObject* /*ah*/, AuctionEntry* /*entry*/) { }

        // Called when an auction expires.
        virtual void OnAuctionExpire(AuctionHouseObject* /*ah*/, AuctionEntry* /*entry*/) { }
};

class ConditionScript : public ScriptObject
{
    protected:

        ConditionScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a single condition is checked for a player.
        virtual bool OnConditionCheck(Condition* /*condition*/, Player* /*player*/, Unit* /*invoker*/) { return true; }
};

class VehicleScript : public ScriptObject
{
    protected:

        VehicleScript(const char* name);

    public:

        // Called after a vehicle is installed.
        virtual void OnInstall(Vehicle* /*veh*/) { }

        // Called after a vehicle is uninstalled.
        virtual void OnUninstall(Vehicle* /*veh*/) { }

        // Called after a vehicle dies.
        virtual void OnDie(Vehicle* /*veh*/) { }

        // Called when a vehicle resets.
        virtual void OnReset(Vehicle* /*veh*/) { }

        // Called after an accessory is installed in a vehicle.
        virtual void OnInstallAccessory(Vehicle* /*veh*/, Creature* /*accessory*/) { }

        // Called after a passenger is added to a vehicle.
        virtual void OnAddPassenger(Vehicle* /*veh*/, Unit* /*passenger*/, int8 /*seatId*/) { }

        // Called after a passenger is removed from a vehicle.
        virtual void OnRemovePassenger(Vehicle* /*veh*/, Unit* /*passenger*/) { }
};

class DynamicObjectScript : public ScriptObject, public UpdatableScript<DynamicObject>
{
    protected:

        DynamicObjectScript(const char* name);
};

class TransportScript : public ScriptObject, public UpdatableScript<Transport>
{
    protected:

        TransportScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when a player boards the transport.
        virtual void OnAddPassenger(Transport* /*transport*/, Player* /*player*/) { }

        // Called when a creature boards the transport.
        virtual void OnAddCreaturePassenger(Transport* /*transport*/, Creature* /*creature*/) { }

        // Called when a player exits the transport.
        virtual void OnRemovePassenger(Transport* /*transport*/, Player* /*player*/) { }

        // Called when a transport moves.
        virtual void OnRelocate(Transport* /*transport*/, uint32 /*waypointId*/, uint32 /*mapId*/, float /*x*/, float /*y*/, float /*z*/) { }
};

class AchievementCriteriaScript : public ScriptObject
{
    protected:

        AchievementCriteriaScript(const char* name);

    public:

        bool IsDatabaseBound() const { return true; }

        // Called when an additional criteria is checked.
        virtual bool OnCheck(Player* source, Unit* target) = 0;
};

class PlayerScript : public ScriptObject
{
    protected:

        PlayerScript(const char* name);

    public:

        // Called when a player kills another player
        virtual void OnPVPKill(Player* /*killer*/, Player* /*killed*/) { }

        // Called when a player kills a creature
        virtual void OnCreatureKill(Player* /*killer*/, Creature* /*killed*/) { }

        // Called when a player is killed by a creature
        virtual void OnPlayerKilledByCreature(Creature* /*killer*/, Player* /*killed*/) { }

        // Called when a player's level changes (right before the level is applied)
        virtual void OnLevelChanged(Player* /*player*/, uint8 /*newLevel*/) { }

        // Called when a player's free talent points change (right before the change is applied)
        virtual void OnFreeTalentPointsChanged(Player* /*player*/, uint32 /*points*/) { }

        // Called when a player's talent points are reset (right before the reset is done)
        virtual void OnTalentsReset(Player* /*player*/, bool /*no_cost*/) { }

        // Called when a player's money is modified (before the modification is done)
        virtual void OnMoneyChanged(Player* /*player*/, int32& /*amount*/) { }

        // Called when a player gains XP (before anything is given)
        virtual void OnGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/) { }

        // Called when a player's reputation changes (before it is actually changed)
        virtual void OnReputationChange(Player* /*player*/, uint32 /*factionID*/, int32& /*standing*/, bool /*incremental*/) { }

        // Called when a duel is requested
        virtual void OnDuelRequest(Player* /*target*/, Player* /*challenger*/) { }

        // Called when a duel starts (after 3s countdown)
        virtual void OnDuelStart(Player* /*player1*/, Player* /*player2*/) { }

        // Called when a duel ends
        virtual void OnDuelEnd(Player* /*winner*/, Player* /*looser*/, DuelCompleteType /*type*/) { }

        // The following methods are called when a player sends a chat message
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string /*msg*/) { }
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string /*msg*/, Player* /*receiver*/) { }
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string /*msg*/, Group* /*group*/) { }
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string /*msg*/, Guild* /*guild*/) { }
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string /*msg*/, Channel* /*channel*/) { }

        // Both of the below are called on emote opcodes
        virtual void OnEmote(Player* /*player*/, uint32 /*emote*/) { }
        virtual void OnTextEmote(Player* /*player*/, uint32 /*text_emote*/, uint32 /*emoteNum*/, uint64 /*guid*/) { }

        // Called in Spell::cast
        virtual void OnSpellCast(Player* /*player*/, Spell * /*spell*/, bool /*skipCheck*/) { }

        // Called when a player logs in or out
        virtual void OnLogin(Player* /*player*/) { }
        virtual void OnLogout(Player* /*player*/) { }

        // Called when a player is created/deleted
        virtual void OnCreate(Player* /*player*/) { }
        virtual void OnDelete(uint64 /*guid*/) { }
};

class GuildScript : public ScriptObject
{
    protected:

        GuildScript(const char* name);

    public:

        bool IsDatabaseBound() const { return false; }

        virtual void OnAddMember(Guild* /*guild*/, Player* /*player*/, uint32& /*plRank*/) { }
        virtual void OnRemoveMember(Guild* /*guild*/, Player* /*player*/, bool /*isDisbanding*/, bool /*isKicked*/) { }
        virtual void OnMOTDChanged(Guild* /*guild*/, std::string /*newMotd*/) { }
        virtual void OnGInfoChanged(Guild* /*guild*/, std::string /*newGInfo*/) { }
        virtual void OnDisband(Guild* /*guild*/) { }
};

class GroupScript : public ScriptObject
{
protected:
    GroupScript(const char* name);

public:
    bool IsDatabaseBound() const { return false; }

    virtual void OnAddMember(Group* /*group*/, uint64 /*guid*/) { }
    virtual void OnInviteMember(Group* /*group*/, uint64 /*guid*/) { }
    virtual void OnRemoveMember(Group* /*group*/, uint64 /*guid*/, RemoveMethod& /*method*/) { }
    virtual void OnChangeLeader(Group* /*group*/, uint64 /*newLeaderGuid*/, uint64 /*oldLeaderGuid*/) { }
    virtual void OnDisband(Group* /*group*/) { }
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

    public: /* Initialization */

        void Initialize();
        void LoadDatabase();
        void FillSpellSummary();

        const char* ScriptsVersion() const { return "Integrated Trinity Scripts"; }

        void IncrementScriptCount() { ++_scriptCount; }
        uint32 GetScriptCount() const { return _scriptCount; }

    public: /* SpellScriptLoader */

        void CreateSpellScripts(uint32 spell_id, std::list<SpellScript*>& script_vector);
        void CreateAuraScripts(uint32 spell_id, std::list<AuraScript*>& script_vector);
        void CreateSpellScriptLoaders(uint32 spell_id, std::vector<std::pair<SpellScriptLoader*, std::multimap<uint32, uint32>::iterator> >& script_vector);

    public: /* ServerScript */

        void OnNetworkStart();
        void OnNetworkStop();
        void OnSocketOpen(WorldSocket* socket);
        void OnSocketClose(WorldSocket* socket, bool wasNew);
        void OnPacketReceive(WorldSocket* socket, WorldPacket packet);
        void OnPacketSend(WorldSocket* socket, WorldPacket packet);
        void OnUnknownPacketReceive(WorldSocket* socket, WorldPacket packet);

    public: /* WorldScript */

        void OnOpenStateChange(bool open);
        void OnConfigLoad(bool reload);
        void OnMotdChange(std::string& newMotd);
        void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask);
        void OnShutdownCancel();
        void OnWorldUpdate(uint32 diff);
        void OnStartup();
        void OnShutdown();

    public: /* FormulaScript */

        void OnHonorCalculation(float& honor, uint8 level, uint32 count);
        void OnHonorCalculation(uint32& honor, uint8 level, uint32 count);
        void OnGrayLevelCalculation(uint8& grayLevel, uint8 playerLevel);
        void OnColorCodeCalculation(XPColorChar& color, uint8 playerLevel, uint8 mobLevel);
        void OnZeroDifferenceCalculation(uint8& diff, uint8 playerLevel);
        void OnBaseGainCalculation(uint32& gain, uint8 playerLevel, uint8 mobLevel, ContentLevels content);
        void OnGainCalculation(uint32& gain, Player* player, Unit* unit);
        void OnGroupRateCalculation(float& rate, uint32 count, bool isRaid);

    public: /* MapScript */

        void OnCreateMap(Map* map);
        void OnDestroyMap(Map* map);
        void OnLoadGridMap(Map* map, GridMap* gmap, uint32 gx, uint32 gy);
        void OnUnloadGridMap(Map* map, GridMap* gmap, uint32 gx, uint32 gy);
        void OnPlayerEnterMap(Map* map, Player* player);
        void OnPlayerLeaveMap(Map* map, Player* player);
        void OnMapUpdate(Map* map, uint32 diff);

    public: /* InstanceMapScript */

        InstanceScript* CreateInstanceData(InstanceMap* map);

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

        bool OnAreaTrigger(Player* player, AreaTriggerEntry const* trigger);

    public: /* BattlegroundScript */

        Battleground* CreateBattleground(BattlegroundTypeId typeId);

    public: /* OutdoorPvPScript */

        OutdoorPvP* CreateOutdoorPvP(OutdoorPvPData const* data);

    public: /* CommandScript */

        std::vector<ChatCommand*> GetChatCommands();

    public: /* WeatherScript */

        void OnWeatherChange(Weather* weather, WeatherState state, float grade);
        void OnWeatherUpdate(Weather* weather, uint32 diff);

    public: /* AuctionHouseScript */

        void OnAuctionAdd(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionRemove(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionSuccessful(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionExpire(AuctionHouseObject* ah, AuctionEntry* entry);

    public: /* ConditionScript */

        bool OnConditionCheck(Condition* condition, Player* player, Unit* invoker);

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
        void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z);

    public: /* AchievementCriteriaScript */

        bool OnCriteriaCheck(AchievementCriteriaData const* data, Player* source, Unit* target);

    public: /* PlayerScript */

        void OnPVPKill(Player *killer, Player *killed);
        void OnCreatureKill(Player *killer, Creature *killed);
        void OnPlayerKilledByCreature(Creature *killer, Player *killed);
        void OnPlayerLevelChanged(Player *player, uint8 newLevel);
        void OnPlayerFreeTalentPointsChanged(Player *player, uint32 newPoints);
        void OnPlayerTalentsReset(Player *player, bool no_cost);
        void OnPlayerMoneyChanged(Player *player, int32& amount);
        void OnGivePlayerXP(Player *player, uint32& amount, Unit *victim);
        void OnPlayerReputationChange(Player *player, uint32 factionID, int32& standing, bool incremental);
        void OnPlayerDuelRequest(Player* target, Player* challenger);
        void OnPlayerDuelStart(Player* player1, Player* player2);
        void OnPlayerDuelEnd(Player* winner, Player* looser, DuelCompleteType type);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string msg);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string msg, Player* receiver);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string msg, Group* group);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string msg, Guild* guild);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string msg, Channel* channel);
        void OnPlayerEmote(Player* player, uint32 emote);
        void OnPlayerTextEmote(Player* player, uint32 text_emote, uint32 emoteNum, uint64 guid);
        void OnPlayerSpellCast(Player* player, Spell *spell, bool skipCheck);
        void OnPlayerLogin(Player* player);
        void OnPlayerLogout(Player* player);
        void OnPlayerCreate(Player* player);
        void OnPlayerDelete(uint64 guid);

    public: /* GuildScript */
        void OnGuildAddMember(Guild *guild, Player *player, uint32& plRank);
        void OnGuildRemoveMember(Guild *guild, Player *player, bool isDisbanding, bool isKicked);
        void OnGuildMOTDChanged(Guild *guild, std::string newMotd);
        void OnGuildInfoChanged(Guild *guild, std::string newGInfo);
        void OnGuildDisband(Guild *guild);

    public: /* GroupScript */
        void OnGroupAddMember(Group* group, uint64 guid);
        void OnGroupInviteMember(Group* group, uint64 guid);
        void OnGroupRemoveMember(Group* group, uint64 guid, RemoveMethod method);
        void OnGroupChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid);
        void OnGroupDisband(Group* group);

    public: /* ScriptRegistry */

        // This is the global static registry of scripts.
        template<class TScript>
        class ScriptRegistry
        {
            // Counter used for code-only scripts.
            static uint32 _scriptIdCounter;

            public:

                typedef std::map<uint32, TScript*> ScriptMap;
                typedef typename ScriptMap::iterator ScriptMapIterator;

                // The actual list of scripts. This will be accessed concurrently, so it must not be modified
                // after server startup.
                static ScriptMap ScriptPointerList;

                static void AddScript(TScript* const script)
                {
                    ASSERT(script);

                    // See if the script is using the same memory as another script. If this happens, it means that
                    // someone forgot to allocate new memory for a script.
                    for (ScriptMapIterator it = ScriptPointerList.begin(); it != ScriptPointerList.end(); ++it)
                    {
                        if (it->second == script)
                        {
                            sLog.outError("Script '%s' has same memory pointer as '%s'.",
                                script->GetName().c_str(), it->second->GetName().c_str());

                            return;
                        }
                    }

                    if (script->IsDatabaseBound())
                    {
                        // Get an ID for the script. An ID only exists if it's a script that is assigned in the database
                        // through a script name (or similar).
                        uint32 id = GetScriptId(script->GetName().c_str());
                        if (id)
                        {
                            // Try to find an existing script.
                            bool existing = false;
                            for (ScriptMapIterator it = ScriptPointerList.begin(); it != ScriptPointerList.end(); ++it)
                            {
                                // If the script names match...
                                if (it->second->GetName() == script->GetName())
                                {
                                    // ... It exists.
                                    existing = true;
                                    break;
                                }
                            }

                            // If the script isn't assigned -> assign it!
                            if (!existing)
                            {
                                ScriptPointerList[id] = script;
                                sScriptMgr.IncrementScriptCount();
                            }
                            else
                            {
                                // If the script is already assigned -> delete it!
                                sLog.outError("Script '%s' already assigned with the same script name, so the script can't work.",
                                    script->GetName().c_str());

                                ASSERT(false); // Error that should be fixed ASAP.
                            }
                        }
                        else
                        {
                            // The script uses a script name from database, but isn't assigned to anything.
                            if (script->GetName().find("example") == std::string::npos)
                                sLog.outErrorDb("Script named '%s' does not have a script name assigned in database.",
                                    script->GetName().c_str());
                        }
                    }
                    else
                    {
                        // We're dealing with a code-only script; just add it.
                        ScriptPointerList[_scriptIdCounter++] = script;
                        sScriptMgr.IncrementScriptCount();
                    }
                }

                // Gets a script by its ID (assigned by ObjectMgr).
                static TScript* GetScriptById(uint32 id)
                {
                    ScriptMapIterator it = ScriptPointerList.find(id);
                    if (it != ScriptPointerList.end())
                        return it->second;

                    return NULL;
                }
        };
};

#endif

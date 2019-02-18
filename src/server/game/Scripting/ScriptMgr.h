/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ObjectGuid.h"
#include <vector>

class AccountMgr;
class AreaTrigger;
class AreaTriggerAI;
class AuctionHouseObject;
class Aura;
class AuraScript;
class Battleground;
class BattlegroundMap;
class Channel;
class ChatCommand;
class Conversation;
class Creature;
class CreatureAI;
class DynamicObject;
class GameObject;
class GameObjectAI;
class Guild;
class GridMap;
class Group;
class InstanceMap;
class InstanceScript;
class Item;
class Map;
class ModuleReference;
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
class Weather;
class WorldPacket;
class WorldSocket;
class WorldObject;
class WorldSession;

struct AreaTriggerEntry;
struct AuctionEntry;
struct ConditionSourceInfo;
struct Condition;
struct CreatureTemplate;
struct CreatureData;
struct ItemTemplate;
struct MapEntry;
struct OutdoorPvPData;
struct QuestObjective;
struct SceneTemplate;

enum BattlegroundTypeId : uint32;
enum Difficulty : uint8;
enum DuelCompleteType : uint8;
enum QuestStatus : uint8;
enum RemoveMethod : uint8;
enum ShutdownExitCode : uint32;
enum ShutdownMask : uint32;
enum SpellEffIndex : uint8;
enum WeatherState : uint32;
enum XPColorChar : uint8;

#define VISIBLE_RANGE       166.0f                          //MAX visible range (size of grid)


/*
    @todo Add more script type classes.

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
                ScriptRegistry<MyScriptType>::AddScript(this);
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

    template class ScriptRegistry<MyScriptType>;

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

class TC_GAME_API ScriptObject
{
    friend class ScriptMgr;

    public:

        const std::string& GetName() const { return _name; }

    protected:

        ScriptObject(const char* name);
        virtual ~ScriptObject();

    private:

        const std::string _name;
};

template<class TObject> class UpdatableScript
{
    protected:

        UpdatableScript()
        {
        }

        virtual ~UpdatableScript() { }

    public:

        virtual void OnUpdate(TObject* /*obj*/, uint32 /*diff*/) { }
};

class TC_GAME_API SpellScriptLoader : public ScriptObject
{
    protected:

        SpellScriptLoader(const char* name);

    public:

        // Should return a fully valid SpellScript pointer.
        virtual SpellScript* GetSpellScript() const { return nullptr; }

        // Should return a fully valid AuraScript pointer.
        virtual AuraScript* GetAuraScript() const { return nullptr; }
};

class TC_GAME_API ServerScript : public ScriptObject
{
    protected:

        ServerScript(const char* name);

    public:

        // Called when reactive socket I/O is started (WorldTcpSessionMgr).
        virtual void OnNetworkStart() { }

        // Called when reactive I/O is stopped.
        virtual void OnNetworkStop() { }

        // Called when a remote socket establishes a connection to the server. Do not store the socket object.
        virtual void OnSocketOpen(std::shared_ptr<WorldSocket> /*socket*/) { }

        // Called when a socket is closed. Do not store the socket object, and do not rely on the connection
        // being open; it is not.
        virtual void OnSocketClose(std::shared_ptr<WorldSocket> /*socket*/) { }

        // Called when a packet is sent to a client. The packet object is a copy of the original packet, so reading
        // and modifying it is safe.
        virtual void OnPacketSend(WorldSession* /*session*/, WorldPacket& /*packet*/) { }

        // Called when a (valid) packet is received by a client. The packet object is a copy of the original packet, so
        // reading and modifying it is safe. Make sure to check WorldSession pointer before usage, it might be null in case of auth packets
        virtual void OnPacketReceive(WorldSession* /*session*/, WorldPacket& /*packet*/) { }
};

class TC_GAME_API WorldScript : public ScriptObject
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
        virtual void OnUpdate(uint32 /*diff*/) { }

        // Called when the world is started.
        virtual void OnStartup() { }

        // Called when the world is actually shut down.
        virtual void OnShutdown() { }
};

class TC_GAME_API FormulaScript : public ScriptObject
{
    protected:

        FormulaScript(const char* name);

    public:

        // Called after calculating honor.
        virtual void OnHonorCalculation(float& /*honor*/, uint8 /*level*/, float /*multiplier*/) { }

        // Called after gray level calculation.
        virtual void OnGrayLevelCalculation(uint8& /*grayLevel*/, uint8 /*playerLevel*/) { }

        // Called after calculating experience color.
        virtual void OnColorCodeCalculation(XPColorChar& /*color*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/) { }

        // Called after calculating zero difference.
        virtual void OnZeroDifferenceCalculation(uint8& /*diff*/, uint8 /*playerLevel*/) { }

        // Called after calculating base experience gain.
        virtual void OnBaseGainCalculation(uint32& /*gain*/, uint8 /*playerLevel*/, uint8 /*mobLevel*/) { }

        // Called after calculating experience gain.
        virtual void OnGainCalculation(uint32& /*gain*/, Player* /*player*/, Unit* /*unit*/) { }

        // Called when calculating the experience rate for group experience.
        virtual void OnGroupRateCalculation(float& /*rate*/, uint32 /*count*/, bool /*isRaid*/) { }
};

template<class TMap>
class MapScript : public UpdatableScript<TMap>
{
    MapEntry const* _mapEntry;

    protected:

        MapScript(MapEntry const* mapEntry) : _mapEntry(mapEntry) { }

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
};

class TC_GAME_API WorldMapScript : public ScriptObject, public MapScript<Map>
{
    protected:

        WorldMapScript(const char* name, uint32 mapId);
};

class TC_GAME_API InstanceMapScript
    : public ScriptObject, public MapScript<InstanceMap>
{
    protected:

        InstanceMapScript(const char* name, uint32 mapId);

    public:

        // Gets an InstanceScript object for this instance.
        virtual InstanceScript* GetInstanceScript(InstanceMap* /*map*/) const { return NULL; }
};

class TC_GAME_API BattlegroundMapScript : public ScriptObject, public MapScript<BattlegroundMap>
{
    protected:

        BattlegroundMapScript(const char* name, uint32 mapId);
};

class TC_GAME_API ItemScript : public ScriptObject
{
    protected:

        ItemScript(const char* name);

    public:

        // Called when a dummy spell effect is triggered on the item.
        virtual bool OnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/, Item* /*target*/) { return false; }

        // Called when a player accepts a quest from the item.
        virtual bool OnQuestAccept(Player* /*player*/, Item* /*item*/, Quest const* /*quest*/) { return false; }

        // Called when a player uses the item.
        virtual bool OnUse(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) { return false; }

        // Called when the item expires (is destroyed).
        virtual bool OnExpire(Player* /*player*/, ItemTemplate const* /*proto*/) { return false; }

        // Called when the item is destroyed.
        virtual bool OnRemove(Player* /*player*/, Item* /*item*/) { return false; }
};

class TC_GAME_API UnitScript : public ScriptObject
{
    protected:

        UnitScript(const char* name, bool addToScripts = true);

    public:
        // Called when a unit deals healing to another unit
        virtual void OnHeal(Unit* /*healer*/, Unit* /*reciever*/, uint32& /*gain*/) { }

        // Called when a unit deals damage to another unit
        virtual void OnDamage(Unit* /*attacker*/, Unit* /*victim*/, uint32& /*damage*/) { }

        // Called when DoT's Tick Damage is being Dealt
        virtual void ModifyPeriodicDamageAurasTick(Unit* /*target*/, Unit* /*attacker*/, uint32& /*damage*/) { }

        // Called when Melee Damage is being Dealt
        virtual void ModifyMeleeDamage(Unit* /*target*/, Unit* /*attacker*/, uint32& /*damage*/) { }

        // Called when Spell Damage is being Dealt
        virtual void ModifySpellDamageTaken(Unit* /*target*/, Unit* /*attacker*/, int32& /*damage*/) { }
};

class TC_GAME_API CreatureScript : public UnitScript, public UpdatableScript<Creature>
{
    protected:

        CreatureScript(const char* name);

    public:

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

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        virtual bool OnQuestReward(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/, uint32 /*opt*/) { return false; }

        // Called when the dialog status between a player and the creature is requested.
        virtual uint32 GetDialogStatus(Player* /*player*/, Creature* /*creature*/);

        // Called when the creature tries to spawn. Return false to block spawn and re-evaluate on next tick.
        virtual bool CanSpawn(ObjectGuid::LowType /*spawnId*/, uint32 /*entry*/, CreatureTemplate const* /*baseTemplate*/, CreatureTemplate const* /*actTemplate*/, CreatureData const* /*cData*/, Map const* /*map*/) const { return true; }

        // Called when a CreatureAI object is needed for the creature.
        virtual CreatureAI* GetAI(Creature* /*creature*/) const { return NULL; }
};

class TC_GAME_API GameObjectScript : public ScriptObject, public UpdatableScript<GameObject>
{
    protected:

        GameObjectScript(const char* name);

    public:

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

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        virtual bool OnQuestReward(Player* /*player*/, GameObject* /*go*/, Quest const* /*quest*/, uint32 /*opt*/) { return false; }

        // Called when the dialog status between a player and the gameobject is requested.
        virtual uint32 GetDialogStatus(Player* /*player*/, GameObject* /*go*/);

        // Called when the game object is destroyed (destructible buildings only).
        virtual void OnDestroyed(GameObject* /*go*/, Player* /*player*/) { }

        // Called when the game object is damaged (destructible buildings only).
        virtual void OnDamaged(GameObject* /*go*/, Player* /*player*/) { }

        // Called when the game object loot state is changed.
        virtual void OnLootStateChanged(GameObject* /*go*/, uint32 /*state*/, Unit* /*unit*/) { }

        // Called when the game object state is changed.
        virtual void OnGameObjectStateChanged(GameObject* /*go*/, uint32 /*state*/) { }

        // Called when a GameObjectAI object is needed for the gameobject.
        virtual GameObjectAI* GetAI(GameObject* /*go*/) const { return NULL; }
};

class TC_GAME_API AreaTriggerScript : public ScriptObject
{
    protected:

        AreaTriggerScript(const char* name);

    public:

        // Called when the area trigger is activated by a player.
        virtual bool OnTrigger(Player* /*player*/, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) { return false; }
};

class TC_GAME_API BattlegroundScript : public ScriptObject
{
    protected:

        BattlegroundScript(const char* name);

    public:

        // Should return a fully valid Battleground object for the type ID.
        virtual Battleground* GetBattleground() const = 0;
};

class TC_GAME_API OutdoorPvPScript : public ScriptObject
{
    protected:

        OutdoorPvPScript(const char* name);

    public:

        // Should return a fully valid OutdoorPvP object for the type ID.
        virtual OutdoorPvP* GetOutdoorPvP() const = 0;
};

class TC_GAME_API CommandScript : public ScriptObject
{
    protected:

        CommandScript(const char* name);

    public:

        // Should return a pointer to a valid command table (ChatCommand array) to be used by ChatHandler.
        virtual std::vector<ChatCommand> GetCommands() const = 0;
};

class TC_GAME_API WeatherScript : public ScriptObject, public UpdatableScript<Weather>
{
    protected:

        WeatherScript(const char* name);

    public:

        // Called when the weather changes in the zone this script is associated with.
        virtual void OnChange(Weather* /*weather*/, WeatherState /*state*/, float /*grade*/) { }
};

class TC_GAME_API AuctionHouseScript : public ScriptObject
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

class TC_GAME_API ConditionScript : public ScriptObject
{
    protected:

        ConditionScript(const char* name);

    public:

        // Called when a single condition is checked for a player.
        virtual bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/) { return true; }
};

class TC_GAME_API VehicleScript : public ScriptObject
{
    protected:

        VehicleScript(const char* name);

    public:

        // Called after a vehicle is installed.
        virtual void OnInstall(Vehicle* /*veh*/) { }

        // Called after a vehicle is uninstalled.
        virtual void OnUninstall(Vehicle* /*veh*/) { }

        // Called when a vehicle resets.
        virtual void OnReset(Vehicle* /*veh*/) { }

        // Called after an accessory is installed in a vehicle.
        virtual void OnInstallAccessory(Vehicle* /*veh*/, Creature* /*accessory*/) { }

        // Called after a passenger is added to a vehicle.
        virtual void OnAddPassenger(Vehicle* /*veh*/, Unit* /*passenger*/, int8 /*seatId*/) { }

        // Called after a passenger is removed from a vehicle.
        virtual void OnRemovePassenger(Vehicle* /*veh*/, Unit* /*passenger*/) { }
};

class TC_GAME_API DynamicObjectScript : public ScriptObject, public UpdatableScript<DynamicObject>
{
    protected:

        DynamicObjectScript(const char* name);
};

class TC_GAME_API TransportScript : public ScriptObject, public UpdatableScript<Transport>
{
    protected:

        TransportScript(const char* name);

    public:

        // Called when a player boards the transport.
        virtual void OnAddPassenger(Transport* /*transport*/, Player* /*player*/) { }

        // Called when a creature boards the transport.
        virtual void OnAddCreaturePassenger(Transport* /*transport*/, Creature* /*creature*/) { }

        // Called when a player exits the transport.
        virtual void OnRemovePassenger(Transport* /*transport*/, Player* /*player*/) { }

        // Called when a transport moves.
        virtual void OnRelocate(Transport* /*transport*/, uint32 /*waypointId*/, uint32 /*mapId*/, float /*x*/, float /*y*/, float /*z*/) { }
};

class TC_GAME_API AchievementCriteriaScript : public ScriptObject
{
    protected:

        AchievementCriteriaScript(const char* name);

    public:

        // Called when an additional criteria is checked.
        virtual bool OnCheck(Player* source, Unit* target) = 0;
};

class TC_GAME_API PlayerScript : public UnitScript
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

        // Called when a player's level changes (after the level is applied)
        virtual void OnLevelChanged(Player* /*player*/, uint8 /*oldLevel*/) { }

        // Called when a player's free talent points change (right before the change is applied)
        virtual void OnFreeTalentPointsChanged(Player* /*player*/, uint32 /*points*/) { }

        // Called when a player's talent points are reset (right before the reset is done)
        virtual void OnTalentsReset(Player* /*player*/, bool /*noCost*/) { }

        // Called when a player's money is modified (before the modification is done)
        virtual void OnMoneyChanged(Player* /*player*/, int64& /*amount*/) { }

        // Called when a player's money is at limit (amount = money tried to add)
        virtual void OnMoneyLimit(Player* /*player*/, int64 /*amount*/) { }

        // Called when a player gains XP (before anything is given)
        virtual void OnGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/) { }

        // Called when a player's reputation changes (before it is actually changed)
        virtual void OnReputationChange(Player* /*player*/, uint32 /*factionId*/, int32& /*standing*/, bool /*incremental*/) { }

        // Called when a duel is requested
        virtual void OnDuelRequest(Player* /*target*/, Player* /*challenger*/) { }

        // Called when a duel starts (after 3s countdown)
        virtual void OnDuelStart(Player* /*player1*/, Player* /*player2*/) { }

        // Called when a duel ends
        virtual void OnDuelEnd(Player* /*winner*/, Player* /*loser*/, DuelCompleteType /*type*/) { }

        // The following methods are called when a player sends a chat message.
        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/) { }

        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Player* /*receiver*/) { }

        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Group* /*group*/) { }

        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Guild* /*guild*/) { }

        virtual void OnChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Channel* /*channel*/) { }

        // Both of the below are called on emote opcodes.
        virtual void OnClearEmote(Player* /*player*/) { }

        virtual void OnTextEmote(Player* /*player*/, uint32 /*textEmote*/, uint32 /*emoteNum*/, ObjectGuid /*guid*/) { }

        // Called in Spell::Cast.
        virtual void OnSpellCast(Player* /*player*/, Spell* /*spell*/, bool /*skipCheck*/) { }

        // Called when a player logs in.
        virtual void OnLogin(Player* /*player*/, bool /*firstLogin*/) { }

        // Called when a player logs out.
        virtual void OnLogout(Player* /*player*/) { }

        // Called when a player is created.
        virtual void OnCreate(Player* /*player*/) { }

        // Called when a player is deleted.
        virtual void OnDelete(ObjectGuid /*guid*/, uint32 /*accountId*/) { }

        // Called when a player delete failed
        virtual void OnFailedDelete(ObjectGuid /*guid*/, uint32 /*accountId*/) { }

        // Called when a player is about to be saved.
        virtual void OnSave(Player* /*player*/) { }

        // Called when a player is bound to an instance
        virtual void OnBindToInstance(Player* /*player*/, Difficulty /*difficulty*/, uint32 /*mapId*/, bool /*permanent*/, uint8 /*extendState*/) { }

        // Called when a player switches to a new zone
        virtual void OnUpdateZone(Player* /*player*/, uint32 /*newZone*/, uint32 /*newArea*/) { }

        // Called when a player changes to a new map (after moving to new map)
        virtual void OnMapChanged(Player* /*player*/) { }

        // Called after a player's quest status has been changed
        virtual void OnQuestStatusChange(Player* /*player*/, uint32 /*questId*/) { }

        // Called when a player completes a movie
        virtual void OnMovieComplete(Player* /*player*/, uint32 /*movieId*/) { }

        // Called when a player choose a response from a PlayerChoice
        virtual void OnPlayerChoiceResponse(Player* /*player*/, uint32 /*choiceId*/, uint32 /*responseId*/) { }
};

class TC_GAME_API AccountScript : public ScriptObject
{
    protected:

        AccountScript(const char* name);

    public:

        // Called when an account logged in succesfully
        virtual void OnAccountLogin(uint32 /*accountId*/) {}

        // Called when an account login failed
        virtual void OnFailedAccountLogin(uint32 /*accountId*/) {}

        // Called when Email is successfully changed for Account
        virtual void OnEmailChange(uint32 /*accountId*/) {}

        // Called when Email failed to change for Account
        virtual void OnFailedEmailChange(uint32 /*accountId*/) {}

        // Called when Password is successfully changed for Account
        virtual void OnPasswordChange(uint32 /*accountId*/) {}

        // Called when Password failed to change for Account
        virtual void OnFailedPasswordChange(uint32 /*accountId*/) {}
};

class TC_GAME_API GuildScript : public ScriptObject
{
    protected:

        GuildScript(const char* name);

    public:

        // Called when a member is added to the guild.
        virtual void OnAddMember(Guild* /*guild*/, Player* /*player*/, uint8& /*plRank*/) { }

        // Called when a member is removed from the guild.
        virtual void OnRemoveMember(Guild* /*guild*/, ObjectGuid /*guid*/, bool /*isDisbanding*/, bool /*isKicked*/) { }

        // Called when the guild MOTD (message of the day) changes.
        virtual void OnMOTDChanged(Guild* /*guild*/, const std::string& /*newMotd*/) { }

        // Called when the guild info is altered.
        virtual void OnInfoChanged(Guild* /*guild*/, const std::string& /*newInfo*/) { }

        // Called when a guild is created.
        virtual void OnCreate(Guild* /*guild*/, Player* /*leader*/, const std::string& /*name*/) { }

        // Called when a guild is disbanded.
        virtual void OnDisband(Guild* /*guild*/) { }

        // Called when a guild member withdraws money from a guild bank.
        virtual void OnMemberWitdrawMoney(Guild* /*guild*/, Player* /*player*/, uint64& /*amount*/, bool /*isRepair*/) { }

        // Called when a guild member deposits money in a guild bank.
        virtual void OnMemberDepositMoney(Guild* /*guild*/, Player* /*player*/, uint64& /*amount*/) { }

        // Called when a guild member moves an item in a guild bank.
        virtual void OnItemMove(Guild* /*guild*/, Player* /*player*/, Item* /*pItem*/, bool /*isSrcBank*/, uint8 /*srcContainer*/, uint8 /*srcSlotId*/,
            bool /*isDestBank*/, uint8 /*destContainer*/, uint8 /*destSlotId*/) { }

        virtual void OnEvent(Guild* /*guild*/, uint8 /*eventType*/, ObjectGuid::LowType /*playerGuid1*/, ObjectGuid::LowType /*playerGuid2*/, uint8 /*newRank*/) { }

        virtual void OnBankEvent(Guild* /*guild*/, uint8 /*eventType*/, uint8 /*tabId*/, ObjectGuid::LowType /*playerGuid*/, uint64 /*itemOrMoney*/, uint16 /*itemStackCount*/, uint8 /*destTabId*/) { }
};

class TC_GAME_API GroupScript : public ScriptObject
{
    protected:

        GroupScript(const char* name);

    public:

        // Called when a member is added to a group.
        virtual void OnAddMember(Group* /*group*/, ObjectGuid /*guid*/) { }

        // Called when a member is invited to join a group.
        virtual void OnInviteMember(Group* /*group*/, ObjectGuid /*guid*/) { }

        // Called when a member is removed from a group.
        virtual void OnRemoveMember(Group* /*group*/, ObjectGuid /*guid*/, RemoveMethod /*method*/, ObjectGuid /*kicker*/, const char* /*reason*/) { }

        // Called when the leader of a group is changed.
        virtual void OnChangeLeader(Group* /*group*/, ObjectGuid /*newLeaderGuid*/, ObjectGuid /*oldLeaderGuid*/) { }

        // Called when a group is disbanded.
        virtual void OnDisband(Group* /*group*/) { }
};

class TC_GAME_API AreaTriggerEntityScript : public ScriptObject
{
    protected:

        AreaTriggerEntityScript(const char* name);

    public:

        // Called when a AreaTriggerAI object is needed for the areatrigger.
        virtual AreaTriggerAI* GetAI(AreaTrigger* /*at*/) const { return nullptr; }
};

class TC_GAME_API ConversationScript : public ScriptObject
{
    protected:
        ConversationScript(char const* name);

    public:

        // Called when Conversation is created but not added to Map yet.
        virtual void OnConversationCreate(Conversation* /*conversation*/, Unit* /*creator*/) { }
};

class TC_GAME_API SceneScript : public ScriptObject
{
    protected:

        SceneScript(const char* name);

    public:
        // Called when a player start a scene
        virtual void OnSceneStart(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) { }

        // Called when a player receive trigger from scene
        virtual void OnSceneTriggerEvent(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& /*triggerName*/) { }

        // Called when a scene is canceled
        virtual void OnSceneCancel(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) { }

        // Called when a scene is completed
        virtual void OnSceneComplete(Player* /*player*/, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) { }
};

class TC_GAME_API QuestScript : public ScriptObject
{
    protected:

        QuestScript(const char* name);

    public:
        // Called when a quest status change
        virtual void OnQuestStatusChange(Player* /*player*/, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus /*newStatus*/) { }

        // Called when a quest objective data change
        virtual void OnQuestObjectiveChange(Player* /*player*/, Quest const* /*quest*/, QuestObjective const& /*objective*/, int32 /*oldAmount*/, int32 /*newAmount*/) { }
};

// Manages registration, loading, and execution of scripts.
class TC_GAME_API ScriptMgr
{
    friend class ScriptObject;

    private:
        ScriptMgr();
        virtual ~ScriptMgr();

        void FillSpellSummary();
        void LoadDatabase();

        void IncreaseScriptCount() { ++_scriptCount; }
        void DecreaseScriptCount() { --_scriptCount; }

    public: /* Initialization */
        static ScriptMgr* instance();

        void Initialize();

        uint32 GetScriptCount() const { return _scriptCount; }

        typedef void(*ScriptLoaderCallbackType)();

        /// Sets the script loader callback which is invoked to load scripts
        /// (Workaround for circular dependency game <-> scripts)
        void SetScriptLoader(ScriptLoaderCallbackType script_loader_callback)
        {
            _script_loader_callback = script_loader_callback;
        }

    public: /* Script contexts */
        /// Set the current script context, which allows the ScriptMgr
        /// to accept new scripts in this context.
        /// Requires a SwapScriptContext() call afterwards to load the new scripts.
        void SetScriptContext(std::string const& context);
        /// Returns the current script context.
        std::string const& GetCurrentScriptContext() const { return _currentContext; }
        /// Releases all scripts associated with the given script context immediately.
        /// Requires a SwapScriptContext() call afterwards to finish the unloading.
        void ReleaseScriptContext(std::string const& context);
        /// Executes all changed introduced by SetScriptContext and ReleaseScriptContext.
        /// It is possible to combine multiple SetScriptContext and ReleaseScriptContext
        /// calls for better performance (bulk changes).
        void SwapScriptContext(bool initialize = false);

        /// Returns the context name of the static context provided by the worldserver
        static std::string const& GetNameOfStaticContext();

        /// Acquires a strong module reference to the module containing the given script name,
        /// which prevents the shared library which contains the script from unloading.
        /// The shared library is lazy unloaded as soon as all references to it are released.
        std::shared_ptr<ModuleReference> AcquireModuleReferenceOfScriptName(
            std::string const& scriptname) const;

    public: /* Unloading */

        void Unload();

    public: /* SpellScriptLoader */

        void CreateSpellScripts(uint32 spellId, std::vector<SpellScript*>& scriptVector, Spell* invoker) const;
        void CreateAuraScripts(uint32 spellId, std::vector<AuraScript*>& scriptVector, Aura* invoker) const;
        SpellScriptLoader* GetSpellScriptLoader(uint32 scriptId);

    public: /* ServerScript */

        void OnNetworkStart();
        void OnNetworkStop();
        void OnSocketOpen(std::shared_ptr<WorldSocket> socket);
        void OnSocketClose(std::shared_ptr<WorldSocket> socket);
        void OnPacketReceive(WorldSession* session, WorldPacket const& packet);
        void OnPacketSend(WorldSession* session, WorldPacket const& packet);

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

        void OnHonorCalculation(float& honor, uint8 level, float multiplier);
        void OnGrayLevelCalculation(uint8& grayLevel, uint8 playerLevel);
        void OnColorCodeCalculation(XPColorChar& color, uint8 playerLevel, uint8 mobLevel);
        void OnZeroDifferenceCalculation(uint8& diff, uint8 playerLevel);
        void OnBaseGainCalculation(uint32& gain, uint8 playerLevel, uint8 mobLevel);
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
        bool OnItemUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid castId);
        bool OnItemExpire(Player* player, ItemTemplate const* proto);
        bool OnItemRemove(Player* player, Item* item);

    public: /* CreatureScript */

        bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target);
        bool OnGossipHello(Player* player, Creature* creature);
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action);
        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code);
        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest);
        bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest);
        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt);
        uint32 GetDialogStatus(Player* player, Creature* creature);
        bool CanSpawn(ObjectGuid::LowType spawnId, uint32 entry, CreatureTemplate const* actTemplate, CreatureData const* cData, Map const* map);
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
        void OnGameObjectDestroyed(GameObject* go, Player* player);
        void OnGameObjectDamaged(GameObject* go, Player* player);
        void OnGameObjectLootStateChanged(GameObject* go, uint32 state, Unit* unit);
        void OnGameObjectStateChanged(GameObject* go, uint32 state);
        void OnGameObjectUpdate(GameObject* go, uint32 diff);
        GameObjectAI* GetGameObjectAI(GameObject* go);

    public: /* AreaTriggerScript */

        bool OnAreaTrigger(Player* player, AreaTriggerEntry const* trigger, bool entered);

    public: /* BattlegroundScript */

        Battleground* CreateBattleground(BattlegroundTypeId typeId);

    public: /* OutdoorPvPScript */

        OutdoorPvP* CreateOutdoorPvP(OutdoorPvPData const* data);

    public: /* CommandScript */

        std::vector<ChatCommand> GetChatCommands();

    public: /* WeatherScript */

        void OnWeatherChange(Weather* weather, WeatherState state, float grade);
        void OnWeatherUpdate(Weather* weather, uint32 diff);

    public: /* AuctionHouseScript */

        void OnAuctionAdd(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionRemove(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionSuccessful(AuctionHouseObject* ah, AuctionEntry* entry);
        void OnAuctionExpire(AuctionHouseObject* ah, AuctionEntry* entry);

    public: /* ConditionScript */

        bool OnConditionCheck(Condition const* condition, ConditionSourceInfo& sourceInfo);

    public: /* VehicleScript */

        void OnInstall(Vehicle* veh);
        void OnUninstall(Vehicle* veh);
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

        bool OnCriteriaCheck(uint32 scriptId, Player* source, Unit* target);

    public: /* PlayerScript */

        void OnPVPKill(Player* killer, Player* killed);
        void OnCreatureKill(Player* killer, Creature* killed);
        void OnPlayerKilledByCreature(Creature* killer, Player* killed);
        void OnPlayerLevelChanged(Player* player, uint8 oldLevel);
        void OnPlayerFreeTalentPointsChanged(Player* player, uint32 newPoints);
        void OnPlayerTalentsReset(Player* player, bool noCost);
        void OnPlayerMoneyChanged(Player* player, int64& amount);
        void OnPlayerMoneyLimit(Player* player, int64 amount);
        void OnGivePlayerXP(Player* player, uint32& amount, Unit* victim);
        void OnPlayerReputationChange(Player* player, uint32 factionID, int32& standing, bool incremental);
        void OnPlayerDuelRequest(Player* target, Player* challenger);
        void OnPlayerDuelStart(Player* player1, Player* player2);
        void OnPlayerDuelEnd(Player* winner, Player* loser, DuelCompleteType type);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Player* receiver);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild);
        void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel);
        void OnPlayerClearEmote(Player* player);
        void OnPlayerTextEmote(Player* player, uint32 textEmote, uint32 emoteNum, ObjectGuid guid);
        void OnPlayerSpellCast(Player* player, Spell* spell, bool skipCheck);
        void OnPlayerLogin(Player* player, bool firstLogin);
        void OnPlayerLogout(Player* player);
        void OnPlayerCreate(Player* player);
        void OnPlayerDelete(ObjectGuid guid, uint32 accountId);
        void OnPlayerFailedDelete(ObjectGuid guid, uint32 accountId);
        void OnPlayerSave(Player* player);
        void OnPlayerBindToInstance(Player* player, Difficulty difficulty, uint32 mapid, bool permanent, uint8 extendState);
        void OnPlayerUpdateZone(Player* player, uint32 newZone, uint32 newArea);
        void OnQuestStatusChange(Player* player, uint32 questId);
        void OnMovieComplete(Player* player, uint32 movieId);
        void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId);

    public: /* AccountScript */

        void OnAccountLogin(uint32 accountId);
        void OnFailedAccountLogin(uint32 accountId);
        void OnEmailChange(uint32 accountId);
        void OnFailedEmailChange(uint32 accountId);
        void OnPasswordChange(uint32 accountId);
        void OnFailedPasswordChange(uint32 accountId);

    public: /* GuildScript */

        void OnGuildAddMember(Guild* guild, Player* player, uint8& plRank);
        void OnGuildRemoveMember(Guild* guild, ObjectGuid guid, bool isDisbanding, bool isKicked);
        void OnGuildMOTDChanged(Guild* guild, const std::string& newMotd);
        void OnGuildInfoChanged(Guild* guild, const std::string& newInfo);
        void OnGuildCreate(Guild* guild, Player* leader, const std::string& name);
        void OnGuildDisband(Guild* guild);
        void OnGuildMemberWitdrawMoney(Guild* guild, Player* player, uint64 &amount, bool isRepair);
        void OnGuildMemberDepositMoney(Guild* guild, Player* player, uint64 &amount);
        void OnGuildItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
            bool isDestBank, uint8 destContainer, uint8 destSlotId);
        void OnGuildEvent(Guild* guild, uint8 eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank);
        void OnGuildBankEvent(Guild* guild, uint8 eventType, uint8 tabId, ObjectGuid::LowType playerGuid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId);

    public: /* GroupScript */

        void OnGroupAddMember(Group* group, ObjectGuid guid);
        void OnGroupInviteMember(Group* group, ObjectGuid guid);
        void OnGroupRemoveMember(Group* group, ObjectGuid guid, RemoveMethod method, ObjectGuid kicker, const char* reason);
        void OnGroupChangeLeader(Group* group, ObjectGuid newLeaderGuid, ObjectGuid oldLeaderGuid);
        void OnGroupDisband(Group* group);

    public: /* UnitScript */

        void OnHeal(Unit* healer, Unit* reciever, uint32& gain);
        void OnDamage(Unit* attacker, Unit* victim, uint32& damage);
        void ModifyPeriodicDamageAurasTick(Unit* target, Unit* attacker, uint32& damage);
        void ModifyMeleeDamage(Unit* target, Unit* attacker, uint32& damage);
        void ModifySpellDamageTaken(Unit* target, Unit* attacker, int32& damage);

    public: /* AreaTriggerEntityScript */

        AreaTriggerAI* GetAreaTriggerAI(AreaTrigger* areaTrigger);

    public: /* ConversationScript */

        void OnConversationCreate(Conversation* conversation, Unit* creator);

    public: /* SceneScript */

        void OnSceneStart(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate);
        void OnSceneTrigger(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate, std::string const& triggerName);
        void OnSceneCancel(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate);
        void OnSceneComplete(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate);

    public: /* QuestScript */

        void OnQuestStatusChange(Player* player, Quest const* quest, QuestStatus oldStatus, QuestStatus newStatus);
        void OnQuestObjectiveChange(Player* player, Quest const* quest, QuestObjective const& objective, int32 oldAmount, int32 newAmount);

    private:
        uint32 _scriptCount;

        ScriptLoaderCallbackType _script_loader_callback;

        std::string _currentContext;
};

template <class S>
class GenericSpellScriptLoader : public SpellScriptLoader
{
    public:
        GenericSpellScriptLoader(char const* name) : SpellScriptLoader(name) { }
        SpellScript* GetSpellScript() const override { return new S(); }
};
#define RegisterSpellScript(spell_script) new GenericSpellScriptLoader<spell_script>(#spell_script)

template <class A>
class GenericAuraScriptLoader : public SpellScriptLoader
{
    public:
        GenericAuraScriptLoader(char const* name) : SpellScriptLoader(name) { }
        AuraScript* GetAuraScript() const override { return new A(); }
};
#define RegisterAuraScript(aura_script) new GenericAuraScriptLoader<aura_script>(#aura_script)

template <class S, class A>
class GenericSpellAndAuraScriptLoader : public SpellScriptLoader
{
    public:
        GenericSpellAndAuraScriptLoader(char const* name) : SpellScriptLoader(name) { }
        SpellScript* GetSpellScript() const override { return new S(); }
        AuraScript* GetAuraScript() const override { return new A(); }
};
#define RegisterSpellAndAuraScriptPair(spell_script, aura_script) new GenericSpellAndAuraScriptLoader<spell_script, aura_script>(#spell_script)

template <class AI>
class GenericCreatureScript : public CreatureScript
{
    public:
        GenericCreatureScript(char const* name) : CreatureScript(name) { }
        CreatureAI* GetAI(Creature* me) const override { return new AI(me); }
};
#define RegisterCreatureAI(ai_name) new GenericCreatureScript<ai_name>(#ai_name)

template <class AI, AI*(*AIFactory)(Creature*)>
class FactoryCreatureScript : public CreatureScript
{
    public:
        FactoryCreatureScript(char const* name) : CreatureScript(name) { }
        CreatureAI* GetAI(Creature* me) const override { return AIFactory(me); }
};
#define RegisterCreatureAIWithFactory(ai_name, factory_fn) new FactoryCreatureScript<ai_name, &factory_fn>(#ai_name)

template <class AI>
class GenericGameObjectScript : public GameObjectScript
{
    public:
        GenericGameObjectScript(char const* name) : GameObjectScript(name) { }
        GameObjectAI* GetAI(GameObject* go) const override { return new AI(go); }
};
#define RegisterGameObjectAI(ai_name) new GenericGameObjectScript<ai_name>(#ai_name)

template <class AI>
class GenericAreaTriggerEntityScript : public AreaTriggerEntityScript
{
    public:
        GenericAreaTriggerEntityScript(char const* name) : AreaTriggerEntityScript(name) { }
        AreaTriggerAI* GetAI(AreaTrigger* at) const override { return new AI(at); }
};
#define RegisterAreaTriggerAI(ai_name) new GenericAreaTriggerEntityScript<ai_name>(#ai_name)

#define sScriptMgr ScriptMgr::instance()

#endif

/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#include "LuaEngine.h"

#include "GlobalMethods.h"
#include "ObjectMethods.h"
#include "WorldObjectMethods.h"
#include "UnitMethods.h"
#include "PlayerMethods.h"
#include "CreatureMethods.h"
#include "GroupMethods.h"
#include "GuildMethods.h"
#include "GameObjectMethods.h"
#include "QueryMethods.h"
#include "AuraMethods.h"
#include "ItemMethods.h"
#include "WorldPacketMethods.h"
#include "SpellMethods.h"
#include "QuestMethods.h"
#include "MapMethods.h"
#include "CorpseMethods.h"
#include "WeatherMethods.h"
#include "VehicleMethods.h"

void RegisterGlobals(lua_State* L)
{
    // Hooks
    lua_register(L, "RegisterServerEvent", &LuaGlobalFunctions::RegisterServerEvent);                       // RegisterServerEvent(event, function)
    lua_register(L, "RegisterPlayerEvent", &LuaGlobalFunctions::RegisterPlayerEvent);                       // RegisterPlayerEvent(event, function)
    lua_register(L, "RegisterVehicleEvent", &LuaGlobalFunctions::RegisterVehicleEvent);                     // RegisterVehicleEvent(event, function)
    lua_register(L, "RegisterGuildEvent", &LuaGlobalFunctions::RegisterGuildEvent);                         // RegisterGuildEvent(event, function)
    lua_register(L, "RegisterGroupEvent", &LuaGlobalFunctions::RegisterGroupEvent);                         // RegisterGroupEvent(event, function)
    lua_register(L, "RegisterCreatureEvent", &LuaGlobalFunctions::RegisterCreatureEvent);                   // RegisterCreatureEvent(entry, event, function)
    lua_register(L, "RegisterCreatureGossipEvent", &LuaGlobalFunctions::RegisterCreatureGossipEvent);       // RegisterCreatureGossipEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectEvent", &LuaGlobalFunctions::RegisterGameObjectEvent);               // RegisterGameObjectEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectGossipEvent", &LuaGlobalFunctions::RegisterGameObjectGossipEvent);   // RegisterGameObjectGossipEvent(entry, event, function)
    lua_register(L, "RegisterItemEvent", &LuaGlobalFunctions::RegisterItemEvent);                           // RegisterItemEvent(entry, event, function)
    lua_register(L, "RegisterItemGossipEvent", &LuaGlobalFunctions::RegisterItemGossipEvent);               // RegisterItemGossipEvent(entry, event, function)
    lua_register(L, "RegisterPlayerGossipEvent", &LuaGlobalFunctions::RegisterPlayerGossipEvent);           // RegisterPlayerGossipEvent(menu_id, event, function)

    // Getters
    lua_register(L, "GetLuaEngine", &LuaGlobalFunctions::GetLuaEngine);                                     // GetLuaEngine() - Returns ElunaEngine
    lua_register(L, "GetCoreVersion", &LuaGlobalFunctions::GetCoreVersion);                                 // GetCoreVersion() - Returns core version string
    lua_register(L, "GetQuest", &LuaGlobalFunctions::GetQuest);                                             // GetQuest(questId) - Returns quest object
    lua_register(L, "GetPlayerByGUID", &LuaGlobalFunctions::GetPlayerByGUID);                               // GetPlayerByGUID(guid) - Returns player object by GUID
    lua_register(L, "GetPlayerByName", &LuaGlobalFunctions::GetPlayerByName);                               // GetPlayerByName(name) - Returns player object by player name
    lua_register(L, "GetGameTime", &LuaGlobalFunctions::GetGameTime);                                       // GetGameTime() - Returns game time
    lua_register(L, "GetPlayersInWorld", &LuaGlobalFunctions::GetPlayersInWorld);                           // GetPlayersInWorld([team, onlyGM]) - Returns a table with all player objects. Team can be 0 for ally, 1 for horde and 2 for neutral
    lua_register(L, "GetPlayersInMap", &LuaGlobalFunctions::GetPlayersInMap);                               // GetPlayersInWorld(mapId[, instanceId, team]) - Returns a table with all player objects in map. Team can be 0 for ally, 1 for horde and 2 for neutral
    lua_register(L, "GetGuildByName", &LuaGlobalFunctions::GetGuildByName);                                 // GetGuildByName(name) - Returns guild object by the guild name
    lua_register(L, "GetGuildByLeaderGUID", &LuaGlobalFunctions::GetGuildByLeaderGUID);                     // GetGuildByLeaderGUID(guid) - Returns guild by it's leader's guid
    lua_register(L, "GetPlayerCount", &LuaGlobalFunctions::GetPlayerCount);                                 // GetPlayerCount() - Returns the server's player count
    //lua_register(L, "FindUnit", &LuaGlobalFunctions::FindUnit);                                             // FindUnit(guid) - Returns unit by it's guid
    lua_register(L, "GetPlayerGUID", &LuaGlobalFunctions::GetPlayerGUID);                                   // GetPlayerGUID(lowguid) - Generates GUID (uint64) string from player lowguid UNDOCUMENTED
    lua_register(L, "GetItemGUID", &LuaGlobalFunctions::GetItemGUID);                                       // GetItemGUID(lowguid) - Generates GUID (uint64) string from item lowguid UNDOCUMENTED
    lua_register(L, "GetObjectGUID", &LuaGlobalFunctions::GetObjectGUID);                                   // GetObjectGUID(lowguid, entry) - Generates GUID (uint64) string from gameobject lowguid and entry UNDOCUMENTED
    lua_register(L, "GetUnitGUID", &LuaGlobalFunctions::GetUnitGUID);                                       // GetUnitGUID(lowguid, entry) - Generates GUID (uint64) string from unit (creature) lowguid and entry UNDOCUMENTED
    lua_register(L, "GetGUIDLow", &LuaGlobalFunctions::GetGUIDLow);                                         // GetGUIDLow(guid) - Returns GUIDLow (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDType", &LuaGlobalFunctions::GetGUIDType);                                       // GetGUIDType(guid) - Returns Type (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDEntry", &LuaGlobalFunctions::GetGUIDEntry);                                     // GetGUIDEntry(guid) - Returns Entry (uint32) from guid (uint64 as string), may be always 0 UNDOCUMENTED
    lua_register(L, "bit_not", &LuaGlobalFunctions::bit_not);                                               // bit_not(a) - Returns ~a UNDOCUMENTED
    lua_register(L, "bit_xor", &LuaGlobalFunctions::bit_xor);                                               // bit_xor(a, b) - Returns a ^ b UNDOCUMENTED
    lua_register(L, "bit_rshift", &LuaGlobalFunctions::bit_rshift);                                         // bit_rshift(a, b) - Returns a >> b UNDOCUMENTED
    lua_register(L, "bit_lshift", &LuaGlobalFunctions::bit_lshift);                                         // bit_lshift(a, b) - Returns a << b UNDOCUMENTED
    lua_register(L, "bit_or", &LuaGlobalFunctions::bit_or);                                                 // bit_or(a, b) - Returns a | b UNDOCUMENTED
    lua_register(L, "bit_and", &LuaGlobalFunctions::bit_and);                                               // bit_and(a, b) - Returns a & b UNDOCUMENTED
    lua_register(L, "GetItemLink", &LuaGlobalFunctions::GetItemLink);                                       // GetItemLink(entry[, localeIndex]) - Returns the shift clickable link of the item. Item name translated if translate available for provided locale index UNDOCUMENTED
    lua_register(L, "GetMapById", &LuaGlobalFunctions::GetMapById);                                         // GetMapById(mapId) - Returns map object of id specified. UNDOCUMENTED

    // Other
    lua_register(L, "ReloadEluna", &LuaGlobalFunctions::ReloadEluna);                                       // ReloadEluna() - Reload's Eluna engine
    lua_register(L, "SendWorldMessage", &LuaGlobalFunctions::SendWorldMessage);                             // SendWorldMessage(msg) - Sends a broadcast message to everyone
    lua_register(L, "WorldDBQuery", &LuaGlobalFunctions::WorldDBQuery);                                     // WorldDBQuery(sql) - Executes given SQL query to world database instantly and returns a QueryResult object
    lua_register(L, "WorldDBExecute", &LuaGlobalFunctions::WorldDBExecute);                                 // WorldDBExecute(sql) - Executes given SQL query to world database (not instant)
    lua_register(L, "CharDBQuery", &LuaGlobalFunctions::CharDBQuery);                                       // CharDBQuery(sql) - Executes given SQL query to character database instantly and returns a QueryResult object
    lua_register(L, "CharDBExecute", &LuaGlobalFunctions::CharDBExecute);                                   // CharDBExecute(sql) - Executes given SQL query to character database (not instant)
    lua_register(L, "AuthDBQuery", &LuaGlobalFunctions::AuthDBQuery);                                       // AuthDBQuery(sql) - Executes given SQL query to auth/logon database instantly and returns a QueryResult object
    lua_register(L, "AuthDBExecute", &LuaGlobalFunctions::AuthDBExecute);                                   // AuthDBExecute(sql) - Executes given SQL query to auth/logon database (not instant)
    lua_register(L, "CreateLuaEvent", &LuaGlobalFunctions::CreateLuaEvent);                                 // CreateLuaEvent(function, delay, calls) - Creates a global timed event. Returns Event ID. Calls set to 0 calls infinitely.
    lua_register(L, "RemoveEventById", &LuaGlobalFunctions::RemoveEventById);                               // RemoveEventById(eventId, [all_events]) - Removes a global timed event by it's ID. If all_events is true, can remove any timed event by ID (unit, gameobject, global..)
    lua_register(L, "RemoveEvents", &LuaGlobalFunctions::RemoveEvents);                                     // RemoveEvents([all_events]) - Removes all global timed events. Removes all timed events (unit, gameobject, global) if all_events is true
    lua_register(L, "PerformIngameSpawn", &LuaGlobalFunctions::PerformIngameSpawn);                         // PerformIngameSpawn(spawntype, entry, mapid, instanceid, x, y, z, o[, save, DurOrResptime, phase]) - spawntype: 1 Creature, 2 Object. DurOrResptime is respawntime for gameobjects and despawntime for creatures if creature is not saved. Returns spawned creature/gameobject
    lua_register(L, "CreatePacket", &LuaGlobalFunctions::CreatePacket);                                     // CreatePacket(opcode, size) - Creates a new packet object
    lua_register(L, "AddVendorItem", &LuaGlobalFunctions::AddVendorItem);                                   // AddVendorItem(entry, itemId, maxcount, incrtime, extendedcost[, persist(bool)]) - Adds an item to vendor entry.
    lua_register(L, "VendorRemoveItem", &LuaGlobalFunctions::VendorRemoveItem);                             // VendorRemoveItem(entry, item[, persist(bool)]) - Removes an item from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "VendorRemoveAllItems", &LuaGlobalFunctions::VendorRemoveAllItems);                     // VendorRemoveAllItems(entry[, persist(bool)]) - Removes all items from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "Kick", &LuaGlobalFunctions::Kick);                                                     // Kick(player) - Kicks given player
    lua_register(L, "Ban", &LuaGlobalFunctions::Ban);                                                       // Ban(banMode(integer), nameOrIP(string), duration(string), reason(string), player(whoBanned)) - Banmode: 0 account, 1 character, 2 IP
    lua_register(L, "SaveAllPlayers", &LuaGlobalFunctions::SaveAllPlayers);                                 // SaveAllPlayers() - Saves all players
    lua_register(L, "SendMail", &LuaGlobalFunctions::SendMail);                                             // SendMail(subject, text, receiverLowGUID[, sender, stationary, delay, itemEntry, itemAmount, itemEntry2, itemAmount2...]) - Sends a mail to player with lowguid. use nil to use default values on optional arguments. Sender is an optional player object. UNDOCUMENTED
    lua_register(L, "AddTaxiPath", &LuaGlobalFunctions::AddTaxiPath);                                       // AddTaxiPath(pathTable, mountA, mountH[, price, pathId]) - Adds a new taxi path. Returns the path's ID. Will replace an existing path if pathId provided and already used. path table structure: T = {{map, x, y, z[, actionFlag, delay, arrivalEvId, departEvId]}, {...}, ...} UDOCUMENTED
    lua_register(L, "AddCorpse", &LuaGlobalFunctions::AddCorpse);                                           // AddCorpse(corpse) - Adds the player's corpse to the world. More specifically, the cell.
    lua_register(L, "RemoveCorpse", &LuaGlobalFunctions::RemoveCorpse);                                     // RemoveCorpse(corpse) - Removes the player's corpse from the world.
    lua_register(L, "ConvertCorpseForPlayer", &LuaGlobalFunctions::ConvertCorpseForPlayer);                 // ConvertCorpseFromPlayer(guid[, insignia]) - Converts the player's corpse to bones. Adding insignia for PvP is optional (true or false).
    lua_register(L, "RemoveOldCorpses", &LuaGlobalFunctions::RemoveOldCorpses);                             // RemoveOldCorpses() - Converts (removes) old corpses that aren't bones.
    lua_register(L, "FindWeather", &LuaGlobalFunctions::FindWeather);                                       // FindWeather(zoneId) - Finds the weather by zoneId and returns the weather
    lua_register(L, "AddWeather", &LuaGlobalFunctions::AddWeather);                                         // AddWeather(zoneId) - Adds weather to the following zone, also returns weather
    lua_register(L, "RemoveWeather", &LuaGlobalFunctions::RemoveWeather);                                   // RemoveWeather(zoneId) - Removes weather from a zone
    lua_register(L, "SendFineWeatherToPlayer", &LuaGlobalFunctions::SendFineWeatherToPlayer);               // SendFineWeatherToPlayer(player) - Sends WEATHER_STATE_FINE weather to the
}

ElunaRegister<Object> ObjectMethods[] =
{
    // Getters
    {"GetEntry", &LuaObject::GetEntry},                     // :GetEntry() - Returns the object's entryId
    {"GetGUID", &LuaObject::GetGUID},                       // :GetGUID() - Returns uint64 guid as hex string
    {"GetGUIDLow", &LuaObject::GetGUIDLow},                 // :GetGUIDLow() - Returns uint32 guid (low guid) that is used in database.
    {"GetInt32Value", &LuaObject::GetInt32Value},           // :GetInt32Value(index) - returns an int value from object fields
    {"GetUInt32Value", &LuaObject::GetUInt32Value},         // :GetUInt32Value(index) - returns an uint value from object fields
    {"GetFloatValue", &LuaObject::GetFloatValue},           // :GetFloatValue(index) - returns a float value from object fields
    {"GetByteValue", &LuaObject::GetByteValue},             // :GetByteValue(index, offset) - returns a byte value from object fields
    {"GetUInt16Value", &LuaObject::GetUInt16Value},         // :GetUInt16Value(index, offset) - returns a uint16 value from object fields
    {"GetScale", &LuaObject::GetScale},                     // :GetScale()

    // Setters
    {"SetInt32Value", &LuaObject::SetInt32Value},           // :SetInt32Value(index, value) - Sets an int value for the object
    {"SetUInt32Value", &LuaObject::SetUInt32Value},         // :SetUInt32Value(index, value) - Sets an uint value for the object
    {"UpdateUInt32Value", &LuaObject::UpdateUInt32Value},   // :UpdateUInt32Value(index, value) - Updates an uint value for the object
    {"SetFloatValue", &LuaObject::SetFloatValue},           // :SetFloatValue(index, value) - Sets a float value for the object
    {"SetByteValue", &LuaObject::SetByteValue},             // :SetByteValue(index, offset, value) - Sets a byte value for the object
    {"SetUInt16Value", &LuaObject::SetUInt16Value},         // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the object
    {"SetInt16Value", &LuaObject::SetInt16Value},           // :SetInt16Value(index, offset, value) - Sets an int16 value for the object
    {"SetScale", &LuaObject::SetScale},                     // :SetScale(scale)
    {"SetFlag", &LuaObject::SetFlag},                       // :SetFlag(index, flag)

    // Boolean
    {"IsInWorld", &LuaObject::IsInWorld},                   // :IsInWorld() - Returns if the object is in world
    {"HasFlag", &LuaObject::HasFlag},                       // :HasFlag(index, flag)

    // Other
    {"ToGameObject", &LuaObject::ToGameObject},             // :ToGameObject()
    {"ToUnit", &LuaObject::ToUnit},                         // :ToUnit()
    {"ToCreature", &LuaObject::ToCreature},                 // :ToCreature()
    {"ToPlayer", &LuaObject::ToPlayer},                     // :ToPlayer()
    {"ToCorpse", &LuaObject::ToCorpse},                     // :ToCorpse()
    {"RemoveFlag", &LuaObject::RemoveFlag},                 // :RemoveFlag(index, flag)

    {NULL, NULL},
};

ElunaRegister<WorldObject> WorldObjectMethods[] =
{
    // Getters
    {"GetName", &LuaWorldObject::GetName},                  // :GetName()
    {"GetMap", &LuaWorldObject::GetMap},                    // :GetMap()
    {"GetPhaseMask", &LuaWorldObject::GetPhaseMask},        // :GetPhaseMask()
    {"GetInstanceId", &LuaWorldObject::GetInstanceId},      // :GetInstanceId()
    {"GetAreaId", &LuaWorldObject::GetAreaId},              // :GetAreaId()
    {"GetZoneId", &LuaWorldObject::GetZoneId},              // :GetZoneId()
    {"GetMapId", &LuaWorldObject::GetMapId},                // :GetMapId() - Returns the WorldObject's current map object
    {"GetX", &LuaWorldObject::GetX},                        // :GetX()
    {"GetY", &LuaWorldObject::GetY},                        // :GetY()
    {"GetZ", &LuaWorldObject::GetZ},                        // :GetZ()
    {"GetO", &LuaWorldObject::GetO},                        // :GetO()
    {"GetLocation", &LuaWorldObject::GetLocation},          // :GetLocation() - returns X, Y, Z and O co - ords (in that order)
    {"GetPlayersInRange", &LuaWorldObject::GetPlayersInRange},              // :GetPlayersInRange([range]) - Returns a table with players in range of the WorldObject.
    {"GetCreaturesInRange", &LuaWorldObject::GetCreaturesInRange},          // :GetCreaturesInRange([range, entry]) - Returns a table with creatures of given entry in range of the WorldObject.
    {"GetGameObjectsInRange", &LuaWorldObject::GetGameObjectsInRange},      // :GetGameObjectsInRange([range, entry]) - Returns a table with gameobjects of given entry in range of the WorldObject.
    {"GetNearestPlayer", &LuaWorldObject::GetNearestPlayer},// :GetNearestPlayer([range]) - Returns nearest player in sight or given range.
    {"GetNearestGameObject", &LuaWorldObject::GetNearestGameObject},        // :GetNearestGameObject([range, entry]) - Returns nearest gameobject with given entry in sight or given range entry can be 0 or nil for any.
    {"GetNearestCreature", &LuaWorldObject::GetNearestCreature},            // :GetNearestCreature([range, entry]) - Returns nearest creature with given entry in sight or given range entry can be 0 or nil for any.
    {"GetWorldObject", &LuaWorldObject::GetWorldObject},    // :GetWorldObject(guid) - Returns a world object (creature, player, gameobject) from the guid. The world object returned must be on the same map as the world object in the arguments.

    {NULL, NULL},
};

ElunaRegister<Unit> UnitMethods[] =
{
    // Getters
    {"GetLevel", &LuaUnit::GetLevel},                       // :GetLevel()
    {"GetHealth", &LuaUnit::GetHealth},                     // :GetHealth()
    {"GetDisplayId", &LuaUnit::GetDisplayId},               // :GetDisplayId()
    {"GetNativeDisplayId", &LuaUnit::GetNativeDisplayId},   // :GetNativeDisplayId()
    {"GetPower", &LuaUnit::GetPower},                       // :GetPower(index) - returns power at index. Index can be omitted
    {"GetMaxPower", &LuaUnit::GetMaxPower},                 // :GetMaxPower(index) - returns power at index. Index can be omitted
    {"GetPowerType", &LuaUnit::GetPowerType},               // :GetPowerType() - Returns the power type
    {"GetMaxHealth", &LuaUnit::GetMaxHealth},               // :GetMaxHealth()
    {"GetHealthPct", &LuaUnit::GetHealthPct},               // :GetHealthPct()
    {"GetPowerPct", &LuaUnit::GetPowerPct},                 // :GetPowerPct(power_id)
    {"GetGender", &LuaUnit::GetGender},                     // :GetGender() - returns the gender where male = 0 female = 1
    {"GetRace", &LuaUnit::GetRace},                         // :GetRace()
    {"GetClass", &LuaUnit::GetClass},                       // :GetClass()
    {"GetClassAsString", &LuaUnit::GetClassAsString},       // :GetClassAsString()
    {"GetAura", &LuaUnit::GetAura},                         // :GetAura(spellID) - returns aura object
    {"GetCombatTime", &LuaUnit::GetCombatTime},             // :GetCombatTime() - Returns how long the unit has been in combat
    {"GetFaction", &LuaUnit::GetFaction},                   // :GetFaction() - Returns the unit's factionId
    {"GetCurrentSpell", &LuaUnit::GetCurrentSpell},         // :GetCurrentSpell(type) - Returns the currently casted spell of given type if any
    {"GetCreatureType", &LuaUnit::GetCreatureType},         // :GetCreatureType() - Returns the unit's type
    // {"GetNearbyTarget", &LuaUnit::GetNearbyTarget},      // :GetNearbyTarget([radius[, exclude]]) - Returns nearby target within sight or given radius. Excludes current target and given unit
    {"GetMountId", &LuaUnit::GetMountId},                   // :GetMountId()
    {"GetDistance", &LuaUnit::GetDistance},                 // :GetDistance(WorldObject or x, y, z){"GetRelativePoint", &LuaUnit::GetRelativePoint},       // :GetRelativePoint(dist, rad) - Returns the X, Y and orientation of a point dist away from unit.
    {"GetOwnerGUID", &LuaUnit::GetOwnerGUID},               // :GetOwnerGUID() - Returns the GUID of the owner
    {"GetOwner", &LuaUnit::GetOwner},                       // :GetOwner() - Returns the owner
    {"GetFriendlyUnitsInRange", &LuaUnit::GetFriendlyUnitsInRange},                                         // :GetFriendlyUnitsInRange([range]) - Returns a list of friendly units in range, can return nil
    {"GetUnfriendlyUnitsInRange", &LuaUnit::GetUnfriendlyUnitsInRange},                                     // :GetUnfriendlyUnitsInRange([range]) - Returns a list of unfriendly units in range, can return nil
    {"GetOwnerGUID", &LuaUnit::GetOwnerGUID},               // :GetOwnerGUID() - Returns the UNIT_FIELD_SUMMONEDBY owner
    {"GetCreatorGUID", &LuaUnit::GetCreatorGUID},           // :GetCreatorGUID() - Returns the UNIT_FIELD_CREATEDBY creator
    {"GetMinionGUID", &LuaUnit::GetMinionGUID},             // :GetMinionGUID() - Returns the UNIT_FIELD_SUMMON unit's minion GUID
    {"GetCharmerGUID", &LuaUnit::GetCharmerGUID},           // :GetCharmerGUID() - Returns the UNIT_FIELD_CHARMEDBY charmer
    {"GetCharmGUID", &LuaUnit::GetCharmGUID},               // :GetCharmGUID() - Returns the unit's UNIT_FIELD_CHARM guid
    {"GetPetGUID", &LuaUnit::GetPetGUID},                   // :GetPetGUID() - Returns the unit's pet GUID
    {"GetCritterGUID", &LuaUnit::GetCritterGUID},           // :GetCritterGUID() - Returns the critter's GUID
    {"GetControllerGUID", &LuaUnit::GetControllerGUID},     // :GetControllerGUID() - Returns the Charmer or Owner GUID
    {"GetControllerGUIDS", &LuaUnit::GetControllerGUIDS},   // :GetControllerGUIDS() - Returns the charmer, owner or unit's own GUID
    {"GetStandState", &LuaUnit::GetStandState},             // :GetStandState() - Returns the unit's stand state
    {"GetVictim", &LuaUnit::GetVictim},                     // :GetVictim() - Returns creature's current target
    {"GetStat", &LuaUnit::GetStat},
    {"GetBaseSpellPower", &LuaUnit::GetBaseSpellPower},

    // Setters
    {"SetFaction", &LuaUnit::SetFaction},                   // :SetFaction(factionId) - Sets the unit's faction
    {"SetLevel", &LuaUnit::SetLevel},                       // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                     // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},               // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                       // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                 // :SetMaxPower(index, amount)
    {"SetDisplayId", &LuaUnit::SetDisplayId},               // :SetDisplayId(id)
    {"SetNativeDisplayId", &LuaUnit::SetNativeDisplayId},   // :SetNativeDisplayId(id)
    {"SetFacing", &LuaUnit::SetFacing},                     // :SetFacing(o) - Sets the Unit facing to arg
    {"SetPhaseMask", &LuaUnit::SetPhaseMask},               // :SetPhaseMask(Phase[, update]) - Sets the phase of the unit
    {"SetSpeed", &LuaUnit::SetSpeed},                       // :SetSpeed(type, speed[, forced]) - Sets speed for the movement type (0 = walk, 1 = run ..)
    // {"SetStunned", &LuaUnit::SetStunned},                // :SetStunned([enable]) - Stuns or removes stun
    // {"SetRooted", &LuaUnit::SetRooted},                  // :SetRooted([enable]) - Roots or removes root
    // {"SetConfused", &LuaUnit::SetConfused},              // :SetConfused([enable]) - Sets confused or removes confusion
    // {"SetFeared", &LuaUnit::SetFeared},                  // :SetFeared([enable]) - Fears or removes fear
    {"SetPvP", &LuaUnit::SetPvP},                           // :SetPvP([apply]) - Sets the units PvP on or off
    {"SetFFA", &LuaUnit::SetFFA},                           // :SetFFA([apply]) - Sets the units FFA tag on or off
    {"SetSanctuary", &LuaUnit::SetSanctuary},               // :SetSanctuary([apply]) - Enables or disables units sanctuary flag
    // {"SetCanFly", &LuaUnit::SetCanFly},                  // :SetCanFly(apply)
    // {"SetVisible", &LuaUnit::SetVisible},                // :SetVisible(x)
    {"SetOwnerGUID", &LuaUnit::SetOwnerGUID},               // :SetOwnerGUID(guid) - Sets the guid of the owner
    {"SetName", &LuaUnit::SetName},                         // :SetName(name) - Sets the unit's name
    {"SetSheath", &LuaUnit::SetSheath},                     // :SetSheath(SheathState) - Sets unit's sheathstate
    {"SetCreatorGUID", &LuaUnit::SetCreatorGUID},           // :SetOwnerGUID(uint64 ownerGUID) - Sets the owner's guid of a summoned creature, etc
    {"SetMinionGUID", &LuaUnit::SetMinionGUID},             // :SetCreatorGUID(uint64 creatorGUID) - Sets the UNIT_FIELD_CREATEDBY creator's guid
    {"SetCharmerGUID", &LuaUnit::SetCharmerGUID},           // :SetCharmerGUID(uint64 ownerGUID) - Sets the UNIT_FIELD_CHARMEDBY charmer GUID
    {"SetPetGUID", &LuaUnit::SetPetGUID},                   // :SetPetGUID(uint64 guid) - Sets the pet's guid
    {"SetCritterGUID", &LuaUnit::SetCritterGUID},           // :SetCritterGUID(uint64 guid) - Sets the critter's guid
    {"SetWaterWalk", &LuaUnit::SetWaterWalk},               // :SetWaterWalk([enable]) - Sets WaterWalk on or off

    // Boolean
    {"IsAlive", &LuaUnit::IsAlive},                         // :IsAlive()
    {"IsDead", &LuaUnit::IsDead},                           // :IsDead() - Returns true if the unit is dead, false if they are alive
    {"IsDying", &LuaUnit::IsDying},                         // :IsDying() - Returns true if the unit death state is JUST_DIED.
    {"IsPvPFlagged", &LuaUnit::IsPvPFlagged},               // :IsPvPFlagged()
    {"IsInCombat", &LuaUnit::IsInCombat},                   // :IsInCombat()
    {"IsBanker", &LuaUnit::IsBanker},                       // :IsBanker() - Returns true if the unit is a banker, false if not
    {"IsBattleMaster", &LuaUnit::IsBattleMaster},           // :IsBattleMaster() - Returns true if the unit is a battle master, false if not
    {"IsCharmed", &LuaUnit::IsCharmed},                     // :IsCharmed() - Returns true if the unit is charmed, false if not
    {"IsArmorer", &LuaUnit::IsArmorer},                     // :IsArmorer() - Returns true if the unit is an Armorer, false if not
    {"IsAttackingPlayer", &LuaUnit::IsAttackingPlayer},     // :IsAttackingPlayer() - Returns true if the unit is attacking a player, false if not
    {"IsInWater", &LuaUnit::IsInWater},                     // :IsInWater() - Returns true if the unit is in water
    {"IsUnderWater", &LuaUnit::IsUnderWater},               // :IsUnderWater() - Returns true if the unit is under water
    {"IsAuctioneer", &LuaUnit::IsAuctioneer},               // :IsAuctioneer()
    {"IsGuildMaster", &LuaUnit::IsGuildMaster},             // :IsGuildMaster()
    {"IsInnkeeper", &LuaUnit::IsInnkeeper},                 // :IsInnkeeper()
    {"IsTrainer", &LuaUnit::IsTrainer},                     // :IsTrainer()
    {"IsGossip", &LuaUnit::IsGossip},                       // :IsGossip()
    {"IsTaxi", &LuaUnit::IsTaxi},                           // :IsTaxi()
    {"IsSpiritHealer", &LuaUnit::IsSpiritHealer},           // :IsSpiritHealer()
    {"IsSpiritGuide", &LuaUnit::IsSpiritGuide},             // :IsSpiritGuide()
    {"IsTabardDesigner", &LuaUnit::IsTabardDesigner},       // :IsSpiritGuide()
    {"IsServiceProvider", &LuaUnit::IsServiceProvider},     // :IsServiceProvider()
    {"IsSpiritService", &LuaUnit::IsSpiritService},         // :IsSpiritService()
    {"HealthBelowPct", &LuaUnit::HealthBelowPct},           // :HealthBelowPct(int32 pct)
    {"HealthAbovePct", &LuaUnit::HealthAbovePct},           // :HealthAbovePct(int32 pct)
    {"IsMounted", &LuaUnit::IsMounted},                     // :IsMounted()
    {"AttackStop", &LuaUnit::AttackStop},                   // :AttackStop()
    {"Attack", &LuaUnit::Attack},                           // :Attack(who[, meleeAttack])
    // {"IsVisible", &LuaUnit::IsVisible},                  // :IsVisible()
    // {"IsMoving", &LuaUnit::IsMoving},                    // :IsMoving()
    // {"IsFlying", &LuaUnit::IsFlying},                    // :IsFlying()
    {"IsStopped", &LuaUnit::IsStopped},                     // :IsStopped()
    {"HasUnitState", &LuaUnit::HasUnitState},               // :HasUnitState(state) - state from UnitState enum
    {"IsQuestGiver", &LuaUnit::IsQuestGiver},               // :IsQuestGiver() - Returns true if the unit is a quest giver, false if not
    {"IsWithinDistInMap", &LuaUnit::IsWithinDistInMap},     // :IsWithinDistInMap(worldObject, radius) - Returns if the unit is within distance in map of the worldObject
    {"IsInAccessiblePlaceFor", &LuaUnit::IsInAccessiblePlaceFor},                                           // :IsInAccessiblePlaceFor(creature) - Returns if the unit is in an accessible place for the specified creature
    {"IsVendor", &LuaUnit::IsVendor},                       // :IsVendor() - Returns if the unit is a vendor or not
    {"IsWithinLoS", &LuaUnit::IsWithinLoS},                 // :IsWithinLoS(x, y, z)
    // {"IsRooted", &LuaUnit::IsRooted},                    // :IsRooted()
    {"IsFullHealth", &LuaUnit::IsFullHealth},               // :IsFullHealth() - Returns if the unit is full health

    // Other
    {"RegisterEvent", &LuaUnit::RegisterEvent},             // :RegisterEvent(function, delay, calls)
    {"RemoveEventById", &LuaUnit::RemoveEventById},         // :RemoveEventById(eventID)
    {"RemoveEvents", &LuaUnit::RemoveEvents},               // :RemoveEvents()
    //{"AddAura", &LuaUnit::AddAura},                       // :AddAura(spellId, target) - Adds an aura to the specified target
    {"RemoveAura", &LuaUnit::RemoveAura},                   // :RemoveAura(spellId[, casterGUID]) - Removes an aura from the unit by the spellId, casterGUID(Original caster) is optional
    {"RemoveAllAuras", &LuaUnit::RemoveAllAuras},           // :RemoveAllAuras() - Removes all the unit's auras
    {"ClearInCombat", &LuaUnit::ClearInCombat},             // :ClearInCombat() - Clears the unit's combat list (unit will be out of combat), resets the timer to 0, etc
    {"DeMorph", &LuaUnit::DeMorph},                         // :DeMorph() - Sets display back to native
    {"SendUnitWhisper", &LuaUnit::SendUnitWhisper},         // :SendUnitWhisper(msg, receiver[, bossWhisper]) - Sends a whisper to the receiver
    {"SendUnitEmote", &LuaUnit::SendUnitEmote},             // :SendUnitEmote(msg[, receiver, bossEmote]) - Sends a text emote
    {"SendUnitSay", &LuaUnit::SendUnitSay},                 // :SendUnitSay(msg, language) - Sends a "Say" message with the specified language (all languages: 0)
    {"SendUnitYell", &LuaUnit::SendUnitYell},               // :SendUnitYell(msg, language) - Sends a "Yell" message with the specified language (all languages: 0)
    {"CastSpell", &LuaUnit::CastSpell},                     // :CastSpell(target, spellID[, triggered]) - Casts spell on target (player/npc/creature), if triggered is true then instant cast
    {"CastSpellAoF", &LuaUnit::CastSpellAoF},               // :CastSpellAoF(x, y, z, spellID[, triggered]) - Casts the spell on coordinates, if triggered is false has mana cost and cast time
    {"PlayDirectSound", &LuaUnit::PlayDirectSound},         // :PlayDirectSound(soundId, player) - Unit plays soundID to player, or everyone around if no player
    {"PlayDistanceSound", &LuaUnit::PlayDistanceSound},     // :PlayDistanceSound(soundId, player) - Unit plays soundID to player, or everyone around if no player. The sound fades the further you are
    // {"Kill", &LuaUnit::Kill},                            // :Kill(target, durabilityLoss) - Unit kills the target, if no target then kills the unit. Durabilityloss is true by default
    // {"KnockbackFrom", &LuaUnit::KnockbackFrom},          // :KnockbackFrom(x, y, speedXY, speedZ) - Knocks the player to the opposite direction from x,y at the defined speeds
    // {"JumpTo", &LuaUnit::JumpTo},                        // :JumpTo(WorldObj, speedZ) - Unit jumps to world object
    // {"Jump", &LuaUnit::Jump},                            // :Jump(speedXY, speedZ[, forward]) - Unit jumps at given speeds
    {"JumpToCoords", &LuaUnit::JumpToCoords},               // :JumpToCoords(x, y, z, speedXY, speedZ) - Unit jumps to coordinates at given speeds
    {"MoveTo", &LuaUnit::MoveTo},                           // :MoveTo(id, x, y, z[, generatePath]) - Unit moves to point. ID is sent to WP reach hook
    // {"MoveCharge", &LuaUnit::MoveCharge},                // :MoveCharge(x, y, z, speed) - Charges to target location
    {"MoveChase", &LuaUnit::MoveChase},                     // :MoveChase(target[, dist, angle]) - Chases target unit
    {"MoveFollow", &LuaUnit::MoveFollow},                   // :MoveFollow(target, dist, angle) - Follows target unit
    {"MoveClear", &LuaUnit::MoveClear},                     // :MoveClear() - Stops movement
    {"MoveRandom", &LuaUnit::MoveRandom},                   // :MoveRandom(radius) - Moves randomly inside radius
    // {"MoveRotate", &LuaUnit::MoveRotate},                // :MoveRotate(time, left) - Turns left (true or nil) or right (false) for given time
    {"SummonGameObject", &LuaUnit::SummonGameObject},       // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil
    {"SpawnCreature", &LuaUnit::SpawnCreature},             // :SpawnCreature(entry, x, y, z, o[, despawnDelay]) - Spawns a creature to location that despawns after given time (0 for infinite). Returns the creature or nil
    {"StopSpellCast", &LuaUnit::StopSpellCast},             // :StopSpellCast(spellId(optional)) - Stops the unit from casting a spell. If a spellId is defined, it will stop that unit from casting that spell
    {"InterruptSpell", &LuaUnit::InterruptSpell},           // :InterruptSpell(spellType, delayed(optional), instant(optional)) - Interrupts the unit's spell by the spellType. If delayed is true it will skip if the spell is delayed. If instant is true, it will skip that the spell has a cast time
    {"SendChatMessageToPlayer", &LuaUnit::SendChatMessageToPlayer},                                         // :SendChatMessageToPlayer(type, lang, msg, target) - Unit sends a chat message to the given target player
    {"Emote", &LuaUnit::Emote},                             // :Emote(emote)
    {"CountPctFromCurHealth", &LuaUnit::CountPctFromCurHealth},                                             // :CountPctFromCurHealth(int32 pct)
    {"CountPctFromMaxHealth", &LuaUnit::CountPctFromMaxHealth},                                             // :CountPctFromMaxHealth()
    {"Dismount", &LuaUnit::Dismount},                       // :Dismount() - Dismounts the unit.
    {"Mount", &LuaUnit::Mount},                             // :Mount(displayId) - Mounts the unit on the specified displayId.
    // {"RestoreDisplayId", &LuaUnit::RestoreDisplayId},    // :RestoreDisplayId()
    // {"RestoreFaction", &LuaUnit::RestoreFaction},        // :RestoreFaction()
    // {"RemoveBindSightAuras", &LuaUnit::RemoveBindSightAuras},                                            // :RemoveBindSightAuras()
    // {"RemoveCharmAuras", &LuaUnit::RemoveCharmAuras},    // :RemoveCharmAuras()
    {"StopMoving", &LuaUnit::StopMoving},                   // :StopMoving()
    {"ClearThreatList", &LuaUnit::ClearThreatList},         // :ClearThreatList()
    {"ClearUnitState", &LuaUnit::ClearUnitState},           // :ClearUnitState(state)
    {"AddUnitState", &LuaUnit::AddUnitState},               // :AddUnitState(state)
    {"DisableMelee", &LuaUnit::DisableMelee},               // :DisableMelee([disable]) - if true, enables
    {"SummonGuardian", &LuaUnit::SummonGuardian},           // :SummonGuardian(entry, x, y, z, o[, duration]) - summons a guardian to location. Scales with summoner, is friendly to him and guards him.

    /* Vehicle */
    {"GetVehicle", &LuaUnit::GetVehicle},                 // :GetVehicle() - Returns the unit's vehicle (if it is a vehicle)

    { NULL, NULL },
};

ElunaRegister<Player> PlayerMethods[] =
{
    // Getters
    {"GetSelection", &LuaPlayer::GetSelection},             // :GetSelection()
    {"GetGMRank", &LuaPlayer::GetGMRank},                   // :GetSecurity()
    {"GetGuildId", &LuaPlayer::GetGuildId},                 // :GetGuildId() - nil on no guild
    {"GetCoinage", &LuaPlayer::GetCoinage},                 // :GetCoinage()
    {"GetTeam", &LuaPlayer::GetTeam},                       // :GetTeam() - returns the player's team. 0 for ally, 1 for horde
    {"GetItemCount", &LuaPlayer::GetItemCount},             // :GetItemCount(item_id[, check_bank])
    {"GetGroup", &LuaPlayer::GetGroup},                     // :GetGroup()
    {"GetGuild", &LuaPlayer::GetGuild},                     // :GetGuild()
    {"GetAccountId", &LuaPlayer::GetAccountId},             // :GetAccountId()
    {"GetAccountName", &LuaPlayer::GetAccountName},         // :GetAccountName()
    {"GetArenaPoints", &LuaPlayer::GetArenaPoints},         // :GetArenaPoints()
    {"GetHonorPoints", &LuaPlayer::GetHonorPoints},         // :GetHonorPoints()
    {"GetLifetimeKills", &LuaPlayer::GetLifetimeKills},     // :GetLifetimeKills() - Returns the player's lifetime (honorable) kills
    {"GetPlayerIP", &LuaPlayer::GetPlayerIP},               // :GetPlayerIP() - Returns the player's IP Address
    {"GetLevelPlayedTime", &LuaPlayer::GetLevelPlayedTime}, // :GetLevelPlayedTime() - Returns the player's played time at that level
    {"GetTotalPlayedTime", &LuaPlayer::GetTotalPlayedTime}, // :GetTotalPlayedTime() - Returns the total played time of that player
    {"GetItemByPos", &LuaPlayer::GetItemByPos},             // :GetItemByPos(bag, slot) - Returns item in given slot in a bag (bag: 19-22 slot : 0-35) or inventory (bag: -1 slot : 0-38)
    {"GetReputation", &LuaPlayer::GetReputation},           // :GetReputation(faction) - Gets player's reputation with given faction
    {"GetItemByEntry", &LuaPlayer::GetItemByEntry},         // :GetItemByEntry(entry) - Gets an item if the player has it
    {"GetEquippedItemBySlot", &LuaPlayer::GetEquippedItemBySlot},// :GetEquippedItemBySlot(slotId) - Returns equipped item by slot
    {"GetQuestLevel", &LuaPlayer::GetQuestLevel},           // :GetQuestLevel(quest) - Returns quest's level
    {"GetChatTag", &LuaPlayer::GetChatTag},                 // :GetChatTag() - Returns player chat tag ID
    {"GetRestBonus", &LuaPlayer::GetRestBonus},             // :GetRestBonus() - Gets player's rest bonus
    {"GetRestType", &LuaPlayer::GetRestType},               // :GetRestType() - Returns the player's rest type
    {"GetPhaseMaskForSpawn", &LuaPlayer::GetPhaseMaskForSpawn},                                               // :GetPhaseMaskForSpawn() - Gets the real phasemask for spawning things. Used if the player is in GM mode
    {"GetReqKillOrCastCurrentCount", &LuaPlayer::GetReqKillOrCastCurrentCount},                                        // :GetReqKillOrCastCurrentCount(questId, entry) - Gets the objective (kill or cast) current count done
    {"GetQuestStatus", &LuaPlayer::GetQuestStatus},         // :GetQuestStatus(entry) - Gets the quest's status
    {"GetInGameTime", &LuaPlayer::GetInGameTime},           // :GetInGameTime() - Returns player's ingame time
    {"GetComboPoints", &LuaPlayer::GetComboPoints},         // :GetComboPoints() - Returns player's combo points
    {"GetComboTarget", &LuaPlayer::GetComboTarget},         // :GetComboTarget() - Returns the player's combo target
    {"GetGuildName", &LuaPlayer::GetGuildName},             // :GetGuildName() - Returns player's guild's name or nil
    {"GetFreeTalentPoints", &LuaPlayer::GetFreeTalentPoints}, // :GetFreeTalentPoints() - Returns the amount of unused talent points
    {"GetActiveSpec", &LuaPlayer::GetActiveSpec},           // :GetActiveSpec() - Returns the active specID
    {"GetSpecsCount", &LuaPlayer::GetSpecsCount},           // :GetSpecsCount() - Returns the player's spec count
    {"GetSpellCooldownDelay", &LuaPlayer::GetSpellCooldownDelay},                                             // :GetSpellCooldownDelay(spellId) - Returns the spell's cooldown
    {"GetGuildRank", &LuaPlayer::GetGuildRank},             // :GetGuildRank() - Gets the player's guild rank
    {"GetDifficulty", &LuaPlayer::GetDifficulty},           // :GetDifficulty([isRaid]) - Returns the current difficulty
    {"GetHealthBonusFromStamina", &LuaPlayer::GetHealthBonusFromStamina},                                     // :GetHealthBonusFromStamina() - Returns the HP bonus from stamina
    {"GetManaBonusFromIntellect", &LuaPlayer::GetManaBonusFromIntellect},                                     // :GetManaBonusFromIntellect() - Returns the mana bonus from intellect
    {"GetMaxSkillValue", &LuaPlayer::GetMaxSkillValue},     // :GetMaxSkillValue(skill) - Gets max skill value for the given skill
    {"GetPureMaxSkillValue", &LuaPlayer::GetPureMaxSkillValue},                                               // :GetPureMaxSkillValue(skill) - Gets max base skill value
    {"GetSkillValue", &LuaPlayer::GetSkillValue},           // :GetSkillValue(skill) - Gets current skill value
    {"GetBaseSkillValue", &LuaPlayer::GetBaseSkillValue},   // :GetBaseSkillValue(skill) - Gets current base skill value (no temp bonus)
    {"GetPureSkillValue", &LuaPlayer::GetPureSkillValue},   // :GetPureSkillValue(skill) - Gets current base skill value (no bonuses)
    {"GetSkillPermBonusValue", &LuaPlayer::GetSkillPermBonusValue},                                           // :GetSkillPermBonusValue(skill) - Returns current permanent bonus
    {"GetSkillTempBonusValue", &LuaPlayer::GetSkillTempBonusValue},                                           // :GetSkillTempBonusValue(skill) - Returns current temp bonus
    {"GetReputationRank", &LuaPlayer::GetReputationRank},   // :GetReputationRank(faction) - Returns the reputation rank with given faction
    {"GetSpellCooldowns", &LuaPlayer::GetSpellCooldowns},   // :GetSpellCooldowns() - Gets a table where spellIDs are the keys and values are cooldowns
    {"GetDrunkValue", &LuaPlayer::GetDrunkValue},           // :GetDrunkValue() - Returns the current drunkness value
    {"GetBattlegroundId", &LuaPlayer::GetBattlegroundId},   // :GetBattlegroundId() - Returns the player's current battleground ID
    {"GetBattlegroundTypeId", &LuaPlayer::GetBattlegroundTypeId},                                             // :GetBattlegroundTypeId() - Returns the player's current battleground type ID
    {"GetXPRestBonus", &LuaPlayer::GetXPRestBonus},         // :GetXPRestBonus(xp) - Returns the rested bonus XP from given XP
    {"GetRestTime", &LuaPlayer::GetRestTime},               // :GetRestTime() - Returns the timed rested
    {"GetGroupInvite", &LuaPlayer::GetGroupInvite},         // :GetGroupInvite() - Returns the group invited to
    {"GetSubGroup", &LuaPlayer::GetSubGroup},               // :GetSubGroup() - Gets the player's current subgroup ID
    {"GetNextRandomRaidMember", &LuaPlayer::GetNextRandomRaidMember},                                         // :GetNextRandomRaidMember(radius) - Gets a random raid member in given radius
    {"GetOriginalGroup", &LuaPlayer::GetOriginalGroup},     // :GetOriginalGroup() - Gets the original group object
    {"GetOriginalSubGroup", &LuaPlayer::GetOriginalSubGroup}, // :GetOriginalSubGroup() - Returns the original subgroup ID
    {"GetChampioningFaction", &LuaPlayer::GetChampioningFaction},                                             // :GetChampioningFaction() - Returns the player's championing faction
    {"GetLatency", &LuaPlayer::GetLatency},                 // :GetLatency() - Returns player's latency
    // {"GetRecruiterId", &LuaPlayer::GetRecruiterId},      // :GetRecruiterId() - Returns player's recruiter's ID
    {"GetDbLocaleIndex", &LuaPlayer::GetDbLocaleIndex},     // :GetDbLocaleIndex() - Returns locale index
    {"GetDbcLocale", &LuaPlayer::GetDbcLocale},             // :GetDbcLocale() - Returns DBC locale
    {"GetCorpse", &LuaPlayer::GetCorpse},                   // :GetCorpse() - Returns the player's corpse
    {"GetGossipTextId", &LuaPlayer::GetGossipTextId},       // :GetGossipTextId(worldObject) - Returns the WorldObject's gossip textId
    {"GetQuestRewardStatus", &LuaPlayer::GetQuestRewardStatus},                                               // :GetQuestRewardStatus(questId) - Returns the true/false of the quest reward status
    {"GetShieldBlockValue", &LuaPlayer::GetShieldBlockValue}, // :GetShieldBlockValue() - Returns block value

    // Setters
    {"AdvanceSkillsToMax", &LuaPlayer::AdvanceSkillsToMax}, // :AdvanceSkillsToMax() - Advances all currently known skills to the currently known max level
    {"AdvanceSkill", &LuaPlayer::AdvanceSkill},             // :AdvanceSkill(skill_id, step) - Advances skill by ID and the amount(step)
    {"AdvanceAllSkills", &LuaPlayer::AdvanceAllSkills},     // :AdvanceAllSkills(value) - Advances all current skills to your input(value)
    {"AddLifetimeKills", &LuaPlayer::AddLifetimeKills},     // :AddLifetimeKills(val) - Adds lifetime (honorable) kills to your current lifetime kills
    {"SetCoinage", &LuaPlayer::SetCoinage},                 // :SetCoinage(amount) - sets plr's coinage to this
    {"SetKnownTitle", &LuaPlayer::SetKnownTitle},           // :SetKnownTitle(id)
    {"UnsetKnownTitle", &LuaPlayer::UnsetKnownTitle},       // :UnsetKnownTitle(id)
    {"SetBindPoint", &LuaPlayer::SetBindPoint},             // :SetBindPoint(x, y, z, map, areaid) - sets home for hearthstone
    {"SetArenaPoints", &LuaPlayer::SetArenaPoints},         // :SetArenaPoints(amount)
    {"SetHonorPoints", &LuaPlayer::SetHonorPoints},         // :SetHonorPoints(amount)
    {"SetLifetimeKills", &LuaPlayer::SetLifetimeKills},     // :SetLifetimeKills(val) - Sets the overall lifetime (honorable) kills of the player
    {"SetGameMaster", &LuaPlayer::SetGameMaster},           // :SetGameMaster([on]) - Sets GM mode on or off
    {"SetGMChat", &LuaPlayer::SetGMChat},                   // :SetGMChat([on]) - Sets GM chat on or off
    {"SetTaxiCheat", &LuaPlayer::SetTaxiCheat},             // :SetTaxiCheat([on]) - Sets taxi cheat on or off
    {"SetGMVisible", &LuaPlayer::SetGMVisible},             // :SetGMVisible([on]) - Sets gm visibility on or off
    {"SetPvPDeath", &LuaPlayer::SetPvPDeath},               // :SetPvPDeath([on]) - Sets PvP death on or off
    {"SetAcceptWhispers", &LuaPlayer::SetAcceptWhispers},   // :SetAcceptWhispers([on]) - Sets whisper accepting death on or off
    {"SetRestBonus", &LuaPlayer::SetRestBonus},             // :SetRestBonus(bonusrate) - Sets new restbonus rate
    {"SetRestType", &LuaPlayer::SetRestType},               // :SetRestType() - Sets rest type
    {"SetQuestStatus", &LuaPlayer::SetQuestStatus},         // :SetQuestStatus(entry, status) - Sets the quest's status
    {"SetReputation", &LuaPlayer::SetReputation},           // :SetReputation(faction, value) - Sets the faction reputation for the player
    {"SetFreeTalentPoints", &LuaPlayer::SetFreeTalentPoints}, // :SetFreeTalentPoints(points) - Sets the amount of unused talent points
    {"SetGuildRank", &LuaPlayer::SetGuildRank},             // :SetGuildRank(rank) - Sets player's guild rank
    // {"SetMovement", &LuaPlayer::SetMovement},            // :SetMovement(type) - Sets player's movement type
    {"SetSkill", &LuaPlayer::SetSkill},                     // :SetSkill(skill, step, currVal, maxVal) - Sets the skill's boundaries and value
    {"SetFactionForRace", &LuaPlayer::SetFactionForRace},   // :SetFactionForRace(race) - Sets the faction by raceID
    {"SetDrunkValue", &LuaPlayer::SetDrunkValue},           // :SetDrunkValue(newDrunkValue) - Sets drunkness value
    {"SetRestTime", &LuaPlayer::SetRestTime},               // :SetRestTime(value) - Sets the rested time
    {"SetAtLoginFlag", &LuaPlayer::SetAtLoginFlag},         // :SetAtLoginFlag(flag) - Adds an at login flag
    {"SetPlayerLock", &LuaPlayer::SetPlayerLock},           // :SetPlayerLock(on/off)
    {"SetGender", &LuaPlayer::SetGender},                   // :SetGender(value) - 0 = male 1 = female
    {"SetSheath", &LuaPlayer::SetSheath},                   // :SetSheath(SheathState) - Sets player's sheathstate

    // Boolean
    {"IsInGroup", &LuaPlayer::IsInGroup},                   // :IsInGroup()
    {"IsInGuild", &LuaPlayer::IsInGuild},                   // :IsInGuild()
    {"IsGM", &LuaPlayer::IsGM},                             // :IsGM()
    {"IsAlliance", &LuaPlayer::IsAlliance},                 // :IsAlliance()
    {"IsHorde", &LuaPlayer::IsHorde},                       // :IsHorde()
    {"HasTitle", &LuaPlayer::HasTitle},                     // :HasTitle(id)
    {"HasItem", &LuaPlayer::HasItem},                       // :HasItem(itemId[, count, check_bank]) - Returns true if the player has the item(itemId) and specified count, else it will return false
    {"Teleport", &LuaPlayer::Teleport},                     // :Teleport(Map, X, Y, Z, O) - Teleports player to specified co - ordinates. Returns true if success and false if not
    {"AddItem", &LuaPlayer::AddItem},                       // :AddItem(id, amount) - Adds amount of item to player. Returns true if success and false if not
    {"IsInArenaTeam", &LuaPlayer::IsInArenaTeam},           // :IsInArenaTeam(type) - type : 0 = 2v2, 1 = 3v3, 2 = 5v5
    {"CanEquipItem", &LuaPlayer::CanEquipItem},             // :CanEquipItem(entry/item, slot) - Returns true if the player can equip given item/item entry
    {"IsFalling", &LuaPlayer::IsFalling},                   // :IsFalling() - Returns true if the unit is falling
    {"ToggleAFK", &LuaPlayer::ToggleAFK},                   // :ToggleAFK() - Toggles AFK state for player
    {"ToggleDND", &LuaPlayer::ToggleDND},                   // :ToggleDND() - Toggles DND state for player
    {"IsAFK", &LuaPlayer::IsAFK},                           // :IsAFK() - Returns true if the player is afk
    {"IsDND", &LuaPlayer::IsDND},                           // :IsDND() - Returns true if the player is in dnd mode
    {"IsAcceptingWhispers", &LuaPlayer::IsAcceptingWhispers}, // :IsAcceptWhispers() - Returns true if the player accepts whispers
    {"IsGMChat", &LuaPlayer::IsGMChat},                     // :IsGMChat() - Returns true if the player has GM chat on
    {"IsTaxiCheater", &LuaPlayer::IsTaxiCheater},           // :IsTaxiCheater() - Returns true if the player has taxi cheat on
    {"IsGMVisible", &LuaPlayer::IsGMVisible},               // :IsGMVisible() - Returns true if the player is GM visible
    {"HasQuest", &LuaPlayer::HasQuest},                     // :HasQuest(entry) - Returns true if player has the quest
    {"InBattlegroundQueue", &LuaPlayer::InBattlegroundQueue}, // :InBattlegroundQueue() - Returns true if the player is in a battleground queue
    // {"IsImmuneToEnvironmentalDamage", &LuaPlayer::IsImmuneToEnvironmentalDamage},                          // :IsImmuneToEnvironmentalDamage() - Returns true if the player is immune to enviromental damage
    {"CanSpeak", &LuaPlayer::CanSpeak},                     // :CanSpeak() - Returns true if the player can speak
    {"HasAtLoginFlag", &LuaPlayer::HasAtLoginFlag},         // :HasAtLoginFlag(flag) - returns true if the player has the login flag
    // {"InRandomLfgDungeon", &LuaPlayer::InRandomLfgDungeon}, // :InRandomLfgDungeon() - Returns true if the player is in a random LFG dungeon
    // {"HasPendingBind", &LuaPlayer::HasPendingBind},       // :HasPendingBind() - Returns true if the player has a pending instance bind
    {"HasAchieved", &LuaPlayer::HasAchieved},               // :HasAchieved(achievementID) - Returns true if the player has achieved the achievement
    {"CanUninviteFromGroup", &LuaPlayer::CanUninviteFromGroup},                                               // :CanUninviteFromGroup() - Returns true if the player can uninvite from group
    {"IsRested", &LuaPlayer::IsRested},                     // :IsRested() - Returns true if the player is rested
    // {"CanFlyInZone", &LuaPlayer::CanFlyInZone},           // :CanFlyInZone(mapid, zone) - Returns true if the player can fly in the area
    // {"IsNeverVisible", &LuaPlayer::IsNeverVisible},       // :IsNeverVisible() - Returns true if the player is never visible
    {"IsVisibleForPlayer", &LuaPlayer::IsVisibleForPlayer}, // :IsVisibleForPlayer(player) - Returns true if the player is visible for the target player
    // {"IsUsingLfg", &LuaPlayer::IsUsingLfg},               // :IsUsingLfg() - Returns true if the player is using LFG
    {"HasQuestForItem", &LuaPlayer::HasQuestForItem},       // :HasQuestForItem(entry) - Returns true if the player has the quest for the item
    {"HasQuestForGO", &LuaPlayer::HasQuestForGO},           // :HasQuestForGO(entry) - Returns true if the player has the quest for the gameobject
    {"CanShareQuest", &LuaPlayer::CanShareQuest},           // :CanShareQuest(entry) - Returns true if the quest entry is shareable by the player
    // {"HasReceivedQuestReward", &LuaPlayer::HasReceivedQuestReward},                                           // :HasReceivedQuestReward(entry) - Returns true if the player has recieved the quest's reward
    {"HasTalent", &LuaPlayer::HasTalent},                   // :HasTalent(talentId, spec) - Returns true if the player has the talent in given spec
    {"IsInSameGroupWith", &LuaPlayer::IsInSameGroupWith},   // :IsInSameGroupWith(player) - Returns true if the players are in the same group
    {"IsInSameRaidWith", &LuaPlayer::IsInSameRaidWith},     // :IsInSameRaidWith(player) - Returns true if the players are in the same raid
    {"IsGroupVisibleFor", &LuaPlayer::IsGroupVisibleFor},   // :IsGroupVisibleFor(player) - Player is group visible for the target
    {"HasSkill", &LuaPlayer::HasSkill},                     // :HasSkill(skill) - Returns true if the player has the skill
    {"IsHonorOrXPTarget", &LuaPlayer::IsHonorOrXPTarget},   // :IsHonorOrXPTarget(victim) - Returns true if the victim gives honor or XP
    {"CanParry", &LuaPlayer::CanParry},                     // :CanParry() - Returns true if the player can parry
    {"CanBlock", &LuaPlayer::CanBlock},                     // :CanBlock() - Returns true if the player can block
    {"CanTitanGrip", &LuaPlayer::CanTitanGrip},             // :CanTitanGrip() - Returns true if the player has titan grip
    {"CanTameExoticPets", &LuaPlayer::CanTameExoticPets},   // :CanTameExoticPets() - Returns true if the player can tame exotic pets
    {"InBattleground", &LuaPlayer::InBattleground},         // :InBattleground() - Returns true if the player is in a battleground
    {"InArena", &LuaPlayer::InArena},                       // :InArena() - Returns true if the player is in an arena
    // {"IsOutdoorPvPActive", &LuaPlayer::IsOutdoorPvPActive},   // :IsOutdoorPvPActive() - Returns true if the player is outdoor pvp active
    // {"IsARecruiter", &LuaPlayer::IsARecruiter},          // :IsARecruiter() - Returns true if the player is a recruiter
    {"CanUseItem", &LuaPlayer::CanUseItem},                 // :CanUseItem(item/entry) - Returns true if the player can use the item or item entry
    {"HasSpell", &LuaPlayer::HasSpell},                     // :HasSpell(id)
    {"HasSpellCooldown", &LuaPlayer::HasSpellCooldown},     // :HasSpellCooldown(spellId) - Returns true if the spell is on cooldown
    {"IsInWater", &LuaPlayer::IsInWater},                   // :IsInWater() - Returns true if the player is in water
    {"CanFly", &LuaPlayer::CanFly},                         // :CanFly() - Returns true if the player can fly
    // {"HasAura", &LuaPlayer::HasAura},                    // :HasAura(spellId[, caster]) - Returns true if the unit has the aura from the spell and casted by the caster if provided

    // Gossip
    {"GossipMenuAddItem", &LuaPlayer::GossipMenuAddItem},   // :GossipMenuAddItem(icon, msg, sender, intid[, code, popup, money])
    {"GossipSendMenu", &LuaPlayer::GossipSendMenu},         // :GossipSendMenu(npc_text, unit[, menu_id]) - If unit is a player, you need to use a menu_id. menu_id is used to hook the gossip select function to the menu
    {"GossipComplete", &LuaPlayer::GossipComplete},         // :GossipComplete()
    {"GossipClearMenu", &LuaPlayer::GossipClearMenu},       // :GossipClearMenu() - Clears the gossip menu of options. Pretty much only useful with player gossip. Need to use before creating a new menu for the player

    // Other
    {"SendClearCooldowns", &LuaPlayer::SendClearCooldowns },// :SendClearCooldowns(spellId, (unit)target) - Clears the cooldown of the target with a specified spellId
    {"SendBroadcastMessage", &LuaPlayer::SendBroadcastMessage},                                               // :SendBroadcastMessage(message)
    {"SendAreaTriggerMessage", &LuaPlayer::SendAreaTriggerMessage},                                           // :SendAreaTriggerMessage(message) - Sends a yellow message in the middle of your screen
    {"SendNotification", &LuaPlayer::SendNotification},     // :SendNotification(message) - Sends a red message in the middle of your screen
    {"SendPacketToPlayer", &LuaPlayer::SendPacketToPlayer}, // :SendPacketToPlayer(packet) - Sends a specified packet to the player
    {"SendPacket", &LuaPlayer::SendPacket},                 // :SendPacket(packet) - Sends a specified packet
    // {"SendPacketToGroup", &LuaPlayer::SendPacketToGroup},// :SendPacketToGroup(packet[, sendToPlayersInBattleground(bool)]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground
    // {"SendPacketToGuild", &LuaPlayer::SendPacketToGuild},// :SendPacketToGuild(packet) - Sends a specified packet to your guild
    // {"SendPacketToRankedInGuild", &LuaPlayer::SendPacketToRankedInGuild},                                     // :SendPacketToRankedInGuild(packet, rankId) - Sends a specified packet to your guild, specifying a rankId will only send the packet to your ranked members
    {"SendVendorWindow", &LuaPlayer::SendVendorWindow},     // :SendVendorWindow(unit) - Sends the unit's vendor window to the player
    {"ModifyMoney", &LuaPlayer::ModifyMoney},               // :ModifyMoney(amount[, sendError]) - Modifies (does not set) money (copper count) of the player. Amount can be negative to remove copper
    {"LearnSpell", &LuaPlayer::LearnSpell},                 // :LearnSpell(id) - learns the given spell
    {"RemoveItem", &LuaPlayer::RemoveItem},                 // :RemoveItem(item/entry, amount) - Removes amount of item from player
    {"RemoveLifetimeKills", &LuaPlayer::RemoveLifetimeKills}, // :RemoveLifetimeKills(val) - Removes a specified amount(val) of the player's lifetime (honorable) kills
    {"ResurrectPlayer", &LuaPlayer::ResurrectPlayer},       // :ResurrectPlayer([percent[, sickness(bool)]]) - Resurrects the player at percentage, player gets resurrection sickness if sickness set to true
    {"PlaySoundToPlayer", &LuaPlayer::PlaySoundToPlayer},   // :PlaySoundToPlayer(soundId) - Plays the specified sound to the player
    {"EquipItem", &LuaPlayer::EquipItem},                   // :EquipItem(entry/item, slot) - Equips given item or item entry for player to given slot. Returns the equipped item or nil
    {"ResetSpellCooldown", &LuaPlayer::ResetSpellCooldown}, // :ResetSpellCooldown(spellId, update(bool~optional)) - Resets cooldown of the specified spellId. If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default
    {"ResetTypeCooldowns", &LuaPlayer::ResetTypeCooldowns}, // :ResetTypeCooldowns(category, update(bool~optional)) - Resets all cooldowns for the spell category(type). If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default
    {"ResetAllCooldowns", &LuaPlayer::ResetAllCooldowns},   // :ResetAllCooldowns() - Resets all spell cooldowns
    {"GiveLevel", &LuaPlayer::GiveLevel},                   // :GiveLevel(level) - Gives levels to the player
    {"GiveXP", &LuaPlayer::GiveXP},                         // :GiveXP(xp[, victim, pureXP, triggerHook]) - Gives XP to the player. If pure is false, bonuses are count in. If triggerHook is false, GiveXp hook is not triggered.
    // {"RemovePet", &LuaPlayer::RemovePet},                // :RemovePet([mode, returnreagent]) - Removes the player's pet. Mode determines if the pet is saved and how
    // {"SummonPet", &LuaPlayer::SummonPet},                // :SummonPet(entry, x, y, z, o, petType, despwtime) - Summons a pet for the player
    {"Say", &LuaPlayer::Say},                               // :Say(text, lang) - The player says the text
    {"Yell", &LuaPlayer::Yell},                             // :Yell(text, lang) - The player yells the text
    {"TextEmote", &LuaPlayer::TextEmote},                   // :TextEmote(text) - The player does a textemote with the text
    {"Whisper", &LuaPlayer::Whisper},                       // :Whisper(text, lang, receiverGuid) - The player whispers the text to the guid
    {"CompleteQuest", &LuaPlayer::CompleteQuest},           // :CompleteQuest(entry) - Completes a quest by entry
    {"IncompleteQuest", &LuaPlayer::IncompleteQuest},       // :IncompleteQuest(entry) - Uncompletes the quest by entry for the player
    {"FailQuest", &LuaPlayer::FailQuest},                   // :FailQuest(entry) - Player fails the quest entry
    // {"RemoveActiveQuest", &LuaPlayer::RemoveActiveQuest},// :RemoveActiveQuest(entry) - Removes an active quest
    // {"RemoveRewardedQuest", &LuaPlayer::RemoveRewardedQuest}, // :RemoveRewardedQuest(entry) - Removes a rewarded quest
    {"AreaExploredOrEventHappens", &LuaPlayer::AreaExploredOrEventHappens},                                   // :AreaExploredOrEventHappens(questId) - Satisfies an area or event requrement for the questId
    {"GroupEventHappens", &LuaPlayer::GroupEventHappens},   // :GroupEventHappens(questId, worldObject) - Satisfies a group event for the questId with the world object
    // {"KilledMonsterCredit", &LuaPlayer::KilledMonsterCredit}, // :KilledMonsterCredit(entry) - Satisfies a monsterkill for the player
    // {"KilledPlayerCredit", &LuaPlayer::KilledPlayerCredit},   // :KilledPlayerCredit() - Satisfies a player kill for the player
    // {"KillGOCredit", &LuaPlayer::KillGOCredit},          // :KillGOCredit(GOEntry[, GUID]) - Credits the player for destroying a GO, guid is optional
    {"TalkedToCreature", &LuaPlayer::TalkedToCreature},     // :TalkedToCreature(npcEntry, creature) - Satisfies creature talk objective for the player
    // {"ResetPetTalents", &LuaPlayer::ResetPetTalents},    // :ResetPetTalents() - Resets player's pet's talents
    {"RegenerateAll", &LuaPlayer::RegenerateAll},           // :RegenerateAll() - Regenerates all player's powers
    {"Regenerate", &LuaPlayer::Regenerate},                 // :Regenerate(powerType) - Regenerates the given power type
    {"RegenerateHealth", &LuaPlayer::RegenerateHealth},     // :RegenerateHealth() - Regenerates health
    {"AddComboPoints", &LuaPlayer::AddComboPoints},         // :AddComboPoints(target, count[, spell]) - Adds combo points to the target for the player
    // {"GainSpellComboPoints", &LuaPlayer::GainSpellComboPoints},                                               // :GainSpellComboPoints(amount) - Player gains spell combo points
    {"ClearComboPoints", &LuaPlayer::ClearComboPoints},     // :ClearComboPoints() - Clears player's combo points
    {"RemoveSpell", &LuaPlayer::RemoveSpell},               // :RemoveSpell(entry[, disabled, learn_low_rank]) - Removes (unlearn) the given spell
    {"ResetTalents", &LuaPlayer::ResetTalents},             // :ResetTalents([no_cost]) - Resets player's talents
    {"ResetTalentsCost", &LuaPlayer::ResetTalentsCost},     // :ResetTalentsCost() - Returns the reset talents cost
    // {"AddTalent", &LuaPlayer::AddTalent},                // :AddTalent(spellid, spec, learning) - Adds a talent spell for the player to given spec
    {"RemoveFromGroup", &LuaPlayer::RemoveFromGroup},       // :RemoveFromGroup() - Removes the player from his group
    {"KillPlayer", &LuaPlayer::KillPlayer},                 // :KillPlayer() - Kills the player
    {"DurabilityLossAll", &LuaPlayer::DurabilityLossAll},   // :DurabilityLossAll(percent[, inventory]) - The player's items lose durability. Inventory true by default
    {"DurabilityLoss", &LuaPlayer::DurabilityLoss},         // :DurabilityLoss(item, percent) - The given item loses durability
    {"DurabilityPointsLoss", &LuaPlayer::DurabilityPointsLoss},                                               // :DurabilityPointsLoss(item, points) - The given item loses durability
    {"DurabilityPointsLossAll", &LuaPlayer::DurabilityPointsLossAll},                                         // :DurabilityPointsLossAll(points, inventory) - Player's items lose durability
    {"DurabilityPointLossForEquipSlot", &LuaPlayer::DurabilityPointLossForEquipSlot},                         // :DurabilityPointLossForEquipSlot(slot) - Causes durability loss for the item in the given slot
    {"DurabilityRepairAll", &LuaPlayer::DurabilityRepairAll}, // :DurabilityRepairAll([has_cost, discount, guildBank]) - Repairs all durability
    {"DurabilityRepair", &LuaPlayer::DurabilityRepair},     // :DurabilityRepair(position[, has_cost, discount, guildBank]) - Repairs item durability of item in given position
    {"ModifyHonorPoints", &LuaPlayer::ModifyHonorPoints},   // :ModifyHonorPoints(amount) - Modifies the player's honor points
    {"ModifyArenaPoints", &LuaPlayer::ModifyArenaPoints},   // :ModifyArenaPoints(amount) - Modifies the player's arena points
    {"LeaveBattleground", &LuaPlayer::LeaveBattleground},   // :LeaveBattleground([teleToEntryPoint]) - The player leaves the battleground
    // {"BindToInstance", &LuaPlayer::BindToInstance},      // :BindToInstance() - Binds the player to the current instance
    {"UnbindInstance", &LuaPlayer::UnbindInstance},         // :UnbindInstance(map, difficulty) - Unbinds the player from an instance
    {"RemoveFromBattlegroundOrBattlefieldRaid", &LuaPlayer::RemoveFromBattlegroundOrBattlefieldRaid},         // :RemoveFromBattlegroundOrBattlefieldRaid() - Removes the player from a battleground or battlefield raid
    {"ResetAchievements", &LuaPlayer::ResetAchievements},   // :ResetAchievements() - Resets playeräs achievements
    {"KickPlayer", &LuaPlayer::KickPlayer},                 // :KickPlayer() - Kicks player from server
    {"LogoutPlayer", &LuaPlayer::LogoutPlayer},             // :LogoutPlayer([save]) - Logs the player out and saves if true
    {"SendTrainerList", &LuaPlayer::SendTrainerList},       // :SendTrainerList(WorldObject) - Sends trainer list from object to player
    {"SendListInventory", &LuaPlayer::SendListInventory},   // :SendListInventory(WorldObject) - Sends vendor list from object to player
    {"SendShowBank", &LuaPlayer::SendShowBank},             // :SendShowBank(WorldObject) - Sends bank window from object to player
    {"SendTabardVendorActivate", &LuaPlayer::SendTabardVendorActivate},                                       // :SendTabardVendorActivate(WorldObject) - Sends tabard vendor window from object to player
    {"SendSpiritResurrect", &LuaPlayer::SendSpiritResurrect}, // :SendSpiritResurrect() - Sends resurrect window to player
    {"SendTaxiMenu", &LuaPlayer::SendTaxiMenu},             // :SendTaxiMenu(creature) - Sends flight window to player from creature
    {"RewardQuest", &LuaPlayer::RewardQuest},               // :RewardQuest(entry) - Gives quest rewards for the player
    {"SendAuctionMenu", &LuaPlayer::SendAuctionMenu},       // :SendAuctionMenu([creature, faction]) - Sends auction window to player. Auction house is sent by creature if provided. AH entry is searched with faction or creature's faction if provided
    {"SendMailMenu", &LuaPlayer::SendMailMenu},             // :SendMailMenu(object) - Sends mail window to player from gameobject
    {"StartTaxi", &LuaPlayer::StartTaxi},                   // :StartTaxi(pathId) - player starts the given flight path
    {"GossipSendPOI", &LuaPlayer::GossipSendPOI},           // :GossipSendPOI(X, Y, Icon, Flags, Data, Name) - Sends a point of interest to the player
    {"GossipAddQuests", &LuaPlayer::GossipAddQuests},       // :GossipAddQuests(unit) - Adds unit's quests to player's gossip menu
    {"SendQuestTemplate", &LuaPlayer::SendQuestTemplate},   // :SendQuestTemplate(questId, activeAccept) -- Sends quest template to player
    {"SpawnBones", &LuaPlayer::SpawnBones},                 // :SpawnBones() - Removes the player's corpse and spawns bones
    {"RemovedInsignia", &LuaPlayer::RemovedInsignia},       // :RemovedInsignia(looter) - Looter removes the player's corpse, looting the player and replacing with lootable bones
    {"SendGuildInvite", &LuaPlayer::SendGuildInvite},       // :SendGuildInvite(player) - Sends a guild invite to the specific player
    {"CreateCorpse", &LuaPlayer::CreateCorpse},             // :CreateCorpse() - Creates the player's corpse
    {"Mute", &LuaPlayer::Mute},                             // :Mute(time[, reason]) - Mutes the player for given time in seconds.
    {"SummonPlayer", &LuaPlayer::SummonPlayer},             // :SummonPlayer(player, map, x, y, z, zoneId[, delay]) - Sends a popup to the player asking if he wants to be summoned if yes, teleported to coords. ZoneID defines the location name shown in the popup Delay is the time until the popup closes automatically.
    {"SaveToDB", &LuaPlayer::SaveToDB},                     // :SaveToDB() - Saves to database

    {NULL, NULL},
};

ElunaRegister<Creature> CreatureMethods[] =
{
    // Getters
    {"GetAITarget", &LuaCreature::GetAITarget},             // :GetAITarget(type[, playeronly, position, distance, aura]) - Get an unit in threat list
    {"GetAITargets", &LuaCreature::GetAITargets},           // :GetAITargets() - Get units in threat list
    {"GetAITargetsCount", &LuaCreature::GetAITargetsCount},                                                     // :GetAITargetsCount() - Get threat list size
    // {"GetNearestTargetInAttackDistance", &LuaCreature::GetNearestTargetInAttackDistance},                    // :GetNearestTargetInAttackDistance([radius]) - Returns nearest target in attack distance and within given radius, if set
    // {"GetNearestTarget", &LuaCreature::GetNearestTarget},                                                    // :GetNearestTarget([radius]) - Returns nearest target in sight or given radius
    // {"GetNearestHostileTargetInAggroRange", &LuaCreature::GetNearestHostileTargetInAggroRange},              // :GetNearestHostileTargetInAggroRange([checkLOS]) - Returns closest hostile target in aggro range of the creature
    {"GetHomePosition", &LuaCreature::GetHomePosition},     // :GetHomePosition() - Returns x,y,z,o of spawn position
    // {"GetTransportHomePosition", &LuaCreature::GetTransportHomePosition},                                    // :GetTransportHomePosition() - Returns x,y,z,o of transport spawn position
    {"GetCorpseDelay", &LuaCreature::GetCorpseDelay},       // :GetCorpseDelay() - Returns corpse delay
    {"GetCreatureSpellCooldownDelay", &LuaCreature::GetCreatureSpellCooldownDelay},                             // :GetCreatureSpellCooldownDelay(spellId) - Returns spell cooldown delay
    {"GetScriptId", &LuaCreature::GetScriptId},             // :GetScriptId() - Returns creature's script ID
    {"GetAIName", &LuaCreature::GetAIName},                 // :GetAIName() - Returns creature's AI name
    {"GetScriptName", &LuaCreature::GetScriptName},         // :GetScriptName() - Returns creature's script name
    {"GetReactState", &LuaCreature::GetReactState},         // :GetReactState() - Returns creature's react state
    {"GetAttackDistance", &LuaCreature::GetAttackDistance}, // :GetAttackDistance(unit) - Returns attack distance to unit
    {"GetAggroRange", &LuaCreature::GetAggroRange},         // :GetAggroRange(unit) - Returns aggro distance to unit
    {"GetDefaultMovementType", &LuaCreature::GetDefaultMovementType},                                           // :GetDefaultMovementType() - Returns default movement type
    {"GetRespawnDelay", &LuaCreature::GetRespawnDelay},     // :GetRespawnDelay() - Returns respawn delay
    {"GetRespawnRadius", &LuaCreature::GetRespawnRadius},   // :GetRespawnRadius() - Returns respawn radius
    // {"GetWaypointPath", &LuaCreature::GetWaypointPath},  // :GetWaypointPath() - Returns waypoint path ID
    // {"GetCurrentWaypointId", &LuaCreature::GetCurrentWaypointId},                                            // :GetCurrentWaypointId() - Returns waypoint ID
    // {"GetLootMode", &LuaCreature::GetLootMode},          // :GetLootMode() - Returns loot mode
    {"GetLootRecipient", &LuaCreature::GetLootRecipient},   // :GetLootRecipient() - Returns loot receiver
    {"GetLootRecipientGroup", &LuaCreature::GetLootRecipientGroup},                                             // :GetLootRecipientGroup() - Returns loot receiver group
    {"GetNPCFlags", &LuaCreature::GetNPCFlags},             // :GetNPCFlags() - Returns NPC flags
    {"GetShieldBlockValue", &LuaCreature::GetShieldBlockValue},                                                 // :GetShieldBlockValue() - Returns block value

    // Setters
    {"SetHover", &LuaCreature::SetHover},                   // :SetHover([enable]) - Sets hover on or off
    // {"SetDisableGravity", &LuaCreature::SetDisableGravity},                                                  // :SetDisableGravity([disable, packetOnly]) - Disables or enables gravity
    {"SetReactState", &LuaCreature::SetReactState},         // :SetReactState(state) - Sets react state
    {"SetNoCallAssistance", &LuaCreature::SetNoCallAssistance},                                                 // :SetNoCallAssistance([noCall]) - Sets call assistance to false or true
    {"SetNoSearchAssistance", &LuaCreature::SetNoSearchAssistance},                                             // :SetNoSearchAssistance([noSearch]) - Sets assistance searhing to false or true
    {"SetDefaultMovementType", &LuaCreature::SetDefaultMovementType},                                           // :SetDefaultMovementType(type) - Sets default movement type
    {"SetRespawnDelay", &LuaCreature::SetRespawnDelay},     // :SetRespawnDelay(delay) - Sets the respawn delay
    {"SetRespawnRadius", &LuaCreature::SetRespawnRadius},   // :SetRespawnRadius(dist) - Sets the respawn radius
    {"SetInCombatWithZone", &LuaCreature::SetInCombatWithZone},                                                 // :SetInCombatWithZone() - Sets the creature in combat with everyone in zone
    {"SetDisableReputationGain", &LuaCreature::SetDisableReputationGain},                                       // :SetDisableReputationGain([disable]) - Disables or enables reputation gain from creature
    // {"SetLootMode", &LuaCreature::SetLootMode},          // :SetLootMode(lootMode) - Sets the lootmode
    {"SetNPCFlags", &LuaCreature::SetNPCFlags},             // :SetNPCFlags(flags) - Sets NPC flags
    {"SetDeathState", &LuaCreature::SetDeathState},         // :SetDeathState(value) - 0 = alive 1 = just died 2 = corpse 3 = dead
    {"SetWalk", &LuaCreature::SetWalk},                     // :SetWalk([enable]) - If false, creature runs, otherwise walks

    // Booleans
    {"IsWorldBoss", &LuaCreature::IsWorldBoss},             // :IsWorldBoss() - Returns true if the creature is a WorldBoss, false if not
    // {"IsDungeonBoss", &LuaCreature::IsDungeonBoss},      // :IsDungeonBoss() - Returns true if the creature is a DungeonBoss, false if not
    {"IsRacialLeader", &LuaCreature::IsRacialLeader},       // :IsRacialLeader() - Returns true if the creature is a racial leader, false if not
    {"IsCivilian", &LuaCreature::IsCivilian},               // :IsCivilian() - Returns true if the creature is a civilian, false if not
    // {"IsTrigger", &LuaCreature::IsTrigger},              // :IsTrigger() - Returns true if the creature is a trigger, false if not
    {"IsGuard", &LuaCreature::IsGuard},                     // :IsGuard() - Returns true if the creature is a guard, false if not
    {"IsElite", &LuaCreature::IsElite},                     // :IsElite() - Returns true if the creature is an elite, false if not
    {"IsInEvadeMode", &LuaCreature::IsInEvadeMode},         // :IsInEvadeMode() - Returns true if the creature is in evade mode, false if not
    {"HasCategoryCooldown", &LuaCreature::HasCategoryCooldown}, // :HasCategoryCooldown(spellId) - Returns true if the creature has a cooldown for the spell's category
    {"CanWalk", &LuaCreature::CanWalk},                     // :CanWalk() - Returns true if the creature can walk
    {"CanSwim", &LuaCreature::CanSwim},                     // :CanSwim() - Returns true if the creature can swim
    {"HasReactState", &LuaCreature::HasReactState},         // :HasReactState(state) - Returns true if the creature has react state
    // {"CanStartAttack", &LuaCreature::CanStartAttack},    // :CanStartAttack(unit[, force]) - Returns true if the creature can attack the unit
    {"HasSearchedAssistance", &LuaCreature::HasSearchedAssistance},                                             // :HasSearchedAssistance() - Returns true if the creature has searched assistance
    {"CanAssistTo", &LuaCreature::CanAssistTo},             // :CanAssistTo(unit, enemy[, checkfaction]) - Returns true if the creature can assist unit with enemy
    {"IsTargetAcceptable", &LuaCreature::IsTargetAcceptable},   // :IsTargetAcceptable(unit) - Returns true if the creature can target unit
    {"HasInvolvedQuest", &LuaCreature::HasInvolvedQuest},   // :HasInvolvedQuest(questId) - Returns true if the creature can finish the quest for players
    {"IsRegeneratingHealth", &LuaCreature::IsRegeneratingHealth},                                               // :IsRegeneratingHealth() - Returns true if the creature is regenerating health
    {"IsReputationGainDisabled", &LuaCreature::IsReputationGainDisabled},                                       // :IsReputationGainDisabled() - Returns true if the creature has reputation gain disabled
    // {"IsDamageEnoughForLootingAndReward", &LuaCreature::IsDamageEnoughForLootingAndReward},                  // :IsDamageEnoughForLootingAndReward()
    // {"HasLootMode", &LuaCreature::HasLootMode},
    {"HasSpell", &LuaCreature::HasSpell},                   // :HasSpell(id)
    {"HasQuest", &LuaCreature::HasQuest},                   // :HasQuest(id)
    {"HasSpellCooldown", &LuaCreature::HasSpellCooldown},   // :HasSpellCooldown(spellId) - Returns true if the spell is on cooldown
    {"CanFly", &LuaCreature::CanFly},                       // :CanFly() - Returns true if the creature can fly

    // Other
    // {"Despawn", &LuaCreature::Despawn},                      // :Despawn([despawnDelay]) - Creature despawns after given time
    {"FleeToGetAssistance", &LuaCreature::FleeToGetAssistance}, // :FleeToGetAssistance() - Creature flees for assistance
    {"CallForHelp", &LuaCreature::CallForHelp},              // :CallForHelp(radius) - Creature calls for help from units in radius
    {"CallAssistance", &LuaCreature::CallAssistance},        // :CallAssistance() - Creature calls for assistance
    {"RemoveCorpse", &LuaCreature::RemoveCorpse},            // :RemoveCorpse([setSpawnTime]) - Removes corpse
    {"DespawnOrUnsummon", &LuaCreature::DespawnOrUnsummon},  // :DespawnOrUnsummon([Delay]) - Despawns the creature after delay if given
    {"Respawn", &LuaCreature::Respawn},                      // :Respawn([force]) - Respawns the creature
    // {"AddLootMode", &LuaCreature::AddLootMode},           // :AddLootMode(lootMode)
    // {"DealDamage", &LuaCreature::DealDamage},             // :DealDamage(target, amount) - Deals damage to target (if target) : if no target, unit will damage self
    // {"SendCreatureTalk", &LuaCreature::SendCreatureTalk}, // :SendCreatureTalk(id, playerGUID) - Sends a chat message to a playerGUID (player) by id. Id can be found in creature_text under the 'group_id' column
    {"AttackStart", &LuaCreature::AttackStart},              // :AttackStart(target) - Creature attacks the specified target
    // {"ResetLootMode", &LuaCreature::ResetLootMode},
    // {"RemoveLootMode", &LuaCreature::RemoveLootMode},
    {"SaveToDB", &LuaCreature::SaveToDB},                    // :SaveToDB() - Saves to database
    {"SelectVictim", &LuaCreature::SelectVictim},            // :SelectVictim() - Selects a victim

    {NULL, NULL},
};

ElunaRegister<GameObject> GameObjectMethods[] =
{
    // Getters
    {"GetDisplayId", &LuaGameObject::GetDisplayId},         // :GetDisplayId()
    {"GetRelativePoint", &LuaGameObject::GetRelativePoint}, // :GetRelativePoint(dist, radians) - Returns the X, Y and orientation of a point dist away from gob. Radian 0 point is the direction the unit is facing.
    {"GetGoState", &LuaGameObject::GetGoState},             // :GetGoState() - Returns state
    {"GetLootState", &LuaGameObject::GetLootState},         // :GetLootState() - Returns loot state

    // Setters
    {"SetGoState", &LuaGameObject::SetGoState},
    {"SetLootState", &LuaGameObject::SetLootState},

    // Boolean
    {"IsTransport", &LuaGameObject::IsTransport},           // :IsTransport()
    // {"IsDestructible", &LuaGameObject::IsDestructible},  // :IsDestructible()
    {"IsActive", &LuaGameObject::IsActive},                 // :IsActive()
    {"HasQuest", &LuaGameObject::HasQuest},                 // :HasQuest(questId)
    {"IsSpawned", &LuaGameObject::IsSpawned},               // :IsSpawned()

    // Other
    {"Move", &LuaGameObject::Move},                         // :Move(x, y, z, o) - Moves the GO to coordinates
    {"SpawnCreature", &LuaGameObject::SummonCreature},      // :SpawnCreature(entry, x, y, z, o, [, spawnType, despawnTimer]) - Spawns a creature to location that despawns depending on your TempSummon type and how long you give it to despawn. SpawnType [TempSummon Type] and despawnTimer are optional.
    {"RegisterEvent", &LuaGameObject::RegisterEvent},       // :RegisterEvent(function, delay, calls)
    {"RemoveEventById", &LuaGameObject::RemoveEventById},   // :RemoveEventById(eventID)
    {"RemoveEvents", &LuaGameObject::RemoveEvents},         // :RemoveEvents()
    {"SummonGameObject", &LuaGameObject::SummonGameObject}, // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil
    {"UseDoorOrButton", &LuaGameObject::UseDoorOrButton},   // :UseDoorOrButton(delay) - Activates/closes/opens after X delay UNDOCUMENTED
    {"Despawn", &LuaGameObject::Despawn},                   // :Despawn([delay]) - Despawns the object after delay
    {"Respawn", &LuaGameObject::Respawn},                   // :Respawn([delay]) - respawns the object after delay
    {"SaveToDB", &LuaGameObject::SaveToDB},                 // :SaveToDB() - Saves to database

    { NULL, NULL },
};

ElunaRegister<Vehicle> VehicleMethods[] =
{
    /* Getters */
    {"GetBase", &LuaVehicle::GetBase},                      // :GetBase() - Returns the vehicle base (unit)
    {"GetAvailableSeatCount", &LuaVehicle::GetAvailableSeatCount}, // :GetAvailableSeatCount() - Returns the available seats
    {"GetCreatureEntry", &LuaVehicle::GetCreatureEntry},    // :GetCreatureEntry() - Returns the vehicle's entryId
    {"GetPassenger", &LuaVehicle::GetPassenger},            // :GetPassenger(seatId) - Returns the passenger (unit) by seatId
    /* Boolean */
    {"HasEmptySeat", &LuaVehicle::HasEmptySeat},            // :HasEmptySeat(seatId) - Returns true if the specified seatId is empty
    {"IsVehicleInUse", &LuaVehicle::IsVehicleInUse},        // :IsVehicleInUse() - Returns true if the vehicle is being used
    /* Other */
    {"InstallAccessory", &LuaVehicle::InstallAccessory},    // :InstallAccessory(entry, seatId, bool minion, typeId, summonTime) - Installs an accessory
    {"ApplyAllImmunities", &LuaVehicle::ApplyAllImmunities}, // :ApplyAllImmunities() - Applies all Vehicle immunities
    {"AddPassenger", &LuaVehicle::AddPassenger},            // :AddPassenger(passenger, seatId) - Adds a vehicle passenger
    {"EjectPassenger", &LuaVehicle::EjectPassenger},        // :EjectPassenger(passenger, controller) - Disabled for now
    {"RelocatePassengers", &LuaVehicle::RelocatePassengers}, // :RelocatePassengers() - Relocates Passengers
    {"RemoveAllPassengers", &LuaVehicle::RemoveAllPassengers}, // :RemoveAllPassengers() - Removes all Passengers from the Vehicle
    {"RemovePassenger", &LuaVehicle::RemovePassenger},      // :RemovePassenger(passenger) - Removes the passenger from the vehicle
    {"RemovePendingEventsForPassenger", &LuaVehicle::RemovePendingEventsForPassenger}, // :RemovePendingEventsForPassenger(passenger) - Removes pending join events from the passenger
    {"Reset", &LuaVehicle::Reset},                          // :Reset(evading) - Resets the vehicle, the boolean is optional

    { NULL, NULL },
};

ElunaRegister<Item> ItemMethods[] =
{
    // Getters
    {"GetOwnerGUID", &LuaItem::GetOwnerGUID},               // :GetOwnerGUID() - Returns the owner's guid
    {"GetOwner", &LuaItem::GetOwner},                       // :GetOwner() - Returns the owner object (player)
    {"GetCount", &LuaItem::GetCount},                       // :GetCount() - Returns item stack count
    {"GetMaxStackCount", &LuaItem::GetMaxStackCount},       // :GetMaxStackCount() - Returns item max stack count
    {"GetSlot", &LuaItem::GetSlot},                         // :GetSlot() - returns the slot the item is in
    {"GetBagSlot", &LuaItem::GetBagSlot},                   // :GetBagSlot() - returns the bagslot of the bag the item is in
    {"GetEnchantmentId", &LuaItem::GetEnchantmentId},       // :GetEnchantmentId(enchant_slot) - Returns the enchantment in given slot. (permanent = 0)
    {"GetSpellId", &LuaItem::GetSpellId},                   // :GetSpellId(index) - Returns spellID at given index (0 - 4)
    {"GetSpellTrigger", &LuaItem::GetSpellTrigger},         // :GetSpellTrigger(index) - Returns spell trigger at given index (0 - 4)
    {"GetItemLink", &LuaItem::GetItemLink},               // :GetItemLink([localeID]) - Returns the shift clickable link of the item. Name translated if locale given and exists
    {"GetClass", &LuaItem::GetClass},                       // :GetClass()
    {"GetSubClass", &LuaItem::GetSubClass},                 // :GetSubClass()
    {"GetName", &LuaItem::GetName},                         // :GetName()
    {"GetDisplayId", &LuaItem::GetDisplayId},               // :GetDisplayId()
    {"GetQuality", &LuaItem::GetQuality},                   // :GetQuality()
    {"GetBuyCount", &LuaItem::GetBuyCount},                 // :GetBuyCount()
    {"GetBuyPrice", &LuaItem::GetBuyPrice},                 // :GetBuyPrice()
    {"GetSellPrice", &LuaItem::GetSellPrice},               // :GetSellPrice()
    {"GetInventoryType", &LuaItem::GetInventoryType},       // :GetInventoryType()
    {"GetAllowableClass", &LuaItem::GetAllowableClass},     // :GetAllowableClass()
    {"GetAllowableRace", &LuaItem::GetAllowableRace},       // :GetAllowableRace()
    {"GetItemLevel", &LuaItem::GetItemLevel},               // :GetItemLevel()
    {"GetRequiredLevel", &LuaItem::GetRequiredLevel},       // :GetRequiredLevel()
    {"GetStatsCount", &LuaItem::GetStatsCount},             // :GetStatsCount()
    {"GetRandomProperty", &LuaItem::GetRandomProperty},     // :GetRandomProperty()
    {"GetRandomSuffix", &LuaItem::GetRandomSuffix},         // :GetRandomSuffix()
    {"GetItemSet", &LuaItem::GetItemSet},                   // :GetItemSet()
    {"GetBagSize", &LuaItem::GetBagSize},                   // :GetBagSize()

    // Setters
    {"SetOwner", &LuaItem::SetOwner},                       // :SetOwner(player) - Sets the owner of the item
    {"SetBinding", &LuaItem::SetBinding},                   // :SetBinding(bound) - Sets the item binding to true or false
    {"SetCount", &LuaItem::SetCount},                       // :SetCount(count) - Sets the item count

    // Boolean
    {"IsSoulBound", &LuaItem::IsSoulBound},                 // :IsSoulBound() - Returns true if the item is soulbound
    {"IsBoundAccountWide", &LuaItem::IsBoundAccountWide},   // :IsBoundAccountWide() - Returns true if the item is account bound
    {"IsBoundByEnchant", &LuaItem::IsBoundByEnchant},       // :IsBoundByEnchant() - Returns true if the item is bound with an enchant
    {"IsNotBoundToPlayer", &LuaItem::IsNotBoundToPlayer},   // :IsNotBoundToPlayer(player) - Returns true if the item is not bound with player
    {"IsLocked", &LuaItem::IsLocked},                       // :IsLocked() - Returns true if the item is locked
    {"IsBag", &LuaItem::IsBag},                             // :IsBag() - Returns true if the item is a bag
    {"IsCurrencyToken", &LuaItem::IsCurrencyToken},         // :IsCurrencyToken() - Returns true if the item is a currency token
    {"IsNotEmptyBag", &LuaItem::IsNotEmptyBag},             // :IsNotEmptyBag() - Returns true if the item is not an empty bag
    {"IsBroken", &LuaItem::IsBroken},                       // :IsBroken() - Returns true if the item is broken
    {"CanBeTraded", &LuaItem::CanBeTraded},                 // :CanBeTraded() - Returns true if the item can be traded
    {"IsInTrade", &LuaItem::IsInTrade},                     // :IsInTrade() - Returns true if the item is in trade
    {"IsInBag", &LuaItem::IsInBag},                         // :IsInBag() - Returns true if the item is in a bag
    {"IsEquipped", &LuaItem::IsEquipped},                   // :IsEquipped() - Returns true if the item is equipped
    {"HasQuest", &LuaItem::HasQuest},                       // :HasQuest(questId) - Returns true if the item starts the quest
    {"IsPotion", &LuaItem::IsPotion},                       // :IsPotion() - Returns true if the item is a potion
    {"IsWeaponVellum", &LuaItem::IsWeaponVellum},           // :IsWeaponVellum() - Returns true if the item is a weapon vellum
    {"IsArmorVellum", &LuaItem::IsArmorVellum},             // :IsArmorVellum() - Returns true if the item is an armor vellum
    {"IsConjuredConsumable", &LuaItem::IsConjuredConsumable},                                               // :IsConjuredConsumable() - Returns true if the item is a conjured consumable
    // {"IsRefundExpired", &LuaItem::IsRefundExpired},      // :IsRefundExpired() - Returns true if the item's refund time has expired
    {"SetEnchantment", &LuaItem::SetEnchantment},           // :SetEnchantment(enchantid, enchantmentslot) - Sets a new enchantment for the item. Returns true on success
    {"ClearEnchantment", &LuaItem::ClearEnchantment},       // :ClearEnchantment(enchantmentslot) - Removes the enchantment from the item if one exists. Returns true on success

    // Other
    {"SaveToDB", &LuaItem::SaveToDB},                       // :SaveToDB() - Saves to database

    {NULL, NULL},
};

ElunaRegister<Aura> AuraMethods[] =
{
    // Getters
    {"GetCaster", &LuaAura::GetCaster},                     // :GetCaster() - Returns caster as object
    {"GetCasterGUID", &LuaAura::GetCasterGUID},             // :GetCasterGUID() - Returns caster as GUID
    {"GetCasterLevel", &LuaAura::GetCasterLevel},           // :GetCasterLevel() - Returns casters level
    {"GetDuration", &LuaAura::GetDuration},                 // :GetDuration() - Returns remaining duration
    {"GetMaxDuration", &LuaAura::GetMaxDuration},           // :GetMaxDuration() - Returns maximum duration
    {"GetCharges", &LuaAura::GetCharges},                   // :GetCharges() - Returns remaining charges
    {"GetAuraId", &LuaAura::GetAuraId},                     // :GetAuraId() - Returns aura ID
    {"GetStackAmount", &LuaAura::GetStackAmount},           // :GetStackAmount() - Returns current stack amount
    {"GetOwner", &LuaAura::GetOwner},                       // :GetOwner() - Gets the unit wearing the aura

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                 // :SetDuration(duration) - Sets remaining duration
    {"SetMaxDuration", &LuaAura::SetMaxDuration},           // :SetMaxDuration(duration) - Sets maximum duration
    {"SetStackAmount", &LuaAura::SetStackAmount},           // :SetStackAmount(amount) - Sets current stack amount

    // Other
    {"Remove", &LuaAura::Remove},                           // :Remove() - Removes the aura

    {NULL, NULL},
};

ElunaRegister<Spell> SpellMethods[] =
{
    // Getters
    {"GetCaster", &LuaSpell::GetCaster},                    // :GetCaster() - Returns the spell's caster (UNIT)
    {"GetCastTime", &LuaSpell::GetCastTime},                // :GetCastTime() - Returns the spell cast time
    {"GetEntry", &LuaSpell::GetId},                         // :GetEntry() - Returns the spell's ID
    {"GetDuration", &LuaSpell::GetDuration},                // :GetDuration() - Returns the spell's duration
    {"GetPowerCost", &LuaSpell::GetPowerCost},              // :GetPowerCost() - Returns the spell's power cost (mana, energy, rage, etc)
    {"GetTargetDest", &LuaSpell::GetTargetDest},            // :GetTargetDest() - Returns the target destination (x,y,z,o,map) or nil. Orientation and map may be 0.

    // Setters
    {"SetAutoRepeat", &LuaSpell::SetAutoRepeat},            // :SetAutoRepeat(boolean)

    // Boolean
    {"IsAutoRepeat", &LuaSpell::IsAutoRepeat},              // :IsAutoRepeat()

    // Other
    {"Cancel", &LuaSpell::cancel},                          // :Cancel() - Cancels the spell casting
    {"Cast", &LuaSpell::Cast},                              // :Cast(skipCheck) - Casts the spell (if true, removes the check for instant spells, etc)
    {"Finish", &LuaSpell::Finish},                          // :Finish() - Finishes the spell (SPELL_STATE_FINISH)

    {NULL, NULL},
};

ElunaRegister<Quest> QuestMethods[] =
{
    // Getters
    {"GetId", &LuaQuest::GetId},                            // :GetId() - Returns the quest's Id
    {"GetLevel", &LuaQuest::GetLevel},                      // :GetLevel() - Returns the quest's level
    {"GetMaxLevel", &LuaQuest::GetMaxLevel},                // :GetMaxLevel() - Returns the quest's max level
    {"GetMinLevel", &LuaQuest::GetMinLevel},                // :GetMinLevel() - Returns the quest's min level
    {"GetNextQuestId", &LuaQuest::GetNextQuestId},          // :GetNextQuestId() - Returns the quest's next quest ID
    {"GetPrevQuestId", &LuaQuest::GetPrevQuestId},          // :GetPrevQuestId() - Returns the quest's previous quest ID
    {"GetNextQuestInChain", &LuaQuest::GetNextQuestInChain},// :GetNexQuestInChain() - Returns the next quest in its chain
    {"GetFlags", &LuaQuest::GetFlags},                      // :GetFlags() - Returns the quest's flags
    {"GetType", &LuaQuest::GetType},                        // :GetType() - Returns the quest's type

    // Boolean
    {"HasFlag", &LuaQuest::HasFlag},                        // :HasFlag(flag) - Returns true or false if the quest has the specified flag
    {"IsDaily", &LuaQuest::IsDaily},                        // :IsDaily() - Returns true or false if the quest is a daily
    {"IsRepeatable", &LuaQuest::IsRepeatable},              // :IsRepeatable() - Returns true or false if the quest is repeatable

    // Setters
    {"SetFlag", &LuaQuest::SetFlag},                        // :SetFlag(flag) - Sets the flag of the quest by the specified flag

    {NULL, NULL},
};

ElunaRegister<Group> GroupMethods[] =
{
    // Getters
    {"GetMembers", &LuaGroup::GetMembers},                  // :GetMembers() - returns a table the players in this group. (Online?)
    {"GetLeaderGUID", &LuaGroup::GetLeaderGUID},
    {"GetLeader", &LuaGroup::GetLeader},
    {"GetGUID", &LuaGroup::GetGUID},
    {"GetMemberGroup", &LuaGroup::GetMemberGroup},          // :GetMemberGroup(player) - Returns the player's subgroup ID
    {"GetMemberGUID", &LuaGroup::GetMemberGUID},            // :GetMemberGUID("name") - Returns the member's GUID
    {"GetMembersCount", &LuaGroup::GetMembersCount},        // :GetMembersCount() - Returns the member count of the group

    // Setters
    {"SetLeader", &LuaGroup::ChangeLeader},                 // :SetLeader(Player) - Sets the player as the new leader
    {"SetMembersGroup", &LuaGroup::ChangeMembersGroup},     // :ChangeMembersGroup(player, subGroup) - Changes the member's subgroup

    // Boolean
    {"IsLeader", &LuaGroup::IsLeader},                      // :IsLeader("name"/Player)
    {"AddInvite", &LuaGroup::AddInvite},                    // :AddInvite(player) - Adds a an invite to player. Returns true if succesful
    {"RemoveMember", &LuaGroup::RemoveMember},              // :RemoveMember(player) - Removes player from group. Returns true on success
    {"Disband", &LuaGroup::Disband},                        // :Disband() - Disbands the group
    {"IsFull", &LuaGroup::IsFull},                          // :IsFull() - Returns true if the group is full
    // {"IsLFGGroup", &LuaGroup::isLFGGroup},               // :IsLFGGroup() - Returns true if the group is an LFG group
    {"IsRaidGroup", &LuaGroup::isRaidGroup},                // :IsRaidGroup() - Returns true if the group is a raid group
    {"IsBGGroup", &LuaGroup::isBGGroup},                    // :IsBGGroup() - Returns true if the group is a battleground group
    // {"IsBFGroup", &LuaGroup::isBFGroup},                 // :IsBFGroup() - Returns true if the group is a battlefield group
    {"IsMember", &LuaGroup::IsMember},                      // :IsMember(player) - Returns true if the player is a member of the group
    {"IsAssistant", &LuaGroup::IsAssistant},                // :IsAssistant(player) - returns true if the player is an assistant in the group
    {"SameSubGroup", &LuaGroup::SameSubGroup},              // :SameSubGroup(player1, player2) - Returns true if the players are in the same subgroup in the group
    {"HasFreeSlotSubGroup", &LuaGroup::HasFreeSlotSubGroup},// :HasFreeSlotSubGroup(subGroup) - Returns true if the subgroupID has free slots

    // Other
    {"SendPacket", &LuaGroup::SendPacket},                  // :SendPacket(packet, sendToPlayersInBattleground[, ignoreguid]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground. Optionally ignores given player guid
    // {"ConvertToLFG", &LuaGroup::ConvertToLFG},           // :ConvertToLFG() - Converts the group to an LFG group
    {"ConvertToRaid", &LuaGroup::ConvertToRaid},            // :ConvertToRaid() - Converts the group to a raid group

    {NULL, NULL},
};

ElunaRegister<Guild> GuildMethods[] =
{
    // Getters
    {"GetMembers", &LuaGuild::GetMembers},                  // :GetMembers() - returns a table containing the players in this guild. (Online?)
    {"GetLeader", &LuaGuild::GetLeader},                    // :GetLeader() - Returns the guild learder's object
    {"GetLeaderGUID", &LuaGuild::GetLeaderGUID},            // :GetLeaderGUID() - Returns the guild learder's guid
    {"GetId", &LuaGuild::GetId},                            // :GetId() - Gets the guild's ID
    {"GetName", &LuaGuild::GetName},                        // :GetName() - Gets the guild name
    {"GetMOTD", &LuaGuild::GetMOTD},                        // :GetMOTD() - Gets the guild MOTD string
    {"GetInfo", &LuaGuild::GetInfo},                        // :GetInfo() - Gets the guild info string
    // {"GetBankMoney", &LuaGuild::GetBankMoney},           // :GetBankMoney() - Returns the money currently in the guild bank
    {"GetMemberCount", &LuaGuild::GetMemberCount},          // :GetMemberCount() - Returns the amount of players in the guild

    // Setters
    {"SetBankTabText", &LuaGuild::SetBankTabText},          // :SetBankTabText(tabId, text)
    {"SetMemberRank", &LuaGuild::ChangeMemberRank},         // :SetMemberRank(player, newRank) - Sets the player rank in the guild to the new rank
    {"SetLeader", &LuaGuild::SetLeader},                    // :SetLeader() - Sets the guild's leader

    // Boolean

    // Other
    {"ChangeMemberRank", &LuaGuild::ChangeMemberRank},      // :ChangeMemberRank(player, rankId) - Changes players rank to rank specified
    {"SendPacket", &LuaGuild::SendPacket},                  // :SendPacket(packet) - sends packet to guild
    {"SendPacketToRanked", &LuaGuild::SendPacketToRanked},  // :SendPacketToRanked(packet, rankId) - sends packet to guild, specifying a rankId will only send the packet to your ranked members
    {"Disband", &LuaGuild::Disband},                        // :Disband() - Disbands the guild
    {"AddMember", &LuaGuild::AddMember},                    // :AddMember(player, rank) - adds the player to the guild. Rank is optional
    {"DeleteMember", &LuaGuild::DeleteMember},              // :DeleteMember(player, disbanding, kicked) - Deletes the player from the guild. Disbanding and kicked are optional bools
    // {"DepositBankMoney", &LuaGuild::DepositBankMoney},   // :DepositBankMoney(money) - Deposits money into the guild bank
    // {"WithdrawBankMoney", &LuaGuild::WithdrawBankMoney}, // :WithdrawBankMoney(money) - Withdraws money from the guild bank

    {NULL, NULL},
};

ElunaRegister<QueryResult> QueryMethods[] =
{
    {"NextRow", &LuaQuery::NextRow},                        // :NextRow() - Advances to next rown in the query. Returns true if there is a next row, otherwise false
    {"GetColumnCount", &LuaQuery::GetColumnCount},          // :GetColumnCount() - Gets the column count of the query
    {"GetRowCount", &LuaQuery::GetRowCount},                // :GetRowCount() - Gets the row count of the query

    {"GetBool", &LuaQuery::GetBool},                        // :GetBool(column) - returns a bool from a number column (for example tinyint)
    {"GetUInt8", &LuaQuery::GetUInt8},                      // :GetUInt8(column) - returns the value of an unsigned tinyint column
    {"GetUInt16", &LuaQuery::GetUInt16},                    // :GetUInt16(column) - returns the value of a unsigned smallint column
    {"GetUInt32", &LuaQuery::GetUInt32},                    // :GetUInt32(column) - returns the value of an unsigned int or mediumint column
    {"GetUInt64", &LuaQuery::GetUInt64},                    // :GetUInt64(column) - returns the value of an unsigned bigint column as string
    {"GetInt8", &LuaQuery::GetInt8},                        // :GetInt8(column) - returns the value of an tinyint column
    {"GetInt16", &LuaQuery::GetInt16},                      // :GetInt16(column) - returns the value of a smallint column
    {"GetInt32", &LuaQuery::GetInt32},                      // :GetInt32(column) - returns the value of an int or mediumint column
    {"GetInt64", &LuaQuery::GetInt64},                      // :GetInt64(column) - returns the value of a bigint column as string
    {"GetFloat", &LuaQuery::GetFloat},                      // :GetFloat(column) - returns the value of a float column
    {"GetDouble", &LuaQuery::GetDouble},                    // :GetDouble(column) - returns the value of a double column
    {"GetString", &LuaQuery::GetString},                    // :GetString(column) - returns the value of a string column
    {"IsNull", &LuaQuery::IsNull},                          // :IsNull(column) - returns true if the column is null

    {NULL, NULL},
};

ElunaRegister<WorldPacket> PacketMethods[] =
{
    // Getters
    {"GetOpcode", &LuaPacket::GetOpcode},                   // :GetOpcode() - Returns an opcode
    {"GetSize", &LuaPacket::GetSize},                       // :GetSize() - Returns the packet size

    // Setters
    {"SetOpcode", &LuaPacket::SetOpcode},                   // :SetOpcode(opcode) - Sets the opcode by specifying an opcode

    // Readers
    {"ReadByte", &LuaPacket::ReadByte},                     // :ReadByte() - Reads an int8 value
    {"ReadUByte", &LuaPacket::ReadUByte},                   // :ReadUByte() - Reads an uint8 value
    {"ReadShort", &LuaPacket::ReadShort},                   // :ReadShort() - Reads an int16 value
    {"ReadUShort", &LuaPacket::ReadUShort},                 // :ReadUShort() - Reads an uint16 value
    {"ReadLong", &LuaPacket::ReadLong},                     // :ReadLong() - Reads an int32 value
    {"ReadULong", &LuaPacket::ReadULong},                   // :ReadULong() - Reads an uint32 value
    {"ReadGUID", &LuaPacket::ReadGUID},                     // :ReadGUID() - Reads an uint64 value
    {"ReadString", &LuaPacket::ReadString},                 // :ReadString() - Reads a string value
    {"ReadFloat", &LuaPacket::ReadFloat},                   // :ReadFloat() - Reads a float value
    {"ReadDouble", &LuaPacket::ReadDouble},                 // :ReadDouble() - Reads a double value

    // Writers
    {"WriteByte", &LuaPacket::WriteByte},                   // :WriteByte(val) - Writes an int8 value
    {"WriteUByte", &LuaPacket::WriteUByte},                 // :WriteUByte(val) - Writes a uint8 value
    {"WriteShort", &LuaPacket::WriteShort},                 // :WriteShort(val) - Writes an int16 value
    {"WriteUShort", &LuaPacket::WriteUShort},               // :WriteUShort(val) - Writes a uint16 value
    {"WriteLong", &LuaPacket::WriteLong},                   // :WriteLong(val) - Writes an int32 value
    {"WriteULong", &LuaPacket::WriteULong},                 // :WriteULong(val) - Writes a uint32 value
    {"WriteGUID", &LuaPacket::WriteGUID},                   // :WriteGUID(guid) - Writes a uint64 value
    {"WriteString", &LuaPacket::WriteString},               // :WriteString(val) - Writes a string value
    {"WriteFloat", &LuaPacket::WriteFloat},                 // :WriteFloat(val) - Writes a float value
    {"WriteDouble", &LuaPacket::WriteDouble},               // :WriteDouble(val) - Writes a double value

    {NULL, NULL},
};

ElunaRegister<Map> MapMethods[] =
{
    // Getters
    {"GetName", &LuaMap::GetName},                          // :GetName() - Returns the map's name UNDOCUMENTED
    {"GetDifficulty", &LuaMap::GetDifficulty},              // :GetDifficulty() - Returns the map's difficulty UNDOCUMENTED
    {"GetInstanceId", &LuaMap::GetInstanceId},              // :GetInstanceId() - Returns the map's instance ID UNDOCUMENTED
    {"GetPlayerCount", &LuaMap::GetPlayerCount},            // :GetPlayerCount() - Returns the amount of players on map except GM's UNDOCUMENTED
    {"GetMapId", &LuaMap::GetMapId},                        // :GetMapId() - Returns the map's ID UNDOCUMENTED
    {"GetAreaId", &LuaMap::GetAreaId},                      // :GetAreaId(x, y, z) - Returns the map's area ID based on coords UNDOCUMENTED
    {"GetHeight", &LuaMap::GetHeight},                      // :GetHeight(x, y[, phasemask]) - Returns ground Z coordinate. UNDOCUMENTED

    // Booleans
    {"IsArena", &LuaMap::IsArena},                          // :IsArena() - Returns the true if the map is an arena, else false UNDOCUMENTED
    {"IsBattleground", &LuaMap::IsBattleground},            // :IsBattleground() - Returns the true if the map is a battleground, else false UNDOCUMENTED
    {"IsDungeon", &LuaMap::IsDungeon},                      // :IsDungeon() - Returns the true if the map is a dungeon , else false UNDOCUMENTED
    {"IsEmpty", &LuaMap::IsEmpty},                          // :IsEmpty() - Returns the true if the map is empty, else false UNDOCUMENTED
    {"IsHeroic", &LuaMap::IsHeroic},                        // :IsHeroic() - Returns the true if the map is a heroic dungeon, else false UNDOCUMENTED
    {"IsRaid", &LuaMap::IsRaid},                            // :IsRaid() - Returns the true if the map is a raid map, else false UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Corpse> CorpseMethods[] =
{
    {"GetOwnerGUID", &LuaCorpse::GetOwnerGUID},             // :GetOwnerGUID() - Returns the corpse owner GUID
    {"GetGhostTime", &LuaCorpse::GetGhostTime},             // :GetGhostTime() - Returns the ghost time of a corpse
    {"GetType", &LuaCorpse::GetType},                       // :GetType() - Returns the (CorpseType) of a corpse
    {"ResetGhostTime", &LuaCorpse::ResetGhostTime},         // :ResetGhostTime() - Resets the corpse's ghost time
    {"SaveToDB", &LuaCorpse::SaveToDB},                     // :SaveToDB() - Saves to database
    {"DeleteBonesFromWorld", &LuaCorpse::DeleteBonesFromWorld},                                             // :DeleteBonesFromWorld() - Deletes all bones from the world

    {NULL, NULL}
};

ElunaRegister<Weather> WeatherMethods[] =
{
    // Getters
    {"GetScriptId", &LuaWeather::GetScriptId},              // :GetScriptId() - Returns the weather's scriptId
    {"GetZoneId", &LuaWeather::GetZoneId},                  // :GetZoneId() - Returns the weather's zoneId

    // Setters
    {"SetWeather", &LuaWeather::SetWeather},                // :SetWeather(weatherType, grade) - Sets the weather by weather type and grade

    // Boolean
    {"Regenerate", &LuaWeather::Regenerate},                // :Regenerate() - Calculates weather, returns true if the weather changed
    {"UpdateWeather", &LuaWeather::UpdateWeather},          // :UpdateWeather() - Updates the weather in a zone that has players in it, returns false if players aren't found

    // Other
    {"SendWeatherUpdateToPlayer", &LuaWeather::SendWeatherUpdateToPlayer},                                   // :SendWeatherUpdateToPlayer(player) - Sends weather update to the player

    {NULL, NULL}
};

ElunaRegister<AuctionHouseObject> AuctionMethods[] =
{
    {NULL, NULL}
};

void RegisterFunctions(lua_State* L)
{
    RegisterGlobals(L);
    lua_settop(L, 0); // clean stack

    ElunaTemplate<Object>::Register(L);
    SetMethods(L, ObjectMethods);

    ElunaTemplate<WorldObject>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);

    ElunaTemplate<Unit>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, VehicleMethods);
    SetMethods(L, UnitMethods);

    ElunaTemplate<Player>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, UnitMethods);
    SetMethods(L, PlayerMethods);

    ElunaTemplate<Creature>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, UnitMethods);
    SetMethods(L, CreatureMethods);

    ElunaTemplate<GameObject>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, GameObjectMethods);

    ElunaTemplate<Vehicle>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, UnitMethods);
    SetMethods(L, VehicleMethods);

    ElunaTemplate<Corpse>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, WorldObjectMethods);
    SetMethods(L, CorpseMethods);

    ElunaTemplate<Item>::Register(L);
    SetMethods(L, ObjectMethods);
    SetMethods(L, ItemMethods);

    ElunaTemplate<Group>::Register(L);
    SetMethods(L, GroupMethods);

    ElunaTemplate<Guild>::Register(L);
    SetMethods(L, GuildMethods);

    ElunaTemplate<QueryResult>::Register(L);
    SetMethods(L, QueryMethods);

    ElunaTemplate<Aura>::Register(L);
    SetMethods(L, AuraMethods);

    ElunaTemplate<WorldPacket>::Register(L);
    SetMethods(L, PacketMethods);

    ElunaTemplate<Spell>::Register(L);
    SetMethods(L, SpellMethods);

    ElunaTemplate<Quest>::Register(L);
    SetMethods(L, QuestMethods);

    ElunaTemplate<Map>::Register(L);
    SetMethods(L, MapMethods);

    ElunaTemplate<Weather>::Register(L);
    SetMethods(L, WeatherMethods);

    ElunaTemplate<AuctionHouseObject>::Register(L);

    lua_settop(L, 0); // clean stack
}

#include "LuaEngine.h"
#include "GlobalMethods.h"
#include "UnitMethods.h"
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

void RegisterGlobals(lua_State* L)
{
    // Hooks
    lua_register(L, "RegisterServerHook", &LuaGlobalFunctions::RegisterServerHook);                         // RegisterServerHook(event, function)
    lua_register(L, "RegisterCreatureEvent", &LuaGlobalFunctions::RegisterCreatureEvent);                   // RegisterCreatureEvent(entry, event, function)
    lua_register(L, "RegisterCreatureGossipEvent", &LuaGlobalFunctions::RegisterCreatureGossipEvent);       // RegisterCreatureGossipEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectEvent", &LuaGlobalFunctions::RegisterGameObjectEvent);               // RegisterGameObjectEvent(entry, event, function)
    lua_register(L, "RegisterGameObjectGossipEvent", &LuaGlobalFunctions::RegisterGameObjectGossipEvent);   // RegisterGameObjectGossipEvent(entry, event, function)
    lua_register(L, "RegisterItemEvent", &LuaGlobalFunctions::RegisterItemEvent);                           // RegisterItemEvent(entry, event, function)
    lua_register(L, "RegisterItemGossipEvent", &LuaGlobalFunctions::RegisterItemGossipEvent);               // RegisterItemGossipEvent(entry, event, function)
    lua_register(L, "RegisterPlayerGossipEvent", &LuaGlobalFunctions::RegisterPlayerGossipEvent);           // RegisterPlayerGossipEvent(menu_id, event, function)

    // Getters
    lua_register(L, "GetLuaEngine", &LuaGlobalFunctions::GetLuaEngine);                                     // GetLuaEngine() - Returns ElunaEngine
    lua_register(L, "GetLUAEngine", &LuaGlobalFunctions::GetLuaEngine);                                     // GetLUAEngine() - Returns ElunaEngine
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
    lua_register(L, "FindUnit", &LuaGlobalFunctions::FindUnit);                                             // FindUnit(guid) - Returns unit by it's guid
    lua_register(L, "GetPlayerGUID", &LuaGlobalFunctions::GetPlayerGUID);                                   // GetPlayerGUID(lowguid) - Generates GUID (uint64) string from player lowguid UNDOCUMENTED
    lua_register(L, "GetItemGUID", &LuaGlobalFunctions::GetItemGUID);                                       // GetItemGUID(lowguid) - Generates GUID (uint64) string from item lowguid UNDOCUMENTED
    lua_register(L, "GetObjectGUID", &LuaGlobalFunctions::GetObjectGUID);                                   // GetObjectGUID(lowguid, entry) - Generates GUID (uint64) string from gameobject lowguid and entry UNDOCUMENTED
    lua_register(L, "GetUnitGUID", &LuaGlobalFunctions::GetUnitGUID);                                       // GetUnitGUID(lowguid, entry) - Generates GUID (uint64) string from unit (creature) lowguid and entry UNDOCUMENTED
    lua_register(L, "GetGUIDLow", &LuaGlobalFunctions::GetGUIDLow);                                         // GetGUIDLow(guid) - Returns GUIDLow (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDType", &LuaGlobalFunctions::GetGUIDType);                                       // GetGUIDType(guid) - Returns Type (uint32) from guid (uint64 as string) UNDOCUMENTED
    lua_register(L, "GetGUIDEntry", &LuaGlobalFunctions::GetGUIDEntry);                                     // GetGUIDLow(guid) - Returns Entry (uint32) from guid (uint64 as string), may be always 0 UNDOCUMENTED
    lua_register(L, "bit_not", &LuaGlobalFunctions::bit_not);                                               // bit_not(a) - Returns ~a UNDOCUMENTED
    lua_register(L, "bit_xor", &LuaGlobalFunctions::bit_xor);                                               // bit_xor(a, b) - Returns a ^ b UNDOCUMENTED
    lua_register(L, "bit_rshift", &LuaGlobalFunctions::bit_rshift);                                         // bit_rshift(a, b) - Returns a >> b UNDOCUMENTED
    lua_register(L, "bit_lshift", &LuaGlobalFunctions::bit_lshift);                                         // bit_lshift(a, b) - Returns a << b UNDOCUMENTED
    lua_register(L, "bit_or", &LuaGlobalFunctions::bit_or);                                                 // bit_or(a, b) - Returns a | b UNDOCUMENTED
    lua_register(L, "bit_and", &LuaGlobalFunctions::bit_and);                                               // bit_and(a, b) - Returns a & b UNDOCUMENTED
    lua_register(L, "GetItemLink", &LuaGlobalFunctions::GetItemLink);                                       // GetItemLink(entry[, localeIndex]) - Returns the shift clickable link of the item. Item name translated if translate available for provided locale index UNDOCUMENTED
    lua_register(L, "GetPlayersInRange", &LuaGlobalFunctions::GetPlayersInRange);                           // GetPlayersInRange(WorldObject[, range]) - Returns a table with players in range of the object inserted (player, npc, gameobject..), range defaults to max. Can return nil
    lua_register(L, "GetCreaturesInRange", &LuaGlobalFunctions::GetCreaturesInRange);                       // GetCreaturesInRange(WorldObject[, range]) - Returns a table with creatures in range of the object inserted (player, npc, gameobject..), range defaults to max. Can return nil
    lua_register(L, "GetGameObjectsInRange", &LuaGlobalFunctions::GetGameObjectsInRange);                   // GetGameObjectsInRange(WorldObject[, range]) - Returns a table with gameobjects in range of the object inserted (player, npc, gameobject..), range defaults to max. Can return nil
    lua_register(L, "GetWorldObject", &LuaGlobalFunctions::GetWorldObject);                                 // GetWorldObject(WorldObject, guid) - Returns a world object (creature, player, gameobject) from the guid. The world object returned must be on the same map as the world object in the arguments.
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
    lua_register(L, "CreateLuaEvent", &LuaGlobalFunctions::CreateLuaEvent);                                 // CreateLuaEvent(function, delay, calls) - Creates a timed event. Returns Event ID
    lua_register(L, "RegisterTimedEvent", &LuaGlobalFunctions::CreateLuaEvent);                             // RegisterTimedEvent(function, delay, calls) - Creates a timed event. Returns Event ID
    lua_register(L, "DestroyEventByID", &LuaGlobalFunctions::DestroyEventByID);                             // DestroyEventByID(eventId) - Removes a global timed event by it's ID
    lua_register(L, "DestroyEvents", &LuaGlobalFunctions::DestroyEvents);                                   // DestroyEvents([allEvents]) - Removes all global timed events. Removes all timed events (creature and gameobject) if allEvents is true
    lua_register(L, "PerformIngameSpawn", &LuaGlobalFunctions::PerformIngameSpawn);                         // PerformIngameSpawn(spawntype, entry, mapid, instanceid, x, y, z, o[, save, DurOrResptime, phase]) - spawntype: 1 Creature, 2 Object. DurOrResptime is respawntime for gameobjects and despawntime for creatures if creature is not saved. Returns spawned creature/gameobject
    lua_register(L, "CreatePacket", &LuaGlobalFunctions::CreatePacket);                                     // CreatePacket(opcode, size) - Creates a new packet object
    lua_register(L, "AddVendorItem", &LuaGlobalFunctions::AddVendorItem);                                   // AddVendorItem(entry, itemId, maxcount, incrtime, extendedcost[, persist(bool)]) - Adds an item to vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "VendorRemoveItem", &LuaGlobalFunctions::VendorRemoveItem);                             // VendorRemoveItem(entry, item[, persist(bool)]) - Removes an item from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "VendorRemoveAllItems", &LuaGlobalFunctions::VendorRemoveAllItems);                     // VendorRemoveAllItems(entry[, persist(bool)]) - Removes all items from vendor entry. If persist is false, wont be saved to database.
    lua_register(L, "Kick", &LuaGlobalFunctions::Kick);                                                     // Kick(player) - Kicks given player
    lua_register(L, "Ban", &LuaGlobalFunctions::Ban);                                                       // Ban(banMode(integer), nameOrIP(string), duration(string), reason(string), player(whoBanned)) - Banmode: 0 account, 1 character, 2 IP
    lua_register(L, "SaveAllPlayers", &LuaGlobalFunctions::SaveAllPlayers);                                 // SaveAllPlayers() - Saves all players
    lua_register(L, "SendMail", &LuaGlobalFunctions::SendMail);                                             // SendMail(subject, text, receiverLowGUID[, sender, stationary, delay, itemEntry, itemAmount, itemEntry2, itemAmount2...]) - Sends a mail to player with lowguid. use nil to use default values on optional arguments. Sender is an optional player object. UNDOCUMENTED
    lua_register(L, "AddTaxiPath", &LuaGlobalFunctions::AddTaxiPath);                                       // AddTaxiPath(pathTable, mountA, mountH[, price, pathId]) - Adds a new taxi path. Returns the path's ID. Will replace an existing path if pathId provided and already used. path table structure: T = {{map, x, y, z[, actionFlag, delay, arrivalEvId, departEvId]}, {...}, ...} UDOCUMENTED
}

ElunaRegister<Unit> UnitMethods[] =
{
    // Player Methods
    // Getters
    {"GetSelection", &LuaUnit::GetSelection},                                                               // :GetSelection()
    {"GetGMRank", &LuaUnit::GetGMRank},                                                                     // :GetSecurity()
    {"GetGuildId", &LuaUnit::GetGuildId},                                                                   // :GetGuildId() - nil on no guild
    {"GetCoinage", &LuaUnit::GetCoinage},                                                                   // :GetCoinage()
    {"GetTeam", &LuaUnit::GetTeam},                                                                         // :GetTeam() - returns the player's team. 0 for ally, 1 for horde
    {"GetItemCount", &LuaUnit::GetItemCount},                                                               // :GetItemCount(item_id[, check_bank])
    {"GetGroup", &LuaUnit::GetGroup},                                                                       // :GetGroup()
    {"GetGuild", &LuaUnit::GetGuild},                                                                       // :GetGuild()
    {"GetGearLevel", &LuaUnit::GetGearLevel},                                                               // :GetGearLevel() - Returns the player's average gear level
    {"GetAccountId", &LuaUnit::GetAccountId},                                                               // :GetAccountId()
    {"GetAccountName", &LuaUnit::GetAccountName},                                                           // :GetAccountName()
    {"GetArenaPoints", &LuaUnit::GetArenaPoints},                                                           // :GetArenaPoints()
    {"GetHonorPoints", &LuaUnit::GetHonorPoints},                                                           // :GetHonorPoints()
    {"GetLifetimeKills", &LuaUnit::GetLifetimeKills},                                                       // :GetLifetimeKills() - Returns the player's lifetime (honorable) kills
    {"GetPlayerIP", &LuaUnit::GetPlayerIP},                                                                 // :GetPlayerIP() - Returns the player's IP Address
    {"GetLevelPlayedTime", &LuaUnit::GetLevelPlayedTime},                                                   // :GetLevelPlayedTime() - Returns the player's played time at that level
    {"GetTotalPlayedTime", &LuaUnit::GetTotalPlayedTime},                                                   // :GetTotalPlayedTime() - Returns the total played time of that player
    {"GetInventoryItem", &LuaUnit::GetInventoryItem},                                                       // :GetInventoryItem(slot) - Returns item at given inventory slot (0, 1, 2.. for equipment 19 - 23 for bags, 23 - 39 for backpack)
    {"GetBagItem", &LuaUnit::GetBagItem},                                                                   // :GetBagItem(bagSlot, slot) - Returns item at given slot (0, 1, 2 .. max slots for bag) in a bag (19 - 23)
    {"GetObjectGlobally", &LuaUnit::GetObjectGlobally},                                                     // :GetObjectGlobally(lowguid, entry) - Returns the gameobject of given lowguid and entry if in world
    {"GetNearbyGameObject", &LuaUnit::GetNearbyGameObject},                                                 // :GetNearbyGameObject() - Returns nearby gameobject if found
    {"GetReputation", &LuaUnit::GetReputation},                                                             // :GetReputation(faction) - Gets player's reputation with given faction
    {"GetItemByEntry", &LuaUnit::GetItemByEntry},                                                           // :GetItemByEntry(entry) - Gets an item if the player has it
    {"GetQuestLevel", &LuaUnit::GetQuestLevel},                                                             // :GetQuestLevel(quest) - Returns quest's level
    {"GetChatTag", &LuaUnit::GetChatTag},                                                                   // :GetChatTag() - Returns player chat tag ID
    {"GetRestBonus", &LuaUnit::GetRestBonus},                                                               // :GetRestBonus() - Gets player's rest bonus
    {"GetRestType", &LuaUnit::GetRestType},                                                                 // :GetRestType() - Returns the player's rest type
    {"GetPhaseMaskForSpawn", &LuaUnit::GetPhaseMaskForSpawn},                                               // :GetPhaseMaskForSpawn() - Gets the real phasemask for spawning things. Used if the player is in GM mode
    {"GetReqKillOrCastCurrentCount", &LuaUnit::RemoveRewardedQuest},                                        // :GetReqKillOrCastCurrentCount(questId, entry) - Gets the objective (kill or cast) current count done
    {"GetQuestStatus", &LuaUnit::GetQuestStatus},                                                           // :GetQuestStatus(entry) - Gets the quest's status
    {"GetInGameTime", &LuaUnit::GetInGameTime},                                                             // :GetInGameTime() - Returns player's ingame time
    {"GetComboPoints", &LuaUnit::GetComboPoints},                                                           // :GetComboPoints() - Returns player's combo points
    {"GetComboTarget", &LuaUnit::GetComboTarget},                                                           // :GetComboTarget() - Returns the player's combo target
    {"GetGuildName", &LuaUnit::GetGuildName},                                                               // :GetGuildName() - Returns player's guild's name or nil
    {"GetFreeTalentPoints", &LuaUnit::GetFreeTalentPoints},                                                 // :GetFreeTalentPoints() - Returns the amount of unused talent points
    {"GetActiveSpec", &LuaUnit::GetActiveSpec},                                                             // :GetActiveSpec() - Returns the active specID
    {"GetSpecsCount", &LuaUnit::GetSpecsCount},                                                             // :GetSpecsCount() - Returns the player's spec count
    {"GetSpellCooldownDelay", &LuaUnit::GetSpellCooldownDelay},                                             // :GetSpellCooldownDelay(spellId) - Returns the spell's cooldown
    {"GetGuildRank", &LuaUnit::GetGuildRank},                                                               // :GetGuildRank() - Gets the player's guild rank
    {"GetDifficulty", &LuaUnit::GetDifficulty},                                                             // :GetDifficulty([isRaid]) - Returns the current difficulty
    {"GetHealthBonusFromStamina", &LuaUnit::GetHealthBonusFromStamina},                                     // :GetHealthBonusFromStamina() - Returns the HP bonus from stamina
    {"GetManaBonusFromIntellect", &LuaUnit::GetManaBonusFromIntellect},                                     // :GetManaBonusFromIntellect() - Returns the mana bonus from intellect
    {"GetMaxSkillValue", &LuaUnit::GetMaxSkillValue},                                                       // :GetMaxSkillValue(skill) - Gets max skill value for the given skill
    {"GetPureMaxSkillValue", &LuaUnit::GetPureMaxSkillValue},                                               // :GetPureMaxSkillValue(skill) - Gets max base skill value
    {"GetSkillValue", &LuaUnit::GetSkillValue},                                                             // :GetSkillValue(skill) - Gets current skill value
    {"GetBaseSkillValue", &LuaUnit::GetBaseSkillValue},                                                     // :GetBaseSkillValue(skill) - Gets current base skill value (no temp bonus)
    {"GetPureSkillValue", &LuaUnit::GetPureSkillValue},                                                     // :GetPureSkillValue(skill) - Gets current base skill value (no bonuses)
    {"GetSkillStep", &LuaUnit::GetSkillStep},                                                               // :GetSkillStep(skill) - Returns current skillstep
    {"GetSkillPermBonusValue", &LuaUnit::GetSkillPermBonusValue},                                           // :GetSkillPermBonusValue(skill) - Returns current permanent bonus
    {"GetSkillTempBonusValue", &LuaUnit::GetSkillTempBonusValue},                                           // :GetSkillTempBonusValue(skill) - Returns current temp bonus
    {"GetReputationRank", &LuaUnit::GetReputationRank},                                                     // :GetReputationRank(faction) - Returns the reputation rank with given faction
    {"GetSpellCooldowns", &LuaUnit::GetSpellCooldowns},                                                     // :GetSpellCooldowns() - Gets a table where spellIDs are the keys and values are cooldowns
    {"GetDrunkValue", &LuaUnit::GetDrunkValue},                                                             // :GetDrunkValue() - Returns the current drunkness value
    {"GetBattlegroundId", &LuaUnit::GetBattlegroundId},                                                     // :GetBattlegroundId() - Returns the player's current battleground ID
    {"GetBattlegroundTypeId", &LuaUnit::GetBattlegroundTypeId},                                             // :GetBattlegroundTypeId() - Returns the player's current battleground type ID
    {"GetXPRestBonus", &LuaUnit::GetXPRestBonus},                                                           // :GetXPRestBonus(xp) - Returns the rested bonus XP from given XP
    {"GetRestTime", &LuaUnit::GetRestTime},                                                                 // :GetRestTime() - Returns the timed rested
    {"GetGroupInvite", &LuaUnit::GetGroupInvite},                                                           // :GetGroupInvite() - Returns the group invited to
    {"GetSubGroup", &LuaUnit::GetSubGroup},                                                                 // :GetSubGroup() - Gets the player's current subgroup ID
    {"GetNextRandomRaidMember", &LuaUnit::GetNextRandomRaidMember},                                         // :GetNextRandomRaidMember(radius) - Gets a random raid member in given radius
    {"GetOriginalGroup", &LuaUnit::GetOriginalGroup},                                                       // :GetOriginalGroup() - Gets the original group object
    {"GetOriginalSubGroup", &LuaUnit::GetOriginalSubGroup},                                                 // :GetOriginalSubGroup() - Returns the original subgroup ID
    {"GetChampioningFaction", &LuaUnit::GetChampioningFaction},                                             // :GetChampioningFaction() - Returns the player's championing faction
    {"GetLatency", &LuaUnit::GetLatency},                                                                   // :GetLatency() - Returns player's latency
    {"GetRecruiterId", &LuaUnit::GetRecruiterId},                                                           // :GetRecruiterId() - Returns player's recruiter's ID
    {"GetSelectedPlayer", &LuaUnit::GetSelectedPlayer},                                                     // :GetSelectedPlayer() - Returns player's selected player.
    {"GetSelectedUnit", &LuaUnit::GetSelectedUnit},                                                         // :GetSelectedUnit() - Returns player's selected unit.
    {"GetDbLocaleIndex", &LuaUnit::GetDbLocaleIndex},                                                       // :GetDbLocaleIndex() - Returns locale index
    {"GetDbcLocale", &LuaUnit::GetDbcLocale},                                                               // :GetDbcLocale() - Returns DBC locale

    // Setters
    {"AdvanceSkillsToMax", &LuaUnit::AdvanceSkillsToMax},                                                   // :AdvanceSkillsToMax() - Advances all currently known skills to the currently known max level
    {"AdvanceSkill", &LuaUnit::AdvanceSkill},                                                               // :AdvanceSkill(skill_id, step) - Advances skill by ID and the amount(step)
    {"AdvanceAllSkills", &LuaUnit::AdvanceAllSkills},                                                       // :AdvanceAllSkills(value) - Advances all current skills to your input(value)
    {"AddLifetimeKills", &LuaUnit::AddLifetimeKills},                                                       // :AddLifetimeKills(val) - Adds lifetime (honorable) kills to your current lifetime kills
    {"SetCoinage", &LuaUnit::SetCoinage},                                                                   // :SetCoinage(amount) - sets plr's coinage to this
    {"SetKnownTitle", &LuaUnit::SetKnownTitle},                                                             // :SetKnownTitle(id)
    {"UnsetKnownTitle", &LuaUnit::UnsetKnownTitle},                                                         // :UnsetKnownTitle(id)
    {"SetBindPoint", &LuaUnit::SetBindPoint},                                                               // :SetBindPoint(x, y, z, map, areaid) - sets home for hearthstone
    {"SetBindPointAtPlayerLoc", &LuaUnit::SetBindPointAtPlayerLoc},                                         // :SetBindPointAtPlayerLoc() - Set's home for hearthstone at player's location
    {"SetArenaPoints", &LuaUnit::SetArenaPoints},                                                           // :SetArenaPoints(amount)
    {"SetHonorPoints", &LuaUnit::SetHonorPoints},                                                           // :SetHonorPoints(amount)
    {"SetLifetimeKills", &LuaUnit::SetLifetimeKills},                                                       // :SetLifetimeKills(val) - Sets the overall lifetime (honorable) kills of the player
    {"SetGameMaster", &LuaUnit::SetGameMaster},                                                             // :SetGameMaster([on]) - Sets GM mode on or off
    {"SetGMChat", &LuaUnit::SetGMChat},                                                                     // :SetGMChat([on]) - Sets GM chat on or off
    {"SetTaxiCheat", &LuaUnit::SetTaxiCheat},                                                               // :SetTaxiCheat([on]) - Sets taxi cheat on or off
    {"SetGMVisible", &LuaUnit::SetGMVisible},                                                               // :SetGMVisible([on]) - Sets gm visibility on or off
    {"SetPvPDeath", &LuaUnit::SetPvPDeath},                                                                 // :SetPvPDeath([on]) - Sets PvP death on or off
    {"SetAcceptWhispers", &LuaUnit::SetAcceptWhispers},                                                     // :SetAcceptWhispers([on]) - Sets whisper accepting death on or off
    {"SetRestBonus", &LuaUnit::SetRestBonus},                                                               // :SetRestBonus(bonusrate) - Sets new restbonus rate
    {"SetRestType", &LuaUnit::SetRestType},                                                                 // :SetRestType() - Sets rest type
    {"SetSheath", &LuaUnit::SetSheath},                                                                     // :SetSheath(SheathState) - Sets player's seathstate
    {"SetQuestStatus", &LuaUnit::SetQuestStatus},                                                           // :SetQuestStatus(entry, status) - Sets the quest's status
    {"SetReputation", &LuaUnit::SetReputation},                                                             // :SetReputation(faction, value) - Sets the faction reputation for the player
    {"SetFreeTalentPoints", &LuaUnit::SetFreeTalentPoints},                                                 // :SetFreeTalentPoints(points) - Sets the amount of unused talent points
    {"SetGuildRank", &LuaUnit::SetGuildRank},                                                               // :SetGuildRank(rank) - Sets player's guild rank
    {"SetMovement", &LuaUnit::SetMovement},                                                                 // :SetMovement(type) - Sets player's movement type
    {"SetSkill", &LuaUnit::SetSkill},                                                                       // :SetSkill(skill, step, currVal, maxVal) - Sets the skill's boundaries and value
    {"SetFactionForRace", &LuaUnit::SetFactionForRace},                                                     // :SetFactionForRace(race) - Sets the faction by raceID
    {"SetDrunkValue", &LuaUnit::SetDrunkValue},                                                             // :SetDrunkValue(newDrunkValue) - Sets drunkness value
    {"SetRestTime", &LuaUnit::SetRestTime},                                                                 // :SetRestTime(value) - Sets the rested time
    {"SetAtLoginFlag", &LuaUnit::SetAtLoginFlag},                                                           // :SetAtLoginFlag(flag) - Adds an at login flag
    {"SetPlayerLock", &LuaUnit::SetPlayerLock},                                                             // :SetPlayerLock(on/off)
    {"SetCreatorGUID", &LuaUnit::SetCreatorGUID},                                                           // :SetOwnerGUID(uint64 ownerGUID) - Sets the owner's guid of a summoned creature, etc
    {"SetMinionGUID", &LuaUnit::SetMinionGUID},                                                             // :SetCreatorGUID(uint64 creatorGUID) - Sets the UNIT_FIELD_CREATEDBY creator's guid
    {"SetCharmerGUID", &LuaUnit::SetCharmerGUID},                                                           // :SetCharmerGUID(uint64 ownerGUID) - Sets the UNIT_FIELD_CHARMEDBY charmer GUID
    {"SetPetGUID", &LuaUnit::SetPetGUID},                                                                   // :SetPetGUID(uint64 guid) - Sets the pet's guid
    {"SetCritterGUID", &LuaUnit::SetCritterGUID},                                                           // :SetCritterGUID(uint64 guid) - Sets the critter's guid
    // Boolean
    {"IsWithinLoS", &LuaUnit::IsWithinLoS},                                                                 // :IsWithinLoS(x, y, z)
    {"IsInGroup", &LuaUnit::IsInGroup},                                                                     // :IsInGroup()
    {"IsInGuild", &LuaUnit::IsInGuild},                                                                     // :IsInGuild()
    {"IsGM", &LuaUnit::IsGM},                                                                               // :IsGM()
    {"IsAlliance", &LuaUnit::IsAlliance},                                                                   // :IsAlliance()
    {"IsHorde", &LuaUnit::IsHorde},                                                                         // :IsHorde()
    {"HasTitle", &LuaUnit::HasTitle},                                                                       // :HasTitle(id)
    {"HasItem", &LuaUnit::HasItem},                                                                         // :HasItem(itemId[, count, check_bank]) - Returns true if the player has the item(itemId) and specified count, else it will return false
    {"Teleport", &LuaUnit::Teleport},                                                                       // :Teleport(Map, X, Y, Z, O) - Teleports player to specified co - ordinates. Returns true if success and false if not
    {"AddItem", &LuaUnit::AddItem},                                                                         // :AddItem(id, amount) - Adds amount of item to player. Returns true if success and false if not
    {"IsInArenaTeam", &LuaUnit::IsInArenaTeam},                                                             // :IsInArenaTeam(type) - type : 0 = 2v2, 1 = 3v3, 2 = 5v5
    {"CanEquipItem", &LuaUnit::CanEquipItem},                                                               // :CanEquipItem(entry/item, slot) - Returns true if the player can equip given item/item entry
    {"IsFalling", &LuaUnit::IsFalling},                                                                     // :IsFalling() - Returns true if the unit is falling
    {"ToggleAFK", &LuaUnit::ToggleAFK},                                                                     // :ToggleAFK() - Toggles AFK state for player
    {"ToggleDND", &LuaUnit::ToggleDND},                                                                     // :ToggleDND() - Toggles DND state for player
    {"IsAFK", &LuaUnit::IsAFK},                                                                             // :IsAFK() - Returns true if the player is afk
    {"IsDND", &LuaUnit::IsDND},                                                                             // :IsDND() - Returns true if the player is in dnd mode
    {"IsAcceptingWhispers", &LuaUnit::IsAcceptingWhispers},                                                 // :IsAcceptWhispers() - Returns true if the player accepts whispers
    {"IsGMChat", &LuaUnit::IsGMChat},                                                                       // :IsGMChat() - Returns true if the player has GM chat on
    {"IsTaxiCheater", &LuaUnit::IsTaxiCheater},                                                             // :IsTaxiCheater() - Returns true if the player has taxi cheat on
    {"IsGMVisible", &LuaUnit::IsGMVisible},                                                                 // :IsGMVisible() - Returns true if the player is GM visible
    {"IsActiveQuest", &LuaUnit::IsActiveQuest},                                                             // :IsActiveQuest(entry) - Returns true if the quest entry is active for the player
    {"InBattlegroundQueue", &LuaUnit::InBattlegroundQueue},                                                 // :InBattlegroundQueue() - Returns true if the player is in a battleground queue
    {"IsImmuneToEnvironmentalDamage", &LuaUnit::IsImmuneToEnvironmentalDamage},                             // :IsImmuneToEnvironmentalDamage() - Returns true if the player is immune to enviromental damage
    {"CanSpeak", &LuaUnit::CanSpeak},                                                                       // :CanSpeak() - Returns true if the player can speak
    {"HasAtLoginFlag", &LuaUnit::HasAtLoginFlag},                                                           // :HasAtLoginFlag(flag) - returns true if the player has the login flag
    {"InRandomLfgDungeon", &LuaUnit::InRandomLfgDungeon},                                                   // :InRandomLfgDungeon() - Returns true if the player is in a random LFG dungeon
    {"HasPendingBind", &LuaUnit::HasPendingBind},                                                           // :HasPendingBind() - Returns true if the player has a pending instance bind
    {"HasAchieved", &LuaUnit::HasAchieved},                                                                 // :HasAchieved(achievementID) - Returns true if the player has achieved the achievement
    {"CanUninviteFromGroup", &LuaUnit::CanUninviteFromGroup},                                               // :CanUninviteFromGroup() - Returns true if the player can uninvite from group
    {"IsRested", &LuaUnit::IsRested},                                                                       // :IsRested() - Returns true if the player is rested
    {"CanFlyInZone", &LuaUnit::CanFlyInZone},                                                               // :CanFlyInZone(mapid, zone) - Returns true if the player can fly in the area
    {"IsNeverVisible", &LuaUnit::IsNeverVisible},                                                           // :IsNeverVisible() - Returns true if the player is never visible
    {"IsVisibleForPlayer", &LuaUnit::IsVisibleForPlayer},                                                   // :IsVisibleForPlayer(player) - Returns true if the player is visible for the target player
    {"IsUsingLfg", &LuaUnit::IsUsingLfg},                                                                   // :IsUsingLfg() - Returns true if the player is using LFG
    {"HasQuestForItem", &LuaUnit::HasQuestForItem},                                                         // :HasQuestForItem(entry) - Returns true if the player has the quest for the item
    {"HasQuestForGO", &LuaUnit::HasQuestForGO},                                                             // :HasQuestForGO(entry) - Returns true if the player has the quest for the gameobject
    {"CanShareQuest", &LuaUnit::CanShareQuest},                                                             // :CanShareQuest(entry) - Returns true if the quest entry is shareable by the player
    {"HasReceivedQuestReward", &LuaUnit::HasReceivedQuestReward},                                           // :HasReceivedQuestReward(entry) - Returns true if the player has recieved the quest's reward
    {"HasTalent", &LuaUnit::HasTalent},                                                                     // :HasTalent(spellid, spec) - Returns true if the player has the talent spell in given spec
    {"IsInSameGroupWith", &LuaUnit::IsInSameGroupWith},                                                     // :IsInSameGroupWith(player) - Returns true if the players are in the same group
    {"IsInSameRaidWith", &LuaUnit::IsInSameRaidWith},                                                       // :IsInSameRaidWith(player) - Returns true if the players are in the same raid
    {"IsGroupVisibleFor", &LuaUnit::IsGroupVisibleFor},                                                     // :IsGroupVisibleFor(player) - Player is group visible for the target
    {"HasSkill", &LuaUnit::HasSkill},                                                                       // :HasSkill(skill) - Returns true if the player has the skill
    {"IsHonorOrXPTarget", &LuaUnit::IsHonorOrXPTarget},                                                     // :IsHonorOrXPTarget(victim) - Returns true if the victim gives honor or XP
    {"CanParry", &LuaUnit::CanParry},                                                                       // :CanParry() - Returns true if the player can parry
    {"CanBlock", &LuaUnit::CanBlock},                                                                       // :CanBlock() - Returns true if the player can block
    {"CanTitanGrip", &LuaUnit::CanTitanGrip},                                                               // :CanTitanGrip() - Returns true if the player has titan grip
    {"CanTameExoticPets", &LuaUnit::CanTameExoticPets},                                                     // :CanTameExoticPets() - Returns true if the player can tame exotic pets
    {"InBattleground", &LuaUnit::InBattleground},                                                           // :InBattleground() - Returns true if the player is in a battleground
    {"InArena", &LuaUnit::InArena},                                                                         // :InArena() - Returns true if the player is in an arena
    {"IsOutdoorPvPActive", &LuaUnit::IsOutdoorPvPActive},                                                   // :IsOutdoorPvPActive() - Returns true if the player is outdoor pvp active
    {"IsARecruiter", &LuaUnit::IsARecruiter},                                                               // :IsARecruiter() - Returns true if the player is a recruiter
    {"CanUseItem", &LuaUnit::CanUseItem},                                                                   // :CanUseItem(item/entry) - Returns true if the player can use the item or item entry

    // Gossip
    {"GossipMenuAddItem", &LuaUnit::GossipMenuAddItem},                                                     // :GossipMenuAddItem(icon, msg, sender, intid[, code, popup, money])
    {"GossipSendMenu", &LuaUnit::GossipSendMenu},                                                           // :GossipSendMenu(npc_text, unit[, menu_id]) - If unit is a player, you need to use a menu_id. menu_id is used to hook the gossip select function to the menu
    {"GossipComplete", &LuaUnit::GossipComplete},                                                           // :GossipComplete()
    {"GossipClearMenu", &LuaUnit::GossipClearMenu},                                                         // :GossipClearMenu() - Clears the gossip menu of options. Pretty much only useful with player gossip. Need to use before creating a new menu for the player

    // Other
    {"SendClearCooldowns", &LuaUnit::SendClearCooldowns },                                                  // :SendClearCooldowns(spellId, (unit)target) - Clears the cooldown of the target with a specified spellId
    {"SendBroadcastMessage", &LuaUnit::SendBroadcastMessage},                                               // :SendBroadcastMessage(message)
    {"SendAreaTriggerMessage", &LuaUnit::SendAreaTriggerMessage},                                           // :SendAreaTriggerMessage(message) - Sends a yellow message in the middle of your screen
    {"SendNotification", &LuaUnit::SendNotification},                                                       // :SendNotification(message) - Sends a red message in the middle of your screen
    {"SendPacketToPlayer", &LuaUnit::SendPacketToPlayer},                                                   // :SendPacketToPlayer(packet) - Sends a specified packet to the player
    {"SendPacket", &LuaUnit::SendPacket},                                                                   // :SendPacket(packet) - Sends a specified packet
    {"SendPacketToGroup", &LuaUnit::SendPacketToGroup},                                                     // :SendPacketToGroup(packet[, sendToPlayersInBattleground(bool)]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground
    {"SendPacketToGuild", &LuaUnit::SendPacketToGuild},                                                     // :SendPacketToGuild(packet) - Sends a specified packet to your guild
    {"SendPacketToRankedInGuild", &LuaUnit::SendPacketToRankedInGuild},                                     // :SendPacketToRankedInGuild(packet, rankId) - Sends a specified packet to your guild, specifying a rankId will only send the packet to your ranked members
    {"SendVendorWindow", &LuaUnit::SendVendorWindow},                                                       // :SendVendorWindow(unit) - Sends the unit's vendor window to the player
    {"ModifyMoney", &LuaUnit::ModifyMoney},                                                                 // :ModifyMoney(amount[, sendError]) - Modifies (does not set) money (copper count) of the player. Amount can be negative to remove copper
    {"LearnSpell", &LuaUnit::LearnSpell},                                                                   // :LearnSpell(id) - learns the given spell
    {"RemoveItem", &LuaUnit::RemoveItem},                                                                   // :RemoveItem(item/entry, amount) - Removes amount of item from player
    {"RemoveLifetimeKills", &LuaUnit::RemoveLifetimeKills},                                                 // :RemoveLifetimeKills(val) - Removes a specified amount(val) of the player's lifetime (honorable) kills
    {"ResurrectPlayer", &LuaUnit::ResurrectPlayer},                                                         // :ResurrectPlayer([percent[, sickness(bool)]]) - Resurrects the player at percentage, player gets resurrection sickness if sickness set to true
    {"PlaySoundToPlayer", &LuaUnit::PlaySoundToPlayer},                                                     // :PlaySoundToPlayer(soundId) - Plays the specified sound to the player
    {"EquipItem", &LuaUnit::EquipItem},                                                                     // :EquipItem(entry/item, slot) - Equips given item or item entry for player to given slot. Returns the equipped item or nil
    {"ResetSpellCooldown", &LuaUnit::ResetSpellCooldown},                                                   // :ResetSpellCooldown(spellId, update(bool~optional)) - Resets cooldown of the specified spellId. If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default
    {"ResetTypeCooldowns", &LuaUnit::ResetTypeCooldowns},                                                   // :ResetTypeCooldowns(category, update(bool~optional)) - Resets all cooldowns for the spell category(type). If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default
    {"ResetAllCooldowns", &LuaUnit::ResetAllCooldowns},                                                     // :ResetAllCooldowns() - Resets all spell cooldowns
    {"GiveLevel", &LuaUnit::GiveLevel},                                                                     // :GiveLevel(level) - Gives levels to the player
    {"GiveXP", &LuaUnit::GiveXP},                                                                           // :GiveXP(xp[, victim, group_rate, pureXP, triggerHook]) - Gives XP to the player. If pure is false, bonuses are count in. If triggerHook is false, GiveXp hook is not triggered.
    {"RemovePet", &LuaUnit::RemovePet},                                                                     // :RemovePet([mode, returnreagent]) - Removes the player's pet. Mode determines if the pet is saved and how
    {"SummonPet", &LuaUnit::SummonPet},                                                                     // :SummonPet(entry, x, y, z, o, petType, despwtime) - Summons a pet for the player
    {"Say", &LuaUnit::Say},                                                                                 // :Say(text, lang) - The player says the text
    {"Yell", &LuaUnit::Yell},                                                                               // :Yell(text, lang) - The player yells the text
    {"TextEmote", &LuaUnit::TextEmote},                                                                     // :TextEmote(text) - The player does a textemote with the text
    {"Whisper", &LuaUnit::Whisper},                                                                         // :Whisper(text, lang, receiverGuid) - The player whispers the text to the guid
    {"CompleteQuest", &LuaUnit::CompleteQuest},                                                             // :CompleteQuest(entry) - Completes a quest by entry
    {"IncompleteQuest", &LuaUnit::IncompleteQuest},                                                         // :IncompleteQuest(entry) - Uncompletes the quest by entry for the player
    {"FailQuest", &LuaUnit::FailQuest},                                                                     // :FailQuest(entry) - Player fails the quest entry
    {"RemoveActiveQuest", &LuaUnit::RemoveActiveQuest},                                                     // :RemoveActiveQuest(entry) - Removes an active quest
    {"RemoveRewardedQuest", &LuaUnit::RemoveRewardedQuest},                                                 // :RemoveRewardedQuest(entry) - Removes a rewarded quest
    {"AreaExploredOrEventHappens", &LuaUnit::AreaExploredOrEventHappens},                                   // :AreaExploredOrEventHappens(questId) - Satisfies an area or event requrement for the questId
    {"GroupEventHappens", &LuaUnit::GroupEventHappens},                                                     // :GroupEventHappens(questId, worldObject) - Satisfies a group event for the questId with the world object
    {"KilledMonsterCredit", &LuaUnit::KilledMonsterCredit},                                                 // :KilledMonsterCredit(entry) - Satisfies a monsterkill for the player
    {"KilledPlayerCredit", &LuaUnit::KilledPlayerCredit},                                                   // :KilledPlayerCredit() - Satisfies a player kill for the player
    {"KillGOCredit", &LuaUnit::KillGOCredit},                                                               // :KillGOCredit(GOEntry[, GUID]) - Credits the player for destroying a GO, guid is optional
    {"TalkedToCreature", &LuaUnit::TalkedToCreature},                                                       // :TalkedToCreature(npcEntry, creature) - Satisfies creature talk objective for the player
    {"ResetPetTalents", &LuaUnit::ResetPetTalents},                                                         // :ResetPetTalents() - Resets player's pet's talents
    {"RegenerateAll", &LuaUnit::RegenerateAll},                                                             // :RegenerateAll() - Regenerates all player's powers
    {"Regenerate", &LuaUnit::Regenerate},                                                                   // :Regenerate(powerType) - Regenerates the given power type
    {"RegenerateHealth", &LuaUnit::RegenerateHealth},                                                       // :RegenerateHealth() - Regenerates health
    {"AddComboPoints", &LuaUnit::AddComboPoints},                                                           // :AddComboPoints(target, count[, spell]) - Adds combo points to the target for the player
    {"GainSpellComboPoints", &LuaUnit::GainSpellComboPoints},                                               // :GainSpellComboPoints(amount) - Player gains spell combo points
    {"ClearComboPoints", &LuaUnit::ClearComboPoints},                                                       // :ClearComboPoints() - Clears player's combo points
    {"RemoveSpell", &LuaUnit::RemoveSpell},                                                                 // :RemoveSpell(entry[, disabled, learn_low_rank]) - Removes (unlearn) the given spell
    {"ResetTalents", &LuaUnit::ResetTalents},                                                               // :ResetTalents([no_cost]) - Resets player's talents
    {"ResetTalentsCost", &LuaUnit::ResetTalentsCost},                                                       // :ResetTalentsCost() - Returns the reset talents cost
    {"AddTalent", &LuaUnit::AddTalent},                                                                     // :AddTalent(spellid, spec, learning) - Adds a talent spell for the player to given spec
    {"RemoveFromGroup", &LuaUnit::RemoveFromGroup},                                                         // :RemoveFromGroup() - Removes the player from his group
    {"KillPlayer", &LuaUnit::KillPlayer},                                                                   // :KillPlayer() - Kills the player
    {"DurabilityLossAll", &LuaUnit::DurabilityLossAll},                                                     // :DurabilityLossAll(percent[, inventory]) - The player's items lose durability. Inventory true by default
    {"DurabilityLoss", &LuaUnit::DurabilityLoss},                                                           // :DurabilityLoss(item, percent) - The given item loses durability
    {"DurabilityPointsLoss", &LuaUnit::DurabilityPointsLoss},                                               // :DurabilityPointsLoss(item, points) - The given item loses durability
    {"DurabilityPointsLossAll", &LuaUnit::DurabilityPointsLossAll},                                         // :DurabilityPointsLossAll(points, inventory) - Player's items lose durability
    {"DurabilityPointLossForEquipSlot", &LuaUnit::DurabilityPointLossForEquipSlot},                         // :DurabilityPointLossForEquipSlot(slot) - Causes durability loss for the item in the given slot
    {"DurabilityRepairAll", &LuaUnit::DurabilityRepairAll},                                                 // :DurabilityRepairAll([has_cost, discount, guildBank]) - Repairs all durability
    {"DurabilityRepair", &LuaUnit::DurabilityRepair},                                                       // :DurabilityRepair(position[, has_cost, discount, guildBank]) - Repairs item durability of item in given position
    {"ModifyHonorPoints", &LuaUnit::ModifyHonorPoints},                                                     // :ModifyHonorPoints(amount) - Modifies the player's honor points
    {"ModifyArenaPoints", &LuaUnit::ModifyArenaPoints},                                                     // :ModifyArenaPoints(amount) - Modifies the player's arena points
    {"LeaveBattleground", &LuaUnit::LeaveBattleground},                                                     // :LeaveBattleground([teleToEntryPoint]) - The player leaves the battleground
    {"BindToInstance", &LuaUnit::BindToInstance},                                                           // :BindToInstance() - Binds the player to the current instance
    {"UnbindInstance", &LuaUnit::UnbindInstance},                                                           // :UnbindInstance(map, difficulty) - Unbinds the player from an instance
    {"RemoveFromBattlegroundOrBattlefieldRaid", &LuaUnit::RemoveFromBattlegroundOrBattlefieldRaid},         // :RemoveFromBattlegroundOrBattlefieldRaid() - Removes the player from a battleground or battlefield raid
    {"ResetAchievements", &LuaUnit::ResetAchievements},                                                     // :ResetAchievements() - Resets playeräs achievements
    {"KickPlayer", &LuaUnit::KickPlayer},                                                                   // :KickPlayer() - Kicks player from server
    {"LogoutPlayer", &LuaUnit::LogoutPlayer},                                                               // :LogoutPlayer([save]) - Logs the player out and saves if true
    {"SendTrainerList", &LuaUnit::SendTrainerList},                                                         // :SendTrainerList(WorldObject) - Sends trainer list from object to player
    {"SendListInventory", &LuaUnit::SendListInventory},                                                     // :SendListInventory(WorldObject) - Sends vendor list from object to player
    {"SendShowBank", &LuaUnit::SendShowBank},                                                               // :SendShowBank(WorldObject) - Sends bank window from object to player
    {"SendTabardVendorActivate", &LuaUnit::SendTabardVendorActivate},                                       // :SendTabardVendorActivate(WorldObject) - Sends tabard vendor window from object to player
    {"SendSpiritResurrect", &LuaUnit::SendSpiritResurrect},                                                 // :SendSpiritResurrect() - Sends resurrect window to player
    {"SendTaxiMenu", &LuaUnit::SendTaxiMenu},                                                               // :SendTaxiMenu(creature) - Sends flight window to player from creature
    {"RewardQuest", &LuaUnit::RewardQuest},                                                                 // :RewardQuest(entry) - Gives quest rewards for the player
    {"SendAuctionMenu", &LuaUnit::SendAuctionMenu},                                                         // :SendAuctionMenu([creature, faction]) - Sends auction window to player. Auction house is sent by creature if provided. AH entry is searched with faction or creature's faction if provided
    {"SendMailMenu", &LuaUnit::SendMailMenu},                                                               // :SendMailMenu(object) - Sends mail window to player from gameobject
    {"StartTaxi", &LuaUnit::StartTaxi},                                                                     // :StartTaxi(pathId) - player starts the given flight path
    {"GossipSendPOI", &LuaUnit::GossipSendPOI},                                                             // :GossipSendPOI(X, Y, Icon, Flags, Data, Name) - Sends a point of interest to the player
    {"GossipAddQuests", &LuaUnit::GossipAddQuests},                                                         // :GossipAddQuests(unit) - Adds unit's quests to player's gossip menu
    {"SendQuestTemplate", &LuaUnit::SendQuestTemplate},                                                     // :SendQuestTemplate(questId, activeAccept) -- Sends quest template to player

    // Creature methods
    // Getters
    {"GetAITarget", &LuaUnit::GetAITarget},                                                                 // :GetAITarget(type[, playeronly, position, distance, aura]) - Get an unit in threat list
    {"GetAITargets", &LuaUnit::GetAITargets},                                                               // :GetAITargets() - Get units in threat list
    {"GetAITargetsCount", &LuaUnit::GetAITargetsCount},                                                     // :GetAITargetsCount() - Get threat list size
    {"GetVictim", &LuaUnit::GetVictim},                                                                     // :GetVictim() - Returns creature's current target
    {"GetNearestTargetInAttackDistance", &LuaUnit::GetNearestTargetInAttackDistance},                       // :GetNearestTargetInAttackDistance([radius]) - Returns nearest target in attack distance and within given radius, if set
    {"GetNearestTarget", &LuaUnit::GetNearestTarget},                                                       // :GetNearestTarget([radius]) - Returns nearest target in sight or given radius
    {"GetNearestHostileTargetInAggroRange", &LuaUnit::GetNearestHostileTargetInAggroRange},                 // :GetNearestHostileTargetInAggroRange([checkLOS]) - Returns closest hostile target in aggro range of the creature
    {"GetHomePosition", &LuaUnit::GetHomePosition},                                                         // :GetHomePosition() - Returns x,y,z,o of spawn position
    {"GetTransportHomePosition", &LuaUnit::GetTransportHomePosition},                                       // :GetTransportHomePosition() - Returns x,y,z,o of transport spawn position
    {"GetCorpseDelay", &LuaUnit::GetCorpseDelay},                                                           // :GetCorpseDelay() - Returns corpse delay
    {"GetCreatureSpellCooldownDelay", &LuaUnit::GetCreatureSpellCooldownDelay},                             // :GetCreatureSpellCooldownDelay(spellId) - Returns spell cooldown delay
    {"GetScriptId", &LuaUnit::GetScriptId},                                                                 // :GetScriptId() - Returns creature's script ID
    {"GetAIName", &LuaUnit::GetAIName},                                                                     // :GetAIName() - Returns creature's AI name
    {"GetScriptName", &LuaUnit::GetScriptName},                                                             // :GetScriptName() - Returns creature's script name
    {"GetReactState", &LuaUnit::GetReactState},                                                             // :GetReactState() - Returns creature's react state
    {"GetAttackDistance", &LuaUnit::GetAttackDistance},                                                     // :GetAttackDistance(unit) - Returns attack distance to unit
    {"GetAggroRange", &LuaUnit::GetAggroRange},                                                             // :GetAggroRange(unit) - Returns aggro distance to unit
    {"GetDefaultMovementType", &LuaUnit::GetDefaultMovementType},                                           // :GetDefaultMovementType() - Returns default movement type
    {"GetRespawnDelay", &LuaUnit::GetRespawnDelay},                                                         // :GetRespawnDelay() - Returns respawn delay
    {"GetRespawnRadius", &LuaUnit::GetRespawnRadius},                                                       // :GetRespawnRadius() - Returns respawn radius
    {"GetWaypointPath", &LuaUnit::GetWaypointPath},                                                         // :GetWaypointPath() - Returns waypoint path ID
    {"GetCurrentWaypointId", &LuaUnit::GetCurrentWaypointId},                                               // :GetCurrentWaypointId() - Returns waypoint ID
    {"GetLootMode", &LuaUnit::GetLootMode},                                                                 // :GetLootMode() - Returns loot mode
    {"GetLootRecipient", &LuaUnit::GetLootRecipient},                                                       // :GetLootRecipient() - Returns loot receiver
    {"GetLootRecipientGroup", &LuaUnit::GetLootRecipientGroup},                                             // :GetLootRecipientGroup() - Returns loot receiver group
    {"GetNPCFlags", &LuaUnit::GetNPCFlags},                                                                 // :GetNPCFlags() - Returns NPC flags

    // Setters
    {"SetHover", &LuaUnit::SetHover},                                                                       // :SetHover([enable]) - Sets hover on or off
    {"SetDisableGravity", &LuaUnit::SetDisableGravity},                                                     // :SetDisableGravity([disable, packetOnly]) - Disables or enables gravity
    {"SetReactState", &LuaUnit::SetReactState},                                                             // :SetReactState(state) - Sets react state
    {"SetNoCallAssistance", &LuaUnit::SetNoCallAssistance},                                                 // :SetNoCallAssistance([noCall]) - Sets call assistance to false or true
    {"SetNoSearchAssistance", &LuaUnit::SetNoSearchAssistance},                                             // :SetNoSearchAssistance([noSearch]) - Sets assistance searhing to false or true
    {"SetDefaultMovementType", &LuaUnit::SetDefaultMovementType},                                           // :SetDefaultMovementType(type) - Sets default movement type
    {"SetRespawnDelay", &LuaUnit::SetRespawnDelay},                                                         // :SetRespawnDelay(delay) - Sets the respawn delay
    {"SetRespawnRadius", &LuaUnit::SetRespawnRadius},                                                       // :SetRespawnRadius(dist) - Sets the respawn radius
    {"SetInCombatWithZone", &LuaUnit::SetInCombatWithZone},                                                 // :SetInCombatWithZone() - Sets the creature in combat with everyone in zone
    {"SetDisableReputationGain", &LuaUnit::SetDisableReputationGain},                                       // :SetDisableReputationGain([disable]) - Disables or enables reputation gain from creature
    {"SetLootMode", &LuaUnit::SetLootMode},                                                                 // :SetLootMode(lootMode) - Sets the lootmode
    {"SetNPCFlags", &LuaUnit::SetNPCFlags},                                                                 // :SetNPCFlags(flags) - Sets NPC flags

    // Booleans
    {"IsWorldBoss", &LuaUnit::IsWorldBoss},                                                                 // :IsWorldBoss() - Returns true if the creature is a WorldBoss, false if not
    {"IsDungeonBoss", &LuaUnit::IsDungeonBoss},                                                             // :IsDungeonBoss() - Returns true if the creature is a DungeonBoss, false if not
    {"IsRacialLeader", &LuaUnit::IsRacialLeader},                                                           // :IsRacialLeader() - Returns true if the creature is a racial leader, false if not
    {"IsCivilian", &LuaUnit::IsCivilian},                                                                   // :IsCivilian() - Returns true if the creature is a civilian, false if not
    {"IsTrigger", &LuaUnit::IsTrigger},                                                                     // :IsTrigger() - Returns true if the creature is a trigger, false if not
    {"IsGuard", &LuaUnit::IsGuard},                                                                         // :IsGuard() - Returns true if the creature is a guard, false if not
    {"IsElite", &LuaUnit::IsElite},                                                                         // :IsElite() - Returns true if the creature is an elite, false if not
    {"IsInEvadeMode", &LuaUnit::IsInEvadeMode},                                                             // :IsInEvadeMode() - Returns true if the creature is in evade mode, false if not
    {"HasCategoryCooldown", &LuaUnit::HasCategoryCooldown},                                                 // :HasCategoryCooldown(spellId) - Returns true if the creature has a cooldown for the spell's category
    {"CanWalk", &LuaUnit::CanWalk},                                                                         // :CanWalk() - Returns true if the creature can walk
    {"CanSwim", &LuaUnit::CanSwim},                                                                         // :CanSwim() - Returns true if the creature can swim
    {"HasReactState", &LuaUnit::HasReactState},                                                             // :HasReactState(state) - Returns true if the creature has react state
    {"CanStartAttack", &LuaUnit::CanStartAttack},                                                           // :CanStartAttack(unit[, force]) - Returns true if the creature can attack the unit
    {"HasSearchedAssistance", &LuaUnit::HasSearchedAssistance},                                             // :HasSearchedAssistance() - Returns true if the creature has searched assistance
    {"CanAssistTo", &LuaUnit::CanAssistTo},                                                                 // :CanAssistTo(unit, enemy[, checkfaction]) - Returns true if the creature can assist unit with enemy
    {"IsTargetAcceptable", &LuaUnit::IsTargetAcceptable},                                                   // :IsTargetAcceptable(unit) - Returns true if the creature can target unit
    {"HasInvolvedQuest", &LuaUnit::HasInvolvedQuest},                                                       // :HasInvolvedQuest(questId) - Returns true if the creature can finish the quest for players
    {"IsRegeneratingHealth", &LuaUnit::IsRegeneratingHealth},                                               // :IsRegeneratingHealth() - Returns true if the creature is regenerating health
    {"IsReputationGainDisabled", &LuaUnit::IsReputationGainDisabled},                                       // :IsReputationGainDisabled() - Returns true if the creature has reputation gain disabled
    {"IsDamageEnoughForLootingAndReward", &LuaUnit::IsDamageEnoughForLootingAndReward},                     // :IsDamageEnoughForLootingAndReward()

    // Other
    {"Despawn", &LuaUnit::Despawn},                                                                         // :Despawn([despawnDelay]) - Creature despawns after given time
    {"FleeToGetAssistance", &LuaUnit::FleeToGetAssistance},                                                 // :FleeToGetAssistance() - Creature flees for assistance
    {"CallForHelp", &LuaUnit::CallForHelp},                                                                 // :CallForHelp(radius) - Creature calls for help from units in radius
    {"CallAssistance", &LuaUnit::CallAssistance},                                                           // :CallAssistance() - Creature calls for assistance
    {"RemoveCorpse", &LuaUnit::RemoveCorpse},                                                               // :RemoveCorpse([setSpawnTime]) - Removes corpse
    {"DespawnOrUnsummon", &LuaUnit::DespawnOrUnsummon},                                                     // :DespawnOrUnsummon([Delay]) - Despawns the creature after delay if given
    {"Respawn", &LuaUnit::Respawn},                                                                         // :Respawn([force]) - Respawns the creature
    {"SelectVictim", &LuaUnit::SelectVictim},                                                               // :SelectVictim() - Returns a victim or nil
    {"AddLootMode", &LuaUnit::AddLootMode},                                                                 // :AddLootMode(lootMode)
    {"DealDamage", &LuaUnit::DealDamage},                                                                   // :DealDamage(target, amount) - Deals damage to target (if target) : if no target, unit will damage self

    // Unit Methods
    // Getters
    {"GetName", &LuaUnit::GetName},                                                                         // :GetName()
    {"GetLevel", &LuaUnit::GetLevel},                                                                       // :GetLevel()
    {"GetHealth", &LuaUnit::GetHealth},                                                                     // :GetHealth()
    {"GetDisplayId", &LuaUnit::GetDisplayId},                                                               // :GetDisplayId()
    {"GetNativeDisplayId", &LuaUnit::GetNativeDisplayId},                                                   // :GetNativeDisplayId()
    {"GetGUID", &LuaUnit::GetGUID},                                                                         // :GetGUID() - Returns uint64 guid as hex string
    {"GetMapId", &LuaUnit::GetMapId},                                                                       // :GetMapId()
    {"GetX", &LuaUnit::GetX},                                                                               // :GetX()
    {"GetY", &LuaUnit::GetY},                                                                               // :GetY()
    {"GetZ", &LuaUnit::GetZ},                                                                               // :GetZ()
    {"GetO", &LuaUnit::GetO},                                                                               // :GetO()
    {"GetLocation", &LuaUnit::GetLocation},                                                                 // :GetLocation() - returns X, Y, Z and O co - ords (in that order)
    {"GetAreaId", &LuaUnit::GetAreaId},                                                                     // :GetAreaId()
    {"GetZoneId", &LuaUnit::GetZoneId},                                                                     // :GetZoneId()
    {"GetPower", &LuaUnit::GetPower},                                                                       // :GetPower(index) - returns power at index. Index can be omitted
    {"GetMaxPower", &LuaUnit::GetMaxPower},                                                                 // :GetMaxPower(index) - returns power at index. Index can be omitted
    {"GetPowerType", &LuaUnit::GetPowerType},                                                               // :GetPowerType() - Returns the power type
    {"GetMaxHealth", &LuaUnit::GetMaxHealth},                                                               // :GetMaxHealth()
    {"GetHealthPct", &LuaUnit::GetHealthPct},                                                               // :GetHealthPct()
    {"GetPowerPct", &LuaUnit::GetPowerPct},                                                                 // :GetPowerPct(power_id)
    {"GetGender", &LuaUnit::GetGender},                                                                     // :GetGender() - returns the gender where male = 0 female = 1
    {"GetRace", &LuaUnit::GetRace},                                                                         // :GetRace()
    {"GetClass", &LuaUnit::GetClass},                                                                       // :GetClass()
    {"GetClassAsString", &LuaUnit::GetClassAsString},                                                       // :GetClassAsString()
    {"GetUnitType", &LuaUnit::GetUnitType},                                                                 // :GetUnitType() - Returns object type, IE: Player, Creature
    {"GetEntry", &LuaUnit::GetEntry},                                                                       // :GetEntry() - Returns the unit's entryId
    {"GetAura", &LuaUnit::GetAura},                                                                         // :GetAura(spellID) - returns aura object
    {"GetInt32Value", &LuaUnit::GetInt32Value},                                                             // :GetInt32Value(index) - returns an int value from unit fields
    {"GetUInt32Value", &LuaUnit::GetUInt32Value},                                                           // :GetUInt32Value(index) - returns an uint value from unit fields
    {"GetFloatValue", &LuaUnit::GetFloatValue},                                                             // :GetFloatValue(index) - returns a float value from unit fields
    {"GetByteValue", &LuaUnit::GetByteValue},                                                               // :GetByteValue(index, offset) - returns a byte value from unit fields
    {"GetUInt16Value", &LuaUnit::GetUInt16Value},                                                           // :GetUInt16Value(index, offset) - returns a uint16 value from unit fields
    {"GetInstanceId", &LuaUnit::GetInstanceId},                                                             // :GetInstanceId() - Gets the instance id of the unit
    {"GetPhaseMask", &LuaUnit::GetPhaseMask},                                                               // :GetPhaseMask() - gets the phase mask of the unit
    {"GetCombatTime", &LuaUnit::GetCombatTime},                                                             // :GetCombatTime() - Returns how long the unit has been in combat
    {"GetFaction", &LuaUnit::GetFaction},                                                                   // :GetFaction() - Returns the unit's factionId
    {"GetCurrentSpell", &LuaUnit::GetCurrentSpell},                                                         // :GetCurrentSpell(type) - Returns the currently casted spell of given type if any
    {"GetCreatureType", &LuaUnit::GetCreatureType},                                                         // :GetCreatureType() - Returns the unit's type
    {"GetNearbyTarget", &LuaUnit::GetNearbyTarget},                                                         // :GetNearbyTarget([radius[, exclude]]) - Returns nearby target within sight or given radius. Excludes current target and given unit
    {"GetShieldBlockValue", &LuaUnit::GetShieldBlockValue},                                                 // :GetShieldBlockValue() - Returns block value
    {"GetMountId", &LuaUnit::GetMountId},                                                                   // :GetMountId()
    {"GetScale", &LuaUnit::GetScale},                                                                       // :GetScale()
    {"GetDistance", &LuaUnit::GetDistance},                                                                 // :GetDistance(WorldObject or x, y, z)
    {"GetGUIDLow", &LuaUnit::GetGUIDLow},                                                                   // :GetGUIDLow() - Returns uint32 guid (low guid) that is used in database.
    {"GetNearestPlayer", &LuaUnit::GetNearestPlayer},                                                       // :GetNearestPlayer([radius]) - Returns nearest player in sight or given radius.
    {"GetNearestGameObject", &LuaUnit::GetNearestGameObject},                                               // :GetNearestGameObject([entry, radius]) - Returns nearest gameobject with given entry in sight or given radius entry can be 0.
    {"GetNearestCreature", &LuaUnit::GetNearestCreature},                                                   // :GetNearestCreatureEntry([entry, radius]) - Returns nearest creature with given entry in sight or given radius entry can be 0.
    {"GetRelativePoint", &LuaUnit::GetRelativePoint},                                                       // :GetRelativePoint(dist, rad) - Returns the X, Y and orientation of a point dist away from unit.
    {"GetOwnerGUID", &LuaUnit::GetOwnerGUID},                                                               // :GetOwnerGUID() - Returns the GUID of the owner
    {"GetOwner", &LuaUnit::GetOwner},                                                                       // :GetOwner() - Returns the owner
    {"GetFriendlyUnitsInRange", &LuaUnit::GetFriendlyUnitsInRange},                                         // :GetFriendlyUnitsInRange([range]) - Returns a list of friendly units in range, can return nil
    {"GetUnfriendlyUnitsInRange", &LuaUnit::GetUnfriendlyUnitsInRange},                                     // :GetUnfriendlyUnitsInRange([range]) - Returns a list of unfriendly units in range, can return nil
    {"GetMap", &LuaUnit::GetMap},                                                                           // :GetMap() - Returns the unit's current map object
    {"GetOwnerGUID", &LuaUnit::GetOwnerGUID},                                                               // :GetOwnerGUID() - Returns the UNIT_FIELD_SUMMONEDBY owner
    {"GetCreatorGUID", &LuaUnit::GetCreatorGUID},                                                           // :GetCreatorGUID() - Returns the UNIT_FIELD_CREATEDBY creator
    {"GetMinionGUID", &LuaUnit::GetMinionGUID},                                                             // :GetMinionGUID() - Returns the UNIT_FIELD_SUMMON unit's minion GUID
    {"GetCharmerGUID", &LuaUnit::GetCharmerGUID},                                                           // :GetCharmerGUID() - Returns the UNIT_FIELD_CHARMEDBY charmer
    {"GetCharmGUID", &LuaUnit::GetCharmGUID},                                                               // :GetCharmGUID() - Returns the unit's UNIT_FIELD_CHARM guid
    {"GetPetGUID", &LuaUnit::GetPetGUID},                                                                   // :GetPetGUID() - Returns the unit's pet GUID
    {"GetCritterGUID", &LuaUnit::GetCritterGUID},                                                           // :GetCritterGUID() - Returns the critter's GUID
    {"GetControllerGUID", &LuaUnit::GetControllerGUID},                                                     // :GetControllerGUID() - Returns the Charmer or Owner GUID
    {"GetControllerGUIDS", &LuaUnit::GetControllerGUIDS},                                                   // :GetControllerGUIDS() - Returns the charmer, owner or unit's own GUID
    
    // Setters
    {"SetFaction", &LuaUnit::SetFaction},                                                                   // :SetFaction(factionId) - Sets the unit's faction
    {"SetLevel", &LuaUnit::SetLevel},                                                                       // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                                                                     // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                                                               // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                                                                       // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                                                                 // :SetMaxPower(index, amount)
    {"SetDisplayId", &LuaUnit::SetDisplayId},                                                               // :SetDisplayId(id)
    {"SetNativeDisplayId", &LuaUnit::SetNativeDisplayId},                                                   // :SetNativeDisplayId(id)
    {"SetFacing", &LuaUnit::SetFacing},                                                                     // :SetFacing(o) - Sets the Unit facing to arg
    {"SetDeathState", &LuaUnit::SetDeathState},                                                             // :SetDeathState(value) - 0 = alive 1 = just died 2 = corpse 3 = dead
    {"SetInt32Value", &LuaUnit::SetInt32Value},                                                             // :SetInt32Value(index, value) - Sets an int value for the unit
    {"SetUInt32Value", &LuaUnit::SetUInt32Value},                                                           // :SetUInt32Value(index, value) - Sets an uint value for the unit
    {"UpdateUInt32Value", &LuaUnit::UpdateUInt32Value},                                                     // :UpdateUInt32Value(index, value) - Updates an uint value for the unit
    {"SetFloatValue", &LuaUnit::SetFloatValue},                                                             // :SetFloatValue(index, value) - Sets a float value for the unit
    {"SetByteValue", &LuaUnit::SetByteValue},                                                               // :SetByteValue(index, offset, value) - Sets a byte value for the unit
    {"SetUInt16Value", &LuaUnit::SetUInt16Value},                                                           // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the unit
    {"SetInt16Value", &LuaUnit::SetInt16Value},                                                             // :SetInt16Value(index, offset, value) - Sets an int16 value for the unit
    {"SetPhaseMask", &LuaUnit::SetPhaseMask},                                                               // :SetPhaseMask(Phase[, update]) - Sets the phase of the unit
    {"SetWalk", &LuaUnit::SetWalk},                                                                         // :SetWalk([enable]) - If false, creature runs, otherwise walks
    {"SetSpeed", &LuaUnit::SetSpeed},                                                                       // :SetSpeed(type, speed[, forced]) - Sets speed for the movement type (0 = walk, 1 = run ..)
    {"SetStunned", &LuaUnit::SetStunned},                                                                   // :SetStunned([enable]) - Stuns or removes stun
    {"SetRooted", &LuaUnit::SetRooted},                                                                     // :SetRooted([enable]) - Roots or removes root
    {"SetConfused", &LuaUnit::SetConfused},                                                                 // :SetConfused([enable]) - Sets confused or removes confusion
    {"SetFeared", &LuaUnit::SetFeared},                                                                     // :SetFeared([enable]) - Fears or removes fear
    {"SetGender", &LuaUnit::SetGender},                                                                     // :SetGender(value) - 0 = male 1 = female
    {"SetPvP", &LuaUnit::SetPvP},                                                                           // :SetPvP([apply]) - Sets the units PvP on or off
    {"SetFFA", &LuaUnit::SetFFA},                                                                           // :SetFFA([apply]) - Sets the units FFA tag on or off
    {"SetSanctuary", &LuaUnit::SetSanctuary},                                                               // :SetSanctuary([apply]) - Enables or disables units sanctuary flag
    {"SetScale", &LuaUnit::SetScale},                                                                       // :SetScale(scale)
    {"SetCanFly", &LuaUnit::SetCanFly},                                                                     // :SetCanFly(apply)
    {"SetVisible", &LuaUnit::SetVisible},                                                                   // :SetVisible(x)
    {"SetOwnerGUID", &LuaUnit::SetOwnerGUID},                                                               // :SetOwnerGUID(guid) - Sets the guid of the owner
    {"SetFlag", &LuaUnit::SetFlag},                                                                         // :SetFlag(index, flag)

    // Boolean
    {"IsAlive", &LuaUnit::IsAlive},                                                                         // :IsAlive()
    {"IsDead", &LuaUnit::IsDead},                                                                           // :IsDead() - Returns true if the unit is dead, false if they are alive
    {"IsDying", &LuaUnit::IsDying},                                                                         // :IsDying() - Returns true if the unit death state is JUST_DIED.
    {"IsInWorld", &LuaUnit::IsInWorld},                                                                     // :IsInWorld()
    {"IsPvPFlagged", &LuaUnit::IsPvPFlagged},                                                               // :IsPvPFlagged()
    {"HasQuest", &LuaUnit::HasQuest},                                                                       // :HasQuest(id)
    {"IsInCombat", &LuaUnit::IsInCombat},                                                                   // :IsInCombat()
    {"HasSpell", &LuaUnit::HasSpell},                                                                       // :HasSpell(id)
    {"IsBanker", &LuaUnit::IsBanker},                                                                       // :IsBanker() - Returns true if the unit is a banker, false if not
    {"IsBattleMaster", &LuaUnit::IsBattleMaster},                                                           // :IsBattleMaster() - Returns true if the unit is a battle master, false if not
    {"IsCharmed", &LuaUnit::IsCharmed},                                                                     // :IsCharmed() - Returns true if the unit is charmed, false if not
    {"IsArmorer", &LuaUnit::IsArmorer},                                                                     // :IsArmorer() - Returns true if the unit is an Armorer, false if not
    {"IsAttackingPlayer", &LuaUnit::IsAttackingPlayer},                                                     // :IsAttackingPlayer() - Returns true if the unit is attacking a player, false if not
    {"IsInWater", &LuaUnit::IsInWater},                                                                     // :IsInWater() - Returns true if the unit is in water
    {"IsUnderWater", &LuaUnit::IsUnderWater},                                                               // :IsUnderWater() - Returns true if the unit is under water
    {"HasAura", &LuaUnit::HasAura},                                                                         // :HasAura(spellId[, caster]) - Returns true if the unit has the aura from the spell and casted by the caster if provided
    {"CanFly", &LuaUnit::CanFly},                                                                           // :CanFly() - Returns true if the unit can fly
    {"HasSpellCooldown", &LuaUnit::HasSpellCooldown},                                                       // :HasSpellCooldown(spellId) - Returns true if the spell is on cooldown
    {"IsAuctioneer", &LuaUnit::IsAuctioneer},                                                               // :IsAuctioneer()
    {"HealthBelowPct", &LuaUnit::HealthBelowPct},                                                           // :HealthBelowPct(int32 pct)
    {"HealthAbovePct", &LuaUnit::HealthAbovePct},                                                           // :HealthAbovePct(int32 pct)
    {"IsMounted", &LuaUnit::IsMounted},                                                                     // :IsMounted()
    {"AttackStop", &LuaUnit::AttackStop},                                                                   // :AttackStop()
    {"Attack", &LuaUnit::Attack},                                                                           // :Attack(who[, meleeAttack])
    {"IsVisible", &LuaUnit::IsVisible},                                                                     // :IsVisible()
    {"IsMoving", &LuaUnit::IsMoving},                                                                       // :IsMoving()
    {"IsFlying", &LuaUnit::IsFlying},                                                                       // :IsFlying()
    {"IsStopped", &LuaUnit::IsStopped},                                                                     // :IsStopped()
    {"HasFlag", &LuaUnit::HasFlag},                                                                         // :HasFlag(index, flag)
    {"HasUnitState", &LuaUnit::HasUnitState},                                                               // :HasUnitState(state) - state from UnitState enum

    // Other
    {"RegisterEvent", &LuaUnit::RegisterEvent},                                                             // :RegisterEvent(function, delay, calls)
    {"RemoveEventById", &LuaUnit::RemoveEventById},                                                         // :RemoveEventById(eventID)
    {"RemoveEvents", &LuaUnit::RemoveEvents},                                                               // :RemoveEvents()
    {"AddAura", &LuaUnit::AddAura},                                                                         // :AddAura(spellId, target) - Adds an aura to the specified target
    {"RemoveAura", &LuaUnit::RemoveAura},                                                                   // :RemoveAura(spellId[, casterGUID]) - Removes an aura from the unit by the spellId, casterGUID(Original caster) is optional
    {"RemoveAllAuras", &LuaUnit::RemoveAllAuras},                                                           // :RemoveAllAuras() - Removes all the unit's auras
    {"ClearInCombat", &LuaUnit::ClearInCombat},                                                             // :ClearInCombat() - Clears the unit's combat list (unit will be out of combat), resets the timer to 0, etc
    {"DeMorph", &LuaUnit::DeMorph},                                                                         // :DeMorph() - Sets display back to native
    {"SendUnitWhisper", &LuaUnit::SendUnitWhisper},                                                         // :SendUnitWhisper(msg, receiver[, bossWhisper]) - Sends a whisper to the receiver
    {"SendUnitEmote", &LuaUnit::SendUnitEmote},                                                             // :SendUnitEmote(msg[, receiver, bossEmote]) - Sends a text emote
    {"SendUnitSay", &LuaUnit::SendUnitSay},                                                                 // :SendUnitSay(msg, language) - Sends a "Say" message with the specified language (all languages: 0)
    {"SendUnitYell", &LuaUnit::SendUnitYell},                                                               // :SendUnitYell(msg, language) - Sends a "Yell" message with the specified language (all languages: 0)
    {"CastSpell", &LuaUnit::CastSpell},                                                                     // :CastSpell(target, spellID[, triggered]) - Casts spell on target (player/npc/object/item), if triggered is false has mana cost and cast time
    {"CastSpellAoF", &LuaUnit::CastSpellAoF},                                                               // :CastSpellAoF(x, y, z, spellID[, triggered]) - Casts the spell on coordinates, if triggered is false has mana cost and cast time
    {"PlayDirectSound", &LuaUnit::PlayDirectSound},                                                         // :PlayDirectSound(soundId, player) - Unit plays soundID to player, or everyone around if no player
    {"PlayDistanceSound", &LuaUnit::PlayDistanceSound},                                                     // :PlayDistanceSound(soundId, player) - Unit plays soundID to player, or everyone around if no player. The sound fades the further you are
    {"Kill", &LuaUnit::Kill},                                                                               // :Kill(target, durabilityLoss) - Unit kills the target, if no target then kills the unit. Durabilityloss is true by default
    {"KnockbackFrom", &LuaUnit::KnockbackFrom},                                                             // :KnockbackFrom(x, y, speedXY, speedZ) - Knocks the player to the opposite direction from x,y at the defined speeds
    {"JumpTo", &LuaUnit::JumpTo},                                                                           // :JumpTo(WorldObj, speedZ) - Unit jumps to world object
    {"Jump", &LuaUnit::Jump},                                                                               // :Jump(speedXY, speedZ[, forward]) - Unit jumps at given speeds
    {"JumpToCoords", &LuaUnit::JumpToCoords},                                                               // :JumpToCoords(x, y, z, speedXY, speedZ) - Unit jumps to coordinates at given speeds
    {"MoveTo", &LuaUnit::MoveTo},                                                                           // :MoveTo(id, x, y, z[, generatePath]) - Unit moves to point. ID is sent to WP reach hook
    {"MoveCharge", &LuaUnit::MoveCharge},                                                                   // :MoveCharge(x, y, z, speed) - Charges to target location
    {"MoveChase", &LuaUnit::MoveChase},                                                                     // :MoveChase(target[, dist, angle]) - Chases target unit
    {"MoveFollow", &LuaUnit::MoveFollow},                                                                   // :MoveFollow(target, dist, angle) - Follows target unit
    {"MoveClear", &LuaUnit::MoveClear},                                                                     // :MoveClear() - Stops movement
    {"MoveRandom", &LuaUnit::MoveRandom},                                                                   // :MoveRandom() - Moves randomly inside radius
    {"MoveRotate", &LuaUnit::MoveRotate},                                                                   // :MoveRotate(time, left) - Turns left (true or nil) or right (false) for given time
    {"SummonGameObject", &LuaUnit::SummonGameObject},                                                       // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil
    {"SpawnCreature", &LuaUnit::SpawnCreature},                                                             // :SpawnCreature(entry, x, y, z, o[, despawnDelay]) - Spawns a creature to location that despawns after given time (0 for infinite). Returns the creature or nil
    {"StopSpellCast", &LuaUnit::StopSpellCast},                                                             // :StopSpellCast(spellId(optional)) - Stops the unit from casting a spell. If a spellId is defined, it will stop that unit from casting that spell
    {"InterruptSpell", &LuaUnit::InterruptSpell},                                                           // :InterruptSpell(spellType, delayed(optional), instant(optional)) - Interrupts the unit's spell by the spellType. If delayed is true it will skip if the spell is delayed. If instant is true, it will skip that the spell has a cast time
    {"SendChatMessageToPlayer", &LuaUnit::SendChatMessageToPlayer},                                         // :SendChatMessageToPlayer(type, lang, msg, target) - Unit sends a chat message to the given target player
    {"SaveToDB", &LuaUnit::SaveToDB},                                                                       // :SaveToDB() - Saves the unit to database
    {"Emote", &LuaUnit::Emote},                                                                             // :Emote(emote)
    {"CountPctFromCurHealth", &LuaUnit::CountPctFromCurHealth},                                             // :CountPctFromCurHealth(int32 pct)
    {"CountPctFromMaxHealth", &LuaUnit::CountPctFromMaxHealth},                                             // :CountPctFromMaxHealth()
    {"Dismount", &LuaUnit::Dismount},                                                                       // :Dismount() - Dismounts the unit.
    {"Mount", &LuaUnit::Mount},                                                                             // :Mount(displayId) - Mounts the unit on the specified displayId.
    {"Mute", &LuaUnit::Mute},                                                                               // :Mute(time[, reason]) - Mutes the player for given time in seconds.
    {"SummonPlayer", &LuaUnit::SummonPlayer},                                                               // :SummonPlayer(player, map, x, y, z, zoneId[, delay]) - Sends a popup to the player asking if he wants to be summoned if yes, teleported to coords. ZoneID defines the location name shown in the popup Delay is the time until the popup closes automatically.
    {"RestoreDisplayId", &LuaUnit::RestoreDisplayId},                                                       // :RestoreDisplayId()
    {"RestoreFaction", &LuaUnit::RestoreFaction},                                                           // :RestoreFaction()
    {"RemoveBindSightAuras", &LuaUnit::RemoveBindSightAuras},                                               // :RemoveBindSightAuras()
    {"RemoveCharmAuras", &LuaUnit::RemoveCharmAuras},                                                       // :RemoveCharmAuras()
    {"StopMoving", &LuaUnit::StopMoving},                                                                   // :StopMoving()
    {"ClearThreatList", &LuaUnit::ClearThreatList},                                                         // :ClearThreatList()
    {"RemoveFlag", &LuaUnit::RemoveFlag},                                                                   // :RemoveFlag(index, flag)
    {"ClearUnitState", &LuaUnit::ClearUnitState},                                                           // :ClearUnitState(state)
    {"AddUnitState", &LuaUnit::AddUnitState},                                                               // :AddUnitState(state)
    {"DisableMelee", &LuaUnit::DisableMelee},                                                               // :DisableMelee([disable]) - if true, enables
    {"SummonGuardian", &LuaUnit::SummonGuardian},                                                           // :SummonGuardian(entry, x, y, z, o[, duration]) - summons a guardian to location. Scales with summoner, is friendly to him and guards him.

    /* Vehicle */
    {"AddVehiclePassenger", &LuaUnit::AddVehiclePassenger},                                                 // :AddVehiclePassenger(unit, seatId) - Adds a passenger to the vehicle by specifying a unit and seatId
    {"IsOnVehicle", &LuaUnit::IsOnVehicle},                                                                 // :IsOnVehicle() - Checks if the (unit) is in a vehicle
    {"DismissVehicle", &LuaUnit::DismissVehicle},                                                           // :DismissVehicle() - Dismisses the (unit)'s vehicle (Unmounts)
    // {"EjectPassenger", &LuaUnit::EjectPassenger},                                                        // :EjectPassenger(unit) - Ejects a specified unit out of the vehicle
    {"RemovePassenger", &LuaUnit::RemovePassenger},                                                         // :RemovePassenger(unit) - Removes a specific unit from the vehicle
    {"RemoveAllPassengers", &LuaUnit::RemoveAllPassengers},                                                 // :RemoveAllPassengers() - Removes all the passengers from the vehicle
    {"GetPassenger", &LuaUnit::GetPassenger},                                                               // :GetPassenger(seatId) - Gets a passenger by their seatId
    {"GetNextEmptySeat", &LuaUnit::GetNextEmptySeat},                                                       // :GetNextEmptySeat(seatId) - Gets(returns) the next empty seat
    {"GetAvailableSeats", &LuaUnit::GetAvailableSeats},                                                     // :GetAvailableSeats() - Returns the available seats count
    {"GetVehicleBase", &LuaUnit::GetVehicleBase},                                                           // :GetVehicleBase() - Returns the unit's vehicle base
    {"HasEmptySeat", &LuaUnit::HasEmptySeat},                                                               // :HasEmptySeat(seatId) - Checks if the specified seatId is empty(nobody in it)
    { NULL, NULL },
};

ElunaRegister<GameObject> GameObjectMethods[] =
{
    // Getters
    {"GetUnitType", &LuaGameObject::GetUnitType},                                                           // :GetUnitType() - Returns unit type Ex. GameObject
    {"GetGUID", &LuaGameObject::GetGUID},                                                                   // :GetGUID() - Returns uint64 guid as hex string
    {"GetName", &LuaGameObject::GetName},                                                                   // :GetName()
    {"GetDisplayId", &LuaGameObject::GetDisplayId},                                                         // :GetDisplayId()
    {"GetScale", &LuaGameObject::GetScale},                                                                 // :GetScale()
    {"GetEntry", &LuaGameObject::GetEntry},                                                                 // :GetEntry()
    {"GetMapId", &LuaGameObject::GetMapId},                                                                 // :GetMapId()
    {"GetX", &LuaGameObject::GetX},                                                                         // :GetX()
    {"GetY", &LuaGameObject::GetY},                                                                         // :GetY()
    {"GetZ", &LuaGameObject::GetZ},                                                                         // :GetZ()
    {"GetO", &LuaGameObject::GetO},                                                                         // :GetO()
    {"GetLocation", &LuaGameObject::GetLocation},                                                           // :GetLocation() - returns X, Y, Z and O co - ords (in that order)
    {"GetAreaId", &LuaGameObject::GetAreaId},                                                               // :GetAreaId()
    {"GetZoneId", &LuaGameObject::GetZoneId},                                                               // :GetZoneId()
    {"GetInt32Value", &LuaGameObject::GetInt32Value},                                                       // :GetInt32Value(index) - returns an int value from object fields
    {"GetUInt32Value", &LuaGameObject::GetUInt32Value},                                                     // :GetUInt32Value(index) - returns an uint value from object fields
    {"GetFloatValue", &LuaGameObject::GetFloatValue},                                                       // :GetFloatValue(index) - returns a float value from object fields
    {"GetByteValue", &LuaGameObject::GetByteValue},                                                         // :GetByteValue(index, offset) - returns a byte value from object fields
    {"GetUInt16Value", &LuaGameObject::GetUInt16Value},                                                     // :GetUInt16Value(index, offset) - returns a uint16 value from object fields
    {"GetGUIDLow", &LuaGameObject::GetGUIDLow},                                                             // :GetGUIDLow() - Returns uint32 guid (low guid) that is used in database.
    {"GetNearestPlayer", &LuaGameObject::GetNearestPlayer},                                                 // :GetNearestPlayer([radius]) - Returns nearest player in sight or given radius.
    {"GetNearestGameObject", &LuaGameObject::GetNearestGameObject},                                         // :GetNearestGameObject([radius, entry]) - Returns nearest gameobject with given entry in sight or given radius.
    {"GetNearestCreature", &LuaGameObject::GetNearestCreature},                                             // :GetNearestCreatureEntry([radius, entry]) - Returns nearest creature with given entry in sight or given radius.
    {"GetRelativePoint", &LuaGameObject::GetRelativePoint},                                                 // :GetRelativePoint(dist, radians) - Returns the X, Y and orientation of a point dist away from gob. Radian 0 point is the direction the unit is facing.
    {"GetGoState", &LuaGameObject::GetGoState},                                                             // :GetGoState() - Returns state
    {"GetLootState", &LuaGameObject::GetLootState},                                                         // :GetLootState() - Returns loot state
    {"GetMap", &LuaGameObject::GetMap},                                                                     // :GetMap() - Returns the map the gameobject is on

    // Setters
    {"SetScale", &LuaGameObject::SetScale},                                                                 // :SetScale(scale)
    {"SetInt32Value", &LuaGameObject::SetInt32Value},                                                       // :SetInt32Value(index, value) - Sets an int value for the object
    {"SetUInt32Value", &LuaGameObject::SetUInt32Value},                                                     // :SetUInt32Value(index, value) - Sets an uint value for the object
    {"UpdateUInt32Value", &LuaGameObject::UpdateUInt32Value},                                               // :UpdateUInt32Value(index, value) - Updates an uint value for the object
    {"SetFloatValue", &LuaGameObject::SetFloatValue},                                                       // :SetFloatValue(index, value) - Sets a float value for the object
    {"SetByteValue", &LuaGameObject::SetByteValue},                                                         // :SetByteValue(index, offset, value) - Sets a byte value for the object
    {"SetUInt16Value", &LuaGameObject::SetUInt16Value},                                                     // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the object
    {"SetInt16Value", &LuaGameObject::SetInt16Value},                                                       // :SetInt16Value(index, offset, value) - Sets an int16 value for the object
    {"SetGoState", &LuaGameObject::SetGoState},
    {"SetLootState", &LuaGameObject::SetLootState},
    {"SetFlag", &LuaGameObject::SetFlag},

    // Boolean
    {"IsInWorld", &LuaGameObject::IsInWorld},                                                               // :IsInWorld()
    {"IsTransport", &LuaGameObject::IsTransport},                                                           // :IsTransport()
    {"IsDestructible", &LuaGameObject::IsDestructible},                                                     // :IsDestructible()
    {"IsActive", &LuaGameObject::IsActive},                                                                 // :IsActive()
    {"HasQuest", &LuaGameObject::HasQuest},                                                                 // :HasQuest(questId)
    {"IsInvisibleDueToDespawn", &LuaGameObject::IsInvisibleDueToDespawn},                                   // :IsInvisibleDueToDespawn()

    // Other
    {"CastSpell", &LuaGameObject::CastSpell},                                                               // :CastSpellOnTarget(target, spellId) - Casts the spell on target, no manacost or cast time
    {"Move", &LuaGameObject::Move},                                                                         // :Move(x, y, z, o) - Moves the GO to coordinates
    {"SpawnCreature", &LuaGameObject::SummonCreature},                                                      // :SummonCreature(entry, x, y, z, o, despawntime) Summons a temporary creature. 0 for infinitely, otherwise despawns after despawntime (ms)
    {"RegisterEvent", &LuaGameObject::RegisterEvent},                                                       // :RegisterEvent(function, delay, calls)
    {"RemoveEventById", &LuaGameObject::RemoveEventById},                                                   // :RemoveEventById(eventID)
    {"RemoveEvents", &LuaGameObject::RemoveEvents},                                                         // :RemoveEvents()
    {"Despawn", &LuaGameObject::Despawn},                                                                   // :Despawn() - Object despawns
    {"SummonGameObject", &LuaGameObject::SummonGameObject},                                                 // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil
    {"RemoveFlag", &LuaGameObject::RemoveFlag},
    {"UseDoorOrButton", &LuaGameObject::UseDoorOrButton},                                                   // :UseDoorOrButton(delay) - Activates/closes/opens after X delay UNDOCUMENTED

    { NULL, NULL },
};

ElunaRegister<Item> ItemMethods[] =
{
    // Getters
    {"GetUnitType", &LuaItem::GetUnitType},                                                                 // :GetUnitType() - Returns object type, IE: Item, Creature
    {"GetGUID", &LuaItem::GetGUID},                                                                         // :GetGUID() - Returns uint64 guid as hex string
    {"GetOwnerGUID", &LuaItem::GetOwnerGUID},                                                               // :GetOwnerGUID() - Returns the owner's guid
    {"GetOwner", &LuaItem::GetOwner},                                                                       // :GetOwner() - Returns the owner object (player)
    {"GetCount", &LuaItem::GetCount},                                                                       // :GetCount() - Returns item stack count
    {"GetMaxStackCount", &LuaItem::GetMaxStackCount},                                                       // :GetMaxStackCount() - Returns item max stack count
    {"GetSlot", &LuaItem::GetSlot},                                                                         // :GetSlot() - returns the slot the item is in
    {"GetBagSlot", &LuaItem::GetBagSlot},                                                                   // :GetBagSlot() - returns the bagslot of the bag the item is in
    {"GetInt32Value", &LuaItem::GetInt32Value},                                                             // :GetInt32Value(index) - returns an int value from item fields
    {"GetUInt32Value", &LuaItem::GetUInt32Value},                                                           // :GetUInt32Value(index) - returns an uint value from item fields
    {"GetFloatValue", &LuaItem::GetFloatValue},                                                             // :GetFloatValue(index) - returns a float value from item fields
    {"GetByteValue", &LuaItem::GetByteValue},                                                               // :GetByteValue(index, offset) - returns a byte value from item fields
    {"GetUInt16Value", &LuaItem::GetUInt16Value},                                                           // :GetUInt16Value(index, offset) - returns a uint16 value from item fields
    {"GetGUIDLow", &LuaItem::GetGUIDLow},                                                                   // :GetGUIDLow() - Returns uint32 guid (low guid) that is used in database.
    {"GetEnchantmentId", &LuaItem::GetEnchantmentId},                                                       // :GetEnchantmentId(enchant_slot) - Returns the enchantment in given slot. (permanent = 0)
    {"GetSpellId", &LuaItem::GetSpellId},                                                                   // :GetSpellId(index) - Returns spellID at given index (0 - 4)
    {"GetSpellTrigger", &LuaItem::GetSpellTrigger},                                                         // :GetSpellTrigger(index) - Returns spell trigger at given index (0 - 4)
    {"GetItemLink", &LuaItem::GetItemLink},                                                                 // :GetItemLink([localeID]) - Returns the shift clickable link of the item. Name translated if locale given and exists
    {"GetEntry", &LuaItem::GetEntry},                                                                       // :GetEntry()
    {"GetClass", &LuaItem::GetClass},                                                                       // :GetClass()
    {"GetSubClass", &LuaItem::GetSubClass},                                                                 // :GetSubClass()
    {"GetName", &LuaItem::GetName},                                                                         // :GetName()
    {"GetDisplayId", &LuaItem::GetDisplayId},                                                               // :GetDisplayId()
    {"GetQuality", &LuaItem::GetQuality},                                                                   // :GetQuality()
    {"GetBuyCount", &LuaItem::GetBuyCount},                                                                 // :GetBuyCount()
    {"GetBuyPrice", &LuaItem::GetBuyPrice},                                                                 // :GetBuyPrice()
    {"GetSellPrice", &LuaItem::GetSellPrice},                                                               // :GetSellPrice()
    {"GetInventoryType", &LuaItem::GetInventoryType},                                                       // :GetInventoryType()
    {"GetAllowableClass", &LuaItem::GetAllowableClass},                                                     // :GetAllowableClass()
    {"GetAllowableRace", &LuaItem::GetAllowableRace},                                                       // :GetAllowableRace()
    {"GetItemLevel", &LuaItem::GetItemLevel},                                                               // :GetItemLevel()
    {"GetRequiredLevel", &LuaItem::GetRequiredLevel},                                                       // :GetRequiredLevel()
    {"GetStatsCount", &LuaItem::GetStatsCount},                                                             // :GetStatsCount()
    {"GetRandomProperty", &LuaItem::GetRandomProperty},                                                     // :GetRandomProperty()
    {"GetRandomSuffix", &LuaItem::GetRandomSuffix},                                                         // :GetRandomSuffix()
    {"GetItemSet", &LuaItem::GetItemSet},                                                                   // :GetItemSet()
    {"GetBagSize", &LuaItem::GetBagSize},                                                                   // :GetBagSize()

    // Setters
    {"SetOwner", &LuaItem::SetOwner},                                                                       // :SetOwner(player) - Sets the owner of the item
    {"SetBinding", &LuaItem::SetBinding},                                                                   // :SetBinding(bound) - Sets the item binding to true or false
    {"SetCount", &LuaItem::SetCount},                                                                       // :SetCount(count) - Sets the item count
    {"SetInt32Value", &LuaItem::SetInt32Value},                                                             // :SetInt32Value(index, value) - Sets an int value for the item
    {"SetUInt32Value", &LuaItem::SetUInt32Value},                                                           // :SetUInt32Value(index, value) - Sets an uint value for the item
    {"UpdateUInt32Value", &LuaItem::UpdateUInt32Value},                                                     // :UpdateUInt32Value(index, value) - Updates an uint value for the item
    {"SetFloatValue", &LuaItem::SetFloatValue},                                                             // :SetFloatValue(index, value) - Sets a float value for the item
    {"SetByteValue", &LuaItem::SetByteValue},                                                               // :SetByteValue(index, offset, value) - Sets a byte value for the item
    {"SetUInt16Value", &LuaItem::SetUInt16Value},                                                           // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the item
    {"SetInt16Value", &LuaItem::SetInt16Value},                                                             // :SetInt16Value(index, offset, value) - Sets an int16 value for the item

    // Boolean
    {"IsSoulBound", &LuaItem::IsSoulBound},                                                                 // :IsSoulBound() - Returns true if the item is soulbound
    {"IsBoundAccountWide", &LuaItem::IsBoundAccountWide},                                                   // :IsBoundAccountWide() - Returns true if the item is account bound
    {"IsBoundByEnchant", &LuaItem::IsBoundByEnchant},                                                       // :IsBoundByEnchant() - Returns true if the item is bound with an enchant
    {"IsNotBoundToPlayer", &LuaItem::IsNotBoundToPlayer},                                                   // :IsNotBoundToPlayer(player) - Returns true if the item is not bound with player
    {"IsLocked", &LuaItem::IsLocked},                                                                       // :IsLocked() - Returns true if the item is locked
    {"IsBag", &LuaItem::IsBag},                                                                             // :IsBag() - Returns true if the item is a bag
    {"IsCurrencyToken", &LuaItem::IsCurrencyToken},                                                         // :IsCurrencyToken() - Returns true if the item is a currency token
    {"IsNotEmptyBag", &LuaItem::IsNotEmptyBag},                                                             // :IsNotEmptyBag() - Returns true if the item is not an empty bag
    {"IsBroken", &LuaItem::IsBroken},                                                                       // :IsBroken() - Returns true if the item is broken
    {"CanBeTraded", &LuaItem::CanBeTraded},                                                                 // :CanBeTraded() - Returns true if the item can be traded
    {"IsInTrade", &LuaItem::IsInTrade},                                                                     // :IsInTrade() - Returns true if the item is in trade
    {"IsInBag", &LuaItem::IsInBag},                                                                         // :IsInBag() - Returns true if the item is in a bag
    {"IsEquipped", &LuaItem::IsEquipped},                                                                   // :IsEquipped() - Returns true if the item is equipped
    {"HasQuest", &LuaItem::hasQuest},                                                                       // :HasQuest(questId) - Returns true if the item starts the quest
    {"IsPotion", &LuaItem::IsPotion},                                                                       // :IsPotion() - Returns true if the item is a potion
    {"IsWeaponVellum", &LuaItem::IsWeaponVellum},                                                           // :IsWeaponVellum() - Returns true if the item is a weapon vellum
    {"IsArmorVellum", &LuaItem::IsArmorVellum},                                                             // :IsArmorVellum() - Returns true if the item is an armor vellum
    {"IsConjuredConsumable", &LuaItem::IsConjuredConsumable},                                               // :IsConjuredConsumable() - Returns true if the item is a conjured consumable
    {"IsRefundExpired", &LuaItem::IsRefundExpired},                                                         // :IsRefundExpired() - Returns true if the item's refund time has expired
    {"SetEnchantment", &LuaItem::SetEnchantment},                                                           // :SetEnchantment(enchantid, enchantmentslot) - Sets a new enchantment for the item. Returns true on success
    {"ClearEnchantment", &LuaItem::ClearEnchantment},                                                       // :ClearEnchantment(enchantmentslot) - Removes the enchantment from the item if one exists. Returns true on success

    // Other
    {NULL, NULL},
};

ElunaRegister<Aura> AuraMethods[] =
{
    // Getters
    {"GetUnitType", &LuaAura::GetUnitType},                                                                 // :GetUnitType() - Returns object type, IE: Aura, Creature
    {"GetCaster", &LuaAura::GetCaster},                                                                     // :GetCaster() - Returns caster as object
    {"GetCasterGUID", &LuaAura::GetCasterGUID},                                                             // :GetCasterGUID() - Returns caster as GUID
    {"GetCasterLevel", &LuaAura::GetCasterLevel},                                                           // :GetCasterLevel() - Returns casters level
    // {"GetDuration", &LuaAura::GetDuration},                                                              // :GetDuration() - Returns remaining duration
    {"GetMaxDuration", &LuaAura::GetMaxDuration},                                                           // :GetMaxDuration() - Returns maximum duration
    {"GetCharges", &LuaAura::GetCharges},                                                                   // :GetCharges() - Returns remaining charges
    {"GetAuraId", &LuaAura::GetAuraId},                                                                     // :GetAuraId() - Returns aura ID
    {"GetStackAmount", &LuaAura::GetStackAmount},                                                           // :GetStackAmount() - Returns current stack amount
    {"GetOwner", &LuaAura::GetOwner},                                                                       // :GetOwner() - Gets the unit wearing the aura

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                                                                 // :SetDuration(duration) - Sets remaining duration
    {"SetMaxDuration", &LuaAura::SetMaxDuration},                                                           // :SetMaxDuration(duration) - Sets maximum duration
    {"SetStackAmount", &LuaAura::SetStackAmount},                                                           // :SetStackAmount(amount) - Sets current stack amount

    // Other
    {"Remove", &LuaAura::Remove},                                                                           // :Remove() - Removes the aura
    {NULL, NULL},
};

ElunaRegister<Spell> SpellMethods[] =
{
    // Getters
    {"GetUnitType", &LuaSpell::GetUnitType},                                                                // :GetUnitType() - Returns the unit type (Spell)
    {"GetCaster", &LuaSpell::GetCaster},                                                                    // :GetCaster() - Returns the spell's caster (UNIT)
    {"GetCastTime", &LuaSpell::GetCastTime},                                                                // :GetCastTime() - Returns the spell cast time
    {"GetEntry", &LuaSpell::GetId},                                                                         // :GetEntry() - Returns the spell's ID
    {"GetDuration", &LuaSpell::GetDuration},                                                                // :GetDuration() - Returns the spell's duration
    {"GetPowerCost", &LuaSpell::GetPowerCost},                                                              // :GetPowerCost() - Returns the spell's power cost (mana, energy, rage, etc)

    // Setters
    {"SetAutoRepeat", &LuaSpell::SetAutoRepeat},                                                            // :SetAutoRepeat(boolean)

    // Boolean
    {"IsAutoRepeat", &LuaSpell::IsAutoRepeat},                                                              // :IsAutoRepeat()

    // Other
    {"Cancel", &LuaSpell::cancel},                                                                          // :Cancel() - Cancels the spell casting
    {"Cast", &LuaSpell::Cast},                                                                              // :Cast(skipCheck) - Casts the spell (if true, removes the check for instant spells, etc)
    {"Finish", &LuaSpell::Finish},                                                                          // :Finish() - Finishes the spell (SPELL_STATE_FINISH)
    {NULL, NULL},
};

ElunaRegister<Quest> QuestMethods[] =
{
    // Getters
    {"GetUnitType", &LuaQuest::GetUnitType},                                                                // :GetUnitType() - Returns the unit type (Quest)
    {"GetId", &LuaQuest::GetId},                                                                            // :GetId() - Returns the quest's Id
    {"GetLevel", &LuaQuest::GetLevel},                                                                      // :GetLevel() - Returns the quest's level
    {"GetMaxLevel", &LuaQuest::GetMaxLevel},                                                                // :GetMaxLevel() - Returns the quest's max level
    {"GetMinLevel", &LuaQuest::GetMinLevel},                                                                // :GetMinLevel() - Returns the quest's min level
    {"GetNextQuestId", &LuaQuest::GetNextQuestId},                                                          // :GetNextQuestId() - Returns the quest's next quest ID
    {"GetPrevQuestId", &LuaQuest::GetPrevQuestId},                                                          // :GetPrevQuestId() - Returns the quest's previous quest ID
    {"GetNextQuestInChain", &LuaQuest::GetNextQuestInChain},                                                // :GetNexQuestInChain() - Returns the next quest in its chain
    {"GetFlags", &LuaQuest::GetFlags},                                                                      // :GetFlags() - Returns the quest's flags
    {"GetType", &LuaQuest::GetType},                                                                        // :GetType() - Returns the quest's type

    // Boolean
    {"HasFlag", &LuaQuest::HasFlag},                                                                        // :HasFlag(flag) - Returns true or false if the quest has the specified flag
    {"IsDaily", &LuaQuest::IsDaily},                                                                        // :IsDaily() - Returns true or false if the quest is a daily
    {"IsRepeatable", &LuaQuest::IsRepeatable},                                                              // :IsRepeatable() - Returns true or false if the quest is repeatable

    // Setters
    {"SetFlag", &LuaQuest::SetFlag},                                                                        // :SetFlag(flag) - Sets the flag of the quest by the specified flag
    {NULL, NULL},
};

ElunaRegister<Group> GroupMethods[] =
{
    // Getters
    {"GetMembers", &LuaGroup::GetMembers},                                                                  // :GetMembers() - returns a table the players in this group. (Online?)
    {"GetLeaderGUID", &LuaGroup::GetLeaderGUID},
    {"GetLeader", &LuaGroup::GetLeader},
    {"GetUnitType", &LuaGroup::GetUnitType},
    {"GetGUID", &LuaGroup::GetGUID},
    {"GetMemberGroup", &LuaGroup::GetMemberGroup},                                                          // :GetMemberGroup(player) - Returns the player's subgroup ID
    {"GetMemberGUID", &LuaGroup::GetMemberGUID},                                                            // :GetMemberGUID("name") - Returns the member's GUID
    {"GetMembersCount", &LuaGroup::GetMembersCount},                                                        // :GetMembersCount() - Returns the member count of the group

    // Setters
    {"SetLeader", &LuaGroup::ChangeLeader},                                                                 // :SetLeader(Player) - Sets the player as the new leader
    {"SetMembersGroup", &LuaGroup::ChangeMembersGroup},                                                     // :ChangeMembersGroup(player, subGroup) - Changes the member's subgroup

    // Boolean
    {"IsLeader", &LuaGroup::IsLeader},                                                                      // :IsLeader("name"/Player)
    // {"HasRole", &LuaGroup::HasRole},                                                                     // :HasRole("name"/Player, "role") - "tank" / "healer" / "dps"
    {"AddInvite", &LuaGroup::AddInvite},                                                                    // :AddInvite(player) - Adds a an invite to player. Returns true if succesful
    {"RemoveMember", &LuaGroup::RemoveMember},                                                              // :RemoveMember(player) - Removes player from group. Returns true on success
    {"Disband", &LuaGroup::Disband},                                                                        // :Disband() - Disbands the group
    {"IsFull", &LuaGroup::IsFull},                                                                          // :IsFull() - Returns true if the group is full
    {"IsLFGGroup", &LuaGroup::isLFGGroup},                                                                  // :IsLFGGroup() - Returns true if the group is an LFG group
    {"IsRaidGroup", &LuaGroup::isRaidGroup},                                                                // :IsRaidGroup() - Returns true if the group is a raid group
    {"IsBGGroup", &LuaGroup::isBGGroup},                                                                    // :IsBGGroup() - Returns true if the group is a battleground group
    {"IsBFGroup", &LuaGroup::isBFGroup},                                                                    // :IsBFGroup() - Returns true if the group is a battlefield group
    {"IsMember", &LuaGroup::IsMember},                                                                      // :IsMember(player) - Returns true if the player is a member of the group
    {"IsAssistant", &LuaGroup::IsAssistant},                                                                // :IsAssistant(player) - returns true if the player is an assistant in the group
    {"SameSubGroup", &LuaGroup::SameSubGroup},                                                              // :SameSubGroup(player1, player2) - Returns true if the players are in the same subgroup in the group
    {"HasFreeSlotSubGroup", &LuaGroup::HasFreeSlotSubGroup},                                                // :HasFreeSlotSubGroup(subGroup) - Returns true if the subgroupID has free slots

    // Other
    {"SendPacket", &LuaGroup::SendPacket},                                                                  // :SendPacket(packet, sendToPlayersInBattleground[, ignoreguid]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground. Optionally ignores given player guid
    {"ConvertToLFG", &LuaGroup::ConvertToLFG},                                                              // :ConvertToLFG() - Converts the group to an LFG group
    {"ConvertToRaid", &LuaGroup::ConvertToRaid},                                                            // :ConvertToRaid() - Converts the group to a raid group
    {NULL, NULL},
};

ElunaRegister<Guild> GuildMethods[] =
{
    // Getters
    {"GetMembers", &LuaGuild::GetMembers},                                                                  // :GetMembers() - returns a table containing the players in this guild. (Online?)
    {"GetUnitType", &LuaGuild::GetUnitType},                                                                // :GetUnitType() - Returns the unit type. Eg: Guild
    {"GetLeaderGUID", &LuaGuild::GetLeaderGUID},                                                            // :GetLeaderGUID() - Returns the guild learder's guid
    {"GetId", &LuaGuild::GetId},                                                                            // :GetId() - Gets the guild's ID
    {"GetName", &LuaGuild::GetName},                                                                        // :GetName() - Gets the guild name
    {"GetMOTD", &LuaGuild::GetMOTD},                                                                        // :GetMOTD() - Gets the guild MOTD string
    {"GetInfo", &LuaGuild::GetInfo},                                                                        // :GetInfo() - Gets the guild info string

    // Setters
    {"SetBankTabText", &LuaGuild::SetBankTabText},                                                          // :SetBankTabText(tabId, text)
    {"SetMemberRank", &LuaGuild::ChangeMemberRank},                                                         // :SetMemberRank(player, newRank) - Sets the player rank in the guild to the new rank

    // Boolean

    // Other
    {"SendPacket", &LuaGuild::SendPacket},                                                                  // :SendPacket(packet) - sends packet to guild
    {"SendPacketToRanked", &LuaGuild::SendPacketToRanked},                                                  // :SendPacketToRanked(packet, rankId) - sends packet to guild, specifying a rankId will only send the packet to your ranked members
    {"Disband", &LuaGuild::Disband},                                                                        // :Disband() - Disbands the guild
    {"AddMember", &LuaGuild::AddMember},                                                                    // :AddMember(player, rank) - adds the player to the guild. Rank is optional
    {"DeleteMember", &LuaGuild::DeleteMember},                                                              // :DeleteMember(player, disbanding, kicked) - Deletes the player from the guild. Disbanding and kicked are optional bools
    {NULL, NULL},
};

ElunaRegister<QueryResult> QueryMethods[] =
{
    {"GetUnitType", &LuaQuery::GetUnitType},                                                                // :GetUnitType() - Returns object type, IE: QueryResult

    {"NextRow", &LuaQuery::NextRow},                                                                        // :NextRow() - Advances to next rown in the query. Returns true if there is a next row, otherwise false
    {"GetColumnCount", &LuaQuery::GetColumnCount},                                                          // :GetColumnCount() - Gets the column count of the query
    {"GetRowCount", &LuaQuery::GetRowCount},                                                                // :GetRowCount() - Gets the row count of the query

    {"GetBool", &LuaQuery::GetBool},                                                                        // :GetBool(column) - returns a bool from a number column (for example tinyint)
    {"GetUInt8", &LuaQuery::GetUInt8},                                                                      // :GetUInt8(column) - returns the value of an unsigned tinyint column
    {"GetUInt16", &LuaQuery::GetUInt16},                                                                    // :GetUInt16(column) - returns the value of a unsigned smallint column
    {"GetUInt32", &LuaQuery::GetUInt32},                                                                    // :GetUInt32(column) - returns the value of an unsigned int or mediumint column
    {"GetUInt64", &LuaQuery::GetUInt64},                                                                    // :GetUInt64(column) - returns the value of an unsigned bigint column as string
    {"GetInt8", &LuaQuery::GetInt8},                                                                        // :GetInt8(column) - returns the value of an tinyint column
    {"GetInt16", &LuaQuery::GetInt16},                                                                      // :GetInt16(column) - returns the value of a smallint column
    {"GetInt32", &LuaQuery::GetInt32},                                                                      // :GetInt32(column) - returns the value of an int or mediumint column
    {"GetInt64", &LuaQuery::GetInt64},                                                                      // :GetInt64(column) - returns the value of a bigint column as string
    {"GetFloat", &LuaQuery::GetFloat},                                                                      // :GetFloat(column) - returns the value of a float column
    {"GetDouble", &LuaQuery::GetDouble},                                                                    // :GetDouble(column) - returns the value of a double column
    {"GetString", &LuaQuery::GetString},                                                                    // :GetString(column) - returns the value of a string column
    {"IsNull", &LuaQuery::IsNull},                                                                          // :IsNull(column) - returns true if the column is null
    {NULL, NULL},
};

ElunaRegister<WorldPacket> PacketMethods[] =
{
    // Getters
    {"GetOpcode", &LuaPacket::GetOpcode},                                                                   // :GetOpcode() - Returns an opcode
    {"GetSize", &LuaPacket::GetSize},                                                                       // :GetSize() - Returns the packet size
    {"GetUnitType", &LuaPacket::GetOpcode},                                                                 // :GetUnitType() - Returns the unit type: Packet

    // Setters
    {"SetOpcode", &LuaPacket::SetOpcode},                                                                   // :SetOpcode(opcode) - Sets the opcode by specifying an opcode

    // Readers
    {"ReadByte", &LuaPacket::ReadByte},                                                                     // :ReadByte() - Reads an int8 value
    {"ReadUByte", &LuaPacket::ReadUByte},                                                                   // :ReadUByte() - Reads an uint8 value
    {"ReadShort", &LuaPacket::ReadShort},                                                                   // :ReadShort() - Reads an int16 value
    {"ReadUShort", &LuaPacket::ReadUShort},                                                                 // :ReadUShort() - Reads an uint16 value
    {"ReadLong", &LuaPacket::ReadLong},                                                                     // :ReadLong() - Reads an int32 value
    {"ReadULong", &LuaPacket::ReadULong},                                                                   // :ReadULong() - Reads an uint32 value
    {"ReadGUID", &LuaPacket::ReadGUID},                                                                     // :ReadGUID() - Reads an uint64 value
    {"ReadString", &LuaPacket::ReadString},                                                                 // :ReadString() - Reads a string value
    {"ReadFloat", &LuaPacket::ReadFloat},                                                                   // :ReadFloat() - Reads a float value
    {"ReadDouble", &LuaPacket::ReadDouble},                                                                 // :ReadDouble() - Reads a double value

    // Writers
    {"WriteByte", &LuaPacket::WriteByte},                                                                   // :WriteByte(val) - Writes an int8 value
    {"WriteUByte", &LuaPacket::WriteUByte},                                                                 // :WriteUByte(val) - Writes a uint8 value
    {"WriteShort", &LuaPacket::WriteShort},                                                                 // :WriteShort(val) - Writes an int16 value
    {"WriteUShort", &LuaPacket::WriteUShort},                                                               // :WriteUShort(val) - Writes a uint16 value
    {"WriteLong", &LuaPacket::WriteLong},                                                                   // :WriteLong(val) - Writes an int32 value
    {"WriteULong", &LuaPacket::WriteULong},                                                                 // :WriteULong(val) - Writes a uint32 value
    {"WriteGUID", &LuaPacket::WriteGUID},                                                                   // :WriteGUID(guid) - Writes a uint64 value
    {"WriteString", &LuaPacket::WriteString},                                                               // :WriteString(val) - Writes a string value
    {"WriteFloat", &LuaPacket::WriteFloat},                                                                 // :WriteFloat(val) - Writes a float value
    {"WriteDouble", &LuaPacket::WriteDouble},                                                               // :WriteDouble(val) - Writes a double value
    {NULL, NULL},
};

ElunaRegister<Map> MapMethods[] =
{
    // Getters
    {"GetName", &LuaMap::GetName},                                                                          // :GetName() - Returns the map's name UNDOCUMENTED
    {"GetDifficulty", &LuaMap::GetDifficulty},                                                              // :GetDifficulty() - Returns the map's difficulty UNDOCUMENTED
    {"GetInstanceId", &LuaMap::GetInstanceId},                                                              // :GetInstanceId() - Returns the map's instance ID UNDOCUMENTED
    {"GetPlayerCount", &LuaMap::GetPlayerCount},                                                            // :GetPlayerCount() - Returns the amount of players on map except GM's UNDOCUMENTED
    {"GetMapId", &LuaMap::GetMapId},                                                                        // :GetMapId() - Returns the map's ID UNDOCUMENTED
    {"GetAreaId", &LuaMap::GetAreaId},                                                                      // :GetAreaId(x, y, z) - Returns the map's area ID based on coords UNDOCUMENTED
    {"GetHeight", &LuaMap::GetHeight},                                                                      // :GetHeight(x, y[, phasemask]) - Returns ground Z coordinate. UNDOCUMENTED

    // Booleans
    {"IsArena", &LuaMap::IsArena},                                                                          // :IsArena() - Returns the true if the map is an arena, else false UNDOCUMENTED
    {"IsBattleground", &LuaMap::IsBattleground},                                                            // :IsBattleground() - Returns the true if the map is a battleground, else false UNDOCUMENTED
    {"IsDungeon", &LuaMap::IsDungeon},                                                                      // :IsDungeon() - Returns the true if the map is a dungeon , else false UNDOCUMENTED
    {"IsEmpty", &LuaMap::IsEmpty},                                                                          // :IsEmpty() - Returns the true if the map is empty, else false UNDOCUMENTED
    {"IsHeroic", &LuaMap::IsHeroic},                                                                        // :IsHeroic() - Returns the true if the map is a heroic dungeon, else false UNDOCUMENTED
    {"IsRaid", &LuaMap::IsRaid},                                                                            // :IsRaid() - Returns the true if the map is a raid map, else false UNDOCUMENTED
    {NULL, NULL},
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template<> ElunaRegister<Unit>* GetMethodTable<Unit>() { return UnitMethods; }
template<> ElunaRegister<GameObject>* GetMethodTable<GameObject>() { return GameObjectMethods; }
template<> ElunaRegister<Group>* GetMethodTable<Group>() { return GroupMethods; }
template<> ElunaRegister<Guild>* GetMethodTable<Guild>() { return GuildMethods; }
template<> ElunaRegister<QueryResult>* GetMethodTable<QueryResult>() { return QueryMethods; }
template<> ElunaRegister<Aura>* GetMethodTable<Aura>() { return AuraMethods; }
template<> ElunaRegister<Item>* GetMethodTable<Item>() { return ItemMethods; }
template<> ElunaRegister<WorldPacket>* GetMethodTable<WorldPacket>() { return PacketMethods; }
template<> ElunaRegister<Spell>* GetMethodTable<Spell>() { return SpellMethods; }
template<> ElunaRegister<Quest>* GetMethodTable<Quest>() { return QuestMethods; }
template<> ElunaRegister<Map>* GetMethodTable<Map>() { return MapMethods; }

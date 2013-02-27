#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Unit> UnitMethods[] =
{
    // Player Methods

    // Getters
    {"GetSelection", &LuaUnit::GetSelection},                       // :GetSelection()
    {"GetGMRank", &LuaUnit::GetSecurity},                           // :GetSecurity()
    {"GetGuildID", &LuaUnit::GetGuildID},                           // :GetGuildID() - nil on no guild.
    {"GetCoinage", &LuaUnit::GetCoinage},                           // :GetCoinage()
    {"GetTeam", &LuaUnit::GetTeam},                                 // :GetTeam() - returns the player's team. 0 for ally, 1 for horde
    {"GetItemCount", &LuaUnit::GetItemCount},                       // :GetItemCount(item_id)
    {"GetGroup", &LuaUnit::GetGroup},                               // :GetGroup()
    {"GetGuild", &LuaUnit::GetGuild},                               // :GetGuild()
    {"GetGearLevel", &LuaUnit::GetGearLevel},                       // :GetGearLevel() -- Returns the player's average gear level
    {"GetAccountId", &LuaUnit::GetAccountId},                       // :GetAccountId()
    {"GetAccountName", &LuaUnit::GetAccountName},                   // :GetAccountName()

    // Setters
    {"SetCoinage", &LuaUnit::SetCoinage},                           // :SetCoinage(amount) - sets plr's coinage to this.
    {"SetKnownTitle", &LuaUnit::SetKnownTitle},                     // :SetKnownTitle(id)
    {"UnsetKnownTitle", &LuaUnit::UnsetKnownTitle},                 // :UnsetKnownTitle(id)
    {"AdvanceSkillsToMax", &LuaUnit::AdvanceSkillsToMax},           // :AdvanceSkillsToMax() -- Advances all currently known skills to the currently known max level
    {"AdvanceSkill", &LuaUnit::AdvanceSkill},                       // AdvanceSkill(skill_id, step) -- Advances skill by ID and the amount(step)
    {"AdvanceAllSkills", &LuaUnit::AdvanceAllSkills},               // AdvanceAllSkills(value) -- Advances all current skills to your input(value)
    {"SetBindPoint", &LuaUnit::SetBindPoint},                       // :SetBindPoint(x, y, z, map, areaid) -- sets home for hearthstone
    {"SetBindPointAtPlayerLoc", &LuaUnit::SetBindPointAtPlayerLoc}, // :SetBindPointAtPlayerLoc() -- Set's home for hearthstone at player's location

    // Boolean
    {"IsInGroup", &LuaUnit::IsInGroup},                             // :IsInGroup()
    {"IsInGuild", &LuaUnit::IsInGuild},                             // :IsInGuild()
    {"IsGM", &LuaUnit::IsGM},                                       // :IsGM()
    {"IsAlliance", &LuaUnit::IsAlliance},                           // :IsAlliance()
    {"IsHorde", &LuaUnit::IsHorde},                                 // :IsHorde()
    {"HasTitle", &LuaUnit::HasTitle},                               // :HasTitle(id)
    {"Teleport", &LuaUnit::Teleport},                               // :Teleport(Map, X, Y, Z, O) - Teleports player to specified co-ordinates. Returns true if success and false if not.
    {"AddItem", &LuaUnit::AddItem},                                 // :AddItem(id, amount) - Adds amount of item to player. Returns true if success and false if not.

    // Gossip                                                           
    {"GossipMenuAddItem", &LuaUnit::GossipMenuAddItem },            // :GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    {"GossipComplete", &LuaUnit::GossipComplete },                  // :GossipComplete()
    {"GossipSendMenu", &LuaUnit::GossipSendMenu },                  // :GossipSendMenu(npc_text, unit)
    {"GossipClearMenu", &LuaUnit::GossipClearMenu },                // :GossipClearMenu() -- Clears the gossip menu of options. Pretty much only useful with player gossip. Need to use before creating a new menu for the player Undocumented

    // Update

    // Other
    {"SendBroadcastMessage", &LuaUnit::SendBroadcastMessage},       // :SendBroadcastMessage(message)
    {"SendAreaTriggerMessage", &LuaUnit::SendAreaTriggerMessage},   // :SendAreaTriggerMessage(message) -- Sends a yellow message in the middle of your screen
    {"SendNotification", &LuaUnit::SendNotification},               // :SendNotification(message) -- Sends a red message in the middle of your screen UNDOCUMENTED
    {"SendPacketToPlayer", &LuaUnit::SendPacketToPlayer},           // :SendPacketToPlayer(packet) - Sends a specified packet to the player (NOT DOCUMENTED)
    {"SendPacket", &LuaUnit::SendPacket},                           // :SendPacket(packet) -- Sends a specified packet (NOT DOCUMENTED)
    {"SendPacketToGroup", &LuaUnit::SendPacketToGroup},             // :SendPacketToGroup(packet, sendToPlayersInBattleground) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground (NOT DOCUMENTED)
    {"SendPacketToGuild", &LuaUnit::SendPacketToGuild},             // :SendPacketToGuild(packet) - Sends a specified packet to your guild
    {"SendPacketToRankedInGuild", &LuaUnit::SendPacketToRankedInGuild}, // :SendPacketToRankedInGuild(packet, rankId) - Sends a specified packet to your guild, specifying a rankId will only send the packet to your ranked members. (NOT DOCUMENTED)
    {"GiveCoinage", &LuaUnit::GiveCoinage},                         // :GiveCoinage(amount) - MODIFIES (does not set) coinage count.
    {"RemoveCoinage", &LuaUnit::RemoveCoinage},                     // :RemoveCoinage(amount) - Removes amount of coinage from plr.
    {"LearnSpell", &LuaUnit::LearnSpell},                           // :LearnSpell(id) - learns the given spell.
    {"RemoveItem", &LuaUnit::RemoveItem},                           // :RemoveItem(id, amount) - Removes amount of item to player.
    {"ResurrectPlayer", &LuaUnit::ResurrectPlayer},                 // :ResurrectPlayer(percent, sickness(bool)) - Resurrects the player at percentage, player gets resurrection sickness if sickness set to true.
    {"PlaySoundToPlayer", &LuaUnit::PlaySoundToPlayer},             // :PlaySoundToPlayer(soundId) - Plays the specified sound to the player (NOT DOCUMENTED)


    // Creature methods

    // Getters
    {"GetAITargets", &LuaUnit::GetAITargets},                       // :GetAITargets() - Get units in threat list
    {"GetAITargetsCount", &LuaUnit::GetAITargetsCount},             // :GetAITargetsCount() - Get threat list size

    // Other
    {"RegisterEvent", &LuaUnit::RegisterEvent},                     // :RegisterEvent(function, delay, calls) - UNDOCUMENTED
    {"RemoveEventByID", &LuaUnit::RemoveEventByID},                 // :RemoveEventByID(eventID) - UNDOCUMENTED
    {"RemoveEvents", &LuaUnit::RemoveEvents},                       // :RemoveEvents() - UNDOCUMENTED


    // Unit Methods

    // Getters
    {"GetName", &LuaUnit::GetName},                                 // :GetName()
    {"GetLevel", &LuaUnit::GetLevel},                               // :GetLevel()
    {"GetHealth", &LuaUnit::GetHealth},                             // :GetHealth()
    {"GetDisplayID", &LuaUnit::GetDisplayID},                       // :GetDisplayID()
    {"GetGUID", &LuaUnit::GetGUID},                                 // :GetGUID()
    {"GetMapId", &LuaUnit::GetMapId},                               // :GetMapId()
    {"GetX", &LuaUnit::GetX},                                       // :GetX()
    {"GetY", &LuaUnit::GetY},                                       // :GetY()
    {"GetZ", &LuaUnit::GetZ},                                       // :GetZ()
    {"GetO", &LuaUnit::GetO},                                       // :GetO()
    {"GetLocation", &LuaUnit::GetLocation},                         // :GetLocation() - returns X, Y, Z and O co-ords (in that order)
    {"GetAreaId", &LuaUnit::GetAreaId},                             // :GetAreaId()
    {"GetZoneId", &LuaUnit::GetZoneId},                             // :GetZoneId()
    {"GetPower", &LuaUnit::GetPower},                               // :GetPower(index) - returns power at index. Index can be omitted.
    {"GetMaxPower", &LuaUnit::GetMaxPower},                         // :GetMaxPower(index) - returns power at index. Index can be omitted.
    {"GetPowerType", &LuaUnit::GetPowerType},                       // :GetPowerType() - Returns the power type.
    {"GetMaxHealth", &LuaUnit::GetMaxHealth},                       // :GetMaxHealth()
    {"GetHealthPct", &LuaUnit::GetHealthPct},                       // :GetHealthPct()
    {"GetPowerPct", &LuaUnit::GetPowerPct},                         // :GetPowerPct(power_id)
    {"GetGender", &LuaUnit::GetGender},                             // :GetGender() - returns the gender where male = 0 female = 1
    {"GetRace", &LuaUnit::GetRace},                                 // :GetRace()
    {"GetClass", &LuaUnit::GetClass},                               // :GetClass()
    {"GetClassAsString", &LuaUnit::GetClassAsString},               // :GetClassAsString()
    {"GetUnitType", &LuaUnit::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Player, Creature
    {"GetEntry", &LuaUnit::GetEntry},                               // :GetEntry() - Returns the unit's entryId
    {"GetAura", &LuaUnit::GetAura},                                 // :GetAura(spellID) - returns aura object
    {"GetInt32Value", &LuaUnit::GetInt32Value},                     // :GetInt32Value(index) - returns an int value from unit fields UNDOCUMENTED
    {"GetUInt32Value", &LuaUnit::GetUInt32Value},                   // :GetUInt32Value(index) - returns an uint value from unit fields UNDOCUMENTED
    {"GetFloatValue", &LuaUnit::GetFloatValue},                     // :GetFloatValue(index) - returns a float value from unit fields UNDOCUMENTED
    {"GetByteValue", &LuaUnit::GetByteValue},                       // :GetByteValue(index, offset) - returns a byte value from unit fields UNDOCUMENTED
    {"GetUInt16Value", &LuaUnit::GetUInt16Value},                   // :GetUInt16Value(index, offset) - returns a uint16 value from unit fields UNDOCUMENTED

    // Setters
    {"SetLevel", &LuaUnit::SetLevel},                               // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                             // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                       // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                               // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                         // :SetMaxPower(index, amount)
    {"SetDisplayID", &LuaUnit::SetDisplayID},                       // :SetDisplayID(id)
    {"SetFacing", &LuaUnit::SetFacing},                             // :SetFacing(o) -- Sets the Unit facing to arg
    {"SetDeathState", &LuaUnit::SetDeathState},                     // :SetDeathState(value) -- 0 = alive 1 = just died 2 = corpse 3 = dead
    {"SetInt32Value", &LuaUnit::SetInt32Value},                     // :SetInt32Value(index, value) - Sets an int value for the unit UNDOCUMENTED
    {"SetUInt32Value", &LuaUnit::SetUInt32Value},                   // :SetUInt32Value(index, value) - Sets an uint value for the unit UNDOCUMENTED
    {"UpdateUInt32Value", &LuaUnit::UpdateUInt32Value},             // :UpdateUInt32Value(index, value) - Updates an uint value for the unit UNDOCUMENTED
    {"SetFloatValue", &LuaUnit::SetFloatValue},                     // :SetFloatValue(index, value) - Sets a float value for the unit UNDOCUMENTED
    {"SetByteValue", &LuaUnit::SetByteValue},                       // :SetByteValue(index, offset, value) - Sets a byte value for the unit UNDOCUMENTED
    {"SetUInt16Value", &LuaUnit::SetUInt16Value},                   // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the unit UNDOCUMENTED
    {"SetInt16Value", &LuaUnit::SetInt16Value},                     // :SetInt16Value(index, offset, value) - Sets an int16 value for the unit UNDOCUMENTED

    // Boolean
    {"IsAlive", &LuaUnit::IsAlive},                                 // :IsAlive()
    {"IsInWorld", &LuaUnit::IsInWorld},                             // :IsInWorld()
    {"IsPvPFlagged", &LuaUnit::IsPvPFlagged},                       // :IsPvPFlagged()
    {"HasQuest", &LuaUnit::HasQuest},                               // :HasQuest(id)
    {"IsInCombat", &LuaUnit::IsInCombat},                           // :IsInCombat()
    {"HasSpell", &LuaUnit::HasSpell},                               // :HasSpell(id)

    // Other
    {"DeMorph", &LuaUnit::DeMorph},                                 // :DeMorph() - Sets display back to native.
    {"SendUnitWhisper", &LuaUnit::SendUnitWhisper},                 // :SendUnitWhisper(msg, unit) -- Sends a whisper to the receiver
    {"SendUnitSay", &LuaUnit::SendUnitSay},                         // :SendUnitSay(msg, language) -- Sends a "Say" message with the specified language (all languages: 0)
    {"SendUnitYell", &LuaUnit::SendUnitYell},                       // :SendUnitYell(msg, language) -- Sends a "Yell" message with the specified language (all languages: 0)
    {"CastSpell", &LuaUnit::CastSpell},                             // :CastSpell(spellID) - Casts the spell on self, no manacost or cast time
    {"CastSpellOnTarget", &LuaUnit::CastSpellOnTarget},             // :CastSpellOnTarget(spellID, unit) - Casts the spell on target, no manacost or cast time
    {"CastSpellAoF", &LuaUnit::CastSpellAoF},                       // :CastSpellAoF(x, y, z, SpellID, triggered) - Casts the spell on coordinates, if triggered is false has manacost and cast time
    {"FullCastSpell", &LuaUnit::FullCastSpell},                     // :FullCastSpell(spellID) - Casts the spell on self
    {"FullCastSpellOnTarget", &LuaUnit::FullCastSpellOnTarget},     // :FullCastSpellOnTarget(spellID, unit) - Casts the spell on target
    {"PlayDirectSound", &LuaUnit::PlayDirectSound},                 // :PlayDirectSound(soundId,  player) - Unit plays soundID to player, or everyone around if no player. UNDOCUMENTED
    {"PlayDistanceSound", &LuaUnit::PlayDistanceSound},             // :PlayDistanceSound(soundId,  player) - Unit plays soundID to player, or everyone around if no player. The sound fades the further you are UNDOCUMENTED
    {"PlaySoundToSet", &LuaUnit::PlayDirectSound},                  // :PlayDirectSound(soundId,  player) - Unit plays soundID to player, or everyone around if no player. (ARC compability) UNDOCUMENTED
    {"Kill", &LuaUnit::Kill},                                       // :Kill(target, durabilityLoss) - Unit kills the target, if no target then kills the unit. Durabilityloss is true by default UNDOCUMENTED

    { NULL, NULL },
};

ElunaRegister<GameObject> GameObjectMethods[] =
{
    // Getters
    {"GetUnitType", &LuaGameObject::GetUnitType},                   // :GetUnitType() - Returns unit type Ex. GameObject UNDOCUMENTED
    {"GetGUID", &LuaGameObject::GetGUID},                           // :GetGUID() - returns object guid UNDOCUMENTED
    {"GetName", &LuaGameObject::GetName},                           // :GetName() - UNDOCUMENTED
    {"GetDisplayId", &LuaGameObject::GetDisplayId},                 // :GetDisplayId() - UNDOCUMENTED
    {"GetScale", &LuaGameObject::GetScale},                         // :GetScale() - UNDOCUMENTED
    {"GetEntry", &LuaGameObject::GetEntry},                         // :GetEntry() - UNDOCUMENTED
    {"GetMapId", &LuaGameObject::GetMapId},                         // :GetMapId() - UNDOCUMENTED
    {"GetX", &LuaGameObject::GetX},                                 // :GetX() - UNDOCUMENTED
    {"GetY", &LuaGameObject::GetY},                                 // :GetY() - UNDOCUMENTED
    {"GetZ", &LuaGameObject::GetZ},                                 // :GetZ() - UNDOCUMENTED
    {"GetO", &LuaGameObject::GetO},                                 // :GetO() - UNDOCUMENTED
    {"GetLocation", &LuaGameObject::GetLocation},                   // :GetLocation() - returns X, Y, Z and O co-ords (in that order) - UNDOCUMENTED
    {"GetAreaId", &LuaGameObject::GetAreaId},                       // :GetAreaId() - UNDOCUMENTED
    {"GetZoneId", &LuaGameObject::GetZoneId},                       // :GetZoneId() - UNDOCUMENTED
    {"GetInt32Value", &LuaGameObject::GetInt32Value},               // :GetInt32Value(index) - returns an int value from object fields UNDOCUMENTED
    {"GetUInt32Value", &LuaGameObject::GetUInt32Value},             // :GetUInt32Value(index) - returns an uint value from object fields UNDOCUMENTED
    {"GetFloatValue", &LuaGameObject::GetFloatValue},               // :GetFloatValue(index) - returns a float value from object fields UNDOCUMENTED
    {"GetByteValue", &LuaGameObject::GetByteValue},                 // :GetByteValue(index, offset) - returns a byte value from object fields UNDOCUMENTED
    {"GetUInt16Value", &LuaGameObject::GetUInt16Value},             // :GetUInt16Value(index, offset) - returns a uint16 value from object fields UNDOCUMENTED

    // Setters
    {"SetScale", &LuaGameObject::SetScale},                         // :SetScale(scale) - UNDOCUMENTED
    {"SetInt32Value", &LuaGameObject::SetInt32Value},               // :SetInt32Value(index, value) - Sets an int value for the object UNDOCUMENTED
    {"SetUInt32Value", &LuaGameObject::SetUInt32Value},             // :SetUInt32Value(index, value) - Sets an uint value for the object UNDOCUMENTED
    {"UpdateUInt32Value", &LuaGameObject::UpdateUInt32Value},       // :UpdateUInt32Value(index, value) - Updates an uint value for the object UNDOCUMENTED
    {"SetFloatValue", &LuaGameObject::SetFloatValue},               // :SetFloatValue(index, value) - Sets a float value for the object UNDOCUMENTED
    {"SetByteValue", &LuaGameObject::SetByteValue},                 // :SetByteValue(index, offset, value) - Sets a byte value for the object UNDOCUMENTED
    {"SetUInt16Value", &LuaGameObject::SetUInt16Value},             // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the object UNDOCUMENTED
    {"SetInt16Value", &LuaGameObject::SetInt16Value},               // :SetInt16Value(index, offset, value) - Sets an int16 value for the object UNDOCUMENTED

    // Boolean
    {"IsInWorld", &LuaGameObject::IsInWorld},                       // :IsInWorld() - UNDOCUMENTED
    {"IsTransport", &LuaGameObject::IsTransport},                   // :IsTransport() - UNDOCUMENTED
    {"IsDestructible", &LuaGameObject::IsDestructible},             // :IsDestructible() - UNDOCUMENTED
    {"IsActive", &LuaGameObject::IsActive},                         // :IsActive() - UNDOCUMENTED
    {"HasQuest", &LuaGameObject::HasQuest},                         // :HasQuest(questId) - UNDOCUMENTED
    
    // Other
    {"CastSpellOnTarget", &LuaGameObject::CastSpellOnTarget},       // :CastSpellOnTarget(target, spellId) - Casts the spell on target, no manacost or cast time - UNDOCUMENTED
    {"Move", &LuaGameObject::Move},                                 // :Move(x, y, z, o) - Moves the GO to coordinates - UNDOCUMENTED
    {"SummonCreature", &LuaGameObject::SummonCreature},             // :SummonCreature(entry, x, y, z, o, despawntime) Summons a temporary creature. 0 for infinitely, otherwise despawns after despawntime (ms) - UNDOCUMENTED
    {"RegisterEvent", &LuaGameObject::RegisterEvent},               // :RegisterEvent(function, delay, calls) - UNDOCUMENTED
    {"RemoveEventByID", &LuaGameObject::RemoveEventByID},           // :RemoveEventByID(eventID) - UNDOCUMENTED
    {"RemoveEvents", &LuaGameObject::RemoveEvents},                 // :RemoveEvents() - UNDOCUMENTED

    { NULL, NULL },
};

ElunaRegister<Group> GroupMethods[] = 
{
    // Getters
    {"GetMembers", &LuaGroup::GetMembers},                          // :GetMembers() - returns a table the players in this group. (Online?)
    {"GetLeaderGUID", &LuaGroup::GetLeaderGUID},
    {"GetLeader", &LuaGroup::GetLeader},
    {"GetUnitType", &LuaGroup::GetUnitType},
    {"GetGUID", &LuaGroup::GetGUID},

    // Setters
    {"SetLeader", &LuaGroup::ChangeLeader},                         // :SetLeader(Player) - Sets the player as the new leader.

    // Boolean
    {"IsLeader", &LuaGroup::IsLeader},                              // :IsLeader("name"/Player)
    //{"HasRole", &LuaGroup::HasRole},                              // :HasRole("name"/Player, "role") - "tank" / "healer" / "dps"

    // Other
    {"SendPacket", &LuaGroup::SendPacket},                          // :SendPacket(packet, sendToPlayersInBattleground[, ignoreguid]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground. Optionally ignores given player guid. UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Guild> GuildMethods[] = 
{
    // Getters
    {"GetMembers", &LuaGuild::GetMembers},                          // :GetMembers() - returns a table containing the players in this guild. (Online?)
    {"GetUnitType", &LuaGuild::GetUnitType},                        // :GetUnitType() - Returns the unit type. Eg: Guild
    {"GetLeaderGUID", &LuaGuild::GetLeaderGUID},                    // :GetLeaderGUID() - Returns the guild learder's guid
    {"GetId", &LuaGuild::GetId},                                    // :GetId() - Gets the guild's ID UNDOCUMENTED
    {"GetName", &LuaGuild::GetName},                                // :GetName() - Gets the guild name UNDOCUMENTED
    {"GetMOTD", &LuaGuild::GetMOTD},                                // :GetMOTD() - Gets the guild MOTD string UNDOCUMENTED
    {"GetInfo", &LuaGuild::GetInfo},                                // :GetInfo() - Gets the guild info string UNDOCUMENTED

    // Setters
    {"SetBankTabText", &LuaGuild::SetBankTabText},                  // :SetBankTabText(tabId, text) - UNDOCUMENTED
    {"SetMemberRank", &LuaGuild::ChangeMemberRank},                 // :SetMemberRank(player, newRank) - Sets the player rank in the guild to the new rank UNDOCUMENTED

    // Boolean

    // Other
    {"SendPacket", &LuaGuild::SendPacket},                          // :SendPacket(packet) - sends packet to guild. UNDOCUMENTED
    {"SendPacketToRanked", &LuaGuild::SendPacketToRanked},          // :SendPacketToRanked(packet, rankId) - sends packet to guild, specifying a rankId will only send the packet to your ranked members. UNDOCUMENTED
    {"Disband", &LuaGuild::Disband},                                // :Disband() - Disbands the guild UNDOCUMENTED
    {"AddMember", &LuaGuild::AddMember},                            // :AddMember(player, rank) - adds the player to the guild. Rank is optional UNDOCUMENTED
    {"DeleteMember", &LuaGuild::DeleteMember},                      // :DeleteMember(player, disbanding, kicked) - Deletes the player from the guild. Disbanding and kicked are optional bools. UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<QueryResult> QueryMethods[] =  // UNDOCUMENTED
{
    {"GetUnitType", &LuaQuery::GetUnitType},                        // :GetUnitType() - Returns object type, IE: QueryResult

    {"NextRow", &LuaQuery::NextRow},                                // :NextRow() - Advances to next rown in the query. Returns true if there is a next row, otherwise false.
    {"GetColumnCount", &LuaQuery::GetColumnCount},                  // :GetColumnCount() - Gets the column count of the query
    {"GetRowCount", &LuaQuery::GetRowCount},                        // :GetRowCount() - Gets the row count of the query

    {"GetBool", &LuaQuery::GetBool},                                // :GetBool(column) -- returns a bool from a number column (for example tinyint)
    {"GetUInt8", &LuaQuery::GetUInt8},                              // :GetInt8(column) -- returns the value of an unsigned tinyint column
    {"GetUInt16", &LuaQuery::GetUInt16},                            // :GetInt16(column) -- returns the value of a unsigned smallint column
    {"GetUInt32", &LuaQuery::GetUInt32},                            // :GetInt32(column) -- returns the value of an unsigned int or mediumint column
    //{"GetUInt64", &LuaQuery::GetUInt64},
    {"GetInt8", &LuaQuery::GetInt8},                                // :GetInt8(column) -- returns the value of an tinyint column
    {"GetInt16", &LuaQuery::GetInt16},                              // :GetInt16(column) -- returns the value of a smallint column
    {"GetInt32", &LuaQuery::GetInt32},                              // :GetInt32(column) -- returns the value of an int or mediumint column
    //{"GetInt64", &LuaQuery::GetInt64},
    {"GetFloat", &LuaQuery::GetFloat},                              // :GetFloat(column) -- returns the value of a float column
    {"GetDouble", &LuaQuery::GetDouble},                            // :GetDouble(column) -- returns the value of a double column
    {"GetString", &LuaQuery::GetString},                            // :GetString(column) -- returns the value of a string column
    {"IsNull", &LuaQuery::IsNull},                                  // :IsNull(column) -- returns true if the column is null

    {NULL, NULL},
};
    
ElunaRegister<Aura> AuraMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaAura::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Aura, Creature UNDOCUMENTED
    {"GetCaster", &LuaAura::GetCaster},                             // :GetCaster() - Returns caster as object. UNDOCUMENTED
    {"GetCasterGUID", &LuaAura::GetCasterGUID},                     // :GetCasterGUID() - Returns caster as GUID. UNDOCUMENTED
    {"GetCasterLevel", &LuaAura::GetCasterLevel},                   // :GetCasterLevel() - Returns casters level. UNDOCUMENTED
    {"GetDuration", &LuaAura::GetDuration},                         // :GetDuration() - Returns remaining duration. UNDOCUMENTED
    {"GetMaxDuration", &LuaAura::GetMaxDuration},                   // :GetMaxDuration() - Returns maximum duration. UNDOCUMENTED
    {"GetCharges", &LuaAura::GetCharges},                           // :GetCharges() - Returns remaining charges. UNDOCUMENTED
    {"GetAuraId", &LuaAura::GetAuraId},                             // :GetAuraId() - Returns aura ID. UNDOCUMENTED
    {"GetStackAmount", &LuaAura::GetStackAmount},                   // :GetStackAmount() - Returns current stack amount. UNDOCUMENTED
    {"GetOwner", &LuaAura::GetOwner},                               // :GetOwner() - Gets the unit wearing the aura UNDOCUMENTED

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                         // :SetDuration(duration) - Sets remaining duration. UNDOCUMENTED
    {"SetMaxDuration", &LuaAura::SetMaxDuration},                   // :SetMaxDuration(duration) - Sets maximum duration. UNDOCUMENTED
    {"SetStackAmount", &LuaAura::SetStackAmount},                   // :SetStackAmount(amount) - Sets current stack amount. UNDOCUMENTED

    // Other
    {"Remove", &LuaAura::Remove},                                   // :Remove() - Removes the aura. UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Channel> ChannelMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaChannel::GetUnitType},                      // :GetUnitType() - Returns object type, IE: Channel, Creature UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Item> ItemMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaItem::GetUnitType},                                 // :GetUnitType() - Returns object type, IE: Item, Creature UNDOCUMENTED
    {"GetGUID", &LuaItem::GetGUID},                                         // :GetGUID() - Returns object guid UNDOCUMENTED
    {"GetOwnerGUID", &LuaItem::GetOwnerGUID},                               // :GetOwnerGUID() - Returns the owner's guid UNDOCUMENTED
    {"GetOwner", &LuaItem::GetOwner},                                       // :GetOwner() - Returns the owner object (player) UNDOCUMENTED
    {"GetCount", &LuaItem::GetCount},                                       // :GetCount() - Returns item stack count UNDOCUMENTED
    {"GetMaxStackCount", &LuaItem::GetMaxStackCount},                       // :GetMaxStackCount() - Returns item max stack count RUNDOCUMENTED
    {"GetSlot", &LuaItem::GetSlot},                                         // :GetSlot() - returns the slot the item is in UNDOCUMENTED
    {"GetBagSlot", &LuaItem::GetBagSlot},                                   // :GetBagSlot() - returns the bagslot the item is in UNDOCUMENTED
    {"GetEntry", &LuaItem::GetEntry},                                       // :GetEntry() - returns the item entry UNDOCUMENTED
    {"GetInt32Value", &LuaItem::GetInt32Value},                             // :GetInt32Value(index) - returns an int value from item fields UNDOCUMENTED
    {"GetUInt32Value", &LuaItem::GetUInt32Value},                           // :GetUInt32Value(index) - returns an uint value from item fields UNDOCUMENTED
    {"GetFloatValue", &LuaItem::GetFloatValue},                             // :GetFloatValue(index) - returns a float value from item fields UNDOCUMENTED
    {"GetByteValue", &LuaItem::GetByteValue},                               // :GetByteValue(index, offset) - returns a byte value from item fields UNDOCUMENTED
    {"GetUInt16Value", &LuaItem::GetUInt16Value},                           // :GetUInt16Value(index, offset) - returns a uint16 value from item fields UNDOCUMENTED

    // Setters
    {"SetOwner", &LuaItem::SetOwner},                                       // :SetOwner(player) - Sets the owner of the item UNDOCUMENTED
    {"SetBinding", &LuaItem::SetBinding},                                   // :SetBinding(bound) - Sets the item binding to true or false UNDOCUMENTED
    {"SetCount", &LuaItem::SetCount},                                       // :SetCount(count) - Sets the item count UNDOCUMENTED
    {"SetInt32Value", &LuaItem::SetInt32Value},                             // :SetInt32Value(index, value) - Sets an int value for the item UNDOCUMENTED
    {"SetUInt32Value", &LuaItem::SetUInt32Value},                           // :SetUInt32Value(index, value) - Sets an uint value for the item UNDOCUMENTED
    {"UpdateUInt32Value", &LuaItem::UpdateUInt32Value},                     // :UpdateUInt32Value(index, value) - Updates an uint value for the item UNDOCUMENTED
    {"SetFloatValue", &LuaItem::SetFloatValue},                             // :SetFloatValue(index, value) - Sets a float value for the item UNDOCUMENTED
    {"SetByteValue", &LuaItem::SetByteValue},                               // :SetByteValue(index, offset, value) - Sets a byte value for the item UNDOCUMENTED
    {"SetUInt16Value", &LuaItem::SetUInt16Value},                           // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the item UNDOCUMENTED
    {"SetInt16Value", &LuaItem::SetInt16Value},                             // :SetInt16Value(index, offset, value) - Sets an int16 value for the item UNDOCUMENTED

    // Boolean
    {"IsSoulBound", &LuaItem::IsSoulBound},                                 // :IsSoulBound() - Returns true if the item is soulbound UNDOCUMENTED
    {"IsBoundAccountWide", &LuaItem::IsBoundAccountWide},                   // :IsBoundAccountWide() - Returns true if the item is account bound UNDOCUMENTED
    {"IsBoundByEnchant", &LuaItem::IsBoundByEnchant},                       // :IsBoundByEnchant() - Returns true if the item is bound with an enchant UNDOCUMENTED
    {"IsBindedNotWith", &LuaItem::IsBindedNotWith},                         // :IsBindedNotWith(player) - Returns true if the item is not bound with player UNDOCUMENTED
    {"IsLocked", &LuaItem::IsBindedNotWith},                                // :IsLocked() - Returns true if the item is locked UNDOCUMENTED
    {"IsBag", &LuaItem::IsBag},                                             // :IsBag() - Returns true if the item is a bag UNDOCUMENTED
    {"IsCurrencyToken", &LuaItem::IsCurrencyToken},                         // :IsCurrencyToken() - Returns true if the item is a currency token UNDOCUMENTED
    {"IsNotEmptyBag", &LuaItem::IsNotEmptyBag},                             // :IsNotEmptyBag() - Returns true if the item is not an empty bag UNDOCUMENTED
    {"IsBroken", &LuaItem::IsBroken},                                       // :IsBroken() - Returns true if the item is broken UNDOCUMENTED
    {"CanBeTraded", &LuaItem::CanBeTraded},                                 // :CanBeTraded() - Returns true if the item can be traded UNDOCUMENTED
    {"IsInTrade", &LuaItem::IsInTrade},                                     // :IsInTrade() - Returns true if the item is in trade UNDOCUMENTED
    {"IsInBag", &LuaItem::IsInBag},                                         // :IsInBag() - Returns true if the item is in a bag UNDOCUMENTED
    {"IsEquipped", &LuaItem::IsEquipped},                                   // :IsEquipped() - Returns true if the item is equipped UNDOCUMENTED
    {"hasQuest", &LuaItem::hasQuest},                                       // :hasQuest(questId) - Returns true if the item starts the quest UNDOCUMENTED
    {"IsPotion", &LuaItem::IsPotion},                                       // :IsPotion() - Returns true if the item is a potion UNDOCUMENTED
    {"IsWeaponVellum", &LuaItem::IsWeaponVellum},                           // :IsWeaponVellum() - Returns true if the item is a weapon vellum UNDOCUMENTED
    {"IsArmorVellum", &LuaItem::IsArmorVellum},                             // :IsArmorVellum() - Returns true if the item is an armor vellum UNDOCUMENTED
    {"IsConjuredConsumable", &LuaItem::IsConjuredConsumable},               // :IsConjuredConsumable() - Returns true if the item is a conjured consumable UNDOCUMENTED
    {"IsRefundExpired", &LuaItem::IsRefundExpired},                         // :IsRefundExpired() - Returns true if the item's refund time has expired UNDOCUMENTED
    {"SetEnchantment", &LuaItem::SetEnchantment},                           // :SetEnchantment(enchantid) - Sets a new enchantment for the item. Returns true on success. UNDOCUMENTED
    {"ClearEnchantment", &LuaItem::ClearEnchantment},                       // :ClearEnchantment() - Removes the enchantment from the item if one exists. Returns true on success. UNDOCUMENTED

    // Other

    {NULL, NULL},
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template<> ElunaRegister<Unit>* GetMethodTable<Unit>() { return UnitMethods; }
template<> ElunaRegister<GameObject>* GetMethodTable<GameObject>() { return GameObjectMethods; }
template<> ElunaRegister<Group>* GetMethodTable<Group>() { return GroupMethods; }
template<> ElunaRegister<Guild>* GetMethodTable<Guild>() { return GuildMethods; }
template<> ElunaRegister<QueryResult>* GetMethodTable<QueryResult>() { return QueryMethods; }
template<> ElunaRegister<Aura>* GetMethodTable<Aura>() { return AuraMethods; }
template<> ElunaRegister<Channel>* GetMethodTable<Channel>() { return ChannelMethods; }
template<> ElunaRegister<Item>* GetMethodTable<Item>() { return ItemMethods; }
#endif
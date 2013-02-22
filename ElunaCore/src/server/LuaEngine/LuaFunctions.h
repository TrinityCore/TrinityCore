#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Unit> UnitMethods[] =
{
    // Player Methods

    // Getters
    {"GetSelection", &LuaUnit::GetSelection},                     // :GetSelection()
    {"GetGuildID", &LuaUnit::GetGuildID},                         // :GetGuildID() - nil on no guild.
    {"GetCoinage", &LuaUnit::GetCoinage},                         // :GetCoinage()
    {"GetTeam", &LuaUnit::GetTeam},                               // :GetTeam() - returns the player's team. 0 for ally, 1 for whored
    {"GetItemCount", &LuaUnit::GetItemCount},                     // :GetItemCount(item_id)
    {"GetGroup", &LuaUnit::GetGroup},                             // :GetGroup()
    {"GetGuild", &LuaUnit::GetGuild},                             // :GetGuild()
	{"GetGearLevel", &LuaUnit::GetGearLevel},                     // :GetGearLevel() -- Returns the player's average gear level

    // Setters
    {"SetCoinage", &LuaUnit::SetCoinage},                         // :SetCoinage(amount) - sets plr's coinage to this.
    {"SetKnownTitle", &LuaUnit::SetKnownTitle},                   // :SetKnownTitle(id)
    {"UnsetKnownTitle", &LuaUnit::UnsetKnownTitle},               // :UnsetKnownTitle(id)
	{"AdvanceSkillsToMax", &LuaUnit::AdvanceSkillsToMax},         // :AdvanceSkillsToMax() -- Advances all currently known skills to the currently known max level
	{"AdvanceSkill", &LuaUnit::AdvanceSkill},                     // AdvanceSkill(skill_id, step) -- Advances skill by ID and the amount(step)
	{"AdvanceAllSkills", &LuaUnit::AdvanceAllSkills},             // AdvanceAllSkills(value) -- Advances all current skills to your input(value)

    // Boolean
    {"IsInGroup", &LuaUnit::IsInGroup},                           // :IsInGroup()
    {"IsInGuild", &LuaUnit::IsInGuild},                           // :IsInGuild()
    {"IsGM", &LuaUnit::IsGM},                                     // :IsGM()
    {"IsAlliance", &LuaUnit::IsAlliance},                         // :IsAlliance()
    {"IsHorde", &LuaUnit::IsHorde},                               // :IsHorde()
    {"HasTitle", &LuaUnit::HasTitle},                             // :HasTitle(id)

    // Gossip                                                           
    {"GossipMenuAddItem", &LuaUnit::GossipMenuAddItem },                // :GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    {"GossipComplete", &LuaUnit::GossipComplete },                      // :GossipComplete()
    {"GossipSendMenu", &LuaUnit::GossipSendMenu },                      // :GossipSendMenu(npc_text, unit)

	// Update

    // Other
    {"SendBroadcastMessage", &LuaUnit::SendBroadcastMessage},     // :SendBroadcastMessage(message)
	{"SendAreaTriggerMessage", &LuaUnit::SendAreaTriggerMessage}, // :SendAreaTriggerMessage(message) -- Sends a message in the middle of your screen
    {"GiveCoinage", &LuaUnit::GiveCoinage},                       // :GiveCoinage(amount) - MODIFIES (does not set) coinage count.
    {"RemoveCoinage", &LuaUnit::RemoveCoinage},                   // :RemoveCoinage(amount) - Removes amount of coinage from plr.
    {"LearnSpell", &LuaUnit::LearnSpell},                         // :LearnSpell(id) - learns the given spell.
    {"Teleport", &LuaUnit::Teleport},                             // :Teleport(Map, X, Y, Z, O) - Teleports player to specified co-ordinates.
    {"AddItem", &LuaUnit::AddItem},                               // :AddItem(id, amount) - Adds amount of item to player.
    {"RemoveItem", &LuaUnit::RemoveItem},                         // :RemoveItem(id, amount) - Removes amount of item to player.

    // Unit Methods

    // Getters
    {"GetByteValue", &LuaUnit::GetByteValue},                       // :GetByteValue(index, offset)
    {"GetName", &LuaUnit::GetName},                                 // :GetName()
    {"GetLevel", &LuaUnit::GetLevel},                               // :GetLevel()
    {"GetHealth", &LuaUnit::GetHealth},                             // :GetHealth()
    {"GetDisplayID", &LuaUnit::GetDisplayID},                       // :GetDisplayID()
    {"GetGUID", &LuaUnit::GetGUID},                                 // :GetGUID()
    {"GetX", &LuaUnit::GetX},                                       // :GetX()
    {"GetY", &LuaUnit::GetY},                                       // :GetY()
    {"GetZ", &LuaUnit::GetZ},                                       // :GetZ()
    {"GetO", &LuaUnit::GetO},                                       // :GetO()
    {"GetLocation", &LuaUnit::GetLocation},                         // :GetLocation() - returns X, Y, Z and O co-ords (in that order)
    {"GetAreaID", &LuaUnit::GetAreaID},                             // :GetAreaID()
    {"GetZoneID", &LuaUnit::GetZoneID},                             // :GetZoneID()
    {"GetPower", &LuaUnit::GetPower},                               // :GetPower(index) - returns power at index. Index can be omitted.
    {"GetMaxPower", &LuaUnit::GetMaxPower},                         // :GetMaxPower(index) - returns power at index. Index can be omitted.
    {"GetMaxHealth", &LuaUnit::GetMaxHealth},                       // :GetMaxHealth()
    {"GetHealthPct", &LuaUnit::GetHealthPct},                       // :GetHealthPct()
    {"GetPowerPct", &LuaUnit::GetPowerPct},                         // :GetPowerPct(power_id)
    {"GetRace", &LuaUnit::GetRace},                                 // :GetRace()
    {"GetClass", &LuaUnit::GetClass},                               // :GetClass()
    {"GetClassAsString", &LuaUnit::GetClassAsString},               // :GetClassAsString()
    {"GetUnitType", &LuaUnit::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Player
	{"GetEntry", &LuaUnit::GetEntry},                               // :GetEntry() - Returns the creatures entryId

    // Setters
    {"SetLevel", &LuaUnit::SetLevel},                               // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                             // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                       // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                               // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                         // :SetMaxPower(index, amount)
    {"SetDisplayID", &LuaUnit::SetDisplayID},                       // :SetDisplayID(id)

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

    { NULL, NULL },
};

ElunaRegister<Group> GroupMethods[] = 
{
	// Getters
	{"GetMembers", &LuaGroup::GetMembers},							// :GetMembers() - returns a table the players in this group. (Online?)
	{"GetLeaderGUID", &LuaGroup::GetLeaderGUID},
	{"GetLeader", &LuaGroup::GetLeader},
	{"GetUnitType", &LuaGroup::GetUnitType},
	{"GetGUID", &LuaGroup::GetGUID},

	// Setters
	{"SetLeader", &LuaGroup::ChangeLeader},							// :SetLeader(Player) - Sets the player as the new leader.

	// Boolean
	{"IsLeader", &LuaGroup::IsLeader},								// :IsLeader("name"/Player)
	//{"HasRole", &LuaGroup::HasRole},								// :HasRole("name"/Player, "role") - "tank" / "healer" / "dps"

	// Other

	{NULL, NULL}
};

ElunaRegister<Guild> GuildMethods[] = 
{
	// Getters
	{"GetMembers", &LuaGuild::GetMembers},							// :GetMembers() - returns a table containing the players in this guild. (Online?)
	{"GetUnitType", &LuaGuild::GetUnitType},
	{"GetLeaderGUID", &LuaGuild::GetLeaderGUID},
	// Setters

	// Boolean
	
	// Other
	{NULL, NULL}
};

ElunaRegister<QueryResult> QueryMethods[] =  // Not working yet
{
	//{"GetColumn", &LuaQuery::GetColumn},
	{"NextRow", &LuaQuery::NextRow},
	{"GetColumnCount", &LuaQuery::GetColumnCount},
	{"GetRowCount", &LuaQuery::GetRowCount},
    
    //TC
	{"GetBool", &LuaQuery::GetBool},
	{"GetUInt8", &LuaQuery::GetUInt8},
	{"GetUInt16", &LuaQuery::GetUInt16},
	{"GetUInt32", &LuaQuery::GetUInt32},
	//{"GetUInt64", &LuaQuery::GetUInt64},
	{"GetInt8", &LuaQuery::GetInt8},
	{"GetInt16", &LuaQuery::GetInt16},
	{"GetInt32", &LuaQuery::GetInt32},
	//{"GetInt64", &LuaQuery::GetInt64},
	{"GetFloat", &LuaQuery::GetFloat},
	{"GetDouble", &LuaQuery::GetDouble},
	{"GetCString", &LuaQuery::GetCString},
	{"GetString", &LuaQuery::GetString},
	{"IsNull", &LuaQuery::IsNull},
    //ARC
	//{"GetByte", &LuaQuery::GetByte},
	//{"GetUByte", &LuaQuery::GetUByte},
	//{"GetShort", &LuaQuery::GetShort},
	//{"GetUShort", &LuaQuery::GetUShort},
	//{"GetLong", &LuaQuery::GetLong},
	//{"GetULong", &LuaQuery::GetULong},
	//{"GetString", &LuaQuery::GetString},
	//{"GetGUID", &LuaQuery::GetGUID},
	//{"GetFloat", &LuaQuery::GetFloat},
	{NULL, NULL}
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template<> ElunaRegister<Unit>* GetMethodTable<Unit>() { return UnitMethods; }
template<> ElunaRegister<Group>* GetMethodTable<Group>() { return GroupMethods; }
template<> ElunaRegister<Guild>* GetMethodTable<Guild>() { return GuildMethods; }
template<> ElunaRegister<QueryResult>* GetMethodTable<QueryResult>() { return QueryMethods; }
#endif
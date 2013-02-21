#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Player> PlayerMethods[] =
{
	// Getters
	{"GetByteValue", &LuaPlayer::GetByteValue},						// :GetByteValue(index, offset)
	{"GetName", &LuaPlayer::GetName},								// :GetName()
	{"GetLevel", &LuaPlayer::GetLevel},								// :GetLevel()
	{"GetHealth", &LuaPlayer::GetHealth},							// :GetHealth()
	{"GetGuildID", &LuaPlayer::GetGuildID},							// :GetGuildID() - nil on no guild.
	{"GetCoinage", &LuaPlayer::GetCoinage},							// :GetCoinage()
	{"GetDisplayID", &LuaPlayer::GetDisplayID},						// :GetDisplayID()
	{"GetGUID", &LuaPlayer::GetGUID},								// :GetGUID()
	{"GetX", &LuaPlayer::GetX},										// :GetX()
	{"GetY", &LuaPlayer::GetY},										// :GetY()
	{"GetZ", &LuaPlayer::GetZ},										// :GetZ()
	{"GetO", &LuaPlayer::GetO},										// :GetO()
	{"GetLocation", &LuaPlayer::GetLocation},						// :GetLocation() - returns X, Y, Z and O co-ords (in that order)
	{"GetAreaID", &LuaPlayer::GetAreaID},							// :GetAreaID()
	{"GetZoneID", &LuaPlayer::GetZoneID},							// :GetZoneID()
	{"GetTeam", &LuaPlayer::GetTeam},								// :GetTeam() - returns the player's team. 0 for ally, 1 for whored
	{"GetPower", &LuaPlayer::GetPower},								// :GetPower(index) - returns power at index. Index can be omitted.
	{"GetMaxPower", &LuaPlayer::GetMaxPower},						// :GetMaxPower(index) - returns power at index. Index can be omitted.
	{"GetMaxHealth", &LuaPlayer::GetMaxHealth},						// :GetMaxHealth()
	{"GetHealthPct", &LuaPlayer::GetHealthPct},						// :GetHealthPct()
	{"GetPowerPct", &LuaPlayer::GetPowerPct},						// :GetPowerPct(power_id)
	{"GetRace", &LuaPlayer::GetRace},								// :GetRace()
	{"GetClass", &LuaPlayer::GetClass},								// :GetClass()
	{"GetClassAsString", &LuaPlayer::GetClassAsString},				// :GetClassAsString()
	{"GetItemCount", &LuaPlayer::GetItemCount},						// :GetItemCount(item_id)
	{"GetUnitType", &LuaPlayer::GetUnitType},						// :GetUnitType() - Returns object type, IE: Player

	// Setters
	{"SetLevel", &LuaPlayer::SetLevel},								// :SetLevel(amount)
	{"SetHealth", &LuaPlayer::SetHealth},							// :SetHealth(amount)
	{"SetMaxHealth", &LuaPlayer::SetMaxHealth},						// :SetMaxHealth(amount)
	{"SetPower", &LuaPlayer::SetPower},								// :SetPower(index, amount)
	{"SetMaxPower", &LuaPlayer::SetMaxPower},						// :SetMaxPower(index, amount)
	{"SetDisplayID", &LuaPlayer::SetDisplayID},						// :SetDisplayID(id)
	{"SetCoinage", &LuaPlayer::SetCoinage},							// :SetCoinage(amount) - sets plr's coinage to this.
	{"SetKnownTitle", &LuaPlayer::SetKnownTitle},					// :SetKnownTitle(id)
	{"UnsetKnownTitle", &LuaPlayer::UnsetKnownTitle},				// :UnsetKnownTitle(id)

	// Boolean
	{"IsAlive", &LuaPlayer::IsAlive},								// :IsAlive()
	{"IsInWorld", &LuaPlayer::IsInWorld},							// :IsInWorld()
	{"IsPvPFlagged", &LuaPlayer::IsPvPFlagged},						// :IsPvPFlagged()
	{"HasQuest", &LuaPlayer::HasQuest},								// :HasQuest(id)
	{"IsInGroup", &LuaPlayer::IsInGroup},							// :IsInGroup()
	{"IsInGuild", &LuaPlayer::IsInGuild},							// :IsInGuild()
	{"IsGM", &LuaPlayer::IsGM},										// :IsGM()
	{"IsAlliance", &LuaPlayer::IsAlliance},							// :IsAlliance()
	{"IsHorde", &LuaPlayer::IsHorde},								// :IsHorde()
	{"IsInCombat", &LuaPlayer::IsInCombat},							// :IsHorde()
	{"HasTitle", &LuaPlayer::HasTitle},								// :HasTitle(id)
	{"HasSpell", &LuaPlayer::HasSpell},								// :HasSpell(id)

	// Gossip
	{"GossipMenuAddItem", &LuaPlayer::GossipMenuAddItem },         // :GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
	{"GossipComplete", &LuaPlayer::GossipComplete },               // :GossipComplete()
	{"GossipSendMenu", &LuaPlayer::GossipSendMenu },               // :GossipSendMenu(npc_text, unit)

	// Other
	{"SendBroadcastMessage", &LuaPlayer::SendBroadcastMessage},		// :SendBroadcastMessage(message)
	{"GiveCoinage", &LuaPlayer::GiveCoinage},						// :GiveCoinage(amount) - MODIFIES (does not set) coinage count.
	{"RemoveCoinage", &LuaPlayer::RemoveCoinage},					// :RemoveCoinage(amount) - Removes amount of coinage from plr.
	{"LearnSpell", &LuaPlayer::LearnSpell},							// :LearnSpell(id) - learns the given spell.
	{"Teleport", &LuaPlayer::Teleport},								// :Teleport(Map, X, Y, Z, O) - Teleports player to specified co-ordinates.
	{"AddItem", &LuaPlayer::AddItem},								// :AddItem(id, amount) - Adds amount of item to player.
	{"RemoveItem", &LuaPlayer::RemoveItem},							// :RemoveItem(id, amount) - Removes amount of item to player.
	{"DeMorph", &LuaPlayer::DeMorph},								// :DeMorph() - Sets display back to native.
	{ NULL, NULL },
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template <> ElunaRegister<Player>* GetMethodTable<Player>() { return PlayerMethods; }
#endif
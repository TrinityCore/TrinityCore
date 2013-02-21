#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Unit> UnitMethods[] =
{
	// Getters
	{"GetByteValue", &LuaUnit::GetByteValue},						// :GetByteValue(index, offset)
	{"GetName", &LuaUnit::GetName},								// :GetName()
	{"GetLevel", &LuaUnit::GetLevel},								// :GetLevel()
	{"GetHealth", &LuaUnit::GetHealth},							// :GetHealth()
	{"GetGuildID", &LuaUnit::GetGuildID},							// :GetGuildID() - nil on no guild.
	{"GetCoinage", &LuaUnit::GetCoinage},							// :GetCoinage()
	{"GetDisplayID", &LuaUnit::GetDisplayID},						// :GetDisplayID()
	{"GetGUID", &LuaUnit::GetGUID},								// :GetGUID()
	{"GetX", &LuaUnit::GetX},										// :GetX()
	{"GetY", &LuaUnit::GetY},										// :GetY()
	{"GetZ", &LuaUnit::GetZ},										// :GetZ()
	{"GetO", &LuaUnit::GetO},										// :GetO()
	{"GetLocation", &LuaUnit::GetLocation},						// :GetLocation() - returns X, Y, Z and O co-ords (in that order)
	{"GetAreaID", &LuaUnit::GetAreaID},							// :GetAreaID()
	{"GetZoneID", &LuaUnit::GetZoneID},							// :GetZoneID()
	{"GetTeam", &LuaUnit::GetTeam},								// :GetTeam() - returns the player's team. 0 for ally, 1 for whored
	{"GetPower", &LuaUnit::GetPower},								// :GetPower(index) - returns power at index. Index can be omitted.
	{"GetMaxPower", &LuaUnit::GetMaxPower},						// :GetMaxPower(index) - returns power at index. Index can be omitted.
	{"GetMaxHealth", &LuaUnit::GetMaxHealth},						// :GetMaxHealth()
	{"GetHealthPct", &LuaUnit::GetHealthPct},						// :GetHealthPct()
	{"GetPowerPct", &LuaUnit::GetPowerPct},						// :GetPowerPct(power_id)
	{"GetRace", &LuaUnit::GetRace},								// :GetRace()
	{"GetClass", &LuaUnit::GetClass},								// :GetClass()
	{"GetClassAsString", &LuaUnit::GetClassAsString},				// :GetClassAsString()
	{"GetItemCount", &LuaUnit::GetItemCount},						// :GetItemCount(item_id)
	{"GetUnitType", &LuaUnit::GetUnitType},						// :GetUnitType() - Returns object type, IE: Player

	// Setters
	{"SetLevel", &LuaUnit::SetLevel},								// :SetLevel(amount)
	{"SetHealth", &LuaUnit::SetHealth},							// :SetHealth(amount)
	{"SetMaxHealth", &LuaUnit::SetMaxHealth},						// :SetMaxHealth(amount)
	{"SetPower", &LuaUnit::SetPower},								// :SetPower(index, amount)
	{"SetMaxPower", &LuaUnit::SetMaxPower},						// :SetMaxPower(index, amount)
	{"SetDisplayID", &LuaUnit::SetDisplayID},						// :SetDisplayID(id)
	{"SetCoinage", &LuaUnit::SetCoinage},							// :SetCoinage(amount) - sets plr's coinage to this.
	{"SetKnownTitle", &LuaUnit::SetKnownTitle},					// :SetKnownTitle(id)
	{"UnsetKnownTitle", &LuaUnit::UnsetKnownTitle},				// :UnsetKnownTitle(id)

	// Boolean
	{"IsAlive", &LuaUnit::IsAlive},								// :IsAlive()
	{"IsInWorld", &LuaUnit::IsInWorld},							// :IsInWorld()
	{"IsPvPFlagged", &LuaUnit::IsPvPFlagged},						// :IsPvPFlagged()
	{"HasQuest", &LuaUnit::HasQuest},								// :HasQuest(id)
	{"IsInGroup", &LuaUnit::IsInGroup},							// :IsInGroup()
	{"IsInGuild", &LuaUnit::IsInGuild},							// :IsInGuild()
	{"IsGM", &LuaUnit::IsGM},										// :IsGM()
	{"IsAlliance", &LuaUnit::IsAlliance},							// :IsAlliance()
	{"IsHorde", &LuaUnit::IsHorde},								// :IsHorde()
	{"IsInCombat", &LuaUnit::IsInCombat},							// :IsHorde()
	{"HasTitle", &LuaUnit::HasTitle},								// :HasTitle(id)
	{"HasSpell", &LuaUnit::HasSpell},								// :HasSpell(id)

	// Other

	{"SendBroadcastMessage", &LuaUnit::SendBroadcastMessage},		// :SendBroadcastMessage(message)
	{"GiveCoinage", &LuaUnit::GiveCoinage},						// :GiveCoinage(amount) - MODIFIES (does not set) coinage count.
	{"RemoveCoinage", &LuaUnit::RemoveCoinage},					// :RemoveCoinage(amount) - Removes amount of coinage from plr.
	{"LearnSpell", &LuaUnit::LearnSpell},							// :LearnSpell(id) - learns the given spell.
	{"Teleport", &LuaUnit::Teleport},								// :Teleport(Map, X, Y, Z, O) - Teleports player to specified co-ordinates.
	{"AddItem", &LuaUnit::AddItem},								// :AddItem(id, amount) - Adds amount of item to player.
	{"RemoveItem", &LuaUnit::RemoveItem},							// :RemoveItem(id, amount) - Removes amount of item to player.
	{"DeMorph", &LuaUnit::DeMorph},								// :DeMorph() - Sets display back to native.
	{ NULL, NULL },
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template <> ElunaRegister<Unit>* GetMethodTable<Unit>() { return UnitMethods; }
#endif
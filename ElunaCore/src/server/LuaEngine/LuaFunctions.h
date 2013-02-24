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


    // Unit Methods

    // Getters
    {"GetByteValue", &LuaUnit::GetByteValue},                       // :GetByteValue(index, offset)
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

    // Setters
    {"SetLevel", &LuaUnit::SetLevel},                               // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                             // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                       // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                               // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                         // :SetMaxPower(index, amount)
    {"SetDisplayID", &LuaUnit::SetDisplayID},                       // :SetDisplayID(id)
    {"SetFacing", &LuaUnit::SetFacing},                             // :SetFacing(o) -- Sets the Unit facing to arg
    {"SetDeathState", &LuaUnit::SetDeathState},                     // :SetDeathState(value) -- 0 = alive 1 = just died 2 = corpse 3 = dead

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

    // Setters
    {"SetScale", &LuaGameObject::SetScale},                         // :SetScale(scale) - UNDOCUMENTED

    // Boolean
    {"IsInWorld", &LuaGameObject::IsInWorld},                       // :IsInWorld() - UNDOCUMENTED
    {"IsTransport", &LuaGameObject::IsTransport},                   // :IsTransport() - UNDOCUMENTED
    {"IsDestructible", &LuaGameObject::IsDestructible},             // :IsDestructible() - UNDOCUMENTED
    {"IsActive", &LuaGameObject::IsActive},                         // :IsActive() - UNDOCUMENTED
    {"HasQuest", &LuaGameObject::HasQuest},                         // :HasQuest(questId) - UNDOCUMENTED
    
    // Other
    {"CastSpellOnTarget", &LuaGameObject::CastSpellOnTarget},       // :CastSpellOnTarget(target, spellId) - Casts the spell on target, no manacost or cast time - UNDOCUMENTED
    {"Move", &LuaGameObject::Move},                                 // :Move(x, y, z, o) - Moves the GO to coordinates - UNDOCUMENTED
    //{"SummonCreature", &LuaGameObject::SummonCreature},           // :SummonCreature(?) - UNDOCUMENTED Tommy or Rochet, check this one please. - UNDOCUMENTED

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
    {"GetUnitType", &LuaGuild::GetUnitType},
    {"GetLeaderGUID", &LuaGuild::GetLeaderGUID},
    // Setters

    // Boolean

    // Other
    {"SendPacket", &LuaGuild::SendPacket},                          // :SendPacket(packet) - sends packet to guild. UNDOCUMENTED
    {"SendPacketToRanked", &LuaGuild::SendPacketToRanked},          // :SendPacketToRanked(packet, rankId) - sends packet to guild, specifying a rankId will only send the packet to your ranked members. UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<QueryResult> QueryMethods[] =  // Not working yet
{
    {"GetUnitType", &LuaQuery::GetUnitType},                        // :GetUnitType() - Returns object type, IE: Player, Creature UNDOCUMENTED

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

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                         // :SetDuration(duration) - Sets remaining duration. UNDOCUMENTED
    {"SetMaxDuration", &LuaAura::SetMaxDuration},                   // :SetMaxDuration(duration) - Sets maximum duration. UNDOCUMENTED
    {"SetStackAmount", &LuaAura::SetStackAmount},                   // :SetStackAmount(amount) - Sets current stack amount. UNDOCUMENTED

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
    {"GetUnitType", &LuaItem::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Item, Creature UNDOCUMENTED
    {"GetGUID", &LuaItem::GetGUID},                                 // :GetGUID() - Returns object guid UNDOCUMENTED

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
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
    {"GetItemCount", &LuaUnit::GetItemCount},                       // :GetItemCount(item_id[, check_bank]) - UNDOCUMENTED
    {"GetGroup", &LuaUnit::GetGroup},                               // :GetGroup()
    {"GetGuild", &LuaUnit::GetGuild},                               // :GetGuild()
    {"GetGearLevel", &LuaUnit::GetGearLevel},                       // :GetGearLevel() -- Returns the player's average gear level
    {"GetAccountId", &LuaUnit::GetAccountId},                       // :GetAccountId()
    {"GetAccountName", &LuaUnit::GetAccountName},                   // :GetAccountName()
    {"GetArenaPoints", &LuaUnit::GetArenaPoints},                   // :GetArenaPoints()
    {"GetHonorPoints", &LuaUnit::GetHonorPoints},                   // :GetHonorPoints()
    {"GetLifetimeKills", &LuaUnit::GetLifetimeKills},               // :GetLifetimeKills() -- Returns the player's lifetime (honorable) kills
    {"GetPlayerIP", &LuaUnit::GetPlayerIP},                         // :GetPlayerIP() -- Returns the player's IP Address
    {"GetLevelPlayedTime", &LuaUnit::GetLevelPlayedTime},           // :GetLevelPlayedTime() -- Returns the player's played time at that level
    {"GetTotalPlayedTime", &LuaUnit::GetTotalPlayedTime},           // :GetTotalPlayedTime() -- Returns the total played time of that player
    {"GetInventoryItem", &LuaUnit::GetInventoryItem},               // :GetInventoryItem(slot) -  Returns item at given inventory slot (0, 1, 2.. for equipment 19-23 for bags, 23-39 for backpack) UNDOCUMENTED
    {"GetBagItem", &LuaUnit::GetBagItem},                           // :GetBagItem(bagSlot, slot) -  Returns item at given slot (0, 1, 2 .. max slots for bag) in a bag (19-23). UNDOCUMENTED
    {"GetObjectGlobally", &LuaUnit::GetObjectGlobally},             // :GetObjectGlobally(guid, entry) - Returns the gameobject of given guid and entry if in world. UNDOCUMENTED
    {"GetNearbyGameObject", &LuaUnit::GetNearbyGameObject},         // :GetNearbyGameObject() - Returns nearby gameobject if found. UNDOCUMENTED
    {"GetReputation", &LuaUnit::GetReputation},                     // :GetReputation(faction) -- Gets player's reputation with given faction. UNDOCUMENTED
    {"GetItemByEntry", &LuaUnit::GetItemByEntry},                   // :GetItemByEntry(entry) -- Gets an item if the player has it. UNDOCUMENTED
    {"GetQuestLevel", &LuaUnit::GetQuestLevel},                     // :GetQuestLevel(quest) -- Returns quest's level. UNDOCUMENTED
    {"GetChatTag", &LuaUnit::GetChatTag},                           // :GetChatTag() -- Returns player chat tag ID. UNDOCUMENTED
    {"GetRestBonus", &LuaUnit::GetRestBonus},                       // :GetRestBonus() -- Gets player's rest bonus. UNDOCUMENTED
    {"GetRestType", &LuaUnit::GetRestType},                         // :GetRestType() -- Returns the player's rest type. UNDOCUMENTED
    {"GetPhaseMaskForSpawn", &LuaUnit::GetPhaseMaskForSpawn},       // :GetPhaseMaskForSpawn() -- Gets the real phasemask for spawning things. Used if the player is in GM mode. UNDOCUMENTED
    {"GetReqKillOrCastCurrentCount", &LuaUnit::RemoveRewardedQuest},    // :GetReqKillOrCastCurrentCount(questId, entry) -- Gets the objective (kill or cast) current count done. UNDOCUMENTED
    {"GetQuestStatus", &LuaUnit::GetQuestStatus},                   // :GetQuestStatus(entry) -- Gets the quest's status. UNDOCUMENTED
    {"GetInGameTime", &LuaUnit::GetInGameTime},                     // :GetInGameTime() -- Returns player's ingame time. UNDOCUMENTED
    {"GetComboPoints", &LuaUnit::GetComboPoints},                   // :GetComboPoints() -- Returns player's combo points. UNDOCUMENTED
    {"GetComboTarget", &LuaUnit::GetComboTarget},                   // :GetComboTarget() -- Returns the player's combo target. UNDOCUMENTED
    {"GetGuildName", &LuaUnit::GetGuildName},                       // :GetGuildName() -- Returns player's guild's name or nil. UNDOCUMENTED
    {"GetFreeTalentPoints", &LuaUnit::GetFreeTalentPoints},         // :GetFreeTalentPoints() -- Returns the amount of unused talent points. UNDOCUMENTED
    {"GetActiveSpec", &LuaUnit::GetActiveSpec},                     // :GetActiveSpec() -- Returns the active specID. UNDOCUMENTED
    {"GetSpecsCount", &LuaUnit::GetSpecsCount},                     // :GetSpecsCount() -- Returns the player's spec count. UNDOCUMENTED
    {"GetSpellCooldownDelay", &LuaUnit::GetSpellCooldownDelay},     // :GetSpellCooldownDelay(spellId) -- Returns the spell's cooldown. UNDOCUMENTED
    {"GetGuildRank", &LuaUnit::GetRank},                            // :GetGuildRank() -- Gets the player's guild rank. UNDOCUMENTED
    {"GetDifficulty", &LuaUnit::GetDifficulty},                     // :GetDifficulty(isRaid) -- Returns the current difficulty. UNDOCUMENTED
    {"GetHealthBonusFromStamina", &LuaUnit::GetHealthBonusFromStamina}, // :GetHealthBonusFromStamina() -- Returns the HP bonus from stamina. UNDOCUMENTED
    {"GetManaBonusFromIntellect", &LuaUnit::GetManaBonusFromIntellect}, // :GetManaBonusFromIntellect() -- Returns the mana bonus from intellect. UNDOCUMENTED
    {"GetMaxSkillValue", &LuaUnit::GetMaxSkillValue},               // :GetMaxSkillValue(skill) -- Gets max skill value for the given skill. UNDOCUMENTED
    {"GetPureMaxSkillValue", &LuaUnit::GetPureMaxSkillValue},       // :GetPureMaxSkillValue(skill) -- Gets max base skill value. UNDOCUMENTED
    {"GetSkillValue", &LuaUnit::GetSkillValue},                     // :GetSkillValue(skill) -- Gets current skill value. UNDOCUMENTED
    {"GetBaseSkillValue", &LuaUnit::GetBaseSkillValue},             // :GetBaseSkillValue(skill) -- Gets current base skill value (no temp bonus). UNDOCUMENTED
    {"GetPureSkillValue", &LuaUnit::GetPureSkillValue},             // :GetPureSkillValue(skill) -- Gets current base skill value (no bonuses). UNDOCUMENTED
    {"GetSkillStep", &LuaUnit::GetSkillStep},                       // :GetSkillStep(skill) -- Returns current skillstep. UNDOCUMENTED
    {"GetSkillPermBonusValue", &LuaUnit::GetSkillPermBonusValue},   // :GetSkillPermBonusValue(skill) -- Returns current permanent bonus. UNDOCUMENTED
    {"GetSkillTempBonusValue", &LuaUnit::GetSkillTempBonusValue},   // :GetSkillTempBonusValue(skill) -- Returns current temp bonus. UNDOCUMENTED
    {"GetReputationRank", &LuaUnit::GetReputationRank},             // :GetReputationRank(faction) -- Returns the reputation rank with given faction. UNDOCUMENTED
    {"GetSpellCooldowns", &LuaUnit::GetSpellCooldowns},             // :GetSpellCooldowns() -- Gets a table where spellIDs are the keys and values are cooldowns. UNDOCUMENTED
    {"GetDrunkValue", &LuaUnit::GetDrunkValue},                     // :GetDrunkValue() -- Returns the current drunkness value. UNDOCUMENTED
    {"GetBattlegroundId", &LuaUnit::GetBattlegroundId},             // :GetBattlegroundId() -- Returns the player's current battleground ID. UNDOCUMENTED
    {"GetBattlegroundTypeId", &LuaUnit::GetBattlegroundTypeId},     // :GetBattlegroundTypeId() -- Returns the player's current battleground type ID. UNDOCUMENTED
    {"GetXPRestBonus", &LuaUnit::GetXPRestBonus},                   // :GetXPRestBonus(xp) -- Returns the rested bonus XP from given XP. UNDOCUMENTED
    {"GetRestTime", &LuaUnit::GetRestTime},                         // :GetRestTime() -- Returns the timed rested. UNDOCUMENTED
    {"GetGroupInvite", &LuaUnit::GetGroupInvite},                   // :GetGroupInvite() -- Returns the group invited to. UNDOCUMENTED
    {"GetSubGroup", &LuaUnit::GetSubGroup},                         // :GetSubGroup() -- Gets the player's current subgroup ID. UNDOCUMENTED
    {"GetNextRandomRaidMember", &LuaUnit::GetNextRandomRaidMember}, // :GetNextRandomRaidMember(radius) -- Gets a random raid member in given radius. UNDOCUMENTED
    {"GetOriginalGroup", &LuaUnit::GetOriginalGroup},               // :GetOriginalGroup() -- Gets the original group object. UNDOCUMENTED
    {"GetOriginalSubGroup", &LuaUnit::GetOriginalSubGroup},         // :GetOriginalSubGroup() -- Returns the original subgroup ID. UNDOCUMENTED
    {"GetChampioningFaction", &LuaUnit::GetChampioningFaction},     // :GetChampioningFaction() -- Returns the player's championing faction. UNDOCUMENTED
    {"GetLatency", &LuaUnit::GetLatency},                           // :GetLatency() -- Returns player's latency. UNDOCUMENTED
    {"GetRecruiterId", &LuaUnit::GetRecruiterId},                   // :GetRecruiterId() -- Returns player's recruiter's ID. UNDOCUMENTED

    // Setters
    {"AdvanceSkillsToMax", &LuaUnit::AdvanceSkillsToMax},           // :AdvanceSkillsToMax() -- Advances all currently known skills to the currently known max level
    {"AdvanceSkill", &LuaUnit::AdvanceSkill},                       // :AdvanceSkill(skill_id, step) -- Advances skill by ID and the amount(step)
    {"AdvanceAllSkills", &LuaUnit::AdvanceAllSkills},               // :AdvanceAllSkills(value) -- Advances all current skills to your input(value)
    {"AddLifetimeKills", &LuaUnit::AddLifetimeKills},               // :AddLifetimeKills(val) -- Adds lifetime (honorable) kills to your current lifetime kills
    {"SetCoinage", &LuaUnit::SetCoinage},                           // :SetCoinage(amount) - sets plr's coinage to this.
    {"SetKnownTitle", &LuaUnit::SetKnownTitle},                     // :SetKnownTitle(id)
    {"UnsetKnownTitle", &LuaUnit::UnsetKnownTitle},                 // :UnsetKnownTitle(id)
    {"SetBindPoint", &LuaUnit::SetBindPoint},                       // :SetBindPoint(x, y, z, map, areaid) -- sets home for hearthstone
    {"SetBindPointAtPlayerLoc", &LuaUnit::SetBindPointAtPlayerLoc}, // :SetBindPointAtPlayerLoc() -- Set's home for hearthstone at player's location
    {"SetArenaPoints", &LuaUnit::SetArenaPoints},                   // :SetArenaPoints(amount)
    {"SetHonorPoints", &LuaUnit::SetHonorPoints},                   // :SetHonorPoints(amount)
    {"SetLifetimeKills", &LuaUnit::SetLifetimeKills},               // :SetLifetimeKills(val) -- Sets the overall lifetime (honorable) kills of the player
    {"SetGameMaster", &LuaUnit::SetGameMaster},                     // :SetGameMaster(on) -- Sets GM mode on or off. UNDOCUMENTED
    {"SetGMChat", &LuaUnit::SetGMChat},                             // :SetGMChat(on) -- Sets GM chat on or off. UNDOCUMENTED
    {"SetTaxiCheater", &LuaUnit::SetTaxiCheater},                   // :SetTaxiCheater(on) -- Sets taxi cheat on or off. UNDOCUMENTED
    {"SetGMVisible", &LuaUnit::SetGMVisible},                       // :SetGMVisible(on) -- Sets gm visibility on or off. UNDOCUMENTED
    {"SetPvPDeath", &LuaUnit::SetPvPDeath},                         // :SetPvPDeath(on) -- Sets PvP death on or off. UNDOCUMENTED
    {"SetAcceptWhispers", &LuaUnit::SetAcceptWhispers},             // :SetAcceptWhispers(on) -- Sets whisper accepting death on or off. UNDOCUMENTED
    {"SetRestBonus", &LuaUnit::SetRestBonus},                       // :SetRestBonus(bonusrate) -- Sets new restbonus rate. UNDOCUMENTED
    {"SetRestType", &LuaUnit::SetRestType},                         // :SetRestType() -- Sets rest type. UNDOCUMENTED
    {"SetSheath", &LuaUnit::SetSheath},                             // :SetSheath(SheathState) -- Sets player's seathstate. UNDOCUMENTED
    {"SetQuestStatus", &LuaUnit::SetQuestStatus},                   // :SetQuestStatus(entry, status) -- Sets the quest's status. UNDOCUMENTED
    {"SetReputation", &LuaUnit::SetReputation},                     // :SetReputation(faction, value) -- Sets the faction reputation for the player. UNDOCUMENTED
    {"SetFreeTalentPoints", &LuaUnit::SetFreeTalentPoints},         // :SetFreeTalentPoints(points) -- Sets the amount of unused talent points. UNDOCUMENTED
    {"SetPvP", &LuaUnit::SetPvP},                                   // :SetPvP([apply]) -- Sets the player's PvP on or off. UNDOCUMENTED
    {"SetGuildRank", &LuaUnit::SetRank},                            // :SetGuildRank(rank) -- Sets player's guild rank. UNDOCUMENTED
    {"SetMovement", &LuaUnit::SetMovement},                         // :SetMovement(type) -- Sets player's movement type. UNDOCUMENTED
    {"SetSkill", &LuaUnit::SetSkill},                               // :SetSkill(skill, step, currVal, maxVal) -- Sets the skill's boundaries and value. UNDOCUMENTED
    {"SetFactionForRace", &LuaUnit::setFactionForRace},             // :SetFactionForRace(race) -- Sets the faction by raceID. UNDOCUMENTED
    {"SetDrunkValue", &LuaUnit::SetDrunkValue},                     // :SetDrunkValue(newDrunkValue) -- Sets drunkness value. UNDOCUMENTED
    {"SetRestTime", &LuaUnit::SetRestTime},                         // :SetRestTime(value) -- Sets the rested time. UNDOCUMENTED
    {"SetAtLoginFlag", &LuaUnit::SetAtLoginFlag},                   // :SetAtLoginFlag(flag) -- Adds an at login flag. UNDOCUMENTED

    // Boolean
    {"IsInGroup", &LuaUnit::IsInGroup},                             // :IsInGroup()
    {"IsInGuild", &LuaUnit::IsInGuild},                             // :IsInGuild()
    {"IsGM", &LuaUnit::IsGM},                                       // :IsGM()
    {"IsAlliance", &LuaUnit::IsAlliance},                           // :IsAlliance()
    {"IsHorde", &LuaUnit::IsHorde},                                 // :IsHorde()
    {"HasTitle", &LuaUnit::HasTitle},                               // :HasTitle(id)
    {"HasItem", &LuaUnit::HasItem},                                 // :HasItem(itemId[, count, check_bank]) -- Returns true if the player has the item(itemId) and specified count, else it will return false. 
    {"Teleport", &LuaUnit::Teleport},                               // :Teleport(Map, X, Y, Z, O) - Teleports player to specified co-ordinates. Returns true if success and false if not.
    {"AddItem", &LuaUnit::AddItem},                                 // :AddItem(id, amount) - Adds amount of item to player. Returns true if success and false if not.
    {"IsInArenaTeam", &LuaUnit::IsInArenaTeam},                     // :IsInArenaTeam(type) -  type : 0 = 2v2, 1 = 3v3, 2 = 5v5
    {"CanEquipItem", &LuaUnit::CanEquipItem},                       // :CanEquipItem(entry/item, slot) - Returns true if the player can equip given item/item entry. UNDOCUMENTED
    {"IsFalling", &LuaUnit::IsFalling},                             // :IsFalling() -- Returns true if the unit is falling. UNDOCUMENTED
    {"ToggleAFK", &LuaUnit::ToggleAFK},                             // :ToggleAFK() -- Toggles AFK state for player. UNDOCUMENTED
    {"ToggleDND", &LuaUnit::ToggleDND},                             // :ToggleDND() -- Toggles DND state for player. UNDOCUMENTED
    {"IsAFK", &LuaUnit::isAFK},                                     // :IsAFK() -- Returns true if the player is afk. UNDOCUMENTED
    {"IsDND", &LuaUnit::isDND},                                     // :IsDND() -- Returns true if the player is in dnd mode. UNDOCUMENTED
    {"IsAcceptingWhispers", &LuaUnit::isAcceptingWhispers},               // :IsAcceptWhispers() -- Returns true if the player accepts whispers. UNDOCUMENTED
    {"IsGMChat", &LuaUnit::isGMChat},                               // :IsGMChat() -- Returns true if the player has GM chat on. UNDOCUMENTED
    {"IsTaxiCheater", &LuaUnit::isTaxiCheater},                     // :IsTaxiCheater() -- Returns true if the player has taxi cheat on. UNDOCUMENTED
    {"IsGMVisible", &LuaUnit::isGMVisible},                         // :IsGMVisible() -- Returns true if the player is GM visible. UNDOCUMENTED
    {"IsActiveQuest", &LuaUnit::IsActiveQuest},                     // :IsActiveQuest(entry) -- Returns true if the quest entry is active for the player. UNDOCUMENTED
    {"CanFly", &LuaUnit::CanFly},                                   // :CanFly() -- Returns true if the player can fly. UNDOCUMENTED
    {"InBattlegroundQueue", &LuaUnit::InBattlegroundQueue},         // :InBattlegroundQueue() -- Returns true if the player is in a battleground queue. UNDOCUMENTED
    {"IsImmuneToEnvironmentalDamage", &LuaUnit::IsImmuneToEnvironmentalDamage}, // :IsImmuneToEnvironmentalDamage() -- Returns true if the player is immune to enviromental damage. UNDOCUMENTED
    {"CanSpeak", &LuaUnit::CanSpeak},                               // :CanSpeak() -- Returns true if the player can speak. UNDOCUMENTED
    {"HasAtLoginFlag", &LuaUnit::HasAtLoginFlag},                   // :HasAtLoginFlag(flag) -- returns true if the player has the login flag. UNDOCUMENTED
    {"InRandomLfgDungeon", &LuaUnit::inRandomLfgDungeon},           // :InRandomLfgDungeon() -- Returns true if the player is in a random LFG dungeon. UNDOCUMENTED
    {"HasPendingBind", &LuaUnit::HasPendingBind},                   // :HasPendingBind() -- Returns true if the player has a pending instance bind. UNDOCUMENTED
    {"HasAchieved", &LuaUnit::HasAchieved},                         // :HasAchieved(achievementID) -- Returns true if the player has achieved the achievement. UNDOCUMENTED
    {"CanUninviteFromGroup", &LuaUnit::CanUninviteFromGroup},       // :CanUninviteFromGroup() -- Returns true if the player can uninvite from group. UNDOCUMENTED
    {"IsRested", &LuaUnit::isRested},                               // :IsRested() -- Returns true if the player is rested. UNDOCUMENTED
    {"IsKnowHowFlyIn", &LuaUnit::IsKnowHowFlyIn},                   // :IsKnowHowFlyIn(mapid, zone) -- Returns true if the player can fly in the area. UNDOCUMENTED
    {"IsNeverVisible", &LuaUnit::IsNeverVisible},                   // :IsNeverVisible() -- Returns true if the player is never visible. UNDOCUMENTED
    {"IsVisibleGloballyFor", &LuaUnit::IsVisibleGloballyFor},       // :IsVisibleGloballyFor(player) -- Returns true if the player is visible for the target player. UNDOCUMENTED
    {"IsUsingLfg", &LuaUnit::isUsingLfg},                           // :IsUsingLfg() -- Returns true if the player is using LFG. UNDOCUMENTED
    {"HasQuestForItem", &LuaUnit::HasQuestForItem},                 // :HasQuestForItem(entry) -- Returns true if the player has the quest for the item. UNDOCUMENTED
    {"HasQuestForGO", &LuaUnit::HasQuestForGO},                     // :HasQuestForGO(entry) -- Returns true if the player has the quest for the gameobject. UNDOCUMENTED
    {"CanShareQuest", &LuaUnit::CanShareQuest},                     // :CanShareQuest(entry) -- Returns true if the quest entry is shareable by the player. UNDOCUMENTED
    {"IsQuestRewarded", &LuaUnit::IsQuestRewarded},                 // :IsQuestRewarded(entry) -- Returns true if the player has recieved the quest's reward. UNDOCUMENTED
    {"HasTalent", &LuaUnit::HasTalent},                             // :HasTalent(spellid, spec) -- Returns true if the player has the talent spell in given spec. UNDOCUMENTED
    {"HasSpellCooldown", &LuaUnit::HasSpellCooldown},               // :HasSpellCooldown(spellId) -- Returns true if the spell is on cooldown. UNDOCUMENTED
    {"IsInSameGroupWith", &LuaUnit::IsInSameGroupWith},             // :IsInSameGroupWith(player) -- Returns true if the players are in the same group. UNDOCUMENTED
    {"IsInSameRaidWith", &LuaUnit::IsInSameRaidWith},               // :IsInSameRaidWith(player) -- Returns true if the players are in the same raid. UNDOCUMENTED
    {"IsGroupVisibleFor", &LuaUnit::IsGroupVisibleFor},             // :IsGroupVisibleFor(player) -- Player is group visible for the target. UNDOCUMENTED
    {"HasSkill", &LuaUnit::HasSkill},                               // :HasSkill(skill) -- Returns true if the player has the skill. UNDOCUMENTED
    {"IsHonorOrXPTarget", &LuaUnit::isHonorOrXPTarget},             // :IsHonorOrXPTarget(victim) -- Returns true if the victim gives honor or XP. UNDOCUMENTED
    {"CanParry", &LuaUnit::CanParry},                               // :CanParry() -- Returns true if the player can parry. UNDOCUMENTED
    {"CanBlock", &LuaUnit::CanBlock},                               // :CanBlock() -- Returns true if the player can block. UNDOCUMENTED
    {"CanTitanGrip", &LuaUnit::CanTitanGrip},                       // :CanTitanGrip() -- Returns true if the player has titan grip. UNDOCUMENTED
    {"CanTameExoticPets", &LuaUnit::CanTameExoticPets},             // :CanTameExoticPets() -- Returns true if the player can tame exotic pets. UNDOCUMENTED
    {"InBattleground", &LuaUnit::InBattleground},                   // :InBattleground() -- Returns true if the player is in a battleground. UNDOCUMENTED
    {"InArena", &LuaUnit::InArena},                                 // :InArena() -- Returns true if the player is in an arena. UNDOCUMENTED
    {"IsOutdoorPvPActive", &LuaUnit::IsOutdoorPvPActive},           // :IsOutdoorPvPActive() -- Returns true if the player is outdoor pvp active. UNDOCUMENTED
    {"IsARecruiter", &LuaUnit::IsARecruiter},                       // :IsARecruiter() -- Returns true if the player is a recruiter. UNDOCUMENTED

    // Gossip                                                           
    {"GossipMenuAddItem", &LuaUnit::GossipMenuAddItem},             // :GossipMenuAddItem(icon, msg, sender, intid, code, popup, money)
    {"GossipSendMenu", &LuaUnit::GossipSendMenu},                   // :GossipSendMenu(npc_text, unit[, menu_id]) -- If unit is a player, you need to use a menu_id. menu_id is used to hook the gossip select function to the menu.
    {"GossipComplete", &LuaUnit::GossipComplete},                   // :GossipComplete()
    {"GossipClearMenu", &LuaUnit::GossipClearMenu},                 // :GossipClearMenu() -- Clears the gossip menu of options. Pretty much only useful with player gossip. Need to use before creating a new menu for the player

    // Other
    {"SendBroadcastMessage", &LuaUnit::SendBroadcastMessage},       // :SendBroadcastMessage(message)
    {"SendAreaTriggerMessage", &LuaUnit::SendAreaTriggerMessage},   // :SendAreaTriggerMessage(message) -- Sends a yellow message in the middle of your screen
    {"SendNotification", &LuaUnit::SendNotification},               // :SendNotification(message) -- Sends a red message in the middle of your screen
    {"SendPacketToPlayer", &LuaUnit::SendPacketToPlayer},           // :SendPacketToPlayer(packet) - Sends a specified packet to the player
    {"SendPacket", &LuaUnit::SendPacket},                           // :SendPacket(packet) -- Sends a specified packet
    {"SendPacketToGroup", &LuaUnit::SendPacketToGroup},             // :SendPacketToGroup(packet, sendToPlayersInBattleground(bool)) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground
    {"SendPacketToGuild", &LuaUnit::SendPacketToGuild},             // :SendPacketToGuild(packet) - Sends a specified packet to your guild
    {"SendPacketToRankedInGuild", &LuaUnit::SendPacketToRankedInGuild}, // :SendPacketToRankedInGuild(packet, rankId) - Sends a specified packet to your guild, specifying a rankId will only send the packet to your ranked members.
    {"SendVendorWindow", &LuaUnit::SendVendorWindow},               // :SendVendorWindow(unit) -- Sends the unit's vendor window to the player
    {"GiveCoinage", &LuaUnit::GiveCoinage},                         // :GiveCoinage(amount) - MODIFIES (does not set) coinage count.
    {"RemoveCoinage", &LuaUnit::RemoveCoinage},                     // :RemoveCoinage(amount) - Removes amount of coinage from plr.
    {"LearnSpell", &LuaUnit::LearnSpell},                           // :LearnSpell(id) - learns the given spell.
    {"RemoveItem", &LuaUnit::RemoveItem},                           // :RemoveItem(id, amount) - Removes amount of item to player.
    {"RemoveLifetimeKills", &LuaUnit::RemoveLifetimeKills},         // :RemoveLifetimeKills(val) - Removes a specified amount(val) of the player's lifetime (honorable) kills
    {"ResurrectPlayer", &LuaUnit::ResurrectPlayer},                 // :ResurrectPlayer([percent[, sickness(bool)]]) - Resurrects the player at percentage, player gets resurrection sickness if sickness set to true.
    {"PlaySoundToPlayer", &LuaUnit::PlaySoundToPlayer},             // :PlaySoundToPlayer(soundId) - Plays the specified sound to the player
    {"EquipItem", &LuaUnit::EquipItem},                             // :EquipItem(entry/item, slot) -  Equips given item or item entry for player to given slot. Returns the equipped item or nil. UNDOCUMENTED
    {"ResetSpellCooldown", &LuaUnit::ResetSpellCooldown},           // :ResetSpellCooldown(spellId, update(bool~optional)) -- Resets cooldown of the specified spellId. If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default.
    {"ResetTypeCooldowns", &LuaUnit::ResetTypeCooldowns},           // :ResetTypeCooldowns(category, update(bool~optional)) -- Resets all cooldowns for the spell category(type). If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default.
    {"ResetAllCooldowns", &LuaUnit::ResetAllCooldowns},             // :ResetAllCooldowns() -- Resets all spell cooldowns.
    {"GiveLevel", &LuaUnit::GiveLevel},                             // :GiveLevel(level) -- Gives levels to the player. UNDOCUMENTED
    {"GiveXP", &LuaUnit::GiveXP},                                   // :GiveXP(xp[, victim, group_rate]) -- Gives XP to the player. UNDOCUMENTED
    {"RemovePet", &LuaUnit::RemovePet},                             // :RemovePet([mode, returnreagent]) -- Removes the player's pet. Mode determines if the pet is saved and how. UNDOCUMENTED
    {"SummonPet", &LuaUnit::SummonPet},                             // :SummonPet(entry, x, y, z, o, petType, despwtime) -- Summons a pet for the player. UNDOCUMENTED
    {"Say", &LuaUnit::Say},                                         // :Say(text, lang) -- The player says the text. UNDOCUMENTED
    {"Yell", &LuaUnit::Yell},                                       // :Yell(text, lang) -- The player yells the text. UNDOCUMENTED
    {"TextEmote", &LuaUnit::TextEmote},                             // :TextEmote(text) -- The player does a textemote with the text. UNDOCUMENTED
    {"Whisper", &LuaUnit::Whisper},                                 // :Whisper(text, lang, receiverGuid) -- The player whispers the text to the playerguid. UNDOCUMENTED
    {"CompleteQuest", &LuaUnit::CompleteQuest},                     // :CompleteQuest(entry) -- Completes a quest by entry. UNDOCUMENTED
    {"IncompleteQuest", &LuaUnit::IncompleteQuest},                 // :IncompleteQuest(entry) -- Uncompletes the quest by entry for the player. UNDOCUMENTED
    {"FailQuest", &LuaUnit::FailQuest},                             // :FailQuest(entry) -- Player fails the quest entry. UNDOCUMENTED
    {"RemoveActiveQuest", &LuaUnit::RemoveActiveQuest},             // :RemoveActiveQuest(entry) -- Removes an active quest. UNDOCUMENTED
    {"RemoveRewardedQuest", &LuaUnit::RemoveRewardedQuest},         // :RemoveRewardedQuest(entry) -- Removes a rewarded quest. UNDOCUMENTED
    {"AreaExploredOrEventHappens", &LuaUnit::AreaExploredOrEventHappens},   // :AreaExploredOrEventHappens(questId) -- Satisfies an area or event requrement for the questId. UNDOCUMENTED
    {"GroupEventHappens", &LuaUnit::GroupEventHappens},             // :GroupEventHappens(questId, worldObject) -- Satisfies a group event for the questId with the world object. UNDOCUMENTED
    {"KilledMonsterCredit", &LuaUnit::KilledMonsterCredit},         // :KilledMonsterCredit(entry) -- Satisfies a monsterkill for the player. UNDOCUMENTED
    {"KilledPlayerCredit", &LuaUnit::KilledPlayerCredit},           // :KilledPlayerCredit() -- Satisfies a player kill for the player. UNDOCUMENTED
    {"CastedCreatureOrGO", &LuaUnit::CastedCreatureOrGO},           // :CastedCreatureOrGO(creatureOrGOEntry, creatureOrGO, spellId) -- Satisfies a spellcast on unit for the player. UNDOCUMENTED
    {"TalkedToCreature", &LuaUnit::TalkedToCreature},               // :TalkedToCreature(npcEntry, creature) -- Satisfies creature talk objective for the player. UNDOCUMENTED
    {"SaveToDB", &LuaUnit::SaveToDB},                               // :SaveToDB() -- Saves the player to database. UNDOCUMENTED
    {"ResetPetTalents", &LuaUnit::ResetPetTalents},                 // :ResetPetTalents() -- Resets player's pet's talents. UNDOCUMENTED
    {"RegenerateAll", &LuaUnit::RegenerateAll},                     // :RegenerateAll() -- Regenerates all player's powers. UNDOCUMENTED
    {"Regenerate", &LuaUnit::Regenerate},                           // :Regenerate(powerType) -- Regenerates the given power type. UNDOCUMENTED
    {"RegenerateHealth", &LuaUnit::RegenerateHealth},               // :RegenerateHealth() -- Regenerates health. UNDOCUMENTED
    {"AddComboPoints", &LuaUnit::AddComboPoints},                   // :AddComboPoints(target, count[, spell]) -- Adds combo points to the target for the player. UNDOCUMENTED
    {"GainSpellComboPoints", &LuaUnit::GainSpellComboPoints},       // :GainSpellComboPoints(amount) -- Player gains spell combo points. UNDOCUMENTED
    {"ClearComboPoints", &LuaUnit::ClearComboPoints},               // :ClearComboPoints() -- Clears player's combo points. UNDOCUMENTED
    {"RemoveSpell", &LuaUnit::removeSpell},                         // :RemoveSpell(entry[, disabled, learn_low_rank]) -- Removes (unlearn) the given spell. UNDOCUMENTED
    {"ResetTalents", &LuaUnit::resetTalents},                       // :ResetTalents([no_cost]) -- Resets player's talents. UNDOCUMENTED
    {"ResetTalentsCost", &LuaUnit::resetTalentsCost},               // :ResetTalentsCost() -- Returns the reset talents cost. UNDOCUMENTED
    {"AddTalent", &LuaUnit::AddTalent},                             // :AddTalent(spellid, spec, learning) -- Adds a talent spell for the player to given spec. UNDOCUMENTED
    {"RemoveFromGroup", &LuaUnit::RemoveFromGroup},                 // :RemoveFromGroup() -- Removes the player from his group. UNDOCUMENTED
    {"KillPlayer", &LuaUnit::KillPlayer},                           // :KillPlayer() -- Kills the player. UNDOCUMENTED
    {"DurabilityLossAll", &LuaUnit::DurabilityLossAll},             // :DurabilityLossAll(percent[, inventory]) -- The player's items lose durability. Inventory true by default. UNDOCUMENTED
    {"DurabilityLoss", &LuaUnit::DurabilityLoss},                   // :DurabilityLoss(item, percent) -- The given item loses durability. UNDOCUMENTED
    {"DurabilityPointsLoss", &LuaUnit::DurabilityPointsLoss},       // :DurabilityPointsLoss(item, points) -- The given item loses durability. UNDOCUMENTED
    {"DurabilityPointsLossAll", &LuaUnit::DurabilityPointsLossAll}, // :DurabilityPointsLossAll(points, inventory) -- Player's items lose durability. UNDOCUMENTED
    {"DurabilityPointLossForEquipSlot", &LuaUnit::DurabilityPointLossForEquipSlot}, // :DurabilityPointLossForEquipSlot(slot) -- Causes durability loss for the item in the given slot. UNDOCUMENTED
    {"DurabilityRepairAll", &LuaUnit::DurabilityRepairAll},         // :DurabilityRepairAll(has_cost, discount, guildBank) -- Repairs all durability. UNDOCUMENTED
    {"DurabilityRepair", &LuaUnit::DurabilityRepair},               // :DurabilityRepair(position, has_cost, discount, guildBank) -- Repairs item durability of item in given position. UNDOCUMENTED
    {"ModifyHonorPoints", &LuaUnit::ModifyHonorPoints},             // :ModifyHonorPoints(amount) -- Modifies the player's honor points. UNDOCUMENTED
    {"ModifyArenaPoints", &LuaUnit::ModifyArenaPoints},             // :ModifyArenaPoints(amount) -- Modifies the player's arena points. UNDOCUMENTED
    {"LeaveBattleground", &LuaUnit::LeaveBattleground},             // :LeaveBattleground([teleToEntryPoint]) -- The player leaves the battleground. UNDOCUMENTED
    {"BindToInstance", &LuaUnit::BindToInstance},                   // :BindToInstance() -- Binds the player to the current instance. UNDOCUMENTED
    {"UnbindInstance", &LuaUnit::UnbindInstance},                   // :UnbindInstance(map, difficulty) -- Unbinds the player from an instance. UNDOCUMENTED
    {"RemoveFromBattlegroundOrBattlefieldRaid", &LuaUnit::RemoveFromBattlegroundOrBattlefieldRaid}, // :RemoveFromBattlegroundOrBattlefieldRaid() -- Removes the player from a battleground or battlefield raid. UNDOCUMENTED
    {"ResetAchievements", &LuaUnit::ResetAchievements},             // :ResetAchievements() -- Resets playeräs achievements. UNDOCUMENTED
    {"KickPlayer", &LuaUnit::KickPlayer},                           // :KickPlayer() -- Kicks player from server. UNDOCUMENTED
    {"LogoutPlayer", &LuaUnit::LogoutPlayer},                       // :LogoutPlayer(save) -- Logs the player out and saves if true. UNDOCUMENTED
    {"SendTrainerList", &LuaUnit::SendTrainerList},                 // :SendTrainerList(WorldObject) -- Sends trainer list from object to player. UNDOCUMENTED
    {"SendListInventory", &LuaUnit::SendListInventory},             // :SendListInventory(WorldObject) -- Sends vendor list from object to player. UNDOCUMENTED
    {"SendShowBank", &LuaUnit::SendShowBank},                       // :SendShowBank(WorldObject) -- Sends bank window from object to player. UNDOCUMENTED
    {"SendTabardVendorActivate", &LuaUnit::SendTabardVendorActivate},   // :SendTabardVendorActivate(WorldObject) -- Sends tabard vendor window from object to player. UNDOCUMENTED
    {"SendSpiritResurrect", &LuaUnit::SendSpiritResurrect},         // :SendSpiritResurrect() -- Sends resurrect window to player. UNDOCUMENTED
    {"SendTaxiMenu", &LuaUnit::SendTaxiMenu},                       // :SendTaxiMenu(creature) -- Sends flight window to player from creature. UNDOCUMENTED

    // Creature methods

    // Getters
    {"GetAITarget", &LuaUnit::GetAITarget},                         // :GetAITarget(type[, playeronly, position, distance, aura]) - Get an unit in threat list
    {"GetAITargets", &LuaUnit::GetAITargets},                       // :GetAITargets() - Get units in threat list
    {"GetAITargetsCount", &LuaUnit::GetAITargetsCount},             // :GetAITargetsCount() - Get threat list size
    {"GetVictim", &LuaUnit::GetVictim},                             // :GetVictim() - Returns creature's current target. UNDOCUMENTED
    {"GetNearestTargetInAttackDistance", &LuaUnit::GetNearestTargetInAttackDistance}, // :GetNearestTargetInAttackDistance([radius]) - Returns nearest target in attack distance and within given radius, if set. UNDOCUMENTED
    {"GetNearestTarget", &LuaUnit::GetNearestTarget},               // :GetNearestTarget([radius]) - Returns nearest target in sight or given radius. UNDOCUMENTED
    {"GetNearestPlayer", &LuaUnit::GetNearestPlayer},               // :GetNearestPlayer([radius]) - Returns nearest player in sight or given radius. UNDOCUMENTED
    {"GetNearestHostileTargetInAggroRange", &LuaUnit::GetNearestHostileUnitInAggroRange}, // :GetNearestHostileTargetInAggroRange([checkLOS]) - Returns closest hostile target in aggro range of the creature. UNDOCUMENTED

    // Booleans
    {"IsWorldBoss", &LuaUnit::IsWorldBoss},                         // :IsWorldBoss() -- Returns true if the creature is a WorldBoss, false if not.
    {"IsDungeonBoss", &LuaUnit::IsDungeonBoss},                     // :IsDungeonBoss() -- Returns true if the creature is a DungeonBoss, false if not.

    // Other
    {"RegisterEvent", &LuaUnit::RegisterEvent},                     // :RegisterEvent(function, delay, calls)
    {"RemoveEventByID", &LuaUnit::RemoveEventByID},                 // :RemoveEventByID(eventID)
    {"RemoveEvents", &LuaUnit::RemoveEvents},                       // :RemoveEvents()
    {"Despawn", &LuaUnit::Despawn},                                 // :Despawn([despawnDelay]) - Creature despawns after given time UNDOCUMENTED

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
    {"GetInt32Value", &LuaUnit::GetInt32Value},                     // :GetInt32Value(index) - returns an int value from unit fields
    {"GetUInt32Value", &LuaUnit::GetUInt32Value},                   // :GetUInt32Value(index) - returns an uint value from unit fields
    {"GetFloatValue", &LuaUnit::GetFloatValue},                     // :GetFloatValue(index) - returns a float value from unit fields
    {"GetByteValue", &LuaUnit::GetByteValue},                       // :GetByteValue(index, offset) - returns a byte value from unit fields
    {"GetUInt16Value", &LuaUnit::GetUInt16Value},                   // :GetUInt16Value(index, offset) - returns a uint16 value from unit fields
    {"GetInstanceId", &LuaUnit::GetInstanceId},                     // :GetInstanceId() - Gets the instance id of the unit
    {"GetPhaseMask", &LuaUnit::GetPhaseMask},                       // :GetPhaseMask() - gets the phase mask of the unit
    {"GetCombatTime", &LuaUnit::GetCombatTime},                     // :GetCombatTime() - Returns how long the unit has been in combat
    {"GetFaction", &LuaUnit::GetFaction},                           // :GetFaction() -- Returns the unit's factionId
    {"GetCurrentSpell", &LuaUnit::GetCurrentSpell},                 // :GetCurrentSpell(type) -- Returns the currently casted spell of given type if any UNDOCUMENTED
    {"GetCreatureType", &LuaUnit::GetCreatureType},                 // :GetCreatureType() -- Returns the unit's type
    {"GetNearbyTarget", &LuaUnit::GetNearbyTarget},                 // :GetNearbyTarget([radius[, exclude]]) - Returns nearby target within sight or given radius. Excludes current target and given unit. UNDOCUMENTED

    // Setters
    {"SetFaction", &LuaUnit::SetFaction},                           // :SetFaction(factionId) -- Sets the unit's faction
    {"SetLevel", &LuaUnit::SetLevel},                               // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                             // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                       // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                               // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                         // :SetMaxPower(index, amount)
    {"SetDisplayID", &LuaUnit::SetDisplayID},                       // :SetDisplayID(id)
    {"SetFacing", &LuaUnit::SetFacing},                             // :SetFacing(o) -- Sets the Unit facing to arg
    {"SetDeathState", &LuaUnit::SetDeathState},                     // :SetDeathState(value) -- 0 = alive 1 = just died 2 = corpse 3 = dead
    {"SetInt32Value", &LuaUnit::SetInt32Value},                     // :SetInt32Value(index, value) - Sets an int value for the unit
    {"SetUInt32Value", &LuaUnit::SetUInt32Value},                   // :SetUInt32Value(index, value) - Sets an uint value for the unit
    {"UpdateUInt32Value", &LuaUnit::UpdateUInt32Value},             // :UpdateUInt32Value(index, value) - Updates an uint value for the unit
    {"SetFloatValue", &LuaUnit::SetFloatValue},                     // :SetFloatValue(index, value) - Sets a float value for the unit
    {"SetByteValue", &LuaUnit::SetByteValue},                       // :SetByteValue(index, offset, value) - Sets a byte value for the unit
    {"SetUInt16Value", &LuaUnit::SetUInt16Value},                   // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the unit
    {"SetInt16Value", &LuaUnit::SetInt16Value},                     // :SetInt16Value(index, offset, value) - Sets an int16 value for the unit
    {"SetPhaseMask", &LuaUnit::SetPhaseMask},                       // :SetPhaseMask(Phase[, update]) - Sets the phase of the unit
    {"SetWalk", &LuaUnit::SetWalk},                                 // :SetWalk(enable) - If false, creature runs, otherwise walks
    {"SetSpeed", &LuaUnit::SetSpeed},                               // :SetSpeed(type, speed[, forced]) - Sets speed for the movement type (0 = walk, 1 = run ..)
    {"SetStunned", &LuaUnit::SetStunned},                           // :SetStunned(enable) - Stuns or removes stun
    {"SetRooted", &LuaUnit::SetRooted},                             // :SetRooted(enable) - Roots or removes root
    {"SetConfused", &LuaUnit::SetConfused},                         // :SetConfused(enable) - Sets confused or removes confusion
    {"SetFeared", &LuaUnit::SetFeared},                             // :SetFeared(enable) - Fears or removes fear

    // Boolean
    {"IsAlive", &LuaUnit::IsAlive},                                 // :IsAlive()
    {"IsDead", &LuaUnit::IsDead},                                   // :IsDead() -- Returns true if the unit is dead, false if they are alive
    {"IsInWorld", &LuaUnit::IsInWorld},                             // :IsInWorld()
    {"IsPvPFlagged", &LuaUnit::IsPvPFlagged},                       // :IsPvPFlagged()
    {"HasQuest", &LuaUnit::HasQuest},                               // :HasQuest(id)
    {"IsInCombat", &LuaUnit::IsInCombat},                           // :IsInCombat()
    {"HasSpell", &LuaUnit::HasSpell},                               // :HasSpell(id)
    {"IsBanker", &LuaUnit::IsBanker},                               // :IsBanker() -- Returns true if the unit is a banker, false if not.
    {"IsBattleMaster", &LuaUnit::IsBattleMaster},                   // :IsBattleMaster() -- Returns true if the unit is a battle master, false if not.
    {"IsCharmed", &LuaUnit::IsCharmed},                             // :IsCharmed() -- Returns true if the unit is charmed, false if not.
    {"IsArmorer", &LuaUnit::IsArmorer},                             // :IsArmorer() -- Returns true if the unit is an Armorer, false if not.
    {"IsAttackingPlayer", &LuaUnit::IsAttackingPlayer},             // :IsAttackingPlayer() -- Returns true if the unit is attacking a player, false if not.
    {"IsInWater", &LuaUnit::IsInWater},                             // :IsInWater() -- Returns true if the unit is in water. UNDOCUMENTED
    {"IsUnderWater", &LuaUnit::IsUnderWater},                       // :IsUnderWater() -- Returns true if the unit is under water. UNDOCUMENTED
    {"HasAura", &LuaUnit::HasAura},                                 // :HasAura(spellId[, caster]) -- Returns true if the unit has the aura from the spell and casted by the caster if provided. UNDOCUMENTED

    // Other
    {"AddAura", &LuaUnit::AddAura},                                 // :AddAura(spellId, target) -- Adds an aura to the specified target
    {"RemoveAura", &LuaUnit::RemoveAura},                           // :RemoveAura(spellId, casterGuid(optional)) -- Removes an aura from the unit by the spellId, casterGUID(Original caster) is optional.
    {"RemoveAllAuras", &LuaUnit::RemoveAllAuras},                   // :RemoveAllAuras() -- Removes all the unit's auras
    {"ClearInCombat", &LuaUnit::ClearInCombat},                     // :ClearInCombat() -- Clears the unit's combat list (unit will be out of combat), resets the timer to 0, etc.
    {"DeMorph", &LuaUnit::DeMorph},                                 // :DeMorph() - Sets display back to native.
    {"SendUnitWhisper", &LuaUnit::SendUnitWhisper},                 // :SendUnitWhisper(msg, unit) -- Sends a whisper to the receiver
    {"SendUnitSay", &LuaUnit::SendUnitSay},                         // :SendUnitSay(msg, language) -- Sends a "Say" message with the specified language (all languages: 0)
    {"SendUnitYell", &LuaUnit::SendUnitYell},                       // :SendUnitYell(msg, language) -- Sends a "Yell" message with the specified language (all languages: 0)
    {"CastSpell", &LuaUnit::CastSpell},                             // :CastSpell(spellID) - Casts the spell on self, no manacost or cast time
    {"CastSpellOnTarget", &LuaUnit::CastSpellOnTarget},             // :CastSpellOnTarget(spellID, unit) - Casts the spell on target, no manacost or cast time
    {"CastSpellAoF", &LuaUnit::CastSpellAoF},                       // :CastSpellAoF(x, y, z, SpellID, triggered) - Casts the spell on coordinates, if triggered is false has manacost and cast time
    {"FullCastSpell", &LuaUnit::FullCastSpell},                     // :FullCastSpell(spellID) - Casts the spell on self
    {"FullCastSpellOnTarget", &LuaUnit::FullCastSpellOnTarget},     // :FullCastSpellOnTarget(spellID, unit) - Casts the spell on target
    {"PlayDirectSound", &LuaUnit::PlayDirectSound},                 // :PlayDirectSound(soundId,  player) - Unit plays soundID to player, or everyone around if no player.
    {"PlayDistanceSound", &LuaUnit::PlayDistanceSound},             // :PlayDistanceSound(soundId,  player) - Unit plays soundID to player, or everyone around if no player. The sound fades the further you are
    {"PlaySoundToSet", &LuaUnit::PlayDirectSound},                  // :PlaySoundToSet(soundId, player) - Unit plays soundID to player, or everyone around if no player. (ARC compability)
    {"Kill", &LuaUnit::Kill},                                       // :Kill(target, durabilityLoss) - Unit kills the target, if no target then kills the unit. Durabilityloss is true by default
    {"KnockbackFrom", &LuaUnit::KnockbackFrom},                     // :KnockbackFrom(x, y, speedXY, speedZ) - Knocks the player to the opposite direction from x,y at the defined speeds
    {"JumpTo", &LuaUnit::JumpTo},                                   // :JumpTo(WorldObj, speedZ) - Unit jumps to world object
    {"Jump", &LuaUnit::Jump},                                       // :Jump(speedXY, speedZ[, forward]) - Unit jumps at given speeds
    {"JumpToCoords", &LuaUnit::JumpToCoords},                       // :JumpToCoords(x, y, z, speedXY, speedZ) - Unit jumps to coordinates at given speeds
    {"MoveTo", &LuaUnit::MovePoint},                                // :MoveTo(id, x, y, z[, generatePath]) - Unit moves to point. ID is sent to WP reach hook
    {"MoveCharge", &LuaUnit::MoveCharge},                           // :MoveCharge(x, y, z, speed) - Charges to target location
    {"MoveChase", &LuaUnit::MoveChase},                             // :MoveChase(target[, dist, angle]) - Chases target unit
    {"MoveFollow", &LuaUnit::MoveFollow},                           // :MoveFollow(target, dist, angle) - Follows target unit
    {"MoveClear", &LuaUnit::MoveClear},                             // :MoveClear() - Stops movement
    {"MoveRandom", &LuaUnit::MoveRandom},                           // :MoveRandom() - Moves randomly inside radius
    {"MoveRotate", &LuaUnit::MoveRotate},                           // :MoveRotate(time, left) - Turns left (true or nil) or right (false) for given time
    {"SummonGameObject", &LuaUnit::SummonGameObject},               // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil UNDOCUMENTED
    {"SpawnCreature", &LuaUnit::SpawnCreature},                     // :SpawnCreature(entry, x, y, z, o[, despawnDelay]) - Spawns a creature to location that despawns after given time (0 for infinite). Returns the creature or nil UNDOCUMENTED
    {"StopSpellCast", &LuaUnit::StopSpellCast},                     // :StopSpellCast(spellId(optional)) -- Stops the unit from casting a spell. If a spellId is defined, it will stop that unit from casting that spell
    {"InterruptSpell", &LuaUnit::InterruptSpell},                   // :InterruptSpell(spellType, delayed(optional), instant(optional)) -- Interrupts the unit's spell by the spellType. If delayed is true it will skip if the spell is delayed. If instant is true, it will skip that the spell has a cast time.
    {"SendChatMessageToPlayer", &LuaUnit::SendChatMessageToPlayer}, // :SendChatMessageToPlayer(type, lang, msg, target) -- Unit sends a chat message to the given target player UNDOCUMENTED

    /* Vehicle */
    {"AddVehiclePassenger", &LuaUnit::AddVehiclePassenger},         // :AddVehiclePassenger(unit, seatId) - Adds a passenger to the vehicle by specifying a unit and seatId
    {"IsOnVehicle", &LuaUnit::IsOnVehicle},                         // :IsOnVehicle() - Checks if the (unit) is in a vehicle
    {"DismissVehicle", &LuaUnit::DismissVehicle},                   // :DismissVehicle() - Dismisses the (unit)'s vehicle (Unmounts)
    //{"EjectPassenger", &LuaUnit::EjectPassenger},                   // :EjectPassenger(unit) - Ejects a specified unit out of the vehicle   UNDOCUMENTED (UNTESTED)
    {"RemovePassenger", &LuaUnit::RemovePassenger},                 // :RemovePassenger(unit) - Removes a specific unit from the vehicle
    {"RemoveAllPassengers", &LuaUnit::RemoveAllPassengers},         // :RemoveAllPassengers() - Removes all the passengers from the vehicle
    {"GetPassenger", &LuaUnit::GetPassenger},                       // :GetPassenger(seatId) - Gets a passenger by their seatId
    {"GetNextEmptySeat", &LuaUnit::GetNextEmptySeat},               // :GetNextEmptySeat(seatId) - Gets(returns) the next empty seat
    {"GetAvailableSeats", &LuaUnit::GetAvailableSeats},             // :GetAvailableSeats() - Returns the available seats count
    {"GetVehicleBase", &LuaUnit::GetVehicleBase},                   // :GetVehicleBase() - Returns the unit's vehicle base
    {"HasEmptySeat", &LuaUnit::HasEmptySeat},                       // :HasEmptySeat(seatId) - Checks if the specified seatId is empty(nobody in it)
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
    {"SpawnCreature", &LuaGameObject::SummonCreature},              // :SummonCreature(entry, x, y, z, o, despawntime) Summons a temporary creature. 0 for infinitely, otherwise despawns after despawntime (ms) - UNDOCUMENTED
    {"RegisterEvent", &LuaGameObject::RegisterEvent},               // :RegisterEvent(function, delay, calls) - UNDOCUMENTED
    {"RemoveEventByID", &LuaGameObject::RemoveEventByID},           // :RemoveEventByID(eventID) - UNDOCUMENTED
    {"RemoveEvents", &LuaGameObject::RemoveEvents},                 // :RemoveEvents() - UNDOCUMENTED
    {"Despawn", &LuaGameObject::Despawn},                           // :Despawn() - Object despawns UNDOCUMENTED
    {"SummonGameObject", &LuaGameObject::SummonGameObject},         // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil UNDOCUMENTED

    { NULL, NULL },
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
    {"GetBagSlot", &LuaItem::GetBagSlot},                                   // :GetBagSlot() - returns the bagslot of the bag the item is in UNDOCUMENTED
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

ElunaRegister<Aura> AuraMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaAura::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Aura, Creature  UNDOCUMENTED
    {"GetCaster", &LuaAura::GetCaster},                             // :GetCaster() - Returns caster as object.					 UNDOCUMENTED
    {"GetCasterGUID", &LuaAura::GetCasterGUID},                     // :GetCasterGUID() - Returns caster as GUID.				 UNDOCUMENTED
    {"GetCasterLevel", &LuaAura::GetCasterLevel},                   // :GetCasterLevel() - Returns casters level.				 UNDOCUMENTED
    {"GetDuration", &LuaAura::GetDuration},                         // :GetDuration() - Returns remaining duration.				 UNDOCUMENTED
    {"GetMaxDuration", &LuaAura::GetMaxDuration},                   // :GetMaxDuration() - Returns maximum duration.		     UNDOCUMENTED
    {"GetCharges", &LuaAura::GetCharges},                           // :GetCharges() - Returns remaining charges.                UNDOCUMENTED
    {"GetAuraId", &LuaAura::GetAuraId},                             // :GetAuraId() - Returns aura ID.							 UNDOCUMENTED
    {"GetStackAmount", &LuaAura::GetStackAmount},                   // :GetStackAmount() - Returns current stack amount.         UNDOCUMENTED
    {"GetOwner", &LuaAura::GetOwner},                               // :GetOwner() - Gets the unit wearing the aura              UNDOCUMENTED

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                         // :SetDuration(duration) - Sets remaining duration.         UNDOCUMENTED
    {"SetMaxDuration", &LuaAura::SetMaxDuration},                   // :SetMaxDuration(duration) - Sets maximum duration.        UNDOCUMENTED
    {"SetStackAmount", &LuaAura::SetStackAmount},                   // :SetStackAmount(amount) - Sets current stack amount.      UNDOCUMENTED

    // Other
    {"Remove", &LuaAura::Remove},                                   // :Remove() - Removes the aura.                             UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Spell> SpellMethods[] =
{
    // Getters
    {"GetUnitType", &LuaSpell::GetUnitType},                        // :GetUnitType() -- Returns the unit type (Spell)              UNDOCUMENTED
    {"GetCaster", &LuaSpell::GetCaster},                            // :GetCaster()  -- Returns the spell's caster (UNIT)           UNDOCUMENTED
    {"GetCastTime", &LuaSpell::GetCastTime},                        // :GetCastTime() -- Returns the spell cast time                UNDOCUMENTED
    {"GetId", &LuaSpell::GetId},                                    // :GetId() -- Returns the spell's ID                           UNDOCUMENTED
    {"GetDuration", &LuaSpell::GetDuration},                        // :GetDuration() -- Returns the spell's duration               UNDOCUMENTED
    {"GetPowerCost", &LuaSpell::GetPowerCost},                      // :GetPowerCost() -- Returns the spell's power cost (mana, energy, rage, etc)      UNDOCUMENTED

    // Other
    {"Cancel", &LuaSpell::cancel},                                  // :Cancel() -- Cancels the spell casting                       UNDOCUMENTED
    {"Cast", &LuaSpell::Cast},                                      // :Cast(skipCheck) -- Casts the spell (if true, removes the check for instant spells, etc)      UNDOCUMENTED
    {"Finish", &LuaSpell::Finish},                                  // :Finish() -- Finishes the spell (SPELL_STATE_FINISH)         UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Quest> QuestMethods[] =
{
    // Getters
    {"GetUnitType", &LuaQuest::GetUnitType},                        // :GetUnitType() -- Returns the unit type (Quest)              UNDOCUMENTED
    {"GetId", &LuaQuest::GetId},                                    // :GetId() -- Returns the quest's Id                           UNDOCUMENTED
    {"GetLevel", &LuaQuest::GetLevel},                              // :GetLevel() -- Returns the quest's level                     UNDOCUMENTED
    {"GetMaxLevel", &LuaQuest::GetMaxLevel},                        // :GetMaxLevel() -- Returns the quest's max level              UNDOCUMENTED
    {"GetMinLevel", &LuaQuest::GetMinLevel},                        // :GetMinLevel() -- Returns the quest's min level              UNDOCUMENTED
    {"GetNextQuestId", &LuaQuest::GetNextQuestId},                  // :GetNextQuestId() -- Returns the quest's next quest ID       UNDOCUMENTED
    {"GetPrevQuestId", &LuaQuest::GetPrevQuestId},                  // :GetPrevQuestId() -- Returns the quest's previous quest ID   UNDOCUMENTED
    {"GetNextQuestInChain", &LuaQuest::GetNextQuestInChain},        // :GetNexQuestInChain() -- Returns the next quest in its chain  UNDOCUMENTED
    {"GetFlags", &LuaQuest::GetFlags},                              // :GetFlags() -- Returns the quest's flags                     UNDOCUMENTED
    {"GetType", &LuaQuest::GetType},                                // :GetType() -- Returns the quest's type                       UNDOCUMENTED

    // Boolean
    {"HasFlag", &LuaQuest::HasFlag},                                // :HasFlag(flag) -- Returns true or false if the quest has the specified flag    UNDOCUMENTED
    {"IsDaily", &LuaQuest::IsDaily},                                // :IsDaily() -- Returns true or false if the quest is a daily  UNDOCUMENTED
    {"IsRepeatable", &LuaQuest::IsRepeatable},                      // :IsRepeatable() -- Returns true or false if the quest is repeatable   UNDOCUMENTED

    // Setters
    {"SetFlag", &LuaQuest::SetFlag},                                // :SetFlag(flag) -- Sets the flag of the quest by the specified flag    UNDOCUMENTED

    {NULL, NULL},
};

ElunaRegister<Group> GroupMethods[] = 
{
    // Getters
    {"GetMembers", &LuaGroup::GetMembers},                          // :GetMembers() - returns a table the players in this group. (Online?)
    {"GetLeaderGUID", &LuaGroup::GetLeaderGUID},
    {"GetLeader", &LuaGroup::GetLeader},
    {"GetUnitType", &LuaGroup::GetUnitType},
    {"GetGUID", &LuaGroup::GetGUID},
    {"GetMemberGroup", &LuaGroup::GetMemberGroup},                  // :GetMemberGroup(player) - Returns the player's subgroup ID UNDOCUMENTED
    {"GetMemberGUID", &LuaGroup::GetMemberGUID},                    // :GetMemberGUID("name") - Returns the member's GUID UNDOCUMENTED
    {"GetMembersCount", &LuaGroup::GetMembersCount},                // :GetMembersCount() - Returns the member count of the group UNDOCUMENTED

    // Setters
    {"SetLeader", &LuaGroup::ChangeLeader},                         // :SetLeader(Player) - Sets the player as the new leader.
    {"SetMembersGroup", &LuaGroup::ChangeMembersGroup},             // :ChangeMembersGroup(player, subGroup) - Changes the member's subgroup UNDOCUMENTED

    // Boolean
    {"IsLeader", &LuaGroup::IsLeader},                              // :IsLeader("name"/Player)
    //{"HasRole", &LuaGroup::HasRole},                              // :HasRole("name"/Player, "role") - "tank" / "healer" / "dps"
    {"AddInvite", &LuaGroup::AddInvite},                            // :AddInvite(player) - Adds a an invite to player. Returns true if succesful UNDOCUMENTED
    {"RemoveMember", &LuaGroup::RemoveMember},                      // :RemoveMember(player) - Removes player from group. Returns true on success UNDOCUMENTED
    {"Disband", &LuaGroup::Disband},                                // :Disband() - Disbands the group. UNDOCUMENTED
    {"IsFull", &LuaGroup::IsFull},                                  // :IsFull() - Returns true if the group is full UNDOCUMENTED
    {"IsLFGGroup", &LuaGroup::isLFGGroup},                          // :IsLFGGroup() - Returns true if the group is an LFG group UNDOCUMENTED
    {"IsRaidGroup", &LuaGroup::isRaidGroup},                        // :IsRaidGroup() - Returns true if the group is a raid group UNDOCUMENTED
    {"IsBGGroup", &LuaGroup::isBGGroup},                            // :IsBGGroup() - Returns true if the group is a battleground group UNDOCUMENTED
    {"IsBFGroup", &LuaGroup::isBFGroup},                            // :IsBFGroup() - Returns true if the group is a battlefield group UNDOCUMENTED
    {"IsMember", &LuaGroup::IsMember},                              // :IsMember(player) - Returns true if the player is a member of the group UNDOCUMENTED
    {"IsAssistant", &LuaGroup::IsAssistant},                        // :IsAssistant(player) - returns true if the player is an assistant in the group UNDOCUMENTED
    {"SameSubGroup", &LuaGroup::SameSubGroup},                      // :SameSubGroup(player1, player2) - Returns true if the players are in the same subgroup in the group UNDOCUMENTED
    {"HasFreeSlotSubGroup", &LuaGroup::HasFreeSlotSubGroup},        // :HasFreeSlotSubGroup(subGroup) - Returns true if the subgroupID has free slots UNDOCUMENTED

    // Other
    {"SendPacket", &LuaGroup::SendPacket},                          // :SendPacket(packet, sendToPlayersInBattleground[, ignoreguid]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground. Optionally ignores given player guid. UNDOCUMENTED
    {"ConvertToLFG", &LuaGroup::ConvertToLFG},                      // :ConvertToLFG() - Converts the group to an LFG group UNDOCUMENTED
    {"ConvertToRaid", &LuaGroup::ConvertToRaid},                    // :ConvertToRaid() - Converts the group to a raid group UNDOCUMENTED

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

ElunaRegister<WorldPacket> PacketMethods[] =
{
    // Getters
    {"GetOpcode", &LuaPacket::GetOpcode},                           //  :GetOpcode() -- Returns an opcode                    (UNDOCUMENTED)
    {"GetSize", &LuaPacket::GetSize},                               //  :GetSize() -- Returns the packet size                 (UNDOCUMENTED)
    {"GetUnitType", &LuaPacket::GetOpcode},                         //  :GetUnitType() -- Returns the unit type: Packet      (UNDOCUMENTED)

    // Setters
    {"SetOpcode", &LuaPacket::SetOpcode},                           //  :SetOpcode(opcode) -- Sets the opcode by specifying an opcode            (UNDOCUMENTED)

    // Readers
    {"ReadByte", &LuaPacket::ReadByte},                             //  :ReadByte() -- Reads an int8 value                    (UNDOCUMENTED)
    {"ReadUByte", &LuaPacket::ReadUByte},                           //  :ReadUByte() -- Reads a uint8 value                   (UNDOCUMENTED)             
    {"ReadShort", &LuaPacket::ReadShort},                           //  :ReadShort() -- Reads an int16 value                  (UNDOCUMENTED)
    {"ReadUShort", &LuaPacket::ReadUShort},                         //  :ReadUShort() -- Reads a uint16 value                 (UNDOCUMENTED)
    {"ReadString", &LuaPacket::ReadString},                         //  :ReadString()  -- Reads a string value                (UNDOCUMENTED)
    {"ReadFloat", &LuaPacket::ReadFloat},                           //  :ReadFloat()  -- Reads a float value                  (UNDOCUMENTED)
    {"ReadDouble", &LuaPacket::ReadDouble},                         //  :ReadDouble() -- Reads a double value                 (UNDOCUMENTED)
    {"ReadLong", &LuaPacket::ReadLong},                             //  :ReadLong() -- Reads an int32 value                   (UNDOCUMENTED)
    {"ReadULong", &LuaPacket::ReadULong},                           //  :ReadULong() -- Reads a uint32 value                  (UNDOCUMENTED)
    {"ReadGUID", &LuaPacket::ReadGUID},                             //  :ReadGUID() -- Reads a uint64 GUID value              (UNDOCUMENTED)

    // Writers
    {"WriteByte", &LuaPacket::WriteByte},                           //  :WriteByte(val)  -- Writes an int8 byte value         (UNDOCUMENTED)
    {"WriteUByte", &LuaPacket::WriteUByte},                         //  :WriteUByte(val) -- Writes a uint8 ubyte value        (UNDOCUMENTED)
    {"WriteShort", &LuaPacket::WriteShort},                         //  :WriteShort(val) -- Writes an int16 short value       (UNDOCUMENTED)
    {"WriteUShort", &LuaPacket::WriteUShort},                       //  :WriteUShort(val) -- Writes a uint16 ushort value     (UNDOCUMENTED)
    {"WriteString", &LuaPacket::WriteString},                       //  :WriteString(val) -- Writes a string value            (UNDOCUMENTED)
    {"WriteFloat", &LuaPacket::WriteFloat},                         //  :WriteFloat(val) -- Writes a float value              (UNDOCUMENTED)
    {"WriteDouble", &LuaPacket::WriteDouble},                       //  :WriteDouble(val) -- Writes a double value            (UNDOCUMENTED)
    {"WriteGUID", &LuaPacket::WriteGUID},                           //  :WriteGUID(worldobject) -- Writes a uint64 guid value. WorldObject can be any unit: creature, gameobject, item.. (UNDOCUMENTED)
    {"WriteLong", &LuaPacket::WriteLong},                           //  :WriteLong(val) -- Writes an int32 long value         (UNDOCUMENTED)
    {"WriteULong", &LuaPacket::WriteULong},                         //  :WriteULong(val) -- Writes a uint32 ulong value       (UNDOCUMENTED)
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
#endif

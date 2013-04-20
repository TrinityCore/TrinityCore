#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Unit> UnitMethods[] =
{
    // Player Methods
    // Getters
    {"GetSelection", &LuaUnit::GetSelection},                       // :GetSelection()
    {"GetGMRank", &LuaUnit::GetSecurity},                           // :GetSecurity()
    {"GetGuildId", &LuaUnit::GetGuildId},                           // :GetGuildId() - nil on no guild.
    {"GetCoinage", &LuaUnit::GetCoinage},                           // :GetCoinage()
    {"GetTeam", &LuaUnit::GetTeam},                                 // :GetTeam() - returns the player's team. 0 for ally, 1 for horde
    {"GetItemCount", &LuaUnit::GetItemCount},                       // :GetItemCount(item_id[, check_bank]) -
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
    {"GetInventoryItem", &LuaUnit::GetInventoryItem},               // :GetInventoryItem(slot) -  Returns item at given inventory slot (0, 1, 2.. for equipment 19-23 for bags, 23-39 for backpack)
    {"GetBagItem", &LuaUnit::GetBagItem},                           // :GetBagItem(bagSlot, slot) -  Returns item at given slot (0, 1, 2 .. max slots for bag) in a bag (19-23).
    {"GetObjectGlobally", &LuaUnit::GetObjectGlobally},             // :GetObjectGlobally(lowguid, entry) - Returns the gameobject of given lowguid and entry if in world.
    {"GetNearbyGameObject", &LuaUnit::GetNearbyGameObject},         // :GetNearbyGameObject() - Returns nearby gameobject if found.
    {"GetReputation", &LuaUnit::GetReputation},                     // :GetReputation(faction) -- Gets player's reputation with given faction.
    {"GetItemByEntry", &LuaUnit::GetItemByEntry},                   // :GetItemByEntry(entry) -- Gets an item if the player has it.
    {"GetQuestLevel", &LuaUnit::GetQuestLevel},                     // :GetQuestLevel(quest) -- Returns quest's level.
    {"GetChatTag", &LuaUnit::GetChatTag},                           // :GetChatTag() -- Returns player chat tag ID.
    {"GetRestBonus", &LuaUnit::GetRestBonus},                       // :GetRestBonus() -- Gets player's rest bonus.
    {"GetRestType", &LuaUnit::GetRestType},                         // :GetRestType() -- Returns the player's rest type.
    {"GetPhaseMaskForSpawn", &LuaUnit::GetPhaseMaskForSpawn},       // :GetPhaseMaskForSpawn() -- Gets the real phasemask for spawning things. Used if the player is in GM mode.
    {"GetReqKillOrCastCurrentCount", &LuaUnit::RemoveRewardedQuest},    // :GetReqKillOrCastCurrentCount(questId, entry) -- Gets the objective (kill or cast) current count done.
    {"GetQuestStatus", &LuaUnit::GetQuestStatus},                   // :GetQuestStatus(entry) -- Gets the quest's status.
    {"GetInGameTime", &LuaUnit::GetInGameTime},                     // :GetInGameTime() -- Returns player's ingame time.
    {"GetComboPoints", &LuaUnit::GetComboPoints},                   // :GetComboPoints() -- Returns player's combo points.
    {"GetComboTarget", &LuaUnit::GetComboTarget},                   // :GetComboTarget() -- Returns the player's combo target.
    {"GetGuildName", &LuaUnit::GetGuildName},                       // :GetGuildName() -- Returns player's guild's name or nil.
    {"GetFreeTalentPoints", &LuaUnit::GetFreeTalentPoints},         // :GetFreeTalentPoints() -- Returns the amount of unused talent points.
    {"GetActiveSpec", &LuaUnit::GetActiveSpec},                     // :GetActiveSpec() -- Returns the active specID.
    {"GetSpecsCount", &LuaUnit::GetSpecsCount},                     // :GetSpecsCount() -- Returns the player's spec count.
    {"GetSpellCooldownDelay", &LuaUnit::GetSpellCooldownDelay},     // :GetSpellCooldownDelay(spellId) -- Returns the spell's cooldown.
    {"GetGuildRank", &LuaUnit::GetRank},                            // :GetGuildRank() -- Gets the player's guild rank.
    {"GetDifficulty", &LuaUnit::GetDifficulty},                     // :GetDifficulty(isRaid) -- Returns the current difficulty.
    {"GetHealthBonusFromStamina", &LuaUnit::GetHealthBonusFromStamina}, // :GetHealthBonusFromStamina() -- Returns the HP bonus from stamina.
    {"GetManaBonusFromIntellect", &LuaUnit::GetManaBonusFromIntellect}, // :GetManaBonusFromIntellect() -- Returns the mana bonus from intellect.
    {"GetMaxSkillValue", &LuaUnit::GetMaxSkillValue},               // :GetMaxSkillValue(skill) -- Gets max skill value for the given skill.
    {"GetPureMaxSkillValue", &LuaUnit::GetPureMaxSkillValue},       // :GetPureMaxSkillValue(skill) -- Gets max base skill value.
    {"GetSkillValue", &LuaUnit::GetSkillValue},                     // :GetSkillValue(skill) -- Gets current skill value.
    {"GetBaseSkillValue", &LuaUnit::GetBaseSkillValue},             // :GetBaseSkillValue(skill) -- Gets current base skill value (no temp bonus).
    {"GetPureSkillValue", &LuaUnit::GetPureSkillValue},             // :GetPureSkillValue(skill) -- Gets current base skill value (no bonuses).
    {"GetSkillStep", &LuaUnit::GetSkillStep},                       // :GetSkillStep(skill) -- Returns current skillstep.
    {"GetSkillPermBonusValue", &LuaUnit::GetSkillPermBonusValue},   // :GetSkillPermBonusValue(skill) -- Returns current permanent bonus.
    {"GetSkillTempBonusValue", &LuaUnit::GetSkillTempBonusValue},   // :GetSkillTempBonusValue(skill) -- Returns current temp bonus.
    {"GetReputationRank", &LuaUnit::GetReputationRank},             // :GetReputationRank(faction) -- Returns the reputation rank with given faction.
    {"GetSpellCooldowns", &LuaUnit::GetSpellCooldowns},             // :GetSpellCooldowns() -- Gets a table where spellIDs are the keys and values are cooldowns.
    {"GetDrunkValue", &LuaUnit::GetDrunkValue},                     // :GetDrunkValue() -- Returns the current drunkness value.
    {"GetBattlegroundId", &LuaUnit::GetBattlegroundId},             // :GetBattlegroundId() -- Returns the player's current battleground ID.
    {"GetBattlegroundTypeId", &LuaUnit::GetBattlegroundTypeId},     // :GetBattlegroundTypeId() -- Returns the player's current battleground type ID.
    {"GetXPRestBonus", &LuaUnit::GetXPRestBonus},                   // :GetXPRestBonus(xp) -- Returns the rested bonus XP from given XP.
    {"GetRestTime", &LuaUnit::GetRestTime},                         // :GetRestTime() -- Returns the timed rested.
    {"GetGroupInvite", &LuaUnit::GetGroupInvite},                   // :GetGroupInvite() -- Returns the group invited to.
    {"GetSubGroup", &LuaUnit::GetSubGroup},                         // :GetSubGroup() -- Gets the player's current subgroup ID.
    {"GetNextRandomRaidMember", &LuaUnit::GetNextRandomRaidMember}, // :GetNextRandomRaidMember(radius) -- Gets a random raid member in given radius.
    {"GetOriginalGroup", &LuaUnit::GetOriginalGroup},               // :GetOriginalGroup() -- Gets the original group object.
    {"GetOriginalSubGroup", &LuaUnit::GetOriginalSubGroup},         // :GetOriginalSubGroup() -- Returns the original subgroup ID.
    {"GetChampioningFaction", &LuaUnit::GetChampioningFaction},     // :GetChampioningFaction() -- Returns the player's championing faction.
    {"GetLatency", &LuaUnit::GetLatency},                           // :GetLatency() -- Returns player's latency.
    {"GetRecruiterId", &LuaUnit::GetRecruiterId},                   // :GetRecruiterId() -- Returns player's recruiter's ID.
    {"GetSelectedPlayer", &LuaUnit::GetSelectedPlayer},             // :GetSelectedPlayer() -- Returns player's selected player. UNDOCUMENTED
    {"GetSelectedUnit", &LuaUnit::GetSelectedUnit},                 // :GetSelectedUnit() -- Returns player's selected unit. UNDOCUMENTED

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
    {"SetGameMaster", &LuaUnit::SetGameMaster},                     // :SetGameMaster(on) -- Sets GM mode on or off.
    {"SetGMChat", &LuaUnit::SetGMChat},                             // :SetGMChat(on) -- Sets GM chat on or off.
    {"SetTaxiCheat", &LuaUnit::SetTaxiCheat},                       // :SetTaxiCheat(on) -- Sets taxi cheat on or off.
    {"SetGMVisible", &LuaUnit::SetGMVisible},                       // :SetGMVisible(on) -- Sets gm visibility on or off.
    {"SetPvPDeath", &LuaUnit::SetPvPDeath},                         // :SetPvPDeath(on) -- Sets PvP death on or off.
    {"SetAcceptWhispers", &LuaUnit::SetAcceptWhispers},             // :SetAcceptWhispers(on) -- Sets whisper accepting death on or off.
    {"SetRestBonus", &LuaUnit::SetRestBonus},                       // :SetRestBonus(bonusrate) -- Sets new restbonus rate.
    {"SetRestType", &LuaUnit::SetRestType},                         // :SetRestType() -- Sets rest type.
    {"SetSheath", &LuaUnit::SetSheath},                             // :SetSheath(SheathState) -- Sets player's seathstate.
    {"SetQuestStatus", &LuaUnit::SetQuestStatus},                   // :SetQuestStatus(entry, status) -- Sets the quest's status.
    {"SetReputation", &LuaUnit::SetReputation},                     // :SetReputation(faction, value) -- Sets the faction reputation for the player.
    {"SetFreeTalentPoints", &LuaUnit::SetFreeTalentPoints},         // :SetFreeTalentPoints(points) -- Sets the amount of unused talent points.
    {"SetGuildRank", &LuaUnit::SetRank},                            // :SetGuildRank(rank) -- Sets player's guild rank.
    {"SetMovement", &LuaUnit::SetMovement},                         // :SetMovement(type) -- Sets player's movement type.
    {"SetSkill", &LuaUnit::SetSkill},                               // :SetSkill(skill, step, currVal, maxVal) -- Sets the skill's boundaries and value.
    {"SetFactionForRace", &LuaUnit::setFactionForRace},             // :SetFactionForRace(race) -- Sets the faction by raceID.
    {"SetDrunkValue", &LuaUnit::SetDrunkValue},                     // :SetDrunkValue(newDrunkValue) -- Sets drunkness value.
    {"SetRestTime", &LuaUnit::SetRestTime},                         // :SetRestTime(value) -- Sets the rested time.
    {"SetAtLoginFlag", &LuaUnit::SetAtLoginFlag},                   // :SetAtLoginFlag(flag) -- Adds an at login flag.
    {"SetPlayerLock", &LuaUnit::SetPlayerLock},                     // :SetPlayerLock(on/off) - UNDOCUMENTED

    // Boolean
    {"IsWithinLOS", &LuaUnit::IsWithinLOS},							// :IsWithinLOS(x, y, z) - UNDOCUMENTED
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
    {"CanEquipItem", &LuaUnit::CanEquipItem},                       // :CanEquipItem(entry/item, slot) - Returns true if the player can equip given item/item entry.
    {"IsFalling", &LuaUnit::IsFalling},                             // :IsFalling() -- Returns true if the unit is falling.
    {"ToggleAFK", &LuaUnit::ToggleAFK},                             // :ToggleAFK() -- Toggles AFK state for player.
    {"ToggleDND", &LuaUnit::ToggleDND},                             // :ToggleDND() -- Toggles DND state for player.
    {"IsAFK", &LuaUnit::isAFK},                                     // :IsAFK() -- Returns true if the player is afk.
    {"IsDND", &LuaUnit::isDND},                                     // :IsDND() -- Returns true if the player is in dnd mode.
    {"IsAcceptingWhispers", &LuaUnit::isAcceptingWhispers},         // :IsAcceptWhispers() -- Returns true if the player accepts whispers.
    {"IsGMChat", &LuaUnit::isGMChat},                               // :IsGMChat() -- Returns true if the player has GM chat on.
    {"IsTaxiCheater", &LuaUnit::isTaxiCheater},                     // :IsTaxiCheater() -- Returns true if the player has taxi cheat on.
    {"IsGMVisible", &LuaUnit::isGMVisible},                         // :IsGMVisible() -- Returns true if the player is GM visible.
    {"IsActiveQuest", &LuaUnit::IsActiveQuest},                     // :IsActiveQuest(entry) -- Returns true if the quest entry is active for the player.
    {"InBattlegroundQueue", &LuaUnit::InBattlegroundQueue},         // :InBattlegroundQueue() -- Returns true if the player is in a battleground queue.
    {"IsImmuneToEnvironmentalDamage", &LuaUnit::IsImmuneToEnvironmentalDamage}, // :IsImmuneToEnvironmentalDamage() -- Returns true if the player is immune to enviromental damage.
    {"CanSpeak", &LuaUnit::CanSpeak},                               // :CanSpeak() -- Returns true if the player can speak.
    {"HasAtLoginFlag", &LuaUnit::HasAtLoginFlag},                   // :HasAtLoginFlag(flag) -- returns true if the player has the login flag.
    {"InRandomLfgDungeon", &LuaUnit::inRandomLfgDungeon},           // :InRandomLfgDungeon() -- Returns true if the player is in a random LFG dungeon.
    {"HasPendingBind", &LuaUnit::HasPendingBind},                   // :HasPendingBind() -- Returns true if the player has a pending instance bind.
    {"HasAchieved", &LuaUnit::HasAchieved},                         // :HasAchieved(achievementID) -- Returns true if the player has achieved the achievement.
    {"CanUninviteFromGroup", &LuaUnit::CanUninviteFromGroup},       // :CanUninviteFromGroup() -- Returns true if the player can uninvite from group.
    {"IsRested", &LuaUnit::isRested},                               // :IsRested() -- Returns true if the player is rested.
    {"CanFlyInZone", &LuaUnit::CanFlyInZone},                       // :CanFlyInZone(mapid, zone) -- Returns true if the player can fly in the area.
    {"IsNeverVisible", &LuaUnit::IsNeverVisible},                   // :IsNeverVisible() -- Returns true if the player is never visible.
    {"IsVisibleForPlayer", &LuaUnit::IsVisibleForPlayer},           // :IsVisibleForPlayer(player) -- Returns true if the player is visible for the target player.
    {"IsUsingLfg", &LuaUnit::isUsingLfg},                           // :IsUsingLfg() -- Returns true if the player is using LFG.
    {"HasQuestForItem", &LuaUnit::HasQuestForItem},                 // :HasQuestForItem(entry) -- Returns true if the player has the quest for the item.
    {"HasQuestForGO", &LuaUnit::HasQuestForGO},                     // :HasQuestForGO(entry) -- Returns true if the player has the quest for the gameobject.
    {"CanShareQuest", &LuaUnit::CanShareQuest},                     // :CanShareQuest(entry) -- Returns true if the quest entry is shareable by the player.
    {"HasReceivedQuestReward", &LuaUnit::HasReceivedQuestReward},   // :HasReceivedQuestReward(entry) -- Returns true if the player has recieved the quest's reward.
    {"HasTalent", &LuaUnit::HasTalent},                             // :HasTalent(spellid, spec) -- Returns true if the player has the talent spell in given spec.
    {"IsInSameGroupWith", &LuaUnit::IsInSameGroupWith},             // :IsInSameGroupWith(player) -- Returns true if the players are in the same group.
    {"IsInSameRaidWith", &LuaUnit::IsInSameRaidWith},               // :IsInSameRaidWith(player) -- Returns true if the players are in the same raid.
    {"IsGroupVisibleFor", &LuaUnit::IsGroupVisibleFor},             // :IsGroupVisibleFor(player) -- Player is group visible for the target.
    {"HasSkill", &LuaUnit::HasSkill},                               // :HasSkill(skill) -- Returns true if the player has the skill.
    {"IsHonorOrXPTarget", &LuaUnit::isHonorOrXPTarget},             // :IsHonorOrXPTarget(victim) -- Returns true if the victim gives honor or XP.
    {"CanParry", &LuaUnit::CanParry},                               // :CanParry() -- Returns true if the player can parry.
    {"CanBlock", &LuaUnit::CanBlock},                               // :CanBlock() -- Returns true if the player can block.
    {"CanTitanGrip", &LuaUnit::CanTitanGrip},                       // :CanTitanGrip() -- Returns true if the player has titan grip.
    {"CanTameExoticPets", &LuaUnit::CanTameExoticPets},             // :CanTameExoticPets() -- Returns true if the player can tame exotic pets.
    {"InBattleground", &LuaUnit::InBattleground},                   // :InBattleground() -- Returns true if the player is in a battleground.
    {"InArena", &LuaUnit::InArena},                                 // :InArena() -- Returns true if the player is in an arena.
    {"IsOutdoorPvPActive", &LuaUnit::IsOutdoorPvPActive},           // :IsOutdoorPvPActive() -- Returns true if the player is outdoor pvp active.
    {"IsARecruiter", &LuaUnit::IsARecruiter},                       // :IsARecruiter() -- Returns true if the player is a recruiter.

    // Gossip                                                           
    {"GossipMenuAddItem", &LuaUnit::GossipMenuAddItem},             // :GossipMenuAddItem(icon, msg, sender, intid[, code, popup, money])
    {"GossipSendMenu", &LuaUnit::GossipSendMenu},                   // :GossipSendMenu(npc_text, unit[, menu_id]) -- If unit is a player, you need to use a menu_id. menu_id is used to hook the gossip select function to the menu.
    {"GossipComplete", &LuaUnit::GossipComplete},                   // :GossipComplete()
    {"GossipClearMenu", &LuaUnit::GossipClearMenu},                 // :GossipClearMenu() -- Clears the gossip menu of options. Pretty much only useful with player gossip. Need to use before creating a new menu for the player

    // Other
    {"Dismount", &LuaUnit::Dismount },								// :Dismount() - Dismounts the unit. UNDOCUMENTED
    {"SendClearCooldowns", &LuaUnit::SendClearCooldowns },          // :SendClearCooldowns(spellId, (unit)target) -- Clears the cooldown of the target with a specified spellId.
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
    {"RemoveItem", &LuaUnit::RemoveItem},                           // :RemoveItem(item/entry, amount) - Removes amount of item from player.
    {"RemoveLifetimeKills", &LuaUnit::RemoveLifetimeKills},         // :RemoveLifetimeKills(val) - Removes a specified amount(val) of the player's lifetime (honorable) kills
    {"ResurrectPlayer", &LuaUnit::ResurrectPlayer},                 // :ResurrectPlayer([percent[, sickness(bool)]]) - Resurrects the player at percentage, player gets resurrection sickness if sickness set to true.
    {"PlaySoundToPlayer", &LuaUnit::PlaySoundToPlayer},             // :PlaySoundToPlayer(soundId) - Plays the specified sound to the player
    {"EquipItem", &LuaUnit::EquipItem},                             // :EquipItem(entry/item, slot) -  Equips given item or item entry for player to given slot. Returns the equipped item or nil.
    {"ResetSpellCooldown", &LuaUnit::ResetSpellCooldown},           // :ResetSpellCooldown(spellId, update(bool~optional)) -- Resets cooldown of the specified spellId. If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default.
    {"ResetTypeCooldowns", &LuaUnit::ResetTypeCooldowns},           // :ResetTypeCooldowns(category, update(bool~optional)) -- Resets all cooldowns for the spell category(type). If update is true, it will send WorldPacket SMSG_CLEAR_COOLDOWN to the player, else it will just clear the spellId from m_spellCooldowns. This is true by default.
    {"ResetAllCooldowns", &LuaUnit::ResetAllCooldowns},             // :ResetAllCooldowns() -- Resets all spell cooldowns.
    {"GiveLevel", &LuaUnit::GiveLevel},                             // :GiveLevel(level) -- Gives levels to the player.
    {"GiveXP", &LuaUnit::GiveXP},                                   // :GiveXP(xp[, victim, group_rate]) -- Gives XP to the player.
    {"RemovePet", &LuaUnit::RemovePet},                             // :RemovePet([mode, returnreagent]) -- Removes the player's pet. Mode determines if the pet is saved and how.
    {"SummonPet", &LuaUnit::SummonPet},                             // :SummonPet(entry, x, y, z, o, petType, despwtime) -- Summons a pet for the player.
    {"Say", &LuaUnit::Say},                                         // :Say(text, lang) -- The player says the text.
    {"Yell", &LuaUnit::Yell},                                       // :Yell(text, lang) -- The player yells the text.
    {"TextEmote", &LuaUnit::TextEmote},                             // :TextEmote(text) -- The player does a textemote with the text.
    {"Whisper", &LuaUnit::Whisper},                                 // :Whisper(text, lang, receiverGuid) -- The player whispers the text to the guid.
    {"CompleteQuest", &LuaUnit::CompleteQuest},                     // :CompleteQuest(entry) -- Completes a quest by entry.
    {"IncompleteQuest", &LuaUnit::IncompleteQuest},                 // :IncompleteQuest(entry) -- Uncompletes the quest by entry for the player.
    {"FailQuest", &LuaUnit::FailQuest},                             // :FailQuest(entry) -- Player fails the quest entry.
    {"RemoveActiveQuest", &LuaUnit::RemoveActiveQuest},             // :RemoveActiveQuest(entry) -- Removes an active quest.
    {"RemoveRewardedQuest", &LuaUnit::RemoveRewardedQuest},         // :RemoveRewardedQuest(entry) -- Removes a rewarded quest.
    {"AreaExploredOrEventHappens", &LuaUnit::AreaExploredOrEventHappens},   // :AreaExploredOrEventHappens(questId) -- Satisfies an area or event requrement for the questId.
    {"GroupEventHappens", &LuaUnit::GroupEventHappens},             // :GroupEventHappens(questId, worldObject) -- Satisfies a group event for the questId with the world object.
    {"KilledMonsterCredit", &LuaUnit::KilledMonsterCredit},         // :KilledMonsterCredit(entry) -- Satisfies a monsterkill for the player.
    {"KilledPlayerCredit", &LuaUnit::KilledPlayerCredit},           // :KilledPlayerCredit() -- Satisfies a player kill for the player.
    {"CastedCreatureOrGO", &LuaUnit::CastedCreatureOrGO},           // :CastedCreatureOrGO(creatureOrGOEntry, creatureOrGO, spellId) -- Satisfies a spellcast on unit for the player.
    {"TalkedToCreature", &LuaUnit::TalkedToCreature},               // :TalkedToCreature(npcEntry, creature) -- Satisfies creature talk objective for the player.
    {"ResetPetTalents", &LuaUnit::ResetPetTalents},                 // :ResetPetTalents() -- Resets player's pet's talents.
    {"RegenerateAll", &LuaUnit::RegenerateAll},                     // :RegenerateAll() -- Regenerates all player's powers.
    {"Regenerate", &LuaUnit::Regenerate},                           // :Regenerate(powerType) -- Regenerates the given power type.
    {"RegenerateHealth", &LuaUnit::RegenerateHealth},               // :RegenerateHealth() -- Regenerates health.
    {"AddComboPoints", &LuaUnit::AddComboPoints},                   // :AddComboPoints(target, count[, spell]) -- Adds combo points to the target for the player.
    {"GainSpellComboPoints", &LuaUnit::GainSpellComboPoints},       // :GainSpellComboPoints(amount) -- Player gains spell combo points.
    {"ClearComboPoints", &LuaUnit::ClearComboPoints},               // :ClearComboPoints() -- Clears player's combo points.
    {"RemoveSpell", &LuaUnit::removeSpell},                         // :RemoveSpell(entry[, disabled, learn_low_rank]) -- Removes (unlearn) the given spell.
    {"ResetTalents", &LuaUnit::resetTalents},                       // :ResetTalents([no_cost]) -- Resets player's talents.
    {"ResetTalentsCost", &LuaUnit::resetTalentsCost},               // :ResetTalentsCost() -- Returns the reset talents cost.
    {"AddTalent", &LuaUnit::AddTalent},                             // :AddTalent(spellid, spec, learning) -- Adds a talent spell for the player to given spec.
    {"RemoveFromGroup", &LuaUnit::RemoveFromGroup},                 // :RemoveFromGroup() -- Removes the player from his group.
    {"KillPlayer", &LuaUnit::KillPlayer},                           // :KillPlayer() -- Kills the player.
    {"DurabilityLossAll", &LuaUnit::DurabilityLossAll},             // :DurabilityLossAll(percent[, inventory]) -- The player's items lose durability. Inventory true by default.
    {"DurabilityLoss", &LuaUnit::DurabilityLoss},                   // :DurabilityLoss(item, percent) -- The given item loses durability.
    {"DurabilityPointsLoss", &LuaUnit::DurabilityPointsLoss},       // :DurabilityPointsLoss(item, points) -- The given item loses durability.
    {"DurabilityPointsLossAll", &LuaUnit::DurabilityPointsLossAll}, // :DurabilityPointsLossAll(points, inventory) -- Player's items lose durability.
    {"DurabilityPointLossForEquipSlot", &LuaUnit::DurabilityPointLossForEquipSlot}, // :DurabilityPointLossForEquipSlot(slot) -- Causes durability loss for the item in the given slot.
    {"DurabilityRepairAll", &LuaUnit::DurabilityRepairAll},         // :DurabilityRepairAll(has_cost, discount, guildBank) -- Repairs all durability.
    {"DurabilityRepair", &LuaUnit::DurabilityRepair},               // :DurabilityRepair(position, has_cost, discount, guildBank) -- Repairs item durability of item in given position.
    {"ModifyHonorPoints", &LuaUnit::ModifyHonorPoints},             // :ModifyHonorPoints(amount) -- Modifies the player's honor points.
    {"ModifyArenaPoints", &LuaUnit::ModifyArenaPoints},             // :ModifyArenaPoints(amount) -- Modifies the player's arena points.
    {"LeaveBattleground", &LuaUnit::LeaveBattleground},             // :LeaveBattleground([teleToEntryPoint]) -- The player leaves the battleground.
    {"BindToInstance", &LuaUnit::BindToInstance},                   // :BindToInstance() -- Binds the player to the current instance.
    {"UnbindInstance", &LuaUnit::UnbindInstance},                   // :UnbindInstance(map, difficulty) -- Unbinds the player from an instance.
    {"RemoveFromBattlegroundOrBattlefieldRaid", &LuaUnit::RemoveFromBattlegroundOrBattlefieldRaid}, // :RemoveFromBattlegroundOrBattlefieldRaid() -- Removes the player from a battleground or battlefield raid.
    {"ResetAchievements", &LuaUnit::ResetAchievements},             // :ResetAchievements() -- Resets playeräs achievements.
    {"KickPlayer", &LuaUnit::KickPlayer},                           // :KickPlayer() -- Kicks player from server.
    {"LogoutPlayer", &LuaUnit::LogoutPlayer},                       // :LogoutPlayer(save) -- Logs the player out and saves if true.
    {"SendTrainerList", &LuaUnit::SendTrainerList},                 // :SendTrainerList(WorldObject) -- Sends trainer list from object to player.
    {"SendListInventory", &LuaUnit::SendListInventory},             // :SendListInventory(WorldObject) -- Sends vendor list from object to player.
    {"SendShowBank", &LuaUnit::SendShowBank},                       // :SendShowBank(WorldObject) -- Sends bank window from object to player.
    {"SendTabardVendorActivate", &LuaUnit::SendTabardVendorActivate},   // :SendTabardVendorActivate(WorldObject) -- Sends tabard vendor window from object to player.
    {"SendSpiritResurrect", &LuaUnit::SendSpiritResurrect},         // :SendSpiritResurrect() -- Sends resurrect window to player.
    {"SendTaxiMenu", &LuaUnit::SendTaxiMenu},                       // :SendTaxiMenu(creature) -- Sends flight window to player from creature.
    {"RewardQuest", &LuaUnit::RewardQuest},                         // :RewardQuest(entry) --  Gives quest rewards for the player.
    {"SendAuctionMenu", &LuaUnit::SendAuctionHello},                // :SendAuctionMenu([creature, faction]) --  Sends auction window to player. Auction house is sent by creature if provided. AH entry is searched with faction or creature's faction if provided.
    {"SendMailMenu", &LuaUnit::HandleGetMailList},                  // :SendMailMenu(object) --  Sends mail window to player from gameobject.
    {"StartTaxi", &LuaUnit::StartTaxi},                             // :StartTaxi(pathId) -- player starts the given flight path UNDOCUMENTED


    // Creature methods

    // Getters
    {"GetAITarget", &LuaUnit::GetAITarget},                         // :GetAITarget(type[, playeronly, position, distance, aura]) - Get an unit in threat list
    {"GetAITargets", &LuaUnit::GetAITargets},                       // :GetAITargets() - Get units in threat list
    {"GetAITargetsCount", &LuaUnit::GetAITargetsCount},             // :GetAITargetsCount() - Get threat list size
    {"GetVictim", &LuaUnit::GetVictim},                             // :GetVictim() - Returns creature's current target.
    {"GetNearestTargetInAttackDistance", &LuaUnit::GetNearestTargetInAttackDistance}, // :GetNearestTargetInAttackDistance([radius]) - Returns nearest target in attack distance and within given radius, if set.
    {"GetNearestTarget", &LuaUnit::GetNearestTarget},               // :GetNearestTarget([radius]) - Returns nearest target in sight or given radius.
    {"GetNearestHostileTargetInAggroRange", &LuaUnit::GetNearestHostileUnitInAggroRange}, // :GetNearestHostileTargetInAggroRange([checkLOS]) - Returns closest hostile target in aggro range of the creature.
    {"GetHomePosition", &LuaUnit::GetHomePosition},                 // :GetHomePosition() - Returns x,y,z,o of spawn position.
    {"GetTransportHomePosition", &LuaUnit::GetTransportHomePosition},   // :GetTransportHomePosition() - Returns x,y,z,o of transport spawn position.
    {"GetCorpseDelay", &LuaUnit::GetCorpseDelay},                   // :GetCorpseDelay() - Returns corpse delay.
    {"GetCreatureSpellCooldownDelay", &LuaUnit::GetCreatureSpellCooldownDelay}, // :GetCreatureSpellCooldownDelay(spellId) - Returns spell cooldown delay.
    {"GetScriptId", &LuaUnit::GetScriptId},                         // :GetScriptId() - Returns creature's script ID.
    {"GetAIName", &LuaUnit::GetAIName},                             // :GetAIName() - Returns creature's AI name.
    {"GetScriptName", &LuaUnit::GetScriptName},                     // :GetScriptName() - Returns creature's script name.
    {"GetReactState", &LuaUnit::GetReactState},                     // :GetReactState() - Returns creature's react state.
    {"GetAttackDistance", &LuaUnit::GetAttackDistance},             // :GetAttackDistance(unit) - Returns attack distance to unit.
    {"GetAggroRange", &LuaUnit::GetAggroRange},                     // :GetAggroRange(unit) - Returns aggro distance to unit.
    {"GetDefaultMovementType", &LuaUnit::GetDefaultMovementType},   // :GetDefaultMovementType() - Returns default movement type.
    {"GetRespawnDelay", &LuaUnit::GetRespawnDelay},                 // :GetRespawnDelay() - Returns respawn delay.
    {"GetRespawnRadius", &LuaUnit::GetRespawnRadius},               // :GetRespawnRadius() - Returns respawn radius.
    {"GetWaypointPath", &LuaUnit::GetWaypointPath},                 // :GetWaypointPath() - Returns waypoint path ID.
    {"GetCurrentWaypointId", &LuaUnit::GetCurrentWaypointId},       // :GetCurrentWaypointId() - Returns waypoint ID.

    // Setters
    {"SetHover", &LuaUnit::SetHover},                               // :SetHover([enable]) -- Sets hover on or off.
    {"SetDisableGravity", &LuaUnit::SetDisableGravity},             // :SetDisableGravity(disable[, packetOnly]) -- Disables or enables gravity.
    {"SetReactState", &LuaUnit::SetReactState},                     // :SetReactState(state) -- Sets react state.
    {"SetDeathState", &LuaUnit::setDeathState},                     // :SetDeathState(state) -- Sets death state.
    {"SetNoCallAssistance", &LuaUnit::SetNoCallAssistance},         // :SetNoCallAssistance([noCall]) -- Sets call assistance to false or true.
    {"SetNoSearchAssistance", &LuaUnit::SetNoSearchAssistance},     // :SetNoSearchAssistance([noSearch]) -- Sets assistance searhing to false or true.
    {"SetDefaultMovementType", &LuaUnit::SetDefaultMovementType},   // :SetDefaultMovementType(type) -- Sets default movement type.
    {"SetRespawnDelay", &LuaUnit::SetRespawnDelay},                 // :SetRespawnDelay(delay) -- Sets the respawn delay.
    {"SetRespawnRadius", &LuaUnit::SetRespawnRadius},               // :SetRespawnRadius(dist) -- Sets the respawn radius.
    {"SetInCombatWithZone", &LuaUnit::SetInCombatWithZone},         // :SetInCombatWithZone() -- Sets the creature in combat with everyone in zone.
    {"SetDisableReputationGain", &LuaUnit::SetDisableReputationGain},   // :SetDisableReputationGain(disable) -- Disables or enables reputation gain from creature.

    // Booleans
    {"IsWorldBoss", &LuaUnit::IsWorldBoss},                         // :IsWorldBoss() -- Returns true if the creature is a WorldBoss, false if not.
    {"IsDungeonBoss", &LuaUnit::IsDungeonBoss},                     // :IsDungeonBoss() -- Returns true if the creature is a DungeonBoss, false if not.
    {"IsRacialLeader", &LuaUnit::isRacialLeader},                   // :IsRacialLeader() -- Returns true if the creature is a racial leader, false if not.
    {"IsCivilian", &LuaUnit::isCivilian},                           // :IsCivilian() -- Returns true if the creature is a civilian, false if not.
    {"IsTrigger", &LuaUnit::isTrigger},                             // :IsTrigger() -- Returns true if the creature is a trigger, false if not.
    {"IsGuard", &LuaUnit::isGuard},                                 // :IsGuard() -- Returns true if the creature is a guard, false if not.
    {"IsElite", &LuaUnit::isElite},                                 // :IsElite() -- Returns true if the creature is an elite, false if not.
    {"IsInEvadeMode", &LuaUnit::IsInEvadeMode},                     // :IsInEvadeMode() -- Returns true if the creature is in evade mode, false if not.
    {"HasCategoryCooldown", &LuaUnit::HasCategoryCooldown},         // :HasCategoryCooldown(spellId) -- Returns true if the creature has a cooldown for the spell's category.
    {"CanWalk", &LuaUnit::canWalk},                                 // :CanWalk() -- Returns true if the creature can walk.
    {"CanSwim", &LuaUnit::canSwim},                                 // :CanSwim() -- Returns true if the creature can swim.
    {"HasReactState", &LuaUnit::HasReactState},                     // :HasReactState(state) -- Returns true if the creature has react state.
    {"CanStartAttack", &LuaUnit::canStartAttack},                   // :CanStartAttack(unit, force) -- Returns true if the creature can attack the unit.
    {"HasSearchedAssistance", &LuaUnit::HasSearchedAssistance},     // :HasSearchedAssistance() -- Returns true if the creature has searched assistance.
    {"CanAssistTo", &LuaUnit::CanAssistTo},                         // :CanAssistTo(unit, enemy[, checkfaction]) -- Returns true if the creature can assist unit with enemy.
    {"IsTargetAcceptable", &LuaUnit::_IsTargetAcceptable},          // :IsTargetAcceptable(unit) -- Returns true if the creature can target unit.
    {"HasInvolvedQuest", &LuaUnit::hasInvolvedQuest},               // :HasInvolvedQuest(questId) -- Returns true if the creature can finish the quest for players.
    {"IsRegeneratingHealth", &LuaUnit::isRegeneratingHealth},       // :IsRegeneratingHealth() -- Returns true if the creature is regenerating health.
    {"IsReputationGainDisabled", &LuaUnit::IsReputationGainDisabled},   // :IsReputationGainDisabled() -- Returns true if the creature has reputation gain disabled.
    {"IsDamageEnoughForLootingAndReward", &LuaUnit::IsDamageEnoughForLootingAndReward}, // :IsDamageEnoughForLootingAndReward() --

    // Other
    {"RegisterEvent", &LuaUnit::RegisterEvent},                     // :RegisterEvent(function, delay, calls)
    {"RemoveEventById", &LuaUnit::RemoveEventById},                 // :RemoveEventById(eventID)
    {"RemoveEvents", &LuaUnit::RemoveEvents},                       // :RemoveEvents()
    {"Despawn", &LuaUnit::Despawn},                                 // :Despawn([despawnDelay]) - Creature despawns after given time
    {"FleeToGetAssistance", &LuaUnit::DoFleeToGetAssistance},       // :FleeToGetAssistance() - Creature flees for assistance
    {"CallForHelp", &LuaUnit::CallForHelp},                         // :CallForHelp(radius) - Creature calls for help from units in radius
    {"CallAssistance", &LuaUnit::CallAssistance},                   // :CallAssistance() - Creature calls for assistance
    {"RemoveCorpse", &LuaUnit::RemoveCorpse},                       // :RemoveCorpse([setSpawnTime]) - Removes corpse
    {"DespawnOrUnsummon", &LuaUnit::DespawnOrUnsummon},             // :DespawnOrUnsummon([Delay]) - Despawns the creature after delay if given
    {"Respawn", &LuaUnit::Respawn},                                 // :Respawn([force]) -- Respawns the creature.
    {"SelectVictim", &LuaUnit::SelectVictim},                       // :SelectVictim() - Returns a victim or nil.

    // Unit Methods

    // Getters
    {"GetName", &LuaUnit::GetName},                                 // :GetName()
    {"GetLevel", &LuaUnit::GetLevel},                               // :GetLevel()
    {"GetHealth", &LuaUnit::GetHealth},                             // :GetHealth()
    {"GetDisplayId", &LuaUnit::GetDisplayId},                       // :GetDisplayId()
    {"GetNativeDisplayId", &LuaUnit::GetNativeDisplayId},           // :GetNativeDisplayId()
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
    {"GetCurrentSpell", &LuaUnit::GetCurrentSpell},                 // :GetCurrentSpell(type) -- Returns the currently casted spell of given type if any
    {"GetCreatureType", &LuaUnit::GetCreatureType},                 // :GetCreatureType() -- Returns the unit's type
    {"GetNearbyTarget", &LuaUnit::GetNearbyTarget},                 // :GetNearbyTarget([radius[, exclude]]) - Returns nearby target within sight or given radius. Excludes current target and given unit.
    {"GetShieldBlockValue", &LuaUnit::GetShieldBlockValue},         // :GetShieldBlockValue() - Returns block value.
    {"GetMountId", &LuaUnit::GetMountId},                           // :GetMountId() -- UNDOCUMENTED
    {"GetScale", &LuaUnit::GetScale},                               // :GetScale() - UNDOCUMENTED
    {"GetDistance", &LuaUnit::GetDistance},                         // :GetDistance(WorldObject or x, y, z) -- UNDOCUMENTED
    {"GetGUIDLow", &LuaUnit::GetGUIDLow},                           // :GetGUIDLow() -- Returns uint32 guid (low guid) that is used in database. UNDOCUMENTED
    {"GetNearestPlayer", &LuaUnit::GetNearestPlayer},               // :GetNearestPlayer([radius]) - Returns nearest player in sight or given radius. UNDOCUMENTED
    {"GetNearestGameObject", &LuaUnit::GetNearestGameObject},       // :GetNearestGameObject([entry, radius]) - Returns nearest gameobject with given entry in sight or given radius. UNDOCUMENTED
    {"GetNearestCreature", &LuaUnit::GetNearestCreature},           // :GetNearestCreatureEntry([entry, radius]) - Returns nearest creature with given entry in sight or given radius. UNDOCUMENTED

    // Setters
    {"SetFaction", &LuaUnit::SetFaction},                           // :SetFaction(factionId) -- Sets the unit's faction
    {"SetLevel", &LuaUnit::SetLevel},                               // :SetLevel(amount)
    {"SetHealth", &LuaUnit::SetHealth},                             // :SetHealth(amount)
    {"SetMaxHealth", &LuaUnit::SetMaxHealth},                       // :SetMaxHealth(amount)
    {"SetPower", &LuaUnit::SetPower},                               // :SetPower(index, amount)
    {"SetMaxPower", &LuaUnit::SetMaxPower},                         // :SetMaxPower(index, amount)
    {"SetDisplayId", &LuaUnit::SetDisplayId},                       // :SetDisplayId(id)
    {"SetNativeDisplayId", &LuaUnit::SetNativeDisplayId},           // :SetNativeDisplayId(id)
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
    {"SetWalk", &LuaUnit::SetWalk},                                 // :SetWalk([enable]) - If false, creature runs, otherwise walks
    {"SetSpeed", &LuaUnit::SetSpeed},                               // :SetSpeed(type, speed[, forced]) - Sets speed for the movement type (0 = walk, 1 = run ..)
    {"SetStunned", &LuaUnit::SetStunned},                           // :SetStunned([enable]) - Stuns or removes stun
    {"SetRooted", &LuaUnit::SetRooted},                             // :SetRooted([enable]) - Roots or removes root
    {"SetConfused", &LuaUnit::SetConfused},                         // :SetConfused([enable]) - Sets confused or removes confusion
    {"SetFeared", &LuaUnit::SetFeared},                             // :SetFeared([enable]) - Fears or removes fear
    {"SetGender", &LuaUnit::SetGender},                             // :SetGender(value) -- 0 = male 1 = female
    {"SetPvP", &LuaUnit::SetPvP},                                   // :SetPvP([apply]) -- Sets the units PvP on or off.
    {"SetFFA", &LuaUnit::SetFFA},                                   // :SetFFA([apply]) -- Sets the units FFA tag on or off.
    {"SetSanctuary", &LuaUnit::SetSanctuary},                       // :SetSanctuary([apply]) -- Enables or disables units sanctuary flag.
    {"SetScale", &LuaUnit::SetScale},                               // :SetScale(scale) - UNDOCUMENTED

    // Boolean
    {"IsAlive", &LuaUnit::IsAlive},                                 // :IsAlive()
    {"IsDead", &LuaUnit::IsDead},                                   // :IsDead() -- Returns true if the unit is dead, false if they are alive
    {"IsDying", &LuaUnit::IsDying},                                 // :IsDying() -- Returns true if the unit death state is JUST_DIED. UNDOCUMENTED
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
    {"IsInWater", &LuaUnit::IsInWater},                             // :IsInWater() -- Returns true if the unit is in water.
    {"IsUnderWater", &LuaUnit::IsUnderWater},                       // :IsUnderWater() -- Returns true if the unit is under water.
    {"HasAura", &LuaUnit::HasAura},                                 // :HasAura(spellId[, caster]) -- Returns true if the unit has the aura from the spell and casted by the caster if provided.
    {"CanFly", &LuaUnit::CanFly},                                   // :CanFly() -- Returns true if the unit can fly.
    {"HasSpellCooldown", &LuaUnit::HasSpellCooldown},               // :HasSpellCooldown(spellId) -- Returns true if the spell is on cooldown.
    {"IsAuctioneer", &LuaUnit::IsAuctioneer},                       // :IsAuctioneer() -- UNDOCUMENTED
    {"HealthBelowPct", &LuaUnit::HealthBelowPct},                   // :HealthBelowPct(int32 pct) -- UNDOCUMENTED
    {"HealthAbovePct", &LuaUnit::HealthAbovePct},                   // :HealthAbovePct(int32 pct) -- UNDOCUMENTED

    // Other
    {"AddAura", &LuaUnit::AddAura},                                 // :AddAura(spellId, target) -- Adds an aura to the specified target
    {"RemoveAura", &LuaUnit::RemoveAura},                           // :RemoveAura(spellId[, casterGUID]) -- Removes an aura from the unit by the spellId, casterGUID(Original caster) is optional.
    {"RemoveAllAuras", &LuaUnit::RemoveAllAuras},                   // :RemoveAllAuras() -- Removes all the unit's auras
    {"ClearInCombat", &LuaUnit::ClearInCombat},                     // :ClearInCombat() -- Clears the unit's combat list (unit will be out of combat), resets the timer to 0, etc.
    {"DeMorph", &LuaUnit::DeMorph},                                 // :DeMorph() - Sets display back to native.
    {"SendUnitWhisper", &LuaUnit::SendUnitWhisper},                 // :SendUnitWhisper(msg, receiver[, bossWhisper]) -- Sends a whisper to the receiver
    {"SendUnitEmote", &LuaUnit::SendUnitEmote},                     // :SendUnitEmote(msg[, receiver, bossEmote]) -- Sends a text emote
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
    {"SummonGameObject", &LuaUnit::SummonGameObject},               // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil
    {"SpawnCreature", &LuaUnit::SpawnCreature},                     // :SpawnCreature(entry, x, y, z, o[, despawnDelay]) - Spawns a creature to location that despawns after given time (0 for infinite). Returns the creature or nil
    {"StopSpellCast", &LuaUnit::StopSpellCast},                     // :StopSpellCast(spellId(optional)) -- Stops the unit from casting a spell. If a spellId is defined, it will stop that unit from casting that spell
    {"InterruptSpell", &LuaUnit::InterruptSpell},                   // :InterruptSpell(spellType, delayed(optional), instant(optional)) -- Interrupts the unit's spell by the spellType. If delayed is true it will skip if the spell is delayed. If instant is true, it will skip that the spell has a cast time.
    {"SendChatMessageToPlayer", &LuaUnit::SendChatMessageToPlayer}, // :SendChatMessageToPlayer(type, lang, msg, target) -- Unit sends a chat message to the given target player
    {"SaveToDB", &LuaUnit::SaveToDB},                               // :SaveToDB() -- Saves the unit to database.
    {"Emote", &LuaUnit::Emote},                                     // :Emote(emote) -- UNDOCUMENTED
    {"CountPctFromCurHealth", &LuaUnit::CountPctFromCurHealth},     // :CountPctFromCurHealth(int32 pct) -- UNDOCUMENTED
    {"CountPctFromMaxHealth", &LuaUnit::CountPctFromMaxHealth},     // :CountPctFromMaxHealth() -- UNDOCUMENTED

    /* Vehicle */
    {"AddVehiclePassenger", &LuaUnit::AddVehiclePassenger},         // :AddVehiclePassenger(unit, seatId) - Adds a passenger to the vehicle by specifying a unit and seatId
    {"IsOnVehicle", &LuaUnit::IsOnVehicle},                         // :IsOnVehicle() - Checks if the (unit) is in a vehicle
    {"DismissVehicle", &LuaUnit::DismissVehicle},                   // :DismissVehicle() - Dismisses the (unit)'s vehicle (Unmounts)
    //{"EjectPassenger", &LuaUnit::EjectPassenger},                 // :EjectPassenger(unit) - Ejects a specified unit out of the vehicle   (UNTESTED)
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
    {"GetUnitType", &LuaGameObject::GetUnitType},                   // :GetUnitType() - Returns unit type Ex. GameObject
    {"GetGUID", &LuaGameObject::GetGUID},                           // :GetGUID() - returns object guid (string)
    {"GetName", &LuaGameObject::GetName},                           // :GetName() -
    {"GetDisplayId", &LuaGameObject::GetDisplayId},                 // :GetDisplayId() -
    {"GetScale", &LuaGameObject::GetScale},                         // :GetScale() -
    {"GetEntry", &LuaGameObject::GetEntry},                         // :GetEntry() -
    {"GetMapId", &LuaGameObject::GetMapId},                         // :GetMapId() -
    {"GetX", &LuaGameObject::GetX},                                 // :GetX() -
    {"GetY", &LuaGameObject::GetY},                                 // :GetY() -
    {"GetZ", &LuaGameObject::GetZ},                                 // :GetZ() -
    {"GetO", &LuaGameObject::GetO},                                 // :GetO() -
    {"GetLocation", &LuaGameObject::GetLocation},                   // :GetLocation() - returns X, Y, Z and O co-ords (in that order) -
    {"GetAreaId", &LuaGameObject::GetAreaId},                       // :GetAreaId() -
    {"GetZoneId", &LuaGameObject::GetZoneId},                       // :GetZoneId() -
    {"GetInt32Value", &LuaGameObject::GetInt32Value},               // :GetInt32Value(index) - returns an int value from object fields
    {"GetUInt32Value", &LuaGameObject::GetUInt32Value},             // :GetUInt32Value(index) - returns an uint value from object fields
    {"GetFloatValue", &LuaGameObject::GetFloatValue},               // :GetFloatValue(index) - returns a float value from object fields
    {"GetByteValue", &LuaGameObject::GetByteValue},                 // :GetByteValue(index, offset) - returns a byte value from object fields
    {"GetUInt16Value", &LuaGameObject::GetUInt16Value},             // :GetUInt16Value(index, offset) - returns a uint16 value from object fields
    {"GetGUIDLow", &LuaGameObject::GetGUIDLow},                     // :GetGUIDLow() -- Returns uint32 guid (low guid) that is used in database. UNDOCUMENTED
    {"GetNearestPlayer", &LuaGameObject::GetNearestPlayer},               // :GetNearestPlayer([radius]) - Returns nearest player in sight or given radius. UNDOCUMENTED
    {"GetNearestGameObject", &LuaGameObject::GetNearestGameObject},       // :GetNearestGameObject([entry, radius]) - Returns nearest gameobject with given entry in sight or given radius. UNDOCUMENTED
    {"GetNearestCreature", &LuaGameObject::GetNearestCreature},           // :GetNearestCreatureEntry([entry, radius]) - Returns nearest creature with given entry in sight or given radius. UNDOCUMENTED

    // Setters
    {"SetScale", &LuaGameObject::SetScale},                         // :SetScale(scale) -
    {"SetInt32Value", &LuaGameObject::SetInt32Value},               // :SetInt32Value(index, value) - Sets an int value for the object
    {"SetUInt32Value", &LuaGameObject::SetUInt32Value},             // :SetUInt32Value(index, value) - Sets an uint value for the object
    {"UpdateUInt32Value", &LuaGameObject::UpdateUInt32Value},       // :UpdateUInt32Value(index, value) - Updates an uint value for the object
    {"SetFloatValue", &LuaGameObject::SetFloatValue},               // :SetFloatValue(index, value) - Sets a float value for the object
    {"SetByteValue", &LuaGameObject::SetByteValue},                 // :SetByteValue(index, offset, value) - Sets a byte value for the object
    {"SetUInt16Value", &LuaGameObject::SetUInt16Value},             // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the object
    {"SetInt16Value", &LuaGameObject::SetInt16Value},               // :SetInt16Value(index, offset, value) - Sets an int16 value for the object

    // Boolean
    {"IsInWorld", &LuaGameObject::IsInWorld},                       // :IsInWorld() -
    {"IsTransport", &LuaGameObject::IsTransport},                   // :IsTransport() -
    {"IsDestructible", &LuaGameObject::IsDestructible},             // :IsDestructible() -
    {"IsActive", &LuaGameObject::IsActive},                         // :IsActive() -
    {"HasQuest", &LuaGameObject::HasQuest},                         // :HasQuest(questId) -
    {"IsInvisibleDueToDespawn", &LuaGameObject::IsInvisibleDueToDespawn}, // :IsInvisibleDueToDespawn() - UNDOCUMENTED

    // Other
    {"CastSpellOnTarget", &LuaGameObject::CastSpellOnTarget},       // :CastSpellOnTarget(target, spellId) - Casts the spell on target, no manacost or cast time -
    {"Move", &LuaGameObject::Move},                                 // :Move(x, y, z, o) - Moves the GO to coordinates -
    {"SpawnCreature", &LuaGameObject::SummonCreature},              // :SummonCreature(entry, x, y, z, o, despawntime) Summons a temporary creature. 0 for infinitely, otherwise despawns after despawntime (ms) -
    {"RegisterEvent", &LuaGameObject::RegisterEvent},               // :RegisterEvent(function, delay, calls) -
    {"RemoveEventById", &LuaGameObject::RemoveEventById},           // :RemoveEventById(eventID) -
    {"RemoveEvents", &LuaGameObject::RemoveEvents},                 // :RemoveEvents() -
    {"Despawn", &LuaGameObject::Despawn},                           // :Despawn() - Object despawns
    {"SummonGameObject", &LuaGameObject::SummonGameObject},         // :SummonGameObject(entry, x, y, z, o[, respawnDelay]) - Spawns an object to location. Returns the object or nil

    { NULL, NULL },
};

ElunaRegister<Item> ItemMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaItem::GetUnitType},                                 // :GetUnitType() - Returns object type, IE: Item, Creature
    {"GetGUID", &LuaItem::GetGUID},                                         // :GetGUID() - Returns object guid (string)
    {"GetOwnerGUID", &LuaItem::GetOwnerGUID},                               // :GetOwnerGUID() - Returns the owner's guid
    {"GetOwner", &LuaItem::GetOwner},                                       // :GetOwner() - Returns the owner object (player)
    {"GetCount", &LuaItem::GetCount},                                       // :GetCount() - Returns item stack count
    {"GetMaxStackCount", &LuaItem::GetMaxStackCount},                       // :GetMaxStackCount() - Returns item max stack count
    {"GetSlot", &LuaItem::GetSlot},                                         // :GetSlot() - returns the slot the item is in
    {"GetBagSlot", &LuaItem::GetBagSlot},                                   // :GetBagSlot() - returns the bagslot of the bag the item is in
    {"GetEntry", &LuaItem::GetEntry},                                       // :GetEntry() - returns the item entry
    {"GetInt32Value", &LuaItem::GetInt32Value},                             // :GetInt32Value(index) - returns an int value from item fields
    {"GetUInt32Value", &LuaItem::GetUInt32Value},                           // :GetUInt32Value(index) - returns an uint value from item fields
    {"GetFloatValue", &LuaItem::GetFloatValue},                             // :GetFloatValue(index) - returns a float value from item fields
    {"GetByteValue", &LuaItem::GetByteValue},                               // :GetByteValue(index, offset) - returns a byte value from item fields
    {"GetUInt16Value", &LuaItem::GetUInt16Value},                           // :GetUInt16Value(index, offset) - returns a uint16 value from item fields
    {"GetGUIDLow", &LuaItem::GetGUIDLow},                                   // :GetGUIDLow() -- Returns uint32 guid (low guid) that is used in database. UNDOCUMENTED
    {"GetEnchantmentId", &LuaItem::GetEnchantmentId},                       // :GetEnchantmentId(enchant_slot) -- Returns the enchantment in given slot. (permanent = 0) UNDOCUMENTED
    {"GetName", &LuaItem::GetName},                                         // :GetName() -- Returns item name UNDOCUMENTED

    // Setters
    {"SetOwner", &LuaItem::SetOwner},                                       // :SetOwner(player) - Sets the owner of the item
    {"SetBinding", &LuaItem::SetBinding},                                   // :SetBinding(bound) - Sets the item binding to true or false
    {"SetCount", &LuaItem::SetCount},                                       // :SetCount(count) - Sets the item count
    {"SetInt32Value", &LuaItem::SetInt32Value},                             // :SetInt32Value(index, value) - Sets an int value for the item
    {"SetUInt32Value", &LuaItem::SetUInt32Value},                           // :SetUInt32Value(index, value) - Sets an uint value for the item
    {"UpdateUInt32Value", &LuaItem::UpdateUInt32Value},                     // :UpdateUInt32Value(index, value) - Updates an uint value for the item
    {"SetFloatValue", &LuaItem::SetFloatValue},                             // :SetFloatValue(index, value) - Sets a float value for the item
    {"SetByteValue", &LuaItem::SetByteValue},                               // :SetByteValue(index, offset, value) - Sets a byte value for the item
    {"SetUInt16Value", &LuaItem::SetUInt16Value},                           // :SetUInt16Value(index, offset, value) - Sets an uint16 value for the item
    {"SetInt16Value", &LuaItem::SetInt16Value},                             // :SetInt16Value(index, offset, value) - Sets an int16 value for the item

    // Boolean
    {"IsSoulBound", &LuaItem::IsSoulBound},                                 // :IsSoulBound() - Returns true if the item is soulbound
    {"IsBoundAccountWide", &LuaItem::IsBoundAccountWide},                   // :IsBoundAccountWide() - Returns true if the item is account bound
    {"IsBoundByEnchant", &LuaItem::IsBoundByEnchant},                       // :IsBoundByEnchant() - Returns true if the item is bound with an enchant
    {"IsNotBoundToPlayer", &LuaItem::IsNotBoundToPlayer},                   // :IsNotBoundToPlayer(player) - Returns true if the item is not bound with player
    {"IsLocked", &LuaItem::IsLocked},                                       // :IsLocked() - Returns true if the item is locked
    {"IsBag", &LuaItem::IsBag},                                             // :IsBag() - Returns true if the item is a bag
    {"IsCurrencyToken", &LuaItem::IsCurrencyToken},                         // :IsCurrencyToken() - Returns true if the item is a currency token
    {"IsNotEmptyBag", &LuaItem::IsNotEmptyBag},                             // :IsNotEmptyBag() - Returns true if the item is not an empty bag
    {"IsBroken", &LuaItem::IsBroken},                                       // :IsBroken() - Returns true if the item is broken
    {"CanBeTraded", &LuaItem::CanBeTraded},                                 // :CanBeTraded() - Returns true if the item can be traded
    {"IsInTrade", &LuaItem::IsInTrade},                                     // :IsInTrade() - Returns true if the item is in trade
    {"IsInBag", &LuaItem::IsInBag},                                         // :IsInBag() - Returns true if the item is in a bag
    {"IsEquipped", &LuaItem::IsEquipped},                                   // :IsEquipped() - Returns true if the item is equipped
    {"hasQuest", &LuaItem::hasQuest},                                       // :hasQuest(questId) - Returns true if the item starts the quest
    {"IsPotion", &LuaItem::IsPotion},                                       // :IsPotion() - Returns true if the item is a potion
    {"IsWeaponVellum", &LuaItem::IsWeaponVellum},                           // :IsWeaponVellum() - Returns true if the item is a weapon vellum
    {"IsArmorVellum", &LuaItem::IsArmorVellum},                             // :IsArmorVellum() - Returns true if the item is an armor vellum
    {"IsConjuredConsumable", &LuaItem::IsConjuredConsumable},               // :IsConjuredConsumable() - Returns true if the item is a conjured consumable
    {"IsRefundExpired", &LuaItem::IsRefundExpired},                         // :IsRefundExpired() - Returns true if the item's refund time has expired
    {"SetEnchantment", &LuaItem::SetEnchantment},                           // :SetEnchantment(enchantid) - Sets a new enchantment for the item. Returns true on success.
    {"ClearEnchantment", &LuaItem::ClearEnchantment},                       // :ClearEnchantment() - Removes the enchantment from the item if one exists. Returns true on success.

    // Other

    {NULL, NULL},
};

ElunaRegister<Aura> AuraMethods[] = 
{
    // Getters
    {"GetUnitType", &LuaAura::GetUnitType},                         // :GetUnitType() - Returns object type, IE: Aura, Creature 
    {"GetCaster", &LuaAura::GetCaster},                             // :GetCaster() - Returns caster as object.                    
    {"GetCasterGUID", &LuaAura::GetCasterGUID},                     // :GetCasterGUID() - Returns caster as GUID.                
    {"GetCasterLevel", &LuaAura::GetCasterLevel},                   // :GetCasterLevel() - Returns casters level.                
    {"GetDuration", &LuaAura::GetDuration},                         // :GetDuration() - Returns remaining duration.                
    {"GetMaxDuration", &LuaAura::GetMaxDuration},                   // :GetMaxDuration() - Returns maximum duration.            
    {"GetCharges", &LuaAura::GetCharges},                           // :GetCharges() - Returns remaining charges.               
    {"GetAuraId", &LuaAura::GetAuraId},                             // :GetAuraId() - Returns aura ID.                            
    {"GetStackAmount", &LuaAura::GetStackAmount},                   // :GetStackAmount() - Returns current stack amount.        
    {"GetOwner", &LuaAura::GetOwner},                               // :GetOwner() - Gets the unit wearing the aura          

    // Setters
    {"SetDuration", &LuaAura::SetDuration},                         // :SetDuration(duration) - Sets remaining duration.        
    {"SetMaxDuration", &LuaAura::SetMaxDuration},                   // :SetMaxDuration(duration) - Sets maximum duration.       
    {"SetStackAmount", &LuaAura::SetStackAmount},                   // :SetStackAmount(amount) - Sets current stack amount.     

    // Other
    {"Remove", &LuaAura::Remove},                                   // :Remove() - Removes the aura.                            

    {NULL, NULL},
};

ElunaRegister<Spell> SpellMethods[] =
{
    // Getters
    {"GetUnitType", &LuaSpell::GetUnitType},                        // :GetUnitType() -- Returns the unit type (Spell)             
    {"GetCaster", &LuaSpell::GetCaster},                            // :GetCaster()  -- Returns the spell's caster (UNIT)          
    {"GetCastTime", &LuaSpell::GetCastTime},                        // :GetCastTime() -- Returns the spell cast time               
    {"GetEntry", &LuaSpell::GetId},                                 // :GetEntry() -- Returns the spell's ID                       
    {"GetDuration", &LuaSpell::GetDuration},                        // :GetDuration() -- Returns the spell's duration              
    {"GetPowerCost", &LuaSpell::GetPowerCost},                      // :GetPowerCost() -- Returns the spell's power cost (mana, energy, rage, etc)     

    //Setters
    {"SetAutoRepeat", &LuaSpell::SetAutoRepeat},                    // :SetAutoRepeat(boolean) -- UNDOCUMENTED

    //Boolean
    {"IsAutoRepeat", &LuaSpell::IsAutoRepeat},                      // :IsAutoRepeat() -- UNDOCUMENTED

    // Other
    {"Cancel", &LuaSpell::cancel},                                  // :Cancel() -- Cancels the spell casting                      
    {"Cast", &LuaSpell::Cast},                                      // :Cast(skipCheck) -- Casts the spell (if true, removes the check for instant spells, etc)     
    {"Finish", &LuaSpell::Finish},                                  // :Finish() -- Finishes the spell (SPELL_STATE_FINISH)        

    {NULL, NULL},
};

ElunaRegister<Quest> QuestMethods[] =
{
    // Getters
    {"GetUnitType", &LuaQuest::GetUnitType},                        // :GetUnitType() -- Returns the unit type (Quest)             
    {"GetId", &LuaQuest::GetId},                                    // :GetId() -- Returns the quest's Id                          
    {"GetLevel", &LuaQuest::GetLevel},                              // :GetLevel() -- Returns the quest's level                    
    {"GetMaxLevel", &LuaQuest::GetMaxLevel},                        // :GetMaxLevel() -- Returns the quest's max level             
    {"GetMinLevel", &LuaQuest::GetMinLevel},                        // :GetMinLevel() -- Returns the quest's min level             
    {"GetNextQuestId", &LuaQuest::GetNextQuestId},                  // :GetNextQuestId() -- Returns the quest's next quest ID      
    {"GetPrevQuestId", &LuaQuest::GetPrevQuestId},                  // :GetPrevQuestId() -- Returns the quest's previous quest ID  
    {"GetNextQuestInChain", &LuaQuest::GetNextQuestInChain},        // :GetNexQuestInChain() -- Returns the next quest in its chain 
    {"GetFlags", &LuaQuest::GetFlags},                              // :GetFlags() -- Returns the quest's flags                    
    {"GetType", &LuaQuest::GetType},                                // :GetType() -- Returns the quest's type                      

    // Boolean
    {"HasFlag", &LuaQuest::HasFlag},                                // :HasFlag(flag) -- Returns true or false if the quest has the specified flag   
    {"IsDaily", &LuaQuest::IsDaily},                                // :IsDaily() -- Returns true or false if the quest is a daily 
    {"IsRepeatable", &LuaQuest::IsRepeatable},                      // :IsRepeatable() -- Returns true or false if the quest is repeatable  

    // Setters
    {"SetFlag", &LuaQuest::SetFlag},                                // :SetFlag(flag) -- Sets the flag of the quest by the specified flag   

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
    {"GetMemberGroup", &LuaGroup::GetMemberGroup},                  // :GetMemberGroup(player) - Returns the player's subgroup ID
    {"GetMemberGUID", &LuaGroup::GetMemberGUID},                    // :GetMemberGUID("name") - Returns the member's GUID
    {"GetMembersCount", &LuaGroup::GetMembersCount},                // :GetMembersCount() - Returns the member count of the group

    // Setters
    {"SetLeader", &LuaGroup::ChangeLeader},                         // :SetLeader(Player) - Sets the player as the new leader.
    {"SetMembersGroup", &LuaGroup::ChangeMembersGroup},             // :ChangeMembersGroup(player, subGroup) - Changes the member's subgroup

    // Boolean
    {"IsLeader", &LuaGroup::IsLeader},                              // :IsLeader("name"/Player)
    //{"HasRole", &LuaGroup::HasRole},                              // :HasRole("name"/Player, "role") - "tank" / "healer" / "dps"
    {"AddInvite", &LuaGroup::AddInvite},                            // :AddInvite(player) - Adds a an invite to player. Returns true if succesful
    {"RemoveMember", &LuaGroup::RemoveMember},                      // :RemoveMember(player) - Removes player from group. Returns true on success
    {"Disband", &LuaGroup::Disband},                                // :Disband() - Disbands the group.
    {"IsFull", &LuaGroup::IsFull},                                  // :IsFull() - Returns true if the group is full
    {"IsLFGGroup", &LuaGroup::isLFGGroup},                          // :IsLFGGroup() - Returns true if the group is an LFG group
    {"IsRaidGroup", &LuaGroup::isRaidGroup},                        // :IsRaidGroup() - Returns true if the group is a raid group
    {"IsBGGroup", &LuaGroup::isBGGroup},                            // :IsBGGroup() - Returns true if the group is a battleground group
    {"IsBFGroup", &LuaGroup::isBFGroup},                            // :IsBFGroup() - Returns true if the group is a battlefield group
    {"IsMember", &LuaGroup::IsMember},                              // :IsMember(player) - Returns true if the player is a member of the group
    {"IsAssistant", &LuaGroup::IsAssistant},                        // :IsAssistant(player) - returns true if the player is an assistant in the group
    {"SameSubGroup", &LuaGroup::SameSubGroup},                      // :SameSubGroup(player1, player2) - Returns true if the players are in the same subgroup in the group
    {"HasFreeSlotSubGroup", &LuaGroup::HasFreeSlotSubGroup},        // :HasFreeSlotSubGroup(subGroup) - Returns true if the subgroupID has free slots

    // Other
    {"SendPacket", &LuaGroup::SendPacket},                          // :SendPacket(packet, sendToPlayersInBattleground[, ignoreguid]) - Sends a specified packet to the group with the choice (true/false) to send it to players in a battleground. Optionally ignores given player guid.
    {"ConvertToLFG", &LuaGroup::ConvertToLFG},                      // :ConvertToLFG() - Converts the group to an LFG group
    {"ConvertToRaid", &LuaGroup::ConvertToRaid},                    // :ConvertToRaid() - Converts the group to a raid group

    {NULL, NULL},
};

ElunaRegister<Guild> GuildMethods[] = 
{
    // Getters
    {"GetMembers", &LuaGuild::GetMembers},                          // :GetMembers() - returns a table containing the players in this guild. (Online?)
    {"GetUnitType", &LuaGuild::GetUnitType},                        // :GetUnitType() - Returns the unit type. Eg: Guild
    {"GetLeaderGUID", &LuaGuild::GetLeaderGUID},                    // :GetLeaderGUID() - Returns the guild learder's guid
    {"GetId", &LuaGuild::GetId},                                    // :GetId() - Gets the guild's ID
    {"GetName", &LuaGuild::GetName},                                // :GetName() - Gets the guild name
    {"GetMOTD", &LuaGuild::GetMOTD},                                // :GetMOTD() - Gets the guild MOTD string
    {"GetInfo", &LuaGuild::GetInfo},                                // :GetInfo() - Gets the guild info string

    // Setters
    {"SetBankTabText", &LuaGuild::SetBankTabText},                  // :SetBankTabText(tabId, text) -
    {"SetMemberRank", &LuaGuild::ChangeMemberRank},                 // :SetMemberRank(player, newRank) - Sets the player rank in the guild to the new rank

    // Boolean

    // Other
    {"SendPacket", &LuaGuild::SendPacket},                          // :SendPacket(packet) - sends packet to guild.
    {"SendPacketToRanked", &LuaGuild::SendPacketToRanked},          // :SendPacketToRanked(packet, rankId) - sends packet to guild, specifying a rankId will only send the packet to your ranked members.
    {"Disband", &LuaGuild::Disband},                                // :Disband() - Disbands the guild
    {"AddMember", &LuaGuild::AddMember},                            // :AddMember(player, rank) - adds the player to the guild. Rank is optional
    {"DeleteMember", &LuaGuild::DeleteMember},                      // :DeleteMember(player, disbanding, kicked) - Deletes the player from the guild. Disbanding and kicked are optional bools.

    {NULL, NULL},
};

ElunaRegister<QueryResult> QueryMethods[] =
{
    {"GetUnitType", &LuaQuery::GetUnitType},                        // :GetUnitType() - Returns object type, IE: QueryResult

    {"NextRow", &LuaQuery::NextRow},                                // :NextRow() - Advances to next rown in the query. Returns true if there is a next row, otherwise false.
    {"GetColumnCount", &LuaQuery::GetColumnCount},                  // :GetColumnCount() - Gets the column count of the query
    {"GetRowCount", &LuaQuery::GetRowCount},                        // :GetRowCount() - Gets the row count of the query

    {"GetBool", &LuaQuery::GetBool},                                // :GetBool(column) -- returns a bool from a number column (for example tinyint)
    {"GetUInt8", &LuaQuery::GetUInt8},                              // :GetUInt8(column) -- returns the value of an unsigned tinyint column
    {"GetUInt16", &LuaQuery::GetUInt16},                            // :GetUInt16(column) -- returns the value of a unsigned smallint column
    {"GetUInt32", &LuaQuery::GetUInt32},                            // :GetUInt32(column) -- returns the value of an unsigned int or mediumint column
    {"GetUInt64", &LuaQuery::GetUInt64},                            // :GetUInt64(column) -- returns the value of an unsigned bigint column as string UNDOCUMENTED
    {"GetInt8", &LuaQuery::GetInt8},                                // :GetInt8(column) -- returns the value of an tinyint column
    {"GetInt16", &LuaQuery::GetInt16},                              // :GetInt16(column) -- returns the value of a smallint column
    {"GetInt32", &LuaQuery::GetInt32},                              // :GetInt32(column) -- returns the value of an int or mediumint column
    {"GetInt64", &LuaQuery::GetInt64},                              // :GetInt64(column) -- returns the value of a bigint column as string UNDOCUMENTED
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
    {"WriteGUID", &LuaPacket::WriteGUID},                           //  :WriteGUID(guid) -- Writes a uint64 guid value.       (UNDOCUMENTED)
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

-- Delete orphaned by missing character's guid
DELETE FROM `arena_team` WHERE `captainGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `arena_team_member` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `auctionhouse` WHERE `itemowner` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `auctionhouse` WHERE `buyguid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `calendar_events` WHERE `creator` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `calendar_invites` WHERE `invitee` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `calendar_invites` WHERE `sender` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_account_data` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_achievement` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_achievement_progress` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_action` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_arena_stats` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_aura` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_aura` WHERE `casterGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_banned` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_battleground_random` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_equipmentsets` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_gifts` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_glyphs` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_homebind` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_instance` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_inventory` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_pet` WHERE `owner` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_pet_declinedname` WHERE `owner` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_pet_declinedname` WHERE `id` NOT IN ( SELECT `id` FROM `character_pet` );
DELETE FROM `character_queststatus` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_queststatus_daily` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_queststatus_monthly` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_queststatus_rewarded` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_queststatus_seasonal` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_queststatus_weekly` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_reputation` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_skills` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_social` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_social` WHERE `friend` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_spell` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_spell_cooldown` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_stats` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `character_talent` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `corpse` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `gm_survey` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `gm_subsurvey` WHERE `surveyId` NOT IN ( SELECT `surveyId` FROM `gm_survey` );
DELETE FROM `gm_ticket` WHERE `playerGuid` NOT IN ( SELECT `guid` FROM `characters` );
UPDATE `gm_ticket` SET `closedBy` = NULL WHERE `closedBy` NOT IN ( SELECT `guid` FROM `characters` );
UPDATE `gm_ticket` SET `assignedTo` = NULL WHERE `assignedTo` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `group_member` WHERE `memberGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `groups` WHERE `leaderGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `groups` WHERE `looterGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `group_instance` WHERE `guid` NOT IN ( SELECT `guid` FROM `groups` );
DELETE FROM `group_member` WHERE `guid` NOT IN ( SELECT `guid` FROM `groups` );
DELETE FROM `guild` WHERE `leaderguid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `guild_bank_eventlog` WHERE `PlayerGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `guild_eventlog` WHERE `playerGuid1` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `guild_eventlog` WHERE `playerGuid2` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `guild_member` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `item_instance` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `item_refund_instance` WHERE `player_guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `lag_reports` WHERE `guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `mail` WHERE `sender` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `mail` WHERE `receiver` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `pet_aura` WHERE `casterGuid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `petition` WHERE `ownerguid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `petition_sign` WHERE `playerguid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `pvpstats_players` WHERE `character_guid` NOT IN ( SELECT `guid` FROM `characters` );
DELETE FROM `quest_tracker` WHERE `character_guid` NOT IN ( SELECT `guid` FROM `characters` );

-- Delete orphaned by missing item_instance's guid
DELETE FROM `auctionhouse` WHERE `itemguid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `character_aura` WHERE `itemGuid` NOT IN ( SELECT `guid` FROM `item_instance` );
-- Partial equipmentsets is allowed, so first I set to NULL invalid data and only delete the ones will ALL NULLs
UPDATE `character_equipmentsets`  SET `item0`=NULL WHERE `item0` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item1`=NULL WHERE `item1` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item2`=NULL WHERE `item2` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item3`=NULL WHERE `item3` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item4`=NULL WHERE `item4` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item5`=NULL WHERE `item5` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item6`=NULL WHERE `item6` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item7`=NULL WHERE `item7` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item8`=NULL WHERE `item8` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item9`=NULL WHERE `item9` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item10`=NULL WHERE `item10` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item11`=NULL WHERE `item11` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item12`=NULL WHERE `item12` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item13`=NULL WHERE `item13` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item14`=NULL WHERE `item14` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item15`=NULL WHERE `item15` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item16`=NULL WHERE `item16` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item17`=NULL WHERE `item17` NOT IN ( SELECT `guid` FROM `item_instance` );
UPDATE `character_equipmentsets`  SET `item18`=NULL WHERE `item18` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `character_equipmentsets` WHERE
`item0` IS NULL
AND `item1` IS NULL 
AND `item2` IS NULL 
AND `item3` IS NULL 
AND `item4` IS NULL 
AND `item5` IS NULL 
AND `item6` IS NULL 
AND `item7` IS NULL 
AND `item8` IS NULL 
AND `item9` IS NULL 
AND `item10` IS NULL 
AND `item11` IS NULL 
AND `item12` IS NULL 
AND `item13` IS NULL 
AND `item14` IS NULL 
AND `item15` IS NULL 
AND `item16` IS NULL 
AND `item17` IS NULL 
AND `item18` IS NULL;
DELETE FROM `character_gifts` WHERE `item_guid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `character_inventory` WHERE `item` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `guild_bank_item` WHERE `item_guid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `item_loot_items` WHERE `container_id` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `item_loot_money` WHERE `container_id` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `item_refund_instance` WHERE `item_guid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `item_soulbound_trade_data` WHERE `itemGuid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `mail_items` WHERE `item_guid` NOT IN ( SELECT `guid` FROM `item_instance` );
DELETE FROM `petition` WHERE `petitionguid` NOT IN ( SELECT `guid` FROM `item_instance` );

-- Delete orphaned by missing instance's guid
DELETE FROM `instance` WHERE (`map`,`difficulty`) NOT IN ( SELECT `mapid`,`difficulty` FROM `instance_reset` );
DELETE FROM `character_instance` WHERE `instance` NOT IN ( SELECT `id` FROM `instance` );
DELETE FROM `group_instance` WHERE `instance` NOT IN ( SELECT `id` FROM `instance` );

-- Delete orphaned by missing guild's guid
DELETE FROM `guild_bank_tab` WHERE `guildid` NOT IN ( SELECT `guildid` FROM `guild` );
DELETE FROM `guild_bank_item` WHERE (`guildid`,`TabId`) NOT IN ( SELECT `guildid`,`TabId` FROM `guild_bank_tab` );
DELETE FROM `guild_rank` WHERE `guildid` NOT IN ( SELECT `guildid` FROM `guild` );
DELETE FROM `guild_bank_right` WHERE (`guildid`,`rid`) NOT IN ( SELECT `guildid`,`rid` FROM `guild_rank` ) OR (`guildid`,`TabId`) NOT IN ( SELECT `guildid`,`TabId` FROM `guild_bank_tab` );
DELETE FROM `guild_eventlog` WHERE `guildid` NOT IN ( SELECT `guildid` FROM `guild` );
DELETE FROM `guild_member` WHERE `guildid` NOT IN ( SELECT `guildid` FROM `guild` );
DELETE FROM `guild_member_withdraw` WHERE `guid` NOT IN ( SELECT `guildid` FROM `guild` );

-- Rest possible orphaned tables
DELETE FROM `mail_items` WHERE `mail_id` NOT IN ( SELECT `id` FROM `mail` );
DELETE FROM `pet_aura` WHERE `guid` NOT IN ( SELECT `id` FROM `character_pet` );
DELETE FROM `pet_spell` WHERE `guid` NOT IN ( SELECT `id` FROM `character_pet` );
DELETE FROM `pet_spell_cooldown` WHERE `guid` NOT IN ( SELECT `id` FROM `character_pet` );
DELETE FROM `petition_sign` WHERE (`ownerguid`,`type`) NOT IN ( SELECT `ownerguid`,`type` FROM `petition` );

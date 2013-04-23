-- Queries for converting auth and characters databases from mangos to trinity. Tested with mangos rev 11896 + lot of custom things and trinity rev b32878f02f801feb0db0a60d528322740d16c01c  from 4th October 2012
-- go through the queries to know whats happening and edit them accordingly, dont just run them blindly.
-- wiped are player/pet auras, talents, instance IDs, corpses, groups, arena stats/teams, GM tickets
-- you might have to split some queries in more parts by guid, or increase innodb_buffer_pool_size in case of error "The total number of locks exceeds the lock table size"
-- character_glyphs and item_instance convertion taken from trinity forums, made up to date + adding other tables done by me
-- convert_mg_characters, convert_mg_auth - origin databases
-- convert_tc_characters, convert_tc_auth - destination databases
-- USE AT OWN RISK!, make sure you have backup

###################
## AUTH DATABASE ##
###################
USE convert_tc_auth;
-- format:  table name: columns left to default

-- account: email, online, os, recruiter
DELETE FROM account;
INSERT INTO account (id, username, sha_pass_hash, sessionkey, v, s, joindate, last_ip, failed_logins, locked, last_login, expansion, mutetime, locale)
SELECT               id, username, sha_pass_hash, sessionkey, v, s, joindate, last_ip, failed_logins, locked, last_login, expansion, mutetime, locale FROM convert_mg_auth.account;

-- account_access: RealmID
DELETE FROM account_access;
INSERT INTO account_access (id, gmlevel) 
SELECT                      id, gmlevel FROM convert_mg_auth.account;

-- account_banned
DELETE FROM account_banned;
INSERT INTO account_banned SELECT * FROM convert_mg_auth.account_banned;

-- ip_banned
DELETE FROM ip_banned;
INSERT INTO ip_banned SELECT * FROM convert_mg_auth.ip_banned;

-- logs
DELETE FROM logs;

-- realmcharacters
DELETE FROM realmcharacters;
INSERT INTO realmcharacters SELECT * FROM convert_mg_auth.realmcharacters;

-- realmlist
DELETE FROM realmlist;
INSERT INTO realmlist SELECT * FROM convert_mg_auth.realmlist;

#########################
## CHARACTERS DATABASE ##
#########################
USE convert_tc_characters;

-- account_data
DELETE FROM account_data;
INSERT INTO account_data SELECT * FROM convert_mg_characters.account_data;

-- account_instance_times
DELETE FROM account_instance_times;

-- account_tutorial
DELETE FROM account_tutorial;
INSERT INTO account_tutorial SELECT * FROM convert_mg_characters.character_tutorial;

-- addons
DELETE FROM addons;

-- arena_logs
DELETE FROM arena_logs;

-- arena_team
DELETE FROM arena_team;

-- arena_team_member
DELETE FROM arena_team_member;

-- auctionhouse
-- delete weird items and items put by AHbot
DELETE FROM convert_mg_characters.auction WHERE itemguid = 0 OR itemowner = 0;
DELETE FROM auctionhouse;
INSERT INTO auctionhouse (id, auctioneerguid, itemguid, itemowner, buyoutprice, time, buyguid, lastbid, startbid, deposit)
SELECT                    id, houseid,        itemguid, itemowner, buyoutprice, time, buyguid, lastbid, startbid, deposit FROM convert_mg_characters.auction;

-- bugreport
DELETE FROM bugreport;

-- corpse
DELETE FROM corpse;

-- creature_respawn
DELETE FROM creature_respawn;

-- game_event_condition_save
DELETE FROM game_event_condition_save;

-- game_event_save
DELETE FROM game_event_save;

-- gameobject_respawn
DELETE FROM gameobject_respawn;

-- gm_subsurveys
DELETE FROM gm_surveys;

-- gm_surveys
DELETE FROM gm_surveys;

-- gm_tickets
DELETE FROM gm_tickets;

-- group_instance
DELETE FROM group_instance;

-- group_member
DELETE FROM group_member;

-- groups
DELETE FROM groups;

-- guild
DELETE FROM guild;
INSERT INTO guild SELECT * FROM convert_mg_characters.guild;

-- guild_bank_eventlog
DELETE FROM guild_bank_eventlog;
INSERT INTO guild_bank_eventlog SELECT * FROM convert_mg_characters.guild_bank_eventlog;

-- guild_bank_item
DELETE FROM guild_bank_item;
INSERT INTO guild_bank_item SELECT guildid, TabId, SlotId, item_guid FROM convert_mg_characters.guild_bank_item;

-- guild_bank_right
DELETE FROM guild_bank_right;
INSERT INTO guild_bank_right SELECT * FROM convert_mg_characters.guild_bank_right;

-- guild_bank_tab
DELETE FROM guild_bank_tab;
INSERT INTO guild_bank_tab SELECT * FROM convert_mg_characters.guild_bank_tab;

-- guild_eventlog
DELETE FROM guild_eventlog;
INSERT INTO guild_eventlog SELECT * FROM convert_mg_characters.guild_eventlog;

-- guild_member
DELETE FROM guild_member;
INSERT INTO guild_member SELECT * FROM convert_mg_characters.guild_member;

-- guild_rank
DELETE FROM guild_rank;
INSERT INTO guild_rank SELECT * FROM convert_mg_characters.guild_rank;

-- channels
DELETE FROM channels;

-- character_account_data
DELETE FROM character_account_data;
INSERT INTO character_account_data SELECT * FROM convert_mg_characters.character_account_data;

-- character_action
DELETE FROM character_action;
INSERT INTO character_action SELECT * FROM convert_mg_characters.character_action;

-- character_achievement
DELETE FROM character_achievement;
INSERT INTO character_achievement SELECT * FROM convert_mg_characters.character_achievement;

-- character_achievement_progress
DELETE FROM character_achievement_progress;
INSERT INTO character_achievement_progress SELECT * FROM convert_mg_characters.character_achievement_progress;

-- character_arena_stats
DELETE FROM character_arena_stats;

-- character_aura
DELETE FROM character_aura;

-- character_banned
DELETE FROM character_banned;

-- character_battleground_data
DELETE FROM character_battleground_data;
INSERT INTO character_battleground_data SELECT * FROM convert_mg_characters.character_battleground_data;

-- character_battleground_random
DELETE FROM character_battleground_random;
INSERT INTO character_battleground_random SELECT * FROM convert_mg_characters.character_battleground_random;

-- character_declinedname
DELETE FROM character_declinedname;
INSERT INTO character_declinedname SELECT * FROM convert_mg_characters.character_declinedname;

-- character_equipmentsets
DELETE FROM character_equipmentsets;
INSERT INTO character_equipmentsets SELECT * FROM convert_mg_characters.character_equipmentsets;

-- character_gifts
DELETE FROM character_gifts;
INSERT INTO character_gifts SELECT * FROM convert_mg_characters.character_gifts;

-- character_glyphs
DELETE FROM character_glyphs;
INSERT INTO character_glyphs (guid,spec) SELECT DISTINCT guid,spec FROM convert_mg_characters.character_glyphs;
UPDATE character_glyphs A SET glyph1 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '0');
UPDATE character_glyphs A SET glyph2 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '1');
UPDATE character_glyphs A SET glyph3 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '2');
UPDATE character_glyphs A SET glyph4 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '3');
UPDATE character_glyphs A SET glyph5 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '4');
UPDATE character_glyphs A SET glyph6 = (SELECT glyph FROM convert_mg_characters.character_glyphs WHERE guid = A.guid AND spec = A.spec AND slot = '5');

-- character_homebind
DELETE FROM character_homebind;
INSERT INTO character_homebind SELECT * FROM convert_mg_characters.character_homebind;

-- character_instance
DELETE FROM character_instance;

-- character_inventory
-- in case of conflicts here check the queries at the bottom of this file
DELETE FROM character_inventory;
INSERT INTO character_inventory SELECT guid, bag, slot, item FROM convert_mg_characters.character_inventory;

-- character_pet
-- convert only tamed (hunter) pets, not summoned ones
DELETE FROM character_pet;
INSERT INTO character_pet SELECT * FROM convert_mg_characters.character_pet AS c WHERE c.PetType = 1;

-- character_pet_declinedname
DELETE FROM character_pet_declinedname;
INSERT INTO character_pet_declinedname SELECT * FROM convert_mg_characters.character_pet_declinedname;

-- character_queststatus
DELETE FROM character_queststatus;
INSERT INTO character_queststatus 
SELECT guid, quest, status, explored, timer, mobcount1, mobcount2, mobcount3, mobcount4, itemcount1, itemcount2, itemcount3, itemcount4, 0 FROM convert_mg_characters.character_queststatus;

-- character_queststatus_daily
DELETE FROM character_queststatus_daily;
INSERT INTO character_queststatus_daily (guid, quest) SELECT * FROM convert_mg_characters.character_queststatus_daily;

-- character_queststatus_rewarded
DELETE FROM character_queststatus_rewarded;
INSERT INTO character_queststatus_rewarded SELECT c.guid, c.quest FROM convert_mg_characters.character_queststatus c WHERE c.status = 1 AND c.rewarded = 1;

-- character_queststatus_seasonal
DELETE FROM character_queststatus_seasonal;

-- character_queststatus_weekly
DELETE FROM character_queststatus_weekly;

-- character_reputation
DELETE FROM character_reputation;
INSERT INTO character_reputation SELECT * FROM convert_mg_characters.character_reputation;

-- character_skills
DELETE FROM character_skills;
INSERT INTO character_skills SELECT * FROM convert_mg_characters.character_skills;

-- character_social
DELETE FROM character_social;
INSERT INTO character_social SELECT * FROM convert_mg_characters.character_social;

-- character_spell
DELETE FROM character_spell;
INSERT INTO character_spell SELECT * FROM convert_mg_characters.character_spell;

-- character_spell_cooldown
DELETE FROM character_spell_cooldown;

-- character_stats
DELETE FROM character_stats;

-- character_talent
DELETE FROM character_talent;

-- characters
DELETE FROM characters;
INSERT INTO characters (guid, account, name, race, class, gender, level, xp, money, playerBytes, playerBytes2, playerFlags, position_x, position_y, position_z, map, instance_id, instance_mode_mask, orientation, taximask, online, cinematic, totaltime, leveltime, logout_time, is_logout_resting, rest_bonus, resettalents_cost, resettalents_time, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login, 
zone, death_expire_time, taxi_path, arenaPoints, totalHonorPoints, todayHonorPoints, yesterdayHonorPoints, totalKills, todayKills, yesterdayKills, chosenTitle, knownCurrencies, watchedFaction, drunk, health, power1, power2, power3, power4, power5, power6, power7, latency, speccount, activespec, exploredZones, equipmentCache, ammoId, knownTitles, actionBars, grantableLevels, deleteInfos_Account, deleteInfos_Name, deleteDate)
SELECT                  guid, account, name, race, class, gender, level, xp, money, playerBytes, playerBytes2, playerFlags, position_x, position_y, position_z, map, 0,           dungeon_difficulty, orientation, taximask, online, cinematic, totaltime, leveltime, logout_time, is_logout_resting, rest_bonus, resettalents_cost, resettalents_time, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login,
zone, death_expire_time, taxi_path, arenaPoints, totalHonorPoints, todayHonorPoints, yesterdayHonorPoints, totalKills, todayKills, yesterdayKills, chosenTitle, knownCurrencies, watchedFaction, drunk, health, power1, power2, power3, power4, power5, power6, power7, 0, speccount, activespec, exploredZones, equipmentCache, ammoId, knownTitles, actionBars, grantableLevels, deleteInfos_Account, deleteInfos_Name, deleteDate FROM convert_mg_characters.characters;
-- even tho people dont have talents, we have to reset them at login to clean up spells they shouldnt have
UPDATE characters SET at_login = at_login | 4 | 16;

-- instance
DELETE FROM instance;

-- instance_reset
DELETE FROM instance_reset;

-- item_instance
-- DROP Trinity table and use mangos one
DROP TABLE IF EXISTS `item_instance`;
CREATE TABLE `item_instance` (
  `guid` int(11) unsigned NOT NULL default '0',
  `owner_guid` int(11) unsigned NOT NULL default '0',
  `data` longtext,
  `text` longtext,
  PRIMARY KEY  (`guid`),
  KEY `idx_owner_guid` (`owner_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Item System';

-- Copy mangos data
INSERT INTO item_instance SELECT * FROM convert_mg_characters.item_instance;

UPDATE item_instance SET data = REPLACE(data,'  ',' ');
UPDATE item_instance SET data = CONCAT(TRIM(data),' ');

UPDATE `item_instance` SET `data` = CONCAT(
SUBSTRING_INDEX(`data`, ' ', 59 + 1), ' ',
SUBSTRING_INDEX(`data`, ' ', -3 -1), '0 ')
WHERE length(SUBSTRING_INDEX(data, ' ', 64)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 64+1)) >= length(data);

UPDATE item_instance SET data = REPLACE(data,'  ',' ');
UPDATE item_instance SET data = CONCAT(TRIM(data),' ');

-- Add new fields
ALTER TABLE `item_instance`
ADD `itemEntry` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `guid`,
ADD `creatorGuid` int(10) unsigned NOT NULL default '0' AFTER `owner_guid`,
ADD `giftCreatorGuid` int(10) unsigned NOT NULL default '0' AFTER `creatorGuid`,
ADD `count` int(10) unsigned NOT NULL default '1' AFTER `giftCreatorGuid`,
ADD `duration` int(10) unsigned NOT NULL AFTER `count`,
ADD `charges` text NOT NULL AFTER `duration`,
ADD `flags` int(10) unsigned NOT NULL default '0' AFTER `charges`,
ADD `enchantments` text NOT NULL AFTER `flags`,
ADD `randomPropertyId` smallint(5) NOT NULL default '0' AFTER `enchantments`,  	-- might have to be increased while converting
ADD `durability` smallint(5) unsigned NOT NULL default '0' AFTER `randomPropertyId`,
ADD `playedTime` int(10) unsigned NOT NULL default '0' AFTER `durability`;

-- Temporarily change delimiter to prevent SQL syntax errors
DELIMITER ||

-- Function to convert ints from unsigned to signed
DROP FUNCTION IF EXISTS `uint32toint32`||
CREATE FUNCTION `uint32toint32`(input INT(10) UNSIGNED) RETURNS BIGINT(20) SIGNED DETERMINISTIC
BEGIN
  RETURN input;
END||

-- Restore original delimiter
DELIMITER ;

-- Move data to new fields
UPDATE `item_instance` SET
`itemEntry` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',3))+2,
length(SUBSTRING_INDEX(`data`,' ',3+1))-length(SUBSTRING_INDEX(data,' ',3))-1),

`creatorGuid` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',10))+2,
length(SUBSTRING_INDEX(`data`,' ',10+1))-length(SUBSTRING_INDEX(data,' ',10))-1),

`giftCreatorGuid` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',12))+2,
length(SUBSTRING_INDEX(`data`,' ',12+1))-length(SUBSTRING_INDEX(data,' ',12))-1),

`count` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',14))+2,
length(SUBSTRING_INDEX(`data`,' ',14+1))-length(SUBSTRING_INDEX(data,' ',14))-1),

`duration` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',15))+2,
length(SUBSTRING_INDEX(`data`,' ',15+1))-length(SUBSTRING_INDEX(data,' ',15))-1),

`charges` = CONCAT_WS(' ',
uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',16))+2,
length(SUBSTRING_INDEX(`data`,' ',16+1))-length(SUBSTRING_INDEX(data,' ',16))-1)),
uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',17))+2,
length(SUBSTRING_INDEX(`data`,' ',17+1))-length(SUBSTRING_INDEX(data,' ',17))-1)),
uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',18))+2,
length(SUBSTRING_INDEX(`data`,' ',18+1))-length(SUBSTRING_INDEX(data,' ',18))-1)),
uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',19))+2,
length(SUBSTRING_INDEX(`data`,' ',19+1))-length(SUBSTRING_INDEX(data,' ',19))-1)),
uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',20))+2,
length(SUBSTRING_INDEX(`data`,' ',20+1))-length(SUBSTRING_INDEX(data,' ',20))-1))),

`flags` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',21))+2,
length(SUBSTRING_INDEX(`data`,' ',21+1))-length(SUBSTRING_INDEX(data,' ',21))-1),

`enchantments` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',22))+2,
length(SUBSTRING_INDEX(`data`,' ',57+1))-length(SUBSTRING_INDEX(data,' ',22))-1),

`randomPropertyId` = uint32toint32(SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',59))+2,
length(SUBSTRING_INDEX(`data`,' ',59+1))-length(SUBSTRING_INDEX(data,' ',59))-1)),

`durability` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',60))+2,
length(SUBSTRING_INDEX(`data`,' ',60+1))-length(SUBSTRING_INDEX(data,' ',60))-1),

`playedTime` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',62))+2,
length(SUBSTRING_INDEX(`data`,' ',62+1))-length(SUBSTRING_INDEX(data,' ',62))-1);

-- Drop function
DROP FUNCTION IF EXISTS `uint32toint32`;

-- Fix heroic item flag
UPDATE `item_instance` SET `flags`=`flags`&~0x8 WHERE
SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',3))+2,
length(SUBSTRING_INDEX(`data`,' ',3+1))-length(SUBSTRING_INDEX(data,' ',3))-1)
NOT IN (5043,5044,17302,17305,17308,21831);

-- Drop old field
ALTER TABLE `item_instance` DROP `data`;

-- Execute 09160_characters_item_instance.sql
SET @allowedFlags := 0x00000001 | 0x00000008 | 0x00000200 | 0x00001000 | 0x00008000 | 0x00010000;
UPDATE `item_instance` SET `flags` = (`flags` & @allowedFlags);

-- item_refund_instance
DELETE FROM item_refund_instance;

-- item_soulbound_trade_data
DELETE FROM item_soulbound_trade_data;
INSERT INTO item_soulbound_trade_data SELECT * FROM convert_mg_characters.item_soulbound_trade_data;

-- lag_reports
DELETE FROM lag_reports;

-- lfg_data
DELETE FROM lfg_data;

-- mail
DELETE FROM mail;
INSERT INTO mail SELECT * FROM convert_mg_characters.mail;

-- mail_items
DELETE FROM mail_items;
INSERT INTO mail_items SELECT mail_id, item_guid, receiver FROM convert_mg_characters.mail_items;

-- pet_aura
DELETE FROM pet_aura;

-- pet_spell
DELETE FROM pet_spell;
INSERT INTO pet_spell SELECT guid, spell, active FROM convert_mg_characters.pet_spell;
-- cleanup spells of deleted pets
-- SELECT A.* FROM pet_spell A LEFT JOIN character_pet B ON A.guid = B.id WHERE A.guid NOT IN (SELECT id FROM character_pet);
DELETE A FROM pet_spell A LEFT JOIN character_pet B ON A.guid = B.id WHERE A.guid NOT IN (SELECT id FROM character_pet);

-- pet_spell_cooldown
DELETE FROM pet_spell_cooldown;

-- petition
DELETE FROM petition;
INSERT INTO petition SELECT * FROM convert_mg_characters.petition;

-- petition_sign
DELETE FROM petition_sign;
INSERT INTO petition_sign SELECT * FROM convert_mg_characters.petition_sign;

-- pool_quest_save
DELETE FROM pool_quest_save;

-- reserved_name
DELETE FROM reserved_name;

-- warden_action
DELETE FROM warden_action;

-- worldstates
DELETE FROM worldstates;

-- checks for case of problems with character_inventory, handle it manually
-- my advise is leaving only the item with the highest guid at the conflicting slot
-- dont forget deleting the item from item_instance too
/*SELECT A.guid, A.bag, A.slot, A.item, A.item_template  FROM character_inventory AS A INNER JOIN character_inventory AS B INNER JOIN character_inventory AS C
WHERE A.guid = B.guid
AND A.bag = B.bag
AND A.slot = B.slot
AND A.item_template <> B.item_template
AND A.bag=C.bag
AND A.slot=C.slot
AND A.guid=C.guid
AND A.item=C.item
ORDER BY A.guid, A.bag, A.slot, A.item, A.item_template*/

/*SELECT A.guid, A.bag, A.slot, A.item, A.item_template  FROM character_inventory AS A INNER JOIN character_inventory AS B INNER JOIN character_inventory AS C
WHERE A.guid = B.guid
AND A.bag = B.bag
AND A.slot = B.slot
AND A.bag = C.bag
AND A.slot = C.slot
AND A.guid = C.guid
AND A.item <> C.item
ORDER BY A.guid, A.bag, A.slot, A.item, A.item_template*/

-- cleaning up old (completed and rewarded) quests from quest log
-- SELECT A.* FROM character_queststatus AS A INNER JOIN character_queststatus_rewarded AS B ON A.guid = B.guid WHERE A.guid < 70000 AND A.status = 1 AND A.quest IN (SELECT quest FROM character_queststatus_rewarded WHERE guid = A.guid) GROUP BY A.guid, A.quest;
DELETE A FROM character_queststatus AS A LEFT JOIN character_queststatus_rewarded AS B ON A.guid = B.guid WHERE A.status = 1 AND A.quest IN (SELECT quest FROM character_queststatus_rewarded WHERE guid = A.guid);

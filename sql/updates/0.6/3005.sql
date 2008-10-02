
ALTER TABLE `auctionhouse` MODIFY COLUMN `id` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `auctioneerguid` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `itemguid` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `buyoutprice` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `buyguid` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `lastbid` int(11) NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` MODIFY COLUMN `startbid` int(11) NOT NULL DEFAULT '0';

ALTER TABLE `character` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character` MODIFY COLUMN `account` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Account Identifier';
ALTER TABLE `character` MODIFY COLUMN `is_logout_resting` tinyint(3) NOT NULL DEFAULT '0';

ALTER TABLE `character_action` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_action` MODIFY COLUMN `button` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `character_action` MODIFY COLUMN `action` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `character_action` MODIFY COLUMN `type` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `character_action` MODIFY COLUMN `misc` tinyint(3) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `character_aura` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `character_homebind` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `character_inventory` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_inventory` MODIFY COLUMN `bag`  int(11) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `character_inventory` MODIFY COLUMN `item` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Item Global Unique Identifier';

ALTER TABLE `character_kill` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_kill` MODIFY COLUMN `type` tinyint(3) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `character_queststatus` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `character_reputation` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `character_social` MODIFY COLUMN `guid`   int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_social` MODIFY COLUMN `friend` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier';

ALTER TABLE `character_spell` MODIFY COLUMN `guid` int(11)  unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_spell` MODIFY COLUMN `active` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `character_ticket` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `character_tutorial` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut0` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut1` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut2` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut3` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut4` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut5` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut6` int(11) unsigned NOT NULL default '0';
ALTER TABLE `character_tutorial` MODIFY COLUMN `tut7` int(11) unsigned NOT NULL default '0';
ALTER TABLE `command` MODIFY COLUMN `name` varchar(50) NOT NULL default '';
ALTER TABLE `command` MODIFY COLUMN `security` tinyint(3) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `corpse` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';
ALTER TABLE `corpse` MODIFY COLUMN `player` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier';

ALTER TABLE `corpse_grid` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `creature` MODIFY COLUMN `guid` int(11) unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier';
ALTER TABLE `creature` MODIFY COLUMN `state` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `creature` MODIFY COLUMN `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0';


ALTER TABLE `creature_grid` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `creature_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `creature_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `creature_template` MODIFY COLUMN `minlevel` tinyint(3) unsigned DEFAULT '1';
ALTER TABLE `creature_template` MODIFY COLUMN `maxlevel` tinyint(3) unsigned DEFAULT '1';
ALTER TABLE `creature_template` MODIFY COLUMN `rank`     tinyint(3) unsigned DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `trainer_type` tinyint(3) DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `class` tinyint(3) unsigned DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `race` tinyint(3) unsigned DEFAULT '0';

ALTER TABLE `creature_template` MODIFY COLUMN `rangedattackpower` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `type` tinyint(3) unsigned DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `civilian` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` MODIFY COLUMN `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `fishing_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `fishing_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `gameobject` MODIFY COLUMN `guid` int(11) unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier';

ALTER TABLE `gameobject_grid` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier';

ALTER TABLE `gameobject_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `gameobject_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `item_instance` MODIFY COLUMN `guid` int(11) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_instance` ADD COLUMN `owner_guid` int(11) unsigned NOT NULL DEFAULT '0' AFTER `guid`;


UPDATE `item_instance`
  SET `owner_guid` = SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',7),' ',-1);

ALTER TABLE `item_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `item_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `item_template` MODIFY COLUMN `class` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `subclass` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `displayid` int(11) unsigned NOT NULL default '0';
ALTER TABLE `item_template` MODIFY COLUMN `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `InventoryType` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `AllowableClass` mediumint(9) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `RequiredLevel` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `maxcount` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stackable` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `ContainerSlots` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type1` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value1` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type2` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value2` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type3` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value3` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type4` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value4` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type5` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value5` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type6` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value6` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type7` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value7` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type8` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value8` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type9` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value9` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_type10` tinyint(4) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `stat_value10` smallint(6) NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `dmg_type1` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `dmg_type2` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `dmg_type3` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `dmg_type4` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `dmg_type5` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `item_template` MODIFY COLUMN `bonding` tinyint(3) unsigned NOT NULL DEFAULT '0';


ALTER TABLE `mail` MODIFY COLUMN `id` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Identifier';
ALTER TABLE `mail` MODIFY COLUMN `messageType` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `mail` MODIFY COLUMN `sender` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier';
ALTER TABLE `mail` MODIFY COLUMN `receiver` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Character Global Unique Identifier';
ALTER TABLE `mail` MODIFY COLUMN `item_guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Mail Item Global Unique Identifier';
ALTER TABLE `mail` MODIFY COLUMN `cod` int(11) unsigned NOT NULL DEFAULT '0';

DROP TABLE IF EXISTS `npc_spirithealer`;
DELETE FROM `command` WHERE `name` = 'addspirit';
DELETE FROM `command` WHERE `name` = 'addsh';

ALTER TABLE `npc_vendor` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `pickpocketing_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `pickpocketing_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `raidgroup` MODIFY COLUMN `leaderGuid` int(11) NOT NULL;
ALTER TABLE `raidgroup` MODIFY COLUMN `lootMethod` tinyint(4) NOT NULL;
ALTER TABLE `raidgroup` MODIFY COLUMN `looterGuid` int(11) NOT NULL;

ALTER TABLE `raidgroup_member` MODIFY COLUMN `leaderGuid` int(11) NOT NULL;
ALTER TABLE `raidgroup_member` MODIFY COLUMN `memberGuid` int(11) NOT NULL;

ALTER TABLE `skinning_loot_template` MODIFY COLUMN `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `skinning_loot_template` MODIFY COLUMN `quest_freeforall` tinyint(3) unsigned NOT NULL DEFAULT '1';

ALTER TABLE `spell_chain` MODIFY COLUMN `rank` tinyint(4) NOT NULL DEFAULT '0';

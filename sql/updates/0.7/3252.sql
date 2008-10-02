ALTER TABLE `areatrigger_template` MODIFY COLUMN `required_level` tinyint(3) unsigned NOT NULL default '0';
ALTER TABLE `item_template` MODIFY COLUMN `DisenchantID` int(11) unsigned NOT NULL default '0';

ALTER TABLE `auctionhouse` MODIFY COLUMN `id` int(11) unsigned NOT NULL default '0';

ALTER TABLE `corpse` MODIFY COLUMN `player` int(11) unsigned NOT NULL default '0' COMMENT 'Character Global Unique Identifier';

ALTER TABLE `creature_template`
  MODIFY COLUMN `rangedattackpower` smallint(5) unsigned NOT NULL default '0',
  MODIFY COLUMN `type` tinyint(3) unsigned default '0';

ALTER TABLE `disenchant_loot_template` MODIFY COLUMN `entry` int(11) unsigned NOT NULL default '0' COMMENT 'Recommended id selection: item_level*100 + item_quality';

UPDATE `item_template` SET `stat_type1`='0' WHERE `stat_type1`<'0';
UPDATE `item_template` SET `stat_type2`='0' WHERE `stat_type2`<'0';
UPDATE `item_template` SET `stat_type3`='0' WHERE `stat_type3`<'0';
UPDATE `item_template` SET `stat_type4`='0' WHERE `stat_type4`<'0';
UPDATE `item_template` SET `stat_type5`='0' WHERE `stat_type5`<'0';
UPDATE `item_template` SET `stat_type6`='0' WHERE `stat_type6`<'0';
UPDATE `item_template` SET `stat_type7`='0' WHERE `stat_type7`<'0';
UPDATE `item_template` SET `stat_type8`='0' WHERE `stat_type8`<'0';
UPDATE `item_template` SET `stat_type9`='0' WHERE `stat_type9`<'0';
UPDATE `item_template` SET `stat_type10`='0' WHERE `stat_type10`<'0';

ALTER TABLE `item_template`
  MODIFY COLUMN `AllowableClass` mediumint(9) NOT NULL default '0',
  MODIFY COLUMN `AllowableRace` mediumint(9) NOT NULL default '0',
  MODIFY COLUMN `stat_type1` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value1` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type2` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value2` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type3` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value3` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type4` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value4` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type5` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value5` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type6` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value6` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type7` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value7` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type8` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value8` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type9` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value9` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `stat_type10` tinyint(4) unsigned NOT NULL default '0',
  MODIFY COLUMN `stat_value10` smallint(6) NOT NULL default '0',
  MODIFY COLUMN `dmg_type1` tinyint(3) unsigned NOT NULL default '0',
  MODIFY COLUMN `dmg_type2` tinyint(3) unsigned NOT NULL default '0',
  MODIFY COLUMN `dmg_type3` tinyint(3) unsigned NOT NULL default '0',
  MODIFY COLUMN `dmg_type4` tinyint(3) unsigned NOT NULL default '0',
  MODIFY COLUMN `dmg_type5` tinyint(3) unsigned NOT NULL default '0',
  MODIFY COLUMN `Material` int(30) NOT NULL default '0';

ALTER TABLE `pet_name_generation` ENGINE=MyISAM, DEFAULT CHARSET=utf8;
ALTER TABLE `pet_name_generation` MODIFY COLUMN `word` tinytext NOT NULL;

ALTER TABLE `quest_template`
  MODIFY COLUMN `ReqSourceId1` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `ReqSourceId2` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `ReqSourceId3` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `ReqSourceId4` int(11) unsigned NOT NULL default '0',
  MODIFY COLUMN `RewRepFaction1` int(11) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  MODIFY COLUMN `RewRepFaction2` int(11) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  MODIFY COLUMN `RewRepFaction3` int(11) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  MODIFY COLUMN `RewRepFaction4` int(11) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  MODIFY COLUMN `RewRepFaction5` int(11) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case';

ALTER TABLE `scripts` ENGINE=MyISAM, DEFAULT CHARSET=utf8;
ALTER TABLE `scripts` MODIFY COLUMN `datatext` text NOT NULL;

ALTER TABLE `spell_proc_event` ENGINE=MyISAM, DEFAULT CHARSET=utf8;

ALTER TABLE `spell_scripts` ENGINE=MyISAM, DEFAULT CHARSET=utf8;
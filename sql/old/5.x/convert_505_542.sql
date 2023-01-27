DROP TABLE IF EXISTS `character_archaeology`;
CREATE TABLE `character_archaeology` (
  `guid` int(11) NOT NULL,
  `sites` text NOT NULL,
  `counts` text NOT NULL,
  `projects` text NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Archaeology System';

DROP TABLE IF EXISTS `character_archaeology_finds`;
CREATE TABLE `character_archaeology_finds` (
  `guid` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `count` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`guid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO character_archaeology_finds (guid, id, count, date) 
SELECT guid, projectId, count, FROM_UNIXTIME(timeCreated) FROM character_archprojecthistory;

INSERT INTO character_archaeology (guid, sites, counts, projects)
SELECT guid, '', '', GROUP_CONCAT(projectId separator ' ') FROM character_archproject GROUP BY guid;

DROP TABLE IF EXISTS character_archproject;
DROP TABLE IF EXISTS character_archprojecthistory;

ALTER TABLE character_queststatus ADD COLUMN `mobcount5` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount4`;
ALTER TABLE character_queststatus ADD COLUMN `mobcount6` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount5`;
ALTER TABLE character_queststatus ADD COLUMN `mobcount7` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount6`;
ALTER TABLE character_queststatus ADD COLUMN `mobcount8` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount7`;
ALTER TABLE character_queststatus ADD COLUMN `mobcount9` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount8`;
ALTER TABLE character_queststatus ADD COLUMN `mobcount10` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `mobcount9`;

ALTER TABLE character_queststatus ADD COLUMN `itemcount5` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount4`;
ALTER TABLE character_queststatus ADD COLUMN `itemcount6` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount5`;
ALTER TABLE character_queststatus ADD COLUMN `itemcount7` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount6`;
ALTER TABLE character_queststatus ADD COLUMN `itemcount8` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount7`;
ALTER TABLE character_queststatus ADD COLUMN `itemcount9` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount8`;
ALTER TABLE character_queststatus ADD COLUMN `itemcount10` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount9`;

ALTER TABLE `character_currency`
ADD `curentcap` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER flags;

DROP TABLE `character_rated_bg`;

DROP TABLE IF EXISTS `character_brackets_info`;
CREATE TABLE `character_brackets_info` (
  `guid` int(11) NOT NULL,
  `bracket` smallint(6) NOT NULL,
  `rating` mediumint(9) NOT NULL DEFAULT '0',
  `best` mediumint(9) NOT NULL DEFAULT '0',
  `bestWeek` smallint(9) NOT NULL DEFAULT '0',
  `mmr` mediumint(9) NOT NULL DEFAULT '0',
  `games` int(11) NOT NULL DEFAULT '0',
  `wins` int(11) NOT NULL DEFAULT '0',
  `weekGames` mediumint(9) NOT NULL DEFAULT '0',
  `weekWins` mediumint(9) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`bracket`),
  KEY `BracketID` (`bracket`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `item_instance`
ADD `upgradeId` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL AFTER transmogrifyId;

DROP TABLE `arena_team`;
DROP TABLE `arena_team_member`;

ALTER TABLE character_achievement_progress
  CHANGE COLUMN guid guid int(11) unsigned NOT NULL,
  CHANGE COLUMN criteria criteria int(11) unsigned NOT NULL,
  CHANGE COLUMN counter counter int(11) unsigned NOT NULL,
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';
ALTER TABLE account_achievement_progress
  CHANGE COLUMN account account int(11) unsigned NOT NULL,
  CHANGE COLUMN criteria criteria int(11) unsigned NOT NULL,
  CHANGE COLUMN counter counter int(11) unsigned NOT NULL,
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';
ALTER TABLE guild_achievement_progress
  CHANGE COLUMN guildId guildId int(11) unsigned NOT NULL,
  CHANGE COLUMN criteria criteria int(11) unsigned NOT NULL,
  CHANGE COLUMN counter counter int(11) unsigned NOT NULL,
  CHANGE COLUMN completedGuid completedGuid int(11) unsigned NOT NULL default '0',
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';

ALTER TABLE account_achievement
  CHANGE COLUMN account account int(11) unsigned NOT NULL,
  CHANGE COLUMN first_guid first_guid int(11) unsigned NOT NULL,
  CHANGE COLUMN achievement achievement int(11) unsigned NOT NULL,
  CHANGE COLUMN date date int(11) unsigned NOT NULL default '0';
ALTER TABLE guild_achievement
  CHANGE COLUMN guildId guildId int(11) unsigned NOT NULL,
  CHANGE COLUMN achievement achievement int(11) unsigned NOT NULL,
  CHANGE COLUMN date date int(11) unsigned NOT NULL default '0';
ALTER TABLE character_achievement
  CHANGE COLUMN guid guid int(11) unsigned NOT NULL,
  CHANGE COLUMN achievement achievement int(11) unsigned NOT NULL;

DELETE FROM `character_spell` WHERE spell IN (103826,103827,103828,55694,29838,103840,107566,12323,102060,46924,46968,118000,114028,114029,114030,107574,12292,107570,85499,87172,26023,105593,20066,110301,85804,114163,20925,114039,114154,105622,105809,53376,86172,114165,114158,114157,109215,109298,118675,109248,19386,19577,109304,109260,109212,82726,120679,109306,131894,130392,120697,117050,109259,120360,14062,108208,108209,26679,108210,74001,31230,108211,79008,138106,36554,108212,131511,108215,108216,114014,137619,114015,108920,108921,605,64129,121536,108942,109186,123040,139139,19236,112833,108945,109142,10060,109175,121135,110744,120517,108170,123693,115989,49039,51052,114556,96268,50041,108194,48743,108196,119975,45529,81229,51462,108199,108200,108201,30884,108270,108271,63374,51485,108273,108285,108284,108287,16166,16188,108283,147074,108281,108282,117012,117013,117014,12043,108843,108839,115610,140468,11426,113724,111264,102051,110959,86949,11958,114923,44457,112948,114003,116011,1463,108359,108370,108371,47897,6789,30283,108415,108416,110913,111397,111400,108482,108499,108501,108503,108505,137587,108508,115173,116841,115174,115098,124081,123986,121817,115396,115399,116844,119392,119381,122280,122278,122783,116847,123904,115008,131768,102280,102401,145108,108238,102351,106707,102359,132469,114107,106731,106737,99,102793,5211,108288,108373,124974);
TRUNCATE TABLE character_talent;
UPDATE characters SET speccount = 1, activespec = 0;

ALTER TABLE `characters` ADD `transfer` tinyint(3) NOT NULL DEFAULT '0';
ALTER TABLE `characters` ADD KEY `transfer` ( `transfer` );

-- Warlock
DELETE FROM `character_pet` WHERE `slot` > 24 AND `slot` < 36;
-- Stamped
DELETE FROM `character_pet` WHERE `slot` > 35 AND `slot` < 41;
-- Other
DELETE FROM `character_pet` WHERE `slot` = 100;
DELETE FROM pet_aura WHERE guid not in (select id from character_pet);
DELETE FROM pet_aura_effect WHERE guid not in (select id from character_pet);
DELETE FROM pet_spell WHERE guid not in (select id from character_pet);
DELETE FROM pet_spell_cooldown WHERE guid not in (select id from character_pet);

ALTER TABLE  `characters` CHANGE  `petslotused`  `petslot` LONGTEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL;
UPDATE `characters` SET `petslot` = 0;

ALTER TABLE  `characters` CHANGE  `currentpetslot`  `currentpetnumber` INT( 11 ) NOT NULL;
update `characters` set `currentpetnumber` = 0;

ALTER TABLE `character_pet` DROP `slot`;


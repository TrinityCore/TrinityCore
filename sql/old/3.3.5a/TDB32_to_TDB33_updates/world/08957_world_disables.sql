-- Step 1: prepare table
DROP TABLE IF EXISTS `disables`;
CREATE TABLE `disables` (
  `sourceType` int(10) unsigned NOT NULL,
  `entry` int(10) unsigned NOT NULL,
  `flags` tinyint(3) unsigned NOT NULL default '0',
  `comment` varchar(255) character set utf8 NOT NULL default '',
  PRIMARY KEY  (`sourceType`,`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- Step 2: pull data
-- a) spells
INSERT INTO `disables` SELECT 0,`entry`,`disable_mask`,`comment` FROM `spell_disabled`;

-- b) maps (areatriggers)
-- don't convert

-- c) battlegrounds
INSERT INTO `disables` SELECT 3,`id`,0,'' FROM `battleground_template` WHERE `disable`=1;

-- d) achievement criteria data
INSERT INTO `disables` SELECT 4,`criteria_id`,0,'' FROM `achievement_criteria_data` WHERE `type`=11;

-- Step 3: drop old fields/tables/data
DROP TABLE IF EXISTS `spell_disabled`;
ALTER TABLE `access_requirement` DROP `status`;
ALTER TABLE `battleground_template` DROP `disable`;
DELETE FROM `achievement_criteria_data` WHERE `type`=11;

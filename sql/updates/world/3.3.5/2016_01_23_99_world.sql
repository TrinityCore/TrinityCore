-- Create databases for creature group template, and creature group membership
-- Current flags
-- 		0x01	Legacy Spawn Mode (spawn using legacy spawn system)
--		0x02	Manual Spawn (don't automatically spawn creature, instead spawn from core as part of script)
DROP TABLE IF EXISTS `creature_group_template`;
CREATE TABLE `creature_group_template` (
  `groupId` int(10) unsigned NOT NULL DEFAULT '0',
  `groupName` varchar(100) NOT NULL DEFAULT '',
  `groupFlags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`groupId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `creature_group`;
CREATE TABLE `creature_group` (
  `groupId` int(10) unsigned NOT NULL DEFAULT '0',
  `creatureId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`groupId`, `creatureId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Current flags
-- 		0x01	Legacy Spawn Mode (spawn using legacy spawn system)
--		0x02	Manual Spawn (don't automatically spawn creature, instead spawn from core as part of script)
DROP TABLE IF EXISTS `gameobject_group_template`;
CREATE TABLE `gameobject_group_template` (
  `groupId` int(10) unsigned NOT NULL DEFAULT '0',
  `groupName` varchar(100) NOT NULL DEFAULT '',
  `groupFlags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`groupId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gameobject_group`;
CREATE TABLE `gameobject_group` (
  `groupId` int(10) unsigned NOT NULL DEFAULT '0',
  `gameobjectId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`groupId`, `gameobjectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Create the default groups
INSERT INTO `creature_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(0, 'Default Group', 0),
(1, 'Legacy Group', 1),
(2, 'Dynamic Spawn Group', 4),
(3, 'Quest giving Escort NPCs', 8);

-- Create the default groups
INSERT INTO `gameobject_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(0, 'Default Group', 0),
(1, 'Legacy Group', 1),
(2, 'Dynamic Spawn Group', 4),
(4, 'Mining/Herb nodes (Dynamic)', 4);

-- Create creature dynamic spawns group (creatures with quest items, or subjects of quests with less than 30min spawn time)
DELETE FROM `creature_group` WHERE `groupId` = 2;
DROP TABLE IF EXISTS `creature_temp_group`;
CREATE TEMPORARY TABLE `creature_temp_group`
(
  `creatureId` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `creature_temp_group`
SELECT `guid`
FROM `creature` C
INNER JOIN `creature_questitem` ON `CreatureEntry` = C.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `creature_temp_group`
SELECT `guid`
FROM `creature` C
INNER JOIN `quest_template` ON `RequiredNpcOrGo1` = C.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `creature_temp_group`
SELECT `guid`
FROM `creature` C
INNER JOIN `quest_template` ON `RequiredNpcOrGo2` = C.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `creature_temp_group`
SELECT `guid`
FROM `creature` C
INNER JOIN `quest_template` ON `RequiredNpcOrGo3` = C.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `creature_temp_group`
SELECT `guid`
FROM `creature` C
INNER JOIN `quest_template` ON `RequiredNpcOrGo4` = C.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `creature_group` (`groupId`, `creatureId`)
SELECT DISTINCT 2, `creatureId`
FROM `creature_temp_group`;

DROP TABLE `creature_temp_group`;

-- Create gameobject dynamic spawns group (gameobjects with quest items, or subjects of quests with less than 30min spawn time)

DELETE FROM `gameobject_group` WHERE `groupId` = 2;
DROP TABLE IF EXISTS `gameobject_temp_group`;
CREATE TEMPORARY TABLE `gameobject_temp_group`
(
  `gameobjectId` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gameobject_temp_group_ids`;
CREATE TEMPORARY TABLE `gameobject_temp_group_ids`
(
  `entryid` int(10) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `gameobject_temp_group_ids` ADD INDEX (`entryid`);

INSERT INTO `gameobject_temp_group`
SELECT `guid`
FROM `gameobject` G
INNER JOIN `gameobject_questitem` ON `GameObjectEntry` = G.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `gameobject_temp_group_ids` (`entryid`)
SELECT DISTINCT `RequiredNpcOrGo1` * -1
FROM `quest_template`;

INSERT INTO `gameobject_temp_group_ids` (`entryid`)
SELECT DISTINCT `RequiredNpcOrGo2` * -1
FROM `quest_template`;

INSERT INTO `gameobject_temp_group_ids` (`entryid`)
SELECT DISTINCT `RequiredNpcOrGo3` * -1
FROM `quest_template`;

INSERT INTO `gameobject_temp_group_ids` (`entryid`)
SELECT DISTINCT `RequiredNpcOrGo4` * -1
FROM `quest_template`;

INSERT INTO `gameobject_temp_group`
SELECT `guid`
FROM `gameobject` G
INNER JOIN `gameobject_temp_group_ids` ON `entryid` = G.`id`
WHERE `spawntimesecs` < 1800
AND `map` IN (0, 1, 530, 571);

INSERT INTO `gameobject_group` (`groupId`, `gameobjectId`)
SELECT DISTINCT 2, `gameobjectId`
FROM `gameobject_temp_group`;

DROP TABLE `gameobject_temp_group`;
ALTER TABLE `gameobject_temp_group_ids` DROP INDEX `entryid`;
DROP TABLE `gameobject_temp_group_ids`;

-- Add mining nodes/herb nodes to profession node group
DELETE FROM `gameobject_group` WHERE `groupId` = 4;
INSERT INTO `gameobject_group` (`groupId`, `gameobjectId`)
SELECT 4, `guid`
FROM `gameobject` g
INNER JOIN `gameobject_template` gt
	ON gt.`entry` = g.`id`
WHERE `type` = 3
AND `Data0` IN (2, 8, 9, 10, 11, 18, 19, 20, 21, 22, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 38, 39, 40, 41, 42, 45, 47, 48, 49, 50, 51, 379, 380, 399, 400, 439, 440, 441, 442, 443, 444, 519, 521, 719, 939, 1119, 1120, 
              1121, 1122, 1123, 1124, 1632, 1639, 1641, 1642, 1643, 1644, 1645, 1646, 1649, 1650, 1651, 1652, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793, 1800, 1860);

-- Add Escort NPCs
DELETE FROM `creature_group` WHERE `groupId` = 3;
INSERT INTO `creature_group` (`groupId`, `creatureId`) VALUES
(3, 10873),
(3, 17874),
(3, 40210),
(3, 11348),
(3, 93301),
(3, 93194),
(3, 19107),
(3, 21692),
(3, 21584),
(3, 23229),
(3, 24268),
(3, 21594),
(3, 14387),
(3, 50381),
(3, 15031),
(3, 26987),
(3, 29241),
(3, 32333),
(3, 33115),
(3, 37085),
(3, 41759),
(3, 84459),
(3, 78685),
(3, 62090),
(3, 72388),
(3, 86832),
(3, 67040),
(3, 78781),
(3, 65108),
(3, 63688),
(3, 59383),
(3, 63625),
(3, 70021),
(3, 82071),
(3, 117903),
(3, 111075),
(3, 101136),
(3, 101303),
(3, 122686),
(3, 117065),
(3, 202337),
(3, 2017),
(3, 132683);


-- Update trinity strings for various cs_list strings, to support showing spawn ID and guid.
UPDATE `trinity_string`
SET `content_default` = '%d (Entry: %d) - |cffffffff|Hgameobject:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r %s %s'
WHERE `entry` = 517;

UPDATE `trinity_string`
SET `content_default` = '%d - |cffffffff|Hcreature:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r %s %s'
WHERE `entry` = 515;

UPDATE `trinity_string`
SET `content_default` = '%d - %s X:%f Y:%f Z:%f MapId:%d %s %s'
WHERE `entry` = 1111;

UPDATE `trinity_string`
SET `content_default` = '%d - %s X:%f Y:%f Z:%f MapId:%d %s %s'
WHERE `entry` = 1110;

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 5062 AND 5077;

-- Add new trinity strings for extra npc/gobject info lines
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5062, 'Group: %u - Flags %u - Active %u'),
(5063, 'Compatibility Mode: %u'),
(5064, 'Group: %u - Flags %u - Active %u'),
(5065, 'Compatibility Mode: %u'),
(5066, 'GUID: %s'),
(5067, 'SpawnID: %u, location (%f, %f, %f)'),
(5068, 'Distance from player %f'),
(5069, 'Creature group %u not found'),
(5070, 'GameObject group %u not found'),
(5071, 'Listing %s respawns for the current scope'),
(5072, 'SpawnID Entry   GridXY  Scope Respawn time Orig Respawn'),
(5073, '%7u %7u [%02u,%02u] %5u %13s %s'),
(5074, 'overdue'),
(5075, 'creatures'),
(5076, 'gameobjects');

-- Add new NPC/Gameobject commands
DELETE FROM `command` WHERE `name` IN ('npc spawngroup', 'npc despawngroup', 'gobject spawngroup', 'gobject despawngroup', 'list respawns');
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('npc spawngroup', 842, 'Syntax: .npc spawngroup $groupId [ignorerespawn] [force]'),
('npc despawngroup', 843, 'Syntax: .npc despawngroup $groupId [removerespawntime]'),
('gobject spawngroup', 844, 'Syntax: .gobject spawngroup $groupId [ignorerespawn] [force]'),
('gobject despawngroup', 845, 'Syntax: .gobject despawngroup $groupId [removerespawntime]'),
('list respawns', 846, 'Syntax: .list respawns [*] [grid] (Enter * for all respawns within current map, or grid for all in current grid)');

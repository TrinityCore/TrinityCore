-- DYNAMIC SPAWNING SYSTEM
-- Create databases for spawn group template, and spawn group membership
-- Current flags
-- 		0x01	Legacy Spawn Mode (spawn using legacy spawn system)
--		0x02	Manual Spawn (don't automatically spawn, instead spawned by core as part of script)
DROP TABLE IF EXISTS `spawn_group_template`;
CREATE TABLE `spawn_group_template` (
  `groupId` int(10) unsigned NOT NULL,
  `groupName` varchar(100) NOT NULL,
  `groupFlags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`groupId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spawn_group`;
CREATE TABLE `spawn_group` (
  `groupId` int(10) unsigned NOT NULL,
  `spawnType` tinyint(10) unsigned NOT NULL,
  `spawnId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`groupId`,`spawnType`,`spawnId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Create the default groups
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(0, 'Default Group', 0x01),
(1, 'Legacy Group', (0x01|0x02)),
(2, 'Dynamic Scaling (Quest objectives)', (0x01|0x08)),
(3, 'Dynamic Scaling (Escort NPCs)', (0x01|0x08|0x10)),
(4, 'Dynamic Scaling (Gathering nodes)', (0x01|0x08));

-- Create creature dynamic spawns group (creatures with quest items, or subjects of quests with less than 30min spawn time)
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

INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`)
SELECT DISTINCT 2, 0, `creatureId`
FROM `creature_temp_group`;

DROP TABLE `creature_temp_group`;

-- Create gameobject dynamic spawns group (gameobjects with quest items, or subjects of quests with less than 30min spawn time)

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

INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`)
SELECT DISTINCT 2, 1, `gameobjectId`
FROM `gameobject_temp_group`;

DROP TABLE `gameobject_temp_group`;
ALTER TABLE `gameobject_temp_group_ids` DROP INDEX `entryid`;
DROP TABLE `gameobject_temp_group_ids`;

-- Add mining nodes/herb nodes to profession node group
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`)
SELECT 4, 1, `guid`
FROM `gameobject` g
INNER JOIN `gameobject_template` gt
	ON gt.`entry` = g.`id`
WHERE `type` = 3
AND `Data0` IN (2, 8, 9, 10, 11, 18, 19, 20, 21, 22, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 38, 39, 40, 41, 42, 45, 47, 48, 49, 50, 51, 379, 380, 399, 400, 439, 440, 441, 442, 443, 444, 519, 521, 719, 939, 1119, 1120, 
              1121, 1122, 1123, 1124, 1632, 1639, 1641, 1642, 1643, 1644, 1645, 1646, 1649, 1650, 1651, 1652, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793, 1800, 1860);

-- Add Escort NPCs
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(3, 0, 10873),
(3, 0, 17874),
(3, 0, 40210),
(3, 0, 11348),
(3, 0, 93301),
(3, 0, 93194),
(3, 0, 19107),
(3, 0, 21692),
(3, 0, 21584),
(3, 0, 23229),
(3, 0, 24268),
(3, 0, 21594),
(3, 0, 14387),
(3, 0, 50381),
(3, 0, 15031),
(3, 0, 26987),
(3, 0, 29241),
(3, 0, 32333),
(3, 0, 33115),
(3, 0, 37085),
(3, 0, 41759),
(3, 0, 84459),
(3, 0, 78685),
(3, 0, 62090),
(3, 0, 72388),
(3, 0, 86832),
(3, 0, 67040),
(3, 0, 78781),
(3, 0, 65108),
(3, 0, 63688),
(3, 0, 59383),
(3, 0, 63625),
(3, 0, 70021),
(3, 0, 82071),
(3, 0, 117903),
(3, 0, 111075),
(3, 0, 101136),
(3, 0, 101303),
(3, 0, 122686),
(3, 0, 117065),
(3, 0, 202337),
(3, 0, 2017),
(3, 0, 132683);
-- remove potential duplicates
DELETE FROM `spawn_group` WHERE `groupId` != 3 AND `spawnType`=0 AND `spawnId` IN (SELECT `spawnId` FROM (SELECT `spawnId` FROM `spawn_group` WHERE `groupId`=3  AND `spawnType`=0) as `temp`);
DELETE FROM `spawn_group` WHERE `groupId` != 4 AND `spawnType`=1 AND `spawnId` IN (SELECT `spawnId` FROM (SELECT `spawnId` FROM `spawn_group` WHERE `groupId`=4  AND `spawnType`=1) as `temp`);


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

-- Add new trinity strings for extra npc/gobject info lines
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 5070 AND 5082;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5070, 'Spawn group: %s (ID: %u, Flags: %u, Active: %u)'),
(5071, 'Compatibility Mode: %u'),
(5072, 'GUID: %s'),
(5073, 'SpawnID: %u, location (%f, %f, %f)'),
(5074, 'Distance from player %f'),
(5075, 'Spawn group %u not found'),
(5076, 'Spawned a total of %zu objects:'),
(5077, 'Listing %s respawns within %uyd'),
(5078, 'Listing %s respawns for %s (zone %u)'),
(5079, 'SpawnID | Entry | GridXY| Zone | Respawn time (Full)'),
(5080, 'overdue'),
(5081, 'creatures'),
(5082, 'gameobjects');

-- Add new NPC/Gameobject commands
DELETE FROM `command` WHERE `name` IN ('npc spawngroup', 'npc despawngroup', 'gobject spawngroup', 'gobject despawngroup', 'list respawns');
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('npc spawngroup', 856, 'Syntax: .npc spawngroup $groupId [ignorerespawn] [force]'),
('npc despawngroup', 857, 'Syntax: .npc despawngroup $groupId [removerespawntime]'),
('gobject spawngroup', 858, 'Syntax: .gobject spawngroup $groupId [ignorerespawn] [force]'),
('gobject despawngroup', 859, 'Syntax: .gobject despawngroup $groupId [removerespawntime]'),
('list respawns', 860, 'Syntax: .list respawns [distance]

Lists all pending respawns within <distance> yards, or within current zone if not specified.');

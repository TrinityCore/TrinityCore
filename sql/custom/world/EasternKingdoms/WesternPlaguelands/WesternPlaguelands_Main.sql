-- Western Plaguelands Fixes

-- NPC: 1835 Scarlet Invoker
-- NPC: 44483 Kirtonos the Herald
-- NPC: 50937 Hamhide
-- NPC: 1847 Foulmane
-- NPC: 50345 Alit

-- Difficulty Fixes
DELETE FROM `creature_template_difficulty` WHERE Entry IN (1847,51058,50345,45129) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (1847,51058,50345,45129) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 25 WHERE Entry IN (50937);
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 | 0x20000000 WHERE Entry IN (44483,50345);

-- Template Fixes
UPDATE `creature_template` SET `unit_flags3` = 8193 WHERE `entry` = 1835;

-- Template Addon Fixes
UPDATE creature_template_addon SET StandState = 7 WHERE Entry = 1835;
UPDATE creature_template_addon SET emote = 1008 WHERE Entry = 44435;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 1841;
INSERT INTO `creature_text` VALUES
(1841, 0, 0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 0, 10677, 0, 'Scarlet Executioner'),
(1841, 1, 0, 'Finally out from under the boot of that she-witch Abbendis, and free to pursue my own interests: BLOOD, BLOOD, AND MORE BLOOD!', 14, 0, 100, 0, 0, 0, 0, 50917, 0, 'Scarlet Executioner');

-- SAI
UPDATE creature_template SET AIName = 'SmartAI' WHERE `Entry` IN (1841);
DELETE FROM smart_scripts WHERE entryorguid = 1841 AND source_type = 0;
INSERT INTO smart_scripts VALUES
(1841, 0, 0, 0, '', 2, 0, 100, 1, 0, 30, 0, 0, 0, '', 11, 8599, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - Between 0-30% Health - Cast Enrage'),
(1841, 0, 1, 0, '', 9, 0, 100, 0, 0, 5, 9000, 14000, 0, '', 11, 16856, 0, 0, 0, 0, 0, 0, '', 2, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - Within 0-5 Range - Cast Mortal Strike'),
(1841, 0, 2, 0, '', 9, 0, 100, 0, 0, 5, 5000, 9000, 0, '', 11, 15284, 0, 0, 0, 0, 0, 0, '', 2, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - Within 0-5 Range - Cast Cleave'),
(1841, 0, 3, 0, '', 2, 0, 100, 1, 0, 15, 0, 0, 0, '', 25, 1, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - Between 0-15% Health - Flee For Assist (No Repeat)'),
(1841, 0, 4, 0, '', 2, 0, 100, 1, 0, 30, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - Between 0-30% Health - Say Line 0 (No Repeat)'),
(1841, 0, 5, 0, '', 4, 0, 100, 1, 0, 0, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'Scarlet Executioner - On Aggro - Say Line 1 (No Repeat)');

-- Creature Spawns
SET @CGUID := 900000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1225 AND @CGUID+1229;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `phaseId`, `phaseGroup`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
-- Scarlet Executioner
(@CGUID+1225, 1841, 0, 28, 190, 0, 0, 0, 0, 1, 2839.28, -1395, 147.547, 3.998, 3600),
(@CGUID+1226, 1841, 0, 28, 5421, 0, 0, 0, 0, 1, 2205.82, -1777.8, 62.1064, 1.63258, 3600),
-- The Husk
(@CGUID+1227, 1851, 0, 28, 28, 0, 0, 0, 0, 0, 2358.1, -2244, 56.844, 2.703, 3600),
(@CGUID+1228, 1851, 0, 28, 2297, 0, 0, 0, 0, 0, 988.134, -2304.67, 58.0165, 2.66703, 3600),
-- Parasitus
(@CGUID+1229, 51029, 0, 28, 2297, 0, 0, 0, 0, 0, 1290.95, -2214.66, 12.7403, 4.16055, 3600);


SET @POOLID := 900000;
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+7 AND @POOLID+8;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+7, 1, 'Western Plaguelands - Scarlet Executioner'),
(@POOLID+8, 1, 'Western Plaguelands - The Husk');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID+7 AND @POOLID+8;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+1225, @POOLID+7, 0, 'Western Plaguelands - Scarlet Executioner'),
(0, @CGUID+1226, @POOLID+7, 0, 'Western Plaguelands - Scarlet Executioner'),
(0, @CGUID+1227, @POOLID+8, 0, 'Western Plaguelands - The Husk'),
(0, @CGUID+1228, @POOLID+8, 0, 'Western Plaguelands - The Husk');

-- Creature Addons
DELETE FROM creature_addon WHERE guid IN (328667,328668,328608,328609,328610,328531,328279,328281,328280,328278,328285);
INSERT INTO creature_addon (guid, StandState) VALUES (328667, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (328668, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (328608, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (328609, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (328610, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (328531, 7);
INSERT INTO creature_addon (guid, emote) VALUES
    (328279, 233),
    (328281, 233),
    (328280, 233),
    (328278, 233),
    (328285, 233);

UPDATE creature SET `unit_flags` = 537133824, `unit_flags3` = 8192 WHERE guid IN (328667,328668,328608,328609,328610,328531);

-- Remove Duplicate/Wrong spawns
DELETE FROM creature WHERE id = 44836 AND guid = 328618;
DELETE FROM creature WHERE id = 44323 AND guid = 328331;

-- Creature Position Fixes
-- 44435/argent-lumberjack
UPDATE creature SET position_x = 2438.8713, position_y = -1617.9844, position_z = 106.45748, orientation = 4.693958 WHERE guid = 328371;
UPDATE creature SET position_x = 2393.5945, position_y = -1534.2042, position_z = 103.336426, orientation = 2.7489376 WHERE guid = 328179;
UPDATE creature SET position_x = 2396.4932, position_y = -1530.8401, position_z = 102.477905, orientation = 2.3471854 WHERE guid = 328178;
-- 45162/hearthglen-trainee
UPDATE creature SET position_x = 2897.3613, position_y = -1521.0454, position_z = 146.31668, orientation = 2.0242624 WHERE guid = 328231;

-- Creature Random Movement
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    44284,
    44478,
    44479,
    1817,
    44482,
	1802,
    1804,
    44483,
    1824,
    1822,
    44432,
    44476,
    1815,
    44473,
    44475,
    44551,
	44474,
	45166,
	4472,
	44483,
	45212,
    50345,
	51029,
    44444,
    44443
);

UPDATE creature
SET MovementType = 1,
    wander_distance = 4
WHERE guid IN (
    328297,
    328244,
	1851
);


UPDATE creature
SET MovementType = 1
WHERE guid IN (
    328855,
    328859
);

UPDATE creature
SET wander_distance = 6
WHERE guid IN (
    328855,
    328859
);

UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE guid IN (
	328896,
    328846,
    328374,
    328383,
    328378,
    328379,
    328412,
    328507,
    328506,
    328252,
    328402,
    328202,
    328197,
    328198,
    328199,
    328200,
    328201,
    328248,
    328254,
    328258
);

-- Remove movement for dead creatures
UPDATE `creature` SET MovementType = 0 AND wander_distance = 0 WHERE guid IN (328608,328609,328610,328531);
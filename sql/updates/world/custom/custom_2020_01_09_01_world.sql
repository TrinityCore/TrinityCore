UPDATE `spawn_group_template` SET `groupName`= 'Shadownfang Keep - Commander Springvale Horde Troups' WHERE `groupId`= 428;
DELETE FROM `spawn_group_template` WHERE `groupId` IN (429, 430);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(429, 'Shadowfang Keep - Commander Springvale - Deathstalker Commander Belmont', 4),
(430, 'Shadowfang Keep - Lord Walden - Deathstalker Commander Belmont', 4);

UPDATE `spawn_group` SET `groupId`= 430 WHERE `spawnType`= 0 AND `spawnId`= 395384;

SET @CGUID := 395385;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 47294, 33, 209, 0, 3, 169, 0, 0, 0, -137.918, 2169.69, 136.6613, 2.775074, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- High Warlord Cromush (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 47293, 33, 209, 0, 3, 169, 0, 0, 0, -264.7126, 2269.896, 97.17555, 5.929502, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(428, 0, @CGUID+0),
(429, 0, @CGUID+1);

SET @CGUID := 396673;
DELETE FROM `creature` WHERE `guid`= @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 10808, 329, 5916, 0, 1, 169, 0, 0, 0, 3729.45068359375, -3263.729736328125, 128.183258056640625, 3.28591012954711914, 7200, 5, 0, 49750, 0, 1, 0, 0, 0, 15595); -- 10808 (Area: 0 - Difficulty: 1)

DELETE FROM `spawn_group_template` WHERE `groupId`= 461;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(461, 'Stratholme - Timmy the Cruel', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 461;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(461, 0, @CGUID+0);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= 461;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(329, 1, 17, 461, 1);

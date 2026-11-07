--
SET @CGUID := 147526; -- 3
SET @SPAWN_GROUP_ID := 416; -- 3

-- Pandemonius
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pandemonius_void_blast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32325, 'spell_pandemonius_void_blast'),
(38760, 'spell_pandemonius_void_blast');

UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1 WHERE `id` = 18341;

-- Shaffar
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0,18431,557,0,0,3,1,0,0,-179.433,9.06982,16.7108,5.13499,86400,3,0,0,0,1,0,0,0,'',NULL,0),
(@CGUID+1,18431,557,0,0,3,1,0,0,-187.271,15.3965,16.7227,1.21272,86400,3,0,0,0,1,0,0,0,'',NULL,0),
(@CGUID+2,18431,557,0,0,3,1,0,0,-188.619,5.124,16.771,3.24971,86400,3,0,0,0,1,0,0,0,'',NULL,0);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+2 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+0),
(@SPAWN_GROUP_ID+1,0,@CGUID+1),
(@SPAWN_GROUP_ID+2,0,@CGUID+2);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+2;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Mana-Tombs - Ethereal Beacon 000",4), -- 416
(@SPAWN_GROUP_ID+1,"Mana-Tombs - Ethereal Beacon 001",4), -- 417
(@SPAWN_GROUP_ID+2,"Mana-Tombs - Ethereal Beacon 002",4); -- 418

DELETE FROM `creature_formations` WHERE `leaderGUID` = 91162;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(91162,91162,0,0,3,0,0),
(91162,@CGUID+0,0,0,3,0,0),
(91162,@CGUID+1,0,0,3,0,0),
(91162,@CGUID+2,0,0,3,0,0);

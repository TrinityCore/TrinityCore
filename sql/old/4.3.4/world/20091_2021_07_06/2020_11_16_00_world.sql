SET @CGUID := 396548;
SET @GROUPID := 453;
DELETE FROM `spawn_group_template` WHERE `groupId`= @GROUPID;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@GROUPID, 'Scarlet Monastery - Alliance Spawns', 4);

DELETE FROM `spawn_group` WHERE `groupId`= @GROUPID;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) 
SELECT @GROUPID, 0, `guid` FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20 AND `guid` NOT IN (@CGUID+5, @CGUID+15, @CGUID+16);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= @GROUPID;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(189, 0, 37, @GROUPID, 0x1 | 0x4);

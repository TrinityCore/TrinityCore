UPDATE `instance_template` SET `parent`= 732 WHERE `map`= 757;

SET @SPAWNGROUP := 443;
DELETE FROM `spawn_group_template` WHERE `groupId`= @SPAWNGROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Baradin Hold - Alizabal Trash', 4);

DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, 266710),
(@SPAWNGROUP+0, 0, 266690);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 757;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(757, 2, 17, @SPAWNGROUP+0, 1); -- Enable group when Alizabal is not DONE

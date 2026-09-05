--
SET @SPAWN_GROUP_ID := 419; -- 4

UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+0 WHERE `spawnId` = 81651 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+1 WHERE `spawnId` = 81652 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+2 WHERE `spawnId` = 81643 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+3 WHERE `spawnId` = 48348 AND `spawnType` = 0;

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Gruul's Lair - Krosh Firehand",4), -- 419
(@SPAWN_GROUP_ID+1,"Gruul's Lair - Olm the Summoner",4), -- 420
(@SPAWN_GROUP_ID+2,"Gruul's Lair - Kiggler the Crazed",4), -- 421
(@SPAWN_GROUP_ID+3,"Gruul's Lair - Blindeye the Seer",4); -- 422

--
DELETE FROM `creature_text` WHERE `CreatureID`=26532 AND `GroupID`=4;
DELETE FROM `spawn_group` WHERE `groupId`=52;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES (52, 0, 111214);

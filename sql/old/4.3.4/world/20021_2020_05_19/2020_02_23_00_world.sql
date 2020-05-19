-- Houndmaster Loksey
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x800 WHERE `entry`= 3974;

DELETE FROM `spawn_group_template` WHERE `groupId`= 433;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(433, 'Scarlet Monastry - Houndmaster Loksey - Scarlet Tracking Hounds', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 433;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(433, 0, 40089),
(433, 0, 40091),
(433, 0, 40090);

DELETE FROM `spawn_group_template` WHERE `groupId` IN (52, 53);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(52, 'Bastion of Twilight - Halfus Wyrmbreaker', 4),
(53, 'Bastion of Twilight - Ascendant Council', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (52, 53);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Halfus Wyrmbreaker
(52, 0, 253860),
(52, 0, 253877),
(52, 0, 253862),
(52, 0, 253880),
(52, 0, 253850),
(52, 0, 253851),
(52, 0, 253852),
(52, 0, 253853),
(52, 0, 253854),
(52, 0, 253855),
(52, 0, 253856),
(52, 0, 253857),
(52, 0, 253858),
(52, 0, 253859),
(52, 0, 253875),
(52, 0, 253879),
(52, 0, 253882),
(52, 0, 253883),
(52, 0, 253884),
(52, 0, 253885),
(52, 0, 253886),
(52, 0, 253887),
(52, 0, 253888),
(52, 0, 253889),
(52, 0, 253890),
(52, 0, 253891),
(52, 0, 253870),
(52, 1, 211098),
(52, 1, 211085),
-- Ascendant Council
(53, 0, 254144),
(53, 0, 254133),
(53, 0, 254134),
(53, 0, 254148);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` IN (52, 53);
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(671, 0, 23, 52, 1),
(671, 2, 23, 53, 1);

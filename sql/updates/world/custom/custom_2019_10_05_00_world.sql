-- Spawn Group
DELETE FROM `spawn_group_template` WHERE `groupId` IN (409, 410);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(409, 'The Deadmines - Alliance Entrance', 4),
(410, 'The Deadmines - Horde Entrance', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (409, 410);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(409, 0, 376219),
(409, 0, 376230),
(409, 0, 376222),
(409, 0, 376220),
(409, 0, 376228),
(409, 0, 376224),
(409, 0, 376231),
(409, 0, 376226),
(409, 0, 376223),
(409, 0, 376217),
(409, 0, 376229),
(409, 0, 376216),
(409, 0, 376227),
(409, 0, 376225),
(409, 0, 376221),
(409, 0, 376218),
(410, 0, 376071),
(410, 0, 376076),
(410, 0, 376074),
(410, 0, 376069),
(410, 0, 376070),
(410, 0, 376073),
(410, 0, 376075),
(410, 0, 376092),
(410, 0, 376072),
(410, 0, 376077);

-- Standardize respawn time
UPDATE `creature` SET `spawntimesecs` = 7200 WHERE `id` BETWEEN 20031 AND 20052 AND `map` = 550;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (12999,15384,22517) AND `map` = 550;
UPDATE `gameobject` SET `spawntimesecs` = 300 WHERE `id` IN (184069,184324,184325,184326,184327,184328,184329,184596,184597) AND `map` = 550;

-- Repair linked respawn
UPDATE `spawn_group` SET `groupId` = 46 WHERE `spawnId` IN (12466,12468) AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = 45 WHERE `spawnId` IN (12543,12544) AND `spawnType` = 0;
DELETE FROM `spawn_group` WHERE `spawnId` IN (84484,84444,75558,64992,64991,64988,48255,64990,64989,64993) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(45,0,84484),
(45,0,84444),
(45,0,75558),
(44,0,64992),
(44,0,64991),
(44,0,64988),
(44,0,48255),
(44,0,64990),
(44,0,64989),
(44,0,64993);

--
DELETE FROM `creature_equip_template` WHERE `entry` IN (38781,38363,37694,36458,37067,35175);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`, `VerifiedBuild`) VALUES
(38781, 1, 2714, 0, 0, 0),
(38363, 1, 0, 0, 34034, 0),
(37694, 1, 2901, 0, 0, 0),
(36458, 1, 25646, 0, 0, 0),
(37067, 1, 2695, 0, 0, 0),
(35175, 1, 2202, 0, 0, 0);

UPDATE `creature_addon` SET `bytes2` = 1, `emote` = 333 WHERE `guid` IN (280020, 280019, 280001, 280003, 279956, 279945, 279928, 279914, 279906, 279894, 279893, 279888, 280008, 280002);

DELETE FROM `creature_addon` WHERE `guid` = 280018;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(280018, 0, 0, 0, 1, 333, 0, 0, 0, 0, NULL);

-- 
DELETE FROM `creature` WHERE `guid` IN (87023);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(87023, 3509, 0, 1, 1, 0, 0, -8838.52, 670.28, 98.0987, 0.553153, 300);

DELETE FROM `creature_formations` WHERE `leaderGUID`=84028 AND `memberGUID`=87023;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(84028, 87023, 3, 120, 515);

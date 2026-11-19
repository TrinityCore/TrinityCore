--
DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` = 54114;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 54114, 64, 0, 0, 'Heart of the Phoenix uses Cooldown, but won''t work through LoS, so ignore LoS.');

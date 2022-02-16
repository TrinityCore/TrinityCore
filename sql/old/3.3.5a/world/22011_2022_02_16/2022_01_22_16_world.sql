--
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=787;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 787, 0, "", "", "Deprecated quest: The New Horde");

-- re-add ignore LOS, still needed on certain coordinates
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=69922;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,69922,64,'','','Ignore LOS on Temper Quel Delar');

-- 
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=526;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,526,0,"","","Deprecated quest");

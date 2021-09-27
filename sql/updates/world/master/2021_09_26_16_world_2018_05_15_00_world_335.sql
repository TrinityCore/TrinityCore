-- 
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (4485,4486);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,4485,0,"","","Deprecated quest"),
(1,4486,0,"","","Deprecated quest");

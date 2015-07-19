DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=35113;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 35113, 64, '', '', 'Ignore LOS on Warp Measurement');

-- 
DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` IN (17639, 29443);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 17639, 256, 0, 0, 'Wail of the Banshee'),
(0, 29443, 256, 0, 0, 'Clutch of Foresight');

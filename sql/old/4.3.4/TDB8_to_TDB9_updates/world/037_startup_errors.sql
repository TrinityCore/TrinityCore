--
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (11934,24688);
INSERT INTO `disables` (`sourceType`, `entry`, `params_0`, `params_1`, `comment`) VALUES
(1, 11934, 0, 0, 'Never implemented quest'),
(1, 24688, 0, 0, 'Never implemented quest');

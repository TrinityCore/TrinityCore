DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN(7181,7202,7381,7382);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(1, 7181, 0, '', '', 'Deprecated quest'),
(1, 7202, 0, '', '', 'Deprecated quest'),
(1, 7381, 0, '', '', 'Deprecated quest'),
(1, 7382, 0, '', '', 'Deprecated quest');

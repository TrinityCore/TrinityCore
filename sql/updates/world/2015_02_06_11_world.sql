--
DELETE FROM `disables` WHERE `entry` IN (649,650) AND `sourceType` = 7;
DELETE FROM `disables` WHERE `entry` = 650 AND `sourceType` = 2;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(7, 649, 0, '', '', 'Disable mmaps - Trial of the Crusader'),
(7, 650, 0, '', '', 'Disable mmaps - Trial of the Champion'),
(2, 650, 3, '', '', 'Disable Trial of the Champion, broken instance');

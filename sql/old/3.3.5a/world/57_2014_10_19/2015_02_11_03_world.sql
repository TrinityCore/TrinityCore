--
DELETE FROM `disables` WHERE `sourceType` =0 AND `entry` IN (71599, 71024) AND `flags`=64;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 71599, 64, '', '', 'Ignore LOS for Cosmetic - Explosion (Chemical Wagon)'),
(0, 71024, 64, '', '', 'Ignore LOS for Throw Bomb');

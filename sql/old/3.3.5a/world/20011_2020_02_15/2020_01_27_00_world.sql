-- 
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (54612);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 54612, 64, '', '', 'Chained Peasant (Chest) LOS');

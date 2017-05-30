DELETE FROM `disables` WHERE  `sourceType`=0 AND `entry` IN(2825, 32182);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES
(0, 2825, 64, 'Ignore LOS for Heroism'),
(0, 32182, 64, 'Ignore LOS for Bloodlust');

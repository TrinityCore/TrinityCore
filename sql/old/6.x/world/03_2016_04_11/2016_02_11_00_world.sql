-- 
DELETE FROM `spell_target_position`  WHERE `ID` IN (159895,159896,159897,159898,159899,159900,159901,159902);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES 
(159895, 0, 1116, 7263.71, 4453.39, 129.221, 20779), -- Path of the Bloodmaul
(159896, 0, 1116, 8850.58, 1370.09,  97.097, 20779), -- Path of the Iron Prow
(159897, 0, 1116, 1489.18,  3075.6, 109.725, 20779), -- Path of the Vigilant
(159898, 0, 1116, 32.4602, 2527.42, 103.606, 20779), -- Path of the Skies
(159899, 0, 1116, 762.092, 130.033, 7.53102, 20779), -- Path of the Crescent Moon
(159900, 0, 1116, 7811.06, 542.615, 122.757, 20779), -- Path of the Dark Rail
(159901, 0, 1116, 7117.57,   197.1, 145.211, 20779), -- Path of the Verdant
(159902, 0,    0,-7508.83,-1326.77, 301.364, 20779); -- Path of the Burning Mountain

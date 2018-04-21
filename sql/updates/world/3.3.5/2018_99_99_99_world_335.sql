-- Stratholme - Baron Rivendare - Set position for each Raise Dead spell (1-6)
DELETE FROM `spell_target_position` WHERE `ID` BETWEEN 17475 AND 17480;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(17475, 0, 0, 4017.403809, -3339.703369, 115.057655, 5.487860, 0),
(17476, 0, 0, 4013.189209, -3351.808350, 115.052254, 0.134280, 0),
(17477, 0, 0, 4017.738037, -3363.478016, 115.057274, 0.723313, 0),
(17478, 0, 0, 4048.877197, -3363.223633, 115.054253, 3.627735, 0),
(17479, 0, 0, 4051.777588, -3350.893311, 115.055351, 3.066176, 0),
(17480, 0, 0, 4048.375977, -3339.966309, 115.055222, 2.457497, 0);

-- Stratholme - Baron Rivendare - Kill Skeleton (if alive) and Heal himself
DELETE FROM `conditions` WHERE `SourceEntry` = 17471;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES 
(13, 0, 17471, 0, 0, 29, 1, 11197, 0, 1, 0, 0, 0, 'Stratholme - Baron Rivendare - Kill Skeleton (if alive) and Heal himself)';

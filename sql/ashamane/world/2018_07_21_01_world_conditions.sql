DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 179335;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`) VALUES
(17, 179335, 1, 31, 1, 3, 89024),
(17, 179335, 2, 31, 1, 3, 89025),
(17, 179335, 3, 31, 1, 3, 89802),
(17, 179335, 4, 31, 1, 3, 89803);

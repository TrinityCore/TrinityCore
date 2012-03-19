DELETE FROM `conditions` WHERE `SourceEntry` IN (69705, 69400, 69402, 70175, 70374, 70383);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 69705, 0, 0, 31, 0, 3, 36838, 0, 0, 0, '', NULL),
(13, 1, 69705, 0, 1, 31, 0, 3, 36839, 0, 0, 0, '', NULL),
(13, 3, 69400, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 3, 69402, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 3, 69402, 0, 1, 31, 0, 3, 37215, 0, 0, 0, '', NULL),
(13, 3, 70175, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 3, 70175, 0, 1, 31, 0, 3, 37215, 0, 0, 0, '', NULL),
(13, 1, 70374, 0, 0, 31, 0, 3, 37540, 0, 0, 0, '', NULL),
(13, 1, 70383, 0, 0, 31, 0, 3, 37215, 0, 0, 0, '', NULL);

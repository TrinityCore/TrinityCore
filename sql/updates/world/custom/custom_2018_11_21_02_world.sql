DELETE FROM `conditions` WHERE `SourceEntry`IN (84651, 93117, 93118, 93119) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 7, 84651, 0, 0, 31, 0, 3, 45812, 0, 0, 0, '', 'Zephyr - Target Ravenous Creeper'),
(13, 7, 93117, 0, 0, 31, 0, 3, 45812, 0, 0, 0, '', 'Zephyr - Target Ravenous Creeper'),
(13, 7, 93118, 0, 0, 31, 0, 3, 45812, 0, 0, 0, '', 'Zephyr - Target Ravenous Creeper'),
(13, 7, 93119, 0, 0, 31, 0, 3, 45812, 0, 0, 0, '', 'Zephyr - Target Ravenous Creeper');

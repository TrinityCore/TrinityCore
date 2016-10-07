--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (13538, 13539);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13538, 0, 0, 48, 0, 0, 0, 0, 1, 0, 0, "", "Alliance quest 'Southern Sabotage' is available if Wintergrasp is held by Alliance"),
(20, 0, 13538, 0, 0, 48, 0, 0, 0, 0, 1, 0, 0, "", "Quest mark for Alliance quest 'Southern Sabotage' is available if Wintergrasp is held by Alliance"),
(19, 0, 13539, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, "", "Horde quest 'Toppling the Towers' is available if Wintergrasp is held by Horde"),
(20, 0, 13539, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, "", "Quest mark for Horde quest 'Toppling the Towers' is available if Wintergrasp is held by Horde");

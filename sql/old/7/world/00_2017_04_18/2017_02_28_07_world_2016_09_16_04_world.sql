--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry` IN (36742, 36746) AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 26349, 36742, 0, 1, 8, 0, 12005, 0, 0, 0, 0, 0, "", "Item 'Goramosh's Strange Device' can drop if quest 'Prevent the Accord' is rewarded"),
(1, 26349, 36746, 0, 1, 8, 0, 12005, 0, 0, 0, 0, 0, "", "Item 'Goramosh's Strange Device' can drop if quest 'Prevent the Accord' is rewarded");

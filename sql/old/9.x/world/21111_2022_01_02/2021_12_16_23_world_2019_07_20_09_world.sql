--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=59564;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 59564, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, "", "Spell Flatulate hits Icy Ghoul"),
(13, 3, 59564, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, "", "Spell Flatulate hits Vicious Geist"),
(13, 3, 59564, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, "", "Spell Flatulate hits Risen Alliance Soldier");

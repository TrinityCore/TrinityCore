-- 
DELETE FROM `conditions` WHERE `SourceEntry`=53349 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 53349, 0, 0, 31, 1, 3, 29106, 0, 0, 0, 0, "", "Arrow Assault targets Death Knight Champion"),
(17, 0, 53349, 0, 1, 31, 1, 3, 29115, 0, 0, 0, 0, "", "Arrow Assault targets Rampaging Abomination"),
(17, 0, 53349, 0, 2, 31, 1, 3, 29136, 0, 0, 0, 0, "", "Arrow Assault targets Volatile Ghoul"),
(17, 0, 53349, 0, 3, 31, 1, 3, 28670, 0, 0, 0, 0, "", "Arrow Assault targets Frostbrood Vanquisher");

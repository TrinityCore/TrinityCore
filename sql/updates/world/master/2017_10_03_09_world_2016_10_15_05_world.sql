--
DELETE FROM `conditions` WHERE `SourceEntry`=53349;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 53349, 0, 0, 31, 0, 3, 29106, 0, 0, 0, 0, "", "Arrow Assault targets Death Knight Champion"),
(13, 1, 53349, 0, 1, 31, 0, 3, 29115, 0, 0, 0, 0, "", "Arrow Assault targets Rampaging Abomination"),
(13, 1, 53349, 0, 2, 31, 0, 3, 29136, 0, 0, 0, 0, "", "Arrow Assault targets Volatile Ghoul"),
(13, 1, 53349, 0, 3, 31, 0, 3, 28670, 0, 0, 0, 0, "", "Arrow Assault targets Frostbrood Vanquisher");

DELETE FROM `creature_text` WHERE `entry` IN (28609, 28611) AND `id`=6;

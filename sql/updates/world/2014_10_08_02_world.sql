DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=48046;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 48046, 0, 0, 31, 1, 3, 26408, 0, 0, 0, 0, '', "Use Camera targets Iron Rune-Smith"),
(17, 0, 48046, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', "Target must be dead"),
(17, 0, 48046, 0, 1, 31, 1, 3, 26414, 0, 0, 0, 0, '', "Use Camera targets Runic Lightning Gunner"),
(17, 0, 48046, 0, 1, 36, 1, 0, 0, 0, 1, 0, 0, '', "Target must be dead"),
(17, 0, 48046, 0, 2, 31, 1, 3, 27177, 0, 0, 0, 0, '', "Use Camera targets Iron Rune Overseer"),
(17, 0, 48046, 0, 2, 36, 1, 0, 0, 0, 1, 0, 0, '', "Target must be dead");

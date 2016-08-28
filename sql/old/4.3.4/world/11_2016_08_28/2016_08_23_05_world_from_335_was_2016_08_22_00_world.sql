--
DELETE FROM `conditions` WHERE `SourceEntry`=42793 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 42793, 0, 0, 31, 0, 3, 24009, 0, 0, 0, 0, "", "Spell Burn Body targets Alliance Corpse"),
(13, 1, 42793, 0, 1, 31, 0, 3, 24010, 0, 0, 0, 0, "", "Spell Burn Body targets Forsaken Corpse");

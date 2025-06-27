-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=66588 AND ConditionTypeOrReference=46;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 66588, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, '', "Flaming Spear could be casted only if the player is in taxi"),
(17, 0, 66588, 0, 1, 46, 0, 0, 0, 0, 0, 0, 0, '', "Flaming Spear could be casted only if the player is in taxi");

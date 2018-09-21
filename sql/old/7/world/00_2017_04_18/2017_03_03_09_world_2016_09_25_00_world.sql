--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=33836;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 33836, 0, 0, 31, 0, 3, 19397, 0, 0, 0, 0, "", "Spell 'Dropping Heavy Bomb' can only hit 'Mo'arg Overseer' OR"),
(13, 3, 33836, 0, 1, 31, 0, 3, 19398, 0, 0, 0, 0, "", "Spell 'Dropping Heavy Bomb' can only hit 'Gan'arg Peon' OR"),
(13, 3, 33836, 0, 2, 31, 0, 3, 19399, 0, 0, 0, 0, "", "Spell 'Dropping Heavy Bomb' can only hit 'Fel Cannon Destroyed'");

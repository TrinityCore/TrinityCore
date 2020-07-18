-- Quest "Fire Sapta"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=1464 AND `ConditionTypeOrReference`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,1464,0,0,2,0,6636,1,1,1,0,0,"","Quest 'Fire Sapta' can only be taken if player does not have item 'Fire Sapta'");

-- Quest "Water Sapta"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=972;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,972,0,0,14,0,96,0,0,0,0,0,"","Quest 'Water Sapta' can only be taken if quest 'Call of Water (Part 9)' is not taken"),
(19,0,972,0,0,2,0,6637,1,1,1,0,0,"","Quest 'Water Sapta' can only be taken if player does not have item 'Water Sapta'");

-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (72260, 72278, 72279, 72280);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 72260, 0, 0, 31, 0, 3, 37813, 0, 0, 0, 0, '', 'Deathbringer Saurfang - Mark of the Fallen Champion heal'),
(13, 1, 72278, 0, 0, 31, 0, 3, 37813, 0, 0, 0, 0, '', 'Deathbringer Saurfang - Mark of the Fallen Champion heal'),
(13, 1, 72279, 0, 0, 31, 0, 3, 37813, 0, 0, 0, 0, '', 'Deathbringer Saurfang - Mark of the Fallen Champion heal'),
(13, 1, 72280, 0, 0, 31, 0, 3, 37813, 0, 0, 0, 0, '', 'Deathbringer Saurfang - Mark of the Fallen Champion heal');

-- Fix taking of 6962/7025 Treats for Great-father Winter 
-- Horde
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=6962;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) and `SourceEntry`IN(6962);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(20, 0, 6962, 0, 0, 8, 0, 7021, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(19, 0, 6962, 0, 0, 8, 0, 7021, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(20, 0, 6962, 0, 1, 8, 0, 7024, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(19, 0, 6962, 0, 1, 8, 0, 7024, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(20, 0, 6962, 0, 2, 8, 0, 6961, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(19, 0, 6962, 0, 2, 8, 0, 6961, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed');

-- Alliance
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=7025;
UPDATE `creature_queststarter` SET `id`='13433' WHERE `id`='13429' and`quest`='7022';

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) and `SourceEntry`IN(7025);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(20, 0, 7025, 0, 0, 8, 0, 7022, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(19, 0, 7025, 0, 0, 8, 0, 7022, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(20, 0, 7025, 0, 1, 8, 0, 7023, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed'),
(19, 0, 7025, 0, 1, 8, 0, 7023, 0, 0, 0, 0, 0, '', 'Treats for Great-father Winter once Great-father Winter is Here! Has been completed');

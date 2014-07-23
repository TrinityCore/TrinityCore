-- Fix for ... and a Batch of Ooze (4294) and ... and a Batch of Ooze (4293)
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=4661; -- Testing for Impurities - Un'Goro Crater
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=4561; -- Testing for Corruption - Felwood

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN (4661,4561);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 4561, 0, 0, 9, 0, 4294, 0, 0, 0, 0, 0, '', 'player needs to be on quest ... and a Batch of Ooze to see Testing for Impurities - UnGoro Crater'),
(19, 0, 4661, 0, 0, 9, 0, 4293, 0, 0, 0, 0, 0, '', 'player needs to be on quest and a batch of slime to see Testing for Corruption - Felwood'),
(20, 0, 4561, 0, 0, 9, 0, 4294, 0, 0, 0, 0, 0, '', 'player needs to be on quest ... and a Batch of Ooze to see Testing for Impurities - UnGoro Crater'),
(20, 0, 4661, 0, 0, 9, 0, 4293, 0, 0, 0, 0, 0, '', 'player needs to be on quest and a batch of slime to see Testing for Corruption - Felwood');

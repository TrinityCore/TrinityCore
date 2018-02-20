-- Breadcrumb Quest "The Corruption Abroad"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1275;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (3765,1275);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,3765,0,0,14,0,1275,0,0,0,0,0,"","Quest 'The Corruption Abroad' can only be taken if quest 'Researching the Corruption' is not taken"),
(19,0,1275,0,0,28,0,3765,0,0,1,0,0,"","Quest 'Researching the Corruption' can only be taken if quest 'The Corruption Abroad' is not completed");

-- BreadCrumb Quest "Tran'rek"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=2865;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (2864,2865);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,2864,0,0,14,0,2865,0,0,0,0,0,"","Quest 'Tran'rek' can only be taken if quest 'Scarab Shells' is not taken"),
(19,0,2865,0,0,28,0,2864,0,0,1,0,0,"","Quest 'Scarab Shells' can only be taken if quest 'Tran'rek' is not completed");

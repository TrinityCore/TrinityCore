--
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (12692, 12695);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (12692, 12695);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 12692, 0, 0, 43, 0, 12582, 0, 0, 0, 0, 0, "", "Quest 'Return of the Lich Hunter' can be accepted if daily quest 'Frenzyheart Champion' hsa been turned in"),
(20, 0, 12692, 0, 0, 43, 0, 12582, 0, 0, 0, 0, 0, "", "Quest mark for 'Return of the Lich Hunter' can be seen if daily quest 'Frenzyheart Champion' hsa been turned in"),
(19, 0, 12695, 0, 0, 43, 0, 12689, 0, 0, 0, 0, 0, "", "Quest 'Return of the Friendly Dryskin' can be accepted if daily quest 'Hand of the Oracles' has been turned in"),
(20, 0, 12695, 0, 0, 43, 0, 12689, 0, 0, 0, 0, 0, "", "Quest mark for 'Return of the Friendly Dryskin' can be accepted if daily quest 'Hand of the Oracles' has been turned in");

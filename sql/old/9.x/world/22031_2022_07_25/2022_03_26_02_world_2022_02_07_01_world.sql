--
UPDATE `quest_template_addon` SET `NextQuestID`=0, `ExclusiveGroup`=0 WHERE `ID` IN (1282, 1302);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11123 WHERE `ID`=1282;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (1282, 1301);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 1282, 0, 0, 8, 0, 1301, 0, 0, 1, 0, 0, "", "Quest They Call Him Smiling Jim requires quest James Hyal (Part 1) NOT rewarded"),
(19, 0, 1301, 0, 0, 8, 0, 1282, 0, 0, 1, 0, 0, "", "Quest James Hyal (Part 1) requires quest They Call Him Smiling Jim NOT rewarded");

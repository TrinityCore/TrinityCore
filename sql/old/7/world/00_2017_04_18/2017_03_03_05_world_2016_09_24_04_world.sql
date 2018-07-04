--
UPDATE `quest_template_addon` SET `PrevQuestID`=10143 WHERE `ID`=9575;

DELETE FROM `quest_template_addon` WHERE `ID` IN (9558, 10050);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(9558, 10143),
(10050, 10143);

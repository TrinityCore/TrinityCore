--
UPDATE `quest_template_addon` SET `ExclusiveGroup`=12182 WHERE `ID` IN (12182, 12189);

DELETE FROM `quest_template_addon` WHERE `ID` IN (12034, 12063);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(12034, 12008),
(12063, 12036);

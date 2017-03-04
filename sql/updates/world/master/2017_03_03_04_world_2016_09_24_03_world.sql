--
DELETE FROM `quest_template_addon` WHERE `ID` IN (10141, 10160);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(10141, 10254),
(10160, 10254);

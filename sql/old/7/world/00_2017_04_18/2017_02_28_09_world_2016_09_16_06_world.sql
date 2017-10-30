--
DELETE FROM `quest_template_addon` WHERE `ID` IN (12089, 12090, 12091);
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(12089, 12095, -12089),
(12090, 12095, -12089),
(12091, 12095, -12089);

UPDATE `quest_template_addon` SET `PrevQuestID`=12008 WHERE `ID`=12039;
DELETE FROM `quest_template_addon` WHERE `ID` IN (12056, 12100);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(12056, 12008),
(12100, 12008);

UPDATE `quest_template_addon` SET `PrevQuestID`=12066 WHERE `ID`=12096;
UPDATE `quest_template_addon` SET `PrevQuestID`=11916 WHERE `ID`=12033;

UPDATE `quest_template_addon` SET `ExclusiveGroup`=11977 WHERE `ID`=11977;
DELETE FROM `quest_template_addon` WHERE `ID`=11979;
INSERT INTO `quest_template_addon` (`ID`, `ExclusiveGroup`) VALUES
(11979, 11977);

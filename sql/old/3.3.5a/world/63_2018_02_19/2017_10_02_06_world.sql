-- 
UPDATE `quest_template` SET `RewardNextQuest`=12211 WHERE `ID`=12206;
UPDATE `quest_template_addon` SET `PrevQuestID`=12206 WHERE `ID`=12211;
UPDATE `quest_template_addon` SET `PrevQuestID`=12230 WHERE `ID`=12240;
DELETE FROM `quest_template_addon` WHERE `ID` IN (12230, 12234, 12214);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(12230, 12211),
(12234, 12230),
(12214, 12209);

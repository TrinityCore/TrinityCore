-- 
DELETE FROM `quest_template_addon` WHERE `ID` IN (5401, 5405, 5503);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES 
(5401, 0, 0, 5401),(5405, 0, 0, 5401),(5503, 0, 0, 5401);

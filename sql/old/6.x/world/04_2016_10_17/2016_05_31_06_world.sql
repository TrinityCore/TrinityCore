-- 
-- set these quests to be exclusive to the Monk class:
-- Alliance Monk quest Palm of the Tiger (31142)
-- Horde Monk quest Tiger Palm (31147,31157)
DELETE FROM `quest_template_addon` WHERE  `ID` IN (31142,31147,31157);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`NextQuestID`,`ExclusiveGroup`) VALUES
(31142, 10, 31143, 0),
(31147, 10, 31148, 24964),
(31157, 10, 0, 0);

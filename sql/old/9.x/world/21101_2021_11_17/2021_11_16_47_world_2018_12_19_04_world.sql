-- 
DELETE FROM `quest_template_addon` WHERE `ID` IN (12598, 12553, 12584, 12583, 12555, 12552, 12554, 12606);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`NextQuestID`,`ExclusiveGroup`,`ProvidedItemCount`,`SpecialFlags`) VALUES
(12598, -12596, 0, 0, 1, 32),
(12553, 12598, 0, 0, 0, 0),
(12584, 12552, 0, 0, 0, 0),
(12583, 12553, 0, 0, 0, 0),
(12555, 12583, 0, 0, 1, 0),
(12552, 12598, 0, 0, 0, 0),
(12554, 12552, 0, 0, 0, 0),
(12606, 12598, 0, 0, 0, 0);

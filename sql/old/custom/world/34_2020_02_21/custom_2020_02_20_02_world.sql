-- Hero's Call: Westfall
-- Furlbrow's Deed
DELETE FROM `quest_template_addon` WHERE `ID` IN (26378, 28562, 184);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `BreadcrumbForQuestId`) VALUES
(26378, 0, 26209),
(28562, 0, 26209),
(184, 0, 26209);

-- Hero's Call: Redridge Mountains
DELETE FROM `quest_template_addon` WHERE `ID` IN (26365, 28563);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `BreadcrumbForQuestId`) VALUES
(26365, 0, 26503),
(28563, 0, 26503);

-- Hero's Call: Duskwood!
DELETE FROM `quest_template_addon` WHERE `ID` IN (26728, 28564);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `BreadcrumbForQuestId`) VALUES
(26728, 0, 26618),
(28564, 0, 26618);

-- Hero's Call: Northern Stranglethorn Valley
-- Rebels Without a Clue
DELETE FROM `quest_template_addon` WHERE `ID` IN (28699, 26838);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `BreadcrumbForQuestId`) VALUES
(28699, 0, 26735),
(26838, 0, 26735);

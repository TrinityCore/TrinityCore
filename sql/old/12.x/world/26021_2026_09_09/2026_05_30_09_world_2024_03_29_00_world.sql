-- "Artifacts of the Blacksilt" shouldn't have a prevquest requirement
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9549;

-- Breadcrumb quest Fix
DELETE FROM `quest_template_addon` WHERE `ID`=10063;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(10063,9549);

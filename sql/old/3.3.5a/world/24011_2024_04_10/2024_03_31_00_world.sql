-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9491;
DELETE FROM `quest_template_addon` WHERE `ID`=10372;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(10372,9491);

-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9143;
DELETE FROM `quest_template_addon` WHERE `ID`=9145;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(9145,9143);

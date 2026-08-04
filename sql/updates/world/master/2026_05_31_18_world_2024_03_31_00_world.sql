-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9491;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=9491 WHERE `ID`=10372;

-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9143;
DELETE FROM `quest_template_addon` WHERE `ID`=9145;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(9145,9143);

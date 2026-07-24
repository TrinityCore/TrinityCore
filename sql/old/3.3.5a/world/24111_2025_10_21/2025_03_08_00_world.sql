-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=6341;
DELETE FROM `quest_template_addon` WHERE `ID`=6344;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(6344,6341);

-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=5621;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=5621 WHERE `ID`=5622;

-- Breadcrumb quest Fix
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=5921 WHERE `ID` IN (5923,5924,5925);

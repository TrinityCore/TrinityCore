-- Breadcrumb quest Fix
DELETE FROM `quest_template_addon` WHERE `ID`=9035;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(9035,9062);

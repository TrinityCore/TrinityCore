ALTER TABLE `quest_template_addon`
ADD COLUMN `BreadcrumbForQuestId` MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `ExclusiveGroup`;

-- Rejold's New Brew
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 413 WHERE `Id` = 415;
UPDATE `quest_template_addon` SET `PrevQuestID` = 315 WHERE `ID` = 413;

-- To Winterspring! & Starfall
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 5244 WHERE `ID` = 5249;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 5244 WHERE `ID` = 5250;

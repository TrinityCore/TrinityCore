ALTER TABLE `quest_template_addon`
ADD COLUMN `BreadcrumbForQuestId` MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `ExclusiveGroup`;

UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 413 WHERE `Id` = 415;
UPDATE `quest_template_addon` SET `PrevQuestID` = 315 WHERE `ID` = 413;

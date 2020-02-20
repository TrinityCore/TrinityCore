ALTER TABLE `quest_template_addon`
ADD COLUMN `BreadcrumbForQuestId` MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `ExclusiveGroup`;

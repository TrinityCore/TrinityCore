-- 
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=788 WHERE `ID`=4641;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=788 WHERE `ID`=787;
DELETE FROM `quest_template_addon` WHERE `ID` IN (2769);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2769, 2770);

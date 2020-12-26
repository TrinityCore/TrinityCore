UPDATE `quest_template_addon` SET `NextQuestID`='12225' WHERE  `ID` IN (12222, 12223);
UPDATE `quest_template_addon` SET `NextQuestID`='0' WHERE  `ID`=8554;
UPDATE `quest_template_addon` SET `NextQuestID`='0' WHERE  `ID`=618;
UPDATE `quest_template_addon` SET `NextQuestID`='0' WHERE  `ID`=415;
ALTER TABLE `quest_template_addon` CHANGE `NextQuestID` `NextQuestID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0;

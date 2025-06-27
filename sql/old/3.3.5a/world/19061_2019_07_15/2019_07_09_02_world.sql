--
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (9253, 9280);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=8490 WHERE `ID`=9253;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=9280 WHERE `ID`=9279;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1708 WHERE `ID`=1704;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1710 WHERE `ID`=1703;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1705 WHERE `ID`=1700;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=8330 WHERE `ID` IN (10068, 10069, 10070, 10071, 10072, 10073);
DELETE FROM `quest_template_addon` WHERE `ID`=8888;
INSERT INTO `quest_template_addon` (`ID`, `BreadcrumbForQuestId`) VALUES
(8888, 8889);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=8330;
UPDATE `quest_template` SET `AllowableRaces`=1 WHERE `ID`=1700;
UPDATE `quest_template` SET `AllowableRaces`=4+64 WHERE `ID`=1704;

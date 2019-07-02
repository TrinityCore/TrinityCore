-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19) AND `SourceEntry`IN (1275,1841, 1846, 1840, 1844, 1839, 1842, 2865, 6383,  13226, 13227);

DELETE FROM `quest_template_addon` WHERE `ID` IN (3765,2864,13226,13227);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES
(3765, 1275),
(2864, 2865),
(13226,13036),
(13227,13036);

UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1846 WHERE `ID` IN (1841);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1844 WHERE `ID` IN (1840);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=1842 WHERE `ID` IN (1839);
UPDATE `quest_template_addon` SET `PrevQuestID`=0,`ExclusiveGroup`=0, `BreadcrumbForQuestId`=6383 WHERE `ID` IN (742,6382,235);

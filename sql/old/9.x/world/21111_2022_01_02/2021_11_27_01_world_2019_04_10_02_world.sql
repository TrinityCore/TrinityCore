-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19) AND `SourceEntry`IN(12451,12161,12425, 11175,11406,12182,12189,11573,11995,12469,12542,11996,12511,12208,12210);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11176 WHERE `ID`=11175;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11269 WHERE `ID`=11406;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12000 WHERE `ID`=11995;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12328 WHERE `ID`=12161;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12188 WHERE `ID`=12182;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12188 WHERE `ID`=12189;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11984 WHERE `ID`=12208;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=11984 WHERE `ID`=12210;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12328 WHERE `ID`=12425;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=12044 WHERE `ID`=12469;

DELETE FROM `quest_template_addon` WHERE `ID` IN (11573,12542,11996,12511,12451);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES
(11573, 11504),
(12542, 12545),
(11996, 11999),
(12511, 12292),
(12451, 12195);

UPDATE `quest_template_addon` SET `ExclusiveGroup`=0 WHERE `ID` IN (12208,12182,12189,12210,12161,12425);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (11999,12044,12545);

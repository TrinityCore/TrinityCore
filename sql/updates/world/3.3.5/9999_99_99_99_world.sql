ALTER TABLE `quest_template_addon`
ADD COLUMN `BreadcrumbForQuestId` MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `ExclusiveGroup`;

-- Rejold's New Brew
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 413 WHERE `Id` = 415;
UPDATE `quest_template_addon` SET `PrevQuestID` = 315 WHERE `ID` = 413;

-- Assisting Arch Druid Runetotem
UPDATE `quest_template_addon` SET `NextQuestID` = 0, `BreadcrumbForQuestId` = 3761 WHERE `ID` IN (936, 3762, 3784);

-- Assisting Arch Druid Staghelm
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 3764 WHERE `ID` IN (3763, 3789, 3790, 10520);

-- Lost Deathstalkers
DELETE FROM `quest_template_addon` WHERE `ID` IN (428,429);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (428, 429);

-- On Guard in Stonetalon
DELETE FROM `quest_template_addon` WHERE `ID` IN (1070);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1070, 1085);

-- The Crown of Will
DELETE FROM `quest_template_addon` WHERE `ID` IN (495,518);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (495,518);

-- Camp Mojache
DELETE FROM `quest_template_addon` WHERE `ID` IN (7489,7492);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (7492,7489);

-- Feathermoon Stronghold
DELETE FROM `quest_template_addon` WHERE `ID` IN (7488,7494);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (7494,7488);

-- Journey to Stonetalon Peak
DELETE FROM `quest_template_addon` WHERE `ID` IN (1056);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (1056,1057);

-- Castpipe's Task
DELETE FROM `quest_template_addon` WHERE `ID` IN (2931);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2931,2930);

-- Kayneth Stillwind
DELETE FROM `quest_template_addon` WHERE `ID` IN (1011);
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1011 WHERE `ID`=4581;

-- Carendin Summons
UPDATE `quest_template` SET `AllowableRaces` = 512 WHERE `Id` = 10605;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 1472 WHERE `ID`=10605;

-- To Winterspring! & Starfall
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 5244 WHERE `ID` = 5249;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId` = 5244 WHERE `ID` = 5250;

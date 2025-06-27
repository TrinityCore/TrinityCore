-- BreadCrumb Quest "Ragnar Thunderbrew"
DELETE FROM `quest_template_addon` WHERE `ID` IN (4126,4128);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (4128,4126);

-- BreadCrumb Quest "Call of Fire"
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0, `BreadcrumbForQuestId`=1524 WHERE `ID` IN (1522,1523,2983,2984);

-- BreadCrumb Quest "Call of Water"
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0, `BreadcrumbForQuestId`=1530 WHERE `ID` IN (1528,1529,2985,2986);

-- BreadCrumb Quest "The Barrens Oases"
DELETE FROM `quest_template_addon` WHERE `ID` IN (886);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (886,870);

-- BreadCrumb Quest "A Threat in Feralas"
DELETE FROM `quest_template_addon` WHERE `ID` IN (2981);
INSERT INTO `quest_template_addon` (`ID`,`BreadcrumbForQuestId`) VALUES (2981,2975);

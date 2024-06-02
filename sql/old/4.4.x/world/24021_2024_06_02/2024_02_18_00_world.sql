-- Delete Empty Rows
DELETE FROM `quest_template_addon` WHERE `ID` IN (25129,25152);
-- Unnecessary NextQuestIDs
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (25131,25132,25133,25136);
-- Hana'zua
UPDATE `quest_template_addon` SET `PrevQuestID`=25127 WHERE `ID`=25128;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=25129 WHERE `ID`=25128;
-- Lazy Peons
UPDATE `quest_template_addon` SET `PrevQuestID`=25172 WHERE `ID`=37446;

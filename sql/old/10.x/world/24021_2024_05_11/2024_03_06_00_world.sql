-- Volatile Mutations (Empty Row)
DELETE FROM `quest_template_addon` WHERE `ID`=10302;
-- Vindicator Aldar
UPDATE `quest_template_addon` SET `PrevQuestID`=9294 WHERE `ID`=10304;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=0 WHERE `ID`=10304;
-- Innoculation and Spare Parts
UPDATE `quest_template_addon` SET `PrevQuestID`=10302 WHERE `ID` IN (37444,37445);

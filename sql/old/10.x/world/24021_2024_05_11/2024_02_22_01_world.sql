-- Unneeded Condition for Caretaker Caice (Handled by BreadcrumbForQuestId)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=28652;
-- Delete Unneeded Rows
DELETE FROM `quest_template_addon` WHERE `ID`=26801;
-- Caretaker Caice
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=24960 WHERE `ID`=28652;
-- Shadow Priest Sarvis
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=26801 WHERE `ID`=28653;
-- Novice Elreth
UPDATE `quest_template_addon` SET `PrevQuestID`=26801 WHERE `ID`=28651;
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID`=28651;
-- The Truth of the Grave
UPDATE `quest_template_addon` SET `PrevQuestID`=28651 WHERE `ID`=24961;

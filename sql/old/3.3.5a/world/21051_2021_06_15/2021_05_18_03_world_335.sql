--
UPDATE `quest_template_addon` SET `NextQuestID` = 3641 WHERE `ID` = 3640; -- Was 3639
UPDATE `quest_template_addon` SET `NextQuestID` = 3643 WHERE `ID` = 3642; -- Was 3639
UPDATE `quest_template_addon` SET `PrevQuestID` = 3638 WHERE `ID` = 3639; -- Was 0

UPDATE `quest_template_addon` SET `ExclusiveGroup` = 0 WHERE `ID` IN (3638,3640,3642); -- Was 3638

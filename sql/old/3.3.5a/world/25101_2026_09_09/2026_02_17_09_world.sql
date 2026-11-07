-- Fixes Zangarmarsh Quest "A Job Undone" invalid prerequisite quest
UPDATE `quest_template_addon` SET `PrevQuestID` = 9773 WHERE `ID` = 9899;

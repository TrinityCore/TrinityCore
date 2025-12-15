-- Fixes Zangarmarsh Quest "A Job Undone" invalid prerequisite quest
-- closes https://github.com/azerothcore/azerothcore-wotlk/issues/21708
UPDATE `quest_template_addon` SET `PrevQuestID` = 9773 WHERE (`ID` = 9899);

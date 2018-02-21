--
DELETE from `quest_poi` where `QuestID` NOT in (select ID from `quest_template`);

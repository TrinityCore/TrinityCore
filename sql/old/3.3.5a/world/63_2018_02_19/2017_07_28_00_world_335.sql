-- insert missing Progress text for the 2 quests "Bandages for the Field" (8496,8810)
UPDATE `quest_request_items` SET `CompletionText`= 'You have something for me, $N?$b$b' WHERE `ID` IN (8496,8810);

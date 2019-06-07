UPDATE quest_poi SET ObjectiveIndex = 5 WHERE id = 1 AND ObjectiveIndex = 4 AND QuestID IN (SELECT ID FROM quest_template WHERE RequiredItemId2 > 0);
UPDATE quest_poi SET ObjectiveIndex = 6 WHERE id = 2 AND ObjectiveIndex = 4 AND QuestID IN (SELECT ID FROM quest_template WHERE RequiredItemId3 > 0);
UPDATE quest_poi SET ObjectiveIndex = 7 WHERE id = 3 AND ObjectiveIndex = 4 AND QuestID IN (SELECT ID FROM quest_template WHERE RequiredItemId4 > 0);

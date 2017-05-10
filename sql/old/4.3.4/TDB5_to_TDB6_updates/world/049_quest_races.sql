-- Update the item quests for Horde only
UPDATE quest_template SET RequiredRaces = 690 WHERE Id IN (25107, 24905);

-- Update the item quests for Alliance only
UPDATE quest_template SET RequiredRaces = 1101 WHERE Id IN (25421);

-- Update the item quests for Horde only
UPDATE quest_template SET RequiredRaces = 690 WHERE Id IN (27254, 27255, 27256, 27257, 27260, 27244, 27259);

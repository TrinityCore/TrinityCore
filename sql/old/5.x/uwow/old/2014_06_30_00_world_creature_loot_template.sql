-- Pattern: Celestial Cloth and Its Uses
UPDATE creature_loot_template SET ChanceOrQuestChance = 100 WHERE item = 100863;
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 1 AND SourceEntry = 100863;
INSERT INTO conditions SELECT
	1, entry, 100863, 0, 0, 7, 0, 197, 600, 0, 0, 0, '', '' FROM creature_loot_template WHERE item = 100863;
INSERT INTO conditions SELECT
	1, entry, 100863, 0, 0, 2, 0, 100863, 1, 1, 1, 0, '', '' FROM creature_loot_template WHERE item = 100863;
INSERT INTO conditions SELECT
	1, entry, 100863, 0, 0, 25, 0, 143011, 0, 0, 1, 0, '', '' FROM creature_loot_template WHERE item = 100863;
	
-- Plans: Balanced Trillium Ingot and Its Uses
UPDATE creature_loot_template SET ChanceOrQuestChance = 100 WHERE item = 100865;
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 1 AND SourceEntry = 100865;
INSERT INTO conditions SELECT
	1, entry, 100865, 0, 0, 7, 0, 164, 600, 0, 0, 0, '', '' FROM creature_loot_template WHERE item = 100865;
INSERT INTO conditions SELECT
	1, entry, 100865, 0, 0, 2, 0, 100865, 1, 1, 1, 0, '', '' FROM creature_loot_template WHERE item = 100865;
INSERT INTO conditions SELECT
	1, entry, 100865, 0, 0, 25, 0, 143255, 0, 0, 1, 0, '', '' FROM creature_loot_template WHERE item = 100865;
	
-- Pattern: Hardened Magnificent Hide and Its Uses
UPDATE creature_loot_template SET ChanceOrQuestChance = 100 WHERE item = 100864;
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 1 AND SourceEntry = 100864;
INSERT INTO conditions SELECT
	1, entry, 100864, 0, 0, 7, 0, 165, 600, 0, 0, 0, '', '' FROM creature_loot_template WHERE item = 100864;
INSERT INTO conditions SELECT
	1, entry, 100864, 0, 0, 2, 0, 100864, 1, 1, 1, 0, '', '' FROM creature_loot_template WHERE item = 100864;
INSERT INTO conditions SELECT
	1, entry, 100864, 0, 0, 25, 0, 142976, 0, 0, 1, 0, '', '' FROM creature_loot_template WHERE item = 100864;
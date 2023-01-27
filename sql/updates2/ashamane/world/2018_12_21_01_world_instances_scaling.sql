UPDATE `creature_template_scaling` SET DifficultyID = 1 WHERE entry IN (SELECT id FROM creature WHERE map = 1841);
UPDATE `creature_template_scaling` SET DifficultyID = 12 WHERE entry IN (SELECT id FROM creature WHERE map = 1904);

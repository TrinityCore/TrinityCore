-- Ragefire Chasm zone=2437
UPDATE creature_template SET EXP = 0 WHERE entry IN (SELECT id FROM creature WHERE map = 389);
UPDATE creature_template SET dmg_multiplier = dmg_multiplier*3 WHERE entry IN (SELECT id FROM creature WHERE map = 389);
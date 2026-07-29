-- Dustwallow Marsh - Alcaz Island

-- NPC: 4364 Strashaz Warrior
-- NPC: 4371 Strashaz Siren
-- NPC: 4366 Strashaz Serpent Guard
-- NPC: 15553 Security Bot
-- NPC: 23969 Firemane Drake
-- NPC: 4368 Strashaz Myrmidon
-- NPC: 4370 Strashaz Sorceress
-- NPC: 16072 Tidelord Rrurgaz

-- Wrong factions
UPDATE creature_template SET faction = 16 WHERE entry = 15553;

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (15553) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (15553) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 23 WHERE Entry IN (4364,4371,4366,23969,4368,4370,16072);

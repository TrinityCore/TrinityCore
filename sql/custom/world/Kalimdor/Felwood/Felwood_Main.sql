-- Felwood Fixes

-- NPC: 50905 Cida

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (50905) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (50905) AND `DifficultyID` = 1;

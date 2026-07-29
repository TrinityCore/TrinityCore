-- Ashenvale Fixes

-- NPC: 49480 Tarindrella

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (49480) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (49480) AND `DifficultyID` = 1;

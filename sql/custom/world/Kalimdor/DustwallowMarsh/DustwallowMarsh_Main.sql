-- Dustwallow Marsh

-- NPC: 50901 Teromak

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (50901) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (50901) AND `DifficultyID` = 1;

-- Eversong Woods (Burning Crusade) Fixes

-- NPC: 16854 Eldinarcus

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (16854) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (16854) AND `DifficultyID` = 1;

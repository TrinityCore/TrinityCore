-- Winterspring Fixes

-- NPC: 10741 Sian-Rotam
-- NPC: 50788 Quetzl
-- NPC: 50993 Gal'dorak
-- NPC: 50995 Bruiser
-- NPC: 50997 Bornak the Gorer

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (10741,50788) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (10741,50788) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 33 WHERE Entry IN (50993,50995,50997);

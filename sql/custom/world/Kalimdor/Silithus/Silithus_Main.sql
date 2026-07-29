-- Silithus Fixes

-- NPC: 132584 Xaarshej
-- NPC: 132578 Qroshekx - phase 9491

-- Incorrect factions
UPDATE creature_template SET faction = 14 WHERE entry = 132584;

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (132578) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (132578) AND `DifficultyID` = 1;

UPDATE `creature_template_difficulty` SET `ContentTuningID` = 650, `LootID` = 132584 WHERE `Entry` = 132584 AND `DifficultyID` = 0;

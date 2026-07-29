-- Desolace Fixes

-- NPC: 18241 Crusty

DELETE FROM `creature_template_difficulty` WHERE Entry = 18241 AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry = 18241 AND `DifficultyID` = 1;

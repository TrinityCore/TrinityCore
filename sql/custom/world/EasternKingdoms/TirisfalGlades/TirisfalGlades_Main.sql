-- Tirisfal Glades Fixes

-- NPC: 50930 Hibernus the Sleeper

-- Difficulty Fixes
DELETE FROM `creature_template_difficulty` WHERE Entry IN (50930) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (50930) AND `DifficultyID` = 1;

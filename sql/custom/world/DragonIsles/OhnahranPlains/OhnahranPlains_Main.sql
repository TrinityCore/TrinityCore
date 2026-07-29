-- Ohnahran Plains Fixes

-- NPC: 187629 Elder Scaleguard
-- NPC: 195515 Elder Boughweaver

-- Difficulty fixes
-- Missing Content Tuning
UPDATE creature_template_difficulty SET ContentTuningID = 2699 WHERE Entry = 187629 AND DifficultyID = 0;
UPDATE creature_template_difficulty SET ContentTuningID = 2699 WHERE Entry = 195515 AND DifficultyID = 0;

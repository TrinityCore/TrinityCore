-- The Forbidden Reach Fixes

-- Creature Difficulty
-- Swim flag addition
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 | 0x10000000
WHERE Entry IN (
    199963
)
AND DifficultyID = 0;

-- Remove floating flag
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 & ~0x20000000
WHERE Entry IN (
    187194
)
AND DifficultyID = 0;

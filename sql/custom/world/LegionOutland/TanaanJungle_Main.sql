-- Tanaan Jungle Fixes

-- Creature Difficulty
-- Swim flag addition
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 | 0x10000000
WHERE Entry IN (
    79316,78568,78569,82003,81999,81993,82011,82001,82000,
    78554,78553
)
AND DifficultyID = 0;

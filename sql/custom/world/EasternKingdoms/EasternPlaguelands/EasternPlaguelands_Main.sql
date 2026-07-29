-- Eastern Plaguelands Fixes

-- NPC: 8556 Crypt Walker
-- NPC: 8557 Crypt Horror

-- Creature Difficulty
-- Swim flag addition
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 | 0x10000000 WHERE Entry IN (16378) AND DifficultyID = 0;
UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 & ~0x20000000 WHERE Entry IN (16378) AND DifficultyID = 0;

-- Creature Template fixes
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (8557,8556);

-- Creature Fixes
UPDATE creature SET `unit_flags` = 537133824, `unit_flags3` = 8192 WHERE guid IN (318242,318250,318255,318249);

-- Creature addons
DELETE FROM creature_addon WHERE guid IN (318242,318250,318255,318249);
INSERT INTO creature_addon (guid, StandState) VALUES (318242, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (318250, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (318255, 7);
INSERT INTO creature_addon (guid, StandState) VALUES (318249, 7);

UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    8597,8601,8603,8534,8541,8538,
    8525,8543,8548,8526,8520,11291,
    11290,8596,8521,8602,8524,45851,
    8523,8530,8555,8557,8563,8565,
    8540,8537,8532,8528
);

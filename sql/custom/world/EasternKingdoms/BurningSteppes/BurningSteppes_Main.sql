-- Burning Steppes Fixes

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    9778,9776,9697,7041,48287,7032,7039,7036,7025,48201,9691,
    48119,7049,47782
);

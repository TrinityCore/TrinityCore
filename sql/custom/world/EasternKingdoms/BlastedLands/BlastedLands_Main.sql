-- Blasted Lands Fixes

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    77653,77721,77090,77644,5990,5992,78348,78345,82451,78488
);

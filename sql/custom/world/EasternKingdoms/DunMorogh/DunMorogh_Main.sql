-- Dun Morogh Fixes

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    42170,1115,1117,1196,41539,41175,41146,1125,41478
);
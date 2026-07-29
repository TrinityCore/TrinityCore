-- Redridge Mountains Fixes

-- Creature Spawn Fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    442,423,426,1083,548,422,547,424,7013,43535,
    568,43084,433,429,712
);

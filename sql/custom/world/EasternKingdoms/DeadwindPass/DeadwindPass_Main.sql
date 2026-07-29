-- Deadwind Pass Fixes

-- NPC: 51987 Deadwind Widow

-- Wrong/Duplicate Spawns
DELETE FROM creature WHERE id = 51987 AND guid = 290818;

-- Creature Spawn Fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    51987
);
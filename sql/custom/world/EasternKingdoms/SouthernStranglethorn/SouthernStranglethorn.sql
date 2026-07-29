-- Southern Stranglethorn Fixes

-- Template Fixes
UPDATE creature_template SET faction = 7 WHERE entry = 203383;
UPDATE creature_template SET faction = 7 WHERE entry = 199211;

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    1492,1488,43223,1491,1489,43376,
	43596,43417,2521,2522,1565,1653,4506,43536,2544,
    1493,1907,1558,1550,1551
);

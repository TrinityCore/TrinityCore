-- Northern Stranglethorn Fixes

-- Template Fixes
UPDATE creature_template SET unit_flags = 0 WHERE entry = 597;

-- Template Addon Fixes
UPDATE creature_template_addon SET emote = 233 WHERE entry = 674;

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    699,588,701,595,736,685,689,694,587,697,
    686,4461,1144,52224,1142,1085,667,696,687,937,
    940,943,977,43050,941,939,942,978,979,1096,
    4260,921,1097,709,678,679,669,782,781,672,
    783,670,597,660,671,675,681,683,1150
);

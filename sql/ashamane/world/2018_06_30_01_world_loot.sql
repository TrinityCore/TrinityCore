UPDATE creature_template SET lootid = 107544 WHERE entry = 107544 AND lootid = 0;

DELETE FROM creature_loot_template WHERE entry = 107544;
INSERT INTO creature_loot_template (Entry, Item, Chance, LootMode, GroupId, MinCount, MaxCount) VALUES
(107544, 141424, 5, 1, 0, 1, 1),
(107544, 141420, 5, 1, 0, 1, 1),
(107544, 141414, 5, 1, 0, 1, 1),
(107544, 141519, 5, 1, 0, 1, 1),
(107544, 141541, 5, 1, 0, 1, 1),
(107544, 141418, 5, 1, 0, 1, 1),
(107544, 141546, 5, 1, 0, 1, 1);

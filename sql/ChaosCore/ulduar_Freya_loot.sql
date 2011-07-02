-- Freya
-- TODO: Fix the loot on remaining caches
-- Add Missing GO's templates for chests

-- Cache with 2 elders alive in 10 man mode
DELETE FROM gameobject_template WHERE `entry` = 194326;
INSERT INTO gameobject_template (`entry`, `type`, `displayId`, `name`, `size`, `data0`, `data1`, `data3`, `data6`, `data11`, `data13`, `data15`, `WDBVerified`) VALUES
(194326, 3, 8628, 'Freya\'s Gift', 2, 1634, 27079, 1, 0, 1, 1, 1, 11159);
-- Cache with 1 elder alive in 25 man mode
DELETE FROM gameobject_template WHERE `entry` = 194329;
INSERT INTO gameobject_template (`entry`, `type`, `displayId`, `name`, `size`, `data0`, `data1`, `data3`, `data6`, `data11`, `data13`, `data15`, `WDBVerified`) VALUES
(194329, 3, 8628, 'Freya\'s Gift', 2, 1634, 26962, 1, 0, 1, 1, 1, 11159);
-- Cache with 2 elders alive in 25 man mode
DELETE FROM gameobject_template WHERE `entry` = 194330;
INSERT INTO gameobject_template (`entry`, `type`, `displayId`, `name`, `size`, `data0`, `data1`, `data3`, `data6`, `data11`, `data13`, `data15`, `WDBVerified`) VALUES
(194330, 3, 8628, 'Freya\'s Gift', 2, 1634, 26962, 1, 0, 1, 1, 1, 11159);

-- Loot Fix 10 man
-- Reference loot for 10 man caches
UPDATE reference_loot_template SET `lootmode` = 1 WHERE `entry` = 34125;
-- Delete faulty loot from freya 10 man 0 elder cache
DELETE FROM gameobject_loot_template WHERE `entry` = 27078 AND `item` IN (2, 3, 4, 5, 6);
UPDATE gameobject_loot_template SET `groupid` = 1, `maxcount` = 3 WHERE `entry` = 27078 AND `item` = 1;

-- Loot cache with 1 elder alive 10 man (entry 194325)
DELETE FROM gameobject_loot_template WHERE `entry` = 27079;
INSERT INTO gameobject_loot_template VALUES
(27079, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(27079, 1, 100, 1, 1, -34125, 3), -- 3 random Normal items
(27079, 2, 100, 1, 2, -34125, 1), -- 1 random hard mode item
(27079, 45087, 100, 1, 0, 1, 1), -- Runed orb
(27079, 45644, 0, 1, 1, 1, 1), -- T8
(27079, 45645, 0, 1, 1, 1, 1), -- T8
(27079, 45646, 0, 1, 1, 1, 1), -- T8
(27079, 45788, -100, 2, 0, 1, 1), -- Sigil Freya
(27079, 46110, 100, 1, 0, 1, 1), -- Alchemist's cache
(27079, 47241, 100, 1, 0, 2, 2); -- Emblem of Triumph x2

-- Loot cache with 2 elders alive 10 man (entry 194326)
DELETE FROM gameobject_loot_template WHERE `entry` = 27080;
INSERT INTO gameobject_loot_template VALUES
(27080, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(27080, 1, 100, 1, 1, -34125, 3), -- 3 random Normal items
(27080, 2, 100, 1, 2, -34125, 2), -- 2 random hard mode items
(27080, 45087, 100, 1, 0, 1, 1), -- Runed orb
(27080, 45644, 0, 1, 1, 1, 1), -- T8
(27080, 45645, 0, 1, 1, 1, 1), -- T8
(27080, 45646, 0, 1, 1, 1, 1), -- T8
(27080, 45788, -100, 2, 0, 1, 1), -- Sigil Freya
(27080, 46110, 100, 1, 0, 1, 1), -- Alchemist's cache
(27080, 47241, 100, 1, 0, 3, 3); -- Emblem of Triumph x3
UPDATE gameobject_template SET `data1` = 27080 WHERE `entry` = 194326; -- Set loot on cache

-- Loot cache with 3 elders alive 10 man (entry 194327)
DELETE FROM gameobject_loot_template WHERE `entry` = 27081; -- Lolwut? 25m loot on a 10m loot cache?
INSERT INTO gameobject_loot_template VALUES
(27081, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(27081, 1, 100, 1, 1, -34125, 3), -- 3 random Normal items
(27081, 2, 100, 1, 2, -34125, 3), -- 3 random hard mode items
(27081, 45038, 100, 1, 0, 1, 1), -- Fragment of Val'anyr (100% drop chance on hardmode to incentivate people to run ulduar :D)
(27081, 45087, 100, 1, 0, 1, 1), -- Runed orb
(27081, 45644, 0, 1, 1, 1, 1), -- T8
(27081, 45645, 0, 1, 1, 1, 1), -- T8
(27081, 45646, 0, 1, 1, 1, 1), -- T8
(27081, 45788, -100, 2, 0, 1, 1), -- Sigil Freya
(27081, 46110, 100, 1, 0, 1, 1), -- Alchemist's cache
(27081, 47241, 100, 1, 0, 4, 4); -- Emblem of Triumph x4
UPDATE gameobject_template SET `data1` = 27081 WHERE `entry` = 194327; 

-- Reference loot for 25 man caches
DELETE FROM reference_loot_template WHERE entry = 26962;
INSERT INTO reference_loot_template VALUES
(26962, 45484, 0, 1, 2, 1, 1),
(26962, 45485, 0, 1, 2, 1, 1),
(26962, 45486, 0, 1, 2, 1, 1),
(26962, 45613, 0, 1, 2, 1, 1),
(26962, 45487, 0, 1, 2, 1, 1),
(26962, 45488, 0, 1, 2, 1, 1),
(26962, 45482, 0, 1, 1, 1, 1),
(26962, 45483, 0, 1, 1, 1, 1),
(26962, 45481, 0, 1, 1, 1, 1),
(26962, 45480, 0, 1, 1, 1, 1),
(26962, 45479, 0, 1, 1, 1, 1);

-- Loot cache with 0 elders alive 25 man (entry 194328)
DELETE FROM `gameobject_loot_template` WHERE `entry` = 26959;
INSERT INTO `gameobject_loot_template` VALUES
(26959, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(26959, 45038, 18, 1, 0, 1, 1), -- Fragment of Val'anyr
(26959, 45087, 75, 1, 0, 1, 1), -- Runed orb
(26959, 45655, 0, 1, 3, 1, 1), -- T8
(26959, 45654, 0, 1, 3, 1, 1), -- T8
(26959, 45653, 0, 1, 3, 1, 1), -- T8
(26959, 1, 100, 1, 1, -26962, 3), -- 3 Normal items
(26959, 45814, -100, 2, 0, 1, 1), -- Sigil Freya
(26959, 47241, 100, 1, 0, 1, 1); -- Emblem of Triumph x1
UPDATE gameobject_template SET `data1` = 26959 WHERE `entry` = 194328;

-- Loot with 1 elder alive 25 man (entry 194329)
DELETE FROM gameobject_loot_template WHERE `entry` = 26960;
INSERT INTO gameobject_loot_template VALUES
(26960, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(26960, 45038, 20, 1, 0, 1, 1), -- Fragment of Val'anyr
(26960, 45087, 75, 1, 0, 1, 1), -- Runed orb
(26960, 45655, 0, 1, 3, 1, 1), -- T8
(26960, 45654, 0, 1, 3, 1, 1), -- T8
(26960, 45653, 0, 1, 3, 1, 1), -- T8
(26960, 1, 100, 1, 1, -26962, 3), -- 3 Normal items
(26960, 2, 100, 1, 2, -26962, 1), -- 1 Hard Mode item
(26960, 45814, -100, 2, 0, 1, 1), -- Sigil Freya
(26960, 47241, 100, 1, 0, 2, 2); -- Emblem of Triumph x2
UPDATE gameobject_template SET `data1` = 26960 WHERE `entry` = 194329;

-- Loot with 2 elders alive 25 man (entry 194330)
DELETE FROM gameobject_loot_template WHERE `entry` = 26961;
INSERT INTO gameobject_loot_template VALUES
(26961, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(26961, 45038, 25, 1, 0, 1, 1), -- Fragment of Val'anyr
(26961, 45087, 75, 1, 0, 1, 1), -- Runed orb
(26961, 45655, 0, 1, 3, 1, 1), -- T8
(26961, 45654, 0, 1, 3, 1, 1), -- T8
(26961, 45653, 0, 1, 3, 1, 1), -- T8
(26961, 1, 100, 1, 1, -26962, 3), -- 3 Normal items
(26961, 2, 100, 1, 2, -26962, 2), -- 2 Hard Mode items
(26961, 45814, -100, 2, 0, 1, 1), -- Sigil Freya
(26961, 47241, 100, 1, 0, 3, 3); -- Emblem of Triumph x3
UPDATE gameobject_template SET `data1` = 26961 WHERE `entry` = 194330;

-- Loot with 3 elders alive 25 man (entry 194331)
DELETE FROM gameobject_loot_template WHERE `entry` = 26962;
INSERT INTO gameobject_loot_template VALUES
(26962, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(26962, 45038, 100, 1, 0, 1, 1), -- Fragment of Val'anyr
(26962, 45087, 75, 1, 0, 1, 1), -- Runed orb
(26962, 45655, 0, 1, 3, 1, 1), -- T8
(26962, 45654, 0, 1, 3, 1, 1), -- T8
(26962, 45653, 0, 1, 3, 1, 1), -- T8
(26962, 1, 100, 1, 1, -26962, 3), -- 3 Normal items
(26962, 2, 100, 1, 2, -26962, 3), -- 3 Hard Mode items
(26962, 45814, -100, 2, 0, 1, 1), -- Sigil Freya
(26962, 47241, 100, 1, 0, 4, 4); -- Emblem of Triumph x4
UPDATE gameobject_template SET `data1` = 26962 WHERE `entry` = 194331;
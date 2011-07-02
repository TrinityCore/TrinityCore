-- Thorim loot 25m
-- TODO: Fix the loot on remaining caches
DELETE FROM reference_loot_template WHERE `entry` =  26956; -- Hardmode + normal itens used for reference
INSERT INTO reference_loot_template VALUES
(26956, 45463, 0, 1, 1, 1, 1),
(26956, 45466, 0, 1, 1, 1, 1),
(26956, 45467, 0, 1, 1, 1, 1),
(26956, 45468, 0, 1, 1, 1, 1),
(26956, 45469, 0, 1, 1, 1, 1),
(26956, 45470, 0, 1, 2, 1, 1),
(26956, 45471, 0, 1, 2, 1, 1),
(26956, 45472, 0, 1, 2, 1, 1),
(26956, 45473, 0, 1, 2, 1, 1),
(26956, 45474, 0, 1, 2, 1, 1),
(26956, 45570, 0, 1, 2, 1, 1);
DELETE FROM `gameobject_loot_template` WHERE `entry` = 26955; -- Chest 25 man normal mode
INSERT INTO `gameobject_loot_template` VALUES 
(26955, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(26955, 45038, 18, 1, 0, 1, 1), -- Fragment of Val'anyr
(26955, 45087, 75, 1, 0, 1, 1), -- Runed Orb
(26955, 1, 100, 1, 1, -26956, 4), -- 4 Normal itens
(26955, 45638, 0, 1, 3, 1, 1), -- T8
(26955, 45639, 0, 1, 3, 1, 1), -- T8
(26955, 45640, 0, 1, 3, 1, 1), -- T8
(26955, 47241, 100, 1, 0, 1, 1); -- Emblem of triumph x1
-- Hard Mode
DELETE FROM `gameobject_loot_template` WHERE `entry` = 40000; -- Chest 25 man Hard mode
INSERT INTO `gameobject_loot_template` VALUES 
(40000, 3, 10, 1, 0, -34154, 1), -- Random Recipes
(40000, 45038, 100, 1, 0, 1, 1), -- Fragment of Val'anyr (100% drop chance on hardmode to incentivate people to run ulduar :D)
(40000, 45087, 75, 1, 0, 1, 1), -- Runed orb
(40000, 45638, 0, 1, 3, 1, 1), -- T8
(40000, 45639, 0, 1, 3, 1, 1), -- T8
(40000, 45640, 0, 1, 3, 1, 1), -- T8
(40000, 1, 100, 1, 1, -26956, 3), -- 3 Normal itens
(40000, 2, 100, 1, 2, -26956, 3), -- 3 Hard Mode itens
(40000, 45817, -100, 2, 0, 1, 1), -- Sigil Thorim
(40000, 47241, 100, 1, 0, 1, 1); -- Emblem of Triumph x1
UPDATE `gameobject_template` SET `data1` = 40000 WHERE `entry` = 194315;
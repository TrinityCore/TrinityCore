-- random fixes part 2

-- item does not exist
DELETE FROM `gameobject_loot_template` WHERE `entry` = 2032 and `item` = 11098;
DELETE FROM `gameobject_loot_template` WHERE `entry` = 2032 and `item` = 9293;
DELETE FROM `gameobject_loot_template` WHERE `entry` = 3597 and `item` = 6172;

-- gameobject does not exist or missing template
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (167, 938, 1420, 1421, 1423, 1424, 1594, 1689, 1730, 1731, 1732, 1733, 1734, 2292, 2416);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (2417, 2418, 2483, 2628, 2629, 3881, 4165, 6142, 6151, 6152, 6312, 6313, 8759, 9239);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (9240, 9241, 9242, 10101, 10102, 12810, 12811, 12812, 13945, 13946, 13947, 13948);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (13970, 14973, 15000, 17378, 18111, 18112, 18113, 18115, 18116, 18117, 18118, 18119);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (18359, 18361, 18363, 22906, 24093, 24124, 24154, 24155, 24156, 24224, 24225, 24226);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (24227, 25089, 25093, 26959, 27742, 27743, 27745, 27746, 27747, 27826, 28492, 28493);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (28494, 28495, 28521, 28522, 28523, 28524, 28525, 28526, 28682, 28683, 41213, 42918);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (195665, 195666, 195667, 195668, 195672, 244447);

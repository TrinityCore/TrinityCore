-- Egg Rush! should only be castable in Azure Watch, Dolannar, Goldshire, haranos, Bloodhoof Village, Brill, Falconwing Square, Razor Hill
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=61810;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(17,0,61810,1,23,3576, 'Egg Rush! - Requires Azure Watch'), -- OR
(17,0,61810,2,23,186, 'Egg Rush! - Requires Dolanaar'), -- OR
(17,0,61810,3,23,87, 'Egg Rush! - Requires Goldshire'), -- OR
(17,0,61810,4,23,131, 'Egg Rush! - Requires Kharanos'), -- OR
(17,0,61810,5,23,222, 'Egg Rush! - Requires Bloodhoof Village'), -- OR
(17,0,61810,6,23,159, 'Egg Rush! - Requires Brill'), -- OR
(17,0,61810,7,23,2118, 'Egg Rush! - Requires Brill Town Hall'), -- OR
(17,0,61810,8,23,3665, 'Egg Rush! - Requires Falconwing Square'), -- OR
(17,0,61810,9,23,362, 'Egg Rush! - Requires Razor Hill'), -- OR
(17,0,61810,10,23,2337, 'Egg Rush! - Requires Razor Hill Barracks');

-- Template updates for gameobject Brightly Colored Egg
UPDATE `gameobject_template` SET `faction`=35 WHERE `entry` BETWEEN 113768 AND 113772; -- Brightly Colored Egg's
UPDATE `gameobject_template` SET `data1`=26884,`data7`=194047 WHERE `entry`=113772 AND `WDBVerified`=1; -- Brightly Colored Egg, made up GOB, no reason to be different from others

-- Loot
DELETE FROM `gameobject_loot_template` WHERE `entry`=4984;
DELETE FROM `item_loot_template` WHERE `entry`=45072;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(45072,44791,95,1,1,1,1), -- Noblegarden Chocolate
(45072,19028,0.2,1,1,1,1), -- Elegant Dress reminder of group 1
(45072,6833,0.9,1,1,1,1), -- White Tuxedo Shirt
(45072,6835,0.9,1,1,1,1), -- Black Tuxedo Pants
(45072,45073,0.6,1,1,1,1), -- Spring Flowers
(45072,44800,0.6,1,1,1,1), -- Spring Robes
(45072,44794,0.4,1,1,1,1), -- Spring Rabbit's Foot
(45072,44803,0.5,1,1,1,1), -- Spring Circlet
(45072,44792,0.9,1,1,1,1), -- Blossoming Branch
(45072,44806,-100,1,0,1,1); -- Brightly Colored Shell Fragment

-- Creature template
UPDATE `creature_template` SET `equipment_id`=10102 WHERE `entry` =32836;

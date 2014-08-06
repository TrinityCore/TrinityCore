-- Mimiron's loot fetched from GC's MaNGOS database.

SET @normal10 := 196004;
SET @heroic10 := 196005;
SET @normal25 := 196006;
SET @heroic25 := 196007;

-- Normal Mode (10)
DELETE FROM `gameobject_loot_template` WHERE `entry` = @normal10;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `lootmode`) VALUES
(@normal10, 47241, 100, 0, 1, 1, 1),
(@normal10, 45647, 0, 1, 1, 1, 1),
(@normal10, 45648, 0, 1, 1, 1, 1),
(@normal10, 45649, 0, 1, 1, 1, 1),
(@normal10, 45972, 0, 2, 1, 1, 1),
(@normal10, 45973, 0, 2, 1, 1, 1),
(@normal10, 45974, 0, 2, 1, 1, 1),	
(@normal10, 45975, 0, 2, 1, 1, 1),	
(@normal10, 45976, 0, 2, 1, 1, 1);	

-- Heroic mode (10)
DELETE FROM `gameobject_loot_template` WHERE `entry` = @heroic10;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `lootmode`) VALUES
(@heroic10,45087,70,0,1,1,1),
(@heroic10, 45647, 0, 1, 1, 1, 1),
(@heroic10, 45648, 0, 1, 1, 1, 1),
(@heroic10, 45649, 0, 1, 1, 1, 1),
(@heroic10,45787,-100,0,1,1, 1),
(@heroic10,45982,0,2,1,1,1),
(@heroic10,45988,0,2,1,1,1),
(@heroic10,45989,0,2,1,1,1),
(@heroic10,45990,0,2,1,1,1),
(@heroic10,47241,100,0,1,1,1),
(@heroic10,45993,0,2,1,1,1);

-- Normal Mode (25)
DELETE FROM `gameobject_loot_template` WHERE `entry` = @normal25;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `lootmode`) VALUES
(@normal25,45038,15,0,1,1,1),
(@normal25,45087,70,0,1,1,1),
(@normal25,45489,0,2,1,1,1),
(@normal25,45490,0,2,1,1,1),
(@normal25,45491,0,2,1,1,1),
(@normal25,45492,0,2,1,1,1),
(@normal25,45493,0,2,1,1,1),
(@normal25,47241,100,0,1,1,1),
(@normal25,45641,0,1,1,1,1),
(@normal25,45642,0,1,1,1,1),
(@normal25,45643,0,1,1,1,1);

-- Heroic Mode (25)
DELETE FROM `gameobject_loot_template` WHERE `entry` = @heroic25;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `lootmode`) VALUES
(@heroic25,45494,0,2,1,1,1),
(@heroic25,45496,0,2,1,1,1),
(@heroic25,45497,0,2,1,1,1),
(@heroic25,45620,0,2,1,1,1),
(@heroic25,45663,0,2,1,1,1),
(@heroic25,45816,-100,0,1,1,1),
(@heroic25,45641,0,1,1,1,1),
(@heroic25,45642,0,1,1,1,1),
(@heroic25,45643,0,1,1,1,1),
(@heroic25,47241,100,0,1,1,1),
(@heroic25,45945,0,2,1,1,1);

UPDATE `gameobject_template` SET `data1` = @normal10 WHERE `data1` = 27085 AND `entry` = 194789;
UPDATE `gameobject_template` SET `data1` = @heroic10 WHERE `data1` = 27086 AND `entry` = 194957;
UPDATE `gameobject_template` SET `data1` = @normal25 WHERE `data1` = 26963 AND `entry` = 194956;
UPDATE `gameobject_template` SET `data1` = @heroic25 WHERE `data1` = 26967 AND `entry` = 194958;

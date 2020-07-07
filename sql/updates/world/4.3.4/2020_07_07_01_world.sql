-- Stormwind Rat
DELETE FROM `creature_loot_template` WHERE `Entry`= 49540;
UPDATE `creature_template` SET `lootid`= 0 WHERE `entry`= 49540;

-- Oasis Moth
DELETE FROM `creature_loot_template` WHERE `Entry`= 50496;
UPDATE `creature_template` SET `lootid`= 0 WHERE `entry`= 50496;

-- Master Chef's Groceries
SET @ENTRY := 69822;
DELETE FROM `item_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, 62780, 0, 1, 18, 20),
(@ENTRY, 62784, 0, 1, 18, 20),
(@ENTRY, 62791, 0, 1, 18, 20),
(@ENTRY, 62779, 0, 1, 18, 20),
(@ENTRY, 62781, 0, 1, 18, 20),
(@ENTRY, 62783, 0, 1, 18, 20),
(@ENTRY, 62782, 0, 1, 18, 20),
(@ENTRY, 62778, 0, 1, 18, 20),
(@ENTRY, 62785, 0, 1, 18, 20);

-- Gub's Catch
SET @ENTRY := 69823;
DELETE FROM `item_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, 53070, 0, 1, 18, 20),
(@ENTRY, 53068, 0, 1, 18, 20),
(@ENTRY, 53072, 0, 1, 18, 20),
(@ENTRY, 53071, 0, 1, 18, 20);

-- Water-Filled Gills
SET @ENTRY := 70719;
DELETE FROM `item_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, 52326, 100, 0, 18, 20);

-- Hive Queen's Honeycomb
SET @ENTRY := 69817;
DELETE FROM `item_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, 52987, 0, 1, 4, 6),
(@ENTRY, 52328, 0, 1, 4, 6),
(@ENTRY, 52329, 0, 1, 4, 6);

-- Giant Sack
SET @ENTRY := 69818;
DELETE FROM `item_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, 52185, 0, 1, 8, 15),
(@ENTRY, 52180, 0, 2, 1, 2),
(@ENTRY, 52182, 0, 2, 1, 2),
(@ENTRY, 52178, 0, 2, 1, 2);

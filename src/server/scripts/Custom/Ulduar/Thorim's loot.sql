
-- Loot fetched from GC's mangos database

SET @normal10 := 196000;
SET @heroic10 := 196001;
SET @normal25 := 196002;
SET @heroic25 := 196003;

DELETE FROM `gameobject_loot_template` WHERE `entry` = @normal10;
INSERT INTO `gameobject_loot_template` (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, lootmode) VALUES
(@normal10, 47241, 100, 0, 1, 1, 1),
(@normal10, 45659, 0, 1, 1, 1, 1),
(@normal10, 45660, 0, 1, 1, 1, 1),
(@normal10, 45661, 0, 1, 1, 1, 1),
(@normal10, 45892, 0, 2, 1, 1, 1),
(@normal10, 45893, 0, 2, 1, 1, 1),
(@normal10, 45894, 0, 2, 1, 1, 1),
(@normal10, 45895, 0, 2, 1, 1, 1),
(@normal10, 45927, 0, 2, 1, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE `entry` = @heroic10;
INSERT INTO `gameobject_loot_template` (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, lootmode) VALUES
(@heroic10, 45087, 70, 0, 1, 1, 1),
(@heroic10, 47241, 100, 0, 1, 1, 1),
(@heroic10, 45784, -100, 0, 1, 1, 1),
(@heroic10, 45928, 0, 2, 1, 1, 1),
(@heroic10, 45929, 0, 2, 1, 1, 1),
(@heroic10, 45930, 0, 2, 1, 1, 1),
(@heroic10, 45931, 0, 2, 1, 1, 1),
(@heroic10, 45933, 0, 2, 1, 1, 1),
(@heroic10, 45892, 0, 3, 1, 1, 1),
(@heroic10, 45893, 0, 3, 1, 1, 1),
(@heroic10, 45894, 0, 3, 1, 1, 1),
(@heroic10, 45895, 0, 3, 1, 1, 1),
(@heroic10, 45927, 0, 3, 1, 1, 1),
(@heroic10, 45659, 0, 1, 1, 1, 1),
(@heroic10, 45660, 0, 1, 1, 1, 1),
(@heroic10, 45661, 0, 1, 1, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE `entry` = @normal25;
INSERT INTO `gameobject_loot_template` (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, lootmode) VALUES
(@normal25, 45038, 15, 0, 1, 1, 1),
(@normal25, 45087, 70, 0, 1, 1, 1),
(@normal25, 45463, 0, 2, 1, 1, 1), 
(@normal25, 45466, 0, 2, 1, 1, 1),
(@normal25, 45467, 0, 2, 1, 1, 1),
(@normal25, 45468, 0, 2, 1, 1, 1),
(@normal25, 45469, 0, 2, 1, 1, 1),
(@normal25, 47241, 100, 0, 1, 1, 1),
(@normal25, 45638, 0, 1, 1, 1, 1),
(@normal25, 45639, 0, 1, 1, 1, 1),
(@normal25, 45640, 0, 1, 1, 1, 1);

DELETE FROM `gameobject_loot_template` WHERE `entry` = @heroic25;
INSERT INTO `gameobject_loot_template` (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, lootmode) VALUES
(@heroic25, 45470, 0, 2, 1, 1, 1),
(@heroic25, 45471, 0, 2, 1, 1, 1),
(@heroic25, 45472, 0, 2, 1, 1, 1),
(@heroic25, 45473, 0, 2, 1, 1, 1),
(@heroic25, 45474, 0, 2, 1, 1, 1),
(@heroic25, 45570, 0, 2, 1, 1, 1),
(@heroic25, 47241, 100, 0, 1, 1, 1),
(@heroic25, 45817, -100, 0, 1, 1, 1),
(@heroic25, 45463, 0, 3, 1, 1, 1), 
(@heroic25, 45466, 0, 3, 1, 1, 1),
(@heroic25, 45467, 0, 3, 1, 1, 1),
(@heroic25, 45468, 0, 3, 1, 1, 1),
(@heroic25, 45469, 0, 3, 1, 1, 1),
(@heroic25, 45638, 0, 1, 1, 1, 1),
(@heroic25, 45639, 0, 1, 1, 1, 1),
(@heroic25, 45640, 0, 1, 1, 1, 1);

-- Update go's
UPDATE `gameobject_template` SET `data1` = 196000 WHERE `data1` = 27073 AND `entry` = 194312;
UPDATE `gameobject_template` SET `data1` = 196001 WHERE `data1` = 27074 AND `entry` = 194313;
UPDATE `gameobject_template` SET `data1` = 196002 WHERE `data1` = 26956 AND `entry` = 194315;
UPDATE `gameobject_template` SET `data1` = 196003 WHERE `data1` = 26955 AND `entry` = 194314;


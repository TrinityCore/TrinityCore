-- Fix Decoy! (8606) quest items drop chance from Narain's Special Kit (21042)
SET @Kit := 21042;
DELETE FROM `item_loot_template` WHERE `entry`= @Kit;
INSERT INTO `item_loot_template` VALUES 
(@Kit, 21037, 100, 1, 0, 1, 1), -- Crude Map
(@Kit, 21039, 100, 1, 0, 1, 1), -- Narain's Turban
(@Kit, 21040, 100, 1, 0, 1, 1), -- Narain's Robe
(@Kit, 21041, 100, 1, 0, 1, 1); -- Bag of Gold

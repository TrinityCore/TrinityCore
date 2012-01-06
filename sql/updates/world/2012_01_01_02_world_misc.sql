-- Fix Decoy! (8606) quest items drop chance from Narain's Special Kit (21042) item by nelegalno

DELETE FROM `item_loot_template` WHERE (`entry`=21042);
INSERT INTO `item_loot_template` VALUES 
(21042, 21037, 100, 1, 0, 1, 1),
(21042, 21039, 100, 1, 0, 1, 1),
(21042, 21040, 100, 1, 0, 1, 1),
(21042, 21041, 100, 1, 0, 1, 1);

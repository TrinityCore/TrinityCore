/*
-- 
-- Remove unique items from reference table 24068
DELETE FROM `reference_loot_template` WHERE `Entry`=24068 AND `Item` IN (897, 1351, 2015, 2017, 3053, 3336, 4723);
-- Add former items from reference table 24068 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (897, 1351, 2015, 2017, 3053, 3336, 4723);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(206,  897,  0.1, 0, "Nightbane Vile Fang - Madwolf Bracers"),
(3808, 1351, 0.1, 0, "Forsaken Dark Stalker - Fingerbone Bracers"),
(570,  2015, 1, 0, "Brain Eater - Black Metal War Axe"),
(785,  2017, 1,   0, "Skeletal Warder - Glowing Leather Bracers"),
(2344, 3053, 2.5, 0, "Dun Garok Mountaineer - Humbert's Chestpiece"),
(2368, 3336, 0.1, 0, "Daggerspine Shorestalker - Flesh Piercer"),
(2370, 3336, 0.1, 0, "Daggerspine Screamer - Flesh Piercer"),
(2346, 4723, 2.5, 0, "Dun Garok Priest - Humbert's Pants");
*/

-- 
-- Remove unique items from reference table 24066
DELETE FROM `reference_loot_template` WHERE `Entry`=24066 AND `Item` IN (886, 1077, 2013, 2227, 2233, 2566, 3204, 3569, 6315);
-- Add former items from reference table 24066 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (886, 1077, 2013, 2227, 2233, 2566, 3204, 3569, 6315);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(210,  886,  0.1, 0, "Bone Chewer - Black Metal Shortsword"),
(910,  1077, 0.1, 0, "Defias Enchanter - Defias Mage Ring"),
(787,  2013, 0.1, 0, "Skeletal Healer - Cryptbone Staff"),
(892,  2227, 0.1, 0, "Splinter Fist Taskmaster - Heavy Ogre War Axe"),
(533,  2233, 0.1, 0, "Nightbane Shadow Weaver - Shadow Weaver Leggings"),
(397,  2566, 1.5, 0, "Morganth - Sacrificial Robes"),
(2372, 3204, 0.1, 0, "Mudsnout Gnoll - Deepwood Bracers"),
(4517, 3569, 1.5, 0, "Death's Head Priest - Vicar's Robe"),
(6523, 6315, 0.1, 0, "Dark Iron Rifleman - Steelarrow Crossbow");

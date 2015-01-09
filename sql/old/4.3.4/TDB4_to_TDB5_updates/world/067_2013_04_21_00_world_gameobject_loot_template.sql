-- Updating maxcount for Scarab Scarab Bag
UPDATE `item_loot_template` SET `maxcount`=5 WHERE `entry`=21156 AND `item` IN (20858,20859,20860,20861,20862,20863,20864,20865);
UPDATE `reference_loot_template` SET `maxcount`=2 WHERE `entry`=14001 AND `item` IN (20866,20867,20868,20869,20870,20871,20872,20873);
-- Updating loot for Scarab Coffer
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (17532,17533);
INSERT INTO `gameobject_loot_template` VALUES 
-- Scarab Coffer
(17532,21156,-100,1,0,1,1), -- Always drop a Sacrab Bag
(17532,1,100,1,0,-14001,1), -- Drop a AQ20 idol from reference
-- Large Scarab Coffer
(17533,21156,-100,1,0,1,1), -- Always drop a Sacrab Bag
(17533,1,100,1,0,-14502,1); -- Drop a AQ40 idol from reference
-- Updating loot for Large Scarab Coffer
DELETE FROM `reference_loot_template` WHERE `entry`=14502;
INSERT INTO `reference_loot_template` VALUES 
(14502,20877,0,1,1,1,3), -- 1 to 3  Idol of the Sage
(14502,20879,0,1,1,1,3), -- 1 to 3  Idol of Life
(14502,20878,0,1,1,1,3), -- 1 to 3  Idol of Rebirth
(14502,20881,0,1,1,1,3), -- 1 to 3  Idol of Strife
(14502,20874,0,1,1,1,3), -- 1 to 3  Idol of the Sun
(14502,20882,0,1,1,1,3), -- 1 to 3  Idol of War
(14502,20876,0,1,1,1,3), -- 1 to 3  Idol of Death
(14502,20875,0,1,1,1,3); -- 1 to 3  Idol of Night

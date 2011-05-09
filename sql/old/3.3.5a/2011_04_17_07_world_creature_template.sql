-- Obsidian Sanctum
-- Template updates for creature 31103 (Twilight Egg (Cosmetic))
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432 WHERE `entry`=31103; -- Twilight Egg (Cosmetic)
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81 WHERE `entry`=30681; -- Onyx Blaze Mistress
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81 WHERE `entry`=30453; -- Onyx Sanctum Guardian
UPDATE `creature_template` SET `exp`=0,`unit_flags`=`unit_flags`|33554432 WHERE `entry`=30648; -- Fire Cyclone
UPDATE `creature_model_info` SET `bounding_radius`=2.25,`combat_reach`=4.5,`gender`=0 WHERE `modelid`=27421; -- Shadron
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2 WHERE `entry`=30616; -- Flame Tsunami

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=1.25,`combat_reach`=8.75,`gender`=0 WHERE `modelid`=27226; -- Onyx Brood General
UPDATE `creature_model_info` SET `bounding_radius`=3.75,`combat_reach`=3.75,`gender`=1 WHERE `modelid`=27227; -- Onyx Blaze Mistress
UPDATE `creature_model_info` SET `bounding_radius`=3.75,`combat_reach`=4.375,`gender`=0 WHERE `modelid`=12891; -- Onyx Flight Captain
UPDATE `creature_model_info` SET `bounding_radius`=2.25,`combat_reach`=4.5,`gender`=0 WHERE `modelid`=27039; -- Vesperon
UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=1,`gender`=0 WHERE `modelid`=27225; -- Onyx Sanctum Guardian
UPDATE `creature_model_info` SET `bounding_radius`=1.8,`combat_reach`=1,`gender`=2 WHERE `modelid`=27035; -- Sartharion

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (31103,30680,30681,30682,30449,30453,30648,30451,28860,30616);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31103,0,0,1,0, NULL), -- Twilight Egg (Cosmetic)
(30680,0,0,1,0, NULL), -- Onyx Brood General
(30681,0,0,1,0, NULL), -- Onyx Blaze Mistress
(30682,0,0,1,0, NULL), -- Onyx Flight Captain
(30449,0,0,1,0, NULL), -- Vesperon
(30453,0,0,1,0, NULL), -- Onyx Sanctum Guardian
(30648,0,0,1,0, NULL), -- Fire Cyclone
(30451,0,0,1,0, NULL), -- Shadron
(28860,0,0,1,0, NULL), -- Sartharion
(30616,0,0,1,0, NULL); -- Flame Tsunami

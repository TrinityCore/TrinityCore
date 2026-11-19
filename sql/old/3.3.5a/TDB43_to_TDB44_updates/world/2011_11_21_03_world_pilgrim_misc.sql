-- Misc stuffz
UPDATE `npc_text` SET `WDBVerified`=12340 WHERE `ID`=14648; -- "A Bountiful Table is laid out..."

-- Template updates
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=3,  `unit_flags`=33536 WHERE `entry`=34654; -- Bountiful Feast Hostess
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`unit_flags`=33536 WHERE `entry`=34678; -- Dokin Farplain
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34684; -- Laha Farplain
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35343; -- Bountiful Barrel
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34685; -- Dalni Tallgrass
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35342; -- Bountiful Barrel
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34713; -- Ondani Greatmill
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34787; -- John Rigsdale
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34786; -- Alice Rigsdale
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`unit_flags`=33536 WHERE `entry`=34677; -- Miles Standish
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34712; -- Roberta Carter
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34683; -- Rose Standish
UPDATE `creature_template` SET `faction_A`=714,`faction_H`=714,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35341; -- Bountiful Barrel

UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=16777216,`unit_flags`=16384,`speed_run`=1.57143,`VehicleId`=321 WHERE `entry`=34819; -- The Stuffing Chair
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=16777216,`unit_flags`=16384,`speed_run`=1.57143,`VehicleId`=321 WHERE `entry`=34824; -- The Sweet Potato Chair
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=16777216,`unit_flags`=16384,`speed_run`=1.57143,`VehicleId`=321 WHERE `entry`=34823; -- The Cranberry Chair
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=16777216,`unit_flags`=16384,`speed_run`=1.57143,`VehicleId`=321 WHERE `entry`=34812; -- The Turkey Chair
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=16777216,`unit_flags`=16384,`speed_run`=1.57143,`VehicleId`=321 WHERE `entry`=34822; -- The Pie Chair

UPDATE `creature_model_info` SET `bounding_radius`=0.8725,`combat_reach`=3.75,`gender`=1 WHERE `modelid`=29330; -- Bountiful Feast Hostess
UPDATE `creature_model_info` SET `bounding_radius`=0.9747,`combat_reach`=4.05,`gender`=0 WHERE `modelid`=29339; -- Dokin Farplain
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=0,`gender`=0 WHERE `modelid`=29775; -- Bountiful Barrel
UPDATE `creature_model_info` SET `bounding_radius`=0.8725,`combat_reach`=3.75,`gender`=1 WHERE `modelid`=29342; -- Laha Farplain
UPDATE `creature_model_info` SET `bounding_radius`=1.6,`combat_reach`=0,`gender`=2 WHERE `modelid`=29205; -- Chairs
UPDATE `creature_model_info` SET `bounding_radius`=0.8725,`combat_reach`=3.75,`gender`=1 WHERE `modelid`=29397; -- Dalni Tallgrass
UPDATE `creature_model_info` SET `bounding_radius`=0.8725,`combat_reach`=3.75,`gender`=1 WHERE `modelid`=29401; -- Ondani Greatmill
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29428; -- John Rigsdale
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29427; -- Alice Rigsdale
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29338; -- Miles Standish
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29365; -- Roberta Carter
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29340; -- Rose Standish

DELETE FROM `creature_template_addon` WHERE `entry` IN (34654,34678,35343,34684,34819,34824,34823,34812,34822,34685,35342,34713,34787,34786,34677,34712,34683,35341);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34654,0,0,1,0, NULL), -- Bountiful Feast Hostess
(34678,0,0,2,0, NULL), -- Dokin Farplain
(35343,0,0,1,0, NULL), -- Bountiful Barrel (TB)
(34684,0,0,1,0, NULL), -- Laha Farplain
(34685,0,0,1,0, NULL), -- Dalni Tallgrass
(35342,0,0,1,0, NULL), -- Bountiful Barrel (OG)
(34713,0,0,2,0, NULL), -- Ondani Greatmill
(34787,0,0,1,0, NULL), -- John Rigsdale
(34786,0,0,2,0, NULL), -- Alice Rigsdale
(34677,0,0,2,0, NULL), -- Miles Standish
(34712,0,0,2,0, NULL), -- Roberta Carter
(34683,0,0,1,0, NULL), -- Rose Standish
(35341,0,0,1,0, NULL), -- Bountiful Barrel
(34819,0,0,1,0, '61795'), -- The Stuffing Chair (Stuffing Server)
(34824,0,0,1,0, '61797'), -- The Sweet Potato Chair (Sweet Potatoes Server)
(34823,0,0,1,0, '61793'), -- The Cranberry Chair (Cranberry Server)
(34812,0,0,1,0, '61796'), -- The Turkey Chair (Turkey Server)
(34822,0,0,1,0, '61794'); -- The Pie Chair (Pie Server)

-- Vehicles
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34819,34824,34823,34812,34822);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES
(34819, 65403, 0, 0, 0, 1, 0, 0, 0), -- The Stuffing Chair (Ride Vehicle)
(34824, 65403, 0, 0, 0, 1, 0, 0, 0), -- The Sweet Potato Chair (Ride Vehicle)
(34823, 65403, 0, 0, 0, 1, 0, 0, 0), -- The Cranberry Chair (Ride Vehicle)
(34812, 65403, 0, 0, 0, 1, 0, 0, 0), -- The Turkey Chair (Ride Vehicle)
(34822, 65403, 0, 0, 0, 1, 0, 0, 0); -- The Pie Chair (Ride Vehicle)

-- Gossips
UPDATE `creature_template` SET `gossip_menu_id`=10575 WHERE `entry`=34654; -- Bountiful Feast Hostess
DELETE FROM `gossip_menu` WHERE `entry`=10575 AND `text_id`=14633;
DELETE FROM `gossip_menu` WHERE `entry`=10589 AND `text_id`=14648;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10575, 14633),
(10589, 14648);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10575 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10575, 0, 0, 'How do the Bountiful Tables work?', 1, 1, 10589, 0, 0, 0, NULL);

-- Vendor tables
UPDATE `item_template` SET `BuyCount`=5 WHERE `entry` IN (44835,44853,46797,46793,46796); -- Autumnal Herbs, Honey, Mulgore Sweet Potato, Tangy Southfury Cranberries, Ripe Tirisfal Pumpkin
DELETE FROM `npc_vendor` WHERE `entry` IN (35343,34684,35342,34685,34787,35341,34683);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`) VALUES
-- 35343 (Bountiful Barrel)
(35343, 1, 46810, 0, 0), -- Bountiful Cookbook
(35343, 2, 46797, 0, 0), -- Mulgore Sweet Potato
(35343, 3, 44835, 0, 0), -- Autumnal Herbs
(35343, 4, 44853, 0, 0), -- Honey
(35343, 5, 159, 0, 0), -- Refreshing Spring Water
(35343, 6, 2678, 0, 0), -- Mild Spices
(35343, 7, 30817, 0, 0), -- Simple Flour
(35343, 8, 46888, 0, 0), -- Bountiful Basket
-- 34684 (Laha Farplain)
(34684, 1, 46810, 0, 0), -- Bountiful Cookbook
(34684, 2, 46797, 0, 0), -- Mulgore Sweet Potato
(34684, 3, 44835, 0, 0), -- Autumnal Herbs
(34684, 4, 44853, 0, 0), -- Honey
(34684, 5, 159, 0, 0), -- Refreshing Spring Water
(34684, 6, 2678, 0, 0), -- Mild Spices
(34684, 7, 30817, 0, 0), -- Simple Flour
(34684, 8, 46888, 0, 0), -- Bountiful Basket
-- 35342 (Bountiful Barrel)
(35342, 1, 46810, 0, 0), -- Bountiful Cookbook
(35342, 2, 46793, 0, 0), -- Tangy Southfury Cranberries
(35342, 3, 44835, 0, 0), -- Autumnal Herbs
(35342, 4, 44853, 0, 0), -- Honey
(35342, 5, 159, 0, 0), -- Refreshing Spring Water
(35342, 6, 2678, 0, 0), -- Mild Spices
(35342, 7, 30817, 0, 0), -- Simple Flour
(35342, 8, 46888, 0, 0), -- Bountiful Basket
-- 34685 (Dalni Tallgrass)
(34685, 1, 46810, 0, 0), -- Bountiful Cookbook
(34685, 2, 46793, 0, 0), -- Tangy Southfury Cranberries
(34685, 3, 44835, 0, 0), -- Autumnal Herbs
(34685, 4, 44853, 0, 0), -- Honey
(34685, 5, 159, 0, 0), -- Refreshing Spring Water
(34685, 6, 2678, 0, 0), -- Mild Spices
(34685, 7, 30817, 0, 0), -- Simple Flour
(34685, 8, 46888, 0, 0), -- Bountiful Basket
-- 34787 (John Rigsdale)
(34787, 1, 46810, 0, 0), -- Bountiful Cookbook
(34787, 2, 44835, 0, 0), -- Autumnal Herbs
(34787, 3, 44853, 0, 0), -- Honey
(34787, 4, 159, 0, 0), -- Refreshing Spring Water
(34787, 5, 2678, 0, 0), -- Mild Spices
(34787, 6, 30817, 0, 0), -- Simple Flour
(34787, 7, 46888, 0, 0), -- Bountiful Basket
-- 35341 (Bountiful Barrel)
(35341, 1, 46810, 0, 0), -- Bountiful Cookbook
(35341, 2, 46796, 0, 0), -- Ripe Tirisfal Pumpkin
(35341, 3, 44835, 0, 0), -- Autumnal Herbs
(35341, 4, 44853, 0, 0), -- Honey
(35341, 5, 159, 0, 0), -- Refreshing Spring Water
(35341, 6, 2678, 0, 0), -- Mild Spices
(35341, 7, 30817, 0, 0), -- Simple Flour
(35341, 8, 46888, 0, 0), -- Bountiful Basket
-- 34683 (Rose Standish)
(34683, 1, 46810, 0, 0), -- Bountiful Cookbook
(34683, 2, 46796, 0, 0), -- Ripe Tirisfal Pumpkin
(34683, 3, 44835, 0, 0), -- Autumnal Herbs
(34683, 4, 44853, 0, 0), -- Honey
(34683, 5, 159, 0, 0), -- Refreshing Spring Water
(34683, 6, 2678, 0, 0), -- Mild Spices
(34683, 7, 30817, 0, 0), -- Simple Flour
(34683, 8, 46888, 0, 0); -- Bountiful Basket

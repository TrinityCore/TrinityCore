DELETE FROM `creature_template_addon` WHERE `entry` IN (32823,34645,34783,34682,35337,35338,35340,34711,34676,34708,34644,34744,34710,34675);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32823,0,0,1,0, NULL), -- Bountiful Table
(34645,0,0,1,0, NULL), -- Elizabeth Barker Winslow
(34783,0,0,1,0, NULL), -- Ranisa Whitebough
(34682,0,0,1,0, NULL), -- Wilmina Holbeck
(35337,0,0,1,0, NULL), -- Bountiful Barrel
(35338,0,0,1,0, NULL), -- Bountiful Barrel
(35340,0,0,1,0, NULL), -- Bountiful Barrel
(34711,0,0,2,0, NULL), -- Mary Allerton
(34676,0,0,2,0, NULL), -- Isaac Allerton
(34708,0,0,2,0, NULL), -- Caitrin Ironkettle
(34644,0,0,2,0, NULL), -- Edward Winslow
(34744,0,0,1,0, NULL), -- Jasper Moore
(34710,0,0,1,0, NULL), -- Ellen Moore
(34675,0,0,2,0, NULL); -- Gregory Tabor

UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34783; -- Ranisa Whitebough
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34645; -- Elizabeth Barker Winslow
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34681; -- Ikaneba Summerset
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`unit_flags`=33536 WHERE `entry`=34682; -- Wilmina Holbeck
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35337; -- Bountiful Barrel
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35338; -- Bountiful Barrel
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=640,`speed_run`=1 WHERE `entry`=35340; -- Bountiful Barrel
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34711; -- Mary Allerton
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`unit_flags`=33536 WHERE `entry`=34676; -- Isaac Allerton
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34708; -- Caitrin Ironkettle
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`unit_flags`=33536 WHERE `entry`=34644; -- Edward Winslow
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=3,`unit_flags`=33536 WHERE `entry`=34744; -- Jasper Moore
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`npcflag`=83,`unit_flags`=33536 WHERE `entry`=34710; -- Ellen Moore
UPDATE `creature_template` SET `faction_A`=534,`faction_H`=534,`baseattacktime`=2000,`unit_flags`=33536 WHERE `entry`=34675; -- Gregory Tabor

UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29394; -- Elizabeth Barker Winslow
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29430; -- Ranisa Whitebough
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29393; -- Ikaneba Summerset
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29329; -- Wilmina Holbeck
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29388; -- Mary Allerton
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29391; -- Isaac Allerton
UPDATE `creature_model_info` SET `bounding_radius`=0.347,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29324; -- Caitrin Ironkettle
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29392; -- Edward Winslow
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29444; -- Jasper Moore
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29400; -- Ellen Moore
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29337; -- Gregory Tabor

UPDATE `item_template` SET `BuyCount`=5 WHERE `entry` IN (44854,46784,44855);
DELETE FROM `npc_vendor` WHERE `entry` IN (34645, 34783, 35337, 35338, 35340, 34681, 34682);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`) VALUES
-- 34645 (Elizabeth Barker Winslow)
(34645, 1, 46809, 0, 0), -- Bountiful Cookbook
(34645, 2, 44854, 0, 0), -- Tangy Wetland Cranberries
(34645, 3, 44835, 0, 0), -- Autumnal Herbs
(34645, 4, 44853, 0, 0), -- Honey
(34645, 5, 159, 0, 0), -- Refreshing Spring Water
(34645, 6, 2678, 0, 0), -- Mild Spices
(34645, 7, 30817, 0, 0), -- Simple Flour
(34645, 8, 46888, 0, 0), -- Bountiful Basket
-- 34783 (Ranisa Whitebough)
(34783, 1, 46809, 0, 0), -- Bountiful Cookbook
(34783, 2, 44835, 0, 0), -- Autumnal Herbs
(34783, 3, 44853, 0, 0), -- Honey
(34783, 4, 159, 0, 0), -- Refreshing Spring Water
(34783, 5, 2678, 0, 0), -- Mild Spices
(34783, 6, 30817, 0, 0), -- Simple Flour
(34783, 7, 46888, 0, 0), -- Bountiful Basket
-- 35337 (Bountiful Barrel)
(35337, 1, 46809, 0, 0), -- Bountiful Cookbook
(35337, 2, 46784, 0, 0), -- Ripe Elwynn Pumpkin
(35337, 3, 44835, 0, 0), -- Autumnal Herbs
(35337, 4, 44853, 0, 0), -- Honey
(35337, 5, 159, 0, 0), -- Refreshing Spring Water
(35337, 6, 2678, 0, 0), -- Mild Spices
(35337, 7, 30817, 0, 0), -- Simple Flour
(35337, 8, 46888, 0, 0), -- Bountiful Basket
-- 35338 (Bountiful Barrel)
(35338, 1, 46809, 0, 0), -- Bountiful Cookbook
(35338, 2, 44855, 0, 0), -- Teldrassil Sweet Potato
(35338, 3, 44835, 0, 0), -- Autumnal Herbs
(35338, 4, 44853, 0, 0), -- Honey
(35338, 5, 159, 0, 0), -- Refreshing Spring Water
(35338, 6, 2678, 0, 0), -- Mild Spices
(35338, 7, 30817, 0, 0), -- Simple Flour
(35338, 8, 46888, 0, 0), -- Bountiful Basket
-- 35340 (Bountiful Barrel)
(35340, 1, 46809, 0, 0), -- Bountiful Cookbook
(35340, 2, 44854, 0, 0), -- Tangy Wetland Cranberries
(35340, 3, 44835, 0, 0), -- Autumnal Herbs
(35340, 4, 44853, 0, 0), -- Honey
(35340, 5, 159, 0, 0), -- Refreshing Spring Water
(35340, 6, 2678, 0, 0), -- Mild Spices
(35340, 7, 30817, 0, 0), -- Simple Flour
(35340, 8, 46888, 0, 0), -- Bountiful Basket
-- 34681 (Ikaneba Summerset)
(34681, 1, 46809, 0, 0), -- Bountiful Cookbook
(34681, 2, 44855, 0, 0), -- Teldrassil Sweet Potato
(34681, 3, 44835, 0, 0), -- Autumnal Herbs
(34681, 4, 44853, 0, 0), -- Honey
(34681, 5, 159, 0, 0), -- Refreshing Spring Water
(34681, 6, 2678, 0, 0), -- Mild Spices
(34681, 7, 30817, 0, 0), -- Simple Flour
(34681, 8, 46888, 0, 0), -- Bountiful Basket
-- 34682 (Wilmina Holbeck)
(34682, 1, 46809, 0, 0), -- Bountiful Cookbook
(34682, 2, 46784, 0, 0), -- Ripe Elwynn Pumpkin
(34682, 3, 44835, 0, 0), -- Autumnal Herbs
(34682, 4, 44853, 0, 0), -- Honey
(34682, 5, 159, 0, 0), -- Refreshing Spring Water
(34682, 6, 2678, 0, 0), -- Mild Spices
(34682, 7, 30817, 0, 0), -- Simple Flour
(34682, 8, 46888, 0, 0); -- Bountiful Basket

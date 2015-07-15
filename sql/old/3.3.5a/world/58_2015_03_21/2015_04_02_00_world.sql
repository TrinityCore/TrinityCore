SET @CGUID		:= 76018;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 21664, 532, 3, 1, -11086.92, -1899.176, 220.7505, 0.7330383, 7200, 0, 0), -- 21664 (Area: 3457) (Auras: )
(@CGUID+1, 21664, 532, 3, 1, -11104.63, -1877.507, 220.7505, 0.6806784, 7200, 0, 0), -- 21664 (Area: 3457) (Auras: )
(@CGUID+2, 17469, 532, 3, 1, -11064.65, -1874.336, 220.7505, 3.839724, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+3, 17211, 532, 3, 1, -11089.7, -1887.114, 220.7505, 0.715585, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+4, 17211, 532, 3, 1, -11093.26, -1882.732, 220.7505, 0.6632251, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+5, 17211, 532, 3, 1, -11096.65, -1878.406, 220.7505, 0.6632251, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+6, 21160, 532, 3, 1, -11083.24, -1903.355, 220.7504, 0.6632251, 7200, 0, 0), -- 21160 (Area: 3457) (Auras: 32226 - 32226)
(@CGUID+7, 17211, 532, 3, 1, -11100.17, -1873.871, 220.7505, 0.6457718, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+8, 17211, 532, 3, 1, -11079.32, -1900.23, 220.7504, 0.6632251, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+9, 17211, 532, 3, 1, -11103.67, -1869.466, 220.7505, 0.6981317, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+10, 17469, 532, 3, 1, -11068.14, -1869.956, 220.7505, 3.892084, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+11, 17211, 532, 3, 1, -11082.71, -1895.736, 220.7505, 0.6632251, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: )
(@CGUID+12, 17469, 532, 3, 1, -11071.65, -1865.527, 220.7505, 3.822271, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+13, 17211, 532, 3, 1, -11086.31, -1891.324, 220.7505, 0.6457718, 7200, 0, 0), -- 17211 (Area: 3457) (Auras: 32226 - 32226)
(@CGUID+14, 17469, 532, 3, 1, -11075.02, -1861.288, 220.7505, 3.735005, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+15, 17469, 532, 3, 1, -11078.52, -1856.995, 220.7505, 3.892084, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: 32226 - 32226)
(@CGUID+16, 21726, 532, 3, 1, -11053.46, -1879.717, 220.7505, 4.014257, 7200, 0, 0), -- 21726 (Area: 3457) (Auras: )
(@CGUID+17, 17469, 532, 3, 1, -11057.62, -1883.089, 220.7505, 3.804818, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+18, 17469, 532, 3, 1, -11082.03, -1852.191, 220.7505, 3.804818, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+19, 21747, 532, 3, 1, -11060.35, -1870.903, 220.7505, 3.804818, 7200, 0, 0), -- 21747 (Area: 3457) (Auras: )
(@CGUID+20, 21748, 532, 3, 1, -11056.89, -1875.286, 220.7505, 3.665191, 7200, 0, 0), -- 21748 (Area: 3457) (Auras: )
(@CGUID+21, 21726, 532, 3, 1, -11077.72, -1848.789, 220.7505, 3.909538, 7200, 0, 0), -- 21726 (Area: 3457) (Auras: )
(@CGUID+22, 17469, 532, 3, 1, -11061.3, -1878.629, 220.7505, 3.909538, 7200, 0, 0), -- 17469 (Area: 3457) (Auras: )
(@CGUID+23, 21747, 532, 3, 1, -11070.86, -1857.749, 220.7505, 3.839724, 7200, 0, 0), -- 21747 (Area: 3457) (Auras: )
(@CGUID+24, 21748, 532, 3, 1, -11074.35, -1853.261, 220.7505, 3.735005, 7200, 0, 0), -- 21748 (Area: 3457) (Auras: )
(@CGUID+25, 21750, 532, 3, 1, -11067.6, -1861.944, 220.7505, 3.839724, 7200, 0, 0), -- 21750 (Area: 3457) (Auras: )
(@CGUID+26, 21752, 532, 3, 1, -11063.64, -1866.364, 220.7505, 3.822271, 7200, 0, 0), -- 21752 (Area: 3457) (Auras: 32226 - 32226)
(@CGUID+27, 21160, 532, 3, 1, -11107.91, -1873.032, 220.7505, 0.715585, 7200, 0, 0), -- 21160 (Area: 3457) (Auras: )
(@CGUID+28, 21682, 532, 3, 1, -11101.01, -1881.932, 220.7505, 0.6632251, 7200, 0, 0), -- 21682 (Area: 3457) (Auras: )
(@CGUID+29, 21683, 532, 3, 1, -11097.45, -1886.197, 220.7505, 0.7853982, 7200, 0, 0), -- 21683 (Area: 3457) (Auras: 32226 - 32226)
(@CGUID+30, 21682, 532, 3, 1, -11090.56, -1894.994, 220.7505, 0.6283185, 7200, 0, 0), -- 21682 (Area: 3457) (Auras: )
(@CGUID+31, 21684, 532, 3, 1, -11093.84, -1890.473, 220.7505, 0.6981317, 7200, 0, 0); -- 21684 (Area: 3457) (Auras: )

DELETE FROM `gossip_menu` WHERE `entry` IN(8404,8368,8354,8355,8366,8362,8367,7413,8345,8346,8347,8349,8348);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(8404,10506), -- 16816
(8404,10718), -- 16816
(8368,10442), -- 21752
(8354,10425), -- 17469
(8355,10426), -- 21726
(8366,10439), -- 21748
(8362,10434), -- 21747
(8367,10440), -- 21750
(7413,8952), -- 17211
(8345,10413), -- 21160
(8346,10414), -- 21664
(8347,10416), -- 21682
(8349,10418), -- 21684
(8348,10417); -- 21683

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(8404,8368,8354,8355,8366,8362,8367,7413,8345,8346,8347,8349,8348);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8368, 0, 0, 'Control Warchief Blackhand', 19384, 1, 1, 0, 0, 0, 0, NULL, 0),
(8349, 0, 0, 'Control King Llane', 19297, 1, 1, 0, 0, 0, 0, NULL, 0),
(8354, 0, 0, 'Control Orc Grunt', 19320, 1, 1, 0, 0, 0, 0, NULL, 0),
(8355, 0, 0, 'Control Summoned Daemon', 19323, 1, 1, 0, 0, 0, 0, NULL, 0),
(8366, 0, 0, 'Control Orc Wolf', 19375, 1, 1, 0, 0, 0, 0, NULL, 0),
(8362, 0, 0, 'Control Orc Necrolyte', 19367, 1, 1, 0, 0, 0, 0, NULL, 0),
(8367, 0, 0, 'Control Orc Warlock', 19377, 1, 1, 0, 0, 0, 0, NULL, 0),
(7413, 0, 0, 'Control Human Footman', 14008, 1, 1, 0, 0, 0, 0, NULL, 0),
(8345, 0, 0, 'Control Conjured Water Elemental.', 19285, 1, 1, 0, 0, 0, 0, NULL, 0),
(8346, 0, 0, 'Control Human Charger.', 19288, 1, 1, 0, 0, 0, 0, NULL, 0),
(8347, 0, 0, 'Control Human Cleric', 19293, 1, 1, 0, 0, 0, 0, NULL, 0),
(8348, 0, 0, 'Control Human Conjurer', 19295, 1, 1, 0, 0, 0, 0, NULL, 0);

UPDATE `creature_template` SET `gossip_menu_id`=8404 WHERE  `entry`=16816;
UPDATE `creature_template` SET `gossip_menu_id`=8368 WHERE  `entry`=21752;
UPDATE `creature_template` SET `gossip_menu_id`=8354 WHERE  `entry`=17469;
UPDATE `creature_template` SET `gossip_menu_id`=8355 WHERE  `entry`=21726;
UPDATE `creature_template` SET `gossip_menu_id`=8366 WHERE  `entry`=21748;
UPDATE `creature_template` SET `gossip_menu_id`=8362 WHERE  `entry`=21747;
UPDATE `creature_template` SET `gossip_menu_id`=8367 WHERE  `entry`=21750;
UPDATE `creature_template` SET `gossip_menu_id`=7413 WHERE  `entry`=17211;
UPDATE `creature_template` SET `gossip_menu_id`=8345 WHERE  `entry`=21160;
UPDATE `creature_template` SET `gossip_menu_id`=8346 WHERE  `entry`=21664;
UPDATE `creature_template` SET `gossip_menu_id`=8347 WHERE  `entry`=21682;
UPDATE `creature_template` SET `gossip_menu_id`=8348 WHERE  `entry`=21683;


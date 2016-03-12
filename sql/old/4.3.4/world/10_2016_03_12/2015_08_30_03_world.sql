--
SET @CGUID := 287252;
SET @OLDCGUID := 25;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 44865, 1, 1, 1643.72, -4443.32, 18.61603, 1.570796, 120, 0, 0), -- Auctioneer Fazdran (Area: Valley of Strength)
(@CGUID+1, 44867, 1, 1, 1640.17, -4445.12, 18.61683, 2.251475, 120, 0, 0), -- Auctioneer Ralinza (Area: Valley of Strength)
(@CGUID+2, 44866, 1, 1, 1637.42, -4448.21, 18.61663, 2.408554, 120, 0, 0), -- Auctioneer Drezmit (Area: Valley of Strength)
(@CGUID+3, 44868, 1, 1, 1635.46, -4451.19, 18.61623, 3.176499, 120, 0, 0); -- Auctioneer Xifa (Area: Valley of Strength)
 
-- The Drag
SET @CGUID := 370865;
SET @OLDCGUID := 81;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 14451, 1, 1, 1818.58, -4514.46, 23.58583, 4.921828, 120, 0, 0), -- Orphan Matron Battlewail (Area: The Drag)
(@CGUID+1, 14499, 1, 1, 1814.32, -4496.01, 24.43963, 2.635447, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+2, 14499, 1, 1, 1813.079, -4504.531, 24.42935, 4.330676, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+3, 14499, 1, 1, 1812.67, -4494.27, 24.41623, 5.096361, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+4, 14499, 1, 1, 1814.645, -4505.915, 24.47924, 2.856299, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+5, 14499, 1, 1, 1812.57, -4496.78, 24.40493, 1.186824, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+6, 14499, 1, 1, 1804.7, -4502.45, 24.43733, 3.961897, 120, 0, 0), -- Horde Orphan (Area: The Drag)
(@CGUID+7, 14498, 1, 1, 1810.56, -4502.17, 24.41543, 5.148721, 120, 0, 0), -- Tosamina (Area: The Drag)
(@CGUID+8, 3317, 1, 1, 1814.78, -4563.1, 23.00011, 2.286381, 120, 0, 0), -- Ollanus (Area: The Drag)
(@CGUID+9, 3364, 1, 1, 1807.04, -4563.03, 23.00011, 1.658063, 120, 0, 0), -- Borya (Area: The Drag) (possible waypoints or random movement)
(@CGUID+10, 3363, 1, 1, 1801.01, -4563.08, 23.08343, 1.553343, 120, 0, 0), -- Magar (Area: The Drag)
(@CGUID+11, 3315, 1, 1, 1791.28, -4566.03, 23.08343, 0.6806784, 120, 0, 0), -- Tor'phan (Area: The Drag)
(@CGUID+12, 2855, 1, 1, 1810.65, -4575.83, 23.00011, 5.445427, 120, 0, 0), -- Snang (Area: The Drag) (possible waypoints or random movement)
(@CGUID+13, 52809, 1, 1, 1860.115, -4525.585, 24.72254, 5.719091, 120, 0, 0), -- Blax Bottlerocket (Area: The Drag) (Auras: )
(@CGUID+14, 3369, 1, 1, 1778.911, -4505.396, 27.73932, 3.979351, 120, 0, 0), -- Gotri (Area: The Drag)
(@CGUID+15, 54472, 1, 1, 1721.033, -4513.222, 31.25615, 0.29052, 120, 0, 0), -- Vaultkeeper Jazra (Area: The Drag)
(@CGUID+16, 54473, 1, 1, 1727.328, -4519.503, 32.6442, 1.291544, 120, 0, 0), -- Warpweaver Dushar (Area: The Drag) (Auras: )
(@CGUID+17, 57801, 1, 1, 1727.368, -4507.533, 30.77355, 4.817109, 120, 0, 0), -- Thaumaturge Altha (Area: The Drag)
(@CGUID+18, 42506, 1, 1, 1762.285, -4489.653, 45.0499, 3.455752, 120, 0, 0), -- Marogg (Area: The Drag)
(@CGUID+19, 49737, 1, 1, 1763.764, -4494.328, 45.0406, 3.612832, 120, 0, 0), -- Shazdar (Area: The Drag)
(@CGUID+20, 3368, 1, 1, 1773.65, -4490.16, 45.64117, 4.520403, 120, 0, 0), -- Borstan (Area: The Drag)
(@CGUID+21, 46709, 1, 1, 1772.18, -4482.51, 45.64117, 0.8794622, 120, 0, 0), -- Arugi (Area: The Drag)
(@CGUID+22, 46708, 1, 1, 1779.2, -4489.25, 45.64117, 4.64705, 120, 0, 0); -- Suja (Area: The Drag)
 
-- @CGUID+09*10 (90)
SET @NPC := @CGUID+09;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1811.28,`position_y`=-4565.53,`position_z`=23.00011 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1811.28,-4565.53,23.00011,0,5000,0,0,100,0),
(@PATH,2,1807.04,-4563.03,23.00011,0,5000,0,0,100,0);
 
-- @CGUID+12*10 (93)
SET @NPC := @CGUID+12;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1810.36,`position_y`=-4575.28,`position_z`=23.25011 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1810.36,-4575.28,23.25011,0,0,0,0,100,0),
(@PATH,2,1810.65,-4575.83,23.00011,5.445427,5000,0,0,100,0),
(@PATH,3,1811.31,-4571.17,23.00011,0,0,0,0,100,0),
(@PATH,4,1811.516,-4571.172,23.25011,0,0,0,0,100,0),
(@PATH,5,1815.552,-4570.529,23.25011,0,0,0,0,100,0),
(@PATH,6,1815.29,-4571.68,23.25011,0,0,0,0,100,0),
(@PATH,7,1811.582,-4571.169,23.25011,0,0,0,0,100,0),
(@PATH,8,1810.36,-4575.28,23.25011,0,0,0,0,100,0);
 
-- @CGUID+13*10 (94)
SET @NPC := @CGUID+13;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1814.534,`position_y`=-4524.287,`position_z`=23.4143 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1814.534,-4524.287,23.4143,0,0,0,0,100,0),
(@PATH,2,1792.397,-4527.087,23.86665,0,0,0,0,100,0),
(@PATH,3,1784.647,-4527.587,24.36665,0,0,0,0,100,0),
(@PATH,4,1775.957,-4528.342,25.0537,0,0,0,0,100,0),
(@PATH,5,1771.707,-4525.842,25.5537,0,0,0,0,100,0),
(@PATH,6,1766.957,-4522.842,26.3037,0,0,0,0,100,0),
(@PATH,7,1763.054,-4520.713,26.70084,0,0,0,0,100,0),
(@PATH,8,1757.339,-4520.239,27.29017,0,0,0,0,100,0),
(@PATH,9,1760.339,-4522.989,26.79017,0,0,0,0,100,0),
(@PATH,10,1763.839,-4525.989,26.29017,0,0,0,0,100,0),
(@PATH,11,1766.141,-4527.969,25.87352,0,0,0,0,100,0),
(@PATH,12,1769.641,-4529.719,25.12352,0,0,0,0,100,0),
(@PATH,13,1775.886,-4532.876,24.55395,0,0,0,0,100,0),
(@PATH,14,1782.636,-4533.376,24.05395,0,0,0,0,100,0),
(@PATH,15,1791.43,-4534.103,23.45097,0,0,0,0,100,0),
(@PATH,16,1811.443,-4530.402,23.69624,0,0,0,0,100,0),
(@PATH,17,1834.693,-4525.652,23.94624,0,0,0,0,100,0),
(@PATH,18,1846.413,-4522.951,24.25943,0,0,0,0,100,0),
(@PATH,19,1858.337,-4524.244,24.93543,0,0,0,0,100,0),
(@PATH,20,1863.337,-4527.494,25.43543,0,0,0,0,100,0),
(@PATH,21,1868.337,-4530.744,26.18543,0,0,0,0,100,0),
(@PATH,22,1872.587,-4533.244,26.68543,0,0,0,0,100,0),
(@PATH,23,1876.587,-4535.744,27.43543,0,0,0,0,100,0),
(@PATH,24,1880.76,-4538.204,28.17977,0,0,0,0,100,0),
(@PATH,25,1890.26,-4536.704,28.67977,0,0,0,0,100,0),
(@PATH,26,1894.436,-4535.524,28.95365,0,0,0,0,100,0),
(@PATH,27,1894.686,-4531.524,28.20365,0,0,0,0,100,0),
(@PATH,28,1894.936,-4525.524,27.70365,0,0,0,0,100,0),
(@PATH,29,1895.186,-4519.774,26.95365,0,0,0,0,100,0),
(@PATH,30,1895.436,-4514.774,26.45365,0,0,0,0,100,0),
(@PATH,31,1895.686,-4510.774,25.95365,0,0,0,0,100,0),
(@PATH,32,1895.721,-4505.721,25.05981,0,0,0,0,100,0),
(@PATH,33,1892.221,-4502.221,24.55981,0,0,0,0,100,0),
(@PATH,34,1889.471,-4499.721,24.05981,0,0,0,0,100,0),
(@PATH,35,1883.432,-4493.992,23.59523,0,0,0,0,100,0),
(@PATH,36,1863.914,-4510.189,23.8035,0,0,0,0,100,0),
(@PATH,37,1851.016,-4517.419,24.18311,0,0,0,0,100,0),
(@PATH,38,1838.676,-4521.322,24.12628,0,0,0,0,100,0),
(@PATH,39,1822.926,-4523.072,23.62628,0,0,0,0,100,0);
 
-- @CGUID+14*10 (94/940)
SET @NPC := @CGUID+14;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1773.416,`position_y`=-4510.458,`position_z`=28.04409 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1773.416,-4510.458,28.04409,0,0,0,0,100,0),
(@PATH,2,1774.916,-4509.208,27.79409,0,0,0,0,100,0),
(@PATH,3,1776.916,-4507.208,27.79409,0,0,0,0,100,0),
(@PATH,4,1778.911,-4505.396,27.73932,3.979351,5000,0,0,100,0);
 
-- @CGUID+21*10 (101)
SET @NPC := @CGUID+21;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1772.08,`position_y`=-4485.131,`position_z`=45.64117 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1772.08,-4485.131,45.64117,0,0,0,0,100,0),
(@PATH,2,1773.615,-4489.646,45.89117,0,0,0,0,100,0),
(@PATH,3,1773.65,-4490.16,45.64117,4.520403,5000,0,0,100,0),
(@PATH,4,1776.47,-4490.49,45.64117,0,0,0,0,100,0),
(@PATH,5,1773.65,-4490.16,45.64117,0,0,0,0,100,0),
(@PATH,6,1773.65,-4490.16,45.64117,4.520403,5000,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid` IN (90,93,94,95,101);
DELETE FROM `waypoint_data` WHERE `id` IN (900,930,940,950,1010);
DELETE FROM `game_event_creature` WHERE `guid` = 134677;

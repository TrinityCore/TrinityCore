-- Og
-- 
SET @CGUID := 25;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 44865, 1, 1, 1643.72, -4443.32, 18.61603, 1.570796, 120, 0, 0), -- Auctioneer Fazdran (Area: Valley of Strength)
(@CGUID+1, 44867, 1, 1, 1640.17, -4445.12, 18.61683, 2.251475, 120, 0, 0), -- Auctioneer Ralinza (Area: Valley of Strength)
(@CGUID+2, 44866, 1, 1, 1637.42, -4448.21, 18.61663, 2.408554, 120, 0, 0), -- Auctioneer Drezmit (Area: Valley of Strength)
(@CGUID+3, 44868, 1, 1, 1635.46, -4451.19, 18.61623, 3.176499, 120, 0, 0); -- Auctioneer Xifa (Area: Valley of Strength)

-- Auctioneer Fazdran SAI
SET @ENTRY := 44865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Fazdran - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Ralinza SAI
SET @ENTRY := 44867;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Ralinza - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Drezmit SAI
SET @ENTRY := 44866;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Drezmit - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Xifa SAI
SET @ENTRY := 44868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Xifa - Out of Combat - Play Random Emote (273, 5)");

-- grundtalk
DELETE FROM `creature_addon` WHERE `guid` IN (310823, 310821,287204,287201);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(310823,0,0,0,1,1, ''),
(310821,0,0,0,1,1, ''),
(287204,0,0,0,1,1, ''),
(287201,0,0,0,1,1, '');

-- Doyo'da SAI
SET @ENTRY := 5613;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,1,11,0,0,0,0,0,0,0,0,0,0,0,0,"Doyo'da - Out of Combat - Play Random Emote (1, 11)");
-- The Drag
SET @CGUID := 81;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
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

SET @NPC := 94;
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

SET @NPC := 93;
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

SET @NPC := 90;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1811.28,`position_y`=-4565.53,`position_z`=23.00011 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1811.28,-4565.53,23.00011,0,5000,0,0,100,0),
(@PATH,2,1807.04,-4563.03,23.00011,0,5000,0,0,100,0);

SET @NPC := 95;
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

DELETE FROM `creature` WHERE `guid` In (310904, 311039);
SET @NPC := 286716;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1923.415,`position_y`=-4436.305,`position_z`=25.1589 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1923.415,-4436.305,25.1589,0,0,0,0,100,0),
(@PATH,2,1920.915,-4439.805,27.6589,0,0,0,0,100,0),
(@PATH,3,1917.915,-4441.055,29.9089,0,0,0,0,100,0),
(@PATH,4,1914.915,-4439.805,31.6589,0,0,0,0,100,0),
(@PATH,5,1912.165,-4437.305,33.1589,0,0,0,0,100,0),
(@PATH,6,1912.665,-4434.305,35.1589,0,0,0,0,100,0),
(@PATH,7,1914.165,-4430.805,37.1589,0,0,0,0,100,0),
(@PATH,8,1916.915,-4430.055,39.1589,0,0,0,0,100,0),
(@PATH,9,1920.415,-4430.555,41.6589,0,0,0,0,100,0),
(@PATH,10,1922.165,-4433.305,43.6589,0,0,0,0,100,0),
(@PATH,11,1922.665,-4437.055,45.4089,0,0,0,0,100,0),
(@PATH,12,1920.165,-4439.555,45.4089,0,0,0,0,100,0),
(@PATH,13,1922.665,-4441.555,45.4089,0,0,0,0,100,0),
(@PATH,14,1930.14,-4441.545,45.25065,0,0,0,0,100,0),
(@PATH,15,1930.64,-4434.795,45.25065,0,0,0,0,100,0),
(@PATH,16,1929.39,-4428.295,45.75065,0,0,0,0,100,0),
(@PATH,17,1929.385,-4428.68,45.66025,0,0,0,0,100,0),
(@PATH,18,1930.385,-4441.18,45.41025,0,0,0,0,100,0),
(@PATH,19,1926.385,-4444.43,45.41025,0,0,0,0,100,0),
(@PATH,20,1921.635,-4439.18,45.41025,0,0,0,0,100,0),
(@PATH,21,1922.635,-4436.43,45.16025,0,0,0,0,100,0),
(@PATH,22,1922.135,-4433.43,43.91025,0,0,0,0,100,0),
(@PATH,23,1920.385,-4430.43,41.91025,0,0,0,0,100,0),
(@PATH,24,1917.135,-4429.93,39.41025,0,0,0,0,100,0),
(@PATH,25,1913.635,-4430.68,36.91025,0,0,0,0,100,0),
(@PATH,26,1912.135,-4434.18,35.41025,0,0,0,0,100,0),
(@PATH,27,1912.385,-4436.93,33.16025,0,0,0,0,100,0),
(@PATH,28,1914.885,-4439.43,31.66025,0,0,0,0,100,0),
(@PATH,29,1917.885,-4440.93,29.91025,0,0,0,0,100,0),
(@PATH,30,1921.135,-4439.93,27.66025,0,0,0,0,100,0),
(@PATH,31,1923.385,-4436.93,25.16025,0,0,0,0,100,0),
(@PATH,32,1925.135,-4432.18,25.41025,0,0,0,0,100,0),
(@PATH,33,1928.385,-4430.18,25.16025,0,0,0,0,100,0),
(@PATH,34,1932.135,-4426.18,24.16025,0,0,0,0,100,0),
(@PATH,35,1936.635,-4419.68,23.91025,0,0,0,0,100,0),
(@PATH,36,1940.635,-4409.68,23.91025,0,0,0,0,100,0),
(@PATH,37,1940.385,-4401.93,23.91025,0,0,0,0,100,0),
(@PATH,38,1940.635,-4397.18,23.91025,0,0,0,0,100,0),
(@PATH,39,1946.385,-4392.68,24.41025,0,0,0,0,100,0),
(@PATH,40,1956.635,-4385.68,27.91025,0,0,0,0,100,0),
(@PATH,41,1923.415,-4436.305,25.1589,0,0,0,0,100,0);

SET @NPC := 286671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1900.79,`position_y`=-4505.65,`position_z`=25.7526 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1900.79,-4505.65,25.7526,2.199115,5000,0,0,100,0),
(@PATH,2,1894.25,-4511.21,25.7111,0,0,0,0,100,0),
(@PATH,3,1891,-4518.46,26.7111,0,0,0,0,100,0),
(@PATH,4,1891,-4526.71,27.4611,0,0,0,0,100,0),
(@PATH,5,1894.25,-4532.71,28.4611,0,0,0,0,100,0),
(@PATH,6,1901.5,-4540.46,29.9611,0,0,0,0,100,0),
(@PATH,7,1910.01,-4538.48,30.68554,0,0,0,0,100,0),
(@PATH,8,1909.944,-4538.645,30.68871,2.199115,5000,0,0,100,0),
(@PATH,9,1904.622,-4538.928,30.22595,0,0,0,0,100,0),
(@PATH,10,1898.622,-4531.678,28.72595,0,0,0,0,100,0),
(@PATH,11,1896.872,-4522.178,27.47595,0,0,0,0,100,0),
(@PATH,12,1896.872,-4511.428,25.97595,0,0,0,0,100,0),
(@PATH,13,1900.8,-4505.71,25.7632,2.199115,5000,0,0,100,0),
(@PATH,14,1915.134,-4553.913,36.10616,0,0,0,0,100,0),
(@PATH,15,1915.634,-4555.413,36.10616,0,0,0,0,100,0),
(@PATH,16,1916.384,-4556.913,36.10616,0,0,0,0,100,0),
(@PATH,17,1889.71,-4497.935,24.12695,0,0,0,0,100,0),
(@PATH,18,1878.71,-4496.935,23.37695,0,0,0,0,100,0),
(@PATH,19,1870.21,-4505.935,23.87695,0,0,0,0,100,0),
(@PATH,20,1855.46,-4513.685,24.37695,0,0,0,0,100,0),
(@PATH,21,1854.12,-4527.16,24.4907,2.024582,5000,0,0,100,0),
(@PATH,22,1861.375,-4526.065,25.05885,0,0,0,0,100,0),
(@PATH,23,1871.375,-4533.815,26.80885,0,0,0,0,100,0),
(@PATH,24,1877.125,-4537.315,27.55885,0,0,0,0,100,0),
(@PATH,25,1884.375,-4542.315,28.80885,0,0,0,0,100,0),
(@PATH,26,1890.13,-4551.97,30.627,2.199115,5000,0,0,100,0),
(@PATH,27,1883.45,-4535.495,27.7967,0,0,0,0,100,0),
(@PATH,28,1876.2,-4530.995,26.7967,0,0,0,0,100,0),
(@PATH,29,1866.45,-4522.995,25.0467,0,0,0,0,100,0),
(@PATH,30,1859.2,-4522.495,24.7967,0,0,0,0,100,0),
(@PATH,31,1853.77,-4527.02,24.4664,2.024582,5000,0,0,100,0),
(@PATH,32,1860.53,-4522.335,24.8595,0,0,0,0,100,0),
(@PATH,33,1866.78,-4516.835,24.3595,0,0,0,0,100,0),
(@PATH,34,1874.28,-4509.585,23.8595,0,0,0,0,100,0),
(@PATH,35,1884.53,-4504.585,24.1095,0,0,0,0,100,0);

UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (42548, 4953); 

-- Thund SAI
SET @ENTRY := 2857;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thund - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 285700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.565630,"On Script - Set Orientation 2,565630"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 233"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.818128,"On Script - Set Orientation 5,818128"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Roxxik SAI
SET @ENTRY := 11017;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,274,273,396,6,0,0,1,0,0,0,0,0,0,0,"Roxxik - Out of Combat - Play Random Emote (274, 273, 396, 6)");

-- Rilli Greasygob SAI
SET @ENTRY := 9317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,274,273,396,6,0,0,1,0,0,0,0,0,0,0,"Rilli Greasygob - Out of Combat - Play Random Emote (274, 273, 396, 6)");

-- Sovik SAI
SET @ENTRY := 3413;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,274,273,396,6,0,0,1,0,0,0,0,0,0,0,"Sovik - Out of Combat - Play Random Emote (274, 273, 396, 6)");

-- Karolek SAI
SET @ENTRY := 3365;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,5000,8000,10,273,396,6,0,0,0,1,0,0,0,0,0,0,0,"Karolek - Out of Combat - Play Random Emote (273, 396, 6)");

-- Kamari SAI
SET @ENTRY := 5811;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,5000,8000,10,273,396,6,0,0,0,1,0,0,0,0,0,0,0,"Kamari - Out of Combat - Play Random Emote (273, 396, 6)");

SET @NPC := 101;
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

-- Arugi SAI
SET @ENTRY := 46709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arugi - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 4670900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 28"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

SET @NPC := 286788;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1753.8,`position_y`=-4493.53,`position_z`=43.9572 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1753.8,-4493.53,43.9572,3.403392,0,0,0,100,0),
(@PATH,2,1758.535,-4486.705,44.69615,0,0,0,0,100,0),
(@PATH,3,1755.535,-4480.205,43.19615,0,0,0,0,100,0),
(@PATH,4,1752.035,-4476.455,40.44615,0,0,0,0,100,0),
(@PATH,5,1747.035,-4472.455,37.44615,0,0,0,0,100,0),
(@PATH,6,1741.785,-4469.455,35.69615,0,0,0,0,100,0),
(@PATH,7,1729.285,-4472.455,35.44615,0,0,0,0,100,0),
(@PATH,8,1726.785,-4480.955,33.94615,0,0,0,0,100,0),
(@PATH,9,1728.285,-4487.955,32.69615,0,0,0,0,100,0),
(@PATH,10,1733.535,-4496.955,31.44615,0,0,0,0,100,0),
(@PATH,11,1737.285,-4501.705,30.94615,0,0,0,0,100,0),
(@PATH,12,1742.035,-4507.205,30.19615,0,0,0,0,100,0),
(@PATH,13,1747.285,-4511.955,29.44615,0,0,0,0,100,0),
(@PATH,14,1755.035,-4518.955,27.94615,0,0,0,0,100,0),
(@PATH,15,1764.285,-4526.705,26.19615,0,0,0,0,100,0),
(@PATH,16,1775.535,-4533.455,24.94615,0,0,0,0,100,0),
(@PATH,17,1793.035,-4534.455,23.69615,0,0,0,0,100,0),
(@PATH,18,1808.535,-4531.705,23.44615,0,0,0,0,100,0),
(@PATH,19,1815.285,-4529.705,23.69615,0,0,0,0,100,0),
(@PATH,20,1829.035,-4529.205,24.19615,0,0,0,0,100,0),
(@PATH,21,1833.535,-4523.455,24.19615,0,0,0,0,100,0),
(@PATH,22,1819.785,-4523.205,23.69615,0,0,0,0,100,0),
(@PATH,23,1809.285,-4523.705,23.44615,0,0,0,0,100,0),
(@PATH,24,1797.785,-4527.455,23.69615,0,0,0,0,100,0),
(@PATH,25,1789.535,-4529.205,23.94615,0,0,0,0,100,0),
(@PATH,26,1775.785,-4529.955,24.94615,0,0,0,0,100,0),
(@PATH,27,1766.035,-4521.955,26.44615,0,0,0,0,100,0),
(@PATH,28,1759.285,-4514.205,27.69615,0,0,0,0,100,0),
(@PATH,29,1753.035,-4509.205,28.94615,0,0,0,0,100,0),
(@PATH,30,1749.035,-4505.205,30.19615,0,0,0,0,100,0),
(@PATH,31,1744.285,-4500.205,30.69615,0,0,0,0,100,0),
(@PATH,32,1738.035,-4493.455,31.69615,0,0,0,0,100,0),
(@PATH,33,1734.285,-4486.955,32.69615,0,0,0,0,100,0),
(@PATH,34,1733.035,-4478.705,34.19615,0,0,0,0,100,0),
(@PATH,35,1733.535,-4472.705,35.44615,0,0,0,0,100,0),
(@PATH,36,1737.035,-4471.455,35.44615,0,0,0,0,100,0),
(@PATH,37,1743.285,-4476.955,37.44615,0,0,0,0,100,0),
(@PATH,38,1747.285,-4480.205,40.19615,0,0,0,0,100,0),
(@PATH,39,1750.785,-4483.455,42.19615,0,0,0,0,100,0),
(@PATH,40,1755.035,-4487.455,44.19615,0,0,0,0,100,0);
-- Orgrimmar - Valley of Honor
SET @CGUID := 685;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+116;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31146, 1, 1, 2118.74, -4623.69, 49.32983, 2.565634, 120, 0, 0), -- Raider's Training Dummy (Area: -Unknown-) (Auras: 61573 - Banner of the Alliance)
(@CGUID+1, 3352, 1, 1, 2106.94, -4616.56, 49.33633, 1.884956, 120, 0, 0), -- Ormak Grimshot (Area: -Unknown-)
(@CGUID+2, 47815, 1, 1, 2104.46, -4618.06, 49.33623, 2.286381, 120, 0, 0), -- Grimfang (Area: -Unknown-)
(@CGUID+3, 47818, 1, 1, 2110.97, -4610.88, 49.33633, 4.08407, 120, 0, 0), -- Tusker (Area: -Unknown-)
(@CGUID+4, 46647, 1, 1, 2126.25, -4599.05, 49.33633, 3.874631, 120, 0, 0), -- Training Dummy (Area: -Unknown-) (Auras: 61573 - Banner of the Alliance)
(@CGUID+5, 47767, 1, 1, 2107.56, -4611.76, 49.33633, 3.979351, 120, 0, 0), -- Korla (Area: -Unknown-)
(@CGUID+6, 31755, 1, 1, 2073.01, -4618.06, 49.28975, 2.268928, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+7, 46647, 1, 1, 2081.63, -4607.98, 49.33633, 5.951573, 120, 0, 0), -- Training Dummy (Area: Valley of Honor) (Auras: 61573 - Banner of the Alliance)
(@CGUID+8, 46639, 1, 1, 2066.51, -4659.04, 34.10603, 2.80998, 120, 0, 0), -- Auctioneer Zilbeena (Area: Valley of Honor)
(@CGUID+9, 46640, 1, 1, 2068.53, -4666.77, 34.10643, 3.368485, 120, 0, 0), -- Auctioneer Kuvi (Area: Valley of Honor)
(@CGUID+10, 3296, 1, 1, 2126.052, -4738.245, 50.66297, 2.740167, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+11, 31146, 1, 1, 2098.6, -4627.86, 49.33633, 0.7853982, 120, 0, 0), -- Raider's Training Dummy (Area: Valley of Honor) (Auras: 61573 - Banner of the Alliance)
(@CGUID+12, 3296, 1, 1, 2057.959, -4668.522, 32.54941, 0.3530898, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+13, 47788, 1, 1, 2102.71, -4613.35, 49.33633, 6.195919, 120, 0, 0), -- Guldor (Area: Valley of Honor)
(@CGUID+14, 46647, 1, 1, 2110.68, -4590.13, 49.33633, 4.520403, 120, 0, 0), -- Training Dummy (Area: Valley of Honor) (Auras: 61573 - Banner of the Alliance)
(@CGUID+15, 47817, 1, 1, 2102.99, -4608.63, 49.33633, 0, 120, 0, 0), -- Scuttler (Area: Valley of Honor)
(@CGUID+16, 3296, 1, 1, 2130.936, -4730.043, 50.65128, 2.600541, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+17, 46637, 1, 1, 2067.2, -4662.71, 34.10633, 3.717551, 120, 0, 0), -- Auctioneer Drezbit (Area: Valley of Honor)
(@CGUID+18, 46647, 1, 1, 2093.14, -4593.85, 49.33633, 5.358161, 120, 0, 0), -- Training Dummy (Area: Valley of Honor) (Auras: 61573 - Banner of the Alliance)
(@CGUID+19, 14539, 1, 1, 2108.84, -4579.1, 49.33633, 6.230825, 120, 0, 0), -- Swift Timber Wolf (Area: Valley of Honor)
(@CGUID+20, 46638, 1, 1, 2070.95, -4669.52, 34.10563, 4.433136, 120, 0, 0), -- Auctioneer Vizput (Area: Valley of Honor)
(@CGUID+21, 3296, 1, 1, 2059.41, -4674.11, 32.63963, 2.007129, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+22, 31756, 1, 1, 2066.95, -4604.88, 49.28975, 1.704291, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+23, 3296, 1, 1, 2045.607, -4706.141, 28.56897, 5.310535, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+24, 65058, 1, 1, 2041.068, -4706.365, 28.4637, 5.445554, 120, 0, 0), -- Black Dragon Turtle (Area: Valley of Honor)
(@CGUID+25, 31758, 1, 1, 2066.756, -4611.738, 49.28975, 0.5314288, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+26, 57922, 1, 1, 2088.715, -4764.458, 28.01213, 3.735005, 120, 0, 0), -- Taryssa Lazuria (Area: Valley of Honor)
(@CGUID+27, 74228, 1, 1, 2058.88, -4730.48, 27.774, 4.705526, 120, 0, 0), -- -Unknown- (Area: Valley of Honor) (Auras: )
(@CGUID+28, 3296, 1, 1, 2055.37, -4663.19, 32.63573, 5.009095, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+29, 3358, 1, 1, 2083.222, -4770.205, 28.00946, 1.58825, 120, 0, 0), -- Gorina (Area: Valley of Honor)
(@CGUID+30, 65008, 1, 1, 2024.453, -4698.135, 28.46393, 5.29936, 120, 0, 0), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+31, 50482, 1, 1, 2087.52, -4769.45, 28.01213, 1.012291, 120, 0, 0), -- Marith Lazuria (Area: Valley of Honor)
(@CGUID+32, 3296, 1, 1, 2024.861, -4657.98, 28.5511, 2.120832, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+33, 65060, 1, 1, 2032.906, -4718.252, 28.33491, 4.387585, 120, 0, 0), -- Blue Dragon Turtle (Area: Valley of Honor)
(@CGUID+34, 65008, 1, 1, 2026.585, -4701.569, 28.44965, 2.062142, 120, 0, 0), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+35, 5029, 1, 1, 2030.547, -4722.234, 56.79307, 4.456704, 120, 0, 0), -- Jiming (Area: Valley of Honor) (Auras: )
(@CGUID+36, 49837, 1, 1, 2032.245, -4656.735, 28.7079, 2.781837, 120, 0, 0), -- Spiny Lizard (Area: Valley of Honor)
(@CGUID+37, 3357, 1, 1, 2081.978, -4764.085, 28.00872, 3.438299, 120, 0, 0), -- Makaru (Area: Valley of Honor)
(@CGUID+38, 46675, 1, 1, 2088.8, -4767.27, 28.01213, 4.153883, 120, 0, 0), -- Lugrah (Area: Valley of Honor)
(@CGUID+39, 65063, 1, 1, 2034.248, -4699.74, 28.42856, 0, 120, 0, 0), -- Purple Dragon Turtle (Area: Valley of Honor)
(@CGUID+40, 14540, 1, 1, 2100.4, -4569.89, 49.33633, 0.5759587, 120, 0, 0), -- Swift Brown Wolf (Area: Valley of Honor)
(@CGUID+41, 14541, 1, 1, 2102.94, -4571.69, 49.33633, 1.53589, 120, 0, 0), -- Swift Gray Wolf (Area: Valley of Honor)
(@CGUID+42, 3296, 1, 1, 2024.55, -4635.63, 31.76513, 3.385939, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+43, 31757, 1, 1, 2076.46, -4589, 49.33633, 5.654867, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+44, 64105, 1, 1, 2088.593, -4565.708, 49.37801, 2.474993, 120, 0, 0), -- Muffin (Area: Valley of Honor)
(@CGUID+45, 47771, 1, 1, 2081.68, -4588.85, 49.33633, 2.6529, 120, 0, 0), -- Drukma (Area: Valley of Honor)
(@CGUID+46, 356, 1, 1, 2072.99, -4564.18, 49.33633, 1.745329, 120, 0, 0), -- Black Wolf (Area: Valley of Honor)
(@CGUID+47, 4752, 1, 1, 2085.36, -4572.86, 49.33633, 5.393067, 120, 0, 0), -- Kildar (Area: Valley of Honor)
(@CGUID+48, 31768, 1, 1, 2088.397, -4584.163, 65.13868, 3.220361, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+49, 12351, 1, 1, 2075.17, -4562.83, 49.33633, 2.391101, 120, 0, 0), -- Dire Riding Wolf (Area: Valley of Honor)
(@CGUID+50, 47809, 1, 1, 2086.21, -4578.24, 49.33633, 1.745329, 120, 0, 0), -- Brown Wolf (Area: Valley of Honor)
(@CGUID+51, 42548, 1, 1, 2029.454, -4598.487, 30.89835, 4.963881, 120, 0, 0), -- Muddy Crawfish (Area: Valley of Honor)
(@CGUID+52, 49743, 1, 1, 2064.779, -4561.279, 49.37801, 5.097329, 120, 0, 0), -- Dung Beetle (Area: Valley of Honor)
(@CGUID+53, 3296, 1, 1, 2030.06, -4634.3, 32.72443, 2.164208, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+54, 31769, 1, 1, 2059.19, -4597.96, 54.53453, 5.794493, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+55, 47764, 1, 1, 2077.69, -4587.09, 49.33633, 5.88176, 120, 0, 0), -- Murog (Area: Valley of Honor)
(@CGUID+56, 3362, 1, 1, 2088.108, -4568.436, 49.37801, 6.148685, 120, 0, 0), -- Ogunaro Wolfrunner (Area: Valley of Honor)
(@CGUID+57, 47808, 1, 1, 2090.61, -4574.53, 49.33633, 2.844887, 120, 0, 0), -- Black Wolf (Area: Valley of Honor)
(@CGUID+58, 49743, 1, 1, 2208.888, -4620.986, 81.70455, 0.461408, 120, 0, 0), -- Dung Beetle (Area: Valley of Honor)
(@CGUID+59, 12353, 1, 1, 2070.63, -4578.04, 49.33633, 3.787364, 120, 0, 0), -- Timber Riding Wolf (Area: Valley of Honor)
(@CGUID+60, 31755, 1, 1, 2082.43, -4591.11, 49.33633, 3.298672, 120, 0, 0), -- Stabled Hunter Pet (Area: Valley of Honor)
(@CGUID+61, 3296, 1, 1, 2021.84, -4636.36, 31.76863, 0.2443461, 120, 0, 0), -- Orgrimmar Grunt (Area: Valley of Honor) (Auras: )
(@CGUID+62, 5195, 1, 1, 2071.26, -4580.62, 49.33633, 3.141593, 120, 0, 0), -- Brown Riding Wolf (Area: Valley of Honor)
(@CGUID+63, 51346, 1, 1, 2079.416, -4304.976, 151.3706, 4.778497, 120, 10, 1), -- Orgrimmar Wind Rider (Area: Valley of Honor) (Auras: ) (possible waypoints or random movement)
(@CGUID+64, 51346, 1, 1, 2068, -4306.357, 151.1366, 4.750923, 120, 10, 1), -- Orgrimmar Wind Rider (Area: Valley of Honor) (Auras: ) (possible waypoints or random movement)
(@CGUID+65, 51346, 1, 1, 2087.293, -4304.559, 151.1373, 4.764519, 120, 10, 1), -- Orgrimmar Wind Rider (Area: Valley of Honor) (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 49743, 1, 1, 2281.795, -4625.089, 99.82313, 3.682395, 120, 0, 0), -- Dung Beetle (Area: 0)
(@CGUID+67, 62114, 1, 1, 2312.9, -4724.179, 117.8283, 2.38314, 120, 0, 0), -- Spiny Lizard (Area: 0)
(@CGUID+68, 49743, 1, 1, 2318.733, -4716.366, 117.0158, 3.291296, 120, 0, 0), -- Dung Beetle (Area: 0)
(@CGUID+69, 49743, 1, 1, 2261.286, -4623.78, 92.22597, 3.034986, 120, 0, 0), -- Dung Beetle (Area: 0)
(@CGUID+70, 62114, 1, 1, 2276.586, -4660.981, 102.8914, 0.02538517, 120, 0, 0), -- Spiny Lizard (Area: 0)
(@CGUID+71, 49837, 1, 1, 2313.926, -4647.306, 110.4751, 5.228102, 120, 0, 0), -- Spiny Lizard (Area: 0)
(@CGUID+72, 49837, 1, 1, 2293.419, -4635.905, 104.2426, 1.571773, 120, 0, 0), -- Spiny Lizard (Area: 0)
(@CGUID+73, 3296, 1, 1, 2293.286, -4661.32, 105.5588, 5.522541, 120, 0, 0), -- Orgrimmar Grunt (Area: 0) (Auras: )
(@CGUID+74, 62115, 1, 1, 2310.692, -4701.588, 114.1208, 4.649848, 120, 0, 0), -- Dung Beetle (Area: 0)
(@CGUID+75, 42650, 1, 1, 2321.906, -4738.458, 122.2641, 0.938438, 120, 0, 0), -- Goblin Siegeworker (Area: 0) (Auras: 80126 - Goblin Carrying a Horde Crate)
(@CGUID+76, 42548, 1, 1, 2329.702, -4738.493, 116.8893, 3.171628, 120, 0, 0), -- Muddy Crawfish (Area: 0)
(@CGUID+77, 42650, 1, 1, 2347.325, -4742.363, 121.195, 0.9773844, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+78, 42548, 1, 1, 2360.02, -4771.724, 119.1137, 1.124648, 120, 0, 0), -- Muddy Crawfish (Area: 0)
(@CGUID+79, 42650, 1, 1, 2375.211, -4760.818, 123.3872, 1.910486, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+80, 42650, 1, 1, 2322.724, -4768.457, 123.5431, 3.996804, 120, 0, 0), -- Goblin Siegeworker (Area: 0) (Auras: 80126 - Goblin Carrying a Horde Crate)
(@CGUID+81, 42650, 1, 1, 2345.14, -4796.854, 124.3948, 4.939282, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+82, 42671, 1, 1, 2390.698, -4790.512, 126.4508, 0.3141593, 120, 0, 0), -- Chief Engineer (Area: 0)
(@CGUID+83, 42673, 1, 1, 2392.984, -4796.818, 126.877, 0.9250245, 120, 0, 0), -- Hellscream Demolisher (Area: 0)
(@CGUID+84, 42650, 1, 1, 2375.762, -4787.292, 129.7977, 4.694936, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+85, 42650, 1, 1, 2366.611, -4790.205, 129.7605, 0.2268928, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+86, 42673, 1, 1, 2402.266, -4807.132, 127.0672, 0.3839724, 120, 0, 0), -- Hellscream Demolisher (Area: 0)
(@CGUID+87, 42650, 1, 1, 2387.059, -4820.118, 134.1067, 5.916666, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+88, 42650, 1, 1, 2384.826, -4813.146, 129.956, 2.600541, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+89, 42671, 1, 1, 2407.099, -4808.962, 126.9619, 1.064651, 120, 0, 0), -- Chief Engineer (Area: 0)
(@CGUID+90, 42650, 1, 1, 2399.405, -4814.858, 127.5179, 4.014257, 120, 0, 0), -- Goblin Siegeworker (Area: 0) (Auras: 80126 - Goblin Carrying a Horde Crate)
(@CGUID+91, 42650, 1, 1, 2422.088, -4806.223, 127.3449, 2.851961, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+92, 42650, 1, 1, 2398.076, -4818.552, 132.5486, 3.787364, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+93, 49837, 1, 1, 2427.167, -4788.862, 128.8044, 0.1792479, 120, 0, 0), -- Spiny Lizard (Area: 0)
(@CGUID+94, 42650, 1, 1, 2430.163, -4828.295, 142.047, 4.694936, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+95, 42650, 1, 1, 2404.344, -4846.243, 136.9398, 5.113815, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+96, 42650, 1, 1, 2393.2, -4828.768, 127.8356, 2.844887, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+97, 42650, 1, 1, 2438.661, -4858.741, 138.4747, 5.131268, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+98, 42650, 1, 1, 2440.625, -4867.327, 150.8198, 2.216568, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+99, 42672, 1, 1, 2482.097, -4815.262, 143.0676, 5.393067, 120, 0, 0), -- Foreman Glibbs (Area: 0)
(@CGUID+100, 42673, 1, 1, 2446.889, -4832.603, 131.6044, 1.012291, 120, 0, 0), -- Hellscream Demolisher (Area: 0)
(@CGUID+101, 42671, 1, 1, 2452.552, -4830.993, 132.6834, 1.064651, 120, 0, 0), -- Chief Engineer (Area: 0)
(@CGUID+102, 42650, 1, 1, 2458.705, -4856.469, 138.3684, 3.374021, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+103, 42650, 1, 1, 2452.25, -4853.809, 137.7998, 3.071779, 120, 0, 0), -- Goblin Siegeworker (Area: 0) (Auras: 80126 - Goblin Carrying a Horde Crate)
(@CGUID+104, 3296, 1, 1, 2450.965, -4825.7, 132.9035, 5.861367, 120, 0, 0), -- Orgrimmar Grunt (Area: 0) (Auras: )
(@CGUID+105, 42650, 1, 1, 2434.986, -4841.952, 132.6866, 2.792527, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+106, 42650, 1, 1, 2488.392, -4827.316, 142.4043, 1.614059, 120, 0, 0), -- Goblin Siegeworker (Area: 0) (Auras: 80126 - Goblin Carrying a Horde Crate)
(@CGUID+107, 42650, 1, 1, 2472.807, -4868.455, 141.0457, 3.543018, 120, 0, 0), -- Goblin Siegeworker (Area: 0)
(@CGUID+108, 3296, 1, 1, 2510.97, -4856.11, 148.5153, 1.361357, 120, 0, 0), -- Orgrimmar Grunt (Area: 0) (Auras: )
(@CGUID+109, 74228, 1, 1, 2513.97, -4836.57, 148.5153, 4.537856, 120, 0, 0), -- -Unknown- (Area: 0) (Auras: )
(@CGUID+110, 35162, 1, 1, 2482.71, -5031.668, 142.9066, 3.595378, 120, 0, 0), -- Azshara Sapling (Area: Orgrimmar Rear Gate) (Auras: )
(@CGUID+111, 3296, 1, 1, 2561.502, -4849.932, 144.9335, 5.131268, 120, 0, 0), -- Orgrimmar Grunt (Area: Orgrimmar Rear Gate) (Auras: )
(@CGUID+112, 3296, 1, 1, 2549.267, -4868.382, 145.5338, 0.4363323, 120, 0, 0), -- Orgrimmar Grunt (Area: Orgrimmar Rear Gate) (Auras: )
(@CGUID+113, 35162, 1, 1, 2514.72, -5012.401, 133.0677, 5.305801, 120, 0, 0), -- Azshara Sapling (Area: Orgrimmar Rear Gate) (Auras: )
(@CGUID+114, 8576, 1, 1, 2551.691, -4851.772, 145.8126, 5.393067, 120, 0, 0), -- Ag'tor Bloodfist (Area: Orgrimmar Rear Gate)
(@CGUID+115, 35086, 1, 1, 2546.905, -4861.781, 145.8856, 0.6283185, 120, 0, 0), -- Labor Captain Grabbit (Area: Orgrimmar Rear Gate)
(@CGUID+116, 35162, 1, 1, 2639.04, -4721.168, 142.183, 3.176499, 120, 0, 0); -- Azshara Sapling (Area: Orgrimmar Rear Gate)

-- correction:
DELETE FROM `creature` WHERE `guid` IN (286470,358717,358716,720,708,695,286467, 697,286484,706,705,286482,702,693,727,746,738,711,286501,722,286503,286502);

UPDATE `creature` SET `spawndist`=4, `MovementType`=1 WHERE  `guid`=286606;
-- Vink SAI
SET @ENTRY := 46620;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,5000,8000,10,3,273,0,0,0,0,1,0,0,0,0,0,0,0,"Vink - Out of Combat - Play Random Emote (3, 273)");

-- Binzella SAI
SET @ENTRY := 46619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,5000,8000,10,3,273,0,0,0,0,1,0,0,0,0,0,0,0,"Binzella - Out of Combat - Play Random Emote (3, 273)");

-- Blademaster Ronakada SAI
SET @ENTRY := 46667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,5000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blademaster Ronakada - Out of Combat - Play Emote 1");

-- Taryssa Lazuria SAI
SET @ENTRY := 57922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,274,273,1,0,0,0,0,0,0,0,0,0,0,0,"Taryssa Lazuria - Out of Combat - Play Random Emote (274, 273, 1)");

-- Marith Lazuria SAI
SET @ENTRY := 50482;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,274,273,1,0,0,0,0,0,0,0,0,0,0,0,"Marith Lazuria - Out of Combat - Play Random Emote (274, 273, 1)");

-- Guldor SAI
SET @ENTRY := 47788;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,274,273,1,0,0,0,0,0,0,0,0,0,0,0,"Guldor - Out of Combat - Play Random Emote (274, 273, 1)");

-- Ormak Grimshot SAI
SET @ENTRY := 3352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,274,273,1,0,0,0,0,0,0,0,0,0,0,0,"Ormak Grimshot - Out of Combat - Play Random Emote (274, 273, 1)");

-- Korla SAI
SET @ENTRY := 47767;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,274,273,1,0,0,0,0,0,0,0,0,0,0,0,"Korla - Out of Combat - Play Random Emote (274, 273, 1)");

-- hammer
DELETE FROM `creature_addon` WHERE `guid` IN (286506,286508,286494, 286499,286505);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(286494,0,0,0,1,233, ''),
(286499,0,0,0,1,233, ''),
(286505,0,0,0,1,233, ''),
(286508,0,0,0,1,233, ''),
(286506,0,0,0,1,233, '');

-- kneeling grunts
DELETE FROM `creature_addon` WHERE `guid` IN (286476,286479,286478,286559,286562,286537,286572,286570,286568,286573,286575,286576,286543,286546,286542,286534,286528,286536,286539);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(286572,0,0,8,1,0, ''),
(286570,0,0,8,1,0, ''),
(286568,0,0,8,1,0, ''),
(286573,0,0,8,1,0, ''),
(286575,0,0,8,1,0, ''),
(286576,0,0,8,1,0, ''),
-- 
(286543,0,0,0,1,1, ''),
(286546,0,0,0,1,1, ''),
(286542,0,0,0,1,1, ''),
(286534,0,0,0,1,0, '78677'),
(286528,0,0,0,1,0, '78677'),
(286536,0,0,0,1,1, ''),
(286539,0,0,0,1,1, ''),
(286562,0,0,0,1,1, ''),
(286559,0,0,0,1,1, ''),
(286478,0,0,0,1,1, ''),
(286479,0,0,0,1,1, ''),
(286476,0,0,0,1,0, '78677'),
(286537,0,0,0,1,0, '78677');

-- Karg Skullgore SAI
SET @ENTRY := 34955;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,273,6,274,0,0,0,1,0,0,0,0,0,0,0,"Karg Skullgore - Out of Combat - Play Random Emote (273, 6, 274)");

-- Karba Blazemaw SAI
SET @ENTRY := 49573;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,273,6,274,0,0,0,1,0,0,0,0,0,0,0,"Karba Blazemaw - Out of Combat - Play Random Emote (273, 6, 274)");

-- Murog SAI
SET @ENTRY := 47764;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,273,6,0,0,0,0,1,0,0,0,0,0,0,0,"Murog - Out of Combat - Play Random Emote (273, 6)");

-- Drukma SAI
SET @ENTRY := 47771;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,273,6,0,0,0,0,1,0,0,0,0,0,0,0,"Drukma - Out of Combat - Play Random Emote (273, 6)");

-- Kildar SAI
SET @ENTRY := 4752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,15,274,0,0,0,0,1,0,0,0,0,0,0,0,"Kildar - Out of Combat - Play Random Emote (15, 274)");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=31768;
UPDATE `creature` SET `spawndist`=4, `MovementType`=1 WHERE  `guid`=741;

SET @NPC := 780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2345.849,`position_y`=-4788.236,`position_z`=123.6137 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2345.849,-4788.236,123.6137,0,0,0,0,100,0),
(@PATH,2,2345.782,-4788.322,123.8437,0,0,0,0,100,0),
(@PATH,3,2345.742,-4792.829,124.0043,0,0,0,0,100,0),
(@PATH,4,2346.992,-4793.579,124.0043,0,0,0,0,100,0),
(@PATH,5,2346.492,-4796.329,124.7543,0,0,0,0,100,0),
(@PATH,6,2345.14,-4796.854,124.3948,4.939282,5000,0,0,100,0),
(@PATH,7,2346.127,-4793.836,123.9689,0,0,0,0,100,0),
(@PATH,8,2346.127,-4789.586,123.9689,0,0,0,0,100,0),
(@PATH,9,2344.127,-4785.586,123.9689,0,0,0,0,100,0),
(@PATH,10,2345.849,-4788.236,123.6137,0,0,0,0,100,0),
(@PATH,11,2345.785,-4788.327,123.8437,0,0,0,0,100,0),
(@PATH,12,2345.742,-4792.84,124.0043,0,0,0,0,100,0),
(@PATH,13,2346.992,-4793.59,124.0043,0,0,0,0,100,0),
(@PATH,14,2346.492,-4796.34,124.7543,0,0,0,0,100,0),
(@PATH,15,2345.14,-4796.854,124.3948,4.939282,5000,0,0,100,0),
(@PATH,16,2346.127,-4793.836,123.9689,0,0,0,0,100,0),
(@PATH,17,2346.127,-4789.586,123.9689,0,0,0,0,100,0),
(@PATH,18,2344.127,-4785.586,123.9689,0,0,0,0,100,0),
(@PATH,19,2345.849,-4788.236,123.6137,0,0,0,0,100,0),
(@PATH,20,2345.785,-4788.326,123.8437,0,0,0,0,100,0),
(@PATH,21,2345.742,-4792.839,124.0043,0,0,0,0,100,0),
(@PATH,22,2346.992,-4793.589,124.0043,0,0,0,0,100,0),
(@PATH,23,2346.492,-4796.339,124.7543,0,0,0,0,100,0),
(@PATH,24,2345.14,-4796.854,124.3948,4.939282,5000,0,0,100,0),
(@PATH,25,2346.127,-4793.836,123.9689,0,0,0,0,100,0),
(@PATH,26,2346.127,-4789.586,123.9689,0,0,0,0,100,0),
(@PATH,27,2344.127,-4785.586,123.9689,0,0,0,0,100,0),
(@PATH,28,2345.849,-4788.236,123.6137,0,0,0,0,100,0);

SET @NPC := 767;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2373.553,`position_y`=-4802.581,`position_z`=127.9173 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2373.553,-4802.581,127.9173,0,0,0,0,100,0),
(@PATH,2,2377.053,-4801.331,127.9173,0,0,0,0,100,0),
(@PATH,3,2382.303,-4798.831,127.6673,0,0,0,0,100,0),
(@PATH,4,2384.053,-4794.581,127.6673,0,0,0,0,100,0),
(@PATH,5,2387.303,-4791.831,127.1673,0,0,0,0,100,0),
(@PATH,6,2388.303,-4787.331,126.1673,0,0,0,0,100,0),
(@PATH,7,2385.303,-4780.831,125.1673,0,0,0,0,100,0),
(@PATH,8,2378.303,-4770.581,124.6673,0,0,0,0,100,0),
(@PATH,9,2376.303,-4763.831,124.1673,0,0,0,0,100,0),
(@PATH,10,2371.803,-4751.081,122.9173,0,0,0,0,100,0),
(@PATH,11,2370.053,-4744.081,122.1673,0,0,0,0,100,0),
(@PATH,12,2365.303,-4738.331,121.6673,0,0,0,0,100,0),
(@PATH,13,2362.946,-4732.276,120.9367,0,0,0,0,100,0),
(@PATH,14,2365.083,-4733.847,120.7839,0.7679449,5000,0,0,100,0),
(@PATH,15,2365.44,-4741.152,121.7646,0,0,0,0,100,0),
(@PATH,16,2367.44,-4749.402,122.7646,0,0,0,0,100,0),
(@PATH,17,2371.19,-4757.152,123.5146,0,0,0,0,100,0),
(@PATH,18,2377.69,-4765.902,124.2646,0,0,0,0,100,0),
(@PATH,19,2383.94,-4776.152,124.7646,0,0,0,0,100,0),
(@PATH,20,2387.44,-4784.402,125.7646,0,0,0,0,100,0),
(@PATH,21,2388.44,-4789.652,126.5146,0,0,0,0,100,0),
(@PATH,22,2384.94,-4797.152,127.5146,0,0,0,0,100,0),
(@PATH,23,2381.69,-4799.652,127.7646,0,0,0,0,100,0),
(@PATH,24,2377.19,-4800.402,127.7646,0,0,0,0,100,0),
(@PATH,25,2373.94,-4802.652,128.0146,0,0,0,0,100,0),
(@PATH,26,2373.553,-4802.581,127.9173,0,0,0,0,100,0);

SET @NPC := 791;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2490.851,`position_y`=-4816.962,`position_z`=142.9825 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2490.851,-4816.962,142.9825,1.047198,0,0,0,100,0),
(@PATH,2,2490.851,-4816.962,142.9825,4.223697,5000,0,0,100,0),
(@PATH,3,2490.052,-4818.995,143.2241,0,0,0,0,100,0),
(@PATH,4,2488.552,-4821.995,142.9741,0,0,0,0,100,0),
(@PATH,5,2489.052,-4825.745,142.9741,0,0,0,0,100,0),
(@PATH,6,2488.302,-4829.745,142.2241,0,0,0,0,100,0),
(@PATH,7,2484.552,-4836.495,140.9741,0,0,0,0,100,0),
(@PATH,8,2482.052,-4844.245,140.7241,0,0,0,0,100,0),
(@PATH,9,2478.302,-4847.995,140.2241,0,0,0,0,100,0),
(@PATH,10,2475.052,-4853.995,140.4741,0,0,0,0,100,0),
(@PATH,11,2467.552,-4856.495,139.7241,0,0,0,0,100,0),
(@PATH,12,2464.552,-4860.245,139.4741,0,0,0,0,100,0),
(@PATH,13,2464.253,-4864.528,138.9658,5.742133,5000,0,0,100,0),
(@PATH,14,2463.802,-4863.745,139.2241,0,0,0,0,100,0),
(@PATH,15,2464.552,-4860.745,139.4741,0,0,0,0,100,0),
(@PATH,16,2467.802,-4858.245,139.7241,0,0,0,0,100,0),
(@PATH,17,2475.552,-4854.745,140.4741,0,0,0,0,100,0),
(@PATH,18,2482.052,-4848.245,140.9741,0,0,0,0,100,0),
(@PATH,19,2485.302,-4837.245,140.9741,0,0,0,0,100,0),
(@PATH,20,2488.552,-4828.995,142.4741,0,0,0,0,100,0),
(@PATH,21,2488.302,-4822.995,142.9741,0,0,0,0,100,0),
(@PATH,22,2490.851,-4816.962,142.9825,1.047198,0,0,0,100,0),
(@PATH,23,2490.851,-4816.962,142.9825,4.223697,0,0,0,100,0);

SET @NPC := 766;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2328.901,`position_y`=-4774.885,`position_z`=123.5431 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2328.901,-4774.885,123.5431,3.420845,0,0,0,100,0),
(@PATH,2,2328.901,-4774.885,123.5431,0.7504916,5000,0,0,100,0),
(@PATH,3,2330.783,-4771.301,123.7794,0,0,0,0,100,0),
(@PATH,4,2330.033,-4764.301,123.7794,0,0,0,0,100,0),
(@PATH,5,2328.783,-4756.551,123.7794,0,0,0,0,100,0),
(@PATH,6,2326.033,-4750.301,123.7794,0,0,0,0,100,0),
(@PATH,7,2324.283,-4746.801,123.7794,0,0,0,0,100,0),
(@PATH,8,2320.783,-4744.051,123.7794,0,0,0,0,100,0),
(@PATH,9,2320.783,-4740.301,123.0294,0,0,0,0,100,0),
(@PATH,10,2325.283,-4734.301,121.5294,0,0,0,0,100,0),
(@PATH,11,2329.533,-4729.551,119.2794,0,0,0,0,100,0),
(@PATH,12,2337.033,-4728.301,119.2794,0,0,0,0,100,0),
(@PATH,13,2345.783,-4729.801,120.2794,0,0,0,0,100,0),
(@PATH,14,2354.783,-4727.051,120.7794,0,0,0,0,100,0),
(@PATH,15,2354.283,-4726.801,120.7794,0,0,0,0,100,0),
(@PATH,16,2343.783,-4728.051,119.7794,0,0,0,0,100,0),
(@PATH,17,2333.783,-4726.301,118.7794,0,0,0,0,100,0),
(@PATH,18,2328.533,-4730.551,119.0294,0,0,0,0,100,0),
(@PATH,19,2324.033,-4737.801,121.5294,0,0,0,0,100,0),
(@PATH,20,2323.033,-4746.801,123.7794,0,0,0,0,100,0),
(@PATH,21,2326.033,-4755.051,123.7794,0,0,0,0,100,0),
(@PATH,22,2329.783,-4764.051,123.7794,0,0,0,0,100,0),
(@PATH,23,2330.283,-4770.801,123.7794,0,0,0,0,100,0),
(@PATH,24,2328.901,-4774.885,123.5431,3.420845,0,0,0,100,0);

SET @NPC := 764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2427.715,`position_y`=-4825.382,`position_z`=130.8018 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2427.715,-4825.382,130.8018,1.204277,5000,0,0,100,0),
(@PATH,2,2429.473,-4822.097,130.7333,0,0,0,0,100,0),
(@PATH,3,2431.723,-4818.597,129.9833,0,0,0,0,100,0),
(@PATH,4,2430.223,-4814.347,129.2333,0,0,0,0,100,0),
(@PATH,5,2426.973,-4810.097,128.4833,0,0,0,0,100,0),
(@PATH,6,2422.473,-4806.347,127.7333,0,0,0,0,100,0),
(@PATH,7,2415.973,-4804.347,127.2333,0,0,0,0,100,0),
(@PATH,8,2411.473,-4803.597,126.9833,0,0,0,0,100,0),
(@PATH,9,2408.723,-4801.347,126.9833,0,0,0,0,100,0),
(@PATH,10,2403.473,-4799.847,126.9833,0,0,0,0,100,0),
(@PATH,11,2399.723,-4801.347,127.2333,0,0,0,0,100,0),
(@PATH,12,2394.473,-4805.847,127.7333,0,0,0,0,100,0),
(@PATH,13,2393.473,-4811.597,127.9833,0,0,0,0,100,0),
(@PATH,14,2392.973,-4812.097,127.9833,0,0,0,0,100,0),
(@PATH,15,2393.473,-4808.347,127.7333,0,0,0,0,100,0),
(@PATH,16,2397.473,-4802.597,127.2333,0,0,0,0,100,0),
(@PATH,17,2402.473,-4800.097,126.9833,0,0,0,0,100,0),
(@PATH,18,2406.973,-4800.597,126.9833,0,0,0,0,100,0),
(@PATH,19,2415.723,-4805.847,127.2333,0,0,0,0,100,0),
(@PATH,20,2421.723,-4807.597,127.7333,0,0,0,0,100,0),
(@PATH,21,2428.723,-4810.847,128.7333,0,0,0,0,100,0),
(@PATH,22,2429.473,-4817.347,129.4833,0,0,0,0,100,0),
(@PATH,23,2429.223,-4821.347,130.7333,0,0,0,0,100,0),
(@PATH,24,2427.715,-4825.382,130.8018,1.204277,0,0,0,100,0);

SET @NPC := 787;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2447.274,`position_y`=-4856.858,`position_z`=137.7073 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2447.274,-4856.858,137.7073,1.710423,5000,0,0,100,0),
(@PATH,2,2449.482,-4858.549,138.2745,0,0,0,0,100,0),
(@PATH,3,2455.732,-4856.799,138.5245,0,0,0,0,100,0),
(@PATH,4,2461.982,-4856.799,139.0245,0,0,0,0,100,0),
(@PATH,5,2472.482,-4858.549,140.0245,0,0,0,0,100,0),
(@PATH,6,2477.732,-4863.299,141.0245,0,0,0,0,100,0),
(@PATH,7,2480.982,-4867.299,141.5245,0,0,0,0,100,0),
(@PATH,8,2447.274,-4856.858,137.7073,1.710423,5000,0,0,100,0),
(@PATH,9,2449.482,-4858.549,138.2745,0,0,0,0,100,0),
(@PATH,10,2455.732,-4856.799,138.5245,0,0,0,0,100,0),
(@PATH,11,2461.982,-4856.799,139.0245,0,0,0,0,100,0),
(@PATH,12,2472.482,-4858.549,140.0245,0,0,0,0,100,0),
(@PATH,13,2477.732,-4863.299,141.0245,0,0,0,0,100,0),
(@PATH,14,2480.982,-4867.299,141.5245,0,0,0,0,100,0),
(@PATH,15,2483.232,-4869.799,142.0245,0,0,0,0,100,0),
(@PATH,16,2480.982,-4866.799,141.5245,0,0,0,0,100,0),
(@PATH,17,2477.982,-4863.299,141.0245,0,0,0,0,100,0),
(@PATH,18,2474.232,-4860.799,140.2745,0,0,0,0,100,0),
(@PATH,19,2469.482,-4857.049,139.7745,0,0,0,0,100,0),
(@PATH,20,2461.732,-4855.799,139.0245,0,0,0,0,100,0),
(@PATH,21,2450.232,-4858.549,138.2745,0,0,0,0,100,0),
(@PATH,22,2447.274,-4856.858,137.7073,1.710423,5000,0,0,100,0);

SET @NPC := 776;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2424.445,`position_y`=-4825.149,`position_z`=130.8846 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2424.445,-4825.149,130.8846,4.380776,5000,0,0,100,0),
(@PATH,2,2424.445,-4825.149,130.8846,1.099557,0,0,0,100,0),
(@PATH,3,2423.513,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,4,2419.763,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,5,2417.013,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,6,2415.082,-4823.842,130.8859,5.358161,5000,0,0,100,0),
(@PATH,7,2414.826,-4823.365,131.3125,0,0,0,0,100,0),
(@PATH,8,2416.326,-4821.615,131.3125,0,0,0,0,100,0),
(@PATH,9,2419.576,-4822.615,131.3125,0,0,0,0,100,0),
(@PATH,10,2422.826,-4824.115,131.3125,0,0,0,0,100,0),
(@PATH,11,2427.326,-4823.865,131.3125,0,0,0,0,100,0),
(@PATH,12,2430.826,-4821.865,130.8125,0,0,0,0,100,0),
(@PATH,13,2436.576,-4820.365,130.8125,0,0,0,0,100,0),
(@PATH,14,2441.826,-4819.615,131.5625,0,0,0,0,100,0),
(@PATH,15,2446.826,-4821.865,132.3125,0,0,0,0,100,0),
(@PATH,16,2458.076,-4828.365,134.3125,0,0,0,0,100,0),
(@PATH,17,2462.326,-4832.865,135.5625,0,0,0,0,100,0),
(@PATH,18,2465.326,-4839.615,137.0625,0,0,0,0,100,0),
(@PATH,19,2464.576,-4846.365,138.5625,0,0,0,0,100,0),
(@PATH,20,2461.326,-4851.865,138.5625,0,0,0,0,100,0),
(@PATH,21,2457.076,-4855.115,138.3125,0,0,0,0,100,0),
(@PATH,22,2452.576,-4857.365,138.0625,0,0,0,0,100,0),
(@PATH,23,2455.097,-4853.229,138.0922,0,0,0,0,100,0),
(@PATH,24,2458.097,-4851.479,138.3422,0,0,0,0,100,0),
(@PATH,25,2462.597,-4847.229,138.3422,0,0,0,0,100,0),
(@PATH,26,2464.597,-4841.979,137.5922,0,0,0,0,100,0),
(@PATH,27,2464.097,-4835.979,136.3422,0,0,0,0,100,0),
(@PATH,28,2459.347,-4828.229,134.5922,0,0,0,0,100,0),
(@PATH,29,2451.097,-4823.479,133.0922,0,0,0,0,100,0),
(@PATH,30,2443.097,-4820.979,131.8422,0,0,0,0,100,0),
(@PATH,31,2435.097,-4820.979,130.8422,0,0,0,0,100,0),
(@PATH,32,2429.097,-4823.229,131.0922,0,0,0,0,100,0),
(@PATH,33,2426.097,-4823.729,131.3422,0,0,0,0,100,0),
(@PATH,34,2424.445,-4825.149,130.8846,4.380776,5000,0,0,100,0),
(@PATH,35,2424.445,-4825.149,130.8846,1.099557,0,0,0,100,0),
(@PATH,36,2423.513,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,37,2419.763,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,38,2417.013,-4822.246,131.1352,0,0,0,0,100,0),
(@PATH,39,2415.082,-4823.842,130.8859,5.358161,5000,0,0,100,0),
(@PATH,40,2414.826,-4823.365,131.3125,0,0,0,0,100,0),
(@PATH,41,2416.326,-4821.615,131.3125,0,0,0,0,100,0),
(@PATH,42,2419.576,-4822.615,131.3125,0,0,0,0,100,0),
(@PATH,43,2422.826,-4824.115,131.3125,0,0,0,0,100,0);

SET @NPC := 775;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2402.055,`position_y`=-4813.739,`position_z`=127.5776 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2402.055,-4813.739,127.5776,0,0,0,0,100,0),
(@PATH,2,2404.305,-4815.739,127.5776,0,0,0,0,100,0),
(@PATH,3,2404.055,-4818.239,127.5776,0,0,0,0,100,0),
(@PATH,4,2401.205,-4819.62,127.6373,3.01942,5000,0,0,100,0),
(@PATH,5,2401.983,-4819.322,127.9547,0,0,0,0,100,0),
(@PATH,6,2403.983,-4817.572,127.9547,0,0,0,0,100,0),
(@PATH,7,2408.983,-4813.072,127.4547,0,0,0,0,100,0),
(@PATH,8,2415.233,-4809.072,127.4547,0,0,0,0,100,0),
(@PATH,9,2425.733,-4812.822,128.7047,0,0,0,0,100,0),
(@PATH,10,2430.983,-4816.322,129.4547,0,0,0,0,100,0),
(@PATH,11,2434.233,-4822.822,130.7047,0,0,0,0,100,0),
(@PATH,12,2399.405,-4814.858,127.5179,4.014257,5000,0,0,100,0),
(@PATH,13,2402.055,-4813.739,127.5776,0,0,0,0,100,0),
(@PATH,14,2404.305,-4815.739,127.5776,0,0,0,0,100,0),
(@PATH,15,2404.055,-4818.239,127.5776,0,0,0,0,100,0),
(@PATH,16,2401.205,-4819.62,127.6373,3.01942,5000,0,0,100,0),
(@PATH,17,2401.983,-4819.322,127.9547,0,0,0,0,100,0),
(@PATH,18,2403.983,-4817.572,127.9547,0,0,0,0,100,0),
(@PATH,19,2408.983,-4813.072,127.4547,0,0,0,0,100,0),
(@PATH,20,2415.233,-4809.072,127.4547,0,0,0,0,100,0),
(@PATH,21,2425.733,-4812.822,128.7047,0,0,0,0,100,0),
(@PATH,22,2430.983,-4816.322,129.4547,0,0,0,0,100,0),
(@PATH,23,2434.233,-4822.822,130.7047,0,0,0,0,100,0),
(@PATH,24,2433.668,-4825.551,130.861,0,0,0,0,100,0),
(@PATH,25,2437.418,-4828.051,131.111,0,0,0,0,100,0),
(@PATH,26,2437.575,-4830.577,130.95,4.29351,5000,0,0,100,0),
(@PATH,27,2437.575,-4830.577,130.95,1.029744,0,0,0,100,0),
(@PATH,28,2439.49,-4826.217,131.2339,0,0,0,0,100,0),
(@PATH,29,2438.24,-4822.717,130.9839,0,0,0,0,100,0),
(@PATH,30,2433.74,-4816.967,129.7339,0,0,0,0,100,0),
(@PATH,31,2426.49,-4811.967,128.7339,0,0,0,0,100,0),
(@PATH,32,2420.49,-4809.717,127.7339,0,0,0,0,100,0),
(@PATH,33,2411.99,-4811.967,127.4839,0,0,0,0,100,0),
(@PATH,34,2405.49,-4812.717,127.7339,0,0,0,0,100,0),
(@PATH,35,2399.405,-4814.858,127.5179,4.014257,5000,0,0,100,0);

SET @NPC := 765;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2322.724,`position_y`=-4768.457,`position_z`=123.5431 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '80126');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2322.724,-4768.457,123.5431,3.996804,5000,0,0,100,0),
(@PATH,2,2323.664,-4767.192,123.7763,0,0,0,0,100,0),
(@PATH,3,2324.414,-4761.692,123.7763,0,0,0,0,100,0),
(@PATH,4,2323.414,-4752.942,123.7763,0,0,0,0,100,0),
(@PATH,5,2320.414,-4746.192,123.7763,0,0,0,0,100,0),
(@PATH,6,2322.414,-4741.442,123.0263,0,0,0,0,100,0),
(@PATH,7,2327.164,-4733.942,120.0263,0,0,0,0,100,0),
(@PATH,8,2332.414,-4731.192,119.2763,0,0,0,0,100,0),
(@PATH,9,2340.414,-4729.942,119.7763,0,0,0,0,100,0),
(@PATH,10,2351.414,-4725.942,120.5263,0,0,0,0,100,0),
(@PATH,11,2356.104,-4721.927,120.5095,3.979351,5000,0,0,100,0),
(@PATH,12,2354.664,-4723.692,120.7763,0,0,0,0,100,0),
(@PATH,13,2350.414,-4726.442,120.5263,0,0,0,0,100,0),
(@PATH,14,2345.164,-4731.192,120.2763,0,0,0,0,100,0),
(@PATH,15,2337.664,-4729.692,119.5263,0,0,0,0,100,0),
(@PATH,16,2333.164,-4730.442,119.2763,0,0,0,0,100,0),
(@PATH,17,2328.164,-4732.942,119.5263,0,0,0,0,100,0),
(@PATH,18,2324.914,-4736.192,121.5263,0,0,0,0,100,0),
(@PATH,19,2322.414,-4741.192,123.0263,0,0,0,0,100,0),
(@PATH,20,2321.664,-4747.192,123.7763,0,0,0,0,100,0),
(@PATH,21,2320.914,-4753.942,123.7763,0,0,0,0,100,0),
(@PATH,22,2322.414,-4760.192,123.7763,0,0,0,0,100,0),
(@PATH,23,2323.914,-4764.692,123.7763,0,0,0,0,100,0),
(@PATH,24,2322.724,-4768.457,123.5431,3.996804,5000,0,0,100,0);

SET @NPC := 789;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2354.64,`position_y`=-4749.77,`position_z`=122.443 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2354.64,-4749.77,122.443,0.9424778,5000,0,0,100,0),
(@PATH,2,2361.065,-4748.025,122.418,0,0,0,0,100,0),
(@PATH,3,2369.315,-4754.025,123.168,0,0,0,0,100,0),
(@PATH,4,2383.565,-4769.275,124.668,0,0,0,0,100,0),
(@PATH,5,2399.065,-4790.025,126.668,0,0,0,0,100,0),
(@PATH,6,2421.065,-4808.775,127.918,0,0,0,0,100,0),
(@PATH,7,2433.315,-4817.525,130.168,0,0,0,0,100,0),
(@PATH,8,2458.815,-4829.025,134.418,0,0,0,0,100,0),
(@PATH,9,2475.315,-4844.025,139.168,0,0,0,0,100,0),
(@PATH,10,2486.99,-4843.78,141.393,6.073746,5000,0,0,100,0),
(@PATH,11,2479.565,-4836.775,139.418,0,0,0,0,100,0),
(@PATH,12,2466.065,-4827.275,136.168,0,0,0,0,100,0),
(@PATH,13,2449.315,-4819.275,132.668,0,0,0,0,100,0),
(@PATH,14,2426.565,-4807.775,128.418,0,0,0,0,100,0),
(@PATH,15,2409.815,-4793.275,126.668,0,0,0,0,100,0),
(@PATH,16,2394.315,-4776.525,125.668,0,0,0,0,100,0),
(@PATH,17,2376.065,-4751.025,122.918,0,0,0,0,100,0);

SET @NPC := 758;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2354.57,`position_y`=-4723.89,`position_z`=120.437 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2354.57,-4723.89,120.437,4.031711,5000,0,0,100,0),
(@PATH,2,2344.805,-4730.075,120.1041,0,0,0,0,100,0),
(@PATH,3,2337.805,-4723.825,118.3541,0,0,0,0,100,0),
(@PATH,4,2335.555,-4714.075,116.8541,0,0,0,0,100,0),
(@PATH,5,2319.305,-4678.825,111.3541,0,0,0,0,100,0),
(@PATH,6,2299.555,-4659.825,106.8541,0,0,0,0,100,0),
(@PATH,7,2263.305,-4637.075,96.60415,0,0,0,0,100,0),
(@PATH,8,2225.305,-4628.825,85.60415,0,0,0,0,100,0),
(@PATH,9,2179.04,-4639.76,69.7713,3.769911,5000,0,0,100,0),
(@PATH,10,2188.555,-4642.075,73.10415,0,0,0,0,100,0),
(@PATH,11,2216.555,-4633.575,82.85415,0,0,0,0,100,0),
(@PATH,12,2259.305,-4640.575,95.60415,0,0,0,0,100,0),
(@PATH,13,2289.555,-4657.575,104.8541,0,0,0,0,100,0),
(@PATH,14,2315.805,-4682.575,111.3541,0,0,0,0,100,0),
(@PATH,15,2328.055,-4707.575,115.3541,0,0,0,0,100,0),
(@PATH,16,2332.055,-4720.075,117.6041,0,0,0,0,100,0),
(@PATH,17,2338.555,-4725.075,118.6041,0,0,0,0,100,0),
(@PATH,18,2347.555,-4726.075,120.1041,0,0,0,0,100,0);

SET @NPC := 717;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2025.857,`position_y`=-4683.201,`position_z`=28.42917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2025.857,-4683.201,28.42917,0,0,0,0,100,0),
(@PATH,2,2015.818,-4688.088,28.73193,0,0,0,0,100,0),
(@PATH,3,2003.643,-4693.797,29.23093,0,0,0,0,100,0),
(@PATH,4,1998.419,-4691.936,29.85946,0,0,0,0,100,0),
(@PATH,5,1994.419,-4690.186,30.85946,0,0,0,0,100,0),
(@PATH,6,1990.419,-4688.186,31.85946,0,0,0,0,100,0),
(@PATH,7,1986.685,-4686.464,32.28598,0,0,0,0,100,0),
(@PATH,8,1985.685,-4685.964,32.28598,0,0,0,0,100,0),
(@PATH,9,1981.435,-4683.964,32.53598,0,0,0,0,100,0),
(@PATH,10,1976.935,-4682.214,32.28598,0,0,0,0,100,0),
(@PATH,11,1971.302,-4679.623,31.55442,0,0,0,0,100,0),
(@PATH,12,1966.365,-4681.003,32.18766,0,0,0,0,100,0),
(@PATH,13,1960.615,-4680.253,32.68766,0,0,0,0,100,0),
(@PATH,14,1953.954,-4679.512,33.14034,0,0,0,0,100,0),
(@PATH,15,1946.454,-4678.262,33.64034,0,0,0,0,100,0),
(@PATH,16,1941.09,-4676.992,33.84451,0,0,0,0,100,0),
(@PATH,17,1927.174,-4666.602,33.64549,0,0,0,0,100,0),
(@PATH,18,1922.214,-4656.237,33.53629,0,0,0,0,100,0),
(@PATH,19,1927.13,-4666.74,33.56191,0,0,0,0,100,0),
(@PATH,20,1927.491,-4666.738,33.64042,0,0,0,0,100,0),
(@PATH,21,1941.121,-4677.292,33.79312,0,0,0,0,100,0),
(@PATH,22,1952.621,-4679.292,33.29312,0,0,0,0,100,0),
(@PATH,23,1953.087,-4679.645,33.25417,0,0,0,0,100,0),
(@PATH,24,1954.087,-4679.895,33.00417,0,0,0,0,100,0),
(@PATH,25,1960.837,-4680.395,32.50417,0,0,0,0,100,0),
(@PATH,26,1966.614,-4681.123,31.85062,0,0,0,0,100,0),
(@PATH,27,1970.864,-4679.373,31.60062,0,0,0,0,100,0),
(@PATH,28,1971.112,-4679.344,31.69574,0,0,0,0,100,0),
(@PATH,29,1972.612,-4678.594,31.69574,0,0,0,0,100,0),
(@PATH,30,1977.362,-4681.344,32.19574,0,0,0,0,100,0),
(@PATH,31,1981.612,-4683.594,32.44574,0,0,0,0,100,0),
(@PATH,32,1985.862,-4685.844,32.44574,0,0,0,0,100,0),
(@PATH,33,1986.063,-4686.081,32.31482,0,0,0,0,100,0),
(@PATH,34,1987.063,-4686.581,32.31482,0,0,0,0,100,0),
(@PATH,35,1990.313,-4688.331,31.81482,0,0,0,0,100,0),
(@PATH,36,1994.313,-4690.081,30.81482,0,0,0,0,100,0),
(@PATH,37,1999.119,-4692.657,29.49647,0,0,0,0,100,0),
(@PATH,38,2003.999,-4693.762,29.15011,0,0,0,0,100,0),
(@PATH,39,2016.105,-4687.969,28.69383,0,0,0,0,100,0),
(@PATH,40,2025.87,-4682.854,28.44343,0,0,0,0,100,0),
(@PATH,41,2027.443,-4670.143,28.80083,0,0,0,0,100,0),
(@PATH,42,2027.256,-4661.537,28.77932,0,0,0,0,100,0),
(@PATH,43,2020.852,-4650.886,28.84587,0,0,0,0,100,0),
(@PATH,44,2020.852,-4650.886,28.34587,0,0,0,0,100,0),
(@PATH,45,2021.602,-4649.136,30.09587,0,0,0,0,100,0),
(@PATH,46,2024.602,-4648.136,31.84587,0,0,0,0,100,0),
(@PATH,47,2024.575,-4648.085,31.76911,0,0,0,0,100,0),
(@PATH,48,2022.575,-4646.835,31.76911,0,0,0,0,100,0),
(@PATH,49,2023.075,-4645.585,31.76911,0,0,0,0,100,0),
(@PATH,50,2023.83,-4640.935,31.93436,0,0,0,0,100,0),
(@PATH,51,2024.012,-4639.788,31.67921,0,0,0,0,100,0),
(@PATH,52,2023.631,-4640.864,31.93753,0,0,0,0,100,0),
(@PATH,53,2022.881,-4644.864,31.93753,0,0,0,0,100,0),
(@PATH,54,2022.803,-4644.882,31.83164,0,0,0,0,100,0),
(@PATH,55,2022.303,-4646.882,31.83164,0,0,0,0,100,0),
(@PATH,56,2019.803,-4646.632,31.83164,0,0,0,0,100,0),
(@PATH,57,2020.303,-4648.382,30.08164,0,0,0,0,100,0),
(@PATH,58,2020.29,-4648.641,30.02628,0,0,0,0,100,0),
(@PATH,59,2020.54,-4651.641,28.77628,0,0,0,0,100,0),
(@PATH,60,2027.098,-4661.933,28.80339,0,0,0,0,100,0),
(@PATH,61,2027.583,-4670.238,28.69053,0,0,0,0,100,0),
(@PATH,62,2025.674,-4683.059,28.40272,0,0,0,0,100,0);

SET @NPC := 286527;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2037.625,`position_y`=-4675.975,`position_z`=31.66002 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2037.625,-4675.975,31.66002,0,0,0,0,100,0),
(@PATH,2,2038.375,-4675.725,31.66002,0,0,0,0,100,0),
(@PATH,3,2039.625,-4675.225,31.66002,0,0,0,0,100,0),
(@PATH,4,2046.375,-4672.725,31.66002,0,0,0,0,100,0),
(@PATH,5,2047.625,-4672.225,31.66002,0,0,0,0,100,0),
(@PATH,6,2050.125,-4671.225,31.66002,0,0,0,0,100,0),
(@PATH,7,2052.625,-4670.475,31.66002,0,0,0,0,100,0),
(@PATH,8,2053.125,-4670.225,31.91002,0,0,0,0,100,0),
(@PATH,9,2055.125,-4669.475,32.91002,0,0,0,0,100,0),
(@PATH,10,2056.875,-4668.975,32.66002,0,0,0,0,100,0),
(@PATH,11,2057.375,-4668.725,32.66002,0,0,0,0,100,0),
(@PATH,12,2057.435,-4668.7,32.66305,0,0,0,0,100,0),
(@PATH,13,2055.185,-4669.45,32.66305,0,0,0,0,100,0),
(@PATH,14,2053.185,-4670.2,31.91305,0,0,0,0,100,0),
(@PATH,15,2052.685,-4670.45,31.66305,0,0,0,0,100,0),
(@PATH,16,2050.185,-4671.2,31.66305,0,0,0,0,100,0),
(@PATH,17,2039.615,-4675.117,31.52842,0,0,0,0,100,0),
(@PATH,18,2037.365,-4675.867,31.52842,0,0,0,0,100,0),
(@PATH,19,2037.625,-4675.975,31.66002,0,0,0,0,100,0),
(@PATH,20,2038.375,-4675.725,31.66002,0,0,0,0,100,0),
(@PATH,21,2039.625,-4675.225,31.66002,0,0,0,0,100,0),
(@PATH,22,2046.375,-4672.725,31.66002,0,0,0,0,100,0),
(@PATH,23,2047.625,-4672.225,31.66002,0,0,0,0,100,0),
(@PATH,24,2050.125,-4671.225,31.66002,0,0,0,0,100,0),
(@PATH,25,2052.625,-4670.475,31.66002,0,0,0,0,100,0),
(@PATH,26,2053.125,-4670.225,31.91002,0,0,0,0,100,0),
(@PATH,27,2055.125,-4669.475,32.91002,0,0,0,0,100,0),
(@PATH,28,2056.875,-4668.975,32.66002,0,0,0,0,100,0),
(@PATH,29,2057.375,-4668.725,32.66002,0,0,0,0,100,0),
(@PATH,30,2065.67,-4665.68,32.55113,3.525565,5000,0,0,100,0);

SET @NPC := 286518;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2129.26,`position_y`=-4671.98,`position_z`=52.79225 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2129.26,-4671.98,52.79225,0,0,0,0,100,0),
(@PATH,2,2129.26,-4671.98,52.79225,4.939282,5000,0,0,100,0),
(@PATH,3,2129.365,-4679.77,51.80112,0,0,0,0,100,0),
(@PATH,4,2121.615,-4686.52,49.30112,0,0,0,0,100,0),
(@PATH,5,2111.365,-4691.02,46.80112,0,0,0,0,100,0),
(@PATH,6,2103.365,-4698.27,44.30112,0,0,0,0,100,0),
(@PATH,7,2095.865,-4704.77,42.05112,0,0,0,0,100,0),
(@PATH,8,2086.615,-4707.52,39.05112,0,0,0,0,100,0),
(@PATH,9,2078.615,-4708.52,37.05112,0,0,0,0,100,0),
(@PATH,10,2069.115,-4709.27,34.05112,0,0,0,0,100,0),
(@PATH,11,2060.365,-4707.27,31.55112,0,0,0,0,100,0),
(@PATH,12,2049.615,-4711.52,29.55112,0,0,0,0,100,0),
(@PATH,13,2040.365,-4722.77,28.55112,0,0,0,0,100,0),
(@PATH,14,2022.615,-4721.77,28.80112,0,0,0,0,100,0),
(@PATH,15,2007.615,-4710.52,29.55112,0,0,0,0,100,0),
(@PATH,16,2007.365,-4700.02,29.05112,0,0,0,0,100,0),
(@PATH,17,2014.365,-4692.02,29.05112,0,0,0,0,100,0),
(@PATH,18,2027.115,-4688.52,28.55112,0,0,0,0,100,0),
(@PATH,19,2040.615,-4698.02,28.55112,0,0,0,0,100,0),
(@PATH,20,2046.365,-4706.52,29.05112,0,0,0,0,100,0),
(@PATH,21,2059.115,-4713.02,31.55112,0,0,0,0,100,0),
(@PATH,22,2069.865,-4715.02,34.05112,0,0,0,0,100,0),
(@PATH,23,2079.615,-4714.27,37.05112,0,0,0,0,100,0),
(@PATH,24,2087.115,-4713.77,39.30112,0,0,0,0,100,0),
(@PATH,25,2095.365,-4712.52,41.55112,0,0,0,0,100,0),
(@PATH,26,2105.115,-4705.02,44.30112,0,0,0,0,100,0),
(@PATH,27,2111.365,-4700.02,46.05112,0,0,0,0,100,0),
(@PATH,28,2119.115,-4695.27,48.05112,0,0,0,0,100,0),
(@PATH,29,2124.615,-4691.02,49.55112,0,0,0,0,100,0),
(@PATH,30,2130.115,-4687.02,50.80112,0,0,0,0,100,0);

SET @NPC := 286556;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1957.43,`position_y`=-4827.78,`position_z`=58.064 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1957.43,-4827.78,58.064,0,0,0,0,100,0),
(@PATH,2,1940.18,-4818.78,58.064,0,0,0,0,100,0),
(@PATH,3,1933.43,-4798.78,58.064,0,0,0,0,100,0),
(@PATH,4,1941.68,-4777.53,58.064,0,0,0,0,100,0),
(@PATH,5,1962.43,-4772.28,58.064,0,0,0,0,100,0),
(@PATH,6,1980.68,-4779.28,58.064,0,0,0,0,100,0),
(@PATH,7,1985.93,-4802.28,58.064,0,0,0,0,100,0),
(@PATH,8,1985.93,-4802.28,58.064,0,0,0,0,100,0),
(@PATH,9,1980.68,-4779.28,58.064,0,0,0,0,100,0),
(@PATH,10,1962.43,-4772.28,58.064,0,0,0,0,100,0),
(@PATH,11,1941.68,-4777.53,58.064,0,0,0,0,100,0),
(@PATH,12,1933.43,-4798.78,58.064,0,0,0,0,100,0),
(@PATH,13,1940.18,-4818.78,58.064,0,0,0,0,100,0),
(@PATH,14,1957.43,-4827.78,58.064,0,0,0,0,100,0),
(@PATH,15,1957.43,-4827.78,58.064,0,0,0,0,100,0);

SET @NPC :=  286548;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1965.46,`position_y`=-4802.14,`position_z`=84.2834 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1965.46,-4802.14,84.2834,3.054326,5000,0,0,100,0),
(@PATH,2,1967.28,-4800.415,84.43535,0,0,0,0,100,0),
(@PATH,3,1966.28,-4794.915,84.43535,0,0,0,0,100,0),
(@PATH,4,1961.53,-4790.665,84.43535,0,0,0,0,100,0),
(@PATH,5,1955.78,-4790.665,84.43535,0,0,0,0,100,0),
(@PATH,6,1950.28,-4793.915,83.18535,0,0,0,0,100,0),
(@PATH,7,1948.28,-4798.665,80.43535,0,0,0,0,100,0),
(@PATH,8,1947.78,-4804.165,78.18535,0,0,0,0,100,0),
(@PATH,9,1950.03,-4808.915,76.68535,0,0,0,0,100,0),
(@PATH,10,1953.78,-4812.165,74.43535,0,0,0,0,100,0),
(@PATH,11,1958.78,-4813.915,71.68535,0,0,0,0,100,0),
(@PATH,12,1962.78,-4813.665,69.43535,0,0,0,0,100,0),
(@PATH,13,1966.78,-4812.165,68.18535,0,0,0,0,100,0),
(@PATH,14,1971.28,-4808.665,66.68535,0,0,0,0,100,0),
(@PATH,15,1973.28,-4803.915,64.43535,0,0,0,0,100,0),
(@PATH,16,1972.78,-4798.665,61.68535,0,0,0,0,100,0),
(@PATH,17,1970.03,-4794.165,58.93535,0,0,0,0,100,0),
(@PATH,18,1967.53,-4792.665,58.43535,0,0,0,0,100,0),
(@PATH,19,1963.28,-4795.165,58.43535,0,0,0,0,100,0),
(@PATH,20,1959.78,-4799.915,58.43535,0,0,0,0,100,0),
(@PATH,21,1959.53,-4804.165,57.43535,0,0,0,0,100,0),
(@PATH,22,1959.28,-4809.665,54.43535,0,0,0,0,100,0),
(@PATH,23,1959.03,-4817.165,50.18535,0,0,0,0,100,0),
(@PATH,24,1958.78,-4821.165,49.43535,0,0,0,0,100,0),
(@PATH,25,1958.03,-4824.915,49.43535,0,0,0,0,100,0),
(@PATH,26,1956.53,-4826.415,49.43535,0,0,0,0,100,0),
(@PATH,27,1952.78,-4824.665,49.43535,0,0,0,0,100,0),
(@PATH,28,1953.03,-4820.915,48.43535,0,0,0,0,100,0),
(@PATH,29,1953.53,-4817.165,46.18535,0,0,0,0,100,0),
(@PATH,30,1954.03,-4813.665,44.18535,0,0,0,0,100,0),
(@PATH,31,1954.03,-4809.665,41.93535,0,0,0,0,100,0),
(@PATH,32,1953.78,-4805.665,39.93535,0,0,0,0,100,0),
(@PATH,33,1950.21,-4802.085,39.3388,0,0,0,0,100,0),
(@PATH,34,1946.71,-4803.585,39.3388,0,0,0,0,100,0),
(@PATH,35,1945.71,-4807.085,39.0888,0,0,0,0,100,0),
(@PATH,36,1946.96,-4812.085,39.0888,0,0,0,0,100,0),
(@PATH,37,1950.46,-4818.585,39.0888,0,0,0,0,100,0),
(@PATH,38,1953.96,-4820.835,39.3388,0,0,0,0,100,0),
(@PATH,39,1958.46,-4821.335,39.3388,0,0,0,0,100,0),
(@PATH,40,1965.21,-4821.585,39.0888,0,0,0,0,100,0),
(@PATH,41,1970.71,-4821.835,39.0888,0,0,0,0,100,0),
(@PATH,42,1976.96,-4821.585,39.3388,0,0,0,0,100,0),
(@PATH,43,1981.21,-4818.085,39.3388,0,0,0,0,100,0),
(@PATH,44,1981.96,-4812.585,39.3388,0,0,0,0,100,0),
(@PATH,45,1978.46,-4807.835,39.3388,0,0,0,0,100,0),
(@PATH,46,1966.82,-4802.98,39.0903,1.448623,5000,0,0,100,0),
(@PATH,47,1966.39,-4805.81,39.43685,0,0,0,0,100,0),
(@PATH,48,1964.89,-4812.81,43.18685,0,0,0,0,100,0),
(@PATH,49,1964.39,-4818.81,46.43685,0,0,0,0,100,0),
(@PATH,50,1964.14,-4825.06,49.43685,0,0,0,0,100,0),
(@PATH,51,1960.39,-4826.81,49.43685,0,0,0,0,100,0),
(@PATH,52,1958.64,-4825.06,49.43685,0,0,0,0,100,0),
(@PATH,53,1958.64,-4819.31,49.43685,0,0,0,0,100,0),
(@PATH,54,1959.14,-4815.56,51.18685,0,0,0,0,100,0),
(@PATH,55,1959.39,-4810.81,53.93685,0,0,0,0,100,0),
(@PATH,56,1959.64,-4807.06,55.93685,0,0,0,0,100,0),
(@PATH,57,1959.89,-4804.06,57.43685,0,0,0,0,100,0),
(@PATH,58,1960.14,-4799.81,58.43685,0,0,0,0,100,0),
(@PATH,59,1963.64,-4795.31,58.43685,0,0,0,0,100,0),
(@PATH,60,1968.89,-4793.06,58.43685,0,0,0,0,100,0),
(@PATH,61,1971.64,-4795.81,60.18685,0,0,0,0,100,0),
(@PATH,62,1972.89,-4798.81,61.68685,0,0,0,0,100,0),
(@PATH,63,1973.39,-4802.56,63.68685,0,0,0,0,100,0),
(@PATH,64,1972.14,-4806.56,65.68685,0,0,0,0,100,0),
(@PATH,65,1969.64,-4809.81,67.43685,0,0,0,0,100,0),
(@PATH,66,1966.39,-4812.31,68.18685,0,0,0,0,100,0),
(@PATH,67,1961.14,-4813.81,70.18685,0,0,0,0,100,0),
(@PATH,68,1956.14,-4813.06,73.18685,0,0,0,0,100,0),
(@PATH,69,1951.64,-4810.31,75.93685,0,0,0,0,100,0),
(@PATH,70,1948.14,-4806.06,78.18685,0,0,0,0,100,0),
(@PATH,71,1947.39,-4801.81,78.43685,0,0,0,0,100,0),
(@PATH,72,1948.39,-4797.31,81.18685,0,0,0,0,100,0),
(@PATH,73,1950.39,-4793.56,83.18685,0,0,0,0,100,0),
(@PATH,74,1953.64,-4791.31,84.43685,0,0,0,0,100,0),
(@PATH,75,1958.64,-4790.31,84.43685,0,0,0,0,100,0),
(@PATH,76,1963.39,-4792.31,84.43685,0,0,0,0,100,0),
(@PATH,77,1966.39,-4796.31,84.43685,0,0,0,0,100,0),
(@PATH,78,1967.39,-4800.06,84.43685,0,0,0,0,100,0);
-- DB/Pathing: Orgrimmar - Orgrimmar Wind Rider
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=51346;
UPDATE `creature_template_addon` SET `mount`=17719 WHERE  `entry`=51346;
-- Orgrimmar Wind Rider SAI
SET @ENTRY := 51346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1000,1000,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Wind Rider - Out of Combat - Set Fly On");

-- 1.
DELETE FROM `creature_formations` WHERE `leaderGUID`=311128;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311128, 311128, 0, 0, 2, 0, 0),
(311128, 311129, 6, 90, 2, 0, 0),
(311128, 311130, 6, 270, 2, 0, 0);

SET @NPC := 311128;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2187.817,`position_y`=-4778.676,`position_z`=125.7029 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2187.817,`position_y`=-4778.676,`position_z`=125.7029 WHERE `guid` IN (311129, 311130);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2187.817,-4778.676,125.7029,0,0,0,0,100,0),
(@PATH,2,2182.846,-4798.097,126.1781,0,0,0,0,100,0),
(@PATH,3,2174.621,-4816.327,127.6751,0,0,0,0,100,0),
(@PATH,4,2164.929,-4832.59,129.7338,0,0,0,0,100,0),
(@PATH,5,2152.912,-4847.764,132.3678,0,0,0,0,100,0),
(@PATH,6,2137.976,-4860.472,136.3017,0,0,0,0,100,0),
(@PATH,7,2121.298,-4869.944,141.6481,0,0,0,0,100,0),
(@PATH,8,2095.439,-4880.728,150.1578,0,0,0,0,100,0),
(@PATH,9,2077.664,-4885.504,155.7869,0,0,0,0,100,0),
(@PATH,10,2060.441,-4889.292,160.9066,0,0,0,0,100,0),
(@PATH,11,2048.303,-4891.24,163.8743,0,0,0,0,100,0),
(@PATH,12,2040.797,-4891.888,165.1125,0,0,0,0,100,0),
(@PATH,13,2009.719,-4890.751,166.2931,0,0,0,0,100,0),
(@PATH,14,1991.264,-4887.998,164.7786,0,0,0,0,100,0),
(@PATH,15,1972.238,-4882.874,162.7602,0,0,0,0,100,0),
(@PATH,16,1954.183,-4875.612,161.0011,0,0,0,0,100,0),
(@PATH,17,1936.896,-4865.991,159.0571,0,0,0,0,100,0),
(@PATH,18,1921.589,-4854.209,156.8548,0,0,0,0,100,0),
(@PATH,19,1907.726,-4842.86,153.6287,0,0,0,0,100,0),
(@PATH,20,1894.537,-4829.801,149.411,0,0,0,0,100,0),
(@PATH,21,1882.714,-4815.224,144.7564,0,0,0,0,100,0),
(@PATH,22,1871.844,-4800.283,140.9853,0,0,0,0,100,0),
(@PATH,23,1861.971,-4783.229,138.1526,0,0,0,0,100,0),
(@PATH,24,1855.708,-4764.293,136.0078,0,0,0,0,100,0),
(@PATH,25,1852.721,-4744.902,134.7815,0,0,0,0,100,0),
(@PATH,26,1849.573,-4730.19,133.674,0,0,0,0,100,0),
(@PATH,27,1842.431,-4714.059,132.0484,0,0,0,0,100,0),
(@PATH,28,1834.485,-4698.854,128.8706,0,0,0,0,100,0),
(@PATH,29,1825.651,-4681.227,124.9815,0,0,0,0,100,0),
(@PATH,30,1820.647,-4662.264,122.322,0,0,0,0,100,0),
(@PATH,31,1818.278,-4643.169,119.7074,0,0,0,0,100,0),
(@PATH,32,1817.632,-4623.775,116.8286,0,0,0,0,100,0),
(@PATH,33,1818.479,-4604.525,113.7605,0,0,0,0,100,0),
(@PATH,34,1821.578,-4586.457,110.5236,0,0,0,0,100,0),
(@PATH,35,1826.724,-4568.271,107.1641,0,0,0,0,100,0),
(@PATH,36,1832.583,-4550.62,104.7226,0,0,0,0,100,0),
(@PATH,37,1839.564,-4533.561,103.9151,0,0,0,0,100,0),
(@PATH,38,1850.087,-4516.717,105.5849,0,0,0,0,100,0),
(@PATH,39,1862.609,-4501.715,108.8422,0,0,0,0,100,0),
(@PATH,40,1876.802,-4488.396,111.5773,0,0,0,0,100,0),
(@PATH,41,1892.35,-4477.78,113.6671,0,0,0,0,100,0),
(@PATH,42,1908.139,-4468.642,116.6651,0,0,0,0,100,0),
(@PATH,43,1925.951,-4459.532,120.2383,0,0,0,0,100,0),
(@PATH,44,1945.116,-4453.866,124.3253,0,0,0,0,100,0),
(@PATH,45,1965.382,-4452.527,129.7621,0,0,0,0,100,0),
(@PATH,46,1985.508,-4456.406,133.5837,0,0,0,0,100,0),
(@PATH,47,2003.947,-4465.961,134.4593,0,0,0,0,100,0),
(@PATH,48,2019.997,-4477.835,134.0049,0,0,0,0,100,0),
(@PATH,49,2034.383,-4491.871,132.9457,0,0,0,0,100,0),
(@PATH,50,2044.794,-4507.014,130.8295,0,0,0,0,100,0),
(@PATH,51,2054.616,-4522.693,128.1867,0,0,0,0,100,0),
(@PATH,52,2063.581,-4538.11,125.4089,0,0,0,0,100,0),
(@PATH,53,2072.56,-4552.639,123.2466,0,0,0,0,100,0),
(@PATH,54,2082.353,-4567.643,121.5576,0,0,0,0,100,0),
(@PATH,55,2092.787,-4581.88,120.9785,0,0,0,0,100,0),
(@PATH,56,2104.217,-4596.457,120.9865,0,0,0,0,100,0),
(@PATH,57,2115.904,-4611.45,121.4817,0,0,0,0,100,0),
(@PATH,58,2127.003,-4626.323,122.7404,0,0,0,0,100,0),
(@PATH,59,2137.855,-4641.216,124.7632,0,0,0,0,100,0),
(@PATH,60,2148.089,-4656.334,126.4673,0,0,0,0,100,0),
(@PATH,61,2158.35,-4673.106,127.38,0,0,0,0,100,0),
(@PATH,62,2172.951,-4701.135,127.8701,0,0,0,0,100,0),
(@PATH,63,2180.643,-4718.625,127.6946,0,0,0,0,100,0),
(@PATH,64,2186.588,-4737.121,127.2609,0,0,0,0,100,0),
(@PATH,65,2189.073,-4756.958,126.5473,0,0,0,0,100,0),
(@PATH,66,2188.074,-4776.907,125.7336,0,0,0,0,100,0),
(@PATH,67,2183.474,-4796.335,126.0819,0,0,0,0,100,0),
(@PATH,68,2175.427,-4814.786,127.5149,0,0,0,0,100,0);

-- 2.
DELETE FROM `creature_formations` WHERE `leaderGUID`=310863;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(310863, 310863, 0, 0, 2, 0, 0),
(310863, 310862, 4, 90, 0, 0, 0),
(310863, 310864, 4, 270, 0, 0, 0);

SET @NPC := 310863;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1453.753,`position_y`=-4362.598,`position_z`=150.2205 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1453.753,`position_y`=-4362.598,`position_z`=150.2205 WHERE `guid`=310862;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1453.753,-4362.598,150.2205,0,0,0,0,100,0),
(@PATH,2,1433.826,-4364,150.1758,0,0,0,0,100,0),
(@PATH,3,1412.867,-4371.117,147.7425,0,0,0,0,100,0),
(@PATH,4,1395.033,-4383.396,143.9625,0,0,0,0,100,0),
(@PATH,5,1384.314,-4401.771,141.7057,0,0,0,0,100,0),
(@PATH,6,1382.594,-4424.03,141.1066,0,0,0,0,100,0),
(@PATH,7,1387.038,-4446.073,141.1109,0,0,0,0,100,0),
(@PATH,8,1399.362,-4463.98,141.1268,0,0,0,0,100,0),
(@PATH,9,1418.6,-4475.412,141.3571,0,0,0,0,100,0),
(@PATH,10,1439.65,-4480.671,141.7339,0,0,0,0,100,0),
(@PATH,11,1461.542,-4476.429,142.3987,0,0,0,0,100,0),
(@PATH,12,1479.532,-4467.318,143.1184,0,0,0,0,100,0),
(@PATH,13,1495.394,-4461.308,142.9345,0,0,0,0,100,0),
(@PATH,14,1511.904,-4456.913,141.6133,0,0,0,0,100,0),
(@PATH,15,1530.222,-4453.2,140.2176,0,0,0,0,100,0),
(@PATH,16,1546.628,-4450.616,138.8715,0,0,0,0,100,0),
(@PATH,17,1564.728,-4448.281,137.6191,0,0,0,0,100,0),
(@PATH,18,1585.957,-4445.819,137.8257,0,0,0,0,100,0),
(@PATH,19,1603.106,-4444.29,139.3361,0,0,0,0,100,0),
(@PATH,20,1622.621,-4442.888,141.715,0,0,0,0,100,0),
(@PATH,21,1642.136,-4441.177,144.7662,0,0,0,0,100,0),
(@PATH,22,1660.079,-4438.621,148.3557,0,0,0,0,100,0),
(@PATH,23,1678.894,-4434.875,154.1817,0,0,0,0,100,0),
(@PATH,24,1696.946,-4429.788,161.3757,0,0,0,0,100,0),
(@PATH,25,1713.376,-4419.644,168.4954,0,0,0,0,100,0),
(@PATH,26,1724.96,-4403.855,174.5833,0,0,0,0,100,0),
(@PATH,27,1732.58,-4385.019,180.4676,0,0,0,0,100,0),
(@PATH,28,1736.862,-4364.963,185.6549,0,0,0,0,100,0),
(@PATH,29,1736.79,-4344.911,189.4968,0,0,0,0,100,0),
(@PATH,30,1730.308,-4323.565,192.2776,0,0,0,0,100,0),
(@PATH,31,1721.316,-4305.716,193.4582,0,0,0,0,100,0),
(@PATH,32,1711.136,-4289.479,192.8545,0,0,0,0,100,0),
(@PATH,33,1696.868,-4274.714,189.1641,0,0,0,0,100,0),
(@PATH,34,1684.186,-4263.849,183.6184,0,0,0,0,100,0),
(@PATH,35,1671.591,-4253.092,175.6228,0,0,0,0,100,0),
(@PATH,36,1658.406,-4242.482,166.7235,0,0,0,0,100,0),
(@PATH,37,1644.187,-4231.799,160.0248,0,0,0,0,100,0),
(@PATH,38,1629.841,-4220.764,153.4237,0,0,0,0,100,0),
(@PATH,39,1620.33,-4210.348,148.7201,0,0,0,0,100,0),
(@PATH,40,1614.203,-4195.522,146.76,0,0,0,0,100,0),
(@PATH,41,1613.691,-4182.065,147.3239,0,0,0,0,100,0),
(@PATH,42,1620.928,-4170.055,150.5764,0,0,0,0,100,0),
(@PATH,43,1631.703,-4160.409,153.4229,0,0,0,0,100,0),
(@PATH,44,1648.289,-4151.509,156.0684,0,0,0,0,100,0),
(@PATH,45,1664.268,-4143.702,158.7324,0,0,0,0,100,0),
(@PATH,46,1681.259,-4136.542,160.1767,0,0,0,0,100,0),
(@PATH,47,1697.498,-4131.925,157.5118,0,0,0,0,100,0),
(@PATH,48,1716.405,-4126.562,153.8514,0,0,0,0,100,0),
(@PATH,49,1733.779,-4118.829,153.4746,0,0,0,0,100,0),
(@PATH,50,1751.665,-4108.66,154.7351,0,0,0,0,100,0),
(@PATH,51,1766.817,-4094.701,156.5226,0,0,0,0,100,0),
(@PATH,52,1777.733,-4079.402,158.4923,0,0,0,0,100,0),
(@PATH,53,1786.683,-4060.58,161.2617,0,0,0,0,100,0),
(@PATH,54,1792.617,-4042.946,164.3353,0,0,0,0,100,0),
(@PATH,55,1797.749,-4026.452,167.322,0,0,0,0,100,0),
(@PATH,56,1802.148,-4007.16,170.8382,0,0,0,0,100,0),
(@PATH,57,1803.962,-3986.031,174.7932,0,0,0,0,100,0),
(@PATH,58,1802.265,-3965.61,178.8509,0,0,0,0,100,0),
(@PATH,59,1799.214,-3947.251,182.7919,0,0,0,0,100,0),
(@PATH,60,1794.865,-3926.838,187.2427,0,0,0,0,100,0),
(@PATH,61,1789.204,-3906.146,191.7953,0,0,0,0,100,0),
(@PATH,62,1782.103,-3886.776,196.0662,0,0,0,0,100,0),
(@PATH,63,1772.051,-3868.774,199.9532,0,0,0,0,100,0),
(@PATH,64,1757.822,-3856.761,202.4072,0,0,0,0,100,0),
(@PATH,65,1736.957,-3853.127,203.7096,0,0,0,0,100,0),
(@PATH,66,1715.396,-3857.027,203.8102,0,0,0,0,100,0),
(@PATH,67,1694.912,-3864.766,203.2657,0,0,0,0,100,0),
(@PATH,68,1677.01,-3873.806,202.6426,0,0,0,0,100,0),
(@PATH,69,1660.573,-3884.544,202.2555,0,0,0,0,100,0),
(@PATH,70,1644.532,-3899.208,201.7124,0,0,0,0,100,0),
(@PATH,71,1630.805,-3915.794,200.8964,0,0,0,0,100,0),
(@PATH,72,1620.844,-3932.873,199.7097,0,0,0,0,100,0),
(@PATH,73,1617.142,-3953.463,197.727,0,0,0,0,100,0),
(@PATH,74,1626.62,-3974.113,194.3372,0,0,0,0,100,0),
(@PATH,75,1639.574,-3989.739,190.5507,0,0,0,0,100,0),
(@PATH,76,1648.191,-4002.926,187.0622,0,0,0,0,100,0),
(@PATH,77,1656.632,-4019.936,183.2987,0,0,0,0,100,0),
(@PATH,78,1661.367,-4033.343,180.1778,0,0,0,0,100,0),
(@PATH,79,1661.558,-4034.377,179.9276,0,0,0,0,100,0),
(@PATH,80,1655.095,-4058.743,175.1125,0,0,0,0,100,0),
(@PATH,81,1642.66,-4070.673,172.3383,0,0,0,0,100,0),
(@PATH,82,1629.409,-4080.272,168.6872,0,0,0,0,100,0),
(@PATH,83,1613.893,-4087.821,163.9733,0,0,0,0,100,0),
(@PATH,84,1598.063,-4094.845,159.4254,0,0,0,0,100,0),
(@PATH,85,1580.72,-4105.733,155.2786,0,0,0,0,100,0),
(@PATH,86,1565.851,-4119.33,151.7436,0,0,0,0,100,0),
(@PATH,87,1553.396,-4135.209,148.8713,0,0,0,0,100,0),
(@PATH,88,1543.916,-4153.896,146.7233,0,0,0,0,100,0),
(@PATH,89,1541.862,-4176.448,144.8783,0,0,0,0,100,0),
(@PATH,90,1546.4,-4196.079,143.3901,0,0,0,0,100,0),
(@PATH,91,1555.503,-4215.291,141.9598,0,0,0,0,100,0),
(@PATH,92,1572.037,-4230.205,140.8074,0,0,0,0,100,0),
(@PATH,93,1583.852,-4239.599,139.5642,0,0,0,0,100,0),
(@PATH,94,1592.342,-4252.434,137.9855,0,0,0,0,100,0),
(@PATH,95,1599.167,-4269.076,136.3192,0,0,0,0,100,0),
(@PATH,96,1605.269,-4286.15,134.7745,0,0,0,0,100,0),
(@PATH,97,1607.538,-4301.603,133.1383,0,0,0,0,100,0),
(@PATH,98,1603.179,-4313.941,131.4175,0,0,0,0,100,0),
(@PATH,99,1592.402,-4328.95,129.5083,0,0,0,0,100,0),
(@PATH,100,1580.699,-4342.257,128.4065,0,0,0,0,100,0),
(@PATH,101,1568.928,-4352.674,130.1394,0,0,0,0,100,0),
(@PATH,102,1554.321,-4360.198,134.159,0,0,0,0,100,0),
(@PATH,103,1540.395,-4365.917,138.999,0,0,0,0,100,0),
(@PATH,104,1526.083,-4367.126,142.841,0,0,0,0,100,0),
(@PATH,105,1507.671,-4366.261,146.282,0,0,0,0,100,0),
(@PATH,106,1489.133,-4365.348,148.2374,0,0,0,0,100,0),
(@PATH,107,1468.95,-4363.478,149.6181,0,0,0,0,100,0);

-- correction
DELETE FROM `creature` WHERE `guid` IN (749, 748, 750, 286722);

-- 3.
DELETE FROM `creature_formations` WHERE `leaderGUID`=287137;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(287137, 287137, 0, 0, 2, 0, 0),
(287137, 287136, 6, 90, 2, 0, 0),
(287137, 287138, 6, 270, 2, 0, 0);

SET @NPC := 287137;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2344.476,`position_y`=-4649.64,`position_z`=193.1467 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2344.476,`position_y`=-4649.64,`position_z`=193.1467 WHERE `guid` IN (287136, 287138);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2344.476,-4649.64,193.1467,0,0,0,0,100,0),
(@PATH,2,2356.663,-4664.491,196.4953,0,0,0,0,100,0),
(@PATH,3,2365.037,-4681.887,202.8909,0,0,0,0,100,0),
(@PATH,4,2371.134,-4695.135,210.2224,0,0,0,0,100,0),
(@PATH,5,2380.507,-4708.189,216.9977,0,0,0,0,100,0),
(@PATH,6,2380.564,-4707.161,217.7028,0,0,0,0,100,0),
(@PATH,7,2403.165,-4735.233,224.0464,0,0,0,0,100,0),
(@PATH,8,2415.197,-4746.526,225.39,0,0,0,0,100,0),
(@PATH,9,2429.123,-4755.889,226.2017,0,0,0,0,100,0),
(@PATH,10,2444.228,-4763.291,226.3444,0,0,0,0,100,0),
(@PATH,11,2460.73,-4769.616,226.2886,0,0,0,0,100,0),
(@PATH,12,2479.895,-4780.43,226.2886,0,0,0,0,100,0),
(@PATH,13,2492.513,-4797.801,226.2886,0,0,0,0,100,0),
(@PATH,14,2498.938,-4818.601,226.2886,0,0,0,0,100,0),
(@PATH,15,2497.883,-4839.326,226.2886,0,0,0,0,100,0),
(@PATH,16,2492.498,-4859.307,226.2886,0,0,0,0,100,0),
(@PATH,17,2482.858,-4877.205,226.2886,0,0,0,0,100,0),
(@PATH,18,2469.356,-4893.59,226.2886,0,0,0,0,100,0),
(@PATH,19,2450.658,-4904.374,226.2886,0,0,0,0,100,0),
(@PATH,20,2428.441,-4907.047,226.2886,0,0,0,0,100,0),
(@PATH,21,2430.179,-4904.146,227.2886,0,0,0,0,100,0),
(@PATH,22,2390.011,-4890.25,226.2886,0,0,0,0,100,0),
(@PATH,23,2376.153,-4876.193,226.3321,0,0,0,0,100,0),
(@PATH,24,2364.573,-4860.924,226.214,0,0,0,0,100,0),
(@PATH,25,2354.688,-4844.067,224.8432,0,0,0,0,100,0),
(@PATH,26,2347.108,-4827.485,221.3296,0,0,0,0,100,0),
(@PATH,27,2340.542,-4808.85,216.7655,0,0,0,0,100,0),
(@PATH,28,2336.556,-4790.968,211.4741,0,0,0,0,100,0),
(@PATH,29,2331.757,-4775.583,207.1461,0,0,0,0,100,0),
(@PATH,30,2324.677,-4761.693,203.7116,0,0,0,0,100,0),
(@PATH,31,2314.852,-4748.389,200.5888,0,0,0,0,100,0),
(@PATH,32,2303.061,-4736.283,197.593,0,0,0,0,100,0),
(@PATH,33,2290.437,-4725.825,192.8786,0,0,0,0,100,0),
(@PATH,34,2276.626,-4716.892,187.3818,0,0,0,0,100,0),
(@PATH,35,2260.946,-4706.064,182.7776,0,0,0,0,100,0),
(@PATH,36,2246.423,-4693.782,179.7449,0,0,0,0,100,0),
(@PATH,37,2232.982,-4679.748,177.2713,0,0,0,0,100,0),
(@PATH,38,2221.459,-4664.255,174.932,0,0,0,0,100,0),
(@PATH,39,2212.006,-4648.268,173.2646,0,0,0,0,100,0),
(@PATH,40,2203.236,-4632.228,172.8204,0,0,0,0,100,0),
(@PATH,41,2194.019,-4617.633,173.9287,0,0,0,0,100,0),
(@PATH,42,2183.847,-4602.959,175.8922,0,0,0,0,100,0),
(@PATH,43,2172.926,-4588.244,178.2528,0,0,0,0,100,0),
(@PATH,44,2162.121,-4573.11,179.1541,0,0,0,0,100,0),
(@PATH,45,2151.729,-4557.401,178.6325,0,0,0,0,100,0),
(@PATH,46,2142.714,-4541.034,176.4897,0,0,0,0,100,0),
(@PATH,47,2134.871,-4525.855,173.5946,0,0,0,0,100,0),
(@PATH,48,2125.843,-4512.703,169.2345,0,0,0,0,100,0),
(@PATH,49,2103.72,-4489.439,158.1273,0,0,0,0,100,0),
(@PATH,50,2089.687,-4478.886,151.5134,0,0,0,0,100,0),
(@PATH,51,2076.47,-4468.49,145.7966,0,0,0,0,100,0),
(@PATH,52,2062.125,-4456.734,140.1501,0,0,0,0,100,0),
(@PATH,53,2048.843,-4444.243,135.3729,0,0,0,0,100,0),
(@PATH,54,2036.135,-4430.877,131.2297,0,0,0,0,100,0),
(@PATH,55,2024.317,-4416.351,128.0157,0,0,0,0,100,0),
(@PATH,56,2013.314,-4400.627,125.5775,0,0,0,0,100,0),
(@PATH,57,2003.819,-4384.565,124.432,0,0,0,0,100,0),
(@PATH,58,1995.68,-4367.403,125.0835,0,0,0,0,100,0),
(@PATH,59,1989.646,-4348.842,127.5712,0,0,0,0,100,0),
(@PATH,60,1986.104,-4330.198,131.3635,0,0,0,0,100,0),
(@PATH,61,1984.33,-4310.543,136.3107,0,0,0,0,100,0),
(@PATH,62,1985.675,-4291.238,142.08,0,0,0,0,100,0),
(@PATH,63,1991.782,-4272.034,149.2602,0,0,0,0,100,0),
(@PATH,64,2006.172,-4256.529,155.3723,0,0,0,0,100,0),
(@PATH,65,2026.905,-4249.235,160.0862,0,0,0,0,100,0),
(@PATH,66,2048.529,-4250.858,161.7471,0,0,0,0,100,0),
(@PATH,67,2068.326,-4261.122,160.5783,0,0,0,0,100,0),
(@PATH,68,2081.692,-4277.859,157.3597,0,0,0,0,100,0),
(@PATH,69,2088.627,-4297.592,152.968,0,0,0,0,100,0),
(@PATH,70,2089.216,-4317.914,147.9373,0,0,0,0,100,0),
(@PATH,71,2085.511,-4337.333,143.084,0,0,0,0,100,0),
(@PATH,72,2077.561,-4355.278,138.611,0,0,0,0,100,0),
(@PATH,73,2066.443,-4371.464,135.3215,0,0,0,0,100,0),
(@PATH,74,2052.791,-4385.495,133.0123,0,0,0,0,100,0),
(@PATH,75,2036.607,-4397.225,129.5401,0,0,0,0,100,0),
(@PATH,76,2020.975,-4406.482,127.706,0,0,0,0,100,0),
(@PATH,77,2006.328,-4414.937,129.485,0,0,0,0,100,0),
(@PATH,78,1997.5,-4426.043,131.056,0,0,0,0,100,0),
(@PATH,79,1991.759,-4439.949,132.9174,0,0,0,0,100,0),
(@PATH,80,1993.17,-4453.991,137.8703,0,0,0,0,100,0),
(@PATH,81,1999.313,-4466.726,141.9852,0,0,0,0,100,0),
(@PATH,82,2009.966,-4479.995,146.4247,0,0,0,0,100,0),
(@PATH,83,2021.526,-4491.116,150.4905,0,0,0,0,100,0),
(@PATH,84,2035.686,-4503.419,155.0344,0,0,0,0,100,0),
(@PATH,85,2049.509,-4515.366,159.5474,0,0,0,0,100,0),
(@PATH,86,2063.091,-4528.274,164.582,0,0,0,0,100,0),
(@PATH,87,2074.898,-4540.081,169.8273,0,0,0,0,100,0),
(@PATH,88,2086.931,-4549.661,174.8661,0,0,0,0,100,0),
(@PATH,89,2102.868,-4558.697,180.0944,0,0,0,0,100,0),
(@PATH,90,2117.932,-4565.953,184.4518,0,0,0,0,100,0),
(@PATH,91,2130.677,-4570.399,187.8371,0,0,0,0,100,0),
(@PATH,92,2148.475,-4573.66,189.4443,0,0,0,0,100,0),
(@PATH,93,2164.142,-4576.132,190.4781,0,0,0,0,100,0),
(@PATH,94,2164.281,-4576.153,190.4873,0,0,0,0,100,0),
(@PATH,95,2205.021,-4582.769,191.698,0,0,0,0,100,0),
(@PATH,96,2223.725,-4587.793,191.629,0,0,0,0,100,0),
(@PATH,97,2241.47,-4593.268,191.629,0,0,0,0,100,0),
(@PATH,98,2259.559,-4599.501,191.629,0,0,0,0,100,0),
(@PATH,99,2276.989,-4606.036,191.629,0,0,0,0,100,0),
(@PATH,100,2294.536,-4613.769,191.629,0,0,0,0,100,0),
(@PATH,101,2311.454,-4623.332,191.3935,0,0,0,0,100,0),
(@PATH,102,2327.26,-4634.21,191.3435,0,0,0,0,100,0);

-- 4.
DELETE FROM `creature_formations` WHERE `leaderGUID`=311055;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311055, 311055, 0, 0, 2, 0, 0),
(311055, 311054, 6, 90, 2, 0, 0),
(311055, 311103, 6, 270, 2, 0, 0);

SET @NPC := 311055;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2070.802,`position_y`=-4466.9,`position_z`=110.4167 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2070.802,`position_y`=-4466.9,`position_z`=110.4167 WHERE `guid` IN (311054, 311103);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2070.802,-4466.9,110.4167,0,0,0,0,100,0),
(@PATH,2,2077.909,-4449.454,111.092,0,0,0,0,100,0),
(@PATH,3,2084.219,-4432.092,115.2293,0,0,0,0,100,0),
(@PATH,4,2089.34,-4414.369,120.0934,0,0,0,0,100,0),
(@PATH,5,2092.373,-4395.824,124.3021,0,0,0,0,100,0),
(@PATH,6,2093.642,-4377.708,129.6119,0,0,0,0,100,0),
(@PATH,7,2093.612,-4359.75,135.9595,0,0,0,0,100,0),
(@PATH,8,2092.712,-4342.802,142.5403,0,0,0,0,100,0),
(@PATH,9,2089.928,-4324.907,149.8836,0,0,0,0,100,0),
(@PATH,10,2085.531,-4308.248,158.0671,0,0,0,0,100,0),
(@PATH,11,2079.91,-4291.361,164.5166,0,0,0,0,100,0),
(@PATH,12,2072.953,-4274.022,167.8593,0,0,0,0,100,0),
(@PATH,13,2064.66,-4257.31,166.0467,0,0,0,0,100,0),
(@PATH,14,2055.794,-4242.208,159.0939,0,0,0,0,100,0),
(@PATH,15,2046.105,-4228.125,149.6974,0,0,0,0,100,0),
(@PATH,16,2035.854,-4216.223,137.8053,0,0,0,0,100,0),
(@PATH,17,2025.628,-4206.5,126.0673,0,0,0,0,100,0),
(@PATH,18,2011.247,-4195.292,115.0595,0,0,0,0,100,0),
(@PATH,19,1995.137,-4186.879,107.0282,0,0,0,0,100,0),
(@PATH,20,1977.305,-4182.569,101.6301,0,0,0,0,100,0),
(@PATH,21,1957.84,-4179.803,99.54911,0,0,0,0,100,0),
(@PATH,22,1937.104,-4181.209,99.66904,0,0,0,0,100,0),
(@PATH,23,1918.19,-4187.264,99.96359,0,0,0,0,100,0),
(@PATH,24,1900.112,-4199.129,99.93196,0,0,0,0,100,0),
(@PATH,25,1886.134,-4214.233,99.90671,0,0,0,0,100,0),
(@PATH,26,1875.294,-4230.847,100.9119,0,0,0,0,100,0),
(@PATH,27,1867.471,-4247.532,102.6202,0,0,0,0,100,0),
(@PATH,28,1860.031,-4265.672,104.4892,0,0,0,0,100,0),
(@PATH,29,1855.04,-4284.947,106.7965,0,0,0,0,100,0),
(@PATH,30,1853.599,-4305.338,109.0562,0,0,0,0,100,0),
(@PATH,31,1858.074,-4326.417,110.5447,0,0,0,0,100,0),
(@PATH,32,1871.455,-4345.249,112.2112,0,0,0,0,100,0),
(@PATH,33,1893.955,-4353.599,114.1995,0,0,0,0,100,0),
(@PATH,34,1911.324,-4352.415,116.2395,0,0,0,0,100,0),
(@PATH,35,1921.525,-4358.517,117.7673,0,0,0,0,100,0),
(@PATH,36,1929.024,-4370.511,119.4713,0,0,0,0,100,0),
(@PATH,37,1932.213,-4384.316,119.4429,0,0,0,0,100,0),
(@PATH,38,1931.979,-4401.509,117.4868,0,0,0,0,100,0),
(@PATH,39,1930.207,-4418.992,115.0721,0,0,0,0,100,0),
(@PATH,40,1927.021,-4435.5,112.7006,0,0,0,0,100,0),
(@PATH,41,1921.894,-4452.03,110.6684,0,0,0,0,100,0),
(@PATH,42,1914.313,-4465.204,108.7827,0,0,0,0,100,0),
(@PATH,43,1903.157,-4477.424,107.414,0,0,0,0,100,0),
(@PATH,44,1889.731,-4488.692,106.9053,0,0,0,0,100,0),
(@PATH,45,1875.686,-4499.458,106.9582,0,0,0,0,100,0),
(@PATH,46,1861.084,-4509.003,107.0194,0,0,0,0,100,0),
(@PATH,47,1845.435,-4516.418,106.7208,0,0,0,0,100,0),
(@PATH,48,1830.062,-4520.913,106.402,0,0,0,0,100,0),
(@PATH,49,1814.017,-4522.21,106.155,0,0,0,0,100,0),
(@PATH,50,1797.839,-4520.491,106.1131,0,0,0,0,100,0),
(@PATH,51,1783.63,-4515.53,106.0794,0,0,0,0,100,0),
(@PATH,52,1770.261,-4505.03,105.6187,0,0,0,0,100,0),
(@PATH,53,1753.287,-4493.229,105.6244,0,0,0,0,100,0),
(@PATH,54,1732.657,-4486.024,107.0413,0,0,0,0,100,0),
(@PATH,55,1709.945,-4489.919,108.4623,0,0,0,0,100,0),
(@PATH,56,1691.712,-4506.029,107.7552,0,0,0,0,100,0),
(@PATH,57,1687.861,-4530.702,108.4373,0,0,0,0,100,0),
(@PATH,58,1703.458,-4551.063,110.0196,0,0,0,0,100,0),
(@PATH,59,1721.49,-4558.226,112.5992,0,0,0,0,100,0),
(@PATH,60,1737.531,-4564.795,115.5456,0,0,0,0,100,0),
(@PATH,61,1737.511,-4564.788,115.5422,0,0,0,0,100,0),
(@PATH,62,1776.312,-4575.609,119.9136,0,0,0,0,100,0),
(@PATH,63,1796.13,-4574.086,121.3507,0,0,0,0,100,0),
(@PATH,64,1814.89,-4570.237,121.5083,0,0,0,0,100,0),
(@PATH,65,1832.352,-4567.336,121.1143,0,0,0,0,100,0),
(@PATH,66,1849.508,-4566.387,120.172,0,0,0,0,100,0),
(@PATH,67,1864.634,-4569.146,118.4792,0,0,0,0,100,0),
(@PATH,68,1878.275,-4575.464,116.1419,0,0,0,0,100,0),
(@PATH,69,1891.51,-4586.458,113.3991,0,0,0,0,100,0),
(@PATH,70,1908.983,-4597.85,110.471,0,0,0,0,100,0),
(@PATH,71,1928.972,-4602.315,106.6242,0,0,0,0,100,0),
(@PATH,72,1949.398,-4601.805,102.9171,0,0,0,0,100,0),
(@PATH,73,1969.276,-4596.564,100.8913,0,0,0,0,100,0),
(@PATH,74,1986.783,-4585.743,100.7549,0,0,0,0,100,0),
(@PATH,75,2001.332,-4573.289,101.1974,0,0,0,0,100,0),
(@PATH,76,2014.655,-4559.408,102.3548,0,0,0,0,100,0),
(@PATH,77,2027.02,-4545.175,104.094,0,0,0,0,100,0),
(@PATH,78,2038.184,-4529.604,106.6144,0,0,0,0,100,0),
(@PATH,79,2047.414,-4513.563,108.0986,0,0,0,0,100,0),
(@PATH,80,2056.418,-4496.791,109.37,0,0,0,0,100,0),
(@PATH,81,2065.042,-4479.687,110.3946,0,0,0,0,100,0),
(@PATH,82,2072.51,-4462.905,110.3689,0,0,0,0,100,0),
(@PATH,83,2079.677,-4444.754,111.9228,0,0,0,0,100,0),
(@PATH,84,2086.185,-4426.043,117.0077,0,0,0,0,100,0),
(@PATH,85,2090.693,-4407.714,121.6001,0,0,0,0,100,0),
(@PATH,86,2092.977,-4389.396,126.0021,0,0,0,0,100,0),
(@PATH,87,2093.759,-4371.153,131.8432,0,0,0,0,100,0),
(@PATH,88,2093.363,-4353.426,138.3627,0,0,0,0,100,0),
(@PATH,89,2091.965,-4336.111,145.2158,0,0,0,0,100,0),
(@PATH,90,2088.477,-4318.838,152.7976,0,0,0,0,100,0);

-- 5. singel
SET @NPC := 310649;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1917.59, -4699.52, 82.6288, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1956.38, -4737.34, 82.0614, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1980.35, -4753.11, 78.5511, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2015.21, -4757, 78.2543, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 2047.53, -4770.04, 77.5184, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2083.43, -4769.09, 79.5475, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2113.08, -4725.98, 83.7579, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2119.78, -4667.99, 87.8909, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2093.88, -4616.57, 87.6157, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 2051.04, -4588.51, 78.1248, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 2000.85, -4598.82, 68.8872, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1955.07, -4629.46, 62.6593, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1918.5, -4662.03, 68.0767, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1908.28, -4682.58, 72.5178, 0, 0, 0, 0, 100, 0);

-- 6.
DELETE FROM `creature_formations` WHERE `leaderGUID`=287140;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(287140, 287140, 0, 0, 2, 0, 0),
(287140, 287141, 6, 90, 2, 0, 0),
(287140, 287139, 6, 270, 2, 0, 0);

SET @NPC := 287140;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1752.398,`position_y`=-4243.478,`position_z`=115.2898 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1752.398,`position_y`=-4243.478,`position_z`=115.2898 WHERE `guid` IN (287141, 287139);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1752.398,-4243.478,115.2898,0,0,0,0,100,0),
(@PATH,2,1739.821,-4239.554,114.8747,0,0,0,0,100,0),
(@PATH,3,1723.82,-4239.623,115.0613,0,0,0,0,100,0),
(@PATH,4,1707.624,-4242.889,114.9495,0,0,0,0,100,0),
(@PATH,5,1696.511,-4248.668,114.8715,0,0,0,0,100,0),
(@PATH,6,1688.887,-4261.579,114.8668,0,0,0,0,100,0),
(@PATH,7,1687.313,-4272.348,115.0801,0,0,0,0,100,0),
(@PATH,8,1694.772,-4283.346,115.7162,0,0,0,0,100,0),
(@PATH,9,1706.599,-4293.738,116.267,0,0,0,0,100,0),
(@PATH,10,1720.707,-4300.788,116.6437,0,0,0,0,100,0),
(@PATH,11,1722.247,-4301.319,116.6611,0,0,0,0,100,0),
(@PATH,12,1748.626,-4301.684,116.3646,0,0,0,0,100,0),
(@PATH,13,1760.774,-4294.115,116.3098,0,0,0,0,100,0),
(@PATH,14,1765.131,-4282.963,116.6441,0,0,0,0,100,0),
(@PATH,15,1768.911,-4265.282,116.7886,0,0,0,0,100,0),
(@PATH,16,1779.849,-4244.463,116.6789,0,0,0,0,100,0),
(@PATH,17,1800.664,-4233.946,116.446,0,0,0,0,100,0),
(@PATH,18,1823.237,-4236.028,116.0322,0,0,0,0,100,0),
(@PATH,19,1842.136,-4244.565,115.7385,0,0,0,0,100,0),
(@PATH,20,1857.677,-4261.013,115.8512,0,0,0,0,100,0),
(@PATH,21,1862.982,-4283.648,116.3685,0,0,0,0,100,0),
(@PATH,22,1852.109,-4305.289,116.8431,0,0,0,0,100,0),
(@PATH,23,1835.275,-4317.941,117.2421,0,0,0,0,100,0),
(@PATH,24,1824.156,-4327.291,117.9631,0,0,0,0,100,0),
(@PATH,25,1816.757,-4339.838,118.5972,0,0,0,0,100,0),
(@PATH,26,1813.489,-4354.331,118.5286,0,0,0,0,100,0),
(@PATH,27,1814.347,-4370.722,118.5286,0,0,0,0,100,0),
(@PATH,28,1817.135,-4387.975,118.5251,0,0,0,0,100,0),
(@PATH,29,1821.922,-4402.899,118.5264,0,0,0,0,100,0),
(@PATH,30,1829.496,-4417.697,118.6126,0,0,0,0,100,0),
(@PATH,31,1839.317,-4429.991,118.732,0,0,0,0,100,0),
(@PATH,32,1851.958,-4439.413,118.8564,0,0,0,0,100,0),
(@PATH,33,1864.205,-4443.029,118.5307,0,0,0,0,100,0),
(@PATH,34,1876.703,-4439.447,118.8907,0,0,0,0,100,0),
(@PATH,35,1886.7,-4432.099,120.0332,0,0,0,0,100,0),
(@PATH,36,1887.963,-4422.688,121.9425,0,0,0,0,100,0),
(@PATH,37,1882.006,-4409.991,123.7688,0,0,0,0,100,0),
(@PATH,38,1871.089,-4395.06,125.3668,0,0,0,0,100,0),
(@PATH,39,1860.026,-4382.354,125.2833,0,0,0,0,100,0),
(@PATH,40,1848.181,-4372.905,123.9159,0,0,0,0,100,0),
(@PATH,41,1833.491,-4365.679,122.3379,0,0,0,0,100,0),
(@PATH,42,1817.43,-4360.013,120.4906,0,0,0,0,100,0),
(@PATH,43,1800.453,-4355.821,118.7043,0,0,0,0,100,0),
(@PATH,44,1783.021,-4350.945,118.2935,0,0,0,0,100,0),
(@PATH,45,1769.411,-4350.87,118.8795,0,0,0,0,100,0),
(@PATH,46,1757.252,-4355.759,120.8041,0,0,0,0,100,0),
(@PATH,47,1746.178,-4366.038,124.6221,0,0,0,0,100,0),
(@PATH,48,1738.148,-4378.114,129.0555,0,0,0,0,100,0),
(@PATH,49,1736.964,-4390.267,132.5117,0,0,0,0,100,0),
(@PATH,50,1740.115,-4406.795,135.334,0,0,0,0,100,0),
(@PATH,51,1744.998,-4423.01,136.7945,0,0,0,0,100,0),
(@PATH,52,1751.891,-4437.946,137.3098,0,0,0,0,100,0),
(@PATH,53,1761.145,-4451.333,138.1502,0,0,0,0,100,0),
(@PATH,54,1773.241,-4464.571,139.2234,0,0,0,0,100,0),
(@PATH,55,1785.103,-4475.089,140.1783,0,0,0,0,100,0),
(@PATH,56,1798.931,-4483.318,141.4307,0,0,0,0,100,0),
(@PATH,57,1811.15,-4485.266,141.3097,0,0,0,0,100,0),
(@PATH,58,1825.475,-4481.725,139.1551,0,0,0,0,100,0),
(@PATH,59,1833.307,-4474.778,135.0122,0,0,0,0,100,0),
(@PATH,60,1836.942,-4462.713,129.762,0,0,0,0,100,0),
(@PATH,61,1834.82,-4449.708,126.425,0,0,0,0,100,0),
(@PATH,62,1828.68,-4434.435,123.9729,0,0,0,0,100,0),
(@PATH,63,1819.578,-4420.028,122.4969,0,0,0,0,100,0),
(@PATH,64,1809.853,-4403.466,121.2047,0,0,0,0,100,0),
(@PATH,65,1801.958,-4387.142,119.9052,0,0,0,0,100,0),
(@PATH,66,1794.5,-4370.375,119.1905,0,0,0,0,100,0),
(@PATH,67,1787.333,-4353.754,119.1238,0,0,0,0,100,0),
(@PATH,68,1780.714,-4335.614,119.2794,0,0,0,0,100,0),
(@PATH,69,1775.645,-4317.413,119.6594,0,0,0,0,100,0),
(@PATH,70,1771.494,-4299.163,120.0483,0,0,0,0,100,0),
(@PATH,71,1768.708,-4279.266,119.8779,0,0,0,0,100,0),
(@PATH,72,1767.849,-4263.084,119.0378,0,0,0,0,100,0),
(@PATH,73,1762.163,-4252.079,117.2981,0,0,0,0,100,0);

-- 7.

DELETE FROM `creature_formations` WHERE `leaderGUID`=287084;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(287084, 287084, 0, 0, 2, 0, 0),
(287084, 287082, 6, 90, 2, 0, 0),
(287084, 287083, 6, 270, 2, 0, 0);

SET @NPC := 287084;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1935.921,`position_y`=-4202.151,`position_z`=99.90977 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1935.921,`position_y`=-4202.151,`position_z`=99.90977 WHERE `guid` IN (287082,287083); 
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1935.921,-4202.151,99.90977,0,0,0,0,100,0),
(@PATH,2,1921.545,-4207.911,99.95251,0,0,0,0,100,0),
(@PATH,3,1909.5,-4217.915,99.88344,0,0,0,0,100,0),
(@PATH,4,1898.489,-4230.976,100.0763,0,0,0,0,100,0),
(@PATH,5,1890.768,-4244.812,101.4671,0,0,0,0,100,0),
(@PATH,6,1882.993,-4261.813,103.2667,0,0,0,0,100,0),
(@PATH,7,1877.236,-4277.878,105.2477,0,0,0,0,100,0),
(@PATH,8,1873.785,-4294.484,107.691,0,0,0,0,100,0),
(@PATH,9,1874.276,-4309.689,109.6676,0,0,0,0,100,0),
(@PATH,10,1878.807,-4323.878,111.0572,0,0,0,0,100,0),
(@PATH,11,1887.464,-4331.698,112.9127,0,0,0,0,100,0),
(@PATH,12,1899.838,-4333.164,114.9801,0,0,0,0,100,0),
(@PATH,13,1923.164,-4335.438,116.874,0,0,0,0,100,0),
(@PATH,14,1940.603,-4350.049,118.275,0,0,0,0,100,0),
(@PATH,15,1949.912,-4369.577,119.8247,0,0,0,0,100,0),
(@PATH,16,1952.322,-4390.372,118.8485,0,0,0,0,100,0),
(@PATH,17,1951.392,-4409.454,116.6469,0,0,0,0,100,0),
(@PATH,18,1949.12,-4427.942,114.229,0,0,0,0,100,0),
(@PATH,19,1944.638,-4446.903,111.9787,0,0,0,0,100,0),
(@PATH,20,1937.552,-4465.993,110.0087,0,0,0,0,100,0),
(@PATH,21,1925.565,-4482.845,108.2043,0,0,0,0,100,0),
(@PATH,22,1912.332,-4496.136,107.1636,0,0,0,0,100,0),
(@PATH,23,1897.506,-4507.985,106.8793,0,0,0,0,100,0),
(@PATH,24,1881.884,-4519.595,107.0125,0,0,0,0,100,0),
(@PATH,25,1864.594,-4529.744,106.943,0,0,0,0,100,0),
(@PATH,26,1846.272,-4537.363,106.5945,0,0,0,0,100,0),
(@PATH,27,1826.524,-4541.63,106.3038,0,0,0,0,100,0),
(@PATH,28,1806.477,-4541.843,106.1006,0,0,0,0,100,0),
(@PATH,29,1786.435,-4538.217,106.1396,0,0,0,0,100,0),
(@PATH,30,1767.084,-4528.427,105.936,0,0,0,0,100,0),
(@PATH,31,1752.535,-4516.355,105.5038,0,0,0,0,100,0),
(@PATH,32,1738.496,-4508.19,105.9019,0,0,0,0,100,0),
(@PATH,33,1726.097,-4505.763,108.0605,0,0,0,0,100,0),
(@PATH,34,1713.973,-4510.533,108.0363,0,0,0,0,100,0),
(@PATH,35,1707.527,-4519.758,107.9116,0,0,0,0,100,0),
(@PATH,36,1708.649,-4529.286,108.8271,0,0,0,0,100,0),
(@PATH,37,1717.73,-4535.468,110.8898,0,0,0,0,100,0),
(@PATH,38,1735.099,-4542.322,113.7331,0,0,0,0,100,0),
(@PATH,39,1744.455,-4546.032,115.5387,0,0,0,0,100,0),
(@PATH,40,1767.765,-4554.515,118.6557,0,0,0,0,100,0),
(@PATH,41,1782.335,-4555.451,120.5992,0,0,0,0,100,0),
(@PATH,42,1799.186,-4553.248,121.4981,0,0,0,0,100,0),
(@PATH,43,1817.777,-4549.193,121.4107,0,0,0,0,100,0),
(@PATH,44,1837.463,-4546.765,120.8337,0,0,0,0,100,0),
(@PATH,45,1857.404,-4546.974,119.6974,0,0,0,0,100,0),
(@PATH,46,1877.712,-4552.726,117.6969,0,0,0,0,100,0),
(@PATH,47,1895.652,-4563.852,115.1779,0,0,0,0,100,0),
(@PATH,48,1908.9,-4574.855,112.4627,0,0,0,0,100,0),
(@PATH,49,1920.992,-4580.644,109.1501,0,0,0,0,100,0),
(@PATH,50,1936.721,-4582.809,105.1895,0,0,0,0,100,0),
(@PATH,51,1952.357,-4580.941,101.9664,0,0,0,0,100,0),
(@PATH,52,1966.249,-4575.677,100.6484,0,0,0,0,100,0),
(@PATH,53,1979.888,-4565.699,100.9134,0,0,0,0,100,0),
(@PATH,54,1992.121,-4554.174,101.5216,0,0,0,0,100,0),
(@PATH,55,2004.498,-4540.778,102.9756,0,0,0,0,100,0),
(@PATH,56,2015.598,-4527.351,105.0364,0,0,0,0,100,0),
(@PATH,57,2024.328,-4513.858,107.2172,0,0,0,0,100,0),
(@PATH,58,2033.161,-4497.864,108.5765,0,0,0,0,100,0),
(@PATH,59,2041.593,-4481.994,109.7591,0,0,0,0,100,0),
(@PATH,60,2049.304,-4466.047,110.514,0,0,0,0,100,0),
(@PATH,61,2056.344,-4449.665,110.4499,0,0,0,0,100,0),
(@PATH,62,2062.734,-4432.895,113.1039,0,0,0,0,100,0),
(@PATH,63,2068.121,-4416.631,118.1264,0,0,0,0,100,0),
(@PATH,64,2071.593,-4400.654,122.4922,0,0,0,0,100,0),
(@PATH,65,2073.321,-4384.095,127.1755,0,0,0,0,100,0),
(@PATH,66,2073.756,-4367.256,133.2768,0,0,0,0,100,0),
(@PATH,67,2073.211,-4350.749,139.8226,0,0,0,0,100,0),
(@PATH,68,2071.648,-4335.55,146.7975,0,0,0,0,100,0),
(@PATH,69,2068.221,-4320.453,154.6145,0,0,0,0,100,0),
(@PATH,70,2063.41,-4304.71,162.3728,0,0,0,0,100,0),
(@PATH,71,2057.478,-4288.737,166.9085,0,0,0,0,100,0),
(@PATH,72,2050.302,-4272.94,167.5631,0,0,0,0,100,0),
(@PATH,73,2042.437,-4258.701,162.4632,0,0,0,0,100,0),
(@PATH,74,2033.77,-4245.15,153.701,0,0,0,0,100,0),
(@PATH,75,2025.198,-4234.163,143.13,0,0,0,0,100,0),
(@PATH,76,2016.179,-4224.923,130.5518,0,0,0,0,100,0),
(@PATH,77,2005.462,-4215.757,119.3923,0,0,0,0,100,0),
(@PATH,78,1993.986,-4208.205,110.6679,0,0,0,0,100,0),
(@PATH,79,1980.92,-4203.697,103.6423,0,0,0,0,100,0),
(@PATH,80,1964.031,-4200.561,100.1602,0,0,0,0,100,0),
(@PATH,81,1947.91,-4199.841,99.29764,0,0,0,0,100,0);

-- 8.
DELETE FROM `creature_formations` WHERE `leaderGUID`=286840;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(286840, 286840, 0, 0, 2, 0, 0),
(286840, 286841, 6, 90, 2, 0, 0),
(286840, 286839, 6, 270, 2, 0, 0);

SET @NPC := 286840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1502.716,`position_y`=-4240.965,`position_z`=145.6398 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1502.716,`position_y`=-4240.965,`position_z`=145.6398 WHERE `guid` IN (286841, 286839);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1502.716,-4240.965,145.6398,0,0,0,0,100,0),
(@PATH,2,1521.766,-4229.916,141.0763,0,0,0,0,100,0),
(@PATH,3,1545.081,-4231.815,135.5507,0,0,0,0,100,0),
(@PATH,4,1563.346,-4243.645,129.5311,0,0,0,0,100,0),
(@PATH,5,1573.269,-4262.555,124.0921,0,0,0,0,100,0),
(@PATH,6,1576.224,-4284.094,120.4005,0,0,0,0,100,0),
(@PATH,7,1570.207,-4305.087,119.0906,0,0,0,0,100,0),
(@PATH,8,1559.188,-4322.599,119.3613,0,0,0,0,100,0),
(@PATH,9,1545.175,-4337.73,120.4396,0,0,0,0,100,0),
(@PATH,10,1524.104,-4346.338,122.4728,0,0,0,0,100,0),
(@PATH,11,1503.495,-4348.131,124.1845,0,0,0,0,100,0),
(@PATH,12,1481.973,-4342.198,123.7066,0,0,0,0,100,0),
(@PATH,13,1468.231,-4334.629,121.768,0,0,0,0,100,0),
(@PATH,14,1454.794,-4333.293,119.0893,0,0,0,0,100,0),
(@PATH,15,1447.411,-4338.956,117.3361,0,0,0,0,100,0),
(@PATH,16,1446.31,-4340.785,117.1032,0,0,0,0,100,0),
(@PATH,17,1436.816,-4370.514,114.6013,0,0,0,0,100,0),
(@PATH,18,1432.841,-4387.51,113.1745,0,0,0,0,100,0),
(@PATH,19,1431.701,-4403.535,112.0783,0,0,0,0,100,0),
(@PATH,20,1433.492,-4420.227,111.5698,0,0,0,0,100,0),
(@PATH,21,1438.619,-4434.499,111.1867,0,0,0,0,100,0),
(@PATH,22,1510.604,-4450.885,114.1283,0,0,0,0,100,0),
(@PATH,23,1529.034,-4456.004,116.4663,0,0,0,0,100,0),
(@PATH,24,1548.209,-4462.812,119.3373,0,0,0,0,100,0),
(@PATH,25,1565.712,-4469.323,122.161,0,0,0,0,100,0),
(@PATH,26,1581.662,-4474.407,124.8381,0,0,0,0,100,0),
(@PATH,27,1598.054,-4478.258,127.9857,0,0,0,0,100,0),
(@PATH,28,1614.608,-4481.175,130.5697,0,0,0,0,100,0),
(@PATH,29,1632.461,-4484.498,133.0226,0,0,0,0,100,0),
(@PATH,30,1649.25,-4486.296,134.6477,0,0,0,0,100,0),
(@PATH,31,1666.103,-4484.893,134.2528,0,0,0,0,100,0),
(@PATH,32,1682.979,-4481.126,132.6382,0,0,0,0,100,0),
(@PATH,33,1698.579,-4475.7,131.3756,0,0,0,0,100,0),
(@PATH,34,1711.682,-4467.347,130.5376,0,0,0,0,100,0),
(@PATH,35,1723.328,-4456.544,130.3224,0,0,0,0,100,0),
(@PATH,36,1728.529,-4444.683,130.6103,0,0,0,0,100,0),
(@PATH,37,1728.302,-4431.08,131.018,0,0,0,0,100,0),
(@PATH,38,1722.222,-4416.401,130.8934,0,0,0,0,100,0),
(@PATH,39,1713.429,-4403.267,129.0098,0,0,0,0,100,0),
(@PATH,40,1702.001,-4391.354,127.2167,0,0,0,0,100,0),
(@PATH,41,1688.388,-4380.945,126.0762,0,0,0,0,100,0),
(@PATH,42,1673.425,-4370.66,125.4516,0,0,0,0,100,0),
(@PATH,43,1658.53,-4360.935,125.2306,0,0,0,0,100,0),
(@PATH,44,1643.211,-4352.356,125.62,0,0,0,0,100,0),
(@PATH,45,1627.278,-4345.106,126.6703,0,0,0,0,100,0),
(@PATH,46,1610.744,-4338.946,128.3904,0,0,0,0,100,0),
(@PATH,47,1593.601,-4334.221,131.1824,0,0,0,0,100,0),
(@PATH,48,1576.339,-4330.934,134.6862,0,0,0,0,100,0),
(@PATH,49,1560.145,-4329.077,138.0405,0,0,0,0,100,0),
(@PATH,50,1541.687,-4328.51,141.218,0,0,0,0,100,0),
(@PATH,51,1521.748,-4322.381,144.0511,0,0,0,0,100,0),
(@PATH,52,1504.034,-4312.254,146.3996,0,0,0,0,100,0),
(@PATH,53,1489.946,-4293.953,148.1813,0,0,0,0,100,0),
(@PATH,54,1488.496,-4270.528,148.5301,0,0,0,0,100,0),
(@PATH,55,1495.272,-4250.421,147.2183,0,0,0,0,100,0);

-- 9.

DELETE FROM `creature_formations` WHERE `leaderGUID`=310949;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(310949, 310949, 0, 0, 2, 0, 0),
(310949, 310948, 6, 90, 2, 0, 0),
(310949, 310950, 6, 270, 2, 0, 0);

SET @NPC := 310949;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1782.49,`position_y`=-3924.35,`position_z`=161.7631 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1782.49,`position_y`=-3924.35,`position_z`=161.7631 WHERE `guid` IN (310948,310950);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1782.49,-3924.35,161.7631,0,0,0,0,100,0),
(@PATH,2,1794.615,-3930.264,162.2107,0,0,0,0,100,0),
(@PATH,3,1805.522,-3939.2,162.5445,0,0,0,0,100,0),
(@PATH,4,1814.109,-3950.02,162.6255,0,0,0,0,100,0),
(@PATH,5,1819.634,-3964.029,162.2112,0,0,0,0,100,0),
(@PATH,6,1821.767,-3976.814,161.4032,0,0,0,0,100,0),
(@PATH,7,1823.256,-3989.302,160.1567,0,0,0,0,100,0),
(@PATH,8,1823.344,-3996.523,159.1215,0,0,0,0,100,0),
(@PATH,9,1822.35,-4013.035,156.407,0,0,0,0,100,0),
(@PATH,10,1821.569,-4024.022,154.3276,0,0,0,0,100,0),
(@PATH,11,1820.607,-4035.974,152.0726,0,0,0,0,100,0),
(@PATH,12,1819.253,-4047.867,149.8837,0,0,0,0,100,0),
(@PATH,13,1817.653,-4059.764,147.6697,0,0,0,0,100,0),
(@PATH,14,1816.078,-4071.278,145.5203,0,0,0,0,100,0),
(@PATH,15,1814.492,-4083.109,143.3595,0,0,0,0,100,0),
(@PATH,16,1813.034,-4094.187,141.3412,0,0,0,0,100,0),
(@PATH,17,1811.869,-4105.119,139.3237,0,0,0,0,100,0),
(@PATH,18,1811.04,-4116.399,137.2942,0,0,0,0,100,0),
(@PATH,19,1810.057,-4128.018,135.3994,0,0,0,0,100,0),
(@PATH,20,1809.026,-4139.601,133.7306,0,0,0,0,100,0),
(@PATH,21,1807.282,-4151.96,132.0467,0,0,0,0,100,0),
(@PATH,22,1804.545,-4163.88,130.183,0,0,0,0,100,0),
(@PATH,23,1800.83,-4175.986,128.2061,0,0,0,0,100,0),
(@PATH,24,1795.765,-4187.718,126.1428,0,0,0,0,100,0),
(@PATH,25,1789.341,-4198.814,123.8942,0,0,0,0,100,0),
(@PATH,26,1781.749,-4208.825,122.5092,0,0,0,0,100,0),
(@PATH,27,1772.541,-4218.223,122.2516,0,0,0,0,100,0),
(@PATH,28,1760.82,-4225.95,123.1252,0,0,0,0,100,0),
(@PATH,29,1748.384,-4230.843,125.131,0,0,0,0,100,0),
(@PATH,30,1734.841,-4233.412,127.6087,0,0,0,0,100,0),
(@PATH,31,1720.987,-4232.403,129.9933,0,0,0,0,100,0),
(@PATH,32,1707.399,-4227.351,132.5653,0,0,0,0,100,0),
(@PATH,33,1696.353,-4218.671,135.5142,0,0,0,0,100,0),
(@PATH,34,1687.908,-4208.504,138.8237,0,0,0,0,100,0),
(@PATH,35,1681.215,-4199.081,141.7039,0,0,0,0,100,0),
(@PATH,36,1674.81,-4188.451,143.8387,0,0,0,0,100,0),
(@PATH,37,1669.814,-4177.183,145.5393,0,0,0,0,100,0),
(@PATH,38,1665.539,-4166.708,147.2283,0,0,0,0,100,0),
(@PATH,39,1661.035,-4155.234,149.092,0,0,0,0,100,0),
(@PATH,40,1656.545,-4144.633,150.6522,0,0,0,0,100,0),
(@PATH,41,1651.291,-4134.366,151.5647,0,0,0,0,100,0),
(@PATH,42,1645.717,-4125.248,151.6956,0,0,0,0,100,0),
(@PATH,43,1639.824,-4118.122,151.5813,0,0,0,0,100,0),
(@PATH,44,1632.568,-4112.105,151.3904,0,0,0,0,100,0),
(@PATH,45,1624.246,-4108.173,150.5881,0,0,0,0,100,0),
(@PATH,46,1616.239,-4105.823,149.2457,0,0,0,0,100,0),
(@PATH,47,1606.571,-4105.216,147.3423,0,0,0,0,100,0),
(@PATH,48,1596.181,-4106.263,145.7002,0,0,0,0,100,0),
(@PATH,49,1585.595,-4108.025,144.1347,0,0,0,0,100,0),
(@PATH,50,1573.769,-4110.471,142.4232,0,0,0,0,100,0),
(@PATH,51,1561.757,-4113.431,140.7244,0,0,0,0,100,0),
(@PATH,52,1551.067,-4116.589,139.2582,0,0,0,0,100,0),
(@PATH,53,1540.059,-4120.447,137.8842,0,0,0,0,100,0),
(@PATH,54,1529.393,-4124.763,136.6354,0,0,0,0,100,0),
(@PATH,55,1519.564,-4129.475,135.5119,0,0,0,0,100,0),
(@PATH,56,1510.97,-4134.532,134.5002,0,0,0,0,100,0),
(@PATH,57,1511.471,-4211.023,133.0304,0,0,0,0,100,0),
(@PATH,58,1520.297,-4216.17,131.5602,0,0,0,0,100,0),
(@PATH,59,1529.923,-4220.291,129.6511,0,0,0,0,100,0),
(@PATH,60,1539.637,-4223.272,127.8224,0,0,0,0,100,0),
(@PATH,61,1549.837,-4224.956,125.8669,0,0,0,0,100,0),
(@PATH,62,1560.925,-4225.85,124.0003,0,0,0,0,100,0),
(@PATH,63,1572.205,-4226.376,122.5518,0,0,0,0,100,0),
(@PATH,64,1583.631,-4226.253,121.4491,0,0,0,0,100,0),
(@PATH,65,1595.088,-4225.796,120.686,0,0,0,0,100,0),
(@PATH,66,1607.112,-4225.413,120.1906,0,0,0,0,100,0),
(@PATH,67,1618.298,-4224.938,120.1016,0,0,0,0,100,0),
(@PATH,68,1628.405,-4223.525,121.1098,0,0,0,0,100,0),
(@PATH,69,1638.406,-4220.944,123.5405,0,0,0,0,100,0),
(@PATH,70,1647.107,-4217.338,126.8946,0,0,0,0,100,0),
(@PATH,71,1655.392,-4212.341,131.4094,0,0,0,0,100,0),
(@PATH,72,1661.444,-4206.973,136.0719,0,0,0,0,100,0),
(@PATH,73,1664.806,-4200.668,139.8007,0,0,0,0,100,0),
(@PATH,74,1666.757,-4191.302,142.9762,0,0,0,0,100,0),
(@PATH,75,1667.16,-4182.498,146.2831,0,0,0,0,100,0),
(@PATH,76,1665.696,-4172.579,148.7019,0,0,0,0,100,0),
(@PATH,77,1662.821,-4163.579,149.0816,0,0,0,0,100,0),
(@PATH,78,1658.465,-4152.605,148.7118,0,0,0,0,100,0),
(@PATH,79,1654.092,-4141.396,148.2908,0,0,0,0,100,0),
(@PATH,80,1649.607,-4130.683,147.6877,0,0,0,0,100,0),
(@PATH,81,1644.864,-4118.967,147.0466,0,0,0,0,100,0),
(@PATH,82,1640.849,-4106.851,146.6917,0,0,0,0,100,0),
(@PATH,83,1637.954,-4094.115,146.8069,0,0,0,0,100,0),
(@PATH,84,1636.319,-4081.77,147.2816,0,0,0,0,100,0),
(@PATH,85,1636.172,-4068.982,148.0928,0,0,0,0,100,0),
(@PATH,86,1637.581,-4056.533,149.2318,0,0,0,0,100,0),
(@PATH,87,1640.186,-4044.125,150.7211,0,0,0,0,100,0),
(@PATH,88,1643.415,-4032.162,152.2013,0,0,0,0,100,0),
(@PATH,89,1647.013,-4020.59,153.3602,0,0,0,0,100,0),
(@PATH,90,1651.505,-4008.7,154.246,0,0,0,0,100,0),
(@PATH,91,1656.385,-3997.713,154.9447,0,0,0,0,100,0),
(@PATH,92,1661.678,-3987.166,155.6336,0,0,0,0,100,0),
(@PATH,93,1668.206,-3976.164,156.3449,0,0,0,0,100,0);

-- 10.
DELETE FROM `creature_formations` WHERE `leaderGUID`=286881;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(286881, 286881, 0, 0, 2, 0, 0),
(286881, 286880, 6, 90, 2, 0, 0),
(286881, 286882, 6, 270, 2, 0, 0);

SET @NPC := 286881;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1954.547,`position_y`=-4234.702,`position_z`=124.1495 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1954.547,`position_y`=-4234.702,`position_z`=124.1495 WHERE `guid` IN (286880,286882); 
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1954.547,-4234.702,124.1495,0,0,0,0,100,0),
(@PATH,2,1938.731,-4222.536,124.6159,0,0,0,0,100,0),
(@PATH,3,1919.533,-4212.465,124.177,0,0,0,0,100,0),
(@PATH,4,1895.385,-4214,122.6989,0,0,0,0,100,0),
(@PATH,5,1876.938,-4224.779,120.3522,0,0,0,0,100,0),
(@PATH,6,1866.533,-4234.044,117.2119,0,0,0,0,100,0),
(@PATH,7,1852.104,-4234.643,113.6671,0,0,0,0,100,0),
(@PATH,8,1836.024,-4232.125,110.88,0,0,0,0,100,0),
(@PATH,9,1819.479,-4227.296,109.4104,0,0,0,0,100,0),
(@PATH,10,1802.794,-4221.022,109.1513,0,0,0,0,100,0),
(@PATH,11,1785.994,-4213.458,109.7092,0,0,0,0,100,0),
(@PATH,12,1766.929,-4208.049,110.8175,0,0,0,0,100,0),
(@PATH,13,1746.482,-4205.335,112.2132,0,0,0,0,100,0),
(@PATH,14,1726.945,-4206.582,113.5684,0,0,0,0,100,0),
(@PATH,15,1707.069,-4211.39,114.7465,0,0,0,0,100,0),
(@PATH,16,1688.293,-4219.502,115.4038,0,0,0,0,100,0),
(@PATH,17,1671.592,-4229.898,115.8248,0,0,0,0,100,0),
(@PATH,18,1657.341,-4247.639,116.0683,0,0,0,0,100,0),
(@PATH,19,1651.852,-4267.857,115.8455,0,0,0,0,100,0),
(@PATH,20,1653.63,-4289.913,115.2588,0,0,0,0,100,0),
(@PATH,21,1661.335,-4309.284,114.4485,0,0,0,0,100,0),
(@PATH,22,1672.424,-4326.894,113.238,0,0,0,0,100,0),
(@PATH,23,1680.395,-4339.328,111.3261,0,0,0,0,100,0),
(@PATH,24,1685.079,-4353.114,109.4104,0,0,0,0,100,0),
(@PATH,25,1683.144,-4367.714,109.1087,0,0,0,0,100,0),
(@PATH,26,1677.937,-4384.193,110.3666,0,0,0,0,100,0),
(@PATH,27,1670.855,-4399.245,112.5851,0,0,0,0,100,0),
(@PATH,28,1661.452,-4412.03,114.6408,0,0,0,0,100,0),
(@PATH,29,1649.163,-4423.056,115.8343,0,0,0,0,100,0),
(@PATH,30,1633.621,-4433.305,115.833,0,0,0,0,100,0),
(@PATH,31,1620.871,-4439.209,115.6198,0,0,0,0,100,0),
(@PATH,32,1611.992,-4438.751,115.4828,0,0,0,0,100,0),
(@PATH,33,1589.736,-4436.129,116.2584,0,0,0,0,100,0),
(@PATH,34,1575.32,-4430.159,116.4765,0,0,0,0,100,0),
(@PATH,35,1567.388,-4420.016,116.511,0,0,0,0,100,0),
(@PATH,36,1560.802,-4404.041,116.404,0,0,0,0,100,0),
(@PATH,37,1557.368,-4388.695,116.1834,0,0,0,0,100,0),
(@PATH,38,1559.424,-4375.208,115.5816,0,0,0,0,100,0),
(@PATH,39,1566.398,-4360.625,114.4203,0,0,0,0,100,0),
(@PATH,40,1576.59,-4345.86,112.7528,0,0,0,0,100,0),
(@PATH,41,1587.612,-4331.081,111.0801,0,0,0,0,100,0),
(@PATH,42,1598.586,-4317.407,109.5039,0,0,0,0,100,0),
(@PATH,43,1609.89,-4303.618,107.9324,0,0,0,0,100,0),
(@PATH,44,1621.851,-4289.64,106.7583,0,0,0,0,100,0),
(@PATH,45,1633.929,-4276.34,107.0436,0,0,0,0,100,0),
(@PATH,46,1646.417,-4263.521,107.8411,0,0,0,0,100,0),
(@PATH,47,1659.544,-4251.433,108.543,0,0,0,0,100,0),
(@PATH,48,1672.973,-4240.702,109.2773,0,0,0,0,100,0),
(@PATH,49,1687.775,-4231.006,110.0295,0,0,0,0,100,0),
(@PATH,50,1702.921,-4223.103,110.6569,0,0,0,0,100,0),
(@PATH,51,1718.936,-4218.556,110.7521,0,0,0,0,100,0),
(@PATH,52,1735.746,-4216.64,110.2329,0,0,0,0,100,0),
(@PATH,53,1752.657,-4216.599,108.4848,0,0,0,0,100,0),
(@PATH,54,1769.614,-4218.347,106.0527,0,0,0,0,100,0),
(@PATH,55,1785.691,-4221.831,103.2465,0,0,0,0,100,0),
(@PATH,56,1801.018,-4227.316,100.5446,0,0,0,0,100,0),
(@PATH,57,1817.06,-4234.363,98.36078,0,0,0,0,100,0),
(@PATH,58,1832.369,-4242.525,96.1289,0,0,0,0,100,0),
(@PATH,59,1844.78,-4253.133,93.64021,0,0,0,0,100,0),
(@PATH,60,1855.947,-4266.039,91.12543,0,0,0,0,100,0),
(@PATH,61,1863.85,-4279.255,89.65752,0,0,0,0,100,0),
(@PATH,62,1869.337,-4296.27,89.45457,0,0,0,0,100,0),
(@PATH,63,1877.801,-4314.619,90.4335,0,0,0,0,100,0),
(@PATH,64,1888.224,-4330.828,92.54515,0,0,0,0,100,0),
(@PATH,65,1903.605,-4345.586,95.40073,0,0,0,0,100,0),
(@PATH,66,1922.573,-4354.502,99.31542,0,0,0,0,100,0),
(@PATH,67,1945.698,-4352.438,103.8368,0,0,0,0,100,0),
(@PATH,68,1963.934,-4340.752,108.3923,0,0,0,0,100,0),
(@PATH,69,1976.774,-4323.534,112.2477,0,0,0,0,100,0),
(@PATH,70,1983.794,-4304.261,115.6078,0,0,0,0,100,0),
(@PATH,71,1983.818,-4282.431,118.565,0,0,0,0,100,0),
(@PATH,72,1976.171,-4262.901,121.0682,0,0,0,0,100,0),
(@PATH,73,1965.106,-4246.208,123.0572,0,0,0,0,100,0);

-- 11.
DELETE FROM `creature_formations` WHERE `leaderGUID`=304146;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(304146, 304146, 0, 0, 2, 0, 0),
(304146, 304145, 6, 90, 2, 0, 0),
(304146, 304144, 6, 270, 2, 0, 0);

SET @NPC := 304146;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1791.164,`position_y`=-4047.381,`position_z`=163.5226 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1791.164,`position_y`=-4047.381,`position_z`=163.5226 WHERE `guid` IN (304145,304144); 
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1791.164,-4047.381,163.5226,0,0,0,0,100,0),
(@PATH,2,1796.218,-4031.665,166.3797,0,0,0,0,100,0),
(@PATH,3,1800.952,-4013.518,169.6719,0,0,0,0,100,0),
(@PATH,4,1803.749,-3993.092,173.4559,0,0,0,0,100,0),
(@PATH,5,1803.008,-3971.102,177.6935,0,0,0,0,100,0),
(@PATH,6,1800.251,-3952.967,181.5564,0,0,0,0,100,0),
(@PATH,7,1796.269,-3932.905,185.9146,0,0,0,0,100,0),
(@PATH,8,1790.943,-3911.934,190.5192,0,0,0,0,100,0),
(@PATH,9,1784.228,-3891.916,194.9351,0,0,0,0,100,0),
(@PATH,10,1775.903,-3874.543,198.7298,0,0,0,0,100,0),
(@PATH,11,1764.839,-3861.119,201.5043,0,0,0,0,100,0),
(@PATH,12,1745.044,-3853.358,203.3846,0,0,0,0,100,0),
(@PATH,13,1621.83,-3966.715,195.7863,0,0,0,0,100,0),
(@PATH,14,1634.631,-3983.975,192.0398,0,0,0,0,100,0),
(@PATH,15,1645.231,-3997.282,188.4355,0,0,0,0,100,0),
(@PATH,16,1653.785,-4013.945,184.6452,0,0,0,0,100,0),
(@PATH,17,1660.204,-4028.969,181.2208,0,0,0,0,100,0),
(@PATH,18,1661.558,-4034.377,179.9276,0,0,0,0,100,0),
(@PATH,19,1657.634,-4055.121,176.0111,0,0,0,0,100,0),
(@PATH,20,1647.564,-4066.465,173.3674,0,0,0,0,100,0),
(@PATH,21,1633.951,-4077.444,170.2001,0,0,0,0,100,0),
(@PATH,22,1619.941,-4084.887,165.6421,0,0,0,0,100,0),
(@PATH,23,1603.974,-4092.245,160.9831,0,0,0,0,100,0),
(@PATH,24,1585.698,-4101.966,156.4931,0,0,0,0,100,0),
(@PATH,25,1589.997,-4248.205,138.498,0,0,0,0,100,0),
(@PATH,26,1597.295,-4264.284,136.7392,0,0,0,0,100,0),
(@PATH,27,1603.667,-4281.062,135.2466,0,0,0,0,100,0),
(@PATH,28,1607.494,-4297.545,133.6204,0,0,0,0,100,0),
(@PATH,29,1605.276,-4309.903,131.971,0,0,0,0,100,0),
(@PATH,30,1595.974,-4324.494,130.0394,0,0,0,0,100,0),
(@PATH,31,1583.835,-4338.783,128.5802,0,0,0,0,100,0),
(@PATH,32,1572.195,-4350.58,129.1572,0,0,0,0,100,0),
(@PATH,33,1558.999,-4357.677,132.9003,0,0,0,0,100,0),
(@PATH,34,1544.339,-4364.787,137.6578,0,0,0,0,100,0),
(@PATH,35,1530.304,-4367.112,141.7922,0,0,0,0,100,0),
(@PATH,36,1513.679,-4366.579,145.3613,0,0,0,0,100,0),
(@PATH,37,1494.094,-4365.717,147.7929,0,0,0,0,100,0),
(@PATH,38,1475.913,-4364.107,149.2123,0,0,0,0,100,0),
(@PATH,39,1455.206,-4362.637,150.1821,0,0,0,0,100,0),
(@PATH,40,1435.142,-4363.744,150.2197,0,0,0,0,100,0),
(@PATH,41,1414.539,-4370.334,148.0383,0,0,0,0,100,0),
(@PATH,42,1396.389,-4382.087,144.2717,0,0,0,0,100,0),
(@PATH,43,1384.842,-4399.914,141.8136,0,0,0,0,100,0),
(@PATH,44,1382.475,-4421.819,141.1265,0,0,0,0,100,0),
(@PATH,45,1478.154,-4468.025,143.0791,0,0,0,0,100,0),
(@PATH,46,1493.763,-4461.798,143.0144,0,0,0,0,100,0),
(@PATH,47,1510.166,-4457.322,141.7738,0,0,0,0,100,0),
(@PATH,48,1528.443,-4453.521,140.3201,0,0,0,0,100,0),
(@PATH,49,1544.797,-4450.876,139.034,0,0,0,0,100,0),
(@PATH,50,1562.82,-4448.512,137.7038,0,0,0,0,100,0),
(@PATH,51,1582.761,-4446.183,137.6434,0,0,0,0,100,0),
(@PATH,52,1600.271,-4444.506,139.045,0,0,0,0,100,0),
(@PATH,53,1619.606,-4443.109,141.3056,0,0,0,0,100,0),
(@PATH,54,1639.214,-4441.48,144.2609,0,0,0,0,100,0),
(@PATH,55,1657.649,-4439.066,147.8115,0,0,0,0,100,0),
(@PATH,56,1676.482,-4435.371,153.3135,0,0,0,0,100,0),
(@PATH,57,1694.668,-4430.645,160.4203,0,0,0,0,100,0),
(@PATH,58,1711.401,-4421.387,167.6144,0,0,0,0,100,0),
(@PATH,59,1723.658,-4406.227,173.7595,0,0,0,0,100,0),
(@PATH,60,1731.781,-4387.549,179.7368,0,0,0,0,100,0),
(@PATH,61,1736.594,-4367,185.1796,0,0,0,0,100,0),
(@PATH,62,1737.088,-4346.997,189.1641,0,0,0,0,100,0),
(@PATH,63,1731.531,-4326.529,191.9673,0,0,0,0,100,0),
(@PATH,64,1722.669,-4308.128,193.3809,0,0,0,0,100,0),
(@PATH,65,1712.675,-4291.575,193.0801,0,0,0,0,100,0),
(@PATH,66,1698.438,-4276.086,189.6956,0,0,0,0,100,0),
(@PATH,67,1685.615,-4265.158,184.3505,0,0,0,0,100,0),
(@PATH,68,1672.95,-4254.187,176.6221,0,0,0,0,100,0),
(@PATH,69,1659.988,-4243.784,167.6225,0,0,0,0,100,0),
(@PATH,70,1645.701,-4232.896,160.7243,0,0,0,0,100,0),
(@PATH,71,1630.688,-4221.482,153.8185,0,0,0,0,100,0),
(@PATH,72,1620.927,-4211.261,148.9949,0,0,0,0,100,0),
(@PATH,73,1614.485,-4196.701,146.7963,0,0,0,0,100,0),
(@PATH,74,1613.337,-4183.714,147.0635,0,0,0,0,100,0),
(@PATH,75,1619.386,-4171.917,150.0361,0,0,0,0,100,0),
(@PATH,76,1629.952,-4161.554,153.0461,0,0,0,0,100,0),
(@PATH,77,1645.151,-4153.147,155.631,0,0,0,0,100,0),
(@PATH,78,1660.821,-4145.302,158.1813,0,0,0,0,100,0),
(@PATH,79,1677.75,-4137.908,160.1336,0,0,0,0,100,0),
(@PATH,80,1693.688,-4132.823,158.4026,0,0,0,0,100,0),
(@PATH,81,1712.224,-4128.033,154.4047,0,0,0,0,100,0),
(@PATH,82,1730.092,-4120.557,153.3734,0,0,0,0,100,0),
(@PATH,83,1747.71,-4111.278,154.3697,0,0,0,0,100,0),
(@PATH,84,1764.086,-4097.786,156.1356,0,0,0,0,100,0),
(@PATH,85,1775.402,-4083.184,157.9884,0,0,0,0,100,0),
(@PATH,86,1784.723,-4065.444,160.5013,0,0,0,0,100,0),
(@PATH,87,1791.437,-4046.544,163.6766,0,0,0,0,100,0),
(@PATH,88,1796.566,-4030.513,166.5879,0,0,0,0,100,0),
(@PATH,89,1801.192,-4012.352,169.8851,0,0,0,0,100,0),
(@PATH,90,1803.823,-3991.704,173.7173,0,0,0,0,100,0),
(@PATH,91,1802.859,-3969.946,177.9357,0,0,0,0,100,0);

-- 12.
DELETE FROM `creature_formations` WHERE `leaderGUID`=311106;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311106, 311106, 0, 0, 2, 0, 0),
(311106, 311107, 6, 90, 2, 0, 0),
(311106, 311104, 6, 270, 2, 0, 0);

SET @NPC := 311106;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1697.098,`position_y`=-4390.057,`position_z`=110.2293 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=1697.098,`position_y`=-4390.057,`position_z`=110.2293 WHERE `guid` IN (311107,311104); 
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1697.098,-4390.057,110.2293,0,0,0,0,100,0),
(@PATH,2,1688.756,-4408.252,112.4431,0,0,0,0,100,0),
(@PATH,3,1677.299,-4424.309,114.4888,0,0,0,0,100,0),
(@PATH,4,1662.421,-4438.106,115.8006,0,0,0,0,100,0),
(@PATH,5,1645.054,-4449.778,115.8482,0,0,0,0,100,0),
(@PATH,6,1625.73,-4458.661,115.6599,0,0,0,0,100,0),
(@PATH,7,1611.918,-4458.752,115.4833,0,0,0,0,100,0),
(@PATH,8,1611.918,-4458.752,115.4833,0,0,0,0,100,0),
(@PATH,9,1565.85,-4447.839,116.4646,0,0,0,0,100,0),
(@PATH,10,1550.472,-4430.803,116.5146,0,0,0,0,100,0),
(@PATH,11,1542.495,-4412.264,116.4163,0,0,0,0,100,0),
(@PATH,12,1537.559,-4391.925,116.2197,0,0,0,0,100,0),
(@PATH,13,1539.805,-4370.872,115.6662,0,0,0,0,100,0),
(@PATH,14,1548.302,-4351.927,114.5623,0,0,0,0,100,0),
(@PATH,15,1559.357,-4335.533,112.9272,0,0,0,0,100,0),
(@PATH,16,1570.618,-4320.385,111.2405,0,0,0,0,100,0),
(@PATH,17,1581.968,-4306.128,109.659,0,0,0,0,100,0),
(@PATH,18,1593.274,-4292.332,108.1045,0,0,0,0,100,0),
(@PATH,19,1605.444,-4277.993,106.8167,0,0,0,0,100,0),
(@PATH,20,1617.835,-4264.283,106.9656,0,0,0,0,100,0),
(@PATH,21,1631.234,-4250.388,107.7713,0,0,0,0,100,0),
(@PATH,22,1645.151,-4237.457,108.4792,0,0,0,0,100,0),
(@PATH,23,1659.894,-4225.478,109.212,0,0,0,0,100,0),
(@PATH,24,1676.042,-4214.731,109.9629,0,0,0,0,100,0),
(@PATH,25,1693.436,-4205.419,110.6195,0,0,0,0,100,0),
(@PATH,26,1713.477,-4199.217,110.7672,0,0,0,0,100,0),
(@PATH,27,1732.214,-4196.871,110.3262,0,0,0,0,100,0),
(@PATH,28,1752.193,-4196.528,108.6993,0,0,0,0,100,0),
(@PATH,29,1772.854,-4198.609,106.0112,0,0,0,0,100,0),
(@PATH,30,1791.319,-4202.637,103.2072,0,0,0,0,100,0),
(@PATH,31,1809.205,-4209.068,100.5155,0,0,0,0,100,0),
(@PATH,32,1826.464,-4216.669,98.21891,0,0,0,0,100,0),
(@PATH,33,1844.653,-4226.695,95.97742,0,0,0,0,100,0),
(@PATH,34,1859.821,-4239.905,93.4817,0,0,0,0,100,0),
(@PATH,35,1872.763,-4255.135,90.97318,0,0,0,0,100,0),
(@PATH,36,1882.969,-4273.238,89.60306,0,0,0,0,100,0),
(@PATH,37,1888.627,-4290.87,89.47735,0,0,0,0,100,0),
(@PATH,38,1895.925,-4306.064,90.55748,0,0,0,0,100,0),
(@PATH,39,1904.6,-4319.286,92.70146,0,0,0,0,100,0),
(@PATH,40,1915.564,-4329.522,95.60627,0,0,0,0,100,0),
(@PATH,41,1928.245,-4335.308,99.52489,0,0,0,0,100,0),
(@PATH,42,1938.608,-4333.708,104.1094,0,0,0,0,100,0),
(@PATH,43,1951.109,-4325.374,108.6329,0,0,0,0,100,0),
(@PATH,44,1959.476,-4313.431,112.4713,0,0,0,0,100,0),
(@PATH,45,1964.395,-4299.242,115.8342,0,0,0,0,100,0),
(@PATH,46,1964.013,-4285.485,118.759,0,0,0,0,100,0),
(@PATH,47,1958.188,-4271.719,121.1986,0,0,0,0,100,0),
(@PATH,48,1948.862,-4257.913,123.1436,0,0,0,0,100,0),
(@PATH,49,1937.571,-4246.421,124.3987,0,0,0,0,100,0),
(@PATH,50,1922.871,-4236.132,124.5614,0,0,0,0,100,0),
(@PATH,51,1910.601,-4230.841,123.9003,0,0,0,0,100,0),
(@PATH,52,1898.089,-4234.909,121.9145,0,0,0,0,100,0),
(@PATH,53,1885.57,-4244.55,119.1837,0,0,0,0,100,0),
(@PATH,54,1863.28,-4254.762,115.8188,0,0,0,0,100,0),
(@PATH,55,1843.03,-4253.876,112.4868,0,0,0,0,100,0),
(@PATH,56,1823.948,-4249.617,110.0904,0,0,0,0,100,0),
(@PATH,57,1805.807,-4243.627,109.2054,0,0,0,0,100,0),
(@PATH,58,1788.298,-4236.372,109.2757,0,0,0,0,100,0),
(@PATH,59,1772.822,-4230.178,110.0869,0,0,0,0,100,0),
(@PATH,60,1756.266,-4226.344,111.3374,0,0,0,0,100,0),
(@PATH,61,1740.067,-4225.406,112.7029,0,0,0,0,100,0),
(@PATH,62,1723.609,-4227.502,114.0724,0,0,0,0,100,0),
(@PATH,63,1707.625,-4232.57,115.0328,0,0,0,0,100,0),
(@PATH,64,1691.672,-4240.448,115.5813,0,0,0,0,100,0),
(@PATH,65,1679.758,-4249.527,115.9751,0,0,0,0,100,0),
(@PATH,66,1673.519,-4261.09,116.0333,0,0,0,0,100,0),
(@PATH,67,1671.568,-4275.499,115.6591,0,0,0,0,100,0),
(@PATH,68,1674.839,-4290.318,114.9819,0,0,0,0,100,0),
(@PATH,69,1682.105,-4306.104,114.1077,0,0,0,0,100,0),
(@PATH,70,1692.008,-4319.158,112.6074,0,0,0,0,100,0),
(@PATH,71,1701.481,-4337.39,110.4719,0,0,0,0,100,0);

-- 13.
SET @NPC := 311105;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1660.82, -4283.98, 63.2615, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1620.27, -4290.06, 60.9092, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1589.57, -4323.7, 57.026, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1560.95, -4345.81, 53.1829, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1509.73, -4387.29, 46.3191, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1508.2, -4427.45, 45.8588, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1522.15, -4428.47, 46.2685, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1589.57, -4422.2, 46.6417, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1616.78, -4418.91, 47.4682, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1684.8, -4405.73, 50.3249, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1717.83, -4380.91, 51.5959, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1710.45, -4338.7, 51.337, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1684.04, -4296.48, 58.0137, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1666.85, -4283.53, 58.9361, 0, 0, 0, 0, 100, 0);

-- 14.
SET @NPC := 311041;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1685.8, -4109.97, 89.4076, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1715.42, -4091.83, 85.8596, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1742.82, -4058.34, 83.0513, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1754.99, -4017.08, 90.8648, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1752.87, -3975.17, 89.2434, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1733.46, -3938.65, 88.8604, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1706.13, -3939.88, 88.283, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1709.8, -3968.48, 85.2167, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1727.49, -4010.25, 84.3052, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1734.95, -4040.12, 82.376, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1713.95, -4065.05, 82.1854, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1676.29, -4087.99, 76.8193, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1646.84, -4105.68, 75.9196, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1610.64, -4121.87, 74.9112, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 1566.51, -4136.79, 76.181, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 1549.57, -4140.85, 76.817, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 1503.23, -4159.52, 77.8546, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 1515.04, -4184.18, 78.218, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 1543.61, -4195.47, 77.6548, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 1576.25, -4196.88, 75.6522, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 1589.45, -4187.76, 74.5151, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 1603.68, -4162.3, 73.1248, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 1621.38, -4141.27, 73.6877, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 1650.98, -4123.75, 75.31, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 1670.35, -4113.5, 78.7438, 0, 0, 0, 0, 100, 0);

-- 15.
SET @NPC := 287018;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1495.565,`position_y`=-4168.035,`position_z`=51.73763 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1495.565,-4168.035,51.73763,0,0,0,0,100,0),
(@PATH,2,1495.287,-4168.088,51.8574,0,0,0,0,100,0),
(@PATH,3,1494.037,-4166.588,51.8574,0,0,0,0,100,0),
(@PATH,4,1493.603,-4164.904,51.87238,0,0,0,0,100,0),
(@PATH,5,1494.23,-4162.97,51.45435,0.5934119,5000,0,0,100,0),
(@PATH,6,1493.085,-4165.53,51.83562,0,0,0,0,100,0),
(@PATH,7,1494.724,-4168.007,51.93468,0,0,0,0,100,0),
(@PATH,8,1495.974,-4174.757,52.18468,0,0,0,0,100,0),
(@PATH,9,1499.974,-4176.757,52.18468,0,0,0,0,100,0),
(@PATH,10,1500.254,-4176.932,52.13823,0,0,0,0,100,0),
(@PATH,11,1501.504,-4175.682,51.88823,0,0,0,0,100,0),
(@PATH,12,1501.751,-4175.708,51.69862,0,0,0,0,100,0),
(@PATH,13,1503.501,-4175.208,51.44862,0,0,0,0,100,0),
(@PATH,14,1503.955,-4171.56,51.6193,0,0,0,0,100,0),
(@PATH,15,1502.705,-4169.31,51.3693,0,0,0,0,100,0),
(@PATH,16,1500.205,-4169.81,51.6193,0,0,0,0,100,0),
(@PATH,17,1498.947,-4174.157,51.77612,0,0,0,0,100,0),
(@PATH,18,1498.819,-4173.981,51.74632,0,0,0,0,100,0),
(@PATH,19,1497.819,-4171.231,51.74632,0,0,0,0,100,0),
(@PATH,20,1499.29,-4168.38,51.16976,0,0,0,0,100,0),
(@PATH,21,1499.29,-4168.38,51.16976,3.996804,5000,0,0,100,0);

-- 16.
SET @NPC := 287015;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1478.185,`position_y`=-4174.237,`position_z`=83.73706 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1478.185,-4174.237,83.73706,0,0,0,0,100,0),
(@PATH,2,1478.935,-4179.987,83.73706,0,0,0,0,100,0),
(@PATH,3,1482.412,-4180.579,83.71821,0,0,0,0,100,0),
(@PATH,4,1492.339,-4184.873,83.66711,0,0,0,0,100,0),
(@PATH,5,1492.155,-4184.79,83.43674,0,0,0,0,100,0),
(@PATH,6,1492.242,-4184.591,83.70753,0,0,0,0,100,0),
(@PATH,7,1482.186,-4180.211,83.72748,0,0,0,0,100,0),
(@PATH,8,1478.936,-4179.961,83.72748,0,0,0,0,100,0),
(@PATH,9,1477.954,-4174.076,83.73439,0,0,0,0,100,0),
(@PATH,10,1476.739,-4154.171,83.73648,0,0,0,0,100,0),
(@PATH,11,1480.489,-4150.921,84.23648,0,0,0,0,100,0),
(@PATH,12,1481.489,-4150.921,84.48648,0,0,0,0,100,0),
(@PATH,13,1479.989,-4150.671,83.73648,0,0,0,0,100,0),
(@PATH,14,1478.538,-4147.028,83.73347,0,0,0,0,100,0),
(@PATH,15,1482.538,-4147.528,83.73347,0,0,0,0,100,0),
(@PATH,16,1483.538,-4149.028,84.23347,0,0,0,0,100,0),
(@PATH,17,1500.656,-4133.007,83.74146,0,0,0,0,100,0),
(@PATH,18,1501.906,-4137.007,83.74146,0,0,0,0,100,0),
(@PATH,19,1503.241,-4136.472,83.70921,0,0,0,0,100,0),
(@PATH,20,1500.507,-4133.066,83.73335,0,0,0,0,100,0),
(@PATH,21,1501.507,-4137.316,83.73335,0,0,0,0,100,0),
(@PATH,22,1478.489,-4147.164,83.73515,0,0,0,0,100,0),
(@PATH,23,1480.489,-4150.664,83.73515,0,0,0,0,100,0),
(@PATH,24,1476.526,-4154.406,83.7347,0,0,0,0,100,0);

-- 17.
SET @NPC := 286946;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1561.884,`position_y`=-4098.291,`position_z`=120.8239 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1561.884,-4098.291,120.8239,0,0,0,0,100,0),
(@PATH,2,1563.884,-4097.541,120.5739,0,0,0,0,100,0),
(@PATH,3,1569.634,-4095.541,120.0739,0,0,0,0,100,0),
(@PATH,4,1580.634,-4091.541,120.0739,0,0,0,0,100,0),
(@PATH,5,1561.673,-4098.669,120.9767,0,0,0,0,100,0),
(@PATH,6,1554.173,-4101.419,119.9767,0,0,0,0,100,0),
(@PATH,7,1550.173,-4102.919,119.7267,0,0,0,0,100,0),
(@PATH,8,1544.173,-4105.169,120.9767,0,0,0,0,100,0),
(@PATH,9,1542.173,-4105.919,120.9767,0,0,0,0,100,0),
(@PATH,10,1539.778,-4107.183,121.6618,0,0,0,0,100,0),
(@PATH,11,1536.778,-4108.183,122.9118,0,0,0,0,100,0),
(@PATH,12,1532.278,-4110.183,123.6618,0,0,0,0,100,0),
(@PATH,13,1531.028,-4110.683,123.6618,0,0,0,0,100,0),
(@PATH,14,1523.528,-4113.683,123.6618,0,0,0,0,100,0),
(@PATH,15,1517.778,-4115.933,121.4118,0,0,0,0,100,0),
(@PATH,16,1513.261,-4117.953,120.2626,0,0,0,0,100,0),
(@PATH,17,1507.261,-4120.703,118.7626,0,0,0,0,100,0),
(@PATH,18,1497.511,-4124.953,118.0126,0,0,0,0,100,0),
(@PATH,19,1492.011,-4127.453,118.7626,0,0,0,0,100,0),
(@PATH,20,1486.741,-4129.933,119.621,0,0,0,0,100,0),
(@PATH,21,1485.491,-4131.183,119.621,0,0,0,0,100,0),
(@PATH,22,1479.991,-4136.683,119.621,0,0,0,0,100,0),
(@PATH,23,1473.491,-4142.683,120.121,0,0,0,0,100,0),
(@PATH,24,1473.25,-4143,120.3613,0,0,0,0,100,0),
(@PATH,25,1471.5,-4144.75,120.6113,0,0,0,0,100,0),
(@PATH,26,1469.5,-4150,120.1113,0,0,0,0,100,0),
(@PATH,27,1468.5,-4154,120.3613,0,0,0,0,100,0),
(@PATH,28,1467.75,-4156,120.1113,0,0,0,0,100,0),
(@PATH,29,1464.75,-4164.75,121.3613,0,0,0,0,100,0),
(@PATH,30,1467.632,-4156.08,120.2714,0,0,0,0,100,0),
(@PATH,31,1468.382,-4153.83,120.2714,0,0,0,0,100,0),
(@PATH,32,1469.632,-4150.08,120.2714,0,0,0,0,100,0),
(@PATH,33,1471.79,-4144.445,120.5612,0,0,0,0,100,0),
(@PATH,34,1473.54,-4142.695,120.3112,0,0,0,0,100,0),
(@PATH,35,1479.79,-4136.695,119.8112,0,0,0,0,100,0),
(@PATH,36,1485.29,-4131.195,119.8112,0,0,0,0,100,0),
(@PATH,37,1487.065,-4129.587,119.8208,0,0,0,0,100,0),
(@PATH,38,1492.065,-4127.337,118.8208,0,0,0,0,100,0),
(@PATH,39,1497.565,-4124.837,118.0708,0,0,0,0,100,0),
(@PATH,40,1507.315,-4120.587,118.8208,0,0,0,0,100,0);

DELETE FROM `creature` WHERE `guid`  IN (304149, 304150,286832,304129,304147,311124,286931);

-- 18.

DELETE FROM `creature_formations` WHERE `leaderGUID`=310854;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(310854, 310854, 0, 0, 2, 0, 0),
(310854, 310855, 3, 90, 2, 0, 0);

SET @NPC := 310854;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1540.968,`position_y`=-4331.818,`position_z`=88.63969 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1540.968,-4331.818,88.63969,0,0,0,0,100,0),
(@PATH,2,1542.468,-4330.818,88.63969,0,0,0,0,100,0),
(@PATH,3,1546.718,-4325.818,89.38969,0,0,0,0,100,0),
(@PATH,4,1549.468,-4322.818,89.13969,0,0,0,0,100,0),
(@PATH,5,1552.968,-4318.568,89.38969,0,0,0,0,100,0),
(@PATH,6,1556.468,-4314.318,90.13969,0,0,0,0,100,0),
(@PATH,7,1561.468,-4308.568,90.13969,0,0,0,0,100,0),
(@PATH,8,1563.607,-4305.764,91.05544,0,0,0,0,100,0),
(@PATH,9,1566.357,-4300.764,91.55544,0,0,0,0,100,0),
(@PATH,10,1568.357,-4296.264,91.55544,0,0,0,0,100,0),
(@PATH,11,1571.107,-4291.264,92.05544,0,0,0,0,100,0),
(@PATH,12,1574.774,-4283.906,93.51273,0,0,0,0,100,0),
(@PATH,13,1574.024,-4280.156,94.51273,0,0,0,0,100,0),
(@PATH,14,1573.024,-4275.406,95.26273,0,0,0,0,100,0),
(@PATH,15,1571.274,-4266.656,96.76273,0,0,0,0,100,0),
(@PATH,16,1571.402,-4266.708,96.79311,0,0,0,0,100,0),
(@PATH,17,1573.152,-4275.458,95.29311,0,0,0,0,100,0),
(@PATH,18,1574.152,-4280.208,94.54311,0,0,0,0,100,0),
(@PATH,19,1574.652,-4282.958,93.79311,0,0,0,0,100,0),
(@PATH,20,1574.587,-4283.181,93.51605,0,0,0,0,100,0),
(@PATH,21,1574.837,-4283.931,93.26605,0,0,0,0,100,0),
(@PATH,22,1571.087,-4291.181,92.26605,0,0,0,0,100,0),
(@PATH,23,1568.587,-4296.431,91.51605,0,0,0,0,100,0),
(@PATH,24,1566.337,-4300.681,92.01605,0,0,0,0,100,0),
(@PATH,25,1563.554,-4305.809,90.76807,0,0,0,0,100,0),
(@PATH,26,1561.304,-4308.309,90.26807,0,0,0,0,100,0),
(@PATH,27,1556.554,-4314.059,90.01807,0,0,0,0,100,0),
(@PATH,28,1553.054,-4318.309,89.76807,0,0,0,0,100,0),
(@PATH,29,1549.304,-4322.809,89.26807,0,0,0,0,100,0),
(@PATH,30,1546.804,-4325.809,89.76807,0,0,0,0,100,0),
(@PATH,31,1542.275,-4331.172,88.49124,0,0,0,0,100,0),
(@PATH,32,1540.775,-4332.172,88.24124,0,0,0,0,100,0),
(@PATH,33,1537.525,-4333.922,87.49124,0,0,0,0,100,0),
(@PATH,34,1530.275,-4338.172,86.74124,0,0,0,0,100,0),
(@PATH,35,1524.969,-4341.395,84.82468,0,0,0,0,100,0),
(@PATH,36,1521.469,-4342.395,83.82468,0,0,0,0,100,0),
(@PATH,37,1515.719,-4343.645,82.32468,0,0,0,0,100,0),
(@PATH,38,1511.219,-4344.895,80.57468,0,0,0,0,100,0),
(@PATH,39,1508.448,-4345.555,79.73019,0,0,0,0,100,0),
(@PATH,40,1503.698,-4345.555,79.23019,0,0,0,0,100,0),
(@PATH,41,1498.198,-4345.555,78.98019,0,0,0,0,100,0),
(@PATH,42,1498.259,-4345.869,78.97261,0,0,0,0,100,0),
(@PATH,43,1503.509,-4345.869,78.97261,0,0,0,0,100,0),
(@PATH,44,1508.849,-4345.683,80.20703,0,0,0,0,100,0),
(@PATH,45,1511.099,-4344.933,80.70703,0,0,0,0,100,0),
(@PATH,46,1515.599,-4343.683,81.95703,0,0,0,0,100,0),
(@PATH,47,1521.349,-4342.433,83.70703,0,0,0,0,100,0),
(@PATH,48,1521.522,-4342.098,84.08778,0,0,0,0,100,0),
(@PATH,49,1525.022,-4341.348,85.08778,0,0,0,0,100,0),
(@PATH,50,1530.272,-4338.098,86.58778,0,0,0,0,100,0),
(@PATH,51,1537.522,-4333.848,87.33778,0,0,0,0,100,0);

-- 19.
DELETE FROM `creature_formations` WHERE `leaderGUID`=311121;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311121, 311121, 0, 0, 2, 0, 0),
-- 
(311121, 311119, 3, 90, 2, 0, 0),
(311121, 311122, 6, 90, 2, 0, 0),
(311121, 311123, 9, 90, 2, 0, 0),
-- 
(311121, 311120, 3, 270, 2, 0, 0),
(311121, 311118, 6, 270, 2, 0, 0),
(311121, 311117, 9, 270, 2, 0, 0);

SET @NPC := 311121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1807.01,`position_y`=-4316.48,`position_z`=149.3002 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,17719,0,1,0, '95230');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1807.01,-4316.48,149.3002,0,0,0,0,100,0),
(@PATH,2,1808.774,-4313.723,173.6998,0,0,0,0,100,0),
(@PATH,3,1807.063,-4316.488,187.2079,0,0,0,0,100,0),
(@PATH,4,1807.063,-4316.488,187.2079,0,0,0,0,100,0),
(@PATH,5,1807.481,-4316.267,184.353,0.9250245,5000,0,0,100,0),
(@PATH,6,1808.33,-4314.263,187.2079,0,0,0,0,100,0),
(@PATH,7,1793.559,-4316.036,178.2978,0,0,0,0,100,0),
(@PATH,8,1777.785,-4306.187,179.0402,0,0,0,0,100,0),
(@PATH,9,1761.671,-4295.139,180.0481,0,0,0,0,100,0),
(@PATH,10,1746.95,-4283.836,180.8696,0,0,0,0,100,0),
(@PATH,11,1732.525,-4271.096,182.3055,0,0,0,0,100,0),
(@PATH,12,1718.8,-4257.377,184.3837,0,0,0,0,100,0),
(@PATH,13,1706.131,-4244.092,186.1173,0,0,0,0,100,0),
(@PATH,14,1694.591,-4230.988,187.1132,0,0,0,0,100,0),
(@PATH,15,1683.094,-4217.781,187.2331,0,0,0,0,100,0),
(@PATH,16,1670.549,-4203.002,186.8739,0,0,0,0,100,0),
(@PATH,17,1658.949,-4187.574,186.0255,0,0,0,0,100,0),
(@PATH,18,1648.444,-4171.864,184.7251,0,0,0,0,100,0),
(@PATH,19,1638.348,-4158.23,183.2735,0,0,0,0,100,0),
(@PATH,20,1627.186,-4145.286,181.4723,0,0,0,0,100,0),
(@PATH,21,1614.735,-4135.304,179.651,0,0,0,0,100,0),
(@PATH,22,1600.054,-4127.3,178.2775,0,0,0,0,100,0),
(@PATH,23,1583.386,-4120.385,176.9991,0,0,0,0,100,0),
(@PATH,24,1567.839,-4116.856,176.2117,0,0,0,0,100,0),
(@PATH,25,1552.111,-4116.935,176.1456,0,0,0,0,100,0),
(@PATH,26,1537.198,-4120.831,176.3604,0,0,0,0,100,0),
(@PATH,27,1524.506,-4128.325,176.0686,0,0,0,0,100,0),
(@PATH,28,1510.056,-4140.798,176.0435,0,0,0,0,100,0),
(@PATH,29,1497.115,-4153.093,178.0401,0,0,0,0,100,0),
(@PATH,30,1485.643,-4166.016,181.9767,0,0,0,0,100,0),
(@PATH,31,1472.987,-4179.955,186.6292,0,0,0,0,100,0),
(@PATH,32,1458.547,-4192.708,191.2159,0,0,0,0,100,0),
(@PATH,33,1442.81,-4204.699,196.5309,0,0,0,0,100,0),
(@PATH,34,1428.188,-4214.711,200.2226,0,0,0,0,100,0),
(@PATH,35,1409.727,-4223.685,198.7708,0,0,0,0,100,0),
(@PATH,36,1397.06,-4228.111,190.9477,0,0,0,0,100,0),
(@PATH,37,1384.933,-4234.856,182.4714,0,0,0,0,100,0),
(@PATH,38,1374.461,-4243.07,170.9508,0,0,0,0,100,0),
(@PATH,39,1365.93,-4251.694,158.6469,0,0,0,0,100,0),
(@PATH,40,1357.721,-4261.561,145.0761,0,0,0,0,100,0),
(@PATH,41,1350.721,-4272.154,132.928,0,0,0,0,100,0),
(@PATH,42,1344.517,-4284.101,121.6979,0,0,0,0,100,0),
(@PATH,43,1339.773,-4296.786,111.3554,0,0,0,0,100,0),
(@PATH,44,1335.96,-4311.421,101.9002,0,0,0,0,100,0),
(@PATH,45,1333.623,-4326.046,93.31429,0,0,0,0,100,0),
(@PATH,46,1334.957,-4337.731,84.69461,0,0,0,0,100,0),
(@PATH,47,1343.626,-4350.635,75.67818,0,0,0,0,100,0),
(@PATH,48,1354.871,-4363.032,68.21049,0,0,0,0,100,0),
(@PATH,49,1358.317,-4367.091,66.27425,0,0,0,0,100,0),
(@PATH,50,1356.423,-4364.788,67.5598,3.263766,5000,0,0,100,0),
(@PATH,51,1351.521,-4382.996,66.27425,0,0,0,0,100,0),
(@PATH,52,1351.521,-4382.996,66.27425,0,0,0,0,100,0),
(@PATH,53,1351.521,-4382.996,66.27425,-2.865702,5000,0,0,100,0),
(@PATH,54,1355.414,-4397.424,64.36366,0,0,0,0,100,0),
(@PATH,55,1349.781,-4417.869,63.44082,0,0,0,0,100,0),
(@PATH,56,1343.145,-4434.903,63.21791,0,0,0,0,100,0),
(@PATH,57,1336.118,-4452.121,63.88697,0,0,0,0,100,0),
(@PATH,58,1329.525,-4469.378,65.8797,0,0,0,0,100,0),
(@PATH,59,1322.943,-4486.343,68.81236,0,0,0,0,100,0),
(@PATH,60,1318.146,-4502.357,72.51958,0,0,0,0,100,0),
(@PATH,61,1316.105,-4518.2,77.22173,0,0,0,0,100,0),
(@PATH,62,1316.302,-4533.891,82.95803,0,0,0,0,100,0),
(@PATH,63,1319.12,-4549.391,88.91561,0,0,0,0,100,0),
(@PATH,64,1324.333,-4563.656,94.31775,0,0,0,0,100,0),
(@PATH,65,1331.916,-4578.44,99.80263,0,0,0,0,100,0),
(@PATH,66,1341.016,-4593.465,105.1026,0,0,0,0,100,0),
(@PATH,67,1350.623,-4607.153,109.9065,0,0,0,0,100,0),
(@PATH,68,1362.2,-4621.035,114.5719,0,0,0,0,100,0),
(@PATH,69,1373.953,-4635.165,118.6817,0,0,0,0,100,0),
(@PATH,70,1384.709,-4650.624,122.1362,0,0,0,0,100,0),
(@PATH,71,1394.193,-4666.75,124.7447,0,0,0,0,100,0),
(@PATH,72,1402.022,-4683.615,126.4022,0,0,0,0,100,0),
(@PATH,73,1408.258,-4700.825,127.3785,0,0,0,0,100,0),
(@PATH,74,1413.426,-4718.913,127.7007,0,0,0,0,100,0),
(@PATH,75,1416.899,-4738.973,127.4302,0,0,0,0,100,0),
(@PATH,76,1418.046,-4757.724,126.6843,0,0,0,0,100,0),
(@PATH,77,1417.918,-4777.43,125.4663,0,0,0,0,100,0),
(@PATH,78,1416.332,-4797.274,124.0066,0,0,0,0,100,0),
(@PATH,79,1412.751,-4816.214,122.5238,0,0,0,0,100,0),
(@PATH,80,1404.375,-4835.041,121.0357,0,0,0,0,100,0),
(@PATH,81,1394.703,-4850.106,119.4216,0,0,0,0,100,0),
(@PATH,82,1387.365,-4864.996,117.1234,0,0,0,0,100,0),
(@PATH,83,1382.297,-4881.407,114.7568,0,0,0,0,100,0),
(@PATH,84,1377.801,-4899.102,112.0526,0,0,0,0,100,0),
(@PATH,85,1375.401,-4915.914,108.7919,0,0,0,0,100,0),
(@PATH,86,1376.218,-4930.03,104.6527,0,0,0,0,100,0),
(@PATH,87,1381.309,-4943.936,99.20206,0,0,0,0,100,0),
(@PATH,88,1389.932,-4958.036,92.84589,0,0,0,0,100,0),
(@PATH,89,1399.953,-4970.539,86.23571,0,0,0,0,100,0),
(@PATH,90,1410.403,-4980.592,78.61923,0,0,0,0,100,0),
(@PATH,91,1424.887,-4988.536,68.9007,0,0,0,0,100,0),
(@PATH,92,1438.818,-4994.247,60.62519,0,0,0,0,100,0),
(@PATH,93,1443.614,-4996.463,58.34653,0,0,0,0,100,0),
(@PATH,94,1441.035,-4995.255,59.76055,1.658063,5000,0,0,100,0),
(@PATH,95,1428.884,-5006.125,58.34653,0,0,0,0,100,0),
(@PATH,96,1428.884,-5006.125,58.34653,0,0,0,0,100,0),
(@PATH,97,1428.884,-5006.125,58.34653,1.63541,5000,0,0,100,0),
(@PATH,98,1426.727,-4984.576,59.54522,0,0,0,0,100,0),
(@PATH,99,1427.424,-4964.031,61.14178,0,0,0,0,100,0),
(@PATH,100,1429.404,-4946.52,62.64558,0,0,0,0,100,0),
(@PATH,101,1431.497,-4927.274,64.41466,0,0,0,0,100,0),
(@PATH,102,1432.58,-4908.179,66.33176,0,0,0,0,100,0),
(@PATH,103,1431.662,-4890.863,68.31383,0,0,0,0,100,0),
(@PATH,104,1428.842,-4874.077,70.41498,0,0,0,0,100,0),
(@PATH,105,1424.707,-4857.552,72.62909,0,0,0,0,100,0),
(@PATH,106,1419.345,-4840.807,74.93507,0,0,0,0,100,0),
(@PATH,107,1412.903,-4823.7,77.27052,0,0,0,0,100,0),
(@PATH,108,1406.075,-4808.176,79.39149,0,0,0,0,100,0),
(@PATH,109,1397.786,-4793.342,81.37319,0,0,0,0,100,0),
(@PATH,110,1388.236,-4777.8,83.39078,0,0,0,0,100,0),
(@PATH,111,1378.527,-4761.554,85.47807,0,0,0,0,100,0),
(@PATH,112,1369.615,-4744.184,87.71409,0,0,0,0,100,0),
(@PATH,113,1362.757,-4726.517,90.05842,0,0,0,0,100,0),
(@PATH,114,1357.021,-4708.558,92.51503,0,0,0,0,100,0),
(@PATH,115,1352.01,-4690.008,95.09456,0,0,0,0,100,0),
(@PATH,116,1347.843,-4671.299,97.76492,0,0,0,0,100,0),
(@PATH,117,1344.698,-4653.094,100.4613,0,0,0,0,100,0),
(@PATH,118,1342.698,-4635.618,103.1828,0,0,0,0,100,0),
(@PATH,119,1341.788,-4615.435,106.5755,0,0,0,0,100,0),
(@PATH,120,1342.429,-4595.523,110.1277,0,0,0,0,100,0),
(@PATH,121,1344.715,-4576.87,113.5843,0,0,0,0,100,0),
(@PATH,122,1348.764,-4559.769,116.8085,0,0,0,0,100,0),
(@PATH,123,1356.282,-4541.801,120.0888,0,0,0,0,100,0),
(@PATH,124,1367.829,-4525.43,123.0104,0,0,0,0,100,0),
(@PATH,125,1381.503,-4512.091,125.9577,0,0,0,0,100,0),
(@PATH,126,1396.188,-4500.717,129.6965,0,0,0,0,100,0),
(@PATH,127,1411.983,-4491.121,134.1022,0,0,0,0,100,0),
(@PATH,128,1429.146,-4483.078,139.0746,0,0,0,0,100,0),
(@PATH,129,1446.704,-4476.547,144.2854,0,0,0,0,100,0),
(@PATH,130,1463.978,-4471.508,149.4841,0,0,0,0,100,0),
(@PATH,131,1481.431,-4468.143,154.7737,0,0,0,0,100,0),
(@PATH,132,1498.786,-4466.564,160.1712,0,0,0,0,100,0),
(@PATH,133,1517.528,-4466.153,166.1545,0,0,0,0,100,0),
(@PATH,134,1534.442,-4466.233,171.8325,0,0,0,0,100,0),
(@PATH,135,1551.467,-4466.555,178.006,0,0,0,0,100,0),
(@PATH,136,1569.594,-4467.434,184.4545,0,0,0,0,100,0),
(@PATH,137,1588.226,-4469.213,190.4113,0,0,0,0,100,0),
(@PATH,138,1606.836,-4472.281,195.1004,0,0,0,0,100,0),
(@PATH,139,1624.713,-4476.79,198.0858,0,0,0,0,100,0),
(@PATH,140,1642.351,-4482.453,200.0069,0,0,0,0,100,0),
(@PATH,141,1659.788,-4489.217,200.9092,0,0,0,0,100,0),
(@PATH,142,1677.164,-4497.134,200.7925,0,0,0,0,100,0),
(@PATH,143,1694.01,-4505.979,199.6644,0,0,0,0,100,0),
(@PATH,144,1709.751,-4515.468,197.2912,0,0,0,0,100,0),
(@PATH,145,1724.935,-4525.876,193.4211,0,0,0,0,100,0),
(@PATH,146,1739.924,-4537.181,188.6904,0,0,0,0,100,0),
(@PATH,147,1754.19,-4548.751,183.9597,0,0,0,0,100,0),
(@PATH,148,1767.79,-4560.417,179.8924,0,0,0,0,100,0),
(@PATH,149,1781.463,-4572.727,176.9339,0,0,0,0,100,0),
(@PATH,150,1795.488,-4586.251,174.6125,0,0,0,0,100,0),
(@PATH,151,1808.908,-4600.187,172.8913,0,0,0,0,100,0),
(@PATH,152,1821.34,-4614.191,171.7502,0,0,0,0,100,0),
(@PATH,153,1832.189,-4627.673,171.1791,0,0,0,0,100,0),
(@PATH,154,1843.175,-4643.834,171.4573,0,0,0,0,100,0),
(@PATH,155,1851.177,-4659.663,173.1657,0,0,0,0,100,0),
(@PATH,156,1857.922,-4676.054,175.525,0,0,0,0,100,0),
(@PATH,157,1865.265,-4693.154,177.2991,0,0,0,0,100,0),
(@PATH,158,1872.05,-4709.729,178.376,0,0,0,0,100,0),
(@PATH,159,1879.111,-4727.632,179.427,0,0,0,0,100,0),
(@PATH,160,1886.306,-4745.599,180.6753,0,0,0,0,100,0),
(@PATH,161,1893.448,-4762.291,182.3388,0,0,0,0,100,0),
(@PATH,162,1901.142,-4778.182,184.9192,0,0,0,0,100,0),
(@PATH,163,1909.677,-4794.671,188.8966,0,0,0,0,100,0),
(@PATH,164,1918.158,-4809.278,193.5147,0,0,0,0,100,0),
(@PATH,165,1927.136,-4822.047,198.2432,0,0,0,0,100,0),
(@PATH,166,1937.749,-4833.822,202.9114,0,0,0,0,100,0),
(@PATH,167,1950.384,-4844.948,208.1431,0,0,0,0,100,0),
(@PATH,168,1963.895,-4854.318,213.2049,0,0,0,0,100,0),
(@PATH,169,1977.87,-4861.619,217.3819,0,0,0,0,100,0),
(@PATH,170,1992.485,-4866.707,220.1422,0,0,0,0,100,0),
(@PATH,171,2007.539,-4869.385,221.5735,0,0,0,0,100,0),
(@PATH,172,2025.376,-4870.392,222.6461,0,0,0,0,100,0),
(@PATH,173,2044.167,-4870.353,224.0206,0,0,0,0,100,0),
(@PATH,174,2061.388,-4869.485,225.2248,0,0,0,0,100,0),
(@PATH,175,2080.476,-4867.871,226.4804,0,0,0,0,100,0),
(@PATH,176,2099.469,-4865.734,227.7914,0,0,0,0,100,0),
(@PATH,177,2117.285,-4863.222,229.2233,0,0,0,0,100,0),
(@PATH,178,2134.274,-4860.052,231.0907,0,0,0,0,100,0),
(@PATH,179,2150.96,-4855.128,233.8257,0,0,0,0,100,0),
(@PATH,180,2185.812,-4843.068,239.4897,0,0,0,0,100,0),
(@PATH,181,2201.066,-4837.948,241.4729,0,0,0,0,100,0),
(@PATH,182,2218.384,-4831.886,243.5535,0,0,0,0,100,0),
(@PATH,183,2230.87,-4827.673,245.0291,0,0,0,0,100,0),
(@PATH,184,2256.073,-4820.334,248.0988,0,0,0,0,100,0),
(@PATH,185,2274.964,-4816.626,250.5945,0,0,0,0,100,0),
(@PATH,186,2288.184,-4815.473,252.5606,0,0,0,0,100,0),
(@PATH,187,2313.565,-4816.311,257.1127,0,0,0,0,100,0),
(@PATH,188,2332.012,-4818.446,260.7191,0,0,0,0,100,0),
(@PATH,189,2349.727,-4820.781,264.0513,0,0,0,0,100,0),
(@PATH,190,2361.119,-4821.99,265.9361,0,0,0,0,100,0),
(@PATH,191,2378.392,-4822.709,268.2498,0,0,0,0,100,0),
(@PATH,192,2395.672,-4822.382,270.5723,0,0,0,0,100,0),
(@PATH,193,2418.667,-4821.696,272.4164,0,0,0,0,100,0),
(@PATH,194,2437.808,-4822.147,271.8976,0,0,0,0,100,0),
(@PATH,195,2451.392,-4823.351,270.2963,0,0,0,0,100,0),
(@PATH,196,2475.574,-4826.919,264.9532,0,0,0,0,100,0),
(@PATH,197,2495.615,-4830.523,259.2421,0,0,0,0,100,0),
(@PATH,198,2515.663,-4834.421,252.9475,0,0,0,0,100,0),
(@PATH,199,2528.312,-4836.965,248.804,0,0,0,0,100,0),
(@PATH,200,2548.086,-4840.947,242.2778,0,0,0,0,100,0),
(@PATH,201,2553.753,-4842.025,240.4903,0,0,0,0,100,0),
(@PATH,202,2553.753,-4842.025,240.4903,0,0,0,0,100,0),
(@PATH,203,2553.753,-4842.025,240.4903,0,0,0,0,100,0),
(@PATH,204,2530.35,-4847.412,246.7449,0,0,0,0,100,0),
(@PATH,205,2519.405,-4838.286,250.5472,0,0,0,0,100,0),
(@PATH,206,2505.105,-4824.995,254.0947,0,0,0,0,100,0),
(@PATH,207,2489.081,-4808.324,257.0263,0,0,0,0,100,0),
(@PATH,208,2480.348,-4799.167,258.2751,0,0,0,0,100,0),
(@PATH,209,2462.016,-4781.071,260.1203,0,0,0,0,100,0),
(@PATH,210,2449.802,-4770.005,260.6873,0,0,0,0,100,0),
(@PATH,211,2437.105,-4758.915,260.8073,0,0,0,0,100,0),
(@PATH,212,2423.625,-4747.453,260.7435,0,0,0,0,100,0),
(@PATH,213,2408.885,-4735.125,260.747,0,0,0,0,100,0),
(@PATH,214,2393.352,-4722.233,261.0336,0,0,0,0,100,0),
(@PATH,215,2380.273,-4711.536,261.4713,0,0,0,0,100,0),
(@PATH,216,2365.73,-4699.78,262.0394,0,0,0,0,100,0),
(@PATH,217,2350.47,-4687.515,262.669,0,0,0,0,100,0),
(@PATH,218,2335.104,-4675.178,263.2961,0,0,0,0,100,0),
(@PATH,219,2320.177,-4663.15,263.8583,0,0,0,0,100,0),
(@PATH,220,2306.352,-4651.905,264.2885,0,0,0,0,100,0),
(@PATH,221,2292.482,-4640.46,264.5583,0,0,0,0,100,0),
(@PATH,222,2277.301,-4628.1,264.7198,0,0,0,0,100,0),
(@PATH,223,2263.924,-4617.124,264.676,0,0,0,0,100,0),
(@PATH,224,2251.102,-4605.994,264.3789,0,0,0,0,100,0),
(@PATH,225,2237.733,-4593.284,263.7799,0,0,0,0,100,0),
(@PATH,226,2225.097,-4580.236,262.826,0,0,0,0,100,0),
(@PATH,227,2216.42,-4570.856,261.8818,0,0,0,0,100,0),
(@PATH,228,2199.343,-4551.523,259.7386,0,0,0,0,100,0),
(@PATH,229,2187.011,-4536.791,258.2495,0,0,0,0,100,0),
(@PATH,230,2175.961,-4522.861,257.2587,0,0,0,0,100,0),
(@PATH,231,2164.849,-4507.772,257.1758,0,0,0,0,100,0),
(@PATH,232,2154.261,-4491.937,258.6173,0,0,0,0,100,0),
(@PATH,233,2145.396,-4476.492,260.5597,0,0,0,0,100,0),
(@PATH,234,2137.43,-4459.933,261.691,0,0,0,0,100,0),
(@PATH,235,2130.769,-4443.319,261.4178,0,0,0,0,100,0),
(@PATH,236,2125.71,-4427.077,260.7786,0,0,0,0,100,0),
(@PATH,237,2121.078,-4409.912,259.4034,0,0,0,0,100,0),
(@PATH,238,2116.066,-4391.729,256.8839,0,0,0,0,100,0),
(@PATH,239,2110.218,-4373.027,253.1455,0,0,0,0,100,0),
(@PATH,240,2105.732,-4357.7,249.3848,0,0,0,0,100,0),
(@PATH,241,2101.378,-4341.67,244.8545,0,0,0,0,100,0),
(@PATH,242,2096.695,-4324.966,239.7186,0,0,0,0,100,0),
(@PATH,243,2091.386,-4308.121,234.2892,0,0,0,0,100,0),
(@PATH,244,2085.056,-4291.282,228.7592,0,0,0,0,100,0),
(@PATH,245,2077.344,-4274.687,223.3504,0,0,0,0,100,0),
(@PATH,246,2069.002,-4260.209,218.6541,0,0,0,0,100,0),
(@PATH,247,2059.842,-4246.49,213.6165,0,0,0,0,100,0),
(@PATH,248,2049.46,-4232.339,208.0533,0,0,0,0,100,0),
(@PATH,249,2038.229,-4218.037,202.3802,0,0,0,0,100,0),
(@PATH,250,2026.325,-4203.612,196.9223,0,0,0,0,100,0),
(@PATH,251,2014.406,-4189.677,192.223,0,0,0,0,100,0),
(@PATH,252,2002.499,-4176.084,188.5589,0,0,0,0,100,0),
(@PATH,253,1991.118,-4163.265,186.4,0,0,0,0,100,0),
(@PATH,254,1980.133,-4150.911,186.1717,0,0,0,0,100,0),
(@PATH,255,1967.656,-4137.147,189.1347,0,0,0,0,100,0),
(@PATH,256,1955.593,-4124.359,195.033,0,0,0,0,100,0),
(@PATH,257,1943.927,-4112.546,202.8083,0,0,0,0,100,0),
(@PATH,258,1932.446,-4101.496,211.4719,0,0,0,0,100,0),
(@PATH,259,1920.958,-4091.026,220.0315,0,0,0,0,100,0),
(@PATH,260,1909.449,-4081.107,227.3716,0,0,0,0,100,0),
(@PATH,261,1896.112,-4070.187,233.6728,0,0,0,0,100,0),
(@PATH,262,1881.711,-4058.82,239.9983,0,0,0,0,100,0),
(@PATH,263,1867.177,-4048.092,245.9405,0,0,0,0,100,0),
(@PATH,264,1853.032,-4038.735,251.0147,0,0,0,0,100,0),
(@PATH,265,1839.338,-4031.089,254.9502,0,0,0,0,100,0),
(@PATH,266,1825.944,-4025.421,257.4778,0,0,0,0,100,0),
(@PATH,267,1809.285,-4021.613,257.9171,0,0,0,0,100,0),
(@PATH,268,1791.939,-4020.598,255.979,0,0,0,0,100,0),
(@PATH,269,1774.828,-4021.412,252.9435,0,0,0,0,100,0),
(@PATH,270,1758.35,-4022.942,250.0472,0,0,0,0,100,0),
(@PATH,271,1740.679,-4025.196,246.935,0,0,0,0,100,0),
(@PATH,272,1725.025,-4029.035,243.3118,0,0,0,0,100,0),
(@PATH,273,1710.132,-4034.917,239.6053,0,0,0,0,100,0),
(@PATH,274,1695.517,-4042.831,236.3092,0,0,0,0,100,0),
(@PATH,275,1680.435,-4053.033,233.0617,0,0,0,0,100,0),
(@PATH,276,1666.971,-4064.274,229.8546,0,0,0,0,100,0),
(@PATH,277,1657.59,-4075.063,226.6826,0,0,0,0,100,0),
(@PATH,278,1651.78,-4088.253,223.0625,0,0,0,0,100,0),
(@PATH,279,1650.519,-4102.87,219.3593,0,0,0,0,100,0),
(@PATH,280,1652.254,-4117.496,215.2804,0,0,0,0,100,0),
(@PATH,281,1656.852,-4132.258,210.9501,0,0,0,0,100,0),
(@PATH,282,1664.544,-4148.375,206.2254,0,0,0,0,100,0),
(@PATH,283,1673.097,-4162.16,202.0511,0,0,0,0,100,0),
(@PATH,284,1683.237,-4175.781,197.7508,0,0,0,0,100,0),
(@PATH,285,1694.797,-4189.847,193.4776,0,0,0,0,100,0),
(@PATH,286,1707.06,-4203.938,189.7254,0,0,0,0,100,0),
(@PATH,287,1718.838,-4216.889,186.956,0,0,0,0,100,0),
(@PATH,288,1730.887,-4229.196,184.764,0,0,0,0,100,0),
(@PATH,289,1743.695,-4241.563,183.2065,0,0,0,0,100,0),
(@PATH,290,1757.407,-4254.418,182.3882,0,0,0,0,100,0),
(@PATH,291,1770.998,-4266.899,182.4858,0,0,0,0,100,0),
(@PATH,292,1786.442,-4280.654,183.4359,0,0,0,0,100,0),
(@PATH,293,1801.985,-4294.292,184.7827,0,0,0,0,100,0),
(@PATH,294,1815.332,-4305.937,186.0635,0,0,0,0,100,0),
(@PATH,295,1823.079,-4312.73,186.7368,0,0,0,0,100,0),
(@PATH,296,1823.079,-4312.73,186.7368,0,0,0,0,100,0),
(@PATH,297,1807.846,-4325.581,162.9674,0,0,0,0,100,0),
(@PATH,298,1807.432,-4324.88,147.9789,0,0,0,0,100,0),
(@PATH,299,1807.792,-4325.482,131.6825,0,0,0,0,100,0),
(@PATH,300,1807.792,-4325.482,131.6825,0,0,0,0,100,0),
(@PATH,301,1824.376,-4325.779,131.6825,0,0,0,0,100,0),
(@PATH,302,1824.376,-4325.779,131.6825,0,0,0,0,100,0),
(@PATH,303,1824.376,-4325.779,131.6825,0,0,0,0,100,0),
(@PATH,304,1824.376,-4325.779,131.6825,-1.985682,5000,0,0,100,0);
-- DB/Pathing: Orgrimmar - Complete 'Roof' of that City
DELETE FROM `creature` WHERE `guid` IN (286799,311126,311127,311125,310878,310924,310922,287257,287256,287255,287254,287253,287252,286859,286860,286861,287247,287247,287247);
SET @NPC :=  287152;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1582.58,`position_y`=-4349.62,`position_z`=21.153 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1582.58,-4349.62,21.153,4.886922,5000,0,0,100,0),
(@PATH,2,1600.605,-4349.375,21.38635,0,0,0,0,100,0),
(@PATH,3,1611.13,-4341.13,21.1197,6.021386,5000,0,0,100,0),
(@PATH,4,1616.5,-4333.325,21.36925,0,0,0,0,100,0),
(@PATH,5,1624.5,-4321.325,21.36925,0,0,0,0,100,0),
(@PATH,6,1632.25,-4305.1,21.23968,0,0,0,0,100,0),
(@PATH,7,1629.665,-4306.11,21.44634,0,0,0,0,100,0),
(@PATH,8,1602.665,-4326.36,21.19634,0,0,0,0,100,0),
(@PATH,9,1596.415,-4344.11,21.19634,0,0,0,0,100,0),
(@PATH,10,1590.165,-4349.86,21.19634,0,0,0,0,100,0),
(@PATH,11,1582.58,-4349.62,21.153,4.886922,5000,0,0,100,0);

SET @NPC := 286970;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1476.08, -4180.59, 117.13, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1482.02, -4186.54, 116.033, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1487.52, -4190.36, 114.569, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1497.14, -4195.27, 112.281, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1508.99, -4200.23, 110.343, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1520.51, -4206.08, 107.232, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1525.82, -4210.04, 105.508, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1534.7, -4218.01, 103.453, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1536.9, -4220.32, 103.043, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1539.57, -4223.04, 102.539, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1534.9, -4217.83, 103.365, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1526.71, -4208.91, 104.874, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1519.39, -4203.54, 107.45, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1509.23, -4199.49, 110.198, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 1500.51, -4196.89, 112.015, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 1490.85, -4194.18, 113.845, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 1481.42, -4189.16, 116.687, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 1475.95, -4182.8, 118.048, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 1470.11, -4173.52, 118.75, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 1465.99, -4163.74, 120.533, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 1467.34, -4154.41, 120.164, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 1475.24, -4143.78, 119.214, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 1479.99, -4139.64, 118.711, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 1485.24, -4135.36, 118.437, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 1475.67, -4144.95, 118.799, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 1468.32, -4153.7, 119.871, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 1465.33, -4164.05, 120.831, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 1468.88, -4172.37, 119.494, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 1472.61, -4176.74, 118.048, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=286884;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(286884, 286884, 0, 0, 2, 0, 0),
(286884, 286883, 3, 270, 2, 0, 0);

SET @NPC := 286884;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1660.113,`position_y`=-4057.619,`position_z`=127.4508 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1660.113,-4057.619,127.4508,0,0,0,0,100,0),
(@PATH,2,1666.363,-4054.119,128.2008,0,0,0,0,100,0),
(@PATH,3,1671.363,-4051.119,128.7008,0,0,0,0,100,0),
(@PATH,4,1674.363,-4049.369,129.2008,0,0,0,0,100,0),
(@PATH,5,1684.635,-4043.444,129.964,0,0,0,0,100,0),
(@PATH,6,1685.635,-4041.694,130.214,0,0,0,0,100,0),
(@PATH,7,1686.635,-4039.694,130.214,0,0,0,0,100,0),
(@PATH,8,1691.385,-4031.944,130.964,0,0,0,0,100,0),
(@PATH,9,1691.274,-4031.574,131.1229,0,0,0,0,100,0),
(@PATH,10,1692.774,-4029.074,131.3729,0,0,0,0,100,0),
(@PATH,11,1691.524,-4019.824,131.8729,0,0,0,0,100,0),
(@PATH,12,1691.274,-4018.074,131.8729,0,0,0,0,100,0),
(@PATH,13,1689.731,-4006.081,133.3835,0,0,0,0,100,0),
(@PATH,14,1689.231,-4005.081,133.6335,0,0,0,0,100,0),
(@PATH,15,1678.981,-3990.581,134.6335,0,0,0,0,100,0),
(@PATH,16,1677.231,-3988.081,134.8835,0,0,0,0,100,0),
(@PATH,17,1677.292,-3988.13,134.791,0,0,0,0,100,0),
(@PATH,18,1679.042,-3990.63,134.791,0,0,0,0,100,0),
(@PATH,19,1689.292,-4005.13,133.541,0,0,0,0,100,0),
(@PATH,20,1690.179,-4006.287,133.306,0,0,0,0,100,0),
(@PATH,21,1691.429,-4017.787,132.056,0,0,0,0,100,0),
(@PATH,22,1691.679,-4019.787,132.056,0,0,0,0,100,0),
(@PATH,23,1692.822,-4029.267,131.171,0,0,0,0,100,0),
(@PATH,24,1691.322,-4032.017,130.921,0,0,0,0,100,0),
(@PATH,25,1686.822,-4039.767,130.421,0,0,0,0,100,0),
(@PATH,26,1685.572,-4041.517,130.171,0,0,0,0,100,0),
(@PATH,27,1684.373,-4043.729,129.8849,0,0,0,0,100,0),
(@PATH,28,1674.373,-4049.479,129.3849,0,0,0,0,100,0),
(@PATH,29,1671.623,-4050.979,128.6349,0,0,0,0,100,0),
(@PATH,30,1666.373,-4054.229,128.3849,0,0,0,0,100,0),
(@PATH,31,1659.931,-4057.989,127.2083,0,0,0,0,100,0),
(@PATH,32,1645.931,-4063.239,125.2083,0,0,0,0,100,0),
(@PATH,33,1616.931,-4074.489,122.9583,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=286865;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(286865, 286865, 0, 0, 2, 0, 0),
(286865, 286864, 3, 270, 2, 0, 0);

SET @NPC := 286865;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1795.847,`position_y`=-3951.65,`position_z`=134.2392 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1795.847,-3951.65,134.2392,0,0,0,0,100,0),
(@PATH,2,1797.097,-3955.9,133.7392,0,0,0,0,100,0),
(@PATH,3,1804.347,-3982.65,131.4892,0,0,0,0,100,0),
(@PATH,4,1807.597,-3994.9,129.9892,0,0,0,0,100,0),
(@PATH,5,1807.899,-3995.059,129.708,0,0,0,0,100,0),
(@PATH,6,1808.399,-3997.059,129.458,0,0,0,0,100,0),
(@PATH,7,1809.149,-4021.809,126.958,0,0,0,0,100,0),
(@PATH,8,1809.138,-4021.836,126.9843,0,0,0,0,100,0),
(@PATH,9,1808.162,-3996.775,129.8237,0,0,0,0,100,0),
(@PATH,10,1807.662,-3994.775,130.0737,0,0,0,0,100,0),
(@PATH,11,1804.162,-3982.775,131.5737,0,0,0,0,100,0),
(@PATH,12,1797.162,-3956.025,133.8237,0,0,0,0,100,0),
(@PATH,13,1795.725,-3951.347,134.4281,0,0,0,0,100,0),
(@PATH,14,1789.975,-3933.597,135.9281,0,0,0,0,100,0),
(@PATH,15,1789.783,-3933.488,136.0831,0,0,0,0,100,0),
(@PATH,16,1795.825,-3951.583,134.2462,0,0,0,0,100,0);

SET @NPC := 286830;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1772.84,-4379.08,101.764,0,0,0,0,100,0),
(@PATH,2,1778.14,-4375.21,102.587,0,0,0,0,100,0),
(@PATH,3,1783.33,-4366.61,102.764,0,0,0,0,100,0),
(@PATH,4,1784.04,-4357.92,102.56,0,0,0,0,100,0),
(@PATH,5,1778.65,-4350.98,102.823,0,0,0,0,100,0),
(@PATH,6,1769.76,-4339.34,101.95,0,0,0,0,100,0),
(@PATH,7,1763.85,-4331.95,101.841,0,0,0,0,100,0),
(@PATH,8,1758.97,-4324.76,103.488,0,0,0,0,100,0),
(@PATH,9,1752.18,-4313.64,101.994,0,0,0,0,100,0),
(@PATH,10,1744.05,-4300.96,102.606,0,0,0,0,100,0),
(@PATH,11,1733.95,-4288.79,101.52,0,0,0,0,100,0),
(@PATH,12,1724.84,-4280.11,103.078,0,0,0,0,100,0),
(@PATH,13,1716.3,-4274.71,102.123,0,0,0,0,100,0),
(@PATH,14,1713.24,-4268.93,101.724,0,0,0,0,100,0),
(@PATH,15,1712.84,-4262.2,101.724,0,0,0,0,100,0),
(@PATH,16,1707.99,-4257.8,101.725,0,0,0,0,100,0),
(@PATH,17,1701.07,-4258.26,101.724,0,0,0,0,100,0),
(@PATH,18,1697.36,-4259.23,101.724,0,0,0,0,100,0),
(@PATH,19,1697.36,-4259.23,101.724,0,0,0,0,100,0),
(@PATH,20,1697.36,-4259.23,101.724,2.460914,5000,0,0,100,0),
(@PATH,21,1697.6,-4263.405,101.994,0,0,0,0,100,0),
(@PATH,22,1697.85,-4269.155,101.994,0,0,0,0,100,0),
(@PATH,23,1701.85,-4274.405,101.994,0,0,0,0,100,0),
(@PATH,24,1708.85,-4273.655,101.994,0,0,0,0,100,0),
(@PATH,25,1714.35,-4273.905,102.244,0,0,0,0,100,0),
(@PATH,26,1728.6,-4286.405,101.744,0,0,0,0,100,0),
(@PATH,27,1739.85,-4299.905,103.244,0,0,0,0,100,0),
(@PATH,28,1749.6,-4314.655,102.244,0,0,0,0,100,0),
(@PATH,29,1756.35,-4324.905,103.744,0,0,0,0,100,0),
(@PATH,30,1763.6,-4335.655,101.994,0,0,0,0,100,0),
(@PATH,31,1769.6,-4343.405,102.244,0,0,0,0,100,0),
(@PATH,32,1774.6,-4349.905,103.244,0,0,0,0,100,0),
(@PATH,33,1781.6,-4359.155,102.994,0,0,0,0,100,0),
(@PATH,34,1782.6,-4364.405,102.994,0,0,0,0,100,0),
(@PATH,35,1778.35,-4371.405,102.994,0,0,0,0,100,0);

SET @NPC := 310962;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1811.399,`position_y`=-4351.669,`position_z`=102.7625 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1811.399,-4351.669,102.7625,0,0,0,0,100,0),
(@PATH,2,1811.438,-4352.036,102.6394,0,0,0,0,100,0),
(@PATH,3,1811.688,-4354.036,102.8894,0,0,0,0,100,0),
(@PATH,4,1813.71,-4353.58,102.7915,1.710423,5000,0,0,100,0),
(@PATH,5,1811.535,-4353.56,102.8446,0,0,0,0,100,0),
(@PATH,6,1811.109,-4349.543,102.6839,0,0,0,0,100,0),
(@PATH,7,1811.817,-4345.384,102.5037,0,0,0,0,100,0),
(@PATH,8,1812.567,-4343.384,102.5037,0,0,0,0,100,0),
(@PATH,9,1812.931,-4343.214,102.3251,0,0,0,0,100,0),
(@PATH,10,1813.431,-4341.714,102.3251,0,0,0,0,100,0),
(@PATH,11,1813.431,-4340.214,102.3251,0,0,0,0,100,0),
(@PATH,12,1813.41,-4339.825,102.2658,0,0,0,0,100,0),
(@PATH,13,1813.176,-4340.16,102.3639,0,0,0,0,100,0),
(@PATH,14,1812.926,-4341.16,102.3639,0,0,0,0,100,0),
(@PATH,15,1812.426,-4342.16,102.3639,0,0,0,0,100,0),
(@PATH,16,1811.674,-4343.991,102.2712,0,0,0,0,100,0),
(@PATH,17,1811.29,-4348.261,102.6309,0,0,0,0,100,0),
(@PATH,18,1811.399,-4351.914,102.7623,0,0,0,0,100,0);

SET @NPC := 310977;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1821.185,`position_y`=-4383.9,`position_z`=103.6216 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1821.185,-4383.9,103.6216,0,0,0,0,100,0),
(@PATH,2,1816.625,-4386.891,103.3357,0,0,0,0,100,0),
(@PATH,3,1808.012,-4386.565,103.1792,0,0,0,0,100,0),
(@PATH,4,1806.262,-4386.565,103.1792,0,0,0,0,100,0),
(@PATH,5,1801.39,-4386.062,103.4776,0,0,0,0,100,0),
(@PATH,6,1802.4,-4387.6,103.4435,0,0,0,0,100,0),
(@PATH,7,1802.54,-4387.46,103.6431,0,0,0,0,100,0),
(@PATH,8,1807.706,-4388.32,103.0164,0,0,0,0,100,0),
(@PATH,9,1812.151,-4388.348,103.0451,0,0,0,0,100,0),
(@PATH,10,1817.385,-4387.065,103.3176,0,0,0,0,100,0),
(@PATH,11,1821.385,-4384.065,103.5676,0,0,0,0,100,0);

SET @NPC := 310982;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1855.755,`position_y`=-4406.695,`position_z`=104.059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1855.755,-4406.695,104.059,0,0,0,0,100,0),
(@PATH,2,1854.255,-4404.445,104.059,0,0,0,0,100,0),
(@PATH,3,1850.755,-4401.195,104.059,0,0,0,0,100,0),
(@PATH,4,1846.755,-4397.195,104.059,0,0,0,0,100,0),
(@PATH,5,1842.505,-4393.695,104.059,0,0,0,0,100,0),
(@PATH,6,1840.005,-4391.945,104.059,0,0,0,0,100,0),
(@PATH,7,1838.255,-4392.445,103.809,0,0,0,0,100,0),
(@PATH,8,1837.255,-4394.195,103.809,0,0,0,0,100,0),
(@PATH,9,1838.755,-4397.695,103.809,0,0,0,0,100,0),
(@PATH,10,1839.505,-4398.195,103.809,0,0,0,0,100,0),
(@PATH,11,1838.505,-4395.945,103.809,0,0,0,0,100,0),
(@PATH,12,1838.505,-4393.945,103.809,0,0,0,0,100,0),
(@PATH,13,1839.755,-4392.445,104.059,0,0,0,0,100,0),
(@PATH,14,1842.005,-4393.445,104.059,0,0,0,0,100,0),
(@PATH,15,1846.005,-4396.695,104.059,0,0,0,0,100,0),
(@PATH,16,1851.005,-4401.945,104.059,0,0,0,0,100,0),
(@PATH,17,1854.707,-4407.343,103.955,0,0,0,0,100,0),
(@PATH,18,1855.27,-4408.17,103.955,0,0,0,0,100,0),
(@PATH,19,1855.69,-4406.9,103.954,0,0,0,0,100,0);

SET @NPC := 286504;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2058.88,`position_y`=-4730.48,`position_z`=27.774 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2058.88,-4730.48,27.774,2.635447,5000,0,0,100,0),
(@PATH,2,2058.83,-4734.94,27.96475,0,0,0,0,100,0),
(@PATH,3,2060.08,-4742.19,27.96475,0,0,0,0,100,0),
(@PATH,4,2061.58,-4750.44,27.96475,0,0,0,0,100,0),
(@PATH,5,2062.58,-4762.19,27.71475,0,0,0,0,100,0),
(@PATH,6,2062.33,-4774.69,27.71475,0,0,0,0,100,0),
(@PATH,7,2067.08,-4785.44,27.71475,0,0,0,0,100,0),
(@PATH,8,2069.08,-4794.44,27.71475,0,0,0,0,100,0),
(@PATH,9,2063.58,-4803.69,27.71475,0,0,0,0,100,0),
(@PATH,10,2057.58,-4814.94,27.71475,0,0,0,0,100,0),
(@PATH,11,2053.08,-4823.44,27.71475,0,0,0,0,100,0),
(@PATH,12,2053.33,-4824.69,27.71475,0,0,0,0,100,0),
(@PATH,13,2058.83,-4818.44,27.71475,0,0,0,0,100,0),
(@PATH,14,2062.58,-4810.69,27.71475,0,0,0,0,100,0),
(@PATH,15,2066.58,-4805.44,27.71475,0,0,0,0,100,0),
(@PATH,16,2069.83,-4799.94,27.71475,0,0,0,0,100,0),
(@PATH,17,2071.58,-4793.69,27.71475,0,0,0,0,100,0),
(@PATH,18,2069.58,-4785.19,27.71475,0,0,0,0,100,0),
(@PATH,19,2066.33,-4777.19,27.71475,0,0,0,0,100,0),
(@PATH,20,2064.83,-4767.44,27.71475,0,0,0,0,100,0),
(@PATH,21,2064.58,-4758.44,27.71475,0,0,0,0,100,0),
(@PATH,22,2063.83,-4748.94,27.71475,0,0,0,0,100,0),
(@PATH,23,2060.83,-4742.19,27.96475,0,0,0,0,100,0),
(@PATH,24,2058.83,-4734.19,27.96475,0,0,0,0,100,0);

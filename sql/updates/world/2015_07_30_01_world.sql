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

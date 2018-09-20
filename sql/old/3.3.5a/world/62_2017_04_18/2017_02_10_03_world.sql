-- -------------------------------------
-- Mountain Gronns in Nagrand Entry: 19201
-- -------------------------------------

-- The first two Gronn's are weird because they don't have a path back from their last waypoint. 
-- They do random movement for a few minutes and then they just walk straight through the mountains back to the starting point.
-- Example:
-- (@GUID,66,-1086.546,8910.48,102.3874,0,0,0,0,0,0,0,0,0,0,0,0,0),
-- (@GUID,67,-1190.294,8772.655,44.03177,0,0,0,0,0,0,0,0,0,0,0,0,0),
-- I assume that Blizzard's intention was that they should despawn after reaching the last waypoint, so that's what I did.

SET @MAXGUID := 947; 
SET @SCRIPTID := 6873300; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 1, 35, 1, 8, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 60, 18, 1000, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 68733;
SET @PATH := @NPC * 10;
SET @POINT := 0;
UPDATE `creature` SET `position_x`=-1190.294,`position_y`=8772.655,`position_z`=44.03177 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH,@POINT := @POINT + 1,-1190.294,8772.655,44.03177,0,0),
(@PATH,@POINT := @POINT + 1,-1203.012,8742.168,42.7664, 0,0),
(@PATH,@POINT := @POINT + 1,-1199.56,8724.674,41.17319, 0,0),
(@PATH,@POINT := @POINT + 1,-1198.571,8721.961,40.50022,0,0),
(@PATH,@POINT := @POINT + 1,-1145.681519,8681.539063,43.931034,0,0),
(@PATH,@POINT := @POINT + 1,-1135.424,8685.5,48.49122,0,0),
(@PATH,@POINT := @POINT + 1,-1106.267,8698.869,61.74326,0,0),
(@PATH,@POINT := @POINT + 1,-1089.461,8709.732,68.98933,0,0),
(@PATH,@POINT := @POINT + 1,-1080.214,8724.287,77.56756,0,0),
(@PATH,@POINT := @POINT + 1,-1076.087,8730.615,80.32574,0,0),
(@PATH,@POINT := @POINT + 1,-1073.906,8743.322,83.13339,0,0),
(@PATH,@POINT := @POINT + 1,-1071.587,8769.987,88.95515,0,0),
(@PATH,@POINT := @POINT + 1,-1069.364,8792.963,93.90515,0,0),
(@PATH,@POINT := @POINT + 1,-1073.472,8810.984,98.12231,0,0),
(@PATH,@POINT := @POINT + 1,-1081.081,8848.842,102.7461,0,0),
(@PATH,@POINT := @POINT + 1,-1082.776,8856.875,102.9781,0,0),
(@PATH,@POINT := @POINT + 1,-1086.328735,8893.722656,102.045715,0,0),
(@PATH,@POINT := @POINT + 1,-1055.303467,8927.958984,100.954239,65000,@SCRIPTID);

SET @NPC := 68734;
SET @PATH := @NPC * 10;
SET @POINT := 0;
UPDATE `creature` SET `position_x`=-984.8678,`position_y`=8734.932,`position_z`=132.8936 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`) VALUES
(@PATH,@POINT := @POINT + 1,-984.8678,8734.932,132.8936,0,0),
(@PATH,@POINT := @POINT + 1,-999.9858,8740.252,125.7903,0,0),
(@PATH,@POINT := @POINT + 1,-1007.913,8747.668,121.9,   0,0),
(@PATH,@POINT := @POINT + 1,-1018.669983,8761.624023,118.182793,0,0),
(@PATH,@POINT := @POINT + 1,-1021.87,8774.891,117.6102 ,0,0),
(@PATH,@POINT := @POINT + 1,-1028.338,8786.554,114.4703,0,0),
(@PATH,@POINT := @POINT + 1,-1043.908,8807.875,110.2811,0,0),
(@PATH,@POINT := @POINT + 1,-1056.555,8834.715,107.1923,0,0),
(@PATH,@POINT := @POINT + 1,-1047.57,8848.311,116.0382 ,0,0),
(@PATH,@POINT := @POINT + 1,-1033.689,8858.738,125.4172,0,0),
(@PATH,@POINT := @POINT + 1,-1014.58,8869.018,133.7491 ,0,0),
(@PATH,@POINT := @POINT + 1,-995.608,8868.662,139.3823 ,0,0),
(@PATH,@POINT := @POINT + 1,-974.8796,8879.833,145.5816,0,0),
(@PATH,@POINT := @POINT + 1,-940.694,8902.678,150.1837,0,0),
(@PATH,@POINT := @POINT + 1,-924.4999,8913.035,151.7751,0,0),
(@PATH,@POINT := @POINT + 1,-908.0786,8923.119,153.3695,0,0),
(@PATH,@POINT := @POINT + 1,-886.0104,8933.393,155.4501,0,0),
(@PATH,@POINT := @POINT + 1,-874.3984,8936.214,156.2588,0,0),
(@PATH,@POINT := @POINT + 1,-855.9192,8931.477,158.7263,0,0),
(@PATH,@POINT := @POINT + 1,-845.134521,8925.713867,161.844772,0,0),
(@PATH,@POINT := @POINT + 1,-834.978149,8919.649414,165.966446,65000,@SCRIPTID);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

SET @NPC := 68735;
SET @PATH := @NPC * 10;
SET @POINT := 0;
UPDATE `creature` SET `position_x`=-1800.628,`position_y`=8785.258,`position_z`=31.36622 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,@POINT := @POINT + 1,-1800.628,8785.258,31.36622,0), -- 17:17:19
(@PATH,@POINT := @POINT + 1,-1821.058,8778.673,30.80778,0), -- 17:17:24
(@PATH,@POINT := @POINT + 1,-1848.456,8762.41,28.90891,0), -- 17:17:37
(@PATH,@POINT := @POINT + 1,-1869.854,8754.341,26.27174,0), -- 17:17:46
(@PATH,@POINT := @POINT + 1,-1904.505,8759.32,26.06429,0), -- 17:17:54
(@PATH,@POINT := @POINT + 1,-1918.91,8769.67,26.86385,10000), -- 17:18:12
(@PATH,@POINT := @POINT + 1,-1946.543091,8816.708984,28.342142,0), -- 17:20:29
(@PATH,@POINT := @POINT + 1,-1981.723999,8863.507813,25.978216,0), -- 17:20:33
(@PATH,@POINT := @POINT + 1,-2015.871,8875.336,30.86393,0), -- 17:20:36
(@PATH,@POINT := @POINT + 1,-1997.016,8879.214,31.98178,0), -- 17:21:39
(@PATH,@POINT := @POINT + 1,-1966.578,8847.789,26.00286,0), -- 17:21:52
(@PATH,@POINT := @POINT + 1,-1946.478,8824.432,29.30156,0), -- 17:22:08
(@PATH,@POINT := @POINT + 1,-1944.506,8822.006,29.37523,0), -- 17:22:22
(@PATH,@POINT := @POINT + 1,-1925.181,8787.125,27.40347,0), -- 17:22:30
(@PATH,@POINT := @POINT + 1,-1916.387,8762.832,26.09533,0), -- 17:22:42
(@PATH,@POINT := @POINT + 1,-1874.201,8754.344,26.05693,0), -- 17:22:51
(@PATH,@POINT := @POINT + 1,-1854.197,8759.664,28.04397,0), -- 17:23:09
(@PATH,@POINT := @POINT + 1,-1840.163,8769.178,30.26139,0), -- 17:23:18
(@PATH,@POINT := @POINT + 1,-1815.867,8780.174,31.31474,0), -- 17:23:26
(@PATH,@POINT := @POINT + 1,-1791.843,8788.039,30.60195,0), -- 17:23:39
(@PATH,@POINT := @POINT + 1,-1778.97,8792.19,28.33318,0), -- 17:23:44
(@PATH,@POINT := @POINT + 1,-1785.26,8790.171,29.29748,0); -- 17:23:52
-- 0x203AF4424012C04000004E0000273198 .go -1800.628 8785.258 31.36622

SET @NPC := 68736;
SET @PATH := @NPC * 10;
SET @POINT := 0;
UPDATE `creature` SET `position_x`=-1882.313,`position_y`=8993.66,`position_z`=38.3989 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,@POINT := @POINT + 1,-1882.313,8993.66,38.3989,0), -- 17:35:09
(@PATH,@POINT := @POINT + 1,-1871.939,8953.98,41.94349,0), -- 17:35:23
(@PATH,@POINT := @POINT + 1,-1836.418,8920.867,36.96106,0), -- 17:35:36
(@PATH,@POINT := @POINT + 1,-1832.932,8918.501,36.04041,0), -- 17:35:54
(@PATH,@POINT := @POINT + 1,-1782.748,8893.457,34.7769,0), -- 17:36:08
(@PATH,@POINT := @POINT + 1,-1749.646,8880.189,32.58824,30000), -- 17:36:18
(@PATH,@POINT := @POINT + 1,-1749.675,8880.189,32.43178,0), -- 17:39:58
(@PATH,@POINT := @POINT + 1,-1716.815,8865.834,35.36955,0), -- 17:40:13
(@PATH,@POINT := @POINT + 1,-1701.336,8863.66,33.39202,0), -- 17:40:26
(@PATH,@POINT := @POINT + 1,-1663.693,8847.714,34.84836,0), -- 17:40:42
(@PATH,@POINT := @POINT + 1,-1666.743,8834.359,36.58212,0), -- 17:40:52
(@PATH,@POINT := @POINT + 1,-1692.787,8829.908,35.22899,0), -- 17:40:58
(@PATH,@POINT := @POINT + 1,-1728.21,8834.949,35.92305,0), -- 17:41:09
(@PATH,@POINT := @POINT + 1,-1763.568,8846.715,28.71403,0), -- 17:41:28
(@PATH,@POINT := @POINT + 1,-1786.974,8851.196,30.74931,0), -- 17:41:39
(@PATH,@POINT := @POINT + 1,-1804.311,8857.869,29.32577,0), -- 17:41:51
(@PATH,@POINT := @POINT + 1,-1836.927,8878.327,34.59752,0), -- 17:42:01
(@PATH,@POINT := @POINT + 1,-1857.11,8892.201,36.93163,0), -- 17:42:12
(@PATH,@POINT := @POINT + 1,-1886.158,8898.459,37.84557,0), -- 17:42:24
(@PATH,@POINT := @POINT + 1,-1902.083,8901.02,38.78384,0), -- 17:42:37
(@PATH,@POINT := @POINT + 1,-1966.359,8933.63,38.7355,0), -- 17:42:54
(@PATH,@POINT := @POINT + 1,-1976.945,8945.818,37.83896,0), -- 17:43:13
(@PATH,@POINT := @POINT + 1,-1972.83,9000.511,41.57624,0), -- 17:43:20
(@PATH,@POINT := @POINT + 1,-1955.283,9009.258,41.16612,0), -- 17:43:39
(@PATH,@POINT := @POINT + 1,-1924.979,9016.831,40.69277,0), -- 17:43:48
(@PATH,@POINT := @POINT + 1,-1917.55,9015.53,40.05937,0), -- 17:44:00
(@PATH,@POINT := @POINT + 1,-1885.793,9012.721,41.2858,0); -- 17:44:11
-- 0x203AF4424012C04000004E0000274379 .go -1882.313 8993.66 38.3989

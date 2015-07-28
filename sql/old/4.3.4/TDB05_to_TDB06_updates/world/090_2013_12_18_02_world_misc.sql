-- Pathing for Razak Ironsides Entry: 21118
SET @NPC := 74169;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1898.282,`position_y`=5588.863,`position_z`=267.5799 WHERE `guid`=@NPC;
UPDATE `creature_template_addon` SET `path_id`=@PATH WHERE `entry`=21118;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1898.282,5588.863,267.5799,0,0,0,0,100,0),
(@PATH,2,1901.311,5591.437,267.5729,2.268928,12000,0,0,100,0),
(@PATH,3,1898.282,5588.863,267.5799,0,0,0,0,100,0),
(@PATH,4,1903.68,5582.878,263.0307,0,0,0,0,100,0),
(@PATH,5,1912.105,5576.249,263.5081,0,0,0,0,100,0),
(@PATH,6,1933.132,5582.547,263.7424,0,0,0,0,100,0),
(@PATH,7,1936.292,5592.606,263.6276,0,0,0,0,100,0),
(@PATH,8,1926.111,5594.334,267.2368,0,0,0,0,100,0),
(@PATH,9,1926.288,5600.459,267.3679,0,0,0,0,100,0),
(@PATH,10,1938.523,5601.16,267.3898,1.448623,10000,0,0,100,0),
(@PATH,11,1926.537,5599.701,267.3592,0,0,0,0,100,0),
(@PATH,12,1926.136,5594.247,267.2361,0,0,0,0,100,0),
(@PATH,13,1935.867,5592.542,263.6276,0,0,0,0,100,0),
(@PATH,14,1941.244,5582.967,263.5026,0,0,0,0,100,0),
(@PATH,15,1947.379,5586.251,263.8776,0,0,0,0,100,0),
(@PATH,16,1953.378,5591.493,268.5281,0,0,0,0,100,0),
(@PATH,17,1956.4,5589.018,268.5525,0.715585,12000,0,0,100,0),
(@PATH,18,1953.378,5591.493,268.5281,0,0,0,0,100,0),
(@PATH,19,1946.525,5585.453,263.715,0,0,0,0,100,0),
(@PATH,20,1941.921,5576.632,263.6276,0,0,0,0,100,0),
(@PATH,21,1947.023,5567.701,263.2973,0,0,0,0,100,0),
(@PATH,22,1952.134,5567.827,262.4904,0,14000,0,0,100,0),
(@PATH,23,1941.256,5567.2,263.1159,0,0,0,0,100,0),
(@PATH,24,1931.549,5558.535,263.5149,0,0,0,0,100,0),
(@PATH,25,1921.011,5561.81,263.1283,0,0,0,0,100,0),
(@PATH,26,1910.488,5564.503,262.6283,0,0,0,0,100,0),
(@PATH,27,1899.725,5566.792,261.2341,2.80998,14000,0,0,100,0),
(@PATH,28,1905.735,5566.743,262.228,0,0,0,0,100,0),
(@PATH,29,1911.517,5567.898,262.866,0,0,0,0,100,0),
(@PATH,30,1913.893,5572.75,263.3232,0,0,0,0,100,0),
(@PATH,31,1910.438,5577.884,263.4108,0,0,0,0,100,0),
(@PATH,32,1903.363,5583.145,263.0307,0,0,0,0,100,0);

-- Pathing for Station Technician Entry: 21114
SET @NPC := 74157;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1927.036,`position_y`=5599.061,`position_z`=267.3522 WHERE `guid`=@NPC;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=74157;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1927.036,5599.061,267.3522,0,0,0,0,100,0),
(@PATH,2,1933.268,5600.586,267.3755,0,0,0,0,100,0),
(@PATH,3,1942.31,5599.332,267.372,0,0,0,0,100,0),
(@PATH,4,1933.268,5600.586,267.3755,0,0,0,0,100,0),
(@PATH,5,1927.036,5599.061,267.3522,0,0,0,0,100,0),
(@PATH,6,1933.268,5600.586,267.3755,0,0,0,0,100,0),
(@PATH,7,1942.31,5599.332,267.372,0,0,0,0,100,0),
(@PATH,8,1933.268,5600.586,267.3755,0,0,0,0,100,0),
(@PATH,9,1927.036,5599.061,267.3522,0,0,0,0,100,0),
(@PATH,10,1933.268,5600.586,267.3755,0,0,0,0,100,0),
(@PATH,11,1942.31,5599.332,267.372,0,0,0,0,100,0),
(@PATH,12,1944.908,5599.906,267.3809,0.541052,20000,0,0,100,0);

UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid`=74216;
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=21423;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (74147,74148,74149,74151,74152,74153,74154,74156);
UPDATE `creature_template` SET InhabitType=4 WHERE `entry`=21757;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=`flags_extra`|128 WHERE `entry` IN (21393,21413,21819);
UPDATE `creature_template_addon` SET bytes2=258 WHERE `entry`=21115;

DELETE FROM `creature_template_addon` WHERE `entry`=21441;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (21441,0,258,214, '');

-- Station Guard SAI "npc had no ai"
SET @ENTRY := 21115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3000,11,36246,64,0,0,0,0,2,0,0,0,0,0,0,0,"Station Guard - In Combat - Cast Shoot Tech Gun");

-- Station Sharpshooter SAI "npc had no ai"
SET @ENTRY := 21441;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3000,11,36246,64,0,0,0,0,2,0,0,0,0,0,0,0,"Station Sharpshooter - In Combat - Cast Shoot Tech Gun");

UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry`=21004;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=21203;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=21203;

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74445;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1925.933,`position_y`=5574.994,`position_z`=263.9057 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1925.933,5574.994,263.9057,0,0,0,0,100,0),
(@PATH,2,1923.862,5571.222,264.5634,0,0,0,0,100,0),
(@PATH,3,1918.887,5573.768,263.9057,0,0,0,0,100,0),
(@PATH,4,1918.378,5580.262,263.9057,0,0,0,0,100,0),
(@PATH,5,1921.742,5581.211,263.9057,0,0,0,0,100,0),
(@PATH,6,1921.567,5583.882,263.9057,0,0,0,0,100,0),
(@PATH,7,1918.75,5579.688,263.9057,0,0,0,0,100,0),
(@PATH,8,1918.887,5573.768,263.9057,0,0,0,0,100,0),
(@PATH,9,1923.862,5571.222,264.5634,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74435;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1930.208,`position_y`=5586.458,`position_z`=263.7807 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1930.208,5586.458,263.7807,0,0,0,0,100,0),
(@PATH,2,1924.03,5583.297,269.222,0,0,0,0,100,0),
(@PATH,3,1920.99,5584.492,269.222,0,0,0,0,100,0),
(@PATH,4,1917.851,5583.545,269.222,0,0,0,0,100,0),
(@PATH,5,1917.235,5581.401,269.222,0,0,0,0,100,0),
(@PATH,6,1918.989,5579.888,269.222,0,0,0,0,100,0),
(@PATH,7,1923.064,5581.889,269.222,0,0,0,0,100,0),
(@PATH,8,1921.47,5580.008,269.222,0,0,0,0,100,0),
(@PATH,9,1917.235,5581.401,269.222,0,0,0,0,100,0),
(@PATH,10,1920.99,5584.492,269.222,0,0,0,0,100,0),
(@PATH,11,1923.452,5583.202,269.222,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74432;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1923.565,`position_y`=5554.142,`position_z`=264.0841 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1923.565,5554.142,264.0841,0,0,0,0,100,0),
(@PATH,2,1919.271,5553.125,263.7533,0,0,0,0,100,0),
(@PATH,3,1917.914,5550.622,263.8282,0,0,0,0,100,0),
(@PATH,4,1919.061,5546.854,265.3362,0,0,0,0,100,0),
(@PATH,5,1922.396,5545.313,267.0033,0,0,0,0,100,0),
(@PATH,6,1924.869,5545.137,268.5815,0,0,0,0,100,0),
(@PATH,7,1921.442,5545.314,266.4293,0,0,0,0,100,0),
(@PATH,8,1918.229,5550.521,263.8783,0,0,0,0,100,0),
(@PATH,9,1919.271,5552.083,263.8783,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1928.164,`position_y`=5571.725,`position_z`=269.162 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1928.164,5571.725,269.162,0,0,0,0,100,0),
(@PATH,2,1928.04,5573.644,269.162,0,0,0,0,100,0),
(@PATH,3,1926.483,5574.808,269.162,0,0,0,0,100,0),
(@PATH,4,1928.04,5573.644,269.162,0,0,0,0,100,0),
(@PATH,5,1924.417,5570.661,269.162,0,0,0,0,100,0),
(@PATH,6,1923.467,5571.99,269.162,0,0,0,0,100,0),
(@PATH,7,1924.153,5574.196,269.162,0,0,0,0,100,0),
(@PATH,8,1923.467,5571.99,269.162,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74433;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1927.253,`position_y`=5578.909,`position_z`=263.9057 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1927.253,5578.909,263.9057,0,0,0,0,100,0),
(@PATH,2,1931.318,5580.051,263.9057,0,0,0,0,100,0),
(@PATH,3,1929.688,5578.125,263.9057,0,0,0,0,100,0),
(@PATH,4,1925.712,5578.032,263.9057,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74434;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1929.118,`position_y`=5532.288,`position_z`=266.8577 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1929.118,5532.288,266.8577,0,0,0,0,100,0),
(@PATH,2,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,3,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,4,1925.521,5531.25,266.7585,0,0,0,0,100,0),
(@PATH,5,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,6,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,7,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,8,1925.521,5531.25,266.7585,0,0,0,0,100,0),
(@PATH,9,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,10,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,11,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,12,1926.394,5530.808,266.6537,0,0,0,0,100,0),
(@PATH,13,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,14,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,15,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,16,1926.394,5530.808,266.6537,0,0,0,0,100,0),
(@PATH,17,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,18,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,19,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,20,1926.394,5530.808,266.6537,0,0,0,0,100,0),
(@PATH,21,1929.192,5531.739,267.5261,0,0,0,0,100,0),
(@PATH,22,1933.571,5532.64,267.3299,0,0,0,0,100,0),
(@PATH,23,1926.394,5530.808,266.6537,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74447;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1938.432,`position_y`=5539.722,`position_z`=266.5296 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1938.432,5539.722,266.5296,0,0,0,0,100,0),
(@PATH,2,1937.34,5536.819,266.5726,0,0,0,0,100,0),
(@PATH,3,1937.305,5535.265,266.5568,0,0,0,0,100,0),
(@PATH,4,1938.837,5533.25,266.4304,0,0,0,0,100,0),
(@PATH,5,1937.302,5535.26,266.5613,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74448;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1958.761,`position_y`=5585.456,`position_z`=268.5192 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1958.761,5585.456,268.5192,0,0,0,0,100,0),
(@PATH,2,1957.849,5587.807,268.5635,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74427;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1905.77,`position_y`=5550.124,`position_z`=263.926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1905.77,5550.124,263.926,0,0,0,0,100,0),
(@PATH,2,1906.093,5546.895,264.1884,0,0,0,0,100,0),
(@PATH,3,1903.544,5544.234,264.8871,0,0,0,0,100,0),
(@PATH,4,1898.493,5549.161,264.5766,0,0,0,0,100,0),
(@PATH,5,1903.544,5544.234,264.8871,0,0,0,0,100,0),
(@PATH,6,1906.093,5546.895,264.1884,0,0,0,0,100,0),
(@PATH,7,1905.77,5550.124,263.926,0,0,0,0,100,0),
(@PATH,8,1902.604,5552.604,263.7533,0,0,0,0,100,0);

-- Pathing for Blade's Edge Invisible Stalker Entry: 21234
SET @NPC := 74430;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1885.685,`position_y`=5573.016,`position_z`=260.2205 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1885.685,5573.016,260.2205,0,0,0,0,100,0),
(@PATH,2,1903.292,5566.08,261.9607,0,0,0,0,100,0),
(@PATH,3,1895.033,5554.773,264.8015,0,0,0,0,100,0),
(@PATH,4,1879.357,5548.936,268.2559,0,0,0,0,100,0),
(@PATH,5,1867.17,5544.657,273.0115,0,0,0,0,100,0),
(@PATH,6,1853.044,5537.785,276.9887,0,0,0,0,100,0),
(@PATH,7,1863.808,5542.95,274.4838,0,0,0,0,100,0),
(@PATH,8,1871.133,5545.963,271.3029,0,0,0,0,100,0),
(@PATH,9,1884.797,5550.7,266.1573,0,0,0,0,100,0),
(@PATH,10,1900.419,5557.055,263.4814,0,0,0,0,100,0),
(@PATH,11,1911.849,5555.216,263.1897,0,0,0,0,100,0),
(@PATH,12,1915.648,5534.096,267.2911,0,0,0,0,100,0),
(@PATH,13,1926.042,5532.813,266.6335,0,0,0,0,100,0),
(@PATH,14,1934.861,5540.538,266.9522,0,0,0,0,100,0),
(@PATH,15,1935.881,5550.045,265.9952,0,0,0,0,100,0),
(@PATH,16,1919.127,5569.151,263.7807,0,0,0,0,100,0),
(@PATH,17,1922.958,5581.576,263.9057,0,0,0,0,100,0),
(@PATH,18,1897.795,5574.03,261.5737,0,0,0,0,100,0),
(@PATH,19,1922.958,5581.576,263.9057,0,0,0,0,100,0),
(@PATH,20,1919.127,5569.151,263.7807,0,0,0,0,100,0),
(@PATH,21,1935.881,5550.045,265.9952,0,0,0,0,100,0),
(@PATH,22,1934.861,5540.538,266.9522,0,0,0,0,100,0),
(@PATH,23,1926.632,5533.106,266.6335,0,0,0,0,100,0),
(@PATH,24,1915.648,5534.096,267.2911,0,0,0,0,100,0),
(@PATH,25,1911.849,5555.216,263.1897,0,0,0,0,100,0),
(@PATH,26,1900.419,5557.055,263.4814,0,0,0,0,100,0),
(@PATH,27,1884.797,5550.7,266.1573,0,0,0,0,100,0),
(@PATH,28,1871.133,5545.963,271.3029,0,0,0,0,100,0),
(@PATH,29,1863.808,5542.95,274.4838,0,0,0,0,100,0),
(@PATH,30,1853.044,5537.785,276.9887,0,0,0,0,100,0),
(@PATH,31,1867.17,5544.657,273.0115,0,0,0,0,100,0),
(@PATH,32,1879.357,5548.936,268.2559,0,0,0,0,100,0),
(@PATH,33,1894.842,5554.514,264.766,0,0,0,0,100,0),
(@PATH,34,1903.292,5566.08,261.9607,0,0,0,0,100,0);

-- Station Technician text
SET @ENTRY := 21114;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'YEOW!!',12,0,100,0,0,0, 'Station Technician'),
(@ENTRY,0,1, 'I''M ON FIRE!!!',12,0,100,0,0,0, 'Station Technician'),
(@ENTRY,0,2, 'IT BURNS!!',12,0,100,0,0,0, 'Station Technician'),
(@ENTRY,0,3, 'I''M ON FIRE!!! AGAIN!!',12,0,100,0,0,0, 'Station Technician'),
(@ENTRY,0,4, 'WHY ME!?!',12,0,100,0,0,0, 'Station Technician'),
(@ENTRY,0,5, 'Not again...',12,0,100,0,0,0, 'Station Technician');

-- Razak Ironsides text
SET @ENTRY := 21118;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'LET''S ROCK!!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,1,0, 'FIRE UP THE DEF GUNS!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,2,0, 'Where''s our back up? I want them here now!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,3,0, 'Last push boys! Let ''em have it!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,4,0, 'Nice work Solders! This is the last of them!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,4,1, 'This is the last of them.  Don''t get sloppy!',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,5,0, 'We can handle it from here.  Roughriders you are dismissed.',14,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event'),
(@ENTRY,6,0, 'Come on you apes. You want to live forever?',12,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event random combat text'),
(@ENTRY,6,1, 'Warm it up and give ''em everything you''ve got.',12,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event random combat text'),
(@ENTRY,6,2, 'I have only one rule. Everyone fights. No one quits.',12,0,100,0,0,0, 'Razak Ironsides - Ravager invasion event random combat text');

-- Strider Jock text
SET @ENTRY := 21427;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You boys need some help?',14,0,100,0,0,0, 'Strider Jock - Ravager invasion event');

-- Gnome Defender 209 text
SET @ENTRY := 21426;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Cavalry, let''s roll out!',14,0,100,0,0,0, 'Gnome Defender 209 - Ravager invasion event');

-- Remove some spawns that should only be spawned with attck script
DELETE FROM `creature` WHERE `guid` IN (84336,84341,84342,84346,84347,84348,84349);
DELETE FROM `creature_addon` WHERE `guid` IN (84336,84341,84342,84346,84347,84348,84349);

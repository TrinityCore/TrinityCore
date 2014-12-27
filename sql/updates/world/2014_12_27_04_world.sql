-- Updating SAI
-- Dreadcaller SAI
SET @ENTRY := 19434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,32666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadcaller - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,0,0,100,0,4000,9000,18100,24000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadcaller - In Combat - Cast 'Cripple' (Phase 1) (No Repeat)");

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69502;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=177.5729,`position_y`=2268.238,`position_z`=48.5948 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,177.5729,2268.238,48.5948,0,0,0,0,100,0),
(@PATH,2,206.0571,2228.519,54.04856,0,0,0,0,100,0);
-- 0xF1304BEA00397367 .go 177.5729 2268.238 48.5948

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69501;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=190.7178,`position_y`=2286.323,`position_z`=49.66181 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,190.7178,2286.323,49.66181,0,0,0,0,100,0),
(@PATH,2,210.6431,2285.845,53.60326,0,0,0,0,100,0),
(@PATH,3,222.5459,2286.666,56.13475,0,0,0,0,100,0),
(@PATH,4,231.5569,2296.63,60.31371,0,0,0,0,100,0),
(@PATH,5,220.7462,2308.746,60.02021,0,0,0,0,100,0),
(@PATH,6,208.7211,2311.991,57.36103,0,0,0,0,100,0),
(@PATH,7,195.7977,2312.93,53.85427,0,0,0,0,100,0),
(@PATH,8,181.254,2297.919,50.28107,0,0,0,0,100,0);
-- 0xF1304BEA00396ED6 .go 190.7178 2286.323 49.66181

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69500;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=233.3709,`position_y`=2074.927,`position_z`=39.10539 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,233.3709,2074.927,39.10539,0,0,0,0,100,0),
(@PATH,2,228.1582,2076.218,39.70464,0,0,0,0,100,0),
(@PATH,3,226.8357,2086.181,39.48833,0,0,0,0,100,0),
(@PATH,4,227.4231,2100.461,39.53439,0,0,0,0,100,0),
(@PATH,5,231.5971,2104.666,38.92635,0,0,0,0,100,0),
(@PATH,6,237.6874,2098.439,39.00676,0,0,0,0,100,0),
(@PATH,7,241.6207,2088.015,38.11906,0,0,0,0,100,0),
(@PATH,8,238.947,2078.802,38.06547,0,0,0,0,100,0);
-- 0xF1304BEA00353517 .go 233.3709 2074.927 39.10539


-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69503;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-523.7537,`position_y`=2008.213,`position_z`=82.43176 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-523.7537,2008.213,82.43176,0,0,0,0,100,0),
(@PATH,2,-513.3772,2034.226,82.13103,0,0,0,0,100,0),
(@PATH,3,-501.1374,2063.957,81.46646,0,0,0,0,100,0),
(@PATH,4,-490.7202,2097.977,79.50304,0,0,0,0,100,0),
(@PATH,5,-495.6437,2124.143,75.1469,0,0,0,0,100,0),
(@PATH,6,-500.0753,2152.032,70.07507,0,0,0,0,100,0),
(@PATH,7,-497.6553,2131.211,73.99121,0,0,0,0,100,0),
(@PATH,8,-488.903,2108.3,78.71799,0,0,0,0,100,0),
(@PATH,9,-496.6252,2076.111,81.08714,0,0,0,0,100,0),
(@PATH,10,-505.7927,2051.876,81.88617,0,0,0,0,100,0),
(@PATH,11,-519.2833,2018.794,82.35017,0,0,0,0,100,0),
(@PATH,12,-523.7976,2008.294,82.49103,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002000004E9B0D .go -523.7537 2008.213 82.43176

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69499;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-558.5822,`position_y`=2003.227,`position_z`=98.30606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-558.5822,2003.227,98.30606,0,0,0,0,100,0),
(@PATH,2,-557.4218,2005.291,99.07405,0,0,0,0,100,0),
(@PATH,3,-559.7542,2056.054,96.38632,0,0,0,0,100,0),
(@PATH,4,-540.9093,2062.701,104.2178,0,0,0,0,100,0),
(@PATH,5,-538.0739,2083.637,102.7935,0,0,0,0,100,0),
(@PATH,6,-531.9629,2100.469,104.145,0,0,0,0,100,0),
(@PATH,7,-540.8042,2121.509,97.44407,0,0,0,0,100,0),
(@PATH,8,-542.6715,2139.263,94.42299,0,0,0,0,100,0),
(@PATH,9,-542.0955,2125.005,96.38588,0,0,0,0,100,0),
(@PATH,10,-531.0101,2105.611,103.8495,0,0,0,0,100,0),
(@PATH,11,-533.4691,2097.096,103.5421,0,0,0,0,100,0),
(@PATH,12,-539.8324,2066.038,103.8721,0,0,0,0,100,0),
(@PATH,13,-559.5454,2057.871,96.58672,0,0,0,0,100,0),
(@PATH,14,-557.4636,2005.37,98.92694,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002D00001EC994 .go -558.5822 2003.227 98.30606

-- Pathing for Dreadcaller Entry: 19434 'TDB FORMAT' 
SET @NPC := 69504;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-506.4011,`position_y`=1982.52,`position_z`=85.11931 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-506.4011,1982.52,85.11931,0,0,0,0,100,0),
(@PATH,2,-491.8763,2002.533,90.20009,0,0,0,0,100,0),
(@PATH,3,-475.5587,2034.282,93.52704,0,0,0,0,100,0),
(@PATH,4,-459.14,2057.011,93.19531,0,0,0,0,100,0),
(@PATH,5,-488.9269,2006.812,90.64146,0,0,0,0,100,0),
(@PATH,6,-506.4684,1982.384,85.10349,0,0,0,0,100,0),
(@PATH,7,-459.1624,2056.984,93.22046,0,0,0,0,100,0),
(@PATH,8,-453.0856,2078.318,92.4622,0,0,0,0,100,0),
(@PATH,9,-458.4782,2105.915,91.30417,0,0,0,0,100,0),
(@PATH,10,-453.1829,2091.579,91.92897,0,0,0,0,100,0),
(@PATH,11,-454.6579,2067.877,92.86068,0,0,0,0,100,0),
(@PATH,12,-471.7339,2040.147,93.86339,0,0,0,0,100,0),
(@PATH,13,-488.8954,2006.772,90.6447,0,0,0,0,100,0),
(@PATH,14,-506.3882,1982.291,85.0636,0,0,0,0,100,0);
-- 0x1C09E4424012FA8000002D00001EC026 .go -506.4011 1982.52 85.11931

-- Adding missing spawn Bleeding Hollow Dark Shaman Entry: 16873
SET @GUID := 29978;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID, 16873, 530, -945.313, 1948.252, 58.1359, 67.06455, 300, 3984, 2434, 2);

-- Bleeding Hollow Dark Shaman SAI
SET @ENTRY := 16873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Out of Combat - Cast 'Lightning Shield' (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,11,0,2,0,100,1,0,30,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-30% Health - Cast 'Bloodlust' (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,4000,8000,30000,45000,11,32062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - In Combat - Cast 'Fire Nova Totem' (Phase 1) (No Repeat)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,16,0,5,0,100,1,0,0,0,0,11,34013,1,0,0,0,0,7,0,0,0,0,0,0,0,"Bleeding Hollow Dark Shaman - On Killed Unit - Cast 'Raise Soul' (No Repeat)");

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58257;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1058.69,`position_y`=2123.373,`position_z`=51.63616 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1058.69,2123.373,51.63616,0,0,0,0,100,0),
(@PATH,2,-1057.219,2099.756,59.51154,0,0,0,0,100,0),
(@PATH,3,-1044.785,2080.962,64.48811,0,0,0,0,100,0),
(@PATH,4,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,5,-1035.883,2045.864,67.88428,0,0,0,0,100,0),
(@PATH,6,-1024.891,2036.104,67.17399,0,0,0,0,100,0),
(@PATH,7,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,8,-993.7006,2017.729,67.06455,0,0,0,0,100,0),
(@PATH,9,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,10,-992.9711,2018.175,67.06455,0,0,0,0,100,0),
(@PATH,11,-971.9114,2014.351,67.06455,0,0,0,0,100,0),
(@PATH,12,-992.9711,2018.175,67.06455,0,0,0,0,100,0),
(@PATH,13,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,14,-1008.182,1997.039,67.06455,0,0,0,0,100,0),
(@PATH,15,-993.7006,2017.729,67.06455,0,0,0,0,100,0),
(@PATH,16,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,17,-1011.885,2038.549,67.04899,0,0,0,0,100,0),
(@PATH,18,-1024.891,2036.104,67.17399,0,0,0,0,100,0),
(@PATH,19,-1035.883,2045.864,67.88428,0,0,0,0,100,0),
(@PATH,20,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,21,-1027.752,2060.003,67.17399,0,0,0,0,100,0),
(@PATH,22,-1044.785,2080.966,64.57795,0,0,0,0,100,0),
(@PATH,23,-1057.219,2099.756,59.51154,0,0,0,0,100,0);
-- 0xF13041E90060F72D .go -1058.69 2123.373 51.63616

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58256;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1144.076,`position_y`=1954.738,`position_z`=80.57024 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1144.076,1954.738,80.57024,0,0,0,0,100,0),
(@PATH,2,-1133.44,1972.225,73.66801,0,0,0,0,100,0),
(@PATH,3,-1122.611,1999.216,68.83028,0,0,0,0,100,0),
(@PATH,4,-1099.563,2031.872,67.05327,0,0,0,0,100,0),
(@PATH,5,-1084.684,2065.122,66.82748,0,0,0,0,100,0),
(@PATH,6,-1070.713,2090.635,62.18363,0,0,0,0,100,0),
(@PATH,7,-1100.243,2084.849,66.59998,0,0,0,0,100,0),
(@PATH,8,-1129.753,2078.135,67.00842,0,0,0,0,100,0),
(@PATH,9,-1100.243,2084.849,66.59998,0,0,0,0,100,0),
(@PATH,10,-1070.713,2090.635,62.18363,0,0,0,0,100,0),
(@PATH,11,-1084.646,2065.203,66.72787,0,0,0,0,100,0),
(@PATH,12,-1099.563,2031.872,67.05327,0,0,0,0,100,0),
(@PATH,13,-1122.611,1999.216,68.83028,0,0,0,0,100,0),
(@PATH,14,-1133.43,1972.312,73.66801,0,0,0,0,100,0);
-- 0xF13041E900612D35 .go -1144.076 1954.738 80.57024

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 58258;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1060.848,`position_y`=2105.119,`position_z`=58.13591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1060.848,2105.119,58.13591,0,0,0,0,100,0),
(@PATH,2,-1037.167,2107.136,59.97014,0,0,0,0,100,0),
(@PATH,3,-1018.748,2084.713,68.99667,0,0,0,0,100,0),
(@PATH,4,-990.0961,2053.444,67.06454,0,0,0,0,100,0),
(@PATH,5,-961.8248,2037.499,67.04703,0,0,0,0,100,0),
(@PATH,6,-938.3379,2024.596,65.73439,0,0,0,0,100,0),
(@PATH,7,-921.1564,2015.199,62.66013,0,0,0,0,100,0),
(@PATH,8,-909.5775,1992.915,67.29996,0,0,0,0,100,0),
(@PATH,9,-889.6608,1985.54,67.38715,0,0,0,0,100,0),
(@PATH,10,-879.1632,1955.284,67.81312,0,0,0,0,100,0),
(@PATH,11,-877.1085,1921.789,70.60205,0,0,0,0,100,0),
(@PATH,12,-901.7319,1883,76.4217,0,0,0,0,100,0),
(@PATH,13,-877.1085,1921.789,70.60205,0,0,0,0,100,0),
(@PATH,14,-879.1632,1955.284,67.81312,0,0,0,0,100,0),
(@PATH,15,-889.6608,1985.54,67.38715,0,0,0,0,100,0),
(@PATH,16,-909.5775,1992.915,67.29996,0,0,0,0,100,0),
(@PATH,17,-921.1564,2015.199,62.66013,0,0,0,0,100,0),
(@PATH,18,-938.3379,2024.596,65.73439,0,0,0,0,100,0),
(@PATH,19,-961.8248,2037.499,67.04703,0,0,0,0,100,0),
(@PATH,20,-990.0961,2053.444,67.06454,0,0,0,0,100,0),
(@PATH,21,-1018.748,2084.713,68.99667,0,0,0,0,100,0),
(@PATH,22,-1037.167,2107.136,59.97014,0,0,0,0,100,0),
(@PATH,23,-1060.848,2105.119,58.13591,0,0,0,0,100,0);
-- 0xF13041E90061464D .go -1060.848 2105.119 58.13591

-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT' 
SET @NPC := 6747;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-945.313,`position_y`=1948.252,`position_z`=67.06455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-945.313,1948.252,67.06455,0,0,0,0,100,0),
(@PATH,2,-946.7964,1966.628,67.06455,0,0,0,0,100,0),
(@PATH,3,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,4,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,5,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,6,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,7,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,8,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,9,-968.4443,2047.705,67.06454,0,0,0,0,100,0),
(@PATH,10,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,11,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,12,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,13,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,14,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,15,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,16,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,17,-946.7964,1966.628,67.06455,0,0,0,0,100,0);
-- 0xF13041E90061F326 .go -945.313 1948.252 67.06455

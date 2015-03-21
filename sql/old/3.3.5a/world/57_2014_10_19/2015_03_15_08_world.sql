-- 
-- Pathing for  Entry: 22410 'TDB FORMAT' 
SET @NPC := 78754;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3009.127,`position_y`=5920.842,`position_z`=130.9854 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,14332,0,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3009.127,5920.842,130.9854,0,0,1,0,100,0),
(@PATH,2,3018.56,5944.067,131.0012,0,0,1,0,100,0),
(@PATH,3,3028.687,5971.723,131.0047,0,0,1,0,100,0),
(@PATH,4,3039.209,5998.325,130.9491,0,0,1,0,100,0),
(@PATH,5,3041.459,6004.325,130.9491,0,0,1,0,100,0),
(@PATH,6,3042.709,6007.575,130.9491,0,0,1,0,100,0),
(@PATH,7,3043.459,6009.825,130.9491,0,0,1,0,100,0),
(@PATH,8,3048.21,6021.786,130.8358,0,0,1,0,100,0),
(@PATH,9,3058.211,6046.689,130.7168,0,0,1,0,100,0),
(@PATH,10,3065.155,6064.995,130.614,0,0,1,0,100,0),
(@PATH,11,3078.91,6073.112,130.3709,0,0,1,0,100,0),
(@PATH,12,3084.571,6056.194,130.4195,0,0,1,0,100,0),
(@PATH,13,3079.821,6040.444,130.6695,0,0,1,0,100,0),
(@PATH,14,3079.655,6040.126,130.764,0,0,1,0,100,0),
(@PATH,15,3079.405,6039.626,130.764,0,0,1,0,100,0),
(@PATH,16,3078.905,6038.126,130.764,0,0,1,0,100,0),
(@PATH,17,3069.25,6014.667,130.9082,0,0,1,0,100,0),
(@PATH,18,3064,6000.667,130.9082,0,0,1,0,100,0),
(@PATH,19,3060.452,5991.971,130.99,0,0,1,0,100,0),
(@PATH,20,3050.27,5967.535,130.9908,0,0,1,0,100,0),
(@PATH,21,3045.52,5954.535,130.9908,0,0,1,0,100,0),
(@PATH,22,3039.294,5938.282,130.9514,0,0,1,0,100,0),
(@PATH,23,3028.456,5913.517,130.8795,0,0,1,0,100,0),
(@PATH,24,3019.764,5891.665,130.7868,0,0,1,0,100,0),
(@PATH,25,3016.764,5884.415,130.7868,0,0,1,0,100,0),
(@PATH,26,3012.264,5873.915,130.7868,0,0,1,0,100,0),
(@PATH,27,3009.264,5866.915,130.7868,0,0,1,0,100,0),
(@PATH,28,3012.196,5873.788,130.7515,0,0,1,0,100,0),
(@PATH,29,3008.946,5866.788,130.7515,0,0,1,0,100,0),
(@PATH,30,3008.446,5865.038,130.7515,0,0,1,0,100,0),
(@PATH,31,2995.446,5836.038,130.5015,0,0,1,0,100,0),
(@PATH,32,2995.104,5835.657,130.3808,0,0,1,0,100,0),
(@PATH,33,2991.854,5828.407,130.6308,0,0,1,0,100,0),
(@PATH,34,2990.604,5827.907,130.3808,0,0,1,0,100,0),
(@PATH,35,2976.186,5821.571,130.1743,0,0,1,0,100,0),
(@PATH,36,2970.518,5837.316,130.481,0,0,1,0,100,0),
(@PATH,37,2971.768,5840.066,130.481,0,0,1,0,100,0),
(@PATH,38,2980.487,5859.262,131.0515,0,0,1,0,100,0),
(@PATH,39,2983.987,5866.762,131.0515,0,0,1,0,100,0),
(@PATH,40,2989.237,5876.512,131.3015,0,0,1,0,100,0);
-- 0x1C3998424015E28000002300007FC920 .go 3009.127 5920.842 130.9854

DELETE FROM `creature_formations` WHERE `leaderGUID`=78754;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(78754, 78754, 0, 0, 2, 0, 0),
(78754, 78755, 7, 0, 0, 0, 0);

-- Expedition Warden SAI
SET @GUID := -63549;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17855;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,100,200,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Warden - Out of Combat - Play Emote 1");

-- Expedition Warden SAI
SET @GUID := -63548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17855;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,100,200,10000,40000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Warden - Out of Combat - Play Emote 1");

-- Pathing for  Entry: 17855 'TDB FORMAT' 
SET @NPC := 63550;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3022.651,`position_y`=5963.609,`position_z`=130.7766 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3022.651,5963.609,130.7766,0,6000,0,0,100,0),
(@PATH,2,3032.096,5959.558,130.6869,0,6000,0,0,100,0);
-- 0x1C39984240116FC000002300027FC920 .go 3022.651 5963.609 130.7766

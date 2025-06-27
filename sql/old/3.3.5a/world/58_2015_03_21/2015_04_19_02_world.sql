-- Highland Mustang SAI
SET @ENTRY := 26472;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,49266,0,0,0,69,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Highland Mustang - On Spell Hit(Dangle Wild Carrot) - Move To Player"),
(@ENTRY,0,1,2,34,0,100,0,0,1,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Reached Point 1 - Set Rooted Off"),
(@ENTRY,0,2,0,61,0,100,0,0,1,0,0,85,49282,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Reached Point 1 - Invoker Cast 'Ride Highland Mustang'"),
(@ENTRY,0,3,0,27,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Passenger Boarded - Remove Root"),
(@ENTRY,0,4,5,8,0,100,1,49319,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit 'Scare Highland Mustang' - Flee For Assist (No Repeat)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,11,49323,0,0,0,0,0,7,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit 'Scare Highland Mustang' - Cast 'Highland Mustang Spooking Credit' (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highland Mustang - On Spellhit 'Scare Highland Mustang' - Despawn In 5000 ms (No Repeat)");

SET @LEADER := 105333;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(@LEADER, @LEADER, 0, 0, 2),
(@LEADER, 105334, 6, 20, 2),
(@LEADER, 105307, 6, 60, 2),
(@LEADER, 105327, 6, 100, 2),
(@LEADER, 105332, 6, 140, 2),
(@LEADER, 105330, 6, 180, 2),
(@LEADER, 105331, 6, 220, 2),
(@LEADER, 105310, 6, 260, 2),
(@LEADER, 105325, 6, 290, 2),
(@LEADER, 105308, 6, 340, 2);

-- Pathing for Highland Mustang Entry: 26472 'TDB FORMAT' 
SET @NPC := 105333;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4427.042,`position_y`=-4339.906,`position_z`=156.9126 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4427.042,-4339.906,156.9126,0,0,1,0,100,0), -- 12:00:19
(@PATH,2,4408.496,-4311.258,159.5146,0,0,1,0,100,0), -- 12:00:25
(@PATH,3,4395.234,-4306.927,159.0624,0,0,1,0,100,0), -- 12:00:28
(@PATH,4,4357.375,-4353.118,158.7053,0,0,1,0,100,0), -- 12:00:32
(@PATH,5,4358.002,-4387.411,154.6664,0,0,1,0,100,0), -- 12:00:37
(@PATH,6,4350.741,-4420.083,151.4936,0,0,1,0,100,0), -- 12:00:41
(@PATH,7,4355.459,-4451.332,147.9055,0,0,1,0,100,0), -- 12:00:45
(@PATH,8,4382.324,-4459.469,141.1845,0,0,1,0,100,0), -- 12:00:49
(@PATH,9,4389.952,-4415.67,148.3579,0,0,1,0,100,0), -- 12:00:53
(@PATH,10,4397.468,-4374.768,153.7379,0,0,1,0,100,0); -- 12:00:58
-- 0x203930476019DA0000000D0000337E18 .go 4427.042 -4339.906 156.9126

SET @LEADER := 105349;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(@LEADER, @LEADER, 0, 0, 2),
(@LEADER, 105304, 6, 20, 2),
(@LEADER, 105303, 6, 60, 2),
(@LEADER, 105305, 6, 100, 2),
(@LEADER, 105301, 6, 140, 2),
(@LEADER, 105283, 6, 180, 2),
(@LEADER, 105302, 6, 220, 2),
(@LEADER, 105350, 6, 260, 2),
(@LEADER, 105322, 6, 290, 2),
(@LEADER, 105321, 6, 340, 2);

-- Pathing for Highland Mustang Entry: 26472 'TDB FORMAT' 
SET @NPC := 105349;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4402.506,`position_y`=-4058.453,`position_z`=178.0393 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4402.506,-4058.453,178.0393,0,0,1,0,100,0), -- 11:54:03
(@PATH,2,4409.204,-4045.754,177.6823,0,0,1,0,100,0), -- 11:54:07
(@PATH,3,4437.108,-4006.367,180.2671,0,0,1,0,100,0), -- 11:54:09
(@PATH,4,4444.708,-3989.958,182.246,0,0,1,0,100,0), -- 11:54:13
(@PATH,5,4449.759,-3956.142,185.0904,0,0,1,0,100,0), -- 11:54:15
(@PATH,6,4428.842,-3946.839,183.3041,0,0,1,0,100,0), -- 11:54:18
(@PATH,7,4415.667,-3952.115,181.8032,0,0,1,0,100,0), -- 11:54:21
(@PATH,8,4397.648,-3971.361,180.6909,0,0,1,0,100,0), -- 11:54:24
(@PATH,9,4390.27,-4002.242,179.2844,0,0,1,0,100,0), -- 11:54:28
(@PATH,10,4391.74,-4008.471,178.8489,0,0,1,0,100,0), -- 11:54:30
(@PATH,11,4385.273,-4030.866,179.386,0,0,1,0,100,0), -- 11:54:31
(@PATH,12,4376.343,-4062.502,181.3641,0,0,1,0,100,0), -- 11:54:34
(@PATH,13,4392.244,-4068.051,179.3222,0,0,1,0,100,0); -- 11:54:37
-- 0x203930476019DA0000000D00003393C1 .go 4402.506 -4058.453 178.0393

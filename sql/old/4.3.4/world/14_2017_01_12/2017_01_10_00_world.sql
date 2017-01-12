--
UPDATE `creature_template` SET `gossip_menu_id`=12452 WHERE `entry` IN (42898);
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (279139, 279142);
DELETE FROM `creature_addon` WHERE `guid` IN (279139, 279142);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (279139,0,0,0,1,375, ''),(279142,0,0,0,1,375, '');

-- Reventusk Drummer SAI
SET @ENTRY := 14734;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1200,1200,1200,1200,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reventusk Drummer - OOC - Play emote");

-- Otho Moj1`Ko SAI
SET @ENTRY := 14738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Otho Moj1`Ko - Out of Combat - Set Emotestate (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Otho Moj1`Ko - On Aggro - Set Emotestate");

-- Smith Slagtree SAI
SET @ENTRY := 14737;
UPDATE `creature` SET `position_x`=-589.9536,`position_y`=-4548.458,`position_z`=9.161489,`orientation`=0.6108652 WHERE `guid`=278346;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,164000,164000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - OOC - Play script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Set emote state"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,69,0,0,0,0,0,0,8,0,0,0,-595.7503,-4559.671,9.161489,0,"Smith Slagtree - Script - Move to"),
(@ENTRY*100,9,3,0,0,0,100,0,6000,6000,6000,6000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.969026,"Smith Slagtree - Script - Turn to"),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Say text"),
(@ENTRY*100,9,5,0,0,0,100,0,3000,3000,3000,3000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.228859,"Smith Slagtree - Script - Turn to"),
(@ENTRY*100,9,6,0,0,0,100,0,115000,115000,115000,115000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Set emote state"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Set Bytes_1 'Kneel'"), -- Kneel not working
(@ENTRY*100,9,8,0,0,0,100,0,3000,3000,3000,3000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Remove Bytes_1 'Kneel'"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-589.9536,-4548.458,9.161489,0,"Smith Slagtree - Script - Move to"),
(@ENTRY*100,9,10,0,0,0,100,0,6000,6000,6000,6000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.6108652,"Smith Slagtree - Script - Turn to"),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,2000,2000,11,23488,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Cast 'Spirit Hammer'"),
(@ENTRY*100,9,12,0,0,0,100,0,2000,2000,2000,2000,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Set emote state"),
(@ENTRY*100,9,13,0,0,0,100,0,24000,24000,24000,24000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smith Slagtree - Script - Set emote state");

DELETE FROM `creature_text` WHERE `entry`=14737 AND `groupid`=0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(14737, 0, 0, 'Don''t fight in broken weapons and armor! Expert armor and weapon repairing done here - while you wait!', 12, 0, 100, 1, 0, 0, 9959, 'Smith Slagtree');

-- Mystic Yayo'jin SAI
SET @ENTRY := 14739;
UPDATE `creature` SET `position_x`=-542.105,`position_y`=-4606.523,`position_z`=13.14816,`orientation`=1.815142 WHERE `guid`=278342;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,36000,36000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - OOC - Play script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Turn run off"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-538.0938,-4609.549,13.13805,0,"Mystic Yayo'jin - Script - Move to"),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.986479,"Mystic Yayo'jin - Script - Turn to"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,2000,2000,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Set emote state"),
(@ENTRY*100,9,4,0,0,0,100,0,6000,6000,6000,6000,69,0,0,0,0,0,0,8,0,0,0,-539.3364,-4606.846,13.14046,0,"Mystic Yayo'jin - Script - Move to"),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,2000,2000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.9773844,"Mystic Yayo'jin - Script - Turn to"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,1000,1000,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Set emote state"),
(@ENTRY*100,9,7,0,0,0,100,0,9000,9000,9000,9000,69,0,0,0,0,0,0,8,0,0,0,-542.105,-4606.523,13.14816,0,"Mystic Yayo'jin - Script - Move to"),
(@ENTRY*100,9,8,0,0,0,100,0,2000,2000,2000,2000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.815142,"Mystic Yayo'jin - Script - Turn to"),
(@ENTRY*100,9,9,0,0,0,100,0,8000,8000,8000,8000,53,0,14739,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Turn to"),
(@ENTRY*100,9,10,0,0,0,100,0,6000,6000,6000,6000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.86234,"Mystic Yayo'jin - Script - Turn to"),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,2000,2000,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Set Bytes_1 'Sit'"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Set emote state"),
(@ENTRY*100,9,13,0,0,0,100,0,34000,34000,34000,34000,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mystic Yayo'jin - Script - Remove Bytes_1 'Sit'");

DELETE from `waypoints` where `entry`=14739;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(14739,1,-543.7079,-4611.147,13.15176,"Mystic Yayo'jin"),
(14739,2,-540.0343,-4611.84,13.14449,"Mystic Yayo'jin"),
(14739,3,-539.916,-4609.014,13.14299,"Mystic Yayo'jin"),
(14739,4,-541.7078,-4608.892,13.14801,"Mystic Yayo'jin");

-- Pathing for Revantusk Watcher Entry: 14730 'TDB FORMAT' 
SET @NPC := 278367;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-559.1216,`position_y`=-4640.588,`position_z`=30.34635 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-559.1216,-4640.588,30.34635,0,0,0,0,100,0),
(@PATH,2,-561.8621,-4639.479,30.34771,0,0,0,0,100,0),
(@PATH,3,-565.1738,-4641.978,30.34876,0,0,0,0,100,0),
(@PATH,4,-568.164,-4644.291,30.34624,0,0,0,0,100,0),
(@PATH,5,-572.6866,-4646.474,28.46771,0,0,0,0,100,0),
(@PATH,6,-576.8602,-4648.417,26.25476,0,0,0,0,100,0),
(@PATH,7,-582.2473,-4647.843,24.64781,0,0,0,0,100,0),
(@PATH,8,-585.2182,-4645.189,22.9425,0,0,0,0,100,0),
(@PATH,9,-585.7538,-4639.803,21.22815,0,0,0,0,100,0),
(@PATH,10,-581.134,-4634.237,19.03621,0,0,0,0,100,0),
(@PATH,11,-576.6482,-4631.978,17.22182,0,0,0,0,100,0),
(@PATH,12,-572.6212,-4631.001,15.46794,0,0,0,0,100,0),
(@PATH,13,-568.9028,-4629.674,13.21041,0,0,0,0,100,0),
(@PATH,14,-565.8718,-4628.861,13.20958,0,0,0,0,100,0),
(@PATH,15,-564.4247,-4626.619,13.21056,0,0,0,0,100,0),
(@PATH,16,-564.7512,-4625.108,12.72349,0,0,0,0,100,0),
(@PATH,17,-565.6238,-4622.17,11.04294,0,0,0,0,100,0),
(@PATH,18,-566.1555,-4615.88,9.739173,0,0,0,0,100,0),
(@PATH,19,-563.2764,-4613.221,9.739173,0,0,0,0,100,0),
(@PATH,20,-559.4357,-4608.517,9.739173,0,0,0,0,100,0),
(@PATH,21,-555.7503,-4601.974,9.614173,0,0,0,0,100,0),
(@PATH,22,-555.0905,-4596.873,9.605314,0,0,0,0,100,0),
(@PATH,23,-552.841,-4589.281,9.605314,0,0,0,0,100,0),
(@PATH,24,-554.7994,-4581.686,9.740568,0,0,0,0,100,0),
(@PATH,25,-559.9419,-4573.958,9.605314,0,0,0,0,100,0),
(@PATH,26,-564.2906,-4571.396,9.480314,0,0,0,0,100,0),
(@PATH,27,-570.6282,-4570.051,9.286489,0,0,0,0,100,0),
(@PATH,28,-576.5599,-4568.717,9.161489,0,0,0,0,100,0),
(@PATH,29,-583.7281,-4567.89,9.120717,0,0,0,0,100,0),
(@PATH,30,-589.5422,-4571.942,9.482045,0,0,0,0,100,0),
(@PATH,31,-595.0231,-4573.951,9.786489,0,0,0,0,100,0),
(@PATH,32,-589.5422,-4571.942,9.482045,0,0,0,0,100,0),
(@PATH,33,-583.7281,-4567.89,9.120717,0,0,0,0,100,0),
(@PATH,34,-576.5599,-4568.717,9.161489,0,0,0,0,100,0),
(@PATH,35,-570.6282,-4570.051,9.286489,0,0,0,0,100,0),
(@PATH,36,-564.2906,-4571.396,9.480314,0,0,0,0,100,0),
(@PATH,37,-559.9419,-4573.958,9.605314,0,0,0,0,100,0),
(@PATH,38,-554.7994,-4581.686,9.740568,0,0,0,0,100,0),
(@PATH,39,-552.841,-4589.281,9.605314,0,0,0,0,100,0),
(@PATH,40,-555.0905,-4596.873,9.605314,0,0,0,0,100,0),
(@PATH,41,-555.7503,-4601.974,9.614173,0,0,0,0,100,0),
(@PATH,42,-559.4357,-4608.517,9.739173,0,0,0,0,100,0),
(@PATH,43,-563.2764,-4613.221,9.739173,0,0,0,0,100,0),
(@PATH,44,-566.1555,-4615.88,9.739173,0,0,0,0,100,0),
(@PATH,45,-566.1465,-4619.271,9.739173,0,0,0,0,100,0),
(@PATH,46,-565.7682,-4621.338,10.51824,0,0,0,0,100,0),
(@PATH,47,-564.9091,-4624.298,12.28793,0,0,0,0,100,0),
(@PATH,48,-564.4247,-4626.619,13.21056,0,0,0,0,100,0),
(@PATH,49,-565.8718,-4628.861,13.20958,0,0,0,0,100,0),
(@PATH,50,-568.9028,-4629.674,13.21041,0,0,0,0,100,0),
(@PATH,51,-572.6212,-4631.001,15.46794,0,0,0,0,100,0),
(@PATH,52,-576.4782,-4631.931,17.15172,0,0,0,0,100,0),
(@PATH,53,-581.1254,-4634.227,19.03236,0,0,0,0,100,0),
(@PATH,54,-585.7308,-4639.775,21.2188,0,0,0,0,100,0),
(@PATH,55,-585.2182,-4645.189,22.9425,0,0,0,0,100,0),
(@PATH,56,-582.2473,-4647.843,24.64781,0,0,0,0,100,0),
(@PATH,57,-576.8602,-4648.417,26.25476,0,0,0,0,100,0),
(@PATH,58,-572.6866,-4646.474,28.46771,0,0,0,0,100,0),
(@PATH,59,-568.164,-4644.291,30.34624,0,0,0,0,100,0),
(@PATH,60,-565.1738,-4641.978,30.34876,0,0,0,0,100,0),
(@PATH,61,-561.8621,-4639.479,30.34771,0,0,0,0,100,0);
-- 0x202F2C00000E62800038470002732169 .go -559.1216 -4640.588 30.34635

-- Pathing for Revantusk Watcher Entry: 14730 'TDB FORMAT' 
SET @NPC := 278372;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-614.1932,`position_y`=-4653.834,`position_z`=5.040805 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-614.1932,-4653.834,5.040805,0,0,0,0,100,0),
(@PATH,2,-620.4515,-4667.109,5.066647,0,0,0,0,100,0),
(@PATH,3,-630.2896,-4686.361,5.10806,0,0,0,0,100,0),
(@PATH,4,-644.1071,-4714.346,5.219751,0,0,0,0,100,0),
(@PATH,5,-630.2896,-4686.361,5.10806,0,0,0,0,100,0),
(@PATH,6,-620.4515,-4667.109,5.066647,0,0,0,0,100,0);
-- 0x202F2C00000E62800038470006F32169 .go -614.1932 -4653.834 5.040805

-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=278372;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(278372,278372,0,0,2),
(278372,278373,3,360,2);

-- Pathing for Revantusk Watcher Entry: 14730 'TDB FORMAT' 
SET @NPC := 278343;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-563.7853,`position_y`=-4572.203,`position_z`=9.480314 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-565.1238,`position_y`=-4574.449,`position_z`=9.548429 WHERE `guid`=278344;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-563.7853,-4572.203,9.480314,0,0,0,0,100,0),
(@PATH,2,-589.0695,-4562.6,9.161489,0,0,0,0,100,0),
(@PATH,3,-584.3304,-4558.535,9.161489,0,0,0,0,100,0),
(@PATH,4,-563.9773,-4568.874,9.527922,0,0,0,0,100,0),
(@PATH,5,-551.5903,-4548.764,10.15376,0,0,0,0,100,0),
(@PATH,6,-529.4497,-4536.548,11.02155,0,0,0,0,100,0),
(@PATH,7,-528.6646,-4538.769,10.74298,0,0,0,0,100,0),
(@PATH,8,-549.9079,-4550.587,9.985304,0,0,0,0,100,0),
(@PATH,9,-561.3011,-4570.924,9.605314,0,0,0,0,100,0),
(@PATH,10,-553.2903,-4587.01,9.647795,0,0,0,0,100,0),
(@PATH,11,-561.1612,-4612.59,9.864173,0,0,0,0,100,0),
(@PATH,12,-588.2601,-4616.572,9.456761,0,0,0,0,100,0),
(@PATH,13,-599.4961,-4630.079,9.579808,0,0,0,0,100,0),
(@PATH,14,-589.3387,-4615.174,9.456761,0,0,0,0,100,0),
(@PATH,15,-565.2857,-4617.084,9.739173,0,0,0,0,100,0),
(@PATH,16,-555.2867,-4586.42,9.730314,0,0,0,0,100,0);
-- 0x202F2C00000E62800038470008F32169 .go -563.7853 -4572.203 9.480314

-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=278343;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(278343,278343,0,0,2),
(278343,278344,3,270,2);
--
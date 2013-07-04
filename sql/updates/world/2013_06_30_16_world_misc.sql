-- Add SAI to Warosh
SET @WAROSH := 10799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@WAROSH;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@WAROSH;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WAROSH,0,0,0,1,0,100,0,20000,20000,20000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warosh -  OOC - Say 0');
-- Text for Warosh
DELETE FROM `creature_text` WHERE `entry` IN (@WAROSH);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@WAROSH,0,0,'%s cries.',16,0,100,0,0,0,'Warosh'),
(@WAROSH,0,1,'%s snorts.',16,0,100,0,0,0,'Warosh'),
(@WAROSH,0,2,'%s grumbles.',16,0,100,0,0,0,'Warosh');

-- Add missing and path Warosh Entry: 10799
SET @NPC := 17;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,10799,229,1,1,0,0,81.104,-479.903,30.86245,3.124139,7200,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,81.104,-479.903,30.86245,0,0,0,0,100,0),
(@PATH,2,73.26363,-487.8571,27.89152,0,0,0,0,100,0),
(@PATH,3,54.61135,-489.3818,28.67157,0,0,0,0,100,0),
(@PATH,4,44.71681,-491.037,29.5888,0,0,0,0,100,0),
(@PATH,5,52.57936,-511.4861,29.06968,0,0,0,0,100,0),
(@PATH,6,50.58394,-533.1805,26.7767,0,0,0,0,100,0),
(@PATH,7,50.20008,-560.1547,30.55615,0,0,0,0,100,0),
(@PATH,8,50.46281,-576.035,30.58308,0,0,0,0,100,0),
(@PATH,9,39.68649,-579.5075,31.06343,0,0,0,0,100,0),
(@PATH,10,17.70853,-578.2368,26.5612,0,0,0,0,100,0),
(@PATH,11,-5.465746,-576.0652,29.19087,0,0,0,0,100,0),
(@PATH,12,-27.13421,-574.506,29.19087,0,0,0,0,100,0),
(@PATH,13,-47.66818,-572.6104,29.19087,0,0,0,0,100,0),
(@PATH,14,-60.44478,-573.6581,29.19087,0,0,0,0,100,0),
(@PATH,15,-43.34514,-571.0668,29.19087,0,0,0,0,100,0),
(@PATH,16,-36.48037,-563.5282,29.19087,0,0,0,0,100,0),
(@PATH,17,-48.5064,-537.1736,29.19087,0,0,0,0,100,0),
(@PATH,18,-36.48037,-563.5282,29.19087,0,0,0,0,100,0),
(@PATH,19,-43.34514,-571.0668,29.19087,0,0,0,0,100,0),
(@PATH,20,-60.44478,-573.6581,29.19087,0,0,0,0,100,0),
(@PATH,21,-47.66818,-572.6104,29.19087,0,0,0,0,100,0),
(@PATH,22,-27.13421,-574.506,29.19087,0,0,0,0,100,0),
(@PATH,23,-5.465746,-576.0652,29.19087,0,0,0,0,100,0),
(@PATH,24,17.42213,-578.2202,26.65305,0,0,0,0,100,0),
(@PATH,25,39.67855,-579.5101,31.09808,0,0,0,0,100,0),
(@PATH,26,50.46281,-576.035,30.58308,0,0,0,0,100,0),
(@PATH,27,50.20008,-560.1547,30.55615,0,0,0,0,100,0),
(@PATH,28,50.58394,-533.1805,26.7767,0,0,0,0,100,0),
(@PATH,29,52.60767,-511.5597,29.21094,0,0,0,0,100,0),
(@PATH,30,44.71681,-491.037,29.5888,0,0,0,0,100,0),
(@PATH,31,54.37603,-489.401,28.65347,0,51000,0,0,100,0),
(@PATH,32,73.26363,-487.8571,27.89152,0,0,0,0,100,0),
(@PATH,33,81.104,-479.903,30.86245,0,0,0,0,100,0),
(@PATH,34,78.66329,-463.2451,35.48121,0,0,0,0,100,0),
(@PATH,35,71.58976,-436.8153,41.41042,0,0,0,0,100,0),
(@PATH,36,58.41603,-418.7091,45.02646,0,0,0,0,100,0),
(@PATH,37,49.90298,-402.1319,48.80593,0,0,0,0,100,0),
(@PATH,38,46.01845,-387.0023,48.69103,0,0,0,0,100,0),
(@PATH,39,49.90298,-402.1319,48.80593,0,0,0,0,100,0),
(@PATH,40,58.41603,-418.7091,45.02646,0,0,0,0,100,0),
(@PATH,41,71.58976,-436.8153,41.41042,0,0,0,0,100,0);
-- 0xF130002A2F01FCD8 .go 81.104 -479.903 30.86245

-- Pathing for Spirestone Butcher Entry: 9219
SET @NPC := 43523;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-36.58493,`position_y`=-441.9179,`position_z`=31.83226 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-36.58493,-441.9179,31.83226,0,0,0,0,100,0),
(@PATH,2,-37.40374,-482.51,29.62917,0,0,0,0,100,0),
(@PATH,3,-37.18431,-487.9846,29.38416,0,0,0,0,100,0),
(@PATH,4,-37.40374,-482.51,29.62917,0,0,0,0,100,0),
(@PATH,5,-36.58493,-441.9179,31.83226,0,0,0,0,100,0),
(@PATH,6,-37.03431,-412.0911,31.57773,0,0,0,0,100,0);
-- .go -36.58493 -441.9179 31.83226

-- Pathing for Smolderthorn Mystic Entry: 9239
SET @NPC := 43527;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2.398426,`position_y`=-461.1257,`position_z`=16.14088 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2.398426,-461.1257,16.14088,0,0,0,0,100,0),
(@PATH,2,2.359199,-464.0517,16.06489,0,0,0,0,100,0),
(@PATH,3,2.3592,-464.0517,16.06489,2.216568,21000,0,0,100,0),
(@PATH,4,1.288787,-463.5652,16.07071,0,0,0,0,100,0),
(@PATH,5,-2.044648,-461.8262,16.13557,0,0,0,0,100,0),
(@PATH,6,-7.927852,-461.18,16.73,0,0,0,0,100,0),
(@PATH,7,-15.24469,-460.3805,16.55355,0,0,0,0,100,0),
(@PATH,8,-21.31746,-455.7214,16.58231,0,0,0,0,100,0),
(@PATH,9,-22.68492,-451.7054,16.6012,0,0,0,0,100,0),
(@PATH,10,-22.68492,-451.7054,16.6012,0.7504916,23000,0,0,100,0),
(@PATH,11,-19.41172,-457.9942,16.57828,0,0,0,0,100,0),
(@PATH,12,-13.95378,-460.6527,16.58616,0,0,0,0,100,0),
(@PATH,13,-7.328142,-460.9917,16.72944,0,0,0,0,100,0);
-- .go -2.398426 -461.1257 16.14088

-- 
-- battlemage
SET @NPC := 136529;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-800.089,`position_y`=-226.5122,`position_z`=430.2167 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH; 
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-797.0466,-234.7317,429.8668,5.203247,25000,0,0,100,0),
(@PATH,2,-801.40063,-232.04281,429.8417,3.129789,0,0,0,100,0),
(@PATH,3,-807.65612,-231.57901,429.8417,3.015907,0,0,0,100,0),
(@PATH,4,-811.0604,-233.729,429.841,4.30792,25000,0,0,100,0),
(@PATH,5,-814.1212,-219.8692,429.9667,0,0,0,0,100,0),
(@PATH,6,-820.0264,-221.115,429.843,3.963378,25000,0,0,100,0),
(@PATH,7,-810.8352,-217.8873,429.9667,0,0,0,0,100,0),
(@PATH,8,-804.5867,-221.2963,430.2167,0,0,0,0,100,0),
(@PATH,9,-800.0966,-226.504,430.2167,0,0,0,0,100,0);
-- formerguy
SET @NPC := 136271;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-797.4893,`position_y`=-68.99318,`position_z`=430.355 WHERE `guid`=@NPC;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=0,`position_x`=-797.4893,`position_y`=-68.99318,`position_z`=430.355 WHERE `guid` IN (136263, 136264);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-797.4893,-68.99318,430.355,0,0,0,0,100,0),
(@PATH,2,-797.2393,-103.7432,430.355,0,0,0,0,100,0),
(@PATH,3,-801.9893,-142.7432,430.355,0,0,0,0,100,0),
(@PATH,4,-814.9893,-160.9932,430.355,0,0,0,0,100,0),
(@PATH,5,-831.4893,-165.9932,441.355,0,0,0,0,100,0),
(@PATH,6,-846.4893,-163.9932,452.105,0,0,0,0,100,0),
(@PATH,7,-855.9893,-164.2432,459.105,0,0,0,0,100,0),
(@PATH,8,-868.4705,-163.9879,458.8668,0,0,0,0,100,0),
(@PATH,9,-856.1097,-160.0616,459.1042,0,0,0,0,100,0),
(@PATH,10,-837.1097,-159.0616,445.3542,0,0,0,0,100,0),
(@PATH,11,-813.1097,-159.5616,430.3542,0,0,0,0,100,0),
(@PATH,12,-797.8597,-176.3116,430.3542,0,0,0,0,100,0),
(@PATH,13,-787.6097,-186.5616,430.3542,0,0,0,0,100,0),
(@PATH,14,-772.1097,-186.3116,430.3542,0,0,0,0,100,0),
(@PATH,15,-756.3597,-184.3116,430.3542,0,0,0,0,100,0),
(@PATH,16,-742.8285,-179.7665,429.89,0,0,0,0,100,0),
(@PATH,17,-735.0785,-160.2665,429.89,0,0,0,0,100,0),
(@PATH,18,-733.5785,-132.5165,429.89,0,0,0,0,100,0),
(@PATH,19,-735.0785,-105.5165,429.89,0,0,0,0,100,0),
(@PATH,20,-726.8285,-86.51649,429.89,0,0,0,0,100,0),
(@PATH,21,-711.0785,-81.01649,429.89,0,0,0,0,100,0),
(@PATH,22,-722.208,-80.19803,429.8908,0,0,0,0,100,0),
(@PATH,23,-735.458,-99.19803,429.8908,0,0,0,0,100,0),
(@PATH,24,-735.958,-124.948,429.8908,0,0,0,0,100,0),
(@PATH,25,-739.208,-154.448,429.8908,0,0,0,0,100,0),
(@PATH,26,-748.958,-176.448,429.8908,0,0,0,0,100,0),
(@PATH,27,-773.958,-186.448,429.8908,0,0,0,0,100,0),
(@PATH,28,-794.958,-180.948,429.8908,0,0,0,0,100,0),
(@PATH,29,-802.458,-153.698,429.8908,0,0,0,0,100,0),
(@PATH,30,-799.958,-131.948,429.6408,0,0,0,0,100,0),
(@PATH,31,-800.208,-108.948,429.8908,0,0,0,0,100,0),
(@PATH,32,-797.708,-86.19803,429.8908,0,0,0,0,100,0),
(@PATH,33,-796.458,-66.44803,429.8908,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=136271;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(136271, 136271, 0, 0, 515, 0, 0),
(136271, 136263, 3, 90, 515, 0, 0),
(136271, 136264, 3, 270, 515, 0, 0);

-- channelguys
-- Kirin Tor Battle-Mage SAI
SET @GUID := -136528;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,5000,5000,11,48310,0,0,0,0,0,10,137508,33779,0,0,0,0,0,"Kirin Tor Battle-Mage - Out of Combat - Cast 'Transitus Shield Beam'");

-- Kirin Tor Battle-Mage SAI
SET @GUID := -136525;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,1000,1000,5000,5000,11,48310,0,0,0,0,0,10,137507,33779,0,0,0,0,0,"Kirin Tor Battle-Mage - On Reset - Cast 'Transitus Shield Beam'");

-- portal visuals mage
-- Kirin Tor Battle-Mage SAI
SET @GUID := -136523;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,5000,5000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin Tor Battle-Mage - Out of Combat - Cast Portal");

-- portal event
-- first mage
-- Kirin Tor Mage SAI
SET @GUID := -136553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,1,0,100,0,5000,5000,50000,50000,80,13655300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Run Script"),
(@GUID,0,1,0,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Set Visibility On");

-- Actionlist SAI
SET @ENTRY := 13655300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Simple Teleport'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-815.467712,-228.523056,429.841766,4.479870,"On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Add Aura 'Kneel'"),
(@ENTRY,9,3,0,0,0,100,0,20000,20000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-814.755310,-201.520081,429.841766,1.837791,"On Script - Move To Position"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Simple Teleport'"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Visibility Off");

-- second mage
-- Kirin Tor Mage SAI
SET @GUID := -136552;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,1,0,100,0,5000,5000,30000,30000,80,13655200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Run Script"),
(@GUID,0,1,0,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Set Visibility On");

-- Actionlist SAI
SET @ENTRY := 13655200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Simple Teleport'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-818.564209,-208.605743,429.841736,3.791860,"On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Add Aura 'Kneel'"),
(@ENTRY,9,3,0,0,0,100,0,10000,10000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-814.755310,-201.520081,429.841766,1.837791,"On Script - Move To Position"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Simple Teleport'"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Visibility Off");

-- wrong emotestate, only used during event
DELETE FROM `creature_template_addon` WHERE  `entry`=33672;
-- mage laugh script
-- Emote ID: OneShotYes (273)
-- Emote ID: OneShotTalk (1)
-- Emote ID: OneShotQuestion (6)
-- Emote ID: OneShotNo (274)
-- Emote ID: OneShotExclamation (5)
-- Kirin Tor Mage SAI
SET @GUID := -136538;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

-- Kirin Tor Battle-Mage SAI
SET @GUID := -136521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Battle-Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

-- Kirin Tor Mage SAI
SET @GUID := -136539;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

-- Kirin Tor Battle-Mage SAI
SET @GUID := -136522;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33662;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Battle-Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

-- Kirin Tor Mage SAI
SET @GUID := -136546;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

-- Kirin Tor Mage SAI
SET @GUID := -136545;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=33672;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,3000,4000,3000,4000,10,273,1,6,274,5,0,1,0,0,0,0,0,0,0,"Kirin Tor Mage - Out of Combat - Play Random Emote (273, 1, 6, 274, 5)");

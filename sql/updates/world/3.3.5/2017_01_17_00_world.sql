-- Instructor Razuvious - Event with Acherus Necromancer and Death Knight Initiate -- http://wow.gamepedia.com/Death_Knight_Initiate
-- Instructor Razuvious
SET @NPC := 129307;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`) VALUES
(@PATH, 1, 2481.1, -5560.54, 420.493, 5.58015, 0),
(@PATH, 2, 2491.86, -5571.77, 420.459, 5.3508, 0),
(@PATH, 3, 2497.91, -5588.32, 420.462, 4.9212, 0),
(@PATH, 4, 2494.03, -5612.09, 420.491, 1.24868, 0),
(@PATH, 5, 2498.68, -5591.69, 420.494, 1.78118, 0),
(@PATH, 6, 2492.94, -5573.05, 420.475, 2.14717, 0),
(@PATH, 7, 2475.93, -5558.57, 420.485, 2.79199, 0),
(@PATH, 8, 2455.66, -5554.78, 420.508, 0.040735, 0),
(@PATH, 9, 2472.56, -5558.04, 420.453, 6.06788, 0),
(@PATH, 10, 2481.1, -5560.54, 420.493, 5.58015, 0),
(@PATH, 11, 2491.86, -5571.77, 420.459, 5.3508, 0),
(@PATH, 12, 2497.91, -5588.32, 420.462, 4.9212, 0),
(@PATH, 13, 2494.03, -5612.09, 420.491, 1.24868, 0),
(@PATH, 14, 2498.68, -5591.69, 420.494, 1.78118, 0),
(@PATH, 15, 2492.94, -5573.05, 420.475, 2.14717, 0),
(@PATH, 16, 2475.93, -5558.57, 420.485, 2.79199, 0),
(@PATH, 17, 2455.66, -5554.78, 420.508, 0.040735, 0),
(@PATH, 18, 2472.56, -5558.04, 420.453, 6.06788, 0),
(@PATH, 19, 2481.1, -5560.54, 420.493, 5.58, 0),
(@PATH, 20, 2482.32, -5552.39, 420.641, 1.51, 70000),
(@PATH, 21, 2491.86, -5571.77, 420.459, 5.351, 0),
(@PATH, 22, 2497.91, -5588.32, 420.462, 4.9212, 0),
(@PATH, 23, 2494.03, -5612.09, 420.491, 1.24868, 0),
(@PATH, 24, 2498.68, -5591.69, 420.494, 1.78118, 0),
(@PATH, 25, 2492.94, -5573.05, 420.475, 2.14717, 0),
(@PATH, 26, 2475.93, -5558.57, 420.485, 2.79199, 0),
(@PATH, 27, 2455.66, -5554.78, 420.508, 0.040735, 0),
(@PATH, 28, 2472.56, -5558.04, 420.453, 6.06788, 0),
(@PATH, 29, 2481.1, -5560.54, 420.493, 5.58015, 0),
(@PATH, 30, 2491.86, -5571.77, 420.459, 5.3508, 0),
(@PATH, 31, 2497.91, -5588.32, 420.462, 4.9212, 0),
(@PATH, 32, 2494.03, -5612.09, 420.491, 1.24868, 0),
(@PATH, 33, 2498.68, -5591.69, 420.494, 1.78118, 0),
(@PATH, 34, 2492.94, -5573.05, 420.475, 2.14717, 0),
(@PATH, 35, 2475.93, -5558.57, 420.485, 2.79199, 0),
(@PATH, 36, 2455.66, -5554.78, 420.508, 0.040735, 0),
(@PATH, 37, 2472.56, -5558.04, 420.453, 6.06788, 0),
(@PATH, 38, 2481.1, -5560.54, 420.493, 5.58015, 0),
(@PATH, 39, 2491.86, -5571.77, 420.459, 5.3508, 0),
(@PATH, 40, 2497.91, -5588.32, 420.462, 4.9212, 0),
(@PATH, 41, 2494.03, -5612.09, 420.491, 1.24868, 0),
(@PATH, 42, 2498.68, -5591.69, 420.494, 1.78118, 0),
(@PATH, 43, 2510.38, -5592.75, 420.643, 6.19, 75000),
(@PATH, 44, 2492.94, -5573.05, 420.475, 2.147, 0),
(@PATH, 45, 2475.93, -5558.57, 420.485, 2.79, 0),
(@PATH, 46, 2455.66, -5554.78, 420.508, 0.040735, 0),
(@PATH, 47, 2472.56, -5558.04, 420.453, 6.06788, 0);

-- Instructor Razuvious SAI
SET @ENTRY := 28357;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,34,0,100,0,2,19,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Razuvious - On Reached Point 19 - Run Script"),
(@ENTRY,0,1,0,34,0,100,0,2,42,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Razuvious - On Reached Point 42 - Run Script"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.78367,"Instructor Razuvious - On Data Set 1 1 - Set Orientation 2.78367"),
(@ENTRY,0,3,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.50472,"Instructor Razuvious - On Data Set 2 2 - Set Orientation 1.50472"),
(@ENTRY,0,4,0,38,0,100,0,3,3,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.26755,"Instructor Razuvious - On Data Set 3 3 - Set Orientation 1.26755"),
(@ENTRY,0,5,0,38,0,100,0,4,4,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.19669,"Instructor Razuvious - On Data Set 4 4 - Set Orientation 6,19669");

-- Actionlist SAI
SET @ENTRY := 2835700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,129391,28383,0,0,0,0,0,"On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 2835701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,129390,28383,0,0,0,0,0,"On Script - Set Data 1 1");

-- Acherus Necromancer SAI
SET @GUID := -129391;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28383;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,38,0,100,0,1,1,0,0,80,12939100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Data Set 1 1 - Run Script"),
(@GUID,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Data Set 1 1 - Set Active On");

UPDATE `creature` SET `id`=28391, `spawntimesecs`=1, `modelid`=25361 WHERE  `guid` IN (130292);
UPDATE `creature` SET `position_x`=2477.361328, `position_y`=-5538.785156, `position_z`=420.645264, `orientation`=4.889500 WHERE  `guid`=129458;
DELETE FROM `creature` WHERE `guid`=129452;
UPDATE `creature` SET `spawntimesecs`=1 WHERE  `guid`=129459;

-- Actionlist SAI
SET @ENTRY := 12939100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,11,51516,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cast 'Raise Dead'"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,86,51517,0,10,130292,28391,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cross Cast 'Raise Dead'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,28,29266,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Aura 'Permanent Feign Death'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,96,32,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Dynamic Flag Dead"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,19,537165824,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Stunned"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,19,1,1,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Server Controlled"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Standstate Dead"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,91,257,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag <Unknown bytes1 (UnitStandStateType)>"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,2,1770,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Set Faction 1770"),
(@ENTRY,9,9,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 1 1"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,11,0,0,0,100,0,4000,4000,0,0,1,0,5000,0,0,0,0,26,28391,50,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 0"),
(@ENTRY,9,12,0,0,0,100,0,5000,5000,0,0,1,1,5000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 1"),
(@ENTRY,9,13,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 1 1"),
(@ENTRY,9,14,0,0,0,100,0,3000,3000,0,0,1,2,5000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 2"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 2 2"),
(@ENTRY,9,16,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 0"),
(@ENTRY,9,17,0,0,0,100,0,4000,4000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Set Run Off"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2482.23,-5546.44,420.644,0.761266,"Acherus Necromancer - On Script - Move To Position"),
(@ENTRY,9,19,0,0,0,100,0,4000,4000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Set Emote State 133"),
(@ENTRY,9,20,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Set Emote State 0"),
(@ENTRY,9,21,0,0,0,100,0,0,0,0,0,86,51537,0,10,130292,28391,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cross Cast 'Death Knight Initiate (Female, Dwarf)'"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,3,0,25406,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Morph To Model 25406"),
(@ENTRY,9,23,0,0,0,100,0,2000,2000,0,0,86,51519,0,10,130292,28391,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cross Cast 'Death Knight Initiate Visual'"),
(@ENTRY,9,24,0,0,0,100,0,2000,2000,0,0,91,8,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Standstate Kneel"),
(@ENTRY,9,25,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2477.37,-5551,420.647,0.77,"Acherus Necromancer - On Script - Move To Position"),
(@ENTRY,9,26,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.746414,"Acherus Necromancer - On Script - Set Orientation 0.746414"),
(@ENTRY,9,27,0,0,0,100,0,1000,1000,0,0,1,3,5000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 3"),
(@ENTRY,9,28,0,0,0,100,0,5000,5000,0,0,1,1,5000,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 1"),
(@ENTRY,9,29,0,0,0,100,0,1000,1000,0,0,48,1,0,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Set Active On"),
(@ENTRY,9,30,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,130292,28391,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 2 2"),
(@ENTRY,9,31,0,0,0,100,0,1000,1000,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Set Active Off");

-- Acherus Necromancer SAI
SET @GUID := -129390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28383;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,38,0,100,0,1,1,0,0,80,12939000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Data Set 1 1 - Run Script"),
(@GUID,0,1,0,61,0,100,0,1,1,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Data Set 1 1 - Set Active On");

-- Actionlist SAI
SET @ENTRY := 12939000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,11,51516,0,1,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cross Cast 'Raise Dead'"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,86,51517,0,10,129459,28394,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Cross Cast 'Raise Dead'"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,28,29266,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Aura 'Permanent Feign Death'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,96,32,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Dynamic Flag Dead"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,19,537165824,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Stunned"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,19,1,1,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Server Controlled"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Standstate Dead"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,91,257,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Remove Flag Dead"),
(@ENTRY,9,8,0,0,0,100,0,2000,2000,0,0,2,1770,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Set Faction 1770"),
(@ENTRY,9,9,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 1 1"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,11,0,0,0,100,0,4000,4000,0,0,1,0,5000,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 0"),
(@ENTRY,9,12,0,0,0,100,0,5000,5000,0,0,1,4,5000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 4"),
(@ENTRY,9,13,0,0,0,100,0,6000,6000,0,0,1,5,6000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 5"),
(@ENTRY,9,14,0,0,0,100,0,5000,5000,0,0,45,3,3,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 3 3"),
(@ENTRY,9,15,0,0,0,100,0,4000,4000,0,0,1,6,6000,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 6"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,45,4,4,0,0,0,0,10,129307,28357,0,0,0,0,0,"Acherus Necromancer - On Script - Set Data 4 4"),
(@ENTRY,9,17,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 0"),
(@ENTRY,9,18,0,0,0,100,0,5000,5000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Say Line 1"),
(@ENTRY,9,19,0,0,0,100,0,4000,4000,0,0,12,28405,3,19000,0,0,0,8,0,0,0,2520.44,-5593.01,420.727,3.4383,"Acherus Necromancer - On Script - Summon Creature 'Acherus Ghoul'"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,12,28405,3,19000,0,0,0,8,0,0,0,2516.65,-5596.68,420.727,1.39626,"Acherus Necromancer - On Script - Summon Creature 'Acherus Ghoul'"),
(@ENTRY,9,21,0,0,0,100,0,0,0,0,0,12,28405,3,19000,0,0,0,8,0,0,0,2515.93,-5589.89,420.727,4.92183,"Acherus Necromancer - On Script - Summon Creature 'Acherus Ghoul'"),
(@ENTRY,9,22,0,0,0,100,0,20000,20000,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Necromancer - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `entry` IN (28357, 28383, 28391, 28394);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
-- Instructor Razuvious
(28357, 0, 0, 'This one...', 12, 0, 100, 25, 0, 0, 27876, 'Instructor Razuvious'),
(28357, 1, 0, 'The Lich King will be pleased with this initiate.', 12, 0, 100, 5, 0, 0, 27869, 'Instructor Razuvious'),
(28357, 1, 1, 'Amidst the wretch, a champion has been found.', 12, 0, 100, 5, 0, 0, 27870, 'Instructor Razuvious'),
(28357, 1, 2, 'CHAOS! DOOM! DESTRUCTION! This one will claim them all!', 12, 0, 100, 5, 0, 0, 27871, 'Instructor Razuvious'),
(28357, 1, 3, 'Marvel at its tenacity and vigor! A champion has been found!', 12, 0, 100, 5, 0, 0, 27868, 'Instructor Razuvious'),
(28357, 1, 4, 'A harbinger of death is reborn...', 12, 0, 100, 5, 0, 0, 27872, 'Instructor Razuvious'),
(28357, 2, 0, 'Place upon it the trappings befitting a herald of Arthas.', 12, 0, 100, 1, 0, 0, 27873, 'Instructor Razuvious'),
(28357, 3, 0, 'Stand and be measured! Rise, for your master awaits your arrival. Go now!', 12, 0, 100, 5, 0, 0, 27883, 'Instructor Razuvious'),
(28357, 3, 1, 'Listen, death knight... Listen for the voice of your master. He calls to you now.', 12, 0, 100, 5, 0, 0, 27884, 'Instructor Razuvious'),
(28357, 4, 0, 'Pathetic...', 12, 0, 100, 1, 0, 0, 27865, 'Instructor Razuvious'),
(28357, 4, 1, 'Useless...', 12, 0, 100, 1, 0, 0, 27862, 'Instructor Razuvious'),
(28357, 4, 2, 'Another failure...', 12, 0, 100, 1, 0, 0, 27861, 'Instructor Razuvious'),
(28357, 4, 3, 'This one has awoken too soon. It retains emotion and memory...', 12, 0, 100, 1, 0, 0, 27864, 'Instructor Razuvious'),
(28357, 5, 0, 'You have been measured and found wanting...', 12, 0, 100, 25, 0, 0, 27866, 'Instructor Razuvious'),
(28357, 6, 0, 'Dispose of it...', 12, 0, 100, 1, 0, 0, 27867, 'Instructor Razuvious'),
-- Acherus Necromancer
(28383, 0, 0, 'Yes, instructor.', 12, 0, 100, 1, 0, 0, 27874, 'Acherus Necromancer'),
(28383, 0, 1, 'Right away, instructor.', 12, 0, 100, 1, 0, 0, 27881, 'Acherus Necromancer'),
(28383, 1, 0, 'Rise, minions. Rise and feast upon the weak!', 12, 0, 100, 22, 0, 0, 27875, 'Acherus Necromancer'),
-- Death Knight Initiate 1
(28391, 0, 0, 'I return from the grave to do my master\'s bidding.', 12, 0, 100, 0, 0, 0, 27880, 'Death Knight Initiate'),
(28391, 0, 1, 'The voice... such splendor... Arthas... My king....', 12, 0, 100, 0, 0, 0, 27879, 'Death Knight Initiate'),
(28391, 0, 2, 'Reborn, I shall become an instrument of doom...', 12, 0, 100, 0, 0, 0, 27878, 'Death Knight Initiate'),
(28391, 0, 3, 'Dark energy courses through me... Such power! I hunger for more!', 12, 0, 100, 0, 0, 0, 27877, 'Death Knight Initiate'),
(28391, 1, 0, 'Death to all that oppose us!', 12, 0, 100, 66, 0, 0, 27888, 'Death Knight Initiate'),
(28391, 1, 1, 'Victory to the Scourge!', 12, 0, 100, 66, 0, 0, 27887, 'Death Knight Initiate'),
(28391, 1, 2, 'I live only to serve the Lich King!', 12, 0, 100, 66, 0, 0, 27886, 'Death Knight Initiate'),
(28391, 1, 3, 'As you command, instructor!', 12, 0, 100, 66, 0, 0, 27885, 'Death Knight Initiate'),
(28391, 2, 0, 'Woe unto those that dare oppose the Scourge!', 12, 0, 100, 66, 0, 0, 30176, 'Death Knight Initiate'),
(28391, 2, 1, 'I am reborn, my king, only to serve you.', 12, 0, 100, 66, 0, 0, 30179, 'Death Knight Initiate'),
(28391, 2, 2, 'I am an instrument of your destruction, my king! Command me!', 12, 0, 100, 66, 0, 0, 30175, 'Death Knight Initiate'),
(28391, 2, 3, 'Our enemies will be annihilated!', 12, 0, 100, 66, 0, 0, 30177, 'Death Knight Initiate'),
(28391, 2, 4, 'A thousand-thousand lives I will sacrifice for you, my lord.', 12, 0, 100, 66, 0, 0, 30172, 'Death Knight Initiate'),
(28391, 2, 5, 'I am yours to command, my king!', 12, 0, 100, 66, 0, 0, 30173, 'Death Knight Initiate'),
(28391, 2, 6, 'There will be no survivors, my lord.', 12, 0, 100, 66, 0, 0, 30180, 'Death Knight Initiate'),
(28391, 2, 7, 'My king, the world will tremble in reverence...', 12, 0, 100, 66, 0, 0, 30174, 'Death Knight Initiate'),
-- Death Knight Initiate 2
(28394, 0, 0, 'Where am I? What is this place?', 12, 0, 100, 0, 0, 0, 27856, 'Death Knight Initiate'),
(28394, 0, 1, 'Who... who are you? Who... what am I?', 12, 0, 100, 0, 0, 0, 27858, 'Death Knight Initiate'),
(28394, 0, 2, 'I hurt... suffering unbearable... end my pain... I beg of you!', 12, 0, 100, 0, 0, 0, 27859, 'Death Knight Initiate'),
(28394, 0, 3, 'I... I have awoken to a nightmare?', 12, 0, 100, 0, 0, 0, 27857, 'Death Knight Initiate');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry` IN (51516);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 51516, 0, 0, 31, 0, 3, 28394, 0, 0, 0, 0, '', 'Rise dead only targets Death Knight Initiate'),
(13, 1, 51516, 0, 1, 31, 0, 3, 28391, 0, 0, 0, 0, '', 'Rise dead only targets Death Knight Initiate');

-- Death Knight Initiate SAI
SET @ENTRY := 28391;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.16204,"Death Knight Initiate - On Data Set 1 1 - Set Orientation 4.16204"),
(@ENTRY,0,1,6,38,0,100,0,2,2,0,0,53,1,28391,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Data Set 2 2 - Start Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,7,28391,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Waypoint 7 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,7,28391,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,9,28391,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Waypoint 9 Reached - Despawn In 2000 ms"),
(@ENTRY,0,5,0,25,0,100,0,0,0,0,0,18,295170,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Reset - Set Flags Not Attackable & Immune To Players & Stunned"),
(@ENTRY,0,6,0,61,0,100,0,2,2,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Data Set 2 2 - Set Active On");

-- Actionlist SAI
SET @ENTRY := 2839100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Script - Play Emote 66"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Script - Say Line 2"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Script - Play Emote 2");

DELETE FROM `waypoints` WHERE `entry`=28391;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(28391,1,2453.87,-5545.37,420.643,'Death Knight Initiate'), 
(28391,2,2423.38,-5574.52,420.631,'Death Knight Initiate'),
(28391,3,2423.38,-5610.59,420.6,'Death Knight Initiate'),
(28391,4,2410.19,-5626.02,420.654,'Death Knight Initiate'),
(28391,5,2381.18,-5637.17,420.858,'Death Knight Initiate'),
(28391,6,2372.68,-5645.34,426.017,'Death Knight Initiate'),
(28391,7,2348.248,-5666.514,426.029,'Death Knight Initiate'),
(28391,8,2373.07,-5652.69,426.126,'Death Knight Initiate'),
(28391,9,2382.63,-5645.56,421.512,'Death Knight Initiate');

-- Death Knight Initiate SAI
SET @ENTRY := 28394;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.07005,"Death Knight Initiate - On Data Set 1 1 - Set Orientation 3.07005"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,18,295170,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Initiate - On Reset - Set Flags Not Attackable & Immune To Players & Stunned");

-- Acherus Ghoul SAI
SET @ENTRY := 28405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Ghoul - On Just Created - Run Script");

-- Actionlist SAI
SET @ENTRY := 2840500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,373,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Ghoul - On Script - Set Emote State 373"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Ghoul - On Script - Cast 'Birth'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Ghoul - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,2,2093,0,0,0,0,0,1,0,0,0,0,0,0,0,"Acherus Ghoul - On Script - Set Faction 2093"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,19,514,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Ghoul - On Script - Remove Flags Not Attackable & Immune To NPC's"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,10,129459,28394,0,0,0,0,0,"Acherus Ghoul - On Script - Start Attacking");

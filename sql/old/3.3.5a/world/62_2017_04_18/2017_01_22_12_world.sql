-- Footman Rob + Footman Chuck + Footman George + Footman Mitch - Path and Textevent

-- Footman Rob SAI
SET @ENTRY := 25258;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,34,0,100,1,2,5,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 5 - Run Script (No Repeat)"),
(@ENTRY,0,1,0,34,0,100,0,2,9,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 9 - Run Script"),
(@ENTRY,0,2,0,34,0,100,0,2,10,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 10 - Run Script"),
(@ENTRY,0,3,0,34,0,100,1,2,15,0,0,12,25260,3,180000,0,0,0,8,0,0,0,2255.77,5186.26,11.4391,1.47479,"Footman Rob - On Reached Point 15 - Summon Creature 'Footman Mitch' (No Repeat)"),
(@ENTRY,0,4,0,34,0,100,0,2,17,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 17 - Run Script"),
(@ENTRY,0,5,0,17,0,100,0,25260,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Footman Rob - On Summoned Unit - Store Targetlist"),
(@ENTRY,0,6,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)"),
(@ENTRY,0,7,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)"),
(@ENTRY,0,8,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)");

-- Actionlist SAI -- Stop in Front of house
SET @ENTRY := 2525800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Say Line 0");

-- Actionlist SAI - stop in front of barkeeper
SET @ENTRY := 2525801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,0,6000,0,0,0,0,10,110613,25245,0,0,0,0,0,"Footman Rob - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,1,1,6000,0,0,0,0,10,110613,25245,0,0,0,0,0,"Footman Rob - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,5,397,0,0,0,0,0,10,110613,25245,0,0,0,0,0,"Footman Rob - On Script - Play Emote 397"),
(@ENTRY,9,5,0,0,0,100,0,7000,7000,0,0,17,423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 423"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,9,0,0,0,100,0,5000,5000,0,0,17,423,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 423"),
(@ENTRY,9,10,0,0,0,100,0,0,0,0,0,17,423,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 423"),
(@ENTRY,9,11,0,0,0,100,0,22000,22000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 0"),
(@ENTRY,9,12,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Set Emote State 0"),
(@ENTRY,9,14,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,16,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,17,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(@ENTRY,9,19,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment");

-- Actionlist SAI - prepare leave building
SET @ENTRY := 2525802; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Line 3"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,0,6000,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Play Emote 11"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Play Emote 11"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Play Emote 11"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Play Emote 274"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,5,274,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Play Emote 274"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,5,274,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Play Emote 274");

-- Actionlist SAI - despawn all member
SET @ENTRY := 2525803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,10,85222,25259,0,0,0,0,0,"Footman Rob - On Script - Despawn Instant"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,10,85226,25261,0,0,0,0,0,"Footman Rob - On Script - Despawn Instant"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Footman Rob - On Script - Despawn Instant"),
(@ENTRY,9,3,0,0,0,100,0,100,100,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Despawn Instant");
UPDATE `creature_template` SET `flags_extra`=2, `InhabitType`=3 WHERE  `entry` IN (25259, 25258, 25261);

-- Footman George SAI
SET @ENTRY := 25259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.282578,"Footman George - On Data Set 1 1 - Set Orientation 4,282578");

-- Footman Chuck SAI
SET @ENTRY := 25261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.28258,"Footman Chuck - On Data Set 1 1 - Set Orientation 4.28258");

-- Footman Mitch SAI
SET @ENTRY := 25260;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,0,0,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Mitch - On Just Created - Say Line 0"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Mitch - On Just Created - Set Run Off"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2264.93652,5221.9863,11.2882,4.3713,"Footman Mitch - On Just Created - Move To Position");

-- texts
DELETE FROM `creature_text` WHERE `entry` IN (25259, 25258, 25261, 25260, 25245);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
-- Footman Rob
(25258, 0, 0, 'One last drink before we head to the front?', 12, 7, 100, 1, 0, 0, 24475, 'Footman Rob'),
(25258, 1, 0, 'Barkeep!  Bring out your strongest ale.  We''re off to the front.', 12, 7, 100, 1, 0, 0, 24478, 'Footman Rob'),
(25258, 2, 0, 'You''ll surely make an exception for us, eh?  We might not come back.', 12, 7, 100, 1, 0, 0, 24479, 'Footman Rob'),
(25258, 3, 0, 'I guess that''s it then.  Off we go.', 12, 7, 100, 1, 0, 0, 24482, 'Footman Rob'),
-- Footman George
(25259, 0, 0, 'Sure, why not?', 12, 7, 100, 6, 0, 0, 24476, 'Footman George'),
-- Footman Chuck
(25261, 0, 0, 'That was the worst beer I''ve ever had.', 12, 7, 100, 0, 0, 0, 24483, 'Footman Chuck'),
-- Footman Mitch
(25260, 0, 0, 'Hey, guys!  Wait up!', 12, 7, 100, 0, 0, 0, 24761, 'Footman Mitch'),
-- James Deacon
(25245, 0, 0, 'You lads know the drill.  No alcohol to servicemen on duty.  You want the general to kill me himself?', 12, 7, 100, 274, 0, 0, 24744, 'James Deacon'),
(25245, 1, 0, 'All right, all right... but you didn''t get these from me!', 12, 7, 100, 6, 0, 0, 24745, 'James Deacon');

-- Formation
DELETE FROM `creature_formations` WHERE `leaderGUID`= 85221;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(85221, 85221, 0, 0, 4, 0, 0),   -- Rob
(85221, 85222, 2, 305, 4, 0, 0), -- George
(85221, 85226, 2, 55, 4, 0, 0);  -- Chuck

-- Waypoints for Rob
SET @NPC := 85221;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 2277.23, 5177.21, 11.34, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 2268.97, 5175.55, 11.1665, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2254.59, 5188.89, 11.384, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2254.27, 5196.42, 11.3837, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 2260.67, 5200.36, 11.3711, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2264.38, 5199.09, 11.3676, 0, 13000, 0, 0, 100, 0), -- stop in front
(@PATH, 7, 2270.18, 5196.94, 12.4959, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2275.23, 5194.94, 12.49, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2276.23, 5197.58, 12.4896, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 2279.08, 5206.5, 12.494, 0, 60000, 0, 0, 100, 0), -- stop beer
(@PATH, 11, 2278.6, 5205.3, 12.4926, 0, 16000, 0, 0, 100, 0), -- stop go
(@PATH, 12, 2275.55, 5197.84, 12.4897, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 2275.60, 5194.96, 12.489, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 2265.21, 5198.54, 11.3533, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 2258.23, 5201.82, 11.3182, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 2258.98, 5205.83, 11.322, 0, 0, 0, 0, 100, 0), -- summon friend
(@PATH, 17, 2261, 5212.02, 11.2373, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 2268.17, 5226.07, 11.2421, 0, 5000, 0, 0, 100, 0); -- despawn

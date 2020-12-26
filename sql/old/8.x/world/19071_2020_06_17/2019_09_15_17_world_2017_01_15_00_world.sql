-- "Cookie McWeaksauce -- http://wotlk.openwow.com/npc=17246
UPDATE `creature` SET `position_x`=-4710.87, `position_y`=-12400.6, `position_z`=12.1142, `orientation`=1.1577 WHERE  `guid`=61976;
-- "Cookie" McWeaksauce SAI
SET @ENTRY := 17246;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Just Summoned - Play Emote 10"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,17246,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,2,17246,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,4,17246,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,5,17246,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,6,17246,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,10,17246,0,0,80,@ENTRY*100+05,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 10 Reached - Run Script"),
(@ENTRY,0,8,0,40,0,100,0,13,17246,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,9,0,40,0,100,0,18,17246,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 18 Reached - Run Script"),
(@ENTRY,0,10,0,40,0,100,0,19,17246,0,0,80,@ENTRY*100+06,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Waypoint 19 Reached - Run Script"),
(@ENTRY,0,11,0,25,0,100,0,0,0,0,0,53,0,17246,1,0,0,1,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Reset - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 1724600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.957318,"Cookie McWeaksauce - On Script - Set Orientation 0,957318");

-- Actionlist SAI
SET @ENTRY := 1724601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.957318,"Cookie McWeaksauce - On Script - Set Orientation 0,957318"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Active On"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Orientation Closest Creature 'Admiral Odesyus'"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 0"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,5,6,0,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Play Emote 6");

-- Actionlist SAI
SET @ENTRY := 1724602;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,48000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.20039,"Cookie McWeaksauce - On Script - Set Orientation 5.20039"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,6000,6000,0,0,1,1,3000,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,5,6,0,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Play Emote 6"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 3"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,11,30221,0,0,0,0,0,19,620,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Cast 'Shoot'"),
(@ENTRY,9,9,0,0,0,100,0,4000,4000,0,0,1,4,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 4"),
(@ENTRY,9,10,0,0,0,100,0,4000,4000,0,0,1,2,5000,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Say Line 2"),
(@ENTRY,9,11,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,10,61965,17240,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Data 2 2");

-- Actionlist SAI
SET @ENTRY := 1724603;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.957318,"Cookie McWeaksauce - On Script - Set Orientation 0,957318");

-- Actionlist SAI
SET @ENTRY := 1724604;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,26000,26000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Set Emote State 0");

-- Actionlist SAI
SET @ENTRY := 1724605;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.40099,"Cookie McWeaksauce - On Script - Set Orientation 3,40099"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Play Emote 16");

-- Actionlist SAI
SET @ENTRY := 1724606;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie McWeaksauce - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.957318,"Cookie McWeaksauce - On Script - Set Orientation 0,957318");

-- Buddy Target Scripts
-- Admiral Odesyus SAI
SET @ENTRY := 17240;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,33,17240,0,0,0,0,0,7,0,0,0,0,0,0,0,"Admiral Odesyus - On Gossip Hello - Quest Credit ''"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Odesyus - On Just Summoned - Set Event Phase 1"),
(@ENTRY,0,2,0,1,1,100,0,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Admiral Odesyus - Out of Combat - Play Emote 10 (Phase 1)"),
(@ENTRY,0,3,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,19,17246,20,0,0,0,0,0,"Admiral Odesyus - On Data Set 1 1 - Set Orientation Closest Creature 'Cookie McWeaksauce'"),
(@ENTRY,0,4,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.380780,"Admiral Odesyus - On Data Set 2 2 - Set Orientation 4,380780");

UPDATE `creature_text` SET `BroadcastTextId`=13703 WHERE  `CreatureID`=17246 AND `GroupID`=3 AND `ID`=0;

DELETE FROM `waypoints` WHERE `entry`=17246;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17246,1,-4708.59,-12400.3,11.8799,  'Cookie McWeaksauce'),
(17246,2,-4708.59,-12400.3,11.8799,  'Cookie McWeaksauce'),
(17246,3,-4704.573,-12405.38,12.4597,'Cookie McWeaksauce'),
(17246,4,-4704.573,-12405.38,12.4597,'Cookie McWeaksauce'),
(17246,5,-4708.59,-12400.3,11.8799,  'Cookie McWeaksauce'),
(17246,6,-4708.59,-12400.3,11.8799,  'Cookie McWeaksauce'),
(17246,7,-4706.2,-12401.6,12.0858,   'Cookie McWeaksauce'),
(17246,8,-4702.63,-12401.1,11.7653,  'Cookie McWeaksauce'),
(17246,9,-4699.89,-12398.4,11.6181,  'Cookie McWeaksauce'),
(17246,10,-4700.77,-12395,11.6193,   'Cookie McWeaksauce'),
(17246,11,-4703.86,-12392.2,11.6306, 'Cookie McWeaksauce'),
(17246,12,-4707.55,-12390.8,11.7246, 'Cookie McWeaksauce'),
(17246,13,-4710.58,-12394,11.8418,   'Cookie McWeaksauce'),
(17246,14,-4713.32,-12394.2,11.7392, 'Cookie McWeaksauce'),
(17246,15,-4714.78,-12398.2,11.8794, 'Cookie McWeaksauce'),
(17246,16,-4715.03,-12401.5,11.9805, 'Cookie McWeaksauce'),
(17246,17,-4713.15,-12405.1,12.0613, 'Cookie McWeaksauce'),
(17246,18,-4710.72,-12400.9,11.8921, 'Cookie McWeaksauce'),
(17246,19,-4708.59,-12400.3,11.8799, 'Cookie McWeaksauce');

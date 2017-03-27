-- Missing spawns 
SET @GUID_1 := 73937; -- ONE FREE GUID SET BY TC
DELETE FROM `creature` WHERE `guid` = @GUID_1;
INSERT INTO `creature` (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType) VALUES 
-- Exodar Invisible stalker
(@GUID_1,18814,530,1,1,0,0,-3669.94,-11450.8,-114.348,4.31096,300,0,0,42,0,0);

-- Hobahken
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 63013;
-- Hobahken SAI
SET @ENTRY := 17519;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,53,0,17519,1,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Reset - Start Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,5,17519,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,10,17519,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Waypoint 10 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,16,17519,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Waypoint 16 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1751900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.95367,"Hobahken - On Script - Set Orientation 4,95367"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Play Emote 25"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,11,32993,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Cast 'Fire Cast Visual'"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,@GUID_1,18814,0,0,0,0,0,"Hobahken - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Play Emote 15");

-- Actionlist SAI
SET @ENTRY := 1751901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.0094,"Hobahken - On Script - Set Orientation 1,0094"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Play Emote 25"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,11,32993,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Cast 'Fire Cast Visual'"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67183,18814,0,0,0,0,0,"Hobahken - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Play Emote 15");

-- Actionlist SAI
SET @ENTRY := 1751902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.16139,"Hobahken - On Script - Set Orientation 3,16139"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,54,240000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,235000,235000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobahken - On Script - Remove Flag Standstate Kneel");

-- Exodar Invisible Stalker SAI
SET @GUID := -@GUID_1;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18814;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,11,33002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Flame Strike Impact Visual'");

-- Exodar Invisible Stalker SAI
SET @GUID := -67183;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,11,33002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Flame Strike Impact Visual'");

DELETE FROM `waypoints` WHERE `entry`=17519;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17519,1,-3668.56,-11437.6,-118.19, 'Hobahken'),
(17519,2,-3671.81,-11439.1,-118.235, 'Hobahken'),
(17519,3,-3673.06,-11442.1,-118.261, 'Hobahken'),
(17519,4,-3673.06,-11444.6,-118.27, 'Hobahken'),
(17519,5,-3671.56,-11447.3,-118.264, 'Hobahken'), 
(17519,6,-3678.77,-11443.1,-118.331, 'Hobahken'), 
(17519,7,-3680.02,-11433.8,-118.312, 'Hobahken'),
(17519,8,-3676.52,-11430.3,-118.256, 'Hobahken'),
(17519,9,-3674.02,-11429.6,-118.225, 'Hobahken'),
(17519,10,-3674.48,-11427.8,-118.224, 'Hobahken'),
(17519,11,-3671.77,-11431.3,-118.205, 'Hobahken'),
(17519,12,-3667.77,-11431.8,-118.158, 'Hobahken'),
(17519,13,-3663.27,-11432.6,-118.11, 'Hobahken'),
(17519,14,-3661.02,-11435.8,-118.096, 'Hobahken'),
(17519,15,-3662.52,-11436.6,-118.116, 'Hobahken'),
(17519,16,-3665.56,-11436.8,-118.154, 'Hobahken');

-- 
-- Sulaa Waypointscript
UPDATE `creature` SET spawndist = 0, MovementType = 0 WHERE guid = 61958;
UPDATE `creature_template_addon` SET bytes1 = 0 WHERE Entry = 17219;

-- Sulaa SAI
SET @ENTRY := 17219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,17219,1,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,17219,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,4,17219,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,8,17219,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Waypoint 8 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,12,17219,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Waypoint 12 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1721900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,300000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,32992,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Cast 'Ice Cast Visual'"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67179,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67176,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Play Emote 4"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67175,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67180,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,10,67173,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67178,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 1721901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,32992,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Cast 'Ice Cast Visual'"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67179,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67181,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67182,18814,0,0,0,0,0,"Sulaa - On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 1721902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,11,32992,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Ice Cast Visual'"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,10,67176,18814,0,0,0,0,0,"On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67171,18814,0,0,0,0,0,"On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,67172,18814,0,0,0,0,0,"On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 1721903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,2,0,0,0,100,0,7000,7000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sulaa - On Script - Remove Flag Standstate Kneel");


DELETE FROM `waypoints` WHERE `entry`=17219;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17219,1,-3778.78,-11409.2,-137.952, 'Sulaa'),
(17219,2,-3778.9,-11411.9,-137.96, 'Sulaa'),
(17219,3,-3779.4,-11415.4,-137.982, 'Sulaa'),
(17219,4,-3775.53,-11420.1,-137.955, 'Sulaa'),
(17219,5,-3777.94,-11421.6,-137.988, 'Sulaa'),
(17219,6,-3781.69,-11422.3,-138.036, 'Sulaa'),
(17219,7,-3788.19,-11418.6,-138.097, 'Sulaa'),
(17219,8,-3789.85,-11414.1,-138.101, 'Sulaa'),
(17219,9,-3788.37,-11413.7,-138.081, 'Sulaa'),
(17219,10,-3783.87,-11414.4,-138.031, 'Sulaa'),
(17219,11,-3779.87,-11410.7,-137.97, 'Sulaa'),
(17219,12,-3777.9,-11407.2,-137.934, 'Sulaa');

-- Exodar Invisible Stalker SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18814;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-67179, -67176, -67175, -67180, -67173, -67178, -67181, -67182, -67171, -67172) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-67179,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67176,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67175,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67180,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67173,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67178,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67181,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67182,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67171,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'"),
(-67172,0,0,0,38,0,100,0,1,1,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exodar Invisible Stalker - On Data Set 1 1 - Cast 'Water Elemental Impact Visual'");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=17436;

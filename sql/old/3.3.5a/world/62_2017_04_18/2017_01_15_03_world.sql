-- Consortium Nether Runner -- http://wotlk.openwow.com/npc=19667
UPDATE `creature` SET `position_x`=-2057.45, `position_y`=8528.71, `position_z`=24.6556, `orientation`=2.05449, `spawntimesecs`=120 WHERE  `guid`=70166;

-- Consortium Nether Runner SAI
SET @ENTRY := 19667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,19667,0,0,0,1,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,1,19667,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,5,19667,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,8,19667,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Waypoint 8 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1966700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.05449,"Consortium Nether Runner - On Script - Set Orientation 2.05449"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Script - Cast 'Ethereal Teleport'");

-- Actionlist SAI
SET @ENTRY := 1966701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.57111,"Consortium Nether Runner - On Script - Set Orientation 3.57111"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,0,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,65554,18265,0,0,0,0,0,"Consortium Nether Runner - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,0,5000,0,0,0,0,10,65554,18265,0,0,0,0,0,"Consortium Nether Runner - On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Nether Runner - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,65554,18265,0,0,0,0,0,"Consortium Nether Runner - On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 1966702;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.573574,"On Script - Set Orientation 0,573574"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Ethereal Teleport'"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

-- Buddy AI
-- Gezhe SAI
SET @ENTRY := 18265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,10,70166,19667,0,0,0,0,0,"Gezhe - On Data Set 1 1 - Set Orientation Closest Creature 'Consortium Nether Runner'"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.513270,"Gezhe - On Data Set 2 2 - Set Orientation 2,513270");

DELETE FROM `creature_text` WHERE `entry` IN (19667, 18265);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
-- Consortium Nether Runner
(19667, 0, 0, 'Hail, Gezhe!  Seventeen more orders have been placed in the Hara''samid Sector.  The markets of heavy veldarite have all but collapsed, as you predicted.', 12, 0, 100, 0, 0, 0, 17184, 'Consortium Nether Runner'),
(19667, 0, 1, 'Heraazi exports are on the rise, sir.  We''ve already bribed the appropriate taxation officers and contraband will begin to arrive within days.', 12, 0, 100, 0, 0, 0, 17186, 'Consortium Nether Runner'),
(19667, 1, 0, 'By your leave, sir.', 12, 0, 100, 0, 0, 0, 17185, 'Consortium Nether Runner'),
-- Gezhe
(18265, 0, 0, 'Nothing surprising there.  Come back with some real news, will you?', 12, 0, 100, 0, 0, 0, 17191, 'Gezhe'),
(18265, 0, 1, 'As expected.  Very well, dismissed.', 12, 0, 100, 0, 0, 0, 17190, 'Gezhe');

DELETE FROM `waypoints` WHERE `entry`=19667;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19667, 1, -2057.45, 8528.71, 24.6556, 'Consortium Nether Runner'),
(19667, 2, -2058.23, 8547.79, 24.0203, 'Consortium Nether Runner'),
(19667, 3, -2064.09, 8554.57, 23.9054, 'Consortium Nether Runner'),
(19667, 4, -2075.08, 8562.74, 22.9801, 'Consortium Nether Runner'),
(19667, 5, -2083.14, 8565.28, 22.0791, 'Consortium Nether Runner'),
(19667, 6, -2062.94, 8574.57, 23.1942, 'Consortium Nether Runner'),
(19667, 7, -2056.25, 8597.59, 21.3663, 'Consortium Nether Runner'),
(19667, 8, -2049.12, 8603.37, 22.7377, 'Consortium Nether Runner');

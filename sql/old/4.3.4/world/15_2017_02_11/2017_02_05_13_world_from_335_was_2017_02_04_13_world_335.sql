/*
-- Saving Sharpbeak
-- Sharpbeak's Cage SAI
SET @ENTRY := 144070;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,45,1,0,0,0,0,0,19,8023,20,0,0,0,0,0,"Sharpbeak's Cage - On Gameobject State Changed - Set Data 1 0");
UPDATE `creature` SET `spawntimesecs`=60 WHERE  `guid`=92997;

-- Sharpbeak SAI
SET @ENTRY := 8023;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak - On Data Set 1 0 - Remove Flag Standstate Dead"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,53,0,8023,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak - On Data Set 1 0 - Start Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak - On Data Set 1 0 - Set Active On"),
(@ENTRY,0,3,0,58,0,100,0,1,8023,0,0,12,8024,3,120000,0,0,0,8,0,0,0,-150.362167,-3511.225830,274.172699,4.062795,"Sharpbeak - On Waypoint 1 Reached - Summon Creature 'Sharpbeak's Father'"),
(@ENTRY,0,4,0,38,0,100,0,2,0,0,0,29,2,270,0,0,0,0,19,8024,10,0,0,0,0,0,"Sharpbeak - On Data Set 2 0 - Start Follow Closest Creature 'Sharpbeak's Father'"),
(@ENTRY,0,5,0,38,0,100,0,3,0,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Sharpbeak - On Data Set 3 0 - Say Line 0"),
(@ENTRY,0,6,0,38,0,100,0,4,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak - On Data Set 4 0 - Despawn Instant");

-- waypoints
DELETE FROM `waypoints` WHERE `entry` IN (8023, 8024);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(8023, 1, -229.494385, -3623.708740, 237.462433, 'Sharpbeak'),
(8024, 1, -230.034515, -3627.350098, 237.616638, 'Sharpbeak father'),
(8024, 2, -244.359818, -3638.187500, 236.659546, 'Sharpbeak father'),
(8024, 3, -227.883606, -3624.622314, 237.235733, 'Sharpbeak father'),
(8024, 4, -122.637520, -3502.211914, 256.078064, 'Sharpbeak father');

UPDATE `creature_template` SET `InhabitType`=4, `speed_walk`=2 WHERE  `entry` IN (8024, 8025, 8023);

-- Sharpbeak's Father SAI
SET @ENTRY := 8024;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Father - On Just Summoned - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,53,0,8024,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Father - On Just Summoned - Start Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,12,8025,3,120000,0,0,0,8,0,0,0,-168.569000,-3509.420166,276.238770,4.320847,"Sharpbeak's Father - On Just Summoned - Summon Creature 'Sharpbeak's Mother'"),
(@ENTRY,0,3,0,40,0,100,0,1,8024,0,0,45,2,0,0,0,0,0,19,8023,20,0,0,0,0,0,"Sharpbeak's Father - On Waypoint 1 Reached - Set Data 2 0"),
(@ENTRY,0,4,0,40,0,100,0,2,8024,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Father - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,3,8024,0,0,45,3,0,0,0,0,0,19,8023,20,0,0,0,0,0,"Sharpbeak's Father - On Waypoint 3 Reached - Set Data 3 0"),
(@ENTRY,0,6,7,40,0,100,0,4,8024,0,0,45,4,0,0,0,0,0,9,0,0,100,0,0,0,0,"Sharpbeak's Father - On Waypoint 4 Reached - Set Data 4 0"),
(@ENTRY,0,7,0,61,0,100,0,4,8024,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Father - On Waypoint 4 Reached - Despawn Instant");

-- Sharpbeak's Mother SAI
SET @ENTRY := 8025;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Mother - On Just Summoned - Set Active On"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,29,2,90,0,0,0,0,19,8024,20,0,0,0,0,0,"Sharpbeak's Mother - On Just Summoned - Start Follow Closest Creature 'Sharpbeak's Father'"),
(@ENTRY,0,2,0,38,0,100,0,4,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sharpbeak's Mother - On Data Set 4 0 - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`= 8023;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8023, 0, 0, '%s chirps a goodbye to $n.', 16, 0, 100, 0, 0, 0, 4138, 0, 'Sharpbeak');
*/

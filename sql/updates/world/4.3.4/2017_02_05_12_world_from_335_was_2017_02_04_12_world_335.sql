/*
-- Ursal the Mauler SAI
SET @ENTRY := 2039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,2000,2000,4000,4000,11,15793,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ursal the Mauler - In Combat - Cast 'Maul'"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,2852,100,0,0,0,0,0,"Ursal the Mauler - On Just Died - Set Data 2 2");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=2852;

-- Enslaved Druid of the Talon SAI
SET @ENTRY := 2852;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,2,2,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Data Set 2 2 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,3,2852,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Waypoint 3 Reached - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 285200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Remove Flag Standstate Sleep"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,3,2853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Morph To Creature Freed Druid of the Talon"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,53,1,2852,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 285201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Remove Flag Standstate Sleep"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,3,2853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Morph To Creature Freed Druid of the Talon"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,53,1,2852,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Script - Start Waypoint");

-- Enslaved Druid of the Talon SAI -- -GUID script because only one of the creatures should say the text
SET @ENTRY := -46215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,2,2,0,0,80,285201,2,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Data Set 2 2 - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,3,2852,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Waypoint 3 Reached - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=2852;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(2852, 0, 0, 'The nightmare of Ursal is over! We are free!', 12, 0, 100, 0, 0, 0, 888, 'Enslaved Druid of the Talon');

DELETE FROM `waypoints` WHERE `entry`=2852;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2852, 1, 9091.11, 1857.64, 1333.71, 'Enslaved Druid of the Talon'),
(2852, 2, 9079.52, 1872.34, 1334.99, 'Enslaved Druid of the Talon'),
(2852, 3, 9024.94, 1885.46, 1334.4,  'Enslaved Druid of the Talon');

-- Reduce respawn to match the respawn of Ursal the Mauler
UPDATE `creature` SET `spawntimesecs`=250 WHERE  `id`=2852;

-- Pathing for Ursal the Mauler
SET @NPC := 49853;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 9126.92, 1838.24, 1327.72, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 9130.38, 1838.8, 1327.49, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 9133.83, 1839.37, 1327.41, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 9131.32, 1838.38, 1327.59, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 9123.09, 1836.68, 1328.18, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 9119.33, 1833.02, 1328.6, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 9115.33, 1823.32, 1328.29, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 9112.83, 1816.78, 1326.97, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 9111.58, 1816.75, 1327.09, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 9110.26, 1827, 1328.74, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 9105.49, 1832.93, 1328.29, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 9100.95, 1840.46, 1327.68, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 9105.24, 1843.42, 1327.53, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 9109.59, 1840.99, 1327.5, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 9120.07, 1836.26, 1328.29, 0, 0, 0, 0, 100, 0);
*/

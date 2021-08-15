-- https://www.youtube.com/watch?v=KAIgaV6dK8Q & https://www.youtube.com/watch?v=bR-xmDJIzD4 & https://github.com/cmangos/issues/issues/1678
UPDATE `creature_template` SET `unit_flags2` = 0, `dynamicflags` = 0 WHERE `entry` = 17768;
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 17768;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17768 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1776800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17768,0,0,0,8,0,100,1,31225,0,0,0,0,80,1776800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Spellhit 'Shimmering Vessel' - Run Script (No Repeat)"),
(17768,0,1,0,40,0,100,0,8,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Waypoint 8 Reached - Despawn Instant"),

(1776800,9,0,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Remove Flag Standstate Dead"),
(1776800,9,1,0,0,0,100,0,0,0,0,0,0,11,25155,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Cast 'Quest - Self Healing from resurrect'"),
(1776800,9,2,0,0,0,100,0,0,0,0,0,0,33,17768,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Quest Credit 'Redeeming the Dead'"),
(1776800,9,3,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Set Orientation Invoker"),
(1776800,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Say Line 0"),
(1776800,9,5,0,0,0,100,0,6000,6000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Say Line 1"),
(1776800,9,6,0,0,0,100,0,0,0,0,0,0,53,0,17768,0,0,0,3,1,0,0,0,0,0,0,0,0,"Blood Knight Stillblade - On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry` = 17768;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17768,1,9674.297852,-7375.656738,22.837454,0,0,"Blood Knight Stillblade"),
(17768,2,9682.087891,-7378.194824,22.844015,0,0,"Blood Knight Stillblade"),
(17768,3,9698.202148,-7378.187988,22.854086,0,0,"Blood Knight Stillblade"),
(17768,4,9702.776367,-7376.458496,20.979189,0,0,"Blood Knight Stillblade"),
(17768,5,9706.027344,-7370.661133,17.425856,0,0,"Blood Knight Stillblade"),
(17768,6,9704.005859,-7365.672363,14.453255,0,0,"Blood Knight Stillblade"),
(17768,7,9687.491211,-7366.161133,11.929653,0,0,"Blood Knight Stillblade"),
(17768,8,9683.428711,-7364.722656,11.931114,0,0,"Blood Knight Stillblade");

-- https://github.com/cmangos/issues/issues/1678
UPDATE `creature_template` SET `speed_walk` = 0.666668, `speed_run` = 1.42857, `unit_flags2` = 0 WHERE `entry` = 17542;
UPDATE `creature_template_addon` SET `bytes1` = 7, `auras` = '' WHERE `entry` = 17542;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17542 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1754200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17542,0,0,0,8,0,100,1,8593,0,0,0,0,80,1754200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Spellhit 'Symbol of Life' - Run Script (No Repeat)"),
(17542,0,1,0,40,0,100,0,4,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Waypoint 4 Reached - Despawn Instant"),

(1754200,9,0,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Remove Flag Standstate Dead"),
(1754200,9,1,0,0,0,100,0,0,0,0,0,0,11,25155,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Cast 'Quest - Self Healing from resurrect'"),
(1754200,9,2,0,0,0,100,0,0,0,0,0,0,33,17542,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Quest Credit 'Redemption'"),
(1754200,9,3,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Set Orientation Invoker"),
(1754200,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Say Line 0"),
(1754200,9,5,0,0,0,100,0,6000,6000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Say Line 1"),
(1754200,9,6,0,0,0,100,0,0,0,0,0,0,53,1,17542,0,0,0,3,1,0,0,0,0,0,0,0,0,"Young Furbolg Shaman - On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry` = 17542;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17542,1,-2444.689,-12207.18,32.8721,0,0,"Young Furbolg Shaman"),
(17542,2,-2443.185,-12220.92,31.8721,0,0,"Young Furbolg Shaman"),
(17542,3,-2435.321,-12240.7,32.0348,0,0,"Young Furbolg Shaman"),
(17542,4,-2423.951,-12278.52,27.72987,0,0,"Young Furbolg Shaman");

DELETE FROM `creature_text` WHERE `CreatureID` = 17542;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17542,0,0,"%s stares at you in sheer wonderment.",16,0,100,0,0,0,14109,0,"Young Furbolg Shaman"),
(17542,1,0,"I run now!",12,0,100,0,0,0,14110,0,"Young Furbolg Shaman");

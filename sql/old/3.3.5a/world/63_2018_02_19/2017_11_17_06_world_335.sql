-- Tsunaman
UPDATE `creature` SET `position_x`=824.854, `position_y`=933.05, `position_z`=155.485, `orientation`=2.16375 WHERE `guid`=29247;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11862;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11862 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1186200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11862,0,0,0,1,0,100,0,5000,5000,80000,100000,53,0,11862,0,0,0,0,1,0,0,0,0,0,0,0,"Tsunaman - Out of Combat - Start Waypoint"),
(11862,0,1,0,40,0,100,0,1,11862,0,0,80,1186200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tsunaman - On Waypoint 1 Reached - Run Script"),
(11862,0,2,0,40,0,100,0,2,11862,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.16375,"Tsunaman - On Waypoint 2 Reached - Set Orientation"),
(1186200,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tsunaman - On Script - Pause Waypoint"),
(1186200,9,1,0,0,0,100,0,2000,2000,0,0,17,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tsunaman - On Script - Set Emote State 'Attack Unarmed'"),
(1186200,9,2,0,0,0,100,0,16000,16000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tsunaman - On Script - Set Emote State 0");

DELETE FROM `waypoints` WHERE `entry`=11862;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(11862,1,818.627,941.855,154.26,""),
(11862,2,824.854,933.05,155.485,"");

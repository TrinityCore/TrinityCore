-- Thun'grim Firegaze
DELETE FROM `creature_text` WHERE `CreatureID`=5878;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5878,0,0,"%s begins to work...",16,0,100,0,0,0,2348,0,"Thun'grim Firegaze"),
(5878,1,0,"Your armor is ready, $n.",12,1,100,1,0,0,2634,0,"Thun'grim Firegaze");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5878;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5878 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (587800,587801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5878,0,0,0,20,0,100,0,1838,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Quest 'Brutal Armor' Finished - Remove Npc Flag Questgiver"),
(5878,0,1,0,20,0,100,0,1838,0,0,0,53,0,5878,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Quest 'Brutal Armor' Finished - Start Waypoint"),
(5878,0,2,0,40,0,100,0,3,5878,0,0,80,587800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Waypoint 3 Reached - Run Script"),
(5878,0,3,0,40,0,100,0,6,5878,0,0,80,587801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Waypoint 6 Reached - Run Script"),
(587800,9,0,0,0,0,100,0,0,0,0,0,54,39000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Pause Waypoint"),
(587800,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.92829,"Thun'grim Firegaze - On Script - Set Orientation"),
(587800,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Say Line 0"),
(587800,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Set Emote State 69"),
(587800,9,4,0,0,0,100,0,15000,15000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Set Emote State 0"),
(587800,9,5,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.30012,"Thun'grim Firegaze - On Script - Set Orientation"),
(587800,9,6,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Set Emote State 233"),
(587800,9,7,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Set Emote State 0"),
(587801,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.820305,"Thun'grim Firegaze - On Script - Set Orientation"),
(587801,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Say Line 1"),
(587801,9,2,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thun'grim Firegaze - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=5878;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(5878,1,-423.713,-3167.24,212.779,""),
(5878,2,-423.211,-3164.23,212.864,""),
(5878,3,-425.1,-3162.25,212.697,""),
(5878,4,-423.211,-3164.23,212.864,""),
(5878,5,-423.713,-3167.24,212.779,""),
(5878,6,-437.62,-3176.26,211.385,"");

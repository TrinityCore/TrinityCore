-- 
-- Jordan Stilwell
DELETE FROM `creature_text` WHERE `CreatureID`=6181;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6181,0,0,"Let's get to work, $n!",12,0,100,1,0,0,2501,0,"Jordan Stilwell"),
(6181,1,0,"Here you are, $n.",12,0,100,1,0,0,2504,0,"Jordan Stilwell");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6181;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6181 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (618100,618101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6181,0,0,0,19,0,100,0,1806,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Quest 'The Test of Righteousness (Part 3)' Taken - Remove Npc Flag Questgiver"),
(6181,0,1,0,19,0,100,0,1806,0,0,0,53,0,6181,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Quest 'The Test of Righteousness (Part 3)' Taken - Start Waypoint"),
(6181,0,2,0,19,0,100,0,1806,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Quest 'The Test of Righteousness (Part 3)' Taken - Say Line 0"),
(6181,0,3,0,40,0,100,0,1,6181,0,0,80,618100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Waypoint 1 Reached - Run Script"),
(6181,0,4,0,40,0,100,0,2,6181,0,0,80,618101,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Waypoint 2 Reached - Run Script"),
(618100,9,0,0,0,0,100,0,0,0,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Script - Pause Waypoint"),
(618100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.90077,"Jordan Stilwell - On Script - Set Orientation"),
(618100,9,2,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Script - Set Emote State 233"),
(618100,9,3,0,0,0,100,0,21000,21000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Script - Set Emote State 0"),
(618101,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.77704,"Jordan Stilwell - On Script - Set Orientation"),
(618101,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Script - Say Line 1"),
(618101,9,2,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jordan Stilwell - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=6181;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6181,1,-5094.12,-786.116,495.226,""),
(6181,2,-5089.28,-782.95,495.279,"");

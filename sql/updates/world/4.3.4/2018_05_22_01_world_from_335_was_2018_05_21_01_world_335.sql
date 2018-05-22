/*
-- 
-- Wynne Larson
DELETE FROM `creature_text` WHERE `CreatureID`=1309;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1309,0,0,"These are fine pieces, $n.  Let me get started on your robe.",12,7,100,1,0,0,2647,0,"Wynne Larson"),
(1309,1,0,"That's it!  It's all finished, $n.",12,7,100,1,0,0,2648,0,"Wynne Larson"),
(1309,2,0,"Ok, let's get to work!",12,7,100,0,0,0,2649,0,"Wynne Larson"),
(1309,3,0,"Now where did I put that silver spool...",12,7,100,0,0,0,2651,0,"Wynne Larson"),
(1309,4,0,"Aha!  There it is.",12,7,100,0,0,0,2650,0,"Wynne Larson");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1309;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1309 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (130900,130901,130902,130903) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1309,0,0,0,20,0,100,0,1921,0,0,0,80,130900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Quest 'Gathering Materials' Finished - Run Script"),
(1309,0,1,0,20,0,100,0,1940,0,0,0,80,130901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Quest 'Pristine Spider Silk' Finished - Run Script"),
(1309,0,2,0,40,0,100,0,1,1309,0,0,80,130902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Waypoint 1 Reached - Run Script"),
(1309,0,3,0,40,0,100,0,2,1309,0,0,80,130903,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Waypoint 2 Reached - Run Script"),
(130900,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Remove Npc Flag Questgiver"),
(130900,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Say Line 0"),
(130900,9,2,0,0,0,100,0,4000,4000,0,0,11,9157,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Cast 'Create Mage's Robe'"),
(130900,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Say Line 1"),
(130900,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Add Npc Flag Questgiver"),
(130901,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Remove Npc Flag Questgiver"),
(130901,9,1,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Say Line 2"),
(130901,9,2,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Say Line 3"),
(130901,9,3,0,0,0,100,0,2000,2000,0,0,53,0,1309,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Start Waypoint"),
(130902,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Pause Waypoint"),
(130902,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.80513,"Wynne Larson - On Script - Set Orientation"),
(130902,9,2,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Say Line 4"),
(130902,9,3,0,0,0,100,0,3000,3000,0,0,11,9157,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Cast 'Create Mage's Robe'"),
(130903,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.846,"Wynne Larson - On Script - Set Orientation"),
(130903,9,1,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wynne Larson - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=1309;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1309,1,-8964.6,824.703,109.447,""),
(1309,2,-8963,822.517,109.447,"");
*/

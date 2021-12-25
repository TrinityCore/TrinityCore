-- Furen Longbeard
DELETE FROM `creature_text` WHERE `CreatureID`=5413;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5413,0,0,"%s begins to work...",16,0,100,0,0,0,2341,0,"Furen Longbeard"),
(5413,1,0,"Finished!  And the results are amazing.  I must convey them to my associates Grimand, Mathiel and Klockmort!",12,7,100,4,0,0,2342,0,"Furen Longbeard"),
(5413,2,0,"Your armor is ready, $n.",12,7,100,1,0,0,2343,0,"Furen Longbeard");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5413;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5413 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (541300,541301,541302) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5413,0,0,0,20,0,100,0,1701,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Quest 'Fire Hardened Mail' Finished - Remove Npc Flag Questgiver"),
(5413,0,1,0,20,0,100,0,1701,0,0,0,53,0,5413,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Quest 'Fire Hardened Mail' Finished - Start Waypoint"),
(5413,0,2,0,40,0,100,0,1,5413,0,0,80,541300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Waypoint 1 Reached - Run Script"),
(5413,0,3,0,40,0,100,0,2,5413,0,0,80,541301,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Waypoint 2 Reached - Run Script"),
(5413,0,4,0,40,0,100,0,4,5413,0,0,80,541302,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Waypoint 4 Reached - Run Script"),
(541300,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Pause Waypoint"),
(541300,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.190955,"Furen Longbeard - On Script - Set Orientation"),
(541300,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Say Line 0"),
(541300,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Set Emote State 233"),
(541300,9,4,0,0,0,100,0,15000,15000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Set Emote State 0"),
(541301,9,0,0,0,0,100,0,0,0,0,0,54,26000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Pause Waypoint"),
(541301,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.38748,"Furen Longbeard - On Script - Set Orientation"),
(541301,9,2,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Set Emote State 233"),
(541301,9,3,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Set Emote State 0"),
(541301,9,4,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Say Line 1"),
(541302,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.281,"Furen Longbeard - On Script - Set Orientation"),
(541302,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Say Line 2"),
(541302,9,2,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furen Longbeard - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=5413;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(5413,1,-8427.86,607.066,95.0986,""),
(5413,2,-8426.26,613.757,95.269,""),
(5413,3,-8428.98,607.758,95.1228,""),
(5413,4,-8427,600.092,94.706,"");

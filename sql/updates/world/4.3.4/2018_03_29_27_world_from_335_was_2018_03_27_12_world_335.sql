/*
-- Donova Snowden
DELETE FROM `creature_text` WHERE `CreatureID`=9298 AND `GroupID` IN (3,4,5,6,7,8);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9298,3,0,"Please, follow me.",12,0,100,0,0,0,6153,0,"Donova Snowden"),
(9298,4,0,"I haven't really figured out what it is, but there's something strange about the hot springs...",12,0,100,0,0,0,6154,0,"Donova Snowden"),
(9298,5,0,"%s tosses the sword into the shallow pool.",16,0,100,61,0,0,6155,0,"Donova Snowden"),
(9298,6,0,"I've found that when I throw something into this water, it has improved incredibly when I retrieve it.",12,0,100,0,0,0,6156,0,"Donova Snowden"),
(9298,7,0,"Well, whatever it is, it works quite well!",12,0,100,0,0,0,6157,0,"Donova Snowden"),
(9298,8,0,"And I am determined to find out more... So if you need my help again, you know where I'll be.",12,0,100,0,0,0,6158,0,"Donova Snowden");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9298 AND `source_type`=0 AND `id` IN (3,4,5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (929802,929803,929804,929805) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9298,0,3,0,20,0,100,0,3908,0,0,0,80,929802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Quest 'It's a Secret to Everybody (Part 3)' Finished - Run Script"),
(9298,0,4,0,40,0,100,0,1,929800,0,0,80,929803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Waypoint 1 Reached - Run Script"),
(9298,0,5,0,40,0,100,0,1,929801,0,0,80,929804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Waypoint 1 Reached - Run Script"),
(9298,0,6,0,40,0,100,0,3,929801,0,0,80,929805,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Waypoint 3 Reached - Run Script"),
(929802,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Remove Npc Flag Questgiver+Gossip"),
(929802,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 3"),
(929802,9,2,0,0,0,100,0,3000,3000,0,0,53,1,929800,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Start Waypoint"),
(929803,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.91764,"Donova Snowden - On Script - Set Orientation"),
(929803,9,1,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 4"),
(929803,9,2,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 5"),
(929803,9,3,0,0,0,100,0,3000,3000,0,0,53,0,929801,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Start Waypoint"),
(929804,9,0,0,0,0,100,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Pause Waypoint"),
(929804,9,1,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 6"),
(929804,9,2,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Set Flag Standstate 'Kneel'"),
(929804,9,3,0,0,0,100,0,6000,6000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Remove Flag Standstate 'Kneel'"),
(929804,9,4,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 7"),
(929804,9,5,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Say Line 8"),
(929805,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.63731,"Donova Snowden - On Script - Set Orientation"),
(929805,9,1,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Donova Snowden - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `waypoints` WHERE `entry` IN (929800,929801);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(929800,1,6370.08,-2523.34,532.122,""),
(929801,1,6364.47,-2522.52,527.093,""),
(929801,2,6370.08,-2523.34,532.122,""),
(929801,3,6395.57,-2536.75,541.548,"");
*/

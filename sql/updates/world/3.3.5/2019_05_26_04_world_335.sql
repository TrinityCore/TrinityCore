-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=6176 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (617600,617601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6176, 0, 0, 0, 19, 0, 100, 0, 1713, 0, 0, 0, 0, 80, 617600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Quest 'The Summoning' Taken - Run Script"),
(6176, 0, 1, 0, 40, 0, 100, 0, 7, 6176, 0, 0, 0, 80, 617601, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Waypoint 7 Reached - Run Script"),
(617600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 53, 0, 6176, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Script - Start Waypoint"),
(617600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Script - Say Line 0"),
(617601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 8606, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Script - Cast 'Summon Cyclonian'"),
(617601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Script - Say Line 1"),
(617601, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 0, 53, 0, 61760, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Bath'rah the Windwatcher - On Script - Start Waypoint"),
(6176, 0, 6, 0, 40, 0, 100, 0, 7, 61760, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1.39626, "Bath'rah the Windwatcher - On Waypoint 7 Reached - reset orientation");

DELETE FROM `waypoints` WHERE `entry` IN (6176,61760);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(6176,1,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(6176,2,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(6176,3,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(6176,4,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(6176,5,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(6176,6,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(6176,7,323.83,-1468.92,42.24,"Bath'rah the Windwatcher"),
(61760,1,332.73,-1455.6,42.24,"Bath'rah the Windwatcher"),
(61760,2,329.59,-1442.08,40.31,"Bath'rah the Windwatcher"),
(61760,3,297.77,-1436.7,46.96,"Bath'rah the Windwatcher"),
(61760,4,273.74,-1433.18,50.29,"Bath'rah the Windwatcher"),
(61760,5,256.87,-1440.35,50.09,"Bath'rah the Windwatcher"),
(61760,6,253.05,-1459.09,52.09,"Bath'rah the Windwatcher"),
(61760,7,250.84,-1470.58,55.4491,"Bath'rah the Windwatcher");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6176 AND `source_type`=0 AND `id` IN (2,3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (617602,617603) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6176,0,2,0,20,0,100,0,8412,0,0,0,80,617602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Quest 'Spirit Totem' Finished - Run Script"),
(6176,0,3,0,40,0,100,0,1,61761,0,0,80,617603,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Waypoint 1 Reached - Run Script"),
(6176,0,4,0,40,0,100,0,2,61761,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.39626,"Bath'rah the Windwatcher - On Waypoint 2 Reached - Set Orientation"),
(6176,0,5,0,40,0,100,0,2,61761,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Waypoint 2 Reached - Add Npc Flag Questgiver"),
(617602,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Remove Npc Flag Questgiver"),
(617602,9,1,0,0,0,100,0,0,0,0,0,53,0,61761,0,0,0,2,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Start Waypoint"),
(617603,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Pause Waypoint"),
(617603,9,1,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 2"),
(617603,9,2,0,0,0,100,0,5000,5000,0,0,11,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Cast 'Spirit Totem'"),
(617603,9,3,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 3");

DELETE FROM `waypoints` WHERE `entry`=61761;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(61761,1,254.741,-1452.16,51.6124,""),
(61761,2,250.84,-1470.58,55.4491,"");

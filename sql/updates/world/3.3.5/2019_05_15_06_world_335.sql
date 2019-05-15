-- Bath'rah the Windwatcher
DELETE FROM `creature_text` WHERE `CreatureID`=6176 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6176,2,0,"%s surveys the ground and nods approvingly.",16,0,100,16,0,0,10864,0,"Bath'rah the Windwatcher"),
(6176,3,0,"I don't think it's strong enough.",12,0,100,0,0,0,10865,0,"Bath'rah the Windwatcher");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6176 AND `source_type`=0 AND `id` IN (2,3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (617600,617601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6176,0,2,0,20,0,100,0,8412,0,0,0,80,617600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Quest 'Spirit Totem' Finished - Run Script"),
(6176,0,3,0,40,0,100,0,1,6176,0,0,80,617601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Waypoint 1 Reached - Run Script"),
(6176,0,4,0,40,0,100,0,2,6176,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.39626,"Bath'rah the Windwatcher - On Waypoint 2 Reached - Set Orientation"),
(6176,0,5,0,40,0,100,0,2,6176,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Waypoint 2 Reached - Add Npc Flag Questgiver"),
(617600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Remove Npc Flag Questgiver"),
(617600,9,1,0,0,0,100,0,0,0,0,0,53,0,6176,0,0,0,2,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Start Waypoint"),
(617601,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Pause Waypoint"),
(617601,9,1,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 2"),
(617601,9,2,0,0,0,100,0,5000,5000,0,0,11,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Cast 'Spirit Totem'"),
(617601,9,3,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bath'rah the Windwatcher - On Script - Say Line 3");

DELETE FROM `waypoints` WHERE `entry`=6176;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6176,1,254.741,-1452.16,51.6124,""),
(6176,2,250.84,-1470.58,55.4491,"");

-- Spirit Totem
DELETE FROM `creature_template_addon` WHERE `entry`=15363;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (15363,25001);

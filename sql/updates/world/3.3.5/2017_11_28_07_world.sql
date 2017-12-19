-- Martek the Exiled
DELETE FROM `creature_text` WHERE `CreatureID`=4618;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4618,0,0,"%s takes the indurium flakes to his forge.",16,0,100,0,0,0,1500,0,"Martek the Exiled"),
(4618,1,0,"Now let's heat up these flakes...",12,0,100,0,0,0,1501,0,"Martek the Exiled"),
(4618,2,0,"So far they're holding.  Let's turn up the heat...",12,0,100,1,0,0,1502,0,"Martek the Exiled"),
(4618,3,0,"By Orgrim!  This indurium can withstand massive heat!",12,0,100,5,0,0,1503,0,"Martek the Exiled"),
(4618,4,0,"A successful test!  $n, this indurium is some amazing stuff.",12,0,100,1,0,0,1504,0,"Martek the Exiled");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4618;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4618 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (461800,461801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4618,0,0,0,20,0,100,0,1108,0,0,0,80,461800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Quest 'Indurium' Finished - Run Script"),
(4618,0,1,0,40,0,100,0,1,4618,0,0,80,461801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Waypoint 1 Reached - Run Script"),
(4618,0,2,0,40,0,100,0,2,4618,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Waypoint 2 Reached - Set Orientation"),
(461800,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Remove Npc Flag Questgiver+Gossip"),
(461800,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Say Line 0"),
(461800,9,2,0,0,0,100,0,0,0,0,0,53,0,4618,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Start Waypoint"),
(461801,9,0,0,0,0,100,0,0,0,0,0,54,19000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Pause Waypoint"),
(461801,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.24047,"Martek the Exiled - On Script - Set Orientation"),
(461801,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Say Line 1"),
(461801,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Set Emote State 69"),
(461801,9,4,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Set Emote State 0"),
(461801,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Say Line 2"),
(461801,9,6,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Set Emote State 69"),
(461801,9,7,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Set Emote State 0"),
(461801,9,8,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Say Line 3"),
(461801,9,9,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Say Line 4"),
(461801,9,10,0,0,0,100,0,5000,5000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Martek the Exiled - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `waypoints` WHERE `entry`=4618;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(4618,1,-6764.09,-3126.58,241.756,""),
(4618,2,-6763.39,-3129.3,241.384,"");

-- Witch Doctor Uzer'i
DELETE FROM `creature_text` WHERE `CreatureID`=8115 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8115,2,0,"%s gathers the materials together and begins to work.",16,0,100,0,0,0,4175,0,"Witch Doctor Uzer'i"),
(8115,3,0,"I have completed the weapons, $n.",12,0,100,1,0,0,4176,0,"Witch Doctor Uzer'i");

DELETE FROM `smart_scripts` WHERE `entryorguid`=8115 AND `source_type`=0 AND `id` IN (1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (811501,811502,811503) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8115,0,1,0,19,0,100,0,3129,0,0,0,80,811501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Quest 'Weapons of Spirit' Taken - Run Script"),
(8115,0,2,0,40,0,100,0,3,8115,0,0,80,811502,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Waypoint 3 Reached - Run Script"),
(8115,0,3,0,40,0,100,0,6,8115,0,0,80,811503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Waypoint 6 Reached - Run Script"),
(811501,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Remove Npc Flag Questgiver+Gossip"),
(811501,9,1,0,0,0,100,0,1000,1000,0,0,53,1,8115,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Start Waypoint"),
(811502,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Pause Waypoint"),
(811502,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.75709,"Witch Doctor Uzer'i - On Script - Set Orientation"),
(811502,9,2,0,0,0,100,0,1000,1000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Set Flag Standstate Kneel"),
(811502,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Say Line 2"),
(811502,9,4,0,0,0,100,0,13000,13000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Remove Flag Standstate Kneel"),
(811503,9,0,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.72984,"Witch Doctor Uzer'i - On Script - Set Orientation"),
(811503,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Say Line 3"),
(811503,9,2,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Uzer'i - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `waypoints` WHERE `entry`=8115;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(8115,1,-4375.1,259.339,26.584,""),
(8115,2,-4378.28,255.898,26.3856,""),
(8115,3,-4383,256.683,25.8833,""),
(8115,4,-4378.28,255.898,26.3856,""),
(8115,5,-4375.1,259.339,26.584,""),
(8115,6,-4375.68,269.717,25.4947,"");

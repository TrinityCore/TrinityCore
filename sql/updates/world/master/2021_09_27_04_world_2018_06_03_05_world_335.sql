-- J.D. Collie
DELETE FROM `creature_text` WHERE `CreatureID`=9117 AND `GroupID` IN (8,9);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9117,8,0,"I know it'll work this time...",12,0,100,1,0,0,4839,0,"J.D. Collie"),
(9117,8,1,"This will be my best experiment yet!",12,0,100,1,0,0,4840,0,"J.D. Collie"),
(9117,8,2,"I know it'll work this time... My last 13 tries were just practice!",12,0,100,1,0,0,4842,0,"J.D. Collie"),
(9117,9,0,"Now, if I add the yellow ones...",12,0,100,0,0,0,4841,0,"J.D. Collie");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9117 AND `source_type`=0 AND `id` IN (2,3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (911701,911702,911703) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=911700 AND `source_type`=9 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9117,0,2,0,20,0,100,0,3941,0,0,0,80,911701,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Quest 'A Gnome's Assistance' Finished - Run Script"),
(9117,0,3,0,40,0,100,0,1,9117,0,0,80,911702,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Waypoint 1 Reached - Run Script"),
(9117,0,4,0,40,0,100,0,2,9117,0,0,80,911703,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Waypoint 2 Reached - Run Script"),
(911701,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Remove Npc Flag Questgiver+Gossip"),
(911701,9,1,0,0,0,100,0,1000,1000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 8"),
(911701,9,2,0,0,0,100,0,4000,4000,0,0,53,1,9117,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Start Waypoint"),
(911702,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Pause Waypoint"),
(911702,9,1,0,0,0,100,0,1000,1000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 9"),
(911702,9,2,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 4"),
(911702,9,3,0,0,0,100,0,0,0,0,0,11,32990,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Cast 'Enchanting Cast Visual'"),
(911702,9,4,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 5"),
(911702,9,5,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 6"),
(911702,9,6,0,0,0,100,0,3000,3000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 7"),
(911703,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.872665,"J.D. Collie - On Script - Set Orientation"),
(911703,9,1,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Add Npc Flag Questgiver+Gossip"),
(911703,9,2,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - On Script - Say Line 3");

DELETE FROM `waypoints` WHERE `entry`=9117;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(9117,1,-6027.85,-1020.16,-217.056,""),
(9117,2,-6033.25,-1017.56,-217.055,"");

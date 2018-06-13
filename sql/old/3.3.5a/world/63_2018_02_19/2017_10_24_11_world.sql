-- Grand Mason Marblesten
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2790;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2790 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (279000,279001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2790,0,0,0,20,0,100,0,689,0,0,0,80,279000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Quest 'A King's Tribute' Finished - Run Script 1"),
(2790,0,1,0,40,0,100,0,4,2790,0,0,80,279001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Waypoint 4 Reached - Run Script 2"),
(2790,0,2,0,40,0,100,0,8,2790,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Waypoint 8 Reached - Set Orientation"),
(2790,0,3,0,40,0,100,0,8,2790,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Waypoint 8 Reached - Add Npc Flag Questgiver"),
(279000,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 1 - Remove Npc Flag Questgiver"),
(279000,9,1,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 1 - Set Emote State 0"),
(279000,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 1 - Say Line 0"),
(279000,9,3,0,0,0,100,0,0,0,0,0,53,0,2790,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 1 - Start Waypoint"),
(279001,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Pause Waypoint"),
(279001,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.97719,"Grand Mason Marblesten - On Script 2 - Set Orientation"),
(279001,9,2,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Set Emote State 233"),
(279001,9,3,0,0,0,100,0,13000,13000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Set Emote State 0"),
(279001,9,4,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Say Line 1"),
(279001,9,5,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Say Line 2"),
(279001,9,6,0,0,0,100,0,60000,60000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Mason Marblesten - On Script 2 - Set Emote State 233");

DELETE FROM `creature_text` WHERE `CreatureID`=2790;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2790,0,0,"I'll get to work right away, $n!",12,0,100,0,0,0,3501,0,"Grand Mason Marblesten"),
(2790,1,0,"There you have it! The King should be quite pleased, if I do say so myself.",12,0,100,1,0,0,3502,0,"Grand Mason Marblesten"),
(2790,2,0,"The King's guards should be along shortly to pick up the Memorial. In the meantime, come join me upstairs and let's finish our little chat, $n.",12,0,100,0,0,0,3503,0,"Grand Mason Marblesten");

DELETE FROM `waypoints` WHERE `entry`=2790;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2790,1,-5032.14,-1014.66,508.876,""),
(2790,2,-5030.03,-1007.38,505.265,""),
(2790,3,-5022.62,-1009.3,502.209,""),
(2790,4,-5026.43,-1022.21,502.21,""),
(2790,5,-5022.62,-1009.3,502.209,""),
(2790,6,-5030.03,-1007.38,505.265,""),
(2790,7,-5032.14,-1014.66,508.876,""),
(2790,8,-5033.81,-1022.23,508.876,"");

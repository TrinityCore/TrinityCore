-- Talvash del Kissel
DELETE FROM `creature_text` WHERE `CreatureID`=6826 AND `GroupID` IN (1,2,3,4,5);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6826,1,0,"Let me grab a spell focus from inside my home here, and then we'll get started!",12,7,100,0,0,0,3121,0,"Talvash del Kissel"),
(6826,2,0,"Bah, it isn't here.  Where did I have that blasted thing at last?",12,7,100,6,0,0,3122,0,"Talvash del Kissel"),
(6826,3,0,"That's right, it's over by the bed.  Heh, sorry about that!",12,7,100,0,0,0,3123,0,"Talvash del Kissel"),
(6826,4,0,"Fantastic then!  Let's get this thing fixed for you.",12,7,100,0,0,0,3124,0,"Talvash del Kissel"),
(6826,5,0,"Success!  Huzzah!  The power source restored the necklace!",12,7,100,4,0,0,3125,0,"Talvash del Kissel");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6826 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (682600,682601,682602) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6826,0,2,0,20,0,100,0,2204,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Quest 'Restoring the Necklace' Finished - Remove Npc Flag Questgiver+Gossip"),
(6826,0,3,0,20,0,100,0,2204,0,0,0,53,0,6826,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Quest 'Restoring the Necklace' Finished - Start Waypoint"),
(6826,0,4,0,20,0,100,0,2204,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Quest 'Restoring the Necklace' Finished - Say Line 1"),
(6826,0,5,0,40,0,100,0,3,6826,0,0,80,682600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Waypoint 3 Reached - Run Script"),
(6826,0,6,0,40,0,100,0,5,6826,0,0,80,682601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Waypoint 5 Reached - Run Script"),
(6826,0,7,0,40,0,100,0,10,6826,0,0,80,682602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Waypoint 10 Reached - Run Script"),
(682600,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Pause Waypoint"),
(682600,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.02135,"Talvash del Kissel - On Script - Set Orientation"),
(682600,9,2,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Say Line 2"),
(682600,9,3,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Say Line 3"),
(682601,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Pause Waypoint"),
(682601,9,2,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Say Line 4"),
(682602,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.31613,"Talvash del Kissel - On Script - Set Orientation"),
(682602,9,1,0,0,0,100,0,1000,1000,0,0,11,9795,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Cast 'Talvash's Necklace Repair'"),
(682602,9,2,0,0,0,100,0,6000,6000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Say Line 5"),
(682602,9,3,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talvash del Kissel - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `waypoints` WHERE `entry`=6826;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6826,1,-4586.89,-997.797,503.658,""),
(6826,2,-4582.68,-996.563,503.658,""),
(6826,3,-4575.23,-998.552,503.658,""),
(6826,4,-4575.04,-995.529,503.657,""),
(6826,5,-4576.11,-992.451,503.657,""),
(6826,6,-4575.04,-995.529,503.657,""),
(6826,7,-4575.64,-997.129,503.657,""),
(6826,8,-4578.79,-998.015,503.657,""),
(6826,9,-4586.89,-997.797,503.658,""),
(6826,10,-4588.3,-1001.21,503.657,"");

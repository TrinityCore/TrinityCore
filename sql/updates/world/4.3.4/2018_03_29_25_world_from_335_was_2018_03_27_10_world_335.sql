/*
-- Klockmort Spannerspan
DELETE FROM `creature_text` WHERE `CreatureID`=6169;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6169,0,0,"%s begins to work...",16,0,100,0,0,0,2344,0,"Klockmort Spannerspan"),
(6169,1,0,"Hooray hooray! $n! It's done!",12,7,100,4,0,0,2345,0,"Klockmort Spannerspan");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6169;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6169 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (616900,616901) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6169,0,0,0,20,0,100,0,1708,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Quest 'Iron Coral' Finished - Remove Npc Flag Questgiver"),
(6169,0,1,0,20,0,100,0,1708,0,0,0,53,0,6169,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Quest 'Iron Coral' Finished - Start Waypoint"),
(6169,0,2,0,40,0,100,0,1,6169,0,0,80,616900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Waypoint 1 Reached - Run Script"),
(6169,0,3,0,40,0,100,0,2,6169,0,0,80,616901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Waypoint 2 Reached - Run Script"),
(616900,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Pause Waypoint"),
(616900,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.97526,"Klockmort Spannerspan - On Script - Set Orientation"),
(616900,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Say Line 0"),
(616900,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Set Emote State 233"),
(616900,9,4,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Set Emote State 0"),
(616901,9,0,0,0,0,100,0,1000,1000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Set Emote State 233"),
(616901,9,1,0,0,0,100,0,15000,15000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Set Emote State 0"),
(616901,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Say Line 1"),
(616901,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.62512,"Klockmort Spannerspan - On Script - Set Orientation"),
(616901,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klockmort Spannerspan - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=6169;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6169,1,-4815,-1250.3,501.915,""),
(6169,2,-4812.48,-1250.62,502.014,"");
*/

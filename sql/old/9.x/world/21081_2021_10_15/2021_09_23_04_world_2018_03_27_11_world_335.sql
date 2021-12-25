-- Tormus Deepforge
DELETE FROM `creature_text` WHERE `CreatureID`=6031;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6031,0,0,"%s begins to work...",16,0,100,0,0,0,2303,0,"Tormus Deepforge"),
(6031,1,0,"$n!  I'm finished!",12,7,100,1,0,0,2304,0,"Tormus Deepforge");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6031;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6031 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (603100,603101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6031,0,0,0,20,0,100,0,1681,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Quest 'Ironband's Compound' Finished - Remove Npc Flag Questgiver"),
(6031,0,1,0,20,0,100,0,1681,0,0,0,53,0,6031,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Quest 'Ironband's Compound' Finished - Start Waypoint"),
(6031,0,2,0,40,0,100,0,1,6031,0,0,80,603100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Waypoint 1 Reached - Run Script"),
(6031,0,3,0,40,0,100,0,2,6031,0,0,80,603101,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Waypoint 2 Reached - Run Script"),
(603100,9,0,0,0,0,100,0,0,0,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Pause Waypoint"),
(603100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.00425,"Tormus Deepforge - On Script - Set Orientation"),
(603100,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Say Line 0"),
(603100,9,3,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Set Emote State 233"),
(603100,9,4,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Set Emote State 0"),
(603101,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.60767,"Tormus Deepforge - On Script - Set Orientation"),
(603101,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Say Line 1"),
(603101,9,2,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormus Deepforge - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=6031;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6031,1,-4798.04,-1104.75,499.605,""),
(6031,2,-4793.38,-1098.17,498.89,"");

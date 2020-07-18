-- Doc Mixilpixil
DELETE FROM `creature_text` WHERE `CreatureID`=7207;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7207,0,0,"Just /lay down anywhere, $n. I promise, this won't hurt a bit!",12,0,100,0,0,0,3567,0,"Doc Mixilpixil"),
(7207,1,0,"%s prepares his syringe.",16,0,100,0,0,0,3563,0,"Doc Mixilpixil"),
(7207,2,0,"%s examines the blood in the bottle.",16,0,100,0,0,0,3564,0,"Doc Mixilpixil"),
(7207,3,0,"Very interesting!",12,0,100,0,0,0,3565,0,"Doc Mixilpixil"),
(7207,4,0,"%s seems to be talking to the squirrel and the statue. He periodically points in your direction.",16,0,100,0,0,0,3566,0,"Doc Mixilpixil"),
(7207,5,0,"This doesn't look good!",12,0,100,274,0,0,3568,0,"Doc Mixilpixil");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7207 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (720700,720701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7207,0,0,0,19,0,100,0,2608,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Quest 'The Touch of Zanzil (Part 2)' Taken - Say Line 0"),
(7207,0,1,0,22,0,100,0,61,15000,15000,0,0,80,720700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Received Emote 'Lay Down' - Run Script"),
(7207,0,2,0,20,0,100,0,2608,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Quest 'The Touch of Zanzil (Part 2)' Finished - Remove Npc Flag Questgiver+Gossip"),
(7207,0,3,0,20,0,100,0,2608,0,0,0,0,53,0,7207,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Quest 'The Touch of Zanzil (Part 2)' Finished - Start Waypoint"),
(7207,0,4,0,40,0,100,0,1,7207,0,0,0,80,720701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Waypoint 1 Reached - Run Script"),
(7207,0,5,0,40,0,100,0,2,7207,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.15905,"Doc Mixilpixil - On Waypoint 2 Reached - Set Orientation"),
(7207,0,6,0,40,0,100,0,2,7207,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Waypoint 2 Reached - Add Npc Flag Questgiver+Gossip"),
(7207,0,7,0,40,0,100,0,2,7207,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Waypoint 2 Reached - Say Line 5"),
(720700,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Remove Npc Flag Questgiver+Gossip"),
(720700,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 1"),
(720700,9,2,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Set Flag Standstate 'Kneel'"),
(720700,9,3,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Set Emote State 233"),
(720700,9,4,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 2"),
(720700,9,5,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 3"),
(720700,9,6,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Add Npc Flag Questgiver+Gossip"),
(720700,9,7,0,0,0,100,0,0,0,0,0,0,15,2608,0,0,0,0,0,7,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Complete Quest 'The Touch of Zanzil (Part 2)'"),
(720701,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Pause Waypoint"),
(720701,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.291581,"Doc Mixilpixil - On Script - Set Orientation"),
(720701,9,2,0,0,0,100,0,1000,1000,0,0,0,17,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Set Emote State 1"),
(720701,9,3,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Say Line 4"),
(720701,9,4,0,0,0,100,0,15000,15000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doc Mixilpixil - On Script - Set Emote State 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=7207;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,7207,0,0,9,0,2608,0,0,0,0,0,"","SAI triggers only if quest 'The Touch of Zanzil (Part 2)' is taken");

DELETE FROM `waypoints` WHERE `entry`=7207;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(7207,1,-8806.36,338.259,95.0989,""),
(7207,2,-8805.56,331.968,95.0986,"");

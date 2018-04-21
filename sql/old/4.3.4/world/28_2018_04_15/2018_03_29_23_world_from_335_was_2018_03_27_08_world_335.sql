/*
-- Grimand Elmore
DELETE FROM `creature_text` WHERE `CreatureID`=1416 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1416,2,0,"%s begins to work...",16,0,100,0,0,0,2346,0,"Grimand Elmore"),
(1416,3,0,"Amazing!  It worked!  $n, I have your armor.",12,7,100,5,0,0,2347,0,"Grimand Elmore");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1416 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=141601 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1416,0,1,0,20,0,100,0,1705,0,0,0,80,141601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Quest 'Burning Blood' Finished - Run Script"),
(141601,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Remove Npc Flag Questgiver+Gossip"),
(141601,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.72935,"Grimand Elmore - On Script - Set Orientation"),
(141601,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Say Line 2"),
(141601,9,3,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Set Emote State 233"),
(141601,9,4,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Set Emote State 0"),
(141601,9,5,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.286,"Grimand Elmore - On Script - Set Orientation"),
(141601,9,6,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Say Line 3"),
(141601,9,7,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimand Elmore - On Script - Add Npc Flag Questgiver+Gossip");
*/

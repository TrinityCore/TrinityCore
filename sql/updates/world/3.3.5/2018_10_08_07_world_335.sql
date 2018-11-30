-- Theldurin the Lost
DELETE FROM `creature_text` WHERE `CreatureID`=2785 AND `GroupID` IN (5,6,7);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2785,5,0,"%s hunkers down to read Yagyin's Digest...",16,0,100,0,0,0,923,0,"Theldurin the Lost"),
(2785,6,0,"%s is struck by unleashed magic!",16,0,100,34,0,0,924,0,"Theldurin the Lost"),
(2785,7,0,"Ow.  Spicy.",12,0,100,0,0,0,934,0,"Theldurin the Lost");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2785 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=278502 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2785,0,2,0,20,0,100,0,737,0,0,0,80,278502,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Quest 'Forbidden Knowledge' Finished - Run Script"),
(278502,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Remove Npc Flag Questgiver"),
(278502,9,1,0,0,0,100,0,1000,1000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 5"),
(278502,9,2,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Set Flag Standstate 'Sit Down'"),
(278502,9,3,0,0,0,100,0,6000,6000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Remove Flag Standstate 'Sit Down'"),
(278502,9,4,0,0,0,100,0,200,200,0,0,11,40108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Cast 'Magic Backlash'"),
(278502,9,5,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 6"),
(278502,9,6,0,0,0,100,0,3000,3000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 7"),
(278502,9,7,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Add Npc Flag Questgiver");

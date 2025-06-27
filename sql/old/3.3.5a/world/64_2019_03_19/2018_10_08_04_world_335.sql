-- Theldurin the Lost
DELETE FROM `creature_text` WHERE `CreatureID`=2785 AND `GroupID` IN (3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2785,3,0,"%s reads the ancient text $n fetched for him...",16,0,100,0,0,0,914,0,"Theldurin the Lost"),
(2785,4,0,"Aha!  That's it!",12,0,100,5,0,0,915,0,"Theldurin the Lost");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2785 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=278501 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2785,0,1,0,20,0,100,0,709,0,0,0,80,278501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Quest 'Solution to Doom' Finished - Run Script"),
(278501,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Remove Npc Flag Questgiver"),
(278501,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 3"),
(278501,9,2,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 4"),
(278501,9,3,0,0,0,100,0,2000,2000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Add Npc Flag Questgiver");

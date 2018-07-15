/*
-- Raleigh the Devout
DELETE FROM `creature_text` WHERE `CreatureID`=3980;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3980,0,0,"%s breaks the seal on Anton's letter and begins to read it.",16,0,100,0,0,0,1377,0,"Raleigh the Devout"),
(3980,1,0,"By the Light! This is not good. There's something you don't understand, $n.",12,7,100,5,0,0,1378,0,"Raleigh the Devout"),
(3980,2,0,"%s throws Anton's letter down on the table.",16,0,100,0,0,0,1379,0,"Raleigh the Devout");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3980 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=398000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3980,0,1,0,20,0,100,0,1052,0,0,0,80,398000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Quest 'Down the Scarlet Path (Part 2)' Finished - Run Script"),
(398000,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Script - Remove Npc Flag Questgiver"),
(398000,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Script - Say Line 0"),
(398000,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Script - Say Line 1"),
(398000,9,3,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Script - Say Line 2"),
(398000,9,4,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raleigh the Devout - On Script - Add Npc Flag Questgiver");
*/

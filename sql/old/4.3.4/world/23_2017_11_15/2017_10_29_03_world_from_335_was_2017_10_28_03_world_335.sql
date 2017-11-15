/*
-- Gor'mul
DELETE FROM `creature_text` WHERE `CreatureID`=2792;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2792,0,0,"%s watches as his blood begins to stir, and the guile of the raptor slips through him.",16,0,100,0,0,0,1020,0,"Gor'mul"),
(2792,1,0,"What is this power that flows through me? Is this the power of shamanism that Tor'gan spoke of...?",12,1,100,6,0,0,861,0,"Gor'mul"),
(2792,2,0,"Amazing! I feel... renewed. My strength returns!",12,1,100,15,0,0,862,0,"Gor'mul");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2792 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=279200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2792,0,0,0,20,0,100,0,702,0,0,0,80,279200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Quest 'Guile of the Raptor (Part 2)' finished - Run Script"),
(279200,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Remove Npc Flag Questgiver"),
(279200,9,1,0,0,0,100,0,0,0,0,0,11,4153,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Cast Guile of the Raptor"),
(279200,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Say Line 0"),
(279200,9,3,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Say Line 1"),
(279200,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Say Line 2"),
(279200,9,5,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - On Script - Add Npc Flag Questgiver");
*/

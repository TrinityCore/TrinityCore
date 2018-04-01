/*
-- Winna Hazzard
DELETE FROM `creature_text` WHERE `CreatureID`=9996;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9996,0,0,"I'm very curious to see what this sample of water will do!",12,0,100,1,0,0,5945,0,"Winna Hazzard"),
(9996,1,0,"%s pours the corrupted water onto the cat.",16,0,100,16,0,0,5946,0,"Winna Hazzard"),
(9996,2,0,"Haha! Perfect!",12,0,100,11,0,0,5947,0,"Winna Hazzard");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9996;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9996 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=999600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9996,0,0,0,20,0,100,0,4505,0,0,0,80,999600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Quest 'Well of Corruption' Finished - Run Script"),
(999600,9,0,0,0,0,100,0,0,0,0,0,36,10658,0,0,0,0,0,19,10657,0,0,0,0,0,0,"Winna Hazzard - On Script - Update Template To 'Winna's Kitten' (Corrupted Cat)"), -- Reset script (in case event was triggered a few seconds before)
(999600,9,1,0,0,0,100,0,0,0,0,0,3,0,0,0,0,0,0,19,10658,0,0,0,0,0,0,"Winna Hazzard - On Script - Demorph (Winna's Kitten)"), -- Reset script (in case event was triggered a few seconds before)
(999600,9,2,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Remove Npc Flag Questgiver"),
(999600,9,3,0,0,0,100,0,0,0,0,0,89,0,0,0,0,0,0,19,10658,0,0,0,0,0,0,"Winna Hazzard - On Script - Stop Random Movement (Winna's Kitten)"),
(999600,9,4,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Say Line 0"),
(999600,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Set Run On"),
(999600,9,6,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,19,10658,0,0,0,0,0,0,"Winna Hazzard - On Script - Start Follow"),
(999600,9,7,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Say Line 1"),
(999600,9,8,0,0,0,100,0,3000,3000,0,0,36,10657,0,0,0,0,0,19,10658,0,0,0,0,0,0,"Winna Hazzard - On Script - Update Template To 'Corrupted Cat' (Winna's Kitten)"),
(999600,9,9,0,0,0,100,0,0,0,0,0,86,16510,0,19,10657,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Cross Cast 'Corrupted Saber Visual (DND)'"),
(999600,9,10,0,0,0,100,0,0,0,0,0,3,10657,0,0,0,0,0,19,10657,0,0,0,0,0,0,"Winna Hazzard - On Script - Morph to Entry 'Corrupted Cat' (Winna's Kitten)"),
(999600,9,11,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Say Line 2"),
(999600,9,12,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,5126.82,-325.127,358.926,0,"Winna Hazzard - On Script - Move to Position"),
(999600,9,13,0,0,0,100,0,0,0,0,0,89,8,0,0,0,0,0,19,10657,0,0,0,0,0,0,"Winna Hazzard - On Script - Start Random Movement (Winna's Kitten)"),
(999600,9,14,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.99164,"Winna Hazzard - On Script - Set Orientation"),
(999600,9,15,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winna Hazzard - On Script - Add Npc Flag Questgiver"),
(999600,9,16,0,0,0,100,0,60000,60000,0,0,36,10658,0,0,0,0,0,19,10657,0,0,0,0,0,0,"Winna Hazzard - On Script - Update Template To 'Winna's Kitten' (Corrupted Cat)"), -- Reset script
(999600,9,17,0,0,0,100,0,0,0,0,0,3,0,0,0,0,0,0,19,10658,0,0,0,0,0,0,"Winna Hazzard - On Script - Demorph (Winna's Kitten)"); -- Reset script

-- Fix position and add random movement for Winna's Kitten
UPDATE `creature` SET `position_x`=5126.69, `position_y`=-332.264, `position_z`=356.926, `spawndist`=8, `MovementType`=1 WHERE `guid`=39704;
*/

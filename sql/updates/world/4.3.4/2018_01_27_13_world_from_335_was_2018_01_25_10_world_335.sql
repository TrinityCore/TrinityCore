/*
-- Quest "The Key to Freedom"
-- Wooden Outhouse
DELETE FROM `smart_scripts` WHERE `entryorguid`=173265 AND `source_type`=1 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(173265,1,1,0,20,0,100,0,4451,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Goodsteel Ledger - On Quest 'The Key to Freedom' Finished - Store Targetlist"),
(173265,1,2,0,20,0,100,0,4451,0,0,0,12,9876,3,30000,0,0,0,8,0,0,0,-7026.11,-1784.73,265.782,2.11562,"Goodsteel Ledger - On Quest 'The Key to Freedom' Finished - Summon Creature 'Locheed'"),
(173265,1,3,0,20,0,100,0,4451,0,0,0,100,1,0,0,0,0,0,19,9876,0,0,0,0,0,0,"Goodsteel Ledger - On Quest 'The Key to Freedom' Finished - Send Targetlist to Locheed");

-- Locheed
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9876;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9876 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=987600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9876,0,0,0,11,0,100,0,0,0,0,0,80,987600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Locheed - On Respawn - Run Script"),
(987600,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Locheed - On Respawn - Say Line 0"),
(987600,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Locheed - On Respawn - Say Line 1"),
(987600,9,2,0,0,0,100,0,6000,6000,0,0,69,0,0,0,0,0,0,8,0,0,0,-7165.31,-1802.59,272.783,3.01882,"Locheed - On Respawn - Move to Position");

DELETE FROM `creature_text` WHERE `CreatureID`=9876;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9876,0,0,"Ach! Thank you so much, $n! I'm free! Finally!",12,0,100,4,0,0,5407,0,"Locheed"),
(9876,1,0,"You take care of yourself! I'm gettin' out o' here.",12,0,100,5,0,0,5408,0,"Locheed");
*/

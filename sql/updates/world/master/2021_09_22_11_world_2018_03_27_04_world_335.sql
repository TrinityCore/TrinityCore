-- Henze Faulk
DELETE FROM `creature_text` WHERE `CreatureID`=6172 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6172,1,0,"Good luck to you, $n. And don't forget... get that script before finding Gazin.",12,7,100,0,0,0,2353,0,"Henze Faulk");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6172 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6172,0,4,0,19,0,100,0,1787,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Henze Faulk - On Quest 'The Tome of Divinity (Part 7)' Taken - Say Line 1");

-- Narm Faulk
DELETE FROM `creature_text` WHERE `CreatureID`=6177 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6177,1,0,"Good luck, $n. And remember, find Muiredon once you've accomplished the task.",12,6,100,0,0,0,2351,0,"Narm Faulk");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6177 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6177,0,4,0,19,0,100,0,1784,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Narm Faulk - On Quest 'The Tome of Divinity (Part 7)' Taken - Say Line 1");

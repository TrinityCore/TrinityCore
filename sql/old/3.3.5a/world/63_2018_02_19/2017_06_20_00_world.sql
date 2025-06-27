-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=12997 AND `id`=2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12997, 0, 2, 0, 1, 0, 100, 0, 50000, 70000, 540000, 620000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Monty - OOC - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=12997 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12997, 1, 0, "Overflowin' with rats! Help a pirate out, matey!", 12, 0, 0, 0, 0, 0, 8458, 0, "Monty"),
(12997, 1, 1, "Don't crowd me, people!", 12, 0, 0, 0, 0, 0, 8460, 0, "Monty"),
(12997, 1, 2, "Do yer part in keepin' the Deeprun Tram clean!", 12, 0, 0, 0, 0, 0, 8459, 0, "Monty");


UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=178304;
DELETE FROM `smart_scripts` WHERE `entryorguid`=178304 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(178304, 1, 0, 0, 1, 0, 100, 0, 500, 1000, 1000, 1400, 93, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Box o' Squirrels - OOC - Send Custom Animation 0");

UPDATE `gameobject` SET `position_z`=-4.2974 WHERE `id`=178304;

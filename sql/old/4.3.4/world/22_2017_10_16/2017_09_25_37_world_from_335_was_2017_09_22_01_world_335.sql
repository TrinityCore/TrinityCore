/*
-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2610 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2610, 0, 5, 0, 20, 0, 100, 0, 670, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Shakes O'Breen - On Quest 'Sunken Treasure' Rewarded - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID`=2610 AND `GroupId`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2610, 2, 0, "Wait, $n!!! It looks like we're going to need some help here...", 12, 0, 100, 0, 0, 0, 857, 0, "Shakes O'Breen");

UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0 WHERE `entryorguid`=261000 AND `source_type`=9 AND `id`=14;
*/

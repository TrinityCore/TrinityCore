-- Prospector Anvilward
UPDATE `smart_scripts` SET `event_flags`=0, `action_param2`=10000, `event_param3`=90000, `event_param4`=120000,  `target_type`=1 WHERE `entryorguid`=15420 AND `source_type`=0 AND `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15420 AND `source_type`=0 AND id=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15420, 0, 9, 0, 52, 0, 100, 0, 2, 15420, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 15405, 50, 0, 0, 0, 0, 0, "Prospector Anvilward - Out Of Combat - Talk (target Ley-Keeper Caidanis)");
DELETE FROM `creature_text` WHERE `CreatureID`=15405;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15405, 0, 0, "It's been a pleasure, Mr. Anvilward.  I must say your enthusiastic interest in our operations is most... unexpected.", 12, 0, 100, 0, 0, 0, 11718, 0, "Ley-Keeper Caidanis");

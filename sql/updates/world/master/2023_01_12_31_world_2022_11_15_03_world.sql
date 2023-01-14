-- Ango'rosh Ogre
DELETE FROM `creature_text` WHERE `CreatureID`=18117 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18117, 1, 0, 'You no take mushroom!', 12, 0, 100, 0, 0, 0, 15198, 0, "Ango'rosh Ogre");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18117;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18117 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18117, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ango'rosh Ogre - On Aggro - Say Line 1");

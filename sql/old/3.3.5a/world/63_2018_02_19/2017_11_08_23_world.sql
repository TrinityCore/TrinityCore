--
DELETE FROM `creature_text` WHERE `CreatureID` IN (16972, 16973);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16972, 0, 0, "%s smells a fresh corpse nearby.", 16, 0, 100, 0, 0, 0, 16746, 0, "Bonestripper Buzzard"),
(16973, 0, 0, "%s smells a fresh corpse nearby.", 16, 0, 100, 0, 0, 0, 16746, 0, "Bonestripper Vulture");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16972, 16973) AND `source_type`=0 AND `id` IN (1, 2, 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16972, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 16972, 20, 0, 0, 0, 0, 0, "Bonestripper Buzzard - On Death - Set Data 1 1 to nearby Bonestripper Buzzard"),
(16972, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 16972, 100, 1, 0, 0, 0, 0, "Bonestripper Buzzard - On Data 1 1 Set - Move To Pos"),
(16972, 0, 3, 0, 61, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bonestripper Buzzard - On Data 1 1 Set - Talk 0"),
(16973, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 16973, 20, 0, 0, 0, 0, 0, "Bonestripper Vulture - On Death - Set Data 1 1 to nearby Bonestripper Vulture"),
(16973, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 16973, 100, 1, 0, 0, 0, 0, "Bonestripper Vulture - On Data 1 1 Set - Move To Pos"),
(16973, 0, 3, 0, 61, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bonestripper Vulture - On Data 1 1 Set - Talk 0");

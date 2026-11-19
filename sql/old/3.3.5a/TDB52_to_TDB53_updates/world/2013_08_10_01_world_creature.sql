UPDATE `creature_template` SET `AIName` = 'NullAI' WHERE `entry` = 27490;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 31339;
UPDATE `creature_template` SET `ScriptName` = '', AIName = 'SmartAI' WHERE `entry` = 26638;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26638 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26638, 0, 1, 0, 0, 0, 100, 6, 0, 0, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Bat Rider - In Combat - Dismount"),
(26638, 0, 2, 0, 0, 0, 100, 6, 0, 0, 0, 0, 19, 0x02000000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Bat Rider - In Combat - Remove flag"),
(26638, 0, 3, 0, 9, 0, 100, 6, 5, 30, 9000, 12000, 11, 16001, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Bat Rider - At 5 - 30 Range - Cast Impale"),
(26638, 0, 4, 0, 0, 0, 100, 2, 3000, 6000, 9000, 12000, 11, 50414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Bat Rider - In Combat - Cast Curse of Blood"),
(26638, 0, 5, 0, 0, 0, 100, 4, 3000, 6000, 9000, 12000, 11, 59009, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Bat Rider - In Combat - Cast Curse of Blood");

DELETE FROM `creature_addon` WHERE `guid` = 127448;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(127448, 0, 26751, 0, 1, 0, '');

--
DELETE FROM `creature_template_addon` WHERE `entry`=29366;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29366, 0, 0, 0, 0, 333, "");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=29366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29366, 0, 0, 0, 1, 0, 100, 0, 3000, 4000, 3000, 4000, 0, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brunnhildar Challenger - OOC - Play Attack Emote");

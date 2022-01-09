-- 
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry` IN (15262, 15312);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15262,15312) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15262, 0, 0, 0, 25, 0, 100, 2, 0, 0, 0, 0, 0, 108, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Obsidian Eradicator - On reset - Set Mana To 0'),
(15312, 0, 0, 0, 25, 0, 100, 2, 0, 0, 0, 0, 0, 108, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Obsidian Nullifier - On reset - Set Mana To 0');

--
DELETE FROM `smart_scripts` WHERE `entryorguid`=28752 AND `source_type`=0 AND `id`IN(14,15);
DELETE FROM `smart_scripts` WHERE `entryorguid`=28754 AND `source_type`=0 AND `id`IN(9,10);
DELETE FROM `smart_scripts` WHERE `entryorguid`=28756 AND `source_type`=0 AND `id`=6;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28752, 0, 14, 0, 6, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Mu funu - On Death - Reset All Scripts'),
(28752, 0, 15, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Mu funu - On Respawn - Set Unit Flags'),
(28754, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Tua-Tua - On Death - Reset All Scripts'),
(28754, 0, 10, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Tua-Tua - On Respawn - Set Unit Flags'),
(28756, 0, 6, 0, 6, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Priest Hawinni - On Death - Reset All Scripts');

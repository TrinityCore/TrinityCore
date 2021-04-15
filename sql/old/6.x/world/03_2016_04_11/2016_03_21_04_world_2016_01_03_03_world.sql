-- Betrayal (Drakuru) fixes:
-- Fix "Blight Fog" cast behavior
-- Fix "Throw Blight Crystal" cast timing
-- By: dr-j
UPDATE `smart_scripts` SET `event_param2`=7500, `event_param3`=10000, `event_param4`=20000 WHERE  `entryorguid`=28998 AND `source_type`=0 AND `id`=5 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28998 AND `source_type`=0 AND `id` in(13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28998, 0, 13, 0, 0, 0, 100, 0, 0, 0, 60000, 60000, 28, 54104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - IC - Remove Aura (Blight Fog'),
(28998, 0, 14, 0, 0, 0, 100, 0, 45000, 45000, 60000, 60000, 11, 54104, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overlord Drakuru - IC - Cast Blight Fog');

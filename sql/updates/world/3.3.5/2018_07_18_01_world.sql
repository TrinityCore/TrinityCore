-- 
UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid`=184906 AND `source_type`=1 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=184906 AND `source_type`=1 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(184906,1,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,21737,5,0,0,0,0,0,"Power Converter - On linked event - despawn");

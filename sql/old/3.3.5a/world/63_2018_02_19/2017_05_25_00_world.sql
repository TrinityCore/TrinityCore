UPDATE `smart_scripts` SET `link`=13 WHERE `entryorguid`=28213 AND `source_type`=0 AND `id`IN(8,10); 
UPDATE `smart_scripts` SET `event_type`=7 WHERE `entryorguid`=28213 AND `source_type`=0 AND `id`=9 AND `link`=10; 
DELETE FROM `smart_scripts` WHERE `entryorguid` =28213 AND `source_type`=0 AND `id`IN(13,14,6); 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28213, 0, 13, 0, 61, 0, 100, 512, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - On Respawn - Set Passive'), 
(28213, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 500, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - On Data Set 1 1 - Start Attacking'), 
(28213, 0, 6, 14, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - On Data Set 1 1 - Set Aggresive'); 

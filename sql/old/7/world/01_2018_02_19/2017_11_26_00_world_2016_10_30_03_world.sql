-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25803 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25803, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 10000, 15000, 11, 42724, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Karen "I Don''t Caribou" the Culler - In Combat - Cast Cleave'),
(25803, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 15000, 21000, 11, 48280, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Karen "I Don''t Caribou" the Culler - In Combat - Cast Whirlwind'),
(25803, 0, 2, 0, 9, 0, 100, 0, 8, 25, 10000, 10000, 11, 27577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Karen "I Don''t Caribou" the Culler - Within Range 8-25yd - Cast Intercept');

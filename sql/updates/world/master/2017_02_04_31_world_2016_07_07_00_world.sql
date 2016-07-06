--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (1986, 1994);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1986, 1994) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1986, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 3000, 7000, 11, 6751, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Webwood Spider - In Combat - Cast \'Weak Poison\''), 
(1994, 0, 0, 0, 0, 0, 100, 0, 4000, 9000, 4000, 9000, 11, 11918, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Githyiss the Vile - In Combat - Cast \'Poison\'');

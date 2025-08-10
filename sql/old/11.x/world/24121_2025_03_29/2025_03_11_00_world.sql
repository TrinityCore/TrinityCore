DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_cycle_of_hatred', 'spell_dh_cycle_of_hatred_talent', 'spell_dh_cycle_of_hatred_remove_stacks');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(198013, 'spell_dh_cycle_of_hatred'),
(258887, 'spell_dh_cycle_of_hatred_talent'),
(1214890, 'spell_dh_cycle_of_hatred_remove_stacks');

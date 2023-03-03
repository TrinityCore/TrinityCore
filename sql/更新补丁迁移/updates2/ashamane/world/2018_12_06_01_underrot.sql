DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_creeping_rot_target_selector', 'spell_creeping_rot_summon', 'spell_sanguine_feast_target_selector');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(260889, 'spell_creeping_rot_target_selector'),
(260894, 'spell_creeping_rot_summon'),
(264747, 'spell_sanguine_feast_target_selector');

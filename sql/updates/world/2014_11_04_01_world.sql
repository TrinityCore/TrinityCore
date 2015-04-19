DELETE FROM spell_ranks where first_spell_id = 77829;
INSERT INTO spell_ranks VALUES ( 77829,77829,1),(77829,77830,2);

DELETE FROM spell_script_names where spell_id = 98020;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (98020, 'spell_sha_spirit_link');

DELETE FROM `spell_script_names` WHERE `spell_id` = 73680;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (73680, 'spell_sha_unleash_elements');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sha_ancestral_resolve';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (77829, 'spell_sha_ancestral_resolve');

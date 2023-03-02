DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_jade_tempest', 'spell_gen_molten_fist', 'spell_gen_return_to_stone', 'spell_gen_shadow_volley', 'spell_gen_fracture');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(148582,'spell_gen_jade_tempest'),
(148517,'spell_gen_molten_fist'),
(145489,'spell_gen_return_to_stone'),
(148513,'spell_gen_fracture'),
(148515,'spell_gen_shadow_volley');

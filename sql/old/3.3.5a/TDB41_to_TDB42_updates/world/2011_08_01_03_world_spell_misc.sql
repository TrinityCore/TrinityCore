DELETE FROM `spell_dbc` WHERE `id`=18350;
INSERT INTO `spell_dbc` (`id`,`Effect1`,`EffectImplicitTargetA1`,`Comment`) VALUES
(18350,3,1,'Soul Preserver trinket spell');

DELETE FROM `spell_script_names` WHERE `spell_id`=18350;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(18350,'spell_gen_soul_preserver');

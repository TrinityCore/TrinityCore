--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_hate_to_zero_caster_target' WHERE `ScriptName` = 'spell_yogg_saron_hate_to_zero';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_gen_hate_to_zero',
'spell_gen_hate_to_50',
'spell_gen_hate_to_75');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(9204,'spell_gen_hate_to_zero'),
(20538,'spell_gen_hate_to_zero'),
(26569,'spell_gen_hate_to_zero'),
(26637,'spell_gen_hate_to_zero'),
(37326,'spell_gen_hate_to_zero'),
(19707,'spell_gen_hate_to_50'),
(26886,'spell_gen_hate_to_75');

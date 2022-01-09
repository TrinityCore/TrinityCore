DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_lightning_bolt_overload';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_chain_lightning_overload';
DELETE FROM `spell_script_names` WHERE `spell_id`=120588 AND `ScriptName`='spell_sha_elemental_blast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45284,'spell_sha_lightning_bolt_overload'),
(45297,'spell_sha_chain_lightning_overload'),
(120588,'spell_sha_elemental_blast');

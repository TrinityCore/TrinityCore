DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_conjure_refreshment_table';

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_conjure_refreshment';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(190336, 'spell_mage_conjure_refreshment');

DELETE FROM `spell_script_names` WHERE `ScriptName` LIKE '%spell_dru_eclipse%' OR `ScriptName` LIKE '%spell_dru_glyph%' OR `ScriptName` = 'spell_dru_insect_swarm';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_moonfire' OR `ScriptName` = 'spell_dru_sunfire';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(8921, 'spell_dru_moonfire'),
(93402, 'spell_dru_sunfire');

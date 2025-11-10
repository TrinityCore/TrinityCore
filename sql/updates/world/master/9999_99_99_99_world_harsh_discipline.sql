DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_harsh_discipline', 'spell_pri_harsh_discipline_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(194509, 'spell_pri_harsh_discipline'),
(373183, 'spell_pri_harsh_discipline_aura');

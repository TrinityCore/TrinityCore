DELETE FROM `spell_learn_spell` WHERE `entry` IN (34428);
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`, `Active`) VALUES
(34428, 32215, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dru_natures_grace',
'spell_dru_solar_beam');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-16880, 'spell_dru_natures_grace'),
(78675, 'spell_dru_solar_beam');

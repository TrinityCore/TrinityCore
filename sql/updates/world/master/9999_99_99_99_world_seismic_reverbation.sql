DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warr_cleave_seismic_reverberation', 
'spell_warr_whirlwind_1680_seismic_reverberation',
'spell_warr_whirlwind_190411_seismic_reverberation',
'spell_warr_whirlwind_190411_offhand_seismic_reverberation',
'spell_warr_revenge_seismic_reverberation');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(845, 'spell_warr_cleave_seismic_reverberation'),
(199658,'spell_warr_whirlwind_1680_seismic_reverberation'),
(199667, 'spell_warr_whirlwind_190411_seismic_reverberation'),
(44949, 'spell_warr_whirlwind_190411_offhand_seismic_reverberation'),
(199852, 'spell_warr_whirlwind_190411_seismic_reverberation'),
(199851, 'spell_warr_whirlwind_190411_offhand_seismic_reverberation'),
(6572, 'spell_warr_revenge_seismic_reverberation');
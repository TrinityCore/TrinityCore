DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_pounce',
'spell_dru_ravage',
'spell_gen_shadowmeld');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(9005, 'spell_dru_pounce'),
(6785, 'spell_dru_ravage'),
(58984, 'spell_gen_shadowmeld');

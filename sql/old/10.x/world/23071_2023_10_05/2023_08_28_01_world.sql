DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_atonement_triggered', 'spell_pri_atonement_effect', 'spell_pri_atonement_effect_aura');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(17,'spell_pri_atonement_effect'),
(139,'spell_pri_atonement_effect'),
(2061,'spell_pri_atonement_effect'),
(194509,'spell_pri_atonement_effect'),
(194384,'spell_pri_atonement_effect_aura'),
(214206,'spell_pri_atonement_effect_aura');

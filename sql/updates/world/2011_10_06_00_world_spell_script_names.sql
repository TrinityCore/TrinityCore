DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_righteous_defense';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_mana_leech';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(31789,'spell_pal_righteous_defense'),
(34433,'spell_pri_mana_leech');

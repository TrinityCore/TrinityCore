DELETE FROM `spell_script_names` WHERE `spell_id`=37877 AND `ScriptName`='spell_pal_blessing_of_faith';
DELETE FROM `spell_script_names` WHERE `spell_id`=-20473 AND `ScriptName`='spell_pal_holy_shock';
DELETE FROM `spell_script_names` WHERE `spell_id`=20425 AND `ScriptName`='spell_pal_judgement_of_command';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(37877,'spell_pal_blessing_of_faith'),
(-20473,'spell_pal_holy_shock'),
(20425,'spell_pal_judgement_of_command');

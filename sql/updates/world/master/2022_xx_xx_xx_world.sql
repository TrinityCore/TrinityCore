DELETE FROM `spell_script_names` WHERE `spell_id` IN (47666, 47750) AND `ScriptName`='spell_pri_penance_damage_healing';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(47666, 'spell_pri_penance_damage_healing'),
(47750, 'spell_pri_penance_damage_healing');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (47758, 47757) AND `ScriptName`='spell_pri_penance_channeled';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(47758, 'spell_pri_penance_channeled'),
(47757, 'spell_pri_penance_channeled');

DELETE FROM `spell_script_names` WHERE `spell_id` = 198068 AND `ScriptName`='spell_pri_power_of_the_dark_side';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(198068, 'spell_pri_power_of_the_dark_side');

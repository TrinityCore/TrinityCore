DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_power_of_the_dark_side_damage_bonus';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_power_of_the_dark_side_healing_bonus';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_penance_channeled';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_power_of_the_dark_side';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(47666, 'spell_pri_power_of_the_dark_side_damage_bonus'),
(47750, 'spell_pri_power_of_the_dark_side_healing_bonus'),
(47758, 'spell_pri_penance_channeled'),
(47757, 'spell_pri_penance_channeled'),
(198069, 'spell_pri_power_of_the_dark_side');

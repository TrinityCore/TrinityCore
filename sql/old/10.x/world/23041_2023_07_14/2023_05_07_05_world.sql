DELETE FROM `spell_script_names` WHERE `spell_id`=400169;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_dark_reprimand';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(400169,'spell_pri_dark_reprimand');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_penance_channeled','spell_pri_penance_or_dark_reprimand_channeled');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(47758,'spell_pri_penance_or_dark_reprimand_channeled'),
(47757,'spell_pri_penance_or_dark_reprimand_channeled'),
(373129,'spell_pri_penance_or_dark_reprimand_channeled'),
(400171,'spell_pri_penance_or_dark_reprimand_channeled');

DELETE FROM `spell_script_names` WHERE `spell_id`=373130 AND `ScriptName`='spell_pri_power_of_the_dark_side_damage_bonus';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(373130,'spell_pri_power_of_the_dark_side_damage_bonus');

DELETE FROM `spell_script_names` WHERE `spell_id`=400187 AND `ScriptName`='spell_pri_power_of_the_dark_side_healing_bonus';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(400187,'spell_pri_power_of_the_dark_side_healing_bonus');

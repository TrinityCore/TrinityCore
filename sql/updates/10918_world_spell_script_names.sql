DELETE FROM `spell_script_names` WHERE `spell_id` IN (68786,70336) AND `ScriptName`='spell_garfrost_permafrost';
DELETE FROM `spell_script_names` WHERE `spell_id`=69012 AND `ScriptName`='spell_krick_explosive_barrage';
DELETE FROM `spell_script_names` WHERE `spell_id`=69263 AND `ScriptName`='spell_ick_explosive_barrage';
DELETE FROM `spell_script_names` WHERE `spell_id`=44851 AND `ScriptName`='spell_exploding_orb_hasty_grow';
DELETE FROM `spell_script_names` WHERE `spell_id`=68987 AND `ScriptName`='spell_krick_pursuit';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (69029,70850) AND `ScriptName`='spell_krick_pursuit_confusion';
DELETE FROM `spell_script_names` WHERE `spell_id`=69275 AND `ScriptName`='spell_tyrannus_mark_of_rimefang';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(68786,'spell_garfrost_permafrost'),
(70336,'spell_garfrost_permafrost'),
(69012,'spell_krick_explosive_barrage'),
(69263,'spell_ick_explosive_barrage'),
(44851,'spell_exploding_orb_hasty_grow'),
(68987,'spell_krick_pursuit'),
(69029,'spell_krick_pursuit_confusion'),
(70850,'spell_krick_pursuit_confusion'),
(69275,'spell_tyrannus_mark_of_rimefang');

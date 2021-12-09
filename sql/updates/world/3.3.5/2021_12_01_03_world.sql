--
DELETE FROM `spell_script_names` WHERE
(`spell_id` = 36730 AND `ScriptName` = 'spell_kaelthas_flame_strike') OR
(`spell_id` = 36976 AND `ScriptName` = 'spell_kaelthas_summon_weapons') OR
(`spell_id` = 39497 AND `ScriptName` = 'spell_kaelthas_remove_weapons');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(36730,'spell_kaelthas_flame_strike'),
(36976,'spell_kaelthas_summon_weapons'),
(39497,'spell_kaelthas_remove_weapons');

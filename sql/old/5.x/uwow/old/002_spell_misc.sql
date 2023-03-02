DELETE FROM `spell_script_names` WHERE (`spell_id`='980') AND (`ScriptName`='spell_warl_agony');

DELETE FROM `spell_bonus_data` WHERE (`entry`='980');
INSERT INTO `spell_bonus_data` (`entry`, `dot_bonus`, `comments`) VALUES ('980', '0.026', 'Warlock - Curse of Agony');
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (49527, 49518, 49528, 49544, 49537, 49548);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49527, 49527, 59972),
(49518, 49518, 59971),
(49528, 49528, 59973),
(49544, 49544, 59965),
(49537, 49537, 59963),
(49548, 49548, 59969);

UPDATE `creature_template` SET `AIName` = 'NullAI' WHERE `entry` = 30413;

DELETE FROM `spell_script_names` WHERE `spell_id` = 53242;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(53242, 'spell_tharon_ja_clear_gift_of_tharon_ja');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_frost_breath';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_unsated_craving';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(69649,'spell_sindragosa_frost_breath'),
(71056,'spell_sindragosa_frost_breath'),
(71057,'spell_sindragosa_frost_breath'),
(71058,'spell_sindragosa_frost_breath'),
(73061,'spell_sindragosa_frost_breath'),
(73062,'spell_sindragosa_frost_breath'),
(73063,'spell_sindragosa_frost_breath'),
(73064,'spell_sindragosa_frost_breath'),
(71168,'spell_item_unsated_craving');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=71952;

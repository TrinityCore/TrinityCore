--
DELETE FROM `spell_scripts` WHERE `id` IN (57337,57397,58466,58475,66477);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_item_great_feast',
'spell_item_fish_feast',
'spell_item_gigantic_feast',
'spell_item_small_feast',
'spell_item_bountiful_feast',
'spell_gen_feast');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(57301,'spell_item_great_feast'),
(57426,'spell_item_fish_feast'),
(58465,'spell_item_gigantic_feast'),
(58474,'spell_item_small_feast'),
(66476,'spell_item_bountiful_feast'),
(57337,'spell_gen_feast'),
(57397,'spell_gen_feast'),
(58466,'spell_gen_feast'),
(58475,'spell_gen_feast'),
(66477,'spell_gen_feast');

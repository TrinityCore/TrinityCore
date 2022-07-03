--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (70192,-71450,71522,71539);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_love_is_in_the_air_fragrant_air_analysis',
'spell_love_is_in_the_air_heavily_perfumed',
'spell_love_is_in_the_air_recently_analyzed',
'spell_love_is_in_the_air_sample_satisfaction',
'spell_love_is_in_the_air_cancel_service_uniform',
'spell_love_is_in_the_air_perfume_cologne_immune');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70192,'spell_love_is_in_the_air_fragrant_air_analysis'),
(71507,'spell_love_is_in_the_air_heavily_perfumed'),
(71508,'spell_love_is_in_the_air_recently_analyzed'),
(69438,'spell_love_is_in_the_air_sample_satisfaction'),
(71522,'spell_love_is_in_the_air_cancel_service_uniform'),
(71539,'spell_love_is_in_the_air_cancel_service_uniform'),
(68529,'spell_love_is_in_the_air_perfume_cologne_immune'),
(68530,'spell_love_is_in_the_air_perfume_cologne_immune');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_love_is_in_the_air_service_uniform' WHERE `ScriptName` = 'spell_gen_aura_service_uniform';

DELETE FROM `spell_group` WHERE `id`=68529;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=68529;

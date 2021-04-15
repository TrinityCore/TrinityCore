DELETE FROM `spell_script_names` WHERE `spell_id` IN (69782,69796,69798,69801) AND `ScriptName`='spell_rotface_ooze_flood';
DELETE FROM `spell_script_names` WHERE `spell_id`=69538 AND `ScriptName`='spell_rotface_little_ooze_combine';
DELETE FROM `spell_script_names` WHERE `spell_id`=69553 AND `ScriptName`='spell_rotface_large_ooze_combine';
DELETE FROM `spell_script_names` WHERE `spell_id`=69610 AND `ScriptName`='spell_rotface_large_ooze_buff_combine';
DELETE FROM `spell_script_names` WHERE `spell_id`=69839 AND `ScriptName`='spell_rotface_unstable_ooze_explosion_init';
DELETE FROM `spell_script_names` WHERE `spell_id`=69832 AND `ScriptName`='spell_rotface_unstable_ooze_explosion';
DELETE FROM `spell_script_names` WHERE `spell_id`=71441 AND `ScriptName`='spell_rotface_unstable_ooze_explosion_suicide';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(69782,'spell_rotface_ooze_flood'),
(69796,'spell_rotface_ooze_flood'),
(69798,'spell_rotface_ooze_flood'),
(69801,'spell_rotface_ooze_flood'),
(69538,'spell_rotface_little_ooze_combine'),
(69553,'spell_rotface_large_ooze_combine'),
(69610,'spell_rotface_large_ooze_buff_combine'),
(69839,'spell_rotface_unstable_ooze_explosion_init'),
(69832,'spell_rotface_unstable_ooze_explosion'),
(71441,'spell_rotface_unstable_ooze_explosion_suicide');

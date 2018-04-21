DELETE FROM `spell_scripts` WHERE `id` IN (15998,25952,29435,45980,51592,51910,52267,54420);
DELETE FROM `spell_script_names` WHERE `spell_id` IN (15998,25952,29435,45980,51592,51910,52267,54420);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(15998, 'spell_gen_despawn_self'),
(25952, 'spell_gen_despawn_self'),
(29435, 'spell_gen_despawn_self'),
(45980, 'spell_gen_despawn_self'),
(51592, 'spell_gen_despawn_self'),
(51910, 'spell_gen_despawn_self'),
(52267, 'spell_gen_despawn_self'),
(54420, 'spell_gen_despawn_self');

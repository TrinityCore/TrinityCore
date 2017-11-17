-- repeal/replace some wrong spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_despawn_self', 'spell_deliver_stolen_horse');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(15998, 'spell_gen_despawn_self'),
(25952, 'spell_gen_despawn_self'),
(29435, 'spell_gen_despawn_self'),
(45980, 'spell_gen_despawn_self'),
(51592, 'spell_gen_despawn_self'),
(51910, 'spell_gen_despawn_self'),
(52264, 'spell_deliver_stolen_horse'),
(54420, 'spell_gen_despawn_self');

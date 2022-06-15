DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1152;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1152, 3);

DELETE FROM `spell_group` WHERE `id`= 1152;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1152, 24907),
(1152, 49868),
(1152, 2895);

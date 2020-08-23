DELETE FROM `spell_group` WHERE `id`= 1149;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1149, 11366),
(1149, 92315);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1149;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1149, 2);

DELETE FROM `spell_group` WHERE `id`= 1123;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1123, 8921),
(1123, 93402);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1123;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1123, 2);

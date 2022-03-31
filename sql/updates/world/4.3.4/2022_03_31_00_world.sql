DELETE FROM `spell_group` WHERE `id`= 1151;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1151, 32216),
(1151, 82368);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1151;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1151, 2);

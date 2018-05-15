--
DELETE FROM `spell_group` WHERE `id`=1122;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1122,588),
(1122,73413);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1122;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1122,1);

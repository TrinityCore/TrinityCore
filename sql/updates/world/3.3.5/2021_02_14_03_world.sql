--
DELETE FROM `spell_group` WHERE `id`=68529;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(68529, 68529),
(68529, 68530);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=68529;
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(68529,1);

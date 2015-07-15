--
DELETE FROM `spell_group` WHERE `id`=1121;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1121,3671),
(1121,3672),
(1121,3673);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1121;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1121,1);

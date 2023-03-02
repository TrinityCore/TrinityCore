INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2227', '1');
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2228', '1');
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2229', '2');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2227', '20217');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2228', '19740');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2229', '-2227');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2229', '-2228');

INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2230', '1');
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2231', '1');
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES ('2232', '2');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2230', '6673');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2231', '469');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2232', '-2230');
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES ('2232', '-2231');

UPDATE `spell_group` SET `id`='2233' WHERE (`id`='1002') AND (`spell_id`='6673');
UPDATE `spell_group` SET `id`='2233' WHERE (`id`='1002') AND (`spell_id`='19506');
UPDATE `spell_group` SET `id`='2233' WHERE (`id`='1002') AND (`spell_id`='57330');
UPDATE `spell_group_stack_rules` SET `group_id`='2233' WHERE (`group_id`='1002');
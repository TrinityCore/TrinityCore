DELETE FROM `spell_group` WHERE `id` IN (1117,1118);
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(1117,25898),
(1117,25899),
(1118,20911),
(1118,20217);

DELETE FROM `spell_group_stack_rules` WHERE `group_id` in (1117,1118);
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(1117,3),
(1118,3);

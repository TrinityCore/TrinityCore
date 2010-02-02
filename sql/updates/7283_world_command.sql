DELETE FROM `command` WHERE `name` = 'reload spell_group_stack_rules';
DELETE FROM `command` WHERE `name` = 'reload spell_elixir';
DELETE FROM `command` WHERE `name` = 'reload spell_stack_masks';
INSERT INTO `command` VALUES ('reload spell_group_stack_rules','3','Syntax: .reload spell_group\nReload spell_group_stack_rules table.');

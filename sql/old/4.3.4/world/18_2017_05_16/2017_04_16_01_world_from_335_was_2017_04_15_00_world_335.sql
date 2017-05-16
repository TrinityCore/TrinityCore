/*
UPDATE `spell_group_stack_rules` SET `stack_rule`=3 WHERE `group_id`=1025;
DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (1023,1024);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1023, 4),
(1024, 4);
*/

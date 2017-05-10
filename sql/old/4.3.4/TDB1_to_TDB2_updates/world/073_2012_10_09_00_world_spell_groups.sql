-- Improved Scorch, Improved Shadow Bolt and Winter's Chill effect should not stack
DELETE FROM `spell_group` WHERE `id`=1037;
INSERT INTO `spell_group`(`id`,`spell_id`) VALUES
(1037,22959),
(1037,17800),
(1037,12579);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1037;
INSERT INTO `spell_group_stack_rules`(`group_id`,`stack_rule`) VALUES (1037,3);

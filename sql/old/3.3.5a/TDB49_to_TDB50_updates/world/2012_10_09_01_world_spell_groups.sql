-- Blood Frenzy (Warrior) and Savage Combat effect should not stack
DELETE FROM `spell_group` WHERE `id`=1119;
INSERT INTO `spell_group`(`id`,`spell_id`) VALUES
(1119,30069),
(1119,58684);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1119;
INSERT INTO `spell_group_stack_rules`(`group_id`,`stack_rule`) VALUES (1119,3);

-- Remove invalid spell_groups
DELETE FROM `spell_group` WHERE `id` IN (1038,1039);

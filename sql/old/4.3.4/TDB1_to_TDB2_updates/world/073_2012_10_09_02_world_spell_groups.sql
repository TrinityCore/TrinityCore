SET @GROUP := 1120;
-- Totem of Wrath and Heart of the Crusader effect should not stack
DELETE FROM `spell_group` WHERE `id`=@GROUP;
INSERT INTO `spell_group`(`id`,`spell_id`) VALUES
(@GROUP,21183),
(@GROUP,30708);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@GROUP;
INSERT INTO `spell_group_stack_rules`(`group_id`,`stack_rule`) VALUES (@GROUP,3);

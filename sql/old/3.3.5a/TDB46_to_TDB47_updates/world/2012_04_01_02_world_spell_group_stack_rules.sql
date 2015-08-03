-- Greater Blessing of Wisdom and Mana Spring Totem should not stack (hotfix)
SET @GROUP := 1117;
DELETE FROM `spell_group` WHERE id=@GROUP;
INSERT INTO `spell_group`(`id`,`spell_id`) VALUES
(@GROUP,25894), -- Greater Blessing of Wisdom
(@GROUP,5677); -- Mana Spring (cast by Mana Spring Totem)
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@GROUP;
INSERT INTO `spell_group_stack_rules`(`group_id`,`stack_rule`) VALUES
(@GROUP,3); -- Make them SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT

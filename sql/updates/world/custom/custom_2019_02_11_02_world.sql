UPDATE `spell_group_stack_rules` SET `stack_rule`= 1 WHERE `group_id`= 1136;
DELETE FROM `spell_group` WHERE `id` IN (1148);
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
-- Blessing of Might / Blessing of Kings
(1148, 79062),
(1148, 79063),
(1148, 79101),
(1148, 79102);

DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (1148);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1148, 1);

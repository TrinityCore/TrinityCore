-- 
DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 2500 AND `stack_rule`= 2;
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES (2500, 2);

DELETE FROM `spell_group` WHERE `id`= 2500 AND `spell_id` IN (469,6673);
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(2500, 469), -- Commanding Shout
(2500, 6673); -- Battle Shout
--

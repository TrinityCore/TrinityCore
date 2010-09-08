DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (1108, 1109, 1110);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1108, 1), -- Mark/Gift of the Wild
(1109, 1), -- Power Word/Prayer of Fortitude
(1110, 1); -- Prayer of/Shadow protection
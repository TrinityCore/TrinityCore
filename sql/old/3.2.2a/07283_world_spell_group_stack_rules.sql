DROP TABLE IF EXISTS `spell_group_stack_rules`;
CREATE TABLE `spell_group_stack_rules` (
  `group_id` INT(11) UNSIGNED NOT NULL DEFAULT 0,
  `stack_rule` TINYINT(3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`group_id`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO spell_group_stack_rules (group_id, stack_rule) VALUES
(1, 1),
(2, 1),
(1001, 1),
(1002, 1),
(1003, 1),
(1004, 1),
(1005, 1),
(1006, 1),
(1007, 1),
(1008, 1),
(1009, 1),
(1010, 2),
(1011, 1);

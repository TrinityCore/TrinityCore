DELETE FROM `command` WHERE `permission`='683';
DELETE FROM `command` WHERE `permission`='684';
DELETE FROM `command` WHERE `permission`='705';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload reputation_reward_rate', 683, 'Syntax: .reload reputation_reward_rate\r\nReload reputation_reward_rate table.'),
('reload reputation_spillover_template', 684, 'Syntax: .reload reputation_spillover_template\r\nReload reputation_spillover_template table.'),
('reload warden_action', 705, 'Syntax: .reload warden_action\r\nReload warden_action.');

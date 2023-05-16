DELETE FROM `command` WHERE `name`='reload mail_server_template';
INSERT INTO `command` (`name`, `help`) VALUES
('reload mail_server_template', 'Syntax: .reload mail_server_template\nReload server_mail_template table.');

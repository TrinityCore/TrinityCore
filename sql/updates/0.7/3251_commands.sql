DELETE FROM `command` WHERE `name` = 'password';
INSERT INTO `command` VALUES ('password',0,'Syntax: .password $old_password $new_password $new_password\r\n\r\nChange your account password.');

DELETE FROM `command` WHERE `name` = 'password';
INSERT INTO command (name, security, help) VALUES ('password', 0,'Syntax: .password $newpassword\r\n\r\nSet for your account $newpassword as new password.');

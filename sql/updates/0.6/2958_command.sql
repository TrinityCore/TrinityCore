DELETE FROM `command` WHERE `name` = 'lockaccount';
INSERT INTO command (name, security, help) VALUES ('lockaccount', 0,'Syntax: .lockaccount [on|off]\r\n\r\nAllow login from account only from current used IP or remove this requirement.');

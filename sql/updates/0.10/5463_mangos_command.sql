DELETE FROM `command` WHERE `name` = 'cshutdown';
UPDATE `command` SET `help`='Syntax: .shutdown seconds\r\n\r\nShut the server down after given seconds or cancel the shutdown if cancel value is used.' WHERE `name` = 'shutdown';

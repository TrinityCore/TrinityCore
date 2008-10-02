DELETE FROM `command`  WHERE `name` = 'grouptele';

INSERT INTO `command` ( `name` , `security` , `help` ) VALUES 
('grouptele',1,'Syntax: .grouptele #location\r\n\r\nTeleport a selected player and his group members to a given location.');

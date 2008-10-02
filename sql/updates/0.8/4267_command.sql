DELETE FROM `command`  WHERE `name` = 'namego';
DELETE FROM `command`  WHERE `name` = 'groupgo';

INSERT INTO `command` ( `name` , `security` , `help` ) VALUES 
('namego',1,'Syntax: .namego $charactername\r\n\r\nTeleport the given character to you.'),
('groupgo',1,'Syntax: .groupgo $charactername\r\n\r\nTeleport the given character and his group to you.');

DELETE FROM `command` WHERE `name` IN ('modify tp');
INSERT INTO `command` VALUES
('modify tp',1,'Syntax: .modify tp #amount\r\n\r\nSte free talent pointes for selected character or character\'s pet. It will be reset to default expected at next levelup/login/quest reward.');
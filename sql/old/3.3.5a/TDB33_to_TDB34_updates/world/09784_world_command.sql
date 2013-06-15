DELETE FROM `command` WHERE `name` IN ('character changefaction','character changerace');
INSERT INTO `command` VALUES
('character changefaction',2,'Syntax: .character changefaction $name\r\n\r\nChange character faction.'),
('character changerace',2,'Syntax: .character changerace $name\r\n\r\nChange character race.');

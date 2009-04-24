ALTER TABLE db_version CHANGE COLUMN required_7705_01_mangos_command required_7706_01_mangos_command bit;

DELETE FROM `command` WHERE `name` IN ('plimit','server plimit');

INSERT INTO `command` VALUES
('server plimit',3,'Syntax: .server plimit [#num|-1|-2|-3|reset|player|moderator|gamemaster|administrator]\r\n\r\nWithout arg show current player amount and security level limitations for login to server, with arg set player linit ($num > 0) or securiti limitation ($num < 0 or security leme name. With `reset` sets player limit to the one in the config file');

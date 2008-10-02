DELETE FROM command WHERE name IN ('plimit');
INSERT INTO `command` VALUES 
('plimit',3,'Syntax: .plimit [#num|-1|-2|-3|default|player|moderator|gamemaster|administrator]\r\n  Without arg show current player amount and security level limitations for login to server, with arg set player linit ($num > 0) or securiti limitation ($num < 0 or security leme name. With `default` arg set default for server player limit (100)');


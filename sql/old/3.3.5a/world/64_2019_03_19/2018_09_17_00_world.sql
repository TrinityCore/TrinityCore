-- 
DELETE FROM `command` WHERE `name`='debug dummy';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug dummy',852,'Syntax: .debug dummy <???>

Catch-all debug command. Does nothing by default. If you want it to do things for testing, add the things to its script in cs_debug.cpp.');

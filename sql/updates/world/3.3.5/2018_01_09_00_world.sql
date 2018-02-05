-- 
DELETE FROM `command` WHERE `name`="debug threatinfo";
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug threatinfo', 870, 'Syntax: .debug threatinfo

Displays various debug information about the target\'s threat state, modifiers, redirects and similar.');

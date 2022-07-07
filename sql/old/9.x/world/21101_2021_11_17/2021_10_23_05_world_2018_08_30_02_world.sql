-- 
DELETE FROM `command` WHERE `name`="go instance";
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('go instance', 874, 'Syntax: .go instance [mapid | name]

Teleports you to entrance of instance with script name matching input (or given mapid)');

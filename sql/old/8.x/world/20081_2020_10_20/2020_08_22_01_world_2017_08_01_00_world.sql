--
DELETE FROM `command` WHERE `name`="list spawnpoints";
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('list spawnpoints', 866, 'Syntax: .list spawnpoints

Lists all spawn points (both creatures and GOs) in the current zone.');

DELETE FROM `command` WHERE `name` = 'debug loadcells';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('debug loadcells', 835, 'Syntax: .debug loadcells [mapId]\nLoads all cells for debugging purposes');

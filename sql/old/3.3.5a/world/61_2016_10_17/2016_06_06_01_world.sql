DELETE FROM `command` WHERE `name` = 'debug neargraveyard';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES 
('debug neargraveyard', 841, 'Syntax: .debug neargraveyard [linked]\nFind the nearest graveyard from dbc or db (if linked)');

DELETE FROM `trinity_string` WHERE `entry` IN (82, 83);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc6`, `content_loc7`) VALUES 
(82, 'Nearest graveyard found: %u (%.3f %.3f %.3f)', 'Cementerio mas cercano encontrado: %u (%.3f %.3f %.3f)', 'Cementerio mas cercano encontrado: %u (%.3f %.3f %.3f)'),
(83, 'There are no graveyards near', 'No se ha encontrado ningun cementerio cerca', 'No se ha encontrado ningun cementerio cerca');

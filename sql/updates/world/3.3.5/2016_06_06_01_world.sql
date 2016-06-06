DELETE FROM `command` WHERE `name` = 'neargraveyard';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES 
('neargraveyard', 841, 'Syntax: .neargraveyard\nFind the nearest graveyard from dbc');

DELETE FROM `trinity_string` WHERE `entry` = 82;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc6`, `content_loc7`) VALUES 
(82, 'Nearest graveyard found: %u (%.3f %.3f %.3f)', 'Cementerio mas cercano encontrado: %u (%.3f %.3f %.3f)', 'Cementerio mas cercano encontrado: %u (%.3f %.3f %.3f)');

--
DELETE FROM `command` WHERE `name` IN ('npcbot sendto point','npcbot sendto point set');
INSERT INTO `command` (`name`) VALUES
('npcbot sendto point'),
('npcbot sendto point set');

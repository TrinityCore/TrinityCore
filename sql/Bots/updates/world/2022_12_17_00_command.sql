--
DELETE FROM `command` WHERE `name` IN ('npcbot list spawned','npcbot list spawned free','npcbot delete free','npcbot delete id');
INSERT INTO `command` (`name`) VALUES
('npcbot list spawned'),
('npcbot list spawned free'),
('npcbot delete free'),
('npcbot delete id');

--
DELETE FROM `command` WHERE `name` IN ('npcbot command nogossip','npcbot command rebind','npcbot command unbind');
INSERT INTO `command` (`name`) VALUES
('npcbot command nogossip'),
('npcbot command rebind'),
('npcbot command unbind');

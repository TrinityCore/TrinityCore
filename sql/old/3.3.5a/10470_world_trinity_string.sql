DELETE FROM `trinity_string` WHERE `entry` IN (1027, 1028);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES 
(1027, 'SQL driver query logging enabled.'),
(1028, 'SQL driver query logging disabled.');
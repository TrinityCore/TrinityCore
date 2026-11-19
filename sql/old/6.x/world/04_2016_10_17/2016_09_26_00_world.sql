DELETE FROM `trinity_string` WHERE `entry` IN (1032, 1033);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1032, 'Battle.net account created: %s with game account %s'),
(1033, 'Battle.net account created: %s');

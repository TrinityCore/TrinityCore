DELETE FROM `trinity_string` WHERE `entry` IN (1204, 1205);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1204, 'You have entered areatrigger %u.'),
(1205, 'You have left areatrigger %u.');

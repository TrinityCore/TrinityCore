DELETE FROM `Kitron_string` WHERE `entry` IN(19,20); # unused entries
INSERT INTO `Kitron_string` (`entry`,`content_default`) VALUES
(19,'Update time diff: %u.'),
(20,'Time left until shutdown/restart: %s');

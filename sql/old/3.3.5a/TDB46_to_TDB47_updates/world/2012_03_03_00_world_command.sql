DELETE FROM `command` WHERE `name` LIKE 'debug moveflags';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('debug moveflags',3,'Syntax: .debug moveflags [$newMoveFlags [$newMoveFlags2]]\r\nNo params given will output the current moveflags of the target');

DELETE FROM `trinity_string` WHERE `entry` IN(1143,1144);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1143,'Target''s moveFlags: %u, moveFlagsExtra: %u.'),
(1144,'Target''s moveFlags set to: %u, moveFlagsExtra to: %u');


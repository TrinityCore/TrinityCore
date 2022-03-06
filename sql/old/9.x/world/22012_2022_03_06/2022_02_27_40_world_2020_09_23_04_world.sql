-- 
DELETE FROM `trinity_string` WHERE `entry` IN (7,193,195);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(  7, 'Subcommand \'%.*s%c%.*s\' is ambiguous:'),
(193, 'Subcommand \'%.*s%c%.*s\' does not exist.'),
(195, '### USAGE: .%.*s ...');

-- 
DELETE FROM `trinity_string` WHERE `entry` IN (6,7,8,191,192,193,194);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(6, 'Command \'%.*s\' does not exist'),
(7, 'Subcommand \'%.*s\' is ambiguous:'),
(8, 'Possible subcommands:'),
(191, '|- %.*s'),
(192, '|- %.*s ...'),
(193, 'Subcommand \'%.*s\' does not exist.'),
(194, 'Command \'%.*s\' is ambiguous:');

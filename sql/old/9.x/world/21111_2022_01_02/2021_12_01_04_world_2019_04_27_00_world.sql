-- 
DELETE FROM `command` WHERE `name`='debug asan';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug asan',874,'Syntax: .debug asan $subcommand
Type .debug asan to see the list of possible subcommands or .help debug asan $subcommand to see info on subcommands.
Use only when testing dynamic analysis tools.');

DELETE FROM `command` WHERE `name`='debug asan outofbounds';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug asan outofbounds',874,'Syntax: .debug asan outofbounds
Triggers a stack out of bounds read.
Use only when testing dynamic analysis tools.');

DELETE FROM `command` WHERE `name`='debug asan memoryleak';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug asan memoryleak',874,'Syntax: .debug asan memoryleak
Triggers a memory leak.
Use only when testing dynamic analysis tools.');

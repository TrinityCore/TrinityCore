-- 
DELETE FROM `command` WHERE `name`='debug asan outofbounds';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug asan outofbounds',874,'Syntax: .debug asan outofbounds
Triggers a stack out of bounds read.
Use only when testing dynamic analysis tools.');

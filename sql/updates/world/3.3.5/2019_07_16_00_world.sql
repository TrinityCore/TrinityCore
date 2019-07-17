-- 
DELETE FROM `command` WHERE `name`='debug questreset';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug questreset',878,'Syntax: .debug questreset <daily/weekly/monthly/all>

Performs quest reset procedure for the specified type (or all types).
Quest pools will be re-generated, and quest completion status will be reset.');

--
DELETE FROM `command` WHERE `name`="debug instancespawn";
INSERT INTO `command`(`name`,`permission`,`help`) VALUES
('debug instancespawn',871,'Syntax: .debug instancespawn [<groupID>/explain]

Displays information about the spawn groups being managed by the current instance script. If groupID is specified, additionally explains why that spawn group is in the listed state. If "explain" is specified, explains all spawn groups.');

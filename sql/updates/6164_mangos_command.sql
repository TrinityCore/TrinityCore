DELETE FROM `command` WHERE `name` IN ('gm fly');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('gm fly',3,'Syntax: .gm fly on/off\r\nEnable/disable gm fly mode.');

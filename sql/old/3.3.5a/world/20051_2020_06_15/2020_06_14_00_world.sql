-- 
DELETE FROM `command` WHERE `name`='debug objectcount';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug objectcount',300,'Syntax: .debug objectcount <optional map id>
Shows the number of Creatures and GameObjects for the specified map id or for all maps if none is specified
');

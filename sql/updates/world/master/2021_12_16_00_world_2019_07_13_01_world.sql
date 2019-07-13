-- 
DELETE FROM `command` WHERE `name`='debug guidlimits';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug guidlimits',300,'Syntax: .debug guidlimits <optional map id>
Shows the current Creature and GameObject highest Guid for the specified map id or for all maps if none is specified
');

DELETE FROM command WHERE name IN ('gotrigger');
INSERT INTO `command` (`name`,`security`,`help`) VALUES 
('gotrigger',2,'Syntax: .gotrigger #trigger_id\r\n\r\nTeleport your character to areatrigger with id #trigger_id.  Character will be teleported to trigger target if selected areatrigger is telporting trigger.');


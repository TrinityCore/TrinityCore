DELETE FROM command WHERE name = 'npc delete';
INSERT INTO `command` VALUES
('npc delete',2,'Syntax: .npc delete [#guid]\r\n\r\nDelete creature with guid #guid (or the selected if no guid is provided)');

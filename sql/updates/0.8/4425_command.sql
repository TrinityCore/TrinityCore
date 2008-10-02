delete from command where name in('goxyz','resetall','reset','reset honor','reset level','reset spells','reset stats','reset talents');
INSERT INTO `command` VALUES 
('goxyz',1,'Syntax: .goxyz #x #y #z [#mapid]\r\n\r\nTeleport player to point with (#x,#y,#z) coordinates at ground(water) level at map #mapid or same map if #mapid not provided.'),
('resetall',3,'Syntax: .resetall spells\r\n\r\nSyntax: .resetall talents\r\n\r\nRequest reset spells or talents at next login each existed character.'),
('reset honor',3,'Syntax:\r\n.reset honor [Playername]\r\n  Reset all honor data for targeted character.'),
('reset level',3,'Syntax:\r\n.reset level [Playername]\r\n  Reset level to 1 including reset stats and talents.  Equipped items with greater level requirement can be lost.'),
('reset spells',3,'Syntax:\r\n.reset spells [Playername]\r\n  Removes all non-original spells from spellbook. Playername can be name of offline character.\r\n.'),
('reset stats',3,'Syntax:\r\n.reset stats [Playername]\r\n  Resets(recalculate) all stats of the targeted player to their original values at current level.'),
('reset talents',3,'Syntax:\r\n.reset talents [Playername]\r\n  Removes all talents of the targeted player.  Playername can be name of offline character.');


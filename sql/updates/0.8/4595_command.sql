DELETE FROM command WHERE name IN ('cast','castback');
INSERT INTO `command` VALUES 
('cast',3,'Syntax: .cast #spellid\r\n  Cast #spellid to selected target. If no target selected cast to self.'),
('castback',3,'Syntax: .castback #spellid\r\n  Selected target cast #spellid to your character.');


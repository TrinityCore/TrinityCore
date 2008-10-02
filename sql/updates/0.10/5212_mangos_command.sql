DELETE FROM command WHERE name IN ('.casttarget');

INSERT INTO `command` VALUES 
('casttarget',3,'Syntax: .casttarget #spellid\r\n  Selected target will cast #spellid to his victim.');

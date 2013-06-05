DELETE FROM `command` WHERE `name` = 'cast dest';
INSERT INTO `command` VALUES
('cast dest',3,'Syntax: .cast dest #spellid #x #y #z [triggered]\r\n  Selected target will cast #spellid at provided destination. If ''trigered'' or part provided then spell casted with triggered flag.');
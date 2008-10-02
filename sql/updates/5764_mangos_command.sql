DELETE FROM `command` WHERE `name` IN ('modify arena','modify honor');
INSERT INTO `command` VALUES 
('modify arena',3,'Syntax: .modify arena #value\r\nAdd $amount arena points to the selected player.'),
('modify honor',1,'Syntax: .modify honor $amount\r\n\r\nAdd $amount honor points to the selected player.');
